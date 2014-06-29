#include <ct_common/common/constraint_l_imply.h>

using namespace ct::common;

Constraint_L_Imply::Constraint_L_Imply(void)
  : Constraint_L_Binary() {
}

Constraint_L_Imply::Constraint_L_Imply(const Constraint_L_Imply &from)
  : Constraint_L_Binary(from) {
}

Constraint_L_Imply &Constraint_L_Imply::operator = (
    const Constraint_L_Imply &right) {
  Constraint_L_Binary::operator=(right);
  return *this;
}

Constraint_L_Imply::~Constraint_L_Imply(void) {
}

std::string Constraint_L_Imply::get_class_name(void) const {
  return Constraint_L_Imply::class_name();
}

std::string Constraint_L_Imply::class_name(void) {
  return "Constraint_L_Imply";
}

EvalType_Bool Constraint_L_Imply::evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const {
  EvalType_Bool tmp_return;
  if (!val_l.is_valid_ || !val_l.value_) {
    tmp_return.value_ = true;
    tmp_return.is_valid_ = true;
  } else {
    tmp_return.is_valid_ = val_r.is_valid_;
    tmp_return.value_ = val_r.value_;
  }
  return tmp_return;
}

std::string Constraint_L_Imply::get_op_token(void) const {
  return "->";
}
