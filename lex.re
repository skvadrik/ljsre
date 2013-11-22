#include <stdio.h>
#include <string.h>

#include "lex.h"
#include "rune.h"

bool lex
    ( const char * pattern
    , unsigned int pattern_len
    , TokenArray & tok_arr
    , NFA<slab_allocator<> > & nfa
    )
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

    unsigned int captures = 0;

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
        "|"       { savetoken (tok_arr, T_ALT);            goto lex_main; }
        "?"       { savetoken (tok_arr, T_ZERO_ONE);       goto lex_main; }
        "*"       { savetoken (tok_arr, T_ZERO_MANY);      goto lex_main; }
        "+"       { savetoken (tok_arr, T_ONE_MANY);       goto lex_main; }
        "("
        {
            savetoken_uint (tok_arr, T_LBRACE_CAPTURE, captures);
            ++ captures;
            goto lex_main;
        }
        "(?:"     { savetoken (tok_arr, T_LBRACE_GROUP);   goto lex_main; }
        ")"       { savetoken (tok_arr, T_RBRACE);         goto lex_main; }
        "{"       { goto lex_times; }

        "^"
        {
            savetoken (tok_arr, T_ASSERT_START);
            goto lex_main;
        }
        "$"
        {
            savetoken (tok_arr, T_ASSERT_END);
            goto lex_main;
        }
        "\\b"
        {
            savetoken_boolean (tok_arr, T_ASSERT_WORD, true);
            goto lex_main;
        }
        "\\B"
        {
            savetoken_boolean (tok_arr, T_ASSERT_WORD, false);
            goto lex_main;
        }
        "(?="
        {
            savetoken_boolean (tok_arr, T_ASSERT_FOLLOW, true);
            goto lex_main;
        }
        "(?!"
        {
            savetoken_boolean (tok_arr, T_ASSERT_FOLLOW, false);
            goto lex_main;
        }

        "["
        {
            savetoken_boolean (tok_arr, T_CLASS_START, true);
            goto lex_class;
        }
        "[^"
        {
            savetoken_boolean (tok_arr, T_CLASS_START, false);
            goto lex_class;
        }
        "."
        {
            savetoken (tok_arr, T_DOT);
            goto lex_main;
        }
        esc_decimal
        {
            const unsigned int n = atoi (token + 1);
            savetoken_uint (tok_arr, T_BACKREF, n - 1);
            goto lex_main;
        }
        esc_class
        {
            RuneVector * rs = nfa.allocator.allocate_type<RuneVector> ();
            to_rune_class (token, * rs);
            savetoken_rune_vector (tok_arr, rs);
            goto lex_main;
        }
        esc_null
        {
            const Rune r = '\0';
            savetoken_rune (tok_arr, r);
            goto lex_main;
        }
        esc_control
        {
            const Rune r = control_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_main;
        }
        esc_control_letter
        {
            const Rune r = control_letter_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_main;
        }
        esc_hex
        {
            const Rune r = hex_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_main;
        }
        esc_unicode
        {
            const Rune r = unicode_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_main;
        }
        esc_identity
        {
            const Rune r = identity_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_main;
        }
        [^]
        {
            const unsigned char c = * token;
            if (c >= 0x7F)
            {
                if (YYCURSOR >= limit)
                {
                    savetoken (tok_arr, T_LAMBDA);
                    goto success;
                }
                else
                    goto failure;
            }
            else
            {
                const Rune r = c;
                savetoken_rune (tok_arr, r);
                goto lex_main;
            }
        }
    */

lex_times:
    token = YYCURSOR;
    /*!re2c
        [1-9][0-9]* | "0"
        {
            const unsigned int n = atoi (token);
            savetoken_uint (tok_arr, T_COUNT, n);
            goto lex_times_upper;
        }
        [^] { goto failure; }
    */

lex_times_upper:
    token = YYCURSOR;
    /*!re2c
        "}"
        {
            goto lex_main;
        }
        ",}"
        {
            savetoken (tok_arr, T_COMMA);
            goto lex_main;
        }
        "," ([1-9][0-9]* | "0") "}"
        {
            savetoken (tok_arr, T_COMMA);
            const unsigned int n = atoi (token + 1);
            savetoken_uint (tok_arr, T_COUNT, n);
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
            savetoken (tok_arr, T_CLASS_END);
            goto lex_main;
        }
        "-"
        {
            savetoken (tok_arr, T_DASH);
            goto lex_class;
        }
        esc_class
        {
            RuneVector * rs = nfa.allocator.allocate_type<RuneVector> ();
            to_rune_class (token, * rs);
            savetoken_rune_vector (tok_arr, rs);
            goto lex_class;
        }
        "\\b"
        {
            const Rune r = '\b';
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        esc_null
        {
            const Rune r = '\0';
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        esc_control
        {
            const Rune r = control_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        esc_control_letter
        {
            const Rune r = control_letter_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        esc_hex
        {
            const Rune r = hex_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        esc_unicode
        {
            const Rune r = unicode_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        esc_identity
        {
            const Rune r = identity_to_rune (token + 1);
            savetoken_rune (tok_arr, r);
            goto lex_class;
        }
        [^\x5C\x5D\x2D\x80-\xFF]
        {
            const Rune r = * token;
            savetoken_rune (tok_arr, r);
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
    nfa.captures = captures;

    delete [] buffer;
    return true;

#   undef YYCTYPE
}
