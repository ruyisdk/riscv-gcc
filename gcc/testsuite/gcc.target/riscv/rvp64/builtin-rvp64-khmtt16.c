/* This is a test program for khmtt16 instruction.  */
/* { dg-do compile { target riscv64*-*-* } } */
/* { dg-options "-march=rv64gc_zpn -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" "" } } */

#include <rvp_intrinsic.h>


/*
**f0:
** khmtt16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int64_t f0 (uint64_t x0, uint64_t x1){

    return __rv_khmtt16(x0, x1);

}



/*
**f1:
** khmtt16\ta[0-9],a[0-9],a[0-9]
** ...
*/

int32x2_t f1 (int16x4_t x0, int16x4_t x1){

    return __rv_v_khmtt16(x0, x1);

}



