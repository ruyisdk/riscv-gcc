
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x3xm1_t test_vlsseg3wuv_mask_uint32x3xm1 (uint32x3xm1_t merge, const unsigned int *address, long stride, e32xm1_t mask, unsigned int gvl) {
    return vlsseg3wuv_mask_uint32x3xm1 (merge, address, stride, mask, gvl);
}


uint32x3xm2_t test_vlsseg3wuv_mask_uint32x3xm2 (uint32x3xm2_t merge, const unsigned int *address, long stride, e32xm2_t mask, unsigned int gvl) {
    return vlsseg3wuv_mask_uint32x3xm2 (merge, address, stride, mask, gvl);
}


uint64x3xm1_t test_vlsseg3wuv_mask_uint64x3xm1 (uint64x3xm1_t merge, const unsigned long *address, long stride, e64xm1_t mask, unsigned int gvl) {
    return vlsseg3wuv_mask_uint64x3xm1 (merge, address, stride, mask, gvl);
}


uint64x3xm2_t test_vlsseg3wuv_mask_uint64x3xm2 (uint64x3xm2_t merge, const unsigned long *address, long stride, e64xm2_t mask, unsigned int gvl) {
    return vlsseg3wuv_mask_uint64x3xm2 (merge, address, stride, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlsseg3wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlsseg3wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlsseg3wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlsseg3wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

