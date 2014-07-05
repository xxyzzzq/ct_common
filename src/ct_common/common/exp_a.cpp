#include <ct_common/common/exp_a.h>

using namespace ct::common;

Exp_A::Exp_A(void)
  : Exp(), type_(EAT_INT) {
}

Exp_A::Exp_A(const Exp_A &from)
  : Exp(from), type_(from.type_) {
}

Exp_A &Exp_A::operator = (const Exp_A &right) {
  Exp::operator=(right);
  this->type_ = right.type_;
  return *this;
}

Exp_A::~Exp_A(void) {
}

std::string Exp_A::get_class_name(void) const {
  return Exp_A::class_name();
}

std::string Exp_A::class_name(void) {
  return "Exp_A";
}

EvalType_Double Exp_A::EvaluateDouble( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                              const Assignment &assignment) const {
  if (this->type_ != EAT_DOUBLE) {
    CT_EXCEPTION("warning: implicit casting non-double to double");
  }
  return this->EvaluateDouble_Impl(param_specs, assignment);
}

EvalType_Int Exp_A::EvaluateInt( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const {
  if (this->type_ != EAT_INT) {
    CT_EXCEPTION("warning: implicit casting non-int to int");
  }
  return this->EvaluateInt_Impl(param_specs, assignment);
}
