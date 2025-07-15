/* This is a test program for ukmsr64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ...
** ukmsr64\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f0 (uint64_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_ukmsr64(x0, x1, x2);

}



