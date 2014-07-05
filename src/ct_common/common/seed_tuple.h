#ifndef CT_COMMON_SEED_TUPLE_H_
#define CT_COMMON_SEED_TUPLE_H_

#include <ct_common/common/seed.h>
#include <ct_common/common/tuple.h>

namespace ct {
namespace common {
class DLL_EXPORT Seed_Tuple : public Seed
{
public:
  Seed_Tuple(void);
  Seed_Tuple(const Seed_Tuple&);
  Seed_Tuple &operator = (const Seed_Tuple &right);
  virtual ~Seed_Tuple(void);
  
public:
  const Tuple &get_tuple(void) const { return this->tuple_; }
  Tuple &the_tuple(void) { return this->tuple_; }
  virtual EvalType_Bool IsMatch(const Assignment &assignment, const std::vector<boost::shared_ptr<ParamSpec> > &paramspecs);
  
private:
  Tuple tuple_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_SEED_TUPLE_H_
