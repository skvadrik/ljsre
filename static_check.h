#ifndef __LJS_STATIC_CHECK__
#define __LJS_STATIC_CHECK__

template <bool> struct CompileTimeError;
template <> struct CompileTimeError<true> {};

#define STATIC_CHECK(expr, msg) \
    { CompileTimeError<((expr) != 0)> ERROR_##msg; (void)ERROR_##msg; }

#endif // __LJS_STATIC_CHECK__
