/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** ppack.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){
    return __rv_ppack_dh(x0, x1);
}

/*
**f1:
** ppack.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){
    return __rv_ppack_dw(x0, x1);
}

/*
**f2:
** ppackbt.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_ppackbt_dh(x0, x1);
}

/*
**f3:
** ppackbt.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int64_t x1){
    return __rv_ppackbt_dw(x0, x1);
}

/*
**f4:
** ppacktb.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int64_t x1){
    return __rv_ppacktb_dh(x0, x1);
}

/*
**f5:
** ppacktb.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_ppacktb_dw(x0, x1);
}

/*
**f6:
** ppackt.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int64_t x0, int64_t x1){
    return __rv_ppackt_dh(x0, x1);
}

/*
**f7:
** ppackt.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int64_t x0, int64_t x1){
    return __rv_ppackt_dw(x0, x1);
}
