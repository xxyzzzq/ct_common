//===----- ct_common/common/seed.h ------------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for seeds
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_SEED_H_
#define CT_COMMON_SEED_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/paramspec.h>
#include <ct_common/common/assignment.h>
#include <ct_common/common/eval_type_bool.h>

namespace ct {
namespace common {
const std::size_t SID_BOUND = std::size_t(-1);  /**< Upper bound for seed ids */

/**
 * The class for seeds
 */
class DLL_EXPORT Seed
{
public:
  Seed(std::size_t sid = SID_BOUND, bool is_starter = false);
  Seed(const Seed& from);
  Seed &operator = (const Seed &right);
  virtual ~Seed(void) = 0;

public:
	/** Whether a given assignment matches the seed */
  virtual EvalType_Bool IsMatch(const Assignment &assignment, const std::vector<boost::shared_ptr<ParamSpec> > &paramspecs) = 0;
	/** Getting the seed id */
  std::size_t get_id(void) const { return this->id_; }
	/** Setting the seed id */
  void set_id(std::size_t id) { this->id_ = id; }
	/** Whether the seed is a starter seed */
  bool get_is_starter(void) const { return this->is_starter_; }
	/** Setting the starter flag */
  void set_is_starter(bool is_starter) { this->is_starter_ = is_starter; }
  
private:
  std::size_t id_;  /**< seed id */
  bool is_starter_;  /**< Whether the seed is a starter (for extending covering arrays).
											* During test generation, the starter seeds will be covered by the preceeding test cases */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_SEED_H_
