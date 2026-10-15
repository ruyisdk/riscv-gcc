#include <riscv_ztt.h>
#ifndef SA_TYPE
#define SA_TYPE u32_rnu
#define SA_ELEMENT __UINT32_TYPE__
#endif
#define SA_CAT_(a, b) a##b
#define SA_CAT(a, b) SA_CAT_(a, b)
#define SA_NAME_(a, b) a##b##_1x1
#define SA_FN_(a, b) SA_NAME_(a, b)
#define SA_FN(a) SA_FN_(a, SA_TYPE)
typedef SA_ELEMENT element_t;
typedef SA_CAT(SA_FN(__riscv_ztt_), _t) matrix_t;
#define LOAD(p) SA_FN(__riscv_ztt_mls_rm_)(p)
#define COPY(d) SA_FN(__riscv_ztt_mcopy_m2m_)(d)
#define SCAT(d, a, b) SA_FN(__riscv_ztt_mrowscatadd_ew_)(d, a, b)
#ifdef __cplusplus
extern "C" {
#endif
void sa_callee (void);
#define CASE(NAME, A, B, GAP, SAVE) \
void __attribute__((noipa)) \
NAME (const element_t *old, const element_t *input, \
      element_t *out, element_t *saved) \
{ \
  matrix_t d = LOAD (old); \
  matrix_t a = A; \
  matrix_t b = B; \
  matrix_t result = SCAT (d, a, b); \
  GAP; \
  __riscv_ztt_mss_rm (out, result); \
  SAVE; \
}
CASE (sa_data, COPY (d), LOAD (input), (void) 0, __riscv_ztt_mss_rm (saved, d))
CASE (sa_index, LOAD (input), COPY (d), (void) 0, __riscv_ztt_mss_rm (saved, d))
CASE (sa_all, COPY (d), COPY (d), (void) 0, __riscv_ztt_mss_rm (saved, d))
CASE (sa_dead, COPY (d), COPY (d), (void) 0, (void) 0)
CASE (sa_call, COPY (d), COPY (d), sa_callee (), __riscv_ztt_mss_rm (saved, d))
CASE (sa_asm, COPY (d), COPY (d), __asm__ volatile ("" ::: "memory"), __riscv_ztt_mss_rm (saved, d))
#ifdef __cplusplus
}
#endif
