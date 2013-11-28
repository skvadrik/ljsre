#ifndef __LJSRE_SUBMATCH__
#define __LJSRE_SUBMATCH__

#include <string.h>

#include "rune.h"

struct Submatch
{
    const unsigned int count;
    const unsigned char ** match;
    unsigned int ref;

    Submatch (unsigned int n)
        : count (n)
        , match (new const unsigned char * [2 * n * sizeof (unsigned char *)])
        , ref   (1)
    {
        memset (match, 0, 2 * n * sizeof (Rune *));
    }

    explicit Submatch (const Submatch & sm)
        : count (sm.count)
        , match (new const unsigned char * [2 * sm.count * sizeof (unsigned char *)])
        , ref   (1)
    {
        memcpy (match, sm.match, 2 * sm.count * sizeof (unsigned char *));
    }

    ~Submatch ()
    {
        delete [] match;
    }

  private:
    Submatch & operator = (const Submatch &);
};

static inline Submatch * incref (Submatch * sm)
{
    ++ sm->ref;
    return sm;
}

static inline void decref (Submatch * sm)
{
    -- sm->ref;
    if (sm->ref == 0)
        delete sm;
}

static inline Submatch * update
    ( Submatch * sm
    , unsigned int i
    , const unsigned char * r
    )
{
    Submatch * sm_new = sm;
    if (sm->ref > 1)
    {
        sm_new = new Submatch (* sm);
        -- sm->ref;
    }
    sm_new->match[i] = r;
    return sm_new;
}

#endif // __LJSRE_SUBMATCH__
