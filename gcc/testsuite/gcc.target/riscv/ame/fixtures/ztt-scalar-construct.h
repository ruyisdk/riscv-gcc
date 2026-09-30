/* AME/Ztt v0.2.5 draft/provisional test construction helpers.  These do not
   change any public intrinsic or automatically convert its arguments.  */
#ifndef ZTT_TEST_SCALAR_CONSTRUCT_H
#define ZTT_TEST_SCALAR_CONSTRUCT_H
#define ZTT_TEST_MAKE_I(T, V) __riscv_ztt_scalar_make_##T (V)
#define ZTT_TEST_MAKE(T, V) ZTT_TEST_MAKE_I(T, V)
#define ZTT_TEST_BITS_I(T, V) __riscv_ztt_scalar_from_bits_##T (V)
#define ZTT_TEST_BITS(T, V) ZTT_TEST_BITS_I(T, V)
#if __riscv_xlen == 64
typedef double ztt_test_f64_carrier_t;
#define ZTT_TEST_F64_I(R, V) __riscv_ztt_scalar_make_f64_##R (V)
#else
typedef __UINT32_TYPE__ ztt_test_f64_carrier_t;
#define ZTT_TEST_F64_I(R, V) __riscv_ztt_scalar_from_bits_f64_##R (V)
#endif
#define ZTT_TEST_F64(R, V) ZTT_TEST_F64_I(R, V)
#endif
