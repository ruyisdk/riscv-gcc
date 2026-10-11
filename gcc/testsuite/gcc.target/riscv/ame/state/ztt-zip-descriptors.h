#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void zip_descriptor_callee (void);

#define ZIP_CHAIN(NAME, TYPE, CTYPE, OP, NEXT, GAP) \
__attribute__((noipa)) void NAME \
  (const CTYPE *in, CTYPE *out, CTYPE *last, int flag) \
{ \
  __riscv_ztt_##TYPE##_1x2_t a = __riscv_ztt_mls_rm_##TYPE##_1x2 (in); \
  a = __riscv_ztt_##OP##_##TYPE##_1x2 (a); \
  NEXT; \
  GAP; \
  __riscv_ztt_mss_rm (out, a); \
  a = __riscv_ztt_madd_ew_##TYPE##_1x2 (a, a); \
  __riscv_ztt_mss_rm (last, a); \
}
ZIP_CHAIN (zip_col_int, i32_rnu, __INT32_TYPE__, mcolzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (zip_row_int, i32_rnu, __INT32_TYPE__, mrowzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (unzip_col_int, i32_rnu, __INT32_TYPE__, mcolunzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (unzip_row_int, i32_rnu, __INT32_TYPE__, mrowunzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (zip_col_fp, f32_rne, float, mcolzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (zip_row_fp, f32_rne, float, mrowzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (unzip_col_fp, f32_rne, float, mcolunzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (unzip_row_fp, f32_rne, float, mrowunzip_ew, (void) 0, (void) 0)
ZIP_CHAIN (zip_cross_axis, i32_rnu, __INT32_TYPE__, mcolzip_ew,
           a = __riscv_ztt_mrowzip_ew_i32_rnu_1x2 (a), (void) 0)
ZIP_CHAIN (zip_asm, i32_rnu, __INT32_TYPE__, mcolzip_ew, (void) 0,
           __asm__ volatile ("" ::: "memory"))
ZIP_CHAIN (zip_call, i32_rnu, __INT32_TYPE__, mcolzip_ew, (void) 0,
           zip_descriptor_callee ())
ZIP_CHAIN (zip_join, i32_rnu, __INT32_TYPE__, mcolzip_ew, (void) 0,
           if (flag) zip_descriptor_callee ())
#undef ZIP_CHAIN
#ifdef __cplusplus
}
#endif
