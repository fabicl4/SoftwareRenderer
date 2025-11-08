#ifndef RMATH_TYPES_H
#define RMATH_TYPES_H

typedef union dvec2 {
    struct { double x, y; };
    struct { double r, g; };
    struct { double s, t; };
    
    double elem[2];

    #ifdef __cplusplus
        inline double &operator[](int index) { return elem[index]; }
        inline const double &operator[](int index) const { return elem[index]; }
    #endif

} dvec2;

typedef union fvec2 {
    struct { float x, y; };
    struct { float r, g; };
    struct { float s, t; };
    
    float elem[2];

    #ifdef __cplusplus
        inline float &operator[](int index) { return elem[index]; }
        inline const float &operator[](int index) const { return elem[index]; }
    #endif

} fvec2;

typedef union ivec2 {
    struct { int x, y; };
    struct { int r, g; };
    struct { int s, t; };
    
    int elem[2];

    #ifdef __cplusplus
        inline int &operator[](int index) { return elem[index]; }
        inline const int &operator[](int index) const { return elem[index]; }
    #endif
} ivec2;


typedef union dvec3 {
    struct { double x, y, z; };
    struct { double r, g, b; };
    struct { double s, t, p; };
    struct { dvec2 xy; double _ignored0;};
    struct { double _ignored1; dvec2 yz;};
    struct { dvec2 st; double _ignored2;};
    struct { double _ignored3; dvec2 tp;};
    
    double elem[3];

    #ifdef __cplusplus
        inline double &operator[](int index) { return elem[index]; }
        inline const double &operator[](int index) const { return elem[index]; }
    #endif

} dvec3;

typedef union fvec3 {
    struct { float x, y, z; };
    struct { float r, g, b; };
    struct { float s, t, p; };
    struct { fvec2 xy; float _ignored0;};
    struct { float _ignored1; fvec2 yz;};
    struct { fvec2 sp; float _ignored2;};
    struct { float _ignored3; fvec2 tp;};
    
    float elem[3];

    #ifdef __cplusplus
        inline float &operator[](int index) { return elem[index]; }
        inline const float &operator[](int index) const { return elem[index]; }
    #endif

} fvec3;

typedef union ivec3 {
    struct { int x, y, z; };
    struct { int r, g, b; };
    struct { int s, t, p; };
    struct { ivec2 xy; int _ignored0;};
    struct { int _ignored1; ivec2 yz;};
    struct { ivec2 sp; int _ignored2;};
    struct { int _ignored3; ivec2 tp;};
    
    int elem[3];

    #ifdef __cplusplus
        inline int &operator[](int index) { return elem[index]; }
        inline const int &operator[](int index) const { return elem[index]; }
    #endif

} ivec3;

#define DVEC3_UP (dvec3) {0,1,0};


typedef union dvec4 {
    struct {
        union {
            dvec3 xyz;
            struct
            {
                double x, y, z;
            };
        };
        double w; 
    };
    struct {
        union {
            dvec3 rgb;
            struct
            {
                double r, g, b;
            };
        };
        double a; 
    };
    struct {
        union {
            dvec3 stp;
            struct
            {
                double s, t, p;
            };
        };
        double q; 
    };
    struct {
        dvec2 xy;
        double _ignored0;
        double _ignored1;
    };
    struct {
        double _ignored2;
        dvec2 yz;
        double _ignored3;
    };
    struct {
        double _ignored4;
        double _ignored5;
        dvec2 zw;
    };
    
    double elem[4];

    #ifdef __cplusplus
        inline double &operator[](int Index) { return elem[Index]; }
        inline const double &operator[](int Index) const { return elem[Index]; }
    #endif

} dvec4;

typedef union fvec4 {
    struct {
        union {
            fvec3 xyz;
            struct
            {
                float x, y, z;
            };
        };
        float w; 
    };
    struct {
        union {
            fvec3 rgb;
            struct
            {
                float r, g, b;
            };
        };
        float a; 
    };
    struct {
        union {
            fvec3 stp;
            struct
            {
                float s, t, p;
            };
        };
        float q; 
    };
    struct {
        fvec2 xy;
        float _ignored0;
        float _ignored1;
    };
    struct {
        float _ignored2;
        fvec2 yz;
        float _ignored3;
    };
    struct {
        float _ignored4;
        float _ignored5;
        fvec2 zw;
    };
    
    float elem[4];

    #ifdef __cplusplus
        inline float &operator[](int Index) { return elem[Index]; }
        inline const float &operator[](int Index) const { return elem[Index]; }
    #endif

} fvec4;

