/* Matmul interface checks.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void mmulaccneg_i32 (const int32_t *p, const int32_t *q, int32_t *out)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (p);
  __riscv_ztt_i32_1x1_t r = __riscv_ztt_mls_rm_i32_1x1 (q);
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1 (m);
  a = __riscv_ztt_mmulaccneg_2d_i32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (a));
}
void mmulatacc_i32 (const int32_t *p, const int32_t *q, int32_t *out)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (p);
  __riscv_ztt_i32_1x1_t r = __riscv_ztt_mls_rm_i32_1x1 (q);
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1 (m);
  a = __riscv_ztt_mmulatacc_2d_i32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (a));
}
void mmulataccneg_i32 (const int32_t *p, const int32_t *q, int32_t *out)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (p);
  __riscv_ztt_i32_1x1_t r = __riscv_ztt_mls_rm_i32_1x1 (q);
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1 (m);
  a = __riscv_ztt_mmulataccneg_2d_i32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (a));
}
void mmulbtacc_i32 (const int32_t *p, const int32_t *q, int32_t *out)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (p);
  __riscv_ztt_i32_1x1_t r = __riscv_ztt_mls_rm_i32_1x1 (q);
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1 (m);
  a = __riscv_ztt_mmulbtacc_2d_i32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (a));
}
void mmulbtaccneg_i32 (const int32_t *p, const int32_t *q, int32_t *out)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (p);
  __riscv_ztt_i32_1x1_t r = __riscv_ztt_mls_rm_i32_1x1 (q);
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mcopy_m2a_i32_accx1 (m);
  a = __riscv_ztt_mmulbtaccneg_2d_i32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (a));
}
void mmulaccneg_u32 (const uint32_t *p, const uint32_t *q, uint32_t *out)
{
  __riscv_ztt_u32_1x1_t m = __riscv_ztt_mls_rm_u32_1x1 (p);
  __riscv_ztt_u32_1x1_t r = __riscv_ztt_mls_rm_u32_1x1 (q);
  __riscv_ztt_u32_accx1_t a = __riscv_ztt_mcopy_m2a_u32_accx1 (m);
  a = __riscv_ztt_mmulaccneg_2d_u32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_u32_1x1 (a));
}
void mmulatacc_u32 (const uint32_t *p, const uint32_t *q, uint32_t *out)
{
  __riscv_ztt_u32_1x1_t m = __riscv_ztt_mls_rm_u32_1x1 (p);
  __riscv_ztt_u32_1x1_t r = __riscv_ztt_mls_rm_u32_1x1 (q);
  __riscv_ztt_u32_accx1_t a = __riscv_ztt_mcopy_m2a_u32_accx1 (m);
  a = __riscv_ztt_mmulatacc_2d_u32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_u32_1x1 (a));
}
void mmulataccneg_u32 (const uint32_t *p, const uint32_t *q, uint32_t *out)
{
  __riscv_ztt_u32_1x1_t m = __riscv_ztt_mls_rm_u32_1x1 (p);
  __riscv_ztt_u32_1x1_t r = __riscv_ztt_mls_rm_u32_1x1 (q);
  __riscv_ztt_u32_accx1_t a = __riscv_ztt_mcopy_m2a_u32_accx1 (m);
  a = __riscv_ztt_mmulataccneg_2d_u32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_u32_1x1 (a));
}
void mmulbtacc_u32 (const uint32_t *p, const uint32_t *q, uint32_t *out)
{
  __riscv_ztt_u32_1x1_t m = __riscv_ztt_mls_rm_u32_1x1 (p);
  __riscv_ztt_u32_1x1_t r = __riscv_ztt_mls_rm_u32_1x1 (q);
  __riscv_ztt_u32_accx1_t a = __riscv_ztt_mcopy_m2a_u32_accx1 (m);
  a = __riscv_ztt_mmulbtacc_2d_u32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_u32_1x1 (a));
}
void mmulbtaccneg_u32 (const uint32_t *p, const uint32_t *q, uint32_t *out)
{
  __riscv_ztt_u32_1x1_t m = __riscv_ztt_mls_rm_u32_1x1 (p);
  __riscv_ztt_u32_1x1_t r = __riscv_ztt_mls_rm_u32_1x1 (q);
  __riscv_ztt_u32_accx1_t a = __riscv_ztt_mcopy_m2a_u32_accx1 (m);
  a = __riscv_ztt_mmulbtaccneg_2d_u32_accx1 (a, m, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_u32_1x1 (a));
}
/* { dg-final { scan-assembler {mmulaccneg\.2d} } } */
/* { dg-final { scan-assembler {mmulatacc\.2d} } } */
/* { dg-final { scan-assembler {mmulataccneg\.2d} } } */
/* { dg-final { scan-assembler {mmulbtacc\.2d} } } */
/* { dg-final { scan-assembler {mmulbtaccneg\.2d} } } */
