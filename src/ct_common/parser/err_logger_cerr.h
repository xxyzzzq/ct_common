// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_PARSER_ERR_LOGGER_CERR_H_
#define CT_COMMON_PARSER_ERR_LOGGER_CERR_H_

#include <string>

#include "ct_common/parser/err_logger.h"

namespace ct_common {

class ErrLogger_Cerr : public ErrLogger {
 public:
  ErrLogger_Cerr(void);
  virtual ~ErrLogger_Cerr(void);

 private:
  virtual void InnerReportError(const std::string &str);
  virtual void InnerReportWarning(const std::string &str);
};

}  // namespace ct_common

#endif  // CT_COMMON_PARSER_ERR_LOGGER_CERR_H_
