/* call-site extent checks.  */
#include <stdint.h>
#include <riscv_ztt.h>

void unused_indices (void)
{
  __riscv_ztt_mrowid_ew_i8_rnu_1x1 ();
  __riscv_ztt_mcolid_ew_u32_rod_1x1 ();
}

void conditional_index (int narrow, int8_t *small, int32_t *wide)
{
  __riscv_ztt_i32_rne_1x1_t a = __riscv_ztt_mrowid_ew_i32_rne_1x1 ();
  if (narrow)
    {
      __riscv_ztt_i8_rod_1x1_t b = __riscv_ztt_mcolid_ew_i8_rod_1x1 ();
      __riscv_ztt_mss_rm (small, b);
    }
  __riscv_ztt_mss_rm (wide, a);
}

static __inline__ __attribute__((always_inline)) void
inline_index (uint8_t *out)
{
  __riscv_ztt_u8_rdn_1x1_t value = __riscv_ztt_mcolid_ew_u8_rdn_1x1 ();
  __riscv_ztt_mss_rm (out, value);
}

void inlined_index (uint8_t *out)
{
  inline_index (out);
}
