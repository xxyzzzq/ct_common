#include <ct_common/common/seed_tuple.h>

using namespace ct::common;

Seed_Tuple::Seed_Tuple(void)
    : tuple_() {
}

Seed_Tuple::Seed_Tuple(const Seed_Tuple &from)
    : tuple_(from.tuple_) {
}

Seed_Tuple::~Seed_Tuple(void) {
}

Seed_Tuple &Seed_Tuple::operator =(const ct::common::Seed_Tuple &right) {
  this->tuple_ = right.tuple_;
  return *this;
}

EvalType_Bool Seed_Tuple::IsMatch(const Assignment &assignment, const std::vector<boost::shared_ptr<ParamSpec> > &paramspecs) {
  return EvalType_Bool(this->tuple_.IsSubAssignmentOf(assignment), true);
}
