/* RISC-V 'Packed SIMD' Extension intrinsics include file.
   Copyright (C) 2025 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef __RISCV_PACKED_SIMD_H
#define __RISCV_PACKED_SIMD_H

#include <stdint.h>

// #ifndef __riscv_p
// #error "Packed SIMD intrinsics require the rvp extension."
// #endif

typedef signed char int8x4_t __attribute((vector_size(4)));
typedef signed char int8x8_t __attribute((vector_size(8)));
typedef short int16x2_t __attribute((vector_size(4)));
typedef short int16x4_t __attribute__((vector_size(8)));
typedef int int32x2_t __attribute__((vector_size(8)));
typedef unsigned char uint8x4_t __attribute__((vector_size(4)));
typedef unsigned char uint8x8_t __attribute__((vector_size(8)));
typedef unsigned short uint16x2_t __attribute__((vector_size(4)));
typedef unsigned short uint16x4_t __attribute__((vector_size(8)));
typedef unsigned int uint32x2_t __attribute__((vector_size(8)));

#if __riscv_xlen == 32
typedef int32_t intXLEN_t;
typedef uint32_t uintXLEN_t;
typedef int32_t int32xN_t;
typedef uint32_t uint32xN_t;
typedef uint16x2_t uint16xN_t;
typedef int16x2_t int16xN_t;
typedef uint8x4_t uint8xN_t;
typedef int8x4_t int8xN_t;
#else
typedef int64_t intXLEN_t;
typedef uint64_t uintXLEN_t;
typedef int32x2_t int32xN_t;
typedef uint32x2_t uint32xN_t;
typedef uint16x4_t uint16xN_t;
typedef int16x4_t int16xN_t;
typedef uint8x8_t uint8xN_t;
typedef int8x8_t int8xN_t;
#endif

#define RVP_INTRINSIC_PREFIX __rv_
#define RVP_INTRINSIC_VECTOR_PREFIX __rv_v_

#define RVP_ARGUMENT_LIST(_0, _1, _2, _3, _4, _5, ...) _5
#define RVP_N_ARG(...) RVP_ARGUMENT_LIST(_, ##__VA_ARGS__, 4, 3, 2, 1, 0)

#define RVP_VAR0(...)
#define RVP_VAR1(type1) a
#define RVP_VAR2(type1, type2) RVP_VAR1(type1), b
#define RVP_VAR3(type1, type2, type3) RVP_VAR2(type1, type2), c
#define RVP_VAR4(type1, type2, type3, type4) RVP_VAR3(type1, type2, type3), d

#define RVP_ARG0(...)
#define RVP_ARG1(type1) type1 a
#define RVP_ARG2(type1, type2) RVP_ARG1(type1), type2 b
#define RVP_ARG3(type1, type2, type3) RVP_ARG2(type1, type2), type3 c
#define RVP_ARG4(type1, type2, type3, type4)                                   \
  RVP_ARG3(type1, type2, type3), type4 d

#define RVP_CONCAT_IMPL(x, y) x##y
#define RVP_CONCAT(x, y) RVP_CONCAT_IMPL(x, y)
#define RVP_EXPAND_ARGS(...)                                                   \
  RVP_CONCAT(RVP_ARG, RVP_N_ARG(__VA_ARGS__))(__VA_ARGS__)
#define RVP_EXPAND_VARS(...)                                                   \
  RVP_CONCAT(RVP_VAR, RVP_N_ARG(__VA_ARGS__))(__VA_ARGS__)

#define RVP_VECTOR_BUILTIN_PREFIX __builtin_riscv_v_

#define CREATE_RVP_INTRINSIC(return_type, name, ...)                           \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, name, __rv_,                  \
                              __builtin_riscv_, RVP_EXPAND_ARGS,               \
                              RVP_EXPAND_VARS, __VA_ARGS__)

#define CREATE_RVP_INTRINSIC_ALIAS(return_type, name, internal_name, ...)      \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, internal_name, __rv_,         \
                              __builtin_riscv_, RVP_EXPAND_ARGS,               \
                              RVP_EXPAND_VARS, __VA_ARGS__)

/* RVP_N_ARG() expands to 0 in c89 */
#define CREATE_RVP_INTRINSIC_EMPTY_ARGS(return_type, name, ...)                \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, name, RVP_INTRINSIC_PREFIX,   \
                              __builtin_riscv_, RVP_ARG0, RVP_VAR0,            \
                              __VA_ARGS__)

#define CREATE_RVP_INTRINSIC_VECTOR(return_type, name, ...)                    \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, name,                         \
                              RVP_INTRINSIC_VECTOR_PREFIX,                     \
                              RVP_VECTOR_BUILTIN_PREFIX, RVP_EXPAND_ARGS,      \
                              RVP_EXPAND_VARS, __VA_ARGS__)

