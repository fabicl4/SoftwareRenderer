#include <math.h>
#include <string.h>  // for memcpy

#include <rmath/types/mat4_double.h>

/* *
 *  The math matches OpenGL’s right-handed coordinate convention.
 *  The look-at matrix builds a camera transform where +Z faces backward.
 *  You can flip the Z terms if you need DirectX-style (left-handed) space.
 * */

RMATHDEF int _dmat4_index(int i, int j) {
	return j * MAT4_SIZE + i;
}


RMATHDEF dmat4 dmat4_identity(void)
{
    dmat4 m = {0};
    m.elem[0] = 1.0; m.elem[5] = 1.0; m.elem[10] = 1.0; m.elem[15] = 1.0;
    return m;
}

RMATHDEF void dmat4_identity_to(dmat4* out) {
    dmat4_zero_to(out);
    out->elem[0] = 1.0; 
    out->elem[5] = 1.0; 
    out->elem[10] = 1.0;
    out->elem[15] = 1.0;
}

RMATHDEF dmat4 dmat4_zero(void) {
    return (dmat4) {0};
}

RMATHDEF void dmat4_zero_to(dmat4* out) {
    *out = (dmat4) {0};
}

RMATHDEF dmat4 dmat4_construct_cols(const dvec4* c0, const dvec4* c1, const dvec4* c2, const dvec4* c3)
{
    dmat4 m;
    m.cols[0] = *c0; m.cols[1] = *c1; m.cols[2] = *c2; m.cols[3] = *c3;
    return m;
}

RMATHDEF void dmat4_construct_cols_to(dmat4* out, const dvec4* c0, const dvec4* c1, const dvec4* c2, const dvec4* c3)
{
    out->cols[0] = *c0;
    out->cols[1] = *c1; 
    out->cols[2] = *c2; 
    out->cols[3] = *c3;
}

RMATHDEF dmat4 dmat4_construct_diagonal(double s)
{
    dmat4 m = {0};
    m.elem[0] = s; m.elem[5] = s; m.elem[10] = s; m.elem[15] = s;
    return m;
}

RMATHDEF void dmat4_construct_diagonal_to(dmat4* out, double s) {
    dmat4_zero_to(out);
    out->elem[0] = s; 
    out->elem[5] = s; 
    out->elem[10] = s;
    out->elem[15] = s;
}

RMATHDEF void dmat4_copy(dmat4* out, const dmat4* src) {
    memcpy(out->elem, src->elem, sizeof(*src));
}

RMATHDEF dmat4 dmat4_clone(const dmat4* src) { return *src; }

RMATHDEF double dmat4_get(const dmat4* m, int x, int y) {
    return m->elem[_dmat4_index(x, y)];
}

RMATHDEF void dmat4_set(dmat4* m, int x, int y, double new_value) {
    m->elem[_dmat4_index(x, y)] = new_value;
}

dvec4* dmat4_col(dmat4* m, int i) {
    return &m->cols[i];
}

RMATHDEF dmat4 dmat4_add(const dmat4* a, const dmat4* b) {
    dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->elem[j * 4 + i] + b->elem[j * 4 + i];
		}
	}

    return m;
}

RMATHDEF void dmat4_add_to(dmat4* out, const dmat4* a, const dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->elem[j * 4 + i] + b->elem[j * 4 + i];
		}
	}
}

RMATHDEF void dmat4_add_inplace(dmat4* a, const dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->elem[j * 4 + i] + b->elem[j * 4 + i];
		}
	}
}

RMATHDEF dmat4 dmat4_sub(const dmat4* a, const dmat4* b) {
    dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->elem[j * 4 + i] - b->elem[j * 4 + i];
		}
	}

    return m;
}
RMATHDEF void dmat4_sub_to(dmat4* out, const dmat4* a, const dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->elem[j * 4 + i] - b->elem[j * 4 + i];
		}
	}
}

