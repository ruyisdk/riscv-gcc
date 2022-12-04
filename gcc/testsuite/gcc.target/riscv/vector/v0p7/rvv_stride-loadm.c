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
    vx = vls##LOP##_v_##VCLASS##EM(x, stride, vl);                                      \
    vy = VLOAD(VCLASS, SEW, EM, y);                                               \
    vz = vadd_vv_##VCLASS##EM (vx, vy, vl);                                                              \
    vss##SOP##_v_##VCLASS##EM(x, stride, vz, vl);                                                \
  }

RVV_INT8_TEST_ARG(VSLOADSTORE, b, b)
RVV_INT16_TEST_ARG(VSLOADSTORE, h, h)
RVV_INT32_TEST_ARG(VSLOADSTORE, w, w)

RVV_UINT8_TEST_ARG(VSLOADSTORE, bu, b)
RVV_UINT16_TEST_ARG(VSLOADSTORE, hu, h)
RVV_UINT32_TEST_ARG(VSLOADSTORE, wu, w)

/* { dg-final { scan-assembler-times "vlsb.v" 16 } } */
/* { dg-final { scan-assembler-times "vssb.v" 32 } } */
/* { dg-final { scan-assembler-times "vlsh.v" 12 } } */
/* { dg-final { scan-assembler-times "vssh.v" 24 } } */
/* { dg-final { scan-assembler-times "vlsw.v" 8 } } */
/* { dg-final { scan-assembler-times "vssw.v" 16 } } */

/* { dg-final { scan-assembler-times "vlsbu.v" 16 } } */
/* { dg-final { scan-assembler-times "vlshu.v" 12 } } */
/* { dg-final { scan-assembler-times "vlswu.v" 8 } } */
