/* This is a test program for mulsr64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O0" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ...
mulsr64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int32_t x0, int32_t x1){

    return __rv_mulsr64(x0, x1);

}



