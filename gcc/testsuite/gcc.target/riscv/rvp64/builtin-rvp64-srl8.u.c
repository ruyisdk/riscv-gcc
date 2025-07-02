/* This is a test program for srl8.u instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** srl8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_srl8_u(x0, x1);

}



/*
**f2:
** srl8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f2 (uint8x8_t x0, uint32_t x1){

    return __rv_v_srl8_u(x0, x1);

}



/*
**f4:
** srl8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint8x8_t f4 (uint8x8_t x0, uint32_t x1){

    return __rv_v_srl8_u(x0, x1);

}



