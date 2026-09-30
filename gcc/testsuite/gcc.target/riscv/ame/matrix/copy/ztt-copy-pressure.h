/* M copy.  */
#include <stdint.h>
#include <riscv_ztt.h>

#define COPY_TYPE0(S) __riscv_ztt_i32_rdn_##S##_t
#define COPY_TYPE(S) COPY_TYPE0(S)
#define COPY_OP0(OP, S) __riscv_ztt_##OP##_i32_rdn_##S
#define COPY_OP(OP, S) COPY_OP0(OP, S)
#if __riscv_ztt_uds == 8
#define SHAPE 1x1
#elif __riscv_ztt_uds == 16
#define SHAPE 1x2
#elif __riscv_ztt_uds == 32
#define SHAPE 1x4
#elif __riscv_ztt_uds == 64
#define SHAPE 1x8
#else
#define SHAPE 1x16
#endif

#ifdef __cplusplus
extern "C"
#endif
void copy_pressure (int32_t *const *dst, const int32_t *const *src)
{
  COPY_TYPE (SHAPE) a0 = COPY_OP (mls_rm, SHAPE) (src[0]);
  COPY_TYPE (SHAPE) a1 = COPY_OP (mls_rm, SHAPE) (src[1]);
  COPY_TYPE (SHAPE) a2 = COPY_OP (mls_rm, SHAPE) (src[2]);
  COPY_TYPE (SHAPE) a3 = COPY_OP (mls_rm, SHAPE) (src[3]);
  COPY_TYPE (SHAPE) a4 = COPY_OP (mls_rm, SHAPE) (src[4]);
  COPY_TYPE (SHAPE) a5 = COPY_OP (mls_rm, SHAPE) (src[5]);
  COPY_TYPE (SHAPE) a6 = COPY_OP (mls_rm, SHAPE) (src[6]);
  COPY_TYPE (SHAPE) a7 = COPY_OP (mls_rm, SHAPE) (src[7]);
  COPY_TYPE (SHAPE) a8 = COPY_OP (mls_rm, SHAPE) (src[8]);
  COPY_TYPE (SHAPE) b0 = COPY_OP (mcopy_m2m, SHAPE) (a0);
  COPY_TYPE (SHAPE) b1 = COPY_OP (mcopy_m2m, SHAPE) (a1);
  COPY_TYPE (SHAPE) b2 = COPY_OP (mcopy_m2m, SHAPE) (a2);
  COPY_TYPE (SHAPE) b3 = COPY_OP (mcopy_m2m, SHAPE) (a3);
  COPY_TYPE (SHAPE) b4 = COPY_OP (mcopy_m2m, SHAPE) (a4);
  COPY_TYPE (SHAPE) b5 = COPY_OP (mcopy_m2m, SHAPE) (a5);
  COPY_TYPE (SHAPE) b6 = COPY_OP (mcopy_m2m, SHAPE) (a6);
  COPY_TYPE (SHAPE) b7 = COPY_OP (mcopy_m2m, SHAPE) (a7);
  COPY_TYPE (SHAPE) b8 = COPY_OP (mcopy_m2m, SHAPE) (a8);
  asm volatile ("" ::: "memory");
  a0 = COPY_OP (mzero_m, SHAPE) ();
  a1 = COPY_OP (mzero_m, SHAPE) ();
  a2 = COPY_OP (mzero_m, SHAPE) ();
  a3 = COPY_OP (mzero_m, SHAPE) ();
  a4 = COPY_OP (mzero_m, SHAPE) ();
  a5 = COPY_OP (mzero_m, SHAPE) ();
  a6 = COPY_OP (mzero_m, SHAPE) ();
  a7 = COPY_OP (mzero_m, SHAPE) ();
  a8 = COPY_OP (mzero_m, SHAPE) ();
  asm volatile ("" ::: "memory");
  __riscv_ztt_mss_rm (dst[0], b0);
  __riscv_ztt_mss_rm (dst[1], b1);
  __riscv_ztt_mss_rm (dst[2], b2);
  __riscv_ztt_mss_rm (dst[3], b3);
  __riscv_ztt_mss_rm (dst[4], b4);
  __riscv_ztt_mss_rm (dst[5], b5);
  __riscv_ztt_mss_rm (dst[6], b6);
  __riscv_ztt_mss_rm (dst[7], b7);
  __riscv_ztt_mss_rm (dst[8], b8);
  __riscv_ztt_mss_rm (dst[9], a0);
  __riscv_ztt_mss_rm (dst[10], a1);
  __riscv_ztt_mss_rm (dst[11], a2);
  __riscv_ztt_mss_rm (dst[12], a3);
  __riscv_ztt_mss_rm (dst[13], a4);
  __riscv_ztt_mss_rm (dst[14], a5);
  __riscv_ztt_mss_rm (dst[15], a6);
  __riscv_ztt_mss_rm (dst[16], a7);
  __riscv_ztt_mss_rm (dst[17], a8);
}
