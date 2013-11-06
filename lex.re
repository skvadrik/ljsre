#include <stdio.h>
#include <string.h>

#include "ast.h"
#include "lex.h"
#include "rune.h"
#include "token_array.h"

static inline void save_token (TokenArray & tok_arr, TokenType t, void * v)
{
    printf ("LEXER: %s - %u\n", token_typenames[t], tok_arr.index);
    tok_arr.start[tok_arr.index].type  = t;
    tok_arr.start[tok_arr.index].value = v;
    ++ tok_arr.index;
}

bool lex (const char * pattern, unsigned int pattern_len, TokenArray & tok_arr, slab_allocator<> & allocator)
{
    /*!max:re2c */
    char * const buffer = new char [pattern_len + YYMAXFILL];
    char * const limit  = &buffer[pattern_len];
    // invalid value '\xFF' is considered EOI
    memcpy (buffer, pattern, pattern_len);
    memset (buffer + pattern_len, 0xFF, YYMAXFILL);

#   define YYCTYPE char
    char * YYCURSOR = buffer;
    char * YYMARKER = buffer;
    char * token    = buffer;

    unsigned int times_from = 0;
    unsigned int times_to   = 0;

lex_main:
    token    = YYCURSOR;
    YYMARKER = YYCURSOR;

    /*!re2c
        re2c:yyfill:enable = 0;

        esc_decimal        = "\\" [1-9][0-9]*;
        esc_null           = "\\0";
        esc_control        = "\\" [fnrtv];
        esc_class          = "\\" [dDsSwW];
        esc_control_letter = "\\c" [a-zA-Z];
        esc_hex            = "\\x" [0-9a-fA-F]{2};
        esc_unicode        = "\\u" [0-9a-fA-F]{4};
        esc_identity       = "\\" .;
    */

    /*!re2c
        "|"       { save_token (tok_arr, T_ALT,                NULL); goto lex_main; }
        "?"       { save_token (tok_arr, T_ZERO_ONE,           NULL); goto lex_main; }
        "*"       { save_token (tok_arr, T_ZERO_MANY,          NULL); goto lex_main; }
        "+"       { save_token (tok_arr, T_ONE_MANY,           NULL); goto lex_main; }
        "("       { save_token (tok_arr, T_CAPTURE_START,      NULL); goto lex_main; }
        "(?:"     { save_token (tok_arr, T_CAPTURE_START_LAZY, NULL); goto lex_main; }
        ")"       { save_token (tok_arr, T_CAPTURE_END,        NULL); goto lex_main; }
        "{"       { goto lex_times_from; }

        "^"
        {
            REAssertStart * p = allocator.allocate_type<REAssertStart> ();
            new (p) REAssertStart ();
            save_token (tok_arr, T_ASSERT, p);
            goto lex_main;
        }
        "$"
        {
            REAssertEnd * p = allocator.allocate_type<REAssertEnd> ();
            new (p) REAssertEnd ();
            save_token (tok_arr, T_ASSERT, p);
            goto lex_main;
        }
        "\\b"
        {
            REAssertWord * p = allocator.allocate_type<REAssertWord> ();
            new (p) REAssertWord (false);
            save_token (tok_arr, T_ASSERT, p);
            goto lex_main;
        }
        "\\B"
        {
            REAssertWord * p = allocator.allocate_type<REAssertWord> ();
            new (p) REAssertWord (true);
            save_token (tok_arr, T_ASSERT, p);
            goto lex_main;
        }
        "(?="    { save_token (tok_arr, T_ASSERT_FOLLOW,     NULL); goto lex_main; }
        "(?!"    { save_token (tok_arr, T_ASSERT_FOLLOW_NOT, NULL); goto lex_main; }

        "["
        {
            REClass * p = allocator.allocate_type<REClass> ();
            new (p) REClass (false, NULL);
            save_token (tok_arr, T_CLASS_START, p);
            goto lex_class;
        }
        "[^"
        {
            REClass * p = allocator.allocate_type<REClass> ();
            new (p) REClass (true, NULL);
            save_token (tok_arr, T_CLASS_START, p);
            goto lex_class;
        }
        "."
        {
            REDot * p = allocator.allocate_type<REDot> ();
            new (p) REDot ();
            save_token (tok_arr, T_DOT, p);
            goto lex_main;
        }
        esc_decimal
        {
            const unsigned int n = (unsigned int) atoi (token);
            REBackref * p = allocator.allocate_type<REBackref> ();
            new (p) REBackref (n);
            save_token (tok_arr, T_BACKREF, p);
            goto lex_main;
        }
        esc_class
        {
            array<Rune, slab_allocator<> > * rc = allocator.allocate_type<array<Rune, slab_allocator<> > > ();
            const bool is_negative = to_rune_class (token, * rc);
            REClass * p = allocator.allocate_type<REClass> ();
            new (p) REClass (is_negative, rc);
            save_token (tok_arr, T_CLASS, p);
            goto lex_main;
        }
        esc_null
        {
            const Rune r = '\0';
            RERune * p = allocator.allocate_type<RERune> ();
            new (p) RERune (r);
            save_token (tok_arr, T_RUNE, p);
            goto lex_main;
        }
        esc_control
        {
            const Rune r = control_to_rune (token + 1);
            RERune * p = allocator.allocate_type<RERune> ();
            new (p) RERune (r);
            save_token (tok_arr, T_RUNE, p);
            goto lex_main;
        }
        esc_control_letter
        {
            const Rune r = control_letter_to_rune (token + 1);
            RERune * p = allocator.allocate_type<RERune> ();
            new (p) RERune (r);
            save_token (tok_arr, T_RUNE, p);
            goto lex_main;
        }
        esc_hex
        {
            const Rune r = hex_to_rune (token + 1);
            RERune * p = allocator.allocate_type<RERune> ();
            new (p) RERune (r);
            save_token (tok_arr, T_RUNE, p);
            goto lex_main;
        }
        esc_unicode
        {
            const Rune r = unicode_to_rune (token + 1);
            RERune * p = allocator.allocate_type<RERune> ();
            new (p) RERune (r);
            save_token (tok_arr, T_RUNE, p);
            goto lex_main;
        }
        esc_identity
        {
            const Rune r = identity_to_rune (token + 1);
            RERune * p = allocator.allocate_type<RERune> ();
            new (p) RERune (r);
            save_token (tok_arr, T_RUNE, p);
            goto lex_main;
        }
        [^]
        {
            const char c = * token;
            if (c >= 0x7F)
            {
                if (YYCURSOR >= limit)
                {
                    save_token (tok_arr, T_LAMBDA, NULL);
                    goto success;
                }
                else
                    goto failure;
            }
            else
            {
                const Rune r = c;
                RERune * p = allocator.allocate_type<RERune> ();
                new (p) RERune (r);
                save_token (tok_arr, T_RUNE, p);
                goto lex_main;
            }
        }
    */

lex_times_from:
    /*!re2c
        [1-9][0-9]* | "0"
        {
            times_from = atoi (token);
            goto lex_times_to;
        }
        [^] { goto failure; }
    */
lex_times_to:
    /*!re2c
        "}"
        {
            int * p = allocator.allocate_type<int> ();
            * p = times_from;
            save_token (tok_arr, T_TIMES, p);
            goto lex_main;
        }
        ",}"
        {
            int * p = allocator.allocate_type<int> ();
            * p = times_from;
            save_token (tok_arr, T_TIMES_FROM, p);
            goto lex_main;
        }
        "," ([1-9][0-9]* | "0") "}"
        {
            times_to = atoi (token + 1);
            int * p = allocator.allocate_type_array<int> (2);
            p[0] = times_from;
            p[1] = times_to;
            save_token (tok_arr, T_TIMES_FROM_TO, p);
            goto lex_main;
        }
        [^] { goto failure; }
    */

lex_class:
    YYMARKER = YYCURSOR;
    token    = YYCURSOR;
    /*!re2c
        "]"
        {
            goto lex_main;
        }
        "-"
        {
            save_token (tok_arr, T_DASH, NULL);
            goto lex_class;
        }
        esc_class
        {
            array<Rune, slab_allocator<> > * rc = allocator.allocate_type<array<Rune, slab_allocator<> > > ();
            to_rune_class (token, * rc);
            save_token (tok_arr, T_CLASS_UNBOXED, rc);
            goto lex_class;
        }
        "\\b"
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = '\b';
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        esc_null
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = '\0';
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        esc_control
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = control_to_rune (token + 1);
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        esc_control_letter
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = control_letter_to_rune (token + 1);
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        esc_hex
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = hex_to_rune (token + 1);
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        esc_unicode
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = unicode_to_rune (token + 1);
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        esc_identity
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = identity_to_rune (token + 1);
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        [^\x5C\x5D\x2D]
        {
            Rune * p = allocator.allocate_type<Rune> ();
            * p = * token;
            save_token (tok_arr, T_RUNE_UNBOXED, p);
            goto lex_class;
        }
        [^]
        {
            goto failure;
        }
    */

failure:
    delete [] buffer;
    return false;

success:
    delete [] buffer;
    return true;

#   undef YYCTYPE
}
