/* local v0.2.3 contract.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt0p6 -mabi=ilp32d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt0p6 -mabi=lp64d -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>

typedef signed char element_t;
static const element_t input[16384] = { 0 };
static element_t output[16384];

unsigned long
memory_carriers (const element_t *input_ptr, element_t *output_ptr,
		 void *explicit_base)
{
  __riscv_ztt_i8_rne_1x1_t value
    = __riscv_ztt_mls_rm_i8_rne_1x1 (input);
  __riscv_ztt_mss_rm (output, value);
  value = __riscv_ztt_mls_rm_i8_rne_1x1 (input_ptr);
  __riscv_ztt_mss_rm (output_ptr, value);
  value = __riscv_ztt_mls_rm_i8_rne_1x1 ((const element_t *) explicit_base);
  __riscv_ztt_mss_rm ((element_t *) explicit_base, value);
  return __builtin_riscv_ztt_read_amenlen ();
}

/* Read-only queries do not cause an L0/typed state-mixing diagnostic.  */
/* { dg-final { scan-assembler-times "mls\\.rm" 3 } } */
/* { dg-final { scan-assembler-times "mss\\.rm" 3 } } */
/* { dg-final { scan-assembler "csrr\t\[a-z0-9\]+,amenlen" } } */
