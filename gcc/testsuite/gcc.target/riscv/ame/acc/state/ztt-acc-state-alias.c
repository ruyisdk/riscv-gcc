/* Default u32 ACC aliases.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a1" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void aliases (uint32_t *p)
{
  __riscv_ztt_u32_1x1_t m = __riscv_ztt_mls_rm_u32_1x1 (p);
  __riscv_ztt_u32_accx1_t a = __riscv_ztt_mcopy_m2a_u32_accx1 (m);
  __riscv_ztt_u32_accx1_t b = __riscv_ztt_mmulacc_2d_u32_accx1 (a, m, m);
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_u32_1x1 (b));
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_u32_1x1 (a));
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_u32_1x1
    (__riscv_ztt_mzero_acc_u32_accx1 ()));
  __riscv_ztt_mss_rm (p, __riscv_ztt_mcopy_a2m_u32_1x1
    (__riscv_ztt_mclear_acc_u32_accx1 ()));
}
