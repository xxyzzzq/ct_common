//===----- ct_common/common/treenode.cpp ------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class TreeNode
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/tree_node.h"

#include <map>
#include <stack>

#include "ct_common/base/arithmetic_utils.h"

using namespace ct::common;

TreeNode::TreeNode(void) : oprds_() {}

TreeNode::TreeNode(const TreeNode &from) : oprds_(from.oprds_) {}

TreeNode::~TreeNode(void) {
  std::stack<std::pair<TreeNode *, std::size_t> > s;
  s.push(std::pair<TreeNode *, std::size_t>(const_cast<TreeNode *>(this), 0));
  while (!s.empty()) {
    if (s.top().first == 0) {
      s.pop();
      ++s.top().second;
    }
    if (s.top().second >= s.top().first->oprds_.size()) {
      s.top().first->oprds_.clear();
      s.pop();
      if (!s.empty()) {
        ++s.top().second;
      }
      continue;
    }
    TreeNode *next = s.top().first->oprds_[s.top().second].get();
    s.push(std::pair<TreeNode *, std::size_t>(next, 0));
  }
}

TreeNode &TreeNode::operator=(const TreeNode &right) {
  this->oprds_ = right.oprds_;
  return *this;
}

std::string TreeNode::get_class_name(void) const {
  return TreeNode::class_name();
}

std::string TreeNode::class_name(void) { return "TreeNode"; }

const std::string &TreeNode::get_str_value(void) const {
  static std::string empty_string;
  return empty_string;
}

void TreeNode::touch_pids(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    std::set<std::size_t> &pids_to_touch) const {
  std::stack<std::pair<const TreeNode *, std::size_t> > s;
  s.push(std::pair<const TreeNode *, std::size_t>(this, 0));
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
    const TreeNode *next = s.top().first->oprds_[s.top().second].get();
    s.push(std::pair<const TreeNode *, std::size_t>(next, 0));
  }
}

void TreeNode::inner_touch_leaf_pids(
    const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
    std::set<std::size_t> &pids_to_touch) const {}
