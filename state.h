#ifndef __LJSRE_STATE__
#define __LJSRE_STATE__

#include "rune.h"

//namespace ljsre {

enum StateType
    { NFA_ALT
    , NFA_ASSERT_START
    , NFA_ASSERT_END
    , NFA_ASSERT_WORD
    , NFA_ASSERT_FOLLOW
    , NFA_RUNE
    , NFA_RUNE_CLASS
    , NFA_BACKREF
    , NFA_ANY
    , NFA_CAPTURE
    , NFA_EMPTY
    , NFA_MATCH
    };

struct State
{
    StateType type;
    unsigned int step;
    char value [];

    template <typename T>
    inline T * to ()
    {
        return reinterpret_cast<T *> (value);
    }
};

struct StateAlt
{
    State * out1;
    State * out2;

    StateAlt
        ( State * o1
        , State * o2
        )
        : out1 (o1)
        , out2 (o2)
    { }
};

struct StateAssertStart
{
    State * out;

    StateAssertStart (State * o)
        : out (o)
    { }
};

struct StateAssertEnd
{
    State * out;

    StateAssertEnd (State * o)
        : out (o)
    { }
};

struct StateAssertWord
{
    State * out;
    bool is_positive;

    StateAssertWord
        ( State * o
        , bool p
        )
        : out         (o)
        , is_positive (p)
    { }
};

struct StateAssertFollow
{
    State * out1;
    State * out2;
    bool is_positive;

    StateAssertFollow
        ( State * o1
        , State * o2
        , bool p
        )
        : out1        (o1)
        , out2        (o2)
        , is_positive (p)
    { }
};

struct StateRune
{
    State * out;
    Rune rune;

    StateRune
        ( State * o
        , Rune r
        )
        : out  (o)
        , rune (r)
    { }
};

struct StateRuneClass
{
    State * out;
    RuneVector * runes;
    bool is_positive;

    StateRuneClass
        ( State * o
        , RuneVector * rs
        , bool p
        )
        : out         (o)
        , runes       (rs)
        , is_positive (p)
    { }
};

struct StateBackref
{
    State * out;
    unsigned int ref;

    StateBackref
        ( State * o
        , unsigned int n
        )
        : out (o)
        , ref (n)
    { }
};

struct StateAny
{
    State * out;

    StateAny (State * o)
        : out (o)
    { }
};

struct StateCapture
{
    State * out;
    unsigned int sub;

    StateCapture
        ( State * o
        , unsigned int s
        )
        : out (o)
        , sub (s)
    { }
};

struct StateEmpty
{
    State * out;

    StateEmpty (State * o)
        : out (o)
    { }
};

//}; // namespace ljsre

#endif // __LJSRE_STATE__