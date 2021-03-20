#include "graphmath/float3.h"

#include "gtest/gtest.h"

using namespace graphmath;

TEST(Float3, Constructor) {
  float3 zeros;
  float3 ones{1, 1, 1};

  ASSERT_FLOAT_EQ(zeros.x(), 0.0f);
  ASSERT_FLOAT_EQ(zeros.y(), 0.0f);
  ASSERT_FLOAT_EQ(zeros.z(), 0.0f);

  ASSERT_FLOAT_EQ(ones.x(), 1.0f);
  ASSERT_FLOAT_EQ(ones.y(), 1.0f);
  ASSERT_FLOAT_EQ(ones.z(), 1.0f);
}

TEST(Float3, Magnitude) {
  float3 f3{1, 1, 1};
  ASSERT_FLOAT_EQ(length(f3), 1.7320508f);
}

TEST(Float3, Normalized) {
  float3 f3{1, 1, 1};
  float3 normalized = normalize(f3);

  ASSERT_FLOAT_EQ(normalized.x(), 0.57735026f);
  ASSERT_FLOAT_EQ(normalized.y(), 0.57735026f);
  ASSERT_FLOAT_EQ(normalized.z(), 0.57735026f);
}

TEST(Float3, Subtract) {
  float3 a{1, 1, 1};
  float3 b{1, 1, 1};

  float3 c = a - b;

  ASSERT_FLOAT_EQ(c.x(), 0.0f);
  ASSERT_FLOAT_EQ(c.y(), 0.0f);
  ASSERT_FLOAT_EQ(c.z(), 0.0f);
}

TEST(Float3, MultiplyByFloat) {
  float3 a{1, 1, 1};
  float3 b = a * 2.0f;

  ASSERT_FLOAT_EQ(b.x(), 2.0f);
  ASSERT_FLOAT_EQ(b.y(), 2.0f);
  ASSERT_FLOAT_EQ(b.z(), 2.0f);
}

TEST(Float3, MultiplyByFloat3) {
  float3 a{1, 1, 1};
  float3 b{2, 2, 2};

  float3 c = a * b;

  ASSERT_FLOAT_EQ(c.x(), 2.0f);
  ASSERT_FLOAT_EQ(c.y(), 2.0f);
  ASSERT_FLOAT_EQ(c.z(), 2.0f);
}

TEST(Float3, DivideByFloat) {
  float3 a{4, 4, 4};
  float3 b = a / 2.0f;

  ASSERT_FLOAT_EQ(b.x(), 2.0f);
  ASSERT_FLOAT_EQ(b.y(), 2.0f);
  ASSERT_FLOAT_EQ(b.z(), 2.0f);
}

TEST(Float3, AddWithFloat3) {
  float3 a{2, 2, 2};
  float3 b{5, 5, 5};

  float3 c = a + b;

  ASSERT_FLOAT_EQ(c.x(), 7.0f);
  ASSERT_FLOAT_EQ(c.y(), 7.0f);
  ASSERT_FLOAT_EQ(c.z(), 7.0f);
}

TEST(Float3, SubtractByFloat) {
  float3 a{2, 2, 2};
  float3 c = a - 2.0f;

  ASSERT_FLOAT_EQ(c.x(), .0f);
  ASSERT_FLOAT_EQ(c.y(), .0f);
  ASSERT_FLOAT_EQ(c.z(), .0f);
}

TEST(Float3, SubtractByFloat3) {
  float3 a{2, 2, 2};
  float3 b{5, 5, 5};

  float3 c = a - b;

  ASSERT_FLOAT_EQ(c.x(), -3.0f);
  ASSERT_FLOAT_EQ(c.y(), -3.0f);
  ASSERT_FLOAT_EQ(c.z(), -3.0f);
}
