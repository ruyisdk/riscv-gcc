/* { dg-do compile } */
/* { dg-options "-O2 -march=rv64gcp -mabi=lp64d -mlittle-endian" } */

#include "mulhi-acc-loop.h"

/* Keep the existing RV64 selection independent of the RV32 cost hook.  */
/* { dg-final { scan-assembler-times {\tpmhracc\.w\t} 2 } } */
/* { dg-final { scan-assembler-times {\tpmhraccu\.w\t} 1 } } */
/* { dg-final { scan-assembler-times {\tpmhraccsu\.w\t} 2 } } */
