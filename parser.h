#ifndef __LJS_PARSER__
#define __LJS_PARSER__

#include "slab_allocator.hh"
#include "token_array.h"
#include "nfa.h"

union StackSemantics
{
    TokenValue token;
    Frag frag;

    StackSemantics ()
        : frag ()
    { }

    StackSemantics (TokenValue & t)
    {
        token = t;
    }
};

struct StackType
{
    unsigned int state;
    StackSemantics semantics;
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

    bool parse (TokenArray & tok_arr, NFA<slab_allocator<> > & nfa);
};

#endif // __LJS_PARSER__
