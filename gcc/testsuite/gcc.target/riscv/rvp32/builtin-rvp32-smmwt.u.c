/* This is a test program for smmwt.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** smmwt.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, uintXLEN_t x1){

    return __rv_smmwt_u(x0, x1);

}



/*
**f1:
** smmwt.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int32_t x0, int16x2_t x1){

    return __rv_v_smmwt_u(x0, x1);

}



