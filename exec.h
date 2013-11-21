#include "submatch.h"
#include "nfa.h"

struct Thread
{
    State * state;
    Submatch * submatch;
};

struct ThreadList
{
    unsigned int size;
    Thread * threads;

    ThreadList (unsigned int n)
        : size    (0)
        , threads (new Thread [n])
    { }

    ~ThreadList ()
    {
        delete [] threads;
    }

  private:
    ThreadList (const ThreadList &);
    ThreadList & operator = (const ThreadList &);
};

struct Exec
{
    const Rune * const input_start;
    const Rune * const input_end;
    Submatch * submatch;
    unsigned int step;
    unsigned int size;

    Exec (const Rune * s, unsigned int s_len, unsigned int n, unsigned int sz)
        : input_start (s)
        , input_end   (s + s_len)
        , submatch    (new Submatch (n))
        , step        (0)
        , size        (sz)
    {
        incref (submatch);
    }

    ~Exec ()
    {
        delete submatch;
    }

    void add_thread (ThreadList * l, State * s, Submatch * sm, const Rune * input);
    bool bfs (State * start, const Rune * input);
    bool dfs (State * s, const Rune * input);

  private:
    Exec (const Exec &);
    Exec & operator = (const Exec &);
};
