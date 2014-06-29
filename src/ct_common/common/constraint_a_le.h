#ifndef CT_COMMON_CONSTRAINT_A_LE_H_
#define CT_COMMON_CONSTRAINT_A_LE_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_a_binary.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_A_LE : public Constraint_A_Binary {
public:
  Constraint_A_LE(void);
  Constraint_A_LE(const Constraint_A_LE &from);
  Constraint_A_LE &operator = (const Constraint_A_LE &right);
  ~Constraint_A_LE(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
  virtual std::string get_op_token(void) const;

private:
  virtual bool evaluate_func_int(int loprd_val, int roprd_val) const;
  virtual bool evaluate_func_double(double loprd_val, double roprd_val) const;
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_A_LE_H_
