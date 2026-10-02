#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
#define COPY(NAME, TYPE, K) \
__attribute__((noinline,noclone)) void NAME (void) \
{ \
  __riscv_ztt_##TYPE##_1x##K##_t m \
    = __riscv_ztt_mzero_m_##TYPE##_1x##K (); \
  __riscv_ztt_##TYPE##_accx##K##_t a \
    = __riscv_ztt_mcopy_m2a_##TYPE##_accx##K (m); \
  __asm__ volatile ("" : : "War" (a), "Wmr" (m)); \
}
COPY (wide8, u64_rod, 1)
COPY (wide16, i128_rnu_sat, 1)
COPY (multi, i8_rnu, 2)
COPY (packed, i4_rne, 2)
#undef COPY
#ifdef __cplusplus
}
#endif
