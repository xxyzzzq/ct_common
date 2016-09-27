function(apply_doc_rule target_name)
  set_source_files_properties(
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/${target_name}
    PROPERTIES GENERATED TRUE)

  set(BUILDDOC
    python ${CMAKE_CURRENT_SOURCE_DIR}/../tools/build_doc.py)

  string(REPLACE ".html" ".md" INPUT_FILE ${target_name})

  add_custom_command(
    OUTPUT
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/${target_name}
    COMMAND
    ${BUILDDOC} ${CMAKE_CURRENT_SOURCE_DIR}/${INPUT_FILE} --out-dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/strapdown/v/0.2
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/style
    DEPENDS ${INPUT_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/../tools/build_doc.py
    )
endfunction(apply_doc_rule)


add_custom_target(ct_common_docs ALL
  DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_CFG_INTDIR}/programming_guide.html
  )

apply_doc_rule(programming_guide.html)
