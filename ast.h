#include "rune.h"

enum RENodeType
    { RE_ALT
    , RE_CAT
    , RE_ZERO_ONE
    , RE_ZERO_MANY
    , RE_ONE_MANY
    , RE_TIMES
    , RE_TIMES_FROM
    , RE_TIMES_FROM_TO
    , RE_ASSERT_START
    , RE_ASSERT_END
    , RE_ASSERT_WORD
    , RE_ASSERT_FOLLOW
    , RE_RUNE
    , RE_BACKREF
    , RE_CLASS
    , RE_DOT
    , RE_CAPTURE
    , RE_EMPTY
    };

struct REAlt
{
    const RENodeType type;
    void * e1;
    void * e2;

    REAlt
        ( void * e1_
        , void * e2_
        )
        : type (RE_ALT)
        , e1   (e1_)
        , e2   (e2_)
    { }
};

struct RECat
{
    const RENodeType type;
    void * e1;
    void * e2;

    RECat
        ( void * e1_
        , void * e2_
        )
        : type (RE_CAT)
        , e1   (e1_)
        , e2   (e2_)
    { }
};

struct REZeroOne
{
    const RENodeType type;
    void * e;
    bool is_greedy;

    REZeroOne
        ( void * e_
        , bool g
        )
        : type      (RE_ZERO_ONE)
        , e         (e_)
        , is_greedy (g)
    { }
};

struct REZeroMany
{
    const RENodeType type;
    void * e;
    bool is_greedy;

    REZeroMany
        ( void * e_
        , bool g
        )
        : type      (RE_ZERO_MANY)
        , e         (e_)
        , is_greedy (g)
    { }
};

struct REOneMany
{
    const RENodeType type;
    void * e;
    bool is_greedy;

    REOneMany
        ( void * e_
        , bool g
        )
        : type      (RE_ONE_MANY)
        , e         (e_)
        , is_greedy (g)
    { }
};

struct RETimes
{
    const RENodeType type;
    void * e;
    unsigned int times;
    bool is_greedy;

    RETimes
        ( void * e_
        , unsigned int t
        , bool g
        )
        : type      (RE_TIMES)
        , e         (e_)
        , times     (t)
        , is_greedy (g)
    { }
};

struct RETimesFrom
{
    const RENodeType type;
    void * e;
    unsigned int times_from;
    bool is_greedy;

    RETimesFrom
        ( void * e_
        , unsigned int tf
        , bool g
        )
        : type       (RE_TIMES_FROM)
        , e          (e_)
        , times_from (tf)
        , is_greedy  (g)
    { }
};

struct RETimesFromTo
{
    const RENodeType type;
    void * e;
    unsigned int times_from;
    unsigned int times_to;
    bool is_greedy;

    RETimesFromTo
        ( void * e_
        , unsigned int tf
        , unsigned int tt
        , bool g
        )
        : type       (RE_TIMES_FROM_TO)
        , e          (e_)
        , times_from (tf)
        , times_to   (tt)
        , is_greedy  (g)
    { }
};

struct REAssertStart
{
    const RENodeType type;

    REAssertStart ()
        : type (RE_ASSERT_START)
    { }
};

struct REAssertEnd
{
    const RENodeType type;

    REAssertEnd ()
        : type (RE_ASSERT_END)
    { }
};

struct REAssertWord
{
    const RENodeType type;
    bool is_inverted;

    REAssertWord (bool i)
        : type        (RE_ASSERT_WORD)
        , is_inverted (i)
    { }
};

struct REAssertFollow
{
    const RENodeType type;
    void * e;
    bool is_inverted;

    REAssertFollow
        ( void * e_
        , bool i
        )
        : type        (RE_ASSERT_FOLLOW)
        , e           (e_)
        , is_inverted (i)
    { }
};

struct RERune
{
    const RENodeType type;
    Rune rune;

    RERune (Rune r)
        : type (RE_RUNE)
        , rune (r)
    { }
};

struct REClass
{
    const RENodeType type;
    bool is_negative;
    array<Rune, slab_allocator<> > * runes;

    REClass
        ( bool i
        , array<Rune, slab_allocator<> > * rs
        )
        : type        (RE_CLASS)
        , is_negative (i)
        , runes       (rs)
    { }
};

struct REDot
{
    const RENodeType type;

    REDot ()
        : type (RE_DOT)
    { }
};

struct RECapture
{
    const RENodeType type;
    void * e;
    bool is_greedy;

    RECapture
        ( void * e_
        , bool g
        )
        : type      (RE_CAPTURE)
        , e         (e_)
        , is_greedy (g)
    { }
};

struct REBackref
{
    const RENodeType type;
    unsigned int n;

    REBackref (unsigned int n_)
        : type (RE_BACKREF)
        , n    (n_)
    { }
};

struct REEmpty
{
    const RENodeType type;

    REEmpty ()
        : type (RE_EMPTY)
    { }
};
