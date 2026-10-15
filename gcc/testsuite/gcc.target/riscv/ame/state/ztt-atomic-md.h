#include <riscv_ztt.h>

typedef unsigned long element;
#if __riscv_xlen == 64
typedef __riscv_ztt_u64_rnu_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_u64_rnu_1x1
#define ADD __riscv_ztt_madd_ew_u64_rnu_1x1
#else
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_u32_rnu_1x1
#define ADD __riscv_ztt_madd_ew_u32_rnu_1x1
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern void atomic_callee (void);
#define CHAIN(NAME, EXPR, BOUNDARY) \
__attribute__((noipa)) void atomic_##NAME \
  (const element *in, element *work, element *out, element *result, element arg) \
{ \
  matrix a = LOAD (in); \
  __riscv_ztt_mss_rm (work, a); \
  element expected = arg; \
  result[0] = (EXPR); \
  result[1] = expected; \
  BOUNDARY; \
  matrix b = LOAD (work); \
  __riscv_ztt_mss_rm (out, ADD (a, b)); \
}
CHAIN (add_relaxed, __atomic_fetch_add (work, arg, __ATOMIC_RELAXED), (void) 0)
CHAIN (add_acquire, __atomic_fetch_add (work, arg, __ATOMIC_ACQUIRE), (void) 0)
CHAIN (add_release, __atomic_fetch_add (work, arg, __ATOMIC_RELEASE), (void) 0)
CHAIN (add_seq, __atomic_fetch_add (work, arg, __ATOMIC_SEQ_CST), (void) 0)
CHAIN (and, __atomic_fetch_and (work, arg, __ATOMIC_SEQ_CST), (void) 0)
CHAIN (or, __atomic_fetch_or (work, arg, __ATOMIC_SEQ_CST), (void) 0)
CHAIN (xor, __atomic_fetch_xor (work, arg, __ATOMIC_SEQ_CST), (void) 0)
CHAIN (exchange, __atomic_exchange_n (work, arg, __ATOMIC_ACQ_REL), (void) 0)
CHAIN (load, __atomic_load_n (work, __ATOMIC_ACQUIRE), (void) 0)
CHAIN (store, (__atomic_store_n (work, arg, __ATOMIC_RELEASE), arg), (void) 0)
CHAIN (cas, __atomic_compare_exchange_n (work, &expected, (element) 5, 0,
                                       __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE), (void) 0)
CHAIN (byte_add, __atomic_fetch_add ((unsigned char *) work, (unsigned char) arg,
                                    __ATOMIC_SEQ_CST), (void) 0)
CHAIN (half_exchange, __atomic_exchange_n ((unsigned short *) work, (unsigned short) arg,
                                          __ATOMIC_SEQ_CST), (void) 0)
CHAIN (barrier, __atomic_fetch_add (work, arg, __ATOMIC_SEQ_CST),
       __asm__ volatile ("# boundary" ::: "memory"))
CHAIN (call, __atomic_fetch_add (work, arg, __ATOMIC_SEQ_CST), atomic_callee ())
CHAIN (plain, work[0], (void) 0)
#undef CHAIN
#ifdef __cplusplus
}
#endif
#undef LOAD
#undef ADD
