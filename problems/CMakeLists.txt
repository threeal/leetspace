macro(get_dir_name var)
  get_filename_component(${var} ${CMAKE_CURRENT_SOURCE_DIR} NAME)
endmacro()

macro(add_c_solution target)
  get_dir_name(id)
  set(${target} c-solution-${id})

  add_library(c-solution-${id} ${ARGN})
  set_property(TARGET c-solution-${id} PROPERTY CXX_STANDARD 20)
  target_compile_options(c-solution-${id} PRIVATE -Werror -Wall -Wextra -Wpedantic)
endmacro()

macro(add_cpp_solution target)
  get_dir_name(id)
  set(${target} cpp-solution-${id})

  add_library(cpp-solution-${id} ${ARGN})
  set_property(TARGET cpp-solution-${id} PROPERTY CXX_STANDARD 20)
  target_compile_options(cpp-solution-${id} PRIVATE -Werror -Wall -Wextra -Wpedantic)
endmacro()

macro(add_problem_test target)
  get_dir_name(id)
  set(${target} test-${id})

  add_executable(test-${id} ${ARGN})
  set_property(TARGET test-${id} PROPERTY CXX_STANDARD 20)
  target_compile_options(test-${id} PRIVATE -Werror -Wall -Wextra -Wpedantic)
  target_link_libraries(test-${id} PRIVATE Catch2::Catch2WithMain)
  catch_discover_tests(test-${id})
endmacro()

file(GLOB problems LIST_DIRECTORIES true "*")
foreach(problem ${problems})
  if(IS_DIRECTORY ${problem})
    add_subdirectory(${problem})
  endif()
endforeach()
