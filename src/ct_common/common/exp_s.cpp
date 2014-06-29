#include <ct_common/common/exp_s.h>

using namespace ct::common;

Exp_S::Exp_S(void)
  : Exp() {
}

Exp_S::Exp_S(const Exp_S &from)
  : Exp(from) {
}

Exp_S& Exp_S::operator = (const Exp_S &right) {
  Exp::operator=(right);
  return *this;
}

Exp_S::~Exp_S(void) {
}

std::string Exp_S::get_class_name(void) const {
  return Exp_S::class_name();
}

std::string Exp_S::class_name(void) {
  return "Exp_S";
}
