#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void descriptor_boundary (void);
extern volatile int descriptor_condition;
#define FN __attribute__((noinline,noclone))
typedef __INT32_TYPE__ elem;

#define LOAD_PAIR(NAME, LOAD) \
FN void NAME (elem *out0, elem *out1, const elem *in0, const elem *in1, \
              unsigned long stride) \
{ \
  __riscv_ztt_i32_1x1_t a = LOAD (in0); \
  __riscv_ztt_i32_1x1_t b = LOAD (in1); \
  __riscv_ztt_mss_rm (out0, a); \
  __riscv_ztt_mss_rm (out1, b); \
}
#define RM(P) __riscv_ztt_mls_rm_i32_1x1 (P)
#define CM(P) __riscv_ztt_mls_cm_i32_1x1 (P)
#define ST(P) __riscv_ztt_mls_st_i32_1x1 (P, stride)
#define TST(P) __riscv_ztt_mls_tst_i32_1x1 (P, stride)
#ifndef DESCRIPTOR_BOUNDARIES_ONLY
LOAD_PAIR (pair_rm, RM)
LOAD_PAIR (pair_cm, CM)
LOAD_PAIR (pair_st, ST)
LOAD_PAIR (pair_tst, TST)
#endif

FN void different_rm (elem *out0, elem *out1, const elem *in0, const elem *in1)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in0);
  __riscv_ztt_i32_rne_1x1_t b = __riscv_ztt_mls_rm_i32_rne_1x1 (in1);
  __riscv_ztt_mss_rm (out0, a);
  __riscv_ztt_mss_rm (out1, b);
}

FN void different_sign (elem *out0, __UINT32_TYPE__ *out1,
                        const elem *in0, const __UINT32_TYPE__ *in1)
{
  __riscv_ztt_i32_1x1_t a = RM (in0);
  __riscv_ztt_u32_1x1_t b = __riscv_ztt_mls_rm_u32_1x1 (in1);
  __riscv_ztt_mss_rm (out0, a);
  __riscv_ztt_mss_rm (out1, b);
}

#define BOUNDARY(NAME, BETWEEN) \
FN void NAME (elem *out0, elem *out1, const elem *in0, const elem *in1) \
{ \
  __riscv_ztt_mss_rm (out0, RM (in0)); \
  BETWEEN; \
  __riscv_ztt_mss_rm (out1, RM (in1)); \
}
BOUNDARY (call_boundary, descriptor_boundary ())
BOUNDARY (asm_boundary, __asm__ volatile ("" ::: "memory"))
BOUNDARY (asm_gpr_boundary,
          __asm__ volatile ("" ::: "a0", "a1", "a2", "a3", "memory"))
BOUNDARY (join_boundary, if (descriptor_condition) descriptor_boundary ())

#ifndef DESCRIPTOR_BOUNDARIES_ONLY
FN void loop_loads (elem *out0, elem *out1, const elem *in0, const elem *in1,
                    unsigned long count)
{
  unsigned long i;
  for (i = 0; i < count; ++i)
    {
      __riscv_ztt_i32_1x1_t a = RM (in0 + i);
      __riscv_ztt_i32_1x1_t b = RM (in1 + i);
      __riscv_ztt_mss_rm (out0 + i, a);
      __riscv_ztt_mss_rm (out1 + i, b);
    }
}

FN void pressure (elem *const *out, const elem *const *in)
{
  __riscv_ztt_i32_1x1_t a = RM (in[0]);
  __riscv_ztt_i32_1x1_t b = RM (in[1]);
  __riscv_ztt_i32_1x1_t c = RM (in[2]);
  __riscv_ztt_i32_1x1_t d = RM (in[3]);
  __riscv_ztt_i32_1x1_t e = RM (in[4]);
  __riscv_ztt_i32_1x1_t f = RM (in[5]);
  __riscv_ztt_i32_1x1_t g = RM (in[6]);
  __riscv_ztt_i32_1x1_t h = RM (in[7]);
  __riscv_ztt_mss_rm (out[0], a);
  __riscv_ztt_mss_rm (out[1], b);
  __riscv_ztt_mss_rm (out[2], c);
  __riscv_ztt_mss_rm (out[3], d);
  __riscv_ztt_mss_rm (out[4], e);
  __riscv_ztt_mss_rm (out[5], f);
  __riscv_ztt_mss_rm (out[6], g);
  __riscv_ztt_mss_rm (out[7], h);
}
#endif

#ifdef __cplusplus
}
#endif
