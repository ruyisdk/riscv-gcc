/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** slx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f0 (int32x2_t x0, int32x2_t x1){
    return __rv_slx(x0, x1);
}

/*
**f1:
** srx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1){
    return __rv_srx(x0, x1);
}
