/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pdifsumu.b\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f0 (uint8x8_t x0, uint8x8_t x1, uint8x8_t x2){
    return __rv_pdifsumu_b(x0, x1, x2);
}

/*
**f1:
** pdifsumau.b\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f0 (uint8x8_t x0, uint8x8_t x1, uint8x8_t x2){
    return __rv_pdifsumau_b(x0, x1, x2);
}

