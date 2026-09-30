#include <stdint.h>
#include <riscv_ztt.h>
#define NT_(T, S) __riscv_ztt_##T##_##S##_t
#define NT(T) NT_(T, NSHAPE)
#define NF_(OP, T, S) __riscv_ztt_##OP##_##T##_##S
#define NF_I(OP, T, S) NF_(OP, T, S)
#define NF(OP, T) NF_I(OP, T, NSHAPE)
#undef NT
#define NT_I(T, S) NT_(T, S)
#define NT(T) NT_I(T, NSHAPE)
#ifdef __cplusplus
extern "C" {
#endif
__attribute__((noinline, used, externally_visible))
void nominal_madd (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(madd_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_msub (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(msub_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmul (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmul_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mabsdiff (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mabsdiff_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mhdiff (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mhdiff_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmean (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmean_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmulneg (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmulneg_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmin (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmin_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmax (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmax_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mand (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mand_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mandnot (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mandnot_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mor (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mor_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mornot (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mornot_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mxor (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mxor_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmulacc (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmulacc_ew_x, i32) (m, m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmulaccneg (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmulaccneg_ew_x, i32) (m, m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmuladd (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmuladd_ew_x, i32) (m, m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mmulsub (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mmulsub_ew_x, i32) (m, m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mcmpge (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mcmpge_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mcmplt (int32_t *out, const int32_t *in, volatile int32_t *p)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mcmplt_ew_x, i32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mlog2sub (float *out, const float *in, volatile int32_t *p)
{
  NT(f32) m = NF(mls_rm, f32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(mlog2sub_ew_x, f32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_msublog2 (float *out, const float *in, volatile int32_t *p)
{
  NT(f32) m = NF(mls_rm, f32) (in);
  __riscv_ztt_i32_rne_scalar_t s = __riscv_ztt_scalar_make_i32_rne (*p);
  m = NF(msublog2_ew_x, f32) (m, s);
  __riscv_ztt_mss_rm (out, m);
}
__attribute__((noinline, used, externally_visible))
void nominal_mbcast (int32_t *out, volatile int32_t *p)
{
  NT(i32) m = NF(mbcast_m_x, i32) (__riscv_ztt_scalar_make_i32_rne (*p));
  __riscv_ztt_mss_rm (out, m);
}
/* FP data Scalar conversion is legal even for integer bitwise operations.  */
__attribute__((noinline, used, externally_visible))
void nominal_fp_bits (int32_t *out, const int32_t *in, uint32_t bits)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  m = NF(mand_ew_x, i32) (m, __riscv_ztt_scalar_from_bits_f32_rno (bits));
  __riscv_ztt_mss_rm (out, m);
}
/* A wide data Scalar still carries only one XLEN register, not 128 bits.  */
__attribute__((noinline, used, externally_visible))
void nominal_wide (int32_t *out, const int32_t *in, unsigned long bits)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  m = NF(mmulacc_ew_x, i32) (m, m,
        __riscv_ztt_scalar_from_bits_u128_rod_sat (bits));
  __riscv_ztt_mss_rm (out, m);
}
/* Control values are not data Scalars.  */
__attribute__((noinline, used, externally_visible))
void nominal_controls (int32_t *out, const int32_t *in, long exponent)
{
  NT(i32) m = NF(mls_rm, i32) (in);
  m = NF(msll_ew_x, i32) (m, 3);
  m = NF(mldexp_ew_x, i32) (m, exponent);
  __riscv_ztt_mss_rm (out, m);
}
#ifdef __cplusplus
}
#endif
