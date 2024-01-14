#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;
typedef double _PrecisionType;
class Vec3 {
  public:
    _PrecisionType e[3];

    Vec3() : e{0,0,0} {}
    Vec3(_PrecisionType e0, _PrecisionType e1, _PrecisionType e2) : e{e0, e1, e2} {}

    _PrecisionType x() const { return e[0]; }
    _PrecisionType y() const { return e[1]; }
    _PrecisionType z() const { return e[2]; }

    _PrecisionType r() const { return e[0]; }
    _PrecisionType g() const { return e[1]; }
    _PrecisionType b() const { return e[2]; }

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
    _PrecisionType operator[](int i) const { return e[i]; }
    _PrecisionType& operator[](int i) { return e[i]; }

    Vec3& operator+=(const Vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    Vec3& operator*=(_PrecisionType t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    Vec3& operator/=(_PrecisionType t) {
        return *this *= 1/t;
    }

    _PrecisionType length() const {
        return sqrt(length_squared());
    }

    _PrecisionType length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// point3 is just an alias for Vec3, but useful for geometric clarity in the code.
//using point3 = Vec3;
typedef Vec3 Point3;
typedef Vec3 Color3;


// Vector Utility Functions

inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vec3 operator*(_PrecisionType t, const Vec3 &v) {
    return Vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vec3 operator*(const Vec3 &v, _PrecisionType t) {
    return t * v;
}

inline Vec3 operator/(Vec3 v, _PrecisionType t) {
    return (1/t) * v;
}

inline _PrecisionType dot(const Vec3 &u, const Vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

#endif