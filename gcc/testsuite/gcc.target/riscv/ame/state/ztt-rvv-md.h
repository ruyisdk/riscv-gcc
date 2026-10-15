#include <riscv_ztt.h>
#include <riscv_vector.h>
#ifdef __cplusplus
extern "C" {
#endif
extern void rv_callee (void);
#define RV_ARGS const uint32_t *in, uint32_t *mid, uint32_t *out, size_t count
#define RV_LOAD __riscv_ztt_u32_rnu_1x1_t m = __riscv_ztt_mls_rm_u32_rnu_1x1 (in); \
  __riscv_ztt_mss_rm (mid, m)
#define RV_VECTOR size_t vl = __riscv_vsetvl_e32m1 (count); \
  vuint32m1_t v = __riscv_vle32_v_u32m1 (mid, vl)
#define RV_STORE __riscv_vse32_v_u32m1 (mid, v, vl); \
  __riscv_ztt_mss_rm (out, m)
#define RV_BINARY(name,op) size_t rv_##name (RV_ARGS) \
{ RV_LOAD; RV_VECTOR; v = __riscv_##op##_vv_u32m1 (v, v, vl); RV_STORE; return vl; }
RV_BINARY(add,vadd)
RV_BINARY(mul,vmul)
RV_BINARY(sat,vsaddu)
size_t rv_shift (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vsrl_vx_u32m1 (v, 3, vl); RV_STORE;
  return vl;
}
size_t rv_reduce (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  vuint32m1_t z = __riscv_vmv_v_x_u32m1 (0, 1);
  vuint32m1_t sum = __riscv_vredsum_vs_u32m1_u32m1 (v, z, vl);
  uint32_t result = __riscv_vmv_x_s_u32m1_u32 (sum);
  mid[0] = result;
  __riscv_ztt_mss_rm (out, m);
  return vl;
}
size_t rv_call (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vadd_vv_u32m1 (v, v, vl);
  __riscv_vse32_v_u32m1 (mid, v, vl);
  rv_callee ();
  __riscv_ztt_mss_rm (out, m);
  return vl;
}
size_t rv_asm (RV_ARGS)
{
  RV_LOAD; RV_VECTOR;
  v = __riscv_vadd_vv_u32m1 (v, v, vl);
  __riscv_vse32_v_u32m1 (mid, v, vl);
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
