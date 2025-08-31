/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pdifsumu.b\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f0 (uint8x4_t x0, uint8x4_t x1, uint8x4_t x2){
    return __rv_pdifsumu_b(x0, x1, x2);
}

/*
**f1:
** pdifsuman.b\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f1 (uint8x4_t x0, uint8x4_t x1, uint8x4_t x2){
    return __rv_pdifsumau_b(x0, x1, x2);
}
