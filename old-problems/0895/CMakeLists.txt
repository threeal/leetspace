get_dir_name(id)

add_executable(test-${id} test.cpp)
target_link_libraries(test-${id} PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(test-${id})
