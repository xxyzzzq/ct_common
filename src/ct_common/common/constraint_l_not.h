//===----- ct_common/common/constraint_l_not.h ------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for logical constraint "!"
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_L_NOT_H_
#define CT_COMMON_CONSTRAINT_L_NOT_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_l_unary.h"

namespace ct {
namespace common {
/**
 * The class for logical constraint "!"
 */
class DLL_EXPORT Constraint_L_Not : public Constraint_L_Unary {
 public:
  Constraint_L_Not(void);
  Constraint_L_Not(const Constraint_L_Not &from);
  Constraint_L_Not &operator=(const Constraint_L_Not &right);
  virtual ~Constraint_L_Not(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual bool evaluate_func(bool val) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_NOT_H_
