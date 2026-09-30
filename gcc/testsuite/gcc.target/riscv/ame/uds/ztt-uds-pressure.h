/* multi-UDS.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_uds == 16
#define TYPE __riscv_ztt_u16_rdn_1x4_t
#define LOAD __riscv_ztt_mls_rm_u16_rdn_1x4
#else
#define TYPE __riscv_ztt_u32_rdn_1x4_t
#define LOAD __riscv_ztt_mls_rm_u32_rdn_1x4
#endif
void pressure (void *out, const void *in)
{
#if __riscv_ztt_uds == 16
  const uint16_t *src = (const uint16_t *) in;
  uint16_t *dst = (uint16_t *) out;
#else
  const uint32_t *src = (const uint32_t *) in;
  uint32_t *dst = (uint32_t *) out;
#endif
  TYPE v0 = LOAD (src + 0);
  TYPE v1 = LOAD (src + 1);
  TYPE v2 = LOAD (src + 2);
  TYPE v3 = LOAD (src + 3);
  TYPE v4 = LOAD (src + 4);
  TYPE v5 = LOAD (src + 5);
  TYPE v6 = LOAD (src + 6);
  TYPE v7 = LOAD (src + 7);
  TYPE v8 = LOAD (src + 8);
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (dst + 0, v0);
  __riscv_ztt_mss_rm (dst + 1, v1);
  __riscv_ztt_mss_rm (dst + 2, v2);
  __riscv_ztt_mss_rm (dst + 3, v3);
  __riscv_ztt_mss_rm (dst + 4, v4);
  __riscv_ztt_mss_rm (dst + 5, v5);
  __riscv_ztt_mss_rm (dst + 6, v6);
  __riscv_ztt_mss_rm (dst + 7, v7);
  __riscv_ztt_mss_rm (dst + 8, v8);
}
