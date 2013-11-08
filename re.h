#ifndef __RE__
#define __RE__

#include "rune.h"

enum REType
    { RE_ALT
    , RE_CAT
    , RE_ZERO_ONE
    , RE_ZERO_ONE_LAZY
    , RE_ZERO_MANY
    , RE_ZERO_MANY_LAZY
    , RE_ONE_MANY
    , RE_ONE_MANY_LAZY
    , RE_TIMES_EXACT
    , RE_TIMES_EXACT_LAZY
    , RE_TIMES_LOWER
    , RE_TIMES_LOWER_LAZY
    , RE_TIMES_LOWER_UPPER
    , RE_TIMES_LOWER_UPPER_LAZY
    , RE_ASSERT_START
    , RE_ASSERT_END
    , RE_ASSERT_WORD
    , RE_ASSERT_WORD_NOT
    , RE_ASSERT_FOLLOW
    , RE_ASSERT_FOLLOW_NOT
    , RE_RUNE
    , RE_RUNE_CLASS
    , RE_RUNE_CLASS_NEG
    , RE_BACKREF
    , RE_DOT
    , RE_CAPTURE
    , RE_EMPTY
    };

struct RE; // forward

struct REAlt
{
    RE * alt1;
    RE * alt2;
};

struct RECat
{
    RE * cat1;
    RE * cat2;
};

struct RETimesExact
{
    RE * re;
    unsigned int exact;
};

struct RETimesLower
{
    RE * re;
    unsigned int lower;
};

struct RETimesLowerUpper
{
    RE * re;
    unsigned int lower;
    unsigned int upper;
};

struct RERuneClass
{
    RuneVector * runes;
};

union REValue
{
    REAlt             alt;
    RECat             cat;
    RE *              zero_one;
    RE *              zero_many;
    RE *              one_many;
    RETimesExact      times_exact;
    RETimesLower      times_lower;
    RETimesLowerUpper times_lower_upper;
    RE *              assert_follow;
    Rune              rune;
    RuneVector *      rune_class;
    RE *              capture;
    unsigned int      backref;
};

struct RE
{
    REType type;
    REValue value;
};

#endif // __RE__
