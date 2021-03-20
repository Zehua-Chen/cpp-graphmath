add_graphmath_test(
  graphmath_test
  SOURCES
    float3_test.cc
    float4_test.cc)

target_link_libraries(
  graphmath_test
  PRIVATE
    graphmath)