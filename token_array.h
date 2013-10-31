#ifndef __LJS_TOKEN_ARRAY__
#define __LJS_TOKEN_ARRAY__

#include "token.h"

struct TokenArray
{
    const unsigned int SIZE;
    Token * start;
    unsigned int index;

    TokenArray (unsigned int sz)
        : SIZE  (sz)
        , start (static_cast<Token *> (operator new (SIZE * sizeof (Token))))
        , index (0)
    { }

    ~TokenArray ()
    {
        operator delete (start);
    }

    inline void clear ()
    {
        index = 0;
    }

  private:
    TokenArray (const TokenArray &);              /* forbid copy */
    TokenArray & operator = (const TokenArray &); /* forbid copy */
};

#endif // __LJS_TOKEN_ARRAY__

