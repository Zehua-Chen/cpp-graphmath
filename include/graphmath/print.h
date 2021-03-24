#pragma once

#include <ostream>

#include "graphmath/float3.h"
#include "graphmath/float4.h"
#include "graphmath/float4x4.h"

namespace graphmath {
namespace print {
template <typename CharT>
constexpr CharT space_v{' '};

template <typename CharT>
constexpr CharT comma_v{','};

template <typename CharT>
constexpr CharT left_parenthesis_v{'('};

template <typename CharT>
constexpr CharT right_parenthesis_v{')'};

template <typename CharT>
constexpr CharT left_square_v{'['};

template <typename CharT>
constexpr CharT right_square_v{']'};

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
}  // namespace print
}  // namespace graphmath

namespace graphmath::print {
template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float3 &f4) {
  out << left_square_v<CharT>;
  out << f4.x() << comma_v<CharT> << space_v<CharT>;
  out << f4.y() << comma_v<CharT> << space_v<CharT>;
  out << f4.z();
  out << right_square_v<CharT>;
  return out;
}

template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float4 &f4) {
  out << left_square_v<CharT>;
  out << f4.x() << comma_v<CharT> << space_v<CharT>;
  out << f4.y() << comma_v<CharT> << space_v<CharT>;
  out << f4.z() << comma_v<CharT> << space_v<CharT>;
  out << f4.w();
  out << right_square_v<CharT>;
  return out;
}

template <typename CharT>
std::basic_ostream<CharT> &operator<<(std::basic_ostream<CharT> &out,
                                      const float4x4 &f4x4) {
  const auto print_line = [&](size_t y) {
    out << left_square_v<CharT>;
    out << f4x4.get(y, 0) << comma_v<CharT> << space_v<CharT>;
    out << f4x4.get(y, 1) << comma_v<CharT> << space_v<CharT>;
    out << f4x4.get(y, 2) << comma_v<CharT> << space_v<CharT>;
    out << f4x4.get(y, 3);
    out << right_square_v<CharT>;
  };

  out << left_square_v<CharT>;

  print_line(0);
  out << comma_v<CharT> << std::endl;

  out << space_v<CharT>;
  print_line(1);
  out << comma_v<CharT> << std::endl;

  out << space_v<CharT>;
  print_line(2);
  out << comma_v<CharT> << std::endl;

  out << space_v<CharT>;
  print_line(3);
  out << right_square_v<CharT>;

  return out;
}
}  // namespace graphmath::print
