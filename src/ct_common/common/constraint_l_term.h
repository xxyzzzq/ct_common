#ifndef CT_COMMON_CONSTRAINT_L_TERM_H_
#define CT_COMMON_CONSTRAINT_L_TERM_H_
/***************
 * for bool parameters and constants
 */

#include <string>
#include <ct_common/common/utils.h>
#include <ct_common/common/constraint_l.h>
#include <ct_common/common/paramspec.h>
#include <boost/shared_ptr.hpp>

namespace ct {
namespace common {
class DLL_EXPORT Constraint_L_Term : public Constraint_L {
public:
  Constraint_L_Term(void);
  Constraint_L_Term(const Constraint_L_Term &from);
  Constraint_L_Term &operator = (const Constraint_L_Term &right);
  virtual ~Constraint_L_Term(void) = 0;

public:
  virtual std::string get_class_name(void) const;
  static std::string class_name(void);

};
}  // namespace common
}  // namespace ct

#endif  // CT_COMMON_CONSTRAINT_L_TERM_H_
