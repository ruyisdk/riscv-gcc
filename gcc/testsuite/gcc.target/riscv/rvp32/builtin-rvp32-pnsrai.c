/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pnsrai.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f0 (int64_t x0, int32_t x1){
    return __rv_pnsrai_b(x0, 1);
}

/*
**f1:
** pnsrai.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f1 (int64_t x0, int32_t x1){
    return __rv_pnsrai_h(x0, 1);
}

/*
**f2:
** nsrai\ta[0-9],a[0-9],1
** ...
*/

int32_t f2 (int64_t x0, int32_t x1){
    return __rv_nsrai(x0, 1);
}

/*
**f3:
** pnsrari.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f3 (int64_t x0, int32_t x1){
    return __rv_pnsrari_b(x0, 1);
}

/*
**f4:
** pnsrari.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f4 (int64_t x0, int32_t x1){
    return __rv_pnsrari_h(x0, 1);
}

/*
**f5:
** nsrari\ta[0-9],a[0-9],1
** ...
*/

int32_t f5 (int64_t x0, int32_t x1){
    return __rv_nsrari(x0, 1);
}
