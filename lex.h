#include "slab_allocator.hh"

struct TokenArray; // forward

bool lex (const char * pattern, unsigned int pattern_len, TokenArray & tok_arr, slab_allocator<> & allocator);
