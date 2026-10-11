#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ element;
extern void split_callee (void);

void split_binary (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_1x1 (a, a));
  else
    __riscv_ztt_mss_rm (out, __riscv_ztt_msub_ew_i32_1x1 (a, a));
}

void split_rowcol (const element *in, element *out, int index, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    __riscv_ztt_mss_rm (out, __riscv_ztt_mrowbcast_ew_x_i32_1x1 (a, index));
  else
    __riscv_ztt_mss_rm (out, __riscv_ztt_mcolbcast_ew_x_i32_1x1 (a, index));
}

void split_call (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  split_callee ();
  if (flag)
    __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_1x1 (a, a));
  else
    __riscv_ztt_mss_rm (out, __riscv_ztt_msub_ew_i32_1x1 (a, a));
}

void split_asm (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __asm__ volatile ("" ::: "memory");
  if (flag)
    __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_1x1 (a, a));
  else
    __riscv_ztt_mss_rm (out, __riscv_ztt_msub_ew_i32_1x1 (a, a));
}

void split_join (const element *in, const element *other, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    a = __riscv_ztt_mls_rm_i32_1x1 (other);
  __riscv_ztt_mss_rm (out, a);
}

void split_loop (const element *in, element *out, unsigned count)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  while (count--)
    a = __riscv_ztt_madd_ew_i32_1x1 (a, a);
  __riscv_ztt_mss_rm (out, a);
}
#ifdef __cplusplus
}
#endif
