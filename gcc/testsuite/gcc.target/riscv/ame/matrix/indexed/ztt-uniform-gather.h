#include <riscv_ztt.h>

#ifndef UG_TYPE
#define UG_TYPE i32_rnu
#define UG_ELEMENT __INT32_TYPE__
#endif
#define UG_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define UG_NAME_I(f, t) UG_NAME_(f, t)
#define UG_NAME(f) UG_NAME_I(f, UG_TYPE)
#ifdef UG_FROM_BITS
#define UG_MAKE_(t) __riscv_ztt_scalar_from_bits_##t
#define UG_SCALAR_INPUT ((unsigned long) value)
#else
#define UG_MAKE_(t) __riscv_ztt_scalar_make_##t
#define UG_SCALAR_INPUT value
#endif
#define UG_MAKE(t) UG_MAKE_(t)
#define UG_T_(t) __riscv_ztt_##t##_1x1_t
#define UG_T(t) UG_T_(t)
typedef UG_ELEMENT ug_element;
typedef UG_T(UG_TYPE) ug_matrix;
#define UG_ARGS ug_element value, const ug_element *in, const __INT32_TYPE__ *index, \
  ug_element *out, ug_element *extra, __INT32_TYPE__ *saved
#define UG_SCALAR ug_matrix a = UG_NAME(mbcast_m_x) (UG_MAKE(UG_TYPE) (UG_SCALAR_INPUT))
#define UG_ZERO ug_matrix a = UG_NAME(mzero_m) ()
#define UG_INDEX __riscv_ztt_i32_rnu_1x1_t i = __riscv_ztt_mls_rm_i32_rnu_1x1 (index)
#define UG_ROW(a) UG_NAME(mrowgather_ew) (a, i)
#define UG_COL(a) UG_NAME(mcolgather_ew) (a, i)
#define UG_STORE(a) __riscv_ztt_mss_rm (out, a)
#define UG_SAVE __riscv_ztt_mss_rm (saved, i)

#ifdef __cplusplus
extern "C" {
#endif
extern void ug_callee (void);
extern volatile unsigned long ug_observed;

void ug_zero_row (UG_ARGS) { UG_INDEX; UG_ZERO; UG_STORE (UG_ROW (a)); UG_SAVE; }
void ug_zero_col (UG_ARGS) { UG_INDEX; UG_ZERO; UG_STORE (UG_COL (a)); UG_SAVE; }
void ug_scalar_row (UG_ARGS) { UG_INDEX; UG_SCALAR; UG_STORE (UG_ROW (a)); UG_SAVE; }
void ug_scalar_col (UG_ARGS) { UG_INDEX; UG_SCALAR; UG_STORE (UG_COL (a)); UG_SAVE; }
void ug_copy (UG_ARGS)
{
  UG_INDEX; UG_SCALAR;
  ug_matrix b = UG_NAME(mcopy_m2m) (a);
  UG_STORE (UG_COL (b)); UG_SAVE;
}
void ug_shared (UG_ARGS)
{
  UG_INDEX; UG_SCALAR;
  UG_STORE (UG_ROW (a));
  __riscv_ztt_mss_rm (extra, a); UG_SAVE;
}
void ug_call (UG_ARGS)
{
  UG_INDEX; UG_SCALAR; ug_callee (); UG_STORE (UG_ROW (a)); UG_SAVE;
}
void ug_asm (UG_ARGS)
{
  UG_INDEX; UG_SCALAR;
  asm volatile ("" ::: "memory"); UG_STORE (UG_COL (a)); UG_SAVE;
}
void ug_memory (UG_ARGS)
{
  UG_INDEX; UG_SCALAR; ug_observed = 101; UG_STORE (UG_ROW (a)); UG_SAVE;
}
void ug_unstored (UG_ARGS)
{
  UG_INDEX; UG_SCALAR; UG_STORE (UG_ROW (a));
}
void ug_nonuniform (UG_ARGS)
{
  UG_INDEX;
  ug_matrix a = UG_NAME(mls_rm) (in);
  UG_STORE (UG_COL (a)); UG_SAVE;
}
void ug_reference (UG_ARGS) { UG_INDEX; UG_SCALAR; UG_STORE (a); UG_SAVE; }
#ifdef __cplusplus
}
#endif
