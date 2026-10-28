// { dg-do compile }
// { dg-options "-O2 -fno-tree-vectorize -fdump-tree-uncprop-details" }
#include "../../gcc.dg/tree-ssa/uncprop-loop-constant.h"
// { dg-final { scan-tree-dump "Retaining cheap loop latch constant" "uncprop1" } }
