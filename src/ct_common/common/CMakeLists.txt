file(
  GLOB_RECURSE
  SOURCE_FILES
  *.cpp
  *.h)

add_library(ct_common
  ${SOURCE_FILES}
  )
