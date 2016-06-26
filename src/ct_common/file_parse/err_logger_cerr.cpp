#include "ct_common/file_parse/err_logger_cerr.h"

#include <iostream>

using namespace ct::common;

ErrLogger_Cerr::ErrLogger_Cerr(void)
    : ErrLogger() {
}

ErrLogger_Cerr::ErrLogger_Cerr(const ErrLogger_Cerr &from)
    : ErrLogger(from) {
}

ErrLogger_Cerr::~ErrLogger_Cerr(void) {
}

const ErrLogger_Cerr &ErrLogger_Cerr::operator =(const ErrLogger_Cerr &right) {
  ErrLogger::operator =(right);
  return *this;
}

void ErrLogger_Cerr::innerReportError(const std::string &str) {
  std::cerr << str << std::endl;
}

void ErrLogger_Cerr::innerReportWarning(const std::string &str) {
  std::cerr << str << std::endl;
}
