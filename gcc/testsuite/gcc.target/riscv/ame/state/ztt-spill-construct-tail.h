#include "../matrix/ternary/ztt-mixed-old-copy.h"
#ifndef CT_SOURCE
#define CT_SOURCE i32_rnu
#endif
#define CT_BCAST_(t, s) __riscv_ztt_mbcast_m_x_##t##_1x1_##s
#define CT_BCAST(t, s) CT_BCAST_(t, s)
#define CT_MAKE_(s) __riscv_ztt_scalar_from_bits_##s
#define CT_MAKE(s) CT_MAKE_(s)
#ifdef __cplusplus
extern "C" {
#endif
#define CT_CASE(name, extra) \
void name (TC_ARGS) \
{ \
  TC_LOAD_SCALAR; \
  TC_T(TC_TYPE) result = TC_SCALAR; \
  TC_T(TC_TYPE) v = extra; \
  TC_STORE (out, TC_NAME(madd_ew, TC_TYPE) (result, v)); \
  TC_STORE (saved, d); \
  TC_STORE (asaved, a); \
}
CT_CASE (ct_zero, TC_NAME(mzero_m, TC_TYPE) ())
CT_CASE (ct_bcast, CT_BCAST(TC_TYPE, CT_SOURCE) (CT_MAKE(CT_SOURCE) (e)))
CT_CASE (ct_row, TC_NAME(mrowid_ew, TC_TYPE) ())
CT_CASE (ct_col, TC_NAME(mcolid_ew, TC_TYPE) ())
void ct_zero_store (TC_ARGS)
{
  TC_LOAD_SCALAR;
  TC_T(TC_TYPE) result = TC_SCALAR;
  TC_STORE (out, result);
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
  TC_STORE ((tc_element *) bsaved, TC_NAME(mzero_m, TC_TYPE) ());
}
#ifdef __cplusplus
}
#endif
