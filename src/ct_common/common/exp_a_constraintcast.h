#ifndef CT_COMMON_EXP_A_CONSTRAINTCAST_H_
#define CT_COMMON_EXP_A_CONSTRAINTCAST_H_

#include <ct_common/common/constraint.h>
#include <ct_common/common/exp_a.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_A_ConstraintCast : public Exp_A {
public:
  Exp_A_ConstraintCast(void);
  Exp_A_ConstraintCast(const Exp_A_ConstraintCast &from);
  Exp_A_ConstraintCast &operator = (const Exp_A_ConstraintCast &right);
  virtual ~Exp_A_ConstraintCast(void);

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;

  boost::shared_ptr<Constraint> get_oprd(void) const { return boost::dynamic_pointer_cast<Constraint>(this->oprds_[0]); }
  void set_oprd(const boost::shared_ptr<TreeNode> &oprd) { this->oprds_[0] = oprd; }
  
private:
  virtual EvalType_Double EvaluateDouble_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const;
};
}  // namespace common
}  // namespace ct

#endif // EXP_A_CONSTRAINTCAST_H_
