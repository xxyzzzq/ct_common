#include "seed_constraint.h"

using namespace ct::common;

Seed_Constraint::Seed_Constraint(void)
    : constraint_() {
}

Seed_Constraint::Seed_Constraint(const Seed_Constraint &from)
    : constraint_(from.constraint_) {
}

Seed_Constraint::~Seed_Constraint(void) {
}

Seed_Constraint &Seed_Constraint::operator =(const ct::common::Seed_Constraint &right) {
  this->constraint_ = right.constraint_;
  return *this;
}

EvalType_Bool Seed_Constraint::IsMatch(const Assignment &assignment, const std::vector<boost::shared_ptr<ParamSpec> > &paramspecs) {
  return this->constraint_->Evaluate(paramspecs, assignment);
}
