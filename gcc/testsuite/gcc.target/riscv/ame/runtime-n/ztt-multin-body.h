/* runtime-N boundary tests.  */

#include <stdint.h>
#include <riscv_ztt.h>

#if TEST_WIDTH == 8
typedef uint8_t carrier;
typedef __riscv_ztt_u8_rnu_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_u8_rnu_1x1
#define ADD __riscv_ztt_madd_ew_u8_rnu_1x1
#elif TEST_WIDTH == 16
typedef uint16_t carrier;
typedef __riscv_ztt_u16_rnu_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_u16_rnu_1x1
#define ADD __riscv_ztt_madd_ew_u16_rnu_1x1
#elif TEST_WIDTH == 32
typedef uint32_t carrier;
typedef __riscv_ztt_u32_rnu_1x1_t matrix;
#define LOAD __riscv_ztt_mls_rm_u32_rnu_1x1
#define ADD __riscv_ztt_madd_ew_u32_rnu_1x1
#else
#error unsupported TEST_WIDTH
#endif

#define DECL(N) matrix v##N = LOAD (in[N])
#define STORE(N) __riscv_ztt_mss_rm (out[N], v##N)

/* Exceed even M=32: 33 one-M, 17 two-M, or 9 four-M live values.
   The values cannot be array elements because their types are sizeless.  */
#ifdef __cplusplus
extern "C"
#endif
void
multin_test (const carrier *const *in, carrier *const *out)
{
  DECL (0);
  DECL (1);
  DECL (2);
  DECL (3);
  DECL (4);
  DECL (5);
  DECL (6);
  DECL (7);
  DECL (8);
#if TEST_WIDTH <= 16
  DECL (9);
  DECL (10);
  DECL (11);
  DECL (12);
  DECL (13);
  DECL (14);
  DECL (15);
  DECL (16);
#endif
#if TEST_WIDTH == 8
  DECL (17);
  DECL (18);
  DECL (19);
  DECL (20);
  DECL (21);
  DECL (22);
  DECL (23);
  DECL (24);
  DECL (25);
  DECL (26);
  DECL (27);
  DECL (28);
  DECL (29);
  DECL (30);
  DECL (31);
  DECL (32);
#endif

  __asm__ volatile ("" ::: "memory");
  v0 = ADD (v0, v1);

  STORE (0);
  STORE (1);
  STORE (2);
  STORE (3);
  STORE (4);
  STORE (5);
  STORE (6);
  STORE (7);
  STORE (8);
#if TEST_WIDTH <= 16
  STORE (9);
  STORE (10);
  STORE (11);
  STORE (12);
  STORE (13);
  STORE (14);
  STORE (15);
  STORE (16);
#endif
#if TEST_WIDTH == 8
  STORE (17);
  STORE (18);
  STORE (19);
  STORE (20);
  STORE (21);
  STORE (22);
  STORE (23);
  STORE (24);
  STORE (25);
  STORE (26);
  STORE (27);
  STORE (28);
  STORE (29);
  STORE (30);
  STORE (31);
  STORE (32);
#endif
}
