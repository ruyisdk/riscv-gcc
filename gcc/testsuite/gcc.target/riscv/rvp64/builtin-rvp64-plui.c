/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** plui.h\ta[0-9],1
** ...
*/

int16x4_t f0 (int64_t x0){
    return __rv_plui_h(1);
}

/*
**f1:
** plui.w\ta[0-9],1
** ...
*/

int32x2_t f1 (int64_t x0){
    return __rv_plui_w(1);
}
