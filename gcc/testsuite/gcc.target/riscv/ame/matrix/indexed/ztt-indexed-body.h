/* basic-square indexed API.  */
#include <stdint.h>
#include <riscv_ztt.h>

#if __riscv_ztt_mcolgather_ew_int != 1 \
    || __riscv_ztt_mrowgather_ew_int != 1 \
    || __riscv_ztt_mcolscatadd_ew_int != 1 \
    || __riscv_ztt_mrowscatadd_ew_int != 1 \
    || __riscv_ztt_mcolscatmax_ew_int != 1 \
    || __riscv_ztt_mrowscatmax_ew_int != 1
#error missing integer indexed support
#endif

#define C_i8 int8_t
#define C_u8 uint8_t
#define C_i16 int16_t
#define C_u16 uint16_t
#define C_i32 int32_t
#define C_u32 uint32_t
#define C_(T) C_##T
#define C(T) C_(T)
#define TYPE_(T, RM) __riscv_ztt_##T##_##RM##_1x1_t
#define TYPE(T, RM) TYPE_(T, RM)
#define OP_(F, T, RM) __riscv_ztt_##F##_##T##_##RM##_1x1
#define OP(F, T, RM) OP_(F, T, RM)
#define DEFAULT_(F, T) __riscv_ztt_##F##_##T##_1x1
#define DEFAULT(F, T) DEFAULT_(F, T)

#define GATHER(F, NAME, D, DR, A, AR, I, IR) \
  void F##_##NAME (C(D) *out, const C(D) *input, const C(I) *indices, \
                  C(D) *copy, C(I) *index_copy) \
  { \
    TYPE(D, DR) data = OP(mls_rm, D, DR) (input); \
    TYPE(I, IR) index = OP(mls_rm, I, IR) (indices); \
    TYPE(D, DR) result = OP(F, D, DR) (data, index); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (copy, data); \
    __riscv_ztt_mss_rm (index_copy, index); \
  }
#define SCATTER(F, NAME, D, DR, A, AR, I, IR) \
  void F##_##NAME (C(D) *out, const C(D) *old_input, const C(A) *input, \
                  const C(I) *indices, C(D) *old_copy, C(A) *copy, \
                  C(I) *index_copy) \
  { \
    TYPE(D, DR) old_d = OP(mls_rm, D, DR) (old_input); \
    TYPE(A, AR) data = OP(mls_rm, A, AR) (input); \
    TYPE(I, IR) index = OP(mls_rm, I, IR) (indices); \
    TYPE(D, DR) result = OP(F, D, DR) (old_d, data, index); \
    __riscv_ztt_mss_rm (out, result); \
    __riscv_ztt_mss_rm (old_copy, old_d); \
    __riscv_ztt_mss_rm (copy, data); \
    __riscv_ztt_mss_rm (index_copy, index); \
  }

#if __riscv_ztt_uds == 8
#define EXTRA(F, B) \
  B(F, narrow, i8, rnu, u32, rod, i16, rdn) \
  B(F, byte, u8, rod, i8, rne, i32, rnu)
#else
#define EXTRA(F, B)
#endif
#if __riscv_ztt_uds <= 16
#define WORD(F, B) \
  B(F, signed_word, i16, rdn, u16, rnu, u32, rod) \
  B(F, unsigned_word, u16, rne, i32, rdn, i16, rnu)
#else
#define WORD(F, B)
#endif
#define FAMILY(F, B) \
  B(F, signed, i32, rod, u32, rnu, u32, rdn) \
  B(F, unsigned, u32, rne, i32, rod, i32, rnu) \
  B(F, same, i32, rnu, i32, rnu, i32, rnu) \
  B(F, rounded, u32, rdn, u32, rne, u32, rod) \
  EXTRA(F, B) \
  WORD(F, B)

FAMILY(mcolgather_ew, GATHER)
FAMILY(mrowgather_ew, GATHER)
FAMILY(mcolscatadd_ew, SCATTER)
FAMILY(mrowscatadd_ew, SCATTER)
FAMILY(mcolscatmax_ew, SCATTER)
FAMILY(mrowscatmax_ew, SCATTER)

/* One value supplies multiple logical inputs, and remains live afterward.  */
#define ALIAS_GATHER(F) \
  void F##_alias (int32_t *out, const int32_t *input, int32_t *copy) \
  { \
    TYPE(i32, rnu) a = OP(mls_rm, i32, rnu) (input); \
    TYPE(i32, rnu) d = DEFAULT(F, i32) (a, a); \
    __riscv_ztt_mss_rm (out, d); \
    __riscv_ztt_mss_rm (copy, a); \
  }
#define ALIAS_SCATTER(F) \
  void F##_alias (int32_t *out, const int32_t *input, int32_t *copy) \
  { \
    TYPE(i32, rnu) a = OP(mls_rm, i32, rnu) (input); \
    TYPE(i32, rnu) d = DEFAULT(F, i32) (a, a, a); \
    __riscv_ztt_mss_rm (out, d); \
    __riscv_ztt_mss_rm (copy, a); \
  }
ALIAS_GATHER(mcolgather_ew)
ALIAS_GATHER(mrowgather_ew)
ALIAS_SCATTER(mcolscatadd_ew)
ALIAS_SCATTER(mrowscatadd_ew)
ALIAS_SCATTER(mcolscatmax_ew)
ALIAS_SCATTER(mrowscatmax_ew)
