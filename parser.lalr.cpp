

#include <stddef.h> // NULL

#include "ast.h"
#include "debug_parser.h"
#include "parser.h"

bool Parser::parse (TokenArray & tok_arr, slab_allocator<> & allocator)
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_LAMBDA:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_17;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_10;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_13;
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
            case T_CLASS_END:
            case T_CLASS_UNBOXED:
            case T_RUNE_UNBOXED:
                goto lalr2c_reduce_1;
            case T_DASH:
                goto lalr2c_state_21;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_9;
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_RBRACE:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
                goto lalr2c_state_12;
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_RBRACE:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
                goto lalr2c_state_12;
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_RBRACE:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
                goto lalr2c_state_12;
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_RBRACE:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_15;
            default:
                { return false; }
        }
    lalr2c_state_13:
        LALR2C_RW_STACK_STATE (0) = 13;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_38;
            case T_ALT:
                goto lalr2c_state_31;
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_14:
        LALR2C_RW_STACK_STATE (0) = 14;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_22;
            default:
                { return false; }
        }
    lalr2c_state_15:
        LALR2C_RW_STACK_STATE (0) = 15;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_TIMES_FROM:
                goto lalr2c_state_25;
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_26;
            case T_ONE_MANY:
                goto lalr2c_state_23;
            case T_TIMES:
                goto lalr2c_state_24;
            case T_ZERO_MANY:
                goto lalr2c_state_27;
            case T_TIMES_FROM_TO:
                goto lalr2c_state_26;
            case T_ZERO_ONE:
                goto lalr2c_state_28;
            default:
                { return false; }
        }
    lalr2c_state_16:
        LALR2C_RW_STACK_STATE (0) = 16;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_12;
            default:
                { return false; }
        }
    lalr2c_state_17:
        LALR2C_RW_STACK_STATE (0) = 17;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_LAMBDA:
                goto lalr2c_reduce_39;
            default:
                { return false; }
        }
    lalr2c_state_18:
        LALR2C_RW_STACK_STATE (0) = 18;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_LAMBDA:
                goto lalr2c_fin;
            default:
                { return false; }
        }
    lalr2c_state_19:
        LALR2C_RW_STACK_STATE (0) = 19;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_33;
            default:
                { return false; }
        }
    lalr2c_state_20:
        LALR2C_RW_STACK_STATE (0) = 20;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_36;
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
            case T_CLASS_END:
            case T_CLASS_UNBOXED:
            case T_DASH:
            case T_RUNE_UNBOXED:
                goto lalr2c_reduce_1;
            default:
                { return false; }
        }
    lalr2c_state_22:
        LALR2C_RW_STACK_STATE (0) = 22;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_DASH:
                goto lalr2c_state_47;
            case T_CLASS_UNBOXED:
                goto lalr2c_state_46;
            case T_RUNE_UNBOXED:
                goto lalr2c_state_48;
            case T_CLASS_END:
                goto lalr2c_state_45;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_25;
            case T_ZERO_ONE:
                goto lalr2c_state_40;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_32;
            case T_ZERO_ONE:
                goto lalr2c_state_36;
            default:
                { return false; }
        }
    lalr2c_state_25:
        LALR2C_RW_STACK_STATE (0) = 25;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_31;
            case T_ZERO_ONE:
                goto lalr2c_state_42;
            default:
                { return false; }
        }
    lalr2c_state_26:
        LALR2C_RW_STACK_STATE (0) = 26;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_30;
            case T_ZERO_ONE:
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_29;
            case T_ZERO_ONE:
                goto lalr2c_state_43;
            default:
                { return false; }
        }
    lalr2c_state_28:
        LALR2C_RW_STACK_STATE (0) = 28;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_28;
            case T_ZERO_ONE:
                goto lalr2c_state_35;
            default:
                { return false; }
        }
    lalr2c_state_29:
        LALR2C_RW_STACK_STATE (0) = 29;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_44;
            default:
                { return false; }
        }
    lalr2c_state_30:
        LALR2C_RW_STACK_STATE (0) = 30;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_41;
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
            case T_LBRACE_FOLLOW:
                goto lalr2c_state_9;
            case T_ASSERT:
                goto lalr2c_state_3;
            case T_ALT:
                goto lalr2c_state_2;
            case T_BACKREF:
                goto lalr2c_state_4;
            case T_DOT:
                goto lalr2c_state_7;
            case T_CLASS_START:
                goto lalr2c_state_6;
            case T_LBRACE_CAPTURE:
                goto lalr2c_state_8;
            case T_LBRACE_LAZY:
                goto lalr2c_state_11;
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_37;
            case T_LBRACE_FOLLOW_NOT:
                goto lalr2c_state_10;
            case T_CLASS:
                goto lalr2c_state_5;
            case T_RUNE:
                goto lalr2c_state_12;
            default:
                { return false; }
        }
    lalr2c_state_32:
        LALR2C_RW_STACK_STATE (0) = 32;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
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
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_49;
            default:
                { return false; }
        }
    lalr2c_state_34:
        LALR2C_RW_STACK_STATE (0) = 34;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
                goto lalr2c_state_50;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_27;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_23;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_20;
            default:
                { return false; }
        }
    lalr2c_state_38:
        LALR2C_RW_STACK_STATE (0) = 38;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_UNBOXED:
                goto lalr2c_state_46;
            case T_RUNE_UNBOXED:
                goto lalr2c_state_48;
            case T_CLASS_END:
                goto lalr2c_state_51;
            case T_DASH:
                goto lalr2c_state_52;
            default:
                { return false; }
        }
    lalr2c_state_39:
        LALR2C_RW_STACK_STATE (0) = 39;
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_RBRACE:
            case T_LAMBDA:
                goto lalr2c_reduce_35;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_21;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_14;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_19;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_24;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_18;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_8;
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
            case T_CLASS_END:
            case T_CLASS_UNBOXED:
            case T_DASH:
            case T_RUNE_UNBOXED:
                goto lalr2c_reduce_4;
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
            case T_CLASS_END:
                goto lalr2c_state_54;
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
            case T_DASH:
                goto lalr2c_state_53;
            case T_CLASS_END:
            case T_CLASS_UNBOXED:
            case T_RUNE_UNBOXED:
                goto lalr2c_reduce_3;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_RBRACE:
            case T_RUNE:
            case T_LAMBDA:
                goto lalr2c_reduce_16;
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
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_11;
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
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_5;
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
            case T_CLASS_END:
                goto lalr2c_state_56;
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
            case T_RUNE_UNBOXED:
                goto lalr2c_state_55;
            default:
                { return false; }
        }
    lalr2c_state_54:
        LALR2C_RW_STACK_STATE (0) = 54;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_6;
            default:
                { return false; }
        }
    lalr2c_state_55:
        LALR2C_RW_STACK_STATE (0) = 55;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_CLASS_END:
            case T_CLASS_UNBOXED:
            case T_DASH:
            case T_RUNE_UNBOXED:
                goto lalr2c_reduce_2;
            default:
                { return false; }
        }
    lalr2c_state_56:
        LALR2C_RW_STACK_STATE (0) = 56;
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_R_TOKEN_SEMANTICS;
        LALR2C_E_SHIFT_TOKEN ();
        LALR2C_E_RESERVE_STACK ();
        switch (LALR2C_R_TOKEN_TYPE)
        {
            case T_ALT:
            case T_ASSERT:
            case T_BACKREF:
            case T_CLASS:
            case T_CLASS_START:
            case T_DOT:
            case T_LBRACE_CAPTURE:
            case T_LBRACE_FOLLOW:
            case T_LBRACE_FOLLOW_NOT:
            case T_LBRACE_LAZY:
            case T_ONE_MANY:
            case T_RBRACE:
            case T_RUNE:
            case T_TIMES:
            case T_TIMES_FROM:
            case T_TIMES_FROM_TO:
            case T_ZERO_MANY:
            case T_ZERO_ONE:
            case T_LAMBDA:
                goto lalr2c_reduce_7;
            default:
                { return false; }
        }
    
    lalr2c_reduce_39:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Npattern;
    lalr2c_reduce_38:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_37:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REEmpty> ();
    new (LALR2C_RW_TMP_SEMANTICS) REEmpty ();
}
        LALR2C_E_POP_STACK (0);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_36:
        {
    REEmpty * p = allocator.allocate_type<REEmpty> ();
    new (p) REEmpty ();
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REAlt> (); new (LALR2C_RW_TMP_SEMANTICS) REAlt (p, LALR2C_RW_STACK_SEMANTICS (1));
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_35:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REAlt> ();
    new (LALR2C_RW_TMP_SEMANTICS) REAlt (LALR2C_RW_STACK_SEMANTICS (3), LALR2C_RW_STACK_SEMANTICS (1));
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Ndisjunction;
    lalr2c_reduce_34:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RECat> ();
    new (LALR2C_RW_TMP_SEMANTICS) RECat (LALR2C_RW_STACK_SEMANTICS (2), LALR2C_RW_STACK_SEMANTICS (1));
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nalternative;
    lalr2c_reduce_33:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nalternative;
    lalr2c_reduce_32:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RETimes> ();
    new (LALR2C_RW_TMP_SEMANTICS) RETimes (LALR2C_RW_STACK_SEMANTICS (2), * (static_cast<unsigned int *> (LALR2C_RW_STACK_SEMANTICS (1))), true);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_31:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RETimesFrom> ();
    new (LALR2C_RW_TMP_SEMANTICS) RETimesFrom (LALR2C_RW_STACK_SEMANTICS (2), * (static_cast<unsigned int *> (LALR2C_RW_STACK_SEMANTICS (1))), true);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_30:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RETimesFromTo> ();
    unsigned int * p = static_cast<unsigned int *> (LALR2C_RW_STACK_SEMANTICS (1));
    new (LALR2C_RW_TMP_SEMANTICS) RETimesFromTo (LALR2C_RW_STACK_SEMANTICS (2), p[0], p[1], true);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_29:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REZeroMany> ();
    new (LALR2C_RW_TMP_SEMANTICS) REZeroMany (LALR2C_RW_STACK_SEMANTICS (2), true);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_28:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REZeroOne> ();
    new (LALR2C_RW_TMP_SEMANTICS) REZeroOne (LALR2C_RW_STACK_SEMANTICS (2), true);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_27:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REZeroOne> ();
    new (LALR2C_RW_TMP_SEMANTICS) REZeroOne (LALR2C_RW_STACK_SEMANTICS (3), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_26:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_25:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REOneMany> ();
    new (LALR2C_RW_TMP_SEMANTICS) REOneMany (LALR2C_RW_STACK_SEMANTICS (2), true);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_24:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REZeroMany> ();
    new (LALR2C_RW_TMP_SEMANTICS) REZeroMany (LALR2C_RW_STACK_SEMANTICS (3), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_23:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RETimes> ();
    new (LALR2C_RW_TMP_SEMANTICS) RETimes (LALR2C_RW_STACK_SEMANTICS (3), * (static_cast<unsigned int *> (LALR2C_RW_STACK_SEMANTICS (2))), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_22:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_21:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REOneMany> ();
    new (LALR2C_RW_TMP_SEMANTICS) REOneMany (LALR2C_RW_STACK_SEMANTICS (3), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_20:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RETimesFromTo> ();
    unsigned int * p = static_cast<unsigned int *> (LALR2C_RW_STACK_SEMANTICS (2));
    new (LALR2C_RW_TMP_SEMANTICS) RETimesFromTo (LALR2C_RW_STACK_SEMANTICS (3), p[0], p[1], false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_19:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RETimesFrom> ();
    new (LALR2C_RW_TMP_SEMANTICS) RETimesFrom (LALR2C_RW_STACK_SEMANTICS (3), * (static_cast<unsigned int *> (LALR2C_RW_STACK_SEMANTICS (2))), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nterm;
    lalr2c_reduce_18:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REAssertFollow> ();
    new (LALR2C_RW_TMP_SEMANTICS) REAssertFollow (LALR2C_RW_STACK_SEMANTICS (2), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_17:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_16:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<REAssertFollow> ();
    new (LALR2C_RW_TMP_SEMANTICS) REAssertFollow (LALR2C_RW_STACK_SEMANTICS (2), true);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nassertion;
    lalr2c_reduce_15:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_14:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RECapture> ();
    new (LALR2C_RW_TMP_SEMANTICS) RECapture (LALR2C_RW_STACK_SEMANTICS (2), false);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_13:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_12:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_11:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<RECapture> ();
    new (LALR2C_RW_TMP_SEMANTICS) RECapture (LALR2C_RW_STACK_SEMANTICS (2), true);
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_10:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_9:
        LALR2C_E_POP_STACK (1);
        goto lalr2c_nonterminal_Natom;
    lalr2c_reduce_8:
        {
    static_cast<REClass *> (LALR2C_RW_STACK_SEMANTICS (3))->runes = static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (2));
}
        LALR2C_E_POP_STACK (3);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass;
    lalr2c_reduce_7:
        {
    const Rune r = '-';
    static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (3))->push_back (r);
    static_cast<REClass *> (LALR2C_RW_STACK_SEMANTICS (5))->runes = static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (3));
}
        LALR2C_E_POP_STACK (5);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass;
    lalr2c_reduce_6:
        {
    const Rune r = '-';
    static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (3))->push_back (r);
    static_cast<REClass *> (LALR2C_RW_STACK_SEMANTICS (4))->runes = static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (3));
}
        LALR2C_E_POP_STACK (4);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass;
    lalr2c_reduce_5:
        {
    const Rune r = '-';
    static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (2))->push_back (r);
    static_cast<REClass *> (LALR2C_RW_STACK_SEMANTICS (4))->runes = static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (2));
}
        LALR2C_E_POP_STACK (4);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass;
    lalr2c_reduce_4:
        {
    const array<Rune, slab_allocator<> > & range = * static_cast<const array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (1));
    for (unsigned int i = 0; i < range.size (); ++i)
        static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (2))->push_back (range[i]);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    lalr2c_reduce_3:
        {
    const Rune r = * static_cast<Rune *> (LALR2C_RW_STACK_SEMANTICS (1));
    static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (2))->push_back (r);
}
        LALR2C_E_POP_STACK (2);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    lalr2c_reduce_2:
        {
    const Rune r1 = * static_cast<Rune *> (LALR2C_RW_STACK_SEMANTICS (3));
    const Rune r2 = * static_cast<Rune *> (LALR2C_RW_STACK_SEMANTICS (1));
    const Rune r = r2 << 16 | r1;
    static_cast<array<Rune, slab_allocator<> > *> (LALR2C_RW_STACK_SEMANTICS (4))->push_back (r);
}
        LALR2C_E_POP_STACK (4);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    lalr2c_reduce_1:
        {
    LALR2C_RW_TMP_SEMANTICS = allocator.allocate_type<array<Rune, slab_allocator<> > > ();
    new (LALR2C_RW_TMP_SEMANTICS) array<Rune, slab_allocator<> > (allocator);
}
        LALR2C_E_POP_STACK (0);
        LALR2C_RW_STACK_SEMANTICS (0) = LALR2C_RW_TMP_SEMANTICS;
        goto lalr2c_nonterminal_Nclass_ranges;
    
    lalr2c_nonterminal_Nalternative:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 8:
            case 9:
            case 10:
            case 11:
            case 31:
                goto lalr2c_state_13;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nassertion:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 8:
            case 9:
            case 10:
            case 11:
            case 13:
            case 31:
                goto lalr2c_state_14;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Natom:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 8:
            case 9:
            case 10:
            case 11:
            case 13:
            case 31:
                goto lalr2c_state_15;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nclass:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
            case 2:
            case 8:
            case 9:
            case 10:
            case 11:
            case 13:
            case 31:
                goto lalr2c_state_16;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nclass_ranges:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 6:
                goto lalr2c_state_22;
            case 21:
                goto lalr2c_state_38;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Ndisjunction:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
                goto lalr2c_state_17;
            case 10:
                goto lalr2c_state_33;
            case 8:
                goto lalr2c_state_34;
            case 2:
                goto lalr2c_state_20;
            case 31:
                goto lalr2c_state_39;
            case 9:
                goto lalr2c_state_29;
            case 11:
                goto lalr2c_state_30;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Npattern:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 1:
                goto lalr2c_state_18;
            default:
                { return false; }
        }
    lalr2c_nonterminal_Nterm:
        switch (LALR2C_RW_STACK_STATE (1))
        {
            case 13:
                goto lalr2c_state_32;
            case 1:
            case 2:
            case 8:
            case 9:
            case 10:
            case 11:
            case 31:
                goto lalr2c_state_19;
            default:
                { return false; }
        }
    
    lalr2c_fin:



    return true;

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

