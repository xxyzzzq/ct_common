// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_COMMON_SUT_MODEL_H_
#define CT_COMMON_COMMON_SUT_MODEL_H_

#include <memory>
#include <vector>

#include "ct_common/common/constraint.h"
#include "ct_common/common/paramspec.h"
#include "ct_common/common/pvpair.h"
#include "ct_common/common/seed.h"
#include "ct_common/common/strength.h"
#include "ct_common/common/tuple.h"

namespace ct_common {

// The class for SUT models
struct SUTModel {
  std::vector<std::shared_ptr<ParamSpec> >
  param_specs;                 /**< The parameter specifications */
  std::vector<Strength> strengths; /**< The strengths */
  std::vector<std::shared_ptr<Seed> > seeds; /**< The seeds */
  std::vector<std::shared_ptr<Constraint> >
  constraints; /**< The constraints */
};

}  // namespace ct_common

#endif  // CT_COMMON_COMMON_SUT_MODEL_H_
