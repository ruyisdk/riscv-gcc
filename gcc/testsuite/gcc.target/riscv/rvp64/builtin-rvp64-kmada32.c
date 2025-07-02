/* This is a test program for kmada32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kmar64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1, int64_t x2){

    return __rv_kmada32(x0, x1, x2);

}



/*
**f1:
** kmar64\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f1 (int64_t x0, int32x2_t x1, int32x2_t x2){

    return __rv_v_kmada32(x0, x1, x2);

}



