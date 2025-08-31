/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** macc.h01\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1, int16x2_t x2){
    return __rv_macc_h01(x0, x1, x2);
}

/*
**f1:
** maccu.h01\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f1 (uint16x2_t x0, uint16x2_t x1, uint16x2_t x2){
    return __rv_maccu_h01(x0, x1, x2);
}
