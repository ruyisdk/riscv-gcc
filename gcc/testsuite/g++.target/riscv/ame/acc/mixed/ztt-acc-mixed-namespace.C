/* Mixed integer capability.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a1" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
namespace mixed_scope {
template<int Which>
void apply (int32_t *out, const int8_t *left, const uint16_t *right)
{
  auto l = __riscv_ztt_mls_rm_i8_rne_1x1 (left);
  auto r = __riscv_ztt_mls_rm_u16_rod_1x1 (right);
  auto a = __riscv_ztt_mclear_acc_i32_rdn_accx1 ();
  auto result = Which ? __riscv_ztt_mmulacc_2d_i32_rdn_accx1 (a, l, r)
    : __riscv_ztt_mmulaccneg_2d_i32_rdn_accx1 (a, l, r);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rdn_1x1 (result));
}
template void apply<0> (int32_t *, const int8_t *, const uint16_t *);
template void apply<1> (int32_t *, const int8_t *, const uint16_t *);
}
/* { dg-final { scan-assembler-not "__builtin_riscv_ztt_mixed" } } */
