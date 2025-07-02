/* This is a test program for sra16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sra16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_sra16(x0, x1);

}



/*
**f1:
** sra16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f1 (int16x2_t x0, uint32_t x1){

    return __rv_v_sra16(x0, x1);

}



/*
**f3:
** sra16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int16x2_t f3 (int16x2_t x0, uint32_t x1){

    return __rv_v_sra16(x0, x1);

}



