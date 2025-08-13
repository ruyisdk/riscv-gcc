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

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__riscv_rvp)

#if __riscv_xlen == 32

#ifdef __OPTIMIZE__

extern __inline uint32_t
__attribute__ ((__gnu_inline__, __always_inline__, __artificial__))
__riscv_psll_bs (uint32_t rs1, uint32_t rs2)
{
  return __builtin_riscv_psll_bs (rs1,rs2);
}

#else
#define __riscv_psll_bs(x, y) __builtin_riscv_psll_bs (x, y)
#endif

#endif

#if __riscv_xlen == 64

extern __inline uint64_t
__attribute__ ((__gnu_inline__, __always_inline__, __artificial__))
__riscv_psll_bs (uint64_t rs1, uint64_t rs2)
{
  return __builtin_riscv_psll_bs (rs1,rs2);
}

#if defined (__cplusplus)
}
#endif // __cplusplus
#endif // __RISCV_PACKED_SIMD_H