typedef union ivec4 {
    struct {
        union {
            ivec3 xyz;
            struct
            {
                int x, y, z;
            };
        };
        int w; 
    };
    struct {
        union {
            ivec3 rgb;
            struct
            {
                int r, g, b;
            };
        };
        int a; 
    };
    struct {
        union {
            ivec3 stp;
            struct
            {
                int s, t, p;
            };
        };
        int q; 
    };
    struct {
        ivec2 xy;
        int _ignored0;
        int _ignored1;
    };
    struct {
        int _ignored2;
        ivec2 yz;
        int _ignored3;
    };
    struct {
        int _ignored4;
        int _ignored5;
        ivec2 zw;
    };
    
    int elem[4];

    #ifdef __cplusplus
        inline int &operator[](int Index) { return elem[Index]; }
        inline const int &operator[](int Index) const { return elem[Index]; }
    #endif

} ivec4;

#define MAT2_SIZE 4
#define MAT2_ROWS 2
#define MAT2_COLS 2

#define MAT3_SIZE 9
#define MAT3_ROWS 3
#define MAT3_COLS 3

#define MAT4_SIZE 16
#define MAT4_ROWS 4
#define MAT4_COLS 4


// MAT 4x4
typedef union dmat4 {
	double elem[MAT4_SIZE];     // flat array: 16 elements
    dvec4 cols[MAT4_COLS];  // 4 column vectors of 4 elements each

    #ifdef __cplusplus
        inline dvec4 &operator[](int index) { return cols[index]; }
        inline const dvec4 &operator[](int index) const { return cols[index]; }
    #endif

} dmat4;


typedef union fmat4 {
	float elem[MAT4_SIZE];
    fvec4 cols[MAT4_COLS];

    #ifdef __cplusplus
        inline fvec4 &operator[](int index) { return cols[index]; }
        inline const fvec4 &operator[](int index) const { return cols[index]; }
    #endif

} fmat4;

typedef union imat4 {
	float elem[MAT4_SIZE];
    ivec4 cols[MAT4_COLS];

    #ifdef __cplusplus
        inline ivec4 &operator[](int index) { return cols[index]; }
        inline const ivec4 &operator[](int index) const { return cols[index]; }
    #endif

} imat4;

// MAT 3x3
typedef union dmat3 {
	double elem[MAT3_SIZE];     // flat array: 16 elements
    dvec3 cols[MAT3_COLS];  // 4 column vectors of 4 elements each

    #ifdef __cplusplus
        inline dvec3 &operator[](int index) { return cols[index]; }
        inline const dvec3 &operator[](int index) const { return cols[index]; }
    #endif

} dmat3;

typedef union fmat3 {
	float elem[MAT3_SIZE];
    fvec3 cols[MAT3_COLS];

    #ifdef __cplusplus
        inline fvec3 &operator[](int index) { return cols[index]; }
        inline const fvec3 &operator[](int index) const { return cols[index]; }
    #endif

} fmat3;

// MAT 2x2
typedef union dmat2 {
	double elem[MAT2_SIZE];     // flat array: 16 elements
    dvec2 cols[MAT2_COLS];  // 4 column vectors of 4 elements each

    #ifdef __cplusplus
        inline dvec2 &operator[](int index) { return cols[index]; }
        inline const dvec2 &operator[](int index) const { return cols[index]; }
    #endif

} dmat2;

typedef union fmat2 {
	float elem[MAT2_SIZE];
    fvec2 cols[MAT2_COLS];

    #ifdef __cplusplus
        inline fvec2 &operator[](int index) { return cols[index]; }
        inline const fvec2 &operator[](int index) const { return cols[index]; }
    #endif

} fmat2;

typedef union quat {
    dvec4 v;
    double elems[4];
} quat;

#endif // !RMATH_TYPES_H