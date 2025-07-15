/* This is a test program for ksubw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ksubw\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0, int32_t x1){

    return __rv_ksubw(x0, x1);

}



