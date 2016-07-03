// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_SEED_H_
#define CT_COMMON_COMMON_SEED_H_

#include <vector>

#include "ct_common/base/optional.h"
#include "ct_common/base/utils.h"
#include "ct_common/common/assignment.h"
#include "ct_common/common/paramspec.h"

namespace ct_common {

// Upper bound for seed ids.
const std::size_t SID_BOUND = std::size_t(-1);

// The base Seed class. Used for cover specific combination/condition.
class DLL_EXPORT Seed {
 public:
  explicit Seed(std::size_t sid = SID_BOUND, bool is_starter = false);
  Seed(const Seed& from);
  Seed& operator=(const Seed& right);
  virtual ~Seed() = 0;

 public:
  /** Whether a given assignment matches the seed */
  virtual optional<bool> IsMatch(
      const Assignment& assignment,
      const std::vector<std::shared_ptr<ParamSpec> >& paramspecs) = 0;
  /** Getting the seed id */
  std::size_t get_id() const { return id_; }
  /** Setting the seed id */
  void set_id(std::size_t id) { id_ = id; }
  /** Whether the seed is a starter seed */
  bool get_is_starter() const { return is_starter_; }
  /** Setting the starter flag */
  void set_is_starter(bool is_starter) { is_starter_ = is_starter; }

 private:
  // Unique id for the seed.
  std::size_t id_;
  // Whether the seed is a starter (for extending covering arrays). During test
  // generation, the starter seeds will be covered by the preceeding test cases.
  bool is_starter_;
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_SEED_H_
