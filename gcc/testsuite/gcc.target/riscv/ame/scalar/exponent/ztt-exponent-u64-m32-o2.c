/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u64-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u64-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
#if __riscv_ztt_exponent_scalar != 1
#error missing exponent capability
#endif
void exponent_mldexp_i4_rnu (long exponent)
{
  __riscv_ztt_u8_rne_16x1_t a = __riscv_ztt_mzero_m_u8_rne_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rnu_16x1_t d = __riscv_ztt_mldexp_ew_x_i4_rnu_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rnu (long exponent)
{
  __riscv_ztt_u8_rne_16x1_t a = __riscv_ztt_mzero_m_u8_rne_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rnu_16x1_t old = __riscv_ztt_mzero_m_i4_rnu_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rnu_16x1_t d = __riscv_ztt_mldexpacc_ew_x_i4_rnu_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rne (long exponent)
{
  __riscv_ztt_u8_rdn_1x32_t a = __riscv_ztt_mzero_m_u8_rdn_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rne_1x32_t d = __riscv_ztt_mldexp_ew_x_i4_rne_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rne (long exponent)
{
  __riscv_ztt_u8_rdn_1x32_t a = __riscv_ztt_mzero_m_u8_rdn_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rne_1x32_t old = __riscv_ztt_mzero_m_i4_rne_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rne_1x32_t d = __riscv_ztt_mldexpacc_ew_x_i4_rne_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rdn (long exponent)
{
  __riscv_ztt_u8_rod_32x1_t a = __riscv_ztt_mzero_m_u8_rod_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rdn_32x1_t d = __riscv_ztt_mldexp_ew_x_i4_rdn_32x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rdn (long exponent)
{
  __riscv_ztt_u8_rod_32x1_t a = __riscv_ztt_mzero_m_u8_rod_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rdn_32x1_t old = __riscv_ztt_mzero_m_i4_rdn_32x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rdn_32x1_t d = __riscv_ztt_mldexpacc_ew_x_i4_rdn_32x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rod (long exponent)
{
  __riscv_ztt_i16_rnu_1x16_t a = __riscv_ztt_mzero_m_i16_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rod_1x16_t d = __riscv_ztt_mldexp_ew_x_i4_rod_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rod (long exponent)
{
  __riscv_ztt_i16_rnu_1x16_t a = __riscv_ztt_mzero_m_i16_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rod_1x16_t old = __riscv_ztt_mzero_m_i4_rod_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rod_1x16_t d = __riscv_ztt_mldexpacc_ew_x_i4_rod_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rnu (long exponent)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mzero_m_i16_rne_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rnu_32x1_t d = __riscv_ztt_mldexp_ew_x_u4_rnu_32x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rnu (long exponent)
{
  __riscv_ztt_i16_rne_32x1_t a = __riscv_ztt_mzero_m_i16_rne_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rnu_32x1_t old = __riscv_ztt_mzero_m_u4_rnu_32x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rnu_32x1_t d = __riscv_ztt_mldexpacc_ew_x_u4_rnu_32x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rne (long exponent)
{
  __riscv_ztt_i16_rdn_1x32_t a = __riscv_ztt_mzero_m_i16_rdn_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rne_1x32_t d = __riscv_ztt_mldexp_ew_x_u4_rne_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rne (long exponent)
{
  __riscv_ztt_i16_rdn_1x32_t a = __riscv_ztt_mzero_m_i16_rdn_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rne_1x32_t old = __riscv_ztt_mzero_m_u4_rne_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rne_1x32_t d = __riscv_ztt_mldexpacc_ew_x_u4_rne_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rdn (long exponent)
{
  __riscv_ztt_i16_rod_16x1_t a = __riscv_ztt_mzero_m_i16_rod_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rdn_16x1_t d = __riscv_ztt_mldexp_ew_x_u4_rdn_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rdn (long exponent)
{
  __riscv_ztt_i16_rod_16x1_t a = __riscv_ztt_mzero_m_i16_rod_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rdn_16x1_t old = __riscv_ztt_mzero_m_u4_rdn_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rdn_16x1_t d = __riscv_ztt_mldexpacc_ew_x_u4_rdn_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rod (long exponent)
{
  __riscv_ztt_u16_rnu_1x32_t a = __riscv_ztt_mzero_m_u16_rnu_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rod_1x32_t d = __riscv_ztt_mldexp_ew_x_u4_rod_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rod (long exponent)
{
  __riscv_ztt_u16_rnu_1x32_t a = __riscv_ztt_mzero_m_u16_rnu_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rod_1x32_t old = __riscv_ztt_mzero_m_u4_rod_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rod_1x32_t d = __riscv_ztt_mldexpacc_ew_x_u4_rod_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rnu (long exponent)
{
  __riscv_ztt_u16_rne_16x1_t a = __riscv_ztt_mzero_m_u16_rne_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rnu_16x1_t d = __riscv_ztt_mldexp_ew_x_i8_rnu_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rnu (long exponent)
{
  __riscv_ztt_u16_rne_16x1_t a = __riscv_ztt_mzero_m_u16_rne_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rnu_16x1_t old = __riscv_ztt_mzero_m_i8_rnu_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rnu_16x1_t d = __riscv_ztt_mldexpacc_ew_x_i8_rnu_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rne (long exponent)
{
  __riscv_ztt_u16_rdn_1x8_t a = __riscv_ztt_mzero_m_u16_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rne_1x8_t d = __riscv_ztt_mldexp_ew_x_i8_rne_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rne (long exponent)
{
  __riscv_ztt_u16_rdn_1x8_t a = __riscv_ztt_mzero_m_u16_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rne_1x8_t old = __riscv_ztt_mzero_m_i8_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rne_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i8_rne_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rdn (long exponent)
{
  __riscv_ztt_u16_rod_16x1_t a = __riscv_ztt_mzero_m_u16_rod_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rdn_16x1_t d = __riscv_ztt_mldexp_ew_x_i8_rdn_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rdn (long exponent)
{
  __riscv_ztt_u16_rod_16x1_t a = __riscv_ztt_mzero_m_u16_rod_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rdn_16x1_t old = __riscv_ztt_mzero_m_i8_rdn_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rdn_16x1_t d = __riscv_ztt_mldexpacc_ew_x_i8_rdn_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rod (long exponent)
{
  __riscv_ztt_i32_rnu_1x16_t a = __riscv_ztt_mzero_m_i32_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rod_1x16_t d = __riscv_ztt_mldexp_ew_x_i8_rod_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rod (long exponent)
{
  __riscv_ztt_i32_rnu_1x16_t a = __riscv_ztt_mzero_m_i32_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rod_1x16_t old = __riscv_ztt_mzero_m_i8_rod_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rod_1x16_t d = __riscv_ztt_mldexpacc_ew_x_i8_rod_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rnu (long exponent)
{
  __riscv_ztt_i32_rne_8x1_t a = __riscv_ztt_mzero_m_i32_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rnu_8x1_t d = __riscv_ztt_mldexp_ew_x_u8_rnu_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rnu (long exponent)
{
  __riscv_ztt_i32_rne_8x1_t a = __riscv_ztt_mzero_m_i32_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rnu_8x1_t old = __riscv_ztt_mzero_m_u8_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rnu_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u8_rnu_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rne (long exponent)
{
  __riscv_ztt_i32_rdn_1x16_t a = __riscv_ztt_mzero_m_i32_rdn_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rne_1x16_t d = __riscv_ztt_mldexp_ew_x_u8_rne_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rne (long exponent)
{
  __riscv_ztt_i32_rdn_1x16_t a = __riscv_ztt_mzero_m_i32_rdn_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rne_1x16_t old = __riscv_ztt_mzero_m_u8_rne_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rne_1x16_t d = __riscv_ztt_mldexpacc_ew_x_u8_rne_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rdn (long exponent)
{
  __riscv_ztt_i32_rod_16x1_t a = __riscv_ztt_mzero_m_i32_rod_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rdn_16x1_t d = __riscv_ztt_mldexp_ew_x_u8_rdn_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rdn (long exponent)
{
  __riscv_ztt_i32_rod_16x1_t a = __riscv_ztt_mzero_m_i32_rod_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rdn_16x1_t old = __riscv_ztt_mzero_m_u8_rdn_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rdn_16x1_t d = __riscv_ztt_mldexpacc_ew_x_u8_rdn_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rod (long exponent)
{
  __riscv_ztt_u32_rnu_1x8_t a = __riscv_ztt_mzero_m_u32_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rod_1x8_t d = __riscv_ztt_mldexp_ew_x_u8_rod_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rod (long exponent)
{
  __riscv_ztt_u32_rnu_1x8_t a = __riscv_ztt_mzero_m_u32_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rod_1x8_t old = __riscv_ztt_mzero_m_u8_rod_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rod_1x8_t d = __riscv_ztt_mldexpacc_ew_x_u8_rod_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rnu (long exponent)
{
  __riscv_ztt_u32_rne_8x1_t a = __riscv_ztt_mzero_m_u32_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rnu_8x1_t d = __riscv_ztt_mldexp_ew_x_i16_rnu_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rnu (long exponent)
{
  __riscv_ztt_u32_rne_8x1_t a = __riscv_ztt_mzero_m_u32_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rnu_8x1_t old = __riscv_ztt_mzero_m_i16_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rnu_8x1_t d = __riscv_ztt_mldexpacc_ew_x_i16_rnu_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rne (long exponent)
{
  __riscv_ztt_u32_rdn_1x8_t a = __riscv_ztt_mzero_m_u32_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rne_1x8_t d = __riscv_ztt_mldexp_ew_x_i16_rne_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rne (long exponent)
{
  __riscv_ztt_u32_rdn_1x8_t a = __riscv_ztt_mzero_m_u32_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rne_1x8_t old = __riscv_ztt_mzero_m_i16_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rne_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i16_rne_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rdn (long exponent)
{
  __riscv_ztt_u32_rod_4x1_t a = __riscv_ztt_mzero_m_u32_rod_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rdn_4x1_t d = __riscv_ztt_mldexp_ew_x_i16_rdn_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rdn (long exponent)
{
  __riscv_ztt_u32_rod_4x1_t a = __riscv_ztt_mzero_m_u32_rod_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rdn_4x1_t old = __riscv_ztt_mzero_m_i16_rdn_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rdn_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i16_rdn_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rod (long exponent)
{
  __riscv_ztt_i64_rnu_1x8_t a = __riscv_ztt_mzero_m_i64_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rod_1x8_t d = __riscv_ztt_mldexp_ew_x_i16_rod_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rod (long exponent)
{
  __riscv_ztt_i64_rnu_1x8_t a = __riscv_ztt_mzero_m_i64_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rod_1x8_t old = __riscv_ztt_mzero_m_i16_rod_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rod_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i16_rod_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rnu (long exponent)
{
  __riscv_ztt_i64_rne_8x1_t a = __riscv_ztt_mzero_m_i64_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rnu_8x1_t d = __riscv_ztt_mldexp_ew_x_u16_rnu_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rnu (long exponent)
{
  __riscv_ztt_i64_rne_8x1_t a = __riscv_ztt_mzero_m_i64_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rnu_8x1_t old = __riscv_ztt_mzero_m_u16_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rnu_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u16_rnu_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rne (long exponent)
{
  __riscv_ztt_i64_rdn_1x4_t a = __riscv_ztt_mzero_m_i64_rdn_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rne_1x4_t d = __riscv_ztt_mldexp_ew_x_u16_rne_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rne (long exponent)
{
  __riscv_ztt_i64_rdn_1x4_t a = __riscv_ztt_mzero_m_i64_rdn_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rne_1x4_t old = __riscv_ztt_mzero_m_u16_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rne_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u16_rne_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rdn (long exponent)
{
  __riscv_ztt_i64_rod_8x1_t a = __riscv_ztt_mzero_m_i64_rod_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rdn_8x1_t d = __riscv_ztt_mldexp_ew_x_u16_rdn_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rdn (long exponent)
{
  __riscv_ztt_i64_rod_8x1_t a = __riscv_ztt_mzero_m_i64_rod_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rdn_8x1_t old = __riscv_ztt_mzero_m_u16_rdn_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rdn_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u16_rdn_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rod (long exponent)
{
  __riscv_ztt_u64_rnu_1x8_t a = __riscv_ztt_mzero_m_u64_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rod_1x8_t d = __riscv_ztt_mldexp_ew_x_u16_rod_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rod (long exponent)
{
  __riscv_ztt_u64_rnu_1x8_t a = __riscv_ztt_mzero_m_u64_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rod_1x8_t old = __riscv_ztt_mzero_m_u16_rod_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rod_1x8_t d = __riscv_ztt_mldexpacc_ew_x_u16_rod_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rnu (long exponent)
{
  __riscv_ztt_u64_rne_2x1_t a = __riscv_ztt_mzero_m_u64_rne_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rnu_2x1_t d = __riscv_ztt_mldexp_ew_x_i32_rnu_2x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rnu (long exponent)
{
  __riscv_ztt_u64_rne_2x1_t a = __riscv_ztt_mzero_m_u64_rne_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rnu_2x1_t old = __riscv_ztt_mzero_m_i32_rnu_2x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rnu_2x1_t d = __riscv_ztt_mldexpacc_ew_x_i32_rnu_2x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rne (long exponent)
{
  __riscv_ztt_u64_rdn_1x4_t a = __riscv_ztt_mzero_m_u64_rdn_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rne_1x4_t d = __riscv_ztt_mldexp_ew_x_i32_rne_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rne (long exponent)
{
  __riscv_ztt_u64_rdn_1x4_t a = __riscv_ztt_mzero_m_u64_rdn_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rne_1x4_t old = __riscv_ztt_mzero_m_i32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rne_1x4_t d = __riscv_ztt_mldexpacc_ew_x_i32_rne_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rdn (long exponent)
{
  __riscv_ztt_u64_rod_4x1_t a = __riscv_ztt_mzero_m_u64_rod_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rdn_4x1_t d = __riscv_ztt_mldexp_ew_x_i32_rdn_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rdn (long exponent)
{
  __riscv_ztt_u64_rod_4x1_t a = __riscv_ztt_mzero_m_u64_rod_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rdn_4x1_t old = __riscv_ztt_mzero_m_i32_rdn_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rdn_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i32_rdn_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rod (long exponent)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mzero_m_i128_rnu_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rod_1x2_t d = __riscv_ztt_mldexp_ew_x_i32_rod_1x2 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rod (long exponent)
{
  __riscv_ztt_i128_rnu_1x2_t a = __riscv_ztt_mzero_m_i128_rnu_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rod_1x2_t old = __riscv_ztt_mzero_m_i32_rod_1x2 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rod_1x2_t d = __riscv_ztt_mldexpacc_ew_x_i32_rod_1x2 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rnu (long exponent)
{
  __riscv_ztt_i128_rne_4x1_t a = __riscv_ztt_mzero_m_i128_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rnu_4x1_t d = __riscv_ztt_mldexp_ew_x_u32_rnu_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rnu (long exponent)
{
  __riscv_ztt_i128_rne_4x1_t a = __riscv_ztt_mzero_m_i128_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rnu_4x1_t old = __riscv_ztt_mzero_m_u32_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rnu_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u32_rnu_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rne (long exponent)
{
  __riscv_ztt_i128_rdn_1x4_t a = __riscv_ztt_mzero_m_i128_rdn_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rne_1x4_t d = __riscv_ztt_mldexp_ew_x_u32_rne_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rne (long exponent)
{
  __riscv_ztt_i128_rdn_1x4_t a = __riscv_ztt_mzero_m_i128_rdn_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rne_1x4_t old = __riscv_ztt_mzero_m_u32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rne_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u32_rne_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rdn (long exponent)
{
  __riscv_ztt_i128_rod_2x1_t a = __riscv_ztt_mzero_m_i128_rod_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rdn_2x1_t d = __riscv_ztt_mldexp_ew_x_u32_rdn_2x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rdn (long exponent)
{
  __riscv_ztt_i128_rod_2x1_t a = __riscv_ztt_mzero_m_i128_rod_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rdn_2x1_t old = __riscv_ztt_mzero_m_u32_rdn_2x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_x_u32_rdn_2x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rod (long exponent)
{
  __riscv_ztt_u128_rnu_1x4_t a = __riscv_ztt_mzero_m_u128_rnu_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rod_1x4_t d = __riscv_ztt_mldexp_ew_x_u32_rod_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rod (long exponent)
{
  __riscv_ztt_u128_rnu_1x4_t a = __riscv_ztt_mzero_m_u128_rnu_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rod_1x4_t old = __riscv_ztt_mzero_m_u32_rod_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rod_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u32_rod_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rnu (long exponent)
{
  __riscv_ztt_u128_rne_4x1_t a = __riscv_ztt_mzero_m_u128_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rnu_4x1_t d = __riscv_ztt_mldexp_ew_x_i64_rnu_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rnu (long exponent)
{
  __riscv_ztt_u128_rne_4x1_t a = __riscv_ztt_mzero_m_u128_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rnu_4x1_t old = __riscv_ztt_mzero_m_i64_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rnu_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i64_rnu_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rne (long exponent)
{
  __riscv_ztt_u128_rdn_1x1_t a = __riscv_ztt_mzero_m_u128_rdn_1x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rne_1x1_t d = __riscv_ztt_mldexp_ew_x_i64_rne_1x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rne (long exponent)
{
  __riscv_ztt_u128_rdn_1x1_t a = __riscv_ztt_mzero_m_u128_rdn_1x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rne_1x1_t old = __riscv_ztt_mzero_m_i64_rne_1x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_x_i64_rne_1x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rdn (long exponent)
{
  __riscv_ztt_u128_rod_4x1_t a = __riscv_ztt_mzero_m_u128_rod_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rdn_4x1_t d = __riscv_ztt_mldexp_ew_x_i64_rdn_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rdn (long exponent)
{
  __riscv_ztt_u128_rod_4x1_t a = __riscv_ztt_mzero_m_u128_rod_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rdn_4x1_t old = __riscv_ztt_mzero_m_i64_rdn_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rdn_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i64_rdn_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rod (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rod_1x8_t d = __riscv_ztt_mldexp_ew_x_i64_rod_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rod (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rod_1x8_t old = __riscv_ztt_mzero_m_i64_rod_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rod_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i64_rod_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rnu (long exponent)
{
  __riscv_ztt_i16_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i16_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rnu_4x1_t d = __riscv_ztt_mldexp_ew_x_u64_rnu_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rnu (long exponent)
{
  __riscv_ztt_i16_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i16_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rnu_4x1_t old = __riscv_ztt_mzero_m_u64_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rnu_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u64_rnu_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rne (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rne_1x8_t d = __riscv_ztt_mldexp_ew_x_u64_rne_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rne (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rne_1x8_t old = __riscv_ztt_mzero_m_u64_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rne_1x8_t d = __riscv_ztt_mldexpacc_ew_x_u64_rne_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rdn (long exponent)
{
  __riscv_ztt_i16_rnu_sat_8x1_t a = __riscv_ztt_mzero_m_i16_rnu_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rdn_8x1_t d = __riscv_ztt_mldexp_ew_x_u64_rdn_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rdn (long exponent)
{
  __riscv_ztt_i16_rnu_sat_8x1_t a = __riscv_ztt_mzero_m_i16_rnu_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rdn_8x1_t old = __riscv_ztt_mzero_m_u64_rdn_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rdn_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u64_rdn_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rod (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rod_1x4_t d = __riscv_ztt_mldexp_ew_x_u64_rod_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rod (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rod_1x4_t old = __riscv_ztt_mzero_m_u64_rod_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rod_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u64_rod_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rnu (long exponent)
{
  __riscv_ztt_i32_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rnu_4x1_t d = __riscv_ztt_mldexp_ew_x_i128_rnu_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rnu (long exponent)
{
  __riscv_ztt_i32_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rnu_4x1_t old = __riscv_ztt_mzero_m_i128_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rnu_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i128_rnu_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rne (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rne_1x4_t d = __riscv_ztt_mldexp_ew_x_i128_rne_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rne (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rne_1x4_t old = __riscv_ztt_mzero_m_i128_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rne_1x4_t d = __riscv_ztt_mldexpacc_ew_x_i128_rne_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rdn (long exponent)
{
  __riscv_ztt_i32_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rdn_2x1_t d = __riscv_ztt_mldexp_ew_x_i128_rdn_2x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rdn (long exponent)
{
  __riscv_ztt_i32_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rdn_2x1_t old = __riscv_ztt_mzero_m_i128_rdn_2x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_x_i128_rdn_2x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rod (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rod_1x4_t d = __riscv_ztt_mldexp_ew_x_i128_rod_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rod (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rod_1x4_t old = __riscv_ztt_mzero_m_i128_rod_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rod_1x4_t d = __riscv_ztt_mldexpacc_ew_x_i128_rod_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rnu (long exponent)
{
  __riscv_ztt_i32_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rnu_4x1_t d = __riscv_ztt_mldexp_ew_x_u128_rnu_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rnu (long exponent)
{
  __riscv_ztt_i32_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rnu_4x1_t old = __riscv_ztt_mzero_m_u128_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rnu_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u128_rnu_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rne (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rne_1x2_t d = __riscv_ztt_mldexp_ew_x_u128_rne_1x2 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rne (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rne_1x2_t old = __riscv_ztt_mzero_m_u128_rne_1x2 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rne_1x2_t d = __riscv_ztt_mldexpacc_ew_x_u128_rne_1x2 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rdn (long exponent)
{
  __riscv_ztt_i32_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rdn_4x1_t d = __riscv_ztt_mldexp_ew_x_u128_rdn_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rdn (long exponent)
{
  __riscv_ztt_i32_rnu_sat_4x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rdn_4x1_t old = __riscv_ztt_mzero_m_u128_rdn_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rdn_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u128_rdn_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rod (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rod_1x4_t d = __riscv_ztt_mldexp_ew_x_u128_rod_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rod (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rod_1x4_t old = __riscv_ztt_mzero_m_u128_rod_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rod_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u128_rod_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rnu_sat (long exponent)
{
  __riscv_ztt_u8_rne_sat_16x1_t a = __riscv_ztt_mzero_m_u8_rne_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rnu_sat_16x1_t d = __riscv_ztt_mldexp_ew_x_i4_rnu_sat_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rnu_sat (long exponent)
{
  __riscv_ztt_u8_rne_sat_16x1_t a = __riscv_ztt_mzero_m_u8_rne_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rnu_sat_16x1_t old = __riscv_ztt_mzero_m_i4_rnu_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rnu_sat_16x1_t d = __riscv_ztt_mldexpacc_ew_x_i4_rnu_sat_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rne_sat (long exponent)
{
  __riscv_ztt_u8_rdn_sat_1x32_t a = __riscv_ztt_mzero_m_u8_rdn_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rne_sat_1x32_t d = __riscv_ztt_mldexp_ew_x_i4_rne_sat_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rne_sat (long exponent)
{
  __riscv_ztt_u8_rdn_sat_1x32_t a = __riscv_ztt_mzero_m_u8_rdn_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rne_sat_1x32_t old = __riscv_ztt_mzero_m_i4_rne_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rne_sat_1x32_t d = __riscv_ztt_mldexpacc_ew_x_i4_rne_sat_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rdn_sat (long exponent)
{
  __riscv_ztt_u8_rod_sat_32x1_t a = __riscv_ztt_mzero_m_u8_rod_sat_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rdn_sat_32x1_t d = __riscv_ztt_mldexp_ew_x_i4_rdn_sat_32x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rdn_sat (long exponent)
{
  __riscv_ztt_u8_rod_sat_32x1_t a = __riscv_ztt_mzero_m_u8_rod_sat_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rdn_sat_32x1_t old = __riscv_ztt_mzero_m_i4_rdn_sat_32x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rdn_sat_32x1_t d = __riscv_ztt_mldexpacc_ew_x_i4_rdn_sat_32x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i4_rod_sat (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x16_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rod_sat_1x16_t d = __riscv_ztt_mldexp_ew_x_i4_rod_sat_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i4_rod_sat (long exponent)
{
  __riscv_ztt_i16_rnu_sat_1x16_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i4_rod_sat_1x16_t old = __riscv_ztt_mzero_m_i4_rod_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i4_rod_sat_1x16_t d = __riscv_ztt_mldexpacc_ew_x_i4_rod_sat_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rnu_sat (long exponent)
{
  __riscv_ztt_i16_rne_sat_32x1_t a = __riscv_ztt_mzero_m_i16_rne_sat_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rnu_sat_32x1_t d = __riscv_ztt_mldexp_ew_x_u4_rnu_sat_32x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rnu_sat (long exponent)
{
  __riscv_ztt_i16_rne_sat_32x1_t a = __riscv_ztt_mzero_m_i16_rne_sat_32x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rnu_sat_32x1_t old = __riscv_ztt_mzero_m_u4_rnu_sat_32x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rnu_sat_32x1_t d = __riscv_ztt_mldexpacc_ew_x_u4_rnu_sat_32x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rne_sat (long exponent)
{
  __riscv_ztt_i16_rdn_sat_1x32_t a = __riscv_ztt_mzero_m_i16_rdn_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rne_sat_1x32_t d = __riscv_ztt_mldexp_ew_x_u4_rne_sat_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rne_sat (long exponent)
{
  __riscv_ztt_i16_rdn_sat_1x32_t a = __riscv_ztt_mzero_m_i16_rdn_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rne_sat_1x32_t old = __riscv_ztt_mzero_m_u4_rne_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rne_sat_1x32_t d = __riscv_ztt_mldexpacc_ew_x_u4_rne_sat_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rdn_sat (long exponent)
{
  __riscv_ztt_i16_rod_sat_16x1_t a = __riscv_ztt_mzero_m_i16_rod_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rdn_sat_16x1_t d = __riscv_ztt_mldexp_ew_x_u4_rdn_sat_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rdn_sat (long exponent)
{
  __riscv_ztt_i16_rod_sat_16x1_t a = __riscv_ztt_mzero_m_i16_rod_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rdn_sat_16x1_t old = __riscv_ztt_mzero_m_u4_rdn_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rdn_sat_16x1_t d = __riscv_ztt_mldexpacc_ew_x_u4_rdn_sat_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u4_rod_sat (long exponent)
{
  __riscv_ztt_u16_rnu_sat_1x32_t a = __riscv_ztt_mzero_m_u16_rnu_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rod_sat_1x32_t d = __riscv_ztt_mldexp_ew_x_u4_rod_sat_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u4_rod_sat (long exponent)
{
  __riscv_ztt_u16_rnu_sat_1x32_t a = __riscv_ztt_mzero_m_u16_rnu_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u4_rod_sat_1x32_t old = __riscv_ztt_mzero_m_u4_rod_sat_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u4_rod_sat_1x32_t d = __riscv_ztt_mldexpacc_ew_x_u4_rod_sat_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rnu_sat (long exponent)
{
  __riscv_ztt_u16_rne_sat_16x1_t a = __riscv_ztt_mzero_m_u16_rne_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rnu_sat_16x1_t d = __riscv_ztt_mldexp_ew_x_i8_rnu_sat_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rnu_sat (long exponent)
{
  __riscv_ztt_u16_rne_sat_16x1_t a = __riscv_ztt_mzero_m_u16_rne_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rnu_sat_16x1_t old = __riscv_ztt_mzero_m_i8_rnu_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rnu_sat_16x1_t d = __riscv_ztt_mldexpacc_ew_x_i8_rnu_sat_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rne_sat (long exponent)
{
  __riscv_ztt_u16_rdn_sat_1x8_t a = __riscv_ztt_mzero_m_u16_rdn_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rne_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_i8_rne_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rne_sat (long exponent)
{
  __riscv_ztt_u16_rdn_sat_1x8_t a = __riscv_ztt_mzero_m_u16_rdn_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rne_sat_1x8_t old = __riscv_ztt_mzero_m_i8_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rne_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i8_rne_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rdn_sat (long exponent)
{
  __riscv_ztt_u16_rod_sat_16x1_t a = __riscv_ztt_mzero_m_u16_rod_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rdn_sat_16x1_t d = __riscv_ztt_mldexp_ew_x_i8_rdn_sat_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rdn_sat (long exponent)
{
  __riscv_ztt_u16_rod_sat_16x1_t a = __riscv_ztt_mzero_m_u16_rod_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rdn_sat_16x1_t old = __riscv_ztt_mzero_m_i8_rdn_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rdn_sat_16x1_t d = __riscv_ztt_mldexpacc_ew_x_i8_rdn_sat_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i8_rod_sat (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x16_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rod_sat_1x16_t d = __riscv_ztt_mldexp_ew_x_i8_rod_sat_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i8_rod_sat (long exponent)
{
  __riscv_ztt_i32_rnu_sat_1x16_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i8_rod_sat_1x16_t old = __riscv_ztt_mzero_m_i8_rod_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i8_rod_sat_1x16_t d = __riscv_ztt_mldexpacc_ew_x_i8_rod_sat_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rnu_sat (long exponent)
{
  __riscv_ztt_i32_rne_sat_8x1_t a = __riscv_ztt_mzero_m_i32_rne_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rnu_sat_8x1_t d = __riscv_ztt_mldexp_ew_x_u8_rnu_sat_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rnu_sat (long exponent)
{
  __riscv_ztt_i32_rne_sat_8x1_t a = __riscv_ztt_mzero_m_i32_rne_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rnu_sat_8x1_t old = __riscv_ztt_mzero_m_u8_rnu_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rnu_sat_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u8_rnu_sat_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rne_sat (long exponent)
{
  __riscv_ztt_i32_rdn_sat_1x16_t a = __riscv_ztt_mzero_m_i32_rdn_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rne_sat_1x16_t d = __riscv_ztt_mldexp_ew_x_u8_rne_sat_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rne_sat (long exponent)
{
  __riscv_ztt_i32_rdn_sat_1x16_t a = __riscv_ztt_mzero_m_i32_rdn_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rne_sat_1x16_t old = __riscv_ztt_mzero_m_u8_rne_sat_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rne_sat_1x16_t d = __riscv_ztt_mldexpacc_ew_x_u8_rne_sat_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rdn_sat (long exponent)
{
  __riscv_ztt_i32_rod_sat_16x1_t a = __riscv_ztt_mzero_m_i32_rod_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rdn_sat_16x1_t d = __riscv_ztt_mldexp_ew_x_u8_rdn_sat_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rdn_sat (long exponent)
{
  __riscv_ztt_i32_rod_sat_16x1_t a = __riscv_ztt_mzero_m_i32_rod_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rdn_sat_16x1_t old = __riscv_ztt_mzero_m_u8_rdn_sat_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rdn_sat_16x1_t d = __riscv_ztt_mldexpacc_ew_x_u8_rdn_sat_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u8_rod_sat (long exponent)
{
  __riscv_ztt_u32_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_u32_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rod_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_u8_rod_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u8_rod_sat (long exponent)
{
  __riscv_ztt_u32_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_u32_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u8_rod_sat_1x8_t old = __riscv_ztt_mzero_m_u8_rod_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u8_rod_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_u8_rod_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rnu_sat (long exponent)
{
  __riscv_ztt_u32_rne_sat_8x1_t a = __riscv_ztt_mzero_m_u32_rne_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rnu_sat_8x1_t d = __riscv_ztt_mldexp_ew_x_i16_rnu_sat_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rnu_sat (long exponent)
{
  __riscv_ztt_u32_rne_sat_8x1_t a = __riscv_ztt_mzero_m_u32_rne_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rnu_sat_8x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rnu_sat_8x1_t d = __riscv_ztt_mldexpacc_ew_x_i16_rnu_sat_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rne_sat (long exponent)
{
  __riscv_ztt_u32_rdn_sat_1x8_t a = __riscv_ztt_mzero_m_u32_rdn_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rne_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_i16_rne_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rne_sat (long exponent)
{
  __riscv_ztt_u32_rdn_sat_1x8_t a = __riscv_ztt_mzero_m_u32_rdn_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rne_sat_1x8_t old = __riscv_ztt_mzero_m_i16_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rne_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i16_rne_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rdn_sat (long exponent)
{
  __riscv_ztt_u32_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u32_rod_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_i16_rdn_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rdn_sat (long exponent)
{
  __riscv_ztt_u32_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u32_rod_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rdn_sat_4x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rdn_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i16_rdn_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i16_rod_sat (long exponent)
{
  __riscv_ztt_i64_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_i64_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rod_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_i16_rod_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i16_rod_sat (long exponent)
{
  __riscv_ztt_i64_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_i64_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i16_rod_sat_1x8_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i16_rod_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i16_rod_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rnu_sat (long exponent)
{
  __riscv_ztt_i64_rne_sat_8x1_t a = __riscv_ztt_mzero_m_i64_rne_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rnu_sat_8x1_t d = __riscv_ztt_mldexp_ew_x_u16_rnu_sat_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rnu_sat (long exponent)
{
  __riscv_ztt_i64_rne_sat_8x1_t a = __riscv_ztt_mzero_m_i64_rne_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rnu_sat_8x1_t old = __riscv_ztt_mzero_m_u16_rnu_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rnu_sat_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u16_rnu_sat_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rne_sat (long exponent)
{
  __riscv_ztt_i64_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_i64_rdn_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rne_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_u16_rne_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rne_sat (long exponent)
{
  __riscv_ztt_i64_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_i64_rdn_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rne_sat_1x4_t old = __riscv_ztt_mzero_m_u16_rne_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u16_rne_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rdn_sat (long exponent)
{
  __riscv_ztt_i64_rod_sat_8x1_t a = __riscv_ztt_mzero_m_i64_rod_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rdn_sat_8x1_t d = __riscv_ztt_mldexp_ew_x_u16_rdn_sat_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rdn_sat (long exponent)
{
  __riscv_ztt_i64_rod_sat_8x1_t a = __riscv_ztt_mzero_m_i64_rod_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rdn_sat_8x1_t old = __riscv_ztt_mzero_m_u16_rdn_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rdn_sat_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u16_rdn_sat_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u16_rod_sat (long exponent)
{
  __riscv_ztt_u64_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_u64_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rod_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_u16_rod_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u16_rod_sat (long exponent)
{
  __riscv_ztt_u64_rnu_sat_1x8_t a = __riscv_ztt_mzero_m_u64_rnu_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u16_rod_sat_1x8_t old = __riscv_ztt_mzero_m_u16_rod_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u16_rod_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_u16_rod_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rnu_sat (long exponent)
{
  __riscv_ztt_u64_rne_sat_2x1_t a = __riscv_ztt_mzero_m_u64_rne_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rnu_sat_2x1_t d = __riscv_ztt_mldexp_ew_x_i32_rnu_sat_2x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rnu_sat (long exponent)
{
  __riscv_ztt_u64_rne_sat_2x1_t a = __riscv_ztt_mzero_m_u64_rne_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rnu_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_x_i32_rnu_sat_2x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rne_sat (long exponent)
{
  __riscv_ztt_u64_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_u64_rdn_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rne_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_i32_rne_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rne_sat (long exponent)
{
  __riscv_ztt_u64_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_u64_rdn_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rne_sat_1x4_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_i32_rne_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rdn_sat (long exponent)
{
  __riscv_ztt_u64_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u64_rod_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_i32_rdn_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rdn_sat (long exponent)
{
  __riscv_ztt_u64_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u64_rod_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rdn_sat_4x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rdn_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i32_rdn_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i32_rod_sat (long exponent)
{
  __riscv_ztt_i128_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i128_rnu_sat_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rod_sat_1x2_t d = __riscv_ztt_mldexp_ew_x_i32_rod_sat_1x2 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i32_rod_sat (long exponent)
{
  __riscv_ztt_i128_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i128_rnu_sat_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i32_rod_sat_1x2_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x2 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i32_rod_sat_1x2_t d = __riscv_ztt_mldexpacc_ew_x_i32_rod_sat_1x2 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rnu_sat (long exponent)
{
  __riscv_ztt_i128_rne_sat_4x1_t a = __riscv_ztt_mzero_m_i128_rne_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rnu_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_u32_rnu_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rnu_sat (long exponent)
{
  __riscv_ztt_i128_rne_sat_4x1_t a = __riscv_ztt_mzero_m_i128_rne_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rnu_sat_4x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rnu_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u32_rnu_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rne_sat (long exponent)
{
  __riscv_ztt_i128_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_i128_rdn_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rne_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_u32_rne_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rne_sat (long exponent)
{
  __riscv_ztt_i128_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_i128_rdn_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rne_sat_1x4_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u32_rne_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rdn_sat (long exponent)
{
  __riscv_ztt_i128_rod_sat_2x1_t a = __riscv_ztt_mzero_m_i128_rod_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rdn_sat_2x1_t d = __riscv_ztt_mldexp_ew_x_u32_rdn_sat_2x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rdn_sat (long exponent)
{
  __riscv_ztt_i128_rod_sat_2x1_t a = __riscv_ztt_mzero_m_i128_rod_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rdn_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_x_u32_rdn_sat_2x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u32_rod_sat (long exponent)
{
  __riscv_ztt_u128_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_u128_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rod_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_u32_rod_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u32_rod_sat (long exponent)
{
  __riscv_ztt_u128_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_u128_rnu_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u32_rod_sat_1x4_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u32_rod_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u32_rod_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rnu_sat (long exponent)
{
  __riscv_ztt_u128_rne_sat_4x1_t a = __riscv_ztt_mzero_m_u128_rne_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rnu_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_i64_rnu_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rnu_sat (long exponent)
{
  __riscv_ztt_u128_rne_sat_4x1_t a = __riscv_ztt_mzero_m_u128_rne_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rnu_sat_4x1_t old = __riscv_ztt_mzero_m_i64_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rnu_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i64_rnu_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rne_sat (long exponent)
{
  __riscv_ztt_u128_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u128_rdn_sat_1x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rne_sat_1x1_t d = __riscv_ztt_mldexp_ew_x_i64_rne_sat_1x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rne_sat (long exponent)
{
  __riscv_ztt_u128_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u128_rdn_sat_1x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i64_rne_sat_1x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rne_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_x_i64_rne_sat_1x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rdn_sat (long exponent)
{
  __riscv_ztt_u128_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u128_rod_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_i64_rdn_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rdn_sat (long exponent)
{
  __riscv_ztt_u128_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u128_rod_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rdn_sat_4x1_t old = __riscv_ztt_mzero_m_i64_rdn_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rdn_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i64_rdn_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i64_rod_sat (long exponent)
{
  __riscv_ztt_f16_rne_1x8_t a = __riscv_ztt_mzero_m_f16_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rod_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_i64_rod_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i64_rod_sat (long exponent)
{
  __riscv_ztt_f16_rne_1x8_t a = __riscv_ztt_mzero_m_f16_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i64_rod_sat_1x8_t old = __riscv_ztt_mzero_m_i64_rod_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i64_rod_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_i64_rod_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rnu_sat (long exponent)
{
  __riscv_ztt_f16_rtz_4x1_t a = __riscv_ztt_mzero_m_f16_rtz_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rnu_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_u64_rnu_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rnu_sat (long exponent)
{
  __riscv_ztt_f16_rtz_4x1_t a = __riscv_ztt_mzero_m_f16_rtz_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rnu_sat_4x1_t old = __riscv_ztt_mzero_m_u64_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rnu_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u64_rnu_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rne_sat (long exponent)
{
  __riscv_ztt_f16_rdn_1x8_t a = __riscv_ztt_mzero_m_f16_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rne_sat_1x8_t d = __riscv_ztt_mldexp_ew_x_u64_rne_sat_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rne_sat (long exponent)
{
  __riscv_ztt_f16_rdn_1x8_t a = __riscv_ztt_mzero_m_f16_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rne_sat_1x8_t old = __riscv_ztt_mzero_m_u64_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rne_sat_1x8_t d = __riscv_ztt_mldexpacc_ew_x_u64_rne_sat_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rdn_sat (long exponent)
{
  __riscv_ztt_f16_rup_8x1_t a = __riscv_ztt_mzero_m_f16_rup_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rdn_sat_8x1_t d = __riscv_ztt_mldexp_ew_x_u64_rdn_sat_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rdn_sat (long exponent)
{
  __riscv_ztt_f16_rup_8x1_t a = __riscv_ztt_mzero_m_f16_rup_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rdn_sat_8x1_t old = __riscv_ztt_mzero_m_u64_rdn_sat_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rdn_sat_8x1_t d = __riscv_ztt_mldexpacc_ew_x_u64_rdn_sat_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u64_rod_sat (long exponent)
{
  __riscv_ztt_f16_rmm_1x4_t a = __riscv_ztt_mzero_m_f16_rmm_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rod_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_u64_rod_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u64_rod_sat (long exponent)
{
  __riscv_ztt_f16_rmm_1x4_t a = __riscv_ztt_mzero_m_f16_rmm_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u64_rod_sat_1x4_t old = __riscv_ztt_mzero_m_u64_rod_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u64_rod_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u64_rod_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rnu_sat (long exponent)
{
  __riscv_ztt_f32_rne_4x1_t a = __riscv_ztt_mzero_m_f32_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rnu_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_i128_rnu_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rnu_sat (long exponent)
{
  __riscv_ztt_f32_rne_4x1_t a = __riscv_ztt_mzero_m_f32_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rnu_sat_4x1_t old = __riscv_ztt_mzero_m_i128_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rnu_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_i128_rnu_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rne_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x4_t a = __riscv_ztt_mzero_m_f32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rne_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_i128_rne_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rne_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x4_t a = __riscv_ztt_mzero_m_f32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rne_sat_1x4_t old = __riscv_ztt_mzero_m_i128_rne_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_i128_rne_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rdn_sat (long exponent)
{
  __riscv_ztt_f32_rne_2x1_t a = __riscv_ztt_mzero_m_f32_rne_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rdn_sat_2x1_t d = __riscv_ztt_mldexp_ew_x_i128_rdn_sat_2x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rdn_sat (long exponent)
{
  __riscv_ztt_f32_rne_2x1_t a = __riscv_ztt_mzero_m_f32_rne_2x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i128_rdn_sat_2x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rdn_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_x_i128_rdn_sat_2x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_i128_rod_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x4_t a = __riscv_ztt_mzero_m_f32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rod_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_i128_rod_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_i128_rod_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x4_t a = __riscv_ztt_mzero_m_f32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_i128_rod_sat_1x4_t old = __riscv_ztt_mzero_m_i128_rod_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_i128_rod_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_i128_rod_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rnu_sat (long exponent)
{
  __riscv_ztt_f32_rne_4x1_t a = __riscv_ztt_mzero_m_f32_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rnu_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_u128_rnu_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rnu_sat (long exponent)
{
  __riscv_ztt_f32_rne_4x1_t a = __riscv_ztt_mzero_m_f32_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rnu_sat_4x1_t old = __riscv_ztt_mzero_m_u128_rnu_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rnu_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u128_rnu_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rne_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mzero_m_f32_rne_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rne_sat_1x2_t d = __riscv_ztt_mldexp_ew_x_u128_rne_sat_1x2 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rne_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x2_t a = __riscv_ztt_mzero_m_f32_rne_1x2 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rne_sat_1x2_t old = __riscv_ztt_mzero_m_u128_rne_sat_1x2 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rne_sat_1x2_t d = __riscv_ztt_mldexpacc_ew_x_u128_rne_sat_1x2 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rdn_sat (long exponent)
{
  __riscv_ztt_f32_rne_4x1_t a = __riscv_ztt_mzero_m_f32_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_x_u128_rdn_sat_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rdn_sat (long exponent)
{
  __riscv_ztt_f32_rne_4x1_t a = __riscv_ztt_mzero_m_f32_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rdn_sat_4x1_t old = __riscv_ztt_mzero_m_u128_rdn_sat_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rdn_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_x_u128_rdn_sat_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_u128_rod_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x4_t a = __riscv_ztt_mzero_m_f32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rod_sat_1x4_t d = __riscv_ztt_mldexp_ew_x_u128_rod_sat_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_u128_rod_sat (long exponent)
{
  __riscv_ztt_f32_rne_1x4_t a = __riscv_ztt_mzero_m_f32_rne_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_u128_rod_sat_1x4_t old = __riscv_ztt_mzero_m_u128_rod_sat_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_u128_rod_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_x_u128_rod_sat_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f16_rne (long exponent)
{
  __riscv_ztt_f32_rtz_4x1_t a = __riscv_ztt_mzero_m_f32_rtz_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mldexp_ew_x_f16_rne_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f16_rne (long exponent)
{
  __riscv_ztt_f32_rtz_4x1_t a = __riscv_ztt_mzero_m_f32_rtz_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rne_4x1_t old = __riscv_ztt_mzero_m_f16_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f16_rne_4x1_t d = __riscv_ztt_mldexpacc_ew_x_f16_rne_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f16_rtz (long exponent)
{
  __riscv_ztt_f32_rdn_1x8_t a = __riscv_ztt_mzero_m_f32_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rtz_1x8_t d = __riscv_ztt_mldexp_ew_x_f16_rtz_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f16_rtz (long exponent)
{
  __riscv_ztt_f32_rdn_1x8_t a = __riscv_ztt_mzero_m_f32_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rtz_1x8_t old = __riscv_ztt_mzero_m_f16_rtz_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f16_rtz_1x8_t d = __riscv_ztt_mldexpacc_ew_x_f16_rtz_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f16_rdn (long exponent)
{
  __riscv_ztt_f32_rup_8x1_t a = __riscv_ztt_mzero_m_f32_rup_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rdn_8x1_t d = __riscv_ztt_mldexp_ew_x_f16_rdn_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f16_rdn (long exponent)
{
  __riscv_ztt_f32_rup_8x1_t a = __riscv_ztt_mzero_m_f32_rup_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rdn_8x1_t old = __riscv_ztt_mzero_m_f16_rdn_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f16_rdn_8x1_t d = __riscv_ztt_mldexpacc_ew_x_f16_rdn_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f16_rup (long exponent)
{
  __riscv_ztt_f32_rmm_1x4_t a = __riscv_ztt_mzero_m_f32_rmm_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mldexp_ew_x_f16_rup_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f16_rup (long exponent)
{
  __riscv_ztt_f32_rmm_1x4_t a = __riscv_ztt_mzero_m_f32_rmm_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rup_1x4_t old = __riscv_ztt_mzero_m_f16_rup_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f16_rup_1x4_t d = __riscv_ztt_mldexpacc_ew_x_f16_rup_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f16_rmm (long exponent)
{
  __riscv_ztt_f32_rno_8x1_t a = __riscv_ztt_mzero_m_f32_rno_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rmm_8x1_t d = __riscv_ztt_mldexp_ew_x_f16_rmm_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f16_rmm (long exponent)
{
  __riscv_ztt_f32_rno_8x1_t a = __riscv_ztt_mzero_m_f32_rno_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rmm_8x1_t old = __riscv_ztt_mzero_m_f16_rmm_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f16_rmm_8x1_t d = __riscv_ztt_mldexpacc_ew_x_f16_rmm_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f16_rno (long exponent)
{
  __riscv_ztt_f64_rne_1x8_t a = __riscv_ztt_mzero_m_f64_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rno_1x8_t d = __riscv_ztt_mldexp_ew_x_f16_rno_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f16_rno (long exponent)
{
  __riscv_ztt_f64_rne_1x8_t a = __riscv_ztt_mzero_m_f64_rne_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f16_rno_1x8_t old = __riscv_ztt_mzero_m_f16_rno_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f16_rno_1x8_t d = __riscv_ztt_mldexpacc_ew_x_f16_rno_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_bf16_rne (long exponent)
{
  __riscv_ztt_f64_rtz_4x1_t a = __riscv_ztt_mzero_m_f64_rtz_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mldexp_ew_x_bf16_rne_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_bf16_rne (long exponent)
{
  __riscv_ztt_f64_rtz_4x1_t a = __riscv_ztt_mzero_m_f64_rtz_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rne_4x1_t old = __riscv_ztt_mzero_m_bf16_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_bf16_rne_4x1_t d = __riscv_ztt_mldexpacc_ew_x_bf16_rne_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_bf16_rtz (long exponent)
{
  __riscv_ztt_f64_rdn_1x8_t a = __riscv_ztt_mzero_m_f64_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rtz_1x8_t d = __riscv_ztt_mldexp_ew_x_bf16_rtz_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_bf16_rtz (long exponent)
{
  __riscv_ztt_f64_rdn_1x8_t a = __riscv_ztt_mzero_m_f64_rdn_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rtz_1x8_t old = __riscv_ztt_mzero_m_bf16_rtz_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_bf16_rtz_1x8_t d = __riscv_ztt_mldexpacc_ew_x_bf16_rtz_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_bf16_rdn (long exponent)
{
  __riscv_ztt_f64_rup_8x1_t a = __riscv_ztt_mzero_m_f64_rup_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rdn_8x1_t d = __riscv_ztt_mldexp_ew_x_bf16_rdn_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_bf16_rdn (long exponent)
{
  __riscv_ztt_f64_rup_8x1_t a = __riscv_ztt_mzero_m_f64_rup_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rdn_8x1_t old = __riscv_ztt_mzero_m_bf16_rdn_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_bf16_rdn_8x1_t d = __riscv_ztt_mldexpacc_ew_x_bf16_rdn_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_bf16_rup (long exponent)
{
  __riscv_ztt_f64_rmm_1x4_t a = __riscv_ztt_mzero_m_f64_rmm_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mldexp_ew_x_bf16_rup_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_bf16_rup (long exponent)
{
  __riscv_ztt_f64_rmm_1x4_t a = __riscv_ztt_mzero_m_f64_rmm_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rup_1x4_t old = __riscv_ztt_mzero_m_bf16_rup_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_bf16_rup_1x4_t d = __riscv_ztt_mldexpacc_ew_x_bf16_rup_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_bf16_rmm (long exponent)
{
  __riscv_ztt_f64_rno_8x1_t a = __riscv_ztt_mzero_m_f64_rno_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rmm_8x1_t d = __riscv_ztt_mldexp_ew_x_bf16_rmm_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_bf16_rmm (long exponent)
{
  __riscv_ztt_f64_rno_8x1_t a = __riscv_ztt_mzero_m_f64_rno_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rmm_8x1_t old = __riscv_ztt_mzero_m_bf16_rmm_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_bf16_rmm_8x1_t d = __riscv_ztt_mldexpacc_ew_x_bf16_rmm_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_bf16_rno (long exponent)
{
  __riscv_ztt_i4_rnu_1x32_t a = __riscv_ztt_mzero_m_i4_rnu_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rno_1x32_t d = __riscv_ztt_mldexp_ew_x_bf16_rno_1x32 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_bf16_rno (long exponent)
{
  __riscv_ztt_i4_rnu_1x32_t a = __riscv_ztt_mzero_m_i4_rnu_1x32 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_bf16_rno_1x32_t old = __riscv_ztt_mzero_m_bf16_rno_1x32 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_bf16_rno_1x32_t d = __riscv_ztt_mldexpacc_ew_x_bf16_rno_1x32 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f32_rne (long exponent)
{
  __riscv_ztt_i8_rnu_8x1_t a = __riscv_ztt_mzero_m_i8_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rne_8x1_t d = __riscv_ztt_mldexp_ew_x_f32_rne_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f32_rne (long exponent)
{
  __riscv_ztt_i8_rnu_8x1_t a = __riscv_ztt_mzero_m_i8_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rne_8x1_t old = __riscv_ztt_mzero_m_f32_rne_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f32_rne_8x1_t d = __riscv_ztt_mldexpacc_ew_x_f32_rne_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f32_rtz (long exponent)
{
  __riscv_ztt_i8_rnu_1x16_t a = __riscv_ztt_mzero_m_i8_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rtz_1x16_t d = __riscv_ztt_mldexp_ew_x_f32_rtz_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f32_rtz (long exponent)
{
  __riscv_ztt_i8_rnu_1x16_t a = __riscv_ztt_mzero_m_i8_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rtz_1x16_t old = __riscv_ztt_mzero_m_f32_rtz_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f32_rtz_1x16_t d = __riscv_ztt_mldexpacc_ew_x_f32_rtz_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f32_rdn (long exponent)
{
  __riscv_ztt_i8_rnu_16x1_t a = __riscv_ztt_mzero_m_i8_rnu_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rdn_16x1_t d = __riscv_ztt_mldexp_ew_x_f32_rdn_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f32_rdn (long exponent)
{
  __riscv_ztt_i8_rnu_16x1_t a = __riscv_ztt_mzero_m_i8_rnu_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rdn_16x1_t old = __riscv_ztt_mzero_m_f32_rdn_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f32_rdn_16x1_t d = __riscv_ztt_mldexpacc_ew_x_f32_rdn_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f32_rup (long exponent)
{
  __riscv_ztt_i8_rnu_1x8_t a = __riscv_ztt_mzero_m_i8_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rup_1x8_t d = __riscv_ztt_mldexp_ew_x_f32_rup_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f32_rup (long exponent)
{
  __riscv_ztt_i8_rnu_1x8_t a = __riscv_ztt_mzero_m_i8_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rup_1x8_t old = __riscv_ztt_mzero_m_f32_rup_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f32_rup_1x8_t d = __riscv_ztt_mldexpacc_ew_x_f32_rup_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f32_rmm (long exponent)
{
  __riscv_ztt_i8_rnu_16x1_t a = __riscv_ztt_mzero_m_i8_rnu_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rmm_16x1_t d = __riscv_ztt_mldexp_ew_x_f32_rmm_16x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f32_rmm (long exponent)
{
  __riscv_ztt_i8_rnu_16x1_t a = __riscv_ztt_mzero_m_i8_rnu_16x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rmm_16x1_t old = __riscv_ztt_mzero_m_f32_rmm_16x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f32_rmm_16x1_t d = __riscv_ztt_mldexpacc_ew_x_f32_rmm_16x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f32_rno (long exponent)
{
  __riscv_ztt_i8_rnu_1x16_t a = __riscv_ztt_mzero_m_i8_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rno_1x16_t d = __riscv_ztt_mldexp_ew_x_f32_rno_1x16 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f32_rno (long exponent)
{
  __riscv_ztt_i8_rnu_1x16_t a = __riscv_ztt_mzero_m_i8_rnu_1x16 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f32_rno_1x16_t old = __riscv_ztt_mzero_m_f32_rno_1x16 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f32_rno_1x16_t d = __riscv_ztt_mldexpacc_ew_x_f32_rno_1x16 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f64_rne (long exponent)
{
  __riscv_ztt_i16_rnu_4x1_t a = __riscv_ztt_mzero_m_i16_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rne_4x1_t d = __riscv_ztt_mldexp_ew_x_f64_rne_4x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f64_rne (long exponent)
{
  __riscv_ztt_i16_rnu_4x1_t a = __riscv_ztt_mzero_m_i16_rnu_4x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rne_4x1_t old = __riscv_ztt_mzero_m_f64_rne_4x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f64_rne_4x1_t d = __riscv_ztt_mldexpacc_ew_x_f64_rne_4x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f64_rtz (long exponent)
{
  __riscv_ztt_i16_rnu_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rtz_1x8_t d = __riscv_ztt_mldexp_ew_x_f64_rtz_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f64_rtz (long exponent)
{
  __riscv_ztt_i16_rnu_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rtz_1x8_t old = __riscv_ztt_mzero_m_f64_rtz_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f64_rtz_1x8_t d = __riscv_ztt_mldexpacc_ew_x_f64_rtz_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f64_rdn (long exponent)
{
  __riscv_ztt_i16_rnu_8x1_t a = __riscv_ztt_mzero_m_i16_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rdn_8x1_t d = __riscv_ztt_mldexp_ew_x_f64_rdn_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f64_rdn (long exponent)
{
  __riscv_ztt_i16_rnu_8x1_t a = __riscv_ztt_mzero_m_i16_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rdn_8x1_t old = __riscv_ztt_mzero_m_f64_rdn_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f64_rdn_8x1_t d = __riscv_ztt_mldexpacc_ew_x_f64_rdn_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f64_rup (long exponent)
{
  __riscv_ztt_i16_rnu_1x4_t a = __riscv_ztt_mzero_m_i16_rnu_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rup_1x4_t d = __riscv_ztt_mldexp_ew_x_f64_rup_1x4 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f64_rup (long exponent)
{
  __riscv_ztt_i16_rnu_1x4_t a = __riscv_ztt_mzero_m_i16_rnu_1x4 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rup_1x4_t old = __riscv_ztt_mzero_m_f64_rup_1x4 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f64_rup_1x4_t d = __riscv_ztt_mldexpacc_ew_x_f64_rup_1x4 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f64_rmm (long exponent)
{
  __riscv_ztt_i16_rnu_8x1_t a = __riscv_ztt_mzero_m_i16_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rmm_8x1_t d = __riscv_ztt_mldexp_ew_x_f64_rmm_8x1 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f64_rmm (long exponent)
{
  __riscv_ztt_i16_rnu_8x1_t a = __riscv_ztt_mzero_m_i16_rnu_8x1 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rmm_8x1_t old = __riscv_ztt_mzero_m_f64_rmm_8x1 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f64_rmm_8x1_t d = __riscv_ztt_mldexpacc_ew_x_f64_rmm_8x1 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
void exponent_mldexp_f64_rno (long exponent)
{
  __riscv_ztt_i16_rnu_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rno_1x8_t d = __riscv_ztt_mldexp_ew_x_f64_rno_1x8 (a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
}
void exponent_mldexpacc_f64_rno (long exponent)
{
  __riscv_ztt_i16_rnu_1x8_t a = __riscv_ztt_mzero_m_i16_rnu_1x8 ();
  __asm__ volatile ("" : "+Wmr" (a));
  __riscv_ztt_f64_rno_1x8_t old = __riscv_ztt_mzero_m_f64_rno_1x8 ();
  __asm__ volatile ("" : "+Wmr" (old));
  __riscv_ztt_f64_rno_1x8_t d = __riscv_ztt_mldexpacc_ew_x_f64_rno_1x8 (old, a, exponent);
  __asm__ volatile ("" : : "Wmr" (d));
  __asm__ volatile ("" : : "Wmr" (a));
  __asm__ volatile ("" : : "Wmr" (old));
}
