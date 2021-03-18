//
//  float4.h
//  CS 419
//
//  Created by Zehua Chen on 2/21/21.
//
#pragma once
#include <cmath>

#include "cs419/platform/platform.h"

#if defined(__APPLE__)
#include <simd/simd.h>
#elif defined(_WIN32)
#include <DirectXMath.h>
#endif

// Declarations

namespace cs419::math {
struct float4;

/// @brief Compute the dot product of two `float4`
/// @param a one `float4`
/// @param b one `float4`
/// @returns the result `float4`
float4 dot(const float4 &a, const float4 &b);

/// @brief four `float32` numbers `(x, y, z, w)`
struct CS419_API float4 final {
 public:
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

#if defined(__APPLE__)
  /// @brief create a `float4` with `simd::float4`
  ///
  /// Only available on Apple platforms
  /// @param values a `simd::float4` instance
  float4(simd::float4 values);
#elif defined(_WIN32)
  /// @brief create a `float4` with `DirectX::XMVECTOR`
  ///
  /// Only available on Microsoft platforms
  /// @param values a `DirectX::XMVECTOR` instance
  float4(DirectX::XMVECTOR values);
#endif

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

  /// @brief Get the magnitude of `float4`
  float magnitude() const;

  /// @brief Get a normalized version of `float4`
  /// @returns the normalized `float4`
  float4 normalized() const;

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

  friend float4 dot(const float4 &a, const float4 &b);

 private:
#if defined(__APPLE__)
  simd::float4 values_;
#elif defined(_WIN32)
  DirectX::XMVECTOR values_;
#endif
};
}  // namespace cs419::math

// Implementations

namespace cs419::math {
inline float4 dot(const float4 &a, const float4 &b) {
#if defined(__APPLE__)
  return float4{simd::dot(a.values_, b.values_)};
#elif defined(_WIN32)
  return float4{DirectX::XMVector4Dot(a.values_, b.values_)};
#endif
}

#if defined(__APPLE__)
inline float4::float4() : values_{simd::make_float4(0, 0, 0, 0)} {}
#elif defined(_WIN32)
inline float4::float4() : values_{DirectX::XMVectorZero()} {}
#endif

inline float4::float4(float x, float y, float z, float w)
#if defined(__APPLE__)
    : values_{simd::make_float4(x, y, z, w)} {
}
#elif defined(_WIN32)
    : values_{DirectX::XMVectorSet(x, y, z, w)} {
}
#endif

inline float4::float4(const float4 &other) : values_(other.values_) {}

#if defined(__APPLE__)
inline float4::float4(simd::float4 values) : values_(values) {}
#elif defined(_WIN32)
inline float4::float4(DirectX::XMVECTOR values) : values_(values) {}
#endif

inline float float4::x() const {
#if defined(__APPLE__)
  return values_.x;
#elif defined(_WIN32)
  return DirectX::XMVectorGetX(values_);
#endif
}

inline float float4::y() const {
#if defined(__APPLE__)
  return values_.y;
#elif defined(_WIN32)
  return DirectX::XMVectorGetY(values_);
#endif
}

inline float float4::z() const {
#if defined(__APPLE__)
  return values_.z;
#elif defined(_WIN32)
  return DirectX::XMVectorGetZ(values_);
#endif
}

inline float float4::w() const {
#if defined(__APPLE__)
  return values_.w;
#elif defined(_WIN32)
  return DirectX::XMVectorGetW(values_);
#endif
}

inline float float4::magnitude() const {
#if defined(__APPLE__)
  simd::float4 squared = values_ * values_;
  return std::sqrt(squared.x + squared.y + squared.z + squared.w);
#elif defined(_WIN32)
  using namespace DirectX;

  XMVECTOR length = XMVector4Length(values_);
  return XMVectorGetX(length);
#endif
}

inline float4 float4::normalized() const {
#if defined(__APPLE__)
  return float4{simd::normalize(values_)};
#elif
  return float4{DirectX::XMVector4Normalize(values_)};
#endif
}

inline float4 float4::operator+(const float4 &other) const {
#if defined(__APPLE__) || defined(_WIN32)
  return float4{values_ + other.values_};
#endif
}

inline float4 float4::operator-(const float4 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return float4{values_ - rhs.values_};
#endif
}

inline float4 float4::operator*(float multiplier) const {
#if defined(__APPLE__) || defined(_WIN32)
  return values_ * multiplier;
#endif
}

inline float4 float4::operator*(const float4 &rhs) const {
#if defined(__APPLE__) || defined(_WIN32)
  return float4{values_ * rhs.values_};
#endif
}
}  // namespace cs419::math
