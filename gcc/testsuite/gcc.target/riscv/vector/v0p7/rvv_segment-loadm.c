/* { dg-do compile } */
/* { dg-skip-if "test v0p7" { *-*-* } { "*" } { "-march=rv*v0p7*" } } */

#include <riscv_vector.h>
#include <stddef.h>
#include "../rvv-common.h"

#define VLOADSTORE_NF2(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, a, vl);					\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v1, *v0, vl);					\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, a, s, vl);					\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v1, *v0, vl);					\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, a, idx, vl);					\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v1, *v0, vl);				\
  }

_RVV_INT_TUPLE_NF2_ITERATOR_ARG(VLOADSTORE_NF2, i, int, b)
_RVV_INT_TUPLE_NF2_ITERATOR_LDST16_ARG(VLOADSTORE_NF2, i, int, h)
_RVV_INT_TUPLE_NF2_ITERATOR_LDST32_ARG(VLOADSTORE_NF2, i, int, w)

#define VLOADSTORE_NF3(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 v##S##SEW##m##LMUL##_t *v2,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, a, vl);					\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v2, *v1, *v0, vl);				\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, a, s, vl);				\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v2, *v1, *v0, vl);				\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, a, idx, vl);				\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v2, *v1, *v0, vl);				\
  }

_RVV_INT_TUPLE_NF3_ITERATOR_ARG(VLOADSTORE_NF3, i, int, b)
_RVV_INT_TUPLE_NF3_ITERATOR_LDST16_ARG(VLOADSTORE_NF3, i, int, h)
_RVV_INT_TUPLE_NF3_ITERATOR_LDST32_ARG(VLOADSTORE_NF3, i, int, w)

#define VLOADSTORE_NF4(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 v##S##SEW##m##LMUL##_t *v2,			\
						 v##S##SEW##m##LMUL##_t *v3,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, a, vl);				\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v3, *v2, *v1, *v0, vl);				\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, a, s, vl);				\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v3, *v2, *v1, *v0, vl);			\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, a, idx, vl);				\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v3, *v2, *v1, *v0, vl);			\
  }

_RVV_INT_TUPLE_NF4_ITERATOR_ARG(VLOADSTORE_NF4, i, int, b)
_RVV_INT_TUPLE_NF4_ITERATOR_LDST16_ARG(VLOADSTORE_NF4, i, int, h)
_RVV_INT_TUPLE_NF4_ITERATOR_LDST32_ARG(VLOADSTORE_NF4, i, int, w)

#define VLOADSTORE_NF5(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 v##S##SEW##m##LMUL##_t *v2,			\
						 v##S##SEW##m##LMUL##_t *v3,			\
						 v##S##SEW##m##LMUL##_t *v4,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, a, vl);				\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v4, *v3, *v2, *v1, *v0, vl);			\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, a, s, vl);			\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v4, *v3, *v2, *v1, *v0, vl);			\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, a, idx, vl);			\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v4, *v3, *v2, *v1, *v0, vl);		\
  }

_RVV_INT_TUPLE_NF5_ITERATOR_ARG(VLOADSTORE_NF5, i, int, b)
_RVV_INT_TUPLE_NF5_ITERATOR_LDST16_ARG(VLOADSTORE_NF5, i, int, h)
_RVV_INT_TUPLE_NF5_ITERATOR_LDST32_ARG(VLOADSTORE_NF5, i, int, w)

#define VLOADSTORE_NF6(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 v##S##SEW##m##LMUL##_t *v2,			\
						 v##S##SEW##m##LMUL##_t *v3,			\
						 v##S##SEW##m##LMUL##_t *v4,			\
						 v##S##SEW##m##LMUL##_t *v5,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, a, vl);			\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v5, *v4, *v3, *v2, *v1, *v0, vl);			\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, a, s, vl);			\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v5, *v4, *v3, *v2, *v1, *v0, vl);		\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, a, idx, vl);			\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v5, *v4, *v3, *v2, *v1, *v0, vl);		\
  }

_RVV_INT_TUPLE_NF6_ITERATOR_ARG(VLOADSTORE_NF6, i, int, b)
_RVV_INT_TUPLE_NF6_ITERATOR_LDST16_ARG(VLOADSTORE_NF6, i, int, h)
_RVV_INT_TUPLE_NF6_ITERATOR_LDST32_ARG(VLOADSTORE_NF6, i, int, w)

