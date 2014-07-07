//===----- ct_common/common/exp.h -------------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_H_
#define CT_COMMON_EXP_H_

#include <map>
#include <string>
#include <ct_common/common/utils.h>
#include <ct_common/common/tuple.h>
#include <ct_common/common/pvpair.h>
#include <ct_common/common/tree_node.h>

namespace ct {
namespace common {
/**
 * Base class for expression
 * non-boolean expressions only
 */
class DLL_EXPORT Exp : public TreeNode {
public:
  Exp(void);
  Exp(const Exp &from);
  Exp &operator = (const Exp &right);
  virtual ~Exp(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_H_
