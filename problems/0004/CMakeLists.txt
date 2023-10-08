add_test_cases(test_cases test_cases.yaml)
add_cpp_solution(cpp_solution cpp/interface.cpp)

add_problem_test(test test.cpp)
target_link_libraries(${test} PRIVATE ${test_cases} ${cpp_solution})
