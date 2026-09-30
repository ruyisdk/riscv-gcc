/* No implicit ACC conversion.  */
/* { dg-do compile } */
/* { dg-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void invalid (int8_t *p)
{
  __riscv_ztt_i8_rnu_1x1_t m = __riscv_ztt_mls_rm_i8_rnu_1x1 (p);
  __riscv_ztt_i8_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i8_rnu_accx1 (m);
  __riscv_ztt_i16_rnu_accx1_t b = __riscv_ztt_mclear_acc_i16_rnu_accx1 ();
  __riscv_ztt_u8_rnu_accx1_t u = __riscv_ztt_mclear_acc_u8_rnu_accx1 ();
  __riscv_ztt_i8_rne_accx1_t r = __riscv_ztt_mclear_acc_i8_rne_accx1 ();
  __riscv_ztt_mcopy_a2m_i8_rnu_1x1 (b); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_a2m_i8_rnu_1x1 (u); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mcopy_a2m_i8_rnu_1x1 (r); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i8_rnu_accx1 (b, m, m); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_mmulacc_2d_i16_rnu_accx1 (b, m, m); /* Mixed sources are now valid. */
  __riscv_ztt_mcopy_m2a_i8_rnu_accx1 (a); /* { dg-error "incompatible|cannot convert" } */
  __riscv_ztt_i8_rnu_accx1_t array[2]; /* { dg-error "sizeless|array" } */
  (void) sizeof (a); /* { dg-error "fixed C object size" } */
}
