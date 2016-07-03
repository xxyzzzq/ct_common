// Copyright 2016 ct_common authors. See LICENSE file for details.

// Macro CONSTRAINT_L_BINARY_SKELETON must be defined before including this file.
// The macro should be in the following form:
// CONSTRAINT_L_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC)

#if !defined(CONSTRAINT_L_BINARY_SKELETON)

#error CONSTRAINT_L_BINARY_SKELETON not defined

#else  // !defined(CONSTRAINT_L_BINARY_SKELETON)

CONSTRAINT_L_BINARY_SKELETON(Constraint_L_And, "&&", kFuncAnd)
CONSTRAINT_L_BINARY_SKELETON(Constraint_L_Iff, "<->", kFuncIff)
CONSTRAINT_L_BINARY_SKELETON(Constraint_L_Imply, "->", kFuncImply)
CONSTRAINT_L_BINARY_SKELETON(Constraint_L_Or, "||", kFuncOr)
CONSTRAINT_L_BINARY_SKELETON(Constraint_L_Xor, "^^", kFuncXor)

#endif  // !defined(CONSTRAINT_L_BINARY_SKELETON)
