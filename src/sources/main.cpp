#include <iostream>
#include <cmath>
#include "m3d.hpp"

using namespace m3d;

static bool eq(float32 a, float32 b) {
    return std::abs(a - b) < EPSILON;
}

static void test(const char* name, bool passed) {
    std::cout << (passed ? "PASS" : "FAIL") << ": " << name << "\n";
}

int main() {

    // --- vec2 ---
    {
        vec2 a(1.0f, 2.0f);
        vec2 b(3.0f, 4.0f);

        test("vec2 default ctor",    eq(vec2().x, 0.0f) && eq(vec2().y, 0.0f));
        test("vec2 scalar ctor",     eq(vec2(5.0f).x, 5.0f) && eq(vec2(5.0f).y, 5.0f));

        vec2 r = a.add(b);
        test("vec2 add",             eq(r.x, 4.0f) && eq(r.y, 6.0f));
        r = a.add(10.0f);
        test("vec2 add scalar",      eq(r.x, 11.0f) && eq(r.y, 12.0f));

        r = a.sub(b);
        test("vec2 sub",             eq(r.x, -2.0f) && eq(r.y, -2.0f));
        r = a.sub(1.0f);
        test("vec2 sub scalar",      eq(r.x, 0.0f) && eq(r.y, 1.0f));

        r = a.mul(b);
        test("vec2 mul",             eq(r.x, 3.0f) && eq(r.y, 8.0f));
        r = a.mul(2.0f);
        test("vec2 mul scalar",      eq(r.x, 2.0f) && eq(r.y, 4.0f));

        r = b.div(a);
        test("vec2 div",             eq(r.x, 3.0f) && eq(r.y, 2.0f));
        r = a.div(2.0f);
        test("vec2 div scalar",      eq(r.x, 0.5f) && eq(r.y, 1.0f));

        r = a + b;
        test("vec2 operator+",       eq(r.x, 4.0f) && eq(r.y, 6.0f));
        r = a + 1.0f;
        test("vec2 operator+ s",     eq(r.x, 2.0f) && eq(r.y, 3.0f));
        r = 1.0f + a;
        test("vec2 operator+ s rev", eq(r.x, 2.0f) && eq(r.y, 3.0f));
        r = a - b;
        test("vec2 operator-",       eq(r.x, -2.0f) && eq(r.y, -2.0f));
        r = 5.0f - a;
        test("vec2 operator- s rev", eq(r.x, 4.0f) && eq(r.y, 3.0f));
        r = a * 3.0f;
        test("vec2 operator*",       eq(r.x, 3.0f) && eq(r.y, 6.0f));
        r = 10.0f / b;
        test("vec2 operator/ s rev", eq(r.x, 10.0f / 3.0f) && eq(r.y, 2.5f));

        vec2 c(a);
        c += b;
        test("vec2 +=",              eq(c.x, 4.0f) && eq(c.y, 6.0f));
        c -= b;
        test("vec2 -=",              eq(c.x, 1.0f) && eq(c.y, 2.0f));
        c *= 2.0f;
        test("vec2 *= scalar",       eq(c.x, 2.0f) && eq(c.y, 4.0f));
        c /= 2.0f;
        test("vec2 /= scalar",       eq(c.x, 1.0f) && eq(c.y, 2.0f));

        test("vec2 lenSq",           eq(a.lenSq(), 5.0f));
        test("vec2 len",             eq(a.len(), std::sqrt(5.0f)));
        vec2 n = a.normalize();
        test("vec2 normalize",       eq(n.lenSq(), 1.0f));
        test("vec2 normalize zero",  eq(vec2(0.0f).normalize().lenSq(), 0.0f));

        test("vec2 dot",             eq(a.dot(b), 11.0f));
        test("vec2 cross",           eq(a.cross(b), -2.0f));

        test("vec2 free dot",        eq(dot(a, b), 11.0f));
        test("vec2 free cross",      eq(cross(a, b), -2.0f));
        test("vec2 free lenSq",      eq(lenSq(a), 5.0f));
        test("vec2 free normalize",  eq(lenSq(normalize(a)), 1.0f));

        test("vec2 free sub(s,v)",   eq(sub(10.0f, a).x, 9.0f) && eq(sub(10.0f, a).y, 8.0f));
        test("vec2 free div(s,v)",   eq(div(8.0f, vec2(2.0f, 4.0f)).x, 4.0f) && eq(div(8.0f, vec2(2.0f, 4.0f)).y, 2.0f));
    }

    // --- vec3 ---
    {
        vec3 a(1.0f, 2.0f, 3.0f);
        vec3 b(4.0f, 5.0f, 6.0f);

        test("vec3 default ctor",    eq(vec3().z, 0.0f));
        test("vec3 scalar ctor",     eq(vec3(7.0f).z, 7.0f));
        test("vec3 from vec2",       eq(vec3(vec2(1.0f, 2.0f)).z, 0.0f));
        test("vec3 from vec2 z",     eq(vec3(vec2(1.0f, 2.0f), 9.0f).z, 9.0f));
        test("vec3 from vec4",       eq(vec3(vec4(1.0f, 2.0f, 3.0f, 4.0f)).z, 3.0f));

        vec3 r = a.add(b);
        test("vec3 add",             eq(r.x, 5.0f) && eq(r.y, 7.0f) && eq(r.z, 9.0f));
        r = a - b;
        test("vec3 operator-",       eq(r.x, -3.0f) && eq(r.y, -3.0f) && eq(r.z, -3.0f));
        r = a * 2.0f;
        test("vec3 operator* s",     eq(r.x, 2.0f) && eq(r.y, 4.0f) && eq(r.z, 6.0f));

        vec3 c(a);
        c += b;
        test("vec3 +=",              eq(c.x, 5.0f) && eq(c.y, 7.0f) && eq(c.z, 9.0f));
        c *= 0.5f;
        test("vec3 *= scalar",       eq(c.x, 2.5f) && eq(c.y, 3.5f) && eq(c.z, 4.5f));

        test("vec3 lenSq",           eq(a.lenSq(), 14.0f));
        test("vec3 len",             eq(a.len(), std::sqrt(14.0f)));
        test("vec3 normalize",       eq(a.normalize().lenSq(), 1.0f));

        test("vec3 dot",             eq(a.dot(b), 32.0f));

        // (1,2,3) x (4,5,6) = (-3, 6, -3)
        vec3 cr = a.cross(b);
        test("vec3 cross",           eq(cr.x, -3.0f) && eq(cr.y, 6.0f) && eq(cr.z, -3.0f));

        test("vec3 free cross",      eq(cross(a, b).y, 6.0f));
        test("vec3 free sub(s,v)",   eq(sub(10.0f, a).x, 9.0f));
    }

    // --- vec4 ---
    {
        vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
        vec4 b(2.0f, 2.0f, 2.0f, 2.0f);

        test("vec4 default ctor",    eq(vec4().w, 0.0f));
        test("vec4 scalar ctor",     eq(vec4(3.0f).w, 3.0f));
        test("vec4 from vec3",       eq(vec4(vec3(1.0f, 2.0f, 3.0f)).w, 0.0f));
        test("vec4 from vec3 w",     eq(vec4(vec3(1.0f, 2.0f, 3.0f), 1.0f).w, 1.0f));
        test("vec4 from vec2",       eq(vec4(vec2(1.0f, 2.0f), 3.0f, 4.0f).z, 3.0f));

        vec4 r = a.add(b);
        test("vec4 add",             eq(r.x, 3.0f) && eq(r.y, 4.0f) && eq(r.z, 5.0f) && eq(r.w, 6.0f));
        r = a * 2.0f;
        test("vec4 operator* s",     eq(r.w, 8.0f));
        r = a / 2.0f;
        test("vec4 operator/ s",     eq(r.w, 2.0f));

        test("vec4 lenSq",           eq(a.lenSq(), 30.0f));
        test("vec4 normalize",       eq(a.normalize().lenSq(), 1.0f));

        vec4 c(a);
        c -= b;
        test("vec4 -=",              eq(c.x, -1.0f) && eq(c.w, 2.0f));

        test("vec4 free add",        eq(add(a, b).x, 3.0f));
        test("vec4 free sub(s,v)",   eq(sub(10.0f, b).x, 8.0f));
    }

    // --- cross-type cast constructors ---
    {
        vec3 v3(1.0f, 2.0f, 3.0f);
        vec2 v2 = vec2(v3);
        test("vec2 explicit from vec3", eq(v2.x, 1.0f) && eq(v2.y, 2.0f));

        vec4 v4(1.0f, 2.0f, 3.0f, 4.0f);
        vec2 v2b = vec2(v4);
        test("vec2 explicit from vec4", eq(v2b.x, 1.0f) && eq(v2b.y, 2.0f));

        vec3 v3b = vec3(v4);
        test("vec3 explicit from vec4", eq(v3b.x, 1.0f) && eq(v3b.z, 3.0f));
    }

    return 0;
}
