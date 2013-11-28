#include <stdio.h>

#include "exec.h"

void Exec::add_thread (ThreadList * l, State * s, Submatch * sm, const unsigned char * input)
{
    if (s->step == step)
    {
        decref (sm);
        return;
    }
    s->step = step;
    switch (s->type)
    {
        case NFA_ALT:
            add_thread (l, s->to<StateAlt> ()->out1, incref (sm), input);
            add_thread (l, s->to<StateAlt> ()->out2, sm, input);
            break;
        case NFA_ASSERT_START:
            if (input == input_start)
                add_thread (l, s->to<StateAssertStart> ()->out, sm, input);
            else
                decref (sm);
            break;
        case NFA_ASSERT_END:
            if (input == input_end)
                add_thread (l, s->to<StateAssertEnd> ()->out, sm, input);
            else
                decref (sm);
            break;
        case NFA_ASSERT_WORD:
        {
            const StateAssertWord * p = s->to<StateAssertWord> ();
            if (input == input_start || input + 1 == input_end)
                return;
            const char c1 = * (input - 1);
            const char c2 = * input;
            if (is_word_rune (c1) ^ is_word_rune (c2) ^ !p->is_positive)
                add_thread (l, p->out, sm, input);
            else
                decref (sm);
            break;
        }
        case NFA_ASSERT_FOLLOW:
        {
            const StateAssertFollow * p = s->to<StateAssertFollow> ();
            const bool is_followed_by = bfs (p->out1, input);
            if ((!p->is_positive ^ is_followed_by))
                add_thread (l, p->out2, sm, input);
            else
                decref (sm);
            break;
        }
        case NFA_CAPTURE:
        {
            const StateCapture * p = s->to<StateCapture> ();
            add_thread (l, p->out, update (sm, p->sub, input), input);
            break;
        }
        case NFA_EMPTY:
            add_thread (l, s->to<StateEmpty> ()->out, sm, input);
            break;
        case NFA_NOLAMBDA:
            add_thread (l, s->to<StateNolambda> ()->out, sm, input);
            break;
        default:
            l->threads[l->size].state = s;
            l->threads[l->size].submatch = sm;
            ++ l->size;
            break;
    }
}

bool Exec::bfs (State * start, const unsigned char * input)
{
    ThreadList cl (size);
    ThreadList nl (size);
    ThreadList * clist = & cl;
    ThreadList * nlist = & nl;

    ++ step;
    Submatch * sm = new Submatch (captures);
    add_thread (clist, start, sm, input);
    for (; clist->size > 0; ++ input)
    {
        ++ step;
        for (unsigned int i = 0; i < clist->size; ++i)
        {
            State * s = clist->threads[i].state;
            Submatch * sm = clist->threads[i].submatch;
            switch (s->type)
            {
                case NFA_BYTE:
                {
                    const StateByte * p = s->to<StateByte> ();
                    if (input != input_end
                        && * input == p->byte)
                        add_thread (nlist, p->out, sm, input + 1);
                    else
                        decref (sm);
                    break;
                }
                case NFA_BYTE_RANGE:
                {
                    const StateByteRange * p = s->to<StateByteRange> ();
                    if (input != input_end
                        && * input >= p->byte_lo
                        && * input <= p->byte_hi)
                        add_thread (nlist, p->out, sm, input + 1);
                    else
                        decref (sm);
                    break;
                }
                case NFA_ANY:
                    if (input != input_end)
                        add_thread (nlist, s->to<StateAny> ()->out, sm, input + 1);
                    else
                        decref (sm);
                    break;
                case NFA_MATCH:
printf ("bfs match\n");
                    if (match)
                        decref (submatch);
                    match = true;
                    submatch = sm;
                    for ( unsigned int j = i + 1
                        ; j < clist->size
                        ; ++ j)
                        decref (clist->threads[j].submatch);
                    goto break_for;
                default:
printf ("bfs fail\n");
                    decref (sm);
                    for ( unsigned int j = i + 1
                        ; j < clist->size
                        ; ++ j)
                        decref (clist->threads[j].submatch);
                    for ( unsigned int j = 0
                        ; j < nlist->size
                        ; ++ j)
                        decref (nlist->threads[j].submatch);
                    return false;
            }
        }
break_for:
        ThreadList * l = nlist;
        nlist = clist;
        nlist->size = 0;
        clist = l;
    }
    return match;
}

bool Exec::dfs (State * s, const unsigned char * input)
{
    switch (s->type)
    {
        case NFA_ALT:
            return dfs (s->to<StateAlt> ()->out1, input)
                || dfs (s->to<StateAlt> ()->out2, input);
        case NFA_ASSERT_START:
            return (input == input_start)
                && dfs (s->to<StateAssertStart> ()->out, input);
        case NFA_ASSERT_END:
            return (input == input_end)
                && dfs (s->to<StateAssertEnd> ()->out, input);
        case NFA_ASSERT_WORD:
        {
            const StateAssertWord * p = s->to<StateAssertWord> ();
            if (input == input_start
                || input == input_end)
                return false;
            const Rune c1 = * (input - 1);
            const Rune c2 = * input;
            return (is_word_rune (c1) ^ is_word_rune (c2)) ^ !p->is_positive
                && dfs (p->out, input);
        }
        case NFA_ASSERT_FOLLOW:
        {
            const StateAssertFollow * p = s->to<StateAssertFollow> ();
            const bool is_followed_by = dfs (p->out1, input);
            return (!p->is_positive ^ is_followed_by)
                && dfs (p->out2, input);
        }
        case NFA_BYTE:
        {
            const StateByte * p = s->to<StateByte> ();
//printf ("%u\n", p->rune);
            return (input != input_end)
                && (* input == p->byte)
                && dfs (p->out, input + 1);
        }
        case NFA_BYTE_RANGE:
        {
            const StateByteRange * p = s->to<StateByteRange> ();
            return input != input_end
                && * input >= p->byte_lo
                && * input <= p->byte_hi
                && dfs (p->out, input + 1);
        }
        case NFA_BACKREF:
        {
            const StateBackref * p = s->to<StateBackref> ();
            for ( const unsigned char * i = submatch->match[2 * p->ref]
                ; i < submatch->match[2 * p->ref + 1]
                ; ++ input, ++ i
                )
            {
                if (input == input_end
                    || * input != * i)
                    return false;
            }
            return dfs (p->out, input);
        }
        case NFA_ANY:
            return (input != input_end)
                && dfs (s->to<StateAny> ()->out, input + 1);
        case NFA_CAPTURE:
        {
            const StateCapture * p = s->to<StateCapture> ();
            const unsigned char * old = submatch->match[p->sub];
            submatch->match[p->sub] = input;
            if (dfs (p->out, input))
                return true;
            else
            {
                submatch->match[p->sub] = old;
                return false;
            }
        }
        case NFA_EMPTY:
            return dfs (s->to<StateEmpty> ()->out, input);
        case NFA_MATCH:
printf ("dfs match\n");
            match = true;
            return true;
        case NFA_NOLAMBDA:
        {
            StateNolambda * p = s->to<StateNolambda> ();
            if (input > p->ptr)
            {
                p->ptr = input;
                return dfs (p->out, input);
            }
            else
                return false;
        }
    }
    return true;
}
