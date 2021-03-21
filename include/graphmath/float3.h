//
//  float3.h
//  CS 419
//
//  Created by Zehua Chen on 2/21/21.
//
#pragma once

#include <cmath>

#include "graphmath/not_implemented.h"

#ifdef __APPLE__
#include <simd/simd.h>
#endif

// Declarations

namespace graphmath {
class float3;

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
class float3 final {
 public:
  /// @brief the native `float3` type
  /// `simd::float3` on Apple Platform
#if defined(__APPLE__)
  using native_float3 = simd::float3;
#else
  using native_float3 = void;
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

  /// @brief Multiply all values of `float3` by a multiplier
  /// @param multiplier the multiplier
  /// @returns the multiplied `float3`
  float3 operator*(float multiplier) const;

  /// @brief Component-wise multiply `a`, `b`
  /// @param rhs `b`
  /// @returns the result
  float3 operator*(const float3 &rhs) const;

  /// @brief Divide all values of `float3` by a divisor
  /// @param multiplier the divisor
  /// @returns the multiplied `float3`
  float3 operator/(float multiplier) const;

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

  bool operator==(const float3 &rhs) const;

  friend float3 sqrt(const float3 &);
  friend float3 normalize(const float3 &);
  friend float3 cross(const float3 &, const float3 &);
  friend float3 clamp(const float3 &, const float3 &, const float3 &);

  friend float dot(const float3 &, const float3 &);
  friend float length(const float3 &);

 private:
  native_float3 values_;
};

}  // namespace graphmath

// Implementations

namespace graphmath {
inline float3 sqrt(const float3 &f3) {
#if defined(__APPLE__)
  return simd::sqrt(f3.values_);
#else
  throw_not_implemented();
#endif
}

inline float3 normalize(const float3 &f3) {
#if defined(__APPLE__)
  return float3{simd::normalize(f3.values_)};
#else
  throw_not_implemented();
#endif
}

inline float3 cross(const float3 &a, const float3 &b) {
#if defined(__APPLE__)
  return float3{simd::cross(a.values_, b.values_)};
#else
  throw_not_implemented();
#endif
}

inline float3 clamp(const float3 &value, const float3 &low,
                    const float3 &high) {
#if defined(__APPLE__)
  return simd::clamp(value.values_, low.values_, high.values_);
#else
  throw_not_implemented();
#endif
}

inline float dot(const float3 &a, const float3 &b) {
#if defined(__APPLE__)
  return simd::dot(a.values_, b.values_);
#else
  throw_not_implemented();
#endif
}

inline float length(const float3 &f3) {
#if defined(__APPLE__)
  return simd::length(f3.values_);
#else
  throw_not_implemented();
#endif
}

inline float3::float3()
#if defined(__APPLE__)
    : values_{simd::make_float3(0, 0, 0)} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float3::float3(float x, float y, float z)
#if defined(__APPLE__)
    : values_{simd::make_float3(x, y, z)} {
}
#else
{
  throw_not_implemented();
}
#endif

inline float3::float3(const float3 &other)
#if defined(__APPLE__)
    : values_(other.values_) {
}
#else
{
  throw_not_implemented();
}
#endif

inline float3::float3(const native_float3 &values)
#if defined(__APPLE__) || defined(_WIN32)
    : values_(values) {
}
#else
{
  throw_not_implemented();
}
#endif

inline float float3::x() const {
#if defined(__APPLE__)
  return values_.x;
#else
  throw_not_implemented();
#endif
}

inline float float3::y() const {
#if defined(__APPLE__)
  return values_.y;
#else
  throw_not_implemented();
#endif
}

inline float float3::z() const {
#if defined(__APPLE__)
  return values_.z;
#else
  throw_not_implemented();
#endif
}

inline float3 float3::operator*(float multiplier) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ * multiplier;
#else
  throw_not_implemented();
#endif
}

inline float3 float3::operator*(const float3 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ * rhs.values_;
#else
  throw_not_implemented();
#endif
}

inline float3 float3::operator/(float multiplier) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ / multiplier;
#else
  throw_not_implemented();
#endif
}

inline float3 float3::operator+(const float3 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ + rhs.values_;
#else
  throw_not_implemented();
#endif
}

inline float3 float3::operator-(float rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ - rhs;
#else
  throw_not_implemented();
#endif
}

inline float3 float3::operator-(const float3 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ - rhs.values_;
#else
  throw_not_implemented();
#endif
}

inline bool float3::operator==(const float3 &rhs) const {
  return x() == rhs.x() && y() == rhs.y() && z() == rhs.z();
}
}  // namespace graphmath
