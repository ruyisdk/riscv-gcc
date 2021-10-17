/* Definition of RISC-V target for GNU compiler.
   Copyright (C) 2011-2018 Free Software Foundation, Inc.
   Contributed by Andrew Waterman (andrew@sifive.com).
   Based on MIPS target for GNU compiler.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_RISCV_V_H
#define GCC_RISCV_V_H

#define TARGET_XTHEAD_VECTOR TARGET_VECTOR
#define TARGET_XTHEAD_VLEN(BITS) (TARGET_XTHEAD_VECTOR && riscv_vlen == VLEN_##BITS )

#define TARGET_XTHEAD_VSPLIT reload_completed

#define TARGET_XTHEAD_VSPN true

#define V_REG_FIRST 66
#define V_REG_LAST  97
#define V_REG_NUM   (V_REG_LAST - V_REG_FIRST + 1)

#define V_REG_RESERVE_FIRST 98
#define V_REG_RESERVE_LAST  105
#define V_REG_RESERVE_NUM   (V_REG_RESERVE_LAST - V_REG_RESERVE_FIRST + 1)

#define MAX_ARGS_IN_VREGISTERS (TARGET_RVE ? 8 : 16)

#define VR_ARG_FIRST  (V_REG_FIRST + 8)
#define VR_ARG_LAST   (VR_ARG_FIRST + MAX_ARGS_IN_VREGISTERS - 1)

#define UNITS_PER_VR_REG (riscv_vlen / 8)

/* The largest type that can be passed in vector registers.  */
#define UNITS_PER_VR_ARG ( \
    (riscv_abi == ABI_LP64V || riscv_abi == ABI_LP64DV) ? UNITS_PER_VR_REG * 8 \
			   : 0)

#define VR_RETURN (UNITS_PER_VR_ARG == 0 ? GP_RETURN : VR_ARG_FIRST)

#define VR_REG_P(REGNO) \
  ((unsigned int) ((int) (REGNO) - V_REG_FIRST) < V_REG_NUM)

#define VR_RESERVE_REG_P(REGNO) \
  ((unsigned int) ((int) (REGNO) - V_REG_RESERVE_FIRST) < V_REG_RESERVE_NUM)

#define VSEW_IMM 3
#define VLMUL_IMM 2

#define VSEW_REACH (1LL << VSEW_IMM)
#define VLMUL_REACH (1LL << VLMUL_IMM)

/* True if VALUE is unsigned 3-bit number， for vsew*/
#define SMALL_OPERAND_UNSIGNED3(VALUE) \
  (((VALUE) & ~(unsigned HOST_WIDE_INT) 0x7) == 0)

/* True if VALUE is unsigned 2-bit number, for vlmul*/
#define SMALL_OPERAND_UNSIGNED2(VALUE) \
  (((VALUE) & ~(unsigned HOST_WIDE_INT) 0x3) == 0)

typedef enum {
    RVV_E8 = 0,
    RVV_E16,
    RVV_E32,
    RVV_E64
} RISCV_VSEW_T;

#endif
