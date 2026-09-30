/* integer arithmetic.  */
#include <stdint.h>
#include <riscv_ztt.h>

void
accepted_rm_sign (int32_t *out, const int32_t *sp, const uint32_t *up)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (sp);
  __riscv_ztt_i32_rne_1x1_t r = __riscv_ztt_mls_rm_i32_rne_1x1 (sp);
  __riscv_ztt_u32_rnu_1x1_t u = __riscv_ztt_mls_rm_u32_rnu_1x1 (up);
  a = __riscv_ztt_msub_ew_i32_rnu_1x1 (r, a);
  a = __riscv_ztt_msub_ew_i32_rnu_1x1 (a, r);
  a = __riscv_ztt_msub_ew_i32_rnu_1x1 (u, a);
  a = __riscv_ztt_msub_ew_i32_rnu_1x1 (a, u);
  __riscv_ztt_mss_rm (out, a);
}

void
accepted_width (int16_t *out, const int16_t *ap, const uint32_t *bp)
{
  __riscv_ztt_i16_rnu_1x1_t a = __riscv_ztt_mls_rm_i16_rnu_1x1 (ap);
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mls_rm_u32_rne_1x1 (bp);
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_madd_ew_i16_rnu_1x1 (a, b);
  __riscv_ztt_mss_rm (out, d);
}

void
accepted_rounding (int8_t *out, const int8_t *ap)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mls_rm_i8_rnu_1x1 (ap);
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_madd_ew_i8_rdn_1x1 (a, a);
  __riscv_ztt_mss_rm (out, d);
}
