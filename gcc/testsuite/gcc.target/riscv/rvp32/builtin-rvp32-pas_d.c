/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pas.dhx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){
    return __rv_pas_dhx(x0, x1);
}

/*
**f1:
** psa.dhx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){
    return __rv_psa_dhx(x0, x1);
}

/*
**f2:
** psas.dhx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_psas_dhx(x0, x1);
}

/*
**f3:
** pssa.dhx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int64_t x1){
    return __rv_pssa_dhx(x0, x1);
}

/*
**f4:
** paas.dhx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int64_t x1){
    return __rv_paas_dhx(x0, x1);
}

/*
**f5:
** pasa.dhx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_pasa_dhx(x0, x1);
}
