/* registration.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu++17 -O2 -fno-ipa-icf --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-std=gnu++17 -O2 -fno-ipa-icf --param ggc-min-expand=0 --param ggc-min-heapsize=0 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include "../../../../gcc.target/riscv/ame/typed/ztt-registration-body.h"

namespace registration_scope {
template<typename T> __attribute__((always_inline)) inline
void apply (int8_t *out, T scalar)
{
  auto a = __riscv_ztt_mbcast_m_x_i8_rnu_1x4_i16_rdn ( __riscv_ztt_scalar_make_i16_rdn (scalar));
  auto b = __riscv_ztt_mbcast_m_x_i8_rne_1x4_u32_rod ( __riscv_ztt_scalar_make_u32_rod (scalar));
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (out + 128, b);
}

void use_both (int8_t *out1, int8_t *out2, int16_t s1, uint32_t s2)
{
  apply (out1, s1);
  apply (out2, s2);
}
}
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 53 } } */
/* { dg-final { scan-assembler-not {amestype|__builtin_riscv_ztt} } } */
