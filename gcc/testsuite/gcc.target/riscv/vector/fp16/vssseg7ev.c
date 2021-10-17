
/* { dg-do assemble } */
/* { dg-skip-if "test vector insns" { *-*-* } { "*" } { "-march=*f*d*v*" } } */
/* { dg-options "-O2 --save-temps" } */

#include <riscv-vector.h>

void test_vssseg7ev_float16x7xm1 (float16_t *address, long stride, float16x7xm1_t a, unsigned int gvl) {
    return vssseg7ev_float16x7xm1 (address, stride, a, gvl);
}

/* { dg-final { scan-assembler "vsetvli\t\[a-z\]+\[0-9\]+,\[a-z\]+\[0-9\]+,e16,m1.*vssseg7e\.v" } }*/

/* { dg-final { cleanup-saved-temps } } */

