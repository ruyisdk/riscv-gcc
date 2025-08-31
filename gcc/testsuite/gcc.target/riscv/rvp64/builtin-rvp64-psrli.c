/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psrli.b\ta[0-9],a[0-9],1
** ...
*/

int8x8_t f0 (int8x8_t x0, int64_t x1){
    return __rv_psrli_b(x0, 1);
}

/*
**f0:
** psrli.h\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f1 (int16x4_t x0, int64_t x1){
    return __rv_psrli_h(x0, 1);
}

/*
**f0:
** psrli.w\ta[0-9],a[0-9],1
** ...
*/

int32x2_t f2 (int32x2_t x0, int64_t x1){
    return __rv_psrli_w(x0, 1);
}
