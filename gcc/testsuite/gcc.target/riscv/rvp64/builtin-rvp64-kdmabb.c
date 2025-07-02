/* This is a test program for kdmabb instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kdmabb\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, uint32_t x1, uint32_t x2){

    return __rv_kdmabb(x0, x1, x2);

}



/*
**f2:
** kdmabb\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f2 (int32_t x0, int16x2_t x1, int16x2_t x2){

    return __rv_v_kdmabb(x0, x1, x2);

}



