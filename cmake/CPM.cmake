# SPDX-License-Identifier: MIT
#
# SPDX-FileCopyrightText: Copyright (c) 2019-2023 Lars Melchior and contributors

set(CPM_DOWNLOAD_VERSION 0.40.1)
set(CPM_HASH_SUM a5467d77aa63a1197ea4e1644623acb7)

if(CPM_SOURCE_CACHE)
  set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
  set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
  set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

# Expand relative path. This is important if the provided path contains a tilde (~)
get_filename_component(CPM_DOWNLOAD_LOCATION ${CPM_DOWNLOAD_LOCATION} ABSOLUTE)

file(DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
     ${CPM_DOWNLOAD_LOCATION} EXPECTED_MD5 ${CPM_HASH_SUM})

include(${CPM_DOWNLOAD_LOCATION})
cpmusepackagelock(package-lock)
