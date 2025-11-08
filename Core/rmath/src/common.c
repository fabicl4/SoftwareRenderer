#include <rmath/common.h>

/*================ Float ==================*/
RMATHDEF float sr_fclamp(float x, float min, float max)
{
    return (x < min) ? min : ((x > max) ? max : x);
}

RMATHDEF float sr_fsaturate(float x) { 
    return sr_fclamp(x, 0.0f, 1.0f); 
}

RMATHDEF float sr_flerp(float a, float b, float t) { return a + t * (b - a); }

RMATHDEF float sr_fsmoothstep(float edge0, float edge1, float x)
{
    float t = sr_fclamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

RMATHDEF int sr_fsign(float x) { return (x > 0) - (x < 0); }

RMATHDEF float sr_fdeg_to_rad(float deg) { return deg * 0.017453292519943295f; }
RMATHDEF float sr_frad_to_deg(float rad) { return rad * 57.29577951308232f; }

RMATHDEF float sr_fabs(float x) { return fabsf(x); }
RMATHDEF float sr_fmin(float a, float b) { return (a < b) ? a : b; }
RMATHDEF float sr_fmax(float a, float b) { return (a > b) ? a : b; }
RMATHDEF float sr_fmod(float x, float y) { return fmodf(x, y); }
RMATHDEF float sr_ffract(float x) { return x - floorf(x); }

/*================ Double ==================*/
RMATHDEF double sr_dclamp(double x, double min, double max)
{
    return (x < min) ? min : ((x > max) ? max : x);
}

RMATHDEF double sr_dsaturate(double x) { return sr_dclamp(x, 0.0, 1.0); }
RMATHDEF double sr_dlerp(double a, double b, double t) { return a + t * (b - a); }
RMATHDEF double sr_dsmoothstep(double edge0, double edge1, double x)
{
    double t = sr_dclamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
    return t * t * (3.0 - 2.0 * t);
}

RMATHDEF int sr_dsign(double x) { return (x > 0) - (x < 0); }

RMATHDEF double sr_ddeg_to_rad(double deg) { return deg * 0.017453292519943295; }
RMATHDEF double sr_drad_to_deg(double rad) { return rad * 57.29577951308232; }

RMATHDEF double sr_dabs(double x) { return fabs(x); }
RMATHDEF double sr_dmin(double a, double b) { return (a < b) ? a : b; }
RMATHDEF double sr_dmax(double a, double b) { return (a > b) ? a : b; }
RMATHDEF double sr_dmod(double x, double y) { return fmod(x, y); }
RMATHDEF double sr_dfract(double x) { return x - floor(x); }

/*================ Comparison ==================*/
RMATHDEF bool sr_fequal(float a, float b, float eps) { return fabsf(a - b) < eps; }
RMATHDEF bool sr_dequal(double a, double b, double eps) { return fabs(a - b) < eps; }
RMATHDEF bool sr_fzero(float x, float eps) { return fabsf(x) < eps; }
RMATHDEF bool sr_dzero(double x, double eps) { return fabs(x) < eps; }

/*================ Random ==================*/

RMATHDEF float sr_frand(void) { return (float)rand() / (float)RAND_MAX; }
RMATHDEF float sr_frand_range(float min, float max) { return min + (max - min) * sr_frand(); }
RMATHDEF double sr_drand(void) { return (double)rand() / (double)RAND_MAX; }
RMATHDEF double sr_drand_range(double min, double max) { return min + (max - min) * sr_drand(); }

/* Simple integer hash (for procedural generation) */
RMATHDEF uint32_t sr_hash_u32(uint32_t x)
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}