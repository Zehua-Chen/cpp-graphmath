#include "graphmath/float4x4.h"

#include "gtest/gtest.h"

using namespace graphmath;

TEST(Float4x4, Construction) {
  float4x4 matrix{float4{0, 1, 2, 3}, float4{4, 5, 6, 7}, float4{8, 9, 10, 11},
                  float4{12, 13, 14, 15}};

  float counter = 0;

  for (size_t y = 0; y < 4; y++) {
    for (size_t x = 0; x < 4; x++) {
      ASSERT_FLOAT_EQ(matrix.get(y, x), counter++);
    }
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

TEST(Float4x4, MultiplicationByFloat4) {
  float4x4 matrix{float4{0, 1, 2, 3}, float4{4, 5, 6, 7}, float4{8, 9, 10, 11},
                  float4{12, 13, 14, 15}};
  float4 f4{1, 2, 3, 4};
  float4 result = matrix * f4;

  ASSERT_FLOAT_EQ(result.x(), 20);
  ASSERT_FLOAT_EQ(result.y(), 60);
  ASSERT_FLOAT_EQ(result.z(), 100);
  ASSERT_FLOAT_EQ(result.w(), 140);
}

TEST(Float4x4, MultiplicationByFloat4x4) {
  float4x4 matrix{float4{0, 1, 2, 3}, float4{4, 5, 6, 7}, float4{8, 9, 10, 11},
                  float4{12, 13, 14, 15}};

  float4x4 result = matrix * matrix;

  float4x4 expected{float4{56, 62, 68, 74}, float4{152, 174, 196, 218},
                    float4{248, 286, 324, 362}, float4{344, 398, 452, 506}};

  for (size_t y = 0; y < 4; y++) {
    for (size_t x = 0; x < 4; x++) {
      ASSERT_FLOAT_EQ(result.get(y, x), expected.get(y, x));
    }
  }
}

TEST(Float4x4, Transpose) {
  float4 rows[4];
  float counter = 0.0f;

  for (size_t row = 0; row < 4; row++) {
    rows[row] = float4{counter++, counter++, counter++, counter++};
  }

  float4x4 matrix{rows[0], rows[1], rows[2], rows[3]};
  float4x4 result = transpose(matrix);

  for (size_t row = 0; row < 4; row++) {
    for (size_t col = 0; col < 4; col++) {
      ASSERT_FLOAT_EQ(result.get(row, col), matrix.get(col, row));
    }
  }
}
