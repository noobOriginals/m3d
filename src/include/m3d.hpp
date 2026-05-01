#ifndef M3D_HPP
#define M3D_HPP

namespace m3d {

typedef signed char int8;
typedef signed short int16;
typedef signed int int32;
typedef signed long long int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

typedef float float32;
typedef double float64;

const float32 EPSILON = 1e-6f;

struct vec2;
struct vec3;
struct vec4;
struct mat3;
struct mat4;

// --- vec2 ---

struct vec2 {
    float32 x, y;

    vec2();
    vec2(float32 s);
    vec2(float32 x, float32 y);
    explicit vec2(const vec3& v);
    explicit vec2(const vec4& v);

    vec2 add(const vec2& other) const;
    vec2 add(float32 s) const;
    vec2 sub(const vec2& other) const;
    vec2 sub(float32 s) const;
    vec2 mul(const vec2& other) const;
    vec2 mul(float32 s) const;
    vec2 div(const vec2& other) const;
    vec2 div(float32 s) const;

    vec2& operator+=(const vec2& other);
    vec2& operator+=(float32 s);
    vec2& operator-=(const vec2& other);
    vec2& operator-=(float32 s);
    vec2& operator*=(const vec2& other);
    vec2& operator*=(float32 s);
    vec2& operator/=(const vec2& other);
    vec2& operator/=(float32 s);

    float32 lenSq() const;
    float32 len() const;
    vec2 normalize() const;

    float32 dot(const vec2& other) const;
    float32 cross(const vec2& other) const;
};

vec2 add(const vec2& a, const vec2& b);
vec2 add(const vec2& v, float32 s);
vec2 add(float32 s, const vec2& v);
vec2 sub(const vec2& a, const vec2& b);
vec2 sub(const vec2& v, float32 s);
vec2 sub(float32 s, const vec2& v);
vec2 mul(const vec2& a, const vec2& b);
vec2 mul(const vec2& v, float32 s);
vec2 mul(float32 s, const vec2& v);
vec2 div(const vec2& a, const vec2& b);
vec2 div(const vec2& v, float32 s);
vec2 div(float32 s, const vec2& v);

vec2 operator+(const vec2& a, const vec2& b);
vec2 operator+(const vec2& v, float32 s);
vec2 operator+(float32 s, const vec2& v);
vec2 operator-(const vec2& a, const vec2& b);
vec2 operator-(const vec2& v, float32 s);
vec2 operator-(float32 s, const vec2& v);
vec2 operator*(const vec2& a, const vec2& b);
vec2 operator*(const vec2& v, float32 s);
vec2 operator*(float32 s, const vec2& v);
vec2 operator/(const vec2& a, const vec2& b);
vec2 operator/(const vec2& v, float32 s);
vec2 operator/(float32 s, const vec2& v);

float32 dot(const vec2& a, const vec2& b);
float32 cross(const vec2& a, const vec2& b);
float32 lenSq(const vec2& v);
float32 len(const vec2& v);
vec2 normalize(const vec2& v);

// --- vec3 ---

struct vec3 {
    float32 x, y, z;

    vec3();
    vec3(float32 s);
    vec3(float32 x, float32 y, float32 z);
    vec3(const vec2& v, float32 z = 0.0f);
    explicit vec3(const vec4& v);

    vec3 add(const vec3& other) const;
    vec3 add(float32 s) const;
    vec3 sub(const vec3& other) const;
    vec3 sub(float32 s) const;
    vec3 mul(const vec3& other) const;
    vec3 mul(float32 s) const;
    vec3 div(const vec3& other) const;
    vec3 div(float32 s) const;

    vec3& operator+=(const vec3& other);
    vec3& operator+=(float32 s);
    vec3& operator-=(const vec3& other);
    vec3& operator-=(float32 s);
    vec3& operator*=(const vec3& other);
    vec3& operator*=(float32 s);
    vec3& operator/=(const vec3& other);
    vec3& operator/=(float32 s);

    float32 lenSq() const;
    float32 len() const;
    vec3 normalize() const;

