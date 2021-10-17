
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x4xm1_t test_vlseg4wuv_mask_uint32x4xm1 (uint32x4xm1_t merge, const unsigned int *address, e32xm1_t mask, unsigned int gvl) {
    return vlseg4wuv_mask_uint32x4xm1 (merge, address, mask, gvl);
}


uint32x4xm2_t test_vlseg4wuv_mask_uint32x4xm2 (uint32x4xm2_t merge, const unsigned int *address, e32xm2_t mask, unsigned int gvl) {
    return vlseg4wuv_mask_uint32x4xm2 (merge, address, mask, gvl);
}


uint64x4xm1_t test_vlseg4wuv_mask_uint64x4xm1 (uint64x4xm1_t merge, const unsigned long *address, e64xm1_t mask, unsigned int gvl) {
    return vlseg4wuv_mask_uint64x4xm1 (merge, address, mask, gvl);
}


uint64x4xm2_t test_vlseg4wuv_mask_uint64x4xm2 (uint64x4xm2_t merge, const unsigned long *address, e64xm2_t mask, unsigned int gvl) {
    return vlseg4wuv_mask_uint64x4xm2 (merge, address, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlseg4wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m2.*vlseg4wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlseg4wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m2.*vlseg4wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

