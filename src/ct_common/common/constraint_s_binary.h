//===----- ct_common/common/constraint_s_binary.h ---------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for binary string constraints
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_S_BINARY_H_
#define CT_COMMON_CONSTRAINT_S_BINARY_H_

#include <memory>
#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_s.h>
#include <ct_common/common/exp_s.h>

namespace ct {
namespace common {
/**
 * Base class for binary string constraints
 */
class DLL_EXPORT Constraint_S_Binary : public Constraint_S {
public:
  Constraint_S_Binary(void);
  Constraint_S_Binary(const Constraint_S_Binary &from);
  Constraint_S_Binary &operator = (const Constraint_S_Binary &right);
  virtual ~Constraint_S_Binary(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;
  /** Get the corresponding string token */
  virtual std::string get_op_token(void) const = 0;

  std::shared_ptr<const Exp_S> get_loprd(void) const { return std::dynamic_pointer_cast<Exp_S>(this->oprds_[0]); }
  std::shared_ptr<const Exp_S> get_roprd(void) const { return std::dynamic_pointer_cast<Exp_S>(this->oprds_[1]); }

  void set_loprd(const std::shared_ptr<TreeNode> &loprd) { this->oprds_[0] = loprd; }
  void set_roprd(const std::shared_ptr<TreeNode> &roprd) { this->oprds_[1] = roprd; }

  virtual EvalType_Bool Evaluate(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;
private:
  /** Inner function for determining the return value */
  virtual bool evaluate_func(const std::string &val_1, const std::string &val_2) const = 0;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_S_BINARY_H_
