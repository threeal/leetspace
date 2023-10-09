add_c_solution(c_solution c/interface.cpp c/solution.c)
add_cpp_solution(cpp_solution cpp/interface.cpp)

get_dir_name(id)
add_problem_test(test-${id} test.yaml)
target_link_libraries(test-${id} PRIVATE ${c_solution} ${cpp_solution})
