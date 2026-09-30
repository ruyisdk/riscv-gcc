/* single-M
   i8 integer rounding-mode subset.  */

#include <riscv_ztt.h>

void
mixed_pressure (const signed char *const *in, signed char *const *out)
{
  __riscv_ztt_i8_rnu_1x1_t v0
    = __riscv_ztt_mls_rm_i8_rnu_1x1 (in[0]);
  __riscv_ztt_i8_rne_1x1_t v1
    = __riscv_ztt_mls_rm_i8_rne_1x1 (in[1]);
  __riscv_ztt_i8_rdn_1x1_t v2
    = __riscv_ztt_mls_rm_i8_rdn_1x1 (in[2]);
  __riscv_ztt_i8_rod_1x1_t v3
    = __riscv_ztt_mls_rm_i8_rod_1x1 (in[3]);
  __riscv_ztt_i8_rnu_1x1_t v4
    = __riscv_ztt_mls_rm_i8_rnu_1x1 (in[4]);
  __riscv_ztt_i8_rne_1x1_t v5
    = __riscv_ztt_mls_rm_i8_rne_1x1 (in[5]);
  __riscv_ztt_i8_rdn_1x1_t v6
    = __riscv_ztt_mls_rm_i8_rdn_1x1 (in[6]);
  __riscv_ztt_i8_rod_1x1_t v7
    = __riscv_ztt_mls_rm_i8_rod_1x1 (in[7]);
  __riscv_ztt_i8_rnu_1x1_t v8
    = __riscv_ztt_mls_rm_i8_rnu_1x1 (in[8]);
  __riscv_ztt_i8_rne_1x1_t v9
    = __riscv_ztt_mls_rm_i8_rne_1x1 (in[9]);
  __riscv_ztt_i8_rdn_1x1_t v10
    = __riscv_ztt_mls_rm_i8_rdn_1x1 (in[10]);
  __riscv_ztt_i8_rod_1x1_t v11
    = __riscv_ztt_mls_rm_i8_rod_1x1 (in[11]);
  __riscv_ztt_i8_rnu_1x1_t v12
    = __riscv_ztt_mls_rm_i8_rnu_1x1 (in[12]);
  __riscv_ztt_i8_rne_1x1_t v13
    = __riscv_ztt_mls_rm_i8_rne_1x1 (in[13]);
  __riscv_ztt_i8_rdn_1x1_t v14
    = __riscv_ztt_mls_rm_i8_rdn_1x1 (in[14]);
  __riscv_ztt_i8_rod_1x1_t v15
    = __riscv_ztt_mls_rm_i8_rod_1x1 (in[15]);
  __riscv_ztt_i8_rnu_1x1_t v16
    = __riscv_ztt_mls_rm_i8_rnu_1x1 (in[16]);

  __asm__ volatile ("" ::: "memory");

  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
  __riscv_ztt_mss_rm (out[5], v5);
  __riscv_ztt_mss_rm (out[6], v6);
  __riscv_ztt_mss_rm (out[7], v7);
  __riscv_ztt_mss_rm (out[8], v8);
  __riscv_ztt_mss_rm (out[9], v9);
  __riscv_ztt_mss_rm (out[10], v10);
  __riscv_ztt_mss_rm (out[11], v11);
  __riscv_ztt_mss_rm (out[12], v12);
  __riscv_ztt_mss_rm (out[13], v13);
  __riscv_ztt_mss_rm (out[14], v14);
  __riscv_ztt_mss_rm (out[15], v15);
  __riscv_ztt_mss_rm (out[16], v16);
}
