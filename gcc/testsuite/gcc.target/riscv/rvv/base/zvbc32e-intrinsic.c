/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvbc32e -mabi=lp64d -O2" } */

#include "riscv_vector.h"

vuint8m1_t
test_vclmul_vv_u8m1 (vuint8m1_t vs2, vuint8m1_t vs1, size_t vl)
{
  return __riscv_vclmul_vv_u8m1 (vs2, vs1, vl);
}

vuint8m1_t
test_vclmul_vx_u8m1 (vuint8m1_t vs2, uint8_t rs1, size_t vl)
{
  return __riscv_vclmul_vx_u8m1 (vs2, rs1, vl);
}

vuint16m2_t
test_vclmulh_vv_u16m2 (vuint16m2_t vs2, vuint16m2_t vs1, size_t vl)
{
  return __riscv_vclmulh_vv_u16m2 (vs2, vs1, vl);
}

vuint16m2_t
test_vclmulh_vx_u16m2 (vuint16m2_t vs2, uint16_t rs1, size_t vl)
{
  return __riscv_vclmulh_vx_u16m2 (vs2, rs1, vl);
}

vuint32m4_t
test_vclmul_vv_u32m4 (vuint32m4_t vs2, vuint32m4_t vs1, size_t vl)
{
  return __riscv_vclmul_vv_u32m4 (vs2, vs1, vl);
}

vuint32m4_t
test_vclmulh_vx_u32m4 (vuint32m4_t vs2, uint32_t rs1, size_t vl)
{
  return __riscv_vclmulh_vx_u32m4 (vs2, rs1, vl);
}

/* { dg-final { scan-assembler-times {vclmul\.vv\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]} 2 } } */
/* { dg-final { scan-assembler-times {vclmul\.vx\s+v[0-9]+,\s*v[0-9]+,\s*a[0-9]} 1 } } */
/* { dg-final { scan-assembler-times {vclmulh\.vv\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]} 1 } } */
/* { dg-final { scan-assembler-times {vclmulh\.vx\s+v[0-9]+,\s*v[0-9]+,\s*a[0-9]} 2 } } */
