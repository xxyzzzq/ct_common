//===----- ct_common/common/constraint.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Constraint
//
//===----------------------------------------------------------------------===//

#include <ct_common/common/constraint.h>

using namespace ct::common;

Constraint::Constraint(void)
    : TreeNode() {
}

Constraint::Constraint(const Constraint &from)
    : TreeNode(from) {
}

Constraint &Constraint::operator = (const Constraint &right) {
  TreeNode::operator = (right);
  return *this;
}

Constraint::~Constraint(void) {
}

std::string Constraint::get_class_name(void) const {
  return Constraint::class_name();
}

std::string Constraint::class_name(void) {
  return "Constraint";
}

EvalType_Bool Constraint::Evaluate(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                          const Assignment &assignment) const {
  return EvalType_Bool(false, false);
}
