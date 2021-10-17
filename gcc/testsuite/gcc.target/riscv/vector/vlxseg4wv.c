
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x4xm1_t test_vlxseg4wv_int32x4xm1 (const int *address, int32xm1_t index, unsigned int gvl) {
    return vlxseg4wv_int32x4xm1 (address, index, gvl);
}


int32x4xm2_t test_vlxseg4wv_int32x4xm2 (const int *address, int32xm2_t index, unsigned int gvl) {
    return vlxseg4wv_int32x4xm2 (address, index, gvl);
}


int64x4xm1_t test_vlxseg4wv_int64x4xm1 (const long *address, int64xm1_t index, unsigned int gvl) {
    return vlxseg4wv_int64x4xm1 (address, index, gvl);
}


int64x4xm2_t test_vlxseg4wv_int64x4xm2 (const long *address, int64xm2_t index, unsigned int gvl) {
    return vlxseg4wv_int64x4xm2 (address, index, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg4w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

