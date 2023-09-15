cmake_minimum_required(VERSION 3.0)

project(leetspace)

include(cmake/CPM.cmake)

enable_testing()

cpmaddpackage("gh:catchorg/Catch2@3.4.0")
include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

add_subdirectory(problems)
