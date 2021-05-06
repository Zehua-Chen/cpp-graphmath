#include "graphmath/float4.h"

#include "gtest/gtest.h"
#include "helpers.h"

using namespace graphmath;

TEST(Float4, Constructor) {
  float4 zeros;
  float4 ones{1, 2, 3, 4};

  EXPECT_FLOAT_EQ(zeros.x(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.y(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.z(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.w(), 0.0f);

  EXPECT_FLOAT_EQ(ones.x(), 1.0f);
  EXPECT_FLOAT_EQ(ones.y(), 2.0f);
  EXPECT_FLOAT_EQ(ones.z(), 3.0f);
  EXPECT_FLOAT_EQ(ones.w(), 4.0f);
}

TEST(Float4, Magnitude) {
  float4 f4{1, 2, 3, 4};
  EXPECT_FLOAT_EQ(length(f4), 5.4772258f);
}

TEST(Float4, Normalized) {
  float4 f4{1, 1, 1, 1};
  float4 normalized = normalize(f4);
  float4 expected{0.4999999702f, 0.4999999702f, 0.4999999702f, 0.4999999702f};

  EXPECT_FLOAT4_EQ(normalized, expected);
}

TEST(Float4, Add) {
  float4 a{1, 1, 1, 1};
  float4 b{2, 2, 2, 2};

  float4 result = a + b;
  float4 expected{3, 3, 3, 3};

  EXPECT_FLOAT4_EQ(result, expected);
}

TEST(Float4, Minus) {
  float4 a{1, 1, 1, 1};
  float4 b{2, 2, 2, 2};

  float4 result = a - b;
  float4 expected{-1, -1, -1, -1};

  EXPECT_FLOAT4_EQ(result, expected);
}

TEST(Float4, MultiplyByNumber) {
  float4 a{1, 1, 1, 1};
  float4 result = a * 2.0f;
  float4 expected{2, 2, 2, 2};

  EXPECT_FLOAT4_EQ(result, expected);
}

TEST(Float4, MultiplyByFloat4) {
  float4 a{1, 1, 1, 1};
  float4 b{2, 2, 2, 2};

  float4 result = a * b;
  float4 expected{2, 2, 2, 2};

  EXPECT_FLOAT4_EQ(result, expected);
}
