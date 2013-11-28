#include "nfa_show.h"

void nfa_to_dot (const char * filename, NFA<slab_allocator<> > & nfa)
{
    FILE * f = fopen (filename, "w");

    fprintf (f, "strict digraph {\n\tgraph[rankdir=LR]\n");
    std::set<State *> closed;
    show_state (f, closed, nfa.start);
    fprintf (f, "}\n");

    fclose (f);
}

void show_state (FILE * f, std::set<State *> & closed, State * s)
{
    if (!closed.insert (s).second)
        return;
    switch (s->type)
    {
        case NFA_ALT:           show_alt           (f, closed, s); return;
        case NFA_ASSERT_START:  show_assert_start  (f, closed, s); return;
        case NFA_ASSERT_END:    show_assert_end    (f, closed, s); return;
        case NFA_ASSERT_WORD:   show_assert_word   (f, closed, s); return;
        case NFA_ASSERT_FOLLOW: show_assert_follow (f, closed, s); return;
        case NFA_BYTE:          show_byte          (f, closed, s); return;
        case NFA_BYTE_RANGE:    show_byte_range    (f, closed, s); return;
        case NFA_BACKREF:       show_backref       (f, closed, s); return;
        case NFA_ANY:           show_any           (f, closed, s); return;
        case NFA_CAPTURE:       show_capture       (f, closed, s); return;
        case NFA_EMPTY:         show_empty         (f, closed, s); return;
        case NFA_MATCH:         show_match         (f, s);         return;
        case NFA_NOLAMBDA:      show_nolambda      (f, closed, s); return;
    }
}
