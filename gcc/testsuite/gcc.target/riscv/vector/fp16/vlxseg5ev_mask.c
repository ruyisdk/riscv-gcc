
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

float16x5xm1_t test_vlxseg5ev_mask_float16x5xm1 (float16x5xm1_t merge, const float16_t *address, int16xm1_t index, e16xm1_t mask, unsigned int gvl) {
    return vlxseg5ev_mask_float16x5xm1 (merge, address, index, mask, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vlxseg5e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

