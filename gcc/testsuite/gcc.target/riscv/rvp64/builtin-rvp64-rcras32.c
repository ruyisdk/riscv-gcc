/* This is a test program for rcras32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** rcras32\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (int64_t x0, int64_t x1){

    return __rv_rcras32(x0, x1);

}



/*
**f1:
** rcras32\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1){

    return __rv_v_rcras32(x0, x1);

}



