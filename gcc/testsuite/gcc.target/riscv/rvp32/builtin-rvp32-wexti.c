/* This is a test program for wexti instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O0" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ...
wexti\ta[0-9],a[0-9],1
** ...
*/

intXLEN_t f0 (uint64_t x0, uint32_t x1){

    return __rv_wexti(x0, 1);

}



