/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmulh.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1){
    return __rv_pmulh_h(x0, x1);
}

/*
**f1:
** pmulh.h.b0\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int8x4_t x0, int8x4_t x1){
    return __rv_pmulh_h_b0(x0, x1);
}

/*
**f2:
** pmulh.h.b1\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int8x4_t x0, int8x4_t x1){
    return __rv_pmulh_h_b1(x0, x1);
}

/*
**f3:
** pmulhu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f3 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pmulhu_h(x0, x1);
}

/*
**f4:
** pmulhr.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f4 (int16x2_t x0, int16x2_t x1){
    return __rv_pmulhr_h(x0, x1);
}

/*
**f5:
** pmulhru.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f5 (uint16x2_t x0, uint16x2_t x1){
    return __rv_pmulhru_h(x0, x1);
}

/*
**f6:
** pmulhsu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f6 (int8x4_t x0, uint8x4_t x1){
    return __rv_pmulhsu_h(x0, x1);
}

/*
**f7:
** pmulhsu.h.b0\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f7 (int8x4_t x0, uint8x4_t x1){
    return __rv_pmulhsu_h_b0(x0, x1);
}

/*
**f8:
** pmulhsu.h.b1\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f8 (int8x4_t x0, uint8x4_t x1){
    return __rv_pmulhsu_h_b1(x0, x1);
}

/*
**f9:
** pmulhrsu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f9 (uint16x2_t x0, int16x2_t x1){
    return __rv_pmulhrsu_h(x0, x1);
}

/*
**f10:
** mulh.h1\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f10 (int16x2_t x0, int16x2_t x1){
    return __rv_mulh_h1(x0, x1);
}

/*
**f11:
** mulhr\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f11 (int32_t x0, int32_t x1){
    return __rv_mulhr(x0, x1);
}

/*
**f12:
** mulhru\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f12 (uint32_t x0, uint32_t x1){
    return __rv_mulhru(x0, x1);
}

/*
**f13:
** mulh.h0\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f13 (int16x2_t x0, int16x2_t x1){
    return __rv_mulh_h0(x0, x1);
}

/*
**f14:
** mulhsu.h0\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f14 (int16x2_t x0, uint16x2_t x1){
    return __rv_mulhsu_h0(x0, x1);
}

/*
**f15:
** mulhsu.h1\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f15 (int16x2_t x0, uint16x2_t x1){
    return __rv_mulhsu_h1(x0, x1);
}

/*
**f16:
** mulhrsu\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f16 (uint32_t x0, int32_t x1){
    return __rv_mulhrsu(x0, x1);
}

