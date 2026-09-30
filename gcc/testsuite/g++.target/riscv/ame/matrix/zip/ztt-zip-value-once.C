/* { dg-do assemble } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m32-a16" { target rv64 } } */
#include <stddef.h>
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_zip_value != 1
#error missing v0.2.5 value interface
#endif
static __inline__ __attribute__((always_inline)) void
helper (int32_t *out, int32_t *old, const int32_t *in, int *events)
{
  __riscv_ztt_i32_1x2_t a = __riscv_ztt_mls_rm_i32_1x2 (in);
  __riscv_ztt_i32_1x2_t b = __riscv_ztt_mcolzip_ew_i32_1x2 ((++*events, a));
  __riscv_ztt_mss_rm (out, __riscv_ztt_mextract_i32_1x1 (b, 1));
  __riscv_ztt_mss_rm (old, a);
}
void once (int32_t *out, int32_t *old, const int32_t *in, int *events)
{
  helper (out, old, in, events);
}
