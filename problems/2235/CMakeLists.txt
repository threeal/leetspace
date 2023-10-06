add_test_cases(test_cases test_cases.yaml)
add_c_solution(c_solution c/interface.cpp c/solution.c)
add_cpp_solution(cpp_solution cpp/interface.cpp)

add_problem_test(test test.cpp)
target_link_libraries(${test} PRIVATE ${test_cases} ${c_solution} ${cpp_solution})
