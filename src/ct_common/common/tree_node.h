//===----- ct_common/common/tree_node.h -------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for expressions and constraints
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_TREE_NODE_H_
#define CT_COMMON_TREE_NODE_H_

#include <vector>
#include <set>
#include <iostream>
#include <memory>

#include "ct_common/base/utils.h"

namespace ct {
namespace common {
class ParamSpec;

/**
 * The base class for all expressions and constraints
 */
class DLL_EXPORT TreeNode {
public:
  TreeNode(void);
  /** Only shallow copy here */
  TreeNode(const TreeNode &from);
  /** Only shallow copy here */
  TreeNode &operator = (const TreeNode &right);
  virtual ~TreeNode(void) = 0;

  /** TODO: replace by typeid */
  virtual std::string get_class_name(void) const;
  /** TODO: replace by typeid */
  static std::string class_name(void);
  /** Whether the node is a leaf node */
  bool is_leaf(void) const { return this->oprds_.empty(); }

  /**
   * Get all related parameters EXCEPT for auto parameters
   * param_specs are used to determine related pids of auto parameters
   */
  void touch_pids(const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                  std::set<std::size_t> &pids_to_touch) const;

  /** Inner function to get all related parameters */
  virtual void inner_touch_leaf_pids( const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
                                      std::set<std::size_t> &pids_to_touch) const;

  /** Get the operands */
  const std::vector<std::shared_ptr<TreeNode> > &get_oprds() const { return this->oprds_; }

  /** Setting the string value (preserve a copy of the original string representation) */
  virtual const std::string &get_str_value(void) const;

  /** Print the tree node to a given output stream */
  virtual void dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const = 0;

protected:
  std::vector<std::shared_ptr<TreeNode> > oprds_;  /**< The operands */
};
}  // namespace common
}  // namespace ct

#endif // CT_COMMON_TREE_NODE_H_
