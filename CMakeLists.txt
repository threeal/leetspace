cmake_minimum_required(VERSION 3.19)

project(leetspace)

include(cmake/CPM.cmake)

cpmgetpackage(CheckWarning.cmake)
add_check_warning()

cpmgetpackage(Format.cmake)

enable_testing()

cpmgetpackage(Catch2)
include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

add_subdirectory(internal)
add_subdirectory(problems)
