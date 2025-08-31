/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** padd.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_padd_bs(x0, x1);
}

/*
**f0:
** padd.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_padd_hs(x0, x1);
}

/*
**f0:
** padd.ws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){
    return __rv_padd_ws(x0, x1);
}
