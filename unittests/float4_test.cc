#include "graphmath/float4.h"

#include "gtest/gtest.h"

using namespace graphmath;

TEST(Float4, Constructor) {
  float4 zeros;
  float4 ones{1, 2, 3, 4};

  EXPECT_FLOAT_EQ(zeros.x(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.y(), 0.0f);
  EXPECT_FLOAT_EQ(zeros.z(), 0.0f);

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

  EXPECT_FLOAT_EQ(normalized.x(), 0.4999999702f);
  EXPECT_FLOAT_EQ(normalized.y(), 0.4999999702f);
  EXPECT_FLOAT_EQ(normalized.z(), 0.4999999702f);
  EXPECT_FLOAT_EQ(normalized.w(), 0.4999999702f);
}

TEST(Float4, Add) {
  float4 a{1, 1, 1, 1};
  float4 b{2, 2, 2, 2};

  float4 result = a + b;

  EXPECT_FLOAT_EQ(result.x(), 3.0f);
  EXPECT_FLOAT_EQ(result.y(), 3.0f);
  EXPECT_FLOAT_EQ(result.z(), 3.0f);
  EXPECT_FLOAT_EQ(result.w(), 3.0f);
}

TEST(Float4, Minus) {
  float4 a{1, 1, 1, 1};
  float4 b{2, 2, 2, 2};

  float4 result = a - b;

  EXPECT_FLOAT_EQ(result.x(), -1.0f);
  EXPECT_FLOAT_EQ(result.y(), -1.0f);
  EXPECT_FLOAT_EQ(result.z(), -1.0f);
  EXPECT_FLOAT_EQ(result.w(), -1.0f);
}

TEST(Float4, MultiplyByNumber) {
  float4 a{1, 1, 1, 1};
  float4 result = a * 2.0f;

  EXPECT_FLOAT_EQ(result.x(), 2.0f);
  EXPECT_FLOAT_EQ(result.y(), 2.0f);
  EXPECT_FLOAT_EQ(result.z(), 2.0f);
  EXPECT_FLOAT_EQ(result.w(), 2.0f);
}

TEST(Float4, MultiplyByFloat4) {
  float4 a{1, 1, 1, 1};
  float4 b{2, 2, 2, 2};

  float4 result = a * b;

  EXPECT_FLOAT_EQ(result.x(), 2.0f);
  EXPECT_FLOAT_EQ(result.y(), 2.0f);
  EXPECT_FLOAT_EQ(result.z(), 2.0f);
  EXPECT_FLOAT_EQ(result.w(), 2.0f);
}
