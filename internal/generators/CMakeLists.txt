function(add_problem_test TARGET CONFIG)
  find_package(Python)
  if(NOT Python_FOUND)
    message(FATAL_ERROR "Could not find Python")
  endif()

  # Generate a C++ source file from a YAML config files.
  set(SCRIPT ${CMAKE_SOURCE_DIR}/internal/generators/generate_test.py)
  set(INPUT ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG})
  set(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp)
  get_filename_component(OUTPUT_DIR ${OUTPUT} DIRECTORY)
  add_custom_command(
    OUTPUT ${OUTPUT}
    COMMAND mkdir -p ${OUTPUT_DIR}
    COMMAND ${Python_EXECUTABLE} ${SCRIPT} ${INPUT} ${OUTPUT}
    DEPENDS ${SCRIPT} ${INPUT}
    VERBATIM)
  add_custom_target(${TARGET}-src DEPENDS ${OUTPUT})

  # Add a test target that includes the generated C++ source file.
  add_executable(${TARGET} ${OUTPUT})
  target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain utils yaml-cpp)

  add_dependencies(${TARGET} ${TARGET}-src)
  catch_discover_tests(${TARGET})
endfunction()
