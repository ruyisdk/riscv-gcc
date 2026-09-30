/* Compile/assemble checks, not numerical execution evidence.  */
#include <riscv_ztt.h>
#if __riscv_ztt_integer_kinds_matmul != 63
#error missing integer kind matmul variants
#endif
#define TYPE_(T, S) __riscv_ztt_##T##_##S##_t
#define TYPE(T, S) TYPE_(T, S)
#define ZERO_M_(T, S) __riscv_ztt_mzero_m_##T##_##S ()
#define ZERO_M(T, S) ZERO_M_(T, S)
#define ZERO_A_(T, K) __riscv_ztt_mzero_acc_##T##_accx##K ()
#define ZERO_A(T, K) ZERO_A_(T, K)
#define MUL_(OP, D, K) __riscv_ztt_##OP##_2d_##D##_accx##K
#define MUL(OP, D, K) MUL_(OP, D, K)
#define KEEP_A(X) __asm__ volatile ("" : : "War" (X))
#define KEEP_M(X) __asm__ volatile ("" : : "Wmr" (X))
#define RUN(NAME, D, K, A, B, Q) \
void NAME (void) \
{ \
  TYPE(D, accx##K) old = ZERO_A(D, K); \
  TYPE(A, 1x##Q) ar = ZERO_M(A, 1x##Q); \
  TYPE(A, Q##x1) ac = ZERO_M(A, Q##x1); \
  TYPE(B, 1x##Q) br = ZERO_M(B, 1x##Q); \
  TYPE(B, Q##x1) bc = ZERO_M(B, Q##x1); \
  TYPE(D, accx##K) d = MUL(mmulacc, D, K) (old, ar, bc); \
  d = MUL(mmulaccneg, D, K) (d, ar, bc); \
  d = MUL(mmulatacc, D, K) (d, ar, br); \
  d = MUL(mmulataccneg, D, K) (d, ar, br); \
  d = MUL(mmulbtacc, D, K) (d, ar, br); \
  d = MUL(mmulbtaccneg, D, K) (d, ar, br); \
  d = MUL(mmulatacc, D, K) (d, ac, bc); \
  d = MUL(mmulataccneg, D, K) (d, ac, bc); \
  d = MUL(mmulbtacc, D, K) (d, ac, bc); \
  d = MUL(mmulbtaccneg, D, K) (d, ac, bc); \
  KEEP_A(d); KEEP_A(old); \
  KEEP_M(ar); KEEP_M(ac); KEEP_M(br); KEEP_M(bc); \
}

#if TEST_UDS == 8
RUN(dtype_0, u8_rnu, 1, i4_rne, u16_rnu, 2)
RUN(dtype_5, i8_rne, 1, u4_rod_sat, i8_rdn_sat, 2)
RUN(dtype_10, u16_rdn, 1, i4_rne, i8_rdn_sat, 2)
RUN(dtype_15, i16_rod, 1, u4_rod_sat, u16_rnu, 2)
RUN(dtype_20, i32_rnu, 1, i4_rne, i8_rdn_sat, 2)
RUN(dtype_40, u4_rnu, 2, i4_rne, i8_rdn_sat, 2)
RUN(dtype_44, i4_rnu, 2, i4_rne, i8_rdn_sat, 2)
RUN(dtype_48, u4_rnu_sat, 2, i4_rne, u16_rnu, 2)
RUN(dtype_52, i4_rnu_sat, 2, i4_rne, i8_rdn_sat, 2)
RUN(dtype_60, i8_rnu_sat, 1, i4_rne, u16_rnu, 2)
RUN(dtype_65, u16_rne_sat, 1, u4_rod_sat, i8_rdn_sat, 2)
RUN(dtype_70, i16_rdn_sat, 1, i4_rne, i8_rdn_sat, 2)
RUN(dtype_75, u32_rod_sat, 1, u4_rod_sat, u16_rnu, 2)
RUN(windows_8, i8_rne_sat, 2, i4_rne, u4_rod_sat, 4)
#endif

#if TEST_UDS == 16
RUN(dtype_1, u8_rne, 2, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_6, i8_rdn, 2, i4_rne, u16_rnu, 4)
RUN(dtype_11, u16_rod, 1, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_16, u32_rnu, 1, i4_rne, i8_rdn_sat, 4)
RUN(dtype_21, i32_rne, 1, u4_rod_sat, u16_rnu, 4)
RUN(dtype_24, u64_rnu, 1, i4_rne, u16_rnu, 4)
RUN(dtype_28, i64_rnu, 1, i4_rne, i8_rdn_sat, 4)
RUN(dtype_41, u4_rne, 4, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_45, i4_rne, 4, u4_rod_sat, u16_rnu, 4)
RUN(dtype_49, u4_rne_sat, 4, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_53, i4_rne_sat, 4, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_56, u8_rnu_sat, 2, i4_rne, i8_rdn_sat, 4)
RUN(dtype_61, i8_rne_sat, 2, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_66, u16_rdn_sat, 1, i4_rne, u16_rnu, 4)
RUN(dtype_71, i16_rod_sat, 1, u4_rod_sat, i8_rdn_sat, 4)
RUN(dtype_76, i32_rnu_sat, 1, i4_rne, i8_rdn_sat, 4)
RUN(dtype_80, u64_rnu_sat, 1, i4_rne, i8_rdn_sat, 4)
RUN(dtype_84, i64_rnu_sat, 1, i4_rne, u16_rnu, 4)
RUN(windows_16, i16_rne_sat, 2, i4_rne, u4_rod_sat, 8)
RUN(wide_16_64, u16_rdn_sat, 1, i64_rod_sat, u32_rne, 1)
#endif

#if TEST_UDS == 32
RUN(dtype_2, u8_rdn, 4, i4_rne, i8_rdn_sat, 8)
RUN(dtype_7, i8_rod, 4, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_12, i16_rnu, 2, i4_rne, u16_rnu, 8)
RUN(dtype_17, u32_rne, 1, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_22, i32_rdn, 1, i4_rne, i8_rdn_sat, 8)
RUN(dtype_25, u64_rne, 1, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_29, i64_rne, 1, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_33, u128_rne, 1, u4_rod_sat, u16_rnu, 8)
RUN(dtype_36, i128_rnu, 1, i4_rne, u16_rnu, 8)
RUN(dtype_39, i128_rod, 1, u4_rod_sat, u16_rnu, 8)
RUN(dtype_42, u4_rdn, 8, i4_rne, u16_rnu, 8)
RUN(dtype_46, i4_rdn, 8, i4_rne, i8_rdn_sat, 8)
RUN(dtype_50, u4_rdn_sat, 8, i4_rne, i8_rdn_sat, 8)
RUN(dtype_54, i4_rdn_sat, 8, i4_rne, u16_rnu, 8)
RUN(dtype_57, u8_rne_sat, 4, u4_rod_sat, u16_rnu, 8)
RUN(dtype_62, i8_rdn_sat, 4, i4_rne, i8_rdn_sat, 8)
RUN(dtype_67, u16_rod_sat, 2, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_72, u32_rnu_sat, 1, i4_rne, u16_rnu, 8)
RUN(dtype_77, i32_rne_sat, 1, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_81, u64_rne_sat, 1, u4_rod_sat, u16_rnu, 8)
RUN(dtype_85, i64_rne_sat, 1, u4_rod_sat, i8_rdn_sat, 8)
RUN(dtype_90, u128_rdn_sat, 1, i4_rne, u16_rnu, 8)
RUN(dtype_93, i128_rne_sat, 1, u4_rod_sat, u16_rnu, 8)
RUN(windows_32, i32_rne_sat, 2, i4_rne, u4_rod_sat, 16)
RUN(wide_32_64, u32_rdn_sat, 1, i64_rod_sat, u32_rne, 1)
RUN(wide_32_128, u32_rdn_sat, 1, i128_rod_sat, u64_rne, 1)
#endif

#if TEST_UDS == 64
RUN(dtype_3, u8_rod, 8, u4_rod_sat, u16_rnu, 16)
RUN(dtype_8, u16_rnu, 4, i4_rne, i8_rdn_sat, 16)
RUN(dtype_13, i16_rne, 4, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_18, u32_rdn, 2, i4_rne, u16_rnu, 16)
RUN(dtype_23, i32_rod, 2, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_26, u64_rdn, 1, i4_rne, i8_rdn_sat, 16)
RUN(dtype_30, i64_rdn, 1, i4_rne, u16_rnu, 16)
RUN(dtype_34, u128_rdn, 1, i4_rne, i8_rdn_sat, 16)
RUN(dtype_37, i128_rne, 1, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_43, u4_rod, 16, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_47, i4_rod, 16, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_51, u4_rod_sat, 16, u4_rod_sat, u16_rnu, 16)
RUN(dtype_55, i4_rod_sat, 16, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_58, u8_rdn_sat, 8, i4_rne, i8_rdn_sat, 16)
RUN(dtype_63, i8_rod_sat, 8, u4_rod_sat, u16_rnu, 16)
RUN(dtype_68, i16_rnu_sat, 4, i4_rne, i8_rdn_sat, 16)
RUN(dtype_73, u32_rne_sat, 2, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_78, i32_rdn_sat, 2, i4_rne, u16_rnu, 16)
RUN(dtype_82, u64_rdn_sat, 1, i4_rne, i8_rdn_sat, 16)
RUN(dtype_86, i64_rdn_sat, 1, i4_rne, i8_rdn_sat, 16)
RUN(dtype_88, u128_rnu_sat, 1, i4_rne, i8_rdn_sat, 16)
RUN(dtype_91, u128_rod_sat, 1, u4_rod_sat, i8_rdn_sat, 16)
RUN(dtype_94, i128_rdn_sat, 1, i4_rne, i8_rdn_sat, 16)
RUN(windows_64, i64_rne_sat, 2, i4_rne, u4_rod_sat, 32)
RUN(wide_64_64, u64_rdn_sat, 1, i64_rod_sat, u32_rne, 2)
RUN(wide_64_128, u64_rdn_sat, 1, i128_rod_sat, u64_rne, 1)
#endif

#if TEST_UDS == 128
RUN(dtype_4, i8_rnu, 16, i4_rne, i8_rdn_sat, 32)
RUN(dtype_9, u16_rne, 8, u4_rod_sat, u16_rnu, 32)
RUN(dtype_14, i16_rdn, 8, i4_rne, i8_rdn_sat, 32)
RUN(dtype_19, u32_rod, 4, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_27, u64_rod, 2, u4_rod_sat, u16_rnu, 32)
RUN(dtype_31, i64_rod, 2, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_32, u128_rnu, 1, i4_rne, i8_rdn_sat, 32)
RUN(dtype_35, u128_rod, 1, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_38, i128_rdn, 1, i4_rne, i8_rdn_sat, 32)
RUN(dtype_59, u8_rod_sat, 16, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_64, u16_rnu_sat, 8, i4_rne, i8_rdn_sat, 32)
RUN(dtype_69, i16_rne_sat, 8, u4_rod_sat, u16_rnu, 32)
RUN(dtype_74, u32_rdn_sat, 4, i4_rne, i8_rdn_sat, 32)
RUN(dtype_79, i32_rod_sat, 4, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_83, u64_rod_sat, 2, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_87, i64_rod_sat, 2, u4_rod_sat, u16_rnu, 32)
RUN(dtype_89, u128_rne_sat, 1, u4_rod_sat, i8_rdn_sat, 32)
RUN(dtype_92, i128_rnu_sat, 1, i4_rne, i8_rdn_sat, 32)
RUN(dtype_95, i128_rod_sat, 1, u4_rod_sat, i8_rdn_sat, 32)
RUN(windows_128, i128_rne_sat, 2, i4_rne, u4_rod_sat, 32)
RUN(wide_128_64, u128_rdn_sat, 1, i64_rod_sat, u32_rne, 4)
RUN(wide_128_128, u128_rdn_sat, 1, i128_rod_sat, u64_rne, 2)
#endif
