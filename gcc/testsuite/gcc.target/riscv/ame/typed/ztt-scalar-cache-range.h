#include "ztt-nominal-signatures.h"
#include "ztt-decl-storage.h"

SIGNATURES (i32_rnu, 1x1, u128_rod);
SIGNATURES (i32_rnu, 1x1, i8_rnu_sat);
SIGNATURES (i32_rnu, 1x1, u128_rod_sat);
SIGNATURES (i32_rnu_sat, 1x1, i8_rnu);
SIGNATURES (i32_rnu_sat, 1x1, u128_rod_sat);
SIGNATURES (i32_rnu, 1x1, f16_rne);
SIGNATURES (i32_rnu, 1x1, f64_rno);
SIGNATURES (f32_rne, 1x1, i8_rnu);
SIGNATURES (f32_rne, 1x1, u128_rod_sat);
SIGNATURES (f32_rne, 1x1, f16_rne);
SIGNATURES (f32_rne, 1x1, f64_rno);

CHECK (__riscv_ztt_madd_ew_x_i32_1x1_i8_sat, i32_rnu_1x1_i8_rnu_sat_binary);
CHECK (__riscv_ztt_madd_ew_x_i32_1x1_f16, i32_rnu_1x1_f16_rne_binary);
CHECK (__riscv_ztt_madd_ew_x_f32_1x1_i8, f32_rne_1x1_i8_rnu_binary);

#ifdef __cplusplus
extern "C"
#endif
__attribute__((noipa)) void
scalar_cache_ranges (__INT32_TYPE__ *out, const __INT32_TYPE__ *in,
                          __INT8_TYPE__ input, float fp)
{
  __riscv_ztt_i32_rnu_1x1_t a = __riscv_ztt_mls_rm_i32_rnu_1x1 (in);
  __riscv_ztt_i8_rnu_sat_scalar_t s = __riscv_ztt_scalar_make_i8_rnu_sat (input);
  __riscv_ztt_f32_rne_scalar_t f = __riscv_ztt_scalar_make_f32_rne (fp);
  a = __riscv_ztt_madd_ew_x_i32_rnu_1x1_i8_rnu_sat (a, s);
  a = __riscv_ztt_mmulacc_ew_x_i32_rnu_1x1_f32_rne (a, a, f);
  __riscv_ztt_mss_rm (out, a);
}
