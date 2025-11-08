#include <rmath/types/vec3_double.h>

#include <math.h>

// CONSTRUCTION
RMATHDEF dvec3 dvec3_zero(void) { return (dvec3){0}; }
RMATHDEF dvec3 dvec3_one(void) { return (dvec3){1.0, 1.0, 1.0}; }
RMATHDEF void dvec3_zero_to(dvec3 *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;
}

RMATHDEF dvec3 dvec3_construct(double x, double y, double z)
{
	return (dvec3){x, y, z};
}

RMATHDEF void dvec3_construct_to(dvec3 *out, double x, double y, double z)
{
	*out = (dvec3){x, y, z};
}

RMATHDEF dvec3 dvec3_construct_uniform(double value)
{
	return (dvec3){value, value, value};
}

RMATHDEF void dvec3_construct_uniform_to(dvec3 *out, double value)
{
	*out = (dvec3){value, value, value};
}

RMATHDEF dvec3 dvec3_construct_from_dvec2(const dvec2 *v)
{
	return (dvec3){v->x, v->y, 0};
}

/* COPY */
RMATHDEF void dvec3_copy(dvec3 *out, const dvec3 *src)
{
	out->x = src->x;
	out->y = src->y;
	out->z = src->z;
}

RMATHDEF dvec3 dvec3_clone(const dvec3 *src) { return *src; }

// GETTERS AND SETTERS
RMATHDEF double dvec3_get_x(const dvec3 *v) { return v->x; }

RMATHDEF double dvec3_get_y(const dvec3 *v) { return v->y; }

RMATHDEF double dvec3_get_z(const dvec3 *v) { return v->z; }

RMATHDEF void dvec3_set_x(dvec3 *v, double x) { v->x = x; }

RMATHDEF void dvec3_set_y(dvec3 *v, double y) { v->y = y; }

RMATHDEF void dvec3_set_z(dvec3 *v, double z) { v->z = z; }

// MATH FUNCTIONS
RMATHDEF dvec3 dvec3_add(const dvec3 *a, const dvec3 *b)
{
	return (dvec3){a->x + b->x, a->y + b->y, a->z + b->z};
}

RMATHDEF void dvec3_add_to(dvec3 *out, const dvec3 *a, const dvec3 *b)
{
	out->x = a->x + b->x;
	out->y = a->y + b->y;
	out->z = a->z + b->z;
}

RMATHDEF void dvec3_add_inplace(dvec3 *a, const dvec3 *b)
{
	a->x = a->x + b->x;
	a->y = a->y + b->y;
	a->z = a->z + b->z;
}

RMATHDEF dvec3 dvec3_sub(const dvec3 *a, const dvec3 *b)
{
	return (dvec3){
		a->x - b->x,
		a->y - b->y,
		a->z - b->z};
}

RMATHDEF void dvec3_sub_to(dvec3 *out, const dvec3 *a, const dvec3 *b)
{
	out->x = a->x - b->x;
	out->y = a->y - b->y;
	out->z = a->z - b->z;
}

RMATHDEF void dvec3_sub_inplace(dvec3 *a, const dvec3 *b)
{
	a->x = a->x - b->x;
	a->y = a->y - b->y;
	a->z = a->z - b->z;
}

RMATHDEF dvec3 dvec3_mult(const dvec3 *v, double t)
{
	return (dvec3){v->x * t, v->y * t, v->z * t};
}

RMATHDEF void dvec3_mult_to(dvec3 *out, const dvec3 *v, double t)
{
	out->x = v->x * t;
	out->y = v->y * t;
	out->z = v->z * t;
}

RMATHDEF void dvec3_mult_inplace(dvec3 *v, double t)
{
	v->x = v->x * t;
	v->y = v->y * t;
	v->z = v->z * t;
}

RMATHDEF dvec3 dvec3_div(const dvec3 *v, double t)
{
	return (dvec3){v->x / t, v->y / t, v->z / t};
}
RMATHDEF void dvec3_div_to(dvec3 *out, const dvec3 *v, double t)
{
	out->x = v->x / t;
	out->y = v->y / t;
	out->z = v->z / t;
}

RMATHDEF void dvec3_div_inplace(dvec3 *v, double t)
{
	v->x = v->x / t;
	v->y = v->y / t;
	v->z = v->z / t;
}

RMATHDEF double dvec3_length_squared(const dvec3 *v)
{
	return v->x * v->x + v->y * v->y + v->z * v->z;
}

RMATHDEF double dvec3_length(const dvec3 *v)
{
	return sqrt(dvec3_length_squared(v));
}

RMATHDEF dvec3 dvec3_normalize(const dvec3 *v)
{
	double len = dvec3_length(v);

	return (dvec3){
		v->x / len,
		v->y / len,
		v->z / len};
}

RMATHDEF void dvec3_normalize_to(dvec3 *out, const dvec3 *v)
{
	double len = dvec3_length(v);

	out->x = v->x / len;
	out->y = v->y / len;
	out->z = v->z / len;
}

RMATHDEF void dvec3_normalize_inplace(dvec3 *v)
{
	double len = dvec3_length(v);

	v->x = v->x / len;
	v->y = v->y / len;
	v->z = v->z / len;
}

RMATHDEF double dvec3_dot(const dvec3 *v, const dvec3 *u)
{
	return v->x * u->x +
		   v->y * u->y +
		   v->z * u->z;
}

RMATHDEF dvec3 dvec3_cross(const dvec3 *a, const dvec3 *b)
{
	return (dvec3){
		a->y * b->z - a->z * b->y,
		a->z * b->x - a->x * b->z,
		a->x * b->y - a->y * b->x};
}

RMATHDEF void dvec3_cross_to(dvec3 *out, const dvec3 *v, const dvec3 *u)
{
	out->x = u->y * v->z - u->z * v->y,
	out->y = u->z * v->x - u->x * v->z,
	out->z = u->x * v->y - u->y * v->x;
}

RMATHDEF dvec3 dvec3_neg(const dvec3 *v)
{
	return (dvec3){-v->x, -v->y, -v->z};
}

RMATHDEF void dvec3_neg_to(dvec3 *out, const dvec3 *v)
{
	out->x = -v->x;
	out->y = -v->y;
	out->z = -v->z;
}

RMATHDEF void dvec3_neg_inplace(dvec3 *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

RMATHDEF dvec3 dvec3_hadamard(const dvec3 *u, const dvec3 *v)
{
	return (dvec3){
		v->x * u->x,
		v->y * u->y,
		v->z * u->z};
}

RMATHDEF double dvec3_distance(const dvec3 *a, const dvec3 *b)
{
	double dx = a->x - b->x;
	double dy = a->y - b->y;
	double dz = a->z - b->z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

RMATHDEF dvec3 dvec3_reflect(const dvec3 *v, const dvec3 *n)
{
	// r = v - 2 * dot(v,n) * n
	double d = v->x * n->x + v->y * n->y + v->z * n->z;
	double k = 2.0 * d;
	return (dvec3){
		v->x - k * n->x,
		v->y - k * n->y,
		v->z - k * n->z};
}