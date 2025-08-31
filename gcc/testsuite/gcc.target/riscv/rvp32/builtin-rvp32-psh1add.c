/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psh1add.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int16x2_t x0, int16x2_t x1){
    return __rv_psh1add_h(x0, x1);
}

/*
**f1:
** ssh1sadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int32_t x0, int32_t x1){
    return __rv_ssh1sadd_h(x0, x1);
}

/*
**f2:
** pssh1sadd.h\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f2 (int16x2_t x0, int16x2_t x1){
    return __rv_pssh1sadd_h(x0, x1);
}
