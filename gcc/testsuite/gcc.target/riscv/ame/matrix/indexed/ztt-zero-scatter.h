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
#define ZS_ARGS const zs_element *in, const __INT32_TYPE__ *index, \
  zs_element *out, zs_element *extra, __INT32_TYPE__ *saved
#define ZS_INPUTS \
  zs_matrix a = ZS_NAME(mls_rm) (in); \
  __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index); \
  zs_matrix z = ZS_NAME(mzero_m) ()
#define ZS_ROW(old, data) ZS_NAME(mrowscatadd_ew) (old, data, i)
#define ZS_COL(old, data) ZS_NAME(mcolscatadd_ew) (old, data, i)
#define ZS_STORE(a) __riscv_ztt_mss_rm (out, a)
#define ZS_SAVE __riscv_ztt_mss_rm (saved, i)

#ifdef __cplusplus
extern "C" {
#endif
extern void zs_callee (void);
extern volatile unsigned long zs_observed;

void zs_row (ZS_ARGS) { ZS_INPUTS; ZS_STORE (ZS_ROW (a, z)); ZS_SAVE; }
void zs_col (ZS_ARGS) { ZS_INPUTS; ZS_STORE (ZS_COL (a, z)); ZS_SAVE; }
void zs_copy (ZS_ARGS)
{
  ZS_INPUTS;
  zs_matrix zero = ZS_NAME(mcopy_m2m) (z);
  ZS_STORE (ZS_ROW (a, zero)); ZS_SAVE;
}
void zs_shared (ZS_ARGS)
{
  ZS_INPUTS;
  ZS_STORE (ZS_COL (a, z)); __riscv_ztt_mss_rm (extra, a); ZS_SAVE;
}
void zs_call (ZS_ARGS)
{
  ZS_INPUTS; zs_callee (); ZS_STORE (ZS_ROW (a, z)); ZS_SAVE;
}
void zs_asm (ZS_ARGS)
{
  ZS_INPUTS; asm volatile ("" ::: "memory"); ZS_STORE (ZS_COL (a, z)); ZS_SAVE;
}
void zs_memory (ZS_ARGS)
{
  ZS_INPUTS; zs_observed = 101; ZS_STORE (ZS_ROW (a, z)); ZS_SAVE;
}
void zs_unstored (ZS_ARGS) { ZS_INPUTS; ZS_STORE (ZS_COL (a, z)); }
void zs_nonzero (ZS_ARGS) { ZS_INPUTS; ZS_STORE (ZS_ROW (a, a)); ZS_SAVE; }
void zs_oldzero (ZS_ARGS) { ZS_INPUTS; ZS_STORE (ZS_COL (z, a)); ZS_SAVE; }
void zs_max (ZS_ARGS)
{
  ZS_INPUTS; ZS_STORE (ZS_NAME(mrowscatmax_ew) (a, z, i)); ZS_SAVE;
}
void zs_reference (ZS_ARGS) { ZS_INPUTS; ZS_STORE (a); ZS_SAVE; }
#ifdef __cplusplus
}
#endif
