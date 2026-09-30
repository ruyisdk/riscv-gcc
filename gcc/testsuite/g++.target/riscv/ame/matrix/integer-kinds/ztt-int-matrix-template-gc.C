/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++14 --param=ggc-min-expand=0 --param=ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++14 --param=ggc-min-expand=0 --param=ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
template<int Order>
void matrix_template (void)
{
  auto a = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  auto b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a), "+Wmr" (b));
  auto first = __riscv_ztt_mmul_ew_i8_rne_sat_1x2 (a, b);
  auto second = __riscv_ztt_mmul_ew_i8_rne_sat_1x2 (b, a);
  auto third = __riscv_ztt_mmul_ew_i8_rne_sat_1x2 (first, a);
  if (Order)
    third = __riscv_ztt_mmul_ew_i8_rne_sat_1x2 (second, a);
  __asm__ volatile ("" : : "Wmr" (first), "Wmr" (second), "Wmr" (third));
}
template void matrix_template<0> (void);
template void matrix_template<1> (void);
/* { dg-final { scan-assembler {mmul\.ew} } } */
/* { dg-final { scan-assembler-not {mconv\.ew|__builtin_riscv_ztt_integer_matrix} } } */
