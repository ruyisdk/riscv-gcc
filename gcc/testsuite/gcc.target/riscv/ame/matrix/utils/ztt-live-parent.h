#include <stdint.h>
#include <riscv_ztt.h>

#ifndef LIVE_TYPE
#define LIVE_TYPE i32_rnu
#define LIVE_CARRIER int32_t
#endif
#define LP_NAME_I(OP, SHAPE, TYPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define LP_NAME_X(OP, SHAPE, TYPE) LP_NAME_I (OP, SHAPE, TYPE)
#define LP(OP, SHAPE) LP_NAME_X (OP, SHAPE, LIVE_TYPE)
#define LP_TYPE_I(SHAPE, TYPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define LP_TYPE_X(SHAPE, TYPE) LP_TYPE_I (SHAPE, TYPE)
#define LP_TYPE(SHAPE) LP_TYPE_X (SHAPE, LIVE_TYPE)
#define LP_ARGS const LIVE_CARRIER *in, LIVE_CARRIER *out, \
                LIVE_CARRIER *other, unsigned stride, int select
#define LP_LOAD LP_TYPE (1x2) p = LP (mls_rm, 1x2) (in)
#define LP_HALVES \
  LP_TYPE (1x1) a = LP (mextract, 1x1) (p, 0); \
  LP_TYPE (1x1) b = LP (mextract, 1x1) (p, 1)
#define LP_PAIR LP_TYPE (1x2) q = LP (mconcat_m, 1x2) (a, b)
#define LP_STORE __riscv_ztt_mss_rm (out, q)
#define LP_FN(NAME) __attribute__((noipa)) void NAME (LP_ARGS)

#ifdef __cplusplus
extern "C" {
#endif
extern void live_parent_callee (void);

LP_FN (rebuild_out_first)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP_STORE;
  __riscv_ztt_mss_rm (other, p);
}

LP_FN (inverse_two_stores)
{
  LP_LOAD;
  LP_TYPE (1x2) middle = LP (mrowzip_ew, 1x2) (p);
  LP_TYPE (1x2) q = LP (mrowunzip_ew, 1x2) (middle);
  __riscv_ztt_mss_rm (other, p);
  LP_STORE;
  __riscv_ztt_mss_rm (other, p);
}

LP_FN (rebuild_column_store)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP_STORE;
  __riscv_ztt_mss_cm (other, p);
}

LP_FN (rebuild_strided_store)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP_STORE;
  __riscv_ztt_mss_st (other, stride, p);
}

LP_FN (parent_before)
{
  LP_LOAD; LP_HALVES;
  __riscv_ztt_mss_rm (other, p);
  LP_PAIR; LP_STORE;
}

LP_FN (parent_after_call)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP_STORE;
  live_parent_callee ();
  __riscv_ztt_mss_rm (other, p);
}

LP_FN (parent_after_branch)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP_STORE;
  if (select)
    __riscv_ztt_mss_rm (other, p);
}

LP_FN (parent_far)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP_STORE; LP_STORE; LP_STORE; LP_STORE;
  LP_STORE; LP_STORE; LP_STORE; LP_STORE;
  LP_STORE; LP_STORE; LP_STORE; LP_STORE;
  LP_STORE; LP_STORE; LP_STORE; LP_STORE;
  __riscv_ztt_mss_rm (other, p);
}

LP_FN (parent_future_witness)
{
  LP_LOAD; LP_HALVES; LP_PAIR;
  LP (mcopy_m2m, 1x2) (p);
  LP_STORE;
}

LP_FN (parent_asm)
{
  LP_LOAD; LP_HALVES;
  __asm__ volatile ("" ::: "memory");
  LP_PAIR; LP_STORE;
  __riscv_ztt_mss_rm (other, p);
}
#ifdef __cplusplus
}
#endif
