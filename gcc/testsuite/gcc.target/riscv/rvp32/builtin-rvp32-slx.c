/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** slx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1){
    return __rv_slx(x0, x1);
}

/*
**f1:
** srx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int32_t x0, int32_t x1){
    return __rv_srx(x0, x1);
}
