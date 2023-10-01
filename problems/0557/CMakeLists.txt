add_test_cases(test_cases test_cases.yaml)
add_c_solution(c_solution c/interface.c c/interface.cpp)
add_cpp_solution(cpp_solution cpp/interface.cpp)

add_problem_test(test test.cpp)
target_link_libraries(${test} PRIVATE ${c_solution} ${cpp_solution} yaml-cpp)
add_dependencies(${test} ${test_cases})
