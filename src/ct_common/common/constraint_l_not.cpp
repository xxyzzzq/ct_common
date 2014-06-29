#include <ct_common/common/constraint_l_not.h>

using namespace ct::common;

Constraint_L_Not::Constraint_L_Not(void)
  : Constraint_L_Unary() {
}

Constraint_L_Not::Constraint_L_Not(const Constraint_L_Not &from)
  : Constraint_L_Unary(from) {
}

Constraint_L_Not &Constraint_L_Not::operator = (
    const Constraint_L_Not &right) {
  Constraint_L_Unary::operator=(right);
  return *this;
}

Constraint_L_Not::~Constraint_L_Not(void) {
}

std::string Constraint_L_Not::get_class_name(void) const {
  return Constraint_L_Not::class_name();
}

std::string Constraint_L_Not::class_name(void) {
  return "Constraint_L_Not";
}

bool Constraint_L_Not::evaluate_func(bool val) const {
  return !val;
}

std::string Constraint_L_Not::get_op_token(void) const {
  return "!";
}
