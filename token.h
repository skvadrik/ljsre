#ifndef __LJS_TOKEN__
#define __LJS_TOKEN__

#include "token_type.h"

__attribute__((unused)) static const char * token_typenames [] =
{
#   define LALR2C_TOKEN(x) #x,
    LALR2C_TOKENS
#   undef LALR2C_TOKEN
};

enum TokenType
{
#   define LALR2C_TOKEN(x) x,
    LALR2C_TOKENS
#   undef LALR2C_TOKEN
    TOKEN_NUMBER
};

// Token is a pair: token = (token_id, token_value)
// For simple tokens, token_value is NULL
// For complex tokens, token_value is a pointer to object.
struct Token
{
    TokenType type;
    void * value;
};

#endif // __LJS_TOKEN__