RMATHDEF void dmat4_sub_inplace(dmat4* a, const dmat4* b) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->elem[j * 4 + i] - b->elem[j * 4 + i];
		}
	}
}

RMATHDEF dmat4 dmat4_mult_scalar(const dmat4* a, double s) {
    dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->elem[j * 4 + i] * s;
		}
	}

    return m;
}

RMATHDEF void dmat4_mult_scalar_to(dmat4* out, const dmat4* a,double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->elem[j * 4 + i] * s;
		}
	}
}

RMATHDEF void dmat4_mult_scalar_inplace(dmat4* a, double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->elem[j * 4 + i] * s;
		}
	}
}

RMATHDEF dmat4 dmat4_div_scalar(const dmat4* a, double s) {
    dmat4 m = {0};

    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			m.elem[j * 4 + i] = a->elem[j * 4 + i] / s;
		}
	}

    return m;
}

RMATHDEF void dmat4_div_scalar_to(dmat4* out, const dmat4* a,double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			out->elem[j * 4 + i] = a->elem[j * 4 + i] / s;
		}
	}
}

RMATHDEF void dmat4_div_scalar_inplace(dmat4* a, double s) {
    for (int i = 0; i < MAT4_ROWS; i++)
	{
		for (int j = 0; j < MAT4_COLS; j++)
		{
			a->elem[j * 4 + i] = a->elem[j * 4 + i] / s;
		}
	}
}

RMATHDEF dmat4 dmat4_mult(const dmat4* a, const dmat4* b)
{
    dmat4 out = {0};
    for (int i = 0; i < 4; i++) // row
    {
        for (int j = 0; j < 4; j++) // col
        {
            double sum = 0.0;
            for (int k = 0; k < 4; k++)
                sum += a->elem[i*4 + k] * b->elem[k*4 + j];
            out.elem[i*4 + j] = sum;
        }
    }
    return out;
}

RMATHDEF void dmat4_mult_to(dmat4* out, const dmat4* a, const dmat4* b)
{
    *out = dmat4_mult(a, b);
}

RMATHDEF void dmat4_mult_inplace(dmat4* a, const dmat4* b)
{
    dmat4 temp = dmat4_mult(a, b);
    *a = temp;
}

RMATHDEF dvec4 dmat4_mult_vec4(const dmat4* m, const dvec4* v)
{
    dvec4 out;
    out.x = m->cols[0].x*v->x + m->cols[1].x*v->y + m->cols[2].x*v->z + m->cols[3].x*v->w;
    out.y = m->cols[0].y*v->x + m->cols[1].y*v->y + m->cols[2].y*v->z + m->cols[3].y*v->w;
    out.z = m->cols[0].z*v->x + m->cols[1].z*v->y + m->cols[2].z*v->z + m->cols[3].z*v->w;
    out.w = m->cols[0].w*v->x + m->cols[1].w*v->y + m->cols[2].w*v->z + m->cols[3].w*v->w;
    return out;
}

RMATHDEF void dmat4_mult_vec4_to(dvec4* out, const dmat4* m, const dvec4* v) {
    *out = dmat4_mult_vec4(m, v);
}

/*
RMATHDEF void dmat4_mult_vec4_inplace(dmat4* m, const dvec4* v) {
    dmat4 temp = dmat4_mult_vec4(m, v);
    *a = temp;
}*/

RMATHDEF dmat4 dmat4_transpose(const dmat4* m) {
    dmat4 out;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            out.elem[i*4 + j] = m->elem[j*4 + i];
    return out;
}

RMATHDEF void dmat4_transpose_to(dmat4* out, const dmat4* m)
{
    *out = dmat4_transpose(m);
}

RMATHDEF void dmat4_transpose_inplace(dmat4* m)
{
    dmat4 temp = dmat4_transpose(m);
    *m = temp;
}

/*-----------------------------------------------------------
 * Determinant (helper: 3x3 minor)
 *-----------------------------------------------------------*/
