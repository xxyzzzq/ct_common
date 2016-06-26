#include "ct_common/file_parse/err_logger.h"

using namespace ct::common;

ErrLogger::ErrLogger(void)
    : num_errs_(0), num_warnings_(0) {
}

ErrLogger::ErrLogger(const ErrLogger &from)
    : num_errs_(from.num_errs_), num_warnings_(from.num_warnings_) {
}

ErrLogger::~ErrLogger(void) {
}

ErrLogger &ErrLogger::operator =(const ErrLogger &right) {
  this->num_errs_ = right.num_errs_;
  this->num_warnings_ = right.num_warnings_;
  return *this;
}

void ErrLogger::reportError(const std::string &str) {
  this->num_errs_++;
  this->innerReportError(str);
}

void ErrLogger::reportWarning(const std::string &str) {
  this->num_warnings_++;
  this->innerReportWarning(str);
}
