#include <riscv_ztt.h>

#ifndef MS_TYPE
#define MS_TYPE i32_rnu
#define MS_ELEMENT __INT32_TYPE__
#endif
#define MS_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define MS_NAME_I(f, t) MS_NAME_(f, t)
#define MS_NAME(f) MS_NAME_I(f, MS_TYPE)
#ifdef MS_FROM_BITS
#define MS_MAKE_(t) __riscv_ztt_scalar_from_bits_##t
#define MS_INPUT ((unsigned long) value)
#else
#define MS_MAKE_(t) __riscv_ztt_scalar_make_##t
#define MS_INPUT value
#endif
#define MS_MAKE(t) MS_MAKE_(t)
#define MS_T_(t) __riscv_ztt_##t##_1x1_t
#define MS_T(t) MS_T_(t)
typedef MS_ELEMENT ms_element;
typedef MS_T(MS_TYPE) ms_matrix;
#define MS_ARGS ms_element value, const ms_element *in, const __INT32_TYPE__ *index, \
  ms_element *out, ms_element *extra, __INT32_TYPE__ *saved
#define MS_INDEX __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index)
#define MS_UNIFORM ms_matrix a = MS_NAME(mbcast_m_x) (MS_MAKE(MS_TYPE) (MS_INPUT))
#define MS_ROW(old, data) MS_NAME(mrowscatmax_ew) (old, data, i)
#define MS_COL(old, data) MS_NAME(mcolscatmax_ew) (old, data, i)
#define MS_STORE(a) __riscv_ztt_mss_rm (out, a)
#define MS_SAVE __riscv_ztt_mss_rm (saved, i)

#ifdef __cplusplus
extern "C" {
#endif
extern void ms_callee (void);
extern volatile unsigned long ms_observed;

void ms_row (MS_ARGS) { MS_INDEX; MS_UNIFORM; MS_STORE (MS_ROW (a, a)); MS_SAVE; }
void ms_col (MS_ARGS) { MS_INDEX; MS_UNIFORM; MS_STORE (MS_COL (a, a)); MS_SAVE; }
void ms_copy (MS_ARGS)
{
  MS_INDEX; MS_UNIFORM;
  ms_matrix old = MS_NAME(mcopy_m2m) (a);
  MS_STORE (MS_ROW (old, a)); MS_SAVE;
}
void ms_shared (MS_ARGS)
{
  MS_INDEX; MS_UNIFORM;
  MS_STORE (MS_COL (a, a)); __riscv_ztt_mss_rm (extra, a); MS_SAVE;
}
void ms_zero_uniform (MS_ARGS)
{
  MS_INDEX; ms_matrix a = MS_NAME(mzero_m) ();
  MS_STORE (MS_ROW (a, a)); MS_SAVE;
}
void ms_zero_row (MS_ARGS)
{
  MS_INDEX; ms_matrix a = MS_NAME(mls_rm) (in), z = MS_NAME(mzero_m) ();
  MS_STORE (MS_ROW (a, z)); MS_SAVE;
}
void ms_zero_col (MS_ARGS)
{
  MS_INDEX; ms_matrix a = MS_NAME(mls_rm) (in), z = MS_NAME(mzero_m) ();
  MS_STORE (MS_COL (a, z)); MS_SAVE;
}
void ms_nonuniform (MS_ARGS)
{
  MS_INDEX; ms_matrix a = MS_NAME(mls_rm) (in);
  MS_STORE (MS_COL (a, a)); MS_SAVE;
}
void ms_distinct (MS_ARGS)
{
  MS_INDEX; ms_matrix old = MS_NAME(mls_rm) (in); MS_UNIFORM;
  MS_STORE (MS_ROW (old, a)); MS_SAVE;
}
void ms_call (MS_ARGS)
{
  MS_INDEX; MS_UNIFORM; ms_callee (); MS_STORE (MS_ROW (a, a)); MS_SAVE;
}
void ms_asm (MS_ARGS)
{
  MS_INDEX; MS_UNIFORM; asm volatile ("" ::: "memory");
  MS_STORE (MS_COL (a, a)); MS_SAVE;
}
void ms_unstored (MS_ARGS) { MS_INDEX; MS_UNIFORM; MS_STORE (MS_ROW (a, a)); }
void ms_memory (MS_ARGS)
{
  MS_INDEX; MS_UNIFORM; ms_observed = 101; MS_STORE (MS_COL (a, a)); MS_SAVE;
}
void ms_reference (MS_ARGS) { MS_INDEX; MS_UNIFORM; MS_STORE (a); MS_SAVE; }
#ifdef __cplusplus
}
#endif
