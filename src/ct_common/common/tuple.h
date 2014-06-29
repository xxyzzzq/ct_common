#ifndef CT_COMMON_TUPLE_H_
#define CT_COMMON_TUPLE_H_

#include <vector>
#include <boost/shared_ptr.hpp>
#include <ct_common/common/utils.h>
#include <ct_common/common/pvpair.h>
#include <ct_common/common/assignment.h>

namespace ct {
namespace common {
class ParamSpec;

class DLL_EXPORT Tuple : public Assignment, private std::vector<PVPair>
{
public:
  Tuple(void);
  Tuple(const Tuple &from);
  explicit Tuple(const std::vector<PVPair> &from);
  Tuple &operator =(const Tuple &right);
  ~Tuple(void);

  virtual bool IsContainParam(std::size_t pid) const;
  virtual std::size_t GetValue(std::size_t pid) const;
  virtual bool IsSubAssignmentOf(const Assignment &asignment) const;

  std::vector<std::size_t> get_rel_pids(void) const;

  void Sort(void);  // Sort the PVPair's

  const PVPair *Search(std::size_t pid) const;  // the tuple need to be sorted in advance
                                        // the returned pointer is weak
                                        // invalid after the tuple is destroyed

  // go to the next tuple, returns false if overflows
  bool to_the_next_tuple(
      std::vector<boost::shared_ptr<ct::common::ParamSpec> > param_specs);

  bool to_the_next_tuple_with_ivld(
      std::vector<boost::shared_ptr<ct::common::ParamSpec> > param_specs);

  using std::vector<PVPair>::push_back;
  using std::vector<PVPair>::pop_back;
  using std::vector<PVPair>::size;
  using std::vector<PVPair>::empty;
  using std::vector<PVPair>::operator [];
  bool operator == (const Tuple &right) const;
  bool operator <(const Tuple &right) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TUPLE_H_
