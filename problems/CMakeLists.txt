macro(get_dir_name var)
  get_filename_component(${var} ${CMAKE_CURRENT_SOURCE_DIR} NAME)
endmacro()

macro(add_test_cases target)
  get_dir_name(id)
  set(${target} test-cases-${id})

  foreach(arg ${ARGN})
    set(output ${CMAKE_CURRENT_BINARY_DIR}/${arg})
    add_custom_command(
      OUTPUT ${output}
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${arg} ${output}
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${arg}
      VERBATIM)
    list(APPEND outputs ${output})
  endforeach()
  add_custom_target(test-cases-${id} DEPENDS ${outputs})
endmacro()

macro(add_c_solution target)
  get_dir_name(id)
  set(${target} c-solution-${id})

  add_library(c-solution-${id} ${ARGN})
endmacro()

macro(add_cpp_solution target)
  get_dir_name(id)
  set(${target} cpp-solution-${id})

  add_library(cpp-solution-${id} ${ARGN})
  set_property(TARGET cpp-solution-${id} PROPERTY CXX_STANDARD 20)
endmacro()

macro(add_problem_test target)
  get_dir_name(id)
  set(${target} test-${id})

  add_executable(test-${id} ${ARGN})
  set_property(TARGET test-${id} PROPERTY CXX_STANDARD 20)
  target_link_libraries(test-${id} PRIVATE Catch2::Catch2WithMain)
  catch_discover_tests(test-${id})
endmacro()

file(GLOB problems LIST_DIRECTORIES true "*")
foreach(problem ${problems})
  if(IS_DIRECTORY ${problem})
    add_subdirectory(${problem})
  endif()
endforeach()
