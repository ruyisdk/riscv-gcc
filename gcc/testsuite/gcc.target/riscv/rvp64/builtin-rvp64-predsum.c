/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** predsum.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int8x8_t x1){
    return __rv_predsum_bs(x0, x1);
}

/*
**f1:
** predsum.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int16x4_t x1){
    return __rv_predsum_hs(x0, x1);
}

/*
**f2:
** predsum.ws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){
    return __rv_predsum_ws(x0, x1);
}

/*
**f3:
** predsumu.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f3 (uint8x8_t x0, uint8x8_t x1){
    return __rv_predsumu_bs(x0, x1);
}

/*
**f4:
** predsumu.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f4 (uint16x4_t x0, uint16x4_t x1){
    return __rv_predsumu_hs(x0, x1);
}

/*
**f5:
** predsumu.ws\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f5 (uint32x2_t x0, uint32x2_t x1){
    return __rv_predsumu_ws(x0, x1);
}
