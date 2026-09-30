/* A shared ordinary input may be reused by matmul expansion, but different
   inputs and repeated volatile reads still need independent M groups.  */
#include <riscv_ztt.h>
#ifdef __cplusplus
extern "C" {
#endif
extern int call_boundary (int);
typedef __riscv_ztt_i128_rod_1x1_t matrix;
typedef __riscv_ztt_i128_rod_accx1_t accumulator;
typedef __riscv_ztt_i128_storage_t storage;

int distinct_after_call (const storage *left, const storage *right,
                         storage *out)
{
  matrix x = __riscv_ztt_mls_rm_i128_rod_1x1 (left);
  matrix y = __riscv_ztt_mls_rm_i128_rod_1x1 (right);
  accumulator a = __riscv_ztt_mzero_acc_i128_rod_accx1 ();
  int result = call_boundary (1);
  a = __riscv_ztt_mmulacc_2d_i128_rod_accx1 (a, x, y);
  __riscv_ztt_mss_rm_i128_rod_1x1
    (out, __riscv_ztt_mcopy_a2m_i128_rod_1x1 (a));
  return result;
}

int volatile_after_call (const storage *in, storage *out)
{
  volatile matrix x = __riscv_ztt_mls_rm_i128_rod_1x1 (in);
  accumulator a = __riscv_ztt_mzero_acc_i128_rod_accx1 ();
  int result = call_boundary (1);
  a = __riscv_ztt_mmulacc_2d_i128_rod_accx1 (a, x, x);
  __riscv_ztt_mss_rm_i128_rod_1x1
    (out, __riscv_ztt_mcopy_a2m_i128_rod_1x1 (a));
  return result;
}
#ifdef __cplusplus
}
#endif
