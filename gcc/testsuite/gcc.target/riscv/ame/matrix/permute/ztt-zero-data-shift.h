#include <riscv_ztt.h>

#ifndef ZS_TYPE
#define ZS_TYPE i32_rnu
#define ZS_ELEMENT __INT32_TYPE__
#endif
#define ZS_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define ZS_NAME_I(f, t) ZS_NAME_(f, t)
#define ZS_NAME(f) ZS_NAME_I(f, ZS_TYPE)
#define ZS_T_(t) __riscv_ztt_##t##_1x1_t
#define ZS_T(t) ZS_T_(t)
typedef ZS_ELEMENT zs_element;
typedef ZS_T(ZS_TYPE) zs_matrix;
#define ZS_ARGS const zs_element *in, zs_element *out, zs_element *extra, int k
#define ZS_ZERO zs_matrix a = ZS_NAME(mzero_m) ()
#define ZS_ROW(a, k) ZS_NAME(mrowshift_ew_x) (a, k)
#define ZS_COL(a, k) ZS_NAME(mcolshift_ew_x) (a, k)
#define ZS_STORE(a) __riscv_ztt_mss_rm (out, a)

#ifdef __cplusplus
extern "C" {
#endif
extern void zs_callee (void);
extern volatile int zs_observed;

void zs_row (ZS_ARGS) { ZS_ZERO; ZS_STORE (ZS_ROW (a, k)); }
void zs_col (ZS_ARGS) { ZS_ZERO; ZS_STORE (ZS_COL (a, k)); }
void zs_copy (ZS_ARGS)
{
  ZS_ZERO;
  zs_matrix b = ZS_NAME(mcopy_m2m) (a);
  ZS_STORE (ZS_COL (b, k));
}
void zs_shared (ZS_ARGS)
{
  ZS_ZERO; ZS_STORE (ZS_ROW (a, k)); __riscv_ztt_mss_rm (extra, a);
}
void zs_positive (ZS_ARGS) { ZS_ZERO; ZS_STORE (ZS_ROW (a, 1)); }
void zs_negative (ZS_ARGS) { ZS_ZERO; ZS_STORE (ZS_COL (a, -1)); }
void zs_extreme (ZS_ARGS) { ZS_ZERO; ZS_STORE (ZS_ROW (a, (-2147483647 - 1))); }
void zs_chain (ZS_ARGS) { ZS_ZERO; ZS_STORE (ZS_COL (ZS_ROW (a, k), k)); }
void zs_control (ZS_ARGS)
{
  int offset = zs_observed;
  ZS_ZERO; ZS_STORE (ZS_COL (a, offset));
}
void zs_nonzero (ZS_ARGS)
{
  zs_matrix a = ZS_NAME(mls_rm) (in);
  ZS_STORE (ZS_ROW (a, k));
}
void zs_call (ZS_ARGS) { ZS_ZERO; zs_callee (); ZS_STORE (ZS_ROW (a, k)); }
void zs_asm (ZS_ARGS)
{
  ZS_ZERO; asm volatile ("" ::: "memory"); ZS_STORE (ZS_COL (a, k));
}
void zs_memory (ZS_ARGS)
{
  ZS_ZERO; zs_observed = k ^ 5; ZS_STORE (ZS_COL (a, k));
}
void zs_reference (ZS_ARGS) { ZS_ZERO; ZS_STORE (a); }
#ifdef __cplusplus
}
#endif
