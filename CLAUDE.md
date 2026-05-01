# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.  

## Project Overview  

m3d is a minimal math library in C++ that provides 2D and 3D vector and matrix operations.  

## Repo layout  

```
m3d/
|- .gitignore
|- CMakeLists.txt               <- CMake config file
|- src/
|  |- include/
|  |  |- m3d.hpp                <- library header (definitions)
|  |- sources/
|  |  |- main.cpp               <- testing the library
|  |  |- m3d.cpp                <- library implementation
|- build/                       <- CMake build output
|- bin/                         <- CMake binary output
|- local-store/                 <- garbage files that don't necesarily need deletion. Irrelevant context. DO NOT read this directory unless explicitly asked.
```  

## Architecture

All public API lives in a single header: `src/include/m3d.hpp`. Implementations are in `src/sources/m3d.cpp`.

## EPSILON

`EPSILON = 1e-6` is defined for floating point comparisons. Use it as a zero-guard in `normalize()` and `inverse()`, and for approximate equality checks in tests.

## Development phases

- Phase 1: `vec2`, `vec3`, `vec4` — COMPLETE
- Phase 2: `mat3`, `mat4` (core ops, `determinant`, `inverse`, `transpose`, `trace`) — COMPLETE
- Phase 3: transform helpers (`translate`, `rotate`, `scale`, `perspective`, `ortho`, `lookAt`) — next

## Current status

Phases 1 and 2 are complete. All types are implemented and tested in `src/sources/main.cpp`.

Key implementation decisions:
- Truncating cast constructors (`vec2(const vec3&)`, `vec2(const vec4&)`, `vec3(const vec4&)`, `mat3(const mat4&)`) are marked `explicit`.
- Extending cast constructors (`vec3(const vec2&, z)`, `vec4(const vec3&, w)`, `mat4(const mat3&, d)`) are non-explicit.
- `normalize()` and `inverse()` return zero vector/matrix when below `EPSILON`.
- `std::sqrt` and `std::abs` are included via `<cmath>` in `m3d.cpp` only.
- Matrix storage is column-major: `e[col * N + row]` where N is 3 or 4.
- `mat3(float32 d)` / `mat4(float32 d)` construct a diagonal matrix (identity when d=1).
- `mat4::inverse()` uses the Laplace 2x2 sub-determinant method (a0..a5, b0..b5 pairs).
- Matrix `mul()` / `operator*` is true matrix multiplication; element-wise ops use `add/sub/div` only.

## Code conventions  

- Namespace: `m3d`  
- Typedefs for: `int8`, `int16`, `int32`, `int64`, `uint8`, `uint16`, `uint32`, `uint64`, `float32` and `float64`
- Use `const` references where appropriate
- Use `const` method bodies where appropriate
- DO NOT use loops of any kind to implement vector/matrix creation or opeations. Hard code the algortihm for better optimization.
- Clean code: spaces between variables and operators, code is readable, well formatted.
- Add a single minimal comment where documentation is needed.
- DO NOT USE useless characters (such as `=`, `-` or arrows and such) in comments or documentation. Keep everything concise.
- `if`, `else`, `for`, `while`, (etc) statements always have a `{}` body.

Header template:  
```cpp
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

const float32 EPSILON = 1e-6;

struct vec2;
struct vec3;
struct vec4;
struct mat3;
struct mat4;

// Code definitions go here

} // namespace m3d

#endif // M3D_HPP
```

## Build

Requires CMake 3.26+ and a C++17-capable compiler.

```bash
cmake -B build -S .
cmake --build build --config Debug -j16
```

Output lands in `bin/`. On Windows with MSVC the executable is at `bin/Debug/m3d.exe`; on Linux/Mac it is `bin/m3d`.

Tests are written in `src/sources/main.cpp` — edit it, add/remove tests as necessary and rebuild to verify changes.

## Vector types

`vec2`, `vec3` and `vec4`.  
Each type provides:  
- Internal `float32` components: `x, y` for `vec2`; `x, y, z` for `vec3`; `x, y, z, w` for `vec4`.
- Default constructors, single-scalar initialization and element-wise initialization constructors.
- Constructors for casting from a vector type to another (e.g. `vec3(const vec4& v)` or `vec3(const vec2& v, float32 z = 0.0f)`)
- Element-wise arithmetic operations (`add()`, `sub()`, `mul()`, `div()`) both between two vectors (of the same type) or a vector and a scalar.
- Operations are implemented as an instance method (`vec3().add(vec3())`).
- Outside of the struct, namespace-level free function equivalents for the instance methods are provided + reversed order scalar-vector operations (`add(float32 scalar, vec3 vector)`).
- For each free function, an overloaded operator provided (`+`, `-`, `*`, `/`).
- `+=`, `-=`, `*=`, `/=` operators.
- `lenSq()`, `len()` and `normalize()` functions.  

`vec2` and `vec3` also provide:  
- `dot()` and `cross()` functions. `cross()` returns `float32` for `vec2` and `vec3` for `vec3`.

## Matrix types

`mat3` and `mat4`.  
Each type provides:
- Internal `float32 e[]` linear storage in column-major order, as per OpenGL convention. Index as `e[col * N + row]` where N is 3 or 4.
- Default constructors and diagonal initialization constructors with one scalar (`mat3(float32 diagonal)`)
- Constructors for casting from a matrix type to another (e.g. `mat3(const mat4& m)` or `mat4(const mat3& m, float32 d = 0.0f)`)
- Element-wise adition, subtraction and division both matrix-matrix and matrix-scalar
- Matrix–matrix and matrix–vector multiplication
- `determinant()`, `transpose()`, `inverse()`, `trace()`
- `mat3` (2D transform as a `mat3`) and `mat4` (3D transforms) transform helpers: `translate()`, `rotate()`, `scale()`

`mat4` also provides `perspective()`, `ortho()`, `lookAt()` transform helpers
