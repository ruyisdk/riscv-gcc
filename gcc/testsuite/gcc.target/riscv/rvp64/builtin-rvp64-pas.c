/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pas.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f0 (int16x4_t x0, int16x4_t x1){
    return __rv_pas_hx(x0, x1);
}

/*
**f1:
** pas.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1){
    return __rv_pas_wx(x0, x1);
}

/*
**f2:
** psa.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f2 (int16x4_t x0, int16x4_t x1){
    return __rv_psa_hx(x0, x1);
}

/*
**f3:
** psa.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f3 (int32x2_t x0, int32x2_t x1){
    return __rv_psa_wx(x0, x1);
}

/*
**f4:
** psas.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f4 (int16x4_t x0, int16x4_t x1){
    return __rv_psas_hx(x0, x1);
}

/*
**f5:
** psas.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f5 (int32x2_t x0, int32x2_t x1){
    return __rv_psas_wx(x0, x1);
}

/*
**f6:
** pssa.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f6 (int16x4_t x0, int16x4_t x1){
    return __rv_pssa_hx(x0, x1);
}

/*
**f7:
** pssa.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f7 (int32x2_t x0, int32x2_t x1){
    return __rv_pssa_wx(x0, x1);
}

/*
**f8:
** paas.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f8 (int16x4_t x0, int16x4_t x1){
    return __rv_paas_hx(x0, x1);
}

/*
**f9:
** paas.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f9 (int32x2_t x0, int32x2_t x1){
    return __rv_paas_wx(x0, x1);
}

/*
**f10:
** pasa.hx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x4_t f10 (int16x4_t x0, int16x4_t x1){
    return __rv_pasa_hx(x0, x1);
}

/*
**f11:
** pasa.wx\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f11 (int32x2_t x0, int32x2_t x1){
    return __rv_pasa_wx(x0, x1);
}
