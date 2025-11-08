#ifndef RMATH_MAT4_DOUBLE_H
#define RMATH_MAT4_DOUBLE_H

#include <rmath/details/define.h>
#include <rmath/types.h>

#include "vec3_double.h"
#include "vec4_double.h"

/*===========================================================
 * CONSTRUCTORS
 *===========================================================*/

/**
 * @brief Returns an identity matrix.
 */
RMATHDEF dmat4 dmat4_identity(void);
RMATHDEF void dmat4_identity_to(dmat4* out);

RMATHDEF dmat4 dmat4_zero(void);
RMATHDEF void dmat4_zero_to(dmat4* out);

/**
 * @brief Constructs a matrix from 4 column vectors.
 * @param c0 First column.
 * @param c1 Second column.
 * @param c2 Third column.
 * @param c3 Fourth column.
 */
RMATHDEF dmat4 dmat4_construct_cols(const dvec4* c0, const dvec4* c1, const dvec4* c2, const dvec4* c3);
RMATHDEF void dmat4_construct_cols_to(dmat4* out, 
    const dvec4* c0, 
    const dvec4* c1, 
    const dvec4* c2, 
    const dvec4* c3);

/**
 * @brief Constructs a diagonal matrix with a given scalar on the diagonal.
 * @param s The diagonal value.
 */
RMATHDEF dmat4 dmat4_construct_diagonal(double s);
RMATHDEF void dmat4_construct_diagonal_to(dmat4* out , double s);

//RMATHDEF dmat4 dmat4_from_rows(dvec4 v0, dvec4 v1, dvec4 v2, dvec4 v3);

/*===========================================================
 * COPY/CLONE
 *===========================================================*/

RMATHDEF void dmat4_copy(dmat4* out, const dmat4* src);
RMATHDEF dmat4 dmat4_clone(const dmat4* src);

/*===========================================================
 * GETTERS/SETTERS
 *===========================================================*/

RMATHDEF double dmat4_get(const dmat4* m, int x, int y);
RMATHDEF void dmat4_set(dmat4* m, int x, int y, double new_value);

dvec4* dmat4_col(dmat4* m, int i);

/*===========================================================
 * ARITHMETIC
 *===========================================================*/

RMATHDEF dmat4 dmat4_add(const dmat4* a, const dmat4* b);
RMATHDEF void dmat4_add_to(dmat4* out, const dmat4* a, const dmat4* b);
RMATHDEF void dmat4_add_inplace(dmat4* a, const dmat4* b);

RMATHDEF dmat4 dmat4_sub(const dmat4* a, const dmat4* b);
RMATHDEF void dmat4_sub_to(dmat4* out, const dmat4* a, const dmat4* b);
RMATHDEF void dmat4_sub_inplace(dmat4* a, const dmat4* b);

RMATHDEF dmat4 dmat4_mult_scalar(const dmat4* a, double s);
RMATHDEF void dmat4_mult_scalar_to(dmat4* out, const dmat4* a, double s);
RMATHDEF void dmat4_mult_scalar_inplace(dmat4* a, double s);

RMATHDEF dmat4 dmat4_div_scalar(const dmat4* a, double s);
RMATHDEF void dmat4_div_scalar_to(dmat4* out, const dmat4* a, double s);
RMATHDEF void dmat4_div_scalar_inplace(dmat4* a, double s);

/**
 * @brief Multiplies two 4x4 matrices (result = a * b).
 */
RMATHDEF dmat4 dmat4_mult(const dmat4* a, const dmat4* b);

/**
 * @brief Multiplies two 4x4 matrices and stores the result in `out`.
 * @param out Output matrix (cannot alias `a` or `b`).
 * @param a Left operand.
 * @param b Right operand.
 */
RMATHDEF void dmat4_mult_to(dmat4* out, const dmat4* a, const dmat4* b);

/**
 * @brief Multiplies matrix `a` by `b` in place (a = a * b).
 */
RMATHDEF void dmat4_mult_inplace(dmat4* a, const dmat4* b);

/**
 * @brief Multiplies a matrix by a 4D vector (result = m * v).
 */
RMATHDEF dvec4 dmat4_mult_vec4(const dmat4* m, const dvec4* v);
RMATHDEF void dmat4_mult_vec4_to(dvec4* out, const dmat4* m, const dvec4* v);
//RMATHDEF void dmat4_mult_vec4_inplace(const dmat4* m, const dvec4* v);


/**
 * @brief Computes the transpose of a matrix.
 */
RMATHDEF dmat4 dmat4_transpose(const dmat4* m);
RMATHDEF void dmat4_transpose_to(dmat4* out, const dmat4* m);
RMATHDEF void dmat4_transpose_inplace(dmat4* m);

