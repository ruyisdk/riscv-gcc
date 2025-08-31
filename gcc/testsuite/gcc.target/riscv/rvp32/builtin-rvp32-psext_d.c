/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psext.dh.b\ta[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0){
    return __rv_psext_dh_b(x0);
}

/*
**f1:
** psext.dw.b\ta[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0){
    return __rv_psext_dw_b(x0);
}

/*
**f2:
** psext.dw.h\ta[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0){
    return __rv_psext_dw_h(x0);
}
