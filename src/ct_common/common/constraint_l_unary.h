#ifndef CT_COMMON_CONSTRAINT_L_UNARY_H_
#define CT_COMMON_CONSTRAINT_L_UNARY_H_

#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_L_Unary : public Constraint_L {
public:
  Constraint_L_Unary(void);
  Constraint_L_Unary(const Constraint_L_Unary &from);
  Constraint_L_Unary &operator = (const Constraint_L_Unary &right);
  virtual ~Constraint_L_Unary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;
  virtual std::string get_op_token(void) const = 0;

  boost::shared_ptr<const Constraint> get_oprd(void) const { return boost::dynamic_pointer_cast<Constraint>(this->oprds_[0]); }
  void set_oprd(const boost::shared_ptr<TreeNode> &oprd) { this->oprds_[0] = oprd; }

  virtual EvalType_Bool Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;

private:
  // whether the result is valid is controled by the Evaluate funciton
  virtual bool evaluate_func(bool val) const = 0;

};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_UNARY_H_
