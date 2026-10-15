#include <riscv_ztt.h>

#ifndef SC_TYPE
#define SC_TYPE u128_rnu
#define SC_ELEMENT __riscv_ztt_u128_storage_t
#endif
#ifndef SC_WHOLE_BANK
#define SC_WHOLE_BANK 0
#endif

#define SC_NAME_(f, t) __riscv_ztt_##f##_##t##_1x1
#define SC_NAME(f, t) SC_NAME_(f, t)
#define SC_MATRIX_(t) __riscv_ztt_##t##_1x1_t
#define SC_MATRIX(t) SC_MATRIX_(t)
#define SC_ARGS const SC_ELEMENT *old, const SC_ELEMENT *in, \
  SC_ELEMENT *out, SC_ELEMENT *saved, SC_ELEMENT *input_saved
#define SC_COPY(x) SC_NAME(mcopy_m2m, SC_TYPE) (x)
#define SC_SAVE(result) __riscv_ztt_mss_rm (out, result); \
  __riscv_ztt_mss_rm (saved, d)

typedef SC_MATRIX(SC_TYPE) scatter_matrix_t;

#ifdef __cplusplus
extern "C" {
#endif
extern void scatter_callee (void);

void
scatter_all (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t result = SC_NAME(mcolscatadd_ew, SC_TYPE) (d, d, d);
  SC_SAVE(result);
}

void
scatter_all_copy (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t a = SC_COPY(d), b = SC_COPY(a);
  scatter_matrix_t result = SC_NAME(mrowscatmax_ew, SC_TYPE) (d, a, b);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, b);
}

void
scatter_all_call (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t a = SC_COPY(d);
  scatter_callee ();
  scatter_matrix_t result = SC_NAME(mrowscatadd_ew, SC_TYPE) (d, a, a);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, a);
}

#if !SC_WHOLE_BANK
void
scatter_old_data (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t index = SC_NAME(mls_rm, SC_TYPE) (in);
  scatter_matrix_t result = SC_NAME(mcolscatadd_ew, SC_TYPE) (d, d, index);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, index);
}

void
scatter_old_index (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t data = SC_NAME(mls_rm, SC_TYPE) (in);
  scatter_matrix_t result = SC_NAME(mrowscatadd_ew, SC_TYPE) (d, data, d);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, data);
}

void
scatter_old_data_copy (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t index = SC_NAME(mls_rm, SC_TYPE) (in);
  scatter_matrix_t data = SC_COPY(d);
  scatter_matrix_t result = SC_NAME(mrowscatmax_ew, SC_TYPE) (d, data, index);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, data);
}

void
scatter_old_index_copy (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t data = SC_NAME(mls_rm, SC_TYPE) (in);
  scatter_matrix_t index = SC_COPY(d);
  scatter_matrix_t result = SC_NAME(mcolscatmax_ew, SC_TYPE) (d, data, index);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, index);
}

void
scatter_old_call (SC_ARGS)
{
  scatter_matrix_t d = SC_NAME(mls_rm, SC_TYPE) (old);
  scatter_matrix_t index = SC_NAME(mls_rm, SC_TYPE) (in);
  scatter_matrix_t data = SC_COPY(d);
  scatter_callee ();
  scatter_matrix_t result = SC_NAME(mcolscatadd_ew, SC_TYPE) (d, data, index);
  SC_SAVE(result);
  __riscv_ztt_mss_rm (input_saved, data);
}
#endif
#ifdef __cplusplus
}
#endif
