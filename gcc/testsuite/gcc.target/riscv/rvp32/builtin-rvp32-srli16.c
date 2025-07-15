/* This is a test program for srli16 instruction.  */
/* { dg-do compile { target riscv32*-*-* } } */
/* { dg-options "-march=rv32gc_zpn -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** srli16\ta[0-9],a[0-9],1
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_srl16(x0, 1);

}



/*
**f1:
** srli16\ta[0-9],a[0-9],1
** ...
*/

uint16x2_t f1 (uint16x2_t x0, uint32_t x1){

    return __rv_v_srl16(x0, 1);

}



/*
**f3:
** srli16\ta[0-9],a[0-9],1
** ...
*/

uint16x2_t f3 (uint16x2_t x0, uint32_t x1){

    return __rv_v_srl16(x0, 1);

}



