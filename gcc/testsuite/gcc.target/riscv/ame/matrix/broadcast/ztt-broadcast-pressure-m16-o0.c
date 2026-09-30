/* integer broadcast.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void pressure (uint32_t **out, volatile uint32_t *input)
{
  __riscv_ztt_u32_rnu_1x4_t v0 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[0]));
  __riscv_ztt_u32_rnu_1x4_t v1 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[1]));
  __riscv_ztt_u32_rnu_1x4_t v2 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[2]));
  __riscv_ztt_u32_rnu_1x4_t v3 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[3]));
  __riscv_ztt_u32_rnu_1x4_t v4 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[4]));
  __riscv_ztt_u32_rnu_1x4_t v5 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[5]));
  __riscv_ztt_u32_rnu_1x4_t v6 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[6]));
  __riscv_ztt_u32_rnu_1x4_t v7 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[7]));
  __riscv_ztt_u32_rnu_1x4_t v8 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[8]));
  __riscv_ztt_u32_rnu_1x4_t v9 = __riscv_ztt_mbcast_m_x_u32_1x4_u32 ( __riscv_ztt_scalar_make_u32_rnu (input[9]));
  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
  __riscv_ztt_mss_rm (out[5], v5);
  __riscv_ztt_mss_rm (out[6], v6);
  __riscv_ztt_mss_rm (out[7], v7);
  __riscv_ztt_mss_rm (out[8], v8);
  __riscv_ztt_mss_rm (out[9], v9);
}
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 40 } } */
/* { dg-final { scan-assembler {\tmss\.1r\t} } } */
/* { dg-final { scan-assembler {\tmls\.1r\t} } } */
