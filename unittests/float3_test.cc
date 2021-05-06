#include "graphmath/float3.h"

#include "gtest/gtest.h"
#include "helpers.h"

using namespace graphmath;

TEST(Float3, Constructor) {
  float3 zeros;
  float3 ones{1, 1, 1};

  EXPECT_FLOAT_EQ(zeros.x(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.y(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.z(), 0.0f);

  EXPECT_FLOAT_EQ(ones.x(), 1.0f);
  EXPECT_FLOAT_EQ(ones.y(), 1.0f);
  EXPECT_FLOAT_EQ(ones.z(), 1.0f);
}

TEST(Float3, Magnitude) {
  float3 f3{1, 1, 1};
  EXPECT_FLOAT_EQ(length(f3), 1.7320508f);
}

TEST(Float3, Normalized) {
  float3 f3{1, 1, 1};
  float3 normalized = normalize(f3);
  float3 expected{0.57735026f, 0.57735026f, 0.57735026f};

  EXPECT_FLOAT3_EQ(normalized, expected);
}

TEST(Float3, Subtract) {
  float3 a{1, 1, 1};
  float3 b{1, 1, 1};

  float3 c = a - b;
  float3 expected{0, 0, 0};

  EXPECT_FLOAT3_EQ(c, expected);
}

TEST(Float3, MultiplyByFloat) {
  float3 a{1, 1, 1};
  float3 b = a * 2.0f;
  float3 expected{2, 2, 2};

  EXPECT_FLOAT3_EQ(b, expected);
}

TEST(Float3, MultiplyByFloat3) {
  float3 a{1, 1, 1};
  float3 b{2, 2, 2};

  float3 c = a * b;
  float3 expected{2, 2, 2};

  EXPECT_FLOAT3_EQ(c, expected);
}

TEST(Float3, DivideByFloat) {
  float3 a{4, 4, 4};
  float3 b = a / 2.0f;
  float3 expected{2, 2, 2};

  EXPECT_FLOAT3_EQ(b, expected);
}

TEST(Float3, AddWithFloat3) {
  float3 a{2, 2, 2};
  float3 b{5, 5, 5};

  float3 c = a + b;
  float3 expected{7, 7, 7};

  EXPECT_FLOAT3_EQ(c, expected);
}

TEST(Float3, SubtractByFloat) {
  float3 a{2, 2, 2};
  float3 c = a - 2.0f;
  float3 expected{0, 0, 0};

  EXPECT_FLOAT3_EQ(c, expected);
}

TEST(Float3, SubtractByFloat3) {
  float3 a{2, 2, 2};
  float3 b{5, 5, 5};

  float3 c = a - b;
  float3 expected{-3, -3, -3};

  EXPECT_FLOAT3_EQ(c, expected);
}
