/* This is a test program for sub32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sub32\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f0 (uint64_t x0, uint64_t x1){

    return __rv_sub32(x0, x1);

}



/*
**f1:
** sub32\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f1 (uint32x2_t x0, uint32x2_t x1){

    return __rv_v_usub32(x0, x1);

}



/*
**f2:
** sub32\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f2 (int32x2_t x0, int32x2_t x1){

    return __rv_v_ssub32(x0, x1);

}



