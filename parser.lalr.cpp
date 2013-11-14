

#include <stddef.h> // NULL

#include "debug_parser.h"
#include "parser.h"

bool Parser::parse (TokenArray & tok_arr, NFA<slab_allocator<> > & nfa, slab_allocator<> & allocator)
{
    StackSemantics semantics;

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
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_LAMBDA:
                goto lalr2c_reduce_39;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_2:
        LALR2C_RW_STACK_STATE (0) = 2;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_39;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_3:
        LALR2C_RW_STACK_STATE (0) = 3;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_18;
            default:
                { return false; }
        }
    lalr2c_state_4:
        LALR2C_RW_STACK_STATE (0) = 4;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_RBRACE:
                goto lalr2c_reduce_39;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_17;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_11;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_14;
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
            case T_DASH:
                goto lalr2c_state_27;
            case T_CLASS:
            case T_CLASS_END:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_2;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_10;
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
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_RBRACE:
                goto lalr2c_reduce_39;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
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
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_RBRACE:
                goto lalr2c_reduce_39;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_16;
            default:
                { return false; }
        }
    lalr2c_state_14:
        LALR2C_RW_STACK_STATE (0) = 14;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_ALT:
                goto lalr2c_state_24;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_40;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_15:
        LALR2C_RW_STACK_STATE (0) = 15;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_26;
            default:
                { return false; }
        }
    lalr2c_state_16:
        LALR2C_RW_STACK_STATE (0) = 16;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ONE_MANY:
                goto lalr2c_state_31;
            case T_NUMBER:
                goto lalr2c_state_30;
            case T_ZERO_MANY:
                goto lalr2c_state_32;
            case T_ZERO_ONE:
                goto lalr2c_state_33;
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_31;
            default:
                { return false; }
        }
    lalr2c_state_17:
        LALR2C_RW_STACK_STATE (0) = 17;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_13;
            default:
                { return false; }
        }
    lalr2c_state_18:
        LALR2C_RW_STACK_STATE (0) = 18;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_LAMBDA:
                goto lalr2c_reduce_41;
            default:
                { return false; }
        }
    lalr2c_state_19:
        LALR2C_RW_STACK_STATE (0) = 19;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_LAMBDA:
                goto lalr2c_fin;
            default:
                { return false; }
        }
    lalr2c_state_20:
        LALR2C_RW_STACK_STATE (0) = 20;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_35;
            default:
                { return false; }
        }
    lalr2c_state_21:
        LALR2C_RW_STACK_STATE (0) = 21;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_35;
            default:
                { return false; }
        }
    lalr2c_state_22:
        LALR2C_RW_STACK_STATE (0) = 22;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_34;
            default:
                { return false; }
        }
    lalr2c_state_23:
        LALR2C_RW_STACK_STATE (0) = 23;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_38;
            default:
                { return false; }
        }
    lalr2c_state_24:
        LALR2C_RW_STACK_STATE (0) = 24;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_START:
                goto lalr2c_state_9;
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_39;
            case T_ASSERT_END:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_RUNE:
                goto lalr2c_state_13;
            case T_ASSERT_FOLLOW:
                goto lalr2c_state_4;
            case T_BACKREF:
                goto lalr2c_state_7;
            case T_ASSERT_WORD:
                goto lalr2c_state_6;
            case T_CLASS:
                goto lalr2c_state_8;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_11;
            case T_DOT:
                goto lalr2c_state_10;
            case T_ASSERT_START:
                goto lalr2c_state_5;
            case T_LBRACE_LAZY:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_25:
        LALR2C_RW_STACK_STATE (0) = 25;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_36;
            default:
                { return false; }
        }
    lalr2c_state_26:
        LALR2C_RW_STACK_STATE (0) = 26;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_37;
            default:
                { return false; }
        }
    lalr2c_state_27:
        LALR2C_RW_STACK_STATE (0) = 27;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS:
            case T_CLASS_END:
            case T_DASH:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_2;
            default:
                { return false; }
        }
    lalr2c_state_28:
        LALR2C_RW_STACK_STATE (0) = 28;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_END:
                goto lalr2c_state_36;
            default:
                { return false; }
        }
    lalr2c_state_29:
        LALR2C_RW_STACK_STATE (0) = 29;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RUNE:
                goto lalr2c_state_45;
            case T_CLASS:
                goto lalr2c_state_43;
            case T_CLASS_END:
                goto lalr2c_reduce_5;
            case T_DASH:
                goto lalr2c_state_44;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_22;
            case T_ZERO_ONE:
                goto lalr2c_state_41;
            case T_COMMA:
                goto lalr2c_state_40;
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
            case T_ZERO_ONE:
                goto lalr2c_state_46;
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_28;
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
            case T_ZERO_ONE:
                goto lalr2c_state_47;
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_34;
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
            case T_ZERO_ONE:
                goto lalr2c_state_38;
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_33;
            default:
                { return false; }
        }
    lalr2c_state_34:
        LALR2C_RW_STACK_STATE (0) = 34;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_20;
            default:
                { return false; }
        }
    lalr2c_state_35:
        LALR2C_RW_STACK_STATE (0) = 35;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_15;
            default:
                { return false; }
        }
    lalr2c_state_36:
        LALR2C_RW_STACK_STATE (0) = 36;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_9;
            default:
                { return false; }
        }
    lalr2c_state_37:
        LALR2C_RW_STACK_STATE (0) = 37;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_NUMBER:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_12;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_32;
            default:
                { return false; }
        }
    lalr2c_state_39:
        LALR2C_RW_STACK_STATE (0) = 39;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_DASH:
                goto lalr2c_state_48;
            case T_RUNE:
                goto lalr2c_state_45;
            case T_CLASS:
                goto lalr2c_state_43;
            case T_CLASS_END:
                goto lalr2c_reduce_8;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_23;
            case T_ZERO_ONE:
                goto lalr2c_state_50;
            case T_NUMBER:
                goto lalr2c_state_49;
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
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_24;
            default:
                { return false; }
        }
    lalr2c_state_42:
        LALR2C_RW_STACK_STATE (0) = 42;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_37;
            default:
                { return false; }
        }
    lalr2c_state_43:
        LALR2C_RW_STACK_STATE (0) = 43;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS:
            case T_CLASS_END:
            case T_DASH:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_3;
            default:
                { return false; }
        }
    lalr2c_state_44:
        LALR2C_RW_STACK_STATE (0) = 44;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_END:
                goto lalr2c_reduce_6;
            default:
                { return false; }
        }
    lalr2c_state_45:
        LALR2C_RW_STACK_STATE (0) = 45;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_DASH:
                goto lalr2c_state_51;
            case T_CLASS:
            case T_CLASS_END:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_4;
            default:
                { return false; }
        }
    lalr2c_state_46:
        LALR2C_RW_STACK_STATE (0) = 46;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_21;
            default:
                { return false; }
        }
    lalr2c_state_47:
        LALR2C_RW_STACK_STATE (0) = 47;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_27;
            default:
                { return false; }
        }
    lalr2c_state_48:
        LALR2C_RW_STACK_STATE (0) = 48;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_END:
                goto lalr2c_reduce_7;
            default:
                { return false; }
        }
    lalr2c_state_49:
        LALR2C_RW_STACK_STATE (0) = 49;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_30;
            case T_ZERO_ONE:
                goto lalr2c_state_53;
            default:
                { return false; }
        }
    lalr2c_state_50:
        LALR2C_RW_STACK_STATE (0) = 50;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_25;
            default:
                { return false; }
        }
    lalr2c_state_51:
        LALR2C_RW_STACK_STATE (0) = 51;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RUNE:
                goto lalr2c_state_52;
            default:
                { return false; }
        }
    lalr2c_state_52:
        LALR2C_RW_STACK_STATE (0) = 52;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS:
            case T_CLASS_END:
            case T_DASH:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_1;
            default:
                { return false; }
        }
    lalr2c_state_53:
        LALR2C_RW_STACK_STATE (0) = 53;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT_END:
            case T_ASSERT_FOLLOW:
            case T_ASSERT_START:
            case T_ASSERT_WORD:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_29;
            default:
                { return false; }
        }
    
    lalr2c_reduce_41:
        {
    nfa.bind_match (LALR2C_RW_STACK_SEMANTICS (1).frag);
    return true;
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Npattern;
    lalr2c_reduce_40:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_39:
        {
    nfa.bind_empty (LALR2C_RW_TMP_SEMANTICS.frag);
}
        LALR2C_E_POP_STACK (0);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_38:
        {
    Frag f_empty;
    nfa.bind_empty (f_empty);
    nfa.bind_alt (LALR2C_RW_TMP_SEMANTICS.frag, f_empty, LALR2C_RW_STACK_SEMANTICS (1).frag);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_37:
        {
    nfa.bind_alt (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (3).frag, LALR2C_RW_STACK_SEMANTICS (1).frag);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_36:
        {
    nfa.bind_cat (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag, LALR2C_RW_STACK_SEMANTICS (1).frag);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nalternative;
    lalr2c_reduce_35:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nalternative;
    lalr2c_reduce_34:
        {
    nfa.bind_zero_many (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_33:
        {
    nfa.bind_zero_one (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_32:
        {
    nfa.bind_zero_one_lazy (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (3).frag);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_31:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_30:
        {
    nfa.bind_times_gteq_lteq (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (4).frag, LALR2C_RW_STACK_SEMANTICS (3).token.number, LALR2C_RW_STACK_SEMANTICS (1).token.number);
}
        LALR2C_E_POP_STACK (4);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_29:
        {
    nfa.bind_times_gteq_lteq_lazy (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (5).frag, LALR2C_RW_STACK_SEMANTICS (4).token.number, LALR2C_RW_STACK_SEMANTICS (2).token.number);
}
        LALR2C_E_POP_STACK (5);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_28:
        {
    nfa.bind_one_many (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_27:
        {
    nfa.bind_zero_many_lazy (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (3).frag);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_26:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_25:
        {
    nfa.bind_times_gteq_lazy (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (4).frag, LALR2C_RW_STACK_SEMANTICS (3).token.number);
}
        LALR2C_E_POP_STACK (4);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_24:
        {
    nfa.bind_times_eq_lazy (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (3).frag, LALR2C_RW_STACK_SEMANTICS (2).token.number);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_23:
        {
    nfa.bind_times_gteq (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (3).frag, LALR2C_RW_STACK_SEMANTICS (2).token.number);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_22:
        {
    nfa.bind_times_eq (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag, LALR2C_RW_STACK_SEMANTICS (1).token.number);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_21:
        {
    nfa.bind_one_many_lazy (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (3).frag);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_20:
        {
    nfa.bind_assert_follow (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag, LALR2C_RW_STACK_SEMANTICS (3).token.boolean);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_19:
        {
    nfa.bind_assert_word (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (1).token.boolean);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_18:
        {
    nfa.bind_assert_end (LALR2C_RW_TMP_SEMANTICS.frag);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_17:
        {
    nfa.bind_assert_start (LALR2C_RW_TMP_SEMANTICS.frag);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_16:
        {
    nfa.bind_rune (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (1).token.rune);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_15:
        {
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (2);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_14:
        {
    nfa.bind_rune_class (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (1).token.rune_vector, true);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_13:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_12:
        {
    nfa.bind_capture (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).frag);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_11:
        {
    nfa.bind_backref (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (1).token.number);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_10:
        {
    nfa.bind_any (LALR2C_RW_TMP_SEMANTICS.frag);
}
        LALR2C_E_POP_STACK (1);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_9:
        {
    nfa.bind_rune_class (LALR2C_RW_TMP_SEMANTICS.frag, LALR2C_RW_STACK_SEMANTICS (2).token.rune_vector, LALR2C_RW_STACK_SEMANTICS (3).token.boolean);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass;
    lalr2c_reduce_8:
        {
    const Rune r = '-';
    LALR2C_RW_STACK_SEMANTICS (1).token.rune_vector->push_back (r);
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (1);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_body;
    lalr2c_reduce_7:
        {
    const Rune r = '-';
    LALR2C_RW_STACK_SEMANTICS (2).token.rune_vector->push_back (r);
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (2);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_body;
    lalr2c_reduce_6:
        {
    const Rune r = '-';
    LALR2C_RW_STACK_SEMANTICS (2).token.rune_vector->push_back (r);
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (2);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_body;
    lalr2c_reduce_5:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nclass_body;
    lalr2c_reduce_4:
        {
    LALR2C_RW_STACK_SEMANTICS (2).token.rune_vector->push_back (LALR2C_RW_STACK_SEMANTICS (1).token.rune);
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (2);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    lalr2c_reduce_3:
        {
    for (unsigned int i = 0; i < LALR2C_RW_STACK_SEMANTICS (1).token.rune_vector->size (); ++i)
        LALR2C_RW_STACK_SEMANTICS (2).token.rune_vector->push_back ((* LALR2C_RW_STACK_SEMANTICS (1).token.rune_vector)[i]);
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (2);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    lalr2c_reduce_2:
        {
    LALR2C_RW_TMP_SEMANTICS.token.rune_vector = allocator.allocate_type<RuneVector> ();
    new (LALR2C_RW_TMP_SEMANTICS.token.rune_vector) RuneVector (allocator);
}
        LALR2C_E_POP_STACK (0);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    lalr2c_reduce_1:
        {
    const Rune r1 = LALR2C_RW_STACK_SEMANTICS (3).token.rune;
    const Rune r2 = LALR2C_RW_STACK_SEMANTICS (1).token.rune;
    const Rune r = r2 << 16 | r1;
    LALR2C_RW_STACK_SEMANTICS (4).token.rune_vector->push_back (r);
    LALR2C_RW_TMP_SEMANTICS = LALR2C_RW_STACK_SEMANTICS (4);
}
        LALR2C_E_POP_STACK (4);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    
    lalr2c_nonterminal_Nalternative:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 4:
            case 11:
            case 12:
            case 24:
                goto lalr2c_state_14;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nassertion:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 4:
            case 11:
            case 12:
            case 14:
            case 24:
                goto lalr2c_state_15;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Natom:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 4:
            case 11:
            case 12:
            case 14:
            case 24:
                goto lalr2c_state_16;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nclass:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 4:
            case 11:
            case 12:
            case 14:
            case 24:
                goto lalr2c_state_17;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nclass_body:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 9:
                goto lalr2c_state_28;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nclass_ranges:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 27:
                goto lalr2c_state_39;
            case 9:
                goto lalr2c_state_29;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Ndisjunction:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
                goto lalr2c_state_18;
            case 12:
                goto lalr2c_state_21;
            case 4:
                goto lalr2c_state_22;
            case 2:
                goto lalr2c_state_23;
            case 11:
                goto lalr2c_state_26;
            case 24:
                goto lalr2c_state_42;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Npattern:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
                goto lalr2c_state_19;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nterm:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 4:
            case 11:
            case 12:
            case 24:
                goto lalr2c_state_20;
            case 14:
                goto lalr2c_state_25;
            default:
                { return false; }
        }
    
    lalr2c_fin:


    ;

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