double _det3x3(double m[9])
{
    return m[0]*(m[4]*m[8]-m[5]*m[7]) -
           m[1]*(m[3]*m[8]-m[5]*m[6]) +
           m[2]*(m[3]*m[7]-m[4]*m[6]);
}

RMATHDEF double dmat4_determinant(const dmat4* m)
{
    double det = 0.0;
    double minor[9];
    int sign = 1;

    for(int col=0; col<4; col++)
    {
        int idx = 0;
        for(int i=1;i<4;i++)
            for(int j=0;j<4;j++)
                if(j != col)
                    minor[idx++] = m->elem[i*4 + j];
        det += sign * m->elem[col] * _det3x3(minor);
        sign = -sign;
    }
    return det;
}

/*-----------------------------------------------------------
 * Matrix inverse (using cofactors)
 *-----------------------------------------------------------*/
RMATHDEF dmat4 dmat4_inverse(const dmat4* m)
{
    dmat4 inv;
    double det = dmat4_determinant(m);
    if(fabs(det) < 1e-12) // singular
    {
        memset(&inv, 0, sizeof(inv));
        return inv;
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            // Build minor for element (j,i) because we compute adjoint
            double minor[9];
            int idx=0;
            for(int row=0;row<4;row++)
            {
                if(row==i) continue;
                for(int col=0;col<4;col++)
                {
                    if(col==j) continue;
                    minor[idx++] = m->elem[row*4 + col];
                }
            }
            inv.elem[i*4 + j] = ((i+j)%2==0 ? 1.0 : -1.0) * _det3x3(minor) / det;
        }
    }
    return inv;
}

RMATHDEF void dmat4_inverse_to(dmat4* out, const dmat4* m)
{
    *out = dmat4_inverse(m);
}

RMATHDEF void dmat4_inverse_inplace(dmat4* m)
{
    dmat4 temp = dmat4_inverse(m);
    *m = temp;
}

RMATHDEF dmat4 dmat4_translation(const dvec3* translation) {
    dmat4 m = {0};

    m.elem[_dmat4_index(0,3)] = translation->elem[0];
    m.elem[_dmat4_index(1,3)] = translation->elem[1];
    m.elem[_dmat4_index(2,3)] = translation->elem[2];
    m.elem[_dmat4_index(3,3)] = 1;

    return m;
}

RMATHDEF void dmat4_translation_to(dmat4* out, const dvec3* translation) {
    *out = dmat4_translation(translation);
}

RMATHDEF dmat4 dmat4_scale(const dvec3* scale) {
    dmat4 m = {0};

    m.elem[_dmat4_index(0,0)] = scale->elem[0];
    m.elem[_dmat4_index(1,1)] = scale->elem[1];
    m.elem[_dmat4_index(2,2)] = scale->elem[2];
    m.elem[_dmat4_index(3,3)] = 1;

    return m;
}

RMATHDEF void dmat4_scale_to(dmat4* out, const dvec3* scale) {
    *out = dmat4_scale(scale);
}

RMATHDEF dmat4 dmat4_rotation_x(double angle)
{
    double c = cos(angle);
    double s = sin(angle);

    dmat4 m = {0};
    m.elem[0] = 1.0; m.elem[5] = c;  m.elem[6] = -s; m.elem[10] = c;  m.elem[9] = s; m.elem[15] = 1.0;
    return m;
}

RMATHDEF void dmat4_rotation_x_to(dmat4* out, double angle)
{
    *out = dmat4_rotation_x(angle);
}

/*-----------------------------------------------------------
 * Rotation around Y-axis
 *-----------------------------------------------------------*/
RMATHDEF dmat4 dmat4_rotation_y(double angle)
{
    double c = cos(angle);
    double s = sin(angle);

    dmat4 m = {0};
    m.elem[0] = c;  m.elem[2] = s;  m.elem[5] = 1.0; m.elem[8] = -s; m.elem[10] = c; m.elem[15] = 1.0;
    return m;
}

