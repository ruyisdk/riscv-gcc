#include <stdint.h>
#include <riscv_ztt.h>

#ifndef RB_TYPE
#define RB_TYPE i32_rnu
#define RB_CARRIER int32_t
#define RB_HALF 1x1
#define RB_PAIR 1x2
#define RB_COLUMN 2x1
#endif
#define RB_NAME_I(OP, TYPE, SHAPE) __riscv_ztt_##OP##_##TYPE##_##SHAPE
#define RB_NAME_X(OP, TYPE, SHAPE) RB_NAME_I (OP, TYPE, SHAPE)
#define RB_NAME(OP, SHAPE) RB_NAME_X (OP, RB_TYPE, SHAPE)
#define RB_TYPE_I(TYPE, SHAPE) __riscv_ztt_##TYPE##_##SHAPE##_t
#define RB_TYPE_X(TYPE, SHAPE) RB_TYPE_I (TYPE, SHAPE)
#define RB_VALUE(SHAPE) RB_TYPE_X (RB_TYPE, SHAPE)
#define RB_ARGS RB_CARRIER *out, const RB_CARRIER *a, const RB_CARRIER *b, \
                RB_CARRIER *other, volatile unsigned *flag, int select
#define RB_LOAD RB_VALUE (RB_PAIR) p = RB_NAME (mls_rm, RB_PAIR) (a)
#define RB_HALVES \
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0); \
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (p, 1)
#define RB_STORE(X, Y) \
  __riscv_ztt_mss_rm (out, RB_NAME (mconcat_m, RB_PAIR) (X, Y))

#ifdef __cplusplus
extern "C" {
#endif
extern void rebuild_callee (void);

void rebuild_row (RB_ARGS)
{
  RB_LOAD;
  RB_HALVES;
  RB_STORE (x, y);
}

void rebuild_order (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (p, 1);
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  RB_STORE (x, y);
}

#ifdef RB_COLUMN
void rebuild_column (RB_ARGS)
{
  RB_VALUE (RB_COLUMN) p = RB_NAME (mls_rm, RB_COLUMN) (a);
  RB_HALVES;
  __riscv_ztt_mss_rm (out, RB_NAME (mconcat_m, RB_COLUMN) (x, y));
}
#endif

void rebuild_reverse (RB_ARGS)
{
  RB_LOAD;
  RB_HALVES;
  RB_STORE (y, x);
}

void rebuild_duplicate (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (p, 0);
  RB_STORE (x, y);
}

void rebuild_mixed (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_PAIR) q = RB_NAME (mls_rm, RB_PAIR) (b);
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (q, 1);
  RB_STORE (x, y);
}

void rebuild_live_half (RB_ARGS)
{
  RB_LOAD;
  RB_HALVES;
  RB_VALUE (RB_PAIR) q = RB_NAME (mconcat_m, RB_PAIR) (x, y);
  __riscv_ztt_mss_rm (other, x);
  __riscv_ztt_mss_rm (out, q);
}

void rebuild_live_parent (RB_ARGS)
{
  RB_LOAD;
  RB_HALVES;
  RB_VALUE (RB_PAIR) q = RB_NAME (mconcat_m, RB_PAIR) (x, y);
  __riscv_ztt_mss_rm (other, p);
  __riscv_ztt_mss_rm (out, q);
}

void rebuild_call (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  rebuild_callee ();
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (p, 1);
  RB_STORE (x, y);
}

void rebuild_asm (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  __asm__ volatile ("" ::: "memory");
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (p, 1);
  RB_STORE (x, y);
}

void rebuild_volatile (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  *flag = 7;
  RB_VALUE (RB_HALF) y = RB_NAME (mextract, RB_HALF) (p, 1);
  RB_STORE (x, y);
}

void rebuild_join (RB_ARGS)
{
  RB_LOAD;
  RB_VALUE (RB_HALF) x = RB_NAME (mextract, RB_HALF) (p, 0);
  RB_VALUE (RB_HALF) y;
  if (select)
    y = RB_NAME (mextract, RB_HALF) (p, 1);
  else
    y = RB_NAME (mls_rm, RB_HALF) (b);
  RB_STORE (x, y);
}

void rebuild_effect (RB_ARGS)
{
  RB_VALUE (RB_PAIR) p = RB_NAME (mls_rm, RB_PAIR)
    (((void) (*flag = *flag + 1), a));
  RB_HALVES;
  RB_STORE (x, y);
}

#ifdef __cplusplus
}
#endif
