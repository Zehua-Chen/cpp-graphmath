function(add_graphmath_test target)
  set(PREFIX "TEST")
  cmake_parse_arguments(PARSE_ARGV 1 "${PREFIX}" "" "" "SOURCES")

  add_executable("${target}")

  target_compile_features(
    "${target}"
    PRIVATE
      cxx_std_17)

  target_link_libraries(
    "${target}"
    PRIVATE
      GTest::gtest
      GTest::gtest_main)

  target_sources(
    "${target}"
    PRIVATE
      "${TEST_SOURCES}")

  if(NOT MSVC)
    target_compile_options(
      "${target}"
      PRIVATE
        "-Wall"
        "-Werror")

  endif()

  gtest_discover_tests("${target}")
endfunction()