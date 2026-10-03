#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void prepared_store_callee (void);
extern volatile int prepared_store_condition;
typedef __INT32_TYPE__ prepared_element;

#define PREPARED_COPY(NAME, LOAD, STORE) \
__attribute__((noinline, noclone)) \
void NAME (const prepared_element *in, prepared_element *out, \
           unsigned long stride) \
{ \
  __riscv_ztt_i32_1x1_t a = LOAD; \
  STORE; \
}
PREPARED_COPY (prepared_rm, __riscv_ztt_mls_rm_i32_1x1 (in),
              __riscv_ztt_mss_rm (out, a))
PREPARED_COPY (prepared_cm, __riscv_ztt_mls_cm_i32_1x1 (in),
              __riscv_ztt_mss_cm (out, a))
PREPARED_COPY (prepared_st, __riscv_ztt_mls_st_i32_1x1 (in, stride),
              __riscv_ztt_mss_st (out, stride, a))
PREPARED_COPY (prepared_tst, __riscv_ztt_mls_tst_i32_1x1 (in, stride),
              __riscv_ztt_mss_tst (out, stride, a))
#undef PREPARED_COPY

void prepared_twice (const prepared_element *in, prepared_element *out,
                     prepared_element *other)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, a);
}

void prepared_zero (prepared_element *out)
{
  __riscv_ztt_mss_rm (out, __riscv_ztt_mzero_m_i32_1x1 ());
}

#define PREPARED_BARRIER(NAME, BARRIER) \
void NAME (const prepared_element *in, prepared_element *out) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  BARRIER; \
  __riscv_ztt_mss_rm (out, a); \
}
PREPARED_BARRIER (prepared_asm, __asm__ volatile ("" ::: "memory"))
PREPARED_BARRIER (prepared_call, prepared_store_callee ())
PREPARED_BARRIER (prepared_join,
                 if (prepared_store_condition)
                   __asm__ volatile ("" ::: "memory"))
#undef PREPARED_BARRIER
#ifdef __cplusplus
}
#endif
