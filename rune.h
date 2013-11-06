#ifndef __RUNE__
#define __RUNE__

#include "array.h"
#include "slab_allocator.hh"

typedef int Rune;

static inline Rune control_to_rune (const char * )
{
    return 0;
}

static inline Rune control_letter_to_rune (const char * )
{
    return 0;
}

static inline Rune hex_to_rune (const char * )
{
    return 0;
}

static inline Rune unicode_to_rune (const char * )
{
    return 0;
}

static inline Rune identity_to_rune (const char * )
{
    return 0;
}

static inline bool to_rune_class (const char * , array<Rune, slab_allocator<> > & )
{
    return false;
}

#endif // __RUNE__
