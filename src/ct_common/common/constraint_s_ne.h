//===----- ct_common/common/constraint_s_ne.h -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for string constraint "!="
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_S_NE_H_
#define CT_COMMON_CONSTRAINT_S_NE_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_s_binary.h"

namespace ct {
namespace common {
/**
 * The class for string function "!="
 */
class DLL_EXPORT Constraint_S_NE : public Constraint_S_Binary {
public:
  Constraint_S_NE(void);
  Constraint_S_NE(const Constraint_S_NE &from);
  Constraint_S_NE &operator = (const Constraint_S_NE &right);
  ~Constraint_S_NE(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual bool evaluate_func(const std::string &val_1, const std::string &val_2) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_S_NE_H_
