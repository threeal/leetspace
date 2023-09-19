cmake_minimum_required(VERSION 3.0)

project(leetspace)

include(cmake/CPM.cmake)

cpmgetpackage(Format.cmake)

enable_testing()

cpmgetpackage(Catch2)
include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

add_subdirectory(problems)
