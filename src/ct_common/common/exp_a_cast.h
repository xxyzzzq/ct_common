// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_A_CAST_H_
#define CT_COMMON_COMMON_EXP_A_CAST_H_

#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/exp_a_unary.h"

namespace ct_common {

// Class for casting between int/double expressions
class DLL_EXPORT Exp_A_Cast : public Exp_A_Unary {
 public:
  Exp_A_Cast(void);
  Exp_A_Cast(const Exp_A_Cast &from);
  Exp_A_Cast &operator=(const Exp_A_Cast &right);
  virtual ~Exp_A_Cast(void);

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual void dump(
      std::ostream &os,
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const;
  virtual std::string get_op_token(void) const;

 private:
  virtual double evaluate_double(double val) const;
  virtual int evaluate_int(int val) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_A_CAST_H_
