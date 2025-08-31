/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** ppack.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1){
    return __rv_ppack_h(x0, x1);
}

/*
**f1:
** ppackbt.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, int16x2_t x1){
    return __rv_ppackbt_h(x0, x1);
}

/*
**f2:
** packbt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f2 (int32_t x0, int32_t x1){
    return __rv_packbt(x0, x1);
}

/*
**f3:
** ppacktb.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f3 (int16x2_t x0, int16x2_t x1){
    return __rv_ppacktb_h(x0, x1);
}

/*
**f4:
** packtb\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f4 (int32_t x0, int32_t x1){
    return __rv_packtb(x0, x1);
}

/*
**f5:
** ppackt.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f5 (int16x2_t x0, int16x2_t x1){
    return __rv_ppackt_h(x0, x1);
}

/*
**f6:
** packt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f6 (int32_t x0, int32_t x1){
    return __rv_packt(x0, x1);
}
