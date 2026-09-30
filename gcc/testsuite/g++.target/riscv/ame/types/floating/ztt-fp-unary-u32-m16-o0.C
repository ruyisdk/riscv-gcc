/* Compilation checks only; no AME numerical execution is implied.  */
/* { dg-do assemble } */
/* { dg-options "-O0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void fp_mfrintm_rne (void)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mfrintm_ew_f16_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintm_rtz (void)
{
  __riscv_ztt_f32_rdn_2x1_t a = __riscv_ztt_mzero_m_f32_rdn_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mfrintm_ew_bf16_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintm_rdn (void)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mzero_m_f64_rup_1x2 ();
  __riscv_ztt_f32_rdn_1x2_t d = __riscv_ztt_mfrintm_ew_f32_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintm_rup (void)
{
  __riscv_ztt_f16_rmm_2x1_t a = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f64_rup_2x1_t d = __riscv_ztt_mfrintm_ew_f64_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintm_rmm (void)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mfrintm_ew_f16_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintm_rno (void)
{
  __riscv_ztt_f32_rne_2x1_t a = __riscv_ztt_mzero_m_f32_rne_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_mfrintm_ew_bf16_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintn_rne (void)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mzero_m_f32_rtz_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mfrintn_ew_bf16_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintn_rtz (void)
{
  __riscv_ztt_f64_rdn_2x1_t a = __riscv_ztt_mzero_m_f64_rdn_2x1 ();
  __riscv_ztt_f32_rtz_2x1_t d = __riscv_ztt_mfrintn_ew_f32_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintn_rdn (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f64_rdn_1x2_t d = __riscv_ztt_mfrintn_ew_f64_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintn_rup (void)
{
  __riscv_ztt_bf16_rmm_2x1_t a = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_mfrintn_ew_f16_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintn_rmm (void)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mzero_m_f32_rno_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mfrintn_ew_bf16_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintn_rno (void)
{
  __riscv_ztt_f64_rne_2x1_t a = __riscv_ztt_mzero_m_f64_rne_2x1 ();
  __riscv_ztt_f32_rno_2x1_t d = __riscv_ztt_mfrintn_ew_f32_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintp_rne (void)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mzero_m_f64_rtz_1x2 ();
  __riscv_ztt_f32_rne_1x2_t d = __riscv_ztt_mfrintp_ew_f32_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintp_rtz (void)
{
  __riscv_ztt_f16_rdn_2x1_t a = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f64_rtz_2x1_t d = __riscv_ztt_mfrintp_ew_f64_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintp_rdn (void)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mfrintp_ew_f16_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintp_rup (void)
{
  __riscv_ztt_f32_rmm_2x1_t a = __riscv_ztt_mzero_m_f32_rmm_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mfrintp_ew_bf16_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintp_rmm (void)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mzero_m_f64_rno_1x2 ();
  __riscv_ztt_f32_rmm_1x2_t d = __riscv_ztt_mfrintp_ew_f32_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintp_rno (void)
{
  __riscv_ztt_f16_rne_2x1_t a = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f64_rno_2x1_t d = __riscv_ztt_mfrintp_ew_f64_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintz_rne (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f64_rne_1x2_t d = __riscv_ztt_mfrintz_ew_f64_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintz_rtz (void)
{
  __riscv_ztt_bf16_rdn_2x1_t a = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_mfrintz_ew_f16_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintz_rdn (void)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mzero_m_f32_rup_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_mfrintz_ew_bf16_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintz_rup (void)
{
  __riscv_ztt_f64_rmm_2x1_t a = __riscv_ztt_mzero_m_f64_rmm_2x1 ();
  __riscv_ztt_f32_rup_2x1_t d = __riscv_ztt_mfrintz_ew_f32_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintz_rmm (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f64_rmm_1x2_t d = __riscv_ztt_mfrintz_ew_f64_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mfrintz_rno (void)
{
  __riscv_ztt_bf16_rne_2x1_t a = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_mfrintz_ew_f16_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mexp2_rne (void)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mexp2_ew_f16_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mexp2_rtz (void)
{
  __riscv_ztt_f32_rdn_2x1_t a = __riscv_ztt_mzero_m_f32_rdn_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mexp2_ew_bf16_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mexp2_rdn (void)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mzero_m_f64_rup_1x2 ();
  __riscv_ztt_f32_rdn_1x2_t d = __riscv_ztt_mexp2_ew_f32_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mexp2_rup (void)
{
  __riscv_ztt_f16_rmm_2x1_t a = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f64_rup_2x1_t d = __riscv_ztt_mexp2_ew_f64_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mexp2_rmm (void)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mexp2_ew_f16_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mexp2_rno (void)
{
  __riscv_ztt_f32_rne_2x1_t a = __riscv_ztt_mzero_m_f32_rne_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_mexp2_ew_bf16_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mlog2_rne (void)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mzero_m_f32_rtz_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mlog2_ew_bf16_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mlog2_rtz (void)
{
  __riscv_ztt_f64_rdn_2x1_t a = __riscv_ztt_mzero_m_f64_rdn_2x1 ();
  __riscv_ztt_f32_rtz_2x1_t d = __riscv_ztt_mlog2_ew_f32_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mlog2_rdn (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f64_rdn_1x2_t d = __riscv_ztt_mlog2_ew_f64_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mlog2_rup (void)
{
  __riscv_ztt_bf16_rmm_2x1_t a = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_mlog2_ew_f16_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mlog2_rmm (void)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mzero_m_f32_rno_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mlog2_ew_bf16_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mlog2_rno (void)
{
  __riscv_ztt_f64_rne_2x1_t a = __riscv_ztt_mzero_m_f64_rne_2x1 ();
  __riscv_ztt_f32_rno_2x1_t d = __riscv_ztt_mlog2_ew_f32_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mcos_rne (void)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mzero_m_f64_rtz_1x2 ();
  __riscv_ztt_f32_rne_1x2_t d = __riscv_ztt_mcos_ew_f32_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mcos_rtz (void)
{
  __riscv_ztt_f16_rdn_2x1_t a = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f64_rtz_2x1_t d = __riscv_ztt_mcos_ew_f64_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mcos_rdn (void)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mcos_ew_f16_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mcos_rup (void)
{
  __riscv_ztt_f32_rmm_2x1_t a = __riscv_ztt_mzero_m_f32_rmm_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mcos_ew_bf16_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mcos_rmm (void)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mzero_m_f64_rno_1x2 ();
  __riscv_ztt_f32_rmm_1x2_t d = __riscv_ztt_mcos_ew_f32_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mcos_rno (void)
{
  __riscv_ztt_f16_rne_2x1_t a = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f64_rno_2x1_t d = __riscv_ztt_mcos_ew_f64_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msin_rne (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f64_rne_1x2_t d = __riscv_ztt_msin_ew_f64_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msin_rtz (void)
{
  __riscv_ztt_bf16_rdn_2x1_t a = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_msin_ew_f16_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msin_rdn (void)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mzero_m_f32_rup_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_msin_ew_bf16_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msin_rup (void)
{
  __riscv_ztt_f64_rmm_2x1_t a = __riscv_ztt_mzero_m_f64_rmm_2x1 ();
  __riscv_ztt_f32_rup_2x1_t d = __riscv_ztt_msin_ew_f32_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msin_rmm (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f64_rmm_1x2_t d = __riscv_ztt_msin_ew_f64_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msin_rno (void)
{
  __riscv_ztt_bf16_rne_2x1_t a = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_msin_ew_f16_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mtanh_rne (void)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mtanh_ew_f16_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mtanh_rtz (void)
{
  __riscv_ztt_f32_rdn_2x1_t a = __riscv_ztt_mzero_m_f32_rdn_2x1 ();
  __riscv_ztt_bf16_rtz_2x1_t d = __riscv_ztt_mtanh_ew_bf16_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mtanh_rdn (void)
{
  __riscv_ztt_f64_rup_1x2_t a = __riscv_ztt_mzero_m_f64_rup_1x2 ();
  __riscv_ztt_f32_rdn_1x2_t d = __riscv_ztt_mtanh_ew_f32_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mtanh_rup (void)
{
  __riscv_ztt_f16_rmm_2x1_t a = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f64_rup_2x1_t d = __riscv_ztt_mtanh_ew_f64_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mtanh_rmm (void)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mtanh_ew_f16_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mtanh_rno (void)
{
  __riscv_ztt_f32_rne_2x1_t a = __riscv_ztt_mzero_m_f32_rne_2x1 ();
  __riscv_ztt_bf16_rno_2x1_t d = __riscv_ztt_mtanh_ew_bf16_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrec_rne (void)
{
  __riscv_ztt_f32_rtz_1x2_t a = __riscv_ztt_mzero_m_f32_rtz_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mrec_ew_bf16_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrec_rtz (void)
{
  __riscv_ztt_f64_rdn_2x1_t a = __riscv_ztt_mzero_m_f64_rdn_2x1 ();
  __riscv_ztt_f32_rtz_2x1_t d = __riscv_ztt_mrec_ew_f32_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrec_rdn (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f64_rdn_1x2_t d = __riscv_ztt_mrec_ew_f64_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrec_rup (void)
{
  __riscv_ztt_bf16_rmm_2x1_t a = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_mrec_ew_f16_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrec_rmm (void)
{
  __riscv_ztt_f32_rno_1x2_t a = __riscv_ztt_mzero_m_f32_rno_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mrec_ew_bf16_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrec_rno (void)
{
  __riscv_ztt_f64_rne_2x1_t a = __riscv_ztt_mzero_m_f64_rne_2x1 ();
  __riscv_ztt_f32_rno_2x1_t d = __riscv_ztt_mrec_ew_f32_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrsqrt_rne (void)
{
  __riscv_ztt_f64_rtz_1x2_t a = __riscv_ztt_mzero_m_f64_rtz_1x2 ();
  __riscv_ztt_f32_rne_1x2_t d = __riscv_ztt_mrsqrt_ew_f32_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrsqrt_rtz (void)
{
  __riscv_ztt_f16_rdn_2x1_t a = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f64_rtz_2x1_t d = __riscv_ztt_mrsqrt_ew_f64_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrsqrt_rdn (void)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mrsqrt_ew_f16_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrsqrt_rup (void)
{
  __riscv_ztt_f32_rmm_2x1_t a = __riscv_ztt_mzero_m_f32_rmm_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mrsqrt_ew_bf16_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrsqrt_rmm (void)
{
  __riscv_ztt_f64_rno_1x2_t a = __riscv_ztt_mzero_m_f64_rno_1x2 ();
  __riscv_ztt_f32_rmm_1x2_t d = __riscv_ztt_mrsqrt_ew_f32_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_mrsqrt_rno (void)
{
  __riscv_ztt_f16_rne_2x1_t a = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f64_rno_2x1_t d = __riscv_ztt_mrsqrt_ew_f64_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msqrt_rne (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f64_rne_1x2_t d = __riscv_ztt_msqrt_ew_f64_rne_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msqrt_rtz (void)
{
  __riscv_ztt_bf16_rdn_2x1_t a = __riscv_ztt_mzero_m_bf16_rdn_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_msqrt_ew_f16_rtz_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msqrt_rdn (void)
{
  __riscv_ztt_f32_rup_1x2_t a = __riscv_ztt_mzero_m_f32_rup_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_msqrt_ew_bf16_rdn_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msqrt_rup (void)
{
  __riscv_ztt_f64_rmm_2x1_t a = __riscv_ztt_mzero_m_f64_rmm_2x1 ();
  __riscv_ztt_f32_rup_2x1_t d = __riscv_ztt_msqrt_ew_f32_rup_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msqrt_rmm (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f64_rmm_1x2_t d = __riscv_ztt_msqrt_ew_f64_rmm_1x2 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_msqrt_rno (void)
{
  __riscv_ztt_bf16_rne_2x1_t a = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_msqrt_ew_f16_rno_2x1 (a);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a));
}
void fp_value_rne (void)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_accx2_t c = __riscv_ztt_mcopy_m2a_f16_rne_accx2 (a);
  __riscv_ztt_f16_rne_accx2_t old = c;
  c = __riscv_ztt_mzero_acc_f16_rne_accx2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mcopy_a2m_f16_rne_1x2 (old);
  __asm__ volatile ("" : : "Wmr" (d), "War" (c));
}
void fp_value_rtz (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_accx2_t c = __riscv_ztt_mcopy_m2a_f16_rtz_accx2 (a);
  __riscv_ztt_f16_rtz_accx2_t old = c;
  c = __riscv_ztt_mzero_acc_f16_rtz_accx2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mcopy_a2m_f16_rtz_1x2 (old);
  __asm__ volatile ("" : : "Wmr" (d), "War" (c));
}
void fp_value_rdn (void)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_f16_rdn_accx2_t c = __riscv_ztt_mcopy_m2a_f16_rdn_accx2 (a);
  __riscv_ztt_f16_rdn_accx2_t old = c;
  c = __riscv_ztt_mzero_acc_f16_rdn_accx2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mcopy_a2m_f16_rdn_1x2 (old);
  __asm__ volatile ("" : : "Wmr" (d), "War" (c));
}
void fp_value_rup (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_f16_rup_accx2_t c = __riscv_ztt_mcopy_m2a_f16_rup_accx2 (a);
  __riscv_ztt_f16_rup_accx2_t old = c;
  c = __riscv_ztt_mzero_acc_f16_rup_accx2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mcopy_a2m_f16_rup_1x2 (old);
  __asm__ volatile ("" : : "Wmr" (d), "War" (c));
}
void fp_value_rmm (void)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_accx2_t c = __riscv_ztt_mcopy_m2a_f16_rmm_accx2 (a);
  __riscv_ztt_f16_rmm_accx2_t old = c;
  c = __riscv_ztt_mzero_acc_f16_rmm_accx2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mcopy_a2m_f16_rmm_1x2 (old);
  __asm__ volatile ("" : : "Wmr" (d), "War" (c));
}
void fp_value_rno (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_accx2_t c = __riscv_ztt_mcopy_m2a_f16_rno_accx2 (a);
  __riscv_ztt_f16_rno_accx2_t old = c;
  c = __riscv_ztt_mzero_acc_f16_rno_accx2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mcopy_a2m_f16_rno_1x2 (old);
  __asm__ volatile ("" : : "Wmr" (d), "War" (c));
}
void fp_to_integer_mconv_ew (void)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mconv_ew_i16_rnu_sat_1x2 (a);
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mconv_ew_f16_rne_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mabs_ew (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mabs_ew_i16_rne_sat_1x2 (a);
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mabs_ew_f16_rtz_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mreduceadd_col (void)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mreduceadd_col_i16_rdn_sat_1x2 (a);
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mreduceadd_col_f16_rdn_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mreduceadd_row (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mreduceadd_row_i16_rod_sat_1x2 (a);
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mreduceadd_row_f16_rup_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mreducemax_col (void)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mreducemax_col_i16_rnu_sat_1x2 (a);
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mreducemax_col_f16_rmm_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mreducemax_row (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mreducemax_row_i16_rne_sat_1x2 (a);
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mreducemax_row_f16_rno_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mreducemin_col (void)
{
  __riscv_ztt_f16_rne_1x2_t a = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mreducemin_col_i16_rdn_sat_1x2 (a);
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mreducemin_col_f16_rne_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mreducemin_row (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mreducemin_row_i16_rod_sat_1x2 (a);
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mreducemin_row_f16_rtz_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mprefixadd_col (void)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t b = __riscv_ztt_mprefixadd_col_i16_rnu_sat_1x2 (a);
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mprefixadd_col_f16_rdn_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mprefixadd_row (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mprefixadd_row_i16_rne_sat_1x2 (a);
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mprefixadd_row_f16_rup_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mprefixmax_col (void)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t b = __riscv_ztt_mprefixmax_col_i16_rdn_sat_1x2 (a);
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mprefixmax_col_f16_rmm_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void fp_to_integer_mprefixmax_row (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mprefixmax_row_i16_rod_sat_1x2 (a);
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mprefixmax_row_f16_rno_1x2 (b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
