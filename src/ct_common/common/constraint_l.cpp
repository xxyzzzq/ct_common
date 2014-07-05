#include <ct_common/common/constraint_l.h>

using namespace ct::common;

Constraint_L::Constraint_L(void)
  : Constraint() {
}

Constraint_L::Constraint_L(const Constraint_L &from)
  : Constraint(from) {
}

Constraint_L &Constraint_L::operator = (const Constraint_L &right) {
  Constraint::operator=(right);
  return *this;
}

Constraint_L::~Constraint_L(void) {
}

std::string Constraint_L::get_class_name(void) const {
  return Constraint_L::class_name();
}

std::string Constraint_L::class_name(void) {
  return "Constraint_L";
}
