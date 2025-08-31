/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psrai.b\ta[0-9],a[0-9],1
** ...
*/

int8x8_t f0 (int8x8_t x0, int64_t x1){
    return __rv_psrai_b(x0, 1);
}

/*
**f1:
** psrai.h\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f1 (int16x4_t x0, int64_t x1){
    return __rv_psrai_h(x0, 1);
}

/*
**f2:
** psrai.w\ta[0-9],a[0-9],1
** ...
*/

int32x2_t f2 (int32x2_t x0, int64_t x1){
    return __rv_psrai_w(x0, 1);
}

/*
**f3:
** psrari.h\ta[0-9],a[0-9],1
** ...
*/

int16x4_t f3 (int16x4_t x0, int64_t x1){
    return __rv_psrari_h(x0, 1);
}

/*
**f4:
** psrari.w\ta[0-9],a[0-9],1
** ...
*/

int32x2_t f4 (int32x2_t x0, int64_t x1){
    return __rv_psrari_w(x0, 1);
}

/*
**f5:
** srari\ta[0-9],a[0-9],1
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_srari(x0, 1);
}
