#include <riscv_ztt.h>

#ifndef BD_TYPE
#define BD_TYPE u32_rnu
#define BD_OTHER u32_rod
#define BD_CARRIER __UINT32_TYPE__
#endif
#define BD_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define BD_NAME(f, t) BD_NAME_(f, t)
#define BD_T_(t) __riscv_ztt_##t##_1x1_t
#define BD_T(t) BD_T_(t)
typedef BD_CARRIER bd_element;
#define BD_ARGS const bd_element *in, const bd_element *other, \
  bd_element *previous, bd_element *out, bd_element *saved, bd_element *saved_other
#define BD_LOAD BD_T(BD_TYPE) a = BD_NAME(mls_rm, BD_TYPE) (in); \
  BD_T(BD_TYPE) b = BD_NAME(mls_rm, BD_TYPE) (other)
#define BD_SAVE __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void bd_callee (void);

#define BD_CASE(NAME, FIRST_TYPE, OP, RHS, BETWEEN) \
void bd_##NAME (BD_ARGS) \
{ \
  BD_LOAD; \
  BD_T(FIRST_TYPE) c = BD_NAME(madd_ew, FIRST_TYPE) (a, b); \
  __riscv_ztt_mss_rm (previous, c); \
  BETWEEN; \
  BD_T(BD_TYPE) d = BD_NAME(OP, BD_TYPE) (a, RHS); \
  __riscv_ztt_mss_rm (out, d); \
  BD_SAVE; \
}
BD_CASE(add, BD_TYPE, madd_ew, b, )
BD_CASE(sub, BD_TYPE, msub_ew, b, )
BD_CASE(min, BD_TYPE, mmin_ew, b, )
BD_CASE(max, BD_TYPE, mmax_ew, b, )
BD_CASE(and, BD_TYPE, mand_ew, b, )
BD_CASE(andnot, BD_TYPE, mandnot_ew, b, )
BD_CASE(or, BD_TYPE, mor_ew, b, )
BD_CASE(ornot, BD_TYPE, mornot_ew, b, )
BD_CASE(xor, BD_TYPE, mxor_ew, b, )
BD_CASE(same, BD_TYPE, msub_ew, a, )
BD_CASE(call, BD_TYPE, msub_ew, b, bd_callee ())
BD_CASE(barrier, BD_TYPE, msub_ew, b, __asm__ volatile ("# AME state boundary" ::: "memory"))
BD_CASE(join, BD_TYPE, msub_ew, b, if (*in & 1) bd_callee ())
BD_CASE(changed, BD_OTHER, msub_ew, b, )

void bd_unknown (BD_ARGS)
{
  BD_LOAD;
  __riscv_ztt_mss_rm (previous, a);
  BD_T(BD_TYPE) c = BD_NAME(msub_ew, BD_TYPE) (a, b);
  __riscv_ztt_mss_rm (out, c);
  BD_SAVE;
}

void bd_reference (BD_ARGS)
{
  BD_LOAD;
  __riscv_ztt_mss_rm (previous, a);
  __riscv_ztt_mss_rm (out, b);
  BD_SAVE;
}
#ifdef __cplusplus
}
#endif
