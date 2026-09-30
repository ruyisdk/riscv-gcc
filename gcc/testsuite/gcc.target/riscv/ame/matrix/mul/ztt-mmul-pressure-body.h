/* mmul.ew.  */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>

void
pressure (int8_t *dst, int32_t *left_copy, uint16_t *right_copy,
          const int32_t *left, const uint16_t *right, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t l0
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 0 * stride);
  __riscv_ztt_u16_rne_1x4_t r0
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t l1
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 1 * stride);
  __riscv_ztt_u16_rne_1x4_t r1
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t l2
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 2 * stride);
  __riscv_ztt_u16_rne_1x4_t r2
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t l3
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 3 * stride);
  __riscv_ztt_u16_rne_1x4_t r3
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t l4
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 4 * stride);
  __riscv_ztt_u16_rne_1x4_t r4
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t l5
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 5 * stride);
  __riscv_ztt_u16_rne_1x4_t r5
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t l6
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 6 * stride);
  __riscv_ztt_u16_rne_1x4_t r6
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t l7
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 7 * stride);
  __riscv_ztt_u16_rne_1x4_t r7
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 7 * stride);
  __riscv_ztt_i32_rod_1x4_t l8
    = __riscv_ztt_mls_rm_i32_rod_1x4 (left + 8 * stride);
  __riscv_ztt_u16_rne_1x4_t r8
    = __riscv_ztt_mls_rm_u16_rne_1x4 (right + 8 * stride);
  __riscv_ztt_i8_rdn_1x4_t d0
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l0, r0);
  __riscv_ztt_i8_rdn_1x4_t d1
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l1, r1);
  __riscv_ztt_i8_rdn_1x4_t d2
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l2, r2);
  __riscv_ztt_i8_rdn_1x4_t d3
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l3, r3);
  __riscv_ztt_i8_rdn_1x4_t d4
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l4, r4);
  __riscv_ztt_i8_rdn_1x4_t d5
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l5, r5);
  __riscv_ztt_i8_rdn_1x4_t d6
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l6, r6);
  __riscv_ztt_i8_rdn_1x4_t d7
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l7, r7);
  __riscv_ztt_i8_rdn_1x4_t d8
    = __riscv_ztt_mmul_ew_i8_rdn_1x4 (l8, r8);
  l0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  r0 = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 0 * stride, d0);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 0 * stride, l0);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 0 * stride, r0);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 1 * stride, d1);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 1 * stride, l1);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 1 * stride, r1);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 2 * stride, d2);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 2 * stride, l2);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 2 * stride, r2);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 3 * stride, d3);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 3 * stride, l3);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 3 * stride, r3);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 4 * stride, d4);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 4 * stride, l4);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 4 * stride, r4);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 5 * stride, d5);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 5 * stride, l5);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 5 * stride, r5);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 6 * stride, d6);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 6 * stride, l6);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 6 * stride, r6);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 7 * stride, d7);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 7 * stride, l7);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 7 * stride, r7);
  __riscv_ztt_mss_rm_i8_rdn_1x4 (dst + 8 * stride, d8);
  __riscv_ztt_mss_rm_i32_rod_1x4 (left_copy + 8 * stride, l8);
  __riscv_ztt_mss_rm_u16_rne_1x4 (right_copy + 8 * stride, r8);
}
