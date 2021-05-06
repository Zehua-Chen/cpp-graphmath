#pragma once

#include <exception>
#include <iostream>

// Declarations

// Define GRAPHMATH_HAS_EXCEPTIONS if the one of the following conditions are
// met
// - X compiler is used and exception is enabled
// - Compiler is not recognized
#ifdef __clang__
#if __has_feature(cxx_exceptions)
#define GRAPHMATH_HAS_EXCEPTIONS
#endif
#else
#define GRAPHMATH_HAS_EXCEPTIONS
#endif

namespace graphmath {
constexpr const char *not_implemented_message = "graphmath: not implemented";

#ifdef GRAPHMATH_HAS_EXCEPTIONS
/// @brief throw when a functionality is not implemented
class not_implemented : public std::exception {
  const char *what() const noexcept override;
};
#endif

/// @brief throw a not implemented exception
void throw_not_implemented();
}  // namespace graphmath

// Implementations

namespace graphmath {
#ifdef GRAPHMATH_HAS_EXCEPTIONS
inline const char *not_implemented::what() const noexcept {
  return "graphmath: not implemented";
}
#endif

inline void throw_not_implemented() {
#ifdef GRAPHMATH_HAS_EXCEPTIONS
  throw not_implemented{};
#else
  std::cerr << not_implemented_message << std::endl;
  std::exit(0);
#endif
}
}  // namespace graphmath
