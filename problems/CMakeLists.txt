set(PROBLEMS problem-1 problem-4 problem-5 problem-28 problem-1337 problem-2235)

foreach(PROBLEM ${PROBLEMS})
  add_executable(${PROBLEM} ${PROBLEM}/test.cpp)
  set_property(TARGET ${PROBLEM} PROPERTY CXX_STANDARD 20)
  target_link_libraries(${PROBLEM} PRIVATE Catch2::Catch2WithMain)
  catch_discover_tests(${PROBLEM})
endforeach()
