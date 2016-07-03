// Copyright 2016 ct_common authors. See LICENSE file for details.

// Macro CONSTRAINT_L_BINARY_SKELETON must be defined before including this file.
// The macro should be in the following form:
// EXP_A_BINARY_SKELETON(CLASS_NAME, OP_TOKEN, EVAL_FUNC)

#if !defined(EXP_A_BINARY_SKELETON)

#error EXP_A_BINARY_SKELETON not defined

#else  // !defined(EXP_A_BINARY_SKELETON)

EXP_A_BINARY_SKELETON(Exp_A_Add, "+", kFuncAdd_Int, kFuncAdd_Double)
EXP_A_BINARY_SKELETON(Exp_A_Div, "/", kFuncDiv_Int, kFuncDiv_Double)
EXP_A_BINARY_SKELETON(Exp_A_Mod, "%", kFuncMod_Int, kFuncMod_Double)
EXP_A_BINARY_SKELETON(Exp_A_Mult, "*", kFuncMult_Int, kFuncMult_Double)
EXP_A_BINARY_SKELETON(Exp_A_Sub, "-", kFuncSub_Int, kFuncSub_Double)

#endif  // !defined(EXP_A_BINARY_SKELETON)
