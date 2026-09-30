/* full wide source values.  */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>

void pressure (int32_t **out, const int32_t **in, size_t index, int offset)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in[0]);
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mls_rm_i32_rne_1x1 (in[1]);
  __riscv_ztt_i32_rdn_1x1_t c = __riscv_ztt_mls_rm_i32_rdn_1x1 (in[2]);
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mls_rm_i32_rod_1x1 (in[3]);
  __riscv_ztt_i32_rnu_1x1_t e = __riscv_ztt_mls_rm_i32_rnu_1x1 (in[4]);
  __riscv_ztt_i32_rne_1x1_t f = __riscv_ztt_mls_rm_i32_rne_1x1 (in[5]);
  __riscv_ztt_mss_rm (out[0], __riscv_ztt_mcolbcast_ew_x_i32_rnu_1x1 (a, index));
  __riscv_ztt_mss_rm (out[1], __riscv_ztt_mrowbcast_ew_x_i32_rne_1x1 (b, index));
  __riscv_ztt_mss_rm (out[2], __riscv_ztt_mcolshift_ew_x_i32_rdn_1x1 (c, offset));
  __riscv_ztt_mss_rm (out[3], __riscv_ztt_mrowshift_ew_x_i32_rod_1x1 (d, offset));
  __riscv_ztt_mss_rm (out[4], a);
  __riscv_ztt_mss_rm (out[5], b);
  __riscv_ztt_mss_rm (out[6], c);
  __riscv_ztt_mss_rm (out[7], d);
  __riscv_ztt_mss_rm (out[8], e);
  __riscv_ztt_mss_rm (out[9], f);
}
