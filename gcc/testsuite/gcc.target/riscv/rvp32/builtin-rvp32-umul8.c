/* This is a test program for umul8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zpsfoperand -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** umul8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f0 (uint32_t x0, uint32_t x1){

    return __rv_umul8(x0, x1);

}



/*
**f1:
** umul8\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f1 (uint8x4_t x0, uint8x4_t x1){

    return __rv_v_umul8(x0, x1);

}



