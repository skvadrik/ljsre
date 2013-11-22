#include <string.h>
#include <stdio.h>

#include "lex.h"
#include "nfa.h"
#include "nfa_show.h"
#include "exec.h"
#include "parser.h"

void print_submatch (Exec & exec)
{
    if (exec.match)
    {
        printf ("submatches: %u\n", exec.submatch->count);
        for (unsigned int i = 0; i < exec.submatch->count; ++i)
        {
            const Rune * r1 = exec.submatch->match[2 * i];
            const Rune * r2 = exec.submatch->match[2 * i + 1];
            if (r1 == NULL)
                printf ("(nil)\n");
            else
            {
                char * sub = new char [r2 - r1 + 1];
                unsigned int j = 0;
                for (const Rune * r = r1; r < r2; ++r, ++j)
                    sub[j] = * r;
                sub[r2 - r1] = 0;
                printf ("%s\n", sub);
                delete [] sub;
            }
        }
    }
}

int main (int argc, char ** argv)
{
    if (argc != 3)
        return 1;

    TokenArray tok_arr (strlen (argv[1]) + 1 /* eof token */);
    slab_allocator<> allocator;
    NFA<slab_allocator<> > nfa (allocator);
    Parser parser;

    if (!lex (argv[1], strlen (argv[1]), tok_arr, nfa))
    {
        printf ("syntax error (lex)\n");
        return 2;
    }

    tok_arr.index = 0;
    if (!parser.parse (tok_arr, nfa))
    {
        printf ("syntax error (parse)\n");
        return 3;
    }

    nfa_to_dot ("nfa.dot", nfa);

    const unsigned int s_len = strlen (argv[2]);
    Rune * s = new Rune [s_len];
    for (unsigned int i = 0; i < s_len; ++i)
        s[i] = argv[2][i];

#if 1
    Exec exec1 (s, s_len, nfa.captures, nfa.size);
    exec1.bfs (nfa.start, exec1.input_start);
    printf ("BFS\n");
    print_submatch (exec1);
#endif

#if 1
    Exec exec2 (s, s_len, nfa.captures, nfa.size);
    exec2.submatch = new Submatch (exec2.captures);
    exec2.dfs (nfa.start, exec2.input_start);
    printf ("DFS\n");
    print_submatch (exec2);
#endif

    delete [] s;
    return 0;
}
