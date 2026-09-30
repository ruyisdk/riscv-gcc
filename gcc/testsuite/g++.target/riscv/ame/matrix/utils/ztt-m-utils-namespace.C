/* M utilities.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv32 } } */
/* { dg-options "-O2 -fstack-clash-protection -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m16-a1" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
namespace m_utils {
template<int Index>
void apply (int16_t *out, const int16_t *in)
{
  constexpr __SIZE_TYPE__ k = Index;
  auto a = __riscv_ztt_mls_rm_i16_rdn_1x1 (in);
  auto row = __riscv_ztt_mconcat_m_i16_rdn_1x2 (a, a);
  auto col = __riscv_ztt_mconcat_m_i16_rdn_2x1 (a, a);
  __riscv_ztt_mss_rm (out, __riscv_ztt_mextract_i16_rdn_1x1 (row, k));
  __riscv_ztt_mss_rm (out, __riscv_ztt_mextract_i16_rdn_1x1 (col, 1 - k));
}
template void apply<0> (int16_t *, const int16_t *);
template void apply<1> (int16_t *, const int16_t *);
}
/* { dg-final { scan-assembler-not "__builtin_riscv_ztt_mextract" } } */
