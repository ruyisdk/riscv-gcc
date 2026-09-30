/* ternary arithmetic.  */
/* { dg-do compile } */
/* { dg-options "-O2 -fno-ipa-icf -fno-pic -march=rv32im_zicsr_ztt0p6 -mabi=ilp32 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv32 } } */
/* { dg-options "-O2 -fno-ipa-icf -fno-pic -march=rv64im_zicsr_ztt0p6 -mabi=lp64 -mztt-profile=gcc-runtime-u8-m16-a4" { target rv64 } } */
#include <stdint.h>
#include <riscv_ztt.h>
void unused (const int8_t *d, const int8_t *a, const int8_t *b,
             volatile unsigned *dc, volatile unsigned *ac, volatile unsigned *bc)
{
  (void) __riscv_ztt_mmulacc_ew_i8_1x1
    (((void) (*dc = *dc + 1), __riscv_ztt_mls_rm_i8_1x1 (d)),
     ((void) (*ac = *ac + 1), __riscv_ztt_mls_rm_i8_1x1 (a)),
     ((void) (*bc = *bc + 1), __riscv_ztt_mls_rm_i8_1x1 (b)));
}
/* { dg-final { scan-assembler-not {\tmmulacc\.ew\t} } } */
/* Count the counter stores, not RV32 frame saves at nonzero offsets.  */
/* { dg-final { scan-assembler-times {\tsw\t[^\n]*,0\(} 3 } } */
