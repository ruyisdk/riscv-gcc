/* { dg-do compile } */
/* { dg-skip-if "test rvv optimize" { *-*-* } { "*" } { "-march=rv*v*" } } */

#include <riscv_vector.h>

vuint16m1_t
v_popcount(vuint8m1_t a, int nlanes)
{
  vuint8m2_t tmp;
  vuint8m2_t index;
  tmp = vset_v_u8m1_u8m2(tmp, 0, a);

  vuint8m1_t index1 = vid_v_u8m1(nlanes);
  index1 = vsll_vx_u8m1(index1, 1, nlanes);
  vuint8m1_t index2 = vadd_vx_u8m1(index1, 1, nlanes);
  index = vset_v_u8m1_u8m2(index, 0, index1);
  index = vset_v_u8m1_u8m2(index, 1, index2);

  tmp = vrgather_vv_u8m2(tmp, index, nlanes << 2);
  vuint16m2_t res;
  res = vwaddu_vv_u16m2(vget_v_u8m2_u8m1(tmp, 0), vget_v_u8m2_u8m1(tmp, 1), nlanes);
  return vget_v_u16m2_u16m1(res, 0);
}

/* { dg-final { scan-assembler-times "vmv.v.x\tv\[0-9\]," 0} } */
