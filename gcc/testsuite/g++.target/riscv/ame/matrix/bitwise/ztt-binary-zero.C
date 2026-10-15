/* { dg-do compile } */
/* { dg-options "-O2 -g -fno-ipa-icf -ffat-lto-objects -fdump-tree-optimized -mztt-profile=gcc-runtime-u8-m32-a16" } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target { rv32 } } } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target { rv64 } } } */
#include "../../../../../gcc.target/riscv/ame/matrix/bitwise/ztt-binary-zero.h"

void mixed_zero (const __INT32_TYPE__ *in, __INT32_TYPE__ *out)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i8_rnu_1x1_t z = __riscv_ztt_mzero_m_i8_rnu_1x1 ();
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_rnu_1x1 (a, z));
}
/* { dg-final { scan-assembler-times {madd\.ew\t} 8 } } */
/* { dg-final { scan-assembler-times {msub\.ew\t} 1 } } */
/* { dg-final { scan-assembler-not {m(or|xor)\.ew\t} } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mzero_m_i32_rnu_1x1 \(\)} 16 "optimized" } } */
/* { dg-final { scan-tree-dump-times {__riscv_ztt_mcopy_m2m_i32_rnu_1x1 \(} 9 "optimized" } } */
