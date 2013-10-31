#ifndef __LJS_PARSER__
#define __LJS_PARSER__

#include "token_array.h"

struct StackType
{
    unsigned int state;
    void * semantics;
};

class Parser
{
    static const unsigned int STACK_SIZE = 1024;
    StackType * const stack;
    StackType * stack_top;

    bool is_start; // is "true" until parse executed

    Parser (const Parser &);              /* forbid copy */
    Parser & operator = (const Parser &); /* forbid copy */

  public:
    Parser ()
        : stack      (static_cast<StackType *> (operator new (STACK_SIZE * sizeof (StackType))))
        , stack_top  (stack)
        , is_start   (true)
    { }

    ~Parser ()
    {
        operator delete (stack);
    }

    bool parse (TokenArray & tok_arr);
};

#endif // __LJS_PARSER__
