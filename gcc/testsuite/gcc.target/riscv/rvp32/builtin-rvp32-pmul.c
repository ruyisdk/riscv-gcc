/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmul.h.b01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int8x4_t x0, int8x4_t x1){
    return __rv_pmul_h_b01(x0, x1);
}

/*
**f1:
** pmulu.h.b01\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f1 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pmulu_h_b01(x0, x1);
}

/*
**f2:
** mul.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int16x2_t x1){
    return __rv_mul_h01(x0, x1);
}

/*
**f3:
** mulu.h01\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f3 (uint16x2_t x0, uint16x2_t x1){
    return __rv_mulu_h01(x0, x1);
}
