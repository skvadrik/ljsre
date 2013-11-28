#ifndef __LJSRE_NFA__
#define __LJSRE_NFA__

#include <stddef.h> // offsetof
#include <map>

#include "list.h"
#include "slab_allocator.hh"
#include "rune_ranges.h"
#include "state.h"

//namespace ljsre {

typedef list<State **, slab_allocator<> > StateList;

struct Frag
{
    State * start;
    StateList * out;
    bool has_lambda_path;

    inline void save (State * s, StateList * sl, bool b)
    {
        start = s;
        out = sl;
        has_lambda_path = b;
    }
};

static inline void patch (StateList * sl, State * s)
{
    for ( StateList::iterator i = sl->head ()
        ; i != sl->tail ()
        ; StateList::next (i)
        )
    {
        * StateList::elem (i) = s;
    }
}

template <typename Allocator>
class NFA
{
    inline State * save_alt             (State * out1, State * out2);
    inline State * save_assert_start    (State * out);
    inline State * save_assert_end      (State * out);
    inline State * save_assert_word     (State * out, bool is_positive);
    inline State * save_assert_follow   (State * out1, State * out2, bool is_positive);
    inline State * save_byte            (State * out, unsigned char byte);
    inline State * save_byte_range      (State * out, unsigned char byte_lo, unsigned char byte_hi);
    inline State * save_backref         (State * out, unsigned int n);
    inline State * save_any             (State * out);
    inline State * save_capture         (State * out, unsigned int n);
    inline State * save_empty           (State * out);
    inline State * save_match           ();
    inline State * save_nolambda        (State * out);

    State * copy_state (StateList * out, State * s);
    void copy (Frag & retf, State * s, bool b);

  public:
    Allocator & allocator;
    State * start;
    unsigned int captures;
    unsigned int size;

    explicit NFA (Allocator & a)
        : allocator (a)
        , start     (0)
        , captures  (0)
        , size      (0)
    { }

    template <typename StateType>
    State * alloc_state ()
    {
        void * p = allocator.allocate (offsetof (State, value) + sizeof (StateType));
        return static_cast<State *> (p);
    }

    inline StateList * state_list ()
    {
        StateList * sl = static_cast<StateList *> (allocator.allocate (sizeof (StateList)));
        new (sl) StateList (allocator);
        return sl;
    }

    inline StateList * state_list (State ** s)
    {
        StateList * sl = static_cast<StateList *> (allocator.allocate (sizeof (StateList)));
        new (sl) StateList (s, allocator);
        return sl;
    }

    inline void bind_alt                  (Frag & retf, Frag & f1, Frag & f2);
    inline void bind_cat                  (Frag & retf, Frag & f1, Frag & f2);
    inline void bind_zero_one             (Frag & retf, Frag & f);
    inline void bind_zero_one_lazy        (Frag & retf, Frag & f);
    inline void bind_zero_many            (Frag & retf, Frag & f);
    inline void bind_zero_many_lazy       (Frag & retf, Frag & f);
    inline void bind_one_many             (Frag & retf, Frag & f);
    inline void bind_one_many_lazy        (Frag & retf, Frag & f);
    inline void bind_times_eq             (Frag & retf, Frag & f, unsigned int n);
    inline void bind_times_gteq           (Frag & retf, Frag & f, unsigned int n);
    inline void bind_times_gteq_lazy      (Frag & retf, Frag & f, unsigned int n);
    inline bool bind_times_gteq_lteq      (Frag & retf, Frag & f, unsigned int n, unsigned int m);
    inline bool bind_times_gteq_lteq_lazy (Frag & retf, Frag & f, unsigned int n, unsigned int m);
    inline void bind_assert_start         (Frag & retf);
    inline void bind_assert_end           (Frag & retf);
    inline void bind_assert_word          (Frag & retf, bool is_positive);
    inline void bind_assert_follow        (Frag & retf, Frag & f, bool is_positive);
    inline void bind_rune                 (Frag & retf, Rune r);
    inline void bind_rune_subrange        (Frag & retf, const char * cl, const char * ch, unsigned int n);
    inline void bind_rune_range           (Frag & retf, Rune l, Rune h);
    inline void bind_rune_class           (Frag & retf, RuneRanges * rs);
    inline bool bind_backref              (Frag & retf, unsigned int n);
    inline void bind_any                  (Frag & retf);
    inline void bind_capture              (Frag & retf, Frag & f, unsigned int n);
    inline void bind_empty                (Frag & retf);
    inline void bind_match                (Frag & f);
};

