/* Complete large packed ACC groups.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a16" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (int8_t *p)
{
  __riscv_ztt_i8_rnu_1x8_t m = __riscv_ztt_mls_rm_i8_rnu_1x8 (p);
  __riscv_ztt_i8_rnu_8x1_t c = __riscv_ztt_mls_rm_i8_rnu_8x1 (p);
  __riscv_ztt_i8_rnu_accx8_t a = __riscv_ztt_mcopy_m2a_i8_rnu_accx8 (m);
  __riscv_ztt_i8_rnu_accx16_t b = __riscv_ztt_mclear_acc_i8_rnu_accx16 ();
  __riscv_ztt_i8_rne_accx8_t r = __riscv_ztt_mclear_acc_i8_rne_accx8 ();
  __riscv_ztt_u8_rnu_accx8_t u = __riscv_ztt_mclear_acc_u8_rnu_accx8 ();
  __riscv_ztt_i16_rnu_accx8_t w = __riscv_ztt_mclear_acc_i16_rnu_accx8 ();
  __riscv_ztt_mcopy_a2m_i8_rnu_1x8 (b); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_a2m_i8_rnu_1x8 (r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_a2m_i8_rnu_1x8 (u); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_a2m_i8_rnu_1x8 (w); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_m2a_i8_rne_accx8 (c); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_m2a_u8_rnu_accx8 (c); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_m2a_i8_rnu_accx16 (m); /* { dg-error "incompatible|cannot convert" } */
  m = c; /* { dg-error "incompatible|no match" } */
  __riscv_ztt_i8_rnu_accx8_t array[2]; /* { dg-error "sizeless|array" } */
  (void) sizeof (a); /* { dg-error "fixed C object size" } */
  a = __riscv_ztt_mmulacc_2d_i8_rnu_accx8 (a, m, c);
  b = __riscv_ztt_mmulacc_2d_i8_rnu_accx16 (b, m, c);
}
