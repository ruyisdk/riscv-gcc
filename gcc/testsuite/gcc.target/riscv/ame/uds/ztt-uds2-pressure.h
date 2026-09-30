/* multi-UDS.  */
#include <stdint.h>
#include <riscv_ztt.h>
#if __riscv_ztt_uds == 64
#define TYPE __riscv_ztt_u32_1x8_t
#define LOAD __riscv_ztt_mls_rm_u32_1x8
#else
#define TYPE __riscv_ztt_u32_1x16_t
#define LOAD __riscv_ztt_mls_rm_u32_1x16
#endif
void pressure (uint32_t *out, const uint32_t *in)
{
  TYPE v0 = LOAD (in + 0);
  TYPE v1 = LOAD (in + 1);
  TYPE v2 = LOAD (in + 2);
  TYPE v3 = LOAD (in + 3);
  TYPE v4 = LOAD (in + 4);
  TYPE v5 = LOAD (in + 5);
  TYPE v6 = LOAD (in + 6);
  TYPE v7 = LOAD (in + 7);
  TYPE v8 = LOAD (in + 8);
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out + 0, v0);
  __riscv_ztt_mss_rm (out + 1, v1);
  __riscv_ztt_mss_rm (out + 2, v2);
  __riscv_ztt_mss_rm (out + 3, v3);
  __riscv_ztt_mss_rm (out + 4, v4);
  __riscv_ztt_mss_rm (out + 5, v5);
  __riscv_ztt_mss_rm (out + 6, v6);
  __riscv_ztt_mss_rm (out + 7, v7);
  __riscv_ztt_mss_rm (out + 8, v8);
}
