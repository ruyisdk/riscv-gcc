/* This is a test program for fsr instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn_zbpbo -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** fsr\ta[0-9],a[0-9],a[0-9],a[0-9]
** ...
*/

uint32_t f0 (uint32_t x0, uint32_t x1, uint32_t x2){

    return __rv_fsr(x0, x1, x2);

}



