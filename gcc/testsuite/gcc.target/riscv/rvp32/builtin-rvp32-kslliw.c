/* This is a test program for kslliw instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kslliw\ta[0-9],a[0-9],1
** ...
*/

int32_t f0 (int32_t x0, uint32_t x1){

    return __rv_ksllw(x0, 1);

}



