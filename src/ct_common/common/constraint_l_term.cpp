#include <ct_common/common/constraint_l_term.h>

using namespace ct::common;

Constraint_L_Term::Constraint_L_Term(void)
    : Constraint_L() {
}

Constraint_L_Term::Constraint_L_Term(const Constraint_L_Term &from)
    : Constraint_L(from) {
}

Constraint_L_Term::~Constraint_L_Term(void) {
}

Constraint_L_Term &Constraint_L_Term::operator = (const Constraint_L_Term &right) {
  Constraint_L::operator =(right);
  return *this;
}

std::string Constraint_L_Term::get_class_name(void) const {
  return Constraint_L_Term::class_name();
}

std::string Constraint_L_Term::class_name(void) {
  return "Constraint_L_Term";
}
