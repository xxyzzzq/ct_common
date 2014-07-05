#ifndef CT_COMMON_CONSTRAINT_L_IMPLY_H_
#define CT_COMMON_CONSTRAINT_L_IMPLY_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l_binary.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_L_Imply : public Constraint_L_Binary {
public:
  Constraint_L_Imply(void);
  Constraint_L_Imply(const Constraint_L_Imply &from);
  Constraint_L_Imply &operator = (const Constraint_L_Imply &right);
  virtual ~Constraint_L_Imply(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual EvalType_Bool evaluate_func(EvalType_Bool val_l, EvalType_Bool val_r) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_IMPLY_H_
