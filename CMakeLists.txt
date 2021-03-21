option(GRAPHMATH_TEST "Development" OFF)

project("GraphMath")

include(cmake/AddGraphMathTest.cmake)

if(GRAPHMATH_TEST)
  find_package(GTest REQUIRED)

  enable_testing()
endif()

add_library(graphmath INTERFACE)

target_include_directories(
  graphmath
  INTERFACE
    "${CMAKE_SOURCE_DIR}/include")

target_compile_features(
  graphmath
  INTERFACE
    cxx_std_17)

target_sources(
  graphmath
  PRIVATE
    "${CMAKE_SOURCE_DIR}/include/graphmath/graphmath.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/not_implemented.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/float3.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/float4.h")


if(GRAPHMATH_TEST)
  add_subdirectory(unittests)
endif()
