/* This is a test program for smmwt instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** smmwt\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, uintXLEN_t x1){

    return __rv_smmwt(x0, x1);

}



/*
**f1:
** smmwt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int32_t x0, int16x2_t x1){

    return __rv_v_smmwt(x0, x1);

}



