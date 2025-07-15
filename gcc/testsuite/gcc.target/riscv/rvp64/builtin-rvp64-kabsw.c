/* This is a test program for kabsw instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kabsw\ta[0-9],a[0-9]
** ...
*/

int32_t f0 (int32_t x0){

    return __rv_kabsw(x0);

}



