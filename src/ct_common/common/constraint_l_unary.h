// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_UNARY_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_UNARY_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l.h"

namespace ct_common {

// Base class for unary logical constraints
class DLL_EXPORT Constraint_L_Unary : public Constraint_L {
 public:
  Constraint_L_Unary(void);
  Constraint_L_Unary(const Constraint_L_Unary &from);
  Constraint_L_Unary &operator=(const Constraint_L_Unary &right);
  virtual ~Constraint_L_Unary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;
  /** Get the corresponding string token */
  virtual std::string get_op_token(void) const = 0;

  std::shared_ptr<const Constraint> get_oprd(void) const {
    return std::dynamic_pointer_cast<Constraint>(this->oprds_[0]);
  }
  void set_oprd(const std::shared_ptr<TreeNode> &oprd) {
    this->oprds_[0] = oprd;
  }

  virtual EvalType_Bool Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  /** Inner function for evaluating the value */
  virtual bool evaluate_func(bool val) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_UNARY_H_
