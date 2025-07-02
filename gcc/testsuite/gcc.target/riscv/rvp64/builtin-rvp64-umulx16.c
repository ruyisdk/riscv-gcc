/* This is a test program for umulx16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** umulx16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f0 (uint32_t x0, uint32_t x1){

    return __rv_umulx16(x0, x1);

}



/*
**f1:
** umulx16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f1 (uint16x2_t x0, uint16x2_t x1){

    return __rv_v_umulx16(x0, x1);

}



