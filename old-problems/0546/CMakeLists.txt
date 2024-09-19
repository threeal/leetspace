get_dir_name(id)
add_problem_test(test-${id} test.yaml)
target_compile_options(test-${id} PRIVATE -Wno-missing-braces)
