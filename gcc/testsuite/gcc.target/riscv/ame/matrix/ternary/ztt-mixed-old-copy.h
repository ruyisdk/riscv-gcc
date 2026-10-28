#include <riscv_ztt.h>
#ifndef TC_TYPE
#define TC_TYPE i64_rnu
#define TC_CARRIER __INT64_TYPE__
#endif
#ifndef TA_TYPE
#define TA_TYPE i32_rnu
#define TA_CARRIER __INT32_TYPE__
#endif
#define TC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define TC_NAME(f, t) TC_NAME_(f, t)
#define TC_T_(t) __riscv_ztt_##t##_1x1_t
#define TC_T(t) TC_T_(t)
#define TC_S_(t) __riscv_ztt_mmulacc_ew_x_##t##_1x1_i32_rnu
#define TC_S(t) TC_S_(t)
typedef TC_CARRIER tc_element;
typedef TA_CARRIER ta_element;
typedef __INT32_TYPE__ tb_element;
typedef __UINT32_TYPE__ ti_element;
#define TC_ARGS const tc_element *old, const ta_element *left, \
  const tb_element *right, const ti_element *index, tc_element *out, \
  tc_element *saved, ta_element *asaved, tb_element *bsaved, long e
#define TC_LOAD TC_T(TA_TYPE) a = TC_NAME(mls_rm, TA_TYPE) (left); \
  TC_T(i32_rnu) b = TC_NAME(mls_rm, i32_rnu) (right); \
  TC_T(TC_TYPE) d = TC_NAME(mls_rm, TC_TYPE) (old)
#define TC_LOAD_SCALAR TC_T(TA_TYPE) a = TC_NAME(mls_rm, TA_TYPE) (left); \
  TC_T(TC_TYPE) d = TC_NAME(mls_rm, TC_TYPE) (old)
#define TC_STORE(p, x) __riscv_ztt_mss_rm (p, x)
#define TC_OP(f) TC_NAME(f, TC_TYPE) (d, a, b)
#define TC_SCALAR TC_S(TC_TYPE) (d, a, __riscv_ztt_scalar_make_i32_rnu (e))
#ifdef __cplusplus
extern "C" {
#endif
extern void tc_callee (void);
#define TC_CASE(name, op) \
void name (TC_ARGS) \
{ \
  TC_LOAD; \
  TC_STORE (out, TC_OP (op)); \
  TC_STORE (saved, d); \
  TC_STORE (asaved, a); \
  TC_STORE (bsaved, b); \
}
TC_CASE (tc_acc, mmulacc_ew)
TC_CASE (tc_neg, mmulaccneg_ew)
TC_CASE (tc_add, mmuladd_ew)
TC_CASE (tc_sub, mmulsub_ew)
TC_CASE (tc_matrix_exponent, mldexpacc_ew)
#undef TC_CASE

void tc_scalar (TC_ARGS)
{
  TC_LOAD_SCALAR;
  TC_STORE (out, TC_SCALAR);
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
}
void tc_exponent (TC_ARGS)
{
  TC_LOAD_SCALAR;
  TC_STORE (out, TC_NAME(mldexpacc_ew_x, TC_TYPE) (d, a, e));
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
}
#define TC_SCAT(name, op) \
void name (TC_ARGS) \
{ \
  TC_LOAD_SCALAR; \
  TC_T(u32_rnu) idx = TC_NAME(mls_rm, u32_rnu) (index); \
  TC_STORE (out, TC_NAME(op, TC_TYPE) (d, a, idx)); \
  TC_STORE (saved, d); \
  TC_STORE (asaved, a); \
  TC_STORE ((ti_element *) bsaved, idx); \
}
TC_SCAT (tc_scatter, mrowscatadd_ew)
TC_SCAT (tc_scatmax, mrowscatmax_ew)
#undef TC_SCAT
void tc_late_input (TC_ARGS)
{
  TC_LOAD_SCALAR;
  TC_T(TC_TYPE) extra = TC_NAME(mls_rm, TC_TYPE) (old + 64);
  TC_T(TC_TYPE) result = TC_SCALAR;
  TC_STORE (out, TC_NAME(madd_ew, TC_TYPE) (result, extra));
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
}
void tc_pressure (TC_ARGS)
{
  TC_LOAD_SCALAR;
  TC_T(TC_TYPE) extra = TC_NAME(mls_rm, TC_TYPE) (old + 64);
  d = TC_NAME(madd_ew, TC_TYPE) (d, extra);
  TC_T(TC_TYPE) result = TC_SCALAR;
  TC_STORE (out, TC_NAME(madd_ew, TC_TYPE) (result, extra));
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
}
void tc_call (TC_ARGS)
{
  TC_LOAD;
  tc_callee ();
  TC_STORE (out, TC_OP (mmulacc_ew));
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
  TC_STORE (bsaved, b);
}
void tc_dead (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_OP (mmulacc_ew));
  TC_STORE (asaved, a);
  TC_STORE (bsaved, b);
}
void tc_after (TC_ARGS)
{
  TC_LOAD;
  TC_STORE (out, TC_OP (mmulacc_ew));
  tc_callee ();
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
  TC_STORE (bsaved, b);
}
void tc_reference (TC_ARGS)
{
  TC_T(TC_TYPE) d = TC_NAME(mls_rm, TC_TYPE) (old);
  TC_STORE (out, d);
}
void tc_order (TC_ARGS)
{
  TC_T(TC_TYPE) d = TC_NAME(mls_rm, TC_TYPE) (old);
  TC_T(TA_TYPE) a = TC_NAME(mls_rm, TA_TYPE) (left);
  TC_T(i32_rnu) b = TC_NAME(mls_rm, i32_rnu) (right);
  TC_STORE (out, TC_OP (mmulacc_ew));
  TC_STORE (saved, d);
  TC_STORE (asaved, a);
  TC_STORE (bsaved, b);
}
#ifdef __cplusplus
}
#endif
