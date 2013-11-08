#include <string.h>
#include <stdio.h>

#include "lex.h"
#include "parser.h"

int main (int argc, char ** argv)
{
    if (argc != 2)
        return 1;

    slab_allocator<> allocator;
    TokenArray tok_arr (strlen (argv[1]) + 1 /* eof token */);
    REArray re_arr (2 * strlen (argv[1]));
    Parser parser;

    if (!lex (argv[1], strlen (argv[1]), tok_arr, re_arr, allocator))
    {
        printf ("syntax error (lex)\n");
        return 2;
    }

    tok_arr.index = 0;
    if (parser.parse (tok_arr, re_arr, allocator) == NULL)
    {
        printf ("syntax error (parse)\n");
        return 3;
    }

    return 0;
}
