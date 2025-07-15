/* This is a test program for max instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn_zbpbo -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** max\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, intXLEN_t x1){

    return __rv_max(x0, x1);

}



