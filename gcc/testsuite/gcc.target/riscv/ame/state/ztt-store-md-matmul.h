#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
/* Reloading the stored matrix keeps matmul after the store when scheduled.  */
#define STORE_MMUL(NAME, STORE, LOAD) \
__attribute__((noinline,noclone)) \
void NAME (const __INT32_TYPE__ *in, __INT32_TYPE__ *out, \
           __INT32_TYPE__ *live, __INT32_TYPE__ *stored, unsigned long stride) \
{ \
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in); \
  __riscv_ztt_i32_accx1_t d = __riscv_ztt_mcopy_m2a_i32_accx1 (a); \
  __asm__ volatile ("" ::: "memory"); \
  STORE; \
  __riscv_ztt_i32_1x1_t b = LOAD; \
  d = __riscv_ztt_mmulacc_2d_i32_accx1 (d, a, b); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (d)); \
  __riscv_ztt_mss_rm (live, a); \
}
STORE_MMUL (store_mmul_rm, __riscv_ztt_mss_rm (stored, a),
            __riscv_ztt_mls_rm_i32_1x1 (stored))
STORE_MMUL (store_mmul_cm, __riscv_ztt_mss_cm (stored, a),
            __riscv_ztt_mls_cm_i32_1x1 (stored))
STORE_MMUL (store_mmul_st, __riscv_ztt_mss_st (stored, stride, a),
            __riscv_ztt_mls_st_i32_1x1 (stored, stride))
STORE_MMUL (store_mmul_tst, __riscv_ztt_mss_tst (stored, stride, a),
            __riscv_ztt_mls_tst_i32_1x1 (stored, stride))
#undef STORE_MMUL
#ifdef __cplusplus
}
#endif
