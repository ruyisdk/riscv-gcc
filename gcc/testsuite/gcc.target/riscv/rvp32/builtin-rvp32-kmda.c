/* This is a test program for kmda instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kmda\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_kmda(x0, x1);

}



/*
**f1:
** kmda\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int16x2_t x0, int16x2_t x1){

    return __rv_v_kmda(x0, x1);

}



