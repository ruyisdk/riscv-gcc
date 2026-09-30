/* Compile/assemble checks, not numerical execution evidence.  */
/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++14 --param=ggc-min-expand=0 --param=ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++14 --param=ggc-min-expand=0 --param=ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>

/* Templates instantiate local values, not an unsupported typed-value ABI.  */
template<int Order>
void wide_template (void)
{
  auto a = __riscv_ztt_mclear_m_u64_rod_1x1 ();
  auto b = __riscv_ztt_mclear_m_i32_rdn_1x1 ();
  auto first = __riscv_ztt_mmul_ew_i128_rne_1x1 (a, b);
  auto second = __riscv_ztt_mmul_ew_i128_rne_1x1 (b, a);
  auto third = __riscv_ztt_mmul_ew_i128_rne_1x1 (first, a);
  if (Order)
    third = __riscv_ztt_mmul_ew_i128_rne_1x1 (second, a);
  auto last = __riscv_ztt_mconv_ew_i32_rdn_1x1 (third);
  __asm__ volatile ("" : : "Wmr" (last), "Wmr" (first), "Wmr" (second));
}
template void wide_template<0> (void);
template void wide_template<1> (void);
/* { dg-final { scan-assembler {mmul\.ew} } } */
/* { dg-final { scan-assembler {mconv\.ew} } } */
