/* This is a test program for khmtt instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** khmtt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f0 (uint32_t x0, uint32_t x1){

    return __rv_khmtt(x0, x1);

}



/*
**f2:
** khmtt\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f2 (int16x2_t x0, int16x2_t x1){

    return __rv_v_khmtt(x0, x1);

}



