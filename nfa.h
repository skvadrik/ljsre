#ifndef __LJSRE_NFA__
#define __LJSRE_NFA__

#include <stddef.h> // offsetof
#include <map>

#include "list.h"
#include "slab_allocator.hh"
#include "rune.h"

//namespace nfa {

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
    char value [];

    template <typename T>
    inline T * to ()
    {
        return reinterpret_cast<T *> (value);
    }
};

typedef list<State **, slab_allocator<> > StateList;

struct Frag
{
    State * start;
    StateList * out;

    inline void save (State * s, StateList * sl)
    {
        start = s;
        out = sl;
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

    StateCapture (State * o)
        : out (o)
    { }
};

struct StateEmpty
{
    State * out;

    StateEmpty (State * o)
        : out (o)
    { }
};

template <typename Allocator>
class NFA
{
    Allocator & allocator;

    inline State * save_alt             (State * out1, State * out2);
    inline State * save_assert_start    (State * out);
    inline State * save_assert_end      (State * out);
    inline State * save_assert_word     (State * out, bool is_positive);
    inline State * save_assert_follow   (State * out1, State * out2, bool is_positive);
    inline State * save_rune            (State * out, Rune r);
    inline State * save_rune_class      (State * out, RuneVector * rs, bool is_positive);
    inline State * save_backref         (State * out, unsigned int n);
    inline State * save_any             (State * out);
    inline State * save_capture         (State * out);
    inline State * save_empty           (State * out);
    inline State * save_match           ();

  public:
    State * start;

    explicit NFA (Allocator & a)
        : allocator (a)
        , start     (0)
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
    inline void bind_times_eq             (Frag & retf, Frag & f, int n);
    inline void bind_times_eq_lazy        (Frag & retf, Frag & f, int n);
    inline void bind_times_gteq           (Frag & retf, Frag & f, int n);
    inline void bind_times_gteq_lazy      (Frag & retf, Frag & f, int n);
    inline void bind_times_gteq_lteq      (Frag & retf, Frag & f, int n, int m);
    inline void bind_times_gteq_lteq_lazy (Frag & retf, Frag & f, int n, int m);
    inline void bind_assert_start         (Frag & retf);
    inline void bind_assert_end           (Frag & retf);
    inline void bind_assert_word          (Frag & retf, bool is_positive);
    inline void bind_assert_follow        (Frag & retf, Frag & f, bool is_positive);
    inline void bind_rune                 (Frag & retf, Rune r);
    inline void bind_rune_class           (Frag & retf, RuneVector * rs, bool is_positive);
    inline void bind_backref              (Frag & retf, unsigned int n);
    inline void bind_any                  (Frag & retf);
    inline void bind_capture              (Frag & retf, Frag & f);
    inline void bind_empty                (Frag & retf);
    inline void bind_match                (Frag & f);

