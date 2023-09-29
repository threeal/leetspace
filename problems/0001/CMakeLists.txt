get_dir_name(id)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/test_cases.yaml
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/test_cases.yaml
          ${CMAKE_CURRENT_BINARY_DIR}/test_cases.yaml
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/test_cases.yaml
  VERBATIM)
add_custom_target(test-cases-${id} DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/test_cases.yaml)

add_cpp_solution(cpp_solution cpp/interface.cpp)

add_problem_test(test test.cpp)
target_link_libraries(${test} PRIVATE ${cpp_solution} yaml-cpp)
add_dependencies(${test} test-cases-${id})
