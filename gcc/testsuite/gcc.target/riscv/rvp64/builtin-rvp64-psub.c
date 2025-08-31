/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psub.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_psub_b(x0, x1);
}

/*
**f1:
** psub.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_psub_h(x0, x1);
}

/*
**f2:
** psub.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){
    return __rv_psub_w(x0, x1);
}

/*
**f3:
** pssub.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f3 (int8x8_t x0, int8x8_t x1){
    return __rv_pssub_b(x0, x1);
}

/*
**f4:
** pssub.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f4 (int16x4_t x0, int16x4_t x1){
    return __rv_pssub_h(x0, x1);
}

/*
**f5:
** pssub.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f5 (int32x2_t x0, int32x2_t x1){
    return __rv_pssub_w(x0, x1);
}

/*
**f6:
** pasub.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f6 (int8x8_t x0, int8x8_t x1){
    return __rv_pasub_b(x0, x1);
}

/*
**f7:
** pasub.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f7 (int16x4_t x0, int16x4_t x1){
    return __rv_pasub_h(x0, x1);
}

/*
**f8:
** pasub.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f8 (int32x2_t x0, int32x2_t x1){
    return __rv_pasub_w(x0, x1);
}

/*
**f9:
** pssubu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f9 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pssubu_b(x0, x1);
}

/*
**f10:
** pssubu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f10 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pssubu_h(x0, x1);
}

/*
**f11:
** pssubu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f11 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pssubu_w(x0, x1);
}

/*
**f12:
** pasubu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f12 (uint8x8_t x0, uint8x8_t x1){
    return __rv_pasubu_b(x0, x1);
}

/*
**f13:
** pasubu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f13 (uint16x4_t x0, uint16x4_t x1){
    return __rv_pasubu_h(x0, x1);
}

/*
**f14:
** pasubu.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f14 (uint32x2_t x0, uint32x2_t x1){
    return __rv_pasubu_w(x0, x1);
}
