/* This is a test program for smalbt instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ...
** smalbt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_smalbt(x0, x1, x2);

}



/*
**f2:
** ...
** smalbt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int16x2_t x1, int16x2_t x2){

    return __rv_v_smalbt(x0, x1, x2);

}



