#ifndef CT_COMMON_EXP_A_CINT_H
#define CT_COMMON_EXP_A_CINT_H

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a_term.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_A_CInt : public Exp_A_Term {
public:
  Exp_A_CInt(void);
  Exp_A_CInt(const Exp_A_CInt &from);
  Exp_A_CInt &operator = (const Exp_A_CInt &right);
  virtual ~Exp_A_CInt(void);

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;

public:
  virtual void set_value(int value);
  virtual void set_value(double value);
  void set_str_value(const std::string &str_value);
  
  int get_value(void) const { return this->value_; }
  virtual const std::string &get_str_value(void) const;

private:
  virtual EvalType_Double EvaluateDouble_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const;

private:
  int value_;
  std::string str_value_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_CINT_H
