#ifndef ZTT_DECL_STORAGE_H
#define ZTT_DECL_STORAGE_H
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noipa)) void
decl_integer (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
              __INT32_TYPE__ input)
{
  __riscv_ztt_i32_rnu_sat_scalar_t s
    = __riscv_ztt_scalar_make_i32_rnu_sat (input);
  __riscv_ztt_i32_rnu_sat_1x1_t a
    = __riscv_ztt_mls_rm_i32_rnu_sat_1x1 (in);
  __riscv_ztt_i32_rnu_sat_1x1_t b
    = __riscv_ztt_mbcast_m_x_i32_rnu_sat_1x1_i32_rnu_sat (s);
  a = __riscv_ztt_mmul_ew_i32_rnu_sat_1x1 (a, b);
  a = __riscv_ztt_madd_ew_x_i32_rnu_sat_1x1_i32_rnu_sat (a, s);
  a = __riscv_ztt_mmul_ew_i32_rnu_sat_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
}

__attribute__((noipa)) void
decl_floating (float *out, const float *in, float input, long exponent)
{
  __riscv_ztt_f32_rne_scalar_t s = __riscv_ztt_scalar_make_f32_rne (input);
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f32_rne_1x1_t b
    = __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne (s);
  a = __riscv_ztt_mmul_ew_f32_rne_1x1 (a, b);
  a = __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne (a, s);
  a = __riscv_ztt_msqrt_ew_f32_rne_1x1 (a);
  a = __riscv_ztt_mlog2sub_ew_f32_rne_1x1 (a, b);
  a = __riscv_ztt_mldexp_ew_x_f32_rne_1x1 (a, exponent);
  a = __riscv_ztt_mmul_ew_f32_rne_1x1 (a, b);
  __riscv_ztt_mss_rm (out, a);
}

#ifdef __cplusplus
}
#endif
#endif
