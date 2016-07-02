// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_EXP_H_
#define CT_COMMON_COMMON_EXP_H_

#include <map>
#include <string>

#include "ct_common/base/utils.h"
#include "ct_common/common/pvpair.h"
#include "ct_common/common/tree_node.h"
#include "ct_common/common/tuple.h"

namespace ct_common {

// Base class for expression non-boolean expressions only
class DLL_EXPORT Exp : public TreeNode {
 public:
  Exp(void);
  Exp(const Exp &from);
  Exp &operator=(const Exp &right);
  virtual ~Exp(void) = 0;

 public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_EXP_H_
