/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** ppack.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f0 (int32x2_t x0, int32x2_t x1){
    return __rv_ppack_w(x0, x1);
}

/*
**f1:
** ppackbt.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1){
    return __rv_ppackbt_w(x0, x1);
}

/*
**f2:
** ppacktb.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){
    return __rv_ppacktb_w(x0, x1);
}

/*
**f3:
** ppackt.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f3 (int32x2_t x0, int32x2_t x1){
    return __rv_ppackt_w(x0, x1);
}