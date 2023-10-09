macro(add_test_cases target)
  get_dir_name(id)
  set(${target} test-cases-${id})

  find_package(Python)
  if(NOT Python_FOUND)
    message(FATAL_ERROR "Could not find Python")
  endif()

  # Generate C++ headers from YAML test cases files.
  foreach(arg ${ARGN})
    get_filename_component(ARG_WE ${arg} NAME_WE)
    add_custom_command(
      OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/include/${ARG_WE}.hpp
      COMMAND mkdir -p ${CMAKE_CURRENT_BINARY_DIR}/include
      COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/internal/generators/generate_test_cases.py
              ${CMAKE_CURRENT_SOURCE_DIR}/${arg} ${CMAKE_CURRENT_BINARY_DIR}/include/${ARG_WE}.hpp
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${arg}
      VERBATIM)
    list(APPEND outputs ${CMAKE_CURRENT_BINARY_DIR}/include/${ARG_WE}.hpp)
  endforeach()
  add_custom_target(test-cases-${id}-hpp DEPENDS ${outputs})

  cpmgetpackage(yaml-cpp)

  # Add a test case target that includes the generated C++ headers.
  add_library(test-cases-${id} INTERFACE)
  target_include_directories(test-cases-${id} INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/include)
  target_link_libraries(test-cases-${id} INTERFACE yaml-cpp)

  add_dependencies(test-cases-${id} test-cases-${id}-hpp)
endmacro()

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
