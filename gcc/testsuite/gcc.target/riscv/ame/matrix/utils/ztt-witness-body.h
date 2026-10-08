#include <stdint.h>
#include <riscv_ztt.h>

#define WT_VALUE __riscv_ztt_i32_rnu_1x2_t
#define WT_HALF __riscv_ztt_i32_rnu_1x1_t
#define WT_LOAD WT_VALUE p = __riscv_ztt_mls_rm_i32_rnu_1x2 (in)
#define WT_FIRST WT_VALUE q = __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (p)
#define WT_SECOND WT_VALUE r = __riscv_ztt_mcolunzip_ew_i32_rnu_1x2 (q)
#define WT_STORE __riscv_ztt_mss_rm (out, r)
#define WT_DISCARD (void) __riscv_ztt_mextract_i32_rnu_1x1 (p, 0)
#define WT_ARGS int32_t *out, const int32_t *in, int32_t *other, \
                volatile unsigned *flag, int select

#ifdef __cplusplus
extern "C" {
#endif
extern void witness_callee (void);

void witness_before (WT_ARGS)
{
  WT_LOAD;
  WT_DISCARD;
  WT_FIRST;
  WT_SECOND;
  WT_STORE;
}

void witness_between (WT_ARGS)
{
  WT_LOAD;
  WT_FIRST;
  WT_DISCARD;
  WT_SECOND;
  WT_STORE;
}

void witness_after (WT_ARGS)
{
  WT_LOAD;
  WT_FIRST;
  WT_SECOND;
  WT_DISCARD;
  WT_STORE;
}

void witness_live (WT_ARGS)
{
  WT_LOAD;
  WT_FIRST;
  WT_HALF half = __riscv_ztt_mextract_i32_rnu_1x1 (p, 0);
  WT_SECOND;
  __riscv_ztt_mss_rm (other, half);
  WT_STORE;
}

void witness_numeric (WT_ARGS)
{
  WT_LOAD;
  WT_FIRST;
  (void) __riscv_ztt_madd_ew_i32_rnu_1x2 (p, p);
  WT_SECOND;
  WT_STORE;
}

void witness_concat (WT_ARGS)
{
  WT_LOAD;
  WT_FIRST;
  (void) __riscv_ztt_mconcat_m_i32_rnu_1x4 (p, p);
  WT_SECOND;
  WT_STORE;
}

#define WT_BOUNDARY(NAME, BARRIER) \
void witness_##NAME (WT_ARGS) \
{ \
  WT_LOAD; \
  WT_DISCARD; \
  BARRIER; \
  WT_FIRST; \
  WT_SECOND; \
  WT_STORE; \
}
WT_BOUNDARY (call, witness_callee ())
WT_BOUNDARY (asm, __asm__ volatile ("" ::: "memory"))
WT_BOUNDARY (memory, *flag = 7)
WT_BOUNDARY (state, *flag = __riscv_ztt_get_amefflags ())

void witness_join (WT_ARGS)
{
  WT_LOAD;
  if (select)
    WT_DISCARD;
  WT_FIRST;
  WT_SECOND;
  WT_STORE;
}

void witness_limit (WT_ARGS)
{
  WT_LOAD;
#define WT_FOUR WT_DISCARD; WT_DISCARD; WT_DISCARD; WT_DISCARD
  WT_FOUR;
  WT_FOUR;
  WT_FOUR;
  WT_FOUR;
  WT_DISCARD;
#undef WT_FOUR
  WT_FIRST;
  WT_SECOND;
  WT_STORE;
}

#ifdef WT_RAW
void witness_raw (WT_ARGS)
{
  WT_LOAD;
  WT_DISCARD;
  __builtin_riscv_ztt_msettyp (0, 0);
  WT_FIRST;
  WT_SECOND;
  WT_STORE;
}
#endif
#ifdef __cplusplus
}
#endif
