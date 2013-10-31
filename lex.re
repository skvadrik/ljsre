#include <stdio.h>
#include <string.h>

#include "lex.h"
#include "token_array.h"

static inline void save_token (TokenArray & tok_arr, TokenType t)
{
    printf ("LEXER: %s - %u\n", token_typenames[t], tok_arr.index);
    tok_arr.start[tok_arr.index].type  = t;
    tok_arr.start[tok_arr.index].value = NULL;
    ++ tok_arr.index;
}

bool re_lex (const char * pattern, unsigned int pattern_len, TokenArray & tok_arr)
{
#   define YYCTYPE char
    /*!max:re2c */
    char * const buffer = new char [pattern_len + YYMAXFILL];
    char * YYCURSOR = buffer;
    char * YYMARKER = buffer;
    char * token    = buffer;
    memcpy (buffer, pattern, pattern_len);
    memset (buffer + pattern_len, 0, YYMAXFILL);

lex_main:
    token    = YYCURSOR;
    YYMARKER = YYCURSOR;

    /*!re2c
        re2c:yyfill:enable = 0;

        dec = [1-9][0-9]*;

        esc_control        = "\\" [fnrtv];
        esc_decimal        = "\\" dec;
        esc_class          = "\\" [dDsSwW];
        esc_control_letter = "\\c" [a-zA-Z];
        esc_hex            = "\\x" [0-9a-fA-F]{2};
        esc_unicode        = "\\u" [0-9a-fA-F]{4};
        esc_identity       = "\\" .;
        esc_word_upper     = "\\B";
        esc_word_lower     = "\\b";

        atom_escape
            = esc_decimal
            | esc_control
            | esc_class
            | esc_control_letter
            | esc_hex
            | esc_unicode
            | esc_identity
            ;

        class_escape
            = esc_decimal
            | esc_word_lower
            | esc_control
            | esc_class
            | esc_control_letter
            | esc_hex
            | esc_unicode
            | esc_identity
            ;
        class_char = [^\x5C\x5D\x2D] | class_escape;
    */

    /*!re2c
        "\x00"                  { save_token (tok_arr, LAMBDA); goto success; }

        "|"                     { save_token (tok_arr, ALT);                goto lex_main; }
        "^"                     { save_token (tok_arr, ASSERT_START);       goto lex_main; }
        "$"                     { save_token (tok_arr, ASSERT_END);         goto lex_main; }
        esc_word_upper          { save_token (tok_arr, ESC_WORD_UPPER);     goto lex_main; }
        esc_word_lower          { save_token (tok_arr, ESC_WORD_LOWER);     goto lex_main; }
        "(?="                   { save_token (tok_arr, LBRACE_ASSERT_YES);  goto lex_main; }
        "(?!"                   { save_token (tok_arr, LBRACE_ASSERT_NO);   goto lex_main; }
        "(?:"                   { save_token (tok_arr, LBRACE_LAZY);        goto lex_main; }
        "("                     { save_token (tok_arr, LBRACE);             goto lex_main; }
        ")"                     { save_token (tok_arr, RBRACE);             goto lex_main; }
        "?"                     { save_token (tok_arr, ZERO_ONE);           goto lex_main; }
        "*"                     { save_token (tok_arr, ZERO_MANY);          goto lex_main; }
        "+"                     { save_token (tok_arr, ONE_MANY);           goto lex_main; }
        "{"                     { goto lex_counted_repeat1; }
        "["                     { goto lex_class; }
        "[^"                    { goto lex_class; }
        "."                     { save_token (tok_arr, DOT);                goto lex_main; }
        esc_control             { save_token (tok_arr, ESC_CONLROL);        goto lex_main; }
        esc_decimal             { save_token (tok_arr, ESC_INTEGER);        goto lex_main; }
        esc_class               { save_token (tok_arr, ESC_CLASS);          goto lex_main; }
        esc_control_letter      { save_token (tok_arr, ESC_CONTROL_LETTER); goto lex_main; }
        esc_hex                 { save_token (tok_arr, ESC_HEX);            goto lex_main; }
        esc_unicode             { save_token (tok_arr, ESC_UNICODE);        goto lex_main; }
        esc_identity            { save_token (tok_arr, ESC_IDENTITY);       goto lex_main; }
        [^]                     { save_token (tok_arr, CHAR);               goto lex_main; }
    */

lex_counted_repeat1:
    /*!re2c
        dec    { goto lex_counted_repeat2; }
        [^]    { goto failure; }
    */
lex_counted_repeat2:
    /*!re2c
        "}"            { save_token (tok_arr, COUNTED_REPEAT); goto lex_main; }
        ",}"           { save_token (tok_arr, COUNTED_REPEAT); goto lex_main; }
        "," dec "}"    { save_token (tok_arr, COUNTED_REPEAT); goto lex_main; }
        [^]            { goto failure; }
    */

lex_class:
    /*!re2c
        "-"    { goto lex_body; }
        [^]    { --YYCURSOR; goto lex_body; }
    */
lex_body:
    /*!re2c
        class_char "-" class_char    { goto lex_body; }
        class_char "-]"              { save_token (tok_arr, CLASS); goto lex_main; }
        class_char                   { goto lex_body; }
        "]"                          { save_token (tok_arr, CLASS); goto lex_main; }
        [^]                          { goto failure; }
    */

failure:
    delete [] buffer;
    return false;

success:
    delete [] buffer;
    return true;

#   undef YYCTYPE
}
