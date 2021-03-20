option(GRAPHMATH_DEV "Development" OFF)

if(GRAPHMATH_DEV)
  list(APPEND VCPKG_MANIFEST_FEATURES test)
endif()

project("GraphMath")

include(cmake/AddGraphMathTest.cmake)

if(GRAPHMATH_DEV)
  find_package(GTest REQUIRED)

  enable_testing()
endif()

add_library(graphmath INTERFACE)

target_include_directories(
  graphmath
  INTERFACE
    "${CMAKE_SOURCE_DIR}/include")

target_sources(
  graphmath
  PRIVATE
    "${CMAKE_SOURCE_DIR}/include/graphmath/graphmath.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/float3.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/float4.h")


if(GRAPHMATH_DEV)
  add_subdirectory(unittests)
endif()