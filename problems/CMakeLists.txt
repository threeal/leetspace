set(PROBLEMS 1-two-sum 1337-the-k-weakest-rows-in-a-matrix 2235-add-two-integers)

foreach(PROBLEM ${PROBLEMS})
  add_executable(${PROBLEM} ${PROBLEM}/test.cpp)
  set_property(TARGET ${PROBLEM} PROPERTY CXX_STANDARD 17)
  target_link_libraries(${PROBLEM} PRIVATE Catch2::Catch2WithMain)
  catch_discover_tests(${PROBLEM})
endforeach()