#define CREATE_RVP_INTRINSIC_VECTOR_ALIAS(return_type, name, internal_name,    \
                                          ...)                                 \
  DIRECT_CREATE_RVP_INTRINSIC(return_type, name, internal_name,                \
                              RVP_INTRINSIC_VECTOR_PREFIX,                     \
                              RVP_VECTOR_BUILTIN_PREFIX, RVP_EXPAND_ARGS,      \
                              RVP_EXPAND_VARS, __VA_ARGS__)

#define DIRECT_CREATE_RVP_INTRINSIC(return_type, name, internal_name,          \
                                    intrisic_prefix, builtin_prefix,           \
                                    arg_expand_macro, var_expand_macro, ...)   \
  __extension__ extern __inline                                                \
      __attribute__((__always_inline__, __gnu_inline__, __artificial__))       \
      return_type                                                              \
      RVP_CONCAT(intrisic_prefix, name(arg_expand_macro(__VA_ARGS__))) {       \
    return RVP_CONCAT(builtin_prefix,                                          \
                      internal_name)(var_expand_macro(__VA_ARGS__));           \
  }


#ifdef __cplusplus
extern "C" {
#endif

// #if defined (__riscv_rvp)

CREATE_RVP_INTRINSIC(int8xN_t, pslli_b, int8xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pslli_h, int16xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psslai_h, int16xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pli_b, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pli_h, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psext_h_b, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, plui_h, intXLEN_t)
CREATE_RVP_INTRINSIC(int8xN_t, psll_bs, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psll_hs, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, padd_bs, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, padd_hs, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pssha_hs, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psshar_hs, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, psrli_b, int8xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psrli_h, int16xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, pusati_h, uintXLEN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, usati, uintXLEN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int8xN_t, psrai_b, int8xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psrai_h, int16xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psrari_h, int16xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(intXLEN_t, srari, intXLEN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psati_h, int16xN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(intXLEN_t, sati, intXLEN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, psrl_bs, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, psrl_hs, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, predsum_bs, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, predsum_hs, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, predsumu_bs, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, predsumu_hs, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, psra_bs, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psra_hs, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, padd_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, padd_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, psadd_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psadd_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, paadd_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, paadd_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, psaddu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, psaddu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, paaddu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, paaddu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, psub_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psub_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pssub_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pssub_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pasub_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pasub_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pssubu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pssubu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pasubu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pasubu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pdif_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pdifu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pdif_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pdifu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int32xN_t, slx, int32xN_t, int32xN_t)
CREATE_RVP_INTRINSIC(int32xN_t, srx, int32xN_t, int32xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmul_h_b01, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmulu_h_b01, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, mvm, uintXLEN_t, uintXLEN_t, uintXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, mvmn, uintXLEN_t, uintXLEN_t, uintXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, merge, uintXLEN_t, uintXLEN_t, uintXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, pdifsumu_b, uintXLEN_t, uintXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, pdifsumau_b, uintXLEN_t, uintXLEN_t, uintXLEN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psh1add_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pssh1sadd_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmul_h_b00, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmul_h_b11, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmulu_h_b00, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmulu_h_b11, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulsu_h_b00, int8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulsu_h_b11, int8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, ppack_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, ppackbt_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int32xN_t, packbt, int32xN_t, int32xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, ppacktb_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int32xN_t, packtb, int32xN_t, int32xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, ppackt_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int32xN_t, packt, int32xN_t, int32xN_t)

CREATE_RVP_INTRINSIC(int16xN_t, pm2add_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pm4add_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2adda_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pm4adda_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2add_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2adda_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pm2addu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pm4addu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pm2addau_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pm4addau_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmq2add_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmqr2add_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmq2adda_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmqr2adda_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2sub_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2sadd_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2suba_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2sub_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2sadd_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pm2suba_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pm2addsu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pm4addsu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pm2addasu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pm4addasu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, mqacc_h01, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, mqracc_h01, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pas_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psa_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, psas_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pssa_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, paas_hx, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pasa_hx, int16xN_t, int16xN_t)

CREATE_RVP_INTRINSIC(int8xN_t, pmseq_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmseq_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pmslt_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmslt_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pmsltu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmsltu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pmin_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmin_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pminu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pminu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int8xN_t, pmax_b, int8xN_t, int8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmax_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint8xN_t, pmaxu_b, uint8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmaxu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulh_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulh_h_b0, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulh_h_b1, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmulhu_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulhr_h, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmulhru_h, uint16xN_t, uint16xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulhsu_h, int8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulhsu_h_b0, int8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(int16xN_t, pmulhsu_h_b1, int8xN_t, uint8xN_t)
CREATE_RVP_INTRINSIC(uint16xN_t, pmulhrsu_h, uint16xN_t, uint16xN_t)


#if __riscv_xlen == 32

CREATE_RVP_INTRINSIC(int32_t, sslai, int32_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int32_t, ssha, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, sshar, sshar, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, sadd, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, aadd, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, ssub, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, asub, int32_t, int32_t)
CREATE_RVP_INTRINSIC(uint32_t, ssubu, uint32_t, uint32_t)
CREATE_RVP_INTRINSIC(uint32_t, asubu, uint32_t, uint32_t)
CREATE_RVP_INTRINSIC(int16x2_t, mul_h01, int16x2_t, int16x2_t)
CREATE_RVP_INTRINSIC(uint16x2_t, mulu_h01, uint16x2_t, uint16x2_t)
CREATE_RVP_INTRINSIC(int16x2_t, macc_h01, int16x2_t, int16x2_t, int16x2_t)
CREATE_RVP_INTRINSIC(uint16x2_t, maccu_h01, uint16x2_t, uint16x2_t, uint16x2_t)
CREATE_RVP_INTRINSIC(int32_t, psh1sadd, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int16x2_t, mul_h00, int8x4_t, int8x4_t)
CREATE_RVP_INTRINSIC(int16x2_t, mul_h11, int8x4_t, int8x4_t)
CREATE_RVP_INTRINSIC(uint16x2_t, mulu_h00, uint8x4_t, uint8x4_t)
CREATE_RVP_INTRINSIC(uint16x2_t, mulu_h11, uint8x4_t, uint8x4_t)
CREATE_RVP_INTRINSIC(int16x2_t, mulsu_h00, int8x4_t, uint8x4_t)
CREATE_RVP_INTRINSIC(int16x2_t, mulsu_h11, int8x4_t, uint8x4_t)
CREATE_RVP_INTRINSIC(int32_t, mseq, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, mslt, int32_t, int32_t)
CREATE_RVP_INTRINSIC(uint32_t, msltu, uint32_t, uint32_t)
CREATE_RVP_INTRINSIC(int16x2_t, mulh_h1, int16x2_t, int16x2_t)
CREATE_RVP_INTRINSIC(int32_t, mulhr, int32_t, int32_t)
CREATE_RVP_INTRINSIC(uint32_t, mulhru, uint32_t, uint32_t)
CREATE_RVP_INTRINSIC(int16x2_t, mulh_h0, int16x2_t, int16x2_t)
CREATE_RVP_INTRINSIC(int16x2_t, mulhsu_h0, int16x2_t, uint16x2_t)
CREATE_RVP_INTRINSIC(int16x2_t, mulhsu_h1, int16x2_t, uint16x2_t)
CREATE_RVP_INTRINSIC(uint32_t, mulhrsu, uint32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pli_db, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pli_dh, int32_t)
CREATE_RVP_INTRINSIC(int64_t, plui_dh, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwslli_b, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwslli_h, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wslli, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwslai_b, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwslai_h, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wslai, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwsll_bs, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwsll_hs, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wsll, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwsla_bs, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwsla_hs, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wsla, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wzip8p, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wzip16p, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwadd_b, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwadd_h, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wadd, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwadda_b, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwadda_h, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, wadda, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwaddu_b, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwaddu_h, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, waddu, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwaddau_b, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pwaddau_h, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, waddau, int32_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, predsum_dbs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, predsum_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, predsumu_dbs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, predsumu_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnsrli_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnsrli_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nsrli, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipiu_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipiu_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipiu, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipriu_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipriu_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipriu, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnsrai_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnsrai_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nsrai, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnsrari_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnsrari_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nsrari, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipi_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipi_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipi, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipri_b, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipri_h, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipri, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipu_bs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipu_hs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipu, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipru_bs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipru_hs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipru, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclip_bs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclip_hs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclip, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipr_bs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, pnclipr_hs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int32_t, nclipr, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pslli_db, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pslli_dh, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pslli_dw, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psll_dbs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psll_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psll_dws, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psslai_dh, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psslai_dw, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pssha_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, pssha_dws, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psshar_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psshar_dws, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psrl_dbs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psrl_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psrl_dws, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psra_dbs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psra_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psra_dws, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, psext_dh_b, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psext_dw_b, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psext_dw_h, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psabs_db, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psabs_dh, int64_t)
CREATE_RVP_INTRINSIC(int64_t, padd_dbs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, padd_dhs, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, padd_dws, int64_t, int32_t)
CREATE_RVP_INTRINSIC(int64_t, padd_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, padd_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, padd_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, addd, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psadd_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psadd_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psadd_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paadd_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paadd_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paadd_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psaddu_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psaddu_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psaddu_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paaddu_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paaddu_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paaddu_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psub_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psub_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psub_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, subd, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppack_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppack_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppackbt_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppackbt_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppacktb_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppacktb_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppackt_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, ppackt_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pas_dhx, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psa_dhx, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, psas_dhx, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pssa_dhx, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, paas_dhx, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pasa_dhx, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmseq_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmseq_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmseq_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmslt_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmslt_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmslt_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmsltu_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmsltu_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmsltu_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmin_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmin_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmin_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pminu_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pminu_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pminu_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmax_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmax_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmax_dw, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmaxu_db, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmaxu_dh, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, pmaxu_dw, int64_t, int64_t)

#endif

#if __riscv_xlen == 64

CREATE_RVP_INTRINSIC(int32x2_t, pslli_w, int32x2_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int32x2_t, psslai_w, int32x2_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int32x2_t, pli_w, intXLEN_t)
CREATE_RVP_INTRINSIC(int32x2_t, psext_w_b, int8x8_t)
CREATE_RVP_INTRINSIC(int32x2_t, psext_w_h, int16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, plui_w, intXLEN_t)
CREATE_RVP_INTRINSIC(int32x2_t, psll_ws, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, padd_ws, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pssha_ws, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, sha, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psshar_ws, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, shar, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psrli_w, int32x2_t, intXLEN_t)
CREATE_RVP_INTRINSIC(uintXLEN_t, pusati_w, uintXLEN_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int32x2_t, psrari_w, int32x2_t, intXLEN_t)
CREATE_RVP_INTRINSIC(int32x2_t, psati_w, int32x2_t, intXLEN_t)
CREATE_RVP_INTRINSIC(uint32x2_t, psrl_ws, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, predsum_ws, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, predsumu_ws, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psra_ws, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, padd_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psadd_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, paadd_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, psaddu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, paaddu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psub_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pssub_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pasub_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pssubu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pasubu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmul_w_h01, int16x4_t, int16x4_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pmulu_w_h01, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, mul_w01, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, mulu_w01, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmacc_w_h01, int16x4_t, int16x4_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pmaccu_w_h01, uint16x4_t, uint16x4_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, macc_w01, int32x2_t, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, maccu_w01, uint32x2_t, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psh1add_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pssh1sadd_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int64_t, unzip8p, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, unzip16p, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, unzip8hp, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, unzip16hp, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, zip8p, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, zip16p, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, zip8hp, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int64_t, zip16hp, int64_t, int64_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmul_w_h00, int16x4_t, int16x4_t)
CREATE_RVP_INTRINSIC(int32xN_t, pmul_w_h11, int16xN_t, int16xN_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pmulu_w_h00, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pmulu_w_h11, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmulsu_w_h00, int16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmulsu_w_h11, int16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, mul_w00, int16x4_t, int16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, mul_w11, int16x4_t, int16x4_t)
CREATE_RVP_INTRINSIC(uint32x2_t, mulu_w00, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(uint32x2_t, mulu_w11, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, mulsu_w00, int16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, mulsu_w11, int16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, ppack_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, ppackbt_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, ppacktb_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, ppackt_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2add_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int16x4_t, pm4add_h, int16x4_t, int16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2adda_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int16x4_t, pm4adda_h, int16x4_t, int16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2add_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2adda_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pm2addu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(uint16x4_t, pm4addu_h, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pm2addau_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(uint16x4_t, pm4addau_h, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmq2add_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmqr2add_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmq2adda_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmqr2adda_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2sub_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2suba_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2sub_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pm2suba_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pm2addsu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(uint16x4_t, pm4addsu_h, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pm2addasu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(uint16x4_t, pm4addasu_h, uint16x4_t, uint16x4_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmqacc_w_h01, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmqracc_w_h01, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, mqacc_w01, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, mqracc_w01, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pas_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psa_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, psas_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pssa_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, paas_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pasa_wx, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmseq_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmslt_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pmsltu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmin_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pminu_w, uint32x2_t, uint32x2_t)
CREATE_RVP_INTRINSIC(int32x2_t, pmax_w, int32x2_t, int32x2_t)
CREATE_RVP_INTRINSIC(uint32x2_t, pmaxu_w, uint32x2_t, uint32x2_t)


#endif

// #endif // __riscvrvp

#if defined (__cplusplus)
}
#endif // __cplusplus
#endif // __RISCV_PACKED_SIMD_H
