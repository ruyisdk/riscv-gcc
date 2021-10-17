
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x4xm1_t test_vlsseg4wuv_mask_uint32x4xm1 (uint32x4xm1_t merge, const unsigned int *address, long stride, e32xm1_t mask, unsigned int gvl) {
    return vlsseg4wuv_mask_uint32x4xm1 (merge, address, stride, mask, gvl);
}


uint32x4xm2_t test_vlsseg4wuv_mask_uint32x4xm2 (uint32x4xm2_t merge, const unsigned int *address, long stride, e32xm2_t mask, unsigned int gvl) {
    return vlsseg4wuv_mask_uint32x4xm2 (merge, address, stride, mask, gvl);
}


uint64x4xm1_t test_vlsseg4wuv_mask_uint64x4xm1 (uint64x4xm1_t merge, const unsigned long *address, long stride, e64xm1_t mask, unsigned int gvl) {
    return vlsseg4wuv_mask_uint64x4xm1 (merge, address, stride, mask, gvl);
}


uint64x4xm2_t test_vlsseg4wuv_mask_uint64x4xm2 (uint64x4xm2_t merge, const unsigned long *address, long stride, e64xm2_t mask, unsigned int gvl) {
    return vlsseg4wuv_mask_uint64x4xm2 (merge, address, stride, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlsseg4wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlsseg4wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlsseg4wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlsseg4wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

