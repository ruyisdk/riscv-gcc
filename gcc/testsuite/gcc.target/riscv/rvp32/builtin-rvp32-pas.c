/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pas.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1){
    return __rv_pas_hx(x0, x1);
}

/*
**f1:
** psa.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, int16x2_t x1){
    return __rv_psa_hx(x0, x1);
}

/*
**f2:
** psas.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int16x2_t x1){
    return __rv_psas_hx(x0, x1);
}

/*
**f3:
** pssa.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f3 (int16x2_t x0, int16x2_t x1){
    return __rv_pssa_hx(x0, x1);
}

/*
**f4:
** paas.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f4 (int16x2_t x0, int16x2_t x1){
    return __rv_paas_hx(x0, x1);
}

/*
**f5:
** pasa.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f5 (int16x2_t x0, int16x2_t x1){
    return __rv_pasa_hx(x0, x1);
}