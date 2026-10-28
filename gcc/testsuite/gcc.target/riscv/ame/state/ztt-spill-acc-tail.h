#include "../matrix/ternary/ztt-mixed-old-copy.h"
#define AT_OP_(f, t) __riscv_ztt_##f##_##t##_accx1
#define AT_OP(f, t) AT_OP_(f, t)
#define AT_TYPE_(t) __riscv_ztt_##t##_accx1_t
#define AT_TYPE(t) AT_TYPE_(t)
#ifdef __cplusplus
extern "C" {
#endif
#define AT_CASE(name, init, op) \
void name (TC_ARGS) \
{ \
  TC_LOAD_SCALAR; \
  TC_T(TC_TYPE) result = TC_SCALAR; \
  AT_TYPE(TC_TYPE) acc = init; \
  acc = AT_OP(op, TC_TYPE) (acc, result, result); \
  TC_STORE (out, TC_NAME(mcopy_a2m, TC_TYPE) (acc)); \
  TC_STORE (saved, d); \
  TC_STORE (asaved, a); \
}
AT_CASE (at_zero, AT_OP(mzero_acc, TC_TYPE) (), mmulacc_2d)
AT_CASE (at_clear, AT_OP(mclear_acc, TC_TYPE) (), mmulacc_2d)
AT_CASE (at_from, AT_OP(mcopy_m2a, TC_TYPE) (result), mmulacc_2d)
AT_CASE (at_neg, AT_OP(mcopy_m2a, TC_TYPE) (result), mmulaccneg_2d)
#ifdef __cplusplus
}
#endif
