get_dir_name(id)
add_problem(${id} cpp)

add_problem_test(test-${id} test.cpp)
target_link_libraries(test-${id} PRIVATE solution-${id}-cpp)
