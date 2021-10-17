
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

unsigned int test_vsetvli_max (const int sew, const int lmul) {
    return vsetvli_max (RVV_E32, RVV_M2);
}

/* { dg-final { scan-assembler "vsetvli\t" } }*/

/* { dg-final { cleanup-saved-temps } } */

