/* { dg-do compile } */
/* { dg-options "-O2 -g -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -g -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

#if !defined (__riscv_ztt_runtime_n) || __riscv_ztt_profile != 2
#error missing runtime profile
#endif
#if defined (__riscv_ztt_n) || defined (__riscv_ztt_nelem)
#error N must not be a compile-time constant
#endif
#if __riscv_ztt_uds != 8 || __riscv_ztt_mregs != 16 || __riscv_ztt_accregs != 4
#error incorrect compile-time resource profile
#endif

void
runtime_add (const signed char *input, const signed char *other,
             signed char *output)
{
  __riscv_ztt_i8_rne_1x1_t a = __riscv_ztt_mls_rm_i8_rne_1x1 (input);
  __riscv_ztt_i8_rne_1x1_t b = __riscv_ztt_mls_rm_i8_rne_1x1 (other);
  __riscv_ztt_mss_rm (output, __riscv_ztt_madd_ew_i8_rne_1x1 (a, b));
}

/* { dg-final { scan-assembler "madd\\.ew" } } */
/* { dg-final { scan-assembler-times "csrr\ts11,amenlen" 1 } } */
/* This function has no AME spill slot: the unused N*N/16 cache may be
   eliminated, but validation of N must remain.  The ztt-multin pressure
   tests check the cache computation when it is actually consumed.  */
/* { dg-final { scan-assembler {addi\s+[a-z][0-9]+,s11,-4} } } */
/* { dg-final { scan-assembler-not {sltiu\s} } } */
/* { dg-final { scan-assembler "ebreak" } } */
/* { dg-final { scan-assembler-not "vlenb" } } */
/* { dg-final { scan-assembler-not "16384" } } */
/* { dg-final { scan-assembler "\\.cfi_offset 27," } } */
/* { dg-final { scan-assembler "\\.cfi_restore 27" } } */
