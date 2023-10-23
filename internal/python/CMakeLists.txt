find_program(POETRY_EXEC poetry)
if(NOT POETRY_EXEC)
  message(FATAL_ERROR "Cannot find Poetry program! See: https://python-poetry.org/docs/")
endif()

execute_process(
  COMMAND ${POETRY_EXEC} config virtualenvs.path ${CMAKE_CURRENT_BINARY_DIR}/venv --local
  COMMAND ${POETRY_EXEC} config virtualenvs.in-project true --local
  COMMAND ${POETRY_EXEC} install
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND_ERROR_IS_FATAL ANY)
