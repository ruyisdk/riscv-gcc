/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmul.h.b00\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int8x4_t x0, int8x4_t x1){
    return __rv_pmul_h_b00(x0, x1);
}

/*
**f1:
** pmul.h.b11\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int8x4_t x0, int8x4_t x1){
    return __rv_pmul_h_b11(x0, x1);
}

/*
**f2:
** pmulu.h.b00\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f2 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pmulu_h_b00(x0, x1);
}

/*
**f3:
** pmulu.h.b11\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f3 (uint8x4_t x0, uint8x4_t x1){
    return __rv_pmulu_h_b11(x0, x1);
}

/*
**f4:
** pmulsu.h.b00\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f4 (int8x4_t x0, uint8x4_t x1){
    return __rv_pmulsu_h_b00(x0, x1);
}

/*
**f5:
** pmulsu.h.b11\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f5 (int8x4_t x0, uint8x4_t x1){
    return __rv_pmulsu_h_b11(x0, x1);
}

/*
**f6:
** mul.h00\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f6 (int8x4_t x0, int8x4_t x1){
    return __rv_mul_h00(x0, x1);
}

/*
**f7:
** mul.h11\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f7 (int8x4_t x0, int8x4_t x1){
    return __rv_mul_h11(x0, x1);
}

/*
**f8:
** mulu.h00\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f8 (uint8x4_t x0, uint8x4_t x1){
    return __rv_mulu_h00(x0, x1);
}

/*
**f9:
** mulu.h11\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f9 (uint8x4_t x0, uint8x4_t x1){
    return __rv_mulu_h11(x0, x1);
}

/*
**f10:
** mulsu.h00\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f10 (int8x4_t x0, uint8x4_t x1){
    return __rv_mulsu_h00(x0, x1);
}

/*
**f11:
** mulsu.h11\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f11 (int8x4_t x0, uint8x4_t x1){
    return __rv_mulsu_h11(x0, x1);
}
