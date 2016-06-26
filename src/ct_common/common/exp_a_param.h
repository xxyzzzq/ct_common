//===----- ct_common/common/exp_a_param.h -----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for arithmetic expressions w.r.t. a
// parameter
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_PARAM_H
#define CT_COMMON_EXP_A_PARAM_H

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_atom.h"

namespace ct {
namespace common {
/**
 * The class for arithemetic expressions w.r.t. a parameter
 */
class DLL_EXPORT Exp_A_Param : public Exp_A_Atom {
 public:
  Exp_A_Param(void);
  Exp_A_Param(const Exp_A_Param &from);
  Exp_A_Param &operator=(const Exp_A_Param &right);
  virtual ~Exp_A_Param(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

  virtual void inner_touch_leaf_pids(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      std::set<std::size_t> &pids_to_touch) const;

 public:
  void set_pid(std::size_t pid) { this->pid_ = pid; }
  std::size_t get_pid(void) const { return this->pid_; }

 private:
  virtual EvalType_Double EvaluateDouble_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

  virtual EvalType_Int EvaluateInt_Impl(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  std::size_t pid_; /**< The parameter id */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_PARAM_H
