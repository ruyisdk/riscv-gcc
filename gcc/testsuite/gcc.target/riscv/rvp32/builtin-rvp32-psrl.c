/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psrl.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f0 (int8x4_t x0, int8x4_t x1){
    return __rv_psrl_bs(x0, x1);
}

/*
**f1:
** psrl.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, int16x2_t x1){
    return __rv_psrl_hs(x0, x1);
}
