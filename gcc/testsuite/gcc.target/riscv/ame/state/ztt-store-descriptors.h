#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void descriptor_callee (void);

#define CHAIN(NAME, STORE, GAP) \
void NAME (const float *in, float *out, float *last, \
           int index, int flag, __SIZE_TYPE__ stride) \
{ \
  __riscv_ztt_f32_1x1_t a = __riscv_ztt_mls_rm_f32_1x1 (in); \
  a = __riscv_ztt_mrowbcast_ew_x_f32_1x1 (a, index); \
  STORE; \
  GAP; \
  a = __riscv_ztt_madd_ew_f32_1x1 (a, a); \
  __riscv_ztt_mss_rm (last, a); \
}
CHAIN (store_rm_fp, __riscv_ztt_mss_rm (out, a), (void) 0)
CHAIN (store_cm_fp, __riscv_ztt_mss_cm (out, a), (void) 0)
CHAIN (store_st_fp, __riscv_ztt_mss_st (out, stride, a), (void) 0)
CHAIN (store_tst_fp, __riscv_ztt_mss_tst (out, stride, a), (void) 0)
CHAIN (store_load_fp, __riscv_ztt_mss_rm (out, a),
       a = __riscv_ztt_mls_rm_f32_1x1 (out))
CHAIN (store_call_fp, __riscv_ztt_mss_rm (out, a), descriptor_callee ())
CHAIN (store_asm_fp, __riscv_ztt_mss_rm (out, a),
       __asm__ volatile ("" ::: "memory"))
CHAIN (store_join_fp, __riscv_ztt_mss_rm (out, a),
       if (flag) descriptor_callee ())
#undef CHAIN

void store_scalar_int (const __INT32_TYPE__ *in, __INT32_TYPE__ *out,
                       __INT32_TYPE__ *last, int index, int flag,
                       __SIZE_TYPE__ stride)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i32_rne
    (a, __riscv_ztt_scalar_from_bits_i32_rne (index));
  __riscv_ztt_mss_rm (out, a);
  a = __riscv_ztt_mmul_ew_x_i32_rnu_1x1_i32_rne
    (a, __riscv_ztt_scalar_from_bits_i32_rne (flag));
  __riscv_ztt_mss_rm (last, a);
}
#ifdef __cplusplus
}
#endif
