#ifndef CT_COMMON_ERR_LOGGER_H_
#define CT_COMMON_ERR_LOGGER_H_

#include <string>

namespace ct {
namespace common {
class ErrLogger {
public:
  ErrLogger(void);
  ErrLogger(const ErrLogger &from);
  virtual ~ErrLogger(void);
  ErrLogger &operator = (const ErrLogger &right);

public:
  void reportError(const std::string &str);
  void reportWarning(const std::string &str);
  
  std::size_t numErrs(void) const { return this->num_errs_; }
  std::size_t numWarnings(void) const { return this->num_warnings_; }

private:
  virtual void innerReportError(const std::string &str) = 0;
  virtual void innerReportWarning(const std::string &str) = 0;
  
private:
  std::size_t num_errs_;
  std::size_t num_warnings_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_ERR_LOGGER_H_
