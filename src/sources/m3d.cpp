#include "m3d.hpp"
#include <cmath>

namespace m3d {

// --- vec2 ---

vec2::vec2() : x(0.0f), y(0.0f) {}
vec2::vec2(float32 s) : x(s), y(s) {}
vec2::vec2(float32 x, float32 y) : x(x), y(y) {}
vec2::vec2(const vec3& v) : x(v.x), y(v.y) {}
vec2::vec2(const vec4& v) : x(v.x), y(v.y) {}

vec2 vec2::add(const vec2& o) const { return vec2(x + o.x, y + o.y); }
vec2 vec2::add(float32 s) const     { return vec2(x + s, y + s); }
vec2 vec2::sub(const vec2& o) const { return vec2(x - o.x, y - o.y); }
vec2 vec2::sub(float32 s) const     { return vec2(x - s, y - s); }
vec2 vec2::mul(const vec2& o) const { return vec2(x * o.x, y * o.y); }
vec2 vec2::mul(float32 s) const     { return vec2(x * s, y * s); }
vec2 vec2::div(const vec2& o) const { return vec2(x / o.x, y / o.y); }
vec2 vec2::div(float32 s) const     { return vec2(x / s, y / s); }

vec2& vec2::operator+=(const vec2& o) { x += o.x; y += o.y; return *this; }
vec2& vec2::operator+=(float32 s)     { x += s;   y += s;   return *this; }
vec2& vec2::operator-=(const vec2& o) { x -= o.x; y -= o.y; return *this; }
vec2& vec2::operator-=(float32 s)     { x -= s;   y -= s;   return *this; }
vec2& vec2::operator*=(const vec2& o) { x *= o.x; y *= o.y; return *this; }
vec2& vec2::operator*=(float32 s)     { x *= s;   y *= s;   return *this; }
vec2& vec2::operator/=(const vec2& o) { x /= o.x; y /= o.y; return *this; }
vec2& vec2::operator/=(float32 s)     { x /= s;   y /= s;   return *this; }

float32 vec2::lenSq() const { return x * x + y * y; }
float32 vec2::len() const   { return std::sqrt(lenSq()); }

// returns zero vector if length is below EPSILON to avoid division by zero
vec2 vec2::normalize() const {
    float32 l = len();
    if (l < EPSILON) { return vec2(0.0f); }
    return vec2(x / l, y / l);
}

float32 vec2::dot(const vec2& o) const   { return x * o.x + y * o.y; }
float32 vec2::cross(const vec2& o) const { return x * o.y - y * o.x; }

vec2 add(const vec2& a, const vec2& b) { return a.add(b); }
vec2 add(const vec2& v, float32 s)     { return v.add(s); }
vec2 add(float32 s, const vec2& v)     { return v.add(s); }
vec2 sub(const vec2& a, const vec2& b) { return a.sub(b); }
vec2 sub(const vec2& v, float32 s)     { return v.sub(s); }
vec2 sub(float32 s, const vec2& v)     { return vec2(s - v.x, s - v.y); }
vec2 mul(const vec2& a, const vec2& b) { return a.mul(b); }
vec2 mul(const vec2& v, float32 s)     { return v.mul(s); }
vec2 mul(float32 s, const vec2& v)     { return v.mul(s); }
vec2 div(const vec2& a, const vec2& b) { return a.div(b); }
vec2 div(const vec2& v, float32 s)     { return v.div(s); }
vec2 div(float32 s, const vec2& v)     { return vec2(s / v.x, s / v.y); }

vec2 operator+(const vec2& a, const vec2& b) { return a.add(b); }
vec2 operator+(const vec2& v, float32 s)     { return v.add(s); }
vec2 operator+(float32 s, const vec2& v)     { return v.add(s); }
vec2 operator-(const vec2& a, const vec2& b) { return a.sub(b); }
vec2 operator-(const vec2& v, float32 s)     { return v.sub(s); }
vec2 operator-(float32 s, const vec2& v)     { return vec2(s - v.x, s - v.y); }
vec2 operator*(const vec2& a, const vec2& b) { return a.mul(b); }
vec2 operator*(const vec2& v, float32 s)     { return v.mul(s); }
vec2 operator*(float32 s, const vec2& v)     { return v.mul(s); }
vec2 operator/(const vec2& a, const vec2& b) { return a.div(b); }
vec2 operator/(const vec2& v, float32 s)     { return v.div(s); }
vec2 operator/(float32 s, const vec2& v)     { return vec2(s / v.x, s / v.y); }

float32 dot(const vec2& a, const vec2& b) { return a.dot(b); }
float32 cross(const vec2& a, const vec2& b) { return a.cross(b); }
float32 lenSq(const vec2& v)  { return v.lenSq(); }
float32 len(const vec2& v)    { return v.len(); }
vec2 normalize(const vec2& v) { return v.normalize(); }

// --- vec3 ---

vec3::vec3() : x(0.0f), y(0.0f), z(0.0f) {}
vec3::vec3(float32 s) : x(s), y(s), z(s) {}
vec3::vec3(float32 x, float32 y, float32 z) : x(x), y(y), z(z) {}
vec3::vec3(const vec2& v, float32 z) : x(v.x), y(v.y), z(z) {}
vec3::vec3(const vec4& v) : x(v.x), y(v.y), z(v.z) {}

vec3 vec3::add(const vec3& o) const { return vec3(x + o.x, y + o.y, z + o.z); }
vec3 vec3::add(float32 s) const     { return vec3(x + s, y + s, z + s); }
vec3 vec3::sub(const vec3& o) const { return vec3(x - o.x, y - o.y, z - o.z); }
vec3 vec3::sub(float32 s) const     { return vec3(x - s, y - s, z - s); }
vec3 vec3::mul(const vec3& o) const { return vec3(x * o.x, y * o.y, z * o.z); }
vec3 vec3::mul(float32 s) const     { return vec3(x * s, y * s, z * s); }
vec3 vec3::div(const vec3& o) const { return vec3(x / o.x, y / o.y, z / o.z); }
vec3 vec3::div(float32 s) const     { return vec3(x / s, y / s, z / s); }

vec3& vec3::operator+=(const vec3& o) { x += o.x; y += o.y; z += o.z; return *this; }
vec3& vec3::operator+=(float32 s)     { x += s;   y += s;   z += s;   return *this; }
vec3& vec3::operator-=(const vec3& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
vec3& vec3::operator-=(float32 s)     { x -= s;   y -= s;   z -= s;   return *this; }
vec3& vec3::operator*=(const vec3& o) { x *= o.x; y *= o.y; z *= o.z; return *this; }
vec3& vec3::operator*=(float32 s)     { x *= s;   y *= s;   z *= s;   return *this; }
vec3& vec3::operator/=(const vec3& o) { x /= o.x; y /= o.y; z /= o.z; return *this; }
vec3& vec3::operator/=(float32 s)     { x /= s;   y /= s;   z /= s;   return *this; }

float32 vec3::lenSq() const { return x * x + y * y + z * z; }
float32 vec3::len() const   { return std::sqrt(lenSq()); }

// returns zero vector if length is below EPSILON to avoid division by zero
vec3 vec3::normalize() const {
    float32 l = len();
    if (l < EPSILON) { return vec3(0.0f); }
    return vec3(x / l, y / l, z / l);
}

float32 vec3::dot(const vec3& o) const { return x * o.x + y * o.y + z * o.z; }

vec3 vec3::cross(const vec3& o) const {
    return vec3(
        y * o.z - z * o.y,
        z * o.x - x * o.z,
        x * o.y - y * o.x
    );
}

vec3 add(const vec3& a, const vec3& b) { return a.add(b); }
vec3 add(const vec3& v, float32 s)     { return v.add(s); }
vec3 add(float32 s, const vec3& v)     { return v.add(s); }
vec3 sub(const vec3& a, const vec3& b) { return a.sub(b); }
vec3 sub(const vec3& v, float32 s)     { return v.sub(s); }
vec3 sub(float32 s, const vec3& v)     { return vec3(s - v.x, s - v.y, s - v.z); }
vec3 mul(const vec3& a, const vec3& b) { return a.mul(b); }
vec3 mul(const vec3& v, float32 s)     { return v.mul(s); }
vec3 mul(float32 s, const vec3& v)     { return v.mul(s); }
vec3 div(const vec3& a, const vec3& b) { return a.div(b); }
vec3 div(const vec3& v, float32 s)     { return v.div(s); }
vec3 div(float32 s, const vec3& v)     { return vec3(s / v.x, s / v.y, s / v.z); }

vec3 operator+(const vec3& a, const vec3& b) { return a.add(b); }
vec3 operator+(const vec3& v, float32 s)     { return v.add(s); }
vec3 operator+(float32 s, const vec3& v)     { return v.add(s); }
vec3 operator-(const vec3& a, const vec3& b) { return a.sub(b); }
vec3 operator-(const vec3& v, float32 s)     { return v.sub(s); }
vec3 operator-(float32 s, const vec3& v)     { return vec3(s - v.x, s - v.y, s - v.z); }
vec3 operator*(const vec3& a, const vec3& b) { return a.mul(b); }
vec3 operator*(const vec3& v, float32 s)     { return v.mul(s); }
vec3 operator*(float32 s, const vec3& v)     { return v.mul(s); }
vec3 operator/(const vec3& a, const vec3& b) { return a.div(b); }
vec3 operator/(const vec3& v, float32 s)     { return v.div(s); }
vec3 operator/(float32 s, const vec3& v)     { return vec3(s / v.x, s / v.y, s / v.z); }

float32 dot(const vec3& a, const vec3& b) { return a.dot(b); }
vec3 cross(const vec3& a, const vec3& b)  { return a.cross(b); }
float32 lenSq(const vec3& v)  { return v.lenSq(); }
float32 len(const vec3& v)    { return v.len(); }
vec3 normalize(const vec3& v) { return v.normalize(); }

// --- vec4 ---

vec4::vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
vec4::vec4(float32 s) : x(s), y(s), z(s), w(s) {}
vec4::vec4(float32 x, float32 y, float32 z, float32 w) : x(x), y(y), z(z), w(w) {}
vec4::vec4(const vec3& v, float32 w) : x(v.x), y(v.y), z(v.z), w(w) {}
vec4::vec4(const vec2& v, float32 z, float32 w) : x(v.x), y(v.y), z(z), w(w) {}

vec4 vec4::add(const vec4& o) const { return vec4(x + o.x, y + o.y, z + o.z, w + o.w); }
vec4 vec4::add(float32 s) const     { return vec4(x + s, y + s, z + s, w + s); }
vec4 vec4::sub(const vec4& o) const { return vec4(x - o.x, y - o.y, z - o.z, w - o.w); }
vec4 vec4::sub(float32 s) const     { return vec4(x - s, y - s, z - s, w - s); }
vec4 vec4::mul(const vec4& o) const { return vec4(x * o.x, y * o.y, z * o.z, w * o.w); }
vec4 vec4::mul(float32 s) const     { return vec4(x * s, y * s, z * s, w * s); }
vec4 vec4::div(const vec4& o) const { return vec4(x / o.x, y / o.y, z / o.z, w / o.w); }
vec4 vec4::div(float32 s) const     { return vec4(x / s, y / s, z / s, w / s); }

vec4& vec4::operator+=(const vec4& o) { x += o.x; y += o.y; z += o.z; w += o.w; return *this; }
vec4& vec4::operator+=(float32 s)     { x += s;   y += s;   z += s;   w += s;   return *this; }
vec4& vec4::operator-=(const vec4& o) { x -= o.x; y -= o.y; z -= o.z; w -= o.w; return *this; }
vec4& vec4::operator-=(float32 s)     { x -= s;   y -= s;   z -= s;   w -= s;   return *this; }
vec4& vec4::operator*=(const vec4& o) { x *= o.x; y *= o.y; z *= o.z; w *= o.w; return *this; }
vec4& vec4::operator*=(float32 s)     { x *= s;   y *= s;   z *= s;   w *= s;   return *this; }
vec4& vec4::operator/=(const vec4& o) { x /= o.x; y /= o.y; z /= o.z; w /= o.w; return *this; }
vec4& vec4::operator/=(float32 s)     { x /= s;   y /= s;   z /= s;   w /= s;   return *this; }

float32 vec4::lenSq() const { return x * x + y * y + z * z + w * w; }
float32 vec4::len() const   { return std::sqrt(lenSq()); }

// returns zero vector if length is below EPSILON to avoid division by zero
vec4 vec4::normalize() const {
    float32 l = len();
    if (l < EPSILON) { return vec4(0.0f); }
    return vec4(x / l, y / l, z / l, w / l);
}

vec4 add(const vec4& a, const vec4& b) { return a.add(b); }
vec4 add(const vec4& v, float32 s)     { return v.add(s); }
vec4 add(float32 s, const vec4& v)     { return v.add(s); }
vec4 sub(const vec4& a, const vec4& b) { return a.sub(b); }
vec4 sub(const vec4& v, float32 s)     { return v.sub(s); }
vec4 sub(float32 s, const vec4& v)     { return vec4(s - v.x, s - v.y, s - v.z, s - v.w); }
vec4 mul(const vec4& a, const vec4& b) { return a.mul(b); }
vec4 mul(const vec4& v, float32 s)     { return v.mul(s); }
vec4 mul(float32 s, const vec4& v)     { return v.mul(s); }
vec4 div(const vec4& a, const vec4& b) { return a.div(b); }
vec4 div(const vec4& v, float32 s)     { return v.div(s); }
vec4 div(float32 s, const vec4& v)     { return vec4(s / v.x, s / v.y, s / v.z, s / v.w); }

vec4 operator+(const vec4& a, const vec4& b) { return a.add(b); }
vec4 operator+(const vec4& v, float32 s)     { return v.add(s); }
vec4 operator+(float32 s, const vec4& v)     { return v.add(s); }
vec4 operator-(const vec4& a, const vec4& b) { return a.sub(b); }
vec4 operator-(const vec4& v, float32 s)     { return v.sub(s); }
vec4 operator-(float32 s, const vec4& v)     { return vec4(s - v.x, s - v.y, s - v.z, s - v.w); }
vec4 operator*(const vec4& a, const vec4& b) { return a.mul(b); }
vec4 operator*(const vec4& v, float32 s)     { return v.mul(s); }
vec4 operator*(float32 s, const vec4& v)     { return v.mul(s); }
vec4 operator/(const vec4& a, const vec4& b) { return a.div(b); }
vec4 operator/(const vec4& v, float32 s)     { return v.div(s); }
vec4 operator/(float32 s, const vec4& v)     { return vec4(s / v.x, s / v.y, s / v.z, s / v.w); }

float32 lenSq(const vec4& v)  { return v.lenSq(); }
float32 len(const vec4& v)    { return v.len(); }
vec4 normalize(const vec4& v) { return v.normalize(); }

} // namespace m3d
