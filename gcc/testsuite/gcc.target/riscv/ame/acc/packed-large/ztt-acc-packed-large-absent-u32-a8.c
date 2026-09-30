/* Complete large packed ACC groups.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a8" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a8" { target rv64 } } */
#include <riscv_ztt.h>
#ifdef __riscv_ztt_i8_u8_accx16_packed_irm
#error unsupported packed capability
#endif
void invalid (void)
{
  __riscv_ztt_i8_rnu_accx16_t a; /* { dg-error "unknown type name|was not declared" } */
}
