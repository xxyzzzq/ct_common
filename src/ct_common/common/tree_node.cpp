// Copyright 2016 ct_common authors. See LICENSE file for details.

#include "ct_common/common/tree_node.h"

#include <map>
#include <stack>
#include <utility>

#include "ct_common/base/arithmetic_utils.h"

namespace ct_common {

REGISTER_CLASS_NAME(TreeNode)

TreeNode::TreeNode() = default;

TreeNode::~TreeNode() = default;

const std::string& TreeNode::get_str_value() const {
  static std::string empty_string;
  return empty_string;
}

void TreeNode::touch_pids(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    std::set<std::size_t>* pids_to_touch) const {
  std::stack<std::pair<const TreeNode*, std::size_t> > s;
  s.push(std::pair<const TreeNode*, std::size_t>(this, 0));
  while (!s.empty()) {
    if (s.top().first == 0) {
      CT_EXCEPTION("empty constraint encountered");
      s.pop();
      ++s.top().second;
    }
    if (s.top().second >= s.top().first->oprds_.size()) {
      s.top().first->inner_touch_leaf_pids(param_specs, pids_to_touch);
      s.pop();
      if (!s.empty()) {
        ++s.top().second;
      }
      continue;
    }
    const TreeNode* next = s.top().first->oprds_[s.top().second].get();
    s.push(std::pair<const TreeNode*, std::size_t>(next, 0));
  }
}

void TreeNode::inner_touch_leaf_pids(
    const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
    std::set<std::size_t>* pids_to_touch) const {}

}  // namespace ct_common
