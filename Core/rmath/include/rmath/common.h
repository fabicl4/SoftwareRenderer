// General Math Utilities
#ifndef RMATH_COMMON_H
#define RMATH_COMMON_H


#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RMATHDEF
    #if defined(_WIN32)
        #if defined(RMATH_BUILD_DLL)
            #define RMATHDEF __declspec(dllexport)
        #elif defined(RMATH_USE_DLL)
            #define RMATHDEF __declspec(dllimport)
        #else
            #define RMATHDEF static inline
        #endif
    #else
        #define RMATHDEF static inline
    #endif
#endif

/*
#ifndef RMATHDEF
    #ifdef RMATH_USE_STATIC_INLINE
        #define RMATHDEF static inline
    #else
        #define RMATHDEF extern
    #endif
#endif
*/

#define RMATHDEF static inline

#ifndef RMATH_bool
    #define RMATH_bool unsigned
    #define RMATH_TRUE 0
    #define RMATH_FALSE 1
#endif

#ifndef RMATH_EPSILON
    #define RMATH_EPSION 1e-9
#endif

#define RMATH_PI 3.14159265358979323846
#define RMATH_PI32 3.14159265359f

#if !defined(RMATH_PROVIDE_MATH_FUNCTIONS)
	#include <math.h>
	#define RMATH_SINF sinf
	#define RMATH_COSF cosf
	#define RMATH_TANF tanf
	#define RMATH_SQRTF sqrtf
	#define RMATH_ACOSF acosf
#endif

#include <stdbool.h>

#define RMATH_MIN(a, b) ((a) > (b) ? (b) : (a))
#define RMATH_MAX(a, b) ((a) < (b) ? (b) : (a))
#define RMATH_ABS(a) ((a) > 0 ? (a) : -(a))
#define RMATH_MOD(a, m) (((a) % (m)) >= 0 ? ((a) % (m)) : (((a) % (m)) + (m)))
#define RMATH_SQUARE(x) ((x) * (x))

#define uint32_t unsigned int

/*===========================================================
 * FLOAT PRECISION FUNCTIONS
 *===========================================================*/

 /**
 * @brief Clamps a float between min and max.
 * @param x Value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return Clamped value.
 */
RMATHDEF float sr_fclamp(float x, float min, float max);

/**
 * @brief Saturates a float value to [0, 1].
 * @param x Value to saturate.
 * @return Saturated value.
 */
RMATHDEF float sr_fsaturate(float x);

/**
 * @brief Linear interpolation between two floats.
 * @param a Start value.
 * @param b End value.
 * @param t Interpolation factor [0, 1].
 * @return Interpolated value.
 */
RMATHDEF float sr_flerp(float a, float b, float t);

/**
 * @brief Smoothstep interpolation.
 * @param edge0 Lower edge.
 * @param edge1 Upper edge.
 * @param x Value to interpolate.
 * @return Smoothstep result.
 */
RMATHDEF float sr_fsmoothstep(float edge0, float edge1, float x);

/**
 * @brief Returns sign of value (-1, 0, 1).
 * @param x Input value.
 * @return Sign of x.
 */
RMATHDEF int sr_fsign(float x);

/**
 * @brief Converts degrees to radians.
 * @param deg Angle in degrees.
 * @return Angle in radians.
 */
RMATHDEF float sr_fdeg_to_rad(float deg);

/**
 * @brief Converts radians to degrees.
 * @param rad Angle in radians.
 * @return Angle in degrees.
 */
RMATHDEF float sr_frad_to_deg(float rad);

/**
 * @brief Absolute value.
 */
RMATHDEF float sr_fabs(float x);

/**
 * @brief Returns minimum of two floats.
 */
RMATHDEF float sr_fmin(float a, float b);

/**
 * @brief Returns maximum of two floats.
 */
RMATHDEF float sr_fmax(float a, float b);

/**
 * @brief Floating point modulus.
 */
RMATHDEF float sr_fmod(float x, float y);

/**
 * @brief Fractional part of x.
 */
RMATHDEF float sr_ffract(float x);

/*===========================================================
 * DOUBLE PRECISION FUNCTIONS
 *===========================================================*/

RMATHDEF double sr_dclamp(double x, double min, double max);
RMATHDEF double sr_dsaturate(double x);
RMATHDEF double sr_dlerp(double a, double b, double t);
RMATHDEF double sr_dsmoothstep(double edge0, double edge1, double x);
RMATHDEF int sr_dsign(double x);
RMATHDEF double sr_ddeg_to_rad(double deg);
RMATHDEF double sr_drad_to_deg(double rad);
RMATHDEF double sr_dabs(double x);
RMATHDEF double sr_dmin(double a, double b);
RMATHDEF double sr_dmax(double a, double b);
RMATHDEF double sr_dmod(double x, double y);
RMATHDEF double sr_dfract(double x);

/*===========================================================
 * COMPARISON / EPSILON
 *===========================================================*/

RMATHDEF bool sr_fequal(float a, float b, float eps);
RMATHDEF bool sr_dequal(double a, double b, double eps);
RMATHDEF bool sr_fzero(float x, float eps);
RMATHDEF bool sr_dzero(double x, double eps);

/*===========================================================
 * RANDOM / HASH
 *===========================================================*/

RMATHDEF float sr_frand(void);                     /**< Uniform [0,1) */
RMATHDEF float sr_frand_range(float min, float max); 
RMATHDEF double sr_drand(void);                    /**< Uniform [0,1) */
RMATHDEF double sr_drand_range(double min, double max);
RMATHDEF uint32_t sr_hash_u32(uint32_t x);

/*===========================================================
 * TRIGONOMETRIC HELPERS
 *===========================================================*/


#ifdef __cplusplus
}
#endif

#endif //!RMATH_COMMON_H