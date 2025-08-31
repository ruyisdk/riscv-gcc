/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** padd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_padd_b(x0, x1);
}

/*
**f1:
** padd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_padd_h(x0, x1);
}

/*
**f2:
** padd.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){
    return __rv_padd_w(x0, x1);
}

/*
**f3:
** psadd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f3 (int8x8_t x0, int8x8_t x1){
    return __rv_psadd_b(x0, x1);
}

/*
**f4:
** psadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f4 (int16x4_t x0, int16x4_t x1){
    return __rv_psadd_h(x0, x1);
}

/*
**f5:
** psadd.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f5 (int32x2_t x0, int32x2_t x1){
    return __rv_psadd_w(x0, x1);
}

/*
**f6:
** paadd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f6 (int8x8_t x0, int8x8_t x1){
    return __rv_paadd_b(x0, x1);
}

/*
**f7:
** paadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f7 (int16x4_t x0, int16x4_t x1){
    return __rv_paadd_h(x0, x1);
}

/*
**f8:
** paadd.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f8 (int32x2_t x0, int32x2_t x1){
    return __rv_paadd_w(x0, x1);
}

/*
**f9:
** psaddu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f9 (uint8x8_t x0, uint8x8_t x1){
    return __rv_psaddu_b(x0, x1);
}

/*
**f10:
** psaddu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f10 (uint16x4_t x0, uint16x4_t x1){
    return __rv_psaddu_h(x0, x1);
}

/*
**f11:
** psaddu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f11 (uint32x2_t x0, uint32x2_t x1){
    return __rv_psaddu_w(x0, x1);
}

/*
**f12:
** paaddu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f12 (uint8x8_t x0, uint8x8_t x1){
    return __rv_paaddu_b(x0, x1);
}

/*
**f13:
** paaddu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f13 (uint16x4_t x0, uint16x4_t x1){
    return __rv_paaddu_h(x0, x1);
}

/*
**f14:
** paaddu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f14 (uint32x2_t x0, uint32x2_t x1){
    return __rv_paaddu_w(x0, x1);
}
