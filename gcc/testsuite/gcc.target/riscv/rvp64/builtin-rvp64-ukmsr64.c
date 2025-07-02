/* This is a test program for ukmsr64 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f1:
** ukmsr64\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f1 (uint64_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_ukmsr64(x0, x1, x2);

}



/*
**f2:
** ukmsr64\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f2 (uint64_t x0, uint32x2_t x1, uint32x2_t x2){

    return __rv_v_ukmsr64(x0, x1, x2);

}



