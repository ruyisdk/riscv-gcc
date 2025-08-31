/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psext.h.b\ta[0-9],a[0-9]
** ...
*/

int16x4_t f0 (int8x8_t x0){
    return __rv_psext_h_b(x0);
}

/*
**f1:
** psext.w.b\ta[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int8x8_t x0){
    return __rv_psext_w_b(x0);
}

/*
**f2:
** psext.w.h\ta[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int16x4_t x0){
    return __rv_psext_w_h(x0);
}
