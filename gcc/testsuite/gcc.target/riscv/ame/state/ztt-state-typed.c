/* { dg-do compile } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -std=gnu11 -Werror=implicit-function-declaration -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */

#include <riscv_ztt.h>
#include <stddef.h>
size_t read_with_typed (signed char *out, const signed char *in)
{
  __riscv_ztt_i8_rnu_1x1_t value = __riscv_ztt_mls_rm_i8_rnu_1x1 (in);
  size_t observed = __riscv_ztt_get_amefflags ();
  __riscv_ztt_mss_rm (out, value);
  return observed + __riscv_ztt_get_amexsat ();
}
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amefflags} 1 } } */
/* { dg-final { scan-assembler-times {csrr\t[^,]+,amexsat} 1 } } */
/* { dg-final { scan-assembler {mls\.rm(.|\n)*amefflags(.|\n)*mss\.rm(.|\n)*amexsat} } } */
