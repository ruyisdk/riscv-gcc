/* mconv.ew.  */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>

void
pressure (int8_t *out, int32_t *copies, const int32_t *input, size_t stride)
{
  __riscv_ztt_i32_rod_1x4_t a0
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 0 * stride);
  __riscv_ztt_i32_rod_1x4_t a1
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 1 * stride);
  __riscv_ztt_i32_rod_1x4_t a2
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 2 * stride);
  __riscv_ztt_i32_rod_1x4_t a3
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 3 * stride);
  __riscv_ztt_i32_rod_1x4_t a4
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 4 * stride);
  __riscv_ztt_i32_rod_1x4_t a5
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 5 * stride);
  __riscv_ztt_i32_rod_1x4_t a6
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 6 * stride);
  __riscv_ztt_i32_rod_1x4_t a7
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 7 * stride);
  __riscv_ztt_i32_rod_1x4_t a8
    = __riscv_ztt_mls_rm_i32_rod_1x4 (input + 8 * stride);
  __riscv_ztt_i8_rne_1x4_t d0
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a0);
  __riscv_ztt_i8_rne_1x4_t d1
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a1);
  __riscv_ztt_i8_rne_1x4_t d2
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a2);
  __riscv_ztt_i8_rne_1x4_t d3
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a3);
  __riscv_ztt_i8_rne_1x4_t d4
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a4);
  __riscv_ztt_i8_rne_1x4_t d5
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a5);
  __riscv_ztt_i8_rne_1x4_t d6
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a6);
  __riscv_ztt_i8_rne_1x4_t d7
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a7);
  __riscv_ztt_i8_rne_1x4_t d8
    = __riscv_ztt_mconv_ew_i8_rne_1x4 (a8);
  a0 = __riscv_ztt_mzero_m_i32_rod_1x4 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (copies + 0 * stride, a0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (copies + 1 * stride, a1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (copies + 2 * stride, a2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (copies + 3 * stride, a3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (copies + 4 * stride, a4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (copies + 5 * stride, a5);
  __riscv_ztt_mss_rm (out + 6 * stride, d6);
  __riscv_ztt_mss_rm (copies + 6 * stride, a6);
  __riscv_ztt_mss_rm (out + 7 * stride, d7);
  __riscv_ztt_mss_rm (copies + 7 * stride, a7);
  __riscv_ztt_mss_rm (out + 8 * stride, d8);
  __riscv_ztt_mss_rm (copies + 8 * stride, a8);
}
