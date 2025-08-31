/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psati.h\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f0 (int16x4_t x0, int64_t x1){
    return __rv_psati_h(x0, 1);
}

/*
**f1:
** psati.w\ta[0-9],a[0-9],1
** ...
*/

int32x2_t f1 (int32x2_t x0, int64_t x1){
    return __rv_psati_w(x0, 1);
}

/*
**f0:
** sati\ta[0-9],a[0-9],1
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_sati(x0, 1);
}
