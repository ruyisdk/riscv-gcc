#include <riscv_ztt.h>
typedef __INT32_TYPE__ element;
typedef __riscv_ztt_i32_rnu_1x1_t matrix;
#ifdef __cplusplus
extern "C" {
#endif
extern void fence_callee (void);

#define TEST(NAME, BARRIER) \
void fence_##NAME (const element *in, element *out, unsigned flag) \
{ \
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  BARRIER; \
  a = __riscv_ztt_madd_ew_i32_1x1 (a, a); \
  __riscv_ztt_mss_rm (out, a); \
}

TEST (plain, (void) flag)
TEST (relaxed, __atomic_thread_fence (__ATOMIC_RELAXED))
TEST (seq, __atomic_thread_fence (__ATOMIC_SEQ_CST))
TEST (acquire, __atomic_thread_fence (__ATOMIC_ACQUIRE))
TEST (release, __atomic_thread_fence (__ATOMIC_RELEASE))
TEST (acqrel, __atomic_thread_fence (__ATOMIC_ACQ_REL))
TEST (dynamic, __atomic_thread_fence (flag))
TEST (sync, __sync_synchronize ())
TEST (signal, __atomic_signal_fence (__ATOMIC_SEQ_CST))
TEST (asm, asm volatile ("fence rw,rw" ::: "memory"))
TEST (call, fence_callee ())
TEST (join, if (flag) __atomic_thread_fence (__ATOMIC_SEQ_CST))
#undef TEST

void fence_memory (const element *in, element *out, unsigned flag)
{
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __atomic_thread_fence (__ATOMIC_ACQUIRE);
  a = __riscv_ztt_madd_ew_i32_1x1 (a, a);
  __riscv_ztt_mss_rm (out, a);
  __atomic_thread_fence (__ATOMIC_RELEASE);
  matrix b = __riscv_ztt_mls_rm_i32_1x1 (out);
  __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_1x1 (b, b));
}
#ifdef __cplusplus
}
#endif
