/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** padd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f0 (int8x4_t x0, int8x4_t x1){
    return __rv_padd_b(x0, x1);
}

/*
**f1:
** padd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, int16x2_t x1){
    return __rv_padd_h(x0, x1);
}

/*
**f2:
** sadd\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f2 (int32_t x0, int32_t x1){
    return __rv_sadd(x0, x1);
}

/*
**f3:
** psadd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f3 (int8x4_t x0, int8x4_t x1){
    return __rv_psadd_b(x0, x1);
}

/*
**f4:
** psadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f4 (int16x2_t x0, int16x2_t x1){
    return __rv_psadd_h(x0, x1);
}

/*
**f5:
** aadd\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f5 (int32_t x0, int32_t x1){
    return __rv_aadd(x0, x1);
}

/*
**f6:
** paadd.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f6 (int8x4_t x0, int8x4_t x1){
    return __rv_paadd_b(x0, x1);
}

/*
**f7:
** paadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f7 (int16x2_t x0, int16x2_t x1){
    return __rv_paadd_h(x0, x1);
}

/*
**f8:
** saddu\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f8 (uint32_t x0, uint32_t x1){
    return __rv_saddu(x0, x1);
}

/*
**f9:
** psaddu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f9 (uint8x4_t x0, uint8x4_t x1){
    return __rv_psaddu_b(x0, x1);
}

/*
**f10:
** psaddu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f10 (uint16x2_t x0, uint16x2_t x1){
    return __rv_psaddu_h(x0, x1);
}

/*
**f11:
** aaddu\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f11 (uint32_t x0, uint32_t x1){
    return __rv_aaddu(x0, x1);
}

/*
**f12:
** paaddu.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x4_t f12 (uint8x4_t x0, uint8x4_t x1){
    return __rv_paaddu_b(x0, x1);
}

/*
**f13:
** paaddu.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x2_t f13 (uint16x2_t x0, uint16x2_t x1){
    return __rv_paaddu_h(x0, x1);
}
