/* This is a test program for maddr32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** maddr32\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1, int32_t x2){

    return __rv_maddr32(x0, x1, x2);

}



