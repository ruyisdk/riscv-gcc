/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pslli.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x8_t f0 (int8x8_t x0, int64_t x1){
    return __rv_pslli_b(x0, x1);
}

/*
**f1:
** pslli.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f1 (int16x4_t x0, int64_t x1){
    return __rv_pslli_h(x0, x1);
}

/*
**f2:
** pslli.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int64_t x1){
    return __rv_pslli_w(x0, x1);
}

/*
**f3:
** psslai.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f3 (int16x4_t x0, int64_t x1){
    return __rv_psslai_h(x0, x1);
}

/*
**f4:
** psslai.w\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f4 (int32x2_t x0, int64_t x1){
    return __rv_psslai_w(x0, x1);
}
