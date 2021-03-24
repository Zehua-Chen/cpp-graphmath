#include "graphmath/print.h"

#include <sstream>

#include "gtest/gtest.h"

using std::string;
using std::stringstream;
using namespace graphmath;
using namespace graphmath::print;

template <typename T>
string to_string(const T &t) {
  stringstream ss;
  ss << t;

  return ss.str();
}

TEST(Print, Float3) {
  float3 f3{1, 2, 3};
  string result = to_string(f3);

  ASSERT_EQ(result, "[1, 2, 3]");
}

TEST(Print, Float4) {
  float4 f4{1, 2, 3, 4};
  string result = to_string(f4);

  ASSERT_EQ(result, "[1, 2, 3, 4]");
}

TEST(Print, Float4x4) {
  float4x4 matrix{float4{0, 1, 2, 3}, float4{4, 5, 6, 7}, float4{8, 9, 10, 11},
                  float4{12, 13, 14, 15}};

  string result = to_string(matrix);
  string expected =
      "[[0, 1, 2, 3],\n"
      " [4, 5, 6, 7],\n"
      " [8, 9, 10, 11],\n"
      " [12, 13, 14, 15]]";

  ASSERT_EQ(result, expected);
}
