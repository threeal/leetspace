macro(get_dir_name var)
  get_filename_component(${var} ${CMAKE_CURRENT_SOURCE_DIR} NAME)
endmacro()

function(target_set_cpp_standard target)
  set_property(TARGET ${target} PROPERTY CXX_STANDARD 20)
  target_compile_options(${target} PRIVATE -Werror -Wall -Wextra -Wpedantic)
endfunction()

macro(add_c_solution target)
  get_dir_name(id)
  set(${target} c-solution-${id})

  add_library(c-solution-${id} ${ARGN})
  target_set_cpp_standard(c-solution-${id})
endmacro()

function(add_problem_test TARGET CONFIG)
  # Generate a C++ test source file from a YAML config files.
  generate_test_src(CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG} OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/src)

  # Add a test target that includes the generated C++ source file.
  add_executable(${TARGET} ${CMAKE_CURRENT_BINARY_DIR}/src/test.cpp ${CMAKE_CURRENT_BINARY_DIR}/src/solution_cpp.cpp)
  target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain)
  target_set_cpp_standard(${TARGET})

  catch_discover_tests(${TARGET})
endfunction()

file(GLOB problems LIST_DIRECTORIES true "*")
foreach(problem ${problems})
  if(IS_DIRECTORY ${problem})
    add_subdirectory(${problem})
  endif()
endforeach()
