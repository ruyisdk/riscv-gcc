/* This is a test program for pbsad instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** pbsad\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uintXLEN_t x1){

    return __rv_pbsad(x0, x1);

}



/*
**f2:
** pbsad\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f2 (uint8x8_t x0, uint8x8_t x1){

    return __rv_v_pbsad(x0, x1);

}



