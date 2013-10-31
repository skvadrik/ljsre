#include <string.h>

#include "lex.h"
#include "parser.h"

int main (int argc, char ** argv)
{
    if (argc != 2)
        return 1;

    TokenArray tok_arr (strlen (argv[1]) + 1 /* eof token */);
    Parser parser;

    if (!re_lex (argv[1], strlen (argv[1]), tok_arr))
    {
        printf ("syntax error (lex)\n");
        return 2;
    }

    tok_arr.index = 0;
    switch (!parser.parse (tok_arr))
    {
        printf ("syntax error (parse)\n");
        return 3;
    }

    return 0;
}
