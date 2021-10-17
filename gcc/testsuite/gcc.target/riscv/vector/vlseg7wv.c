
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x7xm1_t test_vlseg7wv_int32x7xm1 (const int *address, unsigned int gvl) {
    return vlseg7wv_int32x7xm1 (address, gvl);
}


int64x7xm1_t test_vlseg7wv_int64x7xm1 (const long *address, unsigned int gvl) {
    return vlseg7wv_int64x7xm1 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg7w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg7w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

