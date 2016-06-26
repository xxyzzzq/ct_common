//===----- ct_common/common/constraint_s_eq.h -------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for string constraint "=="
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_CONSTRAINT_S_EQ_H_
#define CT_COMMON_CONSTRAINT_S_EQ_H_

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_s_binary.h"

namespace ct {
namespace common {
/**
 * The class for string constraint "=="
 */
class DLL_EXPORT Constraint_S_EQ : public Constraint_S_Binary {
 public:
  Constraint_S_EQ(void);
  Constraint_S_EQ(const Constraint_S_EQ &from);
  Constraint_S_EQ &operator=(const Constraint_S_EQ &right);
  ~Constraint_S_EQ(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

 private:
  virtual bool evaluate_func(const std::string &val_1,
                             const std::string &val_2) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_S_EQ_H_
