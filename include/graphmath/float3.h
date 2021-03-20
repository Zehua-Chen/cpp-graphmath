//
//  float3.h
//  CS 419
//
//  Created by Zehua Chen on 2/21/21.
//
#pragma once
#include <cmath>

#ifdef __APPLE__
#include <simd/simd.h>
#endif

// Declarations

namespace graphmath {
struct float3;

/// @brief Take `sqrt` of all values of a `float3`
/// @param f3 the `float3`
float3 sqrt(const float3 &f3);

/// @brief Compute the dot product of two `float3`
/// @param a one `float3`
/// @param b one `float3`
/// @returns the resulting number`
float dot(const float3 &a, const float3 &b);

/// @brief Compute the cross product of two `float3`
/// @param a one `float3`
/// @param b one `float3`
/// @returns the result `float3`
float3 cross(const float3 &a, const float3 &b);

/// @brief clamp a float to a low and high bound
/// @param value the value to clamp
/// @param low the low bound (inclusive)
/// @param high the high bound (inclusive)
float3 clamp(const float3 &value, const float3 &low, const float3 &high);

/// @brief three `float32` numbers `(x, y, z)`
struct float3 final {
 public:
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

#ifdef __APPLE__
  /// @brief create a `float3` with `simd::float3`
  ///
  /// Only available on Apple platforms
  /// @param values a `simd::float3` instance
  float3(simd::float3 values);
#endif

  /// @brief Get `x` of `float3`
  /// @returns the `x` value of `float3`
  float x() const;

  /// @brief Get `y` of `float3`
  /// @returns the `y` value of `float3`
  float y() const;

  /// @brief Get `z` of `float3`
  /// @returns the `z` value of `float3`
  float z() const;

  /// @brief Get the magnitude of `float3`
  float magnitude() const;

  /// @brief Get a normalized version of `float3`
  /// @returns the normalized float3
  float3 normalized() const;

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

  friend float3 sqrt(const float3 &f3);
  friend float dot(const float3 &a, const float3 &b);
  friend float3 cross(const float3 &a, const float3 &b);
  friend float3 clamp(const float3 &value, const float3 &low,
                      const float3 &high);

 private:
#ifdef __APPLE__
  simd::float3 values_;
#endif
};

}  // namespace cs419::math

// Implementations

namespace graphmath {
inline float3 sqrt(const float3 &f3) {
#ifdef __APPLE__
  return simd::sqrt(f3.values_);
#endif
}

inline float dot(const float3 &a, const float3 &b) {
#ifdef __APPLE__
  return simd::dot(a.values_, b.values_);
#endif
}

inline float3 cross(const float3 &a, const float3 &b) {
#ifdef __APPLE__
  return float3{simd::cross(a.values_, b.values_)};
#endif
}

inline float3 clamp(const float3 &value, const float3 &low,
                    const float3 &high) {
#if defined(__APPLE__)
  return simd::clamp(value.values_, low.values_, high.values_);
#endif
}

#ifdef __APPLE__
inline float3::float3() : values_{simd::make_float3(0, 0, 0)} {}
#endif

#ifdef __APPLE__
inline float3::float3(float x, float y, float z)
    : values_{simd::make_float3(x, y, z)} {}
#endif

#ifdef __APPLE__
inline float3::float3(const float3 &other) : values_(other.values_) {}
#endif

#ifdef __APPLE__
inline float3::float3(simd::float3 values) : values_(values) {}
#endif

inline float float3::x() const {
#ifdef __APPLE__
  return values_.x;
#endif
}

inline float float3::y() const {
#ifdef __APPLE__
  return values_.y;
#endif
}

inline float float3::z() const {
#ifdef __APPLE__
  return values_.z;
#endif
}

inline float float3::magnitude() const {
#ifdef __APPLE__
  simd::float3 squared = values_ * values_;
  return std::sqrt(squared.x + squared.y + squared.z);
#endif
}

inline float3 float3::normalized() const {
#ifdef __APPLE__
  return float3{simd::normalize(values_)};
#endif
}

inline float3 float3::operator*(float multiplier) const {
#ifdef __APPLE__
  return values_ * multiplier;
#endif
}

inline float3 float3::operator*(const float3 &rhs) const {
#ifdef __APPLE__
  return values_ * rhs.values_;
#endif
}

inline float3 float3::operator/(float multiplier) const {
#ifdef __APPLE__
  return values_ / multiplier;
#endif
}

inline float3 float3::operator+(const float3 &rhs) const {
#ifdef __APPLE__
  return values_ + rhs.values_;
#endif
}

inline float3 float3::operator-(float rhs) const {
#ifdef __APPLE__
  return values_ - rhs;
#endif
}

inline float3 float3::operator-(const float3 &rhs) const {
#ifdef __APPLE__
  return values_ - rhs.values_;
#endif
}

inline bool float3::operator==(const float3 &rhs) const {
  return x() == rhs.x() && y() == rhs.y() && z() == rhs.z();
}
}  // namespace cs419::math
