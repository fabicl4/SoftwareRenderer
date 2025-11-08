#ifndef RMATH_DEFINE_H
#define RMATH_DEFINE_H

#define RMATH_VERSION 0.1

#if !defined(RMATH_USE_SIMD)
#pragma message("NO SIMD optimization")
#endif

#ifndef RMATHDEF
    #ifdef RMATH_USE_STATIC_INLINE
        #define RMATHDEF static inline
    #else
        #define RMATHDEF extern
    #endif
#endif

#endif