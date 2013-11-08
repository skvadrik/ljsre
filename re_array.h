#ifndef __LJS_RE_ARRAY__
#define __LJS_RE_ARRAY__

#include "array.h"
#include "re.h"

typedef array<RE> REArray;

static inline RE * savere_alt (REArray & re_arr, RE * re1, RE * re2)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ALT;
    p->value.alt.alt1 = re1;
    p->value.alt.alt2 = re2;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_cat (REArray & re_arr, RE * re1, RE * re2)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_CAT;
    p->value.cat.cat1 = re1;
    p->value.cat.cat2 = re2;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_zero_one (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ZERO_ONE;
    p->value.zero_one = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_zero_one_lazy (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ZERO_ONE_LAZY;
    p->value.zero_one = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_zero_many (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ZERO_MANY;
    p->value.zero_one = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_zero_many_lazy (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ZERO_MANY_LAZY;
    p->value.zero_one = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_one_many (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ONE_MANY;
    p->value.zero_one = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_one_many_lazy (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ONE_MANY_LAZY;
    p->value.zero_one = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_times_exact (REArray & re_arr, RE * re, unsigned int n)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_TIMES_EXACT;
    p->value.times_exact.re = re;
    p->value.times_exact.exact = n;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_times_exact_lazy (REArray & re_arr, RE * re, unsigned int n)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_TIMES_EXACT_LAZY;
    p->value.times_exact.re = re;
    p->value.times_exact.exact = n;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_times_lower (REArray & re_arr, RE * re, unsigned int n)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_TIMES_LOWER;
    p->value.times_lower.re = re;
    p->value.times_lower.lower = n;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_times_lower_lazy (REArray & re_arr, RE * re, unsigned int n)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_TIMES_LOWER_LAZY;
    p->value.times_lower.re = re;
    p->value.times_lower.lower = n;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_times_lower_upper (REArray & re_arr, RE * re, unsigned int n, unsigned int m)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_TIMES_LOWER_UPPER;
    p->value.times_lower_upper.re = re;
    p->value.times_lower_upper.lower = n;
    p->value.times_lower_upper.upper = m;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_times_lower_upper_lazy (REArray & re_arr, RE * re, unsigned int n, unsigned int m)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_TIMES_LOWER_UPPER_LAZY;
    p->value.times_lower_upper.re = re;
    p->value.times_lower_upper.lower = n;
    p->value.times_lower_upper.upper = m;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_assert_start (REArray & re_arr)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ASSERT_START;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_assert_end (REArray & re_arr)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ASSERT_END;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_assert_word (REArray & re_arr)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ASSERT_WORD;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_assert_word_not (REArray & re_arr)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ASSERT_WORD_NOT;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_assert_follow (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ASSERT_FOLLOW;
    p->value.assert_follow = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_assert_follow_not (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_ASSERT_FOLLOW_NOT;
    p->value.assert_follow = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_rune (REArray & re_arr, Rune r)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_RUNE;
    p->value.rune = r;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_rune_class (REArray & re_arr, RuneVector * rs)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_RUNE_CLASS;
    p->value.rune_class = rs;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_rune_class_neg (REArray & re_arr, RuneVector * rs)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_RUNE_CLASS_NEG;
    p->value.rune_class = rs;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_backref (REArray & re_arr, unsigned int n)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_BACKREF;
    p->value.backref = n;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_dot (REArray & re_arr)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_DOT;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_capture (REArray & re_arr, RE * re)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_CAPTURE;
    p->value.capture = re;
    ++ re_arr.index;
    return p;
}

static inline RE * savere_empty (REArray & re_arr)
{
    RE * p = &re_arr.start[re_arr.index];
    p->type = RE_EMPTY;
    ++ re_arr.index;
    return p;
}

#endif // __LJS_RE_ARRAY__

