#ifndef __RUNE_RANGES__
#define __RUNE_RANGES__

#include "rune.h"

typedef std::pair <Rune, Rune> RuneRange;

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
    RuneRanges::iterator i = rs->begin ();
    Rune * rightmost = &(i->second);
    for (++i; i != rs->end (); ++i)
    {
        if (i->first < * rightmost)
        {
            if (i->second > * rightmost)
                * rightmost = i->second;
            rs->erase (i);
        }
        else
            rightmost = &(i->second);
    }
}

static inline void negate_ranges (RuneRanges *)
{
}

#endif // __RUNE_RANGES__
