cmake_minimum_required (VERSION 3.1)
project (ct_common)

set(CMAKE_CXX_STANDARD_REQUIRED 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/bin)

include_directories(src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(third_party/quex)

set(QUEX
  python ${CMAKE_CURRENT_SOURCE_DIR}/tools/quex_wrapper.py)

add_subdirectory(src/ct_common)
