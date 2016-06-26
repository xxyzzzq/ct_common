//===----- ct_common/common/exp_a_cast.cpp ----------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the function definitions of class Exp_A_Cast
//
//===----------------------------------------------------------------------===//

#include "ct_common/common/exp_a_cast.h"

using namespace ct::common;

Exp_A_Cast::Exp_A_Cast(void)
  : Exp_A_Unary() {
}

Exp_A_Cast::Exp_A_Cast(const Exp_A_Cast &from)
  : Exp_A_Unary(from) {
}

Exp_A_Cast& Exp_A_Cast::operator = (const Exp_A_Cast &right) {
  Exp_A_Unary::operator=(right);
  return *this;
}

Exp_A_Cast::~Exp_A_Cast(void) {
}

std::string Exp_A_Cast::get_class_name(void) const {
  return Exp_A_Cast::class_name();
}

std::string Exp_A_Cast::class_name(void) {
  return "Exp_A_Cast";
}

double Exp_A_Cast::evaluate_double(double val) const {
  return val;
}

int Exp_A_Cast::evaluate_int(int val) const {
  return val;
}

std::string Exp_A_Cast::get_op_token(void) const {
  switch (this->type_) {
  case EAT_INT:
    return "int";
    break;
  case EAT_DOUBLE:
    return "double";
    break;
  default:
    CT_EXCEPTION("unknown cast type");
    break;
  }
  return "";
}


void Exp_A_Cast::dump(std::ostream &os, const std::vector<std::shared_ptr<ParamSpec> > &param_specs) const {
  os << this->get_op_token();
  os << "(";
  this->get_oprd()->dump(os, param_specs);
  os << ")";
}
