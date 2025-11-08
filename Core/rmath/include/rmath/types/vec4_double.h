#ifndef RMATH_VEC4_DOUBLE_H
#define RMATH_VEC4_DOUBLE_H

// double vector 4 header file
#include <rmath/details/define.h>
#include <rmath/types.h>

// DEFINITION
/*===========================================================
 * Constructors
 *===========================================================*/
/**
 * @brief Returns a zero vector (0, 0, 0, 0).
 */
RMATHDEF dvec4 dvec4_zero(void);

/**
 * @brief Returns a vector with all components set to one (1, 1, 1, 1).
 */
RMATHDEF dvec4 dvec4_one(void);

/**
 * @brief Sets the output vector to zero.
 * @param out Output vector.
 */
RMATHDEF void dvec4_zero_to(dvec4* out);

/**
 * @brief Constructs a vector from four components.
 * @param x X component.
 * @param y Y component.
 * @param z Z component.
 * @param w W component.
 */
RMATHDEF dvec4 dvec4_construct(double x, double y, double z, double w);

/**
 * @brief Constructs a vector with all components set to the same value.
 * @param v Scalar value to set.
 */
RMATHDEF dvec4 dvec4_construct_uniform(double v);

/**
 * @brief Constructs a 4D vector from a 3D vector, setting w = 0.
 * @param v Input 3D vector.
 */
RMATHDEF dvec4 dvec4_construct_from_dvec3(const dvec3* v);

/**
 * @brief Constructs a 4D vector from a 2D vector, setting z = w = 0.
 * @param v Input 2D vector.
 */
RMATHDEF dvec4 dvec4_construct_from_dvec2(const dvec2* v);

/*===========================================================
 * Copy / Clone
 *===========================================================*/

/**
 * @brief Copies one vector to another.
 * @param out Output vector.
 * @param src Source vector.
 */
RMATHDEF void dvec4_copy(dvec4* out, const dvec4* src);

/**
 * @brief Returns a copy of the source vector.
 * @param src Source vector.
 */
RMATHDEF dvec4 dvec4_clone(const dvec4* src);

/*===========================================================
 * Getters / Setters
 *===========================================================*/

/**
 * @brief Returns the X component of the vector.
 */
RMATHDEF double dvec4_get_x(const dvec4* v);

/**
 * @brief Returns the Y component of the vector.
 */
RMATHDEF double dvec4_get_y(const dvec4* v);

/**
 * @brief Returns the Z component of the vector.
 */
RMATHDEF double dvec4_get_z(const dvec4* v);

/**
 * @brief Returns the W component of the vector.
 */
RMATHDEF double dvec4_get_w(const dvec4* v);

/**
 * @brief Sets the X component of the vector.
 */
RMATHDEF void dvec4_set_x(dvec4* v, double x);

/**
 * @brief Sets the Y component of the vector.
 */
RMATHDEF void dvec4_set_y(dvec4* v, double y);

/**
 * @brief Sets the Z component of the vector.
 */
RMATHDEF void dvec4_set_z(dvec4* v, double z);

/**
 * @brief Sets the W component of the vector.
 */
RMATHDEF void dvec4_set_w(dvec4* v, double w);

/*===========================================================
 * Math Operations
 *===========================================================*/

/**
 * @brief Adds two vectors (result = a + b).
 */
RMATHDEF dvec4 dvec4_add(const dvec4* a, const dvec4* b);

/**
 * @brief Adds two vectors and stores the result in `out`.
 */
RMATHDEF void dvec4_add_to(dvec4* out, const dvec4* a, const dvec4* b);

/**
 * @brief Adds another vector to this one in place (a += b).
 */
RMATHDEF void dvec4_add_inplace(dvec4* a, const dvec4* b);

/**
 * @brief Subtracts two vectors (result = a - b).
 */
RMATHDEF dvec4 dvec4_sub(const dvec4* a, const dvec4* b);

/**
 * @brief Subtracts two vectors and stores the result in `out`.
 */
RMATHDEF void dvec4_sub_to(dvec4* out, const dvec4* a, const dvec4* b);

/**
 * @brief Subtracts another vector from this one in place (a -= b).
 */
RMATHDEF void dvec4_sub_inplace(dvec4* a, const dvec4* b);

/**
 * @brief Multiplies a vector by a scalar (result = v * s).
 */
RMATHDEF dvec4 dvec4_mult(const dvec4* v, double s);

/**
 * @brief Multiplies a vector by a scalar and stores the result in `out`.
 */
RMATHDEF void dvec4_mult_to(dvec4* out, const dvec4* v, double s);

/**
 * @brief Multiplies a vector by a scalar in place (v *= s).
 */
RMATHDEF void dvec4_mult_inplace(dvec4* v, double s);

/**
 * @brief Divides a vector by a scalar (result = v / s).
 */
RMATHDEF dvec4 dvec4_div(const dvec4* v, double s);

/**
 * @brief Divides a vector by a scalar and stores the result in `out`.
 */
RMATHDEF void dvec4_div_to(dvec4* out, const dvec4* v, double s);

/**
 * @brief Divides a vector by a scalar in place (v /= s).
 */
RMATHDEF void dvec4_div_inplace(dvec4* v, double s);

/**
 * @brief Returns the squared length of the vector.
 */
RMATHDEF double dvec4_length_squared(const dvec4* v);

/**
 * @brief Returns the Euclidean length of the vector.
 */
RMATHDEF double dvec4_length(const dvec4* v);

/**
 * @brief Normalizes a vector in place (v = normalize(v)).
 */
RMATHDEF void dvec4_normalize(dvec4* v);

/**
 * @brief Normalizes `v` and stores the result in `out`.
 */
RMATHDEF void dvec4_normalize_to(dvec4* out, const dvec4* v);

/**
 * @brief Normalizes a vector in place (alias for `dvec4_normalize`).
 */
RMATHDEF void dvec4_normalize_inplace(dvec4* v);

/**
 * @brief Computes the dot product between two vectors.
 */
RMATHDEF double dvec4_dot(const dvec4* a, const dvec4* b);

/**
 * @brief Computes the Euclidean distance between two vectors.
 */
RMATHDEF double dvec4_distance(const dvec4* a, const dvec4* b);

/**
 * @brief Returns the negated vector (result = -v).
 */
RMATHDEF dvec4 dvec4_neg(const dvec4* v);

/**
 * @brief Negates a vector and stores the result in `out`.
 */
RMATHDEF void dvec4_neg_to(dvec4* out, const dvec4* v);

/**
 * @brief Negates a vector in place.
 */
RMATHDEF void dvec4_neg_inplace(dvec4* v);

/**
 * @brief Performs element-wise multiplication (Hadamard product) of two vectors.
 */
RMATHDEF dvec4 dvec4_hadamard(const dvec4* a, const dvec4* b);

/**
 * @brief Performs element-wise multiplication and stores the result in `out`.
 */
RMATHDEF void dvec4_hadamard_to(dvec4* out, const dvec4* a, const dvec4* b);

#endif //!RMATH_VEC4_DOUBLE_H