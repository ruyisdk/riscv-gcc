#include <riscv_ztt.h>

typedef __INT32_TYPE__ i32;
typedef __INT8_TYPE__ i8;
extern i32 offset_limit (i32);

#define TILE(V, OFFSET) \
  __riscv_ztt_i32_rnu_accx1_t V##acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 \
    (__riscv_ztt_mls_rm_i32_rnu_1x1 (initial + (OFFSET))); \
  V##acc = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (V##acc, \
    __riscv_ztt_mls_rm_i32_rnu_1x1 (a + (OFFSET)), \
    __riscv_ztt_mls_rm_i32_rnu_1x1 (b + (OFFSET))); \
  __riscv_ztt_i32_rnu_1x1_t V = __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (V##acc)

void
stack_offsets (i8 *out, i32 *saved, const i32 *initial, const i32 *a,
	       const i32 *b, const i32 *bias, __SIZE_TYPE__ tile, i32 limit)
{
  TILE (v0, 0); TILE (v1, tile); TILE (v2, 2 * tile); TILE (v3, 3 * tile);
  __riscv_ztt_i32_rnu_1x4_t raw = __riscv_ztt_mconcat_m_i32_rnu_1x4
    (__riscv_ztt_mconcat_m_i32_rnu_1x2 (v0, v1),
     __riscv_ztt_mconcat_m_i32_rnu_1x2 (v2, v3));
  __riscv_ztt_i32_rnu_1x4_t y = __riscv_ztt_madd_ew_i32_rnu_1x4
    (raw, __riscv_ztt_mls_rm_i32_rnu_1x4 (bias));
  limit = offset_limit (limit);
  y = __riscv_ztt_mmax_ew_x_i32_rnu_1x4_i32_rnu
    (y, __riscv_ztt_scalar_make_i32_rnu (0));
  y = __riscv_ztt_mmin_ew_x_i32_rnu_1x4_i32_rnu
    (y, __riscv_ztt_scalar_make_i32_rnu (limit));
  __riscv_ztt_mss_rm (out, __riscv_ztt_mconv_ew_i8_rnu_1x4 (y));
}
#undef TILE
