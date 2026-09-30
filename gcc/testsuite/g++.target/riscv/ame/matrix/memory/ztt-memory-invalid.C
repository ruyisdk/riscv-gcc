/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu++11 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
void invalid (signed char *out, const signed char *ro, unsigned char *wrong,
              volatile signed char *io, void *raw)
{
  __riscv_ztt_i8_rnu_1x1_t v = __riscv_ztt_mls_cm_i8_1x1 (ro);
  __riscv_ztt_mls_cm_i8_1x1 (wrong); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_st_i8_1x1 (raw, 0); /* { dg-error "requires a pointer to" } */
  __riscv_ztt_mls_tst_i8_1x1 (io, 3); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mss_cm (ro, v); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_st (wrong, 0, v); /* { dg-error "requires a pointer to writable" } */
  __riscv_ztt_mss_tst (io, 3, v); /* { dg-error "cannot access volatile or atomic memory" } */
  __riscv_ztt_mls_st_i8_1x1 (ro, 1.5); /* { dg-error "memory stride must be an integer scalar" } */
  __riscv_ztt_mls_tst_i8_1x1 (ro, out); /* { dg-error "memory stride must be an integer scalar" } */
  __riscv_ztt_mss_st (out, 1.5, v); /* { dg-error "memory stride must be an integer scalar" } */
  __riscv_ztt_mss_tst (out, ro, v); /* { dg-error "memory stride must be an integer scalar" } */
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mclear_acc_i32_accx1 ();
  __riscv_ztt_mss_cm (out, a); /* { dg-error "accumulator values require an M copy" } */
  __riscv_ztt_mss_st (out, 0, a); /* { dg-error "accumulator values require an M copy" } */
  __riscv_ztt_mss_tst (out, 0, a); /* { dg-error "accumulator values require an M copy" } */
}
