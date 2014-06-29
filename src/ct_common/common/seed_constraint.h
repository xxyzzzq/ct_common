#ifndef CT_COMMON_SEED_CONSTRAINT_H_
#define CT_COMMON_SEED_CONSTRAINT_H_

#include <ct_common/common/seed.h>
#include <ct_common/common/constraint.h>

namespace ct {
namespace common {
class DLL_EXPORT Seed_Constraint : public Seed
{
public:
  Seed_Constraint(void);
  Seed_Constraint(const Seed_Constraint&);
  Seed_Constraint &operator = (const Seed_Constraint &right);
  virtual ~Seed_Constraint(void);
  
public:
  const boost::shared_ptr<Constraint> &get_constraint(void) const { return this->constraint_; }
  boost::shared_ptr<Constraint> &the_constraint(void) { return this->constraint_; }
  virtual EvalType_Bool IsMatch(const Assignment &assignment, const std::vector<boost::shared_ptr<ParamSpec> > &paramspecs);
  
private:
  boost::shared_ptr<Constraint> constraint_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_SEED_CONSTRAINT_H_
