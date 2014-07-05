#ifndef CT_COMMON_CONSTRAINT_L_H_
#define CT_COMMON_CONSTRAINT_L_H_

#include <ct_common/common/utils.h>
#include <ct_common/common/constraint.h>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_L : public Constraint {
public:
  Constraint_L(void);
  Constraint_L(const Constraint_L &from);
  Constraint_L &operator = (const Constraint_L &right);
  virtual ~Constraint_L(void);

  virtual std::string get_class_name(void) const;
  static std::string class_name(void);
};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_H_
