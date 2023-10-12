add_cpp_solution(cpp_solution cpp/interface.cpp)

get_dir_name(id)
add_problem_test(test-${id} test.yaml)
target_link_libraries(test-${id} PRIVATE ${cpp_solution})
