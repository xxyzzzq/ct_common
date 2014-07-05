#include <ct_common/common/eval_type_double.h>
#include <ct_common/common/eval_type_int.h>

using namespace ct::common;

EvalType_Double::EvalType_Double(void)
  : EvalType(), value_(0) {
}

EvalType_Double::EvalType_Double(double value, bool is_valid)
  : EvalType(is_valid), value_(value) {
}

EvalType_Double::EvalType_Double(const EvalType_Double &from)
  : EvalType(from), value_(from.value_) {
}

EvalType_Double::EvalType_Double(const EvalType_Int &from)
  : EvalType(from), value_(from.value_) {
}

EvalType_Double::~EvalType_Double(void) {
}

EvalType_Double &EvalType_Double::operator =(const EvalType_Double &right) {
  EvalType::operator =(right);
  this->value_ = right.value_;
  return *this;
}

EvalType_Double &EvalType_Double::operator =(const EvalType_Int &right) {
  EvalType::operator =(right);
  this->value_ = right.value_;
  return *this;
}
