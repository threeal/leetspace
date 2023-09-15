set(PROBLEMS 2235-add-two-integers)

foreach(PROBLEM ${PROBLEMS})
  add_executable(${PROBLEM} ${PROBLEM}/main.cpp)
endforeach()
