// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_ERR_LOGGER_H_
#define CT_COMMON_ERR_LOGGER_H_

#include <string>
#include "ct_common/base/utils.h"

namespace ct_common {

class ErrLogger {
 public:
  ErrLogger(void);
  virtual ~ErrLogger(void);

  void reportError(const std::string &str);
  void reportWarning(const std::string &str);

  std::size_t numErrs(void) const { return this->num_errs_; }
  std::size_t numWarnings(void) const { return this->num_warnings_; }

 private:
  virtual void innerReportError(const std::string &str) = 0;
  virtual void innerReportWarning(const std::string &str) = 0;

  std::size_t num_errs_;
  std::size_t num_warnings_;

  DISALLOW_COPY_AND_ASSIGN(ErrLogger);
};

}  // namespace ct_common

#endif  // CT_COMMON_ERR_LOGGER_H_
