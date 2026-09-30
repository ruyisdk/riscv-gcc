/* FP catalogue entries must not overwrite integer broadcast/scalar slots.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void coexist (void)
{
  __riscv_ztt_u16_rnu_sat_1x1_t a
    = __riscv_ztt_mbcast_m_x_u16_rnu_sat_1x1_u16_rnu ( __riscv_ztt_scalar_make_u16_rnu (7));
  a = __riscv_ztt_madd_ew_x_u16_rnu_sat_1x1_u16_rnu (a, __riscv_ztt_scalar_make_u16_rnu (3));
  __riscv_ztt_bf16_rno_1x1_t b = __riscv_ztt_mconv_ew_bf16_rno_1x1 (a);
  __asm__ volatile ("" : : "Wmr" (a), "Wmr" (b));
}
