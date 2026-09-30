/* basic-square indexed API.  */
#include <stdint.h>
#include <stddef.h>
#include <riscv_ztt.h>

void
pressure (int32_t *out, int32_t *copies, const int32_t *input,
          const uint32_t *contributions, const int16_t *indices,
          uint32_t *data_copy, int16_t *index_copy, size_t stride)
{
  __riscv_ztt_i32_rne_1x1_t a0
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 0 * stride);
  __riscv_ztt_i32_rne_1x1_t a1
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 1 * stride);
  __riscv_ztt_i32_rne_1x1_t a2
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 2 * stride);
  __riscv_ztt_i32_rne_1x1_t a3
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 3 * stride);
  __riscv_ztt_i32_rne_1x1_t a4
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 4 * stride);
  __riscv_ztt_i32_rne_1x1_t a5
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 5 * stride);
  __riscv_ztt_i32_rne_1x1_t a6
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 6 * stride);
  __riscv_ztt_i32_rne_1x1_t a7
    = __riscv_ztt_mls_rm_i32_rne_1x1 (input + 7 * stride);
  __riscv_ztt_u32_rod_1x1_t data
    = __riscv_ztt_mls_rm_u32_rod_1x1 (contributions);
  __riscv_ztt_i16_rdn_1x1_t index
    = __riscv_ztt_mls_rm_i16_rdn_1x1 (indices);
  __riscv_ztt_i32_rne_1x1_t d0
    = __riscv_ztt_mcolgather_ew_i32_rne_1x1 (a0, index);
  __riscv_ztt_i32_rne_1x1_t d1
    = __riscv_ztt_mrowgather_ew_i32_rne_1x1 (a1, index);
  __riscv_ztt_i32_rne_1x1_t d2
    = __riscv_ztt_mcolscatadd_ew_i32_rne_1x1 (a2, data, index);
  __riscv_ztt_i32_rne_1x1_t d3
    = __riscv_ztt_mrowscatadd_ew_i32_rne_1x1 (a3, data, index);
  __riscv_ztt_i32_rne_1x1_t d4
    = __riscv_ztt_mcolscatmax_ew_i32_rne_1x1 (a4, data, index);
  __riscv_ztt_i32_rne_1x1_t d5
    = __riscv_ztt_mrowscatmax_ew_i32_rne_1x1 (a5, data, index);
  a0 = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_mss_rm (out + 0 * stride, d0);
  __riscv_ztt_mss_rm (out + 1 * stride, d1);
  __riscv_ztt_mss_rm (out + 2 * stride, d2);
  __riscv_ztt_mss_rm (out + 3 * stride, d3);
  __riscv_ztt_mss_rm (out + 4 * stride, d4);
  __riscv_ztt_mss_rm (out + 5 * stride, d5);
  __riscv_ztt_mss_rm (copies + 0 * stride, a0);
  __riscv_ztt_mss_rm (copies + 1 * stride, a1);
  __riscv_ztt_mss_rm (copies + 2 * stride, a2);
  __riscv_ztt_mss_rm (copies + 3 * stride, a3);
  __riscv_ztt_mss_rm (copies + 4 * stride, a4);
  __riscv_ztt_mss_rm (copies + 5 * stride, a5);
  __riscv_ztt_mss_rm (copies + 6 * stride, a6);
  __riscv_ztt_mss_rm (copies + 7 * stride, a7);
  __riscv_ztt_mss_rm (data_copy, data);
  __riscv_ztt_mss_rm (index_copy, index);
}
