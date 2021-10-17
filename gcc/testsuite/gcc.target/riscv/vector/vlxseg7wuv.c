
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x7xm1_t test_vlxseg7wuv_uint32x7xm1 (const unsigned int *address, uint32xm1_t index, unsigned int gvl) {
    return vlxseg7wuv_uint32x7xm1 (address, index, gvl);
}


uint64x7xm1_t test_vlxseg7wuv_uint64x7xm1 (const unsigned long *address, uint64xm1_t index, unsigned int gvl) {
    return vlxseg7wuv_uint64x7xm1 (address, index, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg7wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg7wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

