/* Default integer RNU aliases.  */
/* { dg-do assemble } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
#define ONE(T, C) \
void alias_##T (C *out, const C *in) \
{ \
  __riscv_ztt_##T##_1x1_t m = __riscv_ztt_mls_rm_##T##_1x1 (in); \
  __riscv_ztt_##T##_accx1_t a = __riscv_ztt_mcopy_m2a_##T##_accx1 (m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (a)); \
  a = __riscv_ztt_mclear_acc_##T##_accx1 (); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (a)); \
  a = __riscv_ztt_mzero_acc_##T##_accx1 (); \
  a = __riscv_ztt_mmulacc_2d_##T##_accx1 (a, m, m); \
  a = __riscv_ztt_mmulaccneg_2d_##T##_accx1 (a, m, m); \
  a = __riscv_ztt_mmulatacc_2d_##T##_accx1 (a, m, m); \
  a = __riscv_ztt_mmulataccneg_2d_##T##_accx1 (a, m, m); \
  a = __riscv_ztt_mmulbtacc_2d_##T##_accx1 (a, m, m); \
  a = __riscv_ztt_mmulbtaccneg_2d_##T##_accx1 (a, m, m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_##T##_1x1 (a)); \
}
ONE (i8, int8_t)
ONE (u8, uint8_t)
ONE (i16, int16_t)
ONE (u16, uint16_t)
