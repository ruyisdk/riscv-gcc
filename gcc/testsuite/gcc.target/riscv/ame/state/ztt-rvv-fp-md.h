#include <riscv_ztt.h>
#include <riscv_vector.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void rv_callee (void);
#define RV_ARGS const float *in, float *mid, float *out, size_t count
#define RV_LOAD __riscv_ztt_f32_rne_1x1_t m = __riscv_ztt_mls_rm_f32_rne_1x1 (in); \
  __riscv_ztt_mss_rm (mid, m)
#define RV_VECTOR size_t vl = __riscv_vsetvl_e32m1 (count); \
  vfloat32m1_t v = __riscv_vle32_v_f32m1 (mid, vl)
#define RV_STORE __riscv_vse32_v_f32m1 (mid, v, vl); \
  __riscv_ztt_mss_rm (out, m)
size_t rv_add (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vfadd_vf_f32m1 (v, 1.0f, vl); RV_STORE;
  return vl;
}
size_t rv_half (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vfmul_vf_f32m1 (v, 0.5f, vl); RV_STORE;
  return vl;
}
size_t rv_up (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vfadd_vf_f32m1_rm (v, 1.0f, __RISCV_FRM_RUP, vl); RV_STORE;
  return vl;
}
size_t rv_min (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vfmin_vf_f32m1 (v, 0.0f, vl); RV_STORE;
  return vl;
}
size_t rv_convert (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  vint32m1_t i = __riscv_vfcvt_x_f_v_i32m1 (v, vl);
  v = __riscv_vreinterpret_v_i32m1_f32m1 (i); RV_STORE;
  return vl;
}
size_t rv_call (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vfadd_vf_f32m1 (v, 1.0f, vl);
  __riscv_vse32_v_f32m1 (mid, v, vl);
  rv_callee ();
  __riscv_ztt_mss_rm (out, m);
  return vl;
}
size_t rv_asm (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vfadd_vf_f32m1 (v, 1.0f, vl);
  __riscv_vse32_v_f32m1 (mid, v, vl);
  asm volatile ("# boundary" ::: "memory");
  __riscv_ztt_mss_rm (out, m);
  return vl;
}
size_t rv_reference (RV_ARGS)
{
  RV_LOAD; __riscv_ztt_mss_rm (out, m);
  return count;
}
#ifdef __cplusplus
}
#endif
