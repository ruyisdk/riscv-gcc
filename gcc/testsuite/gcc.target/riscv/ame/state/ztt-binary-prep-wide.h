#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
#define WIDE(D, E, OP, SAME) \
__attribute__((noinline, noclone)) \
void wide_##D##_##OP##_##SAME (const E *a, const E *b, E *out) \
{ \
  __riscv_ztt_##D##_1x1_t x = __riscv_ztt_mls_rm_##D##_1x1 (a); \
  __riscv_ztt_##D##_1x1_t y = SAME ? x : __riscv_ztt_mls_rm_##D##_1x1 (b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_m##OP##_ew_##D##_1x1 (x, y)); \
}
#define WIDTH(D, E) \
  WIDE (D, E, add, 0) WIDE (D, E, add, 1) \
  WIDE (D, E, xor, 0) WIDE (D, E, xor, 1)
WIDTH (u64, __UINT64_TYPE__)
WIDTH (u128, __riscv_ztt_u128_storage_t)
#undef WIDTH
#undef WIDE
#ifdef __cplusplus
}
#endif
