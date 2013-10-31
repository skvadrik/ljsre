

#include "parser.h"

ParseResult Parser::parse (TokenArray & tok_arr)
{
    void * semantics = NULL;

#   define LALR2C_R_TOKEN_TYPE             tok_arr.start[tok_arr.index].type
#   define LALR2C_R_TOKEN_SEMANTICS        tok_arr.start[tok_arr.index].value

#   define LALR2C_RW_STACK_STATE(n)        (stack_top - n)->state
#   define LALR2C_RW_STACK_SEMANTICS(n)    (stack_top - n)->semantics

#   define LALR2C_E_SHIFT_TOKEN()          do { ++ tok_arr.index; } while (0)
#   define LALR2C_E_RESERVE_STACK()        do { ++ stack_top; } while (0)
#   define LALR2C_E_POP_STACK(n)           do { stack_top -= n; } while (0)

#   define LALR2C_RW_TMP_SEMANTICS         semantics

#   define LALR2C_RW_IS_1ST_CALL           is_start


    goto lalr2c_state_1;
    
    lalr2c_state_1:
        LALR2C_RW_STACK_STATE (0) = 1;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case LAMBDA:
                goto lalr2c_reduce_28;
            default:
                { return false; }
        }
    lalr2c_state_2:
        LALR2C_RW_STACK_STATE (0) = 2;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ESC_IDENTITY:
                goto lalr2c_state_15;
            case ESC_HEX:
                goto lalr2c_state_14;
            case CLASS:
                goto lalr2c_state_9;
            case ESC_INTEGER:
                goto lalr2c_state_16;
            case ESC_WORD_UPPER:
                goto lalr2c_state_19;
            case ESC_WORD_LOWER:
                goto lalr2c_state_18;
            case ESC_CONTROL_LETTER:
                goto lalr2c_state_13;
            case LBRACE:
                goto lalr2c_state_20;
            case ASSERT_START:
                goto lalr2c_state_7;
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_30;
            case LBRACE_LAZY:
                goto lalr2c_state_23;
            case LBRACE_ASSERT_YES:
                goto lalr2c_state_22;
            case ASSERT_END:
                goto lalr2c_state_6;
            case ESC_UNICODE:
                goto lalr2c_state_17;
            case CHAR:
                goto lalr2c_state_8;
            case ESC_CLASS:
                goto lalr2c_state_11;
            case DOT:
                goto lalr2c_state_10;
            case LBRACE_ASSERT_NO:
                goto lalr2c_state_21;
            case ALT:
                goto lalr2c_state_5;
            case ESC_CONLROL:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_3:
        LALR2C_RW_STACK_STATE (0) = 3;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case LAMBDA:
                goto lalr2c_reduce_32;
            default:
                { return false; }
        }
    lalr2c_state_4:
        LALR2C_RW_STACK_STATE (0) = 4;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case LAMBDA:
                goto lalr2c_fin;
            default:
                { return false; }
        }
    lalr2c_state_5:
        LALR2C_RW_STACK_STATE (0) = 5;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_28;
            default:
                { return false; }
        }
    lalr2c_state_6:
        LALR2C_RW_STACK_STATE (0) = 6;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_19;
            default:
                { return false; }
        }
    lalr2c_state_7:
        LALR2C_RW_STACK_STATE (0) = 7;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_21;
            default:
                { return false; }
        }
    lalr2c_state_8:
        LALR2C_RW_STACK_STATE (0) = 8;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_8;
            default:
                { return false; }
        }
    lalr2c_state_9:
        LALR2C_RW_STACK_STATE (0) = 9;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_5;
            default:
                { return false; }
        }
    lalr2c_state_10:
        LALR2C_RW_STACK_STATE (0) = 10;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_2;
            default:
                { return false; }
        }
    lalr2c_state_11:
        LALR2C_RW_STACK_STATE (0) = 11;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_7;
            default:
                { return false; }
        }
    lalr2c_state_12:
        LALR2C_RW_STACK_STATE (0) = 12;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_6;
            default:
                { return false; }
        }
    lalr2c_state_13:
        LALR2C_RW_STACK_STATE (0) = 13;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_10;
            default:
                { return false; }
        }
    lalr2c_state_14:
        LALR2C_RW_STACK_STATE (0) = 14;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_3;
            default:
                { return false; }
        }
    lalr2c_state_15:
        LALR2C_RW_STACK_STATE (0) = 15;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_9;
            default:
                { return false; }
        }
    lalr2c_state_16:
        LALR2C_RW_STACK_STATE (0) = 16;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_4;
            default:
                { return false; }
        }
    lalr2c_state_17:
        LALR2C_RW_STACK_STATE (0) = 17;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_11;
            default:
                { return false; }
        }
    lalr2c_state_18:
        LALR2C_RW_STACK_STATE (0) = 18;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_20;
            default:
                { return false; }
        }
    lalr2c_state_19:
        LALR2C_RW_STACK_STATE (0) = 19;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_24;
            default:
                { return false; }
        }
    lalr2c_state_20:
        LALR2C_RW_STACK_STATE (0) = 20;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_28;
            default:
                { return false; }
        }
    lalr2c_state_21:
        LALR2C_RW_STACK_STATE (0) = 21;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_28;
            default:
                { return false; }
        }
    lalr2c_state_22:
        LALR2C_RW_STACK_STATE (0) = 22;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_28;
            default:
                { return false; }
        }
    lalr2c_state_23:
        LALR2C_RW_STACK_STATE (0) = 23;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_28;
            default:
                { return false; }
        }
    lalr2c_state_24:
        LALR2C_RW_STACK_STATE (0) = 24;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_25;
            default:
                { return false; }
        }
    lalr2c_state_25:
        LALR2C_RW_STACK_STATE (0) = 25;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ONE_MANY:
                goto lalr2c_state_31;
            case COUNTED_REPEAT:
                goto lalr2c_state_30;
            case ZERO_MANY:
                goto lalr2c_state_32;
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_26;
            case ZERO_ONE:
                goto lalr2c_state_33;
            default:
                { return false; }
        }
    lalr2c_state_26:
        LALR2C_RW_STACK_STATE (0) = 26;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_29;
            default:
                { return false; }
        }
    lalr2c_state_27:
        LALR2C_RW_STACK_STATE (0) = 27;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_31;
            default:
                { return false; }
        }
    lalr2c_state_28:
        LALR2C_RW_STACK_STATE (0) = 28;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case RBRACE:
                goto lalr2c_state_40;
            default:
                { return false; }
        }
    lalr2c_state_29:
        LALR2C_RW_STACK_STATE (0) = 29;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case RBRACE:
                goto lalr2c_state_39;
            default:
                { return false; }
        }
    lalr2c_state_30:
        LALR2C_RW_STACK_STATE (0) = 30;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_13;
            default:
                { return false; }
        }
    lalr2c_state_31:
        LALR2C_RW_STACK_STATE (0) = 31;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_14;
            default:
                { return false; }
        }
    lalr2c_state_32:
        LALR2C_RW_STACK_STATE (0) = 32;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_16;
            default:
                { return false; }
        }
    lalr2c_state_33:
        LALR2C_RW_STACK_STATE (0) = 33;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_15;
            default:
                { return false; }
        }
    lalr2c_state_34:
        LALR2C_RW_STACK_STATE (0) = 34;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_27;
            default:
                { return false; }
        }
    lalr2c_state_35:
        LALR2C_RW_STACK_STATE (0) = 35;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ZERO_ONE:
                goto lalr2c_state_38;
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_18;
            default:
                { return false; }
        }
    lalr2c_state_36:
        LALR2C_RW_STACK_STATE (0) = 36;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case RBRACE:
                goto lalr2c_state_42;
            default:
                { return false; }
        }
    lalr2c_state_37:
        LALR2C_RW_STACK_STATE (0) = 37;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case RBRACE:
                goto lalr2c_state_41;
            default:
                { return false; }
        }
    lalr2c_state_38:
        LALR2C_RW_STACK_STATE (0) = 38;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_17;
            default:
                { return false; }
        }
    lalr2c_state_39:
        LALR2C_RW_STACK_STATE (0) = 39;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_12;
            default:
                { return false; }
        }
    lalr2c_state_40:
        LALR2C_RW_STACK_STATE (0) = 40;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_23;
            default:
                { return false; }
        }
    lalr2c_state_41:
        LALR2C_RW_STACK_STATE (0) = 41;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case RBRACE:
            case LAMBDA:
                goto lalr2c_reduce_22;
            default:
                { return false; }
        }
    lalr2c_state_42:
        LALR2C_RW_STACK_STATE (0) = 42;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case ALT:
            case ASSERT_END:
            case ASSERT_START:
            case CHAR:
            case CLASS:
            case COUNTED_REPEAT:
            case DOT:
            case ESC_CLASS:
            case ESC_CONLROL:
            case ESC_CONTROL_LETTER:
            case ESC_HEX:
            case ESC_IDENTITY:
            case ESC_INTEGER:
            case ESC_UNICODE:
            case ESC_WORD_LOWER:
            case ESC_WORD_UPPER:
            case LBRACE:
            case LBRACE_ASSERT_NO:
            case LBRACE_ASSERT_YES:
            case LBRACE_LAZY:
            case ONE_MANY:
            case RBRACE:
            case ZERO_MANY:
            case ZERO_ONE:
            case LAMBDA:
                goto lalr2c_reduce_1;
            default:
                { return false; }
        }
    
    lalr2c_reduce_32:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Npattern;
    lalr2c_reduce_31:
        LALR2C_E_POP_STACK (3);
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_30:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_29:
        LALR2C_E_POP_STACK (2);
        goto lalr2c_nonterminal_Nalternative;
    lalr2c_reduce_28:
        LALR2C_E_POP_STACK (0);
        goto lalr2c_nonterminal_Nalternative;
    lalr2c_reduce_27:
        LALR2C_E_POP_STACK (2);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_26:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_25:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_24:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_23:
        LALR2C_E_POP_STACK (3);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_22:
        LALR2C_E_POP_STACK (3);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_21:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_20:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_19:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_18:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nquantifier;
    lalr2c_reduce_17:
        LALR2C_E_POP_STACK (2);
        goto lalr2c_nonterminal_Nquantifier;
    lalr2c_reduce_16:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nquantifier_prefix;
    lalr2c_reduce_15:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nquantifier_prefix;
    lalr2c_reduce_14:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nquantifier_prefix;
    lalr2c_reduce_13:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nquantifier_prefix;
    lalr2c_reduce_12:
        LALR2C_E_POP_STACK (3);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_11:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_10:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_9:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_8:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_7:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_6:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_5:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_4:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_3:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_2:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_1:
        LALR2C_E_POP_STACK (3);
        goto lalr2c_nonterminal_Natom;
    
    lalr2c_nonterminal_Nalternative:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 5:
            case 20:
            case 21:
            case 22:
            case 23:
                goto lalr2c_state_2;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nassertion:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 2:
                goto lalr2c_state_24;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Natom:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 2:
                goto lalr2c_state_25;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Ndisjunction:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
                goto lalr2c_state_3;
            case 23:
                goto lalr2c_state_36;
            case 21:
                goto lalr2c_state_37;
            case 5:
                goto lalr2c_state_27;
            case 22:
                goto lalr2c_state_28;
            case 20:
                goto lalr2c_state_29;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Npattern:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
                goto lalr2c_state_4;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nquantifier:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 25:
                goto lalr2c_state_34;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nquantifier_prefix:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 25:
                goto lalr2c_state_35;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nterm:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 2:
                goto lalr2c_state_26;
            default:
                { return false; }
        }
    
    lalr2c_fin:



    return PARSE_OK;

#   undef LALR2C_R_TOKEN_TYPE
#   undef LALR2C_R_TOKEN_SEMANTICS

#   undef LALR2C_RW_STACK_STATE
#   undef LALR2C_RW_STACK_SEMANTICS

#   undef LALR2C_E_SHIFT_TOKEN
#   undef LALR2C_E_RESERVE_STACK
#   undef LALR2C_E_POP_STACK

#   undef LALR2C_RW_TMP_SEMANTICS

#   undef LALR2C_RW_IS_1ST_CALL

}

