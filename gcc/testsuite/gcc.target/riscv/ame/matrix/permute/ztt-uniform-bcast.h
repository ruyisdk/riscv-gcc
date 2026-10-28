#include <riscv_ztt.h>

#ifndef UB_TYPE
#define UB_TYPE i32_rnu
#define UB_ELEMENT __INT32_TYPE__
#endif
#define UB_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define UB_NAME_I(f, t) UB_NAME_(f, t)
#define UB_NAME(f) UB_NAME_I(f, UB_TYPE)
#ifdef UB_FROM_BITS
#define UB_MAKE_(t) __riscv_ztt_scalar_from_bits_##t
#define UB_SCALAR_INPUT ((unsigned long) value)
#else
#define UB_MAKE_(t) __riscv_ztt_scalar_make_##t
#define UB_SCALAR_INPUT value
#endif
#define UB_MAKE(t) UB_MAKE_(t)
#define UB_T_(t) __riscv_ztt_##t##_1x1_t
#define UB_T(t) UB_T_(t)
typedef UB_ELEMENT ub_element;
typedef UB_T(UB_TYPE) ub_matrix;
#define UB_ARGS ub_element value, ub_element *out, ub_element *extra, unsigned long k
#define UB_SCALAR ub_matrix a = UB_NAME(mbcast_m_x) (UB_MAKE(UB_TYPE) (UB_SCALAR_INPUT))
#define UB_ZERO ub_matrix a = UB_NAME(mzero_m) ()
#define UB_ROW(a, k) UB_NAME(mrowbcast_ew_x) (a, k)
#define UB_COL(a, k) UB_NAME(mcolbcast_ew_x) (a, k)
#define UB_STORE(a) __riscv_ztt_mss_rm (out, a)

#ifdef __cplusplus
extern "C" {
#endif
extern void ub_callee (void);
extern volatile unsigned long ub_observed;

void ub_zero_row (UB_ARGS) { UB_ZERO; UB_STORE (UB_ROW (a, 0)); }
void ub_zero_col (UB_ARGS) { UB_ZERO; UB_STORE (UB_COL (a, 0)); }
void ub_scalar_row (UB_ARGS) { UB_SCALAR; UB_STORE (UB_ROW (a, 0)); }
void ub_scalar_col (UB_ARGS) { UB_SCALAR; UB_STORE (UB_COL (a, 0)); }
void ub_high (UB_ARGS)
{
  UB_SCALAR; UB_STORE (UB_ROW (a, (unsigned long) 0xabcdef1200000000ULL));
}
void ub_copy (UB_ARGS)
{
  UB_SCALAR;
  ub_matrix b = UB_NAME(mcopy_m2m) (a);
  UB_STORE (UB_COL (b, 0));
}
void ub_shared (UB_ARGS)
{
  UB_SCALAR; UB_STORE (UB_ROW (a, 0)); __riscv_ztt_mss_rm (extra, a);
}
void ub_nonzero (UB_ARGS) { UB_SCALAR; UB_STORE (UB_ROW (a, 1)); }
void ub_dynamic (UB_ARGS) { UB_SCALAR; UB_STORE (UB_COL (a, k)); }
void ub_invalid (UB_ARGS) { UB_SCALAR; UB_STORE (UB_ROW (a, ~0UL)); }
void ub_call (UB_ARGS) { UB_SCALAR; ub_callee (); UB_STORE (UB_ROW (a, 0)); }
void ub_asm (UB_ARGS)
{
  UB_SCALAR; asm volatile ("" ::: "memory"); UB_STORE (UB_COL (a, 0));
}
void ub_memory (UB_ARGS)
{
  UB_SCALAR; ub_observed = k; UB_STORE (UB_ROW (a, 0));
}
void ub_reference (UB_ARGS) { UB_SCALAR; UB_STORE (a); }
#ifdef __cplusplus
}
#endif
