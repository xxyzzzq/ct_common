#ifndef CT_COMMON_CONSTRAINT_L_BINARY_H_
#define CT_COMMON_CONSTRAINT_L_BINARY_H_

#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_L_Binary : public Constraint_L {
public:
  Constraint_L_Binary(void);
  Constraint_L_Binary(const Constraint_L_Binary &from);
  Constraint_L_Binary &operator = (const Constraint_L_Binary &right);
  virtual ~Constraint_L_Binary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;
  virtual std::string get_op_token(void) const = 0;

  boost::shared_ptr<const Constraint> get_loprd(void) const { return boost::dynamic_pointer_cast<Constraint>(this->oprds_[0]); }
  boost::shared_ptr<const Constraint> get_roprd(void) const { return boost::dynamic_pointer_cast<Constraint>(this->oprds_[1]); }

  void set_loprd(const boost::shared_ptr<TreeNode> &loprd) { this->oprds_[0] = loprd; }
  void set_roprd(const boost::shared_ptr<TreeNode> &roprd) { this->oprds_[1] = roprd; }

  virtual EvalType_Bool Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;

private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const = 0;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_BINARY_H_
