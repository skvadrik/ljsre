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
    Parser parser;

    if (!lex (argv[1], strlen (argv[1]), tok_arr, allocator))
    {
        printf ("syntax error (lex)\n");
        return 2;
    }

    tok_arr.index = 0;
    if (!parser.parse (tok_arr, allocator))
    {
        printf ("syntax error (parse)\n");
        return 3;
    }

    return 0;
}
