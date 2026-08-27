get_dir_name(id)

add_executable(test-${id} test.cpp)
target_link_libraries(test-${id} PRIVATE Catch2::Catch2WithMain)
target_compile_options(test-${id} PRIVATE -Wno-write-strings)

catch_discover_tests(test-${id})
