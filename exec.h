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
    const unsigned char * const input_start;
    const unsigned char * const input_end;
    Submatch * submatch;
    unsigned int step;
    unsigned int size;
    unsigned int captures;
    bool match;

    Exec (const unsigned char * s, unsigned int s_len, unsigned int n, unsigned int sz)
        : input_start (s)
        , input_end   (s + s_len)
        , submatch    (0)
        , step        (0)
        , size        (sz)
        , captures    (n)
        , match       (false)
    { }

    ~Exec ()
    {
        if (submatch != 0)
            delete submatch;
    }

    void add_thread (ThreadList * l, State * s, Submatch * sm, const unsigned char * input);
    bool bfs (State * start, const unsigned char * input);
    bool dfs (State * s, const unsigned char * input);

  private:
    Exec (const Exec &);
    Exec & operator = (const Exec &);
};
