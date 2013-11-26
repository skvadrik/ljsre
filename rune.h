#ifndef __RUNE__
#define __RUNE__

#include <map>

#include "slab_allocator.hh"

typedef int Rune;
typedef std::map <Rune, Rune> RuneRanges;

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

static inline bool to_rune_class (const char * , RuneRanges &)
{
// must normalize and negate
    return false;
}
/*
static inline bool is_word_char (unsigned char c)
{
    return ('A' <= c && c <= 'Z') ||
           ('a' <= c && c <= 'z') ||
           ('0' <= c && c <= '9') ||
           c == '_';
}
*/
static inline bool is_word_rune (Rune)
{
    return true;
}

static inline bool member (Rune, RuneRanges *)
{
    return true;
}

#endif // __RUNE__
