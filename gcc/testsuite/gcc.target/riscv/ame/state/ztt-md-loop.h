#include <riscv_ztt.h>
typedef __INT32_TYPE__ i32;
typedef __SIZE_TYPE__ usize;
typedef __riscv_ztt_i32_rnu_1x1_t matrix;
typedef __riscv_ztt_i32_rnu_accx1_t accumulator;

#define load __riscv_ztt_mls_rm_i32_rnu_1x1
#define add __riscv_ztt_madd_ew_i32_rnu_1x1
#define maximum __riscv_ztt_mmax_ew_i32_rnu_1x1
#define zero __riscv_ztt_mzero_m_i32_rnu_1x1
#define store __riscv_ztt_mss_rm

#ifdef __cplusplus
extern "C" {
#endif

void bias_relu (i32 *out, const i32 *in, const i32 *expanded_bias)
{
  matrix x = load (in);
  matrix b = load (expanded_bias);
  store (out, maximum (add (x, b), zero ()));
}

void bias_row_relu (i32 *out, const i32 *in, const i32 *bias_tile)
{
  matrix x = load (in);
  matrix b = __riscv_ztt_mrowbcast_ew_x_i32_rnu_1x1 (load (bias_tile), 0);
  store (out, maximum (add (x, b), zero ()));
}

void matmul_bias_relu (i32 *out, const i32 *a, const i32 *b,
                       const i32 *seed, const i32 *expanded_bias)
{
  accumulator acc = __riscv_ztt_mcopy_m2a_i32_rnu_accx1 (load (seed));
  acc = __riscv_ztt_mmulacc_2d_i32_rnu_accx1 (acc, load (a), load (b));
  matrix x = __riscv_ztt_mcopy_a2m_i32_rnu_1x1 (acc);
  matrix bias = load (expanded_bias);
  store (out, maximum (add (x, bias), zero ()));
}

void bias_relu_tiles (i32 *out, const i32 *in, const i32 *expanded_bias,
                      usize tiles, usize tile_elements)
{
  matrix b = load (expanded_bias);
  matrix z = zero ();
  for (usize i = 0; i < tiles; ++i)
    {
      store (out, maximum (add (load (in), b), z));
      in += tile_elements;
      out += tile_elements;
    }
}

extern void loop_callee (void);
#define CONTROL(NAME, BARRIER) \
void NAME (i32 *out, const i32 *in, const i32 *bias, usize tiles, usize step) \
{ \
  matrix b = load (bias), z = zero (); \
  for (usize i=0; i<tiles; ++i) \
    { \
      BARRIER; \
      store (out, maximum (add (load (in), b), z)); \
      in += step; out += step; \
    } \
}
CONTROL (bias_relu_call, loop_callee ())
CONTROL (bias_relu_asm, asm volatile ("# Md boundary" ::: "memory"))
CONTROL (bias_relu_branch, if (i & 1) asm volatile ("# conditional boundary" ::: "memory"))
CONTROL (bias_relu_volatile, *(volatile i32 *)out = (i32)i)

#ifdef __cplusplus
}
#endif
