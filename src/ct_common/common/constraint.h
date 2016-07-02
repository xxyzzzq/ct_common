// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_CONSTRAINT_H_
#define CT_COMMON_COMMON_CONSTRAINT_H_

#include <memory>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/assignment.h"
#include "ct_common/common/eval_type_bool.h"
#include "ct_common/common/paramspec.h"
#include "ct_common/common/pvpair.h"
#include "ct_common/common/tree_node.h"

namespace ct_common {

// Base constraint class.  Only for boolean expressions. Actually, a constraint
// is a boolean-typed expression, but our design seperates constraints from
// other expressions to eliminate possible ambiguities.
class DLL_EXPORT Constraint : public TreeNode {
 public:
  Constraint(void);
  // This class is not supposed to be copied and assigned
  // only the reference is copied
  Constraint(const Constraint &from);
  Constraint &operator=(const Constraint &right);
  virtual ~Constraint(void) = 0;

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

 public:
  /** Whether the constraint is satisfied */
  virtual EvalType_Bool Evaluate(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const Assignment &assignment) const = 0;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_CONSTRAINT_H_
