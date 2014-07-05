#include <ct_common/common/eval_type_bool.h>

using namespace ct::common;

EvalType_Bool::EvalType_Bool(void)
  : EvalType() {
  this->value_ = false;
}

EvalType_Bool::EvalType_Bool(bool value, bool is_valid)
  : EvalType(is_valid) {
  this->value_ = value;
}

EvalType_Bool::EvalType_Bool(const EvalType_Bool &from)
  : EvalType(from) {
  this->value_ = from.value_;
}

EvalType_Bool::~EvalType_Bool(void) {
}

EvalType_Bool &EvalType_Bool::operator =(const EvalType_Bool &right) {
  EvalType::operator =(right);
  this->value_ = right.value_;
  return *this;
}
