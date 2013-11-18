#include <stdio.h>
#include <set>

#include "nfa.h"

void nfa_to_dot (const char * filename, NFA<slab_allocator<> > & nfa);
void show_state (FILE * f, std::set<State *> & closed, State * s);

inline void show_alt (FILE * f, std::set<State *> & closed, State * s)
{
    StateAlt * sa = s->to<StateAlt> ();
    fprintf (f, "\t\"%p\" [label = \"alt\"]\n", s);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out1);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out2);
    show_state (f, closed, sa->out1);
    show_state (f, closed, sa->out2);
}

inline void show_assert_start (FILE * f, std::set<State *> & closed, State * s)
{
    StateAssertStart * sa = s->to<StateAssertStart> ();
    fprintf (f, "\t\"%p\" [label = \"assert_start\"]\n", s);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out);
    show_state (f, closed, sa->out);
}

inline void show_assert_end (FILE * f, std::set<State *> & closed, State * s)
{
    StateAssertEnd * sa = s->to<StateAssertEnd> ();
    fprintf (f, "\t\"%p\" [label = \"assert_end\"]\n", s);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out);
    show_state (f, closed, sa->out);
}

inline void show_assert_word (FILE * f, std::set<State *> & closed, State * s)
{
    StateAssertWord * sa = s->to<StateAssertWord> ();
    fprintf (f, "\t\"%p\" [label = \"assert_word, %u\"]\n", s, sa->is_positive);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out);
    show_state (f, closed, sa->out);
}

inline void show_assert_follow (FILE * f, std::set<State *> & closed, State * s)
{
    StateAssertFollow * sa = s->to<StateAssertFollow> ();
    fprintf (f, "\t\"%p\" [label = \"assert_follow, %u\"]\n", s, sa->is_positive);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out1);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out2);
    show_state (f, closed, sa->out1);
    show_state (f, closed, sa->out2);
}

inline void show_rune (FILE * f, std::set<State *> & closed, State * s)
{
    StateRune * sr = s->to<StateRune> ();
    fprintf (f, "\t\"%p\" [label = \"rune, %u\"]\n", s, sr->rune);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sr->out);
    show_state (f, closed, sr->out);
}

inline void show_rune_class (FILE * f, std::set<State *> & closed, State * s)
{
    StateRuneClass * sr = s->to<StateRuneClass> ();
    fprintf (f, "\t\"%p\" [label = \"rune, %u\"]\n", s, sr->is_positive);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sr->out);
    show_state (f, closed, sr->out);
}

inline void show_backref (FILE * f, std::set<State *> & closed, State * s)
{
    StateBackref * sb = s->to<StateBackref> ();
    fprintf (f, "\t\"%p\" [label = \"backref, %u\"]\n", s, sb->ref);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sb->out);
    show_state (f, closed, sb->out);
}

inline void show_any (FILE * f, std::set<State *> & closed, State * s)
{
    StateAny * sa = s->to<StateAny> ();
    fprintf (f, "\t\"%p\" [label = \"any\"]\n", s);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sa->out);
    show_state (f, closed, sa->out);
}

inline void show_capture (FILE * f, std::set<State *> & closed, State * s)
{
    StateCapture * sc = s->to<StateCapture> ();
    fprintf (f, "\t\"%p\" [label = \"capture\"]\n", s);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, sc->out);
    show_state (f, closed, sc->out);
}

inline void show_empty (FILE * f, std::set<State *> & closed, State * s)
{
    StateEmpty * se = s->to<StateEmpty> ();
    fprintf (f, "\t\"%p\" [label = \"empty\"]\n", s);
    fprintf (f, "\t\"%p\" -> \"%p\"\n", s, se->out);
    show_state (f, closed, se->out);
}

inline void show_match (FILE * f, State * s)
{
    fprintf (f, "\t\"%p\" [style = bold, label = \"match\"]\n", s);
}
