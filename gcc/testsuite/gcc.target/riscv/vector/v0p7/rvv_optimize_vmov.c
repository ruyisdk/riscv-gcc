/* { dg-do compile } */
/* { dg-skip-if "test v0p7" { *-*-* } { "*" } { "-march=rv*v0p7*" } } */

#include <riscv_vector.h>
#include <stddef.h>

void func (uint16_t *src1, uint16_t *src2, uint8_t *dst, int32_t len, uint16_t *px_ofs, uint8_t *px_alpha)
{
  uint8_t cbufy[2];
  size_t l = vsetvl_e16m4(len);
  vuint16m4_t sx = vundefined_u16m4();
  sx = vle16_v_u16m4(px_ofs, l);

  vuint8m2_t data0 = vundefined_u8m2();
  vuint8m2_t data2 = vundefined_u8m2();
  vuint16m4_t data0t = vundefined_u16m4();
  vuint16m4_t data2t = vundefined_u16m4();
  vlxseg2bu_v_u16m4(&data0t, &data2t, src1, sx, l);
  data0 = vnclipu_wx_u8m2(data0t, 0, l);
  data2 = vnclipu_wx_u8m2(data2t, 0, l);
  vuint8m2_t data1 = vundefined_u8m2();
  vuint8m2_t data3 = vundefined_u8m2();
  vuint16m4_t data1t = vundefined_u16m4();
  vuint16m4_t data3t = vundefined_u16m4();
  vlxseg2bu_v_u16m4(&data1t, &data3t, src2, sx, l);
  data1 = vnclipu_wx_u8m2(data1t, 0, l);
  data3 = vnclipu_wx_u8m2(data3t, 0, l);

  vuint8m2_t cbufx0 = vundefined_u8m2();
  vuint8m2_t cbufx1 = vundefined_u8m2();
  vlseg2e8_v_u8m2(&cbufx0, &cbufx1, px_alpha, l);
  vuint16m4_t tmp_u16_0 = vundefined_u16m4();
  tmp_u16_0 = vwmulu_vv_u16m4(data0, cbufx0, l);
  vuint16m4_t tmp_u16_1 = vundefined_u16m4();
  tmp_u16_1 = vwmulu_vv_u16m4(data1, cbufx0, l);
  vuint16m4_t tmp_u16_2 = vundefined_u16m4();
  tmp_u16_2 = vwmulu_vv_u16m4(data2, cbufx1, l);
  vuint16m4_t tmp_u16_3 = vundefined_u16m4();
  tmp_u16_3 = vwmulu_vv_u16m4(data3, cbufx1, l);

  vuint32m8_t res = vundefined_u32m8();
  res = vwmulu_vx_u32m8(tmp_u16_0, (uint16_t)cbufy[0], l);
  res = vwmaccu_vx_u32m8(res, (uint16_t)cbufy[1], tmp_u16_1, l);
  res = vwmaccu_vx_u32m8(res, (uint16_t)cbufy[0], tmp_u16_2, l);
  res = vwmaccu_vx_u32m8(res, (uint16_t)cbufy[1], tmp_u16_3, l);

  data0 = vnclipu_wx_u8m2(vnclipu_wx_u16m4((res), 14, l), 0, l);
  vse8_v_u8m2(dst, data0, l);
}

/* { dg-final { scan-assembler-times "vmv.v.v" 0 } } */
