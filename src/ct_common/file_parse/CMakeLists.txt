set(SOURCE_FILES
  assembler.cpp
  err_logger.cpp
  err_logger_cerr.cpp)

set(PARSER_GENERATED_FILES
  ct_parser.tab.cpp)

set(LEXER_GENERATED_FILES
  ct_lexer.cpp)

set_source_files_properties(
  ct_parser.tab.cpp
  ct_lexer.cpp
  PROPERTIES GENERATED TRUE)

add_custom_command(
  OUTPUT ct_lexer.cpp ct_lexer.hpp ct_lexer-token.hpp ct_lexer-configuration.hpp
  COMMAND
  ${QUEX} -i ${CMAKE_CURRENT_SOURCE_DIR}/ct_lexer.qx -o ct::lexer --token-class ct::lexer_Token --foreign-token-id-file ${CMAKE_CURRENT_SOURCE_DIR}/ct_lexer-token_ids.h --source-package . --file-extension-scheme pp --suppress 0
  DEPENDS ct_lexer.qx ct_parser.tab.hpp
  )

add_custom_command(
  OUTPUT ct_parser.tab.hpp ct_parser.tab.cpp location.hh position.hh stack.hh
  COMMAND
  bison -d ${CMAKE_CURRENT_SOURCE_DIR}/ct_parser.ypp
  DEPENDS ct_parser.ypp
  )

add_library(
  ct_file_parse
  ${SOURCE_FILES}
  ${LEXER_GENERATED_FILES}
  ${PARSER_GENERATED_FILES}
  )
