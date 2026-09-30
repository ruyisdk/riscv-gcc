/* Matrix mathematics; compile contracts are not numerical execution.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u16-m32-a16" { target rv64 } } */
#include <riscv_ztt.h>
static __attribute__((always_inline)) inline long
next_exponent (volatile long *p)
{
  long value = *p;
  *p = value + 1;
  return value;
}
void control_0 (long e, volatile long *p)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_mldexp_ew_x_i16_1x1 (a, 0);
  __asm__ volatile ("" : : "Wmr" (d));
}
void control_1 (long e, volatile long *p)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_mldexp_ew_x_i16_1x1 (a, -1);
  __asm__ volatile ("" : : "Wmr" (d));
}
void control_2 (long e, volatile long *p)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_mldexp_ew_x_i16_1x1 (a, __LONG_MAX__);
  __asm__ volatile ("" : : "Wmr" (d));
}
void control_3 (long e, volatile long *p)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_mldexp_ew_x_i16_1x1 (a, (-__LONG_MAX__ - 1));
  __asm__ volatile ("" : : "Wmr" (d));
}
void control_4 (long e, volatile long *p)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_mldexp_ew_x_i16_1x1 (a, e);
  __asm__ volatile ("" : : "Wmr" (d));
}
void control_5 (long e, volatile long *p)
{
  __riscv_ztt_i16_1x1_t a = __riscv_ztt_mzero_m_i16_1x1 ();
  __riscv_ztt_i16_1x1_t d = __riscv_ztt_mldexp_ew_x_i16_1x1 (a, next_exponent (p));
  __asm__ volatile ("" : : "Wmr" (d));
}
/* { dg-final { scan-assembler-not {amestype} } } */
