/* UDS32, i32/RNU only.  */
#include <stdint.h>
#include <riscv_ztt.h>
#ifndef __riscv_ztt_i32_rnu_accx1
#error typed accx1 capability required
#endif
#ifdef __cplusplus
extern "C" {
#endif
void acc_smoke (int32_t *dst, const int32_t *src)
{
  __riscv_ztt_i32_1x1_t m = __riscv_ztt_mls_rm_i32_1x1 (src);
  __riscv_ztt_i32_accx1_t old = __riscv_ztt_mcopy_m2a_i32_accx1 (m);
  __riscv_ztt_i32_accx1_t next
    = __riscv_ztt_mmulacc_2d_i32_accx1 (old, m, m);
  __riscv_ztt_mss_rm (dst, __riscv_ztt_mcopy_a2m_i32_1x1 (next));
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (dst, __riscv_ztt_mcopy_a2m_i32_1x1 (old));
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (dst, __riscv_ztt_mcopy_a2m_i32_1x1
    (__riscv_ztt_mclear_acc_i32_accx1 ()));
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (dst, __riscv_ztt_mcopy_a2m_i32_1x1
    (__riscv_ztt_mzero_acc_i32_accx1 ()));
}
#ifdef __cplusplus
}
#endif
