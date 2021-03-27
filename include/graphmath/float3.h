//
//  float3.h
//  CS 419
//
//  Created by Zehua Chen on 2/21/21.
//
#pragma once

#include "graphmath/not_implemented.h"

#if defined(__APPLE__)
#include <simd/simd.h>
#elif defined(_WIN32)
#include <DirectXMath.h>
#else
#include <array>
#endif

// Declarations

namespace graphmath {
struct float3;

/// @brief Take `sqrt` of all values of a `float3`
/// @param f3 the `float3`
float3 sqrt(const float3 &f3);

/// @brief Get a normalized version of `float3`
/// @param f3 the `float3` to normalize
/// @returns the normalized `float3`
float3 normalize(const float3 &f3);

/// @brief Compute the cross product of two `float3`
/// @param a one `float3`
/// @param b one `float3`
/// @returns the result `float3`
float3 cross(const float3 &a, const float3 &b);

/// @brief clamp a float to a low and high bound
/// @param value the value to clamp
/// @param low the low bound (inclusive)
/// @param high the high bound (inclusive)
/// @returns the clammped float3
float3 clamp(const float3 &value, const float3 &low, const float3 &high);

/// @brief Compute the dot product of two `float3`
/// @param a one `float3`
/// @param b one `float3`
/// @returns the resulting number`
float dot(const float3 &a, const float3 &b);

/// @brief Get the length of a `float3`
/// @param f3 the float 3
/// @returns the length
float length(const float3 &f3);

/// @brief three `float32` numbers `(x, y, z)`
struct float3 final {
 public:
  /// @brief the native `float3` type
  /// `simd::float3` on Apple Platform
#if defined(__APPLE__)
  using native_float3 = simd::float3;
#elif defined(_WIN32)
  using native_float3 = DirectX::XMVECTOR;
#else
  using native_float3 = std::array<float, 3>;
#endif

  /// @brief create a `float3` of zeroes
  float3();

  /// @brief create a `float3` with values
  /// @param x x
  /// @param y y
  /// @param z z
  float3(float x, float y, float z);

  /// @brief copy constructor
  /// @param other another `float3`
  float3(const float3 &other);

  /// @brief create a `float3` with `native_float3`
  ///
  /// @param native the native `float3` instance
  float3(const native_float3 &native);

  /// @brief Get `x` of `float3`
  /// @returns the `x` value of `float3`
  float x() const;

  /// @brief Get `y` of `float3`
  /// @returns the `y` value of `float3`
  float y() const;

  /// @brief Get `z` of `float3`
  /// @returns the `z` value of `float3`
  float z() const;

  /// @brief Add one `a` to `b` from another
  /// @param rhs `b`
  /// @returns the result
  float3 operator+(const float3 &rhs) const;

  /// @brief Subtract a value from all values of `float3`
  /// @param rhs the value to subtract with
  /// @returns the subtracted `float3`
  float3 operator-(float rhs) const;

  /// @brief Subtract one `a` from `b` from another
  /// @param rhs `b`
  /// @returns the result
  float3 operator-(const float3 &rhs) const;

  /// @brief Multiply all values of `float3` by a multiplier
  /// @param rhs the multiplier
  /// @returns the multiplied `float3`
  float3 operator*(float rhs) const;

  /// @brief Component-wise multiply `a`, `b`
  /// @param rhs `b`
  /// @returns the result
  float3 operator*(const float3 &rhs) const;

  /// @brief Divide all values of `float3` by a divisor
  /// @param rhs the divisor
  /// @returns the multiplied `float3`
  float3 operator/(float rhs) const;

  /// @brief Compare `this` with another `float3`
  /// @param rhs the other `float3`
  /// @returns true if equal; false otherwise
  bool operator==(const float3 &rhs) const;

  native_float3 native;
};

}  // namespace graphmath

// Implementations

