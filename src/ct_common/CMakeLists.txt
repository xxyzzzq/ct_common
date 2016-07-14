file(
  GLOB_RECURSE
  CT_COMMON_SOURCE_FILES
  base/*.cpp
  base/*.h
  common/*.cpp
  common/*.h
  common/*.inc)

add_library(ct_common
  ${CT_COMMON_SOURCE_FILES}
  )

add_subdirectory(file_parse)
