/* distinct in/out M objects.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-p0-n128-u8-m16-a4" { target rv64 } } */
#include <riscv_ztt.h>
#if defined (__riscv_ztt_mcolzip_ew_int) \
    || defined (__riscv_ztt_mrowzip_ew_int) \
    || defined (__riscv_ztt_mcolunzip_ew_int) \
    || defined (__riscv_ztt_mrowunzip_ew_int)
#error retired pointer zip API advertised
#endif
#ifdef __riscv_ztt_zip_value
#error runtime value interface must not be advertised for P0
#endif
void retired (void)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mzero_m_i32_1x1 ();
  __riscv_ztt_mcolzip_ew_i32_1x1 (&a, &a); /* { dg-error "was replaced in AME/Ztt intrinsic v0.2.5; use the 1x2 value interface" } */
}
