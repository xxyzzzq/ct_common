//===----- ct_common/common/tuple.h -----------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for tuples
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_TUPLE_H_
#define CT_COMMON_TUPLE_H_

#include <vector>
#include <memory>
#include <ct_common/common/utils.h>
#include <ct_common/common/pvpair.h>
#include <ct_common/common/assignment.h>

namespace ct {
namespace common {
class ParamSpec;
/**
 * The class for tuples
 */
class DLL_EXPORT Tuple : public Assignment, private std::vector<PVPair>
{
private:
  typedef std::vector<PVPair> impl_type;
public:
  Tuple(void);
  Tuple(const Tuple &from);
  explicit Tuple(const std::vector<PVPair> &from);
  Tuple &operator =(const Tuple &right);
  ~Tuple(void);

  virtual bool IsContainParam(std::size_t pid) const;
  virtual std::size_t GetValue(std::size_t pid) const;
  virtual bool IsSubAssignmentOf(const Assignment &asignment) const;

  /** Get the set of related pids */
  std::vector<std::size_t> get_rel_pids(void) const;

  /** Sort the pvpairs */
  void Sort(void);

  /** Search for the PVPair for a given pid. The tuple need to be sorted in advance.
   * The returned pointer is weak and should not be deleted. */
  const PVPair *Search(std::size_t pid) const;

  /** For iterating tuples. Go to the next tuple, returns false if overflows */
  bool to_the_next_tuple(
      std::vector<std::shared_ptr<ct::common::ParamSpec> > param_specs);
  /** For iterating tuples. Go to the next tuple (considering invalid values), returns false if overflows */
  bool to_the_next_tuple_with_ivld(
      std::vector<std::shared_ptr<ct::common::ParamSpec> > param_specs);

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
  using impl_type::operator [];
  bool operator == (const Tuple &right) const;
  bool operator <(const Tuple &right) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_TUPLE_H_
