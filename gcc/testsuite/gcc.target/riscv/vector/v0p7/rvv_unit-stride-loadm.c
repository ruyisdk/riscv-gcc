/* { dg-do compile } */
/* { dg-skip-if "test v0p7" { *-*-* } { "*" } { "-march=rv*v0p7*" } } */

#include <riscv_vector.h>
#include <stddef.h>
#include "../rvv-common.h"
#include "rvv-common.h"

/* Takes the scalar type STYPE, vector class VCLASS (int or float), and
   the e and m value.  */
#define VSLOADSTORE(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW, LOP, SOP)                                   \
  void vsloadstore##VCLASS##EM##LOP(size_t n, long stride, STYPE *x,                \
                               STYPE *y, STYPE z, word_type vl) {                            \
    v##VCLASST##EM##_t vx, vy, vz;                                           \
    vbool##MLEN##_t mask;                                                   \
    vx = VLOADM(LOP, VCLASS, SEW, EM, x);                                               \
    vy = VLOADM(LOP, VCLASS, SEW, EM, y);                                               \
    vz = vadd_vv_##VCLASS##EM (vx, vy, vl);                                                              \
    VSTOREM(SOP, VCLASS, SEW, EM, x, vz);                                                \
  }

RVV_INT8_TEST_ARG(VSLOADSTORE, b, b)
RVV_INT16_TEST_ARG(VSLOADSTORE, h, h)
RVV_INT32_TEST_ARG(VSLOADSTORE, w, w)

RVV_UINT8_TEST_ARG(VSLOADSTORE, bu, b)
RVV_UINT16_TEST_ARG(VSLOADSTORE, hu, h)
RVV_UINT32_TEST_ARG(VSLOADSTORE, wu, w)

/* { dg-final { scan-assembler-times "vlb.v" 32 } } */
/* { dg-final { scan-assembler-times "vsb.v" 32 } } */
/* { dg-final { scan-assembler-times "vlh.v" 24 } } */
/* { dg-final { scan-assembler-times "vsh.v" 24 } } */
/* { dg-final { scan-assembler-times "vlw.v" 16 } } */
/* { dg-final { scan-assembler-times "vsw.v" 16 } } */

/* { dg-final { scan-assembler-times "vlbu.v" 32 } } */
/* { dg-final { scan-assembler-times "vlhu.v" 24 } } */
/* { dg-final { scan-assembler-times "vlwu.v" 16 } } */
