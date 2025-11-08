#ifndef RMATH_VEC3_DOUBLE_H
#define RMATH_VEC3_DOUBLE_H

// double vector 3 header file

#include "../types.h"
#include <rmath/details/define.h>

// DEFINITION
// CONSTRUCTION

RMATHDEF dvec3 dvec3_zero(void);
RMATHDEF void dvec3_zero_to(dvec3* v);
RMATHDEF dvec3 dvec3_one(void);

RMATHDEF dvec3 dvec3_construct(double x, double y, double z);
RMATHDEF void dvec3_construct_to(dvec3* out, double x, double y, double z);

RMATHDEF dvec3 dvec3_construct_uniform(double value);
RMATHDEF void dvec3_construct_uniform_to(dvec3* out, double value);

RMATHDEF dvec3 dvec3_construct_from_dvec2(const dvec2* v);

/* COPY */
RMATHDEF void dvec3_copy(dvec3* out, const dvec3* src);

RMATHDEF dvec3 dvec3_clone(const dvec3* src);

// GETTERS AND SETTERS
RMATHDEF double dvec3_get_x(const dvec3* v);
RMATHDEF double dvec3_get_y(const dvec3* v);
RMATHDEF double dvec3_get_z(const dvec3* v);

RMATHDEF void dvec3_set_x(dvec3* v, double x);
RMATHDEF void dvec3_set_y(dvec3* v, double y);
RMATHDEF void dvec3_set_z(dvec3* v, double z);

// MATH FUNCTIONS
RMATHDEF dvec3 dvec3_add(const dvec3* a, const dvec3* b);
RMATHDEF void dvec3_add_to(dvec3* out, const dvec3* a, const dvec3* b);
RMATHDEF void dvec3_add_inplace(dvec3* a, const dvec3* b);

RMATHDEF dvec3 dvec3_sub(const dvec3* a, const dvec3* b);
RMATHDEF void dvec3_sub_to(dvec3* out, const dvec3* a, const dvec3* b);
RMATHDEF void dvec3_sub_inplace(dvec3* a, const dvec3* b);

RMATHDEF dvec3 dvec3_mult(const dvec3* v, double t);
RMATHDEF void dvec3_mult_to(dvec3* out, const dvec3* v, double t);
RMATHDEF void dvec3_mult_inplace(dvec3* v, double t);

RMATHDEF dvec3 dvec3_div(const dvec3* v, double t);
RMATHDEF void dvec3_div_to(dvec3* out, const dvec3* v, double t);
RMATHDEF void dvec3_div_inplace(dvec3* v, double t);

RMATHDEF double dvec3_length_squared(const dvec3* v);
RMATHDEF double dvec3_length(const dvec3* v);

RMATHDEF dvec3 dvec3_normalize(const dvec3* v);
RMATHDEF void dvec3_normalize_to(dvec3* out, const dvec3* v);
RMATHDEF void dvec3_normalize_inplace(dvec3* v);

RMATHDEF double dvec3_dot(const dvec3* v, const dvec3* u);

RMATHDEF dvec3 dvec3_cross(const dvec3* a,const dvec3* b);
RMATHDEF void dvec3_cross_to(dvec3* out, const dvec3* v, const dvec3* u);

RMATHDEF dvec3 dvec3_neg(const dvec3* v);
RMATHDEF void dvec3_neg_to(dvec3* out, const dvec3* v);

RMATHDEF dvec3 dvec3_hadamard(const dvec3* u, const dvec3* v);

RMATHDEF double dvec3_distance(const dvec3* a, const dvec3* b);

RMATHDEF dvec3 dvec3_reflect(const dvec3* v, const dvec3* n);

// refract

#endif //!RMATH_VEC3_DOUBLE_H