// { dg-do compile }
// { dg-options "-O2 -fno-tree-vectorize -fdump-tree-lim2-details" }
#include "../../gcc.dg/tree-ssa/lim-aligned-self-copy.h"
// { dg-final { scan-tree-dump-times "independent \\(self write\\)" 3 "lim2" } }
