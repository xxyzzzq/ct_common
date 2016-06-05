cmake_minimum_required (VERSION 2.8)
project (ct_common)

include_directories(src)
include_directories(${CMAKE_BINARY_DIR}/src)
include_directories(third_party/quex)

set(QUEX
  python ${CMAKE_SOURCE_DIR}/third_party/quex/quex-exe.py)

set(QUEX_PATH
  ${CMAKE_SOURCE_DIR}/third_party/quex)

set(QUEX_PATH "${CMAKE_SOURCE_DIR}/third_party/quex")

add_subdirectory (src/ct_common)
