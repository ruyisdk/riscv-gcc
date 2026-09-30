/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_ztt -mabi=ilp32" { target rv32 } } */
/* { dg-options "-O2 -march=rv64gc_ztt -mabi=lp64" { target rv64 } } */

#define ZTT_TEST_ARGS_none
#define ZTT_TEST_ARGS_m 31
#define ZTT_TEST_ARGS_a 15
#define ZTT_TEST_ARGS_mm 31, 16
#define ZTT_TEST_ARGS_ma 31, 15
#define ZTT_TEST_ARGS_am 15, 31
#define ZTT_TEST_ARGS_mmm 31, 16, 15
#define ZTT_TEST_ARGS_amm 15, 16, 31
#define ZTT_TEST_ARGS_mxm 31, x, 16
#define ZTT_TEST_ARGS_mxx 31, x, y
#define ZTT_TEST_ARGS_mx 31, x
#define ZTT_TEST_ARGS_ax 15, x
#define ZTT_TEST_ARGS_x_a 15
#define ZTT_TEST_ARGS_x_m 31
#define ZTT_TEST_ARGS_x_m_x 31, x
#define ZTT_TEST_ARGS_x_x x
#define ZTT_TEST_ARGS_load 31, base
#define ZTT_TEST_ARGS_store 31, base
#define ZTT_TEST_ARGS_load_strided 31, base, x
#define ZTT_TEST_ARGS_store_strided 31, base, x

void
ztt_all_builtins (unsigned long x, unsigned long y, void *base)
{
#define ZTT_BUILTIN(NAME, MNEMONIC, PATTERN, FUNCTION_TYPE) \
  (void) __builtin_riscv_ztt_ ## NAME (ZTT_TEST_ARGS_ ## PATTERN);
#define ZTT_BUILTIN_X ZTT_BUILTIN
#include "../../../../../config/riscv/riscv-ztt-builtins.def"
#undef ZTT_BUILTIN_X
#undef ZTT_BUILTIN
}