    float32 dot(const vec3& other) const;
    vec3 cross(const vec3& other) const;
};

vec3 add(const vec3& a, const vec3& b);
vec3 add(const vec3& v, float32 s);
vec3 add(float32 s, const vec3& v);
vec3 sub(const vec3& a, const vec3& b);
vec3 sub(const vec3& v, float32 s);
vec3 sub(float32 s, const vec3& v);
vec3 mul(const vec3& a, const vec3& b);
vec3 mul(const vec3& v, float32 s);
vec3 mul(float32 s, const vec3& v);
vec3 div(const vec3& a, const vec3& b);
vec3 div(const vec3& v, float32 s);
vec3 div(float32 s, const vec3& v);

vec3 operator+(const vec3& a, const vec3& b);
vec3 operator+(const vec3& v, float32 s);
vec3 operator+(float32 s, const vec3& v);
vec3 operator-(const vec3& a, const vec3& b);
vec3 operator-(const vec3& v, float32 s);
vec3 operator-(float32 s, const vec3& v);
vec3 operator*(const vec3& a, const vec3& b);
vec3 operator*(const vec3& v, float32 s);
vec3 operator*(float32 s, const vec3& v);
vec3 operator/(const vec3& a, const vec3& b);
vec3 operator/(const vec3& v, float32 s);
vec3 operator/(float32 s, const vec3& v);

float32 dot(const vec3& a, const vec3& b);
vec3 cross(const vec3& a, const vec3& b);
float32 lenSq(const vec3& v);
float32 len(const vec3& v);
vec3 normalize(const vec3& v);

// --- vec4 ---

struct vec4 {
    float32 x, y, z, w;

    vec4();
    vec4(float32 s);
    vec4(float32 x, float32 y, float32 z, float32 w);
    vec4(const vec3& v, float32 w = 0.0f);
    vec4(const vec2& v, float32 z = 0.0f, float32 w = 0.0f);

    vec4 add(const vec4& other) const;
    vec4 add(float32 s) const;
    vec4 sub(const vec4& other) const;
    vec4 sub(float32 s) const;
    vec4 mul(const vec4& other) const;
    vec4 mul(float32 s) const;
    vec4 div(const vec4& other) const;
    vec4 div(float32 s) const;

    vec4& operator+=(const vec4& other);
    vec4& operator+=(float32 s);
    vec4& operator-=(const vec4& other);
    vec4& operator-=(float32 s);
    vec4& operator*=(const vec4& other);
    vec4& operator*=(float32 s);
    vec4& operator/=(const vec4& other);
    vec4& operator/=(float32 s);

    float32 lenSq() const;
    float32 len() const;
    vec4 normalize() const;
};

vec4 add(const vec4& a, const vec4& b);
vec4 add(const vec4& v, float32 s);
vec4 add(float32 s, const vec4& v);
vec4 sub(const vec4& a, const vec4& b);
vec4 sub(const vec4& v, float32 s);
vec4 sub(float32 s, const vec4& v);
vec4 mul(const vec4& a, const vec4& b);
vec4 mul(const vec4& v, float32 s);
vec4 mul(float32 s, const vec4& v);
vec4 div(const vec4& a, const vec4& b);
vec4 div(const vec4& v, float32 s);
vec4 div(float32 s, const vec4& v);

vec4 operator+(const vec4& a, const vec4& b);
vec4 operator+(const vec4& v, float32 s);
vec4 operator+(float32 s, const vec4& v);
vec4 operator-(const vec4& a, const vec4& b);
vec4 operator-(const vec4& v, float32 s);
vec4 operator-(float32 s, const vec4& v);
vec4 operator*(const vec4& a, const vec4& b);
vec4 operator*(const vec4& v, float32 s);
vec4 operator*(float32 s, const vec4& v);
vec4 operator/(const vec4& a, const vec4& b);
vec4 operator/(const vec4& v, float32 s);
vec4 operator/(float32 s, const vec4& v);

float32 lenSq(const vec4& v);
float32 len(const vec4& v);
vec4 normalize(const vec4& v);

} // namespace m3d

#endif // M3D_HPP
