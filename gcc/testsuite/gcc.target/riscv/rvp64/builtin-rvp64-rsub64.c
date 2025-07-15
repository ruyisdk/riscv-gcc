/* This is a test program for rsub64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f1:
** rsub64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int64_t x1){

    return __rv_rsub64(x0, x1);

}



