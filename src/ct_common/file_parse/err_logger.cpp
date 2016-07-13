// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/file_parse/err_logger.h"

namespace ct_common {

ErrLogger::ErrLogger(void) : num_errs_(0), num_warnings_(0) {}

ErrLogger::~ErrLogger(void) {}

void ErrLogger::ReportError(const std::string &str) {
  this->num_errs_++;
  this->InnerReportError(str);
}

void ErrLogger::ReportWarning(const std::string &str) {
  this->num_warnings_++;
  this->InnerReportWarning(str);
}

}  // namespace ct_common
