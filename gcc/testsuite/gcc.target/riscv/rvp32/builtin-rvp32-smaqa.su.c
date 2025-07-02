/* This is a test program for smaqa.su instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** smaqa.su\ta[0-9],a[0-9],a[0-9]
** ...
*/

intXLEN_t f0 (intXLEN_t x0, uintXLEN_t x1, uintXLEN_t x2){

    return __rv_smaqa_su(x0, x1, x2);

}



/*
**f1:
** smaqa.su\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32_t f1 (int32_t x0, int8x4_t x1, uint8x4_t x2){

    return __rv_v_smaqa_su(x0, x1, x2);

}



