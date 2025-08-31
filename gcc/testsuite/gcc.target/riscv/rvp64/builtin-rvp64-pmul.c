/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmul.h.b01\ta[0-9],a[0-9]
** ...
*/

int16x4_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_pmul_h_b01(x0, x1);
}

/*
**f1:
** pmul.w.h01\ta[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_pmul_w_h01(x0, x1);
}

/*
**f2:
** pmulu.h.b01\ta[0-9],a[0-9]
** ...
*/

uint16x4_t f2 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pmulu_h_b01(x0, x1);
}

/*
**f3:
** pmulu.w.h01\ta[0-9],a[0-9]
** ...
*/

uint32x2_t f3 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pmulu_w_h01(x0, x1);
}

/*
**f4:
** mul.w01\ta[0-9],a[0-9]
** ...
*/

int32x2_t f4 (int32x2_t x0, int32x2_t x1){
    return __rv_mul_w01(x0, x1);
}

/*
**f5:
** mulu.w01\ta[0-9],a[0-9]
** ...
*/

uint32x2_t f5 (uint32x2_t x0, uint32x2_t x1){
    return __rv_mulu_w01(x0, x1);
}
