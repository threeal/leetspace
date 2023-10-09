add_test_cases(test_cases test_cases.yaml)
add_c_solution(c_solution c/interface.c c/interface.cpp)
add_cpp_solution(cpp_solution cpp/interface.cpp)

get_dir_name(id)
generate_problem_test(test-${id} test.yaml)
target_link_libraries(test-${id} PRIVATE ${test_cases} ${c_solution} ${cpp_solution})
