
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x2xm1_t test_vlseg2wuv_uint32x2xm1 (const unsigned int *address, unsigned int gvl) {
    return vlseg2wuv_uint32x2xm1 (address, gvl);
}


uint32x2xm2_t test_vlseg2wuv_uint32x2xm2 (const unsigned int *address, unsigned int gvl) {
    return vlseg2wuv_uint32x2xm2 (address, gvl);
}


uint32x2xm4_t test_vlseg2wuv_uint32x2xm4 (const unsigned int *address, unsigned int gvl) {
    return vlseg2wuv_uint32x2xm4 (address, gvl);
}


uint64x2xm1_t test_vlseg2wuv_uint64x2xm1 (const unsigned long *address, unsigned int gvl) {
    return vlseg2wuv_uint64x2xm1 (address, gvl);
}


uint64x2xm2_t test_vlseg2wuv_uint64x2xm2 (const unsigned long *address, unsigned int gvl) {
    return vlseg2wuv_uint64x2xm2 (address, gvl);
}


uint64x2xm4_t test_vlseg2wuv_uint64x2xm4 (const unsigned long *address, unsigned int gvl) {
    return vlseg2wuv_uint64x2xm4 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlseg2wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

