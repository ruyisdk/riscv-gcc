/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psati.h\ta[0-9],a[0-9],1
** ...
*/

int16x2_t f0 (int16x2_t x0, int32_t x1){
    return __rv_psati_h(x0, 1);
}

/*
**f1:
** sati\ta[0-9],a[0-9],1
** ...
*/

int32_t f1 (int32_t x0, int32_t x1){
    return __rv_sati(x0, 1);
}
