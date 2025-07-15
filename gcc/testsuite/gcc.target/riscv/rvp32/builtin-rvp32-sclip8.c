/* This is a test program for sclip8 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sclip8\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_sclip8(x0, 1);

}



/*
**f1:
** sclip8\ta[0-9],a[0-9],1
** ...
*/

int8x4_t f1 (int8x4_t x0, uint32_t x1){

    return __rv_v_sclip8(x0, 1);

}



