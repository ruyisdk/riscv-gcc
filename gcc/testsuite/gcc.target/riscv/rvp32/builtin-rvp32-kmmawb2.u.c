/* This is a test program for kmmawb2.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kmmawb2.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, intXLEN_t x1, uintXLEN_t x2){

    return __rv_kmmawb2_u(x0, x1, x2);

}



/*
**f1:
** kmmawb2.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int32_t x0, int32_t x1, int16x2_t x2){

    return __rv_v_kmmawb2_u(x0, x1, x2);

}



