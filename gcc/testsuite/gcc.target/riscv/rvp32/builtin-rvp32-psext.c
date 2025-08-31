/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gcp -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <riscv_simd.h>

/*
**f0:
** psext.h.b\ta[0-9],a[0-9]
** ...
*/

int16x2_t f0 (int8x4_t x0){
    return __rv_psext_h_b(x0);
}
