/* This is a test program for smulx16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** smulx16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (uint32_t x0, uint32_t x1){

    return __rv_smulx16(x0, x1);

}



/*
**f1:
** smulx16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int16x2_t x0, int16x2_t x1){

    return __rv_v_smulx16(x0, x1);

}



