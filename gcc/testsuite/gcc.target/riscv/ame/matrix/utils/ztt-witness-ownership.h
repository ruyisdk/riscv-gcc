#include <stdint.h>
#include <riscv_ztt.h>

#define WO_VALUE __riscv_ztt_i32_rnu_1x2_t
#define WO_LOAD WO_VALUE p = __riscv_ztt_mls_rm_i32_rnu_1x2 (in)
#define WO_REBUILD(V) __riscv_ztt_mconcat_m_i32_rnu_1x2 \
  (__riscv_ztt_mextract_i32_rnu_1x1 (V, 0), \
   __riscv_ztt_mextract_i32_rnu_1x1 (V, 1))

#ifndef WO_CONCAT
void witness_unowned_extract (int32_t *out, const int32_t *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  WO_LOAD;
  __riscv_ztt_ame_release ();
  WO_VALUE q = __riscv_ztt_mcolzip_ew_i32_rnu_1x2 (p);
  WO_VALUE r = __riscv_ztt_mcolunzip_ew_i32_rnu_1x2 (q);
  WO_VALUE s = WO_REBUILD (r);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, s);
  __riscv_ztt_ame_release ();
}

#else
void witness_unowned_concat (int32_t *out, const int32_t *in)
{
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  WO_LOAD;
  __riscv_ztt_ame_release ();
  WO_VALUE r = WO_REBUILD (p);
  WO_VALUE q = __riscv_ztt_mrowzip_ew_i32_rnu_1x2 (r);
  WO_VALUE s = __riscv_ztt_mrowunzip_ew_i32_rnu_1x2 (q);
  if (!(__riscv_ztt_ame_acquire (0) & 1))
    return;
  __riscv_ztt_mss_rm (out, s);
  __riscv_ztt_ame_release ();
}
#endif
