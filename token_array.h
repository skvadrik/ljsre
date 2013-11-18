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

static inline void savetoken_backref (TokenArray & tok_arr, unsigned int n)
{
    tok_arr.start[tok_arr.index].type = T_BACKREF;
    tok_arr.start[tok_arr.index].value.backref = n;
    ++ tok_arr.index;
}

static inline void savetoken_count (TokenArray & tok_arr, unsigned int n)
{
    tok_arr.start[tok_arr.index].type = T_COUNT;
    tok_arr.start[tok_arr.index].value.count = n;
    ++ tok_arr.index;
}

static inline void savetoken_rune (TokenArray & tok_arr, Rune r)
{
    tok_arr.start[tok_arr.index].type = T_RUNE;
    tok_arr.start[tok_arr.index].value.rune = r;
    ++ tok_arr.index;
}

static inline void savetoken_rune_vector (TokenArray & tok_arr, RuneVector * rs)
{
    tok_arr.start[tok_arr.index].type = T_CLASS;
    tok_arr.start[tok_arr.index].value.rune_vector = rs;
    ++ tok_arr.index;
}

#endif // __LJS_TOKEN_ARRAY__

