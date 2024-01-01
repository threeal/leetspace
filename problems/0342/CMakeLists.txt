add_c_solution(c_solution c/interface.c c/interface.cpp)

get_dir_name(id)
add_problem_test(test-${id} test.yaml)
target_link_libraries(test-${id} PRIVATE ${c_solution})
