/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvkg -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vuint32m1_t
test_vgmul_vs (vuint32m1_t vd, vuint32m1_t vs2, size_t vl)
{
  return __riscv_vgmul_vs_u32m1_u32m1 (vd, vs2, vl); /* { dg-error {built-in function '__riscv_vgmul_vs_u32m1_u32m1\(vd,  vs2,  vl\)' requires the 'zvkgs' ISA extension} } */
}

vuint32m1_t
test_vghsh_vs (vuint32m1_t vd, vuint32m1_t vs2, vuint32m1_t vs1, size_t vl)
{
  return __riscv_vghsh_vs_u32m1_u32m1 (vd, vs2, vs1, vl); /* { dg-error {built-in function '__riscv_vghsh_vs_u32m1_u32m1\(vd,  vs2,  vs1,  vl\)' requires the 'zvkgs' ISA extension} } */
}
