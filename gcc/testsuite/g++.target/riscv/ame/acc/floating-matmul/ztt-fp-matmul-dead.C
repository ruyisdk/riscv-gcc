/* Selected compiler checks, not floating arithmetic execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -ffast-math -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -ffast-math -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
unsigned long dead_fp (void)
{
  __riscv_ztt_f32_accx1_t d = __riscv_ztt_mzero_acc_f32_accx1 ();
  __riscv_ztt_bf16_1x2_t a = __riscv_ztt_mzero_m_bf16_1x2 ();
  __riscv_ztt_i16_rod_2x1_t b = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  unsigned long before = __riscv_ztt_get_amefflags ();
  __riscv_ztt_mmulacc_2d_f32_accx1 (d, a, b);
  return __riscv_ztt_get_amefflags () - before;
}
unsigned long dead_integer_result (void)
{
  __riscv_ztt_i32_accx1_t d = __riscv_ztt_mzero_acc_i32_accx1 ();
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u32_1x1_t b = __riscv_ztt_mzero_m_u32_1x1 ();
  unsigned long before = __riscv_ztt_get_amefflags ();
  __riscv_ztt_mmulatacc_2d_i32_accx1 (d, a, b);
  return __riscv_ztt_get_amefflags () - before;
}
/* { dg-final { scan-assembler-times {\tmmulacc\.2d\t} 1 } } */
/* { dg-final { scan-assembler-times {\tmmulatacc\.2d\t} 1 } } */
/* { dg-final { scan-assembler-times {amefflags} 4 } } */
/* { dg-final { scan-assembler-not {\tmconv\.ew\t} } } */
