/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** predsum.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int64_t x0, int32_t x1){
    return __rv_predsum_dbs(x0, x1);
}

/*
**f1:
** predsum.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int64_t x0, int32_t x1){
    return __rv_predsum_dhs(x0, x1);
}

/*
**f2:
** predsumu.dbs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f2 (int64_t x0, int32_t x1){
    return __rv_predsumu_dbs(x0, x1);
}

/*
**f3:
** predsumu.dhs\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f3 (int64_t x0, int32_t x1){
    return __rv_predsumu_dhs(x0, x1);
}
