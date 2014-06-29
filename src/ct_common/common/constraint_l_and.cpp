#include <ct_common/common/constraint_l_and.h>

using namespace ct::common;

Constraint_L_And::Constraint_L_And(void)
  : Constraint_L_Binary() {
}

Constraint_L_And::Constraint_L_And(const Constraint_L_And &from)
  : Constraint_L_Binary(from) {
}

Constraint_L_And &Constraint_L_And::operator = (
    const Constraint_L_And &right) {
  Constraint_L_Binary::operator=(right);
  return *this;
}

Constraint_L_And::~Constraint_L_And(void) {
}

std::string Constraint_L_And::get_class_name(void) const {
  return Constraint_L_And::class_name();
}

std::string Constraint_L_And::class_name(void) {
  return "Constraint_L_And";
}

EvalType_Bool Constraint_L_And::evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const {
  EvalType_Bool tmp_return;
  tmp_return.is_valid_ = val_l.is_valid_ && val_r.is_valid_;
  if (tmp_return.is_valid_) {
    tmp_return.value_ = val_l.value_ && val_r.value_;
  }
  return tmp_return;;
}

std::string Constraint_L_And::get_op_token(void) const {
  return "&&";
}
