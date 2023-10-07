add_test_cases(test_cases test_cases.yaml)

add_problem_test(test test.cpp)
target_link_libraries(${test} PRIVATE yaml-cpp)
add_dependencies(${test} ${test_cases})
