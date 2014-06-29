#ifndef CT_COMMON_SEED_H_
#define CT_COMMON_SEED_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>
#include <ct_common/common/assignment.h>
#include <ct_common/common/eval_type_bool.h>

namespace ct {
namespace common {
const std::size_t SID_BOUND = std::size_t(-1);
class DLL_EXPORT Seed
{
public:
  Seed(std::size_t sid = SID_BOUND, bool is_starter = false);
  Seed(const Seed&);
  Seed &operator = (const Seed &right);
  virtual ~Seed(void) = 0;

public:
  virtual EvalType_Bool IsMatch(const Assignment &assignment, const std::vector<boost::shared_ptr<ParamSpec> > &paramspecs) = 0;
  std::size_t get_id(void) const { return this->id_; }
  void set_id(std::size_t id) { this->id_ = id; }
  bool get_is_starter(void) const { return this->is_starter_; }
  void set_is_starter(bool is_starter) { this->is_starter_ = is_starter; }
  
private:
  std::size_t id_;
  bool is_starter_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_SEED_H_
