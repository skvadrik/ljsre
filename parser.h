#ifndef __LJS_PARSER__
#define __LJS_PARSER__

#include "slab_allocator.hh"
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

    Parser (const Parser &);              /* forbid copy */
    Parser & operator = (const Parser &); /* forbid copy */

  public:
    Parser ()
        : stack      (static_cast<StackType *> (operator new (STACK_SIZE * sizeof (StackType))))
        , stack_top  (stack)
    { }

    ~Parser ()
    {
        operator delete (stack);
    }

    bool parse (TokenArray & tok_arr, slab_allocator<> & allocator);
};

#endif // __LJS_PARSER__
