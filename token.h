#ifndef __LJS_TOKEN__
#define __LJS_TOKEN__

#include "token_type.h"
#include "re.h"
#include "rune.h"

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

union TokenValue
{
    RE *         re;
    unsigned int number;
    Rune         rune;
    RuneVector * rune_vector;

    TokenValue ()
        : re (NULL)
    { }
};

struct Token
{
    TokenType type;
    TokenValue value;
};

#endif // __LJS_TOKEN__


