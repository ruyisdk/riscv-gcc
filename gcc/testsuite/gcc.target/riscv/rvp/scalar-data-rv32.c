/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O2" } */

#include <riscv_packed_simd.h>
#include "scalar-data.h"

/* { dg-final { scan-assembler-times {\mabs\M} 1 } } */
/* { dg-final { scan-assembler-times {\mmseq\M} 2 } } */
/* { dg-final { scan-assembler-times {\mmslt\M} 1 } } */
/* { dg-final { scan-assembler-times {\mmsgt\M} 1 } } */
/* { dg-final { scan-assembler-times {\mmsltu\M} 1 } } */
/* { dg-final { scan-assembler-times {\mmsgtu\M} 1 } } */
/* { dg-final { scan-assembler-times {\m(merge|mvmn?)\M} 6 } } */
