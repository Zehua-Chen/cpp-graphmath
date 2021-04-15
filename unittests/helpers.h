#pragma once

#include "graphmath/graphmath.h"
#include "gtest/gtest.h"

#define EXPECT_FLOAT4_EQ(a, b)     \
  {                                \
    EXPECT_FLOAT_EQ(a.x(), b.x()); \
    EXPECT_FLOAT_EQ(a.y(), b.y()); \
    EXPECT_FLOAT_EQ(a.z(), b.z()); \
    EXPECT_FLOAT_EQ(a.w(), b.w()); \
  }
