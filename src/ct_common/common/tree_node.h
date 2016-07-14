// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_TREE_NODE_H_
#define CT_COMMON_COMMON_TREE_NODE_H_

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/base/class_name_utils.h"

namespace ct_common {

class ParamSpec;

// The base class for all expressions and constraints
class DLL_EXPORT TreeNode {
 public:
  TreeNode();
  virtual ~TreeNode() = 0;

  /** Whether the node is a leaf node */
  bool IsLeaf() const { return oprds_.empty(); }

  /**
   * Get all related parameters EXCEPT for auto parameters
   * param_specs are used to determine related pids of auto parameters
   */
  void TouchPids(const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
                 std::set<std::size_t>* pids_to_touch) const;

  /** Get the operands */
  const std::vector<std::shared_ptr<TreeNode> >& get_oprds() const {
    return oprds_;
  }

  /** getting the string value (preserved copy of the original string
   * representation) */
  virtual const std::string& get_str_value() const;

  /** Print the tree node to a given output stream */
  virtual void Dump(
      std::ostream& os,
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs) const = 0;

 protected:
  std::vector<std::shared_ptr<TreeNode> > oprds_; /**< The operands */

 private:
  /** Inner function to get all related parameters */
  virtual void InnerTouchLeafPids(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      std::set<std::size_t>* pids_to_touch) const;

  DISALLOW_COPY_AND_ASSIGN(TreeNode);
};
}  // namespace ct_common

#endif  // CT_COMMON_COMMON_TREE_NODE_H_
