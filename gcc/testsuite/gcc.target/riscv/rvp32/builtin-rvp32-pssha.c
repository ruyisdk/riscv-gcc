/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pssha.bs\ta[0-9],a[0-9],[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1){
    return __rv_pssha_hs(x0, x1);
}

/*
**f1:
** ssha\ta[0-9],a[0-9],[0-9]
** ...
*/

int32_t f1 (int32_t x0, int32_t x1){
    return __rv_ssha(x0, x1);
}

/*
**f2:
** psshar.hs\ta[0-9],a[0-9],[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int16x2_t x1){
    return __rv_psshar_hs(x0, x1);
}

/*
**f3:
** sshar\ta[0-9],a[0-9],[0-9]
** ...
*/

int32_t f3 (int32_t x0, int32_t x1){
    return __rv_sshar(x0, x1);
}
