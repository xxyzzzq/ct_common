//===----- ct_common/common/exp_s.h -----------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for string expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_S_H_
#define CT_COMMON_EXP_S_H_

#include <string>
#include <ct_common/common/utils.h>
#include <ct_common/common/exp.h>
#include <ct_common/common/paramspec.h>
#include <boost/shared_ptr.hpp>
#include <ct_common/common/eval_type_string.h>

namespace ct {
namespace common {
/**
 * The base class for string expressions
 */
class DLL_EXPORT Exp_S : public Exp {
public:
  Exp_S(void);
  Exp_S(const Exp_S &from);
  Exp_S &operator = (const Exp_S &right);
  virtual ~Exp_S(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

public:
  /** Function for evaluating the expression */
  virtual EvalType_String Evaluate( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                    const Assignment &assignment) const = 0;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_H_
