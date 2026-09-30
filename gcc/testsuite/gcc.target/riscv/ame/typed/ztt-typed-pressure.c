/* { dg-do compile { target rv64 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" } */

#include <riscv_ztt.h>

void
ztt_typed_pressure (const signed char *const input[17], signed char *output)
{
  __riscv_ztt_i8_rne_1x1_t v0
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[0]);
  __riscv_ztt_i8_rne_1x1_t v1
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[1]);
  __riscv_ztt_i8_rne_1x1_t v2
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[2]);
  __riscv_ztt_i8_rne_1x1_t v3
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[3]);
  __riscv_ztt_i8_rne_1x1_t v4
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[4]);
  __riscv_ztt_i8_rne_1x1_t v5
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[5]);
  __riscv_ztt_i8_rne_1x1_t v6
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[6]);
  __riscv_ztt_i8_rne_1x1_t v7
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[7]);
  __riscv_ztt_i8_rne_1x1_t v8
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[8]);
  __riscv_ztt_i8_rne_1x1_t v9
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[9]);
  __riscv_ztt_i8_rne_1x1_t v10
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[10]);
  __riscv_ztt_i8_rne_1x1_t v11
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[11]);
  __riscv_ztt_i8_rne_1x1_t v12
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[12]);
  __riscv_ztt_i8_rne_1x1_t v13
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[13]);
  __riscv_ztt_i8_rne_1x1_t v14
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[14]);
  __riscv_ztt_i8_rne_1x1_t v15
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[15]);
  __riscv_ztt_i8_rne_1x1_t v16
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input[16]);

  __asm__ volatile ("" ::: "memory");

  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v1);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v2);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v3);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v4);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v5);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v6);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v7);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v8);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v9);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v10);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v11);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v12);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v13);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v14);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v15);
  v0 = __riscv_ztt_madd_ew_i8_rne_1x1 (v0, v16);
  __riscv_ztt_mss_rm (output, v0);
}

/* Only the profile's m0-m15 are allocatable.  The seventeenth live value
   must use the compiler-only .1r spill path.  */
/* { dg-final { scan-assembler-times "msettyp\tm\[0-9\]+," 16 } } */
/* { dg-final { scan-assembler-times "mss\\.1r\tm\[0-9\]+," 2 } } */
/* { dg-final { scan-assembler-times "mls\\.1r\tm\[0-9\]+," 2 } } */
/* { dg-final { scan-assembler-times "madd\\.ew\tm\[0-9\]+,m\[0-9\]+,m\[0-9\]+" 16 } } */
