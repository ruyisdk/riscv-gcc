#include <stdint.h>
#include <riscv_ztt.h>

#ifndef HC_TYPE
#define HC_TYPE i32_rnu
#define HC_CARRIER int32_t
#endif
#ifndef HC_PAIR
#define HC_PAIR 1x2
#define HC_HALF 1x1
#endif
#define HC_NAME_I(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define HC_NAME_X(OP, TYPE, SHAPE) HC_NAME_I (OP, TYPE, SHAPE)
#define HC_FULL(OP) HC_NAME_X (OP, HC_TYPE, HC_PAIR)
#define HC_PART(OP) HC_NAME_X (OP, HC_TYPE, HC_HALF)
#define HC_TYPE_I(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define HC_TYPE_X(TYPE, SHAPE) HC_TYPE_I (TYPE, SHAPE)
#define HC_VALUE(SHAPE) HC_TYPE_X (HC_TYPE, SHAPE)
#define HC_ARGS HC_CARRIER *out, const HC_CARRIER *in, const HC_CARRIER *second, \
                HC_CARRIER *other, volatile unsigned *flag, int select
#define HC_LOAD HC_VALUE (HC_PAIR) p = HC_FULL (mls_rm) (in)
#define HC_HALVES HC_VALUE (HC_HALF) a = HC_PART (mextract) (p, 0); \
                  HC_VALUE (HC_HALF) b = HC_PART (mextract) (p, 1)
#define HC_COPY(X) HC_PART (mcopy_m2m) (X)
#define HC_ID(X) (X)
#define HC_TWICE(X) HC_COPY (HC_COPY (X))
#define HC_COPIES HC_VALUE (HC_HALF) x = HC_COPY (a); \
                  HC_VALUE (HC_HALF) y = HC_COPY (b)
#define HC_STORE(X, Y) __riscv_ztt_mss_rm (out, HC_FULL (mconcat_m) (X, Y))

#ifdef __cplusplus
extern "C" {
#endif
extern void half_copy_callee (void);

void hc_direct (HC_ARGS)
{
  __riscv_ztt_mss_rm (out, HC_FULL (mls_rm) (in));
}

#define HC_REBUILD(NAME, LEFT, RIGHT, FIRST, SECOND) \
void hc_##NAME (HC_ARGS) \
{ \
  HC_LOAD; \
  HC_VALUE (HC_HALF) a = HC_PART (mextract) (p, FIRST); \
  HC_VALUE (HC_HALF) b = HC_PART (mextract) (p, SECOND); \
  HC_VALUE (HC_HALF) x = LEFT (a); \
  HC_VALUE (HC_HALF) y = RIGHT (b); \
  HC_STORE (x, y); \
}
HC_REBUILD (plain, HC_ID, HC_ID, 0, 1)
HC_REBUILD (left, HC_COPY, HC_ID, 0, 1)
HC_REBUILD (right, HC_ID, HC_COPY, 0, 1)
HC_REBUILD (both, HC_COPY, HC_COPY, 0, 1)
HC_REBUILD (two_left, HC_TWICE, HC_COPY, 0, 1)
HC_REBUILD (two_right, HC_COPY, HC_TWICE, 0, 1)
HC_REBUILD (reversed, HC_COPY, HC_COPY, 1, 0)
HC_REBUILD (repeated, HC_COPY, HC_COPY, 0, 0)

void hc_order (HC_ARGS)
{
  HC_LOAD;
  HC_VALUE (HC_HALF) b = HC_PART (mextract) (p, 1);
  HC_VALUE (HC_HALF) a = HC_PART (mextract) (p, 0);
  HC_COPIES;
  HC_STORE (x, y);
}

void hc_effect (HC_ARGS)
{
  HC_VALUE (HC_PAIR) p = HC_FULL (mls_rm)
    (((void) (*flag = *flag + 1), in));
  HC_HALVES;
  HC_COPIES;
  HC_STORE (x, y);
}

void hc_discarded (HC_ARGS)
{
  HC_LOAD;
  (void) HC_PART (mextract) (p, 0);
  HC_HALVES;
  HC_COPIES;
  HC_STORE (x, y);
}

void hc_mixed (HC_ARGS)
{
  HC_LOAD;
  HC_VALUE (HC_PAIR) q = HC_FULL (mls_rm) (second);
  HC_VALUE (HC_HALF) a = HC_PART (mextract) (p, 0);
  HC_VALUE (HC_HALF) b = HC_PART (mextract) (q, 1);
  HC_COPIES;
  HC_STORE (x, y);
}

#define HC_LIVE(NAME, VALUE) \
void hc_##NAME (HC_ARGS) \
{ \
  HC_LOAD; HC_HALVES; HC_COPIES; \
  HC_VALUE (HC_PAIR) q = HC_FULL (mconcat_m) (x, y); \
  __riscv_ztt_mss_rm (other, VALUE); \
  __riscv_ztt_mss_rm (out, q); \
}
HC_LIVE (live_half, a)
HC_LIVE (live_copy, x)
HC_LIVE (live_parent, p)

void hc_between_call (HC_ARGS)
{
  HC_LOAD;
  HC_VALUE (HC_HALF) a = HC_PART (mextract) (p, 0);
  half_copy_callee ();
  HC_VALUE (HC_HALF) b = HC_PART (mextract) (p, 1);
  HC_COPIES;
  HC_STORE (x, y);
}

#define HC_AFTER(NAME, BARRIER) \
void hc_##NAME (HC_ARGS) \
{ \
  HC_LOAD; HC_HALVES; HC_COPIES; \
  BARRIER; \
  HC_STORE (x, y); \
}
HC_AFTER (after_call, half_copy_callee ())
HC_AFTER (asm, __asm__ volatile ("" ::: "memory"))
HC_AFTER (memory, *flag = 7)
HC_AFTER (state, *flag = __riscv_ztt_get_amefflags ())

void hc_join (HC_ARGS)
{
  HC_LOAD;
  HC_VALUE (HC_HALF) a = HC_PART (mextract) (p, 0);
  HC_VALUE (HC_HALF) x = HC_COPY (a);
  HC_VALUE (HC_HALF) y;
  if (select)
    y = HC_COPY (HC_PART (mextract) (p, 1));
  else
    y = HC_PART (mls_rm) (second);
  HC_STORE (x, y);
}

void hc_future (HC_ARGS)
{
  HC_LOAD; HC_HALVES; HC_COPIES;
  HC_STORE (x, y);
  (void) HC_PART (mextract) (p, 0);
}

void hc_limit (HC_ARGS)
{
  HC_LOAD;
#define HC_FOUR (void) HC_PART (mextract) (p, 0); \
                (void) HC_PART (mextract) (p, 0); \
                (void) HC_PART (mextract) (p, 0); \
                (void) HC_PART (mextract) (p, 0)
  HC_FOUR; HC_FOUR; HC_FOUR; HC_FOUR;
  (void) HC_PART (mextract) (p, 0);
#undef HC_FOUR
  HC_HALVES; HC_COPIES;
  HC_STORE (x, y);
}
#ifdef __cplusplus
}
#endif
