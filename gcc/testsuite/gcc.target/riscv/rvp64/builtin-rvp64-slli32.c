/* This is a test program for slli32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** slli32\ta[0-9],a[0-9],1
** ...
*/

uint64_t f0 (uint64_t x0, uint32_t x1){

    return __rv_slli32(x0, 1);

}



/*
**f1:
** slli32\ta[0-9],a[0-9],1
** ...
*/

uint32x2_t f1 (uint32x2_t x0, uint32_t x1){

    return __rv_v_sll32(x0, 1);

}



/*
**f2:
** slli32\ta[0-9],a[0-9],1
** ...
*/

uint32x2_t f2 (uint32x2_t x0, uint32_t x1){

    return __rv_v_sll32(x0, 1);

}



