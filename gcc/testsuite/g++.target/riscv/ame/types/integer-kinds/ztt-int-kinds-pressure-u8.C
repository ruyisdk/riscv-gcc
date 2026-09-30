/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a16" { target rv64 } } */
#include <riscv_ztt.h>
void pressure_8 (void)
{
  __riscv_ztt_i4_rne_sat_1x8_t m0 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m0));
  __riscv_ztt_i4_rne_sat_1x8_t m1 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m1));
  __riscv_ztt_i4_rne_sat_1x8_t m2 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m2));
  __riscv_ztt_i4_rne_sat_1x8_t m3 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m3));
  __riscv_ztt_i4_rne_sat_1x8_t m4 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m4));
  __riscv_ztt_i4_rne_sat_1x8_t m5 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m5));
  __riscv_ztt_i4_rne_sat_1x8_t m6 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m6));
  __riscv_ztt_i4_rne_sat_1x8_t m7 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m7));
  __riscv_ztt_i4_rne_sat_1x8_t m8 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m8));
  __riscv_ztt_i4_rne_sat_1x8_t m9 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m9));
  __riscv_ztt_i4_rne_sat_1x8_t m10 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m10));
  __riscv_ztt_i4_rne_sat_1x8_t m11 = __riscv_ztt_mzero_m_i4_rne_sat_1x8 ();
  __asm__ volatile ("" : "+Wmr" (m11));
  __riscv_ztt_i4_rne_sat_accx8_t a0 = __riscv_ztt_mzero_acc_i4_rne_sat_accx8 ();
  __asm__ volatile ("" : "+War" (a0));
  __riscv_ztt_i4_rne_sat_accx8_t a1 = __riscv_ztt_mzero_acc_i4_rne_sat_accx8 ();
  __asm__ volatile ("" : "+War" (a1));
  __riscv_ztt_i4_rne_sat_accx8_t a2 = __riscv_ztt_mzero_acc_i4_rne_sat_accx8 ();
  __asm__ volatile ("" : "+War" (a2));
  __riscv_ztt_i4_rne_sat_accx8_t a3 = __riscv_ztt_mzero_acc_i4_rne_sat_accx8 ();
  __asm__ volatile ("" : "+War" (a3));
  __asm__ volatile ("" : : "Wmr" (m0));
  __asm__ volatile ("" : : "Wmr" (m1));
  __asm__ volatile ("" : : "Wmr" (m2));
  __asm__ volatile ("" : : "Wmr" (m3));
  __asm__ volatile ("" : : "Wmr" (m4));
  __asm__ volatile ("" : : "Wmr" (m5));
  __asm__ volatile ("" : : "Wmr" (m6));
  __asm__ volatile ("" : : "Wmr" (m7));
  __asm__ volatile ("" : : "Wmr" (m8));
  __asm__ volatile ("" : : "Wmr" (m9));
  __asm__ volatile ("" : : "Wmr" (m10));
  __asm__ volatile ("" : : "Wmr" (m11));
  __asm__ volatile ("" : : "War" (a0));
  __asm__ volatile ("" : : "War" (a1));
  __asm__ volatile ("" : : "War" (a2));
  __asm__ volatile ("" : : "War" (a3));
}
/* { dg-final { scan-assembler "mss\\.1r" } } */
/* { dg-final { scan-assembler "mls\\.1r" } } */
/* { dg-final { scan-assembler "agettyp" } } */
/* { dg-final { scan-assembler "asettyp" } } */
