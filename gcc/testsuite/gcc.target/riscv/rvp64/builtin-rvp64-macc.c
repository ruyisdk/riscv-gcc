/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmacc.w.h01\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f0 (int16x4_t x0, int16x4_t x1, int32x2_t x2){
    return __rv_pmacc_w_h01(x0, x1, x2);
}

/*
**f1:
** pmaccu.w.h01\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f1 (uint16x4_t x0, uint16x4_t x1, uint32x2_t x2){
    return __rv_pmaccu_w_h01(x0, x1, x2);
}

/*
**f2:
** macc.w01\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1, int32x2_t x2){
    return __rv_macc_w01(x0, x1, x2);
}

/*
**f3:
** maccu.w01\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f3 (uint32x2_t x0, uint32x2_t x1, uint32x2_t x2){
    return __rv_maccu_w01(x0, x1, x2);
}
