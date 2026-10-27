/* { dg-do compile } */
/* { dg-options "-O2 -march=rv64gcp -mabi=lp64d -mlittle-endian" } */

/*
** exact:
**  pmulq.h\ta0,a0,a1
**  ret
*/
/*
** rounding:
**  pmulqr.h\ta0,a0,a1
**  ret
*/

#include "q15-pair.h"

/* Only exact and widened Q15 results use the saturating operations.  */
/* { dg-final { scan-assembler-times {\tpmulq\.h\t} 2 } } */
/* { dg-final { scan-assembler-times {\tpmulqr\.h\t} 2 } } */
/* { dg-final { check-function-bodies "**" "" } } */