RMATHDEF void dmat4_rotation_y_to(dmat4* out, double angle)
{
    *out = dmat4_rotation_y(angle);
}

/*-----------------------------------------------------------
 * Rotation around Z-axis
 *-----------------------------------------------------------*/
RMATHDEF dmat4 dmat4_rotation_z(double angle)
{
    double c = cos(angle);
    double s = sin(angle);

    dmat4 m = {0};
    m.elem[0] = c;  m.elem[1] = -s; m.elem[4] = s;  m.elem[5] = c;
    m.elem[10] = 1.0; m.elem[15] = 1.0;
    return m;
}

RMATHDEF void dmat4_rotation_z_to(dmat4* out, double angle)
{
    *out = dmat4_rotation_z(angle);
}

/*-----------------------------------------------------------
 * Rotation from Euler angles (XYZ order)
 *-----------------------------------------------------------*/
RMATHDEF dmat4 dmat4_rotation_euler(const dvec3* euler)
{
    dmat4 rx = dmat4_rotation_x(euler->x);
    dmat4 ry = dmat4_rotation_y(euler->y);
    dmat4 rz = dmat4_rotation_z(euler->z);

    // Combined rotation: R = Rz * Ry * Rx (XYZ order)
    dmat4 ry_rx = dmat4_mult(&ry, &rx);
    return dmat4_mult(&rz, &ry_rx);
}

RMATHDEF void dmat4_rotation_euler_to(dmat4* out, const dvec3* euler)
{
    *out = dmat4_rotation_euler(euler);
}

RMATHDEF dmat4 dmat4_trs(const dvec3* translation, 
    const dvec3* rotation, 
    const dvec3* scale) {

    dmat4 m = dmat4_identity();
    //printf("[WARNING] dmat4_trs(): not implemented yet!");

    /*dmat4_translation(m,m, translation);
	dmat4_rotation_z(m,m, &rotation.z);
	dmat4_rotation_y(m,m, &rotation.y);
	dmat4_rotation_x(m,m, &rotation.x);
	dmat4_scale(m,m, &t->scale);*/

    return m;
}

RMATHDEF void dmat4_trs_to(dmat4* out,
    const dvec3* translation, 
    const dvec3* rotation, 
    const dvec3* scale) {

    *out = dmat4_trs(translation, rotation, scale);
}

// Decompose TRS (transform)
RMATHDEF void dmat4_decompose_trs(const dmat4* m,
    dvec3* translation, 
    dvec3* rotation, 
    dvec3* scale) {

    //TODO
}

RMATHDEF dmat4 dmat4_look_at(
    const dvec3* eye, 
    const dvec3* target, 
    const dvec3* up) {

    dmat4 result;
    dmat4_look_at_to(&result, eye, target, up);
    return result;
}

RMATHDEF void dmat4_look_at_to(dmat4* out,
    const dvec3* eye, 
    const dvec3* target, 
    const dvec3* up) {

    dvec3 f = dvec3_sub(target, eye);
    dvec3_normalize_inplace(&f);

    dvec3 s = dvec3_cross(&f, up);
    dvec3_normalize_inplace(&s);
    dvec3 u = dvec3_cross(&s, &f);

    out->elem[_dmat4_index(0,0)] =  s.x;
    out->elem[_dmat4_index(0,1)] =  u.x; 
    out->elem[_dmat4_index(0,2)] = -f.x; 
    out->elem[_dmat4_index(0,3)] = 0.0;

    out->elem[_dmat4_index(1,0)] =  s.y;
    out->elem[_dmat4_index(1,1)] =  u.y;
    out->elem[_dmat4_index(1,2)] = -f.y; 
    out->elem[_dmat4_index(1,3)] = 0.0;

    out->elem[_dmat4_index(2,0)] =  s.z; 
    out->elem[_dmat4_index(2,1)] =  u.z; 
    out->elem[_dmat4_index(2,2)] = -f.z; 
    out->elem[_dmat4_index(2,3)] = 0.0;

    out->elem[_dmat4_index(3,0)] = -dvec3_dot(&s, eye);
    out->elem[_dmat4_index(3,1)] = -dvec3_dot(&u, eye);
    out->elem[_dmat4_index(3,2)] =  dvec3_dot(&f, eye);
    out->elem[_dmat4_index(3,3)] = 1.0;
}

