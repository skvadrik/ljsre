#ifndef __LJSRE_STATE__
#define __LJSRE_STATE__

//namespace ljsre {

enum StateType
    { NFA_ALT
    , NFA_ASSERT_START
    , NFA_ASSERT_END
    , NFA_ASSERT_WORD
    , NFA_ASSERT_FOLLOW
    , NFA_BYTE
    , NFA_BYTE_RANGE
    , NFA_BACKREF
    , NFA_ANY
    , NFA_CAPTURE
    , NFA_EMPTY
    , NFA_MATCH
    , NFA_NOLAMBDA
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

struct StateByte
{
    State * out;
    unsigned char byte;

    StateByte
        ( State * o
        , unsigned char c
        )
        : out  (o)
        , byte (c)
    { }
};

struct StateByteRange
{
    State * out;
    unsigned char byte_lo;
    unsigned char byte_hi;

    StateByteRange
        ( State * o
        , unsigned char lo
        , unsigned char hi
        )
        : out     (o)
        , byte_lo (lo)
        , byte_hi (hi)
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

struct StateNolambda
{
    State * out;
    const unsigned char * ptr;

    StateNolambda (State * o)
        : out (o)
        , ptr (0)
    { }
};

//}; // namespace ljsre

#endif // __LJSRE_STATE__
