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
#endif

// Declarations

namespace graphmath {
class float4;

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

/// @brief four `float32` numbers `(x, y, z, w)`
class float4 final {
 public:
  /// @brief the native `float3` type
  /// `simd::float3` on Apple Platform, `DirectX::XMVECTOR` on Windows
#if defined(__APPLE__)
  using native_float4 = simd::float4;
#elif defined(_WIN32)
  using native_float4 = DirectX::XMVECTOR;
#else
  using native_float4 = void;
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
  /// @param other `b`
  /// @returns the result
  float4 operator+(const float4 &other) const;

  /// @brief `a - b`
  /// @param rhs `b`
  /// @returns the result
  float4 operator-(const float4 &rhs) const;

  /// @brief Multiply all values of `float4` by a multiplier
  /// @param multiplier the multiplier
  /// @returns the multiplied `float4`
  float4 operator*(float multiplier) const;

  /// @brief Component wise multiply `a` and `b`
  /// @param rhs `b`
  /// @returns the result
  float4 operator*(const float4 &rhs) const;

  friend float4 dot(const float4 &, const float4 &);
  friend float4 normalize(const float4 &);

  friend float length(const float4 &);

 private:
  native_float4 values_;
};
}  // namespace graphmath

// Implementations

namespace graphmath {
inline float4 dot(const float4 &a, const float4 &b) {
#if defined(__APPLE__)
  return float4{simd::dot(a.values_, b.values_)};
#elif defined(_WIN32)
  return float4{DirectX::XMVector4Dot(a.values_, b.values_)};
#else
  throw_not_implemented();
#endif
}

inline float4 normalize(const float4 &f4) {
#if defined(__APPLE__)
  return float4{simd::normalize(f4.values_)};
#elif
  return float4{DirectX::XMVector4Normalize(f4.values_)};
#else
  throw_not_implemented();
#endif
}

inline float length(const float4 &f4) {
#if defined(__APPLE__)
  return simd::length(f4.values_);
#else
  throw_not_implemented();
#endif
}

inline float4::float4()
#if defined(__APPLE__)
    : values_{simd::make_float4(0, 0, 0, 0)} {
}
#elif defined(_WIN32)
    : values_{DirectX::XMVectorZero()} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float4::float4(float x, float y, float z, float w)
#if defined(__APPLE__)
    : values_{simd::make_float4(x, y, z, w)} {
}
#elif defined(_WIN32)
    : values_{DirectX::XMVectorSet(x, y, z, w)} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float4::float4(const float4 &other) : values_(other.values_) {}

inline float4::float4(const native_float4 &values) : values_(values) {}

inline float float4::x() const {
#if defined(__APPLE__)
  return values_.x;
#elif defined(_WIN32)
  return DirectX::XMVectorGetX(values_);
#else
  throw_not_implemented();
#endif
}

inline float float4::y() const {
#if defined(__APPLE__)
  return values_.y;
#elif defined(_WIN32)
  return DirectX::XMVectorGetY(values_);
#else
  throw_not_implemented();
#endif
}

inline float float4::z() const {
#if defined(__APPLE__)
  return values_.z;
#elif defined(_WIN32)
  return DirectX::XMVectorGetZ(values_);
#else
  throw_not_implemented();
#endif
}

inline float float4::w() const {
#if defined(__APPLE__)
  return values_.w;
#elif defined(_WIN32)
  return DirectX::XMVectorGetW(values_);
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator+(const float4 &other) const {
#if defined(__APPLE__) || defined(_WIN32)
  return float4{values_ + other.values_};
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator-(const float4 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return float4{values_ - rhs.values_};
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator*(float multiplier) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ * multiplier;
#else
  throw_not_implemented();
#endif
}

inline float4 float4::operator*(const float4 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return float4{values_ * rhs.values_};
#else
  throw_not_implemented();
#endif
}
}  // namespace graphmath
