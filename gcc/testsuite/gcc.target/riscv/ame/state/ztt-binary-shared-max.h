#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
#define MAX_VALUE(D, E, COUNT, OP) \
__attribute__((noinline, noclone)) \
void max_##D##_##OP (const E *a, E *out) \
{ \
  __riscv_ztt_##D##_1x##COUNT##_t x = __riscv_ztt_mls_rm_##D##_1x##COUNT (a); \
  __asm__ volatile ("" ::: "memory"); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_m##OP##_ew_##D##_1x##COUNT (x, x)); \
}
MAX_VALUE (u64, __UINT64_TYPE__, 4, add)
MAX_VALUE (u64, __UINT64_TYPE__, 4, xor)
MAX_VALUE (u128, __riscv_ztt_u128_storage_t, 2, add)
MAX_VALUE (u128, __riscv_ztt_u128_storage_t, 2, xor)
#undef MAX_VALUE
#ifdef __cplusplus
}
#endif
