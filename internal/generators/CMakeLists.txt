function(add_problem_test TARGET CONFIG)
  # Generate a C++ test source file from a YAML config files.
  generate_test_src(CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG} OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/src)

  # Add a test target that includes the generated C++ source file.
  add_executable(${TARGET} ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp ${CMAKE_CURRENT_BINARY_DIR}/src/solution_cpp.cpp)
  target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain)

  set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 20)
  target_compile_options(${TARGET} PRIVATE -Werror -Wall -Wextra -Wpedantic)

  catch_discover_tests(${TARGET})
endfunction()
