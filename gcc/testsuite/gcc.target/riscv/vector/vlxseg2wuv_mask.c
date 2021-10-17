
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x2xm1_t test_vlxseg2wuv_mask_uint32x2xm1 (uint32x2xm1_t merge, const unsigned int *address, uint32xm1_t index, e32xm1_t mask, unsigned int gvl) {
    return vlxseg2wuv_mask_uint32x2xm1 (merge, address, index, mask, gvl);
}


uint32x2xm2_t test_vlxseg2wuv_mask_uint32x2xm2 (uint32x2xm2_t merge, const unsigned int *address, uint32xm2_t index, e32xm2_t mask, unsigned int gvl) {
    return vlxseg2wuv_mask_uint32x2xm2 (merge, address, index, mask, gvl);
}


uint32x2xm4_t test_vlxseg2wuv_mask_uint32x2xm4 (uint32x2xm4_t merge, const unsigned int *address, uint32xm4_t index, e32xm4_t mask, unsigned int gvl) {
    return vlxseg2wuv_mask_uint32x2xm4 (merge, address, index, mask, gvl);
}


uint64x2xm1_t test_vlxseg2wuv_mask_uint64x2xm1 (uint64x2xm1_t merge, const unsigned long *address, uint64xm1_t index, e64xm1_t mask, unsigned int gvl) {
    return vlxseg2wuv_mask_uint64x2xm1 (merge, address, index, mask, gvl);
}


uint64x2xm2_t test_vlxseg2wuv_mask_uint64x2xm2 (uint64x2xm2_t merge, const unsigned long *address, uint64xm2_t index, e64xm2_t mask, unsigned int gvl) {
    return vlxseg2wuv_mask_uint64x2xm2 (merge, address, index, mask, gvl);
}


uint64x2xm4_t test_vlxseg2wuv_mask_uint64x2xm4 (uint64x2xm4_t merge, const unsigned long *address, uint64xm4_t index, e64xm4_t mask, unsigned int gvl) {
    return vlxseg2wuv_mask_uint64x2xm4 (merge, address, index, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlxseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlxseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlxseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlxseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlxseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlxseg2wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

