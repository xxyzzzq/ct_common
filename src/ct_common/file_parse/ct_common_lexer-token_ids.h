#ifndef CT_LEXER_TOKEN_IDS_H_
#define CT_LEXER_TOKEN_IDS_H_

#include "ct_common/file_parse/parser.tab.hpp"

namespace ct_common {
const int QUEX_TKN_TERMINATION = ct_common::parser::token::TKN_END;
const int QUEX_TKN_UNINITIALIZED = 1;
const int QUEX_TKN_UNKNOWN = 2;
const int QUEX_TKN_FAILURE = 3;
}

#endif  // CT_LEXER_TOKEN_IDS_H_
