
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x6xm1_t test_vlseg6wuv_uint32x6xm1 (const unsigned int *address, unsigned int gvl) {
    return vlseg6wuv_uint32x6xm1 (address, gvl);
}


uint64x6xm1_t test_vlseg6wuv_uint64x6xm1 (const unsigned long *address, unsigned int gvl) {
    return vlseg6wuv_uint64x6xm1 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg6wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg6wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

