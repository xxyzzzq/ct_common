// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_TUPLE_H_
#define CT_COMMON_COMMON_TUPLE_H_

#include <memory>
#include <vector>

#include "ct_common/base/utils.h"
#include "ct_common/common/assignment.h"
#include "ct_common/common/pvpair.h"

namespace ct_common {

class ParamSpec;

// The class for tuples.
class DLL_EXPORT Tuple : public Assignment, private std::vector<PVPair> {
 private:
  typedef std::vector<PVPair> impl_type;

 public:
  Tuple();
  Tuple(const Tuple& from);
  explicit Tuple(const std::vector<PVPair>& from);
  Tuple& operator=(const Tuple& right);
  ~Tuple() override;

  bool IsContainParam(std::size_t pid) const override;
  std::size_t GetValue(std::size_t pid) const override;
  bool IsSubAssignmentOf(const Assignment& asignment) const override;

  /** Get the set of related pids */
  std::vector<std::size_t> get_rel_pids() const;

  /** Sort the pvpairs */
  void Sort();

  /** Search for the PVPair for a given pid. The tuple need to be sorted in
   * advance.
   * The returned pointer is weak and should not be deleted. */
  const PVPair* Search(std::size_t pid) const;

  /** For iterating tuples. Go to the next tuple, returns false if overflows */
  bool ToTheNextTuple(
      std::vector<std::shared_ptr<ParamSpec> > param_specs);
  /** For iterating tuples. Go to the next tuple (considering invalid values),
   * returns false if overflows */
  bool ToTheNextTupleWithIvld(
      std::vector<std::shared_ptr<ParamSpec> > param_specs);

  using impl_type::iterator;
  using impl_type::const_iterator;
  using impl_type::begin;
  using impl_type::rbegin;
  using impl_type::end;
  using impl_type::rend;
  using impl_type::assign;
  using impl_type::push_back;
  using impl_type::pop_back;
  using impl_type::resize;
  using impl_type::clear;
  using impl_type::size;
  using impl_type::empty;
  using impl_type::operator[];
  bool operator==(const Tuple& right) const;
  bool operator<(const Tuple& right) const;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_TUPLE_H_
