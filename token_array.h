#ifndef __LJS_TOKEN_ARRAY__
#define __LJS_TOKEN_ARRAY__

#include "array.h"
#include "token.h"

typedef array<Token> TokenArray;

static inline void savetoken (TokenArray & tok_arr, TokenType t)
{
    tok_arr.start[tok_arr.index].type = t;
    ++ tok_arr.index;
}

static inline void savetoken_boolean (TokenArray & tok_arr, TokenType t, bool b)
{
    tok_arr.start[tok_arr.index].type = t;
    tok_arr.start[tok_arr.index].value.boolean = b;
    ++ tok_arr.index;
}

static inline void savetoken_uint (TokenArray & tok_arr, TokenType t, unsigned int n)
{
    tok_arr.start[tok_arr.index].type = t;
    tok_arr.start[tok_arr.index].value.uint = n;
    ++ tok_arr.index;
}

static inline void savetoken_rune (TokenArray & tok_arr, Rune r)
{
    tok_arr.start[tok_arr.index].type = T_RUNE;
    tok_arr.start[tok_arr.index].value.rune = r;
    ++ tok_arr.index;
}

static inline void savetoken_rune_class (TokenArray & tok_arr, RuneRanges * rs)
{
    tok_arr.start[tok_arr.index].type = T_CLASS;
    tok_arr.start[tok_arr.index].value.rune_class = rs;
    ++ tok_arr.index;
}

#endif // __LJS_TOKEN_ARRAY__

