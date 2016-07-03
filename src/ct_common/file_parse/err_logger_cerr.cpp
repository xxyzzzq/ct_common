// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/file_parse/err_logger_cerr.h"

#include <iostream>

namespace ct_common {

ErrLogger_Cerr::ErrLogger_Cerr(void) : ErrLogger() {}

ErrLogger_Cerr::~ErrLogger_Cerr(void) {}

void ErrLogger_Cerr::innerReportError(const std::string &str) {
  std::cerr << str << std::endl;
}

void ErrLogger_Cerr::innerReportWarning(const std::string &str) {
  std::cerr << str << std::endl;
}

}  // namespace ct_common
