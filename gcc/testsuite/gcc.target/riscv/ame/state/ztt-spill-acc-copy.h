#include "ztt-spill-acc-tail.h"
#ifdef __cplusplus
extern "C" {
#endif
#define AP_CASE(name, init, op, before) \
void name (TC_ARGS) \
{ \
  TC_LOAD_SCALAR; \
  TC_T(TC_TYPE) result = TC_SCALAR; \
  AT_TYPE(TC_TYPE) original = init; \
  AT_TYPE(TC_TYPE) acc = AT_OP(op, TC_TYPE) (original, result, result); \
  before; \
  TC_STORE (out, TC_NAME(mcopy_a2m, TC_TYPE) (acc)); \
  TC_STORE ((tc_element *)bsaved, TC_NAME(mcopy_a2m, TC_TYPE) (original)); \
  TC_STORE (saved, d); \
  TC_STORE (asaved, a); \
}
AP_CASE (ap_copy, AT_OP(mcopy_m2a, TC_TYPE) (result), mmulacc_2d, (void)0)
AP_CASE (ap_neg, AT_OP(mcopy_m2a, TC_TYPE) (result), mmulaccneg_2d, (void)0)
AP_CASE (ap_zero, AT_OP(mzero_acc, TC_TYPE) (), mmulacc_2d, (void)0)
AP_CASE (ap_call, AT_OP(mcopy_m2a, TC_TYPE) (result), mmulacc_2d, tc_callee ())
#ifdef __cplusplus
}
#endif
