/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmul.h.b00\ta[0-9],a[0-9]
** ...
*/

int16x4_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_pmul_h_b00(x0, x1);
}

/*
**f1:
** pmul.w.h00\ta[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_pmul_w_h00(x0, x1);
}

/*
**f2:
** pmul.h.b11\ta[0-9],a[0-9]
** ...
*/

int16x4_t f2 (int8x8_t x0, int8x8_t x1){
    return __rv_pmul_h_b11(x0, x1);
}

/*
**f3:
** pmul.w.h11\ta[0-9],a[0-9]
** ...
*/

int32x2_t f3 (int16x4_t x0, int16x4_t x1){
    return __rv_pmul_w_h11(x0, x1);
}

/*
**f4:
** pmulu.h.b00\ta[0-9],a[0-9]
** ...
*/

uint16x4_t f4 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pmulu_h_b00(x0, x1);
}

/*
**f5:
** pmulu.w.h00\ta[0-9],a[0-9]
** ...
*/

uint32x2_t f5 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pmulu_w_h00(x0, x1);
}

/*
**f6:
** pmulu.h.b11\ta[0-9],a[0-9]
** ...
*/

uint16x4_t f6 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pmulu_h_b11(x0, x1);
}

/*
**f7:
** pmulu.w.h11\ta[0-9],a[0-9]
** ...
*/

uint32x2_t f7 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pmulu_w_h11(x0, x1);
}

/*
**f8:
** pmulsu.h.b00\ta[0-9],a[0-9]
** ...
*/

int16x4_t f8 (int8x8_t x0, int8x8_t x1){
    return __rv_pmulsu_h_b00(x0, x1);
}

/*
**f9:
** pmulsu.w.h00\ta[0-9],a[0-9]
** ...
*/

int32x2_t f9 (int16x4_t x0, int16x4_t x1){
    return __rv_pmulsu_w_h00(x0, x1);
}

/*
**f10:
** pmulsu.h.b11\ta[0-9],a[0-9]
** ...
*/

int16x4_t f10 (int8x8_t x0, int8x8_t x1){
    return __rv_pmulsu_h_b11(x0, x1);
}

/*
**f11:
** pmulsu.w.h11\ta[0-9],a[0-9]
** ...
*/

int32x2_t f11 (int16x4_t x0, int16x4_t x1){
    return __rv_pmulsu_w_h11(x0, x1);
}

/*
**f12:
** mul.w00\ta[0-9],a[0-9]
** ...
*/

int32x2_t f12 (int16x4_t x0, int16x4_t x1){
    return __rv_mul_w00(x0, x1);
}

/*
**f13:
** mul.w11\ta[0-9],a[0-9]
** ...
*/

int32x2_t f13 (int16x4_t x0, int16x4_t x1){
    return __rv_mul_w11(x0, x1);
}

/*
**f14:
** mulu.w00\ta[0-9],a[0-9]
** ...
*/

uint32x2_t f14 (uint16x4_t x0, uint16x4_t x1){
    return __rv_mulu_w00(x0, x1);
}

/*
**f15:
** mulu.w11\ta[0-9],a[0-9]
** ...
*/

uint32x2_t f15 (uint16x4_t x0, uint16x4_t x1){
    return __rv_mulu_w11(x0, x1);
}

/*
**f16:
** mulsu.w00\ta[0-9],a[0-9]
** ...
*/

int32x2_t f16 (int16x4_t x0, uint16x4_t x1){
    return __rv_mulsu_w00(x0, x1);
}

/*
**f17:
** mulsu.w11\ta[0-9],a[0-9]
** ...
*/

int32x2_t f17 (int16x4_t x0, uint16x4_t x1){
    return __rv_mulsu_w11(x0, x1);
}
