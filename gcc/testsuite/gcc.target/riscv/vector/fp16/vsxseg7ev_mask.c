
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

void test_vsxseg7ev_mask_float16x7xm1 (float16_t *address, int16xm1_t index, float16x7xm1_t a, e16xm1_t mask, unsigned int gvl) {
    return vsxseg7ev_mask_float16x7xm1 (address, index, a, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vsxseg7e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

