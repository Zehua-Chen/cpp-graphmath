add_graphmath_test(
  test_all
  SOURCES
    float3_test.cc
    float4_test.cc)

target_link_libraries(
  test_all
  PRIVATE
    graphmath)