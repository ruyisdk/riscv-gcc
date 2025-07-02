/* This is a test program for uclip32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** uclip32\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (intXLEN_t x0, uint32_t x1){

    return __rv_uclip32(x0, 1);

}



/*
**f1:
** uclip32\ta[0-9],a[0-9],1
** ...
*/

uint32x2_t f1 (int32x2_t x0, uint32_t x1){

    return __rv_v_uclip32(x0, 1);

}



