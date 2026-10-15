#define BR_INNER_mmin_ew mmax_ew
#define BR_INNER_mmax_ew mmin_ew
#define BR_INNER_mand_ew mor_ew
#define BR_INNER_mor_ew mand_ew
#define BR_INNER_(op) BR_INNER_##op
#define BR_INNER(op) BR_INNER_(op)
#ifndef BR_OBSERVE
#define BR_OBSERVE 1
#endif
#if BR_OBSERVE
#define BR_ARGS const element_t *in, const element_t *other, element_t *out, \
  element_t *saved_a, element_t *saved_b
#define BR_SAVE(v) __riscv_ztt_mss_rm (saved_a, a); \
  __riscv_ztt_mss_rm (saved_b, b); __riscv_ztt_mss_rm (out, v)
#endif
#include "ztt-binary-repeat.h"
