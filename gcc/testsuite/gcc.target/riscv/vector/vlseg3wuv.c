
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x3xm1_t test_vlseg3wuv_uint32x3xm1 (const unsigned int *address, unsigned int gvl) {
    return vlseg3wuv_uint32x3xm1 (address, gvl);
}


uint32x3xm2_t test_vlseg3wuv_uint32x3xm2 (const unsigned int *address, unsigned int gvl) {
    return vlseg3wuv_uint32x3xm2 (address, gvl);
}


uint64x3xm1_t test_vlseg3wuv_uint64x3xm1 (const unsigned long *address, unsigned int gvl) {
    return vlseg3wuv_uint64x3xm1 (address, gvl);
}


uint64x3xm2_t test_vlseg3wuv_uint64x3xm2 (const unsigned long *address, unsigned int gvl) {
    return vlseg3wuv_uint64x3xm2 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg3wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg3wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg3wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg3wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

