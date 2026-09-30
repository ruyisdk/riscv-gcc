/* integer
   1x1 types with UDS=8.  Wider elements own a complete 2/4-M group.  */

#include <stdint.h>
#include <riscv_ztt.h>

void
pressure_i16 (const int16_t *const *in, int16_t *const *out)
{
  __riscv_ztt_i16_rnu_1x1_t v0
    = __riscv_ztt_mls_rm_i16_rnu_1x1 (in[0]);
  __riscv_ztt_i16_rne_1x1_t v1
    = __riscv_ztt_mls_rm_i16_rne_1x1 (in[1]);
  __riscv_ztt_i16_rdn_1x1_t v2
    = __riscv_ztt_mls_rm_i16_rdn_1x1 (in[2]);
  __riscv_ztt_i16_rod_1x1_t v3
    = __riscv_ztt_mls_rm_i16_rod_1x1 (in[3]);
  __riscv_ztt_i16_rnu_1x1_t v4
    = __riscv_ztt_mls_rm_i16_rnu_1x1 (in[4]);
  __riscv_ztt_i16_rne_1x1_t v5
    = __riscv_ztt_mls_rm_i16_rne_1x1 (in[5]);
  __riscv_ztt_i16_rdn_1x1_t v6
    = __riscv_ztt_mls_rm_i16_rdn_1x1 (in[6]);
  __riscv_ztt_i16_rod_1x1_t v7
    = __riscv_ztt_mls_rm_i16_rod_1x1 (in[7]);
  __riscv_ztt_i16_rnu_1x1_t v8
    = __riscv_ztt_mls_rm_i16_rnu_1x1 (in[8]);

  __asm__ volatile ("" ::: "memory");

  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
  __riscv_ztt_mss_rm (out[5], v5);
  __riscv_ztt_mss_rm (out[6], v6);
  __riscv_ztt_mss_rm (out[7], v7);
  __riscv_ztt_mss_rm (out[8], v8);
}

void
pressure_u16 (const uint16_t *const *in, uint16_t *const *out)
{
  __riscv_ztt_u16_rnu_1x1_t v0
    = __riscv_ztt_mls_rm_u16_rnu_1x1 (in[0]);
  __riscv_ztt_u16_rne_1x1_t v1
    = __riscv_ztt_mls_rm_u16_rne_1x1 (in[1]);
  __riscv_ztt_u16_rdn_1x1_t v2
    = __riscv_ztt_mls_rm_u16_rdn_1x1 (in[2]);
  __riscv_ztt_u16_rod_1x1_t v3
    = __riscv_ztt_mls_rm_u16_rod_1x1 (in[3]);
  __riscv_ztt_u16_rnu_1x1_t v4
    = __riscv_ztt_mls_rm_u16_rnu_1x1 (in[4]);
  __riscv_ztt_u16_rne_1x1_t v5
    = __riscv_ztt_mls_rm_u16_rne_1x1 (in[5]);
  __riscv_ztt_u16_rdn_1x1_t v6
    = __riscv_ztt_mls_rm_u16_rdn_1x1 (in[6]);
  __riscv_ztt_u16_rod_1x1_t v7
    = __riscv_ztt_mls_rm_u16_rod_1x1 (in[7]);
  __riscv_ztt_u16_rnu_1x1_t v8
    = __riscv_ztt_mls_rm_u16_rnu_1x1 (in[8]);

  __asm__ volatile ("" ::: "memory");

  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
  __riscv_ztt_mss_rm (out[5], v5);
  __riscv_ztt_mss_rm (out[6], v6);
  __riscv_ztt_mss_rm (out[7], v7);
  __riscv_ztt_mss_rm (out[8], v8);
}

void
pressure_i32 (const int32_t *const *in, int32_t *const *out)
{
  __riscv_ztt_i32_rnu_1x1_t v0
    = __riscv_ztt_mls_rm_i32_rnu_1x1 (in[0]);
  __riscv_ztt_i32_rne_1x1_t v1
    = __riscv_ztt_mls_rm_i32_rne_1x1 (in[1]);
  __riscv_ztt_i32_rdn_1x1_t v2
    = __riscv_ztt_mls_rm_i32_rdn_1x1 (in[2]);
  __riscv_ztt_i32_rod_1x1_t v3
    = __riscv_ztt_mls_rm_i32_rod_1x1 (in[3]);
  __riscv_ztt_i32_rnu_1x1_t v4
    = __riscv_ztt_mls_rm_i32_rnu_1x1 (in[4]);

  __asm__ volatile ("" ::: "memory");

  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
}

void
pressure_u32 (const uint32_t *const *in, uint32_t *const *out)
{
  __riscv_ztt_u32_rnu_1x1_t v0
    = __riscv_ztt_mls_rm_u32_rnu_1x1 (in[0]);
  __riscv_ztt_u32_rne_1x1_t v1
    = __riscv_ztt_mls_rm_u32_rne_1x1 (in[1]);
  __riscv_ztt_u32_rdn_1x1_t v2
    = __riscv_ztt_mls_rm_u32_rdn_1x1 (in[2]);
  __riscv_ztt_u32_rod_1x1_t v3
    = __riscv_ztt_mls_rm_u32_rod_1x1 (in[3]);
  __riscv_ztt_u32_rnu_1x1_t v4
    = __riscv_ztt_mls_rm_u32_rnu_1x1 (in[4]);

  __asm__ volatile ("" ::: "memory");

  __riscv_ztt_mss_rm (out[0], v0);
  __riscv_ztt_mss_rm (out[1], v1);
  __riscv_ztt_mss_rm (out[2], v2);
  __riscv_ztt_mss_rm (out[3], v3);
  __riscv_ztt_mss_rm (out[4], v4);
}

void
mixed_widths (const uint8_t *a, const int16_t *b, const uint32_t *c,
	      uint8_t *x, int16_t *y, uint32_t *z)
{
  __riscv_ztt_u8_rnu_1x1_t v0 = __riscv_ztt_mls_rm_u8_rnu_1x1 (a);
  __riscv_ztt_i16_rdn_1x1_t v1 = __riscv_ztt_mls_rm_i16_rdn_1x1 (b);
  __riscv_ztt_u32_rod_1x1_t v2 = __riscv_ztt_mls_rm_u32_rod_1x1 (c);
  __asm__ volatile ("" : "+Wmr" (v0), "+Wmr" (v1), "+Wmr" (v2));
  __riscv_ztt_mss_rm (x, v0);
  __riscv_ztt_mss_rm (y, v1);
  __riscv_ztt_mss_rm (z, v2);
}

void
copy_u32 (const uint32_t *in, uint32_t *out, uint32_t *other)
{
  __riscv_ztt_u32_rnu_1x1_t a = __riscv_ztt_mls_rm_u32_rnu_1x1 (in);
  __riscv_ztt_u32_rnu_1x1_t b = a;
  __asm__ volatile ("" : "+Wmr" (b));
  __riscv_ztt_mss_rm (out, a);
  __riscv_ztt_mss_rm (other, b);
}
