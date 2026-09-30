/* integer broadcast.  */
/* { dg-do compile } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv32 } } */
/* { dg-options "-O0 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u128-m32-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void q1x32_i8 (uint8_t *out, int8_t c)
{
  __riscv_ztt_u8_rnu_1x32_t v = __riscv_ztt_mbcast_m_x_u8_rnu_1x32_i8_rne ( __riscv_ztt_scalar_make_i8_rne (c));
  __riscv_ztt_mss_rm (out, v);
}
void q1x32_u8 (uint8_t *out, uint8_t c)
{
  __riscv_ztt_u8_rne_1x32_t v = __riscv_ztt_mbcast_m_x_u8_rne_1x32_u8_rdn ( __riscv_ztt_scalar_make_u8_rdn (c));
  __riscv_ztt_mss_rm (out, v);
}
void q1x32_i16 (uint8_t *out, int16_t c)
{
  __riscv_ztt_u8_rdn_1x32_t v = __riscv_ztt_mbcast_m_x_u8_rdn_1x32_i16_rod ( __riscv_ztt_scalar_make_i16_rod (c));
  __riscv_ztt_mss_rm (out, v);
}
void q1x32_u16 (uint8_t *out, uint16_t c)
{
  __riscv_ztt_u8_rod_1x32_t v = __riscv_ztt_mbcast_m_x_u8_rod_1x32_u16_rnu ( __riscv_ztt_scalar_make_u16_rnu (c));
  __riscv_ztt_mss_rm (out, v);
}
void q1x32_i32 (uint8_t *out, int32_t c)
{
  __riscv_ztt_u8_rnu_1x32_t v = __riscv_ztt_mbcast_m_x_u8_rnu_1x32_i32_rne ( __riscv_ztt_scalar_make_i32_rne (c));
  __riscv_ztt_mss_rm (out, v);
}
void q1x32_u32 (uint8_t *out, uint32_t c)
{
  __riscv_ztt_u8_rne_1x32_t v = __riscv_ztt_mbcast_m_x_u8_rne_1x32_u32_rdn ( __riscv_ztt_scalar_make_u32_rdn (c));
  __riscv_ztt_mss_rm (out, v);
}
void q32x1_i8 (uint8_t *out, int8_t c)
{
  __riscv_ztt_u8_rnu_32x1_t v = __riscv_ztt_mbcast_m_x_u8_rnu_32x1_i8_rne ( __riscv_ztt_scalar_make_i8_rne (c));
  __riscv_ztt_mss_rm (out, v);
}
void q32x1_u8 (uint8_t *out, uint8_t c)
{
  __riscv_ztt_u8_rne_32x1_t v = __riscv_ztt_mbcast_m_x_u8_rne_32x1_u8_rdn ( __riscv_ztt_scalar_make_u8_rdn (c));
  __riscv_ztt_mss_rm (out, v);
}
void q32x1_i16 (uint8_t *out, int16_t c)
{
  __riscv_ztt_u8_rdn_32x1_t v = __riscv_ztt_mbcast_m_x_u8_rdn_32x1_i16_rod ( __riscv_ztt_scalar_make_i16_rod (c));
  __riscv_ztt_mss_rm (out, v);
}
void q32x1_u16 (uint8_t *out, uint16_t c)
{
  __riscv_ztt_u8_rod_32x1_t v = __riscv_ztt_mbcast_m_x_u8_rod_32x1_u16_rnu ( __riscv_ztt_scalar_make_u16_rnu (c));
  __riscv_ztt_mss_rm (out, v);
}
void q32x1_i32 (uint8_t *out, int32_t c)
{
  __riscv_ztt_u8_rnu_32x1_t v = __riscv_ztt_mbcast_m_x_u8_rnu_32x1_i32_rne ( __riscv_ztt_scalar_make_i32_rne (c));
  __riscv_ztt_mss_rm (out, v);
}
void q32x1_u32 (uint8_t *out, uint32_t c)
{
  __riscv_ztt_u8_rne_32x1_t v = __riscv_ztt_mbcast_m_x_u8_rne_32x1_u32_rdn ( __riscv_ztt_scalar_make_u32_rdn (c));
  __riscv_ztt_mss_rm (out, v);
}
/* { dg-final { scan-assembler-times {\tmbcast\.m\.x\t} 24 } } */
