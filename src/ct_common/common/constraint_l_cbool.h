#ifndef CT_COMMON_CONSTRAINT_L_CBOOL_H_
#define CT_COMMON_CONSTRAINT_L_CBOOL_H_

#include <ct_common/common/constraint_l_term.h>

namespace ct {
namespace common {
class Constraint_L_CBool : public Constraint_L_Term {
public:
  Constraint_L_CBool(void);
  Constraint_L_CBool(const Constraint_L_CBool &from);
  virtual ~Constraint_L_CBool(void);
  Constraint_L_CBool &operator = (const Constraint_L_CBool &right);
  
public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

  void set_value(bool val) { this->value_ = val; }
  bool get_value(void) const { return this->value_; }
  
  virtual const std::string &get_str_value(void) const;
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;

public:
  virtual EvalType_Bool Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;

private:
  bool value_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_CBOOL_H_
