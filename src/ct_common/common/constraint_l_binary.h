// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_BINARY_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_BINARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l.h"

namespace ct_common {

// Base class for binary logical constraints
class DLL_EXPORT Constraint_L_Binary : public Constraint_L {
 public:
  Constraint_L_Binary(void);
  Constraint_L_Binary(const Constraint_L_Binary &from);
  Constraint_L_Binary &operator=(const Constraint_L_Binary &right);
  virtual ~Constraint_L_Binary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;
  /** Get the corresponding string token */
  virtual std::string get_op_token(void) const = 0;

  std::shared_ptr<const Constraint> get_loprd(void) const {
    return std::dynamic_pointer_cast<Constraint>(this->oprds_[0]);
  }
  std::shared_ptr<const Constraint> get_roprd(void) const {
    return std::dynamic_pointer_cast<Constraint>(this->oprds_[1]);
  }

  void set_loprd(const std::shared_ptr<TreeNode> &loprd) {
    this->oprds_[0] = loprd;
  }
  void set_roprd(const std::shared_ptr<TreeNode> &roprd) {
    this->oprds_[1] = roprd;
  }

  virtual EvalType_Bool Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  /** Inner evaluation function */
  virtual EvalType_Bool evaluate_func(EvalType_Bool val_l,
                                      EvalType_Bool val_r) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_BINARY_H_
