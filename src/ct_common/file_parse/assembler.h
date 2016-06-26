//===----- ct_common/file_parse/assembler.h ---------------------*- C++ -*-===//
//
//                      The ct_common Library
//
// This file is distributed under the MIT license. See LICENSE for details.
//
//===----------------------------------------------------------------------===//
//
// This header file contains the class for assembling elements of the SUT model
//
//===----------------------------------------------------------------------===//

#ifndef ASSEMBLER_H_
#define ASSEMBLER_H_

#include <cstdlib>
#include <string>
#include <vector>

#include "ct_common/common/constraints.h"
#include "ct_common/common/exps.h"
#include "ct_common/common/paramspecs.h"
#include "ct_common/common/pvpair.h"
#include "ct_common/common/seed.h"
#include "ct_common/common/strength.h"
#include "ct_common/file_parse/err_logger.h"

namespace ct {
namespace common {
/**
 * Operators in constraints and expressions
 */
enum eOPERATOR {
  OP_ADD,
  OP_SUB,
  OP_MULT,
  OP_DIV,
  OP_MOD,
  OP_NEG,
  OP_UPLUS,
  OP_EQ,
  OP_NE,
  OP_GT,
  OP_GE,
  OP_LT,
  OP_LE,
  OP_AND,
  OP_OR,
  OP_XOR,
  OP_IMPLY,
  OP_IFF,
  OP_NOT,
};

/**
 * The class for assembling elements of the SUT model
 */
class Assembler {
 public:
  Assembler(void);
  Assembler(const Assembler &from);
  ~Assembler(void);
  const Assembler &operator=(const Assembler &right);

  /** Setting the error logger */
  void setErrLogger(const std::shared_ptr<ErrLogger> &err_logger) {
    this->err_logger_ = err_logger;
  }
  /** Getting the error logger */
  const std::shared_ptr<ErrLogger> &get_err_logger(void) {
    return this->err_logger_;
  }

  /** Report an error */
  void reportError(const std::string &str);
  /** Report a warning */
  void reportWarning(const std::string &str);
  /** Get the total number of errors */
  std::size_t numErrs(void) const;
  /** Get the total number of warnings */
  std::size_t numWarnings(void) const;

 public:
  /** Assemble a parameter specification */
  ParamSpec *asm_paramspec(const std::string &type,
                           const std::string &identifier,
                           const std::vector<std::shared_ptr<TreeNode> > &vals);

  /** Assemble an automatic parameter specification */
  ParamSpec *asm_paramspec(
      const std::string &type, const std::string &identifier,
      const std::vector<
          std::pair<std::shared_ptr<TreeNode>, std::shared_ptr<TreeNode> > >
          &auto_value_specs);

  /** Assemble a covering strength */
  void attach_strengths(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const std::vector<std::string> &identifiers,
      std::vector<Strength> &strengths, std::size_t strength);

  /** Assemble a universal covering strength */
  void attach_default_strengths(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      std::vector<Strength> &strengths, std::size_t strength);

  /** Assemble a pvpair */
  PVPair *asm_pvpair(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const std::string &identifier, const TreeNode *value_exp);

  /** Assemble a string constraint */
  Constraint_S *asm_constraint_s(Exp_S *oprd1, Exp_S *oprd2, eOPERATOR op);
  /** Assemble an arithematic constraint */
  Constraint_A *asm_constraint_a(Exp_A *oprd1, Exp_A *oprd2, eOPERATOR op,
                                 double precision);
  /** Assemble an arithmatic/string/logical constraint */
  Constraint *asm_constraint_asb(TreeNode *oprd1, TreeNode *oprd2, eOPERATOR op,
                                 const std::string &str);
  /** Assemble a binary logical constraint */
  Constraint_L *asm_constraint_l(TreeNode *oprd1, TreeNode *oprd2,
                                 eOPERATOR op);
  /** Assemble a unary logical constraint */
  Constraint_L *asm_constraint_l(TreeNode *oprd, eOPERATOR op);
  /** Assemble a constant Boolean constraint */
  Constraint_L_CBool *asm_constraint_l_cbool(const std::string &val);
  /** Assemble a parameter invalidation atomic constraint (in the
   * post-processing stage) */
  Constraint *asm_constraint_invalid(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const std::string &identifier);
  /** Assemble a parameter constraint/expression */
  TreeNode *asm_param(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const std::string &identifier);

  /** Assemble a binary expression */
  Exp_A *asm_exp_a(TreeNode *oprd1, TreeNode *oprd2, eOPERATOR op);
  /** Assemble a unary expression */
  Exp_A *asm_exp_a(TreeNode *oprd, eOPERATOR op);
  /** Assemble a cast expresion */
  Exp_A *asm_exp_a_cast(TreeNode *oprd, const std::string &type);

  /** Store the parameter invalidation constraint for later post-processing */
  void store_invalidation(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs,
      const std::vector<std::string> &identifiers,
      const std::shared_ptr<TreeNode> &precond);
  /** Post-processing parameter invalidation constraints */
  std::vector<std::shared_ptr<Constraint> > dump_invalidations(
      const std::vector<std::shared_ptr<ParamSpec> > &param_specs);

  /** Assemble a tuple seed */
  ct::common::Seed *asm_seed(std::size_t id, const ct::common::Tuple &tuple);
  /** Assemble a constraint seed */
  ct::common::Seed *asm_seed(std::size_t id, ct::common::Constraint *constr);

  /** Setting an option */
  void set_option(const std::string &identifier,
                  const ct::common::TreeNode *value);

 private:
  /** Geting the conjunction of a set of constraints */
  Constraint *conjunction(
      const std::vector<std::shared_ptr<TreeNode> > &constrs);

 private:
  std::shared_ptr<ErrLogger> err_logger_; /**< The error logger */
  std::map<std::size_t, std::vector<std::shared_ptr<TreeNode> > >
      stored_invalidations_; /**< Stored parameter invalidation constraint */
  double default_precision_; /**< The default floating-point precision */
};
}  // namepsace common
}  // namespace ct

#endif  // ASSEMBLER_H_
