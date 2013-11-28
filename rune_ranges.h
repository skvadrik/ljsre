#ifndef __RUNE_RANGES__
#define __RUNE_RANGES__

#include <map>

#include "rune.h"

static const unsigned int RUNE_BOUNDS = 7;

static const Rune rune_len [RUNE_BOUNDS] =
    { 1
    , 2
    , 3
    , 3
    , 4
    , 4
    , 4
    };

static const Rune rune_bounds [RUNE_BOUNDS] =
    { 0x7F
    , 0x7FF
    , 0xFFF
    , 0xFFFF
    , 0x3FFFF
    , 0xFFFFF
    , 0x10FFFF
    };

static const char * runetochar_min [RUNE_BOUNDS] =
    { "\x00"             // 0x0
    , "\xc2\x80"         // 0x80
    , "\xe0\xa0\x80"     // 0x800
    , "\xe1\x80\x80"     // 0x1000
    , "\xf0\x90\x80\x80" // 0x10000
    , "\xf1\x80\x80\x80" // 0x40000
    , "\xf4\x80\x80\x80" // 0x100000
    };

static const char * runetochar_max [RUNE_BOUNDS] =
    { "\x7f"             // 0x7F
    , "\xdf\xbf"         // 0x7FF
    , "\xe0\xbf\xbf"     // 0xFFF
    , "\xef\xbf\xbf"     // 0xFFFF
    , "\xf0\xbf\xbf\xbf" // 0x3FFFF
    , "\xf3\xbf\xbf\xbf" // 0xFFFFF
    , "\xf4\x8f\xbf\xbf" // 0x10FFFF
    };

typedef std::pair <Rune, Rune> RuneRange;
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


static inline bool add_range (RuneRanges * rs, Rune lo, Rune hi)
{
    if (hi < lo)
        return false;

    std::pair<RuneRanges::iterator, bool> p = rs->insert (RuneRange (lo, hi));
    if (!p.second)
    {
        if (p.first->second < hi)
            p.first->second = hi;
    }
    return true;
}

static inline void unite_ranges (RuneRanges * rs1, RuneRanges * rs2)
{
    for ( RuneRanges::iterator i = rs2->begin ()
        ; i != rs2->end ()
        ; ++i
        )
    {
        add_range (rs1, i->first, i->second);
    }
    delete rs2;
}

static inline void normalize_ranges (RuneRanges * rs)
{
    if (rs->size () > 1)
    {
        RuneRanges::iterator i = rs->begin ();
        Rune * rightmost = &(i->second);
        ++i;
        while (i != rs->end ())
        {
            if (i->first <= * rightmost + 1)
            {
                if (i->second > * rightmost)
                    * rightmost = i->second;

                // must increase i before the element is erased
                // and all iterators to it get invalidated
                const RuneRanges::iterator i_erase = i;
                ++i;
                rs->erase (i_erase);
            }
            else
            {
                rightmost = &(i->second);
                ++i;
            }
        }
    }
}

static inline void negate_ranges (RuneRanges *)
{
}

#endif // __RUNE_RANGES__
