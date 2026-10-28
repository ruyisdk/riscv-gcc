#include <riscv_ztt.h>
typedef __INT32_TYPE__ i32;
typedef __INT8_TYPE__ i8;

#ifdef __cplusplus
extern "C" {
#endif

extern i32 post_limit (i32);

#define PROBE(NAME, ELEMENT, TYPE, ROW, COL, CALL, LIVE) \
void NAME (i32 *out, i32 *saved, const i32 *initial, \
           const ELEMENT *a, const ELEMENT *b, const i32 *bias, i32 upper) \
{ \
  __riscv_ztt_i32_rnu_accx1_t acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 \
    (__riscv_ztt_mls_rm_i32_rnu_1x1 (initial)); \
  __riscv_ztt_##TYPE##_rnu_##ROW##_t av = __riscv_ztt_mls_rm_##TYPE##_rnu_##ROW (a); \
  __riscv_ztt_##TYPE##_rnu_##COL##_t bv = __riscv_ztt_mls_rm_##TYPE##_rnu_##COL (b); \
  acc = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (acc, av, bv); \
  __riscv_ztt_i32_rnu_1x1_t raw = __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (acc); \
  __riscv_ztt_i32_rnu_1x1_t biasv = __riscv_ztt_mls_st_i32_rnu_1x1 (bias, 0); \
  __riscv_ztt_i32_rnu_1x1_t y = __riscv_ztt_madd_ew_i32_rnu_1x1 (raw, biasv); \
  if (CALL) upper = post_limit (upper); \
  y = __riscv_ztt_mmax_ew_x_i32_rnu_1x1_i32_rnu \
    (y, __riscv_ztt_scalar_make_i32_rnu (0)); \
  y = __riscv_ztt_mmin_ew_x_i32_rnu_1x1_i32_rnu \
    (y, __riscv_ztt_scalar_make_i32_rnu (upper)); \
  __riscv_ztt_mss_rm (out, y); \
  if (LIVE) __riscv_ztt_mss_rm (saved, raw); \
}

PROBE (post_i32, i32, i32, 1x1, 1x1, 0, 0)
PROBE (post_i32_call, i32, i32, 1x1, 1x1, 1, 0)
PROBE (post_i32_live, i32, i32, 1x1, 1x1, 0, 1)
PROBE (post_i8, i8, i8, 1x4, 4x1, 0, 0)
PROBE (post_i8_call, i8, i8, 1x4, 4x1, 1, 0)
PROBE (post_i8_live, i8, i8, 1x4, 4x1, 0, 1)

#ifdef __cplusplus
}
#endif
