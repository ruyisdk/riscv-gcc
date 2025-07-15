/* This is a test program for kslraw.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kslraw.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (int32_t x0, int32_t x1){

    return __rv_kslraw_u(x0, x1);

}



