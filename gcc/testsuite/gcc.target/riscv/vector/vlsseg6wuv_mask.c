
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=rv*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

uint32x6xm1_t test_vlsseg6wuv_mask_uint32x6xm1 (uint32x6xm1_t merge, const unsigned int *address, long stride, e32xm1_t mask, unsigned int gvl) {
    return vlsseg6wuv_mask_uint32x6xm1 (merge, address, stride, mask, gvl);
}


uint64x6xm1_t test_vlsseg6wuv_mask_uint64x6xm1 (uint64x6xm1_t merge, const unsigned long *address, long stride, e64xm1_t mask, unsigned int gvl) {
    return vlsseg6wuv_mask_uint64x6xm1 (merge, address, stride, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e32,m1.*vlsseg6wu\.v" } }*/
/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e64,m1.*vlsseg6wu\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

