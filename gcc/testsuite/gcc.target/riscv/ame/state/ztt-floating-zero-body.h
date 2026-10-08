#include <riscv_ztt.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ZERO(D, S, K) \
void zero_m_##D (void) \
{ \
  __riscv_ztt_##D##_##S##_t value = __riscv_ztt_mzero_m_##D##_##S (); \
  __asm__ volatile ("" : : "Wmr" (value)); \
} \
void zero_acc_##D (void) \
{ \
  __riscv_ztt_##D##_accx##K##_t value = __riscv_ztt_mzero_acc_##D##_accx##K (); \
  __asm__ volatile ("" : : "War" (value)); \
}

#define ALL_RM(T, S, K) \
ZERO(T##_rne, S, K) \
ZERO(T##_rtz, S, K) \
ZERO(T##_rdn, S, K) \
ZERO(T##_rup, S, K) \
ZERO(T##_rmm, S, K) \
ZERO(T##_rno, S, K)

ALL_RM(f16, 1x2, 2)
ALL_RM(bf16, 1x2, 2)
ALL_RM(f32, 1x1, 1)
ALL_RM(f64, 1x1, 1)

void raw_zero (unsigned long descriptor)
{
  __builtin_riscv_ztt_msettyp (0, descriptor);
  __builtin_riscv_ztt_mzero_2d_m (0);
  __builtin_riscv_ztt_asettyp (0, descriptor);
  __builtin_riscv_ztt_mzero_2d_acc (0);
}

void raw_known_zero (void)
{
  __builtin_riscv_ztt_msettyp (0, 0x20300120UL);
  __builtin_riscv_ztt_mzero_2d_m (0);
  __builtin_riscv_ztt_asettyp (0, 0x20300120UL);
  __builtin_riscv_ztt_mzero_2d_acc (0);
}

#define BCAST(NAME, DEST, SOURCE, VALUE) \
void NAME (void) \
{ \
  __riscv_ztt_##DEST##_1x1_t value = \
    __riscv_ztt_mbcast_m_x_##DEST##_1x1_##SOURCE \
      (__riscv_ztt_scalar_make_##SOURCE (VALUE)); \
  __asm__ volatile ("" : : "Wmr" (value)); \
}
BCAST(positive_zero, f32_rne, f32_rne, 0.0f)
BCAST(negative_zero, f32_rne, f32_rne, -0.0f)
BCAST(integer_source, f32_rne, i32_rnu, 0)
BCAST(integer_destination, i32_rnu, f32_rne, 0.0f)

#ifdef __cplusplus
}
#endif
