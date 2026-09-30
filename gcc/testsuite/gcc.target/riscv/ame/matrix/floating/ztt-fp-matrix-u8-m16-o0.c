/* Compile/assemble contracts, not AME numerical execution tests.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_floating_matrix != 1
#error missing FP matrix capability
#endif
void fp_madd_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_madd_ew_f16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_madd_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_madd_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_madd_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_madd_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_madd_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_madd_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_madd_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_madd_ew_bf16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_madd_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_madd_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msub_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_msub_ew_bf16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msub_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_msub_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msub_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_msub_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msub_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_msub_ew_bf16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msub_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_msub_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msub_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_msub_ew_f16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmul_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmul_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmul_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mmul_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmul_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mmul_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmul_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmul_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmul_rmm (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mmul_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmul_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mmul_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulneg_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmulneg_ew_f16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulneg_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mmulneg_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulneg_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmulneg_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulneg_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmulneg_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulneg_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mmulneg_ew_bf16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulneg_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmulneg_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mabsdiff_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mabsdiff_ew_bf16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mabsdiff_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mabsdiff_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mabsdiff_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mabsdiff_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mabsdiff_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mabsdiff_ew_bf16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mabsdiff_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mabsdiff_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mabsdiff_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mabsdiff_ew_f16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mhdiff_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mhdiff_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mhdiff_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mhdiff_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mhdiff_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mhdiff_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mhdiff_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mhdiff_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mhdiff_rmm (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mhdiff_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mhdiff_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mhdiff_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmean_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmean_ew_f16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmean_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mmean_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmean_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmean_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmean_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmean_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmean_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mmean_ew_bf16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmean_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmean_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmin_rne (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmin_ew_bf16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmin_rtz (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmin_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmin_rdn (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mmin_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmin_rup (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmin_ew_bf16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmin_rmm (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmin_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmin_rno (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mmin_ew_f16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmax_rne (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmax_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmax_rtz (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mmax_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmax_rdn (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mmax_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmax_rup (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmax_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmax_rmm (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mmax_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmax_rno (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mmax_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmpge_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mcmpge_ew_i16_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmpge_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mcmpge_ew_i16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmpge_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mcmpge_ew_i16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmpge_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mcmpge_ew_i16_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmpge_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mcmpge_ew_i16_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmpge_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mcmpge_ew_i16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmplt_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_i16_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmplt_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mcmplt_ew_i16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmplt_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mcmplt_ew_i16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmplt_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mcmplt_ew_i16_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmplt_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mcmplt_ew_i16_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcmplt_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mcmplt_ew_i16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mselge_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mselge_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mselge_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mselge_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mselge_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mselge_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mselge_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mselge_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mselge_rmm (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mselge_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mselge_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mselge_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msellt_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_msellt_ew_f16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msellt_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_msellt_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msellt_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_msellt_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msellt_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_msellt_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msellt_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_msellt_ew_bf16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_msellt_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_msellt_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mmulacc_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t old = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmulacc_ew_bf16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulacc_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmulacc_ew_f32_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulacc_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mmulacc_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulacc_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t old = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmulacc_ew_bf16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulacc_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmulacc_ew_f32_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulacc_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mmulacc_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulaccneg_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mmulaccneg_ew_f32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulaccneg_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mmulaccneg_ew_f16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulaccneg_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t old = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mmulaccneg_ew_bf16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulaccneg_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mmulaccneg_ew_f32_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulaccneg_rmm (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mmulaccneg_ew_f16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulaccneg_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t old = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mmulaccneg_ew_bf16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmuladd_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mmuladd_ew_f16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmuladd_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t old = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mmuladd_ew_bf16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmuladd_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mmuladd_ew_f32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmuladd_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mmuladd_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmuladd_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t old = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mmuladd_ew_bf16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmuladd_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mmuladd_ew_f32_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulsub_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t b = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t old = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mmulsub_ew_bf16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulsub_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t b = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mmulsub_ew_f32_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulsub_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t b = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mmulsub_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulsub_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f16_rno_1x1_t b = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t old = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mmulsub_ew_bf16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulsub_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t b = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mmulsub_ew_f32_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mmulsub_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t b = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mmulsub_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovge_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f32_rne_1x1_t b = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mcmovge_ew_f32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovge_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t b = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mcmovge_ew_f16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovge_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t b = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t old = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mcmovge_ew_bf16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovge_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f32_rup_1x1_t b = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mcmovge_ew_f32_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovge_rmm (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mcmovge_ew_f16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovge_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t old = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mcmovge_ew_bf16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovlt_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mcmovlt_ew_f16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovlt_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t b = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t old = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mcmovlt_ew_bf16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovlt_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mcmovlt_ew_f32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovlt_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f16_rup_1x1_t b = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mcmovlt_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovlt_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t b = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t old = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mcmovlt_ew_bf16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcmovlt_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f32_rno_1x1_t b = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mcmovlt_ew_f32_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_integer_madd (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_madd_ew_i16_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_msub (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_msub_ew_i16_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_mmul (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmul_ew_i16_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_mmulneg (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mmulneg_ew_i16_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_mabsdiff (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mabsdiff_ew_i16_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_mhdiff (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mhdiff_ew_i16_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_mmean (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmean_ew_i16_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_integer_mmulacc (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mmulacc_ew_i16_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_integer_mmulaccneg (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mmulaccneg_ew_i16_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_integer_mmuladd (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mmuladd_ew_i16_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_integer_mmulsub (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mmulsub_ew_i16_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolgather_rne (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mcolgather_ew_f16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcolgather_rtz (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mcolgather_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcolgather_rdn (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mcolgather_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcolgather_rup (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mcolgather_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcolgather_rmm (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mcolgather_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcolgather_rno (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mcolgather_ew_f16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mrowgather_rne (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mrowgather_ew_f16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mrowgather_rtz (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mrowgather_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mrowgather_rdn (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mrowgather_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mrowgather_rup (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mrowgather_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mrowgather_rmm (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mrowgather_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mrowgather_rno (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mrowgather_ew_f16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_mcolscatadd_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mcolscatadd_ew_f16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatadd_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mcolscatadd_ew_f16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatadd_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mcolscatadd_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatadd_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mcolscatadd_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatadd_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mcolscatadd_ew_f16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatadd_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mcolscatadd_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatadd_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mrowscatadd_ew_f16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatadd_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mrowscatadd_ew_f16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatadd_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mrowscatadd_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatadd_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mrowscatadd_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatadd_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mrowscatadd_ew_f16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatadd_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mrowscatadd_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatmax_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mcolscatmax_ew_f16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatmax_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mcolscatmax_ew_f16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatmax_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mcolscatmax_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatmax_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mcolscatmax_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatmax_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mcolscatmax_ew_f16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mcolscatmax_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mcolscatmax_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatmax_rne (void)
{
  __riscv_ztt_f16_rtz_1x1_t a = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rne_1x1_t old = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_f16_rne_1x1_t d = __riscv_ztt_mrowscatmax_ew_f16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatmax_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t old = __riscv_ztt_mzero_m_f16_rtz_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mrowscatmax_ew_f16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatmax_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mrowscatmax_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatmax_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mrowscatmax_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatmax_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t old = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mrowscatmax_ew_f16_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void fp_mrowscatmax_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mrowscatmax_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