/**
 * @brief Creates a perspective projection matrix.
 */
RMATHDEF dmat4 dmat4_perspective(
    double fov_y,
    double aspect,
    double near_plane,
    double far_plane)
{
    dmat4 result;
    dmat4_perspective_to(&result, fov_y, aspect, near_plane, far_plane);
    return result;
}

RMATHDEF void dmat4_perspective_to(
    dmat4* out,
    double fov_y,
    double aspect,
    double near_plane,
    double far_plane)
{
    double f = 1.0 / tan(fov_y / 2.0);
    double nf = 1.0 / (near_plane - far_plane);

    out->elem[_dmat4_index(0,0)] = f / aspect;
    out->elem[_dmat4_index(0,1)] = 0.0;
    out->elem[_dmat4_index(0,2)] = 0.0;
    out->elem[_dmat4_index(0,3)] = 0.0;
    out->elem[_dmat4_index(1,0)] = 0.0;
    out->elem[_dmat4_index(1,1)] = f;
    out->elem[_dmat4_index(1,2)] = 0.0;
    out->elem[_dmat4_index(1,3)] = 0.0;
    out->elem[_dmat4_index(2,0)] = 0.0;
    out->elem[_dmat4_index(2,1)] = 0.0;
    out->elem[_dmat4_index(2,2)] = (far_plane + near_plane) * nf;
    out->elem[_dmat4_index(2,3)] = -1.0;
    out->elem[_dmat4_index(3,0)] = 0.0;
    out->elem[_dmat4_index(3,1)] = 0.0;
    out->elem[_dmat4_index(3,2)] = (2.0 * far_plane * near_plane) * nf;
    out->elem[_dmat4_index(3,3)] = 0.0;
}

/**
 * @brief Creates an orthographic projection matrix.
 */
RMATHDEF dmat4 dmat4_ortho(
    double left, double right,
    double bottom, double top,
    double near_plane, double far_plane)
{
    dmat4 result;
    dmat4_ortho_to(&result, left, right, bottom, top, near_plane, far_plane);
    return result;
}

RMATHDEF void dmat4_ortho_to(
    dmat4* out,
    double left, double right,
    double bottom, double top,
    double near_plane, double far_plane)
{
    double rl = right - left;
    double tb = top - bottom;
    double fn = far_plane - near_plane;

    out->elem[_dmat4_index(0,0)] = 2.0 / rl;
    out->elem[_dmat4_index(0,1)] = 0.0;
    out->elem[_dmat4_index(0,2)] = 0.0;
    out->elem[_dmat4_index(0,3)] = 0.0;
    out->elem[_dmat4_index(1,0)] = 0.0;
    out->elem[_dmat4_index(1,1)] = 2.0 / tb;
    out->elem[_dmat4_index(1,2)] = 0.0;
    out->elem[_dmat4_index(1,3)] = 0.0;
    out->elem[_dmat4_index(2,0)] = 0.0;
    out->elem[_dmat4_index(2,1)] = 0.0;
    out->elem[_dmat4_index(2,2)] = -2.0 / fn;
    out->elem[_dmat4_index(2,3)] = 0.0;
    out->elem[_dmat4_index(3,0)] = -(right + left) / rl;
    out->elem[_dmat4_index(3,1)] = -(top + bottom) / tb;
    out->elem[_dmat4_index(3,2)] = -(far_plane + near_plane) / fn;
    out->elem[_dmat4_index(3,3)] = 1.0;
}