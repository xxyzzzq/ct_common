// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_S_EQ_H_
#define CT_COMMON_COMMON_CONSTRAINT_S_EQ_H_

#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/constraint_s_binary.h"

namespace ct_common {

// Class for string constraint "=="
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

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_S_EQ_H_
