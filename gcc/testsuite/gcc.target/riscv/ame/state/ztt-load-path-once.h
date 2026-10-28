#ifdef __cplusplus
extern "C"
#endif
void path_once (i32 *out, const i32 *seed, const i32 *right,
                i32 *work, const i32 *input, usize count)
{
  accumulator acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (load (seed));
  for (usize i = 0; i < count; ++i)
    if (input[i] > 0)
      work[i] = input[i];
    else
      work[i] = 0;
  acc = __riscv_ztt_mmulacc_2d_i32_rnu_accx1
    (acc, load (work), load (right));
  __riscv_ztt_mss_rm (out, __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (acc));
}
