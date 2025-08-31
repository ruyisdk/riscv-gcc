/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pslli.b\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f0 (int8x4_t x0, int32_t x1){
    return __rv_pslli_b(x0, x1);
}

/*
**f0:
** pslli.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, int32_t x1){
    return __rv_pslli_h(x0, x1);
}

/*
**f0:
** psslai.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int32_t x1){
    return __rv_psslai_h(x0, x1);
}

/*
**f0:
** sslai\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f3 (int32_t x0, int32_t x1){
    return __rv_sslai(x0, x1);
}
