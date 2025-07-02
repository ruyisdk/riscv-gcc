/* This is a test program for sub64 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ...
** sub64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){

    return __rv_ssub64(x0, x1);

}



/*
**f1:
** ...
** sub64\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f1 (uint64_t x0, uint64_t x1){

    return __rv_usub64(x0, x1);

}



