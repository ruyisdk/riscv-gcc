/* This is a test program for kmmawb2.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kmmawb2.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, intXLEN_t x1, uintXLEN_t x2){

    return __rv_kmmawb2_u(x0, x1, x2);

}



/*
**f2:
** kmmawb2.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1, int16x4_t x2){

    return __rv_v_kmmawb2_u(x0, x1, x2);

}



