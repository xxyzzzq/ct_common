#ifndef ERR_LOGGER_CERR_H_
#define ERR_LOGGER_CERR_H_

#include <ct_common/common/err_logger.h>

namespace ct {
namespace common {
class ErrLogger_Cerr : public ErrLogger {
public:
  ErrLogger_Cerr(void);
  ErrLogger_Cerr(const ErrLogger_Cerr &from);
  virtual ~ErrLogger_Cerr(void);
  const ErrLogger_Cerr &operator = (const ErrLogger_Cerr &right);
  
public:
  virtual void innerReportError(const std::string &str);
  virtual void innerReportWarning(const std::string &str);  
};
}  // common
}  // ct

#endif  // ERR_LOGGER_CERR_H_
