// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/file_parse/err_logger.h"

namespace ct_common {

ErrLogger::ErrLogger(void) : num_errs_(0), num_warnings_(0) {}

ErrLogger::~ErrLogger(void) {}

void ErrLogger::reportError(const std::string &str) {
  this->num_errs_++;
  this->innerReportError(str);
}

void ErrLogger::reportWarning(const std::string &str) {
  this->num_warnings_++;
  this->innerReportWarning(str);
}

}  // namespace ct_common
