file(
  GLOB_RECURSE
  SOURCE_FILES
  *.cpp
  *.h)

set(PARSER_GENERATED_FILES
  parser.tab.hpp parser.tab.cpp location.hh position.hh stack.hh)

set(LEXER_GENERATED_FILES
  ct_common_lexer.cpp ct_common_lexer.hpp ct_common_lexer-token.hpp ct_common_lexer-configuration.hpp)

set_source_files_properties(
  ${PARSER_GENERATED_FILES}
  ${LEXER_GENERATED_FILES}
  PROPERTIES GENERATED TRUE)

add_custom_command(
  OUTPUT ${LEXER_GENERATED_FILES}
  COMMAND
  ${QUEX} -i ${CMAKE_CURRENT_SOURCE_DIR}/ct_common_lexer.qx -o ct_common::lexer --token-class ct_common::lexer_Token --foreign-token-id-file ${CMAKE_CURRENT_SOURCE_DIR}/ct_common_lexer-token_ids.h --source-package . --file-extension-scheme pp --suppress 0
  DEPENDS ct_common_lexer.qx parser.tab.hpp
  )

add_custom_command(
  OUTPUT ${PARSER_GENERATED_FILES}
  COMMAND
  bison -d ${CMAKE_CURRENT_SOURCE_DIR}/parser.ypp
  DEPENDS parser.ypp
  )

add_library(
  ct_file_parse
  ${SOURCE_FILES}
  ${LEXER_GENERATED_FILES}
  ${PARSER_GENERATED_FILES}
  )
