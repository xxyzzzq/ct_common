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

#include <string>
#include <vector>
#include <cstdlib>
#include <ct_common/common/paramspecs.h>
#include <ct_common/common/constraints.h>
#include <ct_common/common/pvpair.h>
#include <ct_common/common/seed.h>
#include <ct_common/common/exps.h>
#include <ct_common/common/strength.h>
#include <ct_common/file_parse/err_logger.h>

namespace ct {
namespace common {
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

class Assembler {
public:
  Assembler(void);
  Assembler(const Assembler &from);
  ~Assembler(void);
  const Assembler &operator = (const Assembler &right);

  void setErrLogger(const boost::shared_ptr<ErrLogger> &err_logger) { this->err_logger_ = err_logger; }
  const boost::shared_ptr<ErrLogger> &get_err_logger(void) { return this->err_logger_; }
  
  void reportError(const std::string &str);
  void reportWarning(const std::string &str);
  std::size_t numErrs(void) const;
  std::size_t numWarnings(void) const;
  
public:
  ParamSpec *asm_paramspec(
      const std::string &type,
      const std::string &identifier,
      const std::vector<boost::shared_ptr<TreeNode> > &vals);
  
  ParamSpec *asm_paramspec(
      const std::string &type,
      const std::string &identifier,
      const std::vector<std::pair<boost::shared_ptr<TreeNode>, boost::shared_ptr<TreeNode> > > &auto_value_specs);

  void attach_strengths(
      const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
      const std::vector<std::string> &identifiers,
      std::vector<Strength> &strengths,
      std::size_t strength);

  void attach_default_strengths(
      const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
      std::vector<Strength> &strengths,
      std::size_t strength);

  PVPair *asm_pvpair(
      const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
      const std::string &identifier,
      const TreeNode *value_exp);

  Constraint_S *asm_constraint_s(Exp_S *oprd1, Exp_S *oprd2, eOPERATOR op);
  Constraint_A *asm_constraint_a(Exp_A *oprd1, Exp_A *oprd2, eOPERATOR op, double precision);

  Constraint *asm_constraint_asb(TreeNode *oprd1, TreeNode *oprd2, eOPERATOR op, const std::string &str);
  Constraint_L *asm_constraint_l(TreeNode *oprd1, TreeNode *oprd2, eOPERATOR op);
  Constraint_L *asm_constraint_l(TreeNode *oprd, eOPERATOR op);
  Constraint_L_CBool *asm_constraint_l_cbool(const std::string &val);
  Constraint *asm_constraint_invalid(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs, const std::string &identifier);
  TreeNode *asm_param(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs, const std::string &identifier);

  Exp_A *asm_exp_a(TreeNode *oprd1, TreeNode *oprd2, eOPERATOR op);
  Exp_A *asm_exp_a(TreeNode *oprd, eOPERATOR op);
  Exp_A *asm_exp_a_cast(TreeNode *oprd, const std::string &type);

  void store_invalidation(
      const std::vector<boost::shared_ptr<ParamSpec> > &param_specs,
      const std::vector<std::string> &identifiers,
      const boost::shared_ptr<TreeNode> &precond);
  std::vector<boost::shared_ptr<Constraint> > dump_invalidations(const std::vector<boost::shared_ptr<ParamSpec> > &param_specs);

  ct::common::Seed *asm_seed(std::size_t id, const ct::common::Tuple &tuple);
  ct::common::Seed *asm_seed(std::size_t id, ct::common::Constraint *constr);
  
  void set_option(const std::string &identifier, const ct::common::TreeNode *value);

private:
  Constraint *conjunction(const std::vector<boost::shared_ptr<TreeNode> > &constrs);

private:
  boost::shared_ptr<ErrLogger> err_logger_;
  std::map<std::size_t, std::vector<boost::shared_ptr<TreeNode> > > stored_invalidations_;
  double default_precision_;
};
}  // namepsace common
}  // namespace ct

#endif  // ASSEMBLER_H_
