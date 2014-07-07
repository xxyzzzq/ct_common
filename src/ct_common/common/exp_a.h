//===----- ct_common/common/exp_a.h -----------------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the base class for arithmetic expressions
//
//===----------------------------------------------------------------------===//

#ifndef CT_COMMON_EXP_A_H_
#define CT_COMMON_EXP_A_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp.h>
#include <ct_common/common/paramspec.h>
#include <boost/shared_ptr.hpp>
#include <ct_common/common/eval_type_int.h>
#include <ct_common/common/eval_type_double.h>
#include <ct_common/common/assignment.h>

namespace ct {
namespace common {
enum eEXP_A_TYPE {
  EAT_INT,
  EAT_DOUBLE,
};

#define GET_EXP_VAL(type, identifier, exp, param_specs, assignment) \
  type identifier; \
  switch (exp->get_type()) { \
  case EAT_INT: \
    identifier = exp->EvaluateInt(param_specs, assignment); \
    break; \
  case EAT_DOUBLE: \
    identifier = exp->EvaluateDouble(param_specs, assignment); \
    break; \
  default: \
    CT_EXCEPTION("unrecognized expression type when evaluating"); \
  }


class DLL_EXPORT Exp_A : public Exp {
public:
  Exp_A(void);
  Exp_A(const Exp_A &from);
  Exp_A &operator = (const Exp_A &right);
  virtual ~Exp_A(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

public:
  // type check is here!!!
  EvalType_Double EvaluateDouble(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;
  EvalType_Int EvaluateInt(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                        const Assignment &assignment) const;

  eEXP_A_TYPE get_type(void) const { return this->type_; }
  void set_type(eEXP_A_TYPE type) { this->type_ = type; }
  
private:
  // no type checking here, just return the desired value!!!
  virtual EvalType_Double EvaluateDouble_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                      const Assignment &assignment) const = 0;

  virtual EvalType_Int EvaluateInt_Impl( const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
                                const Assignment &assignment) const = 0;

protected:
  eEXP_A_TYPE type_;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_H_
