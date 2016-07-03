// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef ERR_LOGGER_CERR_H_
#define ERR_LOGGER_CERR_H_

#include "ct_common/file_parse/err_logger.h"

namespace ct_common {

class ErrLogger_Cerr : public ErrLogger {
 public:
  ErrLogger_Cerr(void);
  virtual ~ErrLogger_Cerr(void);

 public:
  virtual void innerReportError(const std::string &str);
  virtual void innerReportWarning(const std::string &str);
};

}  // namespace ct_common

#endif  // ERR_LOGGER_CERR_H_
