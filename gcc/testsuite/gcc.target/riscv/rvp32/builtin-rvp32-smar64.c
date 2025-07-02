/* This is a test program for smar64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ...
** smar64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, intXLEN_t x1, intXLEN_t x2){

    return __rv_smar64(x0, x1, x2);

}



