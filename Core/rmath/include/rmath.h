#ifndef RMATH_H
#define RMATH_H

// Master include

#ifdef __cplusplus
extern "C" {
#endif

// TYPE INCLUDES
#include <rmath/details/define.h>

#define VEC2_SIZE 2
#define VEC3_SIZE 3
#define VEC4_SIZE 4

#define DVEC2_SIZEOF     sizeof(dvec2)
#define DVEC3_SIZEOF     sizeof(rtm_dvec3)
#define DVEC4_SIZEOF     sizeof(rtm_dvec4)

// FUNCTION DEFINITION
#include <rmath/types/vec3_double.h>
#include <rmath/types/vec4_double.h>
#include <rmath/types/mat4_double.h>

#ifdef __cplusplus
}
#endif

#endif //!RT_MATH_H