#include <ct_common/common/exp_s_term.h>

using namespace ct::common;

Exp_S_Term::Exp_S_Term(void)
  : Exp_S() {
}

Exp_S_Term::Exp_S_Term(const Exp_S_Term &from)
  : Exp_S(from) {
}

Exp_S_Term& Exp_S_Term::operator = (const Exp_S_Term &right) {
  Exp_S::operator=(right);
  return *this;
}

Exp_S_Term::~Exp_S_Term(void) {
}

std::string Exp_S_Term::get_class_name(void) const {
  return Exp_S_Term::class_name();
}

std::string Exp_S_Term::class_name(void) {
  return "Exp_S_Term";
}
