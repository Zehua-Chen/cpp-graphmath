add_cs419_test(
  test_math
  SOURCES
    float3.cc
    float4.cc)

target_link_libraries(
  test_math
  PRIVATE
    cs419-math)
