#include <riscv_ztt.h>
#ifndef GD_TYPE
#define GD_TYPE u32_rnu
#define GD_ELEMENT __UINT32_TYPE__
#endif
#define GD_F_(f, t) __riscv_ztt_##f##_##t##_1x1
#define GD_F_I(f, t) GD_F_(f, t)
#define GD_F(f) GD_F_I(f, GD_TYPE)
#define GD_T_(t) __riscv_ztt_##t##_1x1_t
#define GD_T_I(t) GD_T_(t)
typedef GD_T_I(GD_TYPE) matrix_t;
typedef __riscv_ztt_u32_rnu_1x1_t index_t;
typedef GD_ELEMENT element_t;
#define GD_ARGS const element_t *in, const __UINT32_TYPE__ *indices, \
  element_t *first, element_t *out, element_t *saved, __UINT32_TYPE__ *saved_index
#define GD_LOAD matrix_t a = GD_F(mls_rm) (in); \
  index_t b = __riscv_ztt_mls_rm_u32_rnu_1x1 (indices)
#define GD_SAVE __riscv_ztt_mss_rm (saved, a); \
  __riscv_ztt_mss_rm (saved_index, b)
#ifdef __cplusplus
extern "C" {
#endif
extern void gd_callee (void);
#define GD_CASE(name, op1, op2, between) \
__attribute__((noipa)) void gd_##name (GD_ARGS) \
{ \
  GD_LOAD; \
  matrix_t p = GD_F(op1) (a, b); \
  __riscv_ztt_mss_rm (first, p); \
  between; \
  matrix_t q = GD_F(op2) (a, b); \
  __riscv_ztt_mss_rm (out, q); \
  GD_SAVE; \
}
GD_CASE(pair, mcolgather_ew, mrowgather_ew, )
GD_CASE(reverse, mrowgather_ew, mcolgather_ew, )
GD_CASE(call, mcolgather_ew, mrowgather_ew, gd_callee ())
GD_CASE(barrier, mcolgather_ew, mrowgather_ew, __asm__ volatile ("# AME state boundary" ::: "memory"))
__attribute__((noipa)) void gd_unknown (GD_ARGS)
{
  GD_LOAD;
  matrix_t q = GD_F(mrowgather_ew) (a, b);
  __riscv_ztt_mss_rm (out, q);
  GD_SAVE;
}
#ifdef __cplusplus
}
#endif
