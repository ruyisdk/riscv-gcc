/* This is a test program for srl32.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** srl32.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f0 (uint64_t x0, uint32_t x1){

    return __rv_srl32_u(x0, x1);

}



/*
**f1:
** srl32.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f1 (uint32x2_t x0, uint32_t x1){

    return __rv_v_srl32_u(x0, x1);

}



/*
**f2:
** srl32.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f2 (uint32x2_t x0, uint32_t x1){

    return __rv_v_srl32_u(x0, x1);

}



