#include <riscv_ztt.h>
typedef __INT32_TYPE__ element;
typedef __riscv_ztt_i32_rnu_1x1_t matrix;
#ifdef __cplusplus
extern "C" {
#endif
extern void fence_callee (void);

#define TEST(NAME, CODE) \
void scalar_barrier_##NAME (const element *in, element *out, unsigned flag) \
{ \
  matrix a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  CODE; \
  a = __riscv_ztt_madd_ew_i32_1x1 (a, a); \
  __riscv_ztt_mss_rm (out, a); \
  out[0] += flag; \
}
TEST (plain, (void) flag)
TEST (input, asm volatile ("" :: "r" (flag) : "memory"))
TEST (output, asm volatile ("" : "+r" (flag) :: "memory"))
TEST (partial, unsigned char part = flag;
      asm volatile ("" : "+r" (part) :: "memory"); flag = part)
TEST (multiple, unsigned other = flag;
      asm volatile ("" : "+r" (flag), "+r" (other) :: "memory"); flag = other)
TEST (clobber, asm volatile ("" :: "r" (flag) : "t0", "memory"))
TEST (registers, asm volatile ("" : "+r" (flag)))
TEST (memory, asm volatile ("" : "+m" (flag) :: "memory"))
TEST (opaque, asm volatile ("# AME state boundary" ::: "memory"))
TEST (matrix, asm volatile ("" ::: "m4", "memory"))
TEST (go, asm goto ("" ::: "memory" : done); done: (void) flag)
TEST (call, fence_callee ())
#undef TEST
#ifdef __cplusplus
}
#endif
