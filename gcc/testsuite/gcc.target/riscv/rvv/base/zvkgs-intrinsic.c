/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvkgs -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vuint32m1_t
test_vgmul_vv_u32m1 (vuint32m1_t vd, vuint32m1_t vs2, size_t vl)
{
  return __riscv_vgmul_vv_u32m1 (vd, vs2, vl);
}

vuint32m1_t
test_vgmul_vs_u32m1_u32m1 (vuint32m1_t vd, vuint32m1_t vs2, size_t vl)
{
  return __riscv_vgmul_vs_u32m1_u32m1 (vd, vs2, vl);
}

vuint32m2_t
test_vgmul_vs_u32m1_u32m2_tu (vuint32m2_t vd, vuint32m1_t vs2, size_t vl)
{
  return __riscv_vgmul_vs_u32m1_u32m2_tu (vd, vs2, vl);
}

vuint32m1_t
test_vghsh_vv_u32m1 (vuint32m1_t vd, vuint32m1_t vs2, vuint32m1_t vs1,
		     size_t vl)
{
  return __riscv_vghsh_vv_u32m1 (vd, vs2, vs1, vl);
}

vuint32m1_t
test_vghsh_vs_u32m1_u32m1 (vuint32m1_t vd, vuint32m1_t vs2,
			   vuint32m1_t vs1, size_t vl)
{
  return __riscv_vghsh_vs_u32m1_u32m1 (vd, vs2, vs1, vl);
}

vuint32m2_t
test_vghsh_vs_u32m1_u32m2_tu (vuint32m2_t vd, vuint32m2_t vs2,
			      vuint32m1_t vs1, size_t vl)
{
  return __riscv_vghsh_vs_u32m1_u32m2_tu (vd, vs2, vs1, vl);
}

/* { dg-final { scan-assembler-times {vgmul\.vv\s+v[0-9]+,\s*v[0-9]} 1 } } */
/* { dg-final { scan-assembler-times {vgmul\.vs\s+v[0-9]+,\s*v[0-9]} 2 } } */
/* { dg-final { scan-assembler-times {vghsh\.vv\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]} 1 } } */
/* { dg-final { scan-assembler-times {vghsh\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]} 2 } } */
