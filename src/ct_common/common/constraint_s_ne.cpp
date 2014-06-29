#include <cstring>
#include <ct_common/common/constraint_s_ne.h>

using namespace ct::common;

Constraint_S_NE::Constraint_S_NE(void)
  : Constraint_S_Binary() {
}

Constraint_S_NE::Constraint_S_NE(const Constraint_S_NE &from)
  : Constraint_S_Binary(from) {
}

Constraint_S_NE &Constraint_S_NE::operator = (
    const Constraint_S_NE &right) {
  Constraint_S_Binary::operator=(right);
  return *this;
}

Constraint_S_NE::~Constraint_S_NE(void) {
}

std::string Constraint_S_NE::get_class_name(void) const {
  return Constraint_S_NE::class_name();
}

std::string Constraint_S_NE::class_name(void) {
  return "Constraint_S_NE";
}

bool Constraint_S_NE::evaluate_func(const std::string &val_1, const std::string &val_2) const {
  return strcmp(val_1.c_str(), val_2.c_str()) != 0;
}

std::string Constraint_S_NE::get_op_token(void) const {
  return "!=";
}
