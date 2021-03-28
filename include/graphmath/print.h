#pragma once

#include <ostream>

#include "graphmath/float3.h"
#include "graphmath/float4.h"
#include "graphmath/float4x4.h"

namespace graphmath {
namespace print {
template <typename CharT>
constexpr CharT space{' '};

template <typename CharT>
constexpr CharT comma{','};

template <typename CharT>
constexpr CharT left_square{'['};

template <typename CharT>
constexpr CharT right_square{']'};

}  // namespace print

/// @brief print a `float3` to an out stream
template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float3 &f4);

/// @brief print a `float4` to an out stream
template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float4 &f4);

/// @brief print a `float4x4` to an out stream
template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float4x4 &f4x4);

}  // namespace graphmath

namespace graphmath {
template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float3 &f4) {
  using namespace print;

  out << left_square<CharT>;
  out << f4.x() << comma<CharT> << space<CharT>;
  out << f4.y() << comma<CharT> << space<CharT>;
  out << f4.z();
  out << right_square<CharT>;
  return out;
}

template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float4 &f4) {
  using namespace print;

  out << left_square<CharT>;
  out << f4.x() << comma<CharT> << space<CharT>;
  out << f4.y() << comma<CharT> << space<CharT>;
  out << f4.z() << comma<CharT> << space<CharT>;
  out << f4.w();
  out << right_square<CharT>;

  return out;
}

template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float4x4 &f4x4) {
  using namespace print;

  const auto print_line = [&](size_t y) {
    out << left_square<CharT>;
    out << f4x4.get(y, 0) << comma<CharT> << space<CharT>;
    out << f4x4.get(y, 1) << comma<CharT> << space<CharT>;
    out << f4x4.get(y, 2) << comma<CharT> << space<CharT>;
    out << f4x4.get(y, 3);
    out << right_square<CharT>;
  };

  out << left_square<CharT>;

  print_line(0);
  out << comma<CharT> << std::endl;

  out << space<CharT>;
  print_line(1);
  out << comma<CharT> << std::endl;

  out << space<CharT>;
  print_line(2);
  out << comma<CharT> << std::endl;

  out << space<CharT>;
  print_line(3);
  out << right_square<CharT>;

  return out;
}
}  // namespace graphmath
