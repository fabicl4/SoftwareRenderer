#include <rmath/types/vec4_double.h>

#include <math.h>

/*===========================================================
 * dvec4 Constructors
 *===========================================================*/
RMATHDEF dvec4 dvec4_zero(void) { return (dvec4){0}; }
RMATHDEF dvec4 dvec4_one(void) { return (dvec4){1.0, 1.0, 1.0, 1.0}; }
RMATHDEF void dvec4_zero_to(dvec4 *v)
{
    v->x = 0;
    v->y = 0;
    v->z = 0;
    v->w = 0;
}

RMATHDEF dvec4 dvec4_construct(double x, double y, double z, double w) { return (dvec4){x, y, z, w}; }
RMATHDEF dvec4 dvec4_construct_uniform(double v) { return (dvec4){v, v, v, v}; }

RMATHDEF dvec4 dvec4_construct_from_dvec3(const dvec3 *v)
{
    return (dvec4){v->x, v->y, v->z, 0};
}

RMATHDEF dvec4 dvec4_construct_from_dvec2(const dvec2 *v)
{
    return (dvec4){v->x, v->y, 0, 0};
}

/* COPY */
RMATHDEF void dvec4_copy(dvec4 *out, const dvec4 *src)
{
    out->x = src->x;
    out->y = src->y;
    out->z = src->z;
    out->w = src->w;
}

RMATHDEF dvec4 dvec4_clone(const dvec4 *src) { return *src; }

/*===========================================================
 * dvec4 Getters / Setters
 *===========================================================*/
RMATHDEF double dvec4_get_x(const dvec4 *v) { return v->x; }
RMATHDEF double dvec4_get_y(const dvec4 *v) { return v->y; }
RMATHDEF double dvec4_get_z(const dvec4 *v) { return v->z; }
RMATHDEF double dvec4_get_w(const dvec4 *v) { return v->w; }

RMATHDEF void dvec4_set_x(dvec4 *v, double x) { v->x = x; }
RMATHDEF void dvec4_set_y(dvec4 *v, double y) { v->y = y; }
RMATHDEF void dvec4_set_z(dvec4 *v, double z) { v->z = z; }
RMATHDEF void dvec4_set_w(dvec4 *v, double w) { v->w = w; }

/*===========================================================
 * dvec4 Math
 *===========================================================*/
RMATHDEF dvec4 dvec4_add(const dvec4 *a, const dvec4 *b)
{
    return (dvec4){a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w};
}
RMATHDEF void dvec4_add_to(dvec4 *out, const dvec4 *a, const dvec4 *b)
{
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
    out->w = a->w + b->w;
}

RMATHDEF void dvec4_add_inplace(dvec4 *a, const dvec4 *b)
{
    a->x = +b->x;
    a->y = +b->y;
    a->z = +b->z;
    a->w = +b->w;
}

RMATHDEF dvec4 dvec4_sub(const dvec4 *a, const dvec4 *b)
{
    return (dvec4){a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w};
}
RMATHDEF void dvec4_sub_to(dvec4 *out, const dvec4 *a, const dvec4 *b)
{
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
    out->w = a->w - b->w;
}

RMATHDEF void dvec4_sub_inplace(dvec4 *a, const dvec4 *b)
{
    a->x = -b->x;
    a->y = -b->y;
    a->z = -b->z;
    a->w = -b->w;
}

RMATHDEF dvec4 dvec4_mult(const dvec4 *v, double s)
{
    return (dvec4){v->x * s, v->y * s, v->z * s, v->w * s};
}
RMATHDEF void dvec4_mult_to(dvec4 *out, const dvec4 *v, double s)
{
    out->x = v->x * s;
    out->y = v->y * s;
    out->z = v->z * s;
    out->w = v->w * s;
}
RMATHDEF void dvec4_mult_inplace(dvec4 *v, double s)
{
    v->x *= s;
    v->y *= s;
    v->z *= s;
    v->w *= s;
}

RMATHDEF dvec4 dvec4_div(const dvec4 *v, double s)
{
    return (dvec4){v->x / s, v->y / s, v->z / s, v->w / s};
}
RMATHDEF void dvec4_div_to(dvec4 *out, const dvec4 *v, double s)
{
    out->x = v->x / s;
    out->y = v->y / s;
    out->z = v->z / s;
    out->w = v->w / s;
}

RMATHDEF void dvec4_div_inplace(dvec4 *v, double s)
{
    v->x /= s;
    v->y /= s;
    v->z /= s;
    v->w /= s;
}

RMATHDEF double dvec4_length_squared(const dvec4 *v)
{
    return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}
RMATHDEF double dvec4_length(const dvec4 *v) { return sqrt(dvec4_length_squared(v)); }

RMATHDEF void dvec4_normalize(dvec4 *v)
{
    double l = dvec4_length(v);
    v->x /= l;
    v->y /= l;
    v->z /= l;
    v->w /= l;
}
RMATHDEF void dvec4_normalize_to(dvec4 *out, const dvec4 *v)
{
    double l = dvec4_length(v);
    out->x = v->x / l;
    out->y = v->y / l;
    out->z = v->z / l;
    out->w = v->w / l;
}

RMATHDEF void dvec4_normalize_inplace(dvec4 *v)
{
    double l = dvec4_length(v);
    dvec4_div_inplace(v, l);
}

RMATHDEF double dvec4_dot(const dvec4 *a, const dvec4 *b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
RMATHDEF double dvec4_distance(const dvec4 *a, const dvec4 *b)
{
    double dx = a->x - b->x, dy = a->y - b->y, dz = a->z - b->z, dw = a->w - b->w;
    return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

RMATHDEF dvec4 dvec4_neg(const dvec4 *v) { return (dvec4){-v->x, -v->y, -v->z, -v->w}; }
RMATHDEF void dvec4_neg_to(dvec4 *out, const dvec4 *v)
{
    out->x = -v->x;
    out->y = -v->y;
    out->z = -v->z;
    out->w = -v->w;
}

RMATHDEF void dvec4_neg_inplace(dvec4 *v)
{
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;
    v->w = -v->w;
}

RMATHDEF dvec4 dvec4_hadamard(const dvec4 *a, const dvec4 *b)
{
    return (dvec4){a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w};
}

RMATHDEF void dvec4_hadamard_to(dvec4 *out, const dvec4 *a, const dvec4 *b)
{
    *out = dvec4_hadamard(a, b);
}