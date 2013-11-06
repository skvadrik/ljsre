#ifndef __LJS_DEBUG_PARSER__
#define __LJS_DEBUG_PARSER__

#include <stdio.h> // fprintf, stderr

#include "token_array.h"

//#ifdef DEBUG_PARSER
#    define LALR2C_E_DEBUG_PRINT_STATE(state, is_shift)   do { debug_parser_state (state, is_shift); } while (0)
#    define LALR2C_E_DEBUG_PRINT_RULE(r)                  do { debug_parser_rule (r); } while (0)
#    define LALR2C_E_DEBUG_PRINT_NONTERMINAL(n)           do { debug_parser_nonterminal (n); } while (0)
#    define LALR2C_E_DEBUG_PRINT_TOKENS()                 do { debug_parser_tokens (tok_arr); } while (0)

/*
#else
#    define LALR2C_E_DEBUG_PRINT_STATE(state, is_shift)   do { } while (0)
#    define LALR2C_E_DEBUG_PRINT_RULE(r)                  do { } while (0)
#    define LALR2C_E_DEBUG_PRINT_NONTERMINAL(n)           do { } while (0)
#    define LALR2C_E_DEBUG_PRINT_TOKENS()                 do { } while (0)
#endif // DEBUG_PARSER
*/

static inline void debug_parser_tokens (const TokenArray & tok_arr)
{
    static const unsigned int delta = 4;

    fprintf (stderr, "\ttokens: ... ,");

    const unsigned int min_index = tok_arr.index < delta
        ? 0
        : tok_arr.index - delta;
    for (unsigned int i = min_index; i < tok_arr.index; ++i)
        fprintf (stderr, "%s,", token_typenames[tok_arr.start[i].type]);
    fprintf (stderr, "  [%s] ...\n", token_typenames[tok_arr.start[tok_arr.index].type]);
}

static inline void debug_parser_state (const char * state, const char * is_shift)
{
    fprintf (stderr, "@state %s, %s\n", state, is_shift);
}

static inline void debug_parser_rule (const char * rule)
{
    fprintf (stderr, "@rule %s\n", rule);
}

static inline void debug_parser_nonterminal (const char * nonterminal)
{
    fprintf (stderr, "@nonterminal %s\n", nonterminal);
}

#endif // __LJS__DEBUG_PARSER__
