set(PROBLEMS 2235-add-two-integers)

foreach(PROBLEM ${PROBLEMS})
  add_executable(${PROBLEM} ${PROBLEM}/test.cpp)
  target_link_libraries(${PROBLEM} PRIVATE Catch2::Catch2WithMain)
  catch_discover_tests(${PROBLEM})
endforeach()
