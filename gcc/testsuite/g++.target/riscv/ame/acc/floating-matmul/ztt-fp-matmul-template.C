/* { dg-do compile } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
template <typename A, typename B> __attribute__((always_inline))
static inline void mul (void)
{
  A a = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  B b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  auto d = __riscv_ztt_mzero_acc_f32_rno_accx1 ();
  d = __riscv_ztt_mmulatacc_2d_f32_rno_accx1 (d, a, b);
  __asm__ volatile ("" : : "War" (d));
}
void instantiate (void)
{
  mul<__riscv_ztt_bf16_rup_1x2_t, __riscv_ztt_i16_rod_1x2_t> ();
}
/* { dg-final { scan-assembler-times {\tmmulatacc\.2d\t} 1 } } */
