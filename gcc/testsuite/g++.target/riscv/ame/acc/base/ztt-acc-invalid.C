/* UDS32, i32/RNU only.  */
/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u32-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
__riscv_ztt_i32_rnu_accx8_t *tuple; /* { dg-error "unknown type name|does not name a type" } */
__riscv_ztt_i16_rnu_accx1_t *width; /* { dg-error "unknown type name|does not name a type" } */
void bad (int32_t *p)
{
  __riscv_ztt_i32_accx1_t a = __riscv_ztt_mzero_acc_i32_accx1 ();
  __riscv_ztt_mss_rm (p, a); /* { dg-error "accumulator values require an M copy" } */
  (void) sizeof (a); /* { dg-error "does not have a fixed C object size" } */
}
