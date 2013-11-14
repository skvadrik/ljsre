#include "slab_allocator.hh"

#include "token_array.h"

bool lex
    ( const char * pattern
    , unsigned int pattern_len
    , TokenArray & tok_arr
    , slab_allocator<> & allocator
    );
