#include <riscv_ztt.h>

#ifndef UB_TYPE
#define UB_TYPE u32_rnu
#define UB_CARRIER __UINT32_TYPE__
#endif
#define UB_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define UB_NAME(f, t) UB_NAME_(f, t)
#define UB_T_(t) __riscv_ztt_##t##_1x1_t
#define UB_T(t) UB_T_(t)
typedef UB_CARRIER ub_element;
#define UB_ARGS const ub_element *in, const ub_element *other, \
  ub_element *out, ub_element *saved, ub_element *saved_other
#define UB_LOAD UB_T(UB_TYPE) a = UB_NAME(mls_rm, UB_TYPE) (in); \
  UB_T(UB_TYPE) b = UB_NAME(mls_rm, UB_TYPE) (other)
#define UB_SAVE __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void ub_callee (void);

#define UB_CASE(NAME, OP, LHS, RHS, BEFORE, AFTER) \
void ub_##NAME (UB_ARGS) \
{ \
  UB_LOAD; \
  BEFORE; \
  UB_T(UB_TYPE) c = UB_NAME(OP, UB_TYPE) (LHS, RHS); \
  __riscv_ztt_mss_rm (out, c); \
  AFTER; \
}
#define UB_PAIR(NAME, OP) \
  UB_CASE(NAME##_dead, OP, a, b, , ) \
  UB_CASE(NAME##_live, OP, a, b, , UB_SAVE)
UB_PAIR(add, madd_ew)
UB_PAIR(sub, msub_ew)
UB_PAIR(min, mmin_ew)
UB_PAIR(max, mmax_ew)
UB_PAIR(and, mand_ew)
UB_PAIR(andnot, mandnot_ew)
UB_PAIR(or, mor_ew)
UB_PAIR(ornot, mornot_ew)
UB_PAIR(xor, mxor_ew)
UB_CASE(left_dead, msub_ew, a, b, , __riscv_ztt_mss_rm (saved_other, b))
UB_CASE(right_dead, msub_ew, a, b, , __riscv_ztt_mss_rm (saved, a))
UB_CASE(same_dead, madd_ew, a, a, , )
UB_CASE(same_live, madd_ew, a, a, , UB_SAVE)
UB_CASE(call_dead, msub_ew, a, b, ub_callee (), )
UB_CASE(call_live, msub_ew, a, b, ub_callee (), UB_SAVE)
UB_CASE(barrier, madd_ew, a, b, __asm__ volatile ("" ::: "memory"), )

void ub_reference (UB_ARGS)
{
  UB_LOAD;
  __riscv_ztt_mss_rm (out, a);
  UB_SAVE;
}
#ifdef __cplusplus
}
#endif
