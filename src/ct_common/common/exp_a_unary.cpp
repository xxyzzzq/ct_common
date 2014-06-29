#include <ct_common/common/exp_a_unary.h>

using namespace ct::common;

Exp_A_Unary::Exp_A_Unary(void)
    : Exp_A() {
  this->oprds_.resize(1);
}

Exp_A_Unary::Exp_A_Unary(const Exp_A_Unary &from)
  : Exp_A(from) {
}

Exp_A_Unary &Exp_A_Unary::operator = (const Exp_A_Unary &right) {
  Exp_A::operator=(right);
  return *this;
}

Exp_A_Unary::~Exp_A_Unary(void) {
}

std::string Exp_A_Unary::get_class_name(void) const {
  return Exp_A_Unary::class_name();
}

std::string Exp_A_Unary::class_name(void) {
  return "Exp_A_Unary";
}

EvalType_Double Exp_A_Unary::EvaluateDouble_Impl(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const {
  GET_EXP_VAL(EvalType_Double, oprd_val, this->get_oprd(), param_specs, assignment);
  if (oprd_val.is_valid_) {
    oprd_val.value_ = this->evaluate_double(oprd_val.value_);
  }
  return oprd_val;
}

EvalType_Int Exp_A_Unary::EvaluateInt_Impl(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const {
  GET_EXP_VAL(EvalType_Int, oprd_val, this->get_oprd(), param_specs, assignment);
  if (oprd_val.is_valid_) {
    oprd_val.value_ = this->evaluate_int(oprd_val.value_);
  }
  return oprd_val;
}

void Exp_A_Unary::dump(std::ostream &os, const std::vector<boost::shared_ptr<ParamSpec> > &param_specs) const {
  os << this->get_op_token();
  this->get_oprd()->dump(os, param_specs);
}
