/* { dg-do compile } */
/* { dg-options "-O2 -mztt-profile=gcc-runtime-u32-m32-a16" } */
/* { dg-additional-options "-march=rv64im_zicsr_ztt0p6 -mabi=lp64" { target rv64 } } */
/* { dg-additional-options "-march=rv32im_zicsr_ztt0p6 -mabi=ilp32" { target rv32 } } */

#include "ztt-scalar-width.h"

/* { dg-final { scan-assembler-times {madd\.ew\.x} 10 } } */
/* { dg-final { scan-assembler-times {mmulacc\.ew\.x} 1 } } */
/* { dg-final { scan-assembler-times {csrw\tamestype} 11 } } */
/* { dg-final { scan-assembler-not {\tandi\t[^\n]*,255} } } */
/* { dg-final { scan-assembler-not {\ts[rl]li\t[^\n]*,(16|48)} } } */
