/* runtime-N resource profiles.  */

#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_profile != 2 || !defined (__riscv_ztt_runtime_n)
#error expected runtime-N profile
#endif
#if defined (__riscv_ztt_n) || defined (__riscv_ztt_nelem)
#error N must not become a compilation constant
#endif
#if __riscv_ztt_uds != 8 || __riscv_ztt_mregs != EXPECT_M \
    || __riscv_ztt_accregs != EXPECT_ACC
#error incorrect resource counts
#endif

#ifdef __cplusplus
extern "C" {
#endif

unsigned long
resource_selectors (unsigned long dtype, void *ptr)
{
  __builtin_riscv_ztt_mzero_2d_m (EXPECT_M - 1);
  __builtin_riscv_ztt_mzero_2d_acc (EXPECT_ACC - 1);
  __builtin_riscv_ztt_msettyp (EXPECT_M - 1, dtype);
  __builtin_riscv_ztt_asettyp (EXPECT_ACC - 1, dtype);
  __builtin_riscv_ztt_mmov_m_a (EXPECT_M - 1, EXPECT_ACC - 1);
  __builtin_riscv_ztt_mmov_a_m (EXPECT_ACC - 1, EXPECT_M - 1);
  __builtin_riscv_ztt_mmulacc_2d (EXPECT_ACC - 1, 0, EXPECT_M - 1);
  __builtin_riscv_ztt_madd_ew (EXPECT_M - 1, 0, EXPECT_M - 1);
  __builtin_riscv_ztt_madd_ew_x (EXPECT_M - 1, 256, EXPECT_M - 1);
  __builtin_riscv_ztt_mls_1r (EXPECT_M - 1, ptr);
  __builtin_riscv_ztt_mss_1r (EXPECT_M - 1, ptr);
  return __builtin_riscv_ztt_mgettyp (EXPECT_M - 1)
	 + __builtin_riscv_ztt_agettyp (EXPECT_ACC - 1);
}

/* Nine complete four-M values exceed even the largest resource profile.
   The memory barrier keeps all loads before any store, forcing spills.  */
void
resource_pressure (const uint32_t *const *in, uint32_t *const *out)
{
  __riscv_ztt_u32_rnu_1x1_t v0
    = __riscv_ztt_mls_rm_u32_rnu_1x1 (in[0]);
  __riscv_ztt_u32_rne_1x1_t v1
    = __riscv_ztt_mls_rm_u32_rne_1x1 (in[1]);
  __riscv_ztt_u32_rdn_1x1_t v2
    = __riscv_ztt_mls_rm_u32_rdn_1x1 (in[2]);
  __riscv_ztt_u32_rod_1x1_t v3
    = __riscv_ztt_mls_rm_u32_rod_1x1 (in[3]);
  __riscv_ztt_u32_rnu_1x1_t v4
    = __riscv_ztt_mls_rm_u32_rnu_1x1 (in[4]);
  __riscv_ztt_u32_rne_1x1_t v5
    = __riscv_ztt_mls_rm_u32_rne_1x1 (in[5]);
  __riscv_ztt_u32_rdn_1x1_t v6
    = __riscv_ztt_mls_rm_u32_rdn_1x1 (in[6]);
  __riscv_ztt_u32_rod_1x1_t v7
    = __riscv_ztt_mls_rm_u32_rod_1x1 (in[7]);
  __riscv_ztt_u32_rnu_1x1_t v8
    = __riscv_ztt_mls_rm_u32_rnu_1x1 (in[8]);

  __asm__ volatile ("" ::: "memory");

  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
  __riscv_ztt_mss_rm (out[5], v5);
  __riscv_ztt_mss_rm (out[6], v6);
  __riscv_ztt_mss_rm (out[7], v7);
  __riscv_ztt_mss_rm (out[8], v8);
}

#ifdef __cplusplus
}
#endif

#define TEST_RUNTIME 1
#include "../types/ztt-dtypes-single.h"
