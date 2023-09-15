set(PROBLEMS 2235-add-two-integers)

foreach(PROBLEM ${PROBLEMS})
  add_executable(${PROBLEM} ${PROBLEM}/main.cpp)
  add_test(NAME ${PROBLEM} COMMAND ${PROBLEM})
endforeach()
