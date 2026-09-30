/* Normative IDs and adaptations are recorded in F60.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16 -fmax-errors=0" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>

extern "C" {
/* Observable legal counterpart of mbcast_m_x:01.  */
void
positive_mbcast_m_x_01 (void *out)
{
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mbcast_m_x_i32_1x2 (scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

/* Observable legal counterpart of mbcast_m_x:02.  */
void
positive_mbcast_m_x_02 (void *out)
{
  __riscv_ztt_i32_rnu_scalar_t scalar_i32 = __riscv_ztt_scalar_make_i32_rnu (3);
  __riscv_ztt_i32_1x2_t value = __riscv_ztt_mbcast_m_x_i32_1x2 (scalar_i32);
  __riscv_ztt_mss_rm ((int32_t *) out, value);
}

}
/* { dg-final { scan-assembler {\tmbcast\.m\.x\t} } } */
