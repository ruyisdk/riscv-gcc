/* This is a test program for kmmsb instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** kmmsb\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, intXLEN_t x1, intXLEN_t x2){

    return __rv_kmmsb(x0, x1, x2);

}



/*
**f1:
** kmmsb\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int32x2_t x0, int32x2_t x1, int32x2_t x2){

    return __rv_v_kmmsb(x0, x1, x2);

}



