lib_LIBRARIES = libct_file_parse.a

AM_CPPFLAGS = -I ../../.. -I ../.. -DQUEX_OPTION_STRANGE_ISTREAM_IMPLEMENTATION -DQUEX_OPTION_ASSERTS_DISABLED
AM_CXXFLAGS = -I ../../.. -I ../.. -DQUEX_OPTION_STRANGE_ISTREAM_IMPLEMENTATION -DQUEX_OPTION_ASSERTS_DISABLED

libct_file_parse_a_SOURCES=assembler.cpp ct_parser.tab.cpp ct_lexer.cpp err_logger_cerr.cpp err_logger.cpp

libct_file_parse_a_LIBADD=../common/libct_common.a

if BISON_ENABLED
ct_parser.tab.hpp: ct_parser.ypp
	${BISON} -d ct_parser.ypp
endif  # BISON_ENABLED

if QUEX_ENABLED
ct_lexer.hpp: ct_lexer.qx ct_parser.tab.hpp
	${QUEX} -i ct_lexer.qx -o ct::lexer --token-class ct::lexer_Token --foreign-token-id-file ct_lexer-token_ids.h --source-package . --file-extension-scheme pp
	rm -rf ../../../quex
	mv quex ../../.. -f
endif  # QUEX_ENABLED

ct_parser.tab.cpp: ct_lexer.hpp ct_lexer.hpp ct_parser.tab.hpp

ct_lexer.cpp: ct_lexer.hpp

QUEX_OUTPUTS=ct_lexer.hpp ct_lexer-token.hpp ct_lexer-token_ids.hpp ct_lexer-configuration.hpp ct_lexer.cpp
BISON_OUTPUTS=ct_parser.tab.hpp ct_parser.tab.cpp \
location.hh  position.hh  stack.hh

clean-local:
if QUEX_ENABLED
	rm -f ${QUEX_OUTPUTS}
endif  # QUEX_ENABLED
if BISON_ENABLED
	rm -f ${BISON_OUTPUTS}
endif  # BISON_ENABLED

EXTRA_DIST= \
ct_lexer.qx ct_parser.ypp \
location.hh  position.hh  stack.hh


