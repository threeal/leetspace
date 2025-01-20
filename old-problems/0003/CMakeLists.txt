add_c_solution(c_solution c/interface.cpp c/solution.c)

get_dir_name(id)
add_problem_test(test-${id} test.yaml)
target_compile_options(test-${id} PRIVATE -Wno-char-subscripts)
target_link_libraries(test-${id} PRIVATE ${c_solution})
