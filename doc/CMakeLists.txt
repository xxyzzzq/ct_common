set(BUILDDOC
  python ${CMAKE_CURRENT_SOURCE_DIR}/../tools/build_doc.py)

add_custom_target(ct_common_docs ALL
  DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  )

set_source_files_properties(
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  PROPERTIES GENERATED TRUE)


add_custom_command(OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  COMMAND
  ${BUILDDOC} ${CMAKE_CURRENT_SOURCE_DIR}/programming_guide.md --out-dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}
  COMMAND
  ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/strapdown/v/0.2
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/style
  DEPENDS programming_guide.md ${CMAKE_CURRENT_SOURCE_DIR}/../tools/build_doc.py
  )
