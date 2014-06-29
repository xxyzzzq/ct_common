#include <cstring>
#include <ct_common/common/constraint_s_eq.h>

using namespace ct::common;

Constraint_S_EQ::Constraint_S_EQ(void)
  : Constraint_S_Binary() {
}

Constraint_S_EQ::Constraint_S_EQ(const Constraint_S_EQ &from)
  : Constraint_S_Binary(from) {
}

Constraint_S_EQ &Constraint_S_EQ::operator = (
    const Constraint_S_EQ &right) {
  Constraint_S_Binary::operator=(right);
  return *this;
}

Constraint_S_EQ::~Constraint_S_EQ(void) {
}

std::string Constraint_S_EQ::get_class_name(void) const {
  return Constraint_S_EQ::class_name();
}

std::string Constraint_S_EQ::class_name(void) {
  return "Constraint_S_EQ";
}

bool Constraint_S_EQ::evaluate_func(const std::string &val_1, const std::string &val_2) const {
  return strcmp(val_1.c_str(), val_2.c_str()) == 0;
}

std::string Constraint_S_EQ::get_op_token(void) const {
  return "==";
}
