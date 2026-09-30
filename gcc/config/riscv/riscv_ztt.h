/* RISC-V AME/Ztt experimental typed intrinsic interface; see README.ztt.

   Copyright (C) 2026 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3, or (at your option) any later
   version.  */

#ifndef _GCC_RISCV_ZTT_H
#define _GCC_RISCV_ZTT_H

#ifndef __riscv_ztt
#error "riscv_ztt.h requires the AME/Ztt ISA extension"
#endif

#ifndef __riscv_ztt_profile
#error "riscv_ztt.h requires a supported -mztt-profile configuration"
#endif

#pragma riscv intrinsic "ztt"

/* Runtime profiles register __riscv_ztt_{i,u}128_storage_t as distinct
   16-byte sized/aligned records with unsigned char __bytes[16].  Bytes
   follow increasing memory addresses.  These storage-only elements do
   not provide ordinary integer arithmetic or a single-X scalar value.  */

/* The pragma registers independent data Scalar records and their default
   RM aliases (integer RNU, floating RNE).  Construct them explicitly with
   scalar_make or scalar_from_bits.  TC wider than XLEN has only a single
   XLEN bit carrier; it is not a native full-width C value.  Control
   integers and the storage-only 128-bit records remain separate.  */

/* These are volatile state observations with exact size_t return types.
   Typed ownership changes require proved regions; explicit register-selector
   builtins remain excluded from functions using typed M/ACC values.  */
#define __riscv_ztt_get_ameown __builtin_riscv_ztt_get_ameown
#define __riscv_ztt_get_amestype __builtin_riscv_ztt_get_amestype
#define __riscv_ztt_get_amenlen __builtin_riscv_ztt_get_amenlen
#define __riscv_ztt_get_ameudsz __builtin_riscv_ztt_get_ameudsz
#define __riscv_ztt_get_amefflags __builtin_riscv_ztt_get_amefflags
#define __riscv_ztt_get_amexsat __builtin_riscv_ztt_get_amexsat
#define __riscv_ztt_get_amestatus __builtin_riscv_ztt_get_amestatus
#define __riscv_ztt_ame_acquire __builtin_riscv_ztt_acquire
#define __riscv_ztt_ame_release __builtin_riscv_ztt_ame_release

/* The pragma also registers default-RM function names with the same
   builtin codes and types as their explicit integer RNU or floating RNE
   forms.  Use the target's family/profile capability macros for feature
   tests; individual intrinsic names are not preprocessor macros.  */

#endif /* _GCC_RISCV_ZTT_H */
