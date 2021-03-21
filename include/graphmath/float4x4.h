#pragma once

#include "graphmath/float4.h"
#include "graphmath/not_implemented.h"

#if defined(__APPLE__)
#include <simd/simd.h>
#endif

// Declarations

namespace graphmath {
float4x4 transpose(const float4x4 &f4x4);

struct float4x4 final {
 public:
#if defined(__APPLE__)
  using native_float4x4 = simd::float4x4;
#endif

  float4x4(const native_float4x4 &native);
  float4x4(const float4 &row0, const float4 &row1, const float4 &row2,
           const float4 &row3);

  float get(size_t row, size_t column) const;
  void set(size_t row, size_t column, float value);

  float operator()(size_t row, size_t column) const;
  float4 operator*(const float4 &other) const;

  friend float4x4 transpose(const float4x4 &);

  native_float4x4 native;
};
}  // namespace graphmath

// Imlementations

namespace graphmath {
inline float4x4 transpose(const float4x4 &f4x4) {
#if defined(__APPLE__)
  return float4x4{simd::transpose(f4x4.native)};
#endif
}

inline float4x4::float4x4(const native_float4x4 &native) : native(native) {}

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

#else
  throw_not_implemented();
#endif
}

inline float float4x4::get(size_t row, size_t column) const {
#if defined(__APPLE__)
  return native.columns[column][row];
#else
  throw_not_implemented();
#endif
}

inline void float4x4::set(size_t row, size_t column, float value) {
#if defined(__APPLE__)
  native.columns[column][row] = value;
#else
  throw_not_implemented();
#endif
}

inline float float4x4::operator()(size_t row, size_t column) const {
  return get(row, column);
}

inline float4 float4x4::operator*(const float4 &other) const {
  return float4{native * other.native};
}
}  // namespace graphmath
