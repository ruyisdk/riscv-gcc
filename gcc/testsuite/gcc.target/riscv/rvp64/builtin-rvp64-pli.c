/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */
#include <riscv_simd.h>

/*
**f0:
** pli.b\ta[0-9],1
** ...
*/

int8x8_t f0 (int64_t x0){
    return __rv_pli_b(1);
}

/*
**f1:
** pli.h\ta[0-9],1
** ...
*/

int16x4_t f1 (int64_t x0){
    return __rv_pli_h(1);
}

/*
**f2:
** pli.w\ta[0-9],1
** ...
*/

int32x2_t f2 (int64_t x0){
    return __rv_pli_w(1);
}
