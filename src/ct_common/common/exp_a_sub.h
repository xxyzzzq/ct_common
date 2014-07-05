#ifndef CT_COMMON_EXP_A_SUB_H_
#define CT_COMMON_EXP_A_SUB_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/exp_a_binary.h>

namespace ct {
namespace common {
class DLL_EXPORT Exp_A_Sub : public Exp_A_Binary {
public:
  Exp_A_Sub(void);
  Exp_A_Sub(const Exp_A_Sub &from);
  Exp_A_Sub &operator = (const Exp_A_Sub &right);
  virtual ~Exp_A_Sub(void);

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual double evaluate_double(double val_1, double val_2) const;
  virtual int evaluate_int(int val_1, int val_2) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_EXP_A_SUB_H_
