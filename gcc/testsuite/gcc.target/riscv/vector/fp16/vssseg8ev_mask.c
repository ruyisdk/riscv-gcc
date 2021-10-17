
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

void test_vssseg8ev_mask_float16x8xm1 (float16_t *address, long stride, float16x8xm1_t a, e16xm1_t mask, unsigned int gvl) {
    return vssseg8ev_mask_float16x8xm1 (address, stride, a, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vssseg8e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

