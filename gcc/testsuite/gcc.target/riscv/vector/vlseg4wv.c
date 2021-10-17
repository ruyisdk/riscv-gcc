
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x4xm1_t test_vlseg4wv_int32x4xm1 (const int *address, unsigned int gvl) {
    return vlseg4wv_int32x4xm1 (address, gvl);
}


int32x4xm2_t test_vlseg4wv_int32x4xm2 (const int *address, unsigned int gvl) {
    return vlseg4wv_int32x4xm2 (address, gvl);
}


int64x4xm1_t test_vlseg4wv_int64x4xm1 (const long *address, unsigned int gvl) {
    return vlseg4wv_int64x4xm1 (address, gvl);
}


int64x4xm2_t test_vlseg4wv_int64x4xm2 (const long *address, unsigned int gvl) {
    return vlseg4wv_int64x4xm2 (address, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg4w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

