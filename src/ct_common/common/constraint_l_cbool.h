//===----- ct_common/common/constraint_l_cbool.h ----------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for constant boolean values
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_CBOOL_H_
#define CT_COMMON_CONSTRAINT_L_CBOOL_H_

#include "ct_common/common/constraint_l_atom.h"

namespace ct {
namespace common {
/**
 * The class for constant boolean atom constraints
 */
class Constraint_L_CBool : public Constraint_L_Atom {
 public:
  Constraint_L_CBool(void);
  Constraint_L_CBool(const Constraint_L_CBool &from);
  virtual ~Constraint_L_CBool(void);
  Constraint_L_CBool &operator=(const Constraint_L_CBool &right);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

  void set_value(bool val) { this->value_ = val; }
  bool get_value(void) const { return this->value_; }

  /** get the string value: true/false */
  virtual const std::string &get_str_value(void) const;
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;

 public:
  virtual EvalType_Bool Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const;

 private:
  bool value_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_CBOOL_H_