    inline void copy (Frag & retf, State * s);
    inline void copy_state (Frag & retf, State * s);
    inline void copy_alt           (Frag & retf, StateAlt * s);
    inline void copy_assert_start  (Frag & retf, StateAssertStart * s);
    inline void copy_assert_end    (Frag & retf, StateAssertEnd * s);
    inline void copy_assert_word   (Frag & retf, StateAssertWord * s);
    inline void copy_assert_follow (Frag & retf, StateAssertFollow * s);
    inline void copy_rune          (Frag & retf, StateRune * s);
    inline void copy_rune_class    (Frag & retf, StateRuneClass * s);
    inline void copy_backref       (Frag & retf, StateBackref * s);
    inline void copy_any           (Frag & retf, StateAny * s);
    inline void copy_capture       (Frag & retf, StateCapture * s);
    inline void copy_empty         (Frag & retf, StateEmpty * s);
    inline void copy_match         (Frag & retf);
};

template <typename Allocator>
inline void NFA<Allocator>::copy (Frag & retf, State * s)
{
    Frag f;
    f.start = NULL;
    f.out = NULL;

    copy_state (f, s);
    std::map<State *, State *> closed;
    closed[s] = f.start;
    StateList * out = state_list ();

    for ( StateList::iterator i = f.out->head ()
        ; i != f.out->tail ()
        ; StateList::next (i)
        )
    {
        State ** ps = StateList::elem (i);
        State * s = * ps;
        if (s == NULL)
        {
            out->add (ps);
            continue;
        }
        std::map<State *, State *>::iterator iter = closed.find (s);
        if (iter != closed.end ())
        {
            * ps = iter->second;
            continue;
        }
        else
        {
            Frag ff;
            ff.start = NULL;
            ff.out = NULL;
            copy_state (ff, s);
            * ps = ff.start;
            closed[s] = ff.start;
            f.out->append (ff.out);
        }
    }

    retf.save (f.start, out);
}

template <typename Allocator>
inline void NFA<Allocator>::copy_state (Frag & retf, State * s)
{
    switch (s->type)
    {
        case NFA_ALT:           copy_alt           (retf, s->to<StateAlt> ());          return;
        case NFA_ASSERT_START:  copy_assert_start  (retf, s->to<StateAssertStart> ());  return;
        case NFA_ASSERT_END:    copy_assert_end    (retf, s->to<StateAssertEnd> ());    return;
        case NFA_ASSERT_WORD:   copy_assert_word   (retf, s->to<StateAssertWord> ());   return;
        case NFA_ASSERT_FOLLOW: copy_assert_follow (retf, s->to<StateAssertFollow> ()); return;
        case NFA_RUNE:          copy_rune          (retf, s->to<StateRune> ());         return;
        case NFA_RUNE_CLASS:    copy_rune_class    (retf, s->to<StateRuneClass> ());    return;
        case NFA_BACKREF:       copy_backref       (retf, s->to<StateBackref> ());      return;
        case NFA_ANY:           copy_any           (retf, s->to<StateAny> ());          return;
        case NFA_CAPTURE:       copy_capture       (retf, s->to<StateCapture> ());      return;
        case NFA_EMPTY:         copy_empty         (retf, s->to<StateEmpty> ());        return;
        case NFA_MATCH:         copy_match         (retf);                              return;
    }
}

template <typename Allocator>
inline void NFA<Allocator>::copy_alt (Frag & retf, StateAlt * s)
{
    retf.start = save_alt (s->out1, s->out2);
    retf.out = state_list (&(retf.start->to<StateAlt> ()->out1));
    retf.out->add (&(retf.start->to<StateAlt> ()->out2));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_assert_start (Frag & retf, StateAssertStart * s)
{
    retf.start = save_assert_start (s->out);
    retf.out = state_list (&(retf.start->to<StateAssertStart> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_assert_end (Frag & retf, StateAssertEnd * s)
{
    retf.start = save_assert_end (s->out);
    retf.out = state_list (&(retf.start->to<StateAssertEnd> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_assert_word (Frag & retf, StateAssertWord * s)
{
    retf.start = save_assert_word (s->out, s->is_positive);
    retf.out = state_list (&(retf.start->to<StateAssertWord> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_assert_follow (Frag & retf, StateAssertFollow * s)
{
    retf.start = save_assert_follow (s->out1, s->out2, s->is_positive);
    retf.out = state_list (&(retf.start->to<StateAssertFollow> ()->out1));
    retf.out->add (&(retf.start->to<StateAssertFollow> ()->out2));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_rune (Frag & retf, StateRune * s)
{
    retf.start = save_rune (s->out, s->rune);
    retf.out = state_list (&(retf.start->to<StateRune> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_rune_class (Frag & retf, StateRuneClass * s)
{
    retf.start = save_rune_class (s->out, s->runes, s->is_positive);
    retf.out = state_list (&(retf.start->to<StateRuneClass> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_backref (Frag & retf, StateBackref * s)
{
    retf.start = save_backref (s->out, s->ref);
    retf.out = state_list (&(retf.start->to<StateBackref> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_any (Frag & retf, StateAny * s)
{
    retf.start = save_any (s->out);
    retf.out = state_list (&(retf.start->to<StateCapture> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_capture (Frag & retf, StateCapture * s)
{
    retf.start = save_capture (s->out);
    retf.out = state_list (&(retf.start->to<StateCapture> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_empty (Frag & retf, StateEmpty * s)
{
    retf.start = save_empty (s->out);
    retf.out = state_list (&(retf.start->to<StateEmpty> ()->out));
}

template <typename Allocator>
inline void NFA<Allocator>::copy_match (Frag & retf)
{
    retf.start = save_match ();
    retf.out = NULL;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_alt (State * out1, State * out2)
{
    State * s = alloc_state<StateAlt> ();
    s->type = NFA_ALT;
    new (s->value) StateAlt (out1, out2);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_start (State * out)
{
    State * s = alloc_state<StateAssertStart> ();
    s->type = NFA_ASSERT_START;
    new (s->value) StateAssertStart (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_end (State * out)
{
    State * s = alloc_state<StateAssertEnd> ();
    s->type = NFA_ASSERT_END;
    new (s->value) StateAssertEnd (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_word (State * out, bool is_positive)
{
    State * s = alloc_state<StateAssertWord> ();
    s->type = NFA_ASSERT_WORD;
    new (s->value) StateAssertWord (out, is_positive);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_assert_follow (State * out1, State * out2, bool is_positive)
{
    State * s = alloc_state<StateAssertFollow> ();
    s->type = NFA_ASSERT_FOLLOW;
    new (s->value) StateAssertFollow (out1, out2, is_positive);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_rune (State * out, Rune r)
{
    State * s = alloc_state<StateRune> ();
    s->type = NFA_RUNE;
    new (s->value) StateRune (out, r);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_rune_class (State * out, RuneVector * rs, bool is_positive)
{
    State * s = alloc_state<StateRuneClass> ();
    s->type = NFA_RUNE_CLASS;
    new (s->value) StateRuneClass (out, rs, is_positive);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_backref (State * out, unsigned int n)
{
    State * s = alloc_state<StateBackref> ();
    s->type = NFA_BACKREF;
    new (s->value) StateBackref (out, n);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_any (State * out)
{
    State * s = alloc_state<StateAny> ();
    s->type = NFA_ANY;
    new (s->value) StateAny (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_capture (State * out)
{
    State * s = alloc_state<StateCapture> ();
    s->type = NFA_CAPTURE;
    new (s->value) StateCapture (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_empty (State * out)
{
    State * s = alloc_state<StateEmpty> ();
    s->type = NFA_EMPTY;
    new (s->value) StateEmpty (out);
    return s;
}

template <typename Allocator>
inline State * NFA<Allocator>::save_match ()
{
    State * s = static_cast<State *> (allocator.allocate (offsetof (State, value)));
    s->type = NFA_MATCH;
    return s;
}

template <typename Allocator>
inline void NFA<Allocator>::bind_alt (Frag & retf, Frag & f1, Frag & f2)
{
    State * s = save_alt (f1.start, f2.start);
    f1.out->append (f2.out);

    retf.save (s, f1.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_cat (Frag & retf, Frag & f1, Frag & f2)
{
    patch (f1.out, f2.start);

    retf.save (f1.start, f2.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_one (Frag & retf, Frag & f)
{
    State * s = save_alt (f.start, NULL);
    f.out->add (&(s->to<StateAlt> ()->out2));

    retf.save (s, f.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_one_lazy (Frag & retf, Frag & f)
{
    State * s = save_alt (NULL, f.start);
    f.out->add (&(s->to<StateAlt> ()->out1));

    retf.save (s, f.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_many (Frag & retf, Frag & f)
{
    State * s = save_alt (f.start, NULL);
    patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out2));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_zero_many_lazy (Frag & retf, Frag & f)
{
    State * s = save_alt (NULL, f.start);
    patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out1));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_one_many (Frag & retf, Frag & f)
{
    State * s = save_alt (f.start, NULL);
    patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out2));

    retf.save (f.start, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_one_many_lazy (Frag & retf, Frag & f)
{
    State * s = save_alt (NULL, f.start);
    patch (f.out, s);
    StateList * out = state_list (&(s->to<StateAlt> ()->out1));

    retf.save (f.start, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_eq (Frag & retf, Frag & f, int n)
{
    Frag f1 = f;
    for (int i = 0; i < n - 1; ++i)
    {
        Frag f2;
        copy (f2, f1.start);
        patch (f1.out, f2.start);
        f1 = f2;
    }

    retf.save (f.start, f1.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_eq_lazy (Frag & retf, Frag & f, int n)
{
    bind_times_eq (retf, f, n);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_gteq (Frag & retf, Frag & f, int n)
{
    Frag f2, f_tmp;
    copy (f_tmp, f.start);
    bind_one_many (f2, f_tmp);

    Frag f1;
    bind_times_eq (f1, f, n - 1);

    bind_cat (retf, f1, f2);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_gteq_lazy (Frag & retf, Frag & f, int n)
{
    Frag f2, f_tmp;
    copy (f_tmp, f.start);
    bind_one_many_lazy (f2, f_tmp);

    Frag f1;
    bind_times_eq (f1, f, n - 1);

    bind_cat (retf, f1, f2);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_gteq_lteq (Frag & retf, Frag & f, int n, int m)
{
    Frag ff;
    copy (ff, f.start);

    Frag f1;
    bind_times_eq (f1, f, n);

    Frag f2 = f1;
    for (int i = n + 1; i <= m; ++i)
    {
        Frag f3, f_tmp;
        copy (f_tmp, ff.start);
        bind_zero_one (f3, f_tmp);
        patch (f2.out, f3.start);
        f2 = f3;
    }

    retf.save (f1.start, f2.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_times_gteq_lteq_lazy (Frag & retf, Frag & f, int n, int m)
{
    Frag f1;
    bind_times_eq (f1, f, n);

    Frag f2 = f1;
    for (int i = n + 1; i <= m; ++i)
    {
        Frag f3, f_tmp;
        copy (f_tmp, f.start);
        bind_zero_one_lazy (f3, f_tmp);
        patch (f2.out, f3.start);
        f2 = f3;
    }

    retf.save (f1.start, f2.out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_start (Frag & retf)
{
    State * s = save_assert_start (NULL);
    StateList * out = state_list (&(s->to<StateAssertStart> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_end (Frag & retf)
{
    State * s = save_assert_end (NULL);
    StateList * out = state_list (&(s->to<StateAssertEnd> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_word (Frag & retf, bool is_positive)
{
    State * s = save_assert_word (NULL, is_positive);
    StateList * out = state_list (&(s->to<StateAssertWord> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_assert_follow (Frag & retf, Frag & f, bool is_positive)
{
    State * s1 = save_assert_follow (f.start, NULL, is_positive);
    State * s2 = save_match ();
    patch (f.out, s2);
    StateList * out = state_list (&(s1->to<StateAssertFollow> ()->out2));

    retf.save (s1, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_rune (Frag & retf, Rune r)
{
    State * s = save_rune (NULL, r);
    StateList * out = state_list (&(s->to<StateRune> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_rune_class (Frag & retf, RuneVector * rs, bool is_positive)
{
    State * s = save_rune_class (NULL, rs, is_positive);
    StateList * out = state_list (&(s->to<StateRuneClass> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_backref (Frag & retf, unsigned int n)
{
    State * s = save_backref (NULL, n);
    StateList * out = state_list (&(s->to<StateBackref> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_any (Frag & retf)
{
    State * s = save_any (NULL);
    StateList * out = state_list (&(s->to<StateAny> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_capture (Frag & retf, Frag & f)
{
    State * s1 = save_capture (f.start);
    State * s2 = save_capture (NULL);
    patch (f.out, s2);
    StateList * out = state_list (&(s2->to<StateCapture> ()->out));

    retf.save (s1, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_empty (Frag & retf)
{
    State * s = save_empty (NULL);
    StateList * out = state_list (&(s->to<StateEmpty> ()->out));

    retf.save (s, out);
}

template <typename Allocator>
inline void NFA<Allocator>::bind_match (Frag & f)
{
    State * s = save_match ();
    patch (f.out, s);
    start = f.start;
}

//}; // namespace nfa

#endif // __LJSRE_NFA__

