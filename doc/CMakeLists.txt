add_custom_target(ct_common_docs ALL
  DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  )

set_source_files_properties(
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  PROPERTIES GENERATED TRUE)

add_custom_command(OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  COMMAND
  ${MARKDOWN} ${CMAKE_CURRENT_SOURCE_DIR}/programming_guide.md -o ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  DEPENDS programming_guide.md
  )
