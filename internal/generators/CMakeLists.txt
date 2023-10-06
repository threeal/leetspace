macro(add_test_cases target)
  get_dir_name(id)
  set(${target} test-cases-${id})

  foreach(arg ${ARGN})
    set(output ${CMAKE_CURRENT_BINARY_DIR}/${arg})
    add_custom_command(
      OUTPUT ${output}
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${arg} ${output}
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${arg}
      VERBATIM)
    list(APPEND outputs ${output})
  endforeach()
  add_custom_target(test-cases-${id} DEPENDS ${outputs})
endmacro()
