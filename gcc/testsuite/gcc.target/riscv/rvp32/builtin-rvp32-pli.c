/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** pli.b\ta[0-9],1
** ...
*/

int8x4_t f0 (int32_t x0){
    return __rv_pli_b(1);
}

/*
**f1:
** pli.h\ta[0-9],1
** ...
*/

int16x2_t f1 (int32_t x0){
    return __rv_pli_h(1);
}
