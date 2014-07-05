#ifndef CT_COMMON_EXP_S_CSTRING_H
#define CT_COMMON_EXP_S_CSTRING_H

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_s_term.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_S_CString : public Exp_S_Term {
public:
  Exp_S_CString(void);
  Exp_S_CString(const Exp_S_CString &from);
  Exp_S_CString &operator = (const Exp_S_CString &right);
  virtual ~Exp_S_CString(void);

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;

public:
  void set_value(const std::string &value) { this->value_ = value; }
  void set_value(const char *value) { this->value_ = value; }
  
  const std::string &get_value(void) const { return this->value_; }
  virtual const std::string &get_str_value(void) const;

  virtual EvalType_String Evaluate( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const;

private:
  std::string value_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_S_CSTRING_H
