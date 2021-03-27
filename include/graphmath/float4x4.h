#pragma once

#include "graphmath/float4.h"
#include "graphmath/not_implemented.h"

#if defined(__APPLE__)
#include <simd/simd.h>
#else
#include <array>
#endif

// Declarations

namespace graphmath {
/// @brief a 4x4 matrix
struct float4x4 final {
 public:
  /// @brief The native `float4x4` type
#if defined(__APPLE__)
  using native_float4x4 = simd::float4x4;
#elif defined(_WIN32)
  using native_float4x4 = DirectX::XMMATRIX;
#else
  using native_float4x4 = std::array<float, 16>;
#endif

  /// @brief Create a `float4x4` matrix using a native matrix
  /// @param native the native matrix
  float4x4(const native_float4x4 &native);

  /// @brief Create a matrix with a single value along the diagonal
  /// @param value the value to use
  float4x4(float value);

  /// @brief Create a matrix from four rows
  /// @param row0 row 0
  /// @param row1 row 1
  /// @param row2 row 2
  /// @param row3 row 3
  float4x4(const float4 &row0, const float4 &row1, const float4 &row2,
           const float4 &row3);

  /// @brief Get the value at `(x, y)`
  /// @param y y
  /// @param x x
  /// @returns the value at `(row, column)`
  float get(size_t y, size_t x) const;

  /// @brief Set the value at `(x, y)`
  /// @param y y
  /// @param x x
  /// @param value the value at `(x, y)`
  void set(size_t y, size_t x, float value);

  /// @brief Get the value at `(x, y)`
  /// @param y y
  /// @param x x
  /// @returns the value at `(x, y)`
  float operator()(size_t y, size_t x) const;

  /// @brief Multiply a `float4x4` by a `float4`
  /// @param rhs the `float4`
  /// @returns the result of multiplication
  float4 operator*(const float4 &rhs) const;

  /// @brief Multiply a `float4x4` by a `float4x4`
  /// @param rhs the `float4x4`
  /// @returns the result of multiplication
  float4x4 operator*(const float4x4 &rhs) const;

  native_float4x4 native;
};

/// @brief Transpose a `float4x4` matrix
/// @param f4x4 the matrix to transpose
/// @returns the transposed matrix
float4x4 transpose(const float4x4 &f4x4);
}  // namespace graphmath

// Imlementations

namespace graphmath {
inline float4x4::float4x4(const native_float4x4 &native) : native(native) {}

inline float4x4::float4x4(float value) {
  set(0, 0, value);
  set(1, 1, value);
  set(2, 2, value);
  set(3, 3, value);
}

inline float4x4::float4x4(const float4 &row0, const float4 &row1,
                          const float4 &row2, const float4 &row3) {
#if defined(__APPLE__)
  simd::float4 col0{row0.x(), row1.x(), row2.x(), row3.x()};
  simd::float4 col1{row0.y(), row1.y(), row2.y(), row3.y()};
  simd::float4 col2{row0.z(), row1.z(), row2.z(), row3.z()};
  simd::float4 col3{row0.w(), row1.w(), row2.w(), row3.w()};

  native.columns[0] = col0;
  native.columns[1] = col1;
  native.columns[2] = col2;
  native.columns[3] = col3;
#elif defined(_WIN32)
  native = DirectX::XMMatrixSet(row0.x(), row0.y(), row0.z(), row0.w(),
                                row1.x(), row1.y(), row1.z(), row1.w(),
                                row2.x(), row2.y(), row2.z(), row2.w(),
                                row3.x(), row3.y(), row3.z(), row3.w());
#else
  throw_not_implemented();
#endif
}

inline float float4x4::get(size_t y, size_t x) const {
#if defined(__APPLE__)
  return native.columns[x][y];
#elif defined(_WIN32)
  using namespace DirectX;

  XMFLOAT4X4 dump;

  XMStoreFloat4x4(&dump, native);
  return dump.m[y][x];
#else
  throw_not_implemented();
#endif
}

inline void float4x4::set(size_t y, size_t x, float value) {
#if defined(__APPLE__)
  native.columns[x][y] = value;
#elif defined(_WIN32)
  using namespace DirectX;

  XMFLOAT4X4 dump;

  XMStoreFloat4x4(&dump, native);
  dump.m[y][x] = value;

  native = XMLoadFloat4x4(&dump);
#else
  throw_not_implemented();
#endif
}

inline float float4x4::operator()(size_t y, size_t x) const {
  return get(y, x);
}

inline float4 float4x4::operator*(const float4 &rhs) const {
#if defined(__APPLE__)
  return float4{native * rhs.native};
#elif defined(_WIN32)
  return float4{DirectX::XMVector4Transform(rhs.native, native)};
#else
  throw_not_implemented();
#endif
}

inline float4x4 float4x4::operator*(const float4x4 &rhs) const {
#if defined(__APPLE__)
  return float4x4{native * rhs.native};
#elif defined(_WIN32)
  return float4x4{DirectX::XMMatrixMultiply(native, rhs.native)};
#else
  throw_not_implemented();
#endif
}

inline float4x4 transpose(const float4x4 &f4x4) {
#if defined(__APPLE__)
  return float4x4{simd::transpose(f4x4.native)};
#elif defined(_WIN32)
  return float4x4{DirectX::XMMatrixTranspose(f4x4.native)};
#else
  throw_not_implemented();
#endif
}
}  // namespace graphmath
