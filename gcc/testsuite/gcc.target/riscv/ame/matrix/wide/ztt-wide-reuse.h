#include <riscv_ztt.h>

#ifndef WR_TYPE
#define WR_TYPE u64_rnu
#define WR_CARRIER __UINT64_TYPE__
#endif
#ifndef WR_NARROW
#define WR_NARROW u32_rdn
#define WR_NARROW_CARRIER __UINT32_TYPE__
#endif
#define WR_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define WR_NAME(f, t) WR_NAME_(f, t)
#define WR_T_(t) __riscv_ztt_##t##_1x1_t
#define WR_T(t) WR_T_(t)
typedef WR_CARRIER wr_element;
typedef WR_NARROW_CARRIER wr_narrow;
#define WR_ARGS const wr_element *in, const wr_narrow *other, \
  wr_element *out, wr_element *saved, wr_narrow *saved_other
#define WR_LOAD WR_T(WR_TYPE) a = WR_NAME(mls_rm, WR_TYPE) (in); \
  WR_T(WR_NARROW) b = WR_NAME(mls_rm, WR_NARROW) (other)
#define WR_SAVE __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_other, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void wr_callee (void);

#define WR_CASE(NAME, OP, LHS, RHS, BEFORE, AFTER) \
void wr_##NAME (WR_ARGS) \
{ \
  WR_LOAD; \
  BEFORE; \
  WR_T(WR_TYPE) c = WR_NAME(OP, WR_TYPE) (LHS, RHS); \
  __riscv_ztt_mss_rm (out, c); \
  AFTER; \
}

WR_CASE(add_dead, madd_ew, a, b, , )
WR_CASE(add_live, madd_ew, a, b, , WR_SAVE)
WR_CASE(sub_left, msub_ew, a, b, , WR_SAVE)
WR_CASE(sub_right, msub_ew, b, a, , WR_SAVE)
WR_CASE(sub_dead, msub_ew, b, a, , )
WR_CASE(mul_left, mmul_ew, a, b, , WR_SAVE)
WR_CASE(mul_right, mmul_ew, b, a, , WR_SAVE)
WR_CASE(call_left, madd_ew, a, b, wr_callee (), WR_SAVE)
WR_CASE(call_right, msub_ew, b, a, wr_callee (), WR_SAVE)

void wr_reference (WR_ARGS)
{
  WR_LOAD;
  __riscv_ztt_mss_rm (out, a);
  WR_SAVE;
}
#ifdef __cplusplus
}
#endif
