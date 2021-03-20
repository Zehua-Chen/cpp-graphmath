project("GraphMath")

add_library(graphmath INTERFACE)

target_sources(
  graphmath
  PRIVATE
    "${CMAKE_SOURCE_DIR}/include/graphmath/graphmath.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/float3.h"
    "${CMAKE_SOURCE_DIR}/include/graphmath/float4.h")

if (NOT GRAPHMATH_DEV)
  if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(GRAPHMATH_DEV True)
  else()
    set(GRAPHMATH_DEV False)
  endif()
endif()


if(GRAPHMATH_DEV)
  add_subdirectory(unittests)
endif()