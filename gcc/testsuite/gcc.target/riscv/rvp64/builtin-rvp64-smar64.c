/* This is a test program for smar64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f1:
** smar64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, intXLEN_t x1, intXLEN_t x2){

    return __rv_smar64(x0, x1, x2);

}



/*
**f2:
** smar64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f2 (int64_t x0, int32x2_t x1, int32x2_t x2){

    return __rv_v_smar64(x0, x1, x2);

}



