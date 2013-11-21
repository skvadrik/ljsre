#include <string.h>
#include <stdio.h>

#include "lex.h"
#include "nfa.h"
#include "nfa_show.h"
#include "exec.h"
#include "parser.h"

int main (int argc, char ** argv)
{
    if (argc != 2)
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

    Exec exec (0, 0, nfa.captures, nfa.size);
//    exec.bfs (nfa.start, exec.input_start);
    exec.dfs (nfa.start, exec.input_start);

    return 0;
}
