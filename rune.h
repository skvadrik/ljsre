#ifndef __RUNE__
#define __RUNE__

#include "vector.h"
#include "slab_allocator.hh"

typedef int Rune;
typedef vector<Rune, slab_allocator<> > RuneVector;

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

static inline bool to_rune_class (const char * , RuneVector & )
{
    return false;
}

static inline bool is_word_rune (Rune)
{
    return true;
}

static inline bool member (Rune, RuneVector *)
{
    return true;
}

#endif // __RUNE__
