get_dir_name(id)

add_c_solution(c_solution c/interface.cpp c/solution.c)
target_compile_options(c-solution-${id} PRIVATE -Wno-char-subscripts)

add_problem_test(test-${id} test.yaml)
target_link_libraries(test-${id} PRIVATE ${c_solution})