template <typename Allocator>
void NFA<Allocator>::copy (Frag & retf, State * s, bool b)
{
    StateList * in = state_list ();
    retf.start = copy_state (in, s);
    retf.out = state_list ();
    retf.has_lambda_path = b;
    std::map<State *, State *> copied;

    for ( StateList::iterator i = in->head ()
        ; i != in->tail ()
        ; StateList::next (i)
        )
    {
        State ** ps = StateList::elem (i);
        State * s = * ps;
        if (s == NULL)
            retf.out->add (ps);
        else
        {
            std::pair<std::map<State *, State *>::iterator, bool> pair = copied.insert (std::pair<State *, State *> (s, NULL));
            if (pair.second)
                pair.first->second = copy_state (in, s);
            * ps = pair.first->second;
        }
    }
}

template <typename Allocator>
State * NFA<Allocator>::copy_state (StateList * out, State * s)
{
    State * s_copy = NULL;
    switch (s->type)
    {
        case NFA_ALT:
        {
            const StateAlt * p = s->to<StateAlt> ();
            s_copy = save_alt (p->out1, p->out2);
            StateAlt * q = s_copy->to<StateAlt> ();
            out->add (&(q->out1));
            out->add (&(q->out2));
            break;
        }
        case NFA_ASSERT_START:
        {
            s_copy = save_assert_start (s->to<StateAssertStart> ()->out);
            out->add (&(s_copy->to<StateAssertStart> ()->out));
            break;
        }
        case NFA_ASSERT_END:
        {
            s_copy = save_assert_end (s->to<StateAssertEnd> ()->out);
            out->add (&(s_copy->to<StateAssertEnd> ()->out));
            break;
        }
        case NFA_ASSERT_WORD:
        {
            const StateAssertWord * p = s->to<StateAssertWord> ();
            s_copy = save_assert_word (p->out, p->is_positive);
            out->add (&(s_copy->to<StateAssertWord> ()->out));
            break;
        }
        case NFA_ASSERT_FOLLOW:
        {
            const StateAssertFollow * p = s->to<StateAssertFollow> ();
            s_copy = save_assert_follow (p->out1, p->out2, p->is_positive);
            StateAssertFollow * q = s_copy->to<StateAssertFollow> ();
            out->add (&(q->out1));
            out->add (&(q->out2));
            break;
        }
        case NFA_BYTE:
        {
            const StateByte * p = s->to<StateByte> ();
            s_copy = save_byte (p->out, p->byte);
            out->add (&(s_copy->to<StateByte> ()->out));
            break;
        }
        case NFA_BYTE_RANGE:
        {
            const StateByteRange * p = s->to<StateByteRange> ();
            s_copy = save_byte_range (p->out, p->byte_lo, p->byte_hi);
            out->add (&(s_copy->to<StateByteRange> ()->out));
            break;
        }
        case NFA_BACKREF:
        {
            const StateBackref * p = s->to<StateBackref> ();
            s_copy = save_backref (p->out, p->ref);
            out->add (&(s_copy->to<StateBackref> ()->out));
            break;
        }
        case NFA_ANY:
        {
            s_copy = save_any (s->to<StateCapture> ()->out);
            out->add (&(s_copy->to<StateCapture> ()->out));
            break;
        }
        case NFA_CAPTURE:
        {
            const StateCapture * p = s->to<StateCapture> ();
            s_copy = save_capture (p->out, p->sub);
            out->add (&(s_copy->to<StateCapture> ()->out));
            break;
        }
        case NFA_EMPTY:
        {
            s_copy = save_empty (s->to<StateEmpty> ()->out);
            out->add (&(s_copy->to<StateEmpty> ()->out));
            break;
        }
        case NFA_MATCH:
        {
            s_copy = save_match ();
            break;
        }
        case NFA_NOLAMBDA:
        {
            s_copy = save_nolambda (s->to<StateNolambda> ()->out);
            out->add (&(s_copy->to<StateNolambda> ()->out));
            break;
        }
    }
    return s_copy;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_alt (State * out1, State * out2)
{
    ++ size;
    State * s = alloc_state<StateAlt> ();
    s->step = 0;
    s->type = NFA_ALT;
    new (s->value) StateAlt (out1, out2);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_start (State * out)
{
    ++ size;
    State * s = alloc_state<StateAssertStart> ();
    s->step = 0;
    s->type = NFA_ASSERT_START;
    new (s->value) StateAssertStart (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_end (State * out)
{
    ++ size;
    State * s = alloc_state<StateAssertEnd> ();
    s->step = 0;
    s->type = NFA_ASSERT_END;
    new (s->value) StateAssertEnd (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_word (State * out, bool is_positive)
{
    ++ size;
    State * s = alloc_state<StateAssertWord> ();
    s->step = 0;
    s->type = NFA_ASSERT_WORD;
    new (s->value) StateAssertWord (out, is_positive);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_follow (State * out1, State * out2, bool is_positive)
{
    ++ size;
    State * s = alloc_state<StateAssertFollow> ();
    s->step = 0;
    s->type = NFA_ASSERT_FOLLOW;
    new (s->value) StateAssertFollow (out1, out2, is_positive);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_byte (State * out, unsigned char byte)
{
    ++ size;
    State * s = alloc_state<StateByte> ();
    s->step = 0;
    s->type = NFA_BYTE;
    new (s->value) StateByte (out, byte);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_byte_range (State * out, unsigned char byte_lo, unsigned char byte_hi)
{
    ++ size;
    State * s = alloc_state<StateByteRange> ();
    s->step = 0;
    s->type = NFA_BYTE_RANGE;
    new (s->value) StateByteRange (out, byte_lo, byte_hi);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_backref (State * out, unsigned int n)
{
    ++ size;
    State * s = alloc_state<StateBackref> ();
    s->step = 0;
    s->type = NFA_BACKREF;
    new (s->value) StateBackref (out, n);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_any (State * out)
{
    ++ size;
    State * s = alloc_state<StateAny> ();
    s->step = 0;
    s->type = NFA_ANY;
    new (s->value) StateAny (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_capture (State * out, unsigned int n)
{
    ++ size;
    State * s = alloc_state<StateCapture> ();
    s->step = 0;
    s->type = NFA_CAPTURE;
    new (s->value) StateCapture (out, n);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_empty (State * out)
{
    ++ size;
    State * s = alloc_state<StateEmpty> ();
    s->step = 0;
    s->type = NFA_EMPTY;
    new (s->value) StateEmpty (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_match ()
{
    ++ size;
    State * s = static_cast<State *> (allocator.allocate (offsetof (State, value)));
    s->step = 0;
    s->type = NFA_MATCH;
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_nolambda (State * out)
{
    ++ size;
    State * s = alloc_state<StateNolambda> ();
    s->step = 0;
    s->type = NFA_NOLAMBDA;
    new (s->value) StateNolambda (out);
    return s;
}

template <typename Allocator>
inline void NFA<Allocator>::bind_alt (Frag & retf, Frag & f1, Frag & f2)
{
    State * s = save_alt (f1.start, f2.start);
    f1.out->append (f2.out);
    const bool has_lambda_path = f1.has_lambda_path || f2.has_lambda_path;

    retf.save (s, f1.out, has_lambda_path);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_cat (Frag & retf, Frag & f1, Frag & f2)
{
    patch (f1.out, f2.start);
    const bool has_lambda_path = f1.has_lambda_path && f2.has_lambda_path;

    retf.save (f1.start, f2.out, has_lambda_path);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_one (Frag & retf, Frag & f)
{
    State * s = save_alt (f.start, NULL);
    f.out->add (&(s->to<StateAlt> ()->out2));

    retf.save (s, f.out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_one_lazy (Frag & retf, Frag & f)
{
    State * s = save_alt (NULL, f.start);
    f.out->add (&(s->to<StateAlt> ()->out1));

    retf.save (s, f.out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_many (Frag & retf, Frag & f)
{
    State * s = save_alt (f.start, NULL);
    if (f.has_lambda_path)
    {
        State * s1 = save_nolambda (s);
        patch (f.out, s1);
    }
    else
        patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out2));

    retf.save (s, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_many_lazy (Frag & retf, Frag & f)
{
    State * s = save_alt (NULL, f.start);
    if (f.has_lambda_path)
    {
        State * s1 = save_nolambda (s);
        patch (f.out, s1);
    }
    else
        patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out1));

    retf.save (s, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_one_many (Frag & retf, Frag & f)
{
    State * s = save_alt (f.start, NULL);
    if (f.has_lambda_path)
    {
        State * s1 = save_nolambda (s);
        patch (f.out, s1);
    }
    else
        patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out2));

    retf.save (f.start, out, f.has_lambda_path);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_one_many_lazy (Frag & retf, Frag & f)
{
    State * s = save_alt (NULL, f.start);
    if (f.has_lambda_path)
    {
        State * s1 = save_nolambda (s);
        patch (f.out, s1);
    }
    else
        patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out1));

    retf.save (f.start, out, f.has_lambda_path);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_eq (Frag & retf, Frag & f, unsigned int n)
{
    if (n == 0)
        bind_empty (retf);
    else if (n == 1)
        retf = f;
    else
    {
        Frag f1 = f;
        for (int i = 0; i < n - 1; ++i)
        {
            Frag f2;
            copy (f2, f1.start, f.has_lambda_path);
            patch (f1.out, f2.start);
            f1 = f2;
        }
        retf.save (f.start, f1.out, f.has_lambda_path);
    }
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_gteq (Frag & retf, Frag & f, unsigned int n)
{
    if (n == 0)
        bind_zero_many (retf, f);
    else if (n == 1)
        bind_one_many (retf, f);
    else
    {
        Frag f_copy;
        copy (f_copy, f.start, f.has_lambda_path);

        Frag f1;
        bind_times_eq (f1, f, n - 1);

        Frag f2;
        bind_one_many (f2, f_copy);

        bind_cat (retf, f1, f2);
    }
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_gteq_lazy (Frag & retf, Frag & f, unsigned int n)
{
    if (n == 0)
        bind_zero_many_lazy (retf, f);
    else if (n == 1)
        bind_one_many_lazy (retf, f);
    else
    {
        Frag f_copy;
        copy (f_copy, f.start, f.has_lambda_path);

        Frag f1;
        bind_times_eq (f1, f, n - 1);

        Frag f2;
        bind_one_many_lazy (f2, f_copy);

        bind_cat (retf, f1, f2);
    }
}

template <typename Allocator>
inline bool NFA<Allocator>::bind_times_gteq_lteq (Frag & retf, Frag & f, unsigned int n, unsigned int m)
{
    if (n > m)
        return false;
    else
    {
        Frag f_copy;
        copy (f_copy, f.start, f.has_lambda_path);

        Frag f1;
        bind_times_eq (f1, f, n);

        StateList * out = f1.out;
        for (int i = n + 1; i <= m; ++i)
        {
            Frag f2;
            copy (f2, f_copy.start, f.has_lambda_path);
            Frag f3;
            bind_zero_one (f3, f2);
            patch (out, f3.start);
            out = f3.out;
        }

        retf.save (f1.start, out, f.has_lambda_path);
        return true;
    }
}

template <typename Allocator>
inline bool NFA<Allocator>::bind_times_gteq_lteq_lazy (Frag & retf, Frag & f, unsigned int n, unsigned int m)
{
    if (n > m)
        return false;
    else
    {
        Frag f_copy;
        copy (f_copy, f.start, f.has_lambda_path);

        Frag f1;
        bind_times_eq (f1, f, n);

        StateList * out = f1.out;
        for (int i = n + 1; i <= m; ++i)
        {
            Frag f2;
            copy (f2, f_copy.start, f.has_lambda_path);
            Frag f3;
            bind_zero_one_lazy (f3, f2);
            patch (out, f3.start);
            out = f3.out;
        }

        retf.save (f1.start, out, f.has_lambda_path);
        return true;
    }
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_start (Frag & retf)
{
    State * s = save_assert_start (NULL);
    StateList * out = state_list (&(s->to<StateAssertStart> ()->out));

    retf.save (s, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_end (Frag & retf)
{
    State * s = save_assert_end (NULL);
    StateList * out = state_list (&(s->to<StateAssertEnd> ()->out));

    retf.save (s, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_word (Frag & retf, bool is_positive)
{
    State * s = save_assert_word (NULL, is_positive);
    StateList * out = state_list (&(s->to<StateAssertWord> ()->out));

    retf.save (s, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_follow (Frag & retf, Frag & f, bool is_positive)
{
    State * s1 = save_assert_follow (f.start, NULL, is_positive);
    State * s2 = save_match ();
    patch (f.out, s2);
    StateList * out = state_list (&(s1->to<StateAssertFollow> ()->out2));

    retf.save (s1, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_rune (Frag & retf, Rune r)
{
    char bytes [UTFmax];
    const int bytes_count = runetochar (bytes, &r);
    State * s = save_byte (NULL, bytes[bytes_count - 1]);
    StateList * out = state_list (&(s->to<StateByte> ()->out));
    for (int i = bytes_count - 2; i >= 0; --i)
        s = save_byte (s, r);

    retf.save (s, out, false);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_rune_subrange (Frag & retf, const char * cl, const char * ch, unsigned int n)
{
    int i = n - 1;
    State * s = NULL;
    StateList * out = NULL;
fprintf (stderr, "n = %u\n", n);
    if (cl[i] == ch[i])
    {
        s = save_byte (s, cl[i]);
        out = state_list (&(s->to<StateByte> ()->out));
    }
    else
    {
        s = save_byte_range (s, cl[i], ch[i]);
        out = state_list (&(s->to<StateByteRange> ()->out));
    }
    for (--i; i >= 0; --i)
    {
        s = cl[i] == ch[i]
            ? save_byte (s, cl[i])
            : save_byte_range (s, cl[i], ch[i]);
    }
    retf.save (s, out, false);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_rune_range (Frag & retf, Rune l, Rune h)
{
    char cl [UTFmax];
    const int nl = runetochar (cl, &l);
    char ch [UTFmax];
    const int nh = runetochar (ch, &h);

    unsigned int lo = 0;
    while (lo < RUNE_BOUNDS - 1 && l > rune_bounds[lo])
        ++ lo;

    unsigned int hi = RUNE_BOUNDS - 1;
    while (hi > 0 && h < rune_bounds[hi])
        -- hi;

    if (lo < hi)
    {
        Frag f1;
        bind_rune_subrange (f1, cl, runetochar_max[lo], nl);

        Frag f11 = f1;
        for (int n = lo + 1; n < hi; ++ n)
        {
            Frag f2;
            bind_rune_subrange (f2, runetochar_min[n], runetochar_max[n], rune_len[n]);
            Frag f3;
            bind_alt (f3, f11, f2);
            f11 = f3;
        }

        Frag f2;
        bind_rune_subrange (f2, runetochar_min[hi], ch, nh);
        bind_alt (retf, f1, f2);
    }
    else
        bind_rune_subrange (retf, cl, ch, nl);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_rune_class (Frag & retf, RuneRanges * rs)
{
for (RuneRanges::iterator it = rs->begin (); it != rs->end ();  ++it)
    fprintf (stderr, "* %i - %i\n", it->first, it->second);
    RuneRanges::iterator i = rs->begin ();
    if (i == rs->end ())
        bind_empty (retf);
    else
    {
        Frag f1;
        bind_rune_range (f1, i->first, i->second);
        StateList * const out = f1.out;
        for (++i; i != rs->end (); ++i)
        {
            Frag f2;
            bind_rune_range (f2, i->first, i->second);
            Frag f3;
            bind_alt (f3, f1, f2);
            f1 = f3;
        }
        retf.save (f1.start, out, false);
    }
    delete rs;
}

template <typename Allocator>
inline bool NFA<Allocator>::bind_backref (Frag & retf, unsigned int n)
{
    if (n >= captures)
        return false;
    else
    {
        State * s = save_backref (NULL, n);
        StateList * out = state_list (&(s->to<StateBackref> ()->out));
        retf.save (s, out, true);
        return true;
    }
}

template <typename Allocator>
inline void NFA<Allocator>::bind_any (Frag & retf)
{
    State * s = save_any (NULL);
    StateList * out = state_list (&(s->to<StateAny> ()->out));

    retf.save (s, out, false);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_capture (Frag & retf, Frag & f, unsigned int n)
{
    State * s1 = save_capture (f.start, 2 * n);
    State * s2 = save_capture (NULL, 2 * n + 1);
    patch (f.out, s2);
    StateList * out = state_list (&(s2->to<StateCapture> ()->out));

    retf.save (s1, out, f.has_lambda_path);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_empty (Frag & retf)
{
    State * s = save_empty (NULL);
    StateList * out = state_list (&(s->to<StateEmpty> ()->out));

    retf.save (s, out, true);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_match (Frag & f)
{
    State * s = save_match ();
    patch (f.out, s);
    start = f.start;
}

//}; // namespace ljsre

#endif // __LJSRE_NFA__
