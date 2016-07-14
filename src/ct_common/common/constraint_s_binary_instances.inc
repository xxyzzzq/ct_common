// Copyright 2016 ct_common authors. See LICENSE file for details.

// Macro CONSTRAINT_S_BINARY_SKELETON must be defined before including this file.
// The macro should be in the following form:
// CONSTRAINT_S_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC)

#if !defined(CONSTRAINT_S_BINARY_SKELETON)

#error CONSTRAINT_S_BINARY_SKELETON not defined

#else  // !defined(CONSTRAINT_S_BINARY_SKELETON)

CONSTRAINT_S_BINARY_SKELETON(Constraint_S_EQ, "==", kFuncEqual)
CONSTRAINT_S_BINARY_SKELETON(Constraint_S_NE, "!=", kFuncUnequal)

#endif  // !defined(CONSTRAINT_S_BINARY_SKELETON)
