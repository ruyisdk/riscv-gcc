/* This is a test program for smalda instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f1:
** smalda\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_smalda(x0, x1, x2);

}



/*
**f3:
** smalda\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f3 (int64_t x0, int16x4_t x1, int16x4_t x2){

    return __rv_v_smalda(x0, x1, x2);

}



