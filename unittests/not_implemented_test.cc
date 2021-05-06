#include "graphmath/not_implemented.h"

#include "gtest/gtest.h"

using namespace graphmath;

#ifdef GRAPHMATH_HAS_EXCEPTIONS
TEST(NotImplemented, Throws) {
  EXPECT_THROW(throw_not_implemented(), not_implemented);
}
#endif
