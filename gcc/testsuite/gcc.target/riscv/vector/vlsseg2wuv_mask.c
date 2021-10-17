
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x2xm1_t test_vlsseg2wuv_mask_uint32x2xm1 (uint32x2xm1_t merge, const unsigned int *address, long stride, e32xm1_t mask, unsigned int gvl) {
    return vlsseg2wuv_mask_uint32x2xm1 (merge, address, stride, mask, gvl);
}


uint32x2xm2_t test_vlsseg2wuv_mask_uint32x2xm2 (uint32x2xm2_t merge, const unsigned int *address, long stride, e32xm2_t mask, unsigned int gvl) {
    return vlsseg2wuv_mask_uint32x2xm2 (merge, address, stride, mask, gvl);
}


uint32x2xm4_t test_vlsseg2wuv_mask_uint32x2xm4 (uint32x2xm4_t merge, const unsigned int *address, long stride, e32xm4_t mask, unsigned int gvl) {
    return vlsseg2wuv_mask_uint32x2xm4 (merge, address, stride, mask, gvl);
}


uint64x2xm1_t test_vlsseg2wuv_mask_uint64x2xm1 (uint64x2xm1_t merge, const unsigned long *address, long stride, e64xm1_t mask, unsigned int gvl) {
    return vlsseg2wuv_mask_uint64x2xm1 (merge, address, stride, mask, gvl);
}


uint64x2xm2_t test_vlsseg2wuv_mask_uint64x2xm2 (uint64x2xm2_t merge, const unsigned long *address, long stride, e64xm2_t mask, unsigned int gvl) {
    return vlsseg2wuv_mask_uint64x2xm2 (merge, address, stride, mask, gvl);
}


uint64x2xm4_t test_vlsseg2wuv_mask_uint64x2xm4 (uint64x2xm4_t merge, const unsigned long *address, long stride, e64xm4_t mask, unsigned int gvl) {
    return vlsseg2wuv_mask_uint64x2xm4 (merge, address, stride, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlsseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlsseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m4.*vlsseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlsseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlsseg2wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m4.*vlsseg2wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