/**
 * @brief Computes the determinant of a 4x4 matrix.
 */
RMATHDEF double dmat4_determinant(const dmat4* m);

/**
 * @brief Computes the inverse of a 4x4 matrix.
 * @param m Input matrix.
 * @return Inverse matrix.
 */
RMATHDEF dmat4 dmat4_inverse(const dmat4* m);
RMATHDEF void dmat4_inverse_to(dmat4* out, const dmat4* m);
RMATHDEF void dmat4_inverse_inplace(dmat4* m);

/*===========================================================
 * TRANSFORM
 *===========================================================*/

/**
 * @brief Creates a translation matrix.
 * @param translation 3D translation vector.
 */
RMATHDEF dmat4 dmat4_translation(const dvec3* translation);
RMATHDEF void dmat4_translation_to(dmat4* out, const dvec3* translation);

/**
 * @brief Creates a scaling matrix.
 * @param scale 3D scale vector.
 */
RMATHDEF dmat4 dmat4_scale(const dvec3* scale);
RMATHDEF void dmat4_scale_to(dmat4* out, const dvec3* scale);

/**
 * @brief Creates a rotation matrix around the X-axis.
 * @param angle_radians Angle in radians.
 */
RMATHDEF dmat4 dmat4_rotation_x(double angle_radians);
RMATHDEF void dmat4_rotation_x_to(dmat4* out, double angle_radians);

/**
 * @brief Creates a rotation matrix around the Y-axis.
 * @param angle_radians Angle in radians.
 */
RMATHDEF dmat4 dmat4_rotation_y(double angle_radians);
RMATHDEF void dmat4_rotation_y_to(dmat4* out, double angle_radians);

/**
 * @brief Creates a rotation matrix around the Z-axis.
 * @param angle_radians Angle in radians.
 */
RMATHDEF dmat4 dmat4_rotation_z(double angle_radians);
RMATHDEF void dmat4_rotation_z_to(dmat4* out, double angle_radians);

/**
 * @brief Creates a rotation matrix from Euler angles (XYZ order).
 * @param euler 3D vector containing angles in radians.
 */
RMATHDEF dmat4 dmat4_rotation_euler(const dvec3* euler);
RMATHDEF void dmat4_rotation_euler_to(dmat4* out, const dvec3* euler);

//RMATHDEF dmat4 dmat4_rotation_axis(const dvec3* axis, double radians);

// Compose TRS (transform)
RMATHDEF dmat4 dmat4_trs(const dvec3* translation, 
    const dvec3* rotation, 
    const dvec3* scale);

RMATHDEF void dmat4_trs_to(dmat4* out,
    const dvec3* translation, 
    const dvec3* rotation, 
    const dvec3* scale);

// Decompose TRS (transform)
RMATHDEF void dmat4_decompose_trs(const dmat4* m,
    dvec3* translation, 
    dvec3* rotation, 
    dvec3* scale);

/*===========================================================
 * CAMERA & PROJECTION HELPERS
 *===========================================================*/

/**
 * @brief Returns a look-at view matrix.
 * @param eye Camera position.
 * @param target Target position.
 * @param up Up direction vector.
 */
RMATHDEF dmat4 dmat4_look_at(
    const dvec3* eye, 
    const dvec3* target, 
    const dvec3* up);

RMATHDEF void dmat4_look_at_to(dmat4* out,
    const dvec3* eye, 
    const dvec3* target, 
    const dvec3* up);

/**
 * @brief Returns a matrix representing a perspective projection.
 * @param fov_y Field of view in the Y direction (radians).
 * @param aspect Aspect ratio.
 * @param near Near clipping plane.
 * @param far Far clipping plane.
 */
RMATHDEF dmat4 dmat4_perspective(
	double fov_y,
	double aspect,
	double near_plane,
	double far_plane);

RMATHDEF void dmat4_perspective_to(dmat4* out,
	double fov_y,
	double aspect,
	double near_plane,
	double far_plane);

/**
 * @brief Returns a matrix representing an orthographic projection.
 * @param left Left clipping plane.
 * @param right Right clipping plane.
 * @param bottom Bottom clipping plane.
 * @param top Top clipping plane.
 * @param near Near clipping plane.
 * @param far Far clipping plane.
 */
RMATHDEF dmat4 dmat4_ortho(
	double left, double right,
	double bottom, double top,
	double near_plane, double far_plane);

RMATHDEF void dmat4_ortho_to(dmat4* out,
	double left, double right,
	double bottom, double top,
	double near_plane, double far_plane);


#endif //!RMATH_MAT4_DOUBLE_H