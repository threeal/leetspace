function(generate_test_src)
  cmake_parse_arguments(ARG "" "CONFIG;OUTDIR" "" ${ARGN})

  find_package(Python REQUIRED)
  set(SCRIPT ${CMAKE_SOURCE_DIR}/internal/generators/generate_test.py)

  add_custom_command(
    OUTPUT ${ARG_OUTDIR}/solution_cpp.cpp ${ARG_OUTDIR}/test.cpp
    COMMAND ${Python_EXECUTABLE} ${SCRIPT} ${ARG_CONFIG} ${ARG_OUTDIR}
    DEPENDS ${SCRIPT} ${ARG_CONFIG}
    VERBATIM)
endfunction()

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