namespace graphmath {
inline float3 sqrt(const float3 &f3) {
#if defined(__APPLE__)
  return simd::sqrt(f3.native);
#else
  throw_not_implemented();
#endif
}

inline float3 normalize(const float3 &f3) {
#if defined(__APPLE__)
  return float3{simd::normalize(f3.native)};
#else
  throw_not_implemented();
#endif
}

inline float3 cross(const float3 &a, const float3 &b) {
#if defined(__APPLE__)
  return float3{simd::cross(a.native, b.native)};
#else
  throw_not_implemented();
#endif
}

inline float3 clamp(const float3 &value, const float3 &low,
                    const float3 &high) {
#if defined(__APPLE__)
  return simd::clamp(value.native, low.native, high.native);
#else
  throw_not_implemented();
#endif
}

inline float dot(const float3 &a, const float3 &b) {
#if defined(__APPLE__)
  return simd::dot(a.native, b.native);
#else
  throw_not_implemented();
#endif
}

inline float length(const float3 &f3) {
#if defined(__APPLE__)
  return simd::length(f3.native);
#elif defined(_WIN32)
  return DirectX::XMVector3Length(f3.native);
#else
  throw_not_implemented();
#endif
}

inline float3::float3()
#if defined(__APPLE__)
    : native{simd::make_float3(0, 0, 0)} {
}
#elif defined(_WIN32)
    : native{DirectX::XMVectorSet(0, 0, 0, 1)} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float3::float3(float x, float y, float z)
#if defined(__APPLE__)
    : native{simd::make_float3(x, y, z)} {
}
#elif defined(_WIN32)
    : native{DirectX::XMVectorSet(x, y, z, 1)} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float3::float3(const float3 &other)
#if defined(__APPLE__) || defined(_WIN32)
    : native(other.native) {
}
#else
{
  throw_not_implemented();
}
#endif

inline float3::float3(const native_float3 &values)
#if defined(__APPLE__) || defined(_WIN32)
    : native(values) {
}
#else
{
  throw_not_implemented();
}
#endif

inline float float3::x() const {
#if defined(__APPLE__)
  return native.x;
#elif defined(_WIN32)
  return DirectX::XMVectorGetX(native);
#else
  throw_not_implemented();

  return -1.0f;
#endif
}

inline float float3::y() const {
#if defined(__APPLE__)
  return native.y;
#elif defined(_WIN32)
  return DirectX::XMVectorGetY(native);
#else
  throw_not_implemented();

  return -1.0f;
#endif
}

inline float float3::z() const {
#if defined(__APPLE__)
  return native.z;
#elif defined(_WIN32)
  return DirectX::XMVectorGetZ(native);
#else
  throw_not_implemented();

  return -1.0f
#endif
}

inline float3 float3::operator+(const float3 &rhs) const {
#if defined(__APPLE__)
  return native + rhs.native;
#elif defined(_WIN32)
  return float3{DirectX::XMVectorAdd(native, rhs.native)};
#else
  throw_not_implemented();

  return float3{};
#endif
}

inline float3 float3::operator-(float rhs) const {
#if defined(__APPLE__)
  return native - rhs;
#elif defined(_WIN32)
  using namespace DirectX;

  XMVECTOR rhs_vec = XMVectorSet(rhs, rhs, rhs, 0.0f);
  return float3{XMVectorSubtract(native, rhs_vec)};
#else
  throw_not_implemented();

  return float3{};
#endif
}

inline float3 float3::operator-(const float3 &rhs) const {
#if defined(__APPLE__)
  return native - rhs.native;
#elif defined(_WIN32)
  return float3{DirectX::XMVectorSubtract(native, rhs.native)};
#else
  throw_not_implemented();

  return float3{};
#endif
}

inline float3 float3::operator*(float rhs) const {
#if defined(__APPLE__)
  return native * rhs;
#elif defined(_WIN32)
  using namespace DirectX;

  XMVECTOR rhs_vec = XMVectorSet(rhs, rhs, rhs, 1.0f);
  return float3{XMVectorMultiply(native, rhs_vec)};
#else
  throw_not_implemented();

  return float3{};
#endif
}

inline float3 float3::operator*(const float3 &rhs) const {
#if defined(__APPLE__)
  return native * rhs.native;
#elif defined(_WIN32)
  return float3{DirectX::XMVectorMultiply(native, rhs.native)};
#else
  throw_not_implemented();

  return float3{};
#endif
}

inline float3 float3::operator/(float rhs) const {
#if defined(__APPLE__)
  return native / rhs;
#else
  throw_not_implemented();

  return float3{};
#endif
}

inline bool float3::operator==(const float3 &rhs) const {
  return x() == rhs.x() && y() == rhs.y() && z() == rhs.z();
}
}  // namespace graphmath
