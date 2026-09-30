/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
void atomic_memory (_Atomic signed char *p, const signed char *in)
{
  __riscv_ztt_i8_rnu_1x1_t a = __riscv_ztt_mls_cm_i8_1x1 (in);
  __riscv_ztt_mls_cm_i8_1x1 (p); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mls_st_i8_1x1 (p, 1); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mls_tst_i8_1x1 (p, 1); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_cm (p, a); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_st (p, 1, a); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_tst (p, 1, a); /* { dg-error "cannot access volatile or atomic memory" } */
}
