/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pnsrli.b\ta[0-9],a[0-9],1
** ...
*/

int32_t f0 (int64_t x0, int32_t x1){
    return __rv_pnsrli_b(x0, 1);
}

/*
**f1:
** pnsrli.h\ta[0-9],a[0-9],1
** ...
*/

int32_t f1 (int64_t x0, int32_t x1){
    return __rv_pnsrli_h(x0, 1);
}

/*
**f2:
** nsrli\ta[0-9],a[0-9],1
** ...
*/

int32_t f2 (int64_t x0, int32_t x1){
    return __rv_nsrli(x0, 1);
}
