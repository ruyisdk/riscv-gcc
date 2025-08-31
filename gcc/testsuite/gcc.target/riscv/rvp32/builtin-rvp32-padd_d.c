/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** padd_db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){
    return __rv_padd_db(x0, x1);
}

/*
**f1:
** padd_dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){
    return __rv_padd_dh(x0, x1);
}

/*
**f2:
** padd_dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_padd_dw(x0, x1);
}

/*
**f3:
** addd\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int64_t x1){
    return __rv_addd(x0, x1);
}

/*
**f4:
** psadd_db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int64_t x1){
    return __rv_psadd_db(x0, x1);
}

/*
**f5:
** psadd_dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_psadd_dh(x0, x1);
}

/*
**f6:
** psadd_dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int64_t x0, int64_t x1){
    return __rv_psadd_dw(x0, x1);
}

/*
**f7:
** paadd_db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int64_t x0, int64_t x1){
    return __rv_paadd_db(x0, x1);
}

/*
**f8:
** paadd_dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f8 (int64_t x0, int64_t x1){
    return __rv_paadd_dh(x0, x1);
}

/*
**f9:
** paadd.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f9 (int64_t x0, int64_t x1){
    return __rv_paadd_dw(x0, x1);
}

/*
**f10:
** psaaddu.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f10 (int64_t x0, int64_t x1){
    return __rv_psaddu_db(x0, x1);
}

/*
**f11:
** psaaddu.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f11 (int64_t x0, int64_t x1){
    return __rv_psaddu_dh(x0, x1);
}

/*
**f12:
** psaaddu.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f12 (int64_t x0, int64_t x1){
    return __rv_psaddu_dw(x0, x1);
}

/*
**f13:
** paaddu.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f13 (int64_t x0, int64_t x1){
    return __rv_paaddu_db(x0, x1);
}

/*
**f14:
** paaddu.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f14 (int64_t x0, int64_t x1){
    return __rv_paaddu_dh(x0, x1);
}

/*
**f15:
** paaddu.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f15 (int64_t x0, int64_t x1){
    return __rv_paaddu_dw(x0, x1);
}

/*
**f16:
** psub.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f16 (int64_t x0, int64_t x1){
    return __rv_psub_db(x0, x1);
}

/*
**f17:
** psub.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f17 (int64_t x0, int64_t x1){
    return __rv_psub_dh(x0, x1);
}

/*
**f18:
** psub.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f18 (int64_t x0, int64_t x1){
    return __rv_psub_dw(x0, x1);
}

/*
**f19:
** subd\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f19 (int64_t x0, int64_t x1){
    return __rv_subd(x0, x1);
}
