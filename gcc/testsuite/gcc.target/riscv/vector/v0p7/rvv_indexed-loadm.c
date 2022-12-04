/* { dg-do compile } */
/* { dg-skip-if "test v0p7" { *-*-* } { "*" } { "-march=rv*v0p7*" } } */

#include <riscv_vector.h>
#include <stddef.h>
#include "../rvv-common.h"
#include "rvv-common.h"

/* Takes the scalar type STYPE, vector class VCLASS (int or float), and
   the e and m value.  */
#define VSLOADSTORE(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW, LOP, SOP)                                   \
  void vsloadstore##VCLASS##EM##LOP(size_t n, vuint##EM##_t index, STYPE *x,                \
                               STYPE *y, STYPE z, word_type vl) {                            \
    v##VCLASST##EM##_t vx, vy, vz;                                           \
    vbool##MLEN##_t mask;                                                   \
    vx = vlx##LOP##_v_##VCLASS##EM(x, index, vl);                                      \
    vy = VLOAD(VCLASS, SEW, EM, y);                                               \
    vz = vadd_vv_##VCLASS##EM (vx, vy, vl);                                                              \
    vsx##SOP##_v_##VCLASS##EM(x, index, vz, vl);                                                \
    vsux##SOP##_v_##VCLASS##EM(y, index, vz, vl);                                                \
  }

RVV_INT8_TEST_ARG(VSLOADSTORE, b, b)
RVV_INT16_TEST_ARG(VSLOADSTORE, h, h)
RVV_INT32_TEST_ARG(VSLOADSTORE, w, w)

RVV_UINT8_TEST_ARG(VSLOADSTORE, bu, b)
RVV_UINT16_TEST_ARG(VSLOADSTORE, hu, h)
RVV_UINT32_TEST_ARG(VSLOADSTORE, wu, w)

/* { dg-final { scan-assembler-times "vlxb.v" 16 } } */
/* { dg-final { scan-assembler-times "vsxb.v" 32 } } */
/* { dg-final { scan-assembler-times "vlxh.v" 12 } } */
/* { dg-final { scan-assembler-times "vsxh.v" 24 } } */
/* { dg-final { scan-assembler-times "vlxw.v" 8 } } */
/* { dg-final { scan-assembler-times "vsxw.v" 16 } } */

/* { dg-final { scan-assembler-times "vlxbu.v" 16 } } */
/* { dg-final { scan-assembler-times "vlxhu.v" 12 } } */
/* { dg-final { scan-assembler-times "vlxwu.v" 8 } } */

/* { dg-final { scan-assembler-times "vsuxb.v" 32 } } */
/* { dg-final { scan-assembler-times "vsuxh.v" 24 } } */
/* { dg-final { scan-assembler-times "vsuxw.v" 16 } } */
