/* { dg-do compile } */
/* { dg-options "-O3 -march=rv32gcp -mabi=ilp32d -mlittle-endian -fdump-tree-vect-details" } */

#include "qmul-cost.h"

/* RV32 keeps its existing model until multiword loop control is costed.  */
/* { dg-final { scan-tree-dump-not {>> 14[^\n]*times scalar_stmt costs 0} "vect" } } */
/* { dg-final { scan-tree-dump-not {>> 30[^\n]*times scalar_stmt costs 0} "vect" } } */
/* { dg-final { scan-tree-dump-not {RVP Q-format loop branch costs} "vect" } } */
/* { dg-final { scan-tree-dump-times {LOOP VECTORIZED} 6 "vect" } } */
