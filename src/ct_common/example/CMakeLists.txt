set(SOURCE_FILES
  example.cpp)

add_executable(ct_common_example
  ${SOURCE_FILES}
  )

target_link_libraries(ct_common_example
  ct_file_parse ct_common)
