#pragma once

#include <exception>

// Declarations

namespace graphmath {
/// @brief throw when a functionality is not implemented
class not_implemented : public std::exception {
  const char *what() const noexcept override;
};

/// @brief throw a not implemented exception
void throw_not_implemented();
}  // namespace graphmath

// Implementations

namespace graphmath {
inline const char *not_implemented::what() const noexcept {
  return "graphmath: not implemented";
}

inline void throw_not_implemented() { throw not_implemented{}; }
}  // namespace graphmath
