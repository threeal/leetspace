find_program(POETRY_EXEC poetry)
if(NOT POETRY_EXEC)
  message(FATAL_ERROR "Cannot find Poetry program! See: https://python-poetry.org/docs/")
endif()

execute_process(
  COMMAND ${POETRY_EXEC} install
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND_ERROR_IS_FATAL ANY)

execute_process(
  COMMAND ${POETRY_EXEC} run black lib
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND_ERROR_IS_FATAL ANY)

function(generate_test_src)
  cmake_parse_arguments(ARG "" "CONFIG;OUTDIR" "" ${ARGN})

  file(GLOB_RECURSE SRCS "${CMAKE_SOURCE_DIR}/internal/python/lib/generate_test_src/*.py")
  get_filename_component(CONFIG_DIR ${ARG_CONFIG} DIRECTORY)

  add_custom_command(
    OUTPUT ${ARG_OUTDIR}/solution_cpp.cpp ${ARG_OUTDIR}/test.cpp
    COMMAND ${POETRY_EXEC} run generate_test_src ${ARG_CONFIG} ${ARG_OUTDIR}
    DEPENDS ${SRCS} ${ARG_CONFIG} ${CONFIG_DIR}/solution.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/internal/python
    VERBATIM)
endfunction()
