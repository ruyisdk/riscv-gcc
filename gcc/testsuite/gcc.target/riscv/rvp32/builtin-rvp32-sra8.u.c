/* This is a test program for sra8.u instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sra8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_sra8_u(x0, x1);

}



/*
**f1:
** sra8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f1 (int8x4_t x0, uint32_t x1){

    return __rv_v_sra8_u(x0, x1);

}



/*
**f3:
** sra8.u\ta[0-9],a[0-9],a[0-9]
** ...
*/

int8x4_t f3 (int8x4_t x0, uint32_t x1){

    return __rv_v_sra8_u(x0, x1);

}



