/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psabs.db\ta[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0){
    return __rv_psabs_db(x0);
}

/*
**f1:
** psabs.dh\ta[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0){
    return __rv_psabs_dh(x0);
}

/*
**f2:
** padd.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int32_t x1){
    return __rv_padd_dbs(x0, x1);
}

/*
**f3:
** padd.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int32_t x1){
    return __rv_padd_dhs(x0, x1);
}

/*
**f4:
** padd.dws\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f4 (int64_t x0, int32_t x1){
    return __rv_padd_dws(x0, x1);
}
