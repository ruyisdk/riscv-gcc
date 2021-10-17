
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

int32x2xm1_t test_vlxseg2wv_mask_int32x2xm1 (int32x2xm1_t merge, const int *address, int32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int32x2xm1 (merge, address, index, mask, gvl);
}


int32x2xm2_t test_vlxseg2wv_mask_int32x2xm2 (int32x2xm2_t merge, const int *address, int32xm2_t index, e32xm2_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int32x2xm2 (merge, address, index, mask, gvl);
}


int32x2xm4_t test_vlxseg2wv_mask_int32x2xm4 (int32x2xm4_t merge, const int *address, int32xm4_t index, e32xm4_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int32x2xm4 (merge, address, index, mask, gvl);
}


int64x2xm1_t test_vlxseg2wv_mask_int64x2xm1 (int64x2xm1_t merge, const long *address, int64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int64x2xm1 (merge, address, index, mask, gvl);
}


int64x2xm2_t test_vlxseg2wv_mask_int64x2xm2 (int64x2xm2_t merge, const long *address, int64xm2_t index, e64xm2_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int64x2xm2 (merge, address, index, mask, gvl);
}


int64x2xm4_t test_vlxseg2wv_mask_int64x2xm4 (int64x2xm4_t merge, const long *address, int64xm4_t index, e64xm4_t mask, unsigned int gvl) {
    return vlxseg2wv_mask_int64x2xm4 (merge, address, index, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg2w\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlxseg2w\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

