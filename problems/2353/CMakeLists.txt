get_dir_name(id)

add_executable(test-${id} test.cpp)
target_link_libraries(test-${id} PRIVATE Catch2::Catch2WithMain)
target_set_cpp_standard(test-${id})

catch_discover_tests(test-${id})
