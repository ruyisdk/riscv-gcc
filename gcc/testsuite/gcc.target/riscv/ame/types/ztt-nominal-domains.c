/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void fp_madd (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_madd_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_msub (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_msub_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmul (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmul_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mabsdiff (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mabsdiff_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mhdiff (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mhdiff_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmean (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmean_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmulneg (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmulneg_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmin (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmin_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmax (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmax_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmulacc (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmulacc_ew_x_f32_1x1 (m, m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmulaccneg (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmulaccneg_ew_x_f32_1x1 (m, m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmuladd (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmuladd_ew_x_f32_1x1 (m, m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mmulsub (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mmulsub_ew_x_f32_1x1 (m, m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mcmpge (int32_t *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mcmpge_ew_x_i32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mcmplt (int32_t *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_i32_1x1_t d = __riscv_ztt_mcmplt_ew_x_i32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_mlog2sub (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_mlog2sub_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void fp_msublog2 (float *out, const float *in, uint16_t bits)
{
  __riscv_ztt_f32_1x1_t m = __riscv_ztt_mls_rm_f32_1x1 (in);
  __riscv_ztt_f16_rno_scalar_t s = __riscv_ztt_scalar_from_bits_f16_rno (bits);
  __riscv_ztt_f32_1x1_t d = __riscv_ztt_msublog2_ew_x_f32_1x1 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
void mixed_sat (int32_t *out, const uint64_t *in, int8_t input)
{
  __riscv_ztt_u64_1x2_t m = __riscv_ztt_mls_rm_u64_1x2 (in);
  __riscv_ztt_i8_rdn_scalar_t s = __riscv_ztt_scalar_make_i8_rdn (input);
  __riscv_ztt_i32_rne_sat_1x2_t d
    = __riscv_ztt_msub_ew_x_i32_rne_sat_1x2 (m, s);
  __riscv_ztt_mss_rm (out, d);
}
/* { dg-final { scan-assembler "madd.ew.x" } } */
/* { dg-final { scan-assembler "msub.ew.x" } } */
/* { dg-final { scan-assembler "mmul.ew.x" } } */
/* { dg-final { scan-assembler "mabsdiff.ew.x" } } */
/* { dg-final { scan-assembler "mhdiff.ew.x" } } */
/* { dg-final { scan-assembler "mmean.ew.x" } } */
/* { dg-final { scan-assembler "mmulneg.ew.x" } } */
/* { dg-final { scan-assembler "mmin.ew.x" } } */
/* { dg-final { scan-assembler "mmax.ew.x" } } */
/* { dg-final { scan-assembler "mmulacc.ew.x" } } */
/* { dg-final { scan-assembler "mmulaccneg.ew.x" } } */
/* { dg-final { scan-assembler "mmuladd.ew.x" } } */
/* { dg-final { scan-assembler "mmulsub.ew.x" } } */
/* { dg-final { scan-assembler "mcmpge.ew.x" } } */
/* { dg-final { scan-assembler "mcmplt.ew.x" } } */
/* { dg-final { scan-assembler "mlog2sub.ew.x" } } */
/* { dg-final { scan-assembler "msublog2.ew.x" } } */
/* { dg-final { scan-assembler-not {call[ \t]+__riscv_ztt_} } } */
