#include "slab_allocator.hh"

#include "token_array.h"
#include "nfa.h"

bool lex
    ( const char * pattern
    , unsigned int pattern_len
    , TokenArray & tok_arr
    , NFA<slab_allocator<> > & nfa
    );
