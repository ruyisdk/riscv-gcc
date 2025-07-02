/* This is a test program for smal instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f1:
** smal\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, uintXLEN_t x1){

    return __rv_smal(x0, x1);

}



/*
**f3:
** smal\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int16x4_t x1){

    return __rv_v_smal(x0, x1);

}



