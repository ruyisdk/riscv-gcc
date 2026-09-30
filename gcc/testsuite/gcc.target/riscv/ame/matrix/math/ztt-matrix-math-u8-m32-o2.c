/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m32-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_matrix_math != 1
#error missing matrix math capability
#endif
void math_mldexp_i4_rnu (void)
{
  __riscv_ztt_i4_rne_2x1_t a = __riscv_ztt_mzero_m_i4_rne_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t d = __riscv_ztt_mldexp_ew_i4_rnu_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rne (void)
{
  __riscv_ztt_i4_rdn_1x4_t a = __riscv_ztt_mzero_m_i4_rdn_1x4 ();
  __riscv_ztt_u4_rod_1x4_t b = __riscv_ztt_mzero_m_u4_rod_1x4 ();
  __riscv_ztt_i4_rne_1x4_t d = __riscv_ztt_mldexp_ew_i4_rne_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rdn (void)
{
  __riscv_ztt_i4_rod_4x1_t a = __riscv_ztt_mzero_m_i4_rod_4x1 ();
  __riscv_ztt_u8_rdn_4x1_t b = __riscv_ztt_mzero_m_u8_rdn_4x1 ();
  __riscv_ztt_i4_rdn_4x1_t d = __riscv_ztt_mldexp_ew_i4_rdn_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rod (void)
{
  __riscv_ztt_u4_rnu_1x2_t a = __riscv_ztt_mzero_m_u4_rnu_1x2 ();
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_i4_rod_1x2_t d = __riscv_ztt_mldexp_ew_i4_rod_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rnu (void)
{
  __riscv_ztt_u4_rne_4x1_t a = __riscv_ztt_mzero_m_u4_rne_4x1 ();
  __riscv_ztt_i4_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_4x1 ();
  __riscv_ztt_u4_rnu_4x1_t d = __riscv_ztt_mldexp_ew_u4_rnu_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rne (void)
{
  __riscv_ztt_u4_rdn_1x8_t a = __riscv_ztt_mzero_m_u4_rdn_1x8 ();
  __riscv_ztt_i4_rod_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x8 ();
  __riscv_ztt_u4_rne_1x8_t d = __riscv_ztt_mldexp_ew_u4_rne_1x8 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rdn (void)
{
  __riscv_ztt_u4_rod_2x1_t a = __riscv_ztt_mzero_m_u4_rod_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mldexp_ew_u4_rdn_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rod (void)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mzero_m_i8_rnu_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_u4_rod_1x2_t d = __riscv_ztt_mldexp_ew_u4_rod_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rnu (void)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mldexp_ew_i8_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rne (void)
{
  __riscv_ztt_i8_rdn_1x1_t a = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mldexp_ew_i8_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rdn (void)
{
  __riscv_ztt_i8_rod_4x1_t a = __riscv_ztt_mzero_m_i8_rod_4x1 ();
  __riscv_ztt_u4_rdn_4x1_t b = __riscv_ztt_mzero_m_u4_rdn_4x1 ();
  __riscv_ztt_i8_rdn_4x1_t d = __riscv_ztt_mldexp_ew_i8_rdn_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rod (void)
{
  __riscv_ztt_u8_rnu_1x4_t a = __riscv_ztt_mzero_m_u8_rnu_1x4 ();
  __riscv_ztt_u8_rne_1x4_t b = __riscv_ztt_mzero_m_u8_rne_1x4 ();
  __riscv_ztt_i8_rod_1x4_t d = __riscv_ztt_mldexp_ew_i8_rod_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rnu (void)
{
  __riscv_ztt_u8_rne_1x1_t a = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mldexp_ew_u8_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rne (void)
{
  __riscv_ztt_u8_rdn_1x1_t a = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mldexp_ew_u8_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rdn (void)
{
  __riscv_ztt_u8_rod_4x1_t a = __riscv_ztt_mzero_m_u8_rod_4x1 ();
  __riscv_ztt_i4_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_4x1 ();
  __riscv_ztt_u8_rdn_4x1_t d = __riscv_ztt_mldexp_ew_u8_rdn_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rod (void)
{
  __riscv_ztt_i16_rnu_1x1_t a = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mldexp_ew_u8_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rnu (void)
{
  __riscv_ztt_i16_rne_2x1_t a = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i16_rnu_2x1_t d = __riscv_ztt_mldexp_ew_i16_rnu_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rne (void)
{
  __riscv_ztt_i16_rdn_1x2_t a = __riscv_ztt_mzero_m_i16_rdn_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_i16_rne_1x2_t d = __riscv_ztt_mldexp_ew_i16_rne_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rdn (void)
{
  __riscv_ztt_i16_rod_1x1_t a = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t d = __riscv_ztt_mldexp_ew_i16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rod (void)
{
  __riscv_ztt_u16_rnu_1x2_t a = __riscv_ztt_mzero_m_u16_rnu_1x2 ();
  __riscv_ztt_u4_rne_1x2_t b = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_i16_rod_1x2_t d = __riscv_ztt_mldexp_ew_i16_rod_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rnu (void)
{
  __riscv_ztt_u16_rne_2x1_t a = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_u8_rnu_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mldexp_ew_u16_rnu_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rne (void)
{
  __riscv_ztt_u16_rdn_1x1_t a = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mldexp_ew_u16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rdn (void)
{
  __riscv_ztt_u16_rod_1x1_t a = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mldexp_ew_u16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rod (void)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mldexp_ew_u16_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rnu (void)
{
  __riscv_ztt_i32_rne_1x1_t a = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mldexp_ew_i32_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rne (void)
{
  __riscv_ztt_i32_rdn_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mldexp_ew_i32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rdn (void)
{
  __riscv_ztt_i32_rod_1x1_t a = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mldexp_ew_i32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rod (void)
{
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mldexp_ew_i32_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rnu (void)
{
  __riscv_ztt_u32_rne_1x1_t a = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mldexp_ew_u32_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rne (void)
{
  __riscv_ztt_u32_rdn_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mldexp_ew_u32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rdn (void)
{
  __riscv_ztt_u32_rod_1x1_t a = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mldexp_ew_u32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rod (void)
{
  __riscv_ztt_i8_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mldexp_ew_u32_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rnu_sat (void)
{
  __riscv_ztt_i4_rne_sat_8x1_t a = __riscv_ztt_mzero_m_i4_rne_sat_8x1 ();
  __riscv_ztt_i4_rnu_sat_8x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_8x1 ();
  __riscv_ztt_i4_rnu_sat_8x1_t d = __riscv_ztt_mldexp_ew_i4_rnu_sat_8x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rne_sat (void)
{
  __riscv_ztt_i4_rdn_sat_1x2_t a = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t d = __riscv_ztt_mldexp_ew_i4_rne_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rdn_sat (void)
{
  __riscv_ztt_i4_rod_sat_4x1_t a = __riscv_ztt_mzero_m_i4_rod_sat_4x1 ();
  __riscv_ztt_u8_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_4x1 ();
  __riscv_ztt_i4_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_i4_rdn_sat_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i4_rod_sat (void)
{
  __riscv_ztt_u4_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_u4_rnu_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t d = __riscv_ztt_mldexp_ew_i4_rod_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rnu_sat (void)
{
  __riscv_ztt_u4_rne_sat_2x1_t a = __riscv_ztt_mzero_m_u4_rne_sat_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t d = __riscv_ztt_mldexp_ew_u4_rnu_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rne_sat (void)
{
  __riscv_ztt_u4_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_u4_rdn_sat_1x4 ();
  __riscv_ztt_i4_rod_1x4_t b = __riscv_ztt_mzero_m_i4_rod_1x4 ();
  __riscv_ztt_u4_rne_sat_1x4_t d = __riscv_ztt_mldexp_ew_u4_rne_sat_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rdn_sat (void)
{
  __riscv_ztt_u4_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u4_rod_sat_4x1 ();
  __riscv_ztt_i8_rdn_4x1_t b = __riscv_ztt_mzero_m_i8_rdn_4x1 ();
  __riscv_ztt_u4_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_u4_rdn_sat_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u4_rod_sat (void)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i8_rnu_sat_1x2 ();
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_mldexp_ew_u4_rod_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rnu_sat (void)
{
  __riscv_ztt_i8_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mldexp_ew_i8_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rne_sat (void)
{
  __riscv_ztt_i8_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t d = __riscv_ztt_mldexp_ew_i8_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rdn_sat (void)
{
  __riscv_ztt_i8_rod_sat_2x1_t a = __riscv_ztt_mzero_m_i8_rod_sat_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t d = __riscv_ztt_mldexp_ew_i8_rdn_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i8_rod_sat (void)
{
  __riscv_ztt_u8_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_u8_rnu_sat_1x2 ();
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x2 ();
  __riscv_ztt_i8_rod_sat_1x2_t d = __riscv_ztt_mldexp_ew_i8_rod_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rnu_sat (void)
{
  __riscv_ztt_u8_rne_sat_2x1_t a = __riscv_ztt_mzero_m_u8_rne_sat_2x1 ();
  __riscv_ztt_u16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t d = __riscv_ztt_mldexp_ew_u8_rnu_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rne_sat (void)
{
  __riscv_ztt_u8_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mldexp_ew_u8_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rdn_sat (void)
{
  __riscv_ztt_u8_rod_sat_4x1_t a = __riscv_ztt_mzero_m_u8_rod_sat_4x1 ();
  __riscv_ztt_i4_rdn_4x1_t b = __riscv_ztt_mzero_m_i4_rdn_4x1 ();
  __riscv_ztt_u8_rdn_sat_4x1_t d = __riscv_ztt_mldexp_ew_u8_rdn_sat_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u8_rod_sat (void)
{
  __riscv_ztt_i16_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x2 ();
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t d = __riscv_ztt_mldexp_ew_u8_rod_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rnu_sat (void)
{
  __riscv_ztt_i16_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mldexp_ew_i16_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rne_sat (void)
{
  __riscv_ztt_i16_rdn_sat_1x2_t a = __riscv_ztt_mzero_m_i16_rdn_sat_1x2 ();
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t d = __riscv_ztt_mldexp_ew_i16_rne_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rdn_sat (void)
{
  __riscv_ztt_i16_rod_sat_1x1_t a = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t d = __riscv_ztt_mldexp_ew_i16_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i16_rod_sat (void)
{
  __riscv_ztt_u16_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_u16_rnu_sat_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mldexp_ew_i16_rod_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rnu_sat (void)
{
  __riscv_ztt_u16_rne_sat_2x1_t a = __riscv_ztt_mzero_m_u16_rne_sat_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_2x1 ();
  __riscv_ztt_u16_rnu_sat_2x1_t d = __riscv_ztt_mldexp_ew_u16_rnu_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rne_sat (void)
{
  __riscv_ztt_u16_rdn_sat_1x2_t a = __riscv_ztt_mzero_m_u16_rdn_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t d = __riscv_ztt_mldexp_ew_u16_rne_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rdn_sat (void)
{
  __riscv_ztt_u16_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mldexp_ew_u16_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u16_rod_sat (void)
{
  __riscv_ztt_i32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mldexp_ew_u16_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rnu_sat (void)
{
  __riscv_ztt_i32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mldexp_ew_i32_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rne_sat (void)
{
  __riscv_ztt_i32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mldexp_ew_i32_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rdn_sat (void)
{
  __riscv_ztt_i32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mldexp_ew_i32_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_i32_rod_sat (void)
{
  __riscv_ztt_u32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mldexp_ew_i32_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rnu_sat (void)
{
  __riscv_ztt_u32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mldexp_ew_u32_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rne_sat (void)
{
  __riscv_ztt_u32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mldexp_ew_u32_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rdn_sat (void)
{
  __riscv_ztt_u32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mldexp_ew_u32_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_u32_rod_sat (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mldexp_ew_u32_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f16_rne (void)
{
  __riscv_ztt_f16_rtz_2x1_t a = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mldexp_ew_f16_rne_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f16_rtz (void)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u4_rod_1x2_t b = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mldexp_ew_f16_rtz_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f16_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mldexp_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f16_rup (void)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mldexp_ew_f16_rup_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f16_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mldexp_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f16_rno (void)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mldexp_ew_f16_rno_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_bf16_rne (void)
{
  __riscv_ztt_bf16_rtz_2x1_t a = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_i8_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mldexp_ew_bf16_rne_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_bf16_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x2_t a = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mldexp_ew_bf16_rtz_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_bf16_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mldexp_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_bf16_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_mldexp_ew_bf16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_bf16_rmm (void)
{
  __riscv_ztt_bf16_rno_2x1_t a = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mldexp_ew_bf16_rmm_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_bf16_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mldexp_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f32_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mldexp_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f32_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mldexp_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f32_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mldexp_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f32_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mldexp_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f32_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mldexp_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexp_f32_rno (void)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mldexp_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rnu (void)
{
  __riscv_ztt_i4_rne_1x4_t a = __riscv_ztt_mzero_m_i4_rne_1x4 ();
  __riscv_ztt_i4_rod_1x4_t b = __riscv_ztt_mzero_m_i4_rod_1x4 ();
  __riscv_ztt_i4_rnu_1x4_t d = __riscv_ztt_mrdexp_ew_i4_rnu_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rne (void)
{
  __riscv_ztt_i4_rdn_4x1_t a = __riscv_ztt_mzero_m_i4_rdn_4x1 ();
  __riscv_ztt_i8_rdn_4x1_t b = __riscv_ztt_mzero_m_i8_rdn_4x1 ();
  __riscv_ztt_i4_rne_4x1_t d = __riscv_ztt_mrdexp_ew_i4_rne_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rdn (void)
{
  __riscv_ztt_i4_rod_1x2_t a = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mrdexp_ew_i4_rdn_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rod (void)
{
  __riscv_ztt_u4_rnu_4x1_t a = __riscv_ztt_mzero_m_u4_rnu_4x1 ();
  __riscv_ztt_i4_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_4x1 ();
  __riscv_ztt_i4_rod_4x1_t d = __riscv_ztt_mrdexp_ew_i4_rod_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rnu (void)
{
  __riscv_ztt_u4_rne_1x8_t a = __riscv_ztt_mzero_m_u4_rne_1x8 ();
  __riscv_ztt_i4_rnu_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x8 ();
  __riscv_ztt_u4_rnu_1x8_t d = __riscv_ztt_mrdexp_ew_u4_rnu_1x8 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rne (void)
{
  __riscv_ztt_u4_rdn_2x1_t a = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_u4_rne_2x1_t d = __riscv_ztt_mrdexp_ew_u4_rne_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rdn (void)
{
  __riscv_ztt_u4_rod_1x4_t a = __riscv_ztt_mzero_m_u4_rod_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_u4_rdn_1x4_t d = __riscv_ztt_mrdexp_ew_u4_rdn_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rod (void)
{
  __riscv_ztt_i8_rnu_2x1_t a = __riscv_ztt_mzero_m_i8_rnu_2x1 ();
  __riscv_ztt_u16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_2x1 ();
  __riscv_ztt_u4_rod_2x1_t d = __riscv_ztt_mrdexp_ew_u4_rod_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rnu (void)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mrdexp_ew_i8_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rne (void)
{
  __riscv_ztt_i8_rdn_4x1_t a = __riscv_ztt_mzero_m_i8_rdn_4x1 ();
  __riscv_ztt_i4_rdn_4x1_t b = __riscv_ztt_mzero_m_i4_rdn_4x1 ();
  __riscv_ztt_i8_rne_4x1_t d = __riscv_ztt_mrdexp_ew_i8_rne_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rdn (void)
{
  __riscv_ztt_i8_rod_1x4_t a = __riscv_ztt_mzero_m_i8_rod_1x4 ();
  __riscv_ztt_i8_rne_1x4_t b = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i8_rdn_1x4_t d = __riscv_ztt_mrdexp_ew_i8_rdn_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rod (void)
{
  __riscv_ztt_u8_rnu_1x1_t a = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i8_rod_1x1_t d = __riscv_ztt_mrdexp_ew_i8_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rnu (void)
{
  __riscv_ztt_u8_rne_1x2_t a = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u8_rnu_1x2_t d = __riscv_ztt_mrdexp_ew_u8_rnu_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rne (void)
{
  __riscv_ztt_u8_rdn_1x1_t a = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u8_rne_1x1_t d = __riscv_ztt_mrdexp_ew_u8_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rdn (void)
{
  __riscv_ztt_u8_rod_1x2_t a = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u8_rdn_1x2_t d = __riscv_ztt_mrdexp_ew_u8_rdn_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rod (void)
{
  __riscv_ztt_i16_rnu_2x1_t a = __riscv_ztt_mzero_m_i16_rnu_2x1 ();
  __riscv_ztt_u8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_2x1 ();
  __riscv_ztt_u8_rod_2x1_t d = __riscv_ztt_mrdexp_ew_u8_rod_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rnu (void)
{
  __riscv_ztt_i16_rne_1x2_t a = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rnu_1x2_t d = __riscv_ztt_mrdexp_ew_i16_rnu_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rne (void)
{
  __riscv_ztt_i16_rdn_1x1_t a = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mrdexp_ew_i16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rdn (void)
{
  __riscv_ztt_i16_rod_1x2_t a = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i4_rne_1x2_t b = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mrdexp_ew_i16_rdn_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rod (void)
{
  __riscv_ztt_u16_rnu_2x1_t a = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mrdexp_ew_i16_rod_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rnu (void)
{
  __riscv_ztt_u16_rne_1x1_t a = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u8_rod_1x1_t b = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t d = __riscv_ztt_mrdexp_ew_u16_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rne (void)
{
  __riscv_ztt_u16_rdn_2x1_t a = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_u16_rne_2x1_t d = __riscv_ztt_mrdexp_ew_u16_rne_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rdn (void)
{
  __riscv_ztt_u16_rod_1x1_t a = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t d = __riscv_ztt_mrdexp_ew_u16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rod (void)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mrdexp_ew_u16_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rnu (void)
{
  __riscv_ztt_i32_rne_1x1_t a = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rne (void)
{
  __riscv_ztt_i32_rdn_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rdn (void)
{
  __riscv_ztt_i32_rod_1x1_t a = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rod (void)
{
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rnu (void)
{
  __riscv_ztt_u32_rne_1x1_t a = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rnu_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rne (void)
{
  __riscv_ztt_u32_rdn_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rdn (void)
{
  __riscv_ztt_u32_rod_1x1_t a = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rod (void)
{
  __riscv_ztt_i8_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rod_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rnu_sat (void)
{
  __riscv_ztt_i4_rne_sat_1x2_t a = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_i4_rnu_sat_1x2_t d = __riscv_ztt_mrdexp_ew_i4_rnu_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rne_sat (void)
{
  __riscv_ztt_i4_rdn_sat_4x1_t a = __riscv_ztt_mzero_m_i4_rdn_sat_4x1 ();
  __riscv_ztt_i8_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_4x1 ();
  __riscv_ztt_i4_rne_sat_4x1_t d = __riscv_ztt_mrdexp_ew_i4_rne_sat_4x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rdn_sat (void)
{
  __riscv_ztt_i4_rod_sat_1x2_t a = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_i16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mrdexp_ew_i4_rdn_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i4_rod_sat (void)
{
  __riscv_ztt_u4_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_u4_rnu_sat_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_i4_rod_sat_2x1_t d = __riscv_ztt_mrdexp_ew_i4_rod_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rnu_sat (void)
{
  __riscv_ztt_u4_rne_sat_1x4_t a = __riscv_ztt_mzero_m_u4_rne_sat_1x4 ();
  __riscv_ztt_i4_rnu_1x4_t b = __riscv_ztt_mzero_m_i4_rnu_1x4 ();
  __riscv_ztt_u4_rnu_sat_1x4_t d = __riscv_ztt_mrdexp_ew_u4_rnu_sat_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rne_sat (void)
{
  __riscv_ztt_u4_rdn_sat_8x1_t a = __riscv_ztt_mzero_m_u4_rdn_sat_8x1 ();
  __riscv_ztt_u4_rdn_8x1_t b = __riscv_ztt_mzero_m_u4_rdn_8x1 ();
  __riscv_ztt_u4_rne_sat_8x1_t d = __riscv_ztt_mrdexp_ew_u4_rne_sat_8x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rdn_sat (void)
{
  __riscv_ztt_u4_rod_sat_1x2_t a = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mrdexp_ew_u4_rdn_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u4_rod_sat (void)
{
  __riscv_ztt_i8_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t d = __riscv_ztt_mrdexp_ew_u4_rod_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rnu_sat (void)
{
  __riscv_ztt_i8_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mrdexp_ew_i8_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rne_sat (void)
{
  __riscv_ztt_i8_rdn_sat_2x1_t a = __riscv_ztt_mzero_m_i8_rdn_sat_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_i8_rne_sat_2x1_t d = __riscv_ztt_mrdexp_ew_i8_rne_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rdn_sat (void)
{
  __riscv_ztt_i8_rod_sat_1x2_t a = __riscv_ztt_mzero_m_i8_rod_sat_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x2 ();
  __riscv_ztt_i8_rdn_sat_1x2_t d = __riscv_ztt_mrdexp_ew_i8_rdn_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i8_rod_sat (void)
{
  __riscv_ztt_u8_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_u8_rnu_sat_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t d = __riscv_ztt_mrdexp_ew_i8_rod_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rnu_sat (void)
{
  __riscv_ztt_u8_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u8_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rne_sat (void)
{
  __riscv_ztt_u8_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u8_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rdn_sat (void)
{
  __riscv_ztt_u8_rod_sat_1x4_t a = __riscv_ztt_mzero_m_u8_rod_sat_1x4 ();
  __riscv_ztt_u4_rne_1x4_t b = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u8_rdn_sat_1x4_t d = __riscv_ztt_mrdexp_ew_u8_rdn_sat_1x4 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u8_rod_sat (void)
{
  __riscv_ztt_i16_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u8_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rnu_sat (void)
{
  __riscv_ztt_i16_rne_sat_1x2_t a = __riscv_ztt_mzero_m_i16_rne_sat_1x2 ();
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i16_rnu_sat_1x2_t d = __riscv_ztt_mrdexp_ew_i16_rnu_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rne_sat (void)
{
  __riscv_ztt_i16_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mrdexp_ew_i16_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rdn_sat (void)
{
  __riscv_ztt_i16_rod_sat_1x2_t a = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t d = __riscv_ztt_mrdexp_ew_i16_rdn_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i16_rod_sat (void)
{
  __riscv_ztt_u16_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_u16_rnu_sat_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_i16_rod_sat_2x1_t d = __riscv_ztt_mrdexp_ew_i16_rod_sat_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rnu_sat (void)
{
  __riscv_ztt_u16_rne_sat_1x2_t a = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u16_rnu_sat_1x2_t d = __riscv_ztt_mrdexp_ew_u16_rnu_sat_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rne_sat (void)
{
  __riscv_ztt_u16_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u16_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rdn_sat (void)
{
  __riscv_ztt_u16_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u16_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u16_rod_sat (void)
{
  __riscv_ztt_i32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u16_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rnu_sat (void)
{
  __riscv_ztt_i32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rne_sat (void)
{
  __riscv_ztt_i32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i16_rdn_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rdn_sat (void)
{
  __riscv_ztt_i32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_i32_rod_sat (void)
{
  __riscv_ztt_u32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mrdexp_ew_i32_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rnu_sat (void)
{
  __riscv_ztt_u32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rnu_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rne_sat (void)
{
  __riscv_ztt_u32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rne_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rdn_sat (void)
{
  __riscv_ztt_u32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rdn_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_u32_rod_sat (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mrdexp_ew_u32_rod_sat_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f16_rne (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_i4_rod_1x2_t b = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mrdexp_ew_f16_rne_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f16_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_mrdexp_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f16_rdn (void)
{
  __riscv_ztt_f16_rup_1x2_t a = __riscv_ztt_mzero_m_f16_rup_1x2 ();
  __riscv_ztt_i16_rne_1x2_t b = __riscv_ztt_mzero_m_i16_rne_1x2 ();
  __riscv_ztt_f16_rdn_1x2_t d = __riscv_ztt_mrdexp_ew_f16_rdn_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f16_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mrdexp_ew_f16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f16_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_mrdexp_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f16_rno (void)
{
  __riscv_ztt_bf16_rne_2x1_t a = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_mrdexp_ew_f16_rno_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_bf16_rne (void)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_u8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mrdexp_ew_bf16_rne_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_bf16_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mrdexp_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_bf16_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mrdexp_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_bf16_rup (void)
{
  __riscv_ztt_bf16_rmm_2x1_t a = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t b = __riscv_ztt_mzero_m_i4_rdn_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mrdexp_ew_bf16_rup_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_bf16_rmm (void)
{
  __riscv_ztt_bf16_rno_1x1_t a = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_bf16_rmm_1x1_t d = __riscv_ztt_mrdexp_ew_bf16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_bf16_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mrdexp_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f32_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mrdexp_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f32_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mrdexp_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f32_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mrdexp_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f32_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mrdexp_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f32_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mrdexp_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mrdexp_f32_rno (void)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mrdexp_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mldexpacc_i4_rnu (void)
{
  __riscv_ztt_i4_rne_8x1_t a = __riscv_ztt_mzero_m_i4_rne_8x1 ();
  __riscv_ztt_u4_rdn_8x1_t b = __riscv_ztt_mzero_m_u4_rdn_8x1 ();
  __riscv_ztt_i4_rnu_8x1_t old = __riscv_ztt_mzero_m_i4_rnu_8x1 ();
  __riscv_ztt_i4_rnu_8x1_t d = __riscv_ztt_mldexpacc_ew_i4_rnu_8x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rne (void)
{
  __riscv_ztt_i4_rdn_1x2_t a = __riscv_ztt_mzero_m_i4_rdn_1x2 ();
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_i4_rne_1x2_t old = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i4_rne_1x2_t d = __riscv_ztt_mldexpacc_ew_i4_rne_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rdn (void)
{
  __riscv_ztt_i4_rod_2x1_t a = __riscv_ztt_mzero_m_i4_rod_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t old = __riscv_ztt_mzero_m_i4_rdn_2x1 ();
  __riscv_ztt_i4_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_i4_rdn_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rod (void)
{
  __riscv_ztt_u4_rnu_1x8_t a = __riscv_ztt_mzero_m_u4_rnu_1x8 ();
  __riscv_ztt_i4_rnu_sat_1x8_t b = __riscv_ztt_mzero_m_i4_rnu_sat_1x8 ();
  __riscv_ztt_i4_rod_1x8_t old = __riscv_ztt_mzero_m_i4_rod_1x8 ();
  __riscv_ztt_i4_rod_1x8_t d = __riscv_ztt_mldexpacc_ew_i4_rod_1x8 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rnu (void)
{
  __riscv_ztt_u4_rne_2x1_t a = __riscv_ztt_mzero_m_u4_rne_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t old = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t d = __riscv_ztt_mldexpacc_ew_u4_rnu_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rne (void)
{
  __riscv_ztt_u4_rdn_1x4_t a = __riscv_ztt_mzero_m_u4_rdn_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_u4_rne_1x4_t old = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u4_rne_1x4_t d = __riscv_ztt_mldexpacc_ew_u4_rne_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rdn (void)
{
  __riscv_ztt_u4_rod_2x1_t a = __riscv_ztt_mzero_m_u4_rod_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t old = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_u4_rdn_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rod (void)
{
  __riscv_ztt_i8_rnu_1x2_t a = __riscv_ztt_mzero_m_i8_rnu_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_u4_rod_1x2_t old = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_u4_rod_1x2_t d = __riscv_ztt_mldexpacc_ew_u4_rod_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rnu (void)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t old = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t d = __riscv_ztt_mldexpacc_ew_i8_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rne (void)
{
  __riscv_ztt_i8_rdn_1x4_t a = __riscv_ztt_mzero_m_i8_rdn_1x4 ();
  __riscv_ztt_u4_rne_1x4_t b = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_i8_rne_1x4_t old = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i8_rne_1x4_t d = __riscv_ztt_mldexpacc_ew_i8_rne_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rdn (void)
{
  __riscv_ztt_i8_rod_1x1_t a = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t old = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t d = __riscv_ztt_mldexpacc_ew_i8_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rod (void)
{
  __riscv_ztt_u8_rnu_1x2_t a = __riscv_ztt_mzero_m_u8_rnu_1x2 ();
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_i8_rod_1x2_t old = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_i8_rod_1x2_t d = __riscv_ztt_mldexpacc_ew_i8_rod_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rnu (void)
{
  __riscv_ztt_u8_rne_1x1_t a = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mldexpacc_ew_u8_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rne (void)
{
  __riscv_ztt_u8_rdn_1x2_t a = __riscv_ztt_mzero_m_u8_rdn_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_u8_rne_1x2_t old = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_u8_rne_1x2_t d = __riscv_ztt_mldexpacc_ew_u8_rne_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rdn (void)
{
  __riscv_ztt_u8_rod_2x1_t a = __riscv_ztt_mzero_m_u8_rod_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_u8_rdn_2x1_t old = __riscv_ztt_mzero_m_u8_rdn_2x1 ();
  __riscv_ztt_u8_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_u8_rdn_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rod (void)
{
  __riscv_ztt_i16_rnu_1x2_t a = __riscv_ztt_mzero_m_i16_rnu_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u8_rod_1x2_t old = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u8_rod_1x2_t d = __riscv_ztt_mldexpacc_ew_u8_rod_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rnu (void)
{
  __riscv_ztt_i16_rne_1x1_t a = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mldexpacc_ew_i16_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rne (void)
{
  __riscv_ztt_i16_rdn_1x1_t a = __riscv_ztt_mzero_m_i16_rdn_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_1x1_t old = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i16_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_i16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rdn (void)
{
  __riscv_ztt_i16_rod_2x1_t a = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t b = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t old = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_i16_rdn_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rod (void)
{
  __riscv_ztt_u16_rnu_1x1_t a = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mzero_m_i8_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t old = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_i16_rod_1x1_t d = __riscv_ztt_mldexpacc_ew_i16_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rnu (void)
{
  __riscv_ztt_u16_rne_2x1_t a = __riscv_ztt_mzero_m_u16_rne_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t old = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t d = __riscv_ztt_mldexpacc_ew_u16_rnu_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rne (void)
{
  __riscv_ztt_u16_rdn_1x1_t a = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t old = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_u16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rdn (void)
{
  __riscv_ztt_u16_rod_2x1_t a = __riscv_ztt_mzero_m_u16_rod_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t old = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_u16_rdn_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rod (void)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u16_rod_1x1_t old = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mldexpacc_ew_u16_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rnu (void)
{
  __riscv_ztt_i32_rne_1x1_t a = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rne (void)
{
  __riscv_ztt_i32_rdn_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t old = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rdn (void)
{
  __riscv_ztt_i32_rod_1x1_t a = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rod (void)
{
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i32_rod_1x1_t old = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rnu (void)
{
  __riscv_ztt_u32_rne_1x1_t a = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rne (void)
{
  __riscv_ztt_u32_rdn_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t old = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rdn (void)
{
  __riscv_ztt_u32_rod_1x1_t a = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rod (void)
{
  __riscv_ztt_i8_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t old = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rnu_sat (void)
{
  __riscv_ztt_i4_rne_sat_4x1_t a = __riscv_ztt_mzero_m_i4_rne_sat_4x1 ();
  __riscv_ztt_u4_rdn_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rdn_sat_4x1 ();
  __riscv_ztt_i4_rnu_sat_4x1_t old = __riscv_ztt_mzero_m_i4_rnu_sat_4x1 ();
  __riscv_ztt_i4_rnu_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_i4_rnu_sat_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rne_sat (void)
{
  __riscv_ztt_i4_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_i4_rdn_sat_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t old = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_i4_rne_sat_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rdn_sat (void)
{
  __riscv_ztt_i4_rod_sat_2x1_t a = __riscv_ztt_mzero_m_i4_rod_sat_2x1 ();
  __riscv_ztt_u16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_i4_rdn_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i4_rod_sat (void)
{
  __riscv_ztt_u4_rnu_sat_1x4_t a = __riscv_ztt_mzero_m_u4_rnu_sat_1x4 ();
  __riscv_ztt_i4_rnu_1x4_t b = __riscv_ztt_mzero_m_i4_rnu_1x4 ();
  __riscv_ztt_i4_rod_sat_1x4_t old = __riscv_ztt_mzero_m_i4_rod_sat_1x4 ();
  __riscv_ztt_i4_rod_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_i4_rod_sat_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rnu_sat (void)
{
  __riscv_ztt_u4_rne_sat_8x1_t a = __riscv_ztt_mzero_m_u4_rne_sat_8x1 ();
  __riscv_ztt_i4_rdn_8x1_t b = __riscv_ztt_mzero_m_i4_rdn_8x1 ();
  __riscv_ztt_u4_rnu_sat_8x1_t old = __riscv_ztt_mzero_m_u4_rnu_sat_8x1 ();
  __riscv_ztt_u4_rnu_sat_8x1_t d = __riscv_ztt_mldexpacc_ew_u4_rnu_sat_8x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rne_sat (void)
{
  __riscv_ztt_u4_rdn_sat_1x2_t a = __riscv_ztt_mzero_m_u4_rdn_sat_1x2 ();
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t d = __riscv_ztt_mldexpacc_ew_u4_rne_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rdn_sat (void)
{
  __riscv_ztt_u4_rod_sat_2x1_t a = __riscv_ztt_mzero_m_u4_rod_sat_2x1 ();
  __riscv_ztt_i16_rnu_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rdn_sat_2x1 ();
  __riscv_ztt_u4_rdn_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_u4_rdn_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u4_rod_sat (void)
{
  __riscv_ztt_i8_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i8_rnu_sat_1x2 ();
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t d = __riscv_ztt_mldexpacc_ew_u4_rod_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rnu_sat (void)
{
  __riscv_ztt_i8_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rne_sat_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i8_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rne_sat (void)
{
  __riscv_ztt_i8_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_i8_rdn_sat_1x4 ();
  __riscv_ztt_u4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t old = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_i8_rne_sat_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rdn_sat (void)
{
  __riscv_ztt_i8_rod_sat_4x1_t a = __riscv_ztt_mzero_m_i8_rod_sat_4x1 ();
  __riscv_ztt_u8_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_4x1 ();
  __riscv_ztt_i8_rdn_sat_4x1_t old = __riscv_ztt_mzero_m_i8_rdn_sat_4x1 ();
  __riscv_ztt_i8_rdn_sat_4x1_t d = __riscv_ztt_mldexpacc_ew_i8_rdn_sat_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i8_rod_sat (void)
{
  __riscv_ztt_u8_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i8_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rnu_sat (void)
{
  __riscv_ztt_u8_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u8_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rne_sat (void)
{
  __riscv_ztt_u8_rdn_sat_1x4_t a = __riscv_ztt_mzero_m_u8_rdn_sat_1x4 ();
  __riscv_ztt_i4_rne_1x4_t b = __riscv_ztt_mzero_m_i4_rne_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t old = __riscv_ztt_mzero_m_u8_rne_sat_1x4 ();
  __riscv_ztt_u8_rne_sat_1x4_t d = __riscv_ztt_mldexpacc_ew_u8_rne_sat_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rdn_sat (void)
{
  __riscv_ztt_u8_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u8_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u8_rod_sat (void)
{
  __riscv_ztt_i16_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_i16_rnu_sat_1x2 ();
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_u8_rod_sat_1x2_t d = __riscv_ztt_mldexpacc_ew_u8_rod_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rnu_sat (void)
{
  __riscv_ztt_i16_rne_sat_2x1_t a = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_i16_rnu_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rne_sat (void)
{
  __riscv_ztt_i16_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i16_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rdn_sat (void)
{
  __riscv_ztt_i16_rod_sat_2x1_t a = __riscv_ztt_mzero_m_i16_rod_sat_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rnu_sat_2x1 ();
  __riscv_ztt_i16_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_i16_rdn_sat_2x1 ();
  __riscv_ztt_i16_rdn_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_i16_rdn_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i16_rod_sat (void)
{
  __riscv_ztt_u16_rnu_sat_1x2_t a = __riscv_ztt_mzero_m_u16_rnu_sat_1x2 ();
  __riscv_ztt_i8_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t d = __riscv_ztt_mldexpacc_ew_i16_rod_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rnu_sat (void)
{
  __riscv_ztt_u16_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u16_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rne_sat (void)
{
  __riscv_ztt_u16_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u16_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rdn_sat (void)
{
  __riscv_ztt_u16_rod_sat_2x1_t a = __riscv_ztt_mzero_m_u16_rod_sat_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t old = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t d = __riscv_ztt_mldexpacc_ew_u16_rdn_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u16_rod_sat (void)
{
  __riscv_ztt_i32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u16_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rnu_sat (void)
{
  __riscv_ztt_i32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rne_sat (void)
{
  __riscv_ztt_i32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rdn_sat (void)
{
  __riscv_ztt_i32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_i32_rod_sat (void)
{
  __riscv_ztt_u32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_i32_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rnu_sat (void)
{
  __riscv_ztt_u32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rne_sat (void)
{
  __riscv_ztt_u32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rdn_sat (void)
{
  __riscv_ztt_u32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_u32_rod_sat (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mldexpacc_ew_u32_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f16_rne (void)
{
  __riscv_ztt_f16_rtz_2x1_t a = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_u4_rdn_2x1_t b = __riscv_ztt_mzero_m_u4_rdn_2x1 ();
  __riscv_ztt_f16_rne_2x1_t old = __riscv_ztt_mzero_m_f16_rne_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mldexpacc_ew_f16_rne_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f16_rtz (void)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_u8_rne_1x2_t b = __riscv_ztt_mzero_m_u8_rne_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t old = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mldexpacc_ew_f16_rtz_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f16_rdn (void)
{
  __riscv_ztt_f16_rup_2x1_t a = __riscv_ztt_mzero_m_f16_rup_2x1 ();
  __riscv_ztt_u16_rnu_2x1_t b = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t old = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_f16_rdn_2x1_t d = __riscv_ztt_mldexpacc_ew_f16_rdn_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f16_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mldexpacc_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f16_rmm (void)
{
  __riscv_ztt_f16_rno_2x1_t a = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_i4_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t old = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mldexpacc_ew_f16_rmm_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f16_rno (void)
{
  __riscv_ztt_bf16_rne_1x2_t a = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_i8_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x2 ();
  __riscv_ztt_f16_rno_1x2_t old = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_f16_rno_1x2_t d = __riscv_ztt_mldexpacc_ew_f16_rno_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_bf16_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t old = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_bf16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_bf16_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x2_t a = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t old = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t d = __riscv_ztt_mldexpacc_ew_bf16_rtz_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_bf16_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t old = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mldexpacc_ew_bf16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_bf16_rup (void)
{
  __riscv_ztt_bf16_rmm_1x2_t a = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_u4_rne_1x2_t b = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t old = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mldexpacc_ew_bf16_rup_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_bf16_rmm (void)
{
  __riscv_ztt_bf16_rno_2x1_t a = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_u8_rnu_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t old = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mldexpacc_ew_bf16_rmm_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_bf16_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i16_rod_1x1_t b = __riscv_ztt_mzero_m_i16_rod_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t old = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mldexpacc_ew_bf16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f32_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mldexpacc_ew_f32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f32_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mldexpacc_ew_f32_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f32_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mldexpacc_ew_f32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f32_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mldexpacc_ew_f32_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f32_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_u16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mldexpacc_ew_f32_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mldexpacc_f32_rno (void)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mldexpacc_ew_f32_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rnu (void)
{
  __riscv_ztt_i4_rne_1x2_t a = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t old = __riscv_ztt_mzero_m_i4_rnu_1x2 ();
  __riscv_ztt_i4_rnu_1x2_t d = __riscv_ztt_mrdexpacc_ew_i4_rnu_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rne (void)
{
  __riscv_ztt_i4_rdn_2x1_t a = __riscv_ztt_mzero_m_i4_rdn_2x1 ();
  __riscv_ztt_i16_rnu_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_2x1 ();
  __riscv_ztt_i4_rne_2x1_t old = __riscv_ztt_mzero_m_i4_rne_2x1 ();
  __riscv_ztt_i4_rne_2x1_t d = __riscv_ztt_mrdexpacc_ew_i4_rne_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rdn (void)
{
  __riscv_ztt_i4_rod_1x2_t a = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_u16_rod_1x2_t b = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t old = __riscv_ztt_mzero_m_i4_rdn_1x2 ();
  __riscv_ztt_i4_rdn_1x2_t d = __riscv_ztt_mrdexpacc_ew_i4_rdn_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rod (void)
{
  __riscv_ztt_u4_rnu_2x1_t a = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_i4_rod_2x1_t old = __riscv_ztt_mzero_m_i4_rod_2x1 ();
  __riscv_ztt_i4_rod_2x1_t d = __riscv_ztt_mrdexpacc_ew_i4_rod_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rnu (void)
{
  __riscv_ztt_u4_rne_1x4_t a = __riscv_ztt_mzero_m_u4_rne_1x4 ();
  __riscv_ztt_u4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x4 ();
  __riscv_ztt_u4_rnu_1x4_t old = __riscv_ztt_mzero_m_u4_rnu_1x4 ();
  __riscv_ztt_u4_rnu_1x4_t d = __riscv_ztt_mrdexpacc_ew_u4_rnu_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rne (void)
{
  __riscv_ztt_u4_rdn_4x1_t a = __riscv_ztt_mzero_m_u4_rdn_4x1 ();
  __riscv_ztt_u8_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_4x1 ();
  __riscv_ztt_u4_rne_4x1_t old = __riscv_ztt_mzero_m_u4_rne_4x1 ();
  __riscv_ztt_u4_rne_4x1_t d = __riscv_ztt_mrdexpacc_ew_u4_rne_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rdn (void)
{
  __riscv_ztt_u4_rod_1x2_t a = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t old = __riscv_ztt_mzero_m_u4_rdn_1x2 ();
  __riscv_ztt_u4_rdn_1x2_t d = __riscv_ztt_mrdexpacc_ew_u4_rdn_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rod (void)
{
  __riscv_ztt_i8_rnu_4x1_t a = __riscv_ztt_mzero_m_i8_rnu_4x1 ();
  __riscv_ztt_i4_rnu_4x1_t b = __riscv_ztt_mzero_m_i4_rnu_4x1 ();
  __riscv_ztt_u4_rod_4x1_t old = __riscv_ztt_mzero_m_u4_rod_4x1 ();
  __riscv_ztt_u4_rod_4x1_t d = __riscv_ztt_mrdexpacc_ew_u4_rod_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rnu (void)
{
  __riscv_ztt_i8_rne_1x4_t a = __riscv_ztt_mzero_m_i8_rne_1x4 ();
  __riscv_ztt_i4_rne_1x4_t b = __riscv_ztt_mzero_m_i4_rne_1x4 ();
  __riscv_ztt_i8_rnu_1x4_t old = __riscv_ztt_mzero_m_i8_rnu_1x4 ();
  __riscv_ztt_i8_rnu_1x4_t d = __riscv_ztt_mrdexpacc_ew_i8_rnu_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rne (void)
{
  __riscv_ztt_i8_rdn_1x1_t a = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rne_1x1_t old = __riscv_ztt_mzero_m_i8_rne_1x1 ();
  __riscv_ztt_i8_rne_1x1_t d = __riscv_ztt_mrdexpacc_ew_i8_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rdn (void)
{
  __riscv_ztt_i8_rod_1x2_t a = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t old = __riscv_ztt_mzero_m_i8_rdn_1x2 ();
  __riscv_ztt_i8_rdn_1x2_t d = __riscv_ztt_mrdexpacc_ew_i8_rdn_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rod (void)
{
  __riscv_ztt_u8_rnu_2x1_t a = __riscv_ztt_mzero_m_u8_rnu_2x1 ();
  __riscv_ztt_u16_rdn_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_2x1 ();
  __riscv_ztt_i8_rod_2x1_t old = __riscv_ztt_mzero_m_i8_rod_2x1 ();
  __riscv_ztt_i8_rod_2x1_t d = __riscv_ztt_mrdexpacc_ew_i8_rod_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rnu (void)
{
  __riscv_ztt_u8_rne_1x1_t a = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_1x1 ();
  __riscv_ztt_u8_rnu_1x1_t d = __riscv_ztt_mrdexpacc_ew_u8_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rne (void)
{
  __riscv_ztt_u8_rdn_4x1_t a = __riscv_ztt_mzero_m_u8_rdn_4x1 ();
  __riscv_ztt_u4_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_u4_rnu_sat_4x1 ();
  __riscv_ztt_u8_rne_4x1_t old = __riscv_ztt_mzero_m_u8_rne_4x1 ();
  __riscv_ztt_u8_rne_4x1_t d = __riscv_ztt_mrdexpacc_ew_u8_rne_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rdn (void)
{
  __riscv_ztt_u8_rod_1x4_t a = __riscv_ztt_mzero_m_u8_rod_1x4 ();
  __riscv_ztt_i8_rod_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x4 ();
  __riscv_ztt_u8_rdn_1x4_t old = __riscv_ztt_mzero_m_u8_rdn_1x4 ();
  __riscv_ztt_u8_rdn_1x4_t d = __riscv_ztt_mrdexpacc_ew_u8_rdn_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rod (void)
{
  __riscv_ztt_i16_rnu_1x1_t a = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_u8_rod_1x1_t old = __riscv_ztt_mzero_m_u8_rod_1x1 ();
  __riscv_ztt_u8_rod_1x1_t d = __riscv_ztt_mrdexpacc_ew_u8_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rnu (void)
{
  __riscv_ztt_i16_rne_1x1_t a = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_1x1 ();
  __riscv_ztt_i16_rnu_1x1_t d = __riscv_ztt_mrdexpacc_ew_i16_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rne (void)
{
  __riscv_ztt_i16_rdn_2x1_t a = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_i16_rne_2x1_t old = __riscv_ztt_mzero_m_i16_rne_2x1 ();
  __riscv_ztt_i16_rne_2x1_t d = __riscv_ztt_mrdexpacc_ew_i16_rne_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rdn (void)
{
  __riscv_ztt_i16_rod_1x2_t a = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_u4_rod_1x2_t b = __riscv_ztt_mzero_m_u4_rod_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t old = __riscv_ztt_mzero_m_i16_rdn_1x2 ();
  __riscv_ztt_i16_rdn_1x2_t d = __riscv_ztt_mrdexpacc_ew_i16_rdn_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rod (void)
{
  __riscv_ztt_u16_rnu_2x1_t a = __riscv_ztt_mzero_m_u16_rnu_2x1 ();
  __riscv_ztt_u8_rdn_2x1_t b = __riscv_ztt_mzero_m_u8_rdn_2x1 ();
  __riscv_ztt_i16_rod_2x1_t old = __riscv_ztt_mzero_m_i16_rod_2x1 ();
  __riscv_ztt_i16_rod_2x1_t d = __riscv_ztt_mrdexpacc_ew_i16_rod_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rnu (void)
{
  __riscv_ztt_u16_rne_1x2_t a = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rne_1x2_t b = __riscv_ztt_mzero_m_u16_rne_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t old = __riscv_ztt_mzero_m_u16_rnu_1x2 ();
  __riscv_ztt_u16_rnu_1x2_t d = __riscv_ztt_mrdexpacc_ew_u16_rnu_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rne (void)
{
  __riscv_ztt_u16_rdn_1x1_t a = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u16_rne_1x1_t old = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_u16_rne_1x1_t d = __riscv_ztt_mrdexpacc_ew_u16_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rdn (void)
{
  __riscv_ztt_u16_rod_1x2_t a = __riscv_ztt_mzero_m_u16_rod_1x2 ();
  __riscv_ztt_i4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t old = __riscv_ztt_mzero_m_u16_rdn_1x2 ();
  __riscv_ztt_u16_rdn_1x2_t d = __riscv_ztt_mrdexpacc_ew_u16_rdn_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rod (void)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_u16_rod_1x1_t old = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_u16_rod_1x1_t d = __riscv_ztt_mrdexpacc_ew_u16_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rnu (void)
{
  __riscv_ztt_i32_rne_1x1_t a = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rne (void)
{
  __riscv_ztt_i32_rdn_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t old = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i32_rne_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rdn (void)
{
  __riscv_ztt_i32_rod_1x1_t a = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rod (void)
{
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i32_rod_1x1_t old = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rnu (void)
{
  __riscv_ztt_u32_rne_1x1_t a = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u8_rne_1x1_t b = __riscv_ztt_mzero_m_u8_rne_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rnu_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rne (void)
{
  __riscv_ztt_u32_rdn_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u16_rnu_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_1x1 ();
  __riscv_ztt_u32_rne_1x1_t old = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_u32_rne_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rdn (void)
{
  __riscv_ztt_u32_rod_1x1_t a = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_i32_rod_1x1_t b = __riscv_ztt_mzero_m_i32_rod_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rod (void)
{
  __riscv_ztt_i8_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_u32_rod_1x1_t old = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_u32_rod_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rod_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rnu_sat (void)
{
  __riscv_ztt_i4_rne_sat_1x4_t a = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i8_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_i4_rnu_sat_1x4_t old = __riscv_ztt_mzero_m_i4_rnu_sat_1x4 ();
  __riscv_ztt_i4_rnu_sat_1x4_t d = __riscv_ztt_mrdexpacc_ew_i4_rnu_sat_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rne_sat (void)
{
  __riscv_ztt_i4_rdn_sat_2x1_t a = __riscv_ztt_mzero_m_i4_rdn_sat_2x1 ();
  __riscv_ztt_i16_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t old = __riscv_ztt_mzero_m_i4_rne_sat_2x1 ();
  __riscv_ztt_i4_rne_sat_2x1_t d = __riscv_ztt_mrdexpacc_ew_i4_rne_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rdn_sat (void)
{
  __riscv_ztt_i4_rod_sat_1x2_t a = __riscv_ztt_mzero_m_i4_rod_sat_1x2 ();
  __riscv_ztt_u16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_i4_rdn_sat_1x2 ();
  __riscv_ztt_i4_rdn_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_i4_rdn_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i4_rod_sat (void)
{
  __riscv_ztt_u4_rnu_sat_8x1_t a = __riscv_ztt_mzero_m_u4_rnu_sat_8x1 ();
  __riscv_ztt_i4_rnu_8x1_t b = __riscv_ztt_mzero_m_i4_rnu_8x1 ();
  __riscv_ztt_i4_rod_sat_8x1_t old = __riscv_ztt_mzero_m_i4_rod_sat_8x1 ();
  __riscv_ztt_i4_rod_sat_8x1_t d = __riscv_ztt_mrdexpacc_ew_i4_rod_sat_8x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rnu_sat (void)
{
  __riscv_ztt_u4_rne_sat_1x2_t a = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_u4_rne_1x2_t b = __riscv_ztt_mzero_m_u4_rne_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rnu_sat_1x2 ();
  __riscv_ztt_u4_rnu_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_u4_rnu_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rne_sat (void)
{
  __riscv_ztt_u4_rdn_sat_4x1_t a = __riscv_ztt_mzero_m_u4_rdn_sat_4x1 ();
  __riscv_ztt_u8_rnu_4x1_t b = __riscv_ztt_mzero_m_u8_rnu_4x1 ();
  __riscv_ztt_u4_rne_sat_4x1_t old = __riscv_ztt_mzero_m_u4_rne_sat_4x1 ();
  __riscv_ztt_u4_rne_sat_4x1_t d = __riscv_ztt_mrdexpacc_ew_u4_rne_sat_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rdn_sat (void)
{
  __riscv_ztt_u4_rod_sat_1x2_t a = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u4_rdn_sat_1x2 ();
  __riscv_ztt_u4_rdn_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_u4_rdn_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u4_rod_sat (void)
{
  __riscv_ztt_i8_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t old = __riscv_ztt_mzero_m_u4_rod_sat_2x1 ();
  __riscv_ztt_u4_rod_sat_2x1_t d = __riscv_ztt_mrdexpacc_ew_u4_rod_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rnu_sat (void)
{
  __riscv_ztt_i8_rne_sat_1x4_t a = __riscv_ztt_mzero_m_i8_rne_sat_1x4 ();
  __riscv_ztt_i4_rne_sat_1x4_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x4 ();
  __riscv_ztt_i8_rnu_sat_1x4_t old = __riscv_ztt_mzero_m_i8_rnu_sat_1x4 ();
  __riscv_ztt_i8_rnu_sat_1x4_t d = __riscv_ztt_mrdexpacc_ew_i8_rnu_sat_1x4 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rne_sat (void)
{
  __riscv_ztt_i8_rdn_sat_4x1_t a = __riscv_ztt_mzero_m_i8_rdn_sat_4x1 ();
  __riscv_ztt_i8_rnu_sat_4x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_4x1 ();
  __riscv_ztt_i8_rne_sat_4x1_t old = __riscv_ztt_mzero_m_i8_rne_sat_4x1 ();
  __riscv_ztt_i8_rne_sat_4x1_t d = __riscv_ztt_mrdexpacc_ew_i8_rne_sat_4x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rdn_sat (void)
{
  __riscv_ztt_i8_rod_sat_1x1_t a = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i8_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i8_rod_sat (void)
{
  __riscv_ztt_u8_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_u8_rnu_sat_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t old = __riscv_ztt_mzero_m_i8_rod_sat_2x1 ();
  __riscv_ztt_i8_rod_sat_2x1_t d = __riscv_ztt_mrdexpacc_ew_i8_rod_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rnu_sat (void)
{
  __riscv_ztt_u8_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u8_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rne_sat (void)
{
  __riscv_ztt_u8_rdn_sat_2x1_t a = __riscv_ztt_mzero_m_u8_rdn_sat_2x1 ();
  __riscv_ztt_u4_rnu_2x1_t b = __riscv_ztt_mzero_m_u4_rnu_2x1 ();
  __riscv_ztt_u8_rne_sat_2x1_t old = __riscv_ztt_mzero_m_u8_rne_sat_2x1 ();
  __riscv_ztt_u8_rne_sat_2x1_t d = __riscv_ztt_mrdexpacc_ew_u8_rne_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rdn_sat (void)
{
  __riscv_ztt_u8_rod_sat_1x2_t a = __riscv_ztt_mzero_m_u8_rod_sat_1x2 ();
  __riscv_ztt_i8_rod_1x2_t b = __riscv_ztt_mzero_m_i8_rod_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u8_rdn_sat_1x2 ();
  __riscv_ztt_u8_rdn_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_u8_rdn_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u8_rod_sat (void)
{
  __riscv_ztt_i16_rnu_sat_2x1_t a = __riscv_ztt_mzero_m_i16_rnu_sat_2x1 ();
  __riscv_ztt_i16_rdn_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_2x1 ();
  __riscv_ztt_u8_rod_sat_2x1_t old = __riscv_ztt_mzero_m_u8_rod_sat_2x1 ();
  __riscv_ztt_u8_rod_sat_2x1_t d = __riscv_ztt_mrdexpacc_ew_u8_rod_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rnu_sat (void)
{
  __riscv_ztt_i16_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mzero_m_i32_rne_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rnu_sat_1x1 ();
  __riscv_ztt_i16_rnu_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i16_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rne_sat (void)
{
  __riscv_ztt_i16_rdn_sat_2x1_t a = __riscv_ztt_mzero_m_i16_rdn_sat_2x1 ();
  __riscv_ztt_i4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t old = __riscv_ztt_mzero_m_i16_rne_sat_2x1 ();
  __riscv_ztt_i16_rne_sat_2x1_t d = __riscv_ztt_mrdexpacc_ew_i16_rne_sat_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rdn_sat (void)
{
  __riscv_ztt_i16_rod_sat_1x2_t a = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_u4_rod_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rod_sat_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_i16_rdn_sat_1x2 ();
  __riscv_ztt_i16_rdn_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_i16_rdn_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i16_rod_sat (void)
{
  __riscv_ztt_u16_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i16_rod_sat_1x1 ();
  __riscv_ztt_i16_rod_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i16_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rnu_sat (void)
{
  __riscv_ztt_u16_rne_sat_1x2_t a = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u16_rne_sat_1x2 ();
  __riscv_ztt_u16_rnu_sat_1x2_t old = __riscv_ztt_mzero_m_u16_rnu_sat_1x2 ();
  __riscv_ztt_u16_rnu_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_u16_rnu_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rne_sat (void)
{
  __riscv_ztt_u16_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u16_rdn_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rne_sat_1x1 ();
  __riscv_ztt_u16_rne_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u16_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rdn_sat (void)
{
  __riscv_ztt_u16_rod_sat_1x2_t a = __riscv_ztt_mzero_m_u16_rod_sat_1x2 ();
  __riscv_ztt_i4_rod_1x2_t b = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t old = __riscv_ztt_mzero_m_u16_rdn_sat_1x2 ();
  __riscv_ztt_u16_rdn_sat_1x2_t d = __riscv_ztt_mrdexpacc_ew_u16_rdn_sat_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u16_rod_sat (void)
{
  __riscv_ztt_i32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u16_rod_sat_1x1 ();
  __riscv_ztt_u16_rod_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u16_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rnu_sat (void)
{
  __riscv_ztt_i32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rnu_sat_1x1 ();
  __riscv_ztt_i32_rnu_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rne_sat (void)
{
  __riscv_ztt_i32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rdn_sat (void)
{
  __riscv_ztt_i32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_i32_rod_sat (void)
{
  __riscv_ztt_u32_rnu_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_i32_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rnu_sat (void)
{
  __riscv_ztt_u32_rne_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rnu_sat_1x1 ();
  __riscv_ztt_u32_rnu_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rnu_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rne_sat (void)
{
  __riscv_ztt_u32_rdn_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rne_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rdn_sat (void)
{
  __riscv_ztt_u32_rod_sat_1x1_t a = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_i32_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rod_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rdn_sat_1x1 ();
  __riscv_ztt_u32_rdn_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rdn_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_u32_rod_sat (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t old = __riscv_ztt_mzero_m_u32_rod_sat_1x1 ();
  __riscv_ztt_u32_rod_sat_1x1_t d = __riscv_ztt_mrdexpacc_ew_u32_rod_sat_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f16_rne (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_i8_rne_1x2_t b = __riscv_ztt_mzero_m_i8_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t old = __riscv_ztt_mzero_m_f16_rne_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_mrdexpacc_ew_f16_rne_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f16_rtz (void)
{
  __riscv_ztt_f16_rdn_2x1_t a = __riscv_ztt_mzero_m_f16_rdn_2x1 ();
  __riscv_ztt_i16_rnu_2x1_t b = __riscv_ztt_mzero_m_i16_rnu_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t old = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_f16_rtz_2x1_t d = __riscv_ztt_mrdexpacc_ew_f16_rtz_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f16_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_u16_rod_1x1_t b = __riscv_ztt_mzero_m_u16_rod_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t old = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mrdexpacc_ew_f16_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f16_rup (void)
{
  __riscv_ztt_f16_rmm_1x1_t a = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_u32_rdn_1x1_t b = __riscv_ztt_mzero_m_u32_rdn_1x1 ();
  __riscv_ztt_f16_rup_1x1_t old = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_f16_rup_1x1_t d = __riscv_ztt_mrdexpacc_ew_f16_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f16_rmm (void)
{
  __riscv_ztt_f16_rno_1x2_t a = __riscv_ztt_mzero_m_f16_rno_1x2 ();
  __riscv_ztt_u4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_u4_rne_sat_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t old = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_f16_rmm_1x2_t d = __riscv_ztt_mrdexpacc_ew_f16_rmm_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f16_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rnu_sat_1x1 ();
  __riscv_ztt_f16_rno_1x1_t old = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mrdexpacc_ew_f16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_bf16_rne (void)
{
  __riscv_ztt_bf16_rtz_1x2_t a = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_i16_rod_sat_1x2_t b = __riscv_ztt_mzero_m_i16_rod_sat_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t old = __riscv_ztt_mzero_m_bf16_rne_1x2 ();
  __riscv_ztt_bf16_rne_1x2_t d = __riscv_ztt_mrdexpacc_ew_bf16_rne_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_bf16_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_i32_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_sat_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t old = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mrdexpacc_ew_bf16_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_bf16_rdn (void)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_i4_rne_1x2_t b = __riscv_ztt_mzero_m_i4_rne_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t old = __riscv_ztt_mzero_m_bf16_rdn_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_mrdexpacc_ew_bf16_rdn_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_bf16_rup (void)
{
  __riscv_ztt_bf16_rmm_2x1_t a = __riscv_ztt_mzero_m_bf16_rmm_2x1 ();
  __riscv_ztt_i8_rnu_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t old = __riscv_ztt_mzero_m_bf16_rup_2x1 ();
  __riscv_ztt_bf16_rup_2x1_t d = __riscv_ztt_mrdexpacc_ew_bf16_rup_2x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_bf16_rmm (void)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t old = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_mrdexpacc_ew_bf16_rmm_1x2 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_bf16_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t old = __riscv_ztt_mzero_m_bf16_rno_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mrdexpacc_ew_bf16_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f32_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t old = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mrdexpacc_ew_f32_rne_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f32_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t old = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mrdexpacc_ew_f32_rtz_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f32_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t old = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mrdexpacc_ew_f32_rdn_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f32_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i16_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_1x1 ();
  __riscv_ztt_f32_rup_1x1_t old = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mrdexpacc_ew_f32_rup_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f32_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t old = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mrdexpacc_ew_f32_rmm_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mrdexpacc_f32_rno (void)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_f32_rno_1x1_t old = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mrdexpacc_ew_f32_rno_1x1 (old, a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b), "Wmr" (old));
}
void math_mlog2sub_f16_rne (void)
{
  __riscv_ztt_f16_rtz_2x1_t a = __riscv_ztt_mzero_m_f16_rtz_2x1 ();
  __riscv_ztt_u8_rnu_2x1_t b = __riscv_ztt_mzero_m_u8_rnu_2x1 ();
  __riscv_ztt_f16_rne_2x1_t d = __riscv_ztt_mlog2sub_ew_f16_rne_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f16_rtz (void)
{
  __riscv_ztt_f16_rdn_1x2_t a = __riscv_ztt_mzero_m_f16_rdn_1x2 ();
  __riscv_ztt_i16_rod_1x2_t b = __riscv_ztt_mzero_m_i16_rod_1x2 ();
  __riscv_ztt_f16_rtz_1x2_t d = __riscv_ztt_mlog2sub_ew_f16_rtz_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f16_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_i32_rdn_1x1_t b = __riscv_ztt_mzero_m_i32_rdn_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_mlog2sub_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f16_rup (void)
{
  __riscv_ztt_f16_rmm_1x2_t a = __riscv_ztt_mzero_m_f16_rmm_1x2 ();
  __riscv_ztt_i4_rne_sat_1x2_t b = __riscv_ztt_mzero_m_i4_rne_sat_1x2 ();
  __riscv_ztt_f16_rup_1x2_t d = __riscv_ztt_mlog2sub_ew_f16_rup_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f16_rmm (void)
{
  __riscv_ztt_f16_rno_2x1_t a = __riscv_ztt_mzero_m_f16_rno_2x1 ();
  __riscv_ztt_i8_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_2x1 ();
  __riscv_ztt_f16_rmm_2x1_t d = __riscv_ztt_mlog2sub_ew_f16_rmm_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f16_rno (void)
{
  __riscv_ztt_bf16_rne_1x1_t a = __riscv_ztt_mzero_m_bf16_rne_1x1 ();
  __riscv_ztt_u8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rod_sat_1x1 ();
  __riscv_ztt_f16_rno_1x1_t d = __riscv_ztt_mlog2sub_ew_f16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_bf16_rne (void)
{
  __riscv_ztt_bf16_rtz_2x1_t a = __riscv_ztt_mzero_m_bf16_rtz_2x1 ();
  __riscv_ztt_u16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_u16_rdn_sat_2x1 ();
  __riscv_ztt_bf16_rne_2x1_t d = __riscv_ztt_mlog2sub_ew_bf16_rne_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_bf16_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_u32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u32_rne_sat_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_mlog2sub_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_bf16_rdn (void)
{
  __riscv_ztt_bf16_rup_1x1_t a = __riscv_ztt_mzero_m_bf16_rup_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t b = __riscv_ztt_mzero_m_f16_rmm_1x1 ();
  __riscv_ztt_bf16_rdn_1x1_t d = __riscv_ztt_mlog2sub_ew_bf16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_bf16_rup (void)
{
  __riscv_ztt_bf16_rmm_1x2_t a = __riscv_ztt_mzero_m_bf16_rmm_1x2 ();
  __riscv_ztt_bf16_rno_1x2_t b = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_bf16_rup_1x2_t d = __riscv_ztt_mlog2sub_ew_bf16_rup_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_bf16_rmm (void)
{
  __riscv_ztt_bf16_rno_2x1_t a = __riscv_ztt_mzero_m_bf16_rno_2x1 ();
  __riscv_ztt_i4_rnu_2x1_t b = __riscv_ztt_mzero_m_i4_rnu_2x1 ();
  __riscv_ztt_bf16_rmm_2x1_t d = __riscv_ztt_mlog2sub_ew_bf16_rmm_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_bf16_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i8_rnu_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_mlog2sub_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f32_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_u8_rdn_1x1_t b = __riscv_ztt_mzero_m_u8_rdn_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_mlog2sub_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f32_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_u16_rne_1x1_t b = __riscv_ztt_mzero_m_u16_rne_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_mlog2sub_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f32_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_u32_rnu_1x1_t b = __riscv_ztt_mzero_m_u32_rnu_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_mlog2sub_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f32_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_mlog2sub_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f32_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_i8_rdn_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_sat_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_mlog2sub_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_mlog2sub_f32_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_i16_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i16_rne_sat_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_mlog2sub_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f16_rne (void)
{
  __riscv_ztt_f16_rtz_1x2_t a = __riscv_ztt_mzero_m_f16_rtz_1x2 ();
  __riscv_ztt_u8_rod_1x2_t b = __riscv_ztt_mzero_m_u8_rod_1x2 ();
  __riscv_ztt_f16_rne_1x2_t d = __riscv_ztt_msublog2_ew_f16_rne_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f16_rtz (void)
{
  __riscv_ztt_f16_rdn_1x1_t a = __riscv_ztt_mzero_m_f16_rdn_1x1 ();
  __riscv_ztt_u16_rdn_1x1_t b = __riscv_ztt_mzero_m_u16_rdn_1x1 ();
  __riscv_ztt_f16_rtz_1x1_t d = __riscv_ztt_msublog2_ew_f16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f16_rdn (void)
{
  __riscv_ztt_f16_rup_1x1_t a = __riscv_ztt_mzero_m_f16_rup_1x1 ();
  __riscv_ztt_u32_rne_1x1_t b = __riscv_ztt_mzero_m_u32_rne_1x1 ();
  __riscv_ztt_f16_rdn_1x1_t d = __riscv_ztt_msublog2_ew_f16_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f16_rup (void)
{
  __riscv_ztt_f16_rmm_2x1_t a = __riscv_ztt_mzero_m_f16_rmm_2x1 ();
  __riscv_ztt_u4_rnu_sat_2x1_t b = __riscv_ztt_mzero_m_u4_rnu_sat_2x1 ();
  __riscv_ztt_f16_rup_2x1_t d = __riscv_ztt_msublog2_ew_f16_rup_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f16_rmm (void)
{
  __riscv_ztt_f16_rno_1x1_t a = __riscv_ztt_mzero_m_f16_rno_1x1 ();
  __riscv_ztt_i8_rod_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rod_sat_1x1 ();
  __riscv_ztt_f16_rmm_1x1_t d = __riscv_ztt_msublog2_ew_f16_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f16_rno (void)
{
  __riscv_ztt_bf16_rne_2x1_t a = __riscv_ztt_mzero_m_bf16_rne_2x1 ();
  __riscv_ztt_i16_rdn_sat_2x1_t b = __riscv_ztt_mzero_m_i16_rdn_sat_2x1 ();
  __riscv_ztt_f16_rno_2x1_t d = __riscv_ztt_msublog2_ew_f16_rno_2x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_bf16_rne (void)
{
  __riscv_ztt_bf16_rtz_1x1_t a = __riscv_ztt_mzero_m_bf16_rtz_1x1 ();
  __riscv_ztt_i32_rne_sat_1x1_t b = __riscv_ztt_mzero_m_i32_rne_sat_1x1 ();
  __riscv_ztt_bf16_rne_1x1_t d = __riscv_ztt_msublog2_ew_bf16_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_bf16_rtz (void)
{
  __riscv_ztt_bf16_rdn_1x1_t a = __riscv_ztt_mzero_m_bf16_rdn_1x1 ();
  __riscv_ztt_f16_rne_1x1_t b = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_bf16_rtz_1x1_t d = __riscv_ztt_msublog2_ew_bf16_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_bf16_rdn (void)
{
  __riscv_ztt_bf16_rup_1x2_t a = __riscv_ztt_mzero_m_bf16_rup_1x2 ();
  __riscv_ztt_bf16_rtz_1x2_t b = __riscv_ztt_mzero_m_bf16_rtz_1x2 ();
  __riscv_ztt_bf16_rdn_1x2_t d = __riscv_ztt_msublog2_ew_bf16_rdn_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_bf16_rup (void)
{
  __riscv_ztt_bf16_rmm_1x1_t a = __riscv_ztt_mzero_m_bf16_rmm_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t b = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_bf16_rup_1x1_t d = __riscv_ztt_msublog2_ew_bf16_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_bf16_rmm (void)
{
  __riscv_ztt_bf16_rno_1x2_t a = __riscv_ztt_mzero_m_bf16_rno_1x2 ();
  __riscv_ztt_i4_rod_1x2_t b = __riscv_ztt_mzero_m_i4_rod_1x2 ();
  __riscv_ztt_bf16_rmm_1x2_t d = __riscv_ztt_msublog2_ew_bf16_rmm_1x2 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_bf16_rno (void)
{
  __riscv_ztt_f32_rne_1x1_t a = __riscv_ztt_mzero_m_f32_rne_1x1 ();
  __riscv_ztt_i8_rdn_1x1_t b = __riscv_ztt_mzero_m_i8_rdn_1x1 ();
  __riscv_ztt_bf16_rno_1x1_t d = __riscv_ztt_msublog2_ew_bf16_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f32_rne (void)
{
  __riscv_ztt_f32_rtz_1x1_t a = __riscv_ztt_mzero_m_f32_rtz_1x1 ();
  __riscv_ztt_i16_rne_1x1_t b = __riscv_ztt_mzero_m_i16_rne_1x1 ();
  __riscv_ztt_f32_rne_1x1_t d = __riscv_ztt_msublog2_ew_f32_rne_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f32_rtz (void)
{
  __riscv_ztt_f32_rdn_1x1_t a = __riscv_ztt_mzero_m_f32_rdn_1x1 ();
  __riscv_ztt_i32_rnu_1x1_t b = __riscv_ztt_mzero_m_i32_rnu_1x1 ();
  __riscv_ztt_f32_rtz_1x1_t d = __riscv_ztt_msublog2_ew_f32_rtz_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f32_rdn (void)
{
  __riscv_ztt_f32_rup_1x1_t a = __riscv_ztt_mzero_m_f32_rup_1x1 ();
  __riscv_ztt_u32_rod_1x1_t b = __riscv_ztt_mzero_m_u32_rod_1x1 ();
  __riscv_ztt_f32_rdn_1x1_t d = __riscv_ztt_msublog2_ew_f32_rdn_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f32_rup (void)
{
  __riscv_ztt_f32_rmm_1x1_t a = __riscv_ztt_mzero_m_f32_rmm_1x1 ();
  __riscv_ztt_i8_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_i8_rnu_sat_1x1 ();
  __riscv_ztt_f32_rup_1x1_t d = __riscv_ztt_msublog2_ew_f32_rup_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f32_rmm (void)
{
  __riscv_ztt_f32_rno_1x1_t a = __riscv_ztt_mzero_m_f32_rno_1x1 ();
  __riscv_ztt_u8_rne_sat_1x1_t b = __riscv_ztt_mzero_m_u8_rne_sat_1x1 ();
  __riscv_ztt_f32_rmm_1x1_t d = __riscv_ztt_msublog2_ew_f32_rmm_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
void math_msublog2_f32_rno (void)
{
  __riscv_ztt_f16_rne_1x1_t a = __riscv_ztt_mzero_m_f16_rne_1x1 ();
  __riscv_ztt_u16_rnu_sat_1x1_t b = __riscv_ztt_mzero_m_u16_rnu_sat_1x1 ();
  __riscv_ztt_f32_rno_1x1_t d = __riscv_ztt_msublog2_ew_f32_rno_1x1 (a, b);
  __asm__ volatile ("" : : "Wmr" (d), "Wmr" (a), "Wmr" (b));
}
