/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** mvm\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1, int32_t x2){
    return __rv_mvm(x0, x1, x2);
}

/*
**f1:
** mvmn\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1, int32_t x2){
    return __rv_mvmn(x0, x1, x2);
}

/*
**f2:
** merge\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1, int32_t x2){
    return __rv_merge(x0, x1, x2);
}