#define VLOADSTORE_NF7(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 v##S##SEW##m##LMUL##_t *v2,			\
						 v##S##SEW##m##LMUL##_t *v3,			\
						 v##S##SEW##m##LMUL##_t *v4,			\
						 v##S##SEW##m##LMUL##_t *v5,			\
						 v##S##SEW##m##LMUL##_t *v6,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, v6, a, vl);			\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v6, *v5, *v4, *v3, *v2, *v1, *v0, vl);		\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, v6, a, s, vl);		\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v6, *v5, *v4, *v3, *v2, *v1, *v0, vl);	\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, v6, a, idx, vl);		\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v6, *v5, *v4, *v3, *v2, *v1, *v0, vl);	\
  }

_RVV_INT_TUPLE_NF7_ITERATOR_ARG(VLOADSTORE_NF7, i, int, b)
_RVV_INT_TUPLE_NF7_ITERATOR_LDST16_ARG(VLOADSTORE_NF7, i, int, h)
_RVV_INT_TUPLE_NF7_ITERATOR_LDST32_ARG(VLOADSTORE_NF7, i, int, w)

#define VLOADSTORE_NF8(SEW, LMUL, NF, MLEN, T, SN, S, OP)					\
  void vloadstore##NF##OP##_v_##SN##SEW##m##LMUL(v##S##SEW##m##LMUL##_t *v0,			\
						 v##S##SEW##m##LMUL##_t *v1,			\
						 v##S##SEW##m##LMUL##_t *v2,			\
						 v##S##SEW##m##LMUL##_t *v3,			\
						 v##S##SEW##m##LMUL##_t *v4,			\
						 v##S##SEW##m##LMUL##_t *v5,			\
						 v##S##SEW##m##LMUL##_t *v6,			\
						 v##S##SEW##m##LMUL##_t *v7,			\
						 S##SEW##_t *a, ptrdiff_t s,			\
						 vu##S##SEW##m##LMUL##_t idx, word_type vl) {	\
    vlseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, v6, v7, a, vl);		\
    vsseg##NF##OP##_v_##SN##SEW##m##LMUL (a, *v7, *v6, *v5, *v4, *v3, *v2, *v1, *v0, vl);	\
    vlsseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, v6, v7, a, s, vl);		\
    vssseg##NF##OP##_v_##SN##SEW##m##LMUL (a, s, *v7, *v6, *v5, *v4, *v3, *v2, *v1, *v0, vl);	\
    vlxseg##NF##OP##_v_##SN##SEW##m##LMUL (v0, v1, v2, v3, v4, v5, v6, v7, a, idx, vl);		\
    vsxseg##NF##OP##_v_##SN##SEW##m##LMUL (a, idx, *v7, *v6, *v5, *v4, *v3, *v2, *v1, *v0, vl);	\
  }

_RVV_INT_TUPLE_NF8_ITERATOR_ARG(VLOADSTORE_NF8, i, int, b)
_RVV_INT_TUPLE_NF8_ITERATOR_LDST16_ARG(VLOADSTORE_NF8, i, int, h)
_RVV_INT_TUPLE_NF8_ITERATOR_LDST32_ARG(VLOADSTORE_NF8, i, int, w)

/* { dg-final { scan-assembler-times "vlseg\[2-8\]b" 44 } } */
/* { dg-final { scan-assembler-times "vsseg\[2-8\]b" 44 } } */
/* { dg-final { scan-assembler-times "vlsseg\[2-8\]b" 44 } } */
/* { dg-final { scan-assembler-times "vssseg\[2-8\]b" 44 } } */
/* { dg-final { scan-assembler-times "vlxseg\[2-8\]b" 44 } } */
/* { dg-final { scan-assembler-times "vsxseg\[2-8\]b" 44 } } */

/* { dg-final { scan-assembler-times "vlseg\[2-8\]h" 33 } } */
/* { dg-final { scan-assembler-times "vsseg\[2-8\]h" 33 } } */
/* { dg-final { scan-assembler-times "vlsseg\[2-8\]h" 33 } } */
/* { dg-final { scan-assembler-times "vssseg\[2-8\]h" 33 } } */
/* { dg-final { scan-assembler-times "vlxseg\[2-8\]h" 33 } } */
/* { dg-final { scan-assembler-times "vsxseg\[2-8\]h" 33 } } */

/* { dg-final { scan-assembler-times "vlseg\[2-8\]w" 22 } } */
/* { dg-final { scan-assembler-times "vsseg\[2-8\]w" 22 } } */
/* { dg-final { scan-assembler-times "vlsseg\[2-8\]w" 22 } } */
/* { dg-final { scan-assembler-times "vssseg\[2-8\]w" 22 } } */
/* { dg-final { scan-assembler-times "vlxseg\[2-8\]w" 22 } } */
/* { dg-final { scan-assembler-times "vsxseg\[2-8\]w" 22 } } */
