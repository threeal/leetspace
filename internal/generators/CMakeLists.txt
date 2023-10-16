function(add_python_generator)
  cmake_parse_arguments(ARG "" "SCRIPT;INPUT;OUTPUT" "" ${ARGN})

  find_package(Python REQUIRED)

  add_custom_command(
    OUTPUT ${ARG_OUTPUT}
    COMMAND ${Python_EXECUTABLE} ${ARG_SCRIPT} ${ARG_INPUT} ${ARG_OUTPUT}
    DEPENDS ${ARG_SCRIPT} ${ARG_INPUT}
    VERBATIM)
endfunction()

function(generate_test_src)
  cmake_parse_arguments(ARG "" "CONFIG;OUTPUT" "" ${ARGN})

  find_package(Python REQUIRED)
  set(SCRIPT ${CMAKE_SOURCE_DIR}/internal/generators/generate_test.py)

  add_custom_command(
    OUTPUT ${ARG_OUTPUT}
    COMMAND ${Python_EXECUTABLE} ${SCRIPT} ${ARG_CONFIG} ${ARG_OUTPUT}
    DEPENDS ${SCRIPT} ${ARG_CONFIG}
    VERBATIM)
endfunction()

function(add_problem_test TARGET CONFIG)
  # Generate a C++ test source file from a YAML config files.
  generate_test_src(CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG} OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp)
  add_python_generator(
    SCRIPT ${CMAKE_SOURCE_DIR}/internal/generators/generate_solution_cpp.py
    INPUT ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG}
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/solution_cpp.cpp)

  # Add a test target that includes the generated C++ source file.
  add_executable(${TARGET} ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp ${CMAKE_CURRENT_BINARY_DIR}/src/solution_cpp.cpp)
  target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain)

  set_property(TARGET ${TARGET} PROPERTY CXX_STANDARD 20)
  target_compile_options(${TARGET} PRIVATE -Werror -Wall -Wextra -Wpedantic)

  catch_discover_tests(${TARGET})
endfunction()
