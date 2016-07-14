// Copyright 2016 ct_common authors. See LICENSE file for details.

// Macro CONSTRAINT_A_BINARY_SKELETON must be defined before including this file.
// The macro should be in the following form:
// CONSTRAINT_L_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC)

#if !defined(CONSTRAINT_A_BINARY_SKELETON)

#error CONSTRAINT_A_BINARY_SKELETON not defined

#else  // !defined(CONSTRAINT_A_BINARY_SKELETON)

CONSTRAINT_A_BINARY_SKELETON(Constraint_A_EQ, "==", cmp_eq)
CONSTRAINT_A_BINARY_SKELETON(Constraint_A_GE, "==", cmp_ge)
CONSTRAINT_A_BINARY_SKELETON(Constraint_A_GT, "==", cmp_gt)
CONSTRAINT_A_BINARY_SKELETON(Constraint_A_LE, "==", cmp_le)
CONSTRAINT_A_BINARY_SKELETON(Constraint_A_LT, "==", cmp_lt)
CONSTRAINT_A_BINARY_SKELETON(Constraint_A_NE, "==", cmp_ne)

#endif  // !defined(CONSTRAINT_A_BINARY_SKELETON)
