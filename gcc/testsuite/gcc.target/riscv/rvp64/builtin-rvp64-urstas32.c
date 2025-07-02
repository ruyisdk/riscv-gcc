/* This is a test program for urstas32 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** urstas32\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint64_t f0 (uint64_t x0, uint64_t x1){

    return __rv_urstas32(x0, x1);

}



/*
**f1:
** urstas32\ta[0-9],a[0-9],a[0-9]
** ...
*/

uint32x2_t f1 (uint32x2_t x0, uint32x2_t x1){

    return __rv_v_urstas32(x0, x1);

}



