/* This is a test program for srai8.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** srai8.u\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_srai8_u(x0, 1);

}



/*
**f2:
** srai8.u\ta[0-9],a[0-9],1
** ...
*/

int8x8_t f2 (int8x8_t x0, uint32_t x1){

    return __rv_v_srai8_u(x0, 1);

}



/*
**f4:
** srai8.u\ta[0-9],a[0-9],1
** ...
*/

int8x8_t f4 (int8x8_t x0, uint32_t x1){

    return __rv_v_srai8_u(x0, 1);

}



