/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pdif.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_pdif_b(x0, x1);
}

/*
**f1:
** pdif.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_pdif_h(x0, x1);
}

/*
**f2:
** pdifu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f2 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pdifu_b(x0, x1);
}

/*
**f3:
** pdifu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f3 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pdifu_h(x0, x1);
}

