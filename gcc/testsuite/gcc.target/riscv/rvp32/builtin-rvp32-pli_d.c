/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pli.db\ta[0-9],1
** ...
*/

int64_t f0 (int64_t x0){
    return __rv_pli_db(1);
}

/*
**f1:
** pli.dh\ta[0-9],1
** ...
*/

int64_t f1 (int64_t x0){
    return __rv_pli_dh(1);
}

/*
**f2:
** plui.db\ta[0-9],1
** ...
*/

int64_t f2 (int64_t x0){
    return __rv_plui_dh(1);
}
