//
//  float4.h
//  CS 419
//
//  Created by Zehua Chen on 2/21/21.
//
#pragma once

#include <cmath>

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
/// @brief four `float32` numbers `(x, y, z, w)`
struct float4 final {
 public:
  /// @brief the native `float3` type
  /// `simd::float3` on Apple Platform, `DirectX::XMVECTOR` on Windows
#if defined(__APPLE__)
  using native_float4 = simd::float4;
#elif defined(_WIN32)
  using native_float4 = DirectX::XMVECTOR;
#else
  using native_float4 = std::array<float, 4>;
#endif

  /// @brief create a `float4` of zeroes
  float4();

  /// @brief create a `float4` with values
  /// @param x x
  /// @param y y
  /// @param z z
  /// @param w w
  float4(float x, float y, float z, float w);

  /// @brief copy constructor
  /// @param other another `float4`
  float4(const float4 &other);

  /// @brief create a `float4` with a `native_float4`
  ///
  /// @param values the native `float4` instance
  float4(const native_float4 &values);

  /// @brief Get `x` of `float4`
  /// @returns the `x` value of `float4`
  float x() const;

  /// @brief Get `y` of `float4`
  /// @returns the `y` value of `float4`
  float y() const;

  /// @brief Get `z` of `float4`
  /// @returns the `z` value of `float4`
  float z() const;

  /// @brief Get `w` of `float4`
  /// @returns the `w` value of `float4`
  float w() const;

  /// @brief Add `a` and `b`
  /// @param rhs `b`
  /// @returns the result
  float4 operator+(const float4 &rhs) const;

  /// @brief `a - b`
  /// @param rhs `b`
  /// @returns the result
  float4 operator-(const float4 &rhs) const;

  /// @brief Multiply all values of `float4` by a multiplier
  /// @param rhs the multiplier
  /// @returns the multiplied `float4`
  float4 operator*(float rhs) const;

  /// @brief Component wise multiply `a` and `b`
  /// @param rhs `b`
  /// @returns the result
  float4 operator*(const float4 &rhs) const;

  native_float4 native;
};

/// @brief Compute the dot product of two `float4`
/// @param a one `float4`
/// @param b one `float4`
/// @returns the result `float4`
float4 dot(const float4 &a, const float4 &b);

/// @brief Get a normalized version of `float4`
/// @param f4 the `float4` to normalize
/// @returns the normalized `float4`
float4 normalize(const float4 &f4);

/// @brief Get the magnitude of `float4`
/// @param f4 the `float4`
/// @returns the magnitude
float length(const float4 &f4);

}  // namespace graphmath

// Implementations

namespace graphmath {
inline float4::float4()
#if defined(__APPLE__)
    : native{simd::make_float4(0, 0, 0, 0)} {
}
#elif defined(_WIN32)
    : native{DirectX::XMVectorZero()} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float4::float4(float x, float y, float z, float w)
#if defined(__APPLE__)
    : native{simd::make_float4(x, y, z, w)} {
}
#elif defined(_WIN32)
    : native{DirectX::XMVectorSet(x, y, z, w)} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float4::float4(const float4 &other) : native(other.native) {}

inline float4::float4(const native_float4 &values) : native(values) {}

inline float float4::x() const {
#if defined(__APPLE__)
  return native.x;
#elif defined(_WIN32)
  return DirectX::XMVectorGetX(native);
#else
  throw_not_implemented();
#endif
}

inline float float4::y() const {
#if defined(__APPLE__)
  return native.y;
#elif defined(_WIN32)
  return DirectX::XMVectorGetY(native);
#else
  throw_not_implemented();
#endif
}

inline float float4::z() const {
#if defined(__APPLE__)
  return native.z;
#elif defined(_WIN32)
  return DirectX::XMVectorGetZ(native);
#else
  throw_not_implemented();
#endif
}

inline float float4::w() const {
#if defined(__APPLE__)
  return native.w;
#elif defined(_WIN32)
  return DirectX::XMVectorGetW(native);
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator+(const float4 &rhs) const {
#if defined(__APPLE__)
  return float4{native + rhs.native};
#elif defined(_WIN32)
  return float4{DirectX::XMVectorAdd(native, rhs.native)};
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator-(const float4 &rhs) const {
#if defined(__APPLE__)
  return float4{native - rhs.native};
#elif defined(_WIN32)
  return float4{DirectX::XMVectorSubtract(native, rhs.native)};
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator*(float rhs) const {
#if defined(__APPLE__)
  return native * rhs;
#elif defined(_WIN32)
  using namespace DirectX;

  XMVECTOR rhs_vec = XMVectorSet(rhs, rhs, rhs, rhs);
  return float4{XMVectorMultiply(native, rhs_vec)};
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator*(const float4 &rhs) const {
#if defined(__APPLE__)
  return float4{native * rhs.native};
#elif defined(_WIN32)
  return float4{DirectX::XMVectorMultiply(native, rhs.native)};
#else
  throw_not_implemented();
#endif
}

inline float4 dot(const float4 &a, const float4 &b) {
#if defined(__APPLE__)
  return float4{simd::dot(a.native, b.native)};
#elif defined(_WIN32)
  return float4{DirectX::XMVector4Dot(a.native, b.native)};
#else
  throw_not_implemented();
#endif
}

inline float4 normalize(const float4 &f4) {
#if defined(__APPLE__)
  return float4{simd::normalize(f4.native)};
#elif defined(_WIN32)
  return float4{DirectX::XMVector4Normalize(f4.native)};
#else
  throw_not_implemented();
#endif
}

inline float length(const float4 &f4) {
#if defined(__APPLE__)
  return simd::length(f4.native);
#elif defined(_WIN32)
  using namespace DirectX;

  return XMVectorGetX(XMVector4Length(f4.native));
#else
  throw_not_implemented();
#endif
}
}  // namespace graphmath
