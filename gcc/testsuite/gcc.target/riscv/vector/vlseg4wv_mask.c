
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x4xm1_t test_vlseg4wv_mask_int32x4xm1 (int32x4xm1_t merge, const int *address, e32xm1_t mask, unsigned int gvl) {
    return vlseg4wv_mask_int32x4xm1 (merge, address, mask, gvl);
}


int32x4xm2_t test_vlseg4wv_mask_int32x4xm2 (int32x4xm2_t merge, const int *address, e32xm2_t mask, unsigned int gvl) {
    return vlseg4wv_mask_int32x4xm2 (merge, address, mask, gvl);
}


int64x4xm1_t test_vlseg4wv_mask_int64x4xm1 (int64x4xm1_t merge, const long *address, e64xm1_t mask, unsigned int gvl) {
    return vlseg4wv_mask_int64x4xm1 (merge, address, mask, gvl);
}


int64x4xm2_t test_vlseg4wv_mask_int64x4xm2 (int64x4xm2_t merge, const long *address, e64xm2_t mask, unsigned int gvl) {
    return vlseg4wv_mask_int64x4xm2 (merge, address, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg4w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg4w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

