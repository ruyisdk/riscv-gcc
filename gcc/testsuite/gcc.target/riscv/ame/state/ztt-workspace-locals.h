#include <stdint.h>
#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void local_observer (volatile unsigned long *);

#define TRANSFER \
  __riscv_ztt_i32_rnu_1x1_t m = __riscv_ztt_mls_rm_i32_rnu_1x1 (in); \
  __riscv_ztt_i32_rnu_accx1_t a = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (m); \
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (a))

unsigned long local_array (const int32_t *in, int32_t *out, unsigned index,
                           volatile unsigned long *control)
{
  volatile unsigned long values[3] = {control[0], control[1], control[2]};
  TRANSFER;
  values[1] += (unsigned long) out[0];
  return values[index % 3];
}

unsigned long local_pointer (const int32_t *in, int32_t *out, unsigned index,
                             volatile unsigned long *control)
{
  const void *values[3] = {in, out, (const void *) control};
  TRANSFER;
  return (uintptr_t) values[index % 3];
}

unsigned long local_fixed (const int32_t *in, int32_t *out, unsigned index,
                           volatile unsigned long *control)
{
  volatile unsigned long values[3] = {control[0], control[1], control[2]};
  TRANSFER;
  values[1] += (unsigned long) out[0];
  return (values[0] ^ values[1]) + values[2] + index;
}

unsigned long local_asm (const int32_t *in, int32_t *out, unsigned index,
                         volatile unsigned long *control)
{
  volatile unsigned long values[3] = {control[0], control[1], control[2]};
  TRANSFER;
  __asm__ volatile ("nop" : : : "memory");
  return values[index % 3];
}

unsigned long local_call (const int32_t *in, int32_t *out, unsigned index,
                          volatile unsigned long *control)
{
  volatile unsigned long values[3] = {control[0], control[1], control[2]};
  TRANSFER;
  local_observer (values);
  return values[index % 3];
}

#undef TRANSFER
#ifdef __cplusplus
}
#endif
