/* This is a test program for ursubw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** ursubw\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f0 (uint32_t x0, uint32_t x1){

    return __rv_ursubw(x0, x1);

}



