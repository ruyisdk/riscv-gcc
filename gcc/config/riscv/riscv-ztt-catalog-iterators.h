/* Ordered iterators for the RISC-V Ztt builtin catalogs.
   Copyright (C) 2026 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3, or (at your option) any later
   version.

   GCC is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifndef GCC_RISCV_ZTT_CATALOG_ITERATORS_H
#define GCC_RISCV_ZTT_CATALOG_ITERATORS_H

/* These are ordered catalog axes, not availability predicates.  Expanding
   an axis does not imply hardware support.  Keep its order stable: the
   canonical catalogs also define builtin codes used by LTO.  Callbacks
   take an enum token, a spelling token, and caller-supplied context.
   SAT/NSAT are either empty or the paired suffixes _SAT/_sat.  */
#define ZTT_CATALOG_INT_RMS(APPLY, TYPE, NAME, SAT, NSAT, ...) \
  APPLY (TYPE##_RNU##SAT, NAME##_rnu##NSAT, __VA_ARGS__) \
  APPLY (TYPE##_RNE##SAT, NAME##_rne##NSAT, __VA_ARGS__) \
  APPLY (TYPE##_RDN##SAT, NAME##_rdn##NSAT, __VA_ARGS__) \
  APPLY (TYPE##_ROD##SAT, NAME##_rod##NSAT, __VA_ARGS__)

#define ZTT_CATALOG_FP_RMS(APPLY, TYPE, NAME, ...) \
  APPLY (TYPE##_RNE, NAME##_rne, __VA_ARGS__) \
  APPLY (TYPE##_RTZ, NAME##_rtz, __VA_ARGS__) \
  APPLY (TYPE##_RDN, NAME##_rdn, __VA_ARGS__) \
  APPLY (TYPE##_RUP, NAME##_rup, __VA_ARGS__) \
  APPLY (TYPE##_RMM, NAME##_rmm, __VA_ARGS__) \
  APPLY (TYPE##_RNO, NAME##_rno, __VA_ARGS__)

#define ZTT_CATALOG_M_SHAPES(APPLY, TYPE, NAME, ...) \
  APPLY (TYPE##_1X1, NAME##_1x1, __VA_ARGS__) \
  APPLY (TYPE##_1X2, NAME##_1x2, __VA_ARGS__) \
  APPLY (TYPE##_2X1, NAME##_2x1, __VA_ARGS__) \
  APPLY (TYPE##_1X4, NAME##_1x4, __VA_ARGS__) \
  APPLY (TYPE##_4X1, NAME##_4x1, __VA_ARGS__) \
  APPLY (TYPE##_1X8, NAME##_1x8, __VA_ARGS__) \
  APPLY (TYPE##_8X1, NAME##_8x1, __VA_ARGS__) \
  APPLY (TYPE##_1X16, NAME##_1x16, __VA_ARGS__) \
  APPLY (TYPE##_16X1, NAME##_16x1, __VA_ARGS__) \
  APPLY (TYPE##_1X32, NAME##_1x32, __VA_ARGS__) \
  APPLY (TYPE##_32X1, NAME##_32x1, __VA_ARGS__)

#define ZTT_CATALOG_FP_TYPES(APPLY, ...) \
  ZTT_CATALOG_FP_RMS (APPLY, F16, f16, __VA_ARGS__) \
  ZTT_CATALOG_FP_RMS (APPLY, BF16, bf16, __VA_ARGS__) \
  ZTT_CATALOG_FP_RMS (APPLY, F32, f32, __VA_ARGS__) \
  ZTT_CATALOG_FP_RMS (APPLY, F64, f64, __VA_ARGS__)

#define ZTT_CATALOG_INT_TYPES(APPLY, SAT, NSAT, ...) \
  ZTT_CATALOG_INT_RMS (APPLY, I4, i4, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, U4, u4, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, I8, i8, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, U8, u8, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, I16, i16, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, U16, u16, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, I32, i32, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, U32, u32, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, I64, i64, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, U64, u64, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, I128, i128, SAT, NSAT, __VA_ARGS__) \
  ZTT_CATALOG_INT_RMS (APPLY, U128, u128, SAT, NSAT, __VA_ARGS__)

#define ZTT_CATALOG_ALL_TYPES(APPLY, ...) \
  ZTT_CATALOG_INT_TYPES (APPLY, , , __VA_ARGS__) \
  ZTT_CATALOG_INT_TYPES (APPLY, _SAT, _sat, __VA_ARGS__) \
  ZTT_CATALOG_FP_TYPES (APPLY, __VA_ARGS__)

#endif /* GCC_RISCV_ZTT_CATALOG_ITERATORS_H */
