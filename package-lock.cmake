# CPM Package Lock
# This file should be committed to version control

# Format.cmake
cpmdeclarepackage(
  Format.cmake
  VERSION 1.7.3
  GITHUB_REPOSITORY TheLartians/Format.cmake
  SYSTEM YES
  EXCLUDE_FROM_ALL YES)
# yaml-cpp
cpmdeclarepackage(
  yaml-cpp GIT_TAG 0.8.0
  GITHUB_REPOSITORY jbeder/yaml-cpp
  SYSTEM YES
  EXCLUDE_FROM_ALL YES
  OPTIONS "YAML_CPP_FORMAT_SOURCE OFF")
# Catch2
cpmdeclarepackage(
  Catch2
  VERSION 3.4.0
  GITHUB_REPOSITORY catchorg/Catch2
  SYSTEM YES
  EXCLUDE_FROM_ALL YES)
