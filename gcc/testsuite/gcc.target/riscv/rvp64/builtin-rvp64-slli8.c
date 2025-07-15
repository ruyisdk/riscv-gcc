/* This is a test program for slli8 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** slli8\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_slli8(x0, 1);

}



/*
**f2:
** slli8\ta[0-9],a[0-9],1
** ...
*/

uint8x8_t f2 (uint8x8_t x0, uint32_t x1){

    return __rv_v_slli8(x0, 1);

}



/*
**f4:
** slli8\ta[0-9],a[0-9],1
** ...
*/

uint8x8_t f4 (uint8x8_t x0, uint32_t x1){

    return __rv_v_slli8(x0, 1);

}



