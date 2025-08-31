/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psrli.b\ta[0-9],a[0-9],1
** ...
*/

int8x4_t f0 (int8x4_t x0, int32_t x1){
    return __rv_psrli_b(x0, 1);
}

/*
**f0:
** psrli.h\ta[0-9],a[0-9],1
** ...
*/

int16x2_t f1 (int16x2_t x0, int32_t x1){
    return __rv_psrli_h(x0, 1);
}
