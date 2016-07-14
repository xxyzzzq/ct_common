// Copyright 2016 ct_common authors. See LICENSE file for details.

#ifndef CT_COMMON_FILE_PARSE_ASSEMBLER_H_
#define CT_COMMON_FILE_PARSE_ASSEMBLER_H_

#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <utility>

#include "ct_common/common/constraints.h"
#include "ct_common/common/exps.h"
#include "ct_common/common/paramspecs.h"
#include "ct_common/common/pvpair.h"
#include "ct_common/common/seed.h"
#include "ct_common/common/strength.h"
#include "ct_common/parser/err_logger.h"

namespace ct_common {

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
  Assembler(const Assembler& from);
  ~Assembler(void);
  const Assembler& operator=(const Assembler& right);

  /** Setting the error logger */
  void SetErrLogger(const std::shared_ptr<ErrLogger>& err_logger) {
    this->err_logger_ = err_logger;
  }
  /** Getting the error logger */
  const std::shared_ptr<ErrLogger>& get_err_logger(void) {
    return this->err_logger_;
  }

  /** Report an error */
  void ReportError(const std::string& str);
  /** Report a warning */
  void ReportWarning(const std::string& str);
  /** Get the total number of errors */
  std::size_t NumErrs(void) const;
  /** Get the total number of warnings */
  std::size_t NumWarnings(void) const;

 public:
  /** Assemble a parameter specification */
  ParamSpec* AsmParamSpec(const std::string& type,
                          const std::string& identifier,
                          const std::vector<std::shared_ptr<TreeNode> >& vals);

  /** Assemble an automatic parameter specification */
  ParamSpec* AsmParamSpec(
      const std::string& type, const std::string& identifier,
      const std::vector<std::pair<std::shared_ptr<TreeNode>,
      std::shared_ptr<TreeNode> > >& auto_value_specs);

  /** Assemble a covering strength */
  void AttachStrengths(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const std::vector<std::string>& identifiers,
      std::vector<Strength>* strengths, std::size_t strength);

  /** Assemble a universal covering strength */
  void AttachDefaultStrengths(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      std::vector<Strength>* strengths, std::size_t strength);

  /** Assemble a pvpair */
  PVPair* AsmPVPair(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const std::string& identifier, const TreeNode* value_exp);

  /** Assemble a string constraint */
  Constraint_S* AsmConstraint_S(Exp_S* oprd1, Exp_S* oprd2, eOPERATOR op);
  /** Assemble an arithematic constraint */
  Constraint_A* AsmConstraint_A(Exp_A* oprd1, Exp_A* oprd2, eOPERATOR op,
                                double precision);
  /** Assemble an arithmatic/string/logical constraint */
  Constraint* AsmConstraint_ASB(TreeNode* oprd1, TreeNode* oprd2, eOPERATOR op,
                                 const std::string& str);
  /** Assemble a binary logical constraint */
  Constraint_L* AsmConstraint_L(TreeNode* oprd1, TreeNode* oprd2,
                                 eOPERATOR op);
  /** Assemble a unary logical constraint */
  Constraint_L* AsmConstraint_L(TreeNode* oprd, eOPERATOR op);
  /** Assemble a constant Boolean constraint */
  Constraint_L_CBool* AsmConstraint_L_CBool(const std::string& val);
  /** Assemble a parameter invalidation atomic constraint (in the
   * post-processing stage) */
  Constraint* AsmConstraint_L_IVLD(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const std::string& identifier);
  /** Assemble a parameter constraint/expression */
  TreeNode* AsmParam(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const std::string& identifier);

  /** Assemble a binary expression */
  Exp_A* AsmExp_A(TreeNode* oprd1, TreeNode* oprd2, eOPERATOR op);
  /** Assemble a unary expression */
  Exp_A* AsmExp_A(TreeNode* oprd, eOPERATOR op);
  /** Assemble a cast expresion */
  Exp_A* AsmExp_A_Cast(TreeNode* oprd, const std::string& type);

  /** Store the parameter invalidation constraint for later post-processing */
  void StoreInvalidation(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs,
      const std::vector<std::string>& identifiers,
      const std::shared_ptr<TreeNode>& precond);
  /** Post-processing parameter invalidation constraints */
  std::vector<std::shared_ptr<Constraint> > DumpInvalidations(
      const std::vector<std::shared_ptr<ParamSpec> >& param_specs);

  /** Assemble a tuple seed */
  Seed* AsmSeed(std::size_t id, const Tuple& tuple);
  /** Assemble a constraint seed */
  Seed* AsmSeed(std::size_t id, Constraint* constr);

  /** Setting an option */
  void SetOption(const std::string& identifier,
                 const TreeNode* value);

 private:
  /** Geting the conjunction of a set of constraints */
  Constraint* Conjunction(
      const std::vector<std::shared_ptr<TreeNode> >& constrs);

 private:
  std::shared_ptr<ErrLogger> err_logger_; /**< The error logger */
  std::map<std::size_t, std::vector<std::shared_ptr<TreeNode> > >
      stored_invalidations_; /**< Stored parameter invalidation constraint */
  double default_precision_; /**< The default floating-point precision */
};

}  // namespace ct_common

#endif  // CT_COMMON_FILE_PARSE_ASSEMBLER_H_
