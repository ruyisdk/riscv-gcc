#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef __INT32_TYPE__ element;
extern void branch_callee (void);

void branch_store (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    __riscv_ztt_mss_rm (out, a);
}

void branch_add (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    __riscv_ztt_mss_rm (out, __riscv_ztt_madd_ew_i32_1x1 (a, a));
}

void branch_acc (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    {
      __riscv_ztt_i32_accx1_t d = __riscv_ztt_mcopy_m2a_i32_accx1 (a);
      __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_1x1 (d));
    }
}

void branch_call (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  branch_callee ();
  if (flag)
    __riscv_ztt_mss_rm (out, a);
}

void branch_asm (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __asm__ volatile ("" ::: "memory");
  if (flag)
    __riscv_ztt_mss_rm (out, a);
}

void branch_join (const element *in, element *out, int flag)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  if (flag)
    __asm__ volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (out, a);
}

void branch_loop (const element *in, element *out, unsigned int count)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  while (count--)
    __riscv_ztt_mss_rm (out, a);
}

void branch_goto (const element *in, element *out)
{
  __riscv_ztt_i32_1x1_t a = __riscv_ztt_mls_rm_i32_1x1 (in);
  __asm__ goto ("" ::: "memory" : done);
  __riscv_ztt_mss_rm (out, a);
done:;
}
#ifdef __cplusplus
}
#endif
