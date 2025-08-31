/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pmin.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){
    return __rv_pmin_db(x0, x1);
}

/*
**f1:
** pmin.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){
    return __rv_pmin_dh(x0, x1);
}

/*
**f2:
** pmin.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int64_t x1){
    return __rv_pmin_dw(x0, x1);
}

/*
**f3:
** pminu.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int64_t x1){
    return __rv_pminu_db(x0, x1);
}

/*
**f4:
** pminu.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int64_t x1){
    return __rv_pminu_dh(x0, x1);
}

/*
**f5:
** pminu.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f5 (int64_t x0, int64_t x1){
    return __rv_pminu_dw(x0, x1);
}

/*
**f6:
** pmax.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f6 (int64_t x0, int64_t x1){
    return __rv_pmax_db(x0, x1);
}

/*
**f7:
** pmax.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f7 (int64_t x0, int64_t x1){
    return __rv_pmax_dh(x0, x1);
}

/*
**f8:
** pmax.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f8 (int64_t x0, int64_t x1){
    return __rv_pmax_dw(x0, x1);
}

/*
**f9:
** pmaxu.db\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f9 (int64_t x0, int64_t x1){
    return __rv_pmaxu_db(x0, x1);
}

/*
**f10:
** pmaxu.dh\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f10 (int64_t x0, int64_t x1){
    return __rv_pmaxu_dh(x0, x1);
}

/*
**f11:
** pmaxu.dw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f11 (int64_t x0, int64_t x1){
    return __rv_pmaxu_dw(x0, x1);
}
