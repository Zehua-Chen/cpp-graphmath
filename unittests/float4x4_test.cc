#include "graphmath/float4x4.h"

#include "gtest/gtest.h"

using namespace graphmath;

TEST(Float4x4, Construction) {
  float4 rows[4];

  float counter = 0.0f;

  for (size_t row = 0; row < 4; row++) {
    rows[row] = float4{counter++, counter++, counter++, counter++};
  }

  float4x4 matrix{rows[0], rows[1], rows[2], rows[3]};

  for (size_t row = 0; row < 4; row++) {
    ASSERT_FLOAT_EQ(matrix.get(row, 0), rows[row].x());
    ASSERT_FLOAT_EQ(matrix.get(row, 1), rows[row].y());
    ASSERT_FLOAT_EQ(matrix.get(row, 2), rows[row].z());
    ASSERT_FLOAT_EQ(matrix.get(row, 3), rows[row].w());
  }
}

TEST(Float4x4, Identity) {
  float4x4 matrix{1.0f};
  float4 vector{1, 2, 3, 4};

  float4 result = matrix * vector;

  ASSERT_FLOAT_EQ(result.x(), 1);
  ASSERT_FLOAT_EQ(result.y(), 2);
  ASSERT_FLOAT_EQ(result.z(), 3);
  ASSERT_FLOAT_EQ(result.w(), 4);
}
