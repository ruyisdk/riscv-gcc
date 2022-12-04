/* { dg-do compile } */
/* { dg-skip-if "test v0p7" { *-*-* } { "*" } { "-march=rv*v0p7*" } } */

#include <riscv_vector.h>
#include <stddef.h>
#include "../rvv-common.h"
#include "rvv-common.h"

#define RVV_TEST_EXT_XV(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW, X)\
  STYPE test_ext_xv##VCLASS##EM (STYPE *x, unsigned idx, word_type vl) {			\
    v##VCLASST##EM##_t vx;					\
    vx = VLOAD(VCLASS, SEW, EM, x);				\
    return vext_x_v_##VCLASS##EM##_##VCLASS##SEW (vx, idx, vl);			\
  }

RVV_INT8_TEST_ARG (RVV_TEST_EXT_XV,)
RVV_UINT8_TEST_ARG (RVV_TEST_EXT_XV,)

/* { dg-final { scan-assembler-times "vext.x.v" 32 } } */
