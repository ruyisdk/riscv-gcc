/* { dg-do compile } */
/* { dg-options "-march=rv64iq -mabi=lp64q" } */


int main () {
#if !defined(__riscv)
#error "__riscv"
#endif

#if __riscv_xlen != 64
#error "__riscv_xlen"
#endif

#if !defined(__riscv_fdiv)
#error "__riscv_fdiv"
#endif
#if !defined(__riscv_fsqrt)
#error "__riscv_fsqrt"
#endif

#if defined(__riscv_float_abi_soft)
#error "__riscv_float_abi_soft"
#endif
#if defined(__riscv_float_abi_single)
#error "__riscv_float_abi_single"
#endif
#if defined(__riscv_float_abi_double)
#error "__riscv_float_abi_double"
#endif
#if !defined(__riscv_float_abi_quad)
#error "__riscv_float_abi_double"
#endif
  return 0;
}
