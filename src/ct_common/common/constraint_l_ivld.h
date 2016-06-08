//===----- ct_common/common/constraint_l_ivld.h -----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for parameter invalidation atom
// constraints
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_IVLD_H_
#define CT_COMMON_CONSTRAINT_L_IVLD_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l_atom.h>

namespace ct {
namespace common {
/**
 * The class for parameter invalidation constraints which is atomic
 */
class DLL_EXPORT Constraint_L_IVLD : public Constraint_L_Atom {
public:
  Constraint_L_IVLD(void);
  Constraint_L_IVLD(const Constraint_L_IVLD &from);
  Constraint_L_IVLD &operator = (const Constraint_L_IVLD &right);
  virtual ~Constraint_L_IVLD(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

  virtual void inner_touch_leaf_pids(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    std::set<std::size_t> &pids_to_touch) const;
  
  void set_pid(std::size_t pid) { this->pid_ = pid; }
  std::size_t get_pid(void) const { return this->pid_; }

  virtual EvalType_Bool Evaluate(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;

private:
  /** Called when some condition of an auto parameter is true, to get the corresponding value */
  std::shared_ptr<EvalType> EvaluateAutoCaseExp(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    const Assignment &assignment,
    const std::shared_ptr<TreeNode> &exp) const;

private:
  std::size_t pid_;  /**< parameter id */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_IVLD_H_
