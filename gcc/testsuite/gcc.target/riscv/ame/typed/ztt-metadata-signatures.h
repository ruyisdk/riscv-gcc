#ifndef ZTT_METADATA_SIGNATURES_H
#define ZTT_METADATA_SIGNATURES_H
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noipa)) void
metadata_integer (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
                  __INT32_TYPE__ input, long exponent)
{
  __riscv_ztt_i32_rnu_sat_scalar_t s = __riscv_ztt_scalar_make_i32_rnu_sat (input);
  __riscv_ztt_i32_rnu_sat_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_sat_1x1 (in);
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mbcast_m_x_i32_rnu_sat_1x1_i32_rnu_sat (s);
  a = __riscv_ztt_madd_ew_i32_rnu_sat_1x1 (a, b);
  a = __riscv_ztt_msub_ew_i32_rnu_sat_1x1 (a, b);
  a = __riscv_ztt_mmul_ew_i32_rnu_sat_1x1 (a, b);
  a = __riscv_ztt_mmulacc_ew_i32_rnu_sat_1x1 (a, a, b);
  a = __riscv_ztt_mmuladd_ew_i32_rnu_sat_1x1 (a, b, a);
  a = __riscv_ztt_madd_ew_x_i32_rnu_sat_1x1_i32_rnu_sat (a, s);
  a = __riscv_ztt_mmulacc_ew_x_i32_rnu_sat_1x1_i32_rnu_sat (a, a, s);
  a = __riscv_ztt_mldexp_ew_x_i32_rnu_sat_1x1 (a, exponent);
  a = __riscv_ztt_mldexpacc_ew_x_i32_rnu_sat_1x1 (a, b, exponent);
  __riscv_ztt_i32_rnu_sat_accx1_t acc = __riscv_ztt_mcopy_m2a_i32_rnu_sat_accx1 (a);
  acc = __riscv_ztt_mmulacc_2d_i32_rnu_sat_accx1 (acc, a, b);
  acc = __riscv_ztt_mmulatacc_2d_i32_rnu_sat_accx1 (acc, a, b);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_sat_1x1 (acc));
}

__attribute__((noipa)) void
metadata_floating (float *out, const float *in, float input, long exponent)
{
  __riscv_ztt_f32_rne_scalar_t s = __riscv_ztt_scalar_make_f32_rne (input);
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mls_rm_f32_rne_1x1 (in);
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mbcast_m_x_f32_rne_1x1_f32_rne (s);
  a = __riscv_ztt_madd_ew_f32_rne_1x1 (a, b);
  a = __riscv_ztt_msub_ew_f32_rne_1x1 (a, b);
  a = __riscv_ztt_mmul_ew_f32_rne_1x1 (a, b);
  a = __riscv_ztt_mmulacc_ew_f32_rne_1x1 (a, a, b);
  a = __riscv_ztt_mmulsub_ew_f32_rne_1x1 (a, b, a);
  a = __riscv_ztt_madd_ew_x_f32_rne_1x1_f32_rne (a, s);
  a = __riscv_ztt_mmulacc_ew_x_f32_rne_1x1_f32_rne (a, a, s);
  a = __riscv_ztt_msqrt_ew_f32_rne_1x1 (a);
  a = __riscv_ztt_mrec_ew_f32_rne_1x1 (a);
  a = __riscv_ztt_mlog2sub_ew_f32_rne_1x1 (a, b);
  a = __riscv_ztt_mldexp_ew_x_f32_rne_1x1 (a, exponent);
  a = __riscv_ztt_mldexpacc_ew_x_f32_rne_1x1 (a, b, exponent);
  __riscv_ztt_f32_rne_accx1_t acc = __riscv_ztt_mcopy_m2a_f32_rne_accx1 (a);
  acc = __riscv_ztt_mmulacc_2d_f32_rne_accx1 (acc, a, b);
  acc = __riscv_ztt_mmulbtacc_2d_f32_rne_accx1 (acc, a, b);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_f32_rne_1x1 (acc));
}

#ifdef __cplusplus
}
#endif
#endif
