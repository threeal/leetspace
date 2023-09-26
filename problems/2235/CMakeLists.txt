get_dir_name(id)
add_problem(${id} c)

add_cpp_solution(cpp-solution-${id} cpp/interface.cpp)

add_problem_test(test-${id} test.cpp)
target_link_libraries(test-${id} PRIVATE cpp-solution-${id} solution-${id}-cpp-c)
