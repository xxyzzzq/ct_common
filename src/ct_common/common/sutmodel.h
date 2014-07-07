//===----- ct_common/common/sutmodel.h --------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the struct for SUT models
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_SUTMODEL_H_
#define CT_COMMON_SUTMODEL_H_

#include <ct_common/common/paramspec.h>
#include <ct_common/common/pvpair.h>
#include <ct_common/common/tuple.h>
#include <ct_common/common/seed.h>
#include <ct_common/common/constraint.h>
#include <ct_common/common/strength.h>
#include <boost/shared_ptr.hpp>

namespace ct {
namespace common {
/**
 * The class for SUT models
 */
struct SUTModel {
  std::vector<boost::shared_ptr<ParamSpec> > param_specs_;  /**< The parameter specifications */
  std::vector<Strength> strengths_;  /**< The strengths */
  std::vector<boost::shared_ptr<Seed> > seeds_;  /**< The seeds */
  std::vector<boost::shared_ptr<Constraint> > constraints_;  /**< The constraints */
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_SUTMODEL_H_
