/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psrl.bs\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f0 (uint8x8_t x0, uint8x8_t x1){
    return __rv_psrl_bs(x0, x1);
}

/*
**f1:
** psrl.hs\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f1 (uint16x4_t x0, uint16x4_t x1){
    return __rv_psrl_hs(x0, x1);
}

/*
**f2:
** psrl.ws\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f2 (uint32x2_t x0, uint32x2_t x1){
    return __rv_psrl_ws(x0, x1);
}
