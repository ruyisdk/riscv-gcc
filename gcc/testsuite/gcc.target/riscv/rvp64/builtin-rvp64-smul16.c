/* This is a test program for smul16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zpsfoperand -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** smul16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (uint32_t x0, uint32_t x1){

    return __rv_smul16(x0, x1);

}



/*
**f1:
** smul16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int16x2_t x0, int16x2_t x1){

    return __rv_v_smul16(x0, x1);

}



