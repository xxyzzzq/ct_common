#include <ct_common/common/exp_a_term.h>

using namespace ct::common;

Exp_A_Term::Exp_A_Term(void)
  : Exp_A() {
}

Exp_A_Term::Exp_A_Term(const Exp_A_Term &from)
  : Exp_A(from) {
}

Exp_A_Term& Exp_A_Term::operator = (const Exp_A_Term &right) {
  Exp_A::operator=(right);
  return *this;
}

Exp_A_Term::~Exp_A_Term(void) {
}

std::string Exp_A_Term::get_class_name(void) const {
  return Exp_A_Term::class_name();
}

std::string Exp_A_Term::class_name(void) {
  return "Exp_A_Term";
}
