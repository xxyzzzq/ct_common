#ifndef CT_COMMON_CONSTRAINT_S_BINARY_H_
#define CT_COMMON_CONSTRAINT_S_BINARY_H_

#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_s.h>
#include <ct_common/common/exp_s.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_S_Binary : public Constraint_S {
public:
  Constraint_S_Binary(void);
  Constraint_S_Binary(const Constraint_S_Binary &from);
  Constraint_S_Binary &operator = (const Constraint_S_Binary &right);
  virtual ~Constraint_S_Binary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const;
  virtual std::string get_op_token(void) const = 0;

  boost::shared_ptr<const Exp_S> get_loprd(void) const { return boost::dynamic_pointer_cast<Exp_S>(this->oprds_[0]); }
  boost::shared_ptr<const Exp_S> get_roprd(void) const { return boost::dynamic_pointer_cast<Exp_S>(this->oprds_[1]); }

  void set_loprd(const boost::shared_ptr<TreeNode> &loprd) { this->oprds_[0] = loprd; }
  void set_roprd(const boost::shared_ptr<TreeNode> &roprd) { this->oprds_[1] = roprd; }

  virtual EvalType_Bool Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;
private:
  virtual bool evaluate_func(const std::string &val_1, const std::string &val_2) const = 0;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_S_BINARY_H_
