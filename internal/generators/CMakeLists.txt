function(add_problem_test TARGET CONFIG)
  find_package(Python)
  if(NOT Python_FOUND)
    message(FATAL_ERROR "Could not find Python")
  endif()

  # Generate a C++ source file from a YAML config files.
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp
    COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/src
    COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/internal/generators/generate_test.py
            ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG} ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG}
    VERBATIM)
  add_custom_target(${TARGET}-src DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp)

  # Add a test target that includes the generated C++ source file.
  add_executable(${TARGET} ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp)
  target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain utils yaml-cpp)

  add_dependencies(${TARGET} ${TARGET}-src)
  catch_discover_tests(${TARGET})
endfunction()
