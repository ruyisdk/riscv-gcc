
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x3xm1_t test_vlseg3wv_mask_int32x3xm1 (int32x3xm1_t merge, const int *address, e32xm1_t mask, unsigned int gvl) {
    return vlseg3wv_mask_int32x3xm1 (merge, address, mask, gvl);
}


int32x3xm2_t test_vlseg3wv_mask_int32x3xm2 (int32x3xm2_t merge, const int *address, e32xm2_t mask, unsigned int gvl) {
    return vlseg3wv_mask_int32x3xm2 (merge, address, mask, gvl);
}


int64x3xm1_t test_vlseg3wv_mask_int64x3xm1 (int64x3xm1_t merge, const long *address, e64xm1_t mask, unsigned int gvl) {
    return vlseg3wv_mask_int64x3xm1 (merge, address, mask, gvl);
}


int64x3xm2_t test_vlseg3wv_mask_int64x3xm2 (int64x3xm2_t merge, const long *address, e64xm2_t mask, unsigned int gvl) {
    return vlseg3wv_mask_int64x3xm2 (merge, address, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg3w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg3w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg3w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg3w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

