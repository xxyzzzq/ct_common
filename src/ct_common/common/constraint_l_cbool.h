// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_L_CBOOL_H_
#define CT_COMMON_COMMON_CONSTRAINT_L_CBOOL_H_

#include <string>
#include <vector>

#include "ct_common/common/constraint_l_atomic.h"

namespace ct_common {

// Class for constant boolean atom constraints
class Constraint_L_CBool : public Constraint_L_Atomic {
 public:
  Constraint_L_CBool();
  ~Constraint_L_CBool() override;

  void set_value(bool val) { value_ = val; }
  bool get_value() const { return value_; }

  /** get the string value: true/false */
  const std::string& get_str_value() const override;
  void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs)
      const override;

  optional<bool> Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const Assignment& assignment) const override;

 private:
  bool value_;

  DISALLOW_COPY_AND_ASSIGN(Constraint_L_CBool);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_L_CBOOL_H_
