/* This is a test program for sll16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** sll16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uintXLEN_t f0 (uintXLEN_t x0, uint32_t x1){

    return __rv_sll16(x0, x1);

}



/*
**f2:
** sll16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f2 (uint16x4_t x0, uint32_t x1){

    return __rv_v_sll16(x0, x1);

}



/*
**f4:
** sll16\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint16x4_t f4 (uint16x4_t x0, uint32_t x1){

    return __rv_v_sll16(x0, x1);

}



