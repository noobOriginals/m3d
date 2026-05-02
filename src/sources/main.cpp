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

    // --- mat3 ---
    {
        mat3 I(1.0f);
        test("mat3 identity diagonal",  eq(I.e[0], 1.0f) && eq(I.e[4], 1.0f) && eq(I.e[8], 1.0f));
        test("mat3 identity off-diag",  eq(I.e[1], 0.0f) && eq(I.e[3], 0.0f));
        test("mat3 default zero",       eq(mat3().e[0], 0.0f) && eq(mat3().e[4], 0.0f));
        test("mat3 trace identity",     eq(I.trace(), 3.0f));
        test("mat3 det identity",       eq(I.determinant(), 1.0f));

        mat3 T = I.transpose();
        test("mat3 transpose identity", eq(T.e[0], 1.0f) && eq(T.e[4], 1.0f) && eq(T.e[8], 1.0f));

        // known 3x3 matrix (column-major):
        // | 1  2  3 |
        // | 0  1  4 |
        // | 5  6  0 |
        // column-major storage: col0=(1,0,5), col1=(2,1,6), col2=(3,4,0)
        mat3 M;
        M.e[0]=1; M.e[1]=0; M.e[2]=5;
        M.e[3]=2; M.e[4]=1; M.e[5]=6;
        M.e[6]=3; M.e[7]=4; M.e[8]=0;

        // det = 1*(1*0 - 4*6) - 2*(0*0 - 4*5) + 3*(0*6 - 1*5) = 1*(-24) - 2*(-20) + 3*(-5) = -24+40-15 = 1
        test("mat3 determinant",        eq(M.determinant(), 1.0f));
        test("mat3 trace",              eq(M.trace(), 2.0f));

        mat3 Minv = M.inverse();
        mat3 MMinv = M * Minv;
        test("mat3 M*inv(M) = I",       eq(MMinv.e[0], 1.0f) && eq(MMinv.e[4], 1.0f) && eq(MMinv.e[8], 1.0f)
                                      && eq(MMinv.e[1], 0.0f) && eq(MMinv.e[3], 0.0f));

        mat3 MT = M.transpose();
        // transpose swaps e[1]<->e[3], e[2]<->e[6], e[5]<->e[7]
        test("mat3 transpose",          eq(MT.e[1], M.e[3]) && eq(MT.e[3], M.e[1]) && eq(MT.e[2], M.e[6]));

        // mul(mat3, vec3)
        vec3 v(1.0f, 0.0f, 0.0f);
        vec3 Mv = M * v;
        // first column of M: (1, 0, 5)
        test("mat3 * vec3",             eq(Mv.x, 1.0f) && eq(Mv.y, 0.0f) && eq(Mv.z, 5.0f));

        // mul(mat3, mat3): M * I = M
        mat3 MI = M * I;
        test("mat3 * identity = M",     eq(MI.e[0], M.e[0]) && eq(MI.e[4], M.e[4]) && eq(MI.e[8], M.e[8]));

        // element-wise ops
        mat3 M2 = M + M;
        test("mat3 add",                eq(M2.e[0], 2.0f) && eq(M2.e[4], 2.0f));
        mat3 M3 = M * 3.0f;
        test("mat3 mul scalar",         eq(M3.e[0], 3.0f) && eq(M3.e[4], 3.0f));

        // cast from mat4
        mat4 big(2.0f);
        mat3 fromMat4 = mat3(big);
        test("mat3 from mat4",          eq(fromMat4.e[0], 2.0f) && eq(fromMat4.e[4], 2.0f) && eq(fromMat4.e[8], 2.0f));
    }

    // --- mat4 ---
    {
        mat4 I(1.0f);
        test("mat4 identity diagonal",  eq(I.e[0], 1.0f) && eq(I.e[5], 1.0f) && eq(I.e[10], 1.0f) && eq(I.e[15], 1.0f));
        test("mat4 identity off-diag",  eq(I.e[1], 0.0f) && eq(I.e[4], 0.0f));
        test("mat4 trace identity",     eq(I.trace(), 4.0f));
        test("mat4 det identity",       eq(I.determinant(), 1.0f));

        mat4 T = I.transpose();
        test("mat4 transpose identity", eq(T.e[0], 1.0f) && eq(T.e[15], 1.0f) && eq(T.e[1], 0.0f));

        // diagonal matrix with known det
        mat4 D(3.0f);
        test("mat4 det diagonal 3",     eq(D.determinant(), 81.0f));

        mat4 Dinv = D.inverse();
        mat4 DDinv = D * Dinv;
        test("mat4 D*inv(D) = I",       eq(DDinv.e[0], 1.0f) && eq(DDinv.e[5], 1.0f)
                                      && eq(DDinv.e[10], 1.0f) && eq(DDinv.e[15], 1.0f)
                                      && eq(DDinv.e[1], 0.0f));

        // singular matrix: zero det, inverse should return zero matrix
        mat4 S;
        test("mat4 singular inverse",   eq(S.inverse().e[0], 0.0f));

        // mul(mat4, vec4): identity * v = v
        vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
        vec4 Iv = I * v;
        test("mat4 * vec4 identity",    eq(Iv.x, 1.0f) && eq(Iv.y, 2.0f) && eq(Iv.z, 3.0f) && eq(Iv.w, 4.0f));

        // mul(mat4, mat4): I * I = I
        mat4 II = I * I;
        test("mat4 I*I = I",            eq(II.e[0], 1.0f) && eq(II.e[5], 1.0f) && eq(II.e[1], 0.0f));

        // element-wise add
        mat4 I2 = I + I;
        test("mat4 add",                eq(I2.e[0], 2.0f) && eq(I2.e[5], 2.0f) && eq(I2.e[1], 0.0f));

        // from mat3
        mat3 m3(2.0f);
        mat4 fromMat3(m3, 1.0f);
        test("mat4 from mat3",          eq(fromMat3.e[0], 2.0f) && eq(fromMat3.e[5], 2.0f)
                                      && eq(fromMat3.e[10], 2.0f) && eq(fromMat3.e[15], 1.0f)
                                      && eq(fromMat3.e[3], 0.0f));

        // transpose of a non-symmetric matrix
        mat4 A(1.0f);
        A.e[4] = 5.0f; // set off-diagonal
        mat4 AT = A.transpose();
        test("mat4 transpose off-diag", eq(AT.e[1], 5.0f) && eq(AT.e[4], 0.0f));

        // *= operator
        mat4 B(2.0f);
        B *= mat4(0.5f);
        test("mat4 *=",                 eq(B.e[0], 1.0f) && eq(B.e[5], 1.0f));
    }

    // tolerance for trig-based checks
    auto eq5 = [](float32 a, float32 b) { return std::abs(a - b) < 1e-5f; };

    // --- mat3 transforms ---
    {
        const float32 pi = 3.14159265358979323846f;

        // translate: identity * T(2,3) — column 2 should be (2,3,1)
        mat3 Tt = translate(vec2(2.0f, 3.0f));
        test("mat3 translate e[6]",      eq(Tt.e[6], 2.0f));
        test("mat3 translate e[7]",      eq(Tt.e[7], 3.0f));
        test("mat3 translate e[8]",      eq(Tt.e[8], 1.0f));
        test("mat3 translate diagonal",  eq(Tt.e[0], 1.0f) && eq(Tt.e[4], 1.0f));

        // apply translate to a point (1,1,1) -> (3,4,1)
        vec3 pt = Tt * vec3(1.0f, 1.0f, 1.0f);
        test("mat3 translate * point",   eq(pt.x, 3.0f) && eq(pt.y, 4.0f) && eq(pt.z, 1.0f));

        // rotate 90 deg: cos=0, sin=1 -> e[0]=0,e[1]=1,e[3]=-1,e[4]=0
        mat3 Tr = rotate(pi * 0.5f);
        test("mat3 rotate e[0]",         eq5(Tr.e[0], 0.0f));
        test("mat3 rotate e[1]",         eq5(Tr.e[1], 1.0f));
        test("mat3 rotate e[3]",         eq5(Tr.e[3], -1.0f));
        test("mat3 rotate e[4]",         eq5(Tr.e[4], 0.0f));

        // rotate(mat3,angle) free function equals instance method
        test("mat3 free rotate equiv",   eq5(rotate(mat3(1.0f), pi * 0.5f).e[1], 1.0f));

        // scale: identity * S(2,3)
        mat3 Ts = scale(vec2(2.0f, 3.0f));
        test("mat3 scale e[0]",          eq(Ts.e[0], 2.0f));
        test("mat3 scale e[4]",          eq(Ts.e[4], 3.0f));
        test("mat3 scale e[8]",          eq(Ts.e[8], 1.0f));

        // chain: T*S applied right-to-left, so scale first then translate
        // T*S*(1,1,1): S*(1,1,1)=(2,2,1), T*(2,2,1)=(3,4,1)
        mat3 Tts = mat3(1.0f).translate(vec2(1.0f, 2.0f)).scale(vec2(2.0f, 2.0f));
        vec3 p2 = Tts * vec3(1.0f, 1.0f, 1.0f);
        test("mat3 chain translate+scale", eq(p2.x, 3.0f) && eq(p2.y, 4.0f));
    }

    // --- mat4 transforms ---
    {
        const float32 pi = 3.14159265358979323846f;

        // translate
        mat4 Tt = translate(vec3(1.0f, 2.0f, 3.0f));
        test("mat4 translate e[12]",     eq(Tt.e[12], 1.0f));
        test("mat4 translate e[13]",     eq(Tt.e[13], 2.0f));
        test("mat4 translate e[14]",     eq(Tt.e[14], 3.0f));
        test("mat4 translate e[15]",     eq(Tt.e[15], 1.0f));
        test("mat4 translate diagonal",  eq(Tt.e[0], 1.0f) && eq(Tt.e[5], 1.0f) && eq(Tt.e[10], 1.0f));

        // apply to a point (0,0,0,1) -> (1,2,3,1)
        vec4 pt = Tt * vec4(0.0f, 0.0f, 0.0f, 1.0f);
        test("mat4 translate * point",   eq(pt.x, 1.0f) && eq(pt.y, 2.0f) && eq(pt.z, 3.0f));

        // rotate 90 deg around Z: (1,0,0,0) -> (0,1,0,0)
        auto eq5 = [](float32 a, float32 b) { return std::abs(a - b) < 1e-5f; };
        mat4 Tr = rotate(pi * 0.5f, vec3(0.0f, 0.0f, 1.0f));
        vec4 rx = Tr * vec4(1.0f, 0.0f, 0.0f, 0.0f);
        test("mat4 rotate Z 90 x->y.x",  eq5(rx.x, 0.0f));
        test("mat4 rotate Z 90 x->y.y",  eq5(rx.y, 1.0f));

        // rotate 90 deg around X: (0,1,0,0) -> (0,0,1,0)
        mat4 TrX = rotate(pi * 0.5f, vec3(1.0f, 0.0f, 0.0f));
        vec4 ry = TrX * vec4(0.0f, 1.0f, 0.0f, 0.0f);
        test("mat4 rotate X 90 y->z.y",  eq5(ry.y, 0.0f));
        test("mat4 rotate X 90 y->z.z",  eq5(ry.z, 1.0f));

        // scale
        mat4 Ts = scale(vec3(2.0f, 3.0f, 4.0f));
        test("mat4 scale e[0]",          eq(Ts.e[0], 2.0f));
        test("mat4 scale e[5]",          eq(Ts.e[5], 3.0f));
        test("mat4 scale e[10]",         eq(Ts.e[10], 4.0f));
        test("mat4 scale e[15]",         eq(Ts.e[15], 1.0f));

        // perspective: check known entries
        // fovy=pi/2, aspect=1, zNear=1, zFar=100
        // f=1/tan(pi/4)=1, e[0]=1, e[5]=1, e[11]=-1, e[15]=0
        mat4 Tp = perspective(pi * 0.5f, 1.0f, 1.0f, 100.0f);
        test("mat4 perspective e[0]",    eq5(Tp.e[0], 1.0f));
        test("mat4 perspective e[5]",    eq5(Tp.e[5], 1.0f));
        test("mat4 perspective e[11]",   eq(Tp.e[11], -1.0f));
        test("mat4 perspective e[15]",   eq(Tp.e[15], 0.0f));

        // ortho: left=-1,right=1,bottom=-1,top=1,near=0,far=1
        // e[0]=1, e[5]=1, e[10]=-2, e[12]=0, e[13]=0, e[14]=-1, e[15]=1
        mat4 To = ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f);
        test("mat4 ortho e[0]",          eq(To.e[0], 1.0f));
        test("mat4 ortho e[5]",          eq(To.e[5], 1.0f));
        test("mat4 ortho e[10]",         eq(To.e[10], -2.0f));
        test("mat4 ortho e[12]",         eq(To.e[12], 0.0f));
        test("mat4 ortho e[14]",         eq(To.e[14], -1.0f));
        test("mat4 ortho e[15]",         eq(To.e[15], 1.0f));

        // lookAt: eye=(0,0,5), center=(0,0,0), up=(0,1,0)
        // forward=(0,0,-1), right=(1,0,0), up=(0,1,0)
        // e[0]=1,e[5]=1,e[10]=1,e[14]=5 (dot(f,eye)=dot(0,0,-1,0,0,5)=-5 => wait)
        // dot(f,eye) = (0,0,-1).(0,0,5) = -5, so e[14]=-5
        // -dot(r,eye)=0, -dot(u,eye)=0
        mat4 Tv = lookAt(vec3(0.0f, 0.0f, 5.0f), vec3(0.0f), vec3(0.0f, 1.0f, 0.0f));
        test("mat4 lookAt e[0]",         eq5(Tv.e[0], 1.0f));
        test("mat4 lookAt e[5]",         eq5(Tv.e[5], 1.0f));
        test("mat4 lookAt e[10]",        eq5(Tv.e[10], 1.0f));  // -(-1)=1 -> wait, e[10]=-f.z=-(-1)=1
        test("mat4 lookAt e[14]",        eq5(Tv.e[14], -5.0f)); // dot(f,eye)=(0,0,-1).(0,0,5)=-5
        test("mat4 lookAt e[15]",        eq(Tv.e[15], 1.0f));

        // free function equiv
        test("mat4 free translate",      eq(translate(mat4(1.0f), vec3(1.0f,0.0f,0.0f)).e[12], 1.0f));
        test("mat4 free scale",          eq(scale(mat4(1.0f), vec3(2.0f,2.0f,2.0f)).e[0], 2.0f));
    }

    return 0;
}
