/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pusati.h\ta[0-9],a[0-9],1
** ...
*/

uint16x2_t f1 (uint16x2_t x0, uint32_t x1){
    return __rv_pusati_h(x0, 1);
}

/*
**f1:
** usati\ta[0-9],a[0-9],1
** ...
*/

uint32_t f0 (uint32_t x0, uint32_t x1){
    return __rv_usati(x0, 1);
}
