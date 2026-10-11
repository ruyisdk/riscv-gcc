/* AME/Ztt experimental typed intrinsic support for RISC-V.

   Copyright (C) 2026 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
details.

You should have received a copy of the GNU General Public License along
with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "rtl-iter.h"
#include "tree.h"
#include "ggc.h"
#include "hash-map.h"
#include "memmodel.h"
#include "insn-codes.h"
#include "optabs.h"
#include "recog.h"
#include "diagnostic-core.h"
#include "expr.h"
#include "basic-block.h"
#include "function.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "ssa.h"
#include "builtins.h"
#include "fold-const.h"
#include "explow.h"
#include "emit-rtl.h"
#include "stor-layout.h"
#include "stringpool.h"
#include "langhooks.h"
#include "attribs.h"
#include "tm_p.h"
#include "backend.h"
#include "regs.h"
#include "tree-pass.h"
#include "cfgrtl.h"
#include "df.h"
#include "dce.h"
#include "output.h"
#include "selftest.h"
#include "selftest-rtl.h"

namespace riscv_ztt {

struct type_info
{
  const char *name;
  const char *mangled_name;
  unsigned int descriptor;
  const char *default_name;
  unsigned int rows;
  unsigned int columns;
  bool accumulator;
};

/* Validate every compiler-only profile, not just the historical P0 row.
   Fixed-size modes currently model N=128/UDS=8 only.  */
#define ZTT_PROFILE(ID, NAME, NELEM, N, UDS, MREGS, ACCREGS) \
  static_assert (((N) == 0 && (NELEM) == 0) \
		 || ((N) == 128 && (NELEM) == 16384)); \
  static_assert ((UDS) == 8 \
		 || ((N) == 0 && ((UDS) == 16 || (UDS) == 32 \
				  || (UDS) == 64 || (UDS) == 128))); \
  static_assert ((MREGS) == 16 || (MREGS) == 32); \
  static_assert ((MREGS) <= M_REG_NUM); \
  static_assert ((ACCREGS) == 1 || (ACCREGS) == 2 || (ACCREGS) == 4 \
		 || (ACCREGS) == 8 || (ACCREGS) == 16); \
  static_assert ((ACCREGS) <= ACC_REG_NUM);
#include "riscv-ztt-profile.def"
#undef ZTT_PROFILE

static constexpr profile_info profiles[] =
{
#define ZTT_PROFILE(ID, NAME, NELEM, N, UDS, MREGS, ACCREGS) \
  { NAME, NELEM, N, UDS, MREGS, ACCREGS },
#include "riscv-ztt-profile.def"
#undef ZTT_PROFILE
};

static const profile_info *
lookup_profile (const char *name)
{
  /* Keep the static table entry, not the caller's option string.  */
  static const profile_info *last_profile;
  if (name)
    {
      if (last_profile && strcmp (name, last_profile->name) == 0)
	return last_profile;
      for (const auto &profile : profiles)
	if (strcmp (name, profile.name) == 0)
	  {
	    last_profile = &profile;
	    return last_profile;
	  }
    }
  return nullptr;
}

enum type_index
{
#define ZTT_M_TYPE(ID, NAME, MANGLED_NAME, DESCRIPTOR, ALIAS) TYPE_##ID,
#define ZTT_M_SHAPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS) TYPE_##ID,
#define ZTT_ACC_TYPE(ID, NAME, LEN, DESC, ALIAS) TYPE_##ID,
#define ZTT_ACC_TUPLE(ID, NAME, LEN, DESC, ALIAS, K) TYPE_##ID##_ACCX##K,
#define ZTT_ACC_LARGE ZTT_ACC_TUPLE
#define ZTT_M_Q32(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS) TYPE_##ID,
#define ZTT_WIDE_TYPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC) TYPE_##ID,
#define ZTT_INT_TYPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC) TYPE_##ID,
#define ZTT_FP_TYPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC) TYPE_##ID,
#include "riscv-ztt-types.def"
#undef ZTT_M_TYPE
#undef ZTT_M_SHAPE
#undef ZTT_ACC_TYPE
#undef ZTT_ACC_TUPLE
#undef ZTT_ACC_LARGE
#undef ZTT_M_Q32
#undef ZTT_WIDE_TYPE
#undef ZTT_INT_TYPE
#undef ZTT_FP_TYPE
  TYPE_MAX
};
static_assert (TYPE_I8_RNU_1X32 == 336);
static_assert (TYPE_F16_RNE_1X1 == 1536);

static constexpr type_info types[] =
{
#define ZTT_M_TYPE(ID, NAME, MANGLED_NAME, DESCRIPTOR, ALIAS) \
  { #NAME, MANGLED_NAME, DESCRIPTOR, ALIAS, 1, 1, false },
#define ZTT_M_SHAPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS) \
  { "__riscv_ztt_" #NAME "_t", MANGLED, DESC, ALIAS, ROWS, COLS, false },
#define ZTT_ACC_TYPE(ID, NAME, LEN, DESC, ALIAS) \
  { "__riscv_ztt_" #NAME "_t", "u" #LEN "__riscv_ztt_" #NAME "_t", \
    DESC, ALIAS, 1, 1, true },
#define ZTT_ACC_TUPLE(ID, NAME, LEN, DESC, ALIAS, K) \
  { "__riscv_ztt_" #NAME "_accx" #K "_t", \
    "u" #LEN "__riscv_ztt_" #NAME "_accx" #K "_t", \
    DESC, ALIAS, 1, K, true },
#define ZTT_ACC_LARGE ZTT_ACC_TUPLE
#define ZTT_M_Q32(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS) \
  { "__riscv_ztt_" #NAME "_t", MANGLED, DESC, ALIAS, ROWS, COLS, false },
#define ZTT_WIDE_TYPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC) \
  { #NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC },
#define ZTT_INT_TYPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC) \
  { #NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC },
#define ZTT_FP_TYPE(ID, NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC) \
  { #NAME, MANGLED, DESC, ALIAS, ROWS, COLS, ACC },
#include "riscv-ztt-types.def"
#undef ZTT_M_TYPE
#undef ZTT_M_SHAPE
#undef ZTT_ACC_TYPE
#undef ZTT_ACC_TUPLE
#undef ZTT_ACC_LARGE
#undef ZTT_M_Q32
#undef ZTT_WIDE_TYPE
#undef ZTT_INT_TYPE
#undef ZTT_FP_TYPE
};
static_assert (ARRAY_SIZE (types) == TYPE_MAX);

static bool
floating_descriptor_p (unsigned int descriptor)
{
  return descriptor & (1U << 8);
}

static bool
extended_integer_p (unsigned int descriptor)
{
  return !floating_descriptor_p (descriptor)
    && ((descriptor & 0xff) == 4 || (descriptor & (1U << 29)));
}

bool
profile_selected_p ()
{
  return riscv_ztt_profile_string != nullptr;
}

bool
p0_profile_p ()
{
  const profile_info *profile = active_profile ();
  return profile && profile->n != 0;
}

const profile_info *
active_profile ()
{
  return lookup_profile (riscv_ztt_profile_string);
}

bool
runtime_profile_p ()
{
  const profile_info *profile = active_profile ();
  return profile && profile->n == 0;
}

bool
typed_profile_p ()
{
  return active_profile () != nullptr;
}

machine_mode
matrix_mode (unsigned int nregs)
{
  switch (nregs)
    {
    case 1: return runtime_profile_p () ? ZTTMR1mode : ZTTM1mode;
    case 2: return runtime_profile_p () ? ZTTMR2mode : ZTTM2mode;
    case 4: return runtime_profile_p () ? ZTTMR4mode : ZTTM4mode;
    case 8: return runtime_profile_p () ? ZTTMR8mode : VOIDmode;
    case 16: return runtime_profile_p () ? ZTTMR16mode : VOIDmode;
    case 32: return runtime_profile_p () ? ZTTMR32mode : VOIDmode;
    default: gcc_unreachable ();
    }
}

unsigned int
m_nregs (machine_mode mode)
{
  switch (mode)
    {
    case E_ZTTM1mode: case E_ZTTMR1mode: return 1;
    case E_ZTTM2mode: case E_ZTTMR2mode: return 2;
    case E_ZTTM4mode: case E_ZTTMR4mode: return 4;
    case E_ZTTMR8mode: return 8;
    case E_ZTTMR16mode: return 16;
    case E_ZTTMR32mode: return 32;
    default: return 0;
    }
}

bool
m_mode_p (machine_mode mode)
{
  return m_nregs (mode) != 0;
}

/* Packed values must own
   complete transfer packets.  Copies preserve every actual Ad.  */
bool
acc_profile_p ()
{
  const profile_info *profile = active_profile ();
  /* Wide integer types also provide complete single-ACC values when
     the profile cannot hold a packed i32 transfer packet.  */
  return profile && profile->n == 0 && profile->accregs != 0;
}

bool
acc_shape_supported_p (unsigned int bits, unsigned int squares,
		       unsigned int uds, unsigned int accregs)
{
  if ((bits != 4 && bits != 8 && bits != 16 && bits != 32
       && bits != 64 && bits != 128)
      || (squares != 1 && squares != 2 && squares != 4
	  && squares != 8 && squares != 16)
      || uds < 8 || uds > 128 || (uds & (uds - 1))
      || squares > accregs)
    return false;
  unsigned int packet = MAX (1U, uds / bits);
  /* A complete image can exceed the M bank.  Copies and spills transfer
     one member/packet at a time, not the entire image in M registers.  */
  return packet <= 16 && squares % packet == 0;
}

static machine_mode
acc_mode (unsigned int bits, unsigned int squares = 1)
{
  gcc_assert (acc_profile_p ());
  unsigned int uds = active_profile ()->uds;
  gcc_assert (acc_shape_supported_p (bits, squares, uds,
				    active_profile ()->accregs));
  if (bits < uds)
    {
      switch (uds / bits)
	{
	case 16: return ZTTAP16X16mode;
	case 8: return squares == 8 ? ZTTAP8X8mode : ZTTAP8X16mode;
	case 4:
	  return squares == 4 ? ZTTAP4X4mode
	    : squares == 8 ? ZTTAP4X8mode : ZTTAP4X16mode;
	case 2:
	  return squares == 2 ? ZTTAP2X2mode
	    : squares == 4 ? ZTTAP2X4mode
	    : squares == 8 ? ZTTAP2X8mode : ZTTAP2X16mode;
	default: gcc_unreachable ();
	}
    }
  static const machine_mode modes[5][5] = {
    { ZTTAR1mode, ZTTAR1X2mode, ZTTAR1X4mode, ZTTAR1X8mode, ZTTAR1X16mode },
    { ZTTAR2mode, ZTTAR2X2mode, ZTTAR2X4mode, ZTTAR2X8mode, ZTTAR2X16mode },
    { ZTTAR4mode, ZTTAR4X2mode, ZTTAR4X4mode, ZTTAR4X8mode, ZTTAR4X16mode },
    { ZTTAR8mode, ZTTAR8X2mode, ZTTAR8X4mode, ZTTAR8X8mode, ZTTAR8X16mode },
    { ZTTAR16mode, ZTTAR16X2mode, ZTTAR16X4mode, ZTTAR16X8mode, ZTTAR16X16mode },
  };
  return modes[exact_log2 (bits / uds)][exact_log2 (squares)];
}

unsigned int
acc_m_nregs (machine_mode mode)
{
  switch (mode)
    {
    case E_ZTTAR1mode: case E_ZTTAR1X2mode: case E_ZTTAR1X4mode:
    case E_ZTTAP2X2mode: case E_ZTTAP4X4mode: case E_ZTTAP2X4mode:
    case E_ZTTAP2X8mode: case E_ZTTAP4X8mode: case E_ZTTAP4X16mode:
    case E_ZTTAP8X8mode: case E_ZTTAP8X16mode: case E_ZTTAP16X16mode:
    case E_ZTTAR1X8mode: case E_ZTTAR1X16mode: case E_ZTTAP2X16mode:
      return 1;
    case E_ZTTAR2mode: case E_ZTTAR2X2mode: case E_ZTTAR2X4mode:
    case E_ZTTAR2X8mode: case E_ZTTAR2X16mode:
      return 2;
    case E_ZTTAR4mode: case E_ZTTAR4X2mode: case E_ZTTAR4X4mode:
    case E_ZTTAR4X8mode: case E_ZTTAR4X16mode:
      return 4;
    case E_ZTTAR8mode: case E_ZTTAR8X2mode: case E_ZTTAR8X4mode:
    case E_ZTTAR8X8mode: case E_ZTTAR8X16mode:
      return 8;
    case E_ZTTAR16mode: case E_ZTTAR16X2mode: case E_ZTTAR16X4mode:
    case E_ZTTAR16X8mode: case E_ZTTAR16X16mode:
      return 16;
    default: return 0;
    }
}

/* ACCs and M registers per transfer are different quantities for packed
   values.  The total M payload need not equal M-per-transfer times K.  */
unsigned int
acc_transfer_accs (machine_mode mode)
{
  switch (mode)
    {
    case E_ZTTAP2X2mode: case E_ZTTAP2X4mode: case E_ZTTAP2X8mode:
    case E_ZTTAP2X16mode:
      return 2;
    case E_ZTTAP4X4mode: case E_ZTTAP4X8mode: case E_ZTTAP4X16mode:
      return 4;
    case E_ZTTAP8X8mode: case E_ZTTAP8X16mode:
      return 8;
    case E_ZTTAP16X16mode:
      return 16;
    default: return acc_m_nregs (mode) ? 1 : 0;
    }
}

unsigned int
acc_full_m_nregs (machine_mode mode)
{
  unsigned int packet = acc_transfer_accs (mode);
  return packet ? acc_m_nregs (mode) * acc_nregs (mode) / packet : 0;
}

bool
acc_mode_p (machine_mode mode)
{
  return acc_m_nregs (mode) != 0;
}

unsigned int
acc_nregs (machine_mode mode)
{
  switch (mode)
    {
    case E_ZTTAR1mode: case E_ZTTAR2mode: case E_ZTTAR4mode:
    case E_ZTTAR8mode: case E_ZTTAR16mode:
      return 1;
    case E_ZTTAR1X2mode: case E_ZTTAR2X2mode: case E_ZTTAP2X2mode:
    case E_ZTTAR4X2mode: case E_ZTTAR8X2mode: case E_ZTTAR16X2mode:
      return 2;
    case E_ZTTAR1X4mode: case E_ZTTAP4X4mode: case E_ZTTAP2X4mode:
    case E_ZTTAR2X4mode: case E_ZTTAR4X4mode: case E_ZTTAR8X4mode:
    case E_ZTTAR16X4mode:
      return 4;
    case E_ZTTAP2X8mode: case E_ZTTAP4X8mode: case E_ZTTAP8X8mode:
    case E_ZTTAR1X8mode: case E_ZTTAR2X8mode: case E_ZTTAR4X8mode:
    case E_ZTTAR8X8mode: case E_ZTTAR16X8mode:
      return 8;
    case E_ZTTAP4X16mode: case E_ZTTAP8X16mode: case E_ZTTAP16X16mode:
    case E_ZTTAR1X16mode: case E_ZTTAR2X16mode: case E_ZTTAR4X16mode:
    case E_ZTTAR8X16mode: case E_ZTTAR16X16mode: case E_ZTTAP2X16mode:
      return 16;
    default: return 0;
    }
}

bool
acc_mode_supported_p (machine_mode mode)
{
  if (!acc_mode_p (mode) || !acc_profile_p ())
    return false;
  unsigned int bits = acc_m_nregs (mode) * active_profile ()->uds
    / acc_transfer_accs (mode);
  return acc_shape_supported_p (bits, acc_nregs (mode), active_profile ()->uds,
				active_profile ()->accregs);
}

bool
value_mode_p (machine_mode mode)
{
  return m_mode_p (mode) || acc_mode_p (mode);
}

void
validate_profile (struct gcc_options *opts)
{
  const char *name = opts->x_riscv_ztt_profile_string;
  if (name == nullptr)
    return;

  const profile_info *profile = lookup_profile (name);
  if (!profile)
    {
      error ("unknown AME/Ztt target profile %qs", name);
      return;
    }

  if (!TARGET_ZTT_OPTS_P (opts))
    error ("%<-mztt-profile=%s%> requires the %<ztt0p6%> ISA extension",
	   name);

  if (profile->n == 0)
    {
      if (!TARGET_MUL_OPTS_P (opts) || !TARGET_ZICSR_OPTS_P (opts))
	error ("runtime-N AME/Ztt profile requires integer multiplication "
	       "and the %<zicsr%> ISA extension");
      if (TARGET_RVE_OPTS_P (opts))
	error ("runtime-N AME/Ztt profile requires the full "
	       "integer register set");
      /* Keep initialization of the cached size inside the complete frame.  */
      opts->x_flag_shrink_wrap = 0;
      opts->x_flag_shrink_wrap_separate = 0;
    }
}

/* Bound the AME contribution and fixed part of a frame in signed XLEN
   address arithmetic.  Four physical M registers must also fit even when
   the current function needs no spill slot.  RVV's independent scalable
   contribution and available stack space remain platform preconditions.  */
unsigned int
runtime_n_max_log2 (unsigned int xlen, poly_int64 frame_size, unsigned int uds)
{
  gcc_assert (xlen == 32 || xlen == 64);
  gcc_assert (uds >= 8 && pow2p_hwi (uds));
  gcc_assert (frame_size.coeffs[2] >= 0
	      && frame_size.coeffs[0] >= frame_size.coeffs[2]);
  unsigned HOST_WIDE_INT limit = (HOST_WIDE_INT_1U << (xlen - 1)) - 1;
  unsigned HOST_WIDE_INT fixed
    = frame_size.coeffs[0] - frame_size.coeffs[2];
  unsigned HOST_WIDE_INT coeff = frame_size.coeffs[2];
  unsigned HOST_WIDE_INT groups = coeff / 16 + (coeff % 16 != 0);
  if (fixed >= limit)
    return 0;
  unsigned HOST_WIDE_INT square_limit = (limit - fixed) / MAX (4, groups);
  square_limit /= uds / 8;
  return square_limit < 16 ? 0 : floor_log2 (square_limit) / 2;
}

enum prototype_index
{
  PROTO_M_VOID,
  PROTO_M_CONST_PTR,
  PROTO_VOID_PTR_M,
  PROTO_M_M_M,
  PROTO_A_VOID,
  PROTO_A_M,
  PROTO_M_A,
  PROTO_A_A_M_M,
  PROTO_A_M_COLUMN,
  PROTO_M_A_COLUMN,
  PROTO_M_M,
  PROTO_A_A_M_M_Q2_RC,
  PROTO_A_A_M_M_Q2_RR,
  PROTO_A_A_M_M_Q2_CC,
  PROTO_A_A_M_M_Q4_RC,
  PROTO_A_A_M_M_Q4_RR,
  PROTO_A_A_M_M_Q4_CC,
  PROTO_M_CONCAT,
  PROTO_M_EXTRACT,
  PROTO_M_EXTRACT_COLUMN,
  PROTO_A_A_M_M_Q8_RC,
  PROTO_A_A_M_M_Q8_RR,
  PROTO_A_A_M_M_Q8_CC,
  PROTO_A_A_M_M_Q16_RC,
  PROTO_A_A_M_M_Q16_RR,
  PROTO_A_A_M_M_Q16_CC,
  PROTO_M_SHIFT_M,
  PROTO_M_SHIFT_X,
  PROTO_A_A_M_M_Q32_RC,
  PROTO_A_A_M_M_Q32_RR,
  PROTO_A_A_M_M_Q32_CC,
  PROTO_M_BINARY_M,
  PROTO_M_CONVERT,
#define ZTT_BCAST_PROTOS(ID) \
  PROTO_M_BCAST_##ID##_RNU, PROTO_M_BCAST_##ID##_RNE, \
  PROTO_M_BCAST_##ID##_RDN, PROTO_M_BCAST_##ID##_ROD,
  ZTT_BCAST_PROTOS (I8)
  ZTT_BCAST_PROTOS (U8)
  ZTT_BCAST_PROTOS (I16)
  ZTT_BCAST_PROTOS (U16)
  ZTT_BCAST_PROTOS (I32)
  ZTT_BCAST_PROTOS (U32)
#undef ZTT_BCAST_PROTOS
  PROTO_M_ROWCOL_INDEX,
  PROTO_M_ROWCOL_OFFSET,
  PROTO_M_STRUCTURAL,
  PROTO_M_GATHER,
  PROTO_M_SCATTER,
  PROTO_VOID_MPTR_MPTR,
#define ZTT_SCALAR_PROTOS(ID) \
  PROTO_M_SCALAR_##ID##_RNU, PROTO_M_SCALAR_##ID##_RNE, \
  PROTO_M_SCALAR_##ID##_RDN, PROTO_M_SCALAR_##ID##_ROD,
  ZTT_SCALAR_PROTOS (I8)
  ZTT_SCALAR_PROTOS (U8)
  ZTT_SCALAR_PROTOS (I16)
  ZTT_SCALAR_PROTOS (U16)
  ZTT_SCALAR_PROTOS (I32)
  ZTT_SCALAR_PROTOS (U32)
#undef ZTT_SCALAR_PROTOS
  PROTO_M_ABS,
  PROTO_M_TERNARY_M,
  PROTO_M_CONST_PTR_STRIDE,
  PROTO_VOID_PTR_STRIDE_M,
#define ZTT_TERNARY_X_PROTOS(ID) \
  PROTO_M_TERNARY_X_##ID##_RNU, PROTO_M_TERNARY_X_##ID##_RNE, \
  PROTO_M_TERNARY_X_##ID##_RDN, PROTO_M_TERNARY_X_##ID##_ROD,
  ZTT_TERNARY_X_PROTOS (I8)
  ZTT_TERNARY_X_PROTOS (U8)
  ZTT_TERNARY_X_PROTOS (I16)
  ZTT_TERNARY_X_PROTOS (U16)
  ZTT_TERNARY_X_PROTOS (I32)
  ZTT_TERNARY_X_PROTOS (U32)
#undef ZTT_TERNARY_X_PROTOS
  /* Append wide prototypes
     without changing the identities of earlier scalar prototypes.  */
#define ZTT_WIDE_PROTOS(KIND, ID) \
  PROTO_M_##KIND##_##ID##_RNU, PROTO_M_##KIND##_##ID##_RNE, \
  PROTO_M_##KIND##_##ID##_RDN, PROTO_M_##KIND##_##ID##_ROD,
#define ZTT_WIDE_PROTO_KIND(KIND) \
  ZTT_WIDE_PROTOS (KIND, I64) \
  ZTT_WIDE_PROTOS (KIND, U64) \
  ZTT_WIDE_PROTOS (KIND, I128) \
  ZTT_WIDE_PROTOS (KIND, U128)
  ZTT_WIDE_PROTO_KIND (BCAST)
  ZTT_WIDE_PROTO_KIND (SCALAR)
  ZTT_WIDE_PROTO_KIND (TERNARY_X)
#undef ZTT_WIDE_PROTO_KIND
#undef ZTT_WIDE_PROTOS
  PROTO_M_EXPONENT_X,
  PROTO_M_EXPONENT_ACC_X,
  PROTO_MAX
};

enum expansion_index
{
  EXPAND_MZERO_2D_M,
  EXPAND_MLS_RM,
  EXPAND_MSS_RM,
  EXPAND_MADD_EW,
  EXPAND_MCLEAR_M,
  EXPAND_ACLEAR,
  EXPAND_AZERO,
  EXPAND_A_FROM_M,
  EXPAND_M_FROM_A,
  EXPAND_A_MMUL,
  EXPAND_MCOPY_M2M,
  EXPAND_A_MMULNEG,
  EXPAND_A_MMULAT,
  EXPAND_A_MMULATNEG,
  EXPAND_A_MMULBT,
  EXPAND_A_MMULBTNEG,
  EXPAND_MCONCAT,
  EXPAND_MEXTRACT,
  EXPAND_MSUB_EW,
  EXPAND_MMIN_EW,
  EXPAND_MMAX_EW,
  EXPAND_MAND_EW,
  EXPAND_MANDNOT_EW,
  EXPAND_MOR_EW,
  EXPAND_MORNOT_EW,
  EXPAND_MXOR_EW,
  EXPAND_MSLL_EW,
  EXPAND_MSLL_EW_X,
  EXPAND_MSRL_EW,
  EXPAND_MSRL_EW_X,
  EXPAND_MSRA_EW,
  EXPAND_MSRA_EW_X,
  EXPAND_MMUL_EW,
  EXPAND_MCONV_EW,
  EXPAND_MBCAST_M_X,
  EXPAND_MCOLBCAST_EW_X,
  EXPAND_MROWBCAST_EW_X,
  EXPAND_MCOLSHIFT_EW_X,
  EXPAND_MROWSHIFT_EW_X,
  EXPAND_MREDUCEADD_COL,
  EXPAND_MREDUCEADD_ROW,
  EXPAND_MREDUCEMAX_COL,
  EXPAND_MREDUCEMAX_ROW,
  EXPAND_MREDUCEMIN_COL,
  EXPAND_MREDUCEMIN_ROW,
  EXPAND_MPREFIXADD_COL,
  EXPAND_MPREFIXADD_ROW,
  EXPAND_MPREFIXMAX_COL,
  EXPAND_MPREFIXMAX_ROW,
  EXPAND_MCOLGATHER_EW,
  EXPAND_MROWGATHER_EW,
  EXPAND_MCOLSCATADD_EW,
  EXPAND_MROWSCATADD_EW,
  EXPAND_MCOLSCATMAX_EW,
  EXPAND_MROWSCATMAX_EW,
  EXPAND_MCOLZIP_EW,
  EXPAND_MROWZIP_EW,
  EXPAND_MCOLUNZIP_EW,
  EXPAND_MROWUNZIP_EW,
  EXPAND_MROWID_EW,
  EXPAND_MCOLID_EW,
  EXPAND_MABSDIFF_EW,
  EXPAND_MHDIFF_EW,
  EXPAND_MMEAN_EW,
  EXPAND_MMULNEG_EW,
  EXPAND_MADD_EW_X,
  EXPAND_MSUB_EW_X,
  EXPAND_MABSDIFF_EW_X,
  EXPAND_MHDIFF_EW_X,
  EXPAND_MMEAN_EW_X,
  EXPAND_MMUL_EW_X,
  EXPAND_MMULNEG_EW_X,
  EXPAND_MMIN_EW_X,
  EXPAND_MMAX_EW_X,
  EXPAND_MAND_EW_X,
  EXPAND_MANDNOT_EW_X,
  EXPAND_MOR_EW_X,
  EXPAND_MORNOT_EW_X,
  EXPAND_MXOR_EW_X,
  EXPAND_MABS_EW,
  EXPAND_MMULACC_EW,
  EXPAND_MMULACCNEG_EW,
  EXPAND_MMULADD_EW,
  EXPAND_MMULSUB_EW,
  EXPAND_MLS_CM,
  EXPAND_MSS_CM,
  EXPAND_MLS_ST,
  EXPAND_MSS_ST,
  EXPAND_MLS_TST,
  EXPAND_MSS_TST,
  EXPAND_MMULACC_EW_X,
  EXPAND_MMULACCNEG_EW_X,
  EXPAND_MMULADD_EW_X,
  EXPAND_MMULSUB_EW_X,
  EXPAND_MCMOVGE_EW,
  EXPAND_MCMOVLT_EW,
  EXPAND_MCMPGE_EW,
  EXPAND_MCMPGE_EW_X,
  EXPAND_MCMPLT_EW,
  EXPAND_MCMPLT_EW_X,
  EXPAND_MSELGE_EW,
  EXPAND_MSELLT_EW,
#define ZTT_FP_UNARY(OP, NAME, INSN) EXPAND_##OP,
#include "riscv-ztt-operations.def"
#undef ZTT_FP_UNARY
#define ZTT_MATRIX_MATH(OP, NAME, PROTO) EXPAND_##OP,
#include "riscv-ztt-operations.def"
#undef ZTT_MATRIX_MATH
  EXPAND_MLOG2SUB_EW_X,
  EXPAND_MSUBLOG2_EW_X,
  EXPAND_MLDEXP_EW_X,
  EXPAND_MLDEXPACC_EW_X,
};

/* Conditional selection
   preserves the selected data representation, including its descriptor.  */
static bool
selected_data_p (expansion_index expansion)
{
  return (expansion == EXPAND_MCMOVGE_EW || expansion == EXPAND_MCMOVLT_EW
	  || expansion == EXPAND_MSELGE_EW || expansion == EXPAND_MSELLT_EW);
}

/* All four expressions
   read the old destination and convert the complete result only once.  */
static int
ternary_variant (expansion_index expansion)
{
  if (expansion >= EXPAND_MMULACC_EW && expansion <= EXPAND_MMULSUB_EW)
    return expansion - EXPAND_MMULACC_EW;
  if (expansion >= EXPAND_MCMOVGE_EW && expansion <= EXPAND_MCMOVLT_EW)
    return 4 + expansion - EXPAND_MCMOVGE_EW;
  if (expansion >= EXPAND_MLDEXPACC_EW && expansion <= EXPAND_MRDEXPACC_EW)
    return 6 + expansion - EXPAND_MLDEXPACC_EW;
  return -1;
}

/* Scalar old-D forms keep
   their own ordinals; do not change existing elementwise variant codes.  */
static int
scalar_ternary_variant (expansion_index expansion)
{
  if (expansion >= EXPAND_MMULACC_EW_X && expansion <= EXPAND_MMULSUB_EW_X)
    return expansion - EXPAND_MMULACC_EW_X;
  if (expansion == EXPAND_MLDEXPACC_EW_X)
    return 4;
  return -1;
}

/* Keep the six historical
   shift variants and mixed multiply at their original ordinals.  */
static int
arithmetic_variant (expansion_index expansion)
{
  switch (expansion)
    {
    case EXPAND_MMUL_EW: return 6;
    case EXPAND_MADD_EW: return 7;
    case EXPAND_MSUB_EW: return 8;
    case EXPAND_MABSDIFF_EW: return 9;
    case EXPAND_MHDIFF_EW: return 10;
    case EXPAND_MMEAN_EW: return 11;
    case EXPAND_MMULNEG_EW: return 12;
    case EXPAND_MCMPGE_EW: return 27;
    case EXPAND_MCMPLT_EW: return 28;
    case EXPAND_MSELGE_EW: return 31;
    case EXPAND_MSELLT_EW: return 32;
    case EXPAND_MMIN_EW: return 33;
    case EXPAND_MMAX_EW: return 34;
    case EXPAND_MLDEXP_EW: return 35;
    case EXPAND_MRDEXP_EW: return 36;
    case EXPAND_MLOG2SUB_EW: return 37;
    case EXPAND_MSUBLOG2_EW: return 38;
    default: return -1;
    }
}

/* Keep historical variants
   0..12 unchanged; data scalars are distinct from control shift counts.  */
static int
scalar_arithmetic_variant (expansion_index expansion)
{
  if (expansion == EXPAND_MLDEXP_EW_X)
    return 41;
  if (expansion >= EXPAND_MADD_EW_X && expansion <= EXPAND_MMAX_EW_X)
    return 13 + expansion - EXPAND_MADD_EW_X;
  if (expansion >= EXPAND_MAND_EW_X && expansion <= EXPAND_MXOR_EW_X)
    return 22 + expansion - EXPAND_MAND_EW_X;
  if (expansion == EXPAND_MCMPGE_EW_X)
    return 29;
  if (expansion == EXPAND_MCMPLT_EW_X)
    return 30;
  if (expansion == EXPAND_MLOG2SUB_EW_X)
    return 39;
  if (expansion == EXPAND_MSUBLOG2_EW_X)
    return 40;
  return -1;
}

/* scalar bitwise
   operations require identical matrix source and destination datatypes.  */
static bool
scalar_bitwise_p (expansion_index expansion)
{
  return expansion >= EXPAND_MAND_EW_X && expansion <= EXPAND_MXOR_EW_X;
}

static bool
data_scalar_variant_p (unsigned int variant)
{
  return IN_RANGE (variant, 13, 26) || IN_RANGE (variant, 29, 30)
    || IN_RANGE (variant, 39, 40);
}

bool
scalar_operand_p (rtx operand, unsigned int variant, bool ternary)
{
  if (operand == const0_rtx)
    return ternary ? variant <= 4
      : (data_scalar_variant_p (variant)
	 || variant == 1 || variant == 3 || variant == 5 || variant == 41);
  machine_mode mode = GET_MODE (operand);
  return mode == Pmode
    || ((mode == QImode || mode == HImode || mode == SImode)
	/* Keep a separate integer carrier for floating register views.  */
	&& (!SUBREG_P (operand)
	    || !FLOAT_MODE_P (GET_MODE (SUBREG_REG (operand))))
	&& (ternary ? variant < 4 : data_scalar_variant_p (variant)));
}

/* Column and row zip, followed by their respective inverses.  */
static int
zip_variant (expansion_index expansion)
{
  if (expansion >= EXPAND_MCOLZIP_EW && expansion <= EXPAND_MROWUNZIP_EW)
    return expansion - EXPAND_MCOLZIP_EW;
  return -1;
}

/* Matrix indices use raw
   element bits, not scalar datatype conversion.  */
static int
indexed_variant (expansion_index expansion)
{
  if (expansion >= EXPAND_MCOLGATHER_EW
      && expansion <= EXPAND_MROWSCATMAX_EW)
    return expansion - EXPAND_MCOLGATHER_EW;
  return -1;
}

/* Preserve the historical
   destination-domain fold variants.  Absolute value shares their unary
   state envelope, but computes magnitude before destination conversion.  */
static int
structural_variant (expansion_index expansion)
{
  if (expansion >= EXPAND_MREDUCEADD_COL
      && expansion <= EXPAND_MPREFIXMAX_ROW)
    return expansion - EXPAND_MREDUCEADD_COL;
  if (expansion == EXPAND_MABS_EW)
    return 10;
  if (expansion >= EXPAND_MFRINTM_EW && expansion <= EXPAND_MSQRT_EW)
    return 11 + expansion - EXPAND_MFRINTM_EW;
  return -1;
}

/* Conversion and structural variants share the unary state envelope.  */
static int
floating_unary_operation (expansion_index expansion)
{
  if (expansion == EXPAND_MCONV_EW)
    return 0;
  int variant = structural_variant (expansion);
  return variant < 0 ? -1 : variant + 1;
}

static expansion_index
floating_unary_expansion (unsigned int op)
{
  gcc_assert (op < 24);
  if (!op)
    return EXPAND_MCONV_EW;
  if (op <= 10)
    return static_cast<expansion_index> (EXPAND_MREDUCEADD_COL + op - 1);
  if (op == 11)
    return EXPAND_MABS_EW;
  return static_cast<expansion_index> (EXPAND_MFRINTM_EW + op - 12);
}

/* Basic-square controls
   are not datatype-converted scalar arithmetic operands.  */
static int
rowcol_variant (expansion_index expansion)
{
  if (expansion >= EXPAND_MCOLBCAST_EW_X
      && expansion <= EXPAND_MROWSHIFT_EW_X)
    return expansion - EXPAND_MCOLBCAST_EW_X;
  return -1;
}

/* These exact-type binary
   operations share operand formation and descriptor-preserving envelopes.  */
static int
binary_unspec (expansion_index expansion)
{
  switch (expansion)
    {
    case EXPAND_MADD_EW: return UNSPEC_ZTT_MADD_EW;
    case EXPAND_MSUB_EW: return UNSPEC_ZTT_MSUB_EW;
    case EXPAND_MMIN_EW: return UNSPEC_ZTT_MMIN_EW;
    case EXPAND_MMAX_EW: return UNSPEC_ZTT_MMAX_EW;
    case EXPAND_MAND_EW: return UNSPEC_ZTT_MAND_EW;
    case EXPAND_MANDNOT_EW: return UNSPEC_ZTT_MANDNOT_EW;
    case EXPAND_MOR_EW: return UNSPEC_ZTT_MOR_EW;
    case EXPAND_MORNOT_EW: return UNSPEC_ZTT_MORNOT_EW;
    case EXPAND_MXOR_EW: return UNSPEC_ZTT_MXOR_EW;
    default: return -1;
    }
}

static int
binary_state_unspec (int code)
{
  switch (code)
    {
    case UNSPEC_ZTT_MADD_EW: return UNSPECV_ZTT_STATE_ADD;
    case UNSPEC_ZTT_MSUB_EW: return UNSPECV_ZTT_STATE_SUB;
    case UNSPEC_ZTT_MMIN_EW: return UNSPECV_ZTT_STATE_MIN;
    case UNSPEC_ZTT_MMAX_EW: return UNSPECV_ZTT_STATE_MAX;
    case UNSPEC_ZTT_MAND_EW: return UNSPECV_ZTT_STATE_AND;
    case UNSPEC_ZTT_MANDNOT_EW: return UNSPECV_ZTT_STATE_ANDNOT;
    case UNSPEC_ZTT_MOR_EW: return UNSPECV_ZTT_STATE_OR;
    case UNSPEC_ZTT_MORNOT_EW: return UNSPECV_ZTT_STATE_ORNOT;
    case UNSPEC_ZTT_MXOR_EW: return UNSPECV_ZTT_STATE_XOR;
    default: return -1;
    }
}

enum builtin_index
{
#define ZTT_INTRINSIC(ID, NAME, PROTO, EXPAND, TYPE) ZTT_BUILTIN_##ID,
#include "riscv-ztt-intrinsics.def"
#undef ZTT_INTRINSIC
  ZTT_BUILTIN_MAX
};
static_assert (ZTT_BUILTIN_MCLEAR_M_I8_RNU_1X32 == 7537);
static_assert (ZTT_BUILTIN_MMUL_EW_I8_RNU_1X1 == 8593);
static_assert (ZTT_BUILTIN_MADD_EW_X_I8_RNU_1X1_I8_RNU == 19537);
static_assert (ZTT_BUILTIN_MAND_EW_X_I8_RNU_1X1_I8_RNU == 76561);
static_assert (ZTT_BUILTIN_MCONV_EW_I8_RNU_1X1 == 8857);
static_assert (ZTT_BUILTIN_MBCAST_M_X_I8_RNU_1X1_I8_RNU == 9121);
static_assert (ZTT_BUILTIN_MCOLBCAST_EW_X_I8_RNU_1X1 == 15457);
static_assert (ZTT_BUILTIN_MREDUCEADD_COL_I8_RNU_1X1 == 15553);
static_assert (ZTT_BUILTIN_MCOLGATHER_EW_I8_RNU_1X1 == 18193);
static_assert (ZTT_BUILTIN_MCOLZIP_EW_I8_RNU_1X1 == 18337);
static_assert (ZTT_BUILTIN_MROWID_EW_I8_RNU_1X1 == 18433);
static_assert (ZTT_BUILTIN_MABSDIFF_EW_I8_RNU_1X1 == 18481);
static_assert (ZTT_BUILTIN_MABS_EW_I8_RNU_1X1 == 108241);

struct builtin_description
{
  const char *name;
  prototype_index prototype;
  expansion_index expansion;
  type_index type;
};

/* Shared type axis for the exponent families.  */
static constexpr type_index exponent_types[] =
{
#define ZTT_EXPONENT_TYPE(TYPE, NAME, ...) TYPE_##TYPE,
#define ZTT_EXPONENT_SHAPES(TYPE, NAME, ...) \
  ZTT_CATALOG_M_SHAPES (ZTT_EXPONENT_TYPE, TYPE, NAME)
  ZTT_CATALOG_ALL_TYPES (ZTT_EXPONENT_SHAPES)
#undef ZTT_EXPONENT_SHAPES
#undef ZTT_EXPONENT_TYPE
};

static constexpr builtin_description exponent_families[] =
{
#define ZTT_EXPONENT_FAMILY(OP, SPELLING, PROTO) \
  { "__riscv_ztt_" #SPELLING, PROTO_##PROTO, EXPAND_##OP, TYPE_MAX },
#include "riscv-ztt-exponent-scalar.def"
#undef ZTT_EXPONENT_FAMILY
};

static constexpr unsigned int exponent_first
  = ZTT_BUILTIN_MLDEXP_EW_X_I4_RNU_1X1;
static constexpr unsigned int exponent_type_count = ARRAY_SIZE (exponent_types);
static constexpr unsigned int exponent_count
  = ARRAY_SIZE (exponent_families) * exponent_type_count;
static_assert (exponent_first == 454804 && exponent_type_count == 1320);
static_assert (ZTT_BUILTIN_MLDEXPACC_EW_X_I4_RNU_1X1
	       == exponent_first + exponent_type_count);
static_assert (ZTT_BUILTIN_MLDEXPACC_EW_X_F64_RNO_32X1
	       == exponent_first + exponent_count - 1);
static_assert (ZTT_BUILTIN_MLS_RM_I128_RNU_1X1
	       == exponent_first + exponent_count);

static constexpr builtin_description stored_builtin_descriptions[] =
{
#define ZTT_EXPONENT_FAMILY(OP, SPELLING, PROTO)
#define ZTT_INTRINSIC(ID, NAME, PROTO, EXPAND, TYPE) \
  { NAME, PROTO_##PROTO, EXPAND_##EXPAND, TYPE_##TYPE },
#include "riscv-ztt-intrinsics.def"
#undef ZTT_INTRINSIC
#undef ZTT_EXPONENT_FAMILY
};
static_assert (ARRAY_SIZE (stored_builtin_descriptions) + exponent_count
	       == ZTT_BUILTIN_MAX);

/* Map stable builtin codes to stored metadata or compact family entries.
   Family names are completed at declaration time.  */
static constexpr builtin_description
builtin_description_for (unsigned int code)
{
  if (code >= exponent_first && code < exponent_first + exponent_count)
    {
      unsigned int offset = code - exponent_first;
      builtin_description d = exponent_families[offset / exponent_type_count];
      d.type = exponent_types[offset % exponent_type_count];
      return d;
    }
  return stored_builtin_descriptions
    [code < exponent_first ? code : code - exponent_count];
}

/* Keep the original RM
   dispatch ID and append the other memory families.  */
static int
memory_variant (expansion_index expansion)
{
  switch (expansion)
    {
    case EXPAND_MLS_RM: case EXPAND_MSS_RM: return 0;
    case EXPAND_MLS_CM: case EXPAND_MSS_CM: return 1;
    case EXPAND_MLS_ST: case EXPAND_MSS_ST: return 2;
    case EXPAND_MLS_TST: case EXPAND_MSS_TST: return 3;
    default: return -1;
    }
}

static bool
memory_store_p (expansion_index expansion)
{
  return expansion == EXPAND_MSS_RM || expansion == EXPAND_MSS_CM
    || expansion == EXPAND_MSS_ST || expansion == EXPAND_MSS_TST;
}

static bool
store_dispatch_p (unsigned int code)
{
  return code == ZTT_BUILTIN_MSS_RM_I8_RNE_1X1
    || code == ZTT_BUILTIN_MSS_CM_DISPATCH
    || code == ZTT_BUILTIN_MSS_ST_DISPATCH
    || code == ZTT_BUILTIN_MSS_TST_DISPATCH;
}

static unsigned int
store_builtin_code (expansion_index expansion, type_index type)
{
  gcc_assert (memory_store_p (expansion) && type < TYPE_MAX);
  /* Cache catalog codes only; declaration availability remains profile-local.  */
  static unsigned int codes[4][TYPE_MAX];
  static unsigned int scanned;
  unsigned int &code = codes[memory_variant (expansion)][type];
  if (!code)
    {
      while (scanned < ZTT_BUILTIN_MAX)
	{
	  unsigned int i = scanned++;
	  const auto &d = builtin_description_for (i);
	  if (!memory_store_p (d.expansion)
	      || (store_dispatch_p (i) && i != ZTT_BUILTIN_MSS_RM_I8_RNE_1X1))
	    continue;
	  gcc_assert (d.type < TYPE_MAX);
	  unsigned int &entry = codes[memory_variant (d.expansion)][d.type];
	  if (!entry)
	    entry = i + 1;
	  if (code)
	    break;
	}
      if (!code)
	code = ZTT_BUILTIN_MAX + 1;
    }
  return code - 1;
}

/* Source shape is independent
   of the output accumulator count.  Transposed forms admit RR and CC.  */
struct matmul_shape_info
{
  unsigned int squares;
  bool lhs_column;
  bool rhs_column;
};

static const matmul_shape_info *
matmul_shape (prototype_index prototype)
{
  static constexpr matmul_shape_info shapes[] = {
    { 1, false, false },
    { 2, false, true }, { 2, false, false }, { 2, true, true },
    { 4, false, true }, { 4, false, false }, { 4, true, true },
    { 8, false, true }, { 8, false, false }, { 8, true, true },
    { 16, false, true }, { 16, false, false }, { 16, true, true },
    { 32, false, true }, { 32, false, false }, { 32, true, true }
  };
  if (prototype == PROTO_A_A_M_M)
    return &shapes[0];
  if (prototype >= PROTO_A_A_M_M_Q2_RC
      && prototype <= PROTO_A_A_M_M_Q4_CC)
    return &shapes[1 + prototype - PROTO_A_A_M_M_Q2_RC];
  if (prototype >= PROTO_A_A_M_M_Q8_RC
      && prototype <= PROTO_A_A_M_M_Q16_CC)
    return &shapes[7 + prototype - PROTO_A_A_M_M_Q8_RC];
  if (prototype >= PROTO_A_A_M_M_Q32_RC
      && prototype <= PROTO_A_A_M_M_Q32_CC)
    return &shapes[13 + prototype - PROTO_A_A_M_M_Q32_RC];
  return nullptr;
}

static GTY (()) tree ztt_m_type_nodes[TYPE_MAX];
static GTY (()) tree ztt_storage128_types[2];
static GTY (()) tree builtin_decls[ZTT_BUILTIN_MAX];
/* Root temporary prototypes until all language declarations are registered.  */
static GTY (()) vec<tree, va_gc> *registration_function_types;
static bool functions_registered_p;
static bool types_registered_p;

/* Reserve a disjoint, decodable
   code range: declaration order must not affect C/C++ or LTO identity.  */
static constexpr unsigned int mixed_code_base = 1U << 29;
static constexpr unsigned int mixed_dtype_count = 24;
static constexpr unsigned int mixed_shape_count = 7;
/* Do not change the old
   seven-shape radix: existing LTO codes must keep their meaning.  */
static constexpr unsigned int packed_code_base = 3U << 28;
static constexpr unsigned int packed_shape_count = 13;
/* Preserve both old
   shape radices; this range contains only the three Q32 orientations.  */
static constexpr unsigned int q32_code_base = 7U << 27;
static constexpr unsigned int q32_shape_count = 3;
static constexpr unsigned int matmul_shape_count
  = packed_shape_count + q32_shape_count;
/* Only matmul anchors enter these ranges.  Appending unrelated interfaces
   must not change the old bases or radices used by LTO.  */
static constexpr unsigned int
matmul_code_limit ()
{
  unsigned int limit = 0;
  /* Bound each constexpr loop independently of the growing public table,
     without raising the host compiler's default loop-iteration limit.  */
  for (unsigned int base = 0; base < ZTT_BUILTIN_MAX; base += 1024)
    for (unsigned int i = base; i < ZTT_BUILTIN_MAX && i < base + 1024; ++i)
      {
	expansion_index e = builtin_description_for (i).expansion;
	if ((e == EXPAND_A_MMUL
	     || (e >= EXPAND_A_MMULNEG && e <= EXPAND_A_MMULBTNEG))
	    && (types[builtin_description_for (i).type].descriptor & 0xff) >= 8
	    && (types[builtin_description_for (i).type].descriptor & 0xff) <= 32
	    && !(types[builtin_description_for (i).type].descriptor
		 & ((1U << 8) | (1U << 29))))
	  limit = i + 1;
      }
  return limit;
}

static constexpr unsigned int matmul_anchor_limit = matmul_code_limit ();

static_assert (mixed_code_base
	       + matmul_anchor_limit * mixed_shape_count
		 * mixed_dtype_count * mixed_dtype_count
	       <= packed_code_base);
static_assert (packed_code_base
	       + matmul_anchor_limit * packed_shape_count
		 * mixed_dtype_count * mixed_dtype_count
	       <= q32_code_base);
static_assert (q32_code_base
	       + matmul_anchor_limit * q32_shape_count
		 * mixed_dtype_count * mixed_dtype_count
	       <= (UINT_MAX >> RISCV_BUILTIN_SHIFT));

struct builtin_decl_traits
  : simple_hashmap_traits<int_hash<unsigned, 0>, tree> {};
typedef hash_map<unsigned, tree, builtin_decl_traits> builtin_decl_map;

/* Allocate only for resolved calls; keep declarations reachable through PCH.  */
struct GTY (()) builtin_decl_cache
{
  builtin_decl_map *entries;

  tree get (unsigned int code) const
  {
    if (entries)
      if (tree *decl = entries->get (code))
	return *decl;
    return NULL_TREE;
  }

  tree put (unsigned int code, tree decl)
  {
    gcc_assert (code != 0);
    if (!entries)
      entries = builtin_decl_map::create_ggc ();
    entries->put (code, decl);
    return decl;
  }
};

static GTY (()) builtin_decl_cache mixed_builtin_decls;

/* Preserve the range and
   radices originally used by shifts; 24 is a scalar shift count only.  */
static constexpr unsigned int elementwise_code_base = 1U << 28;
/* New type/operation domains
   must not enlarge the legacy 24-by-25 signature interval.  Use the same
   eligibility check at encoding and when recovering a streamed call.  */
static constexpr bool
legacy_elementwise_anchor_p (unsigned int i)
{
  const auto &d = builtin_description_for (i);
  if (d.expansion >= EXPAND_MFRINTM_EW)
    return false;
  switch (d.prototype)
    {
    case PROTO_M_M_M:
    case PROTO_M_SHIFT_M:
    case PROTO_M_SHIFT_X:
    case PROTO_M_BINARY_M:
    case PROTO_M_GATHER:
    case PROTO_M_SCATTER:
    case PROTO_M_TERNARY_M:
      break;
    default:
      return false;
    }
  unsigned int descriptor = types[d.type].descriptor;
  return (descriptor & 0xff) >= 8 && (descriptor & 0xff) <= 32
    && !(descriptor & ((1U << 8) | (1U << 29)));
}

static constexpr unsigned int
elementwise_code_limit ()
{
  unsigned int limit = 0;
  for (unsigned int base = 0; base < ZTT_BUILTIN_MAX; base += 1024)
    for (unsigned int i = base; i < ZTT_BUILTIN_MAX && i < base + 1024; ++i)
      if (legacy_elementwise_anchor_p (i))
	limit = i + 1;
  return limit;
}

static constexpr unsigned int elementwise_anchor_limit = elementwise_code_limit ();
static_assert (ZTT_BUILTIN_MAX < elementwise_code_base);
static_assert (elementwise_code_base + elementwise_anchor_limit * 24U * 25U
	       < mixed_code_base);
static GTY (()) builtin_decl_cache elementwise_builtin_decls;

/* Do not reuse the scalar
   shift sentinel or alter any existing lazy-code radix.  */
static constexpr unsigned int conversion_code_base = 1U << 27;
static_assert (ZTT_BUILTIN_MAX < conversion_code_base);
static_assert (conversion_code_base + ZTT_BUILTIN_MAX * 24U
	       < elementwise_code_base);
static GTY (()) builtin_decl_cache conversion_builtin_decls;

/* TC is in the public
   anchor; resolve TB lazily without changing earlier code ranges.  */
static constexpr unsigned int scalar_code_base = 1U << 26;
/* Wide matmul has its
   own fixed signature interval, independent of public anchor indices.  */
static constexpr unsigned int wide_matmul_code_base = 3U << 25;
static constexpr unsigned int wide_matmul_code_limit
  = wide_matmul_code_base + 6 * 5 * matmul_shape_count * 40 * 40 * 40;
static_assert (ZTT_BUILTIN_MAX < scalar_code_base);
static_assert (scalar_code_base + ZTT_BUILTIN_MAX * 24U
	       < wide_matmul_code_base);
static_assert (wide_matmul_code_limit < conversion_code_base);
static GTY (()) builtin_decl_cache scalar_builtin_decls;

static bool
wide_matmul_code_p (unsigned int code)
{
  return code >= wide_matmul_code_base && code < conversion_code_base;
}

struct wide_matmul_signature
{
  unsigned int variant, acc_group, shape, dst, lhs, rhs;
};

static unsigned int
encode_wide_matmul_signature (const wide_matmul_signature &s)
{
  gcc_assert (s.variant < 6 && s.acc_group < 5
	      && s.shape < matmul_shape_count
	      && s.dst < 40 && s.lhs < 40 && s.rhs < 40);
  return wide_matmul_code_base
    + (((((s.variant * 5 + s.acc_group) * matmul_shape_count + s.shape)
	 * 40 + s.dst) * 40 + s.lhs) * 40 + s.rhs);
}

static bool
decode_wide_matmul_signature (unsigned int code, wide_matmul_signature &s)
{
  if (code < wide_matmul_code_base || code >= wide_matmul_code_limit)
    return false;
  unsigned int payload = code - wide_matmul_code_base;
  s.rhs = payload % 40;
  payload /= 40;
  s.lhs = payload % 40;
  payload /= 40;
  s.dst = payload % 40;
  payload /= 40;
  s.shape = payload % matmul_shape_count;
  payload /= matmul_shape_count;
  s.acc_group = payload % 5;
  s.variant = payload / 5;
  return s.dst >= mixed_dtype_count || s.lhs >= mixed_dtype_count
    || s.rhs >= mixed_dtype_count;
}

/* Keep the legacy radices
   intact.  Extended signatures use operation ordinals rather than public
   anchor indices; later anchors cannot enlarge this reserved interval.  */
struct wide_operation_info
{
  expansion_index expansion;
  prototype_index prototype;
  bool basic;
};

static constexpr wide_operation_info wide_operations[] = {
#define ZTT_WIDE_OP(OP, NAME, PROTO, BASIC) { EXPAND_##OP, PROTO_##PROTO, BASIC },
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_OP
#define ZTT_WIDE_SCALAR_OP(OP, NAME, KIND) \
  { EXPAND_##OP, PROTO_M_##KIND##_I8_RNU, false },
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_SCALAR_OP
};

enum wide_operation_index
{
#define ZTT_WIDE_OP(OP, NAME, PROTO, BASIC) WIDE_##OP,
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_OP
#define ZTT_WIDE_SCALAR_OP(OP, NAME, KIND) WIDE_##OP,
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_SCALAR_OP
  WIDE_MAX
};
static_assert (WIDE_MADD_EW_X == 41);

static int
wide_operation (expansion_index expansion)
{
  switch (expansion)
    {
#define ZTT_WIDE_OP(OP, NAME, PROTO, BASIC) case EXPAND_##OP: return WIDE_##OP;
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_OP
#define ZTT_WIDE_SCALAR_OP(OP, NAME, KIND) case EXPAND_##OP: return WIDE_##OP;
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_SCALAR_OP
    default: return -1;
    }
}

static constexpr unsigned int wide_code_base = 1U << 20;
static constexpr unsigned int wide_dtype_count = 40;
static constexpr unsigned int wide_shape_count = 11;
static constexpr unsigned int acc_shape_count = 5;
static constexpr unsigned int wide_code_limit = wide_code_base
  + WIDE_MAX * wide_shape_count * wide_dtype_count * wide_dtype_count
    * (wide_dtype_count + 1);
static_assert (ZTT_BUILTIN_MAX < wide_code_base);
static_assert (wide_code_limit < scalar_code_base);
static_assert (ARRAY_SIZE (wide_operations) == WIDE_MAX);

/* Keep all old radices;
   nibble/saturating unary signatures use a separate, bounded interval.  */
static constexpr unsigned int integer_dtype_count = 96;
static constexpr unsigned int integer_unary_operations = 41;
static constexpr unsigned int integer_unary_code_base = 48U << 20;
static constexpr unsigned int integer_unary_code_limit
  = integer_unary_code_base
    + integer_unary_operations * wide_shape_count
      * integer_dtype_count * integer_dtype_count;
static_assert (wide_code_limit < integer_unary_code_base);
static_assert (integer_unary_code_limit < scalar_code_base);

/* Only physical carrier
   groups enter the code.  Original type identities are constant operands.  */
/* Supplemental domains keep
   the old three-group radices and all existing codes unchanged.  */
static constexpr unsigned int large_group_code_base = 160U << 20;
static constexpr unsigned int large_integer_matrix_code_base = 160U << 20;
static constexpr unsigned int large_floating_matrix_code_base = 161U << 20;
static constexpr unsigned int large_matrix_math_code_base = 162U << 20;
static constexpr unsigned int large_floating_unary_code_base = 163U << 20;
static constexpr unsigned int large_integer_scalar_code_base = 164U << 20;
static constexpr unsigned int large_floating_scalar_code_base = 165U << 20;
static constexpr unsigned int large_integer_matmul_code_base = 166U << 20;
static constexpr unsigned int large_floating_matmul_code_base = 167U << 20;
static_assert (conversion_code_base + ZTT_BUILTIN_MAX * 24U < large_group_code_base);
static_assert ((168U << 20) < elementwise_code_base);

static constexpr unsigned int integer_matrix_code_base = 56U << 20;
static constexpr unsigned int integer_matrix_code_count = 41 * 5 * 3 * 3 * 4;
static constexpr unsigned int large_integer_matrix_code_count = 41 * 5 * 6 * 6 * 7;
static_assert (large_integer_matrix_code_count < (1U << 20));
static_assert (integer_unary_code_limit < integer_matrix_code_base);
static_assert (integer_matrix_code_base + integer_matrix_code_count
	       < scalar_code_base);
static GTY (()) tree integer_matrix_decls[integer_matrix_code_count + large_integer_matrix_code_count];

/* Preserve the exact ACC
   type in the signature.  Only M inputs use physical carriers, with their
   original type identities passed as two checked constant operands.  */
static constexpr unsigned int integer_matmul_code_base = 57U << 20;
static constexpr unsigned int integer_matmul_code_count
  = 6 * 5 * 5 * integer_dtype_count * 3 * 3;
static constexpr unsigned int large_integer_matmul_code_count
  = 6 * 5 * 5 * integer_dtype_count * 6 * 6;
static_assert (large_integer_matmul_code_count < (1U << 20));
static_assert (integer_matrix_code_base + integer_matrix_code_count
	       < integer_matmul_code_base);
static_assert (integer_matmul_code_base + integer_matmul_code_count
	       < scalar_code_base);
static GTY (()) builtin_decl_cache integer_matmul_decls;

/* Broadcast has no M input.
   Keep its typed public signatures separate from the legacy anchor table.
   TC excludes i4/u4, including their saturating variants.  */
static constexpr unsigned int integer_broadcast_code_base = 58U << 20;
static constexpr unsigned int integer_scalar_dtype_count = 80;
static constexpr unsigned int integer_broadcast_code_count
  = integer_dtype_count * wide_shape_count * integer_scalar_dtype_count;
static_assert (integer_matmul_code_base + integer_matmul_code_count
	       < integer_broadcast_code_base);
static_assert (integer_broadcast_code_base + integer_broadcast_code_count
	       < scalar_code_base);
static GTY (()) tree integer_broadcast_decls[integer_broadcast_code_count];

/* Public scalar signatures
   contain TD/shape/TC only.  Internal signatures contain physical carriers;
   checked constant operands preserve TD/TB/TC through GIMPLE and LTO.  */
static constexpr unsigned int integer_scalar_operations = 20;
static constexpr unsigned int integer_scalar_public_base = 59U << 20;
static constexpr unsigned int integer_scalar_public_count
  = integer_scalar_operations * integer_broadcast_code_count;
static constexpr unsigned int integer_scalar_code_base = 61U << 20;
static constexpr unsigned int integer_scalar_code_count
  = integer_scalar_operations * 5 * 3 * 3 * 10;
static constexpr unsigned int large_integer_scalar_code_count
  = integer_scalar_operations * 5 * 6 * 6 * 10;
static_assert (large_integer_scalar_code_count < (1U << 20));
static_assert (WIDE_MAX - WIDE_MADD_EW_X == integer_scalar_operations);
static_assert (integer_broadcast_code_base + integer_broadcast_code_count
	       < integer_scalar_public_base);
static_assert (integer_scalar_public_base + integer_scalar_public_count
	       < integer_scalar_code_base);
static_assert (integer_scalar_code_base + integer_scalar_code_count
	       < scalar_code_base);
/* Allocate a TC block only for a legal operation/destination/shape.  Keep
   the public code radix independent of this GC-managed cache layout.
   The top-level cache is also lazy, so non-AME compilations do not scan
   thousands of empty blocks on every collection.  */
struct GTY (()) integer_scalar_public_cache
{
  vec<tree, va_gc> *blocks
    [integer_scalar_operations * integer_dtype_count * wide_shape_count];
};
static GTY (()) integer_scalar_public_cache *integer_scalar_public_decls;
static GTY (()) tree integer_scalar_decls[integer_scalar_code_count + large_integer_scalar_code_count];
static const char *const integer_scalar_names[] = {
#define ZTT_WIDE_SCALAR_OP(OP, NAME, KIND) #NAME,
#include "riscv-ztt-operations.def"
#undef ZTT_WIDE_SCALAR_OP
};
static_assert (ARRAY_SIZE (integer_scalar_names) == integer_scalar_operations);

/* Checked original type
   operands preserve floating format/RM through GIMPLE and LTO.  Only the
   operation, UDS and physical groups enter this bounded code interval.  */
static constexpr unsigned int floating_unary_code_base = 62U << 20;
static constexpr unsigned int floating_unary_code_count = 24 * 5 * 3 * 3;
static constexpr unsigned int large_floating_unary_code_count = 24 * 5 * 6 * 6;
static_assert (large_floating_unary_code_count < (1U << 20));
static_assert (integer_scalar_code_base + integer_scalar_code_count
	       < floating_unary_code_base);
static_assert (floating_unary_code_base + floating_unary_code_count
	       < scalar_code_base);
static GTY (()) tree floating_unary_decls[floating_unary_code_count + large_floating_unary_code_count];

/* Reuse the matrix carrier
   signature, but keep floating calls outside all integer code intervals.
   Ordinals 41/42 are local min/max entries, not wide scalar ordinals.  */
static constexpr unsigned int floating_matrix_code_base = 63U << 20;
static constexpr unsigned int floating_matrix_code_count = 43 * 5 * 3 * 3 * 4;
static constexpr unsigned int large_floating_matrix_code_count = 43 * 5 * 6 * 6 * 7;
static_assert (large_floating_matrix_code_count < (1U << 20));
static_assert (floating_unary_code_base + floating_unary_code_count
	       < floating_matrix_code_base);
static_assert (floating_matrix_code_base + floating_matrix_code_count
	       < scalar_code_base);
static GTY (()) tree floating_matrix_decls[floating_matrix_code_count + large_floating_matrix_code_count];

/* Mathematics reuses the
   three checked datatype operands without changing earlier signatures.  */
static constexpr unsigned int matrix_math_code_base
  = (63U << 20) + (1U << 16);
static constexpr unsigned int matrix_math_code_count = 6 * 5 * 3 * 3 * 4;
static constexpr unsigned int large_matrix_math_code_count = 6 * 5 * 6 * 6 * 7;
static_assert (large_matrix_math_code_count < (1U << 20));
static_assert (floating_matrix_code_base + floating_matrix_code_count
	       < matrix_math_code_base);
static_assert (matrix_math_code_base + matrix_math_code_count < scalar_code_base);
static GTY (()) tree matrix_math_decls[matrix_math_code_count + large_matrix_math_code_count];

/* Public signatures contain
   TD/shape/TC; bounded internal signatures carry checked original types.
   The old integer radices and public declarations are unchanged.  */
static constexpr unsigned int floating_scalar_operations = 22;
static constexpr unsigned int numeric_dtype_count = 120;
static constexpr unsigned int numeric_scalar_dtype_count = 104;
static constexpr unsigned int floating_scalar_public_base = 80U << 20;
static constexpr unsigned int floating_scalar_public_count
  = floating_scalar_operations * numeric_dtype_count * wide_shape_count
    * numeric_scalar_dtype_count;
static constexpr unsigned int floating_scalar_code_base
  = (63U << 20) + (2U << 16);
static constexpr unsigned int floating_scalar_code_count
  = floating_scalar_operations * 5 * 3 * 3 * 10;
static constexpr unsigned int large_floating_scalar_code_count
  = floating_scalar_operations * 5 * 6 * 6 * 10;
static_assert (large_floating_scalar_code_count < (1U << 20));
static_assert (scalar_code_base + ZTT_BUILTIN_MAX * 24U
	       < floating_scalar_public_base);
static_assert (floating_scalar_public_base + floating_scalar_public_count
	       < wide_matmul_code_base);
static_assert (matrix_math_code_base + matrix_math_code_count
	       < floating_scalar_code_base);
static_assert (floating_scalar_code_base + floating_scalar_code_count
	       < scalar_code_base);
struct GTY (()) floating_scalar_public_cache
{
  vec<tree, va_gc> *blocks
    [floating_scalar_operations * numeric_dtype_count * wide_shape_count];
};
static GTY (()) floating_scalar_public_cache *floating_scalar_public_decls;
static GTY (()) tree floating_scalar_decls[floating_scalar_code_count + large_floating_scalar_code_count];

/* Broadcast carries TD/TC
   in its public signature.  Integer-only declarations keep their old IDs.  */
static constexpr unsigned int floating_broadcast_code_base
  = (63U << 20) + (3U << 16);
static constexpr unsigned int floating_broadcast_code_count
  = numeric_dtype_count * wide_shape_count * numeric_scalar_dtype_count;
static_assert (floating_scalar_public_count
	       == floating_scalar_operations * floating_broadcast_code_count);
static_assert (floating_scalar_code_base + floating_scalar_code_count
	       < floating_broadcast_code_base);
static_assert (floating_broadcast_code_base + floating_broadcast_code_count
	       < scalar_code_base);
static GTY (()) tree floating_broadcast_decls[floating_broadcast_code_count];

/* Keep integer-only matmul
   signatures unchanged.  Source type IDs travel as checked operands, not
   a registration-order index or a Cartesian product of all datatypes.  */
static constexpr unsigned int floating_matmul_code_base
  = (63U << 20) + (6U << 16);
static constexpr unsigned int floating_matmul_code_count
  = 6 * 5 * 5 * numeric_dtype_count * 3 * 3;
static constexpr unsigned int large_floating_matmul_code_count
  = 6 * 5 * 5 * numeric_dtype_count * 6 * 6;
static_assert (large_floating_matmul_code_count < (1U << 20));
static_assert (floating_broadcast_code_base + floating_broadcast_code_count
	       < floating_matmul_code_base);
static_assert (floating_matmul_code_base + floating_matmul_code_count
	       < scalar_code_base);

/* Fixed signed exponent
   controls have no TC.  Carry original TD/TA as checked operands, keeping
   existing public and internal signatures unchanged.  */
static constexpr unsigned int exponent_code_base = (63U << 20) + (14U << 16);
static constexpr unsigned int exponent_code_count = 2 * 5 * 6 * 6;
static_assert (floating_matmul_code_base + floating_matmul_code_count
	       < exponent_code_base);
static_assert (exponent_code_base + exponent_code_count < scalar_code_base);
static GTY (()) tree exponent_decls[exponent_code_count];

/* Nominal scalars are frontend records, not new M types or RTL modes.
   Keep these codes separate from all legacy raw-carrier signatures.  */
static constexpr unsigned int nominal_scalar_base = 168U << 20;
static constexpr unsigned int nominal_operation_base
  = nominal_scalar_base + 3 * numeric_scalar_dtype_count;
static constexpr unsigned int nominal_broadcast_base
  = nominal_operation_base + 2 * TYPE_MAX;
static constexpr unsigned int nominal_scalar_limit
  = nominal_broadcast_base + TYPE_MAX * numeric_scalar_dtype_count;
/* Keep the first madd/broadcast codes and raw broadcast range unchanged.  */
static constexpr unsigned int nominal_extended_base = 169U << 20;
static constexpr unsigned int nominal_extended_count
  = (floating_scalar_operations - 1) * TYPE_MAX;
static_assert (nominal_scalar_limit < nominal_extended_base);
static_assert (nominal_extended_base + nominal_extended_count
	       < elementwise_code_base);
static GTY (()) tree nominal_scalar_types[numeric_scalar_dtype_count];
static GTY (()) tree nominal_scalar_decls[3 * numeric_scalar_dtype_count
					+ 2 * TYPE_MAX];
static GTY (()) tree nominal_extended_decls[nominal_extended_count];
static GTY (()) vec<tree, va_gc> *nominal_broadcast_decls;
static GTY (()) vec<tree, va_gc> *nominal_registration_types;

static bool
nominal_extended_p (unsigned int code)
{
  return code >= nominal_extended_base
    && code < nominal_extended_base + nominal_extended_count;
}

static bool
nominal_raw_broadcast_p (unsigned int code)
{
  return code >= nominal_broadcast_base && code < nominal_scalar_limit;
}

static bool
nominal_operation_p (unsigned int code)
{
  return (code >= nominal_operation_base && code < nominal_broadcast_base)
    || nominal_extended_p (code);
}

static bool
nominal_scalar_code_p (unsigned int code)
{
  return (code >= nominal_scalar_base && code < nominal_scalar_limit)
    || nominal_extended_p (code);
}

static void register_nominal_scalars ();
static tree nominal_builtin_decl (unsigned int, bool);
static unsigned int nominal_scalar_number (type_index);
static tree nominal_registration_type (type_index, unsigned int, unsigned int);
static bool check_nominal_call (unsigned int, unsigned int, tree *);

static bool
exponent_code_p (unsigned int code)
{
  return code >= exponent_code_base && code < exponent_code_base + exponent_code_count;
}

static bool
exponent_p (expansion_index expansion)
{
  return expansion == EXPAND_MLDEXP_EW_X || expansion == EXPAND_MLDEXPACC_EW_X;
}

static bool
floating_matmul_code_p (unsigned int code)
{
  return (code >= floating_matmul_code_base
	  && code < floating_matmul_code_base + floating_matmul_code_count)
    || (code >= large_floating_matmul_code_base
	&& code < large_floating_matmul_code_base + large_floating_matmul_code_count);
}

static bool
floating_broadcast_code_p (unsigned int code)
{
  return code >= floating_broadcast_code_base
    && code < floating_broadcast_code_base + floating_broadcast_code_count;
}

static bool
floating_scalar_public_p (unsigned int code)
{
  return code >= floating_scalar_public_base
    && code < floating_scalar_public_base + floating_scalar_public_count;
}

static bool
floating_scalar_code_p (unsigned int code)
{
  return (code >= floating_scalar_code_base
	  && code < floating_scalar_code_base + floating_scalar_code_count)
    || (code >= large_floating_scalar_code_base
	&& code < large_floating_scalar_code_base + large_floating_scalar_code_count);
}

static bool
matrix_math_code_p (unsigned int code)
{
  return (code >= matrix_math_code_base
	  && code < matrix_math_code_base + matrix_math_code_count)
    || (code >= large_matrix_math_code_base
	&& code < large_matrix_math_code_base + large_matrix_math_code_count);
}

static bool
floating_matrix_code_p (unsigned int code)
{
  return (code >= floating_matrix_code_base
	  && code < floating_matrix_code_base + floating_matrix_code_count)
    || (code >= large_floating_matrix_code_base
	&& code < large_floating_matrix_code_base + large_floating_matrix_code_count);
}

static bool
floating_unary_code_p (unsigned int code)
{
  return (code >= floating_unary_code_base
	  && code < floating_unary_code_base + floating_unary_code_count)
    || (code >= large_floating_unary_code_base
	&& code < large_floating_unary_code_base + large_floating_unary_code_count);
}

static bool
integer_scalar_public_p (unsigned int code)
{
  return code >= integer_scalar_public_base
    && code < integer_scalar_public_base + integer_scalar_public_count;
}

static bool
integer_scalar_code_p (unsigned int code)
{
  return (code >= integer_scalar_code_base
	  && code < integer_scalar_code_base + integer_scalar_code_count)
    || (code >= large_integer_scalar_code_base
	&& code < large_integer_scalar_code_base + large_integer_scalar_code_count);
}

static bool
numeric_scalar_code_p (unsigned int code)
{
  return integer_scalar_code_p (code) || floating_scalar_code_p (code);
}

static bool
integer_broadcast_code_p (unsigned int code)
{
  return code >= integer_broadcast_code_base
    && code < integer_broadcast_code_base + integer_broadcast_code_count;
}

static bool
integer_matmul_code_p (unsigned int code)
{
  return (code >= integer_matmul_code_base
	  && code < integer_matmul_code_base + integer_matmul_code_count)
    || (code >= large_integer_matmul_code_base
	&& code < large_integer_matmul_code_base + large_integer_matmul_code_count);
}

static bool
integer_matrix_code_p (unsigned int code)
{
  return (code >= integer_matrix_code_base
	  && code < integer_matrix_code_base + integer_matrix_code_count)
    || (code >= large_integer_matrix_code_base
	&& code < large_integer_matrix_code_base + large_integer_matrix_code_count);
}

static bool
integer_unary_code_p (unsigned int code)
{
  return code >= integer_unary_code_base && code < scalar_code_base;
}

static bool
wide_code_p (unsigned int code)
{
  return code >= wide_code_base && code < integer_unary_code_base;
}

struct wide_signature
{
  unsigned int operation, shape, dst, data, count;
};

static unsigned int
encode_wide_signature (const wide_signature &s)
{
  gcc_assert (s.operation < WIDE_MAX && s.shape < wide_shape_count
	      && s.dst < wide_dtype_count && s.data < wide_dtype_count
	      && s.count <= wide_dtype_count);
  return wide_code_base
    + (((s.operation * wide_shape_count + s.shape) * wide_dtype_count
	+ s.dst) * wide_dtype_count + s.data) * (wide_dtype_count + 1)
    + s.count;
}

static bool
decode_wide_signature (unsigned int code, wide_signature &s)
{
  if (code < wide_code_base || code >= wide_code_limit)
    return false;
  unsigned int payload = code - wide_code_base;
  s.count = payload % (wide_dtype_count + 1);
  payload /= wide_dtype_count + 1;
  s.data = payload % wide_dtype_count;
  payload /= wide_dtype_count;
  s.dst = payload % wide_dtype_count;
  payload /= wide_dtype_count;
  s.shape = payload % wide_shape_count;
  s.operation = payload / wide_shape_count;
  /* Old-only signatures retain their historical identity.  */
  return s.dst >= mixed_dtype_count || s.data >= mixed_dtype_count
    || (s.count >= mixed_dtype_count && s.count < wide_dtype_count);
}

static bool
wide_unary_p (unsigned int code)
{
  wide_signature s;
  if (!decode_wide_signature (code, s))
    return false;
  prototype_index p = wide_operations[s.operation].prototype;
  return p == PROTO_M_CONVERT || p == PROTO_M_STRUCTURAL || p == PROTO_M_ABS;
}

static bool
wide_scalar_p (unsigned int code)
{
  wide_signature s;
  if (!decode_wide_signature (code, s))
    return false;
  prototype_index p = wide_operations[s.operation].prototype;
  return p == PROTO_M_SCALAR_I8_RNU || p == PROTO_M_TERNARY_X_I8_RNU;
}

struct scalar_description
{
  unsigned int canonical;
  type_index source;
  type_index scalar;
  elementwise_formation formation;
};

struct conversion_description
{
  unsigned int canonical;
  type_index source;
  elementwise_formation formation;
};

struct elementwise_description
{
  unsigned int canonical;
  type_index data;
  type_index count;
  elementwise_formation formation;
};

struct mixed_description
{
  unsigned int canonical;
  prototype_index prototype;
  type_index lhs;
  type_index rhs;
};

static tree
lookup_type_attribute (const_tree type)
{
  if (type == error_mark_node)
    return NULL_TREE;
  return lookup_attribute ("Ztt type", TYPE_ATTRIBUTES (type));
}

static type_index
type_for_tree (const_tree type)
{
  tree attr = lookup_type_attribute (type);
  if (!attr)
    return TYPE_MAX;
  tree index = TREE_VALUE (chain_index (1, TREE_VALUE (attr)));
  unsigned int i = tree_to_uhwi (index);
  return i < TYPE_MAX ? static_cast<type_index> (i) : TYPE_MAX;
}

/* N cancels from register
   occupancy, but not from the independently scaled storage mode.  Compute
   the complete M span independently of the available compiler modes and
   of the simultaneously live operands of an instruction.  */
unsigned int
m_shape_nregs (unsigned int bits, unsigned int squares, unsigned int uds,
	       unsigned int register_limit)
{
  if (bits < 4 || bits > 128 || (bits & (bits - 1))
      || !squares || squares > 32 || (squares & (squares - 1))
      || uds < 8 || uds > 128 || (uds & (uds - 1))
      || !register_limit || register_limit > 32
      || (register_limit & (register_limit - 1)))
    return 0;
  unsigned int total = bits * squares;
  if (total < uds || total % uds != 0 || total / uds > register_limit)
    return 0;
  return total / uds;
}

unsigned int
shape_nregs (unsigned int bits, unsigned int squares, unsigned int uds)
{
  return m_shape_nregs (bits, squares, uds, 32);
}

/* A datatype step is a
   register count, not its logarithm.  Six bits also represent 16 and 32;
   zero denotes the absent second tensor operand of a scalar/unary form.
   This private RTL field is neither an instruction nor a builtin code.  */
unsigned int
pack_datatype_steps (unsigned int dst, unsigned int source, unsigned int other)
{
  gcc_assert (dst && dst <= 32 && !(dst & (dst - 1)));
  gcc_assert (source && source <= 32 && !(source & (source - 1)));
  gcc_assert (other <= 32 && !(other & (other - 1)));
  return dst | (source << 6) | (other << 12);
}

unsigned int
datatype_step (unsigned int steps, unsigned int operand)
{
  gcc_assert (operand < 3 && !(steps >> 18));
  unsigned int count = (steps >> (6 * operand)) & 63;
  gcc_assert (count <= 32 && !(count & (count - 1)));
  gcc_assert (count || operand == 2);
  return count;
}

/* One instruction folds P
   paired source Squares, not one Square per source register.  N and the
   output ACC width/count do not participate in this formation.  */
bool
form_matmul (unsigned int lhs, unsigned int rhs, unsigned int q,
	     unsigned int uds, matmul_formation &result)
{
  if ((lhs != 4 && lhs != 8 && lhs != 16 && lhs != 32 && lhs != 64 && lhs != 128)
      || (rhs != 4 && rhs != 8 && rhs != 16 && rhs != 32 && rhs != 64 && rhs != 128)
      || (q != 1 && q != 2 && q != 4 && q != 8 && q != 16 && q != 32)
      || uds < 8 || uds > 128 || (uds & (uds - 1)))
    return false;
  unsigned int p = MAX (1U, MAX (uds / lhs, uds / rhs));
  unsigned int l = shape_nregs (lhs, q, uds);
  unsigned int r = shape_nregs (rhs, q, uds);
  if (!l || !r || q < p || q % p)
    return false;
  result = { p, q / p, l, r, p * lhs / uds, p * rhs / uds };
  gcc_assert (result.lhs_step && result.rhs_step);
  return true;
}

/* A zero count width denotes
   an absent second tensor source (unary operation or scalar operand),
   which is excluded from tensor operand formation.  */
bool
form_elementwise (unsigned int dst, unsigned int data, unsigned int count,
		  unsigned int q, unsigned int uds,
		  elementwise_formation &result)
{
  if (!q || q > 32 || (q & (q - 1))
      || uds < 8 || uds > 128 || (uds & (uds - 1)))
    return false;
  unsigned int bits[] = { dst, data, count };
  unsigned int operands = count ? 3 : 2;
  elementwise_formation f = {};
  f.squares_per_insn = 1;
  for (unsigned int i = 0; i < operands; ++i)
    {
      if (bits[i] != 4 && bits[i] != 8 && bits[i] != 16 && bits[i] != 32
	  && bits[i] != 64 && bits[i] != 128)
	return false;
      f.nregs[i] = shape_nregs (bits[i], q, uds);
      if (!f.nregs[i])
	return false;
      f.squares_per_insn = MAX (f.squares_per_insn, uds / bits[i]);
    }
  if (q < f.squares_per_insn || q % f.squares_per_insn)
    return false;
  f.insns = q / f.squares_per_insn;
  for (unsigned int i = 0; i < operands; ++i)
    f.step[i] = f.squares_per_insn * bits[i] / uds;
  result = f;
  return true;
}

static unsigned int
type_nregs_for_profile (type_index type, const profile_info &profile)
{
  const auto &t = types[type];
  const bool runtime = profile.n == 0;
  if ((extended_integer_p (t.descriptor)
       || floating_descriptor_p (t.descriptor)) && !runtime)
    return 0;
  if (t.accumulator)
    return (runtime && profile.accregs
	    && acc_shape_supported_p (t.descriptor & 0xff, t.columns,
				      profile.uds, profile.accregs)
	    ? t.columns : 0);
  if (!runtime && t.rows * t.columns != 1)
    return 0;
  return m_shape_nregs (t.descriptor & 0xff, t.rows * t.columns,
			profile.uds, runtime ? profile.mregs : 4);
}

static unsigned int
type_nregs (type_index type)
{
  static const profile_info *cached_profile;
  static unsigned char counts[TYPE_MAX];
  const profile_info *profile = active_profile ();
  if (profile != cached_profile)
    {
      memset (counts, 0, sizeof (counts));
      cached_profile = profile;
    }
  if (!profile)
    return 0;
  /* Store the count plus one so unavailable types also hit the cache.  */
  if (!counts[type])
    {
      unsigned int count = type_nregs_for_profile (type, *profile);
      gcc_assert (count <= M_REG_NUM);
      counts[type] = count + 1;
    }
  return counts[type] - 1;
}

static machine_mode
type_mode (type_index type)
{
  return types[type].accumulator
    ? acc_mode (types[type].descriptor & 0xff, types[type].columns)
    : matrix_mode (type_nregs (type));
}

static const char *
carrier_name (type_index type)
{
  unsigned int descriptor = types[type].descriptor;
  if (floating_descriptor_p (descriptor))
    {
      if ((descriptor & 0xff) == 64)
	return "double";
      if ((descriptor & 0xff) == 32)
	return "float";
      bool bf = (descriptor & ~(7U << 22))
	== (types[TYPE_BF16_RNE_1X1].descriptor & ~(7U << 22));
      return bf ? "__bf16" : "_Float16";
    }
  bool signed_p = descriptor & (1U << 30);
  switch (descriptor & 0xff)
    {
    case 8: return signed_p ? INT8_TYPE : UINT8_TYPE;
    case 16: return signed_p ? INT16_TYPE : UINT16_TYPE;
    case 32: return signed_p ? INT32_TYPE : UINT32_TYPE;
    case 64: return signed_p ? INT64_TYPE : UINT64_TYPE;
    case 128: return signed_p ? "__riscv_ztt_i128_storage_t"
	: "__riscv_ztt_u128_storage_t";
    default: gcc_unreachable ();
    }
}

static tree
carrier_type (type_index type)
{
  /* Memory elements keep
     their full native format, including an eight-byte double on RV32.  */
  unsigned int d = types[type].descriptor;
  if ((d & 0xff) == 128 && !floating_descriptor_p (d))
    return ztt_storage128_types[(d >> 30) & 1];
  if (floating_descriptor_p (d))
    {
      if ((d & 0xff) == 64)
	return double_type_node;
      if ((d & 0xff) == 32)
	return float_type_node;
      bool bf = (d & ~(7U << 22))
	== (types[TYPE_BF16_RNE_1X1].descriptor & ~(7U << 22));
      tree type_node = lang_hooks.types.type_for_mode (bf ? BFmode : HFmode, 0);
      gcc_assert (type_node && TREE_CODE (type_node) == REAL_TYPE);
      return type_node;
    }
  return get_typenode_from_name (carrier_name (type));
}

/* A data scalar wider
   than XLEN is an X-register bit pattern, zero-extended by the ISA.
   Memory carriers keep their full element width.  */
static tree
scalar_carrier_type (type_index type)
{
  if ((types[type].descriptor & 0xff) > BITS_PER_WORD)
    return get_typenode_from_name (TARGET_64BIT ? UINT64_TYPE : UINT32_TYPE);
  if (floating_descriptor_p (types[type].descriptor))
    {
      unsigned int bits = types[type].descriptor & 0xff;
      return get_typenode_from_name (bits == 16 ? UINT16_TYPE
				    : bits == 32 ? UINT32_TYPE : UINT64_TYPE);
    }
  return carrier_type (type);
}

/* Floating data is transferred as bits, not converted to an integer.
   Wider-than-XLEN public operands are explicitly constructed bit patterns.  */
static tree
scalar_public_carrier_type (type_index type)
{
  unsigned int d = types[type].descriptor;
  if (!floating_descriptor_p (d) || (d & 0xff) > BITS_PER_WORD)
    return scalar_carrier_type (type);
  return carrier_type (type);
}

static bool
broadcast_prototype_p (prototype_index prototype)
{
  return IN_RANGE (prototype, PROTO_M_BCAST_I8_RNU, PROTO_M_BCAST_U32_ROD)
    || IN_RANGE (prototype, PROTO_M_BCAST_I64_RNU, PROTO_M_BCAST_U128_ROD);
}

static bool
scalar_prototype_p (prototype_index prototype, bool ternary)
{
  if (ternary)
    return IN_RANGE (prototype, PROTO_M_TERNARY_X_I8_RNU,
		     PROTO_M_TERNARY_X_U32_ROD)
      || IN_RANGE (prototype, PROTO_M_TERNARY_X_I64_RNU,
		   PROTO_M_TERNARY_X_U128_ROD);
  return IN_RANGE (prototype, PROTO_M_SCALAR_I8_RNU, PROTO_M_SCALAR_U32_ROD)
    || IN_RANGE (prototype, PROTO_M_SCALAR_I64_RNU, PROTO_M_SCALAR_U128_ROD);
}

/* TC is explicit in the
   function name.  Its scalar carrier needs no available 1x1 M type.  */
static type_index
broadcast_source_type (prototype_index prototype)
{
  static constexpr type_index sources[] = {
#define ZTT_BCAST_TYPES(ID) \
    TYPE_##ID##_RNU_1X1, TYPE_##ID##_RNE_1X1, \
    TYPE_##ID##_RDN_1X1, TYPE_##ID##_ROD_1X1,
    ZTT_BCAST_TYPES (I8)
    ZTT_BCAST_TYPES (U8)
    ZTT_BCAST_TYPES (I16)
    ZTT_BCAST_TYPES (U16)
    ZTT_BCAST_TYPES (I32)
    ZTT_BCAST_TYPES (U32)
    ZTT_BCAST_TYPES (I64)
    ZTT_BCAST_TYPES (U64)
    ZTT_BCAST_TYPES (I128)
    ZTT_BCAST_TYPES (U128)
#undef ZTT_BCAST_TYPES
  };
  gcc_assert (broadcast_prototype_p (prototype));
  unsigned int index = prototype >= PROTO_M_BCAST_I64_RNU
    ? 24 + prototype - PROTO_M_BCAST_I64_RNU : prototype - PROTO_M_BCAST_I8_RNU;
  return sources[index];
}

static type_index
scalar_source_type (prototype_index prototype)
{
  if (IN_RANGE (prototype, PROTO_M_TERNARY_X_I64_RNU,
		PROTO_M_TERNARY_X_U128_ROD))
    return broadcast_source_type (static_cast<prototype_index>
      (PROTO_M_BCAST_I64_RNU + prototype - PROTO_M_TERNARY_X_I64_RNU));
  if (IN_RANGE (prototype, PROTO_M_SCALAR_I64_RNU, PROTO_M_SCALAR_U128_ROD))
    return broadcast_source_type (static_cast<prototype_index>
      (PROTO_M_BCAST_I64_RNU + prototype - PROTO_M_SCALAR_I64_RNU));
  if (prototype >= PROTO_M_TERNARY_X_I8_RNU
      && prototype <= PROTO_M_TERNARY_X_U32_ROD)
    return broadcast_source_type (static_cast<prototype_index>
      (PROTO_M_BCAST_I8_RNU + prototype - PROTO_M_TERNARY_X_I8_RNU));
  gcc_assert (prototype >= PROTO_M_SCALAR_I8_RNU
	      && prototype <= PROTO_M_SCALAR_U32_ROD);
  return broadcast_source_type (static_cast<prototype_index>
    (PROTO_M_BCAST_I8_RNU + prototype - PROTO_M_SCALAR_I8_RNU));
}

static void
register_storage128_types ()
{
  /* These sized storage
     records are not integer arithmetic types or sizeless M values.  */
  if (runtime_profile_p ())
    for (unsigned int sign = 0; sign < 2; ++sign)
      {
	tree bytes = build_array_type_nelts (unsigned_char_type_node, 16);
	tree field = build_decl (BUILTINS_LOCATION, FIELD_DECL,
				 get_identifier ("__bytes"), bytes);
	SET_DECL_ALIGN (field, 128);
	DECL_USER_ALIGN (field) = 1;
	tree type = lang_hooks.types.simulate_record_decl
	  (BUILTINS_LOCATION, sign ? "__riscv_ztt_i128_storage_t"
	   : "__riscv_ztt_u128_storage_t", make_array_slice (&field, 1));
	gcc_assert (tree_to_uhwi (TYPE_SIZE_UNIT (type)) == 16
		    && TYPE_ALIGN (type) == 128);
	ztt_storage128_types[sign] = type;
      }
}

static void
register_builtin_type ()
{
  if (types_registered_p)
    return;

  for (unsigned int i = 0; i < TYPE_MAX; ++i)
    {
      if (!type_nregs (static_cast<type_index> (i)))
	continue;
      machine_mode mode = type_mode (static_cast<type_index> (i));
      bool old_have_regs_of_mode = have_regs_of_mode[mode];
      have_regs_of_mode[mode] = true;
      poly_uint64 precision = GET_MODE_BITSIZE (mode);
      tree type = make_node (OPAQUE_TYPE);
      ztt_m_type_nodes[i] = type;
      SET_TYPE_MODE (type, mode);
      TYPE_SIZE (type) = bitsize_int (precision);
      TYPE_PRECISION (type) = constant_lower_bound (precision);
      TYPE_SIZE_UNIT (type) = size_int (GET_MODE_SIZE (mode));
      SET_TYPE_ALIGN (type, 128);
      TYPE_USER_ALIGN (type) = 0;
      TYPE_ARTIFICIAL (type) = 1;
      TYPE_INDIVISIBLE_P (type) = 1;

      tree index = build_int_cst (unsigned_type_node, i);
      tree value = tree_cons
	(NULL_TREE, get_identifier (types[i].mangled_name),
	 tree_cons (NULL_TREE, index,
		    tree_cons (NULL_TREE,
			       build_int_cst (unsigned_type_node,
					      active_profile ()->uds),
			       NULL_TREE)));
      TYPE_ATTRIBUTES (type)
	= tree_cons (get_identifier ("Ztt type"), value,
		     TYPE_ATTRIBUTES (type));
      TYPE_ATTRIBUTES (type)
	= tree_cons (get_identifier ("Ztt sizeless type"), NULL_TREE,
		     TYPE_ATTRIBUTES (type));
      lang_hooks.types.register_builtin_type (type, types[i].name);
      if (types[i].default_name)
	lang_hooks.types.register_builtin_type (type, types[i].default_name);
      have_regs_of_mode[mode] = old_have_regs_of_mode;
    }
  types_registered_p = true;
}

static type_index matrix_type_index (unsigned int, unsigned int, unsigned int);
static type_index numeric_matrix_type (unsigned int, unsigned int, bool = false);

static tree
acc_matrix_type (type_index type, unsigned int rows = 1, unsigned int columns = 1)
{
  gcc_assert (types[type].accumulator);
  type_index index = matrix_type_index (types[type].descriptor, rows, columns);
  gcc_assert (index != TYPE_MAX);
  return ztt_m_type_nodes[index];
}

/* Both ends of a shape
   transition must be registered; a complete parent can have an
   unrepresentable fractional-M half.  TYPE is the result type.  */
static type_index
m_utility_source_type (prototype_index prototype, type_index type)
{
  const auto &t = types[type];
  unsigned int rows = t.rows, columns = t.columns;
  if (prototype == PROTO_M_CONCAT)
    {
      if (rows > 1)
	rows /= 2;
      else
	columns /= 2;
    }
  else if (rows > 1 || prototype == PROTO_M_EXTRACT_COLUMN)
    rows *= 2;
  else
    columns *= 2;
  return matrix_type_index (t.descriptor, rows, columns);
}

static tree
build_function_type (prototype_index prototype, type_index type)
{
  tree ztt_m_type_node = ztt_m_type_nodes[type];
  if (scalar_prototype_p (prototype, true))
    return build_function_type_list
      (ztt_m_type_node, ztt_m_type_node, ztt_m_type_node,
       scalar_carrier_type (scalar_source_type (prototype)), NULL_TREE);
  if (scalar_prototype_p (prototype, false))
    return build_function_type_list
      (ztt_m_type_node, ztt_m_type_node,
       scalar_carrier_type (scalar_source_type (prototype)), NULL_TREE);
  if (broadcast_prototype_p (prototype))
    return build_function_type_list
      (ztt_m_type_node, scalar_carrier_type (broadcast_source_type (prototype)),
       NULL_TREE);
  /* Register-only wide
     values need no ordinary C scalar carrier (notably i128 on RV32).  */
  tree element_ptr = NULL_TREE;
  tree const_element_ptr = NULL_TREE;
  if (prototype == PROTO_M_CONST_PTR || prototype == PROTO_VOID_PTR_M
      || prototype == PROTO_M_CONST_PTR_STRIDE
      || prototype == PROTO_VOID_PTR_STRIDE_M)
    {
      tree element = carrier_type (type);
      element_ptr = build_pointer_type (element);
      const_element_ptr
	= build_pointer_type (build_qualified_type (element, TYPE_QUAL_CONST));
    }

  switch (prototype)
    {
    case PROTO_VOID_MPTR_MPTR:
      {
	tree ptr = build_pointer_type (ztt_m_type_node);
	return build_function_type_list (void_type_node, ptr, ptr, NULL_TREE);
      }
    case PROTO_M_VOID:
    case PROTO_A_VOID:
      return build_function_type_list (ztt_m_type_node, NULL_TREE);
    case PROTO_M_CONST_PTR:
      return build_function_type_list (ztt_m_type_node, const_element_ptr,
				       NULL_TREE);
    case PROTO_M_CONST_PTR_STRIDE:
      return build_function_type_list (ztt_m_type_node, const_element_ptr,
				       size_type_node, NULL_TREE);
    case PROTO_VOID_PTR_STRIDE_M:
      return build_function_type_list (void_type_node, element_ptr,
				       size_type_node, ztt_m_type_node, NULL_TREE);
    case PROTO_VOID_PTR_M:
      return build_function_type_list (void_type_node, element_ptr,
				       ztt_m_type_node, NULL_TREE);
    case PROTO_M_M_M:
    case PROTO_M_SHIFT_M:
    case PROTO_M_BINARY_M:
    case PROTO_M_GATHER:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       ztt_m_type_node, NULL_TREE);
    case PROTO_M_SCATTER:
    case PROTO_M_TERNARY_M:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       ztt_m_type_node, ztt_m_type_node,
				       NULL_TREE);
    case PROTO_M_SHIFT_X:
    case PROTO_M_ROWCOL_INDEX:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       size_type_node, NULL_TREE);
    case PROTO_M_ROWCOL_OFFSET:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       integer_type_node, NULL_TREE);
    case PROTO_M_EXPONENT_X:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       long_integer_type_node, NULL_TREE);
    case PROTO_M_EXPONENT_ACC_X:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       ztt_m_type_node, long_integer_type_node,
				       NULL_TREE);
    case PROTO_M_M:
    case PROTO_M_CONVERT:
    case PROTO_M_STRUCTURAL:
    case PROTO_M_ABS:
      return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
				       NULL_TREE);
    case PROTO_M_CONCAT:
    case PROTO_M_EXTRACT:
    case PROTO_M_EXTRACT_COLUMN:
      {
	tree src = ztt_m_type_nodes[m_utility_source_type (prototype, type)];
	return build_function_type_list
	  (ztt_m_type_node, src,
	   prototype == PROTO_M_CONCAT ? src : size_type_node, NULL_TREE);
      }
    case PROTO_A_M:
    case PROTO_A_M_COLUMN:
      return build_function_type_list
	(ztt_m_type_node,
	 acc_matrix_type (type, prototype == PROTO_A_M_COLUMN ? types[type].columns : 1,
			 prototype == PROTO_A_M_COLUMN ? 1 : types[type].columns),
	 NULL_TREE);
    case PROTO_M_A:
    case PROTO_M_A_COLUMN:
      return build_function_type_list
	(acc_matrix_type (type, prototype == PROTO_M_A_COLUMN ? types[type].columns : 1,
			 prototype == PROTO_M_A_COLUMN ? 1 : types[type].columns),
	 ztt_m_type_node, NULL_TREE);
    case PROTO_A_A_M_M:
    case PROTO_A_A_M_M_Q2_RC:
    case PROTO_A_A_M_M_Q2_RR:
    case PROTO_A_A_M_M_Q2_CC:
    case PROTO_A_A_M_M_Q4_RC:
    case PROTO_A_A_M_M_Q4_RR:
    case PROTO_A_A_M_M_Q4_CC:
    case PROTO_A_A_M_M_Q8_RC:
    case PROTO_A_A_M_M_Q8_RR:
    case PROTO_A_A_M_M_Q8_CC:
    case PROTO_A_A_M_M_Q16_RC:
    case PROTO_A_A_M_M_Q16_RR:
    case PROTO_A_A_M_M_Q16_CC:
      {
	const auto &shape = *matmul_shape (prototype);
	tree lhs = acc_matrix_type (type, shape.lhs_column ? shape.squares : 1,
				    shape.lhs_column ? 1 : shape.squares);
	tree rhs = acc_matrix_type (type, shape.rhs_column ? shape.squares : 1,
				    shape.rhs_column ? 1 : shape.squares);
	return build_function_type_list (ztt_m_type_node, ztt_m_type_node,
					 lhs, rhs, NULL_TREE);
      }
    default:
      gcc_unreachable ();
    }
  gcc_unreachable ();
}

static tree
registration_function_type (prototype_index prototype, type_index type)
{
  if (broadcast_prototype_p (prototype))
    return nominal_registration_type
      (type, nominal_scalar_number (broadcast_source_type (prototype)), 1);
  if (scalar_prototype_p (prototype, false)
      || scalar_prototype_p (prototype, true))
    return nominal_registration_type
      (type, nominal_scalar_number (scalar_source_type (prototype)),
       scalar_prototype_p (prototype, true) ? 3 : 2);
  unsigned int key = prototype;
  switch (prototype)
    {
    case PROTO_M_SHIFT_M:
    case PROTO_M_BINARY_M:
    case PROTO_M_GATHER:
      key = PROTO_M_M_M;
      break;
    case PROTO_M_CONVERT:
    case PROTO_M_STRUCTURAL:
    case PROTO_M_ABS:
      key = PROTO_M_M;
      break;
    case PROTO_M_TERNARY_M:
      key = PROTO_M_SCATTER;
      break;
    case PROTO_M_ROWCOL_INDEX:
      key = PROTO_M_SHIFT_X;
      break;
    default:
      break;
    }
  tree &result = (*registration_function_types)
    [type * PROTO_MAX + key];
  if (!result)
    result = build_function_type (prototype, type);
  return result;
}

/* decl_attributes copies these argument-free inputs into each declaration.  */
static GTY (()) tree builtin_function_attributes;

static tree
function_attributes ()
{
  if (!builtin_function_attributes)
    {
      tree attrs = tree_cons (get_identifier ("leaf"), NULL_TREE, NULL_TREE);
      builtin_function_attributes
	= tree_cons (get_identifier ("nothrow"), NULL_TREE, attrs);
    }
  return builtin_function_attributes;
}

static int
matmul_variant (expansion_index expansion)
{
  if (expansion == EXPAND_A_MMUL)
    return 0;
  if (expansion >= EXPAND_A_MMULNEG && expansion <= EXPAND_A_MMULBTNEG)
    return expansion - EXPAND_A_MMULNEG + 1;
  return -1;
}

static prototype_index
matmul_prototype (unsigned int shape)
{
  gcc_assert (shape < matmul_shape_count);
  if (shape >= packed_shape_count)
    return static_cast<prototype_index>
      (PROTO_A_A_M_M_Q32_RC + shape - packed_shape_count);
  if (shape >= mixed_shape_count)
    return static_cast<prototype_index>
      (PROTO_A_A_M_M_Q8_RC + shape - mixed_shape_count);
  return shape == 0 ? PROTO_A_A_M_M
    : static_cast<prototype_index> (PROTO_A_A_M_M_Q2_RC + shape - 1);
}

static bool
matmul_shape_allowed_p (unsigned int shape, expansion_index expansion)
{
  int variant = matmul_variant (expansion);
  return variant >= 0 && shape < matmul_shape_count
    && (shape == 0 || ((shape - 1) % 3 == 0) == (variant < 2));
}

static unsigned int
redirect_key (prototype_index prototype, expansion_index expansion,
	      type_index type)
{
  gcc_assert (type < TYPE_MAX);
  int variant = 0;
  if (prototype != PROTO_M_EXTRACT_COLUMN && prototype != PROTO_A_M_COLUMN)
    {
      const auto *shape = matmul_shape (prototype);
      variant = matmul_variant (expansion);
      if (!shape || shape->squares <= 1 || variant < 0)
	return UINT_MAX;
    }
  static_assert (TYPE_MAX < UINT_MAX / PROTO_MAX / 6);
  return (variant * PROTO_MAX + prototype) * TYPE_MAX + type;
}

static unsigned int
redirect_builtin_code (prototype_index prototype, expansion_index expansion,
		       type_index type)
{
  unsigned int key = redirect_key (prototype, expansion, type);
  if (key == UINT_MAX)
    return ZTT_BUILTIN_MAX;
  /* Catalog codes are profile-independent; declarations are not cached here.  */
  static hash_map<int_hash<unsigned int, UINT_MAX>, unsigned int> codes;
  static unsigned int scanned;
  if (unsigned int *code = codes.get (key))
    return *code;
  while (scanned < ZTT_BUILTIN_MAX)
    {
      unsigned int i = scanned++;
      const auto &d = builtin_description_for (i);
      unsigned int candidate = redirect_key (d.prototype, d.expansion, d.type);
      if (candidate == UINT_MAX)
	continue;
      bool present;
      unsigned int &code = codes.get_or_insert (candidate, &present);
      if (!present)
	code = i;
      if (candidate == key)
	return code;
    }
  return ZTT_BUILTIN_MAX;
}

/* The ordinal is independent of the historical type declaration order.  */
static unsigned int
mixed_dtype_number (unsigned int descriptor)
{
  gcc_assert (!floating_descriptor_p (descriptor));
  return (exact_log2 (descriptor & 0xff) - 3) * 8
    + ((descriptor >> 30) & 1) * 4 + ((descriptor >> 27) & 3);
}

static unsigned int
mixed_dtype_descriptor (unsigned int number)
{
  gcc_assert (number < wide_dtype_count);
  return (8U << (number / 8)) | ((number % 8 / 4) << 30)
    | ((number % 4) << 27);
}

static type_index
mixed_matrix_type (unsigned int number, unsigned int q, bool column)
{
  return matrix_type_index (mixed_dtype_descriptor (number), column ? q : 1,
			    column ? 1 : q);
}

/* The first forty ordinals are identical to the existing integer scheme.
   The next eight are i4/u4; saturation adds 48 without discarding RM.  */
static unsigned int
integer_dtype_number (unsigned int descriptor)
{
  gcc_assert (!floating_descriptor_p (descriptor));
  unsigned int n = (descriptor & 0xff) == 4
    ? 40 + ((descriptor >> 30) & 1) * 4 + ((descriptor >> 27) & 3)
    : mixed_dtype_number (descriptor);
  return n + ((descriptor & (1U << 29)) ? 48 : 0);
}

static unsigned int
integer_dtype_descriptor (unsigned int number)
{
  gcc_assert (number < integer_dtype_count);
  unsigned int n = number % 48;
  unsigned int d = n >= 40
    ? 4U | (((n - 40) / 4) << 30) | ((n % 4) << 27)
    : mixed_dtype_descriptor (n);
  return d | (number >= 48 ? 1U << 29 : 0);
}

static type_index
integer_matrix_type (unsigned int number, unsigned int q, bool column)
{
  return matrix_type_index (integer_dtype_descriptor (number), column ? q : 1,
			    column ? 1 : q);
}

static unsigned int
integer_broadcast_code (unsigned int dst, unsigned int shape, unsigned int tc)
{
  gcc_assert (dst < integer_dtype_count && shape < wide_shape_count
	      && tc < integer_scalar_dtype_count);
  return integer_broadcast_code_base
    + (dst * wide_shape_count + shape) * integer_scalar_dtype_count + tc;
}

static bool
decode_integer_broadcast (unsigned int code, type_index &dst, type_index &tc)
{
  if (!integer_broadcast_code_p (code) || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  unsigned int payload = code - integer_broadcast_code_base;
  unsigned int c = payload % integer_scalar_dtype_count;
  payload /= integer_scalar_dtype_count;
  unsigned int shape = payload % wide_shape_count;
  unsigned int d = payload / wide_shape_count;
  if (d < 40 && c < 40)
    return false; /* Preserve the old public declarations and codes.  */

  type_index di = numeric_matrix_type (d, shape);
  type_index ci = numeric_matrix_type (c < 40 ? c : c + 8, 0);
  if (di == TYPE_MAX || ci == TYPE_MAX)
    return false;
  dst = di;
  tc = ci;
  return ztt_m_type_nodes[dst] != NULL_TREE;
}

static unsigned int numeric_dtype_number (unsigned int);

static const char *
scalar_datatype_name (unsigned int d, bool alias)
{
  /* Names depend only on the descriptor, not on the active profile.  */
  static char names[numeric_dtype_count][2][16];
  unsigned int number = numeric_dtype_number (d);
  gcc_assert (number < numeric_dtype_count);
  char *name = names[number][alias];
  if (name[0])
    return name;
  int length;
  if (floating_descriptor_p (d))
    {
      static const char *const rm[] = { "_rne", "_rtz", "_rdn", "_rup", "_rmm", "_rno" };
      bool bf = (d & ~(7U << 22))
	== (types[TYPE_BF16_RNE_1X1].descriptor & ~(7U << 22));
      length = snprintf (name, sizeof (names[0][0]), "%s%u%s",
			 bf ? "bf" : "f", d & 0xff,
			 alias ? "" : rm[(d >> 22) & 7]);
    }
  else
    {
      static const char *const rm[] = { "_rnu", "_rne", "_rdn", "_rod" };
      length = snprintf (name, sizeof (names[0][0]), "%c%u%s%s",
			 d & (1U << 30) ? 'i' : 'u', d & 0xff,
			 alias ? "" : rm[(d >> 27) & 3],
			 d & (1U << 29) ? "_sat" : "");
    }
  gcc_assert (length >= 0
	      && static_cast<size_t> (length) < sizeof (names[0][0]));
  return name;
}

static void
integer_scalar_name (char *name, size_t size, const char *operation,
		     type_index dst, type_index tc, bool alias)
{
  unsigned int d = types[dst].descriptor, c = types[tc].descriptor;
  const char *dtype = scalar_datatype_name (d, alias);
  const char *ctype = scalar_datatype_name (c, alias);
  auto dimension = [] (unsigned int n) {
    static const char *const names[] = { "1", "2", "4", "8", "16", "32" };
    int index = exact_log2 (n);
    gcc_assert (index >= 0 && static_cast<unsigned> (index) < ARRAY_SIZE (names));
    return names[index];
  };
  auto append = [&] (const char *part) {
    size_t length = strlen (part);
    gcc_assert (length < size);
    memcpy (name, part, length);
    name += length;
    size -= length;
  };
  append ("__riscv_ztt_");
  append (operation);
  append ("_");
  append (dtype);
  append ("_");
  append (dimension (types[dst].rows));
  append ("x");
  append (dimension (types[dst].columns));
  append ("_");
  append (ctype);
  *name = '\0';
}

static const char *
canonical_builtin_name (const builtin_description &d, char (&name)[160])
{
  if (!exponent_p (d.expansion))
    return d.name;
  const char *dtype = scalar_datatype_name (types[d.type].descriptor, false);
  int length = snprintf (name, sizeof (name), "%s_%s_%ux%u", d.name, dtype,
			 types[d.type].rows, types[d.type].columns);
  gcc_assert (length >= 0 && static_cast<size_t> (length) < sizeof (name));
  return name;
}

static tree
integer_broadcast_builtin_decl (unsigned int code, bool initialize_p,
				type_index dst, type_index tc)
{
  if (in_lto_p)
    return integer_zero_node;
  tree &decl = integer_broadcast_decls[code - integer_broadcast_code_base];
  if (!decl && initialize_p)
    {
      char name[160];
      integer_scalar_name (name, sizeof (name), "mbcast_m_x", dst, tc, false);
      unsigned int c = (code - integer_broadcast_code_base)
	% integer_scalar_dtype_count;
      tree ftype = nominal_registration_type (dst, c, 1);
      unsigned int fullcode = (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT;
      decl = simulate_builtin_function_decl
	(input_location, name, ftype, fullcode, NULL, function_attributes ());
      if (!((types[dst].descriptor | types[tc].descriptor) & (3U << 27)))
	{
	  integer_scalar_name (name, sizeof (name), "mbcast_m_x", dst, tc, true);
	  simulate_builtin_function_decl
	    (input_location, name, ftype, fullcode, NULL, function_attributes ());
	}
    }
  return decl ? decl : error_mark_node;
}

static tree
integer_broadcast_builtin_decl (unsigned int code, bool initialize_p)
{
  type_index dst, tc;
  if (!decode_integer_broadcast (code, dst, tc))
    return error_mark_node;
  return integer_broadcast_builtin_decl (code, initialize_p, dst, tc);
}

static bool
decode_integer_scalar_public (unsigned int code, unsigned int &op,
			      type_index &dst, type_index &tc)
{
  if (!integer_scalar_public_p (code))
    return false;
  unsigned int n = code - integer_scalar_public_base;
  op = n / integer_broadcast_code_count;
  return decode_integer_broadcast (integer_broadcast_code_base
				   + n % integer_broadcast_code_count, dst, tc);
}

static bool
integer_scalar_old_p (unsigned int op)
{
  return op < integer_scalar_operations
    && scalar_ternary_variant (wide_operations[WIDE_MADD_EW_X + op].expansion) >= 0;
}

static tree
integer_scalar_public_decl (unsigned int code, bool initialize_p,
			    unsigned int op, type_index dst, type_index tc)
{
  if (in_lto_p)
    return integer_zero_node;
  if (!integer_scalar_public_decls)
    {
      if (!initialize_p)
	return error_mark_node;
      integer_scalar_public_decls
	= ggc_cleared_alloc<integer_scalar_public_cache> ();
    }
  unsigned int index = code - integer_scalar_public_base;
  auto &block
    = integer_scalar_public_decls->blocks[index / integer_scalar_dtype_count];
  if (!block)
    {
      if (!initialize_p)
	return error_mark_node;
      vec_safe_grow_cleared (block, integer_scalar_dtype_count, true);
    }
  tree &decl = (*block)[index % integer_scalar_dtype_count];
  if (!decl && initialize_p)
    {
      bool old = integer_scalar_old_p (op);
      tree ftype = nominal_registration_type
	(dst, index % integer_scalar_dtype_count, old ? 3 : 2);
      char name[160];
      integer_scalar_name (name, sizeof (name), integer_scalar_names[op], dst, tc, false);
      unsigned int fullcode = (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT;
      decl = simulate_builtin_function_decl
	(input_location, name, ftype, fullcode, NULL, function_attributes ());
      if (!((types[dst].descriptor | types[tc].descriptor) & (3U << 27)))
	{
	  integer_scalar_name (name, sizeof (name), integer_scalar_names[op], dst, tc, true);
	  simulate_builtin_function_decl
	    (input_location, name, ftype, fullcode, NULL, function_attributes ());
	}
    }
  return decl ? decl : error_mark_node;
}

static tree
integer_scalar_public_decl (unsigned int code, bool initialize_p)
{
  unsigned int op;
  type_index dst, tc;
  if (!decode_integer_scalar_public (code, op, dst, tc))
    return error_mark_node;
  return integer_scalar_public_decl (code, initialize_p, op, dst, tc);
}

static constexpr type_index floating_dtype_bases[] = { TYPE_F16_RNE_1X1,
  TYPE_BF16_RNE_1X1, TYPE_F32_RNE_1X1, TYPE_F64_RNE_1X1 };

static unsigned int
numeric_dtype_number (unsigned int descriptor)
{
  if (!floating_descriptor_p (descriptor))
    return integer_dtype_number (descriptor);
  unsigned int format = 0;
  while (format < ARRAY_SIZE (floating_dtype_bases)
	 && (descriptor & ~(7U << 22))
	    != types[floating_dtype_bases[format]].descriptor)
    ++format;
  gcc_assert (format < ARRAY_SIZE (floating_dtype_bases));
  return integer_dtype_count + format * 6 + ((descriptor >> 22) & 7);
}

static unsigned int
numeric_dtype_descriptor (unsigned int number)
{
  gcc_assert (number < numeric_dtype_count);
  if (number < integer_dtype_count)
    return integer_dtype_descriptor (number);
  number -= integer_dtype_count;
  return types[floating_dtype_bases[number / 6]].descriptor
    | ((number % 6) << 22);
}

/* Only immutable catalogue indices are shared; trees remain profile-local.  */
static type_index
numeric_matrix_type (unsigned int number, unsigned int shape, bool accumulator)
{
  gcc_assert (number < numeric_dtype_count
	      && shape < (accumulator ? acc_shape_count : wide_shape_count));
  static unsigned int indices[numeric_dtype_count]
			     [wide_shape_count + acc_shape_count];
  static bool initialized;
  if (!initialized)
    {
      for (unsigned int i = 0; i < TYPE_MAX; ++i)
	{
	  const auto &t = types[i];
	  unsigned int number = numeric_dtype_number (t.descriptor);
	  unsigned int q = exact_log2 (t.rows * t.columns);
	  unsigned int s = q ? 2 * q - (t.rows == 1) : 0;
	  if (t.accumulator)
	    {
	      gcc_assert (t.rows == 1 && q < acc_shape_count);
	      s = wide_shape_count + q;
	    }
	  else
	    gcc_assert (s < wide_shape_count);
	  gcc_assert (number < numeric_dtype_count && !indices[number][s]);
	  indices[number][s] = i + 1;
	}
      initialized = true;
    }
  unsigned int index = indices[number][shape + (accumulator ? wide_shape_count : 0)];
  return index ? static_cast<type_index> (index - 1) : TYPE_MAX;
}

/* A Scalar's nominal identity is independent of M shape availability.  */
static type_index
nominal_scalar_type_index (unsigned int n)
{
  gcc_assert (n < numeric_scalar_dtype_count);
  type_index type = numeric_matrix_type (n < 40 ? n : n < 80 ? n + 8 : n + 16, 0);
  gcc_assert (type != TYPE_MAX);
  return type;
}

static unsigned int
nominal_scalar_number (type_index type)
{
  gcc_assert ((types[type].descriptor & 0xff) != 4);
  unsigned int n = numeric_dtype_number (types[type].descriptor);
  return n < 40 ? n : n < 96 ? n - 8 : n - 16;
}

static type_index
matrix_type_index (unsigned int descriptor, unsigned int rows,
		   unsigned int columns)
{
  if (!rows || !columns || (rows != 1 && columns != 1))
    return TYPE_MAX;
  int q = exact_log2 (rows == 1 ? columns : rows);
  if (q < 0)
    return TYPE_MAX;
  unsigned int shape = q ? 2 * q - (rows == 1) : 0;
  if (shape >= wide_shape_count)
    return TYPE_MAX;
  return numeric_matrix_type (numeric_dtype_number (descriptor), shape);
}

static bool
decode_numeric_scalar_types (unsigned int d, unsigned int shape,
			     unsigned int c, type_index &dst, type_index &tc)
{
  gcc_assert (c < numeric_scalar_dtype_count);
  type_index di = numeric_matrix_type (d, shape);
  type_index ci = numeric_matrix_type (c < 40 ? c : c < 80 ? c + 8 : c + 16, 0);
  if (di == TYPE_MAX || ci == TYPE_MAX)
    return false;
  dst = di;
  tc = ci;
  return ztt_m_type_nodes[dst] != NULL_TREE;
}

static bool
floating_scalar_operation_p (unsigned int op, bool floating)
{
  gcc_assert (op < floating_scalar_operations);
  if (op >= integer_scalar_operations)
    return floating;
  expansion_index e = wide_operations[WIDE_MADD_EW_X + op].expansion;
  return !floating || !(scalar_bitwise_p (e) || e == EXPAND_MCMPGE_EW_X
			|| e == EXPAND_MCMPLT_EW_X);
}

static bool
decode_floating_scalar_public (unsigned int code, unsigned int &op,
			       type_index &dst, type_index &tc)
{
  if (!floating_scalar_public_p (code) || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  unsigned int n = code - floating_scalar_public_base;
  unsigned int c = n % numeric_scalar_dtype_count;
  n /= numeric_scalar_dtype_count;
  unsigned int shape = n % wide_shape_count;
  n /= wide_shape_count;
  unsigned int d = n % numeric_dtype_count;
  op = n / numeric_dtype_count;
  if ((d < 96 && c < 80) || !floating_scalar_operation_p (op, d >= 96))
    return false;
  return decode_numeric_scalar_types (d, shape, c, dst, tc);
}

static bool
decode_floating_broadcast (unsigned int code, type_index &dst, type_index &tc)
{
  if (!floating_broadcast_code_p (code) || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  unsigned int n = code - floating_broadcast_code_base;
  unsigned int c = n % numeric_scalar_dtype_count;
  n /= numeric_scalar_dtype_count;
  unsigned int shape = n % wide_shape_count;
  unsigned int d = n / wide_shape_count;
  if (d < integer_dtype_count && c < integer_scalar_dtype_count)
    return false;
  return decode_numeric_scalar_types (d, shape, c, dst, tc);
}

struct scalar_registration_group
{
  unsigned int payload;
  type_index dst;
  unsigned int first_tc;
};

/* TC is the innermost code axis.  Keep each available destination once.  */
static void
collect_scalar_registration_groups (vec<scalar_registration_group> &groups,
				    bool floating)
{
  unsigned int count = floating ? numeric_dtype_count : integer_dtype_count;
  unsigned int scalar_count = floating ? numeric_scalar_dtype_count
    : integer_scalar_dtype_count;
  for (unsigned int d = 0; d < count; ++d)
    for (unsigned int shape = 0; shape < wide_shape_count; ++shape)
      {
	type_index dst = numeric_matrix_type (d, shape);
	if (dst == TYPE_MAX || !ztt_m_type_nodes[dst])
	  continue;
	/* Integer legacy entries retain their original declarations.  */
	unsigned int first_tc = floating ? (d < integer_dtype_count ? 80 : 0)
	  : (d < 40 ? 40 : 0);
	groups.safe_push ({ (d * wide_shape_count + shape) * scalar_count,
			    dst, first_tc });
      }
}

static const wide_operation_info &
numeric_scalar_operation (unsigned int op)
{
  static constexpr wide_operation_info log[] = {
    { EXPAND_MLOG2SUB_EW_X, PROTO_M_SCALAR_I8_RNU, false },
    { EXPAND_MSUBLOG2_EW_X, PROTO_M_SCALAR_I8_RNU, false }
  };
  gcc_assert (op < floating_scalar_operations);
  return op < integer_scalar_operations ? wide_operations[WIDE_MADD_EW_X + op]
    : log[op - integer_scalar_operations];
}

static const char *
numeric_scalar_name (unsigned int op)
{
  gcc_assert (op < floating_scalar_operations);
  return op < integer_scalar_operations ? integer_scalar_names[op]
    : op == integer_scalar_operations ? "mlog2sub_ew_x" : "msublog2_ew_x";
}

static bool
default_scalar_rm_p (unsigned int d)
{
  return !(d & (floating_descriptor_p (d) ? 7U << 22 : 3U << 27));
}

/* Public prototypes retain exact nominal identity, even for equal-width
   payloads.  Internal raw signatures continue to share carrier types.  */
static tree
nominal_registration_type (type_index dst, unsigned int c, unsigned int nargs)
{
  gcc_assert (nargs >= 1 && nargs <= 3);
  gcc_assert (c < numeric_scalar_dtype_count && nominal_scalar_types[c]);
  unsigned int key = (dst * numeric_scalar_dtype_count + c) * 3 + nargs - 1;
  tree ftype = nominal_registration_types
    ? (*nominal_registration_types)[key] : NULL_TREE;
  if (!ftype)
    {
      tree m = ztt_m_type_nodes[dst], scalar = nominal_scalar_types[c];
      ftype = nargs == 1 ? build_function_type_list (m, scalar, NULL_TREE)
	: nargs == 2 ? build_function_type_list (m, m, scalar, NULL_TREE)
	: build_function_type_list (m, m, m, scalar, NULL_TREE);
      if (nominal_registration_types)
	(*nominal_registration_types)[key] = ftype;
    }
  return ftype;
}

static tree
floating_broadcast_builtin_decl (unsigned int code, bool initialize_p,
				 type_index dst, type_index tc)
{
  if (in_lto_p)
    return integer_zero_node;
  tree &decl = floating_broadcast_decls[code - floating_broadcast_code_base];
  if (!decl && initialize_p)
    {
      unsigned int desc = types[tc].descriptor;
      unsigned int c = (code - floating_broadcast_code_base)
	% numeric_scalar_dtype_count;
      tree ftype = nominal_registration_type (dst, c, 1);
      char name[160];
      integer_scalar_name (name, sizeof (name), "mbcast_m_x", dst, tc, false);
      unsigned int fullcode = (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT;
      decl = simulate_builtin_function_decl
	(input_location, name, ftype, fullcode, NULL, function_attributes ());
      if (default_scalar_rm_p (types[dst].descriptor) && default_scalar_rm_p (desc))
	{
	  integer_scalar_name (name, sizeof (name), "mbcast_m_x", dst, tc, true);
	  simulate_builtin_function_decl
	    (input_location, name, ftype, fullcode, NULL, function_attributes ());
	}
    }
  return decl ? decl : error_mark_node;
}

static tree
floating_broadcast_builtin_decl (unsigned int code, bool initialize_p)
{
  type_index dst, tc;
  if (!decode_floating_broadcast (code, dst, tc))
    return error_mark_node;
  return floating_broadcast_builtin_decl (code, initialize_p, dst, tc);
}

static tree
floating_scalar_public_decl (unsigned int code, bool initialize_p,
			     unsigned int op, type_index dst, type_index tc)
{
  if (in_lto_p)
    return integer_zero_node;
  if (!floating_scalar_public_decls)
    {
      if (!initialize_p)
	return error_mark_node;
      floating_scalar_public_decls
	= ggc_cleared_alloc<floating_scalar_public_cache> ();
    }
  unsigned int index = code - floating_scalar_public_base;
  auto &block
    = floating_scalar_public_decls->blocks[index / numeric_scalar_dtype_count];
  if (!block)
    {
      if (!initialize_p)
	return error_mark_node;
      vec_safe_grow_cleared (block, numeric_scalar_dtype_count, true);
    }
  tree &decl = (*block)[index % numeric_scalar_dtype_count];
  if (!decl && initialize_p)
    {
      bool old = integer_scalar_old_p (op);
      unsigned int desc = types[tc].descriptor;
      tree ftype = nominal_registration_type
	(dst, index % numeric_scalar_dtype_count, old ? 3 : 2);
      const char *operation = numeric_scalar_name (op);
      char name[160];
      integer_scalar_name (name, sizeof (name), operation, dst, tc, false);
      unsigned int fullcode = (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT;
      decl = simulate_builtin_function_decl
	(input_location, name, ftype, fullcode, NULL, function_attributes ());
      if (default_scalar_rm_p (types[dst].descriptor) && default_scalar_rm_p (desc))
	{
	  integer_scalar_name (name, sizeof (name), operation, dst, tc, true);
	  simulate_builtin_function_decl
	    (input_location, name, ftype, fullcode, NULL, function_attributes ());
	}
    }
  return decl ? decl : error_mark_node;
}

static tree
floating_scalar_public_decl (unsigned int code, bool initialize_p)
{
  unsigned int op;
  type_index dst, tc;
  if (!decode_floating_scalar_public (code, op, dst, tc))
    return error_mark_node;
  return floating_scalar_public_decl (code, initialize_p, op, dst, tc);
}

static bool
integer_unary_operation_p (unsigned int op)
{
  if (op >= integer_unary_operations)
    return false;
  prototype_index p = wide_operations[op].prototype;
  return p == PROTO_M_CONVERT || p == PROTO_M_STRUCTURAL || p == PROTO_M_ABS;
}

static unsigned int
encode_integer_unary_builtin (unsigned int canonical, type_index source)
{
  const auto &d = builtin_description_for (canonical);
  const auto &t = types[d.type];
  unsigned int op = wide_operation (d.expansion);
  gcc_assert (integer_unary_operation_p (op));
  unsigned int q = exact_log2 (t.rows * t.columns);
  unsigned int shape = q ? 2 * q - (t.rows == 1) : 0;
  return integer_unary_code_base
    + ((op * wide_shape_count + shape) * integer_dtype_count
	+ integer_dtype_number (t.descriptor)) * integer_dtype_count
      + integer_dtype_number (types[source].descriptor);
}

static bool
decode_integer_unary_builtin (unsigned int code, unsigned int &canonical,
			     unsigned int &source)
{
  if (code < integer_unary_code_base || code >= integer_unary_code_limit)
    return false;
  unsigned int payload = code - integer_unary_code_base;
  source = payload % integer_dtype_count;
  payload /= integer_dtype_count;
  unsigned int dst = payload % integer_dtype_count;
  payload /= integer_dtype_count;
  unsigned int shape = payload % wide_shape_count;
  unsigned int op = payload / wide_shape_count;
  if (!integer_unary_operation_p (op) || (dst < 40 && source < 40))
    return false;
  /* Only indices are cached.  Trees and availability remain profile-local.  */
  static unsigned int anchors[integer_unary_operations][wide_shape_count]
    [integer_dtype_count];
  static unsigned int scanned;
  unsigned int &anchor = anchors[op][shape][dst];
  if (!anchor)
    {
      while (scanned < ZTT_BUILTIN_MAX)
	{
	  unsigned int i = scanned++;
	  const auto &d = builtin_description_for (i);
	  unsigned int operation = wide_operation (d.expansion);
	  if (!integer_unary_operation_p (operation) || types[d.type].accumulator
	      || floating_descriptor_p (types[d.type].descriptor))
	    continue;
	  const auto &t = types[d.type];
	  unsigned int q = exact_log2 (t.rows * t.columns);
	  unsigned int s = q ? 2 * q - (t.rows == 1) : 0;
	  unsigned int n = integer_dtype_number (t.descriptor);
	  gcc_assert (s < wide_shape_count && n < integer_dtype_count);
	  unsigned int &entry = anchors[operation][s][n];
	  if (!entry)
	    entry = i + 1;
	  if (anchor)
	    break;
	}
    }
  if (!anchor)
    return false;
  canonical = anchor - 1;
  return true;
}

static bool
decode_wide_builtin (unsigned int code, unsigned int &canonical,
		     unsigned int &data, unsigned int &count)
{
  wide_signature s;
  if (!decode_wide_signature (code, s))
    return false;
  const auto &op = wide_operations[s.operation];
  if ((s.count == wide_dtype_count)
      != (wide_unary_p (code) || op.prototype == PROTO_M_SHIFT_X)
      || (op.basic && s.shape != 0))
    return false;

  /* Integer-only metadata is safe across GC and target-option changes.
     Profile availability is checked by the normal decoder, not cached.  */
  static unsigned int anchors[WIDE_MAX][wide_shape_count][wide_dtype_count];
  static unsigned int scanned;
  unsigned int &anchor = anchors[s.operation][s.shape][s.dst];
  if (!anchor)
    {
      while (scanned < ZTT_BUILTIN_MAX)
	{
	  unsigned int i = scanned++;
	  const auto &d = builtin_description_for (i);
	  int operation = wide_operation (d.expansion);
	  if (operation < 0 || d.prototype != wide_operations[operation].prototype
	      || types[d.type].accumulator
	      || floating_descriptor_p (types[d.type].descriptor)
	      || extended_integer_p (types[d.type].descriptor))
	    continue;
	  const auto &t = types[d.type];
	  unsigned int dtype = mixed_dtype_number (t.descriptor);
	  unsigned int q = exact_log2 (t.rows * t.columns);
	  unsigned int shape = q ? 2 * q - (t.rows == 1) : 0;
	  gcc_assert (dtype < wide_dtype_count && shape < wide_shape_count);
	  unsigned int &entry = anchors[operation][shape][dtype];
	  if (!entry)
	    entry = i + 1;
	  if (anchor)
	    break;
	}
    }
  if (!anchor)
    return false;
  canonical = anchor - 1;
  data = s.data;
  count = s.count;
  return true;
}

static unsigned int
encode_extended_builtin (unsigned int canonical, type_index data,
			 type_index count)
{
  const auto &d = builtin_description_for (canonical);
  const auto &t = types[d.type];
  int operation = wide_operation (d.expansion);
  gcc_assert (operation >= 0);
  unsigned int q = exact_log2 (t.rows * t.columns);
  wide_signature s = {
    static_cast<unsigned int> (operation),
    q ? 2 * q - (t.rows == 1) : 0,
    mixed_dtype_number (t.descriptor),
    mixed_dtype_number (types[data].descriptor),
    count == TYPE_MAX ? wide_dtype_count
      : mixed_dtype_number (types[count].descriptor)
  };
  return encode_wide_signature (s);
}

static unsigned int
encode_elementwise_builtin (unsigned int canonical, type_index data,
			    type_index count)
{
  if ((types[builtin_description_for (canonical).type].descriptor & 0xff) > 32
      || (types[data].descriptor & 0xff) > 32
      || (count != TYPE_MAX && (types[count].descriptor & 0xff) > 32))
    return encode_extended_builtin (canonical, data, count);
  gcc_assert (canonical < elementwise_anchor_limit
	      && legacy_elementwise_anchor_p (canonical));
  return elementwise_code_base
    + (canonical * 24 + mixed_dtype_number (types[data].descriptor)) * 25
    + (count == TYPE_MAX ? 24 : mixed_dtype_number (types[count].descriptor));
}

static unsigned int
encode_conversion_builtin (unsigned int canonical, type_index source)
{
  if (extended_integer_p
	(types[builtin_description_for (canonical).type].descriptor)
      || extended_integer_p (types[source].descriptor))
    return encode_integer_unary_builtin (canonical, source);
  if ((types[builtin_description_for (canonical).type].descriptor & 0xff) > 32
      || (types[source].descriptor & 0xff) > 32)
    return encode_extended_builtin (canonical, source, TYPE_MAX);
  return conversion_code_base + canonical * 24
    + mixed_dtype_number (types[source].descriptor);
}

#if CHECKING_P
static void run_large_matrix_signature_selftests ();
static void run_acc_shared_source_selftests ();
static void run_md_reuse_selftests ();

static type_index
linear_matrix_type (unsigned int descriptor, unsigned int rows,
		    unsigned int columns, bool accumulator = false)
{
  for (unsigned int i = 0; i < TYPE_MAX; ++i)
    if (types[i].accumulator == accumulator && types[i].descriptor == descriptor
	&& types[i].rows == rows && types[i].columns == columns)
      return static_cast<type_index> (i);
  return TYPE_MAX;
}

static void
run_matrix_type_index_selftests ()
{
  using namespace selftest;
  for (unsigned int n = 0; n < numeric_dtype_count; ++n)
    {
      unsigned int descriptor = numeric_dtype_descriptor (n);
      for (unsigned int s = 0; s < wide_shape_count; ++s)
	{
	  unsigned int q = 1U << ((s + 1) / 2);
	  bool column = s && !(s & 1);
	  unsigned int rows = column ? q : 1, columns = column ? 1 : q;
	  type_index expected = linear_matrix_type (descriptor, rows, columns);
	  ASSERT_EQ (numeric_matrix_type (n, s), expected);
	  ASSERT_EQ (matrix_type_index (descriptor, rows, columns), expected);
	  if (n < integer_dtype_count)
	    ASSERT_EQ (integer_matrix_type (n, q, column), expected);
	  if (n < wide_dtype_count)
	    ASSERT_EQ (mixed_matrix_type (n, q, column), expected);
	}
      const unsigned int absent[][2] = {
	{ 0, 1 }, { 1, 0 }, { 2, 2 }, { 3, 1 }, { 1, 3 },
	{ 64, 1 }, { 1, 64 }, { ~0U, 1 }, { 1, ~0U }
      };
      for (const auto &shape : absent)
	ASSERT_EQ (matrix_type_index (descriptor, shape[0], shape[1]), TYPE_MAX);
      for (unsigned int s = 0; s < acc_shape_count; ++s)
	ASSERT_EQ (numeric_matrix_type (n, s, true),
		   linear_matrix_type (descriptor, 1, 1U << s, true));
    }

  for (unsigned int n = 0; n < numeric_scalar_dtype_count; ++n)
    {
      unsigned int descriptor = numeric_dtype_descriptor
	(n < 40 ? n : n < 80 ? n + 8 : n + 16);
      ASSERT_EQ (nominal_scalar_type_index (n),
		 linear_matrix_type (descriptor, 1, 1));
      ASSERT_EQ (nominal_scalar_number (nominal_scalar_type_index (n)), n);
    }

  for (unsigned int i = 0; i < TYPE_MAX; ++i)
    if (!types[i].accumulator)
      {
	const auto &t = types[i];
	ASSERT_EQ (numeric_dtype_descriptor (numeric_dtype_number (t.descriptor)),
		   t.descriptor);
	ASSERT_EQ (matrix_type_index (t.descriptor, t.rows, t.columns),
		   static_cast<type_index> (i));
	unsigned int half_rows = t.rows > 1 ? t.rows / 2 : 1;
	unsigned int half_columns = t.rows > 1 ? t.columns : t.columns / 2;
	ASSERT_EQ (m_utility_source_type (PROTO_M_CONCAT,
					 static_cast<type_index> (i)),
		   linear_matrix_type (t.descriptor, half_rows, half_columns));
	ASSERT_EQ (m_utility_source_type (PROTO_M_EXTRACT,
					 static_cast<type_index> (i)),
		   linear_matrix_type (t.descriptor,
				       t.rows > 1 ? t.rows * 2 : 1,
				       t.rows > 1 ? t.columns : t.columns * 2));
	ASSERT_EQ (m_utility_source_type (PROTO_M_EXTRACT_COLUMN,
					 static_cast<type_index> (i)),
		   linear_matrix_type (t.descriptor, t.rows * 2, t.columns));
      }
}

static void
run_redirect_lookup_selftests ()
{
  using namespace selftest;
  static constexpr expansion_index operations[] = {
    EXPAND_A_MMUL, EXPAND_A_MMULNEG, EXPAND_A_MMULAT, EXPAND_A_MMULATNEG,
    EXPAND_A_MMULBT, EXPAND_A_MMULBTNEG
  };
  constexpr unsigned int families = 2 + 6 * (matmul_shape_count - 1);
  auto_vec<unsigned int> expected;
  expected.safe_grow_cleared (TYPE_MAX * families);
  /* Independently retain the first catalog match, including absent keys.  */
  for (unsigned int i = 0; i < ZTT_BUILTIN_MAX; ++i)
    {
      const auto &d = builtin_description_for (i);
      unsigned int family = families;
      if (d.prototype == PROTO_M_EXTRACT_COLUMN)
	family = 0;
      else if (d.prototype == PROTO_A_M_COLUMN)
	family = 1;
      else if (const auto *shape = matmul_shape (d.prototype))
	if (shape->squares > 1)
	  for (unsigned int v = 0; v < ARRAY_SIZE (operations); ++v)
	    if (d.expansion == operations[v])
	      for (unsigned int s = 1; s < matmul_shape_count; ++s)
		if (d.prototype == matmul_prototype (s))
		  family = 2 + v * (matmul_shape_count - 1) + s - 1;
      if (family < families && !expected[d.type * families + family])
	expected[d.type * families + family] = i + 1;
    }
  for (unsigned int t = 0; t < TYPE_MAX; ++t)
    for (unsigned int f = 0; f < families; ++f)
      {
	prototype_index p = f == 0 ? PROTO_M_EXTRACT_COLUMN
	  : f == 1 ? PROTO_A_M_COLUMN
	  : matmul_prototype (1 + (f - 2) % (matmul_shape_count - 1));
	expansion_index e = f == 0 ? EXPAND_MEXTRACT : f == 1 ? EXPAND_A_FROM_M
	  : operations[(f - 2) / (matmul_shape_count - 1)];
	unsigned int code = expected[t * families + f];
	ASSERT_EQ (redirect_builtin_code (p, e, static_cast<type_index> (t)),
		   code ? code - 1 : ZTT_BUILTIN_MAX);
      }
  for (unsigned int t = TYPE_MAX; t > 0; --t)
    {
      unsigned int code = expected[(t - 1) * families];
      /* Column matching has never depended on the expansion field.  */
      ASSERT_EQ (redirect_builtin_code (PROTO_M_EXTRACT_COLUMN, EXPAND_A_MMUL,
				       static_cast<type_index> (t - 1)),
		 code ? code - 1 : ZTT_BUILTIN_MAX);
    }
  ASSERT_EQ (redirect_builtin_code (PROTO_M_M_M, EXPAND_MADD_EW, TYPE_I8_RNU_1X1),
	     ZTT_BUILTIN_MAX);
  ASSERT_EQ (redirect_builtin_code (PROTO_A_A_M_M_Q2_RC, EXPAND_MADD_EW,
				   TYPE_I8_RNU_ACCX1), ZTT_BUILTIN_MAX);
}

static void
run_store_lookup_selftests ()
{
  using namespace selftest;
  static constexpr expansion_index operations[] = {
    EXPAND_MSS_RM, EXPAND_MSS_CM, EXPAND_MSS_ST, EXPAND_MSS_TST
  };
  static constexpr type_index samples[] = {
    TYPE_I8_RNE_1X1, TYPE_I8_RNU_1X1, TYPE_I8_RNU_1X2, TYPE_I8_RNU_2X1,
    TYPE_I32_RDN_1X1, TYPE_U32_ROD_1X4, TYPE_I64_RNU_1X1, TYPE_U128_ROD_1X1,
    TYPE_F16_RNE_1X1, TYPE_BF16_RNE_1X1, TYPE_F32_RTZ_1X1, TYPE_F64_RMM_1X1,
    TYPE_I4_RNU_1X1, TYPE_I128_RNU_ACCX1
  };
  auto_vec<unsigned int> expected;
  expected.safe_grow_cleared (ARRAY_SIZE (operations) * TYPE_MAX);
  for (unsigned int i = 0; i < ZTT_BUILTIN_MAX; ++i)
    {
      const auto &d = builtin_description_for (i);
      if (!memory_store_p (d.expansion)
	  || (store_dispatch_p (i) && i != ZTT_BUILTIN_MSS_RM_I8_RNE_1X1))
	continue;
      for (unsigned int op = 0; op < ARRAY_SIZE (operations); ++op)
	if (d.expansion == operations[op])
	  {
	    unsigned int &code = expected[op * TYPE_MAX + d.type];
	    if (!code)
	      code = i + 1;
	  }
    }
  for (unsigned int op = 0; op < ARRAY_SIZE (operations); ++op)
    for (type_index type : samples)
      {
	unsigned int code = expected[op * TYPE_MAX + type];
	ASSERT_EQ (store_builtin_code (operations[op], type),
		   code ? code - 1 : ZTT_BUILTIN_MAX);
      }
  for (unsigned int op = ARRAY_SIZE (operations); op > 0; --op)
    for (unsigned int t = TYPE_MAX; t > 0; --t)
      {
	unsigned int code = expected[(op - 1) * TYPE_MAX + t - 1];
	ASSERT_EQ (store_builtin_code (operations[op - 1],
				       static_cast<type_index> (t - 1)),
		   code ? code - 1 : ZTT_BUILTIN_MAX);
      }
  ASSERT_EQ (store_builtin_code (EXPAND_MSS_RM, TYPE_I8_RNE_1X1),
	     ZTT_BUILTIN_MSS_RM_I8_RNE_1X1);
  for (auto op : operations)
    {
      ASSERT_EQ (store_builtin_code (op, TYPE_I4_RNU_1X1), ZTT_BUILTIN_MAX);
      ASSERT_EQ (store_builtin_code (op, TYPE_I128_RNU_ACCX1), ZTT_BUILTIN_MAX);
    }
}

static void
run_decoder_anchor_selftests ()
{
  using namespace selftest;
  unsigned int canonical, data, count;
  wide_signature early = {
    WIDE_MADD_EW, 0, mixed_dtype_number (types[TYPE_I8_RNE_1X1].descriptor),
    24, 0
  };
  ASSERT_TRUE (decode_wide_builtin (encode_wide_signature (early),
				   canonical, data, count));
  ASSERT_EQ (canonical, ZTT_BUILTIN_MADD_EW_I8_RNE_1X1);
  unsigned int unary_code = encode_integer_unary_builtin
    (ZTT_BUILTIN_MCONV_EW_I8_RNU_1X1, TYPE_I4_RNU_1X1);
  ASSERT_TRUE (decode_integer_unary_builtin (unary_code, canonical, data));
  ASSERT_EQ (canonical, ZTT_BUILTIN_MCONV_EW_I8_RNU_1X1);

  auto_vec<unsigned int> wide, unary;
  wide.safe_grow_cleared (WIDE_MAX * wide_shape_count * wide_dtype_count);
  unary.safe_grow_cleared
    (integer_unary_operations * wide_shape_count * integer_dtype_count);
  /* Independently retain the first catalog entry for every anchor key.  */
  for (unsigned int i = 0; i < ZTT_BUILTIN_MAX; ++i)
    {
      const auto d = builtin_description_for (i);
      int op = wide_operation (d.expansion);
      const auto &t = types[d.type];
      if (op < 0 || t.accumulator || floating_descriptor_p (t.descriptor))
	continue;
      unsigned int q = exact_log2 (t.rows * t.columns);
      unsigned int shape = q ? 2 * q - (t.rows == 1) : 0;
      if (d.prototype == wide_operations[op].prototype
	  && !extended_integer_p (t.descriptor))
	{
	  unsigned int key = (op * wide_shape_count + shape) * wide_dtype_count
	    + mixed_dtype_number (t.descriptor);
	  if (!wide[key])
	    wide[key] = i + 1;
	}
      if (integer_unary_operation_p (op))
	{
	  unsigned int key
	    = (op * wide_shape_count + shape) * integer_dtype_count
	      + integer_dtype_number (t.descriptor);
	  if (!unary[key])
	    unary[key] = i + 1;
	}
    }
  for (unsigned int key = 0; key < wide.length (); ++key)
    {
      unsigned int dst = key % wide_dtype_count;
      unsigned int shape = key / wide_dtype_count % wide_shape_count;
      unsigned int op = key / wide_dtype_count / wide_shape_count;
      auto p = wide_operations[op].prototype;
      bool unary_p = p == PROTO_M_CONVERT || p == PROTO_M_STRUCTURAL
	|| p == PROTO_M_ABS || p == PROTO_M_SHIFT_X;
      wide_signature s = { op, shape, dst, 39, unary_p ? wide_dtype_count : 0 };
      canonical = data = count = UINT_MAX;
      bool valid = wide[key] && !(wide_operations[op].basic && shape);
      ASSERT_EQ (decode_wide_builtin (encode_wide_signature (s),
				     canonical, data, count), valid);
      ASSERT_EQ (canonical, valid ? wide[key] - 1 : UINT_MAX);
      ASSERT_EQ (data, valid ? s.data : UINT_MAX);
      ASSERT_EQ (count, valid ? s.count : UINT_MAX);
      s.count = unary_p ? 0 : wide_dtype_count;
      ASSERT_FALSE (decode_wide_builtin (encode_wide_signature (s),
					canonical, data, count));
    }
  for (unsigned int key = 0; key < unary.length (); ++key)
    {
      unsigned int code = integer_unary_code_base
	+ key * integer_dtype_count + integer_dtype_count - 1;
      canonical = UINT_MAX;
      ASSERT_EQ (decode_integer_unary_builtin (code, canonical, data),
		 unary[key] != 0);
      ASSERT_EQ (canonical, unary[key] ? unary[key] - 1 : UINT_MAX);
      ASSERT_EQ (data, integer_dtype_count - 1);
    }
  ASSERT_TRUE (decode_wide_builtin (encode_wide_signature (early),
				   canonical, data, count));
  ASSERT_EQ (canonical, ZTT_BUILTIN_MADD_EW_I8_RNE_1X1);
  ASSERT_TRUE (decode_integer_unary_builtin (unary_code, canonical, data));
  ASSERT_EQ (canonical, ZTT_BUILTIN_MCONV_EW_I8_RNU_1X1);
}

static void
run_profile_lookup_selftests ()
{
  using namespace selftest;
  ASSERT_EQ (lookup_profile (nullptr), nullptr);
  ASSERT_EQ (lookup_profile (""), nullptr);
  char name[80];
  for (const auto &from : profiles)
    for (const auto &to : profiles)
      {
	ASSERT_EQ (lookup_profile (from.name), &from);
	size_t length = strlen (to.name);
	ASSERT_TRUE (length + 1 < sizeof (name));
	memcpy (name, to.name, length + 1);
	ASSERT_EQ (lookup_profile (name), &to);
	ASSERT_EQ (lookup_profile (name), &to);
	name[length] = 'x';
	name[length + 1] = '\0';
	ASSERT_EQ (lookup_profile (name), nullptr);
	ASSERT_EQ (lookup_profile (nullptr), nullptr);
	name[length] = '\0';
	ASSERT_EQ (lookup_profile (name), &to);
      }
}

static void
run_type_nregs_selftests ()
{
  using namespace selftest;
  const char *saved_profile = riscv_ztt_profile_string;
  for (unsigned int reverse : { 0U, 1U })
    for (unsigned int p = 0; p < ARRAY_SIZE (profiles); ++p)
      {
	unsigned int index = reverse ? ARRAY_SIZE (profiles) - 1 - p : p;
	const auto &profile = profiles[index];
	riscv_ztt_profile_string = profile.name;
	for (unsigned int repeat = 0; repeat < 2; ++repeat)
	  for (unsigned int i = 0; i < TYPE_MAX; ++i)
	    {
	      type_index type = static_cast<type_index> (i);
	      ASSERT_EQ (type_nregs (type),
			 type_nregs_for_profile (type, profile));
	    }
	riscv_ztt_profile_string = nullptr;
	ASSERT_EQ (type_nregs (TYPE_I8_RNU_1X1), 0U);
	riscv_ztt_profile_string = "invalid";
	ASSERT_EQ (type_nregs (TYPE_I8_RNU_1X1), 0U);
	riscv_ztt_profile_string = profile.name;
	ASSERT_EQ (type_nregs (TYPE_I8_RNU_1X1),
		   type_nregs_for_profile (TYPE_I8_RNU_1X1, profile));
      }
  riscv_ztt_profile_string = saved_profile;
}

static void
run_scalar_datatype_name_selftests ()
{
  using namespace selftest;
  static const unsigned int widths[] = { 8, 16, 32, 64, 128, 4 };
  static const char *const int_rm[] = { "rnu", "rne", "rdn", "rod" };
  static const char *const fp_rm[] = { "rne", "rtz", "rdn", "rup", "rmm", "rno" };
  static const char *const fp_types[] = { "f16", "bf16", "f32", "f64" };
  char expected[numeric_dtype_count][2][32];
  const char *names[numeric_dtype_count][2];
  ASSERT_EQ (integer_dtype_count, 2 * ARRAY_SIZE (widths) * 8);
  ASSERT_EQ (numeric_dtype_count - integer_dtype_count,
	     ARRAY_SIZE (fp_types) * ARRAY_SIZE (fp_rm));
  for (unsigned int n = 0; n < numeric_dtype_count; ++n)
    for (unsigned int alias = 0; alias < 2; ++alias)
      {
	char *name = expected[n][alias];
	if (n < integer_dtype_count)
	  snprintf (name, sizeof (expected[0][0]), "%c%u%s%s%s",
		    n % 8 >= 4 ? 'i' : 'u', widths[(n % 48) / 8],
		    alias ? "" : "_", alias ? "" : int_rm[n % 4],
		    n >= 48 ? "_sat" : "");
	else
	  {
	    unsigned int fp = n - integer_dtype_count;
	    snprintf (name, sizeof (expected[0][0]), "%s%s%s",
		      fp_types[fp / 6], alias ? "" : "_",
		      alias ? "" : fp_rm[fp % 6]);
	  }
	unsigned int d = numeric_dtype_descriptor (n);
	ASSERT_EQ (numeric_dtype_number (d), n);
	names[n][alias] = scalar_datatype_name (d, alias);
	ASSERT_STREQ (names[n][alias], expected[n][alias]);
      }
  /* Other lookups must not overwrite earlier results.  */
  for (unsigned int i = numeric_dtype_count; i > 0; --i)
    for (unsigned int alias = 0; alias < 2; ++alias)
      {
	unsigned int n = i - 1;
	ASSERT_STREQ (names[n][alias], expected[n][alias]);
	ASSERT_EQ (names[n][alias], scalar_datatype_name
		   (numeric_dtype_descriptor (n), alias));
      }
}

static void
run_scalar_registration_group_selftests ()
{
  using namespace selftest;
  if (!TARGET_ZTT)
    return;
  const char *saved_profile = riscv_ztt_profile_string;
  tree saved_types[TYPE_MAX];
  memcpy (saved_types, ztt_m_type_nodes, sizeof (saved_types));
  for (const auto &profile : profiles)
    if (!profile.n && profile.accregs == 16)
      {
	riscv_ztt_profile_string = profile.name;
	for (unsigned int i = 0; i < TYPE_MAX; ++i)
	  ztt_m_type_nodes[i]
	    = type_nregs_for_profile (static_cast<type_index> (i), profile)
	      ? integer_zero_node : NULL_TREE;
	for (bool floating : { false, true })
	  {
	    auto_vec<scalar_registration_group> groups;
	    collect_scalar_registration_groups (groups, floating);
	    unsigned int count = floating ? floating_broadcast_code_count
	      : integer_broadcast_code_count;
	    unsigned int scalar_count = floating ? numeric_scalar_dtype_count
	      : integer_scalar_dtype_count;
	    unsigned int g = 0;
	    for (unsigned int i = 0; i < count; ++i)
	      {
		while (g < groups.length ()
		       && i >= groups[g].payload + scalar_count)
		  ++g;
		bool present = g < groups.length ()
		  && i >= groups[g].payload + groups[g].first_tc;
		type_index dst, tc;
		bool decoded = floating
		  ? decode_floating_broadcast (floating_broadcast_code_base + i,
					       dst, tc)
		  : decode_integer_broadcast (integer_broadcast_code_base + i,
					      dst, tc);
		ASSERT_EQ (present, decoded);
		if (decoded)
		  {
		    ASSERT_EQ (groups[g].dst, dst);
		    ASSERT_EQ (nominal_scalar_type_index (i % scalar_count), tc);
		  }
	      }
	  }
      }
  memcpy (ztt_m_type_nodes, saved_types, sizeof (saved_types));
  riscv_ztt_profile_string = saved_profile;
}

static void
run_scalar_full_name_selftests ()
{
  using namespace selftest;
  type_index sources[numeric_dtype_count];
  for (unsigned int n = 0; n < numeric_dtype_count; ++n)
    {
      sources[n] = TYPE_MAX;
      for (unsigned int t = 0; t < TYPE_MAX; ++t)
	if (!types[t].accumulator
	    && types[t].descriptor == numeric_dtype_descriptor (n))
	  {
	    sources[n] = static_cast<type_index> (t);
	    break;
	  }
      ASSERT_NE (sources[n], TYPE_MAX);
    }
  auto check = [] (const char *op, type_index dst, type_index tc, bool alias) {
    char expected[160], actual[162];
    int length = snprintf (expected, sizeof (expected),
			   "__riscv_ztt_%s_%s_%ux%u_%s", op,
			   scalar_datatype_name (types[dst].descriptor, alias),
			   types[dst].rows, types[dst].columns,
			   scalar_datatype_name (types[tc].descriptor, alias));
    ASSERT_TRUE (length > 0 && static_cast<size_t> (length) < sizeof (expected));
    memset (actual, '#', sizeof (actual));
    integer_scalar_name (actual + 1, length + 1, op, dst, tc, alias);
    ASSERT_STREQ (expected, actual + 1);
    ASSERT_EQ (actual[0], '#');
    ASSERT_EQ (actual[length + 2], '#');
  };
  for (unsigned int t = 0; t < TYPE_MAX; ++t)
    for (unsigned int n = 0; n < numeric_dtype_count; ++n)
      for (unsigned int alias = 0; alias < 2; ++alias)
	check (numeric_scalar_name (n % floating_scalar_operations),
	       static_cast<type_index> (t), sources[n], alias);
  for (unsigned int op = 0; op <= floating_scalar_operations; ++op)
    for (unsigned int alias = 0; alias < 2; ++alias)
      check (op == floating_scalar_operations ? "mbcast_m_x"
	     : numeric_scalar_name (op), TYPE_I128_ROD_1X1,
	     TYPE_BF16_RNO_1X1, alias);
}

void
run_wide_signature_selftests ()
{
  using namespace selftest;
  builtin_decl_cache cache = {}, other = {};
  ASSERT_EQ (cache.get (conversion_code_base), NULL_TREE);
  ASSERT_EQ (cache.entries, nullptr);
  for (unsigned int i = 0; i < 256; ++i)
    ASSERT_EQ (cache.put (conversion_code_base + i * 257, integer_one_node),
	       integer_one_node);
  other.put (conversion_code_base, integer_zero_node);
  for (unsigned int i = 256; i-- > 0;)
    {
      ASSERT_EQ (cache.get (conversion_code_base + i * 257), integer_one_node);
      ASSERT_EQ (cache.get (conversion_code_base + i * 257 + 1), NULL_TREE);
    }
  ASSERT_EQ (other.get (conversion_code_base), integer_zero_node);
  run_matrix_type_index_selftests ();
  run_store_lookup_selftests ();
  run_redirect_lookup_selftests ();
  run_decoder_anchor_selftests ();
  run_profile_lookup_selftests ();
  run_type_nregs_selftests ();
  run_scalar_datatype_name_selftests ();
  run_scalar_full_name_selftests ();
  run_scalar_registration_group_selftests ();
  run_acc_shared_source_selftests ();
  run_md_reuse_selftests ();
  for (unsigned int i = 0; i < exponent_type_count; ++i)
    {
      auto d = builtin_description_for (exponent_first + i);
      auto a = builtin_description_for
	(exponent_first + exponent_type_count + i);
      ASSERT_EQ (d.prototype, PROTO_M_EXPONENT_X);
      ASSERT_EQ (a.prototype, PROTO_M_EXPONENT_ACC_X);
      ASSERT_EQ (d.expansion, EXPAND_MLDEXP_EW_X);
      ASSERT_EQ (a.expansion, EXPAND_MLDEXPACC_EW_X);
      ASSERT_EQ (d.type, a.type);
      ASSERT_FALSE (types[d.type].accumulator);
    }
  ASSERT_EQ (builtin_description_for (exponent_first).type, TYPE_I4_RNU_1X1);
  ASSERT_EQ (builtin_description_for (exponent_first + exponent_count - 1).type,
	     TYPE_F64_RNO_32X1);
  auto after = builtin_description_for (exponent_first + exponent_count);
  ASSERT_EQ (after.type, TYPE_I128_RNU_1X1);
  ASSERT_EQ (after.expansion, EXPAND_MLS_RM);
  char name[160];
  ASSERT_STREQ (canonical_builtin_name
		 (builtin_description_for (exponent_first), name),
		 "__riscv_ztt_mldexp_ew_x_i4_rnu_1x1");
  ASSERT_STREQ (canonical_builtin_name
		 (builtin_description_for (ZTT_BUILTIN_MLDEXP_EW_X_BF16_RMM_2X1),
		  name), "__riscv_ztt_mldexp_ew_x_bf16_rmm_2x1");
  ASSERT_STREQ (canonical_builtin_name
		 (builtin_description_for (ZTT_BUILTIN_MLDEXPACC_EW_X_U128_ROD_SAT_1X2),
		  name), "__riscv_ztt_mldexpacc_ew_x_u128_rod_sat_1x2");
  ASSERT_FALSE (exponent_code_p (exponent_code_base - 1));
  ASSERT_FALSE (exponent_code_p (exponent_code_base + exponent_code_count));
  for (unsigned int op = 0; op < 2; ++op)
    for (unsigned int u = 0; u < 5; ++u)
      for (unsigned int d = 0; d < 6; ++d)
	for (unsigned int a = 0; a < 6; ++a)
	  {
	    unsigned int code = exponent_code_base + ((op * 5 + u) * 6 + d) * 6 + a;
	    ASSERT_TRUE (exponent_code_p (code));
	    unsigned int n = code - exponent_code_base;
	    ASSERT_EQ (n % 6, a);
	    ASSERT_EQ (n / 6 % 6, d);
	    ASSERT_EQ (n / 36 % 5, u);
	    ASSERT_EQ (n / 180, op);
	  }
  ASSERT_FALSE (floating_unary_code_p (floating_unary_code_base - 1));
  ASSERT_TRUE (floating_unary_code_p (floating_unary_code_base));
  ASSERT_TRUE (floating_unary_code_p (floating_unary_code_base
				    + floating_unary_code_count - 1));
  ASSERT_FALSE (floating_unary_code_p (floating_unary_code_base
				     + floating_unary_code_count));
  ASSERT_FALSE (floating_matrix_code_p (floating_matrix_code_base - 1));
  ASSERT_TRUE (floating_matrix_code_p (floating_matrix_code_base));
  ASSERT_TRUE (floating_matrix_code_p (floating_matrix_code_base
				     + floating_matrix_code_count - 1));
  ASSERT_FALSE (floating_matrix_code_p (floating_matrix_code_base
				      + floating_matrix_code_count));
  ASSERT_EQ (arithmetic_variant (EXPAND_MMIN_EW), 33);
  ASSERT_EQ (arithmetic_variant (EXPAND_MMAX_EW), 34);
  ASSERT_EQ (arithmetic_variant (EXPAND_MLDEXP_EW), 35);
  ASSERT_EQ (arithmetic_variant (EXPAND_MRDEXP_EW), 36);
  ASSERT_EQ (arithmetic_variant (EXPAND_MLOG2SUB_EW), 37);
  ASSERT_EQ (arithmetic_variant (EXPAND_MSUBLOG2_EW), 38);
  ASSERT_EQ (ternary_variant (EXPAND_MLDEXPACC_EW), 6);
  ASSERT_EQ (ternary_variant (EXPAND_MRDEXPACC_EW), 7);
  ASSERT_FALSE (matrix_math_code_p (matrix_math_code_base - 1));
  ASSERT_TRUE (matrix_math_code_p (matrix_math_code_base));
  ASSERT_TRUE (matrix_math_code_p (matrix_math_code_base + matrix_math_code_count - 1));
  ASSERT_FALSE (matrix_math_code_p (matrix_math_code_base + matrix_math_code_count));
  ASSERT_FALSE (floating_scalar_public_p (floating_scalar_public_base - 1));
  ASSERT_TRUE (floating_scalar_public_p (floating_scalar_public_base));
  ASSERT_TRUE (floating_scalar_public_p (floating_scalar_public_base + floating_scalar_public_count - 1));
  ASSERT_FALSE (floating_scalar_public_p (floating_scalar_public_base + floating_scalar_public_count));
  ASSERT_FALSE (floating_scalar_code_p (floating_scalar_code_base - 1));
  ASSERT_TRUE (floating_scalar_code_p (floating_scalar_code_base));
  ASSERT_TRUE (floating_scalar_code_p (floating_scalar_code_base + floating_scalar_code_count - 1));
  ASSERT_FALSE (floating_scalar_code_p (floating_scalar_code_base + floating_scalar_code_count));
  ASSERT_FALSE (floating_broadcast_code_p (floating_broadcast_code_base - 1));
  ASSERT_TRUE (floating_broadcast_code_p (floating_broadcast_code_base));
  ASSERT_TRUE (floating_broadcast_code_p (floating_broadcast_code_base
					+ floating_broadcast_code_count - 1));
  ASSERT_FALSE (floating_broadcast_code_p (floating_broadcast_code_base
					 + floating_broadcast_code_count));
  ASSERT_EQ (scalar_arithmetic_variant (EXPAND_MLOG2SUB_EW_X), 39);
  ASSERT_EQ (scalar_arithmetic_variant (EXPAND_MSUBLOG2_EW_X), 40);
  ASSERT_TRUE (data_scalar_variant_p (39));
  ASSERT_TRUE (data_scalar_variant_p (40));
  ASSERT_FALSE (integer_scalar_old_p (20));
  ASSERT_FALSE (integer_scalar_old_p (21));
  const char *scalar_name
    = scalar_datatype_name (types[TYPE_I16_ROD_1X1].descriptor, false);
  ASSERT_STREQ (scalar_name, "i16_rod");
  scalar_name = scalar_datatype_name (types[TYPE_BF16_RNO_1X1].descriptor, false);
  ASSERT_STREQ (scalar_name, "bf16_rno");
  scalar_name = scalar_datatype_name (types[TYPE_F64_RNE_1X1].descriptor, true);
  ASSERT_STREQ (scalar_name, "f64");
  ASSERT_TRUE (elementwise_anchor_limit < ZTT_BUILTIN_MAX);
  for (unsigned int op = 0; op < 24; ++op)
    ASSERT_EQ (floating_unary_operation (floating_unary_expansion (op)),
	       static_cast<int> (op));
  ASSERT_EQ (floating_unary_operation (EXPAND_MADD_EW), -1);
  for (unsigned int t = TYPE_F16_RNE_1X1; t < TYPE_MAX; ++t)
    {
      unsigned int d = types[t].descriptor;
      ASSERT_TRUE (floating_descriptor_p (d));
      ASSERT_FALSE (extended_integer_p (d));
      ASSERT_TRUE (((d >> 22) & 15) < 6);
      unsigned int expbits = (d >> 26) & 31;
      ASSERT_TRUE (expbits == 5 || expbits == 8 || expbits == 11);
    }
  ASSERT_FALSE (integer_scalar_public_p (integer_scalar_public_base - 1));
  ASSERT_TRUE (integer_scalar_public_p (integer_scalar_public_base));
  ASSERT_TRUE (integer_scalar_public_p (integer_scalar_public_base
				      + integer_scalar_public_count - 1));
  ASSERT_FALSE (integer_scalar_public_p (integer_scalar_public_base
				       + integer_scalar_public_count));
  ASSERT_FALSE (integer_scalar_code_p (integer_scalar_code_base - 1));
  ASSERT_TRUE (integer_scalar_code_p (integer_scalar_code_base));
  ASSERT_TRUE (integer_scalar_code_p (integer_scalar_code_base
				    + integer_scalar_code_count - 1));
  ASSERT_FALSE (integer_scalar_code_p (integer_scalar_code_base
				     + integer_scalar_code_count));
  for (unsigned int op = 0; op < integer_scalar_operations; ++op)
    {
      auto expansion = wide_operations[WIDE_MADD_EW_X + op].expansion;
      ASSERT_TRUE (scalar_arithmetic_variant (expansion) >= 0
		   || scalar_ternary_variant (expansion) >= 0);
      ASSERT_EQ (wide_operation (expansion), static_cast<int> (WIDE_MADD_EW_X + op));
      ASSERT_EQ (integer_scalar_old_p (op), op >= 14 && op <= 17);
    }
  for (unsigned int op = 0; op < floating_scalar_operations; ++op)
    {
      const char *name = numeric_scalar_name (op);
      bool integer_only = strstr (name, "and") || strstr (name, "or")
	|| strstr (name, "cmpge") || strstr (name, "cmplt");
      ASSERT_EQ (floating_scalar_operation_p (op, true), !integer_only);
      ASSERT_EQ (floating_scalar_operation_p (op, false),
		 strstr (name, "log2") == nullptr);
    }
  ASSERT_FALSE (integer_broadcast_code_p (integer_broadcast_code_base - 1));
  ASSERT_TRUE (integer_broadcast_code_p (integer_broadcast_code_base));
  ASSERT_FALSE (integer_broadcast_code_p (integer_broadcast_code_base
					+ integer_broadcast_code_count));
  for (unsigned int d = 0; d < integer_dtype_count; ++d)
    for (unsigned int s = 0; s < wide_shape_count; ++s)
      for (unsigned int c = 0; c < integer_scalar_dtype_count; ++c)
	{
	  unsigned int code = integer_broadcast_code (d, s, c);
	  ASSERT_TRUE (integer_broadcast_code_p (code));
	  unsigned int payload = code - integer_broadcast_code_base;
	  ASSERT_EQ (payload % integer_scalar_dtype_count, c);
	  payload /= integer_scalar_dtype_count;
	  ASSERT_EQ (payload % wide_shape_count, s);
	  ASSERT_EQ (payload / wide_shape_count, d);
	  ASSERT_NE (integer_dtype_descriptor (c < 40 ? c : c + 8) & 0xff, 4U);
	}
  ASSERT_FALSE (integer_matrix_code_p (integer_matrix_code_base - 1));
  ASSERT_TRUE (integer_matrix_code_p (integer_matrix_code_base));
  ASSERT_TRUE (integer_matrix_code_p (integer_matrix_code_base
				     + integer_matrix_code_count - 1));
  ASSERT_FALSE (integer_matrix_code_p (integer_matrix_code_base
				      + integer_matrix_code_count));
  ASSERT_FALSE (integer_matrix_code_p (integer_unary_code_limit - 1));
  ASSERT_FALSE (integer_matrix_code_p (scalar_code_base));
  ASSERT_FALSE (integer_matmul_code_p (integer_matmul_code_base - 1));
  ASSERT_TRUE (integer_matmul_code_p (integer_matmul_code_base));
  ASSERT_TRUE (integer_matmul_code_p (integer_matmul_code_base
				     + integer_matmul_code_count - 1));
  ASSERT_FALSE (integer_matmul_code_p (integer_matmul_code_base
				      + integer_matmul_code_count));
  ASSERT_FALSE (integer_matmul_code_p (scalar_code_base));
  ASSERT_FALSE (floating_matmul_code_p (floating_matmul_code_base - 1));
  ASSERT_TRUE (floating_matmul_code_p (floating_matmul_code_base));
  ASSERT_TRUE (floating_matmul_code_p (floating_matmul_code_base
				     + floating_matmul_code_count - 1));
  ASSERT_FALSE (floating_matmul_code_p (floating_matmul_code_base
				      + floating_matmul_code_count));
  for (unsigned int i = 0; i < numeric_dtype_count; ++i)
    ASSERT_EQ (i, numeric_dtype_number (numeric_dtype_descriptor (i)));
  for (unsigned int n = 0; n < integer_dtype_count; ++n)
    {
      unsigned int d = integer_dtype_descriptor (n);
      ASSERT_EQ (integer_dtype_number (d), n);
      ASSERT_EQ (extended_integer_p (d), n >= 40);
      ASSERT_EQ ((d >> 29) & 1, n >= 48 ? 1U : 0U);
    }
  unsigned int canonical, source;
  ASSERT_FALSE (decode_integer_unary_builtin
		(integer_unary_code_base - 1, canonical, source));
  ASSERT_FALSE (decode_integer_unary_builtin
		(integer_unary_code_limit, canonical, source));
  for (unsigned int i = 0; i < ZTT_BUILTIN_MAX; ++i)
    {
      const auto &d = builtin_description_for (i);
      if (legacy_elementwise_anchor_p (i))
	ASSERT_TRUE (i < elementwise_anchor_limit);
      if (d.prototype != PROTO_M_CONVERT
	  || floating_descriptor_p (types[d.type].descriptor))
	continue;
      const auto &t = types[d.type];
      for (unsigned int src : { 0U, 23U, 39U, 40U, 47U, 48U, 87U, 95U })
	{
	  type_index st = integer_matrix_type
	    (src, t.rows * t.columns, t.rows > 1);
	  ASSERT_NE (st, TYPE_MAX);
	  unsigned int code = encode_integer_unary_builtin (i, st);
	  bool extended = extended_integer_p (t.descriptor) || src >= 40;
	  ASSERT_EQ (decode_integer_unary_builtin (code, canonical, source),
		     extended);
	  if (extended)
	    {
	      ASSERT_EQ (source, src);
	      ASSERT_EQ (builtin_description_for (canonical).type, d.type);
	      ASSERT_EQ (builtin_description_for (canonical).expansion, d.expansion);
	    }
	}
    }
  for (unsigned int type = 0; type < wide_dtype_count; ++type)
    ASSERT_EQ (mixed_dtype_number (mixed_dtype_descriptor (type)), type);
  for (unsigned int op = 0; op < WIDE_MAX; ++op)
    for (unsigned int shape = 0; shape < wide_shape_count; ++shape)
      for (unsigned int dst : { 0U, 23U, 24U, 39U })
	for (unsigned int a : { 0U, 23U, 24U, 39U })
	  for (unsigned int b : { 0U, 23U, 24U, 39U, 40U })
	    {
	      wide_signature s = { op, shape, dst, a, b }, decoded;
	      unsigned int code = encode_wide_signature (s);
	      ASSERT_TRUE (code >= wide_code_base && code < scalar_code_base);
	      bool wide = dst >= 24 || a >= 24 || (b >= 24 && b < 40);
	      ASSERT_EQ (decode_wide_signature (code, decoded), wide);
	      if (!wide)
		continue;
	      ASSERT_EQ (decoded.operation, op);
	      ASSERT_EQ (decoded.shape, shape);
	      ASSERT_EQ (decoded.dst, dst);
	      ASSERT_EQ (decoded.data, a);
	      ASSERT_EQ (decoded.count, b);
	    }
  wide_signature invalid;
  ASSERT_FALSE (decode_wide_signature (wide_code_base - 1, invalid));
  ASSERT_FALSE (decode_wide_signature (wide_code_limit, invalid));
  ASSERT_FALSE (decode_wide_signature (scalar_code_base - 1, invalid));
  ASSERT_FALSE (decode_wide_signature (mixed_code_base, invalid));
  for (unsigned int v = 0; v < 6; ++v)
    for (unsigned int k = 0; k < 5; ++k)
      for (unsigned int q = 0; q < matmul_shape_count; ++q)
	for (unsigned int d : { 0U, 23U, 24U, 39U })
	  for (unsigned int a : { 0U, 23U, 24U, 39U })
	    for (unsigned int b : { 0U, 23U, 24U, 39U })
	      {
		wide_matmul_signature s = { v, k, q, d, a, b }, decoded;
		unsigned int code = encode_wide_matmul_signature (s);
		bool wide = d >= 24 || a >= 24 || b >= 24;
		ASSERT_TRUE (wide_matmul_code_p (code));
		ASSERT_EQ (decode_wide_matmul_signature (code, decoded), wide);
		if (!wide)
		  continue;
		ASSERT_EQ (decoded.variant, v);
		ASSERT_EQ (decoded.acc_group, k);
		ASSERT_EQ (decoded.shape, q);
		ASSERT_EQ (decoded.dst, d);
		ASSERT_EQ (decoded.lhs, a);
		ASSERT_EQ (decoded.rhs, b);
	      }
  wide_matmul_signature bad;
  ASSERT_FALSE (decode_wide_matmul_signature (wide_matmul_code_base - 1, bad));
  ASSERT_FALSE (decode_wide_matmul_signature (wide_matmul_code_limit, bad));
  ASSERT_FALSE (decode_wide_matmul_signature (conversion_code_base - 1, bad));
  run_large_matrix_signature_selftests ();
}
#endif

static bool
decode_mixed_builtin (unsigned int code, mixed_description &result)
{
  bool wide = wide_matmul_code_p (code);
  if ((!wide && code < mixed_code_base) || !TARGET_ZTT || !acc_profile_p ())
    return false;
  bool packed_p = wide || code >= packed_code_base;
  unsigned int lhs, rhs, shape;
  if (wide)
    {
      wide_matmul_signature s;
      if (!decode_wide_matmul_signature (code, s))
	return false;
      /* Cache only integer anchor metadata, never profile-dependent trees.  */
      static unsigned int anchors[6][5][wide_dtype_count];
      static bool initialized;
      if (!initialized)
	{
	  for (unsigned int i = 0; i < ZTT_BUILTIN_MAX; ++i)
	    {
	      const auto &d = builtin_description_for (i);
	      int variant = matmul_variant (d.expansion);
	      if (variant < 0 || d.prototype != PROTO_A_A_M_M
		  || extended_integer_p (types[d.type].descriptor)
		  || floating_descriptor_p (types[d.type].descriptor))
		continue;
	      const auto &t = types[d.type];
	      unsigned int &anchor
		= anchors[variant][exact_log2 (t.columns)]
			 [mixed_dtype_number (t.descriptor)];
	      gcc_assert (!anchor);
	      anchor = i + 1;
	    }
	  initialized = true;
	}
      unsigned int anchor = anchors[s.variant][s.acc_group][s.dst];
      if (!anchor)
	return false;
      result.canonical = anchor - 1;
      lhs = s.lhs;
      rhs = s.rhs;
      shape = s.shape;
    }
  else
    {
      bool q32_p = code >= q32_code_base;
      unsigned int radix = q32_p ? q32_shape_count
	: packed_p ? packed_shape_count : mixed_shape_count;
      unsigned int base = q32_p ? q32_code_base
	: packed_p ? packed_code_base : mixed_code_base;
      unsigned int payload = code - base;
      rhs = payload % mixed_dtype_count;
      payload /= mixed_dtype_count;
      lhs = payload % mixed_dtype_count;
      payload /= mixed_dtype_count;
      shape = payload % radix;
      if (q32_p)
	shape += packed_shape_count;
      result.canonical = payload / radix;
    }
  if (result.canonical >= ZTT_BUILTIN_MAX)
    return false;
  const auto &d = builtin_description_for (result.canonical);
  if (d.prototype != PROTO_A_A_M_M
      || !matmul_shape_allowed_p (shape, d.expansion)
      || (!packed_p && (types[d.type].descriptor & 0xff) < active_profile ()->uds)
      || !ztt_m_type_nodes[d.type])
    return false;
  result.prototype = matmul_prototype (shape);
  const auto &s = *matmul_shape (result.prototype);
  result.lhs = mixed_matrix_type (lhs, s.squares, s.lhs_column);
  result.rhs = mixed_matrix_type (rhs, s.squares, s.rhs_column);
  for (auto type : { result.lhs, result.rhs })
    if (type == TYPE_MAX || !ztt_m_type_nodes[type]
	|| (!packed_p && (types[type].descriptor & 0xff) < active_profile ()->uds))
      return false;
  matmul_formation formation;
  return form_matmul (types[result.lhs].descriptor & 0xff,
		      types[result.rhs].descriptor & 0xff, s.squares,
		      active_profile ()->uds, formation);
}

static bool
decode_elementwise_builtin (unsigned int code, elementwise_description &result)
{
  bool wide = wide_code_p (code);
  if ((!wide && (code < elementwise_code_base || code >= mixed_code_base))
      || !TARGET_ZTT || !typed_profile_p ())
    return false;
  unsigned int data, count;
  if (wide)
    {
      if (!decode_wide_builtin (code, result.canonical, data, count))
	return false;
    }
  else
    {
      unsigned int payload = code - elementwise_code_base;
      count = payload % 25;
      payload /= 25;
      data = payload % 24;
      result.canonical = payload / 24;
      if (result.canonical >= elementwise_anchor_limit
	  || !legacy_elementwise_anchor_p (result.canonical))
	return false;
    }
  if (result.canonical >= ZTT_BUILTIN_MAX)
    return false;
  const auto &d = builtin_description_for (result.canonical);
  bool scalar = d.prototype == PROTO_M_SHIFT_X;
  bool indexed = indexed_variant (d.expansion) >= 0;
  if ((!scalar && d.prototype != PROTO_M_SHIFT_M
       && d.prototype != PROTO_M_BINARY_M && !indexed
       && d.prototype != PROTO_M_TERNARY_M
       && arithmetic_variant (d.expansion) < 0)
      || scalar != (count == (wide ? wide_dtype_count : 24))
      || !ztt_m_type_nodes[d.type])
    return false;
  const auto &dst = types[d.type];
  unsigned int q = dst.rows * dst.columns;
  if (indexed && q != 1)
    return false;
  result.data = mixed_matrix_type (data, q, dst.rows > 1);
  result.count = scalar ? TYPE_MAX
    : mixed_matrix_type (count, q, dst.rows > 1);
  if (result.data == TYPE_MAX || !ztt_m_type_nodes[result.data]
      || (!scalar && (result.count == TYPE_MAX
		     || !ztt_m_type_nodes[result.count])))
    return false;
  if ((d.expansion == EXPAND_MSRA_EW || d.expansion == EXPAND_MSRA_EW_X)
      && !(types[result.data].descriptor & (1U << 30)))
    return false;
  if (d.prototype == PROTO_M_GATHER && result.data != d.type)
    return false;
  if (selected_data_p (d.expansion) && result.count != d.type)
    return false;
  return form_elementwise (dst.descriptor & 0xff,
		     types[result.data].descriptor & 0xff,
		     scalar ? 0 : types[result.count].descriptor & 0xff,
		     q, active_profile ()->uds, result.formation);
}

struct integer_matrix_signature
{
  unsigned int operation, dst, lhs, rhs;
};

enum matrix_domain
{
  MATRIX_INTEGER,
  MATRIX_FLOATING,
  MATRIX_MATH
};

static bool
matrix_builtin_code_p (unsigned int code)
{
  return integer_matrix_code_p (code) || floating_matrix_code_p (code)
    || matrix_math_code_p (code);
}

static matrix_domain
matrix_code_domain (unsigned int code)
{
  gcc_assert (matrix_builtin_code_p (code));
  return matrix_math_code_p (code) ? MATRIX_MATH
    : floating_matrix_code_p (code) ? MATRIX_FLOATING : MATRIX_INTEGER;
}

static unsigned int
matrix_domain_base (matrix_domain domain, bool large = false)
{
  if (large)
    return domain == MATRIX_MATH ? large_matrix_math_code_base
      : domain == MATRIX_FLOATING ? large_floating_matrix_code_base
      : large_integer_matrix_code_base;
  return domain == MATRIX_MATH ? matrix_math_code_base
    : domain == MATRIX_FLOATING ? floating_matrix_code_base
    : integer_matrix_code_base;
}

static const char *
matrix_domain_name (matrix_domain domain)
{
  return domain == MATRIX_MATH ? "math"
    : domain == MATRIX_FLOATING ? "floating" : "integer";
}

static bool
floating_matrix_operation_p (unsigned int op)
{
  return op < 11 || IN_RANGE (op, 29, 42);
}

static const wide_operation_info &
matrix_operation_info (unsigned int op)
{
  static constexpr wide_operation_info minmax[] = {
    { EXPAND_MMIN_EW, PROTO_M_M_M, false },
    { EXPAND_MMAX_EW, PROTO_M_M_M, false },
#define ZTT_MATRIX_MATH(OP, NAME, PROTO) { EXPAND_##OP, PROTO_##PROTO, false },
#include "riscv-ztt-operations.def"
#undef ZTT_MATRIX_MATH
  };
  gcc_assert (op < 41 + ARRAY_SIZE (minmax));
  return op < 41 ? wide_operations[op] : minmax[op - 41];
}

static int
floating_matrix_operation (expansion_index expansion)
{
  if (expansion == EXPAND_MMIN_EW || expansion == EXPAND_MMAX_EW)
    return expansion == EXPAND_MMIN_EW ? 41 : 42;
  int op = wide_operation (expansion);
  return op >= 0 && op < 41 && floating_matrix_operation_p (op) ? op : -1;
}

static int
matrix_math_operation (expansion_index expansion)
{
  return IN_RANGE (expansion, EXPAND_MLDEXP_EW, EXPAND_MSUBLOG2_EW)
    ? 43 + expansion - EXPAND_MLDEXP_EW : -1;
}

static bool
integer_matrix_operation_p (unsigned int op)
{
  return op < integer_unary_operations && !integer_unary_operation_p (op);
}

static bool
matrix_domain_operation_p (unsigned int op, matrix_domain domain)
{
  return domain == MATRIX_MATH ? IN_RANGE (op, 43, 48)
    : domain == MATRIX_FLOATING ? floating_matrix_operation_p (op)
    : integer_matrix_operation_p (op);
}

static bool
integer_matrix_old_p (unsigned int op)
{
  return matrix_operation_info (op).prototype == PROTO_M_TERNARY_M
    || matrix_operation_info (op).prototype == PROTO_M_SCATTER;
}

static bool
decode_integer_matrix_code (unsigned int code, integer_matrix_signature &s)
{
  if (!matrix_builtin_code_p (code))
    return false;
  matrix_domain domain = matrix_code_domain (code);
  bool large = code >= large_group_code_base;
  unsigned int radix = large ? 6 : 3;
  unsigned int n = code - matrix_domain_base (domain, large);
  s.rhs = n % (radix + 1);
  n /= radix + 1;
  bool scalar = s.rhs == radix;
  if (scalar)
    s.rhs = 6;
  s.lhs = n % radix;
  n /= radix;
  s.dst = n % radix;
  n /= radix;
  unsigned int uds = n % 5;
  s.operation = n / 5 + (domain == MATRIX_MATH ? 43 : 0);
  return matrix_domain_operation_p (s.operation, domain)
    && active_profile () && active_profile ()->uds == (8U << uds)
    && (1U << s.dst) <= active_profile ()->mregs
    && (1U << s.lhs) <= active_profile ()->mregs
    && (scalar || (1U << s.rhs) <= active_profile ()->mregs)
    && (!large || s.dst >= 3 || s.lhs >= 3 || (!scalar && s.rhs >= 3))
    && scalar
       == (matrix_operation_info (s.operation).prototype == PROTO_M_SHIFT_X);
}

static unsigned int
integer_matrix_code (unsigned int op, const elementwise_formation &f,
		     matrix_domain domain = MATRIX_INTEGER)
{
  bool scalar = matrix_operation_info (op).prototype == PROTO_M_SHIFT_X;
  bool large = f.nregs[0] > 4 || f.nregs[1] > 4 || (!scalar && f.nregs[2] > 4);
  unsigned int radix = large ? 6 : 3;
  unsigned int rhs = scalar ? radix : exact_log2 (f.nregs[2]);
  gcc_assert (matrix_domain_operation_p (op, domain));
  unsigned int ordinal = op - (domain == MATRIX_MATH ? 43 : 0);
  return matrix_domain_base (domain, large)
    + (((ordinal * 5 + exact_log2 (active_profile ()->uds) - 3) * radix
	+ exact_log2 (f.nregs[0])) * radix
       + exact_log2 (f.nregs[1])) * (radix + 1) + rhs;
}

#if CHECKING_P
/* The supplemental domain
   must not renumber old signatures or confuse an 8-M RHS with a scalar.  */
static void
run_large_matrix_signature_selftests ()
{
  using namespace selftest;
  const char *saved_profile = riscv_ztt_profile_string;
  for (unsigned int u = 0; u < 5; ++u)
    {
      char profile[48];
      snprintf (profile, sizeof (profile), "gcc-runtime-u%u-m32-a16", 8U << u);
      riscv_ztt_profile_string = profile;
      for (matrix_domain domain : { MATRIX_INTEGER, MATRIX_FLOATING, MATRIX_MATH })
	for (unsigned int op = 0; op < 49; ++op)
	  {
	    if (!matrix_domain_operation_p (op, domain))
	      continue;
	    bool scalar = matrix_operation_info (op).prototype == PROTO_M_SHIFT_X;
	    for (unsigned int d = 0; d < 6; ++d)
	      for (unsigned int a = 0; a < 6; ++a)
		for (unsigned int b = 0; b < (scalar ? 1U : 6U); ++b)
		  {
		    elementwise_formation f = {};
		    f.nregs[0] = 1U << d;
		    f.nregs[1] = 1U << a;
		    f.nregs[2] = scalar ? 0 : 1U << b;
		    unsigned int code = integer_matrix_code (op, f, domain);
		    bool large = d >= 3 || a >= 3 || (!scalar && b >= 3);
		    ASSERT_EQ (code >= large_group_code_base, large);
		    if (!large)
		      ASSERT_EQ (code, matrix_domain_base (domain)
			+ ((((op - (domain == MATRIX_MATH ? 43 : 0)) * 5 + u)
			    * 3 + d) * 3 + a) * 4 + (scalar ? 3 : b));
		    integer_matrix_signature s;
		    ASSERT_TRUE (decode_integer_matrix_code (code, s));
		    ASSERT_EQ (s.operation, op);
		    ASSERT_EQ (s.dst, d);
		    ASSERT_EQ (s.lhs, a);
		    ASSERT_EQ (s.rhs, scalar ? 6U : b);
		  }
	  }
    }
  const unsigned int bases[] = {
    large_integer_matrix_code_base, large_floating_matrix_code_base,
    large_matrix_math_code_base, large_floating_unary_code_base,
    large_integer_scalar_code_base, large_floating_scalar_code_base,
    large_integer_matmul_code_base, large_floating_matmul_code_base
  };
  const unsigned int counts[] = {
    large_integer_matrix_code_count, large_floating_matrix_code_count,
    large_matrix_math_code_count, large_floating_unary_code_count,
    large_integer_scalar_code_count, large_floating_scalar_code_count,
    large_integer_matmul_code_count, large_floating_matmul_code_count
  };
  bool (*const predicates[]) (unsigned int) = {
    integer_matrix_code_p, floating_matrix_code_p, matrix_math_code_p,
    floating_unary_code_p, integer_scalar_code_p, floating_scalar_code_p,
    integer_matmul_code_p, floating_matmul_code_p
  };
  for (unsigned int i = 0; i < ARRAY_SIZE (bases); ++i)
    {
      ASSERT_FALSE (predicates[i] (bases[i] - 1));
      ASSERT_TRUE (predicates[i] (bases[i]));
      ASSERT_TRUE (predicates[i] (bases[i] + counts[i] - 1));
      ASSERT_FALSE (predicates[i] (bases[i] + counts[i]));
      for (unsigned int j = 0; j < ARRAY_SIZE (bases); ++j)
	ASSERT_EQ (predicates[i] (bases[j]), i == j);
    }
  riscv_ztt_profile_string = "gcc-runtime-u8-m16-a16";
  elementwise_formation f = {};
  f.nregs[0] = 32; f.nregs[1] = 8; f.nregs[2] = 16;
  integer_matrix_signature s;
  ASSERT_FALSE (decode_integer_matrix_code (integer_matrix_code (0, f), s));
  ASSERT_FALSE (decode_integer_matrix_code (large_integer_matrix_code_base, s));
  riscv_ztt_profile_string = saved_profile;
}
#endif

static type_index
integer_matrix_carrier (unsigned int group)
{
  unsigned int dtype = (exact_log2 (active_profile ()->uds) - 3) * 8;
  return mixed_matrix_type (dtype, 1U << group, false);
}

static bool
form_integer_matrix (unsigned int op, const type_index *t,
		     elementwise_formation &f, matrix_domain domain = MATRIX_INTEGER)
{
  if (!TARGET_ZTT || !runtime_profile_p ()
      || !matrix_domain_operation_p (op, domain))
    return false;
  const auto &operation = matrix_operation_info (op);
  bool scalar = operation.prototype == PROTO_M_SHIFT_X;
  bool extended = false, any_fp = false;
  for (unsigned int i = 0; i < (scalar ? 2U : 3U); ++i)
    {
      if (t[i] >= TYPE_MAX || !ztt_m_type_nodes[t[i]] || types[t[i]].accumulator)
	return false;
      const auto &v = types[t[i]];
      bool fp = floating_descriptor_p (v.descriptor);
      if (fp && domain == MATRIX_INTEGER)
	return false;
      any_fp |= fp;
      extended |= extended_integer_p (v.descriptor);
      if (i && (v.rows != types[t[0]].rows || v.columns != types[t[0]].columns))
	return false;
    }
  if ((domain == MATRIX_FLOATING && !any_fp)
      || (domain == MATRIX_INTEGER && !extended)
      || (scalar && t[2] != TYPE_MAX))
    return false;
  if (domain == MATRIX_FLOATING
      && (((operation.expansion == EXPAND_MCMPGE_EW
	    || operation.expansion == EXPAND_MCMPLT_EW)
	   && floating_descriptor_p (types[t[0]].descriptor))
	  || (operation.basic && floating_descriptor_p (types[t[2]].descriptor))
	  || (op >= 41 && (t[0] != t[1] || t[0] != t[2]))))
    return false;
  if (domain == MATRIX_MATH
      && (op < 47 ? floating_descriptor_p (types[t[2]].descriptor)
	  : (!floating_descriptor_p (types[t[0]].descriptor)
	     || !floating_descriptor_p (types[t[1]].descriptor))))
    return false;
  unsigned int q = types[t[0]].rows * types[t[0]].columns;
  if ((operation.basic && q != 1)
      || (operation.prototype == PROTO_M_GATHER && t[1] != t[0])
      || (selected_data_p (operation.expansion) && t[2] != t[0])
      || ((operation.expansion == EXPAND_MSRA_EW
	   || operation.expansion == EXPAND_MSRA_EW_X)
	  && !(types[t[1]].descriptor & (1U << 30))))
    return false;
  return form_elementwise (types[t[0]].descriptor & 0xff,
			   types[t[1]].descriptor & 0xff,
			   scalar ? 0 : types[t[2]].descriptor & 0xff,
			   q, active_profile ()->uds, f);
}

static tree
integer_matrix_builtin_decl (unsigned int code)
{
  integer_matrix_signature s;
  if (!TARGET_ZTT || !runtime_profile_p () || !decode_integer_matrix_code (code, s))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  matrix_domain domain = matrix_code_domain (code);
  bool large = code >= large_group_code_base;
  unsigned int slot = code - matrix_domain_base (domain, large);
  if (large)
    slot += domain == MATRIX_MATH ? matrix_math_code_count
      : domain == MATRIX_FLOATING ? floating_matrix_code_count : integer_matrix_code_count;
  tree &decl = domain == MATRIX_MATH ? matrix_math_decls[slot]
    : domain == MATRIX_FLOATING ? floating_matrix_decls[slot] : integer_matrix_decls[slot];
  if (decl)
    return decl;
  tree dst = ztt_m_type_nodes[integer_matrix_carrier (s.dst)];
  tree lhs = ztt_m_type_nodes[integer_matrix_carrier (s.lhs)];
  tree rhs = s.rhs == 6 ? size_type_node
    : ztt_m_type_nodes[integer_matrix_carrier (s.rhs)];
  gcc_assert (dst && lhs && rhs);
  tree ftype = integer_matrix_old_p (s.operation)
    ? build_function_type_list (dst, dst, lhs, rhs, unsigned_type_node,
				unsigned_type_node, unsigned_type_node, NULL_TREE)
    : build_function_type_list (dst, lhs, rhs, unsigned_type_node,
				unsigned_type_node, unsigned_type_node, NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_%s_matrix_%u",
	    matrix_domain_name (domain), code);
  decl = add_builtin_function_ext_scope
    (name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return decl;
}

/* Revalidate metadata from the streamed call, not from registration order.  */
static bool
describe_integer_matrix (unsigned int code, unsigned int nargs, tree *args,
			 builtin_description &d, elementwise_description &e)
{
  integer_matrix_signature s;
  if (!decode_integer_matrix_code (code, s))
    return false;
  unsigned int values = integer_matrix_old_p (s.operation) ? 3 : 2;
  if (nargs != values + 3)
    return false;
  type_index t[3];
  for (unsigned int i = 0; i < 3; ++i)
    {
      if (!tree_fits_uhwi_p (args[values + i]))
	return false;
      unsigned HOST_WIDE_INT value = tree_to_uhwi (args[values + i]);
      if (value != UINT_MAX && value >= TYPE_MAX)
	return false;
      t[i] = value == UINT_MAX ? TYPE_MAX : static_cast<type_index> (value);
    }
  matrix_domain domain = matrix_code_domain (code);
  if (!form_integer_matrix (s.operation, t, e.formation, domain)
      || integer_matrix_code (s.operation, e.formation, domain) != code)
    return false;
  unsigned int groups[] = { s.dst, s.lhs, s.rhs };
  for (unsigned int i = 0; i < values; ++i)
    {
      unsigned int g = groups[i + 3 - values];
      if (args[i] == error_mark_node || TREE_TYPE (args[i]) == error_mark_node)
	return false;
      tree type = TREE_TYPE (args[i]);
      if (g == 6)
	{
	  if (!INTEGRAL_TYPE_P (type) || TYPE_PRECISION (type) != BITS_PER_WORD)
	    return false;
	}
      /* GIMPLE can remove a same-mode view conversion.  Metadata, not the
	 surviving argument type, supplies the arithmetic datatype.  */
      else if (type_for_tree (type) == TYPE_MAX
	       || TYPE_MODE (type) != type_mode (integer_matrix_carrier (g)))
	return false;
    }
  const auto &operation = matrix_operation_info (s.operation);
  d = { "AME/Ztt matrix operation", operation.prototype,
	operation.expansion, t[0] };
  e.canonical = 0;
  e.data = t[1];
  e.count = t[2];
  return true;
}

static tree
resolve_integer_matrix (location_t loc, const builtin_description &d,
			vec<tree, va_gc> *args, matrix_domain domain = MATRIX_INTEGER)
{
  unsigned int op = domain == MATRIX_MATH ? matrix_math_operation (d.expansion)
    : domain == MATRIX_FLOATING ? floating_matrix_operation (d.expansion)
    : wide_operation (d.expansion);
  bool old = integer_matrix_old_p (op);
  unsigned int values = old ? 3 : 2;
  if (args->length () != values)
    return NULL_TREE;
  bool scalar = d.prototype == PROTO_M_SHIFT_X;
  type_index t[] = { d.type, TYPE_MAX, TYPE_MAX };
  for (unsigned int i = 0; i < values; ++i)
    {
      tree arg = (*args)[i];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return error_mark_node;
      if (scalar && i == values - 1)
	{
	  if (!INTEGRAL_TYPE_P (TREE_TYPE (arg)))
	    {
	      error_at (loc, "AME/Ztt scalar shift count must be an integer");
	      return error_mark_node;
	    }
	  continue;
	}
      type_index actual = type_for_tree (TREE_TYPE (arg));
      if (old && i == 0)
	{
	  if (actual != d.type)
	    {
	      error_at (loc, "AME/Ztt %s matrix operation requires old_d "
			"to have the exact result datatype and shape",
			matrix_domain_name (domain));
	      return error_mark_node;
	    }
	}
      else
	t[i + 3 - values] = actual;
    }
  elementwise_formation f;
  if (!form_integer_matrix (op, t, f, domain))
    {
      if (domain == MATRIX_MATH)
	{
	  error_at (loc, "AME/Ztt math matrix operation requires compatible "
			"shapes and complete M groups; exponents must be integer, "
			"logarithm data and results must be floating-point");
	  return error_mark_node;
	}
      if (domain == MATRIX_FLOATING)
	{
	  error_at (loc, "AME/Ztt floating matrix operation requires compatible "
			"types, shapes and complete M groups; comparison results "
			"and indices must be integer, and selected data, old_d "
			"and min/max operands must have the required exact types");
	  return error_mark_node;
	}
      error_at (loc, "AME/Ztt integer matrix operation requires compatible "
		"types, shapes and complete M groups");
      return error_mark_node;
    }
  unsigned int code = integer_matrix_code (op, f, domain);
  tree fn = integer_matrix_builtin_decl (code);
  auto_vec<tree, 6> operands;
  /* Keep one evaluation through gimplification: separate carrier views of
     the same large value otherwise become distinct O0 temporaries.  */
  bool shared = !old && !scalar && f.nregs[1] > 4 && t[1] == t[2]
    && operand_equal_p ((*args)[0], (*args)[1], 0);
  for (unsigned int i = 0; i < values; ++i)
    {
      if (shared && i == 1)
	{
	  operands.safe_push (operands[0]);
	  continue;
	}
      tree arg = (*args)[i];
      unsigned int index = i + 3 - values;
      tree value = index == 2 && scalar ? fold_convert (size_type_node, arg)
	: build1 (VIEW_CONVERT_EXPR,
		  ztt_m_type_nodes[integer_matrix_carrier
		    (exact_log2 (f.nregs[index]))], arg);
      if (shared)
	value = save_expr (value);
      operands.safe_push (value);
    }
  for (type_index type : t)
    operands.safe_push (build_int_cstu (unsigned_type_node,
				       type == TYPE_MAX ? UINT_MAX : type));
  tree call = build_call_expr_loc_array (loc, fn, operands.length (), operands.address ());
  return build1 (VIEW_CONVERT_EXPR, ztt_m_type_nodes[d.type], call);
}

/* Exponent controls are
   signed long, not a TC data scalar and not an amestype conversion.  */
struct exponent_signature
{
  unsigned int op, uds, dst, source;
};

static bool
decode_exponent_code (unsigned int code, exponent_signature &s)
{
  if (!exponent_code_p (code) || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  unsigned int n = code - exponent_code_base;
  s.source = n % 6;
  s.dst = n / 6 % 6;
  s.uds = n / 36 % 5;
  s.op = n / 180;
  return (8U << s.uds) == active_profile ()->uds
    && (1U << s.dst) <= active_profile ()->mregs
    && (1U << s.source) <= active_profile ()->mregs;
}

static unsigned int
exponent_code (bool old, const elementwise_formation &f)
{
  return exponent_code_base
    + ((old * 5 + exact_log2 (active_profile ()->uds) - 3) * 6
	+ exact_log2 (f.nregs[0])) * 6 + exact_log2 (f.nregs[1]);
}

static bool
form_exponent (type_index dst, type_index source, elementwise_formation &f)
{
  if (!TARGET_ZTT || !runtime_profile_p ())
    return false;
  for (type_index t : { dst, source })
    if (t >= TYPE_MAX || !ztt_m_type_nodes[t] || types[t].accumulator)
      return false;
  const auto &d = types[dst];
  const auto &s = types[source];
  return d.rows == s.rows && d.columns == s.columns
    && form_elementwise (d.descriptor & 0xff, s.descriptor & 0xff, 0,
			 d.rows * d.columns, active_profile ()->uds, f);
}

static tree
exponent_builtin_decl (unsigned int code)
{
  exponent_signature s;
  if (!decode_exponent_code (code, s))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  tree &decl = exponent_decls[code - exponent_code_base];
  if (!decl)
    {
      tree dst = ztt_m_type_nodes[integer_matrix_carrier (s.dst)];
      tree src = ztt_m_type_nodes[integer_matrix_carrier (s.source)];
      tree ftype = s.op
	? build_function_type_list (dst, dst, src, long_integer_type_node,
				    unsigned_type_node, unsigned_type_node, NULL_TREE)
	: build_function_type_list (dst, src, long_integer_type_node,
				    unsigned_type_node, unsigned_type_node, NULL_TREE);
      char name[64];
      snprintf (name, sizeof (name), "__builtin_riscv_ztt_exponent_%u", code);
      decl = add_builtin_function_ext_scope
	(name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
	 BUILT_IN_MD, NULL, function_attributes ());
    }
  return decl;
}

static bool
describe_exponent (unsigned int code, unsigned int nargs, tree *args,
		   builtin_description &d, scalar_description &e)
{
  exponent_signature s;
  if (!decode_exponent_code (code, s) || nargs != 4 + s.op)
    return false;
  unsigned int values = 2 + s.op;
  type_index t[2];
  for (unsigned int i = 0; i < 2; ++i)
    {
      if (!tree_fits_uhwi_p (args[values + i]))
	return false;
      unsigned HOST_WIDE_INT n = tree_to_uhwi (args[values + i]);
      if (n >= TYPE_MAX)
	return false;
      t[i] = static_cast<type_index> (n);
    }
  if (!form_exponent (t[0], t[1], e.formation)
      || exponent_code (s.op, e.formation) != code)
    return false;
  for (unsigned int i = 0; i < values; ++i)
    {
      if (args[i] == error_mark_node || TREE_TYPE (args[i]) == error_mark_node)
	return false;
      tree type = TREE_TYPE (args[i]);
      if (i == values - 1)
	{
	  if (!INTEGRAL_TYPE_P (type) || TYPE_UNSIGNED (type)
	      || TYPE_PRECISION (type) != BITS_PER_WORD)
	    return false;
	}
      else if (type_for_tree (type) == TYPE_MAX
	       || TYPE_MODE (type) != type_mode (integer_matrix_carrier
						 (s.op && i == 0 ? s.dst : s.source)))
	return false;
    }
  d = { "AME/Ztt exponent scalar operation",
	s.op ? PROTO_M_EXPONENT_ACC_X : PROTO_M_EXPONENT_X,
	s.op ? EXPAND_MLDEXPACC_EW_X : EXPAND_MLDEXP_EW_X, t[0] };
  e.canonical = 0;
  e.source = t[1];
  e.scalar = TYPE_MAX;
  return true;
}

static tree
resolve_exponent (location_t loc, const builtin_description &d,
		  vec<tree, va_gc> *args)
{
  bool old = d.expansion == EXPAND_MLDEXPACC_EW_X;
  unsigned int values = old ? 3 : 2;
  if (args->length () != values)
    return NULL_TREE;
  for (tree arg : *args)
    if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
      return error_mark_node;
  if (old && type_for_tree (TREE_TYPE ((*args)[0])) != d.type)
    {
      error_at (loc, "AME/Ztt exponent operation requires %<old_d%> to have "
		    "the exact result datatype and shape");
      return error_mark_node;
    }
  tree control = (*args)[values - 1];
  if (!INTEGRAL_TYPE_P (TREE_TYPE (control)))
    {
      error_at (loc, "AME/Ztt exponent control must be an integer convertible "
		    "to %<signed long%>");
      return error_mark_node;
    }
  tree folded_control = fold (control);
  if (TREE_CODE (folded_control) == INTEGER_CST
      ? !int_fits_type_p (folded_control, long_integer_type_node)
      : TYPE_PRECISION (TREE_TYPE (control)) > BITS_PER_WORD)
    {
      error_at (loc, "AME/Ztt exponent control exceeds %<signed long%>; "
		    "use an explicit conversion or a matrix exponent");
      return error_mark_node;
    }
  type_index source = type_for_tree (TREE_TYPE ((*args)[values - 2]));
  elementwise_formation f;
  if (!form_exponent (d.type, source, f))
    {
      error_at (loc, "AME/Ztt exponent operation requires numeric M operands "
		    "with identical shapes and complete groups");
      return error_mark_node;
    }
  auto_vec<tree, 5> operands;
  bool shared = old && d.type == source && f.nregs[0] > 4
    && operand_equal_p ((*args)[0], (*args)[1], 0);
  for (unsigned int i = 0; i < values - 1; ++i)
    {
      if (shared && i == 1)
	{
	  operands.safe_push (operands[0]);
	  continue;
	}
      tree value = build1 (VIEW_CONVERT_EXPR,
	  ztt_m_type_nodes[integer_matrix_carrier
	    (exact_log2 (f.nregs[old && i == 0 ? 0 : 1]))], (*args)[i]);
      operands.safe_push (shared ? save_expr (value) : value);
    }
  operands.safe_push (fold_convert (long_integer_type_node, control));
  for (type_index t : { d.type, source })
    operands.safe_push (build_int_cstu (unsigned_type_node, t));
  tree call = build_call_expr_loc_array
    (loc, exponent_builtin_decl (exponent_code (old, f)),
     operands.length (), operands.address ());
  return build1 (VIEW_CONVERT_EXPR, ztt_m_type_nodes[d.type], call);
}

struct floating_unary_signature
{
  unsigned int op, uds, dst, source;
};

static bool
decode_floating_unary_code (unsigned int code, floating_unary_signature &s)
{
  if (!floating_unary_code_p (code) || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  bool large = code >= large_group_code_base;
  unsigned int radix = large ? 6 : 3;
  unsigned int n = code - (large ? large_floating_unary_code_base : floating_unary_code_base);
  s.source = n % radix;
  n /= radix;
  s.dst = n % radix;
  n /= radix;
  s.uds = n % 5;
  s.op = n / 5;
  return (8U << s.uds) == active_profile ()->uds
    && (1U << s.dst) <= active_profile ()->mregs
    && (1U << s.source) <= active_profile ()->mregs
    && (!large || s.dst >= 3 || s.source >= 3);
}

static unsigned int
floating_unary_code (unsigned int op, const elementwise_formation &f)
{
  bool large = f.nregs[0] > 4 || f.nregs[1] > 4;
  unsigned int radix = large ? 6 : 3;
  return (large ? large_floating_unary_code_base : floating_unary_code_base)
    + ((op * 5 + exact_log2 (active_profile ()->uds) - 3) * radix
	+ exact_log2 (f.nregs[0])) * radix + exact_log2 (f.nregs[1]);
}

static bool
form_floating_unary (unsigned int op, type_index dst, type_index source,
		     elementwise_formation &f)
{
  if (op >= 24 || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  for (type_index t : { dst, source })
    if (t >= TYPE_MAX || !ztt_m_type_nodes[t] || types[t].accumulator)
      return false;
  const auto &d = types[dst];
  const auto &s = types[source];
  bool dfp = floating_descriptor_p (d.descriptor);
  bool sfp = floating_descriptor_p (s.descriptor);
  if ((!dfp && !sfp) || (op >= 12 && (!dfp || !sfp))
      || d.rows != s.rows || d.columns != s.columns)
    return false;
  return form_elementwise (d.descriptor & 0xff, s.descriptor & 0xff, 0,
			   d.rows * d.columns, active_profile ()->uds, f);
}

static tree
floating_unary_builtin_decl (unsigned int code)
{
  floating_unary_signature s;
  if (!decode_floating_unary_code (code, s))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  unsigned int slot = code >= large_group_code_base
    ? floating_unary_code_count + code - large_floating_unary_code_base
    : code - floating_unary_code_base;
  tree &decl = floating_unary_decls[slot];
  if (!decl)
    {
      tree dst = ztt_m_type_nodes[integer_matrix_carrier (s.dst)];
      tree src = ztt_m_type_nodes[integer_matrix_carrier (s.source)];
      tree ftype = build_function_type_list
	(dst, src, unsigned_type_node, unsigned_type_node, NULL_TREE);
      char name[64];
      snprintf (name, sizeof (name), "__builtin_riscv_ztt_floating_unary_%u", code);
      decl = add_builtin_function_ext_scope
	(name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
	 BUILT_IN_MD, NULL, function_attributes ());
    }
  return decl;
}

static bool
describe_floating_unary (unsigned int code, unsigned int nargs, tree *args,
			 builtin_description &d, conversion_description &e)
{
  floating_unary_signature s;
  if (!decode_floating_unary_code (code, s) || nargs != 3)
    return false;
  type_index t[2];
  for (unsigned int i = 0; i < 2; ++i)
    {
      if (!tree_fits_uhwi_p (args[i + 1]))
	return false;
      unsigned HOST_WIDE_INT n = tree_to_uhwi (args[i + 1]);
      if (n >= TYPE_MAX)
	return false;
      t[i] = static_cast<type_index> (n);
    }
  if (!form_floating_unary (s.op, t[0], t[1], e.formation)
      || floating_unary_code (s.op, e.formation) != code
      || args[0] == error_mark_node || TREE_TYPE (args[0]) == error_mark_node)
    return false;
  tree type = TREE_TYPE (args[0]);
  if (type_for_tree (type) == TYPE_MAX
      || TYPE_MODE (type) != type_mode (integer_matrix_carrier (s.source)))
    return false;
  d = { "AME/Ztt floating unary operation", PROTO_M_CONVERT,
	floating_unary_expansion (s.op), t[0] };
  e = { 0, t[1], e.formation };
  return true;
}

static tree
resolve_floating_unary (location_t loc, const builtin_description &d,
			vec<tree, va_gc> *args)
{
  if (args->length () != 1)
    return NULL_TREE;
  tree arg = (*args)[0];
  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
    return error_mark_node;
  type_index source = type_for_tree (TREE_TYPE (arg));
  unsigned int op = floating_unary_operation (d.expansion);
  elementwise_formation f;
  if (!form_floating_unary (op, d.type, source, f))
    {
      error_at (loc, "AME/Ztt floating unary operation requires compatible "
		    "M shapes and complete groups; floating-only operations "
		    "require floating source and result types");
      return error_mark_node;
    }
  unsigned int code = floating_unary_code (op, f);
  tree value = build1 (VIEW_CONVERT_EXPR,
		      ztt_m_type_nodes[integer_matrix_carrier
			(exact_log2 (f.nregs[1]))], arg);
  tree call = build_call_expr_loc
    (loc, floating_unary_builtin_decl (code), 3, value,
     build_int_cstu (unsigned_type_node, d.type),
     build_int_cstu (unsigned_type_node, source));
  return build1 (VIEW_CONVERT_EXPR, ztt_m_type_nodes[d.type], call);
}

struct integer_scalar_signature
{
  unsigned int op, uds, dst, source, carrier;
  bool floating;
};

static bool
decode_integer_scalar_code (unsigned int code, integer_scalar_signature &s)
{
  if (!numeric_scalar_code_p (code) || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  s.floating = floating_scalar_code_p (code);
  bool large = code >= large_group_code_base;
  unsigned int radix = large ? 6 : 3;
  unsigned int base = s.floating ? floating_scalar_code_base : integer_scalar_code_base;
  if (large)
    base = s.floating ? large_floating_scalar_code_base : large_integer_scalar_code_base;
  unsigned int n = code - base;
  s.carrier = n % 10;
  n /= 10;
  s.source = n % radix;
  n /= radix;
  s.dst = n % radix;
  n /= radix;
  s.uds = n % 5;
  s.op = n / 5;
  return (8U << s.uds) == active_profile ()->uds
    && (1U << s.dst) <= active_profile ()->mregs
    && (1U << s.source) <= active_profile ()->mregs
    && (!large || s.dst >= 3 || s.source >= 3);
}

static unsigned int
integer_scalar_code (unsigned int op, const elementwise_formation &f,
		     type_index tc, bool floating = false)
{
  unsigned int d = types[tc].descriptor;
  unsigned int carrier = floating_descriptor_p (d)
    ? 2 * (exact_log2 (MIN (d & 0xff, BITS_PER_WORD)) - 3)
    : mixed_dtype_number (d & ~(1U << 29)) / 4;
  bool large = f.nregs[0] > 4 || f.nregs[1] > 4;
  unsigned int radix = large ? 6 : 3;
  unsigned int base = floating ? floating_scalar_code_base : integer_scalar_code_base;
  if (large)
    base = floating ? large_floating_scalar_code_base : large_integer_scalar_code_base;
  return base
    + ((((op * 5 + exact_log2 (active_profile ()->uds) - 3) * radix
	 + exact_log2 (f.nregs[0])) * radix + exact_log2 (f.nregs[1])) * 10
       + carrier);
}

static bool
form_integer_scalar (unsigned int op, const type_index t[3],
		     elementwise_formation &f, bool floating = false)
{
  if (op >= (floating ? floating_scalar_operations : integer_scalar_operations)
      || !TARGET_ZTT || !runtime_profile_p ())
    return false;
  bool have_fp = false;
  for (unsigned int i = 0; i < 3; ++i)
    {
      if (t[i] == TYPE_MAX || types[t[i]].accumulator)
	return false;
      bool fp = floating_descriptor_p (types[t[i]].descriptor);
      if (fp && !floating)
	return false;
      have_fp |= fp;
      if (i < 2 && !ztt_m_type_nodes[t[i]])
	return false;
    }
  /* Nominal public Scalars also use this carrier path for narrow non-SAT
     types; their frontend identity is checked before unwrapping.  */
  if ((floating && !have_fp) || (types[t[2]].descriptor & 0xff) == 4
      || types[t[2]].rows != 1 || types[t[2]].columns != 1
      || types[t[0]].rows != types[t[1]].rows
      || types[t[0]].columns != types[t[1]].columns)
    return false;
  expansion_index expansion = numeric_scalar_operation (op).expansion;
  bool dfp = floating_descriptor_p (types[t[0]].descriptor);
  bool sfp = floating_descriptor_p (types[t[1]].descriptor);
  if ((scalar_bitwise_p (expansion) && (dfp || sfp))
      || ((expansion == EXPAND_MCMPGE_EW_X || expansion == EXPAND_MCMPLT_EW_X) && dfp)
      || (op >= 20 && (!dfp || !sfp)))
    return false;
  if ((expansion == EXPAND_MMIN_EW_X || expansion == EXPAND_MMAX_EW_X
       || scalar_bitwise_p (expansion)) && t[0] != t[1])
    return false;
  return form_elementwise (types[t[0]].descriptor & 0xff,
			   types[t[1]].descriptor & 0xff, 0,
			   types[t[0]].rows * types[t[0]].columns,
			   active_profile ()->uds, f);
}

static tree
integer_scalar_builtin_decl (unsigned int code)
{
  integer_scalar_signature s;
  if (!decode_integer_scalar_code (code, s))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  bool large = code >= large_group_code_base;
  unsigned int base = s.floating ? floating_scalar_code_base : integer_scalar_code_base;
  if (large)
    base = s.floating ? large_floating_scalar_code_base : large_integer_scalar_code_base;
  unsigned int slot = code - base;
  if (large)
    slot += s.floating ? floating_scalar_code_count : integer_scalar_code_count;
  tree &decl = s.floating ? floating_scalar_decls[slot] : integer_scalar_decls[slot];
  if (decl)
    return decl;
  tree dst = ztt_m_type_nodes[integer_matrix_carrier (s.dst)];
  tree src = ztt_m_type_nodes[integer_matrix_carrier (s.source)];
  tree carrier = scalar_carrier_type (integer_matrix_type (s.carrier * 4, 1, false));
  tree ftype = integer_scalar_old_p (s.op)
    ? build_function_type_list (dst, dst, src, carrier, unsigned_type_node,
				unsigned_type_node, unsigned_type_node, NULL_TREE)
    : build_function_type_list (dst, src, carrier, unsigned_type_node,
				unsigned_type_node, unsigned_type_node, NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_%s_scalar_%u",
	    s.floating ? "floating" : "integer", code);
  decl = add_builtin_function_ext_scope
    (name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return decl;
}

static bool
describe_integer_scalar (unsigned int code, unsigned int nargs, tree *args,
			 builtin_description &d, scalar_description &e)
{
  integer_scalar_signature s;
  if (!decode_integer_scalar_code (code, s))
    return false;
  unsigned int values = integer_scalar_old_p (s.op) ? 3 : 2;
  if (nargs != values + 3)
    return false;
  type_index t[3];
  for (unsigned int i = 0; i < 3; ++i)
    {
      if (!tree_fits_uhwi_p (args[values + i]))
	return false;
      unsigned HOST_WIDE_INT n = tree_to_uhwi (args[values + i]);
      if (n >= TYPE_MAX)
	return false;
      t[i] = static_cast<type_index> (n);
    }
  if (!form_integer_scalar (s.op, t, e.formation, s.floating)
      || integer_scalar_code (s.op, e.formation, t[2], s.floating) != code)
    return false;
  for (unsigned int i = 0; i < values; ++i)
    {
      if (args[i] == error_mark_node || TREE_TYPE (args[i]) == error_mark_node)
	return false;
      tree type = TREE_TYPE (args[i]);
      if (i == values - 1)
	{
	  tree carrier = scalar_carrier_type (t[2]);
	  if (!INTEGRAL_TYPE_P (type) || TYPE_MODE (type) != TYPE_MODE (carrier)
	      || TYPE_UNSIGNED (type) != TYPE_UNSIGNED (carrier))
	    return false;
	}
      else
	{
	  unsigned int group = (values == 3 && i == 0) ? s.dst : s.source;
	  if (type_for_tree (type) == TYPE_MAX
	      || TYPE_MODE (type) != type_mode (integer_matrix_carrier (group)))
	    return false;
	}
    }
  const auto &operation = numeric_scalar_operation (s.op);
  d = { "AME/Ztt numeric scalar operation", operation.prototype,
	operation.expansion, t[0] };
  e = { 0, t[1], t[2], e.formation };
  return true;
}

struct integer_matmul_signature
{
  unsigned int variant, uds, acc_group, dtype, lhs, rhs;
  type_index dst;
  bool floating;
};

static bool
decode_integer_matmul_code (unsigned int code, integer_matmul_signature &s)
{
  s.floating = floating_matmul_code_p (code);
  if (!s.floating && !integer_matmul_code_p (code))
    return false;
  bool large = code >= large_group_code_base;
  unsigned int radix = large ? 6 : 3;
  unsigned int base = s.floating ? floating_matmul_code_base : integer_matmul_code_base;
  if (large)
    base = s.floating ? large_floating_matmul_code_base : large_integer_matmul_code_base;
  unsigned int n = code - base;
  unsigned int count = s.floating ? numeric_dtype_count : integer_dtype_count;
  s.rhs = n % radix;
  n /= radix;
  s.lhs = n % radix;
  n /= radix;
  s.dtype = n % count;
  n /= count;
  s.acc_group = n % 5;
  n /= 5;
  s.uds = 8U << (n % 5);
  s.variant = n / 5;
  s.dst = numeric_matrix_type (s.dtype, s.acc_group, true);
  return TARGET_ZTT && acc_profile_p () && active_profile ()->uds == s.uds
    && (1U << s.lhs) <= active_profile ()->mregs
    && (1U << s.rhs) <= active_profile ()->mregs
    && (!large || s.lhs >= 3 || s.rhs >= 3)
    && s.dst != TYPE_MAX && ztt_m_type_nodes[s.dst];
}

static unsigned int
integer_matmul_code (unsigned int variant, type_index dst,
		     const matmul_formation &f, bool floating = false)
{
  const auto &t = types[dst];
  unsigned int base = floating ? floating_matmul_code_base
    : integer_matmul_code_base;
  bool large = f.lhs_nregs > 4 || f.rhs_nregs > 4;
  unsigned int radix = large ? 6 : 3;
  if (large)
    base = floating ? large_floating_matmul_code_base : large_integer_matmul_code_base;
  unsigned int count = floating ? numeric_dtype_count : integer_dtype_count;
  return base
    + ((((variant * 5 + exact_log2 (active_profile ()->uds) - 3) * 5
	 + exact_log2 (t.columns)) * count
	+ numeric_dtype_number (t.descriptor)) * radix
       + exact_log2 (f.lhs_nregs)) * radix + exact_log2 (f.rhs_nregs);
}

static expansion_index
integer_matmul_expansion (unsigned int variant)
{
  static constexpr expansion_index variants[] = {
    EXPAND_A_MMUL, EXPAND_A_MMULNEG, EXPAND_A_MMULAT,
    EXPAND_A_MMULATNEG, EXPAND_A_MMULBT, EXPAND_A_MMULBTNEG
  };
  gcc_assert (variant < ARRAY_SIZE (variants));
  return variants[variant];
}

static bool
form_integer_matmul (const builtin_description &d, type_index lhs,
		     type_index rhs, prototype_index &prototype,
		     matmul_formation &f, bool floating = false)
{
  if (!TARGET_ZTT || !acc_profile_p () || !ztt_m_type_nodes[d.type]
      || !types[d.type].accumulator || matmul_variant (d.expansion) < 0)
    return false;
  bool extended = extended_integer_p (types[d.type].descriptor);
  bool any_fp = floating_descriptor_p (types[d.type].descriptor);
  for (type_index t : { lhs, rhs })
    {
      if (t >= TYPE_MAX || !ztt_m_type_nodes[t] || types[t].accumulator)
	return false;
      extended |= extended_integer_p (types[t].descriptor);
      any_fp |= floating_descriptor_p (types[t].descriptor);
    }
  if (floating ? !any_fp : (any_fp || !extended))
    return false;
  for (unsigned int shape = 0; shape < matmul_shape_count; ++shape)
    {
      if (!matmul_shape_allowed_p (shape, d.expansion))
	continue;
      prototype_index p = matmul_prototype (shape);
      const auto &s = *matmul_shape (p);
      const auto &a = types[lhs];
      const auto &b = types[rhs];
      if (a.rows != (s.lhs_column ? s.squares : 1)
	  || a.columns != (s.lhs_column ? 1 : s.squares)
	  || b.rows != (s.rhs_column ? s.squares : 1)
	  || b.columns != (s.rhs_column ? 1 : s.squares))
	continue;
      prototype = p;
      return form_matmul (a.descriptor & 0xff, b.descriptor & 0xff,
			  s.squares, active_profile ()->uds, f);
    }
  return false;
}

static tree
integer_matmul_builtin_decl (unsigned int code)
{
  integer_matmul_signature s;
  if (!decode_integer_matmul_code (code, s))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  if (tree decl = integer_matmul_decls.get (code))
    return decl;
  tree dst = ztt_m_type_nodes[s.dst];
  tree lhs = ztt_m_type_nodes[integer_matrix_carrier (s.lhs)];
  tree rhs = ztt_m_type_nodes[integer_matrix_carrier (s.rhs)];
  gcc_assert (dst && lhs && rhs);
  tree ftype = build_function_type_list
    (dst, dst, lhs, rhs, unsigned_type_node, unsigned_type_node, NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_%s_matmul_%u",
	    s.floating ? "floating" : "integer", code);
  tree decl = add_builtin_function_ext_scope
    (name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return integer_matmul_decls.put (code, decl);
}

static bool
describe_integer_matmul (unsigned int code, unsigned int nargs, tree *args,
			 builtin_description &d, type_index &lhs,
			 type_index &rhs)
{
  integer_matmul_signature s;
  if (nargs != 5 || !decode_integer_matmul_code (code, s))
    return false;
  type_index t[2];
  for (unsigned int i = 0; i < 2; ++i)
    {
      if (!tree_fits_uhwi_p (args[3 + i])
	  || tree_to_uhwi (args[3 + i]) >= TYPE_MAX)
	return false;
      t[i] = static_cast<type_index> (tree_to_uhwi (args[3 + i]));
    }
  d = { s.floating ? "AME/Ztt floating matmul" : "AME/Ztt integer matmul",
	PROTO_A_A_M_M,
	integer_matmul_expansion (s.variant), s.dst };
  matmul_formation f;
  if (!form_integer_matmul (d, t[0], t[1], d.prototype, f, s.floating)
      || integer_matmul_code (s.variant, d.type, f, s.floating) != code)
    return false;
  for (unsigned int i = 0; i < 3; ++i)
    {
      if (args[i] == error_mark_node || TREE_TYPE (args[i]) == error_mark_node)
	return false;
      tree type = TREE_TYPE (args[i]);
      /* GIMPLE may remove a same-mode M view.  ACC never uses a carrier.  */
      if (i == 0 ? type_for_tree (type) != d.type
	  : type_for_tree (type) == TYPE_MAX
	    || TYPE_MODE (type) != type_mode (t[i - 1]))
	return false;
    }
  lhs = t[0];
  rhs = t[1];
  return true;
}

static tree
resolve_integer_matmul (location_t loc, const builtin_description &d,
			vec<tree, va_gc> *args, bool floating = false)
{
  if (args->length () != 3)
    return NULL_TREE;
  type_index t[3];
  for (unsigned int i = 0; i < 3; ++i)
    {
      tree arg = (*args)[i];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return error_mark_node;
      t[i] = type_for_tree (TREE_TYPE (arg));
    }
  if (t[0] != d.type)
    {
      error_at (loc, "AME/Ztt %s matmul requires old_acc to have "
		"the exact result datatype and shape",
		floating ? "floating" : "integer");
      return error_mark_node;
    }
  matmul_formation f;
  prototype_index prototype;
  if (!form_integer_matmul (d, t[1], t[2], prototype, f, floating))
    {
      error_at (loc, "AME/Ztt %s matmul requires compatible orientations, "
		"equal source Squares and complete M/ACC groups",
		floating ? "floating" : "integer");
      return error_mark_node;
    }
  tree fn = integer_matmul_builtin_decl
    (integer_matmul_code (matmul_variant (d.expansion), d.type, f, floating));
  tree operands[] = {
    (*args)[0],
    build1 (VIEW_CONVERT_EXPR,
	    ztt_m_type_nodes[integer_matrix_carrier (exact_log2 (f.lhs_nregs))],
	    (*args)[1]),
    build1 (VIEW_CONVERT_EXPR,
	    ztt_m_type_nodes[integer_matrix_carrier (exact_log2 (f.rhs_nregs))],
	    (*args)[2]),
    build_int_cstu (unsigned_type_node, t[1]),
    build_int_cstu (unsigned_type_node, t[2])
  };
  return build_call_expr_loc_array (loc, fn, ARRAY_SIZE (operands), operands);
}

static bool
decode_conversion_builtin (unsigned int code, conversion_description &result)
{
  bool integer = integer_unary_code_p (code);
  bool wide = wide_code_p (code);
  if ((!integer && !wide
       && (code < conversion_code_base || code >= elementwise_code_base))
      || !TARGET_ZTT || !typed_profile_p ())
    return false;
  unsigned int source, count;
  if (integer)
    {
      if (!decode_integer_unary_builtin (code, result.canonical, source))
	return false;
    }
  else if (wide)
    {
      if (!decode_wide_builtin (code, result.canonical, source, count))
	return false;
    }
  else
    {
      unsigned int payload = code - conversion_code_base;
      result.canonical = payload / 24;
      source = payload % 24;
    }
  if (result.canonical >= ZTT_BUILTIN_MAX)
    return false;
  const auto &d = builtin_description_for (result.canonical);
  if ((d.prototype != PROTO_M_CONVERT && d.prototype != PROTO_M_STRUCTURAL
       && d.prototype != PROTO_M_ABS)
      || !ztt_m_type_nodes[d.type]
      || floating_descriptor_p (types[d.type].descriptor))
    return false;
  const auto &dst = types[d.type];
  unsigned int q = dst.rows * dst.columns;
  result.source = integer ? integer_matrix_type (source, q, dst.rows > 1)
    : mixed_matrix_type (source, q, dst.rows > 1);
  if (result.source == TYPE_MAX || !ztt_m_type_nodes[result.source])
    return false;
  return form_elementwise (dst.descriptor & 0xff,
			   types[result.source].descriptor & 0xff, 0, q,
			   active_profile ()->uds, result.formation);
}

static tree
conversion_builtin_decl (unsigned int code, bool initialize_p)
{
  conversion_description d;
  if (!decode_conversion_builtin (code, d))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  if (tree decl = conversion_builtin_decls.get (code))
    return decl;
  if (!initialize_p)
    return error_mark_node;
  tree ftype = build_function_type_list
    (ztt_m_type_nodes[builtin_description_for (d.canonical).type],
     ztt_m_type_nodes[d.source], NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_%s_%u",
	    builtin_description_for (d.canonical).prototype == PROTO_M_ABS
	    ? "abs"
	    : builtin_description_for (d.canonical).prototype == PROTO_M_STRUCTURAL
	    ? "structural" : "convert", code);
  tree decl = add_builtin_function_ext_scope
    (name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return conversion_builtin_decls.put (code, decl);
}

static bool
decode_scalar_builtin (unsigned int code, scalar_description &result)
{
  bool wide = wide_code_p (code);
  if ((!wide && (code < scalar_code_base || code >= conversion_code_base))
      || !TARGET_ZTT || !typed_profile_p ())
    return false;
  unsigned int source, scalar;
  if (wide)
    {
      if (!wide_scalar_p (code)
	  || !decode_wide_builtin (code, result.canonical, source, scalar))
	return false;
    }
  else
    {
      unsigned int payload = code - scalar_code_base;
      result.canonical = payload / 24;
      source = payload % 24;
    }
  if (result.canonical >= ZTT_BUILTIN_MAX)
    return false;
  const auto &d = builtin_description_for (result.canonical);
  bool ternary = scalar_ternary_variant (d.expansion) >= 0;
  if ((!ternary && scalar_arithmetic_variant (d.expansion) < 0)
      || !scalar_prototype_p (d.prototype, ternary)
      || !ztt_m_type_nodes[d.type])
    return false;
  const auto &dst = types[d.type];
  unsigned int q = dst.rows * dst.columns;
  result.source = mixed_matrix_type (source, q, dst.rows > 1);
  result.scalar = wide ? mixed_matrix_type (scalar, 1, false)
    : scalar_source_type (d.prototype);
  if (result.scalar == TYPE_MAX)
    return false;
  if (result.source == TYPE_MAX || !ztt_m_type_nodes[result.source]
      || ((d.expansion == EXPAND_MMIN_EW_X || d.expansion == EXPAND_MMAX_EW_X
	   || scalar_bitwise_p (d.expansion))
	  && result.source != d.type))
    return false;
  return form_elementwise (dst.descriptor & 0xff,
			   types[result.source].descriptor & 0xff, 0, q,
			   active_profile ()->uds, result.formation);
}

static tree
scalar_builtin_decl (unsigned int code, bool initialize_p)
{
  scalar_description d;
  if (!decode_scalar_builtin (code, d))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  if (tree decl = scalar_builtin_decls.get (code))
    return decl;
  if (!initialize_p)
    return error_mark_node;
  const auto &canonical = builtin_description_for (d.canonical);
  bool ternary = scalar_ternary_variant (canonical.expansion) >= 0;
  tree dst = ztt_m_type_nodes[canonical.type];
  tree ftype = ternary
    ? build_function_type_list (dst, dst, ztt_m_type_nodes[d.source],
				scalar_carrier_type (d.scalar), NULL_TREE)
    : build_function_type_list (dst, ztt_m_type_nodes[d.source],
				scalar_carrier_type (d.scalar), NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_scalar_%s%u",
	    ternary ? "ternary_" : "", code);
  tree decl = add_builtin_function_ext_scope
    (name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return scalar_builtin_decls.put (code, decl);
}

static tree
elementwise_builtin_decl (unsigned int code, bool initialize_p)
{
  elementwise_description d;
  if (!decode_elementwise_builtin (code, d))
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  if (tree decl = elementwise_builtin_decls.get (code))
    return decl;
  if (!initialize_p)
    return error_mark_node;
  const auto &canonical = builtin_description_for (d.canonical);
  tree dst = ztt_m_type_nodes[canonical.type];
  tree data = ztt_m_type_nodes[d.data];
  tree count = d.count == TYPE_MAX ? size_type_node : ztt_m_type_nodes[d.count];
  tree ftype = (canonical.prototype == PROTO_M_SCATTER
		|| canonical.prototype == PROTO_M_TERNARY_M)
    ? build_function_type_list (dst, dst, data, count, NULL_TREE)
    : build_function_type_list (dst, data, count, NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_%s_%u",
	    canonical.prototype == PROTO_M_SCATTER ? "scatter"
	    : canonical.prototype == PROTO_M_TERNARY_M ? "ternary"
	    : canonical.prototype == PROTO_M_GATHER ? "gather"
	    : arithmetic_variant (canonical.expansion) >= 0 ? "binary" : "shift",
	    code);
  tree decl = add_builtin_function_ext_scope
    (name, ftype, (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return elementwise_builtin_decls.put (code, decl);
}

static unsigned int
encode_mixed_builtin (unsigned int canonical, unsigned int shape,
		      unsigned int lhs, unsigned int rhs)
{
  const auto &d = builtin_description_for (canonical);
  const auto &t = types[d.type];
  if ((t.descriptor & 0xff) > 32 || (lhs & 0xff) > 32 || (rhs & 0xff) > 32)
    {
      wide_matmul_signature s = {
	static_cast<unsigned int> (matmul_variant (d.expansion)),
	static_cast<unsigned int> (exact_log2 (t.columns)), shape,
	mixed_dtype_number (t.descriptor), mixed_dtype_number (lhs),
	mixed_dtype_number (rhs)
      };
      return encode_wide_matmul_signature (s);
    }
  unsigned int uds = active_profile ()->uds;
  bool packed_p = shape >= mixed_shape_count || (lhs & 0xff) < uds
    || (rhs & 0xff) < uds
    || (types[builtin_description_for (canonical).type].descriptor & 0xff) < uds;
  bool q32_p = shape >= packed_shape_count;
  unsigned int radix = q32_p ? q32_shape_count
    : packed_p ? packed_shape_count : mixed_shape_count;
  unsigned int base = q32_p ? q32_code_base
    : packed_p ? packed_code_base : mixed_code_base;
  if (q32_p)
    shape -= packed_shape_count;
  return base
    + ((canonical * radix + shape) * mixed_dtype_count
       + mixed_dtype_number (lhs)) * mixed_dtype_count
    + mixed_dtype_number (rhs);
}

static tree
mixed_builtin_decl (unsigned int code, bool initialize_p)
{
  mixed_description d;
  if (!decode_mixed_builtin (code, d))
    return error_mark_node;
  /* Like RVV, LTO streams the actual declaration by value; the target hook
     only validates its deterministic code and active profile.  */
  if (in_lto_p)
    return integer_zero_node;
  if (tree decl = mixed_builtin_decls.get (code))
    return decl;
  if (!initialize_p)
    return error_mark_node;
  tree result = ztt_m_type_nodes[builtin_description_for (d.canonical).type];
  tree ftype = build_function_type_list
    (result, result, ztt_m_type_nodes[d.lhs], ztt_m_type_nodes[d.rhs], NULL_TREE);
  char name[64];
  snprintf (name, sizeof (name), "__builtin_riscv_ztt_mixed_%u", code);
  /* Resolution can occur inside a C++ function or template.  Unlike header
     registration, a lazy builtin must enter the external scope.  */
  tree decl = add_builtin_function_ext_scope
    (name, ftype,
     (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT,
     BUILT_IN_MD, NULL, function_attributes ());
  return mixed_builtin_decls.put (code, decl);
}

/* Build the default spelling from an eligible public catalog entry.  The
   descriptor and prototype, rather than the spelling alone, decide RM.  */
static bool
default_builtin_alias (const builtin_description &d, const char *canonical_name,
		       char (&name)[160])
{
  unsigned int desc = types[d.type].descriptor;
  if (!startswith (canonical_name, "__riscv_ztt_")
      || !default_scalar_rm_p (desc))
    return false;
  if (broadcast_prototype_p (d.prototype)
      && !default_scalar_rm_p
	    (types[broadcast_source_type (d.prototype)].descriptor))
    return false;
  if ((scalar_prototype_p (d.prototype, false)
       || scalar_prototype_p (d.prototype, true))
      && !default_scalar_rm_p
	    (types[scalar_source_type (d.prototype)].descriptor))
    return false;

  /* The original small, nonsaturating integer stores use the overloaded
     store spelling.  Do not add new typed short names for those entries.  */
  if ((d.prototype == PROTO_VOID_PTR_M
       || d.prototype == PROTO_VOID_PTR_STRIDE_M)
      && !floating_descriptor_p (desc) && (desc & 0xff) <= 32
      && !(desc & (1U << 29)))
    return false;

  gcc_assert (strlen (canonical_name) < sizeof (name));
  char *out = name;
  bool changed = false;
  for (const char *in = canonical_name; *in;)
    if ((strncmp (in, "_rnu", 4) == 0 || strncmp (in, "_rne", 4) == 0)
	&& (in[4] == '_' || in[4] == '\0'))
      {
	in += 4;
	changed = true;
      }
    else
      *out++ = *in++;
  *out = '\0';
  return changed;
}

static void
register_functions ()
{
  if (functions_registered_p)
    return;

  /* These compiler-owned declarations have no source bodies to optimize.
     Replaying the current optimize pragma for every catalog entry creates
     a large amount of temporary option state.  Keep the current option
     nodes and restore the pragma before parsing any further user code.  */
  tree saved_optimize_pragma = current_optimize_pragma;
  current_optimize_pragma = NULL_TREE;
  register_builtin_type ();
  register_storage128_types ();
  if (!in_lto_p)
    {
      register_nominal_scalars ();
      vec_safe_grow_cleared (nominal_registration_types,
			    TYPE_MAX * numeric_scalar_dtype_count * 3, true);
      vec_safe_grow_cleared (registration_function_types,
			    TYPE_MAX * PROTO_MAX, true);
    }
  for (unsigned int i = 0; i < ZTT_BUILTIN_MAX; ++i)
    {
      const builtin_description &d = builtin_description_for (i);
      if (exponent_p (d.expansion) && !runtime_profile_p ())
	continue;
      type_index type = d.type;
      if (!ztt_m_type_nodes[type])
	{
	  /* The overloaded store's stable dispatch code is not itself an
	     i8_1x1 availability promise.  Give it a legal anchor prototype.  */
	  if (!store_dispatch_p (i))
	    continue;
	  for (unsigned int j = 0; j < TYPE_MAX; ++j)
	    if (ztt_m_type_nodes[j] && !types[j].accumulator)
	      {
		type = static_cast<type_index> (j);
		break;
	      }
	}
      prototype_index prototype = d.prototype;
      if (zip_variant (d.expansion) >= 0 && prototype == PROTO_M_M
	  && (!runtime_profile_p ()
	      || (types[type].descriptor & 0xff) < active_profile ()->uds))
	continue;
      if (prototype == PROTO_A_M || prototype == PROTO_A_M_COLUMN
	  || prototype == PROTO_M_A || prototype == PROTO_M_A_COLUMN)
	{
	  bool column = prototype == PROTO_A_M_COLUMN
	    || prototype == PROTO_M_A_COLUMN;
	  if (!acc_matrix_type (type, column ? types[type].columns : 1,
				column ? 1 : types[type].columns))
	    continue;
	}
      if (const auto *shape = matmul_shape (prototype))
	{
	  unsigned int bits = types[type].descriptor & 0xff;
	  if (prototype == PROTO_A_A_M_M && bits < active_profile ()->uds)
	    {
	      /* A packed output need not have a same-type 1x1 M type.
		 This is a legal dispatch anchor, not a fixed operand shape.  */
	      unsigned int q = active_profile ()->uds / bits;
	      unsigned int anchor = 1 + 3 * (exact_log2 (q) - 1)
		+ (matmul_variant (d.expansion) >= 2 ? 1 : 0);
	      prototype = matmul_prototype (anchor);
	    }
	  else if (bits < active_profile ()->uds
		   || !m_shape_nregs (bits, shape->squares, active_profile ()->uds,
				      active_profile ()->mregs))
	    continue;
	}
      if (d.expansion == EXPAND_MCONCAT || d.expansion == EXPAND_MEXTRACT)
	{
	  type_index src = m_utility_source_type (d.prototype, type);
	  if (!runtime_profile_p () || src == TYPE_MAX || !ztt_m_type_nodes[src])
	    continue;
	}
      unsigned int code = (i << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT;
      char name[160];
      const char *canonical_name = in_lto_p ? nullptr
	: canonical_builtin_name (d, name);
      builtin_decls[i] = (in_lto_p
	? integer_zero_node
	: simulate_builtin_function_decl (input_location, canonical_name,
					  registration_function_type (prototype, type),
					  code, NULL, function_attributes ()));
      char alias[160];
      if (!in_lto_p && default_builtin_alias (d, canonical_name, alias))
	simulate_builtin_function_decl (input_location, alias,
					TREE_TYPE (builtin_decls[i]), code,
					NULL, function_attributes ());
    }
  if (runtime_profile_p () && !in_lto_p)
    {
      auto_vec<scalar_registration_group> integer_candidates, floating_candidates;
      collect_scalar_registration_groups (integer_candidates, false);
      collect_scalar_registration_groups (floating_candidates, true);
      type_index scalar_types[numeric_scalar_dtype_count];
      for (unsigned int c = 0; c < numeric_scalar_dtype_count; ++c)
	scalar_types[c] = nominal_scalar_type_index (c);
      for (const auto &candidate : integer_candidates)
	for (unsigned int c = candidate.first_tc;
	     c < integer_scalar_dtype_count; ++c)
	  integer_broadcast_builtin_decl
	    (integer_broadcast_code_base + candidate.payload + c, true,
	     candidate.dst, scalar_types[c]);
      for (unsigned int op = 0; op < integer_scalar_operations; ++op)
	for (const auto &candidate : integer_candidates)
	  for (unsigned int c = candidate.first_tc;
	       c < integer_scalar_dtype_count; ++c)
	    integer_scalar_public_decl (integer_scalar_public_base
					+ op * integer_broadcast_code_count
					+ candidate.payload + c, true, op,
					candidate.dst, scalar_types[c]);
      for (unsigned int op = 0; op < floating_scalar_operations; ++op)
	for (const auto &candidate : floating_candidates)
	  if (floating_scalar_operation_p
		(op, floating_descriptor_p (types[candidate.dst].descriptor)))
	    for (unsigned int c = candidate.first_tc;
		 c < numeric_scalar_dtype_count; ++c)
	      floating_scalar_public_decl (floating_scalar_public_base
					   + op * floating_broadcast_code_count
					   + candidate.payload + c, true, op,
					   candidate.dst, scalar_types[c]);
      for (const auto &candidate : floating_candidates)
	for (unsigned int c = candidate.first_tc;
	     c < numeric_scalar_dtype_count; ++c)
	  floating_broadcast_builtin_decl
	    (floating_broadcast_code_base + candidate.payload + c, true,
	     candidate.dst, scalar_types[c]);
    }
  vec_free (registration_function_types);
  vec_free (nominal_registration_types);
  current_optimize_pragma = saved_optimize_pragma;
  functions_registered_p = true;
}

void
init_builtins ()
{
  if (!TARGET_ZTT || !typed_profile_p ())
    return;

  register_builtin_type ();
  if (in_lto_p)
    register_functions ();
}

void
handle_pragma_ztt ()
{
  if (!TARGET_ZTT)
    {
      error ("%<#pragma riscv intrinsic \"ztt\"%> requires the "
	     "%<ztt0p6%> ISA extension");
      return;
    }
  if (!typed_profile_p ())
    {
      error ("%<#pragma riscv intrinsic \"ztt\"%> requires "
	     "%<-mztt-profile=gcc-p0-n128-u8-m16-a4%> or "
	     "a supported %<-mztt-profile=gcc-runtime-uU-mM-aA%>");
      return;
    }
  if (functions_registered_p)
    {
      error ("duplicate definition of %qs", "riscv_ztt.h");
      return;
    }
  register_functions ();
}

tree
builtin_decl (unsigned int code, bool initialize_p)
{
  if (nominal_scalar_code_p (code))
    return nominal_builtin_decl (code, initialize_p);
  if (exponent_code_p (code))
    return exponent_builtin_decl (code);
  if (floating_broadcast_code_p (code))
    return floating_broadcast_builtin_decl (code, initialize_p);
  if (floating_scalar_public_p (code))
    return floating_scalar_public_decl (code, initialize_p);
  if (floating_unary_code_p (code))
    return floating_unary_builtin_decl (code);
  if (integer_scalar_public_p (code))
    return integer_scalar_public_decl (code, initialize_p);
  if (numeric_scalar_code_p (code))
    return integer_scalar_builtin_decl (code);
  if (integer_broadcast_code_p (code))
    return integer_broadcast_builtin_decl (code, initialize_p);
  if (integer_matmul_code_p (code) || floating_matmul_code_p (code))
    return integer_matmul_builtin_decl (code);
  if (matrix_builtin_code_p (code))
    return integer_matrix_builtin_decl (code);
  if (integer_unary_code_p (code))
    return conversion_builtin_decl (code, initialize_p);
  if (wide_matmul_code_p (code))
    return mixed_builtin_decl (code, initialize_p);
  if (wide_code_p (code))
    return wide_scalar_p (code) ? scalar_builtin_decl (code, initialize_p)
      : wide_unary_p (code) ? conversion_builtin_decl (code, initialize_p)
      : elementwise_builtin_decl (code, initialize_p);
  if (code >= mixed_code_base)
    return mixed_builtin_decl (code, initialize_p);
  if (code >= elementwise_code_base)
    return elementwise_builtin_decl (code, initialize_p);
  if (code >= conversion_code_base)
    return conversion_builtin_decl (code, initialize_p);
  if (code >= scalar_code_base)
    return scalar_builtin_decl (code, initialize_p);
  if (code >= ZTT_BUILTIN_MAX)
    return error_mark_node;
  if (builtin_decls[code] == NULL_TREE && initialize_p
      && TARGET_ZTT && typed_profile_p ())
    register_functions ();
  return builtin_decls[code] ? builtin_decls[code] : error_mark_node;
}

/* Reject lossy implicit entry into the XLEN-bit carrier.  A caller can
   explicitly construct that bit pattern; it is not a full wide C value.  */
static bool
check_scalar_carrier (location_t loc, tree arg, type_index scalar)
{
  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
    return false;
  if ((types[scalar].descriptor & 0xff) > BITS_PER_WORD
      && TYPE_PRECISION (TREE_TYPE (arg)) > BITS_PER_WORD)
    {
      error_at (loc, "AME/Ztt scalar datatype wider than XLEN requires an "
		"XLEN-bit carrier; use an explicit cast or a matrix operand");
      return false;
    }
  return true;
}

/* Check the public carrier
   before ordinary argument conversions can change its bit pattern.  */
static bool
check_broadcast_carrier (location_t loc, tree arg, type_index tc)
{
  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
    return false;
  tree actual = TREE_TYPE (arg), expected = scalar_public_carrier_type (tc);
  if (TREE_CODE (expected) == REAL_TYPE)
    {
      if (TREE_CODE (actual) != REAL_TYPE
	  || TYPE_MODE (actual) != TYPE_MODE (expected))
	{
	  error_at (loc, "AME/Ztt floating scalar requires the exact C floating format");
	  return false;
	}
    }
  else if (!INTEGRAL_TYPE_P (actual))
    {
      error_at (loc, "AME/Ztt broadcast requires an integer scalar");
      return false;
    }
  return check_scalar_carrier (loc, arg, tc);
}

/* Resolve C/C++ overloaded operations before ordinary argument conversion.
   Explicit type instances stay distinct even though their RTL mode is shared.  */
static tree
resolve_integer_scalar (location_t loc, unsigned int op, type_index dst,
			type_index tc, vec<tree, va_gc> *args,
			bool raw_bits = false)
{
  bool old = integer_scalar_old_p (op);
  unsigned int values = old ? 3 : 2;
  if (args->length () != values)
    return NULL_TREE;
  for (tree arg : *args)
    if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
      return error_mark_node;
  if (old && type_for_tree (TREE_TYPE ((*args)[0])) != dst)
    {
      error_at (loc, "AME/Ztt scalar ternary arithmetic requires old_d "
		    "to have the exact result datatype and shape");
      return error_mark_node;
    }
  tree scalar = (*args)[values - 1];
  tree public_carrier = scalar_public_carrier_type (tc);
  bool fp_carrier = !raw_bits && TREE_CODE (public_carrier) == REAL_TYPE;
  if (fp_carrier
      ? (TREE_CODE (TREE_TYPE (scalar)) != REAL_TYPE
	 || TYPE_MODE (TREE_TYPE (scalar)) != TYPE_MODE (public_carrier))
      : !INTEGRAL_TYPE_P (TREE_TYPE (scalar)))
    {
      if (fp_carrier)
	error_at (loc, "AME/Ztt floating scalar requires the exact C floating format");
      else
	error_at (loc, "AME/Ztt data-scalar arithmetic requires an integer scalar");
      return error_mark_node;
    }
  if (!check_scalar_carrier (loc, scalar, tc))
    return error_mark_node;
  type_index source = type_for_tree (TREE_TYPE ((*args)[values - 2]));
  type_index t[] = { dst, source, tc };
  bool floating = floating_descriptor_p (types[dst].descriptor)
    || floating_descriptor_p (types[tc].descriptor)
    || (source != TYPE_MAX && floating_descriptor_p (types[source].descriptor));
  elementwise_formation f;
  if (!form_integer_scalar (op, t, f, floating))
    {
      if (floating)
	error_at (loc, "AME/Ztt floating data-scalar operation requires compatible "
		  "numeric types and complete M shapes; bitwise and comparison "
		  "results must be integer, min/max types exact, log data floating");
      else
	error_at (loc, "AME/Ztt integer data-scalar operation requires compatible "
		    "types, shapes and complete M groups; min/max and bitwise "
		    "require the exact result datatype for the M source");
      return error_mark_node;
    }
  unsigned int code = integer_scalar_code (op, f, tc, floating);
  tree fn = integer_scalar_builtin_decl (code);
  auto_vec<tree, 6> operands;
  for (unsigned int i = 0; i < values; ++i)
    {
      tree value = i == values - 1
	? (fp_carrier ? build1 (VIEW_CONVERT_EXPR, scalar_carrier_type (tc), scalar)
	   : fold_convert (scalar_carrier_type (tc), scalar))
	: build1 (VIEW_CONVERT_EXPR,
		  ztt_m_type_nodes[integer_matrix_carrier
		    (exact_log2 (f.nregs[old && i == 0 ? 0 : 1]))], (*args)[i]);
      operands.safe_push (value);
    }
  for (type_index type : t)
    operands.safe_push (build_int_cstu (unsigned_type_node, type));
  tree call = build_call_expr_loc_array (loc, fn, operands.length (), operands.address ());
  return build1 (VIEW_CONVERT_EXPR, ztt_m_type_nodes[dst], call);
}

static tree
nominal_payload_type (unsigned int n)
{
  unsigned int bits = types[nominal_scalar_type_index (n)].descriptor & 0xff;
  return lang_hooks.types.type_for_size (MIN (bits, BITS_PER_WORD), true);
}

/* The first two public ranges retain their F55 meaning: madd and broadcast.
   Append the other operations without changing those or raw-call IDs.  */
static unsigned int
nominal_operation (unsigned int code, type_index &dst)
{
  gcc_assert (nominal_operation_p (code));
  unsigned int n = code - (nominal_extended_p (code)
			   ? nominal_extended_base : nominal_operation_base);
  dst = static_cast<type_index> (n % TYPE_MAX);
  return nominal_extended_p (code) ? 1 + n / TYPE_MAX
    : n < TYPE_MAX ? 0 : floating_scalar_operations;
}

static bool
nominal_result_p (unsigned int op, type_index dst)
{
  if (types[dst].accumulator || !ztt_m_type_nodes[dst])
    return false;
  if (op == floating_scalar_operations)
    return true;
  bool fp = floating_descriptor_p (types[dst].descriptor);
  if (op >= integer_scalar_operations)
    return fp;
  expansion_index e = numeric_scalar_operation (op).expansion;
  return !fp || (!scalar_bitwise_p (e) && e != EXPAND_MCMPGE_EW_X
		&& e != EXPAND_MCMPLT_EW_X);
}

static void
register_nominal_scalars ()
{
  for (unsigned int n = 0; n < numeric_scalar_dtype_count; ++n)
    {
      unsigned int d = numeric_dtype_descriptor
	(n < 40 ? n : n < 80 ? n + 8 : n + 16);
      char name[128];
      const char *dtype = scalar_datatype_name (d, false);
      snprintf (name, sizeof (name), "__riscv_ztt_%s_scalar_t", dtype);
      tree field = build_decl (BUILTINS_LOCATION, FIELD_DECL,
			       get_identifier ("__bits"), nominal_payload_type (n));
      tree type = lang_hooks.types.simulate_record_decl
	(BUILTINS_LOCATION, name, make_array_slice (&field, 1));
      nominal_scalar_types[n] = type;
      if (default_scalar_rm_p (d))
	{
	  dtype = scalar_datatype_name (d, true);
	  snprintf (name, sizeof (name), "__riscv_ztt_%s_scalar_t", dtype);
	  lang_hooks.types.register_builtin_type (type, name);
	}
      for (unsigned int kind = 0; kind < 3; ++kind)
	nominal_builtin_decl (nominal_scalar_base + kind * numeric_scalar_dtype_count
			      + n, true);
    }
  /* Fixed P0 retains its explicit-TC operations, using the same nominal
     constructors.  Do not expand its matrix-operation availability.  */
  if (!runtime_profile_p ())
    return;
  for (unsigned int n = 0; n < 2 * TYPE_MAX; ++n)
    nominal_builtin_decl (nominal_operation_base + n, true);
  for (unsigned int n = 0; n < nominal_extended_count; ++n)
    nominal_builtin_decl (nominal_extended_base + n, true);
}

static tree
nominal_builtin_decl (unsigned int code, bool initialize_p)
{
  if (!TARGET_ZTT || !typed_profile_p ())
    return error_mark_node;
  if (in_lto_p)
    return integer_zero_node;
  char name[160];
  const char *dtype;
  tree ftype;
  tree *slot;
  if (code < nominal_operation_base)
    {
      unsigned int n = (code - nominal_scalar_base) % numeric_scalar_dtype_count;
      unsigned int kind = (code - nominal_scalar_base) / numeric_scalar_dtype_count;
      type_index tc = nominal_scalar_type_index (n);
      unsigned int d = types[tc].descriptor;
      if (!nominal_scalar_types[n] || (kind == 0 && (d & 0xff) > BITS_PER_WORD))
	return error_mark_node;
      slot = &nominal_scalar_decls[code - nominal_scalar_base];
      if (*slot || !initialize_p)
	return *slot ? *slot : error_mark_node;
      dtype = scalar_datatype_name (d, false);
      static const char *const names[] = { "make", "from_bits", "bits" };
      snprintf (name, sizeof (name), "__riscv_ztt_scalar_%s_%s", names[kind], dtype);
      tree payload = nominal_payload_type (n);
      ftype = build_function_type_list
	(kind == 2 ? payload : nominal_scalar_types[n],
	 kind == 2 ? nominal_scalar_types[n]
	 : kind == 0 ? scalar_public_carrier_type (tc) : payload, NULL_TREE);
    }
  else if (nominal_operation_p (code))
    {

      type_index t;
      unsigned int op = nominal_operation (code, t);
      if (!nominal_result_p (op, t))
	return error_mark_node;
      slot = nominal_extended_p (code)
	? &nominal_extended_decls[code - nominal_extended_base]
	: &nominal_scalar_decls[code - nominal_scalar_base];
      if (*slot || !initialize_p)
	return *slot ? *slot : error_mark_node;
      dtype = scalar_datatype_name (types[t].descriptor, false);
      snprintf (name, sizeof (name), "__riscv_ztt_%s_%s_%ux%u",
		op == floating_scalar_operations ? "mbcast_m_x"
		: numeric_scalar_name (op), dtype,
		types[t].rows, types[t].columns);
      /* Resolution checks the unconverted arguments.  The placeholder
	 prototype is never a GIMPLE or LTO signature.  */
      tree m = ztt_m_type_nodes[t];
      ftype = op == floating_scalar_operations
	? build_function_type_list (m, void_type_node, NULL_TREE)
	: integer_scalar_old_p (op)
	? build_function_type_list (m, m, m, void_type_node, NULL_TREE)
	: build_function_type_list (m, m, void_type_node, NULL_TREE);
    }
  else
    {
      unsigned int n = code - nominal_broadcast_base;
      unsigned int t = n / numeric_scalar_dtype_count, c = n % numeric_scalar_dtype_count;
      if (types[t].accumulator || !ztt_m_type_nodes[t])
	return error_mark_node;
      if (!nominal_broadcast_decls)
	{
	  if (!initialize_p)
	    return error_mark_node;
	  vec_safe_grow_cleared (nominal_broadcast_decls,
				TYPE_MAX * numeric_scalar_dtype_count, true);
	}
      slot = &(*nominal_broadcast_decls)[n];
      if (*slot || !initialize_p)
	return *slot ? *slot : error_mark_node;
      snprintf (name, sizeof (name), "__builtin_riscv_ztt_nominal_broadcast_%u", n);
      ftype = build_function_type_list (ztt_m_type_nodes[t],
					scalar_carrier_type (nominal_scalar_type_index (c)), NULL_TREE);
    }
  unsigned int fullcode = (code << RISCV_BUILTIN_SHIFT) | RISCV_BUILTIN_ZTT;
  *slot = nominal_raw_broadcast_p (code)
    ? add_builtin_function_ext_scope (name, ftype, fullcode, BUILT_IN_MD,
				     NULL, function_attributes ())
    : simulate_builtin_function_decl (input_location, name, ftype, fullcode,
				      NULL, function_attributes ());
  if (nominal_operation_p (code))
    {
      type_index t;
      unsigned int op = nominal_operation (code, t);
      if (default_scalar_rm_p (types[t].descriptor))
	{
	  dtype = scalar_datatype_name (types[t].descriptor, true);
	  snprintf (name, sizeof (name), "__riscv_ztt_%s_%s_%ux%u",
		    op == floating_scalar_operations ? "mbcast_m_x"
		    : numeric_scalar_name (op), dtype,
		    types[t].rows, types[t].columns);
	  simulate_builtin_function_decl (input_location, name, ftype, fullcode,
					  NULL, function_attributes ());
	}
    }
  return *slot;
}

static unsigned int
nominal_scalar_number (tree type)
{
  type = TYPE_MAIN_VARIANT (type);
  for (unsigned int n = 0; n < numeric_scalar_dtype_count; ++n)
    if (type == nominal_scalar_types[n])
      return n;
  return numeric_scalar_dtype_count;
}

static tree
nominal_payload_field (tree type)
{
  for (tree field = TYPE_FIELDS (type); field; field = DECL_CHAIN (field))
    if (TREE_CODE (field) == FIELD_DECL)
      return field;
  gcc_unreachable ();
}

static tree
nominal_scalar_bits (tree value)
{
  tree field = nominal_payload_field (TREE_TYPE (value));
  return build3 (COMPONENT_REF, TREE_TYPE (field), value, field, NULL_TREE);
}

static tree
resolve_nominal_scalar (location_t loc, unsigned int code, vec<tree, va_gc> *args)
{
  if (nominal_raw_broadcast_p (code))
    return NULL_TREE;
  type_index dst = TYPE_MAX;
  unsigned int op = nominal_operation_p (code)
    ? nominal_operation (code, dst) : floating_scalar_operations;
  unsigned int nargs = op == floating_scalar_operations ? 1
    : integer_scalar_old_p (op) ? 3 : 2;
  if (args->length () != nargs)
    {
      error_at (loc, "AME/Ztt nominal Scalar interface expects %u arguments", nargs);
      return error_mark_node;
    }
  for (tree arg : *args)
    if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
      return error_mark_node;
  tree value = (*args)[nargs - 1];
  if (code < nominal_operation_base)
    {
      unsigned int n = (code - nominal_scalar_base) % numeric_scalar_dtype_count;
      unsigned int kind = (code - nominal_scalar_base) / numeric_scalar_dtype_count;
      if (kind == 2)
	{
	  if (nominal_scalar_number (TREE_TYPE (value)) != n)
	    {
	      error_at (loc, "AME/Ztt Scalar extraction requires the exact TC/RM/SAT type");
	      return error_mark_node;
	    }
	  return nominal_scalar_bits (value);
	}
      tree expected = kind == 0 ? scalar_public_carrier_type (nominal_scalar_type_index (n))
	: nominal_payload_type (n);
      bool fp = TREE_CODE (expected) == REAL_TYPE;
      if (fp ? (TREE_CODE (TREE_TYPE (value)) != REAL_TYPE
		|| TYPE_MODE (TREE_TYPE (value)) != TYPE_MODE (expected))
	: !INTEGRAL_TYPE_P (TREE_TYPE (value)))
	{
	  error_at (loc, "AME/Ztt Scalar constructor requires %s",
		    fp ? "the exact C floating format" : "an integer carrier");
	  return error_mark_node;
	}
      if (!check_scalar_carrier (loc, value, nominal_scalar_type_index (n)))
	return error_mark_node;
      tree constant = fold (value);
      if (!fp && TREE_CODE (constant) == INTEGER_CST
	  && !int_fits_type_p (constant, expected))
	{
	  error_at (loc, "AME/Ztt Scalar constructor constant is out of range");
	  return error_mark_node;
	}
      tree payload = nominal_payload_type (n);
      tree bits = fp ? build1 (VIEW_CONVERT_EXPR, payload, value)
	: fold_convert (payload, value);
      tree type = nominal_scalar_types[n];
      vec<constructor_elt, va_gc> *elts = NULL;
      CONSTRUCTOR_APPEND_ELT (elts, nominal_payload_field (type), bits);
      /* Give the aggregate a temporary object in both languages.  A bare
	 CONSTRUCTOR below COMPONENT_REF is not a C++ class prvalue.  */
      tree temporary = build_decl (loc, VAR_DECL, NULL_TREE, type);
      DECL_ARTIFICIAL (temporary) = 1;
      DECL_IGNORED_P (temporary) = 1;
      return build4 (TARGET_EXPR, type, temporary, build_constructor (type, elts),
		     NULL_TREE, NULL_TREE);
    }
  unsigned int c = nominal_scalar_number (TREE_TYPE (value));
  if (c == numeric_scalar_dtype_count)
    {
      error_at (loc, "AME/Ztt data scalar requires an independent Scalar type; "
		    "use an explicit Scalar constructor");
      return error_mark_node;
    }
  type_index tc = nominal_scalar_type_index (c);
  tree bits = fold_convert (scalar_carrier_type (tc), nominal_scalar_bits (value));
  if (op != floating_scalar_operations)
    {
      vec<tree, va_gc> *resolved = NULL;
      for (unsigned int i = 0; i < nargs - 1; ++i)
	vec_safe_push (resolved, (*args)[i]);
      vec_safe_push (resolved, bits);
      tree result = resolve_integer_scalar (loc, op, dst, tc, resolved, true);
      vec_free (resolved);
      return result;
    }
  unsigned int raw = nominal_broadcast_base + dst * numeric_scalar_dtype_count + c;
  return build_call_expr_loc (loc, nominal_builtin_decl (raw, true), 1, bits);
}

static bool
check_nominal_call (unsigned int code, unsigned int nargs, tree *args)
{
  if (!nominal_raw_broadcast_p (code) || nargs != 1 || args[0] == error_mark_node)
    return false;
  unsigned int n = code - nominal_broadcast_base;
  unsigned int t = n / numeric_scalar_dtype_count, c = n % numeric_scalar_dtype_count;
  if (types[t].accumulator || !type_nregs (static_cast<type_index> (t)))
    return false;
  /* The raw call streams by value in LTO.  Decode TC without frontend trees.  */
  unsigned int d = numeric_dtype_descriptor (c < 40 ? c : c < 80 ? c + 8 : c + 16);
  unsigned int width = MIN (d & 0xff, BITS_PER_WORD);
  tree type = TREE_TYPE (args[0]);
  return INTEGRAL_TYPE_P (type) && TYPE_PRECISION (type) == width
    && TYPE_UNSIGNED (type) == (floating_descriptor_p (d)
			       || (d & 0xff) > BITS_PER_WORD || !(d & (1U << 30)));
}

/* Public explicit-TC spellings share the nominal Scalar contract.  Internal
   carrier builtins are deliberately outside this classification.  */
static bool
public_data_scalar (unsigned int code, unsigned int &op,
		    type_index &dst, type_index &tc)
{
  if (floating_scalar_public_p (code))
    return decode_floating_scalar_public (code, op, dst, tc);
  if (integer_scalar_public_p (code))
    return decode_integer_scalar_public (code, op, dst, tc);
  op = floating_scalar_operations;
  if (floating_broadcast_code_p (code))
    return decode_floating_broadcast (code, dst, tc);
  if (integer_broadcast_code_p (code))
    return decode_integer_broadcast (code, dst, tc);
  if (code >= ZTT_BUILTIN_MAX)
    return false;
  const auto &d = builtin_description_for (code);
  dst = d.type;
  if (d.expansion == EXPAND_MBCAST_M_X)
    {
      tc = broadcast_source_type (d.prototype);
      return true;
    }
  if (scalar_prototype_p (d.prototype, false)
      || scalar_prototype_p (d.prototype, true))
    {
      op = wide_operation (d.expansion) - WIDE_MADD_EW_X;
      tc = scalar_source_type (d.prototype);
      return true;
    }
  return false;
}

tree
resolve_overloaded_builtin (location_t loc, unsigned int code,
			    vec<tree, va_gc> *args)
{
  if (nominal_scalar_code_p (code))
    return resolve_nominal_scalar (loc, code, args);
  unsigned int op;
  type_index dst, tc;
  if (public_data_scalar (code, op, dst, tc))
    {
      unsigned int nargs = op == floating_scalar_operations ? 1
	: integer_scalar_old_p (op) ? 3 : 2;
      if (args->length () != nargs)
	{
	  error_at (loc, "AME/Ztt data-scalar operation expects %u arguments", nargs);
	  return error_mark_node;
	}
      tree value = (*args)[nargs - 1];
      if (value == error_mark_node || TREE_TYPE (value) == error_mark_node)
	return error_mark_node;
      unsigned int c = nominal_scalar_number (TREE_TYPE (value));
      if (c == numeric_scalar_dtype_count)
	{
	  error_at (loc, "AME/Ztt data scalar requires an independent Scalar type; "
			"use an explicit Scalar constructor");
	  return error_mark_node;
	}
      if (types[nominal_scalar_type_index (c)].descriptor != types[tc].descriptor)
	{
	  error_at (loc, "AME/Ztt explicit scalar suffix requires the exact TC/RM/SAT type");
	  return error_mark_node;
	}
      tree bits = fold_convert (scalar_carrier_type (tc), nominal_scalar_bits (value));
      if (op == floating_scalar_operations)
	{
	  unsigned int raw = nominal_broadcast_base + dst * numeric_scalar_dtype_count + c;
	  return build_call_expr_loc (loc, nominal_builtin_decl (raw, true), 1, bits);
	}
      (*args)[nargs - 1] = bits;
      if (runtime_profile_p ())
	return resolve_integer_scalar (loc, op, dst, tc, args, true);
      /* Fixed P0 retains the narrow private lowering below.  Its public
	 record argument has now been checked and unwrapped exactly once.  */
    }
  if (code >= ZTT_BUILTIN_MAX)
    return NULL_TREE;
  const auto &d = builtin_description_for (code);
  if (exponent_p (d.expansion))
    return resolve_exponent (loc, d, args);
  if (matrix_math_operation (d.expansion) >= 0)
    return resolve_integer_matrix (loc, d, args, MATRIX_MATH);
  bool scalar_ternary = scalar_ternary_variant (d.expansion) >= 0;
  bool lazy_arithmetic = scalar_arithmetic_variant (d.expansion) >= 0
    || scalar_ternary || d.prototype == PROTO_M_GATHER
    || d.prototype == PROTO_M_SCATTER || d.prototype == PROTO_M_SHIFT_M
    || d.prototype == PROTO_M_SHIFT_X || d.prototype == PROTO_M_BINARY_M
    || d.prototype == PROTO_M_TERNARY_M || d.expansion == EXPAND_MADD_EW
    || d.expansion == EXPAND_MSUB_EW || d.prototype == PROTO_A_A_M_M;
  bool floating = floating_descriptor_p (types[d.type].descriptor);
  for (tree arg : *args)
    if (arg != error_mark_node && TREE_TYPE (arg) != error_mark_node)
      {
	type_index t = type_for_tree (TREE_TYPE (arg));
	floating |= t != TYPE_MAX && floating_descriptor_p (types[t].descriptor);
      }
  if (floating && floating_unary_operation (d.expansion) >= 0)
    return resolve_floating_unary (loc, d, args);
  if (floating && floating_matrix_operation (d.expansion) >= 0)
    return resolve_integer_matrix (loc, d, args, MATRIX_FLOATING);
  if (floating && d.prototype == PROTO_A_A_M_M)
    return resolve_integer_matmul (loc, d, args, true);
  if (floating && (scalar_arithmetic_variant (d.expansion) >= 0 || scalar_ternary))
    return resolve_integer_scalar
      (loc, wide_operation (d.expansion) - WIDE_MADD_EW_X, d.type,
       scalar_source_type (d.prototype), args);
  if (floating && lazy_arithmetic)
    {
      error_at (loc, "AME/Ztt floating operands are not implemented for this operation");
      return error_mark_node;
    }
  bool extended = extended_integer_p (types[d.type].descriptor);
  if (lazy_arithmetic)
    for (tree arg : *args)
      if (arg != error_mark_node && TREE_TYPE (arg) != error_mark_node)
	{
	  type_index t = type_for_tree (TREE_TYPE (arg));
	  extended |= t != TYPE_MAX && extended_integer_p (types[t].descriptor);
	}
  if (lazy_arithmetic && extended)
    {
      if (scalar_arithmetic_variant (d.expansion) >= 0 || scalar_ternary)
	return resolve_integer_scalar
	  (loc, wide_operation (d.expansion) - WIDE_MADD_EW_X, d.type,
	   scalar_source_type (d.prototype), args);
      if (d.prototype == PROTO_A_A_M_M)
	return resolve_integer_matmul (loc, d, args);
      unsigned int op = wide_operation (d.expansion);
      if (integer_matrix_operation_p (op))
	return resolve_integer_matrix (loc, d, args);
      error_at (loc, "AME/Ztt nibble and saturating arithmetic signatures "
		"are not implemented for this operation");
      return error_mark_node;
    }
  if ((scalar_arithmetic_variant (d.expansion) >= 0 || scalar_ternary)
      && args->length () == (scalar_ternary ? 3U : 2U))
    {
      if (scalar_ternary)
	{
	  tree old = (*args)[0];
	  if (old == error_mark_node || TREE_TYPE (old) == error_mark_node)
	    return error_mark_node;
	  if (type_for_tree (TREE_TYPE (old)) != d.type)
	    {
	      error_at (loc, "AME/Ztt scalar ternary arithmetic requires old_d "
			"to have the exact result datatype and shape");
	      return error_mark_node;
	    }
	}
      tree matrix = (*args)[scalar_ternary ? 1 : 0];
      tree scalar = (*args)[scalar_ternary ? 2 : 1];
      if (matrix == error_mark_node || scalar == error_mark_node
	  || TREE_TYPE (matrix) == error_mark_node
	  || TREE_TYPE (scalar) == error_mark_node)
	return error_mark_node;
      if (!INTEGRAL_TYPE_P (TREE_TYPE (scalar)))
	{
	  error_at (loc, "AME/Ztt data-scalar arithmetic requires an integer scalar");
	  return error_mark_node;
	}
      type_index scalar_type = scalar_source_type (d.prototype);
      if (!check_scalar_carrier (loc, scalar, scalar_type))
	return error_mark_node;
      type_index source = type_for_tree (TREE_TYPE (matrix));
      if (source == TYPE_MAX || types[source].accumulator
	  || types[source].rows != types[d.type].rows
	  || types[source].columns != types[d.type].columns)
	{
	  error_at (loc, "AME/Ztt data-scalar arithmetic requires an integer "
		    "M source with the result shape");
	  return error_mark_node;
	}
      if ((d.expansion == EXPAND_MMIN_EW_X || d.expansion == EXPAND_MMAX_EW_X
	   || scalar_bitwise_p (d.expansion))
	  && source != d.type)
	{
	  if (scalar_bitwise_p (d.expansion))
	    error_at (loc, "AME/Ztt scalar bitwise requires the exact result "
		      "datatype for its M source");
	  else
	    error_at (loc, "AME/Ztt scalar min/max requires the exact result "
		      "datatype for its M source");
	  return error_mark_node;
	}
      bool wide = (types[d.type].descriptor & 0xff) > 32
	|| (types[source].descriptor & 0xff) > 32
	|| (types[scalar_type].descriptor & 0xff) > 32;
      unsigned int resolved = wide
	? encode_extended_builtin (code, source, scalar_type)
	: scalar_code_base + code * 24
	  + mixed_dtype_number (types[source].descriptor);
      scalar_description description;
      if (!decode_scalar_builtin (resolved, description))
	{
	  error_at (loc, "AME/Ztt data-scalar arithmetic requires complete "
		    "M groups for source and destination");
	  return error_mark_node;
	}
      return builtin_decl (resolved, true);
    }
  if (d.prototype == PROTO_M_GATHER || d.prototype == PROTO_M_SCATTER)
    {
      bool scatter = d.prototype == PROTO_M_SCATTER;
      unsigned int nargs = scatter ? 3 : 2;
      if (args->length () != nargs)
	return NULL_TREE;
      type_index actual[3];
      for (unsigned int i = 0; i < nargs; ++i)
	{
	  tree arg = (*args)[i];
	  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	    return error_mark_node;
	  actual[i] = type_for_tree (TREE_TYPE (arg));
	  if (actual[i] == TYPE_MAX || types[actual[i]].accumulator
	      || types[actual[i]].rows != 1 || types[actual[i]].columns != 1)
	    {
	      error_at (loc, "AME/Ztt indexed operation requires basic 1x1 "
			"integer M operands");
	      return error_mark_node;
	    }
	}
      if (actual[0] != d.type)
	{
	  error_at (loc, "AME/Ztt indexed operation requires its first "
		    "operand to have the exact result datatype");
	  return error_mark_node;
	}
      unsigned int resolved = encode_elementwise_builtin
	(code, actual[scatter ? 1 : 0], actual[nargs - 1]);
      elementwise_description description;
      if (!decode_elementwise_builtin (resolved, description))
	{
	  error_at (loc, "AME/Ztt indexed operation requires complete "
		    "basic M groups for every source and destination");
	  return error_mark_node;
	}
      return builtin_decl (resolved, true);
    }
  if ((d.prototype == PROTO_M_CONVERT || d.prototype == PROTO_M_STRUCTURAL
       || d.prototype == PROTO_M_ABS)
      && args->length () == 1)
    {
      tree arg = (*args)[0];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return error_mark_node;
      type_index actual = type_for_tree (TREE_TYPE (arg));
      if (actual == TYPE_MAX || types[actual].accumulator
	  || types[actual].rows != types[d.type].rows
	  || types[actual].columns != types[d.type].columns)
	{
	  if (d.prototype == PROTO_M_ABS)
	    error_at (loc, "AME/Ztt absolute value requires an integer "
		      "M operand with the result shape");
	  else if (d.prototype == PROTO_M_STRUCTURAL)
	    error_at (loc, "AME/Ztt structural operation requires an integer "
		      "M operand with the result shape");
	  else
	    error_at (loc, "AME/Ztt conversion requires an integer M operand "
		      "with the result shape");
	  return error_mark_node;
	}
      unsigned int resolved = encode_conversion_builtin (code, actual);
      conversion_description description;
      if (!decode_conversion_builtin (resolved, description))
	{
	  if (d.prototype == PROTO_M_ABS)
	    error_at (loc, "AME/Ztt absolute value requires complete "
		      "M groups for source and destination");
	  else if (d.prototype == PROTO_M_STRUCTURAL)
	    error_at (loc, "AME/Ztt structural operation requires complete "
		      "M groups for source and destination");
	  else
	    error_at (loc, "AME/Ztt conversion requires complete M groups "
		      "for source and destination");
	  return error_mark_node;
	}
      return builtin_decl (resolved, true);
    }
  bool legacy_arithmetic = d.expansion == EXPAND_MADD_EW
    || d.expansion == EXPAND_MSUB_EW;
  bool ternary = d.prototype == PROTO_M_TERNARY_M;
  if ((d.prototype == PROTO_M_SHIFT_M || d.prototype == PROTO_M_SHIFT_X
       || d.prototype == PROTO_M_BINARY_M || legacy_arithmetic || ternary)
      && args->length () == (ternary ? 3U : 2U))
    {
      bool scalar = d.prototype == PROTO_M_SHIFT_X;
      if (ternary)
	{
	  tree old = (*args)[0];
	  if (old == error_mark_node || TREE_TYPE (old) == error_mark_node)
	    return error_mark_node;
	  if (type_for_tree (TREE_TYPE (old)) != d.type)
	    {
	      if (selected_data_p (d.expansion))
		error_at (loc, "AME/Ztt conditional move requires old_d to have "
			  "the exact result datatype, rounding mode and shape");
	      else
		error_at (loc, "AME/Ztt ternary arithmetic requires old_d to "
			  "have the exact result datatype, rounding mode and shape");
	      return error_mark_node;
	    }
	}
      type_index actual[2] = { TYPE_MAX, TYPE_MAX };
      for (unsigned int i = 0; i < 2; ++i)
	{
	  tree arg = (*args)[i + (ternary ? 1 : 0)];
	  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	    return error_mark_node;
	  if (scalar && i == 1)
	    {
	      if (!INTEGRAL_TYPE_P (TREE_TYPE (arg)))
		{
		  error_at (loc, "AME/Ztt scalar shift count must be an integer");
		  return error_mark_node;
		}
	      continue;
	    }
	  actual[i] = type_for_tree (TREE_TYPE (arg));
	  if (actual[i] == TYPE_MAX || types[actual[i]].accumulator
	      || types[actual[i]].rows != types[d.type].rows
	      || types[actual[i]].columns != types[d.type].columns)
	    {
	      if (legacy_arithmetic)
		return NULL_TREE;
	      if (d.expansion == EXPAND_MMUL_EW)
		error_at (loc, "AME/Ztt elementwise multiply requires integer "
			  "M operands with the result shape");
	      else if (d.prototype == PROTO_M_BINARY_M || ternary)
		error_at (loc, "AME/Ztt elementwise arithmetic requires integer "
			  "M operands with the result shape");
	      else
		error_at (loc, "AME/Ztt shift requires integer M operands "
			  "with the result shape");
	      return error_mark_node;
	    }
	}
      if (selected_data_p (d.expansion) && actual[1] != d.type)
	{
	  error_at (loc, "AME/Ztt conditional selection requires selected "
		    "data to have the exact result datatype, rounding mode and shape");
	  return error_mark_node;
	}
      /* Preserve the historical exact-type add/sub declaration and lowering.
	 Mixed declarations are created only when a source type differs.  */
      if (legacy_arithmetic && actual[0] == d.type && actual[1] == d.type)
	return NULL_TREE;
      unsigned int resolved = encode_elementwise_builtin
	(code, actual[0], scalar ? TYPE_MAX : actual[1]);
      elementwise_description description;
      if (!decode_elementwise_builtin (resolved, description))
	{
	  if (d.expansion == EXPAND_MMUL_EW)
	    error_at (loc, "AME/Ztt elementwise multiply requires complete "
		      "M groups for every source and destination");
	  else if (arithmetic_variant (d.expansion) >= 0 || ternary)
	    error_at (loc, "AME/Ztt elementwise arithmetic requires complete "
		      "M groups for every source and destination");
	  else
	    error_at (loc, "AME/Ztt shift requires complete M groups "
		      "and a signed data source for arithmetic right shift");
	  return error_mark_node;
	}
      return builtin_decl (resolved, true);
    }
  if (d.prototype == PROTO_M_EXTRACT
      && types[d.type].rows == 1 && types[d.type].columns == 1
      && args->length () == 2)
    {
      tree arg = (*args)[0];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return NULL_TREE;
      if (type_for_tree (TREE_TYPE (arg))
	  == m_utility_source_type (PROTO_M_EXTRACT_COLUMN, d.type))
	{
	  unsigned int redirected
	    = redirect_builtin_code (PROTO_M_EXTRACT_COLUMN, d.expansion, d.type);
	  if (redirected < ZTT_BUILTIN_MAX)
	    return builtin_decl (redirected, true);
	}
      return NULL_TREE;
    }
  if (d.prototype == PROTO_A_A_M_M && args->length () == 3)
    {
      type_index actual[3];
      for (unsigned int j = 0; j < 3; ++j)
	{
	  tree arg = (*args)[j];
	  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	    return NULL_TREE;
	  actual[j] = type_for_tree (TREE_TYPE (arg));
	  if (actual[j] == TYPE_MAX)
	    return NULL_TREE;
	}
      if (actual[0] != d.type)
	return NULL_TREE;
      const auto &lhs = types[actual[1]];
      const auto &rhs = types[actual[2]];
      unsigned int uds = active_profile ()->uds;
      if (!lhs.accumulator && !rhs.accumulator
	  && (lhs.descriptor != types[d.type].descriptor
	      || rhs.descriptor != types[d.type].descriptor
	      || (types[d.type].descriptor & 0xff) > 32
	      || (types[d.type].descriptor & 0xff) < uds
	      || lhs.rows * lhs.columns > 4))
	for (unsigned int i = 0; i < matmul_shape_count; ++i)
	  {
	    if (!matmul_shape_allowed_p (i, d.expansion))
	      continue;
	    const auto &s = *matmul_shape (matmul_prototype (i));
	    if (lhs.rows != (s.lhs_column ? s.squares : 1)
		|| lhs.columns != (s.lhs_column ? 1 : s.squares)
		|| rhs.rows != (s.rhs_column ? s.squares : 1)
		|| rhs.columns != (s.rhs_column ? 1 : s.squares))
	      continue;
	    unsigned int mixed = encode_mixed_builtin
	      (code, i, lhs.descriptor, rhs.descriptor);
	    mixed_description description;
	    if (!decode_mixed_builtin (mixed, description))
	      {
		error_at (loc, "AME/Ztt mixed matmul requires complete "
			  "M groups and paired Squares for both inputs");
		return error_mark_node;
	      }
	    return builtin_decl (mixed, true);
	  }
      if (lhs.accumulator || rhs.accumulator
	  || lhs.descriptor != types[d.type].descriptor
	  || rhs.descriptor != types[d.type].descriptor)
	return NULL_TREE;

      unsigned int redirected = ZTT_BUILTIN_MAX;
      for (unsigned int i = 1; i < matmul_shape_count; ++i)
	{
	  prototype_index prototype = matmul_prototype (i);
	  const auto *shape = matmul_shape (prototype);
	  if (lhs.rows == (shape->lhs_column ? shape->squares : 1)
	      && lhs.columns == (shape->lhs_column ? 1 : shape->squares)
	      && rhs.rows == (shape->rhs_column ? shape->squares : 1)
	      && rhs.columns == (shape->rhs_column ? 1 : shape->squares))
	    {
	      unsigned int candidate
		= redirect_builtin_code (prototype, d.expansion, d.type);
	      redirected = MIN (redirected, candidate);
	    }
	}
      if (redirected < ZTT_BUILTIN_MAX)
	return builtin_decl (redirected, true);
      return NULL_TREE;
    }
  if (d.prototype == PROTO_A_M && types[d.type].columns > 1
      && args->length () == 1)
    {
      tree arg = (*args)[0];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return NULL_TREE;
      type_index actual = type_for_tree (TREE_TYPE (arg));
      if (actual != TYPE_MAX && !types[actual].accumulator
	  && types[actual].descriptor == types[d.type].descriptor
	  && types[actual].rows == types[d.type].columns
	  && types[actual].columns == 1)
	{
	  unsigned int redirected
	    = redirect_builtin_code (PROTO_A_M_COLUMN, d.expansion, d.type);
	  if (redirected < ZTT_BUILTIN_MAX)
	    return builtin_decl (redirected, true);
	}
      return NULL_TREE;
    }
  if (!store_dispatch_p (code)
      || args->length () != (memory_variant (d.expansion) >= 2 ? 3U : 2U))
    return NULL_TREE;
  tree arg = (*args)[args->length () - 1];
  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
    return NULL_TREE;
  type_index type = type_for_tree (TREE_TYPE (arg));
  if (type == TYPE_MAX
      || (code == ZTT_BUILTIN_MSS_RM_I8_RNE_1X1 && type == TYPE_I8_RNE_1X1))
    return NULL_TREE;
  if (types[type].accumulator)
    {
      error_at (loc,
		"AME/Ztt accumulator values require an M copy before storing");
      return error_mark_node;
    }
  if ((types[type].descriptor & 0xff) == 4)
    {
      error_at (loc, "AME/Ztt i4/u4 memory interfaces are not supported");
      return error_mark_node;
    }
  unsigned int resolved = store_builtin_code (d.expansion, type);
  gcc_assert (resolved != ZTT_BUILTIN_MAX);
  return builtin_decl (resolved, true);
}

/* Retain old codes for a migration diagnostic, not executable compatibility.  */
static bool
reject_pointer_zip (location_t loc, const builtin_description &d)
{
  error_at (loc, "%qs was replaced in AME/Ztt intrinsic v0.2.5; "
	    "use the 1x2 value interface", d.name);
  return false;
}

bool
check_builtin_arguments (location_t loc, unsigned int code,
			vec<tree, va_gc> *args)
{
  if (nominal_scalar_code_p (code))
    return !nominal_raw_broadcast_p (code)
      || check_nominal_call (code, args->length (), args->address ());
  unsigned int scalar_op;
  type_index scalar_dst, scalar_tc;
  if (public_data_scalar (code, scalar_op, scalar_dst, scalar_tc))
    return true; /* Check nominal arguments before frontend conversions.  */
  if (exponent_code_p (code))
    {
      builtin_description d;
      scalar_description e;
      if (describe_exponent (code, args->length (), args->address (), d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal exponent signature");
      return false;
    }
  if (floating_broadcast_code_p (code))
    {
      type_index dst, tc;
      return decode_floating_broadcast (code, dst, tc)
	&& (args->length () != 1
	    || check_broadcast_carrier (loc, (*args)[0], tc));
    }
  if (floating_unary_code_p (code))
    {
      builtin_description d;
      conversion_description e;
      if (describe_floating_unary (code, args->length (), args->address (), d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal floating unary signature");
      return false;
    }
  if (floating_scalar_public_p (code))
    {
      unsigned int op;
      type_index dst, tc;
      return decode_floating_scalar_public (code, op, dst, tc);
    }
  if (integer_scalar_public_p (code))
    {
      unsigned int op;
      type_index dst, tc;
      return decode_integer_scalar_public (code, op, dst, tc);
    }
  if (numeric_scalar_code_p (code))
    {
      builtin_description d;
      scalar_description e;
      if (describe_integer_scalar (code, args->length (), args->address (), d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal data-scalar signature");
      return false;
    }
  if (integer_broadcast_code_p (code))
    {
      type_index dst, tc;
      if (!decode_integer_broadcast (code, dst, tc))
	return false;
      if (args->length () != 1)
	return true; /* Let the frontend diagnose arity.  */
      tree arg = (*args)[0];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return false;
      if (!INTEGRAL_TYPE_P (TREE_TYPE (arg)))
	{
	  error_at (loc, "AME/Ztt integer broadcast requires an integer scalar");
	  return false;
	}
      return check_scalar_carrier (loc, arg, tc);
    }
  if (integer_matmul_code_p (code) || floating_matmul_code_p (code))
    {
      builtin_description d;
      type_index lhs, rhs;
      if (describe_integer_matmul (code, args->length (), args->address (),
				  d, lhs, rhs))
	return true;
      error_at (loc, "invalid AME/Ztt internal matmul signature");
      return false;
    }
  if (matrix_builtin_code_p (code))
    {
      builtin_description d;
      elementwise_description e;
      if (describe_integer_matrix (code, args->length (), args->address (), d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal matrix signature");
      return false;
    }
  if (integer_unary_code_p (code))
    {
      conversion_description d;
      return decode_conversion_builtin (code, d);
    }
  if (wide_matmul_code_p (code))
    {
      mixed_description d;
      return decode_mixed_builtin (code, d);
    }
  if (wide_scalar_p (code))
    {
      scalar_description d;
      return decode_scalar_builtin (code, d);
    }
  if (code >= conversion_code_base && code < elementwise_code_base)
    {
      conversion_description d;
      return decode_conversion_builtin (code, d);
    }
  if (code >= scalar_code_base && code < conversion_code_base)
    {
      scalar_description d;
      return decode_scalar_builtin (code, d);
    }
  if (code >= elementwise_code_base && code < mixed_code_base)
    {
      elementwise_description d;
      return decode_elementwise_builtin (code, d);
    }
  if (code >= mixed_code_base)
    {
      mixed_description d;
      return decode_mixed_builtin (code, d);
    }
  if (code >= ZTT_BUILTIN_MAX)
    return false;

  const builtin_description &d = builtin_description_for (code);
  if (d.prototype == PROTO_VOID_MPTR_MPTR && args->length () == 2)
    return reject_pointer_zip (loc, d);
  if (rowcol_variant (d.expansion) >= 0 && args->length () == 2)
    {
      tree arg = (*args)[1];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return false;
      if (!INTEGRAL_TYPE_P (TREE_TYPE (arg)))
	{
	  error_at (loc, "AME/Ztt row/column control must be an integer scalar");
	  return false;
	}
    }
  if (d.expansion == EXPAND_MBCAST_M_X && args->length () == 1)
    {
      tree arg = (*args)[0];
      if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
	return false;
      if (!INTEGRAL_TYPE_P (TREE_TYPE (arg)))
	{
	  error_at (loc, "AME/Ztt integer broadcast requires an integer scalar");
	  return false;
	}
      if (!check_scalar_carrier (loc, arg, broadcast_source_type (d.prototype)))
	return false;
    }
  if (d.expansion == EXPAND_MEXTRACT && args->length () == 2)
    {
      tree index = (*args)[1];
      if (index == error_mark_node || TREE_TYPE (index) == error_mark_node)
	return false;
      /* Check the original value before conversion to size_t can discard
	 high bits on RV32.  Nonconstant expressions are checked after folding.  */
      if (!INTEGRAL_TYPE_P (TREE_TYPE (index)))
	{
	  error_at (loc, "AME/Ztt mextract index must be an integer constant 0 or 1");
	  return false;
	}
      tree value = fold (index);
      if (TREE_CODE (value) == INTEGER_CST
	  && (!tree_fits_uhwi_p (value) || tree_to_uhwi (value) > 1))
	{
	  error_at (loc, "AME/Ztt mextract index must be an integer constant 0 or 1");
	  return false;
	}
    }
  int variant = memory_variant (d.expansion);
  bool store_p = memory_store_p (d.expansion);
  if (variant < 0)
    return true;
  if (args->length () != (store_p ? 2U : 1U) + (variant >= 2))
    return true;

  if (variant >= 2)
    {
      tree stride = (*args)[1];
      if (stride == error_mark_node || TREE_TYPE (stride) == error_mark_node)
	return false;
      if (!INTEGRAL_TYPE_P (TREE_TYPE (stride)))
	{
	  error_at (loc, "AME/Ztt memory stride must be an integer scalar");
	  return false;
	}
    }

  tree arg = (*args)[0];
  if (arg == error_mark_node || TREE_TYPE (arg) == error_mark_node)
    return false;

  type_index value_type = d.type;
  if (store_dispatch_p (code))
    {
      tree value = (*args)[args->length () - 1];
      if (value != error_mark_node && TREE_TYPE (value) != error_mark_node)
	{
	  type_index actual = type_for_tree (TREE_TYPE (value));
	  if (actual != TYPE_MAX)
	    value_type = actual;
	}
    }

  if (store_p && types[value_type].accumulator)
    {
      error_at (loc,
		"AME/Ztt accumulator values require an M copy before storing");
      return false;
    }

  if ((types[value_type].descriptor & 0xff) == 4)
    {
      error_at (loc, "AME/Ztt i4/u4 memory interfaces are not supported");
      return false;
    }
  /* Check before implicit pointer conversions lose the caller's carrier
     and qualifiers.  Arrays are accepted through their element type.  */
  tree type = TREE_TYPE (arg);
  tree element = NULL_TREE;
  if (POINTER_TYPE_P (type) || TREE_CODE (type) == ARRAY_TYPE)
    element = TREE_TYPE (type);

  if (!element || TYPE_MAIN_VARIANT (element) != carrier_type (value_type)
      || (store_p && TYPE_READONLY (element)))
    {
      if (store_p)
	error_at (loc, "%qs requires a pointer to writable %qs",
		  d.name, carrier_name (value_type));
      else
	error_at (loc, "%qs requires a pointer to %qs or its %<const%>-qualified type",
		  d.name, carrier_name (value_type));
      return false;
    }

  if (TYPE_VOLATILE (element) || TYPE_ATOMIC (element))
    {
      error_at (loc, "%qs cannot access volatile or atomic memory", d.name);
      return false;
    }
  return true;
}

bool
check_builtin_call (location_t loc, unsigned int code, tree,
		    unsigned int nargs, tree *args)
{
  if (nominal_scalar_code_p (code))
    {
      if (check_nominal_call (code, nargs, args))
	return true;
      error_at (loc, "invalid unresolved AME/Ztt nominal Scalar call");
      return false;
    }
  if (exponent_code_p (code))
    {
      builtin_description d;
      scalar_description e;
      if (describe_exponent (code, nargs, args, d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal exponent signature");
      return false;
    }
  if (floating_broadcast_code_p (code))
    {
      type_index dst, tc;
      return decode_floating_broadcast (code, dst, tc) && nargs == 1
	&& check_broadcast_carrier (loc, args[0], tc);
    }
  if (floating_unary_code_p (code))
    {
      builtin_description d;
      conversion_description e;
      if (describe_floating_unary (code, nargs, args, d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal floating unary signature");
      return false;
    }
  if (floating_scalar_public_p (code))
    {
      unsigned int op;
      type_index dst, tc;
      return decode_floating_scalar_public (code, op, dst, tc)
	&& nargs == (integer_scalar_old_p (op) ? 3U : 2U);
    }
  if (integer_scalar_public_p (code))
    {
      unsigned int op;
      type_index dst, tc;
      return decode_integer_scalar_public (code, op, dst, tc)
	&& nargs == (integer_scalar_old_p (op) ? 3U : 2U);
    }
  if (numeric_scalar_code_p (code))
    {
      builtin_description d;
      scalar_description e;
      if (describe_integer_scalar (code, nargs, args, d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal data-scalar signature");
      return false;
    }
  if (integer_broadcast_code_p (code))
    {
      type_index dst, tc;
      return decode_integer_broadcast (code, dst, tc) && nargs == 1
	&& INTEGRAL_TYPE_P (TREE_TYPE (args[0]));
    }
  if (integer_matmul_code_p (code) || floating_matmul_code_p (code))
    {
      builtin_description d;
      type_index lhs, rhs;
      if (describe_integer_matmul (code, nargs, args, d, lhs, rhs))
	return true;
      error_at (loc, "invalid AME/Ztt internal matmul signature");
      return false;
    }
  if (matrix_builtin_code_p (code))
    {
      builtin_description d;
      elementwise_description e;
      if (describe_integer_matrix (code, nargs, args, d, e))
	return true;
      error_at (loc, "invalid AME/Ztt internal matrix signature");
      return false;
    }
  if (integer_unary_code_p (code))
    {
      conversion_description d;
      return decode_conversion_builtin (code, d);
    }
  if (wide_matmul_code_p (code))
    {
      mixed_description d;
      return decode_mixed_builtin (code, d);
    }
  if (wide_code_p (code))
    {
      if (wide_scalar_p (code))
	{
	  scalar_description d;
	  return decode_scalar_builtin (code, d);
	}
      if (wide_unary_p (code))
	{
	  conversion_description d;
	  return decode_conversion_builtin (code, d);
	}
      elementwise_description d;
      return decode_elementwise_builtin (code, d);
    }
  if (code >= scalar_code_base && code < conversion_code_base)
    {
      scalar_description d;
      return decode_scalar_builtin (code, d);
    }
  if (code >= conversion_code_base && code < elementwise_code_base)
    {
      conversion_description d;
      return decode_conversion_builtin (code, d);
    }
  if (code >= elementwise_code_base && code < mixed_code_base)
    {
      elementwise_description d;
      return decode_elementwise_builtin (code, d);
    }
  if (code >= mixed_code_base)
    {
      mixed_description d;
      return decode_mixed_builtin (code, d);
    }
  if (code >= ZTT_BUILTIN_MAX)
    return false;
  if (!TARGET_ZTT || !typed_profile_p ())
    {
      error_at (loc, "AME/Ztt typed intrinsic requires %<ztt0p6%> and "
		"%<-mztt-profile=gcc-p0-n128-u8-m16-a4%> or "
		"a supported %<-mztt-profile=gcc-runtime-uU-mM-aA%>");
      return false;
    }
  if (builtin_description_for (code).expansion == EXPAND_MEXTRACT && nargs == 2
      && (!tree_fits_uhwi_p (args[1]) || tree_to_uhwi (args[1]) > 1))
    {
      error_at (loc, "AME/Ztt mextract index must be an integer constant 0 or 1");
      return false;
    }
  if (builtin_description_for (code).prototype == PROTO_VOID_MPTR_MPTR
      && nargs == 2)
    return reject_pointer_zip (loc, builtin_description_for (code));
  return true;
}

/* Scalar work may separate structural producers without changing AME state.  */
static bool
local_structure_assignment_p (gimple *stmt)
{
  if (!is_gimple_assign (stmt) || gimple_vuse (stmt)
      || gimple_has_side_effects (stmt)
      || TREE_CODE (gimple_assign_lhs (stmt)) != SSA_NAME)
    return false;
  if (gimple_assign_single_p (stmt))
    return true;
  if (gimple_could_trap_p (stmt))
    return false;
  for (unsigned int i = 0; i < gimple_num_ops (stmt); ++i)
    {
      tree type = TREE_TYPE (gimple_op (stmt, i));
      if (!INTEGRAL_TYPE_P (type) && !POINTER_TYPE_P (type))
	return false;
    }
  return true;
}

/* Keep producer calls as ownership witnesses.  Only cross local scalar
   assignments, not memory accesses, calls or state-changing operations.  */
static bool
local_structure_producers_p (gimple_stmt_iterator *gsi,
			    gimple *const *producers, unsigned int count)
{
  gcc_assert (count && count <= 16);
  for (unsigned int i = 0; i < count; ++i)
    if (!gimple_bb (producers[i]) || gimple_bb (producers[i]) != gsi_bb (*gsi))
      return false;
  gimple_stmt_iterator prev = *gsi;
  unsigned int seen = 0, wanted = (1U << count) - 1;
  for (unsigned int i = 0; i < 16; ++i)
    {
      gsi_prev_nondebug (&prev);
      if (gsi_end_p (prev))
	return false;
      gimple *stmt = gsi_stmt (prev);
      unsigned int before = seen;
      for (unsigned int j = 0; j < count; ++j)
	if (stmt == producers[j])
	  seen |= 1U << j;
      if (seen == wanted)
	return true;
      if (seen != before)
	continue;

      if (!local_structure_assignment_p (stmt))
	return false;
    }
  return false;
}

static unsigned int
structure_builtin_code (gimple *stmt, unsigned int nargs = 2)
{
  if (!is_gimple_call (stmt) || gimple_call_num_args (stmt) != nargs)
    return ZTT_BUILTIN_MAX;
  tree decl = gimple_call_fndecl (stmt);
  if (!decl || !fndecl_built_in_p (decl, BUILT_IN_MD))
    return ZTT_BUILTIN_MAX;
  unsigned int code = DECL_MD_FUNCTION_CODE (decl);
  if ((code & RISCV_BUILTIN_CLASS) != RISCV_BUILTIN_ZTT)
    return ZTT_BUILTIN_MAX;
  return MIN (code >> RISCV_BUILTIN_SHIFT, ZTT_BUILTIN_MAX);
}

/* Shared pairs must be consumed entirely by local, complete projections.  */
static bool
local_projection_uses_p (tree value, type_index half,
			 gimple_stmt_iterator *gsi)
{
  type_index pair = type_for_tree (TREE_TYPE (value));
  unsigned int nregs = type_nregs (half);
  if (pair == TYPE_MAX || !nregs || type_nregs (pair) != 2 * nregs)
    return false;
  gimple *definition = SSA_NAME_DEF_STMT (value);
  if (!is_gimple_call (definition) || gimple_bb (definition) != gsi_bb (*gsi))
    return false;
  gimple *users[16];
  unsigned int count = 0;
  imm_use_iterator iter;
  use_operand_p use;
  FOR_EACH_IMM_USE_FAST (use, iter, value)
    {
      gimple *stmt = USE_STMT (use);
      if (is_gimple_debug (stmt))
	continue;
      unsigned int code = structure_builtin_code (stmt);
      if (count == ARRAY_SIZE (users) || code == ZTT_BUILTIN_MAX
	  || gimple_bb (stmt) != gsi_bb (*gsi))
	return false;
      const auto d = builtin_description_for (code);
      if (d.expansion != EXPAND_MEXTRACT || d.type != half
	  || m_utility_source_type (d.prototype, d.type) != pair
	  || gimple_call_arg (stmt, 0) != value)
	return false;
      tree index = gimple_call_arg (stmt, 1);
      if (!tree_fits_uhwi_p (index) || tree_to_uhwi (index) > 1)
	return false;
      users[count++] = stmt;
    }
  if (count < 2)
    return false;
  unsigned int seen = 0, wanted = (1U << count) - 1;
  gimple_stmt_iterator next = gsi_for_stmt (definition);
  for (unsigned int i = 0; i < 16; ++i)
    {
      gsi_next_nondebug (&next);
      if (gsi_end_p (next))
	return false;
      gimple *stmt = gsi_stmt (next);
      unsigned int before = seen;
      for (unsigned int j = 0; j < count; ++j)
	if (stmt == users[j])
	  seen |= 1U << j;
      if (seen == wanted)
	return true;
      if (seen == before && !local_structure_assignment_p (stmt))
	return false;
    }
  return false;
}

/* Collect at most four same-type copies per input, without deleting witnesses.  */
static bool
strip_structure_copies (tree &value, type_index type, gimple **copies,
			unsigned int &count, bool shared_input = false)
{
  if (type == TYPE_MAX || types[type].accumulator || !type_nregs (type))
    return false;
  unsigned int start = count;
  for (;;)
    {
      if (TREE_CODE (value) != SSA_NAME
	  || (!has_single_use (value) && !(shared_input && count == start))
	  || type_for_tree (TREE_TYPE (value)) != type)
	return false;
      gimple *producer = SSA_NAME_DEF_STMT (value);
      unsigned int code = structure_builtin_code (producer, 1);
      if (code == ZTT_BUILTIN_MAX)
	return true;
      const auto d = builtin_description_for (code);
      if (d.expansion != EXPAND_MCOPY_M2M)
	return true;
      if (d.prototype != PROTO_M_M || d.type != type || count - start == 4)
	return false;
      copies[count++] = producer;
      value = gimple_call_arg (producer, 0);
    }
}

/* Keep structural calls and one terminal copy as ownership witnesses.  */
static bool
structure_witness_p (gimple *stmt, tree parent, gimple *&copy)
{
  copy = nullptr;
  if (!is_gimple_call (stmt))
    return false;
  unsigned int nargs = gimple_call_num_args (stmt);
  if ((nargs != 1 && nargs != 2) || gimple_call_arg (stmt, 0) != parent)
    return false;
  unsigned int code = structure_builtin_code (stmt, nargs);
  if (code == ZTT_BUILTIN_MAX)
    return false;
  const auto d = builtin_description_for (code);
  type_index type = type_for_tree (TREE_TYPE (parent));
  if (type == TYPE_MAX || d.type == TYPE_MAX
      || !type_nregs (type) || !type_nregs (d.type))
    return false;
  if (d.expansion == EXPAND_MCOPY_M2M)
    return nargs == 1 && d.prototype == PROTO_M_M && d.type == type
      && !types[type].accumulator && !gimple_call_lhs (stmt);
  if (nargs == 1)
    {
      if (d.prototype != PROTO_M_M || zip_variant (d.expansion) < 0
	  || d.type != type || types[type].accumulator
	  || types[type].rows != 1 || types[type].columns != 2
	  || (types[type].descriptor & 0xff) < active_profile ()->uds)
	return false;
    }
  else
    {
      if (d.expansion != EXPAND_MEXTRACT
	  || m_utility_source_type (d.prototype, d.type) != type
	  || type_nregs (type) != 2 * type_nregs (d.type))
	return false;
      tree index = gimple_call_arg (stmt, 1);
      if (!tree_fits_uhwi_p (index) || tree_to_uhwi (index) > 1)
	return false;
    }
  tree value = gimple_call_lhs (stmt);
  if (!value)
    return true;
  if (TREE_CODE (value) != SSA_NAME
      || type_for_tree (TREE_TYPE (value)) != d.type)
    return false;
  unsigned int visits = 0;
  imm_use_iterator iter;
  use_operand_p use;
  FOR_EACH_IMM_USE_FAST (use, iter, value)
    {
      gimple *user = USE_STMT (use);
      if (is_gimple_debug (user))
	continue;
      if (++visits > 16)
	return false;
      if (copy)
	return false;
      copy = user;
    }
  if (!copy)
    return false;
  unsigned int copy_code = structure_builtin_code (copy, 1);
  if (copy_code == ZTT_BUILTIN_MAX || gimple_call_lhs (copy)
      || gimple_call_arg (copy, 0) != value)
    return false;
  const auto c = builtin_description_for (copy_code);
  return c.expansion == EXPAND_MCOPY_M2M && c.prototype == PROTO_M_M
    && c.type == d.type && !types[d.type].accumulator;
}

static bool
structure_store_p (gimple *stmt, tree value = NULL_TREE)
{
  if (!is_gimple_call (stmt))
    return false;
  unsigned int nargs = gimple_call_num_args (stmt);
  if (nargs != 2 && nargs != 3)
    return false;
  unsigned int code = structure_builtin_code (stmt, nargs);
  if (code == ZTT_BUILTIN_MAX)
    return false;
  const auto d = builtin_description_for (code);
  return memory_store_p (d.expansion) && d.type != TYPE_MAX
    && !types[d.type].accumulator && type_nregs (d.type)
    && d.prototype == (nargs == 2 ? PROTO_VOID_PTR_M : PROTO_VOID_PTR_STRIDE_M)
    && type_for_tree (TREE_TYPE (gimple_call_arg (stmt, nargs - 1))) == d.type
    && (!value || gimple_call_arg (stmt, nargs - 1) == value);
}

/* Later full stores keep PARENT live without extending its lifetime.  */
static bool
local_structure_parent_p (tree parent, gimple_stmt_iterator *gsi,
			  gimple *producer, gimple *other = nullptr,
			  gimple *const *copies = nullptr,
			  unsigned int ncopies = 0)
{
  gimple *uses[16];
  gimple *stores[16];
  unsigned int nuses = 0, nstores = 0, values = 0, visits = 0;
  unsigned int wanted = other ? 2 : 1;
  imm_use_iterator iter;
  use_operand_p use;
  FOR_EACH_IMM_USE_FAST (use, iter, parent)
    {
      gimple *stmt = USE_STMT (use);
      if (is_gimple_debug (stmt))
	continue;
      if (++visits > 16)
	return false;
      gimple *terminal = nullptr;
      if (stmt == producer || stmt == other)
	{
	  if (++values > wanted)
	    return false;
	}
      else if (!structure_witness_p (stmt, parent, terminal))
	{
	  if (!structure_store_p (stmt, parent)
	      || gimple_bb (stmt) != gsi_bb (*gsi))
	    return false;
	  stores[nstores++] = stmt;
	  continue;
	}
      if (nuses + nstores + (terminal ? 2 : 1) > 16)
	return false;
      if (terminal)
	uses[nuses++] = terminal;
      uses[nuses++] = stmt;
    }
  if (values != wanted || nuses + nstores + ncopies > ARRAY_SIZE (uses))
    return false;
  /* Matched copies do not use PARENT directly.  */
  for (unsigned int i = 0; i < ncopies; ++i)
    uses[nuses++] = copies[i];
  if (!local_structure_producers_p (gsi, uses, nuses))
    return false;
  if (!nstores)
    return true;

  unsigned int seen = 0, all = (1U << nstores) - 1;
  gimple_stmt_iterator next = *gsi;
  for (unsigned int i = 0; i < 16; ++i)
    {
      gsi_next_nondebug (&next);
      if (gsi_end_p (next))
	return false;
      gimple *stmt = gsi_stmt (next);
      for (unsigned int j = 0; j < nstores; ++j)
	if (stmt == stores[j])
	  seen |= 1U << j;
      if (seen == all)
	return true;
      if (!structure_store_p (stmt) && !local_structure_assignment_p (stmt))
	return false;
    }
  return false;
}

static tree
extracted_concat_value (const builtin_description &d,
			gimple_stmt_iterator *gsi, gcall *stmt)
{
  tree index = gimple_call_arg (stmt, 1);
  tree pair = gimple_call_arg (stmt, 0);
  if (!tree_fits_uhwi_p (index) || tree_to_uhwi (index) > 1)
    return NULL_TREE;
  gimple *producers[5];
  unsigned int count = 0;
  type_index pair_type = m_utility_source_type (d.prototype, d.type);
  bool shared = TREE_CODE (pair) == SSA_NAME && !has_single_use (pair);
  if ((shared && !local_projection_uses_p (pair, d.type, gsi))
      || !strip_structure_copies (pair, pair_type, producers, count, shared))
    return NULL_TREE;
  unsigned int half_nregs = type_nregs (d.type);
  if (count && (!half_nregs || type_nregs (pair_type) != 2 * half_nregs))
    return NULL_TREE;
  gimple *producer = SSA_NAME_DEF_STMT (pair);
  unsigned int source_code = structure_builtin_code (producer);
  if (source_code == ZTT_BUILTIN_MAX)
    return NULL_TREE;

  const auto source = builtin_description_for (source_code);
  if (source.expansion != EXPAND_MCONCAT
      || m_utility_source_type (d.prototype, d.type) != source.type
      || m_utility_source_type (source.prototype, source.type) != d.type)
    return NULL_TREE;
  tree value = gimple_call_arg (producer, tree_to_uhwi (index));
  producers[count++] = producer;
  if (type_for_tree (TREE_TYPE (value)) != d.type
      || type_for_tree (TREE_TYPE (pair)) != source.type
      || !local_structure_producers_p (gsi, producers, count))
    return NULL_TREE;
  return value;
}

static tree
rebuilt_pair_value (const builtin_description &d,
		    gimple_stmt_iterator *gsi, gcall *stmt)
{
  type_index half_type = m_utility_source_type (d.prototype, d.type);
  if (half_type == TYPE_MAX)
    return NULL_TREE;
  unsigned int half_nregs = type_nregs (half_type);
  if (!half_nregs || type_nregs (d.type) != 2 * half_nregs)
    return NULL_TREE;
  tree parent = NULL_TREE;
  gimple *extracts[2];
  gimple *copies[8];
  unsigned int ncopies = 0;
  for (unsigned int i = 0; i < 2; ++i)
    {
      tree half = gimple_call_arg (stmt, i);
      if (!strip_structure_copies (half, half_type, copies, ncopies))
	return NULL_TREE;
      extracts[i] = SSA_NAME_DEF_STMT (half);
      unsigned int code = structure_builtin_code (extracts[i]);
      if (code == ZTT_BUILTIN_MAX)
	return NULL_TREE;
      const auto source = builtin_description_for (code);
      if (source.expansion != EXPAND_MEXTRACT || source.type != half_type
	  || m_utility_source_type (source.prototype, source.type) != d.type)
	return NULL_TREE;
      tree index = gimple_call_arg (extracts[i], 1);
      tree value = gimple_call_arg (extracts[i], 0);
      if (!tree_fits_uhwi_p (index) || tree_to_uhwi (index) != i
	  || TREE_CODE (value) != SSA_NAME
	  || type_for_tree (TREE_TYPE (value)) != d.type
	  || (i && value != parent))
	return NULL_TREE;
      parent = value;
    }

  if (!local_structure_parent_p (parent, gsi, extracts[0], extracts[1],
				copies, ncopies))
    return NULL_TREE;
  return parent;
}

static tree
inverse_zip_value (const builtin_description &d,
		   gimple_stmt_iterator *gsi, gcall *stmt)
{
  if (d.type == TYPE_MAX || types[d.type].accumulator
      || types[d.type].rows != 1 || types[d.type].columns != 2
      || (types[d.type].descriptor & 0xff) < active_profile ()->uds)
    return NULL_TREE;
  tree middle = gimple_call_arg (stmt, 0);
  gimple *copies[4];
  unsigned int ncopies = 0;
  if (!strip_structure_copies (middle, d.type, copies, ncopies))
    return NULL_TREE;
  gimple *producer = SSA_NAME_DEF_STMT (middle);
  unsigned int code = structure_builtin_code (producer, 1);
  if (code == ZTT_BUILTIN_MAX)
    return NULL_TREE;
  const auto source = builtin_description_for (code);
  int variant = zip_variant (source.expansion);
  if (source.prototype != PROTO_M_M || source.type != d.type
      || variant < 0 || (variant ^ 2) != zip_variant (d.expansion))
    return NULL_TREE;
  tree parent = gimple_call_arg (producer, 0);
  if (TREE_CODE (parent) != SSA_NAME
      || type_for_tree (TREE_TYPE (parent)) != d.type
      || !local_structure_parent_p (parent, gsi, producer, nullptr, copies,
				    ncopies))
    return NULL_TREE;
  return parent;
}

gimple *
gimple_fold_builtin (unsigned int code, gimple_stmt_iterator *gsi, gcall *stmt)
{
  if (!optimize || code >= ZTT_BUILTIN_MAX)
    return nullptr;
  const auto d = builtin_description_for (code);
  bool zip = d.prototype == PROTO_M_M && zip_variant (d.expansion) >= 0;
  if ((!zip && d.expansion != EXPAND_MEXTRACT && d.expansion != EXPAND_MCONCAT)
      || gimple_call_num_args (stmt) != (zip ? 1 : 2) || !gimple_call_lhs (stmt)
      || !TARGET_ZTT || !runtime_profile_p ())
    return nullptr;
  tree lhs = gimple_call_lhs (stmt);
  if (type_for_tree (TREE_TYPE (lhs)) != d.type)
    return nullptr;
  tree value = zip ? inverse_zip_value (d, gsi, stmt)
    : d.expansion == EXPAND_MEXTRACT ? extracted_concat_value (d, gsi, stmt)
    : rebuilt_pair_value (d, gsi, stmt);
  if (!value)
    return nullptr;

  unlink_stmt_vdef (stmt);
  if (tree vdef = gimple_vdef (stmt))
    release_ssa_name (vdef);
  return gimple_build_assign (lhs, value);
}

static rtx
result_register (machine_mode mode, rtx target)
{
  if (target == NULL_RTX || GET_MODE (target) != mode || !REG_P (target))
    return gen_reg_rtx (mode);
  return target;
}

static rtx
matrix_memory (machine_mode mode, tree exp, unsigned int argno)
{
  tree pointer = CALL_EXPR_ARG (exp, argno);
  rtx addr = expand_normal (pointer);
  addr = convert_memory_address (Pmode, addr);
  addr = force_reg (Pmode, addr);

  rtx mem = gen_rtx_MEM (mode, addr);
  /* The pointer contract, rather than the mode, determines alignment.  */
  set_mem_align (mem, get_pointer_alignment (pointer));
  return mem;
}

static rtx
matrix_register (machine_mode mode, tree exp, unsigned int argno)
{
  return force_reg (mode, expand_normal (CALL_EXPR_ARG (exp, argno)));
}

/* A scatter result retains
   the old destination as an explicit input, including untouched elements.  */
static rtx
expand_indexed (const builtin_description &d,
		const elementwise_description &operation, tree exp)
{
  bool scatter = d.prototype == PROTO_M_SCATTER;
  type_index indices[] = { d.type, operation.data, operation.count };
  machine_mode modes[3];
  rtx dtype[3];
  for (unsigned int i = 0; i < 3; ++i)
    {
      unsigned int descriptor = types[indices[i]].descriptor;
      riscv_ztt_note_descriptor (descriptor);
      dtype[i] = GEN_INT (descriptor);
      modes[i] = type_mode (indices[i]);
    }
  gcc_assert (operation.formation.insns == 1
	      && types[d.type].rows == 1 && types[d.type].columns == 1);
  rtx old = scatter ? matrix_register (modes[0], exp, 0) : NULL_RTX;
  rtx data = matrix_register (modes[1], exp, scatter ? 1 : 0);
  rtx index = matrix_register (modes[2], exp, scatter ? 2 : 1);
  rtx result = gen_reg_rtx (modes[0]);
  rtx variant = GEN_INT (indexed_variant (d.expansion));
  bool flags = floating_descriptor_p (types[d.type].descriptor)
    || floating_descriptor_p (types[operation.data].descriptor)
    || (types[d.type].descriptor & (1U << 29));
  if (scatter && flags)
    emit_insn (gen_ztt_typed_scatter_flags
	       (modes[0], result, data, index, variant,
		dtype[1], dtype[2], dtype[0], old));
  else if (scatter)
    emit_insn (gen_ztt_typed_scatter
	       (modes[0], result, data, index, variant,
		dtype[1], dtype[2], dtype[0], old));
  else if (flags)
    emit_insn (gen_ztt_typed_gather_flags
	       (modes[0], result, data, index, variant,
		dtype[1], dtype[2], dtype[0]));
  else
    emit_insn (gen_ztt_typed_gather
	       (modes[0], result, data, index, variant,
		dtype[1], dtype[2], dtype[0]));
  return result;
}

static rtx
expand_elementwise (const builtin_description &d,
		    const elementwise_description &operation, tree exp)
{
  if (indexed_variant (d.expansion) >= 0)
    return expand_indexed (d, operation, exp);
  bool scalar = operation.count == TYPE_MAX;
  int ternary = ternary_variant (d.expansion);
  int arithmetic = arithmetic_variant (d.expansion);
  unsigned int variant = ternary >= 0 ? ternary : arithmetic >= 0
    ? arithmetic : d.expansion - EXPAND_MSLL_EW;
  type_index indices[] = { d.type, operation.data, operation.count };
  rtx dtype[3] = { NULL_RTX, NULL_RTX, const0_rtx };
  machine_mode modes[3] = { VOIDmode, VOIDmode, VOIDmode };
  for (unsigned int i = 0; i < (scalar ? 2U : 3U); ++i)
    {
      unsigned int descriptor = types[indices[i]].descriptor;
      riscv_ztt_note_descriptor (descriptor);
      dtype[i] = GEN_INT (descriptor);
      modes[i] = type_mode (indices[i]);
    }
  rtx old = ternary >= 0 ? matrix_register (modes[0], exp, 0) : NULL_RTX;
  rtx data = matrix_register (modes[1], exp, ternary >= 0 ? 1 : 0);
  bool shared = !scalar && ternary < 0 && m_nregs (modes[1]) > 4
    && modes[1] == modes[2] && rtx_equal_p (dtype[1], dtype[2])
    && operand_equal_p (CALL_EXPR_ARG (exp, 0), CALL_EXPR_ARG (exp, 1), 0);
  rtx count = scalar ? expand_normal (CALL_EXPR_ARG (exp, 1))
    : shared ? data : matrix_register (modes[2], exp, ternary >= 0 ? 2 : 1);
  if (scalar && count != const0_rtx)
    count = force_reg (Pmode, count);
  rtx result = gen_reg_rtx (modes[0]);
  const auto &f = operation.formation;
  bool flags = floating_descriptor_p (types[d.type].descriptor)
    || floating_descriptor_p (types[operation.data].descriptor)
    || (!scalar && floating_descriptor_p (types[operation.count].descriptor))
    || (types[d.type].descriptor & (1U << 29));
  emit_clobber (result);
  for (unsigned int i = 0; i < f.insns; ++i)
    {
      auto part = [&] (unsigned int operand, rtx value)
	{
	  machine_mode mode = matrix_mode (f.step[operand]);
	  return simplify_gen_subreg
	    (mode, value, modes[operand], GET_MODE_SIZE (mode) * i);
	};
      rtx dst = part (0, result);

      if (ternary >= 0 && flags)
	emit_insn (gen_ztt_typed_ternary_flags
		   (GET_MODE (dst), dst, part (1, data), part (2, count),
		    GEN_INT (variant), dtype[1], dtype[2], dtype[0], part (0, old)));
      else if (ternary >= 0)
	emit_insn (gen_ztt_typed_ternary
		   (GET_MODE (dst), dst, part (1, data), part (2, count),
		    GEN_INT (variant), dtype[1], dtype[2], dtype[0], part (0, old)));
      else if (flags)
	emit_insn (gen_ztt_typed_elementwise_flags
		   (scalar ? UNSPECV_ZTT_ELEMENTWISE_X_FLAGS
		    : UNSPECV_ZTT_ELEMENTWISE_M_FLAGS,
		    GET_MODE (dst), dst, part (1, data),
		    scalar ? count : part (2, count), GEN_INT (variant),
		    dtype[1], dtype[2], dtype[0]));
      else
	emit_insn (gen_ztt_typed_elementwise
		 (scalar ? UNSPEC_ZTT_ELEMENTWISE_X : UNSPEC_ZTT_ELEMENTWISE_M,
		  GET_MODE (dst), dst, part (1, data),
		  scalar ? count : part (2, count), GEN_INT (variant),
		  dtype[1], dtype[2], dtype[0]));
    }
  return result;
}

static rtx
expand_elementwise (unsigned int code, tree exp)
{
  elementwise_description operation;
  bool valid = decode_elementwise_builtin (code, operation);
  gcc_assert (valid);
  return expand_elementwise (builtin_description_for (operation.canonical),
			     operation, exp);
}

static rtx
expand_conversion (const builtin_description &d,
		   const conversion_description &operation, tree exp)
{
  type_index indices[] = { d.type, operation.source };
  machine_mode modes[2];
  rtx dtype[2];
  for (unsigned int i = 0; i < 2; ++i)
    {
      unsigned int descriptor = types[indices[i]].descriptor;
      riscv_ztt_note_descriptor (descriptor);
      dtype[i] = GEN_INT (descriptor);
      modes[i] = type_mode (indices[i]);
    }
  rtx source = matrix_register (modes[1], exp, 0);
  rtx result = gen_reg_rtx (modes[0]);
  const auto &f = operation.formation;
  emit_clobber (result);
  for (unsigned int i = 0; i < f.insns; ++i)
    {
      machine_mode dm = matrix_mode (f.step[0]);
      machine_mode sm = matrix_mode (f.step[1]);
      rtx dst = simplify_gen_subreg (dm, result, modes[0], GET_MODE_SIZE (dm) * i);
      rtx src = simplify_gen_subreg (sm, source, modes[1], GET_MODE_SIZE (sm) * i);
      int variant = structural_variant (d.expansion);
      /* FP exceptions accrue in amefflags, independently of scalar fast-math
	 and fenv options.  FP exponent bits must not be read as integer SAT.  */
      bool flags = floating_descriptor_p (UINTVAL (dtype[0]))
	|| floating_descriptor_p (UINTVAL (dtype[1]))
	|| (UINTVAL (dtype[0]) & (1U << 29));
      rtx_code effect = flags
	? UNSPEC_VOLATILE : UNSPEC;
      if (variant >= 0)
	emit_insn (gen_ztt_typed_structural
		   (effect, dm, dst, src, GEN_INT (variant), dtype[1], dtype[0]));
      else
	emit_insn (gen_ztt_typed_convert
		   (effect, dm, dst, src, dtype[1], dtype[0]));
    }
  return result;
}

static rtx
expand_conversion (unsigned int code, tree exp)
{
  conversion_description operation;
  bool valid = decode_conversion_builtin (code, operation);
  gcc_assert (valid);
  return expand_conversion (builtin_description_for (operation.canonical),
			    operation, exp);
}

/* C first converts to the
   named carrier; hardware converts TC to TB before the family expression.  */
static rtx
expand_scalar (const builtin_description &d, const scalar_description &operation,
	       tree exp)
{
  bool exponent = exponent_p (d.expansion);
  int ternary = scalar_ternary_variant (d.expansion);
  type_index indices[] = { d.type, operation.source };
  machine_mode modes[2];
  rtx dtype[2];
  for (unsigned int i = 0; i < 2; ++i)
    {
      unsigned int descriptor = types[indices[i]].descriptor;
      riscv_ztt_note_descriptor (descriptor);
      dtype[i] = GEN_INT (descriptor);
      modes[i] = type_mode (indices[i]);
    }
  rtx old = ternary >= 0 ? matrix_register (modes[0], exp, 0) : NULL_RTX;
  bool shared = exponent && ternary >= 0 && m_nregs (modes[0]) > 4
    && modes[0] == modes[1] && rtx_equal_p (dtype[0], dtype[1])
    && operand_equal_p (CALL_EXPR_ARG (exp, 0), CALL_EXPR_ARG (exp, 1), 0);
  rtx source = shared ? old : matrix_register (modes[1], exp, ternary >= 0 ? 1 : 0);
  tree carrier = exponent ? long_integer_type_node : scalar_carrier_type (operation.scalar);
  rtx scalar = expand_normal (CALL_EXPR_ARG (exp, ternary >= 0 ? 2 : 1));
  scalar = convert_modes
    (Pmode, TYPE_MODE (carrier), scalar, TYPE_UNSIGNED (carrier));
  if (scalar != const0_rtx)
    scalar = force_reg (Pmode, scalar);
  if (!exponent
      && (TYPE_MODE (carrier) == QImode || TYPE_MODE (carrier) == HImode
	  || TYPE_MODE (carrier) == SImode))
    scalar = gen_lowpart (TYPE_MODE (carrier), scalar);
  rtx scalar_descriptor = exponent ? const0_rtx : GEN_INT (types[operation.scalar].descriptor);
  rtx result = gen_reg_rtx (modes[0]);
  const auto &f = operation.formation;
  /* Scalar ingress converts TC to TB before computing the result in TD.
     Either conversion can saturate, even when the result is unused.  */
  bool flags = floating_descriptor_p (UINTVAL (dtype[0]))
    || floating_descriptor_p (UINTVAL (dtype[1]))
    || (!exponent && floating_descriptor_p (types[operation.scalar].descriptor))
    || ((UINTVAL (dtype[0]) | (exponent ? 0 : UINTVAL (dtype[1]))) & (1U << 29));
  emit_clobber (result);
  for (unsigned int i = 0; i < f.insns; ++i)
    {
      auto part = [&] (unsigned int operand, rtx value)
	{
	  machine_mode mode = matrix_mode (f.step[operand]);
	  return simplify_gen_subreg
	    (mode, value, modes[operand], GET_MODE_SIZE (mode) * i);
	};
      rtx dst = part (0, result);
      if (ternary >= 0)
	{
	  insn_code insn = flags
	    ? code_for_ztt_typed_ternary_x_flags (GET_MODE (dst), Pmode)
	    : code_for_ztt_typed_ternary_x (GET_MODE (dst), Pmode);
	  emit_insn (GEN_FCN (insn)
	    (dst, part (1, source), scalar, GEN_INT (ternary),
	     dtype[1], scalar_descriptor, dtype[0], part (0, old)));
	}
      else if (flags)
	emit_insn (gen_ztt_typed_elementwise_flags
		 (UNSPECV_ZTT_ELEMENTWISE_X_FLAGS, GET_MODE (dst), dst,
		  part (1, source), scalar,
		  GEN_INT (scalar_arithmetic_variant (d.expansion)),
		  dtype[1], scalar_descriptor, dtype[0]));
      else
	emit_insn (gen_ztt_typed_elementwise
		 (UNSPEC_ZTT_ELEMENTWISE_X, GET_MODE (dst), dst,
		  part (1, source), scalar,
		  GEN_INT (scalar_arithmetic_variant (d.expansion)),
		  dtype[1], scalar_descriptor, dtype[0]));
    }
  return result;
}

static rtx
expand_scalar (unsigned int code, tree exp)
{
  scalar_description operation;
  bool valid = decode_scalar_builtin (code, operation);
  gcc_assert (valid);
  return expand_scalar (builtin_description_for (operation.canonical),
			operation, exp);
}

/* Copy the four 32-byte
   segments of an N=4, 64-bit packet without touching padding.  Byte moves
   also preserve overlapping-store segment order and arbitrary strides.
   Do not use a block-move libcall in a typed AME leaf function.  */
static void
copy_small_tst_packet (rtx address, rtx stride, rtx buffer, bool store_p)
{
  rtx segment = copy_to_mode_reg (Pmode, address);
  for (unsigned int i = 0; i < 4; ++i)
    {
      rtx bytes = copy_to_mode_reg (Pmode, segment);
      rtx temp = copy_to_mode_reg
	(Pmode, plus_constant (Pmode, XEXP (buffer, 0), i * 32));
      rtx end = force_reg (Pmode, plus_constant (Pmode, bytes, 32));
      rtx_code_label *loop = gen_label_rtx ();
      emit_label (loop);
      rtx value = gen_reg_rtx (QImode);
      rtx data_mem = gen_rtx_MEM (QImode, bytes);
      rtx temp_mem = gen_rtx_MEM (QImode, temp);
      set_mem_align (data_mem, BITS_PER_UNIT);
      set_mem_align (temp_mem, BITS_PER_UNIT);
      emit_move_insn (value, store_p ? temp_mem : data_mem);
      emit_move_insn (store_p ? data_mem : temp_mem, value);
      emit_move_insn (bytes, plus_constant (Pmode, bytes, 1));
      emit_move_insn (temp, plus_constant (Pmode, temp, 1));
      emit_cmp_and_jump_insns (bytes, end, NE, NULL_RTX, Pmode, 1, loop);
      if (i + 1 < 4)
	emit_move_insn (segment, gen_rtx_PLUS (Pmode, segment, stride));
    }
}

/* A 128-bit TST packet
   can need staging at N=4 or N=8.  Copy N segments of N*16 bytes in
   increasing order, preserving high halves and overlapping stores.  */
static void
copy_wide_tst_packet (rtx address, rtx stride, rtx buffer, rtx n,
		      rtx segment_size, bool store_p)
{
  rtx segment = copy_to_mode_reg (Pmode, address);
  rtx temp = copy_to_mode_reg (Pmode, XEXP (buffer, 0));
  rtx remaining = copy_to_mode_reg (Pmode, n);
  rtx_code_label *outer = gen_label_rtx ();
  rtx_code_label *inner = gen_label_rtx ();
  emit_label (outer);
  rtx bytes = copy_to_mode_reg (Pmode, segment);
  rtx end = force_reg (Pmode, gen_rtx_PLUS (Pmode, bytes, segment_size));
  emit_label (inner);
  rtx value = gen_reg_rtx (QImode);
  rtx data_mem = gen_rtx_MEM (QImode, bytes);
  rtx temp_mem = gen_rtx_MEM (QImode, temp);
  set_mem_align (data_mem, BITS_PER_UNIT);
  set_mem_align (temp_mem, BITS_PER_UNIT);
  emit_move_insn (value, store_p ? temp_mem : data_mem);
  emit_move_insn (store_p ? data_mem : temp_mem, value);
  emit_move_insn (bytes, plus_constant (Pmode, bytes, 1));
  emit_move_insn (temp, plus_constant (Pmode, temp, 1));
  emit_cmp_and_jump_insns (bytes, end, NE, NULL_RTX, Pmode, 1, inner);
  emit_move_insn (segment, gen_rtx_PLUS (Pmode, segment, stride));
  emit_move_insn (remaining, plus_constant (Pmode, remaining, -1));
  emit_cmp_and_jump_insns (remaining, const0_rtx, NE, NULL_RTX,
			 Pmode, 1, outer);
}

/* Each instruction transfers
   one complete packet.  ST packets advance horizontally by P*N*E/8;
   TST packets advance by P*N byte strides.  Shape labels do not change
   this local packet-order memory contract.  */
static rtx
expand_memory (const builtin_description &d, tree exp, rtx target)
{
  unsigned int dtype = types[d.type].descriptor;
  unsigned int bits = dtype & 0xff;
  unsigned int group = MAX (1U, bits / active_profile ()->uds);
  unsigned int packets = type_nregs (d.type) / group;
  unsigned int packed = MAX (1U, active_profile ()->uds / bits);
  int variant = memory_variant (d.expansion);
  bool store_p = memory_store_p (d.expansion);
  machine_mode mode = type_mode (d.type), part_mode = matrix_mode (group);
  poly_int64 part_size = GET_MODE_SIZE (part_mode);
  rtx address = XEXP (matrix_memory (BLKmode, exp, 0), 0);
  rtx scalar_stride = variant == 1 ? const0_rtx
    : expand_normal (CALL_EXPR_ARG (exp, 1));
  bool even_stride = CONST_INT_P (scalar_stride)
    && (UINTVAL (scalar_stride) & 1) == 0;
  rtx stride = variant == 1 ? const0_rtx : force_reg (Pmode, scalar_stride);
  rtx value = store_p ? matrix_register (mode, exp, variant == 1 ? 1 : 2)
    : (packets == 1 ? result_register (mode, target) : gen_reg_rtx (mode));
  if (!store_p && packets > 1)
    emit_clobber (value);

  rtx step = NULL_RTX;
  rtx runtime_n = NULL_RTX;
  if (packets > 1)
    {
      if (variant == 1)
	step = force_reg (Pmode, gen_int_mode (part_size, Pmode));
      else
	{
	  rtx n;
	  if (runtime_profile_p ())
	    {
	      n = gen_reg_rtx (Pmode);
	      emit_insn (TARGET_64BIT ? gen_riscv_ztt_read_amenlen_di (n)
			: gen_riscv_ztt_read_amenlen_si (n));
	      runtime_n = n;
	    }
	  else
	    n = GEN_INT (active_profile ()->n);
	  unsigned int shift = exact_log2 (packed * (variant == 2 ? bits / 8 : 1));
	  if (variant == 3 && !runtime_profile_p ())
	    {
	      shift += exact_log2 (active_profile ()->n);
	      n = stride;
	    }
	  step = shift ? expand_simple_binop (Pmode, ASHIFT, n, GEN_INT (shift),
					     NULL_RTX, 1, OPTAB_DIRECT) : n;
	  if (variant == 3 && runtime_profile_p ())
	    step = expand_simple_binop (Pmode, MULT, step, stride, NULL_RTX,
				       1, OPTAB_DIRECT);
	  gcc_assert (step);
	}
    }
  rtx misaligned = const0_rtx;
  rtx buffer = NULL_RTX;
  bool wide_staging = variant == 3 && bits == 128 && packets > 1
    && runtime_profile_p ()
    && !(CONST_INT_P (scalar_stride) && (UINTVAL (scalar_stride) & 3) == 0);
  rtx wide_segment_size = NULL_RTX;
  if (wide_staging)
    {
      gcc_assert (runtime_n && packed == 1);
      /* Nonzero derived-base remainder implies N=4 or N=8.  The
	 largest staged packet is therefore 8*8*16 bytes, aligned to 16.  */
      buffer = assign_stack_temp (BLKmode, 1024);
      gcc_assert (MEM_ALIGN (buffer) >= 128);
      buffer = replace_equiv_address
	(buffer, force_reg (Pmode, XEXP (buffer, 0)));
      wide_segment_size = expand_simple_binop
	(Pmode, ASHIFT, runtime_n, GEN_INT (4), NULL_RTX, 1, OPTAB_DIRECT);
    }
  if (variant == 3 && bits == 64 && packed == 1 && packets > 1 && !even_stride
      && runtime_profile_p ())
    {
      /* Valid runtime N is a power of two >= 4.  A nonzero remainder
	 therefore implies N=4 and odd stride.  Even-numbered packet
	 offsets stay aligned, and all other sizes keep the direct path.  */
      misaligned = expand_simple_binop (Pmode, AND, step, GEN_INT (7),
				       NULL_RTX, 1, OPTAB_DIRECT);
      if (!rtx_equal_p (misaligned, const0_rtx))
	{
	  misaligned = force_reg (Pmode, misaligned);
	  buffer = assign_stack_temp (BLKmode, 128);
	  gcc_assert (MEM_ALIGN (buffer) >= 64);
	  rtx buffer_address = force_reg (Pmode, XEXP (buffer, 0));
	  buffer = replace_equiv_address (buffer, buffer_address);
	}
    }
  for (unsigned int i = 0; i < packets; ++i)
    {
      rtx part = simplify_gen_subreg (part_mode, value, mode, part_size * i);
      /* A strided access is not a contiguous mode-sized object.  Unknown
	 BLK extent and alias set zero conservatively cover every segment.  */
      rtx mem = gen_rtx_MEM (BLKmode, address);
      if (variant == 1)
	set_mem_size (mem, part_size);
      auto transfer = [&] (rtx location, rtx byte_stride)
	{
	  if (store_p)
	    emit_insn (gen_ztt_typed_memory_store
		       (part_mode, Pmode, location, part, byte_stride,
			GEN_INT (variant), GEN_INT (dtype)));
	  else
	    emit_insn (gen_ztt_typed_memory_load
		       (part_mode, Pmode, part, location, byte_stride,
			GEN_INT (variant), GEN_INT (dtype)));
	};
      if (wide_staging && (i & 3))
	misaligned = expand_simple_binop (Pmode, AND, address, GEN_INT (15),
					 NULL_RTX, 1, OPTAB_DIRECT);
      if (buffer && (wide_staging ? (i & 3) != 0 : (i & 1) != 0))
	{
	  rtx_code_label *direct = gen_label_rtx ();
	  rtx_code_label *done = gen_label_rtx ();
	  emit_cmp_and_jump_insns (misaligned, const0_rtx, EQ, NULL_RTX,
				 Pmode, 1, direct);
	  rtx temp_stride = force_reg (Pmode, wide_staging
				      ? wide_segment_size : GEN_INT (32));
	  if (store_p)
	    transfer (buffer, temp_stride);
	  if (wide_staging)
	    copy_wide_tst_packet (address, stride, buffer, runtime_n,
				  wide_segment_size, store_p);
	  else
	    copy_small_tst_packet (address, stride, buffer, store_p);
	  if (!store_p)
	    transfer (buffer, temp_stride);
	  emit_jump (done);
	  emit_label (direct);
	  transfer (mem, stride);
	  emit_label (done);
	}
      else
	transfer (mem, stride);
      if (i + 1 < packets)
	address = force_reg (Pmode, gen_rtx_PLUS (Pmode, address, step));
    }
  return store_p ? const0_rtx : value;
}

/* Shared lowering retains full old-ACC dependencies and source order.
   Each input subreg denotes a complete formed window, never a partial ACC.  */
static rtx
expand_matmul (const builtin_description &d, unsigned int lhs_dtype,
	       unsigned int rhs_dtype, bool mixed_p, tree exp, rtx target)
{
  unsigned int dtype = types[d.type].descriptor;
  riscv_ztt_note_descriptor (dtype);
  riscv_ztt_note_descriptor (lhs_dtype);
  riscv_ztt_note_descriptor (rhs_dtype);
  machine_mode mode = type_mode (d.type);
  gcc_assert (acc_mode_supported_p (mode));
  matmul_formation formation;
  bool valid = form_matmul (lhs_dtype & 0xff, rhs_dtype & 0xff,
			    matmul_shape (d.prototype)->squares,
			    active_profile ()->uds, formation);
  gcc_assert (valid);
  machine_mode lhs_part = matrix_mode (formation.lhs_step);
  machine_mode rhs_part = matrix_mode (formation.rhs_step);
  machine_mode lhs_mode = matrix_mode (formation.lhs_nregs);
  machine_mode rhs_mode = matrix_mode (formation.rhs_nregs);
  target = result_register (mode, target);
  rtx old_acc = matrix_register (mode, exp, 0);
  rtx lhs = matrix_register (lhs_mode, exp, 1);
  /* At -O0, separately expanding the same M object can require two full
     register banks.  Share only identical, nonvolatile source values.  */
  rtx rhs = (lhs_mode == rhs_mode && lhs_dtype == rhs_dtype
	     && operand_equal_p (CALL_EXPR_ARG (exp, 1),
			 CALL_EXPR_ARG (exp, 2), 0))
    ? lhs : matrix_register (rhs_mode, exp, 2);
  rtx descriptor = GEN_INT (dtype);
  rtx variant = GEN_INT (matmul_variant (d.expansion));
  for (unsigned int i = 0; i < formation.insns; ++i)
    {
      rtx a = simplify_gen_subreg
	(lhs_part, lhs, lhs_mode, GET_MODE_SIZE (lhs_part) * i);
      rtx b = simplify_gen_subreg
	(rhs_part, rhs, rhs_mode, GET_MODE_SIZE (rhs_part) * i);
      if (floating_descriptor_p (dtype | lhs_dtype | rhs_dtype)
	  || (dtype & (1U << 29)))
	emit_insn (gen_ztt_typed_acc_mmul_flags
		   (mode, target, old_acc, a, b, descriptor, variant,
		    GEN_INT (lhs_dtype), GEN_INT (rhs_dtype)));
      else if (mixed_p)
	emit_insn (gen_ztt_typed_acc_mmul_mixed
		   (mode, target, old_acc, a, b, descriptor, variant,
		    GEN_INT (lhs_dtype), GEN_INT (rhs_dtype)));
      else
	emit_insn (gen_ztt_typed_acc_mmul
		   (mode, target, old_acc, a, b, descriptor, variant));
      old_acc = target;
    }
  return target;
}

/* Reuse the indivisible,
   volatile settyp/broadcast pattern so unused SAT results retain flags.
   Expand the scalar once, even when several formed groups are emitted.  */
static rtx
expand_broadcast (type_index dst_type, type_index source_type, tree exp)
{
  unsigned int dtype = types[dst_type].descriptor;
  riscv_ztt_note_descriptor (dtype);
  machine_mode mode = type_mode (dst_type);
  unsigned int nregs = type_nregs (dst_type);
  tree carrier = scalar_carrier_type (source_type);
  tree scalar_arg = CALL_EXPR_ARG (exp, 0);
  if (TREE_CODE (TREE_TYPE (scalar_arg)) == REAL_TYPE)
    scalar_arg = build1 (VIEW_CONVERT_EXPR, carrier, scalar_arg);
  rtx scalar = expand_normal (scalar_arg);
  scalar = force_reg (Pmode, convert_modes
    (Pmode, TYPE_MODE (carrier), scalar, TYPE_UNSIGNED (carrier)));
  scalar = gen_lowpart (TYPE_MODE (carrier), scalar);
  rtx source_descriptor = force_reg
    (Pmode, GEN_INT (types[source_type].descriptor));
  rtx descriptor = force_reg (Pmode, GEN_INT (dtype));
  unsigned int step = MAX (1, (dtype & 0xff) / active_profile ()->uds);
  gcc_assert (nregs && nregs % step == 0);
  machine_mode part_mode = matrix_mode (step);
  rtx result = gen_reg_rtx (mode);
  emit_clobber (result);
  for (unsigned int i = 0; i < nregs / step; ++i)
    {
      rtx dst = simplify_gen_subreg
	(part_mode, result, mode, GET_MODE_SIZE (part_mode) * i);
      emit_insn (gen_ztt_typed_broadcast
	(part_mode, Pmode, dst, scalar, source_descriptor, descriptor));
    }
  return result;
}

rtx
expand_builtin (unsigned int code, tree exp, rtx target)
{
  if (nominal_scalar_code_p (code))
    {
      tree arg = call_expr_nargs (exp) == 1 ? CALL_EXPR_ARG (exp, 0) : error_mark_node;
      if (!check_nominal_call (code, call_expr_nargs (exp), &arg))
	{
	  error_at (EXPR_LOCATION (exp), "invalid unresolved AME/Ztt nominal Scalar call");
	  return const0_rtx;
	}
      unsigned int n = code - nominal_broadcast_base;
      return expand_broadcast
	(static_cast<type_index> (n / numeric_scalar_dtype_count),
	 nominal_scalar_type_index (n % numeric_scalar_dtype_count), exp);
    }
  if (exponent_code_p (code))
    {
      auto_vec<tree, 5> args;
      for (int i = 0; i < call_expr_nargs (exp); ++i)
	args.safe_push (CALL_EXPR_ARG (exp, i));
      builtin_description d;
      scalar_description e;
      if (!describe_exponent (code, args.length (), args.address (), d, e))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt internal exponent signature");
	  return const0_rtx;
	}
      return expand_scalar (d, e, exp);
    }
  if (floating_broadcast_code_p (code))
    {
      type_index dst, tc;
      if (!decode_floating_broadcast (code, dst, tc))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt floating broadcast signature");
	  return const0_rtx;
	}
      return expand_broadcast (dst, tc, exp);
    }
  if (floating_unary_code_p (code))
    {
      auto_vec<tree, 3> args;
      for (int i = 0; i < call_expr_nargs (exp); ++i)
	args.safe_push (CALL_EXPR_ARG (exp, i));
      builtin_description d;
      conversion_description e;
      if (!describe_floating_unary (code, args.length (), args.address (), d, e))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt internal floating unary signature");
	  return const0_rtx;
	}
      return expand_conversion (d, e, exp);
    }
  if (numeric_scalar_code_p (code))
    {
      auto_vec<tree, 6> args;
      for (int i = 0; i < call_expr_nargs (exp); ++i)
	args.safe_push (CALL_EXPR_ARG (exp, i));
      builtin_description d;
      scalar_description e;
      if (!describe_integer_scalar (code, args.length (), args.address (), d, e))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt internal data-scalar signature");
	  return const0_rtx;
	}
      return expand_scalar (d, e, exp);
    }
  if (integer_scalar_public_p (code) || floating_scalar_public_p (code))
    {
      error_at (EXPR_LOCATION (exp), "unresolved AME/Ztt data-scalar call");
      return const0_rtx;
    }
  if (integer_broadcast_code_p (code))
    {
      type_index dst, tc;
      if (!decode_integer_broadcast (code, dst, tc))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt broadcast signature");
	  return const0_rtx;
	}
      return expand_broadcast (dst, tc, exp);
    }
  if (integer_matmul_code_p (code) || floating_matmul_code_p (code))
    {
      auto_vec<tree, 5> args;
      for (int i = 0; i < call_expr_nargs (exp); ++i)
	args.safe_push (CALL_EXPR_ARG (exp, i));
      builtin_description d;
      type_index lhs, rhs;
      if (!describe_integer_matmul (code, args.length (), args.address (),
				  d, lhs, rhs))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt internal matmul signature");
	  return const0_rtx;
	}
      return expand_matmul (d, types[lhs].descriptor, types[rhs].descriptor,
			    true, exp, target);
    }
  if (matrix_builtin_code_p (code))
    {
      auto_vec<tree, 6> args;
      for (int i = 0; i < call_expr_nargs (exp); ++i)
	args.safe_push (CALL_EXPR_ARG (exp, i));
      builtin_description d;
      elementwise_description e;
      if (!describe_integer_matrix (code, args.length (), args.address (), d, e))
	{
	  error_at (EXPR_LOCATION (exp), "invalid AME/Ztt internal matrix signature");
	  return const0_rtx;
	}
      return expand_elementwise (d, e, exp);
    }
  if (integer_unary_code_p (code))
    return expand_conversion (code, exp);
  if (wide_code_p (code))
    return wide_scalar_p (code) ? expand_scalar (code, exp)
      : wide_unary_p (code) ? expand_conversion (code, exp)
      : expand_elementwise (code, exp);
  if (code >= scalar_code_base && code < wide_matmul_code_base)
    return expand_scalar (code, exp);
  if (code >= conversion_code_base && code < elementwise_code_base)
    return expand_conversion (code, exp);
  if (code >= elementwise_code_base && code < mixed_code_base)
    return expand_elementwise (code, exp);
  mixed_description mixed;
  bool mixed_p = code >= mixed_code_base || wide_matmul_code_p (code);
  if (mixed_p)
    {
      bool valid = decode_mixed_builtin (code, mixed);
      gcc_assert (valid);
    }
  else
    gcc_assert (code < ZTT_BUILTIN_MAX);
  builtin_description d
    = builtin_description_for (mixed_p ? mixed.canonical : code);
  if (mixed_p)
    d.prototype = mixed.prototype;
  unsigned int dtype = types[d.type].descriptor;
  riscv_ztt_note_descriptor (dtype);
  unsigned int nregs = type_nregs (d.type);
  if (!nregs)
    {
      char name[160];
      error_at (EXPR_LOCATION (exp), "%qs has an unsupported AME/Ztt shape "
		"for UDS=%u", canonical_builtin_name (d, name),
		active_profile ()->uds);
      return const0_rtx;
    }
  machine_mode mode = type_mode (d.type);
  rtx descriptor = GEN_INT (dtype);

  if (memory_variant (d.expansion) > 0)
    return expand_memory (d, exp, target);

  if (d.expansion == EXPAND_MROWID_EW || d.expansion == EXPAND_MCOLID_EW)
    {
      /* The typed constructor
	 needs an exact N-1, not the ISA's UN/no-write probing outcome.
	 Check the local typed precondition at the call, not at function entry:
	 an untaken narrow constructor must not reject a wider operation.  */
      gcc_assert (types[d.type].rows == 1 && types[d.type].columns == 1
		  && (dtype & 0xff) >= active_profile ()->uds);
      unsigned int precision = (dtype & 0xff) - ((dtype >> 30) & 1);
      if (runtime_profile_p () && precision < GET_MODE_BITSIZE (Pmode))
	{
	  rtx n = gen_reg_rtx (Pmode);
	  emit_insn (TARGET_64BIT ? gen_riscv_ztt_read_amenlen_di (n)
				: gen_riscv_ztt_read_amenlen_si (n));
	  rtx_code_label *valid = gen_label_rtx ();
	  riscv_expand_conditional_branch
	    (valid, LEU, n, gen_int_mode (HOST_WIDE_INT_1U << precision, Pmode));
	  JUMP_LABEL (get_last_insn ()) = valid;
	  expand_builtin_trap ();
	  emit_label (valid);
	}
      else if (p0_profile_p ())
	gcc_assert (active_profile ()->n <= (HOST_WIDE_INT_1U << precision));
      target = result_register (mode, target);
      emit_insn (gen_ztt_typed_index_construct
	(mode, Pmode, target, force_reg (Pmode, descriptor),
	 GEN_INT (d.expansion == EXPAND_MCOLID_EW)));
      return target;
    }

  if (zip_variant (d.expansion) >= 0)
    {
      if (d.prototype == PROTO_M_M)
	{
	  gcc_assert (types[d.type].rows == 1 && types[d.type].columns == 2
		      && (dtype & 0xff) >= active_profile ()->uds);
	  target = result_register (mode, target);
	  emit_insn (gen_ztt_typed_zip_value
	    (mode, target, matrix_register (mode, exp, 0),
	     GEN_INT (zip_variant (d.expansion)), descriptor));
	  return target;
	}
      reject_pointer_zip (EXPR_LOCATION (exp), d);
      return const0_rtx;
    }

  if (rowcol_variant (d.expansion) >= 0)
    {
      gcc_assert (types[d.type].rows == 1 && types[d.type].columns == 1
		  && (dtype & 0xff) >= active_profile ()->uds);
      tree arg = CALL_EXPR_ARG (exp, 1);
      if (optimize && runtime_profile_p ()
	  && d.prototype == PROTO_M_ROWCOL_OFFSET && integer_zerop (arg))
	{
	  /* Keep a full-mode move for the early ownership check.  */
	  rtx result = gen_reg_rtx (mode);
	  emit_move_insn (result, matrix_register (mode, exp, 0));
	  return result;
	}
      /* Both fixed-type controls consume only the low 32 bits.  */
      rtx control = expand_normal (arg);
      control = convert_modes
	(Pmode, TYPE_MODE (TREE_TYPE (arg)), control,
	 d.prototype == PROTO_M_ROWCOL_INDEX);
      if (CONST_INT_P (control)
	  && trunc_int_for_mode (INTVAL (control), SImode) == 0)
	control = const0_rtx;
      else
	control = gen_lowpart (SImode, force_reg (Pmode, control));
      rtx result = gen_reg_rtx (mode);
      emit_insn (gen_ztt_typed_rowcol
	(mode, result, matrix_register (mode, exp, 0), control,
	 GEN_INT (rowcol_variant (d.expansion)), descriptor));
      return result;
    }

  if (d.expansion == EXPAND_MBCAST_M_X)
    return expand_broadcast (d.type, broadcast_source_type (d.prototype), exp);

  if (types[d.type].accumulator)
    {
      gcc_assert (acc_mode_supported_p (mode)
		  && (dtype & 0xff) == acc_m_nregs (mode) * active_profile ()->uds
				     / acc_transfer_accs (mode));
      /* Whole M/ACC transfers need a representable M value; clearing,
	 copying and matmul do not require the complete image to fit in M.  */
      machine_mode m_mode = (d.expansion == EXPAND_A_FROM_M
			     || d.expansion == EXPAND_M_FROM_A)
	? matrix_mode (acc_full_m_nregs (mode)) : VOIDmode;
      switch (d.expansion)
	{
	case EXPAND_ACLEAR:
	case EXPAND_AZERO:
	  target = result_register (mode, target);
	  descriptor = force_reg (Pmode, descriptor);
	  emit_insn (d.expansion == EXPAND_ACLEAR
		     ? gen_ztt_acc_clear (mode, Pmode, target, descriptor)
		     : gen_ztt_acc_zero (mode, Pmode, target, descriptor));
	  return target;
	case EXPAND_A_FROM_M:
	  target = result_register (mode, target);
	  emit_insn (gen_ztt_typed_acc_from_m
		     (mode, target, matrix_register (m_mode, exp, 0), descriptor));
	  return target;
	case EXPAND_M_FROM_A:
	  target = result_register (m_mode, target);
	  emit_insn (gen_ztt_acc_to_m
		     (mode, Pmode, target, matrix_register (mode, exp, 0),
		      force_reg (Pmode, descriptor)));
	  return target;
	case EXPAND_A_MMUL:
	case EXPAND_A_MMULNEG:
	case EXPAND_A_MMULAT:
	case EXPAND_A_MMULATNEG:
	case EXPAND_A_MMULBT:
	case EXPAND_A_MMULBTNEG:
	  {
	    return expand_matmul (d, mixed_p ? types[mixed.lhs].descriptor : dtype,
				  mixed_p ? types[mixed.rhs].descriptor : dtype,
				  mixed_p, exp, target);
	  }
	default:
	  gcc_unreachable ();
	}
    }

  if (d.expansion == EXPAND_MCOPY_M2M)
    {
      /* Copy the complete value, including a concatenated group.  Ordinary
	 moves already preserve data across descriptor changes and spills;
	 an unconditional settyp here could clear a still-live source.  */
      rtx src = matrix_register (mode, exp, 0);
      target = result_register (mode, target);
      emit_move_insn (target, src);
      return target;
    }

  if (d.expansion == EXPAND_MCONCAT || d.expansion == EXPAND_MEXTRACT)
    {
      machine_mode src_mode
	= type_mode (m_utility_source_type (d.prototype, d.type));
      rtx src = matrix_register (src_mode, exp, 0);
      if (d.expansion == EXPAND_MCONCAT)
	{
	  rtx rhs = matrix_register (src_mode, exp, 1);
	  /* Read both sources before defining a fresh contiguous parent.
	     Allocation may coalesce copies, but cannot discard live halves.  */
	  target = gen_reg_rtx (mode);
	  emit_clobber (target);
	  emit_move_insn (simplify_gen_subreg (src_mode, target, mode, 0), src);
	  emit_move_insn (simplify_gen_subreg
			 (src_mode, target, mode, GET_MODE_SIZE (src_mode)), rhs);
	}
      else
	{
	  unsigned int index = tree_to_uhwi (CALL_EXPR_ARG (exp, 1));
	  gcc_assert (index <= 1);
	  target = result_register (mode, target);
	  emit_move_insn (target, simplify_gen_subreg
			 (mode, src, src_mode, GET_MODE_SIZE (mode) * index));
	}
      return target;
    }

  /* Decompose a concatenation before allocation.  The enclosing pseudo
     owns the complete span; subregs identify complete hardware operands,
     not fragments of a packed M.  Existing state envelopes can therefore
     preserve each operand without confusing wide and concatenated values.  */
  unsigned int group = MAX (1U, (dtype & 0xff) / active_profile ()->uds);
  unsigned int chunks = nregs / group;
  int binary_code = binary_unspec (d.expansion);
  if (chunks > 1)
    {
      machine_mode part_mode = matrix_mode (group);
      poly_int64 part_size = GET_MODE_SIZE (part_mode);
      rtx memory = NULL_RTX, lhs = NULL_RTX, rhs = NULL_RTX;
      if (d.expansion == EXPAND_MSS_RM)
	{
	  memory = matrix_memory (mode, exp, 0);
	  lhs = matrix_register (mode, exp, 1);
	}
      else
	{
	  /* A fresh destination cannot overwrite a still-live source chunk.  */
	  target = gen_reg_rtx (mode);
	  if (d.expansion == EXPAND_MLS_RM)
	    memory = matrix_memory (mode, exp, 0);
	  else if (binary_code >= 0)
	    {
	      lhs = matrix_register (mode, exp, 0);
	      rhs = (group > 4
		     && operand_equal_p (CALL_EXPR_ARG (exp, 0),
				 CALL_EXPR_ARG (exp, 1), 0))
		? lhs : matrix_register (mode, exp, 1);
	    }
	  emit_clobber (target);
	}
      for (unsigned int i = 0; i < chunks; ++i)
	{
	  poly_int64 offset = part_size * i;
	  rtx dst = d.expansion == EXPAND_MSS_RM ? NULL_RTX
	    : simplify_gen_subreg (part_mode, target, mode, offset);
	  rtx a = lhs ? simplify_gen_subreg (part_mode, lhs, mode, offset)
	    : NULL_RTX;
	  rtx b = rhs ? simplify_gen_subreg (part_mode, rhs, mode, offset)
	    : NULL_RTX;
	  rtx mem = memory ? adjust_address (memory, part_mode, offset)
	    : NULL_RTX;
	  switch (d.expansion)
	    {
	    case EXPAND_MCLEAR_M:
	      emit_insn (gen_ztt_typed_msettyp_p0
			 (part_mode, Pmode, dst, force_reg (Pmode, descriptor)));
	      break;
	    case EXPAND_MZERO_2D_M:
	      emit_insn (gen_ztt_typed_mzero_2d_m (part_mode, dst, descriptor));
	      break;
	    case EXPAND_MLS_RM:
	      emit_insn (gen_ztt_typed_mls_rm (part_mode, dst, mem, descriptor));
	      break;
	    case EXPAND_MSS_RM:
	      emit_insn (gen_ztt_typed_mss_rm (part_mode, mem, a, descriptor));
	      break;
	    case EXPAND_MADD_EW:
	    case EXPAND_MSUB_EW:
	    case EXPAND_MMIN_EW:
	    case EXPAND_MMAX_EW:
	    case EXPAND_MAND_EW:
	    case EXPAND_MANDNOT_EW:
	    case EXPAND_MOR_EW:
	    case EXPAND_MORNOT_EW:
	    case EXPAND_MXOR_EW:
	      emit_insn (gen_ztt_typed_m_ew
			 (binary_code, part_mode, dst, a, b, descriptor));
	      break;
	    default:
	      gcc_unreachable ();
	    }
	}
      return d.expansion == EXPAND_MSS_RM ? const0_rtx : target;
    }

  switch (d.expansion)
    {
    case EXPAND_MCLEAR_M:
      {
	target = result_register (mode, target);
	descriptor = force_reg (Pmode, descriptor);
	/* Settyp defines the value as well as Md.  Emit it at the call,
	   even if the prologue has already established this datatype.  */
	emit_insn (gen_ztt_typed_msettyp_p0
		   (mode, Pmode, target, descriptor));
	return target;
      }

    case EXPAND_MZERO_2D_M:
      target = result_register (mode, target);
      emit_insn (gen_ztt_typed_mzero_2d_m (mode, target, descriptor));
      return target;

    case EXPAND_MLS_RM:
      target = result_register (mode, target);
      emit_insn (gen_ztt_typed_mls_rm
		 (mode, target, matrix_memory (mode, exp, 0), descriptor));
      return target;

    case EXPAND_MSS_RM:
      emit_insn (gen_ztt_typed_mss_rm
		 (mode, matrix_memory (mode, exp, 0),
		  matrix_register (mode, exp, 1), descriptor));
      return const0_rtx;

    case EXPAND_MADD_EW:
    case EXPAND_MSUB_EW:
    case EXPAND_MMIN_EW:
    case EXPAND_MMAX_EW:
    case EXPAND_MAND_EW:
    case EXPAND_MANDNOT_EW:
    case EXPAND_MOR_EW:
    case EXPAND_MORNOT_EW:
    case EXPAND_MXOR_EW:
      target = result_register (mode, target);
      {
	rtx a = matrix_register (mode, exp, 0);
	/* At -O0 the same source object can be loaded into two different
	   pseudos.  Keep one read for equal, nonvolatile operands so an
	   entire-bank input remains allocatable without relying on CSE.  */
	rtx b = (group > 4
		 && operand_equal_p (CALL_EXPR_ARG (exp, 0),
				     CALL_EXPR_ARG (exp, 1), 0))
	  ? a : matrix_register (mode, exp, 1);
	emit_insn (gen_ztt_typed_m_ew
		   (binary_code, mode, target, a, b, descriptor));
      }
      return target;
    default:
      gcc_unreachable ();
    }
  gcc_unreachable ();
}


/* Split only after allocation:
   the group mode owns all M registers, while each raw transfer owns one.  */
void
split_group_move (rtx *operands)
{
  bool load_p = MEM_P (operands[1]);
  rtx mem = operands[load_p ? 1 : 0];
  rtx group = operands[load_p ? 0 : 1];
  gcc_assert (MEM_P (mem) && REG_P (group));
  unsigned int nregs = m_nregs (GET_MODE (group));
  machine_mode unit_mode = matrix_mode ();
  poly_int64 unit_size = GET_MODE_SIZE (unit_mode);
  rtx address = operands[2];
  rtx stride = operands[3];
  if (runtime_profile_p ())
    emit_insn (gen_rtx_SET
	       (stride, gen_rtx_ASHIFT
		(Pmode, gen_rtx_REG (Pmode, RISCV_ZTT_SCALE_REGNUM),
		 GEN_INT (4))));
  else
    emit_move_insn (stride, gen_int_mode (unit_size, Pmode));
  emit_move_insn (address, XEXP (mem, 0));
  for (unsigned int i = 0; i < nregs; ++i)
    {
      rtx reg = gen_rtx_REG (unit_mode, REGNO (group) + i);
      rtx part = adjust_address_nv (mem, unit_mode, unit_size * i);
      part = replace_equiv_address (part, address);
      if (load_p)
	emit_move_insn (reg, part);
      else
	emit_move_insn (part, reg);
      if (i + 1 < nregs)
	emit_insn (gen_rtx_SET (address,
			       gen_rtx_PLUS (Pmode, address, stride)));
    }
}

/* Preserve ALL source registers before settyp clears their group.  These
   envelopes stay indivisible, with explicit private memory and GPR scratch.  */
static bool
binary_dest_setup_p (rtx *operands)
{
  return !reload_completed
    || (!rtx_equal_p (operands[0], operands[1])
	&& !rtx_equal_p (operands[0], operands[2]));
}

unsigned int
binary_state_length (rtx *operands, unsigned int prepared)
{
  gcc_assert (prepared <= 3);
  unsigned int nregs = m_nregs (GET_MODE (operands[1]));
  unsigned int sources = !(prepared & 1) + !(prepared & 2);
  return 4 * (sources * (nregs == 1 ? 3 : 4 * nregs + 1)
	      + binary_dest_setup_p (operands) + 1);
}

const char *
output_group_state (rtx *operands, const char *binary_format,
		    unsigned int prepared)
{
  bool binary_p = binary_format != nullptr;
  if (binary_p && prepared == 3)
    {
      if (binary_dest_setup_p (operands))
	output_asm_insn ("msettyp\t%0,%3", operands);
      return binary_format;
    }
  rtx base = XEXP (operands[binary_p ? 4 : 3], 0);
  unsigned int nregs = m_nregs (GET_MODE (operands[1]));
  rtx stride = nregs == 1 ? NULL_RTX : operands[binary_p ? 5 : 4];
  rtx address = nregs == 1 ? base : operands[binary_p ? 6 : 5];
  rtx descriptor = operands[binary_p ? 3 : 2];
  auto transfer = [&] (rtx group, bool load_p)
    {
      rtx args[] = { address, base, stride, NULL_RTX };
      if (nregs > 1)
	output_asm_insn ("mv\t%0,%1", args);
      for (unsigned int i = 0; i < nregs; ++i)
	{
	  args[3] = gen_rtx_REG (matrix_mode (), REGNO (group) + i);
	  output_asm_insn (load_p ? "mls.1r\t%3,%0" : "mss.1r\t%3,%0",
			   args);
	  if (i + 1 < nregs)
	    output_asm_insn ("add\t%0,%0,%2", args);
	}
    };
  auto preserve = [&] (rtx group)
    {
      transfer (group, false);
      rtx args[] = { group, descriptor };
      output_asm_insn ("msettyp\t%0,%1", args);
      transfer (group, true);
    };
  if (!(prepared & 1))
    preserve (operands[1]);
  if (binary_p)
    {
      if (!(prepared & 2))
	preserve (operands[2]);
      /* Same-mode aligned groups can only overlap completely.  Both sources
	 now have the required Md and their original payload.  A repeated
	 destination msettyp would erase an overlapping source before use.  */
      if (binary_dest_setup_p (operands))
	{
	  rtx args[] = { operands[0], descriptor };
	  output_asm_insn ("msettyp\t%0,%1", args);
	}
      output_asm_insn (binary_format, operands);
    }
  else
    output_asm_insn ("mss.rm\t%1,%q0", operands);
  return "";
}

/* ADDRESS is an explicit
   scratch for groups; one .1r transfers one physical M, not one Square.  */
static void
output_acc_m_transfer (rtx group, rtx address, rtx stride, bool load_p)
{
  unsigned int nregs = m_nregs (GET_MODE (group));
  for (unsigned int i = 0; i < nregs; ++i)
    {
      rtx args[] = { gen_rtx_REG (matrix_mode (), REGNO (group) + i),
		     address, stride };
      output_asm_insn (load_p ? "mls.1r\t%0,%1" : "mss.1r\t%0,%1", args);
      if (i + 1 < nregs)
	output_asm_insn ("add\t%1,%1,%2", args);
    }
}

/* Keep the complete source payload across msettyp, including all members
   of a wide operand.  The private save area is explicit in the pattern.  */
const char *
output_memory_store (rtx *operands)
{
  unsigned int nregs = m_nregs (GET_MODE (operands[1]));
  rtx base = XEXP (operands[4], 0);
  for (unsigned int pass = 0; pass < 2; ++pass)
    {
      rtx address = base;
      if (nregs > 1)
	{
	  rtx args[] = { operands[7], base };
	  output_asm_insn ("mv\t%0,%1", args);
	  address = operands[7];
	}
      output_acc_m_transfer (operands[1], address, operands[5], pass != 0);
      if (pass == 0)
	output_asm_insn ("msettyp\t%1,%3", operands);
    }
  switch (INTVAL (operands[6]))
    {
    case 1: return "mss.cm\t%1,%q0";
    case 2: return "mss.st\t%1,(%q0),%z2";
    case 3: return "mss.tst\t%1,(%q0),%z2";
    default: gcc_unreachable ();
    }
}

unsigned int
memory_store_length (machine_mode mode)
{
  unsigned int nregs = m_nregs (mode);
  return nregs == 1 ? 16 : 4 * (4 * nregs + 2);
}

/* After the first complete
   save/set/reload, an identical physical source needs no second preparation.
   Match the full mode, descriptor and datatype step, not just overlapping
   storage or equal C types.  Keep pre-allocation length queries conservative.  */
static bool
elementwise_shared_source_p (rtx *operands, bool scalar)
{
  if (scalar || !reload_completed
      || !REG_P (operands[1]) || !M_REG_P (REGNO (operands[1]))
      || !rtx_equal_p (operands[1], operands[2])
      || !REG_P (operands[4]) || !GP_REG_P (REGNO (operands[4]))
      || !rtx_equal_p (operands[4], operands[5]))
    return false;
  unsigned int steps = UINTVAL (operands[9]);
  unsigned int lhs = datatype_step (steps, 1);
  unsigned int rhs = datatype_step (steps, 2);
  return lhs && lhs == rhs;
}

/* A completely overlapping
   source already has the destination's Md after its save/set/reload.
   Repeating the destination settyp would destroy the restored source.  */
static bool
elementwise_reused_destination_p (rtx *operands, bool scalar)
{
  if (!reload_completed || !REG_P (operands[0])
      || !M_REG_P (REGNO (operands[0]))
      || !operands[3] || !REG_P (operands[3])
      || !GP_REG_P (REGNO (operands[3])))
    return false;
  unsigned int steps = UINTVAL (operands[9]);
  unsigned int dest_step = datatype_step (steps, 0);
  for (unsigned int i = 1; i <= (scalar ? 1U : 2U); ++i)
    if (rtx_equal_p (operands[0], operands[i])
	&& rtx_equal_p (operands[3], operands[3 + i])
	&& dest_step && dest_step == datatype_step (steps, i))
      return true;
  return false;
}

/* Preserve every raw member
   before settyp; a formed operand can contain several datatype groups.  */
static void
prepare_elementwise_state (rtx *operands, bool scalar, bool preserve_dest,
			   unsigned int prepared)
{
  unsigned int steps = UINTVAL (operands[9]);
  auto setup = [&] (unsigned int operand)
    {
      unsigned int group = datatype_step (steps, operand);
      unsigned int nregs = m_nregs (GET_MODE (operands[operand]));
      gcc_assert (group && nregs % group == 0);
      for (unsigned int i = 0; i < nregs; i += group)
	{
	  rtx args[] = { gen_rtx_REG (matrix_mode (group),
				     REGNO (operands[operand]) + i),
			 operands[3 + operand] };
	  output_asm_insn ("msettyp\t%0,%1", args);
	}
    };
  unsigned int sources
    = scalar || elementwise_shared_source_p (operands, scalar) ? 1 : 2;
  for (unsigned int operand = preserve_dest ? 0 : 1;
       operand <= sources; ++operand)
    {
      if (prepared & (1U << operand))
	continue;
      rtx base = XEXP (operands[6], 0);
      bool group = m_nregs (GET_MODE (operands[operand])) > 1;
      for (bool load : { false, true })
	{
	  if (group)
	    {
	      rtx args[] = { operands[10], base };
	      output_asm_insn ("mv\t%0,%1", args);
	    }
	  output_acc_m_transfer (operands[operand], group ? operands[10] : base,
				 operands[7], load);
	  if (!load)
	    setup (operand);
	}
    }
  if (!preserve_dest && !elementwise_reused_destination_p (operands, scalar))
    setup (0);
}

const char *
output_elementwise_state (rtx *operands, bool scalar)
{
  prepare_elementwise_state (operands, scalar, false, UINTVAL (operands[11]));
  static const char *const templates[] = {
    "msll.ew\t%0,%1,%2", "msll.ew.x\t%0,%z2,%1",
    "msrl.ew\t%0,%1,%2", "msrl.ew.x\t%0,%z2,%1",
    "msra.ew\t%0,%1,%2", "msra.ew.x\t%0,%z2,%1",
    "mmul.ew\t%0,%1,%2",
    "madd.ew\t%0,%1,%2", "msub.ew\t%0,%1,%2",
    "mabsdiff.ew\t%0,%1,%2", "mhdiff.ew\t%0,%1,%2",
    "mmean.ew\t%0,%1,%2", "mmulneg.ew\t%0,%1,%2",
    "madd.ew.x\t%0,%z2,%1", "msub.ew.x\t%0,%z2,%1",
    "mabsdiff.ew.x\t%0,%z2,%1", "mhdiff.ew.x\t%0,%z2,%1",
    "mmean.ew.x\t%0,%z2,%1", "mmul.ew.x\t%0,%z2,%1",
    "mmulneg.ew.x\t%0,%z2,%1", "mmin.ew.x\t%0,%z2,%1",
    "mmax.ew.x\t%0,%z2,%1",
    "mand.ew.x\t%0,%z2,%1", "mandnot.ew.x\t%0,%z2,%1",
    "mor.ew.x\t%0,%z2,%1", "mornot.ew.x\t%0,%z2,%1",
    "mxor.ew.x\t%0,%z2,%1",
    "mcmpge.ew\t%0,%1,%2", "mcmplt.ew\t%0,%1,%2",
    "mcmpge.ew.x\t%0,%z2,%1", "mcmplt.ew.x\t%0,%z2,%1",
    "mselge.ew\t%0,%1,%2", "msellt.ew\t%0,%1,%2",
    "mmin.ew\t%0,%1,%2", "mmax.ew\t%0,%1,%2",
    "mldexp.ew\t%0,%1,%2", "mrdexp.ew\t%0,%1,%2",
    "mlog2sub.ew\t%0,%1,%2", "msublog2.ew\t%0,%1,%2",
    "mlog2sub.ew.x\t%0,%z2,%1", "msublog2.ew.x\t%0,%z2,%1",
    "mldexp.ew.x\t%0,%z2,%1"
  };
  unsigned int variant = UINTVAL (operands[8]);
  gcc_assert (variant < ARRAY_SIZE (templates)
	      && scalar == ((variant < 6 && (variant % 2) != 0)
			    || data_scalar_variant_p (variant) || variant == 41));
  if (data_scalar_variant_p (variant) && operands[5] != const0_rtx)
    output_asm_insn ("csrw\tamestype,%5", operands);
  output_asm_insn (templates[variant], operands);
  return "";
}

static unsigned int
elementwise_base_length (rtx *operands, bool scalar, bool preserve_dest,
			 unsigned int prepared)
{
  unsigned int length = 1 + (data_scalar_variant_p (UINTVAL (operands[8]))
			    && operands[5] != const0_rtx);
  unsigned int steps = UINTVAL (operands[9]);
  unsigned int count
    = scalar || elementwise_shared_source_p (operands, scalar) ? 2 : 3;
  for (unsigned int i = 0; i < count; ++i)
    {
      if (prepared & (1U << i))
	continue;
      unsigned int r = m_nregs (GET_MODE (operands[i]));
      unsigned int group = datatype_step (steps, i);
      if (i || preserve_dest
	  || !elementwise_reused_destination_p (operands, scalar))
	length += r / group;
      if (i || preserve_dest)
	length += r == 1 ? 2 : 4 * r;
    }
  return 4 * length;
}

unsigned int
elementwise_length (rtx *operands, bool scalar)
{
  return elementwise_base_length (operands, scalar, false,
				  UINTVAL (operands[11]));
}

/* Scatter must preserve the
   tied old destination across settyp as well as both immutable sources.  */
const char *
output_indexed_state (rtx *operands)
{
  static const char *const templates[] = {
    "mcolgather.ew\t%0,%1,%2", "mrowgather.ew\t%0,%1,%2",
    "mcolscatadd.ew\t%0,%1,%2", "mrowscatadd.ew\t%0,%1,%2",
    "mcolscatmax.ew\t%0,%1,%2", "mrowscatmax.ew\t%0,%1,%2"
  };
  unsigned int variant = UINTVAL (operands[8]);
  gcc_assert (variant < ARRAY_SIZE (templates));
  prepare_elementwise_state (operands, false, variant >= 2,
			     UINTVAL (operands[variant >= 2 ? 12 : 11]));
  output_asm_insn (templates[variant], operands);
  return "";
}

unsigned int
indexed_length (rtx *operands)
{
  bool old_dest = UINTVAL (operands[8]) >= 2;
  return elementwise_base_length (operands, false, old_dest,
				  UINTVAL (operands[old_dest ? 12 : 11]));
}

/* The tied destination
   must survive destructive datatype setup along with both explicit sources.  */
const char *
output_ternary_state (rtx *operands)
{
  static const char *const templates[] = {
    "mmulacc.ew\t%0,%1,%2", "mmulaccneg.ew\t%0,%1,%2",
    "mmuladd.ew\t%0,%1,%2", "mmulsub.ew\t%0,%1,%2",
    "mcmovge.ew\t%0,%1,%2", "mcmovlt.ew\t%0,%1,%2",
    "mldexpacc.ew\t%0,%1,%2", "mrdexpacc.ew\t%0,%1,%2"
  };
  unsigned int variant = UINTVAL (operands[8]);
  gcc_assert (variant < ARRAY_SIZE (templates));
  prepare_elementwise_state (operands, false, true, UINTVAL (operands[12]));
  output_asm_insn (templates[variant], operands);
  return "";
}

unsigned int
ternary_length (rtx *operands)
{
  return elementwise_base_length (operands, false, true,
				  UINTVAL (operands[12]));
}

/* Preserve D and B before
   destructive Md setup, then set TC immediately before the scalar core.  */
const char *
output_scalar_ternary_state (rtx *operands)
{
  static const char *const templates[] = {
    "mmulacc.ew.x\t%0,%z2,%1", "mmulaccneg.ew.x\t%0,%z2,%1",
    "mmuladd.ew.x\t%0,%z2,%1", "mmulsub.ew.x\t%0,%z2,%1",
    "mldexpacc.ew.x\t%0,%z2,%1"
  };
  unsigned int variant = UINTVAL (operands[8]);
  gcc_assert (variant < ARRAY_SIZE (templates));
  prepare_elementwise_state (operands, true, true, UINTVAL (operands[12]));
  if (variant < 4 && operands[5] != const0_rtx)
    output_asm_insn ("csrw\tamestype,%5", operands);
  output_asm_insn (templates[variant], operands);
  return "";
}

unsigned int
scalar_ternary_length (rtx *operands)
{
  gcc_assert (UINTVAL (operands[8]) <= 4);
  return elementwise_base_length (operands, true, true,
				  UINTVAL (operands[12]))
    + 4 * (UINTVAL (operands[8]) < 4 && operands[5] != const0_rtx);
}

static bool
common_old_dest_p (int code)
{
  return code == UNSPECV_ZTT_STATE_TERNARY
    || code == UNSPECV_ZTT_STATE_TERNARY_X
    || code == UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE
    || code == UNSPECV_ZTT_STATE_SCATTER;
}

static bool
common_scalar_p (int code)
{
  return code == UNSPECV_ZTT_STATE_ELEMENTWISE_X
    || code == UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE
    || code == UNSPECV_ZTT_STATE_TERNARY_X
    || code == UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE;
}

static bool
common_data_scalar_p (rtx src, bool prepared)
{
  int code = XINT (src, 1);
  if (!common_scalar_p (code))
    return false;
  unsigned int variant = UINTVAL (XVECEXP (src, 0, prepared ? 5 : 6));
  return common_old_dest_p (code) ? variant < 4
    : data_scalar_variant_p (variant);
}

/* Destination setup must not destroy a partially overlapping source.  */
bool
common_prepared_operands_p (rtx *operands, bool scalar)
{
  if (!reload_completed || !REG_P (operands[0])
      || !M_REG_P (REGNO (operands[0])))
    return false;
  unsigned int steps = UINTVAL (operands[7]);
  for (unsigned int i = 1; i <= (scalar ? 1U : 2U); ++i)
    if (reg_overlap_mentioned_p (operands[0], operands[i])
	&& (!rtx_equal_p (operands[0], operands[i])
	    || !rtx_equal_p (operands[3], operands[3 + i])
	    || !datatype_step (steps, 0)
	    || datatype_step (steps, 0) != datatype_step (steps, i)))
      return false;
  return true;
}

static void
unpack_common_prepared (rtx *operands, rtx *full, int code)
{
  for (unsigned int i = 0; i < 6; ++i)
    full[i] = operands[i];
  full[8] = operands[6];
  full[9] = operands[7];
  bool old_dest = common_old_dest_p (code);
  if (old_dest)
    full[11] = operands[8];
  full[old_dest ? 12 : 11]
    = GEN_INT ((common_scalar_p (code) ? 2 : 6) | (old_dest ? 1 : 0));
}

const char *
output_common_prepared (rtx *operands, int code)
{
  rtx full[13] = {};
  unpack_common_prepared (operands, full, code);
  switch (code)
    {
    case UNSPECV_ZTT_STATE_ELEMENTWISE_M:
    case UNSPECV_ZTT_STATE_ELEMENTWISE_X:
      return output_elementwise_state (full, common_scalar_p (code));
    case UNSPECV_ZTT_STATE_GATHER:
    case UNSPECV_ZTT_STATE_SCATTER:
      return output_indexed_state (full);
    case UNSPECV_ZTT_STATE_TERNARY:
      return output_ternary_state (full);
    case UNSPECV_ZTT_STATE_TERNARY_X:
      return output_scalar_ternary_state (full);
    default:
      gcc_unreachable ();
    }
}

unsigned int
common_prepared_length (rtx *operands, int code)
{
  rtx full[13] = {};
  unpack_common_prepared (operands, full, code);
  switch (code)
    {
    case UNSPECV_ZTT_STATE_ELEMENTWISE_M:
    case UNSPECV_ZTT_STATE_ELEMENTWISE_X:
      return elementwise_length (full, common_scalar_p (code));
    case UNSPECV_ZTT_STATE_GATHER:
    case UNSPECV_ZTT_STATE_SCATTER:
      return indexed_length (full);
    case UNSPECV_ZTT_STATE_TERNARY:
      return ternary_length (full);
    case UNSPECV_ZTT_STATE_TERNARY_X:
      return scalar_ternary_length (full);
    default:
      gcc_unreachable ();
    }
}

/* Both tied operands retain
   their full old payload across destructive datatype preparation.  */
const char *
output_zip_state (rtx *operands, bool prepared)
{
  static const char *const templates[] = {
    "mcolzip.ew\t%0,%1", "mrowzip.ew\t%0,%1",
    "mcolunzip.ew\t%0,%1", "mrowunzip.ew\t%0,%1"
  };
  unsigned int variant = UINTVAL (operands[5]);
  gcc_assert (variant < ARRAY_SIZE (templates));
  if (!prepared)
    {
      rtx base = XEXP (operands[6], 0);
      bool group = m_nregs (GET_MODE (operands[0])) > 1;
      for (unsigned int i = 0; i < 2; ++i)
	for (bool load : { false, true })
	  {
	    if (group)
	      {
		rtx args[] = { operands[8], base };
		output_asm_insn ("mv\t%0,%1", args);
	      }
	    output_acc_m_transfer (operands[i], group ? operands[8] : base,
				   operands[7], load);
	    if (!load)
	      {
		rtx args[] = { operands[i], operands[4] };
		output_asm_insn ("msettyp\t%0,%1", args);
	      }
	  }
    }
  output_asm_insn (templates[variant], operands);
  return "";
}

unsigned int
zip_length (rtx *operands)
{
  unsigned int r = m_nregs (GET_MODE (operands[0]));
  return 4 * (1 + 2 * (r == 1 ? 3 : 4 * r + 1));
}

/* Only split the single allocation unit once hard registers are known.
   Reuse the established per-square state envelope without changing it.  */
const char *
output_zip_value_state (rtx *operands, bool prepared)
{
  unsigned int r = m_nregs (GET_MODE (operands[0])) / 2;
  unsigned int regno = REGNO (operands[0]);
  gcc_assert (r && M_REG_P (regno)
	      && (regno - M_REG_FIRST) % (2 * r) == 0
	      && regno + 2 * r <= M_REG_FIRST + active_profile ()->mregs);
  machine_mode mode = matrix_mode (r);
  rtx a = gen_rtx_REG (mode, regno);
  rtx b = gen_rtx_REG (mode, regno + r);
  rtx parts[] = { a, b, a, b, prepared ? NULL_RTX : operands[2],
		  operands[prepared ? 2 : 3],
		  prepared ? NULL_RTX : operands[4],
		  prepared ? NULL_RTX : operands[5],
		  prepared ? NULL_RTX : operands[6] };
  return output_zip_state (parts, prepared);
}

unsigned int
zip_value_length (rtx *operands)
{
  unsigned int r = m_nregs (GET_MODE (operands[0])) / 2;
  return 4 * (1 + 2 * (r == 1 ? 3 : 4 * r + 1));
}

/* A complete same-Md
   source has already prepared the destination without losing its payload.  */
static bool
unary_reused_destination_p (rtx *operands, bool prepared = false)
{
  unsigned int steps = UINTVAL (operands[prepared ? 4 : 6]);
  return reload_completed && REG_P (operands[0])
    && M_REG_P (REGNO (operands[0]))
    && rtx_equal_p (operands[0], operands[1])
    && operands[2] && REG_P (operands[2])
    && GP_REG_P (REGNO (operands[2]))
    && rtx_equal_p (operands[2], operands[3])
    && datatype_step (steps, 0)
    && datatype_step (steps, 0) == datatype_step (steps, 1);
}

/* Source preparation preserves every member.  Disjoint destinations still
   need setup; a reused destination must not clear the restored source.  */
static void
prepare_unary_state (rtx *operands, bool prepared)
{
  unsigned int steps = UINTVAL (operands[prepared ? 4 : 6]);
  auto setup = [&] (unsigned int i)
    {
      unsigned int step = datatype_step (steps, i);
      unsigned int nregs = m_nregs (GET_MODE (operands[i]));
      gcc_assert (step && nregs % step == 0);
      for (unsigned int r = 0; r < nregs; r += step)
	{
	  rtx args[] = { gen_rtx_REG (matrix_mode (step), REGNO (operands[i]) + r),
			 operands[2 + i] };
	  output_asm_insn ("msettyp\t%0,%1", args);
	}
    };
  if (!prepared)
    {
      rtx base = XEXP (operands[4], 0);
      bool group = m_nregs (GET_MODE (operands[1])) > 1;
      for (bool load : { false, true })
	{
	  if (group)
	    {
	      rtx args[] = { operands[7], base };
	      output_asm_insn ("mv\t%0,%1", args);
	    }
	  output_acc_m_transfer (operands[1], group ? operands[7] : base,
				 operands[5], load);
	  if (!load)
	    setup (1);
	}
    }
  if (!unary_reused_destination_p (operands, prepared))
    setup (0);
}

const char *
output_conversion_state (rtx *operands, bool prepared)
{
  prepare_unary_state (operands, prepared);
  output_asm_insn ("mconv.ew\t%0,%1", operands);
  return "";
}

/* The instruction applies
   independently to each logical Square in the formed register operands.  */
const char *
output_structural_state (rtx *operands, bool prepared)
{
  static const char * const mnemonics[] = {
    "mreduceadd.col\t%0,%1", "mreduceadd.row\t%0,%1",
    "mreducemax.col\t%0,%1", "mreducemax.row\t%0,%1",
    "mreducemin.col\t%0,%1", "mreducemin.row\t%0,%1",
    "mprefixadd.col\t%0,%1", "mprefixadd.row\t%0,%1",
    "mprefixmax.col\t%0,%1", "mprefixmax.row\t%0,%1",
    "mabs.ew\t%0,%1",
#define ZTT_FP_UNARY(OP, NAME, INSN) INSN "\t%0,%1",
#include "riscv-ztt-operations.def"
#undef ZTT_FP_UNARY
  };
  unsigned int variant = UINTVAL (operands[prepared ? 5 : 8]);
  gcc_assert (variant < ARRAY_SIZE (mnemonics));
  prepare_unary_state (operands, prepared);
  output_asm_insn (mnemonics[variant], operands);
  return "";
}

unsigned int
conversion_length (rtx *operands, bool prepared)
{
  unsigned int steps = UINTVAL (operands[prepared ? 4 : 6]);
  unsigned int dst = m_nregs (GET_MODE (operands[0]));
  unsigned int src = m_nregs (GET_MODE (operands[1]));
  return 4 * (1 + (unary_reused_destination_p (operands, prepared)
		  ? 0 : dst / datatype_step (steps, 0))
	      + (prepared ? 0 : src / datatype_step (steps, 1)
		 + (src == 1 ? 2 : 4 * src)));
}

static bool
rowcol_reused_destination_p (rtx *operands)
{
  return reload_completed && REG_P (operands[0])
    && M_REG_P (REGNO (operands[0]))
    && rtx_equal_p (operands[0], operands[1]);
}

/* One owned basic Square,
   including wide M groups.  Preserve the source across destructive Md setup.  */
const char *
output_rowcol_state (rtx *operands, bool prepared)
{
  if (!prepared)
    {
      rtx base = XEXP (operands[4], 0);
      bool group = m_nregs (GET_MODE (operands[1])) > 1;
      for (bool load : { false, true })
	{
	  if (group)
	    {
	      rtx args[] = { operands[7], base };
	      output_asm_insn ("mv\t%0,%1", args);
	    }
	  output_acc_m_transfer (operands[1], group ? operands[7] : base,
				 operands[5], load);
	  if (!load)
	    output_asm_insn ("msettyp\t%1,%3", operands);
	}
    }
  if (!rowcol_reused_destination_p (operands))
    output_asm_insn ("msettyp\t%0,%3", operands);
  static const char * const mnemonics[] = {
    "mcolbcast.ew.x\t%0,%z2,%1", "mrowbcast.ew.x\t%0,%z2,%1",
    "mcolshift.ew.x\t%0,%z2,%1", "mrowshift.ew.x\t%0,%z2,%1"
  };
  unsigned int variant = UINTVAL (operands[prepared ? 4 : 6]);
  gcc_assert (variant < ARRAY_SIZE (mnemonics));
  output_asm_insn (mnemonics[variant], operands);
  return "";
}

unsigned int
rowcol_length (rtx *operands, bool prepared)
{
  unsigned int nregs = m_nregs (GET_MODE (operands[0]));
  return 4 * (2 + (prepared ? 0 : (nregs == 1 ? 3 : 4 * nregs + 1))
	      - rowcol_reused_destination_p (operands));
}

/* The enclosing mode owns
   every ACC.  Only final output names individual physical members.  */
const char *
output_acc_clear (rtx *operands, bool zero_p)
{
  machine_mode mode = GET_MODE (operands[0]);
  for (unsigned int i = 0; i < acc_nregs (mode); ++i)
    {
      rtx args[] = { GEN_INT (REGNO (operands[0]) - ACC_REG_FIRST + i),
		     operands[1] };
      output_asm_insn ("asettyp\tacc%c0,%1", args);
      if (zero_p)
	output_asm_insn ("mzero.2d.acc\tacc%c0", args);
    }
  return "";
}

const char *
output_acc_to_m (rtx *operands)
{
  machine_mode mode = GET_MODE (operands[1]);
  unsigned int r = acc_m_nregs (mode);
  unsigned int packet = acc_transfer_accs (mode);
  for (unsigned int i = 0; i < acc_nregs (mode) / packet; ++i)
    {
      rtx args[] = { gen_rtx_REG (matrix_mode (r), REGNO (operands[0]) + i * r),
		     GEN_INT (REGNO (operands[1]) - ACC_REG_FIRST + i * packet),
		     operands[2] };
      output_asm_insn ("msettyp\t%0,%2", args);
      output_asm_insn ("mmov.m.a\t%0,acc%c1", args);
    }
  return "";
}

const char *
output_acc_from_m (rtx *operands)
{
  machine_mode mode = GET_MODE (operands[0]);
  unsigned int r = acc_m_nregs (mode);
  unsigned int packet = acc_transfer_accs (mode);
  for (unsigned int i = 0; i < acc_nregs (mode) / packet; ++i)
    {
      rtx args[] = { GEN_INT (REGNO (operands[0]) - ACC_REG_FIRST + i * packet),
		     gen_rtx_REG (matrix_mode (r), REGNO (operands[1]) + i * r),
		     operands[2] };
      for (unsigned int j = 0; j < packet; ++j)
	{
	  rtx member[] = { GEN_INT (INTVAL (args[0]) + j), operands[2] };
	  output_asm_insn ("asettyp\tacc%c0,%1", member);
	}
      output_asm_insn ("mmov.a.m\tacc%c0,%1", args);
    }
  return "";
}

static const char *
output_acc_tuple_move (rtx *operands)
{
  bool load_p = MEM_P (operands[1]);
  bool store_p = MEM_P (operands[0]);
  machine_mode mode = GET_MODE (operands[0]);
  machine_mode member = acc_mode (acc_m_nregs (mode) * active_profile ()->uds);
  unsigned int count = acc_nregs (mode);
  if (!load_p && !store_p)
    {
      for (unsigned int i = 0; i < count; ++i)
	{
	  rtx args[] = { gen_rtx_REG (member, REGNO (operands[0]) + i),
			 gen_rtx_REG (member, REGNO (operands[1]) + i),
			 operands[2], operands[3] };
	  output_asm_insn ("agettyp\t%3,%1", args);
	  output_asm_insn ("msettyp\t%2,%3", args);
	  output_asm_insn ("mmov.m.a\t%2,%1", args);
	  output_asm_insn ("asettyp\t%0,%3", args);
	  output_asm_insn ("mmov.a.m\t%0,%2", args);
	}
      return "";
    }

  rtx address = operands[4];
  rtx stride = operands[5];
  rtx setup[] = { address, XEXP (operands[load_p ? 1 : 0], 0), stride,
		  gen_rtx_REG (Pmode, RISCV_ZTT_SCALE_REGNUM) };
  output_asm_insn ("mv\t%0,%1", setup);
  output_asm_insn ("slli\t%2,%3,4", setup);
  for (unsigned int i = 0; i < count; ++i)
    {
      rtx args[] = { gen_rtx_REG (member, REGNO (operands[load_p ? 0 : 1]) + i),
		     operands[2], operands[3], address, stride };
      if (load_p)
	output_asm_insn (TARGET_64BIT ? "lwu\t%2,0(%3)" : "lw\t%2,0(%3)", args);
      else
	{
	  output_asm_insn ("agettyp\t%2,%0", args);
	  output_asm_insn ("sw\t%2,0(%3)", args);
	}
      output_asm_insn ("addi\t%3,%3,16", args);
      output_asm_insn ("msettyp\t%1,%2", args);
      if (store_p)
	output_asm_insn ("mmov.m.a\t%1,%0", args);
      output_acc_m_transfer (operands[2], address, stride, load_p);
      if (load_p)
	{
	  output_asm_insn ("asettyp\t%0,%2", args);
	  output_asm_insn ("mmov.a.m\t%0,%1", args);
	}
      if (i + 1 < count)
	output_asm_insn ("add\t%3,%3,%4", args);
    }
  return "";
}

/* A packet stores one
   16-byte Ad header per physical ACC, followed by one raw M payload.
   Only the base Ad controls mmov; preserve the other actual Ads as well.
   No partial ACC RTL value is manufactured to name a physical member.  */
static const char *
output_acc_packed_move (rtx *operands)
{
  machine_mode mode = GET_MODE (operands[0]);
  unsigned int packet = acc_transfer_accs (mode);
  unsigned int count = acc_nregs (mode) / packet;
  bool load_p = MEM_P (operands[1]);
  bool store_p = MEM_P (operands[0]);
  if (!load_p && !store_p)
    {
      for (unsigned int i = 0; i < count; ++i)
	{
	  rtx args[] = {
	    GEN_INT (REGNO (operands[0]) - ACC_REG_FIRST + i * packet),
	    GEN_INT (REGNO (operands[1]) - ACC_REG_FIRST + i * packet),
	    operands[2], operands[3]
	  };
	  output_asm_insn ("agettyp\t%3,acc%c1", args);
	  output_asm_insn ("msettyp\t%2,%3", args);
	  output_asm_insn ("mmov.m.a\t%2,acc%c1", args);
	  output_asm_insn ("asettyp\tacc%c0,%3", args);
	  for (unsigned int j = 1; j < packet; ++j)
	    {
	      rtx member[] = { GEN_INT (INTVAL (args[0]) + j),
			       GEN_INT (INTVAL (args[1]) + j), operands[3] };
	      output_asm_insn ("agettyp\t%2,acc%c1", member);
	      output_asm_insn ("asettyp\tacc%c0,%2", member);
	    }
	  output_asm_insn ("mmov.a.m\tacc%c0,%2", args);
	}
      return "";
    }

  rtx setup[] = { operands[4], XEXP (operands[load_p ? 1 : 0], 0),
		  operands[5], gen_rtx_REG (Pmode, RISCV_ZTT_SCALE_REGNUM) };
  output_asm_insn ("mv\t%0,%1", setup);
  if (count > 1)
    output_asm_insn ("slli\t%2,%3,4", setup);
  for (unsigned int i = 0; i < count; ++i)
    {
      unsigned int base = REGNO (operands[load_p ? 0 : 1]) - ACC_REG_FIRST
			 + i * packet;
      /* Reverse order leaves the base Ad in the descriptor scratch.  */
      for (unsigned int j = packet; j-- > 0; )
	{
	  rtx member[] = { GEN_INT (base + j), operands[3], operands[4],
			   GEN_INT (16 * j) };
	  if (load_p)
	    {
	      output_asm_insn (TARGET_64BIT ? "lwu\t%1,%c3(%2)"
			      : "lw\t%1,%c3(%2)", member);
	      output_asm_insn ("asettyp\tacc%c0,%1", member);
	    }
	  else
	    {
	      output_asm_insn ("agettyp\t%1,acc%c0", member);
	      output_asm_insn ("sw\t%1,%c3(%2)", member);
	    }
	}
      rtx args[] = { GEN_INT (base), operands[2], operands[3], operands[4],
		     GEN_INT (16 * packet), operands[5] };
      output_asm_insn ("msettyp\t%1,%2", args);
      if (store_p)
	output_asm_insn ("mmov.m.a\t%1,acc%c0", args);
      output_asm_insn ("addi\t%3,%3,%c4", args);
      output_asm_insn (load_p ? "mls.1r\t%1,%3" : "mss.1r\t%1,%3", args);
      if (load_p)
	output_asm_insn ("mmov.a.m\tacc%c0,%1", args);
      if (i + 1 < count)
	output_asm_insn ("add\t%3,%3,%5", args);
    }
  return "";
}

const char *
output_acc_move (rtx *operands)
{
  if (acc_transfer_accs (GET_MODE (operands[0])) > 1)
    return output_acc_packed_move (operands);
  if (acc_nregs (GET_MODE (operands[0])) > 1)
    return output_acc_tuple_move (operands);
  bool load_p = MEM_P (operands[1]);
  bool store_p = MEM_P (operands[0]);
  if (!load_p && !store_p)
    {
      output_asm_insn ("agettyp\t%3,%1", operands);
      output_asm_insn ("msettyp\t%2,%3", operands);
      output_asm_insn ("mmov.m.a\t%2,%1", operands);
      output_asm_insn ("asettyp\t%0,%3", operands);
      output_asm_insn ("mmov.a.m\t%0,%2", operands);
      return "";
    }

  if (load_p)
    output_asm_insn (TARGET_64BIT ? "lwu\t%3,0(%q1)" : "lw\t%3,0(%q1)",
		     operands);
  else
    {
      output_asm_insn ("agettyp\t%3,%1", operands);
      output_asm_insn ("sw\t%3,0(%q0)", operands);
    }
  output_asm_insn (load_p ? "addi\t%4,%q1,16" : "addi\t%4,%q0,16",
		   operands);
  if (m_nregs (GET_MODE (operands[2])) > 1)
    {
      rtx args[] = { operands[5],
		     gen_rtx_REG (Pmode, RISCV_ZTT_SCALE_REGNUM) };
      output_asm_insn ("slli\t%0,%1,4", args);
    }
  output_asm_insn ("msettyp\t%2,%3", operands);
  if (store_p)
    output_asm_insn ("mmov.m.a\t%2,%1", operands);
  output_acc_m_transfer (operands[2], operands[4], operands[5], load_p);
  if (load_p)
    {
      output_asm_insn ("asettyp\t%0,%3", operands);
      output_asm_insn ("mmov.a.m\t%0,%2", operands);
    }
  return "";
}

/* An asm can need the entire M bank while an ACC input is reloaded.  Save
   all physical M payloads before borrowing m0; the required ACC datatype
   can span more than the first live M value.  Md is prepared at each typed
   use in these functions, just as it is across ordinary calls.  */
const char *
output_acc_borrowed_move (rtx *operands)
{
  if (REG_P (operands[0]) && REG_P (operands[1])
      && rtx_equal_p (operands[0], operands[1]))
    return "";
  gcc_assert (riscv_ztt_explicit_state_p ());
  machine_mode mode = GET_MODE (operands[0]);
  rtx bank = gen_rtx_REG (matrix_mode (active_profile ()->mregs), M_REG_FIRST);
  rtx args[] = { operands[4], XEXP (operands[2], 0), operands[5],
		 gen_rtx_REG (Pmode, RISCV_ZTT_SCALE_REGNUM) };
  output_asm_insn ("slli\t%2,%3,4", args);
  output_asm_insn ("mv\t%0,%1", args);
  output_acc_m_transfer (bank, operands[4], operands[5], false);

  rtx move[] = { operands[0], operands[1],
		 gen_rtx_REG (matrix_mode (acc_m_nregs (mode)), M_REG_FIRST),
		 operands[3], operands[4], operands[5] };
  output_acc_move (move);

  output_asm_insn ("mv\t%0,%1", args);
  output_acc_m_transfer (bank, operands[4], operands[5], true);
  return "";
}

unsigned int
acc_borrowed_move_length (rtx *operands)
{
  bool memory = MEM_P (operands[0]) || MEM_P (operands[1]);
  if (!memory && reload_completed && rtx_equal_p (operands[0], operands[1]))
    return 0;
  machine_mode mode = GET_MODE (operands[0]);
  unsigned int regs = acc_nregs (mode);
  unsigned int packet = acc_transfer_accs (mode);
  unsigned int r = acc_m_nregs (mode);
  unsigned int count = regs / packet;
  unsigned int core;
  if (!memory)
    core = count * (2 * packet + 3);
  else if (packet > 1)
    core = count * (2 * packet + 5) + (count > 1);
  else if (regs > 1)
    core = 1 + regs * (2 * r + 5);
  else
    core = 2 * r + 4 + (r > 1);
  return 4 * (core + 4 * active_profile ()->mregs + 1);
}
/* Reuse requires identical complete hard-register groups and Md.  */
static bool
acc_shared_source_p (rtx *operands, bool mixed_p)
{
  return reload_completed
    && REG_P (operands[2]) && M_REG_P (REGNO (operands[2]))
    && rtx_equal_p (operands[2], operands[3])
    && REG_P (operands[4]) && GP_REG_P (REGNO (operands[4]))
    && (!mixed_p || rtx_equal_p (operands[4], operands[8]));
}

#if CHECKING_P
static void
run_acc_shared_source_selftests ()
{
  using namespace selftest;
  int saved_reload_completed = reload_completed;
  rtx operands[11] = {};
  operands[2] = operands[3] = gen_rtx_REG (ZTTMR2mode, M_REG_FIRST);
  operands[4] = gen_rtx_REG (SImode, 10);
  operands[8] = operands[9] = const0_rtx;
  reload_completed = 0;
  ASSERT_FALSE (acc_shared_source_p (operands, false));
  ASSERT_EQ (acc_mmul_length (operands, false), 76U);
  reload_completed = 1;
  operands[8] = operands[4];
  ASSERT_TRUE (acc_shared_source_p (operands, false));
  ASSERT_TRUE (acc_shared_source_p (operands, true));
  ASSERT_EQ (acc_mmul_length (operands, true), 40U);
  operands[8] = gen_rtx_REG (SImode, 11);
  ASSERT_FALSE (acc_shared_source_p (operands, true));
  ASSERT_EQ (acc_mmul_length (operands, true), 76U);
  operands[8] = operands[4];
  operands[3] = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
  ASSERT_FALSE (acc_shared_source_p (operands, true));
  operands[3] = gen_rtx_REG (ZTTMR2mode, M_REG_FIRST + 1);
  ASSERT_FALSE (acc_shared_source_p (operands, true));
  operands[2] = operands[3] = gen_rtx_REG (ZTTMR2mode, FIRST_PSEUDO_REGISTER);
  ASSERT_FALSE (acc_shared_source_p (operands, true));
  operands[2] = operands[3] = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
  ASSERT_EQ (acc_mmul_length (operands, true), 16U);
  operands[4] = operands[8] = gen_rtx_REG (SImode, FIRST_PSEUDO_REGISTER);
  ASSERT_FALSE (acc_shared_source_p (operands, true));
  operands[2] = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
  operands[3] = gen_rtx_REG (ZTTMR2mode, M_REG_FIRST + 2);
  operands[4] = const0_rtx;
  operands[8] = gen_rtx_REG (SImode, 10);
  operands[9] = const1_rtx;
  ASSERT_EQ (acc_mmul_length (operands, true), 40U);
  operands[4] = operands[8];
  operands[8] = const0_rtx;
  operands[9] = GEN_INT (2);
  ASSERT_EQ (acc_mmul_length (operands, true), 16U);
  reload_completed = saved_reload_completed;
}
#endif

const char *
acc_mmul_template (unsigned int variant)
{
  static const char *const templates[] = {
    "mmulacc.2d\t%0,%2,%3", "mmulaccneg.2d\t%0,%2,%3",
    "mmulatacc.2d\t%0,%2,%3", "mmulataccneg.2d\t%0,%2,%3",
    "mmulbtacc.2d\t%0,%2,%3", "mmulbtaccneg.2d\t%0,%2,%3"
  };
  gcc_assert (variant < ARRAY_SIZE (templates));
  return templates[variant];
}

/* Private MEM preserves the M group across msettyp; reused sources still
   require destination Ad setup.  */
const char *
output_acc_state (rtx *operands, bool mul_p, bool mixed_p)
{
  machine_mode mode = GET_MODE (operands[0]);
  unsigned int packet = acc_transfer_accs (mode);
  unsigned int count = mul_p ? 1 : acc_nregs (mode) / packet;
  unsigned int r = acc_m_nregs (mode);
  rtx source = operands[mul_p ? 2 : 1];
  rtx descriptor = operands[mul_p ? 4 : 2];
  rtx base = XEXP (operands[mul_p ? 5 : 3], 0);
  rtx stride = operands[mul_p ? 6 : 4];
  rtx address = operands[mul_p ? (mixed_p ? 10 : 9) : 6];
  unsigned int prepared = UINTVAL (operands[mul_p ? (mixed_p ? 9 : 8) : 5]);
  gcc_assert (mul_p || !prepared
	      || (prepared == 1 && acc_nregs (mode) == 1));
  auto transfer = [&] (rtx group, bool load_p)
    {
      bool group_p = m_nregs (GET_MODE (group)) > 1;
      if (group_p)
	{
	  rtx args[] = { address, base };
	  output_asm_insn ("mv\t%0,%1", args);
	}
      output_acc_m_transfer (group, group_p ? address : base, stride, load_p);
    };
  auto preserve = [&] (rtx group, rtx group_descriptor)
    {
      transfer (group, false);
      unsigned int group_r = mul_p ? m_nregs (GET_MODE (group)) : r;
      for (unsigned int i = 0; i < count; ++i)
	{
	  rtx args[] = { gen_rtx_REG (matrix_mode (group_r),
				     REGNO (group) + i * group_r),
			 group_descriptor };
	  output_asm_insn ("msettyp\t%0,%1", args);
	}
      transfer (group, true);
    };
  if (!(prepared & 1))
    preserve (source, descriptor);
  if (mul_p)
    {
      if (!(prepared & 2) && !acc_shared_source_p (operands, mixed_p))
	preserve (operands[3], mixed_p ? operands[8] : descriptor);
      output_asm_insn (acc_mmul_template (UINTVAL (operands[7])), operands);
    }
  else
    return output_acc_from_m (operands);
  return "";
}

unsigned int
acc_mmul_length (rtx *operands, bool mixed_p)
{
  unsigned int length = 1;
  unsigned int prepared = UINTVAL (operands[mixed_p ? 9 : 8]);
  unsigned int last = acc_shared_source_p (operands, mixed_p) ? 2 : 3;
  for (unsigned int i = 2; i <= last; ++i)
    {
      if (prepared & (1U << (i - 2)))
	continue;
      unsigned int r = m_nregs (GET_MODE (operands[i]));
      length += r == 1 ? 3 : 4 * r + 1;
    }
  return 4 * length;
}

/* In a mixed-RM or non-i8 function, a reload may leave arbitrary Md on a register.
   Keep each setup/preserve/operation sequence indivisible until output.
   The private slot has the real M size and is reused by these sequences.  */
static unsigned int
lower_explicit_state ()
{
  bool matrix_state = riscv_ztt_explicit_state_p ();
  rtx state_slots[6] = {};
  for (rtx_insn *insn = get_insns (); insn; )
    {
      rtx_insn *next = NEXT_INSN (insn);
      if (CALL_P (insn))
	{
	  /* IPA summaries may cover only part of the physical bank.  */
	  const profile_info *profile = active_profile ();
	  for (unsigned int i = 0; i < profile->mregs; ++i)
	    clobber_reg (&CALL_INSN_FUNCTION_USAGE (insn),
			 gen_rtx_REG (SImode, M_REG_FIRST + i));
	  for (unsigned int i = 0; i < profile->accregs; ++i)
	    clobber_reg (&CALL_INSN_FUNCTION_USAGE (insn),
			 gen_rtx_REG (SImode, ACC_REG_FIRST + i));
	  df_insn_rescan (insn);
	  if (dump_file)
	    fprintf (dump_file, "Ztt call clobbers at insn %d\n", INSN_UID (insn));
	}
      rtx value_set = NONDEBUG_INSN_P (insn) ? single_set (insn) : NULL_RTX;
      if (value_set && GET_CODE (SET_SRC (value_set)) == UNSPEC
	  && XINT (SET_SRC (value_set), 1) == UNSPEC_ZTT_ZIP_VALUE)
	{
	  rtx src = SET_SRC (value_set);
	  machine_mode mode = GET_MODE (SET_DEST (value_set));
	  unsigned int r = m_nregs (mode) / 2;
	  machine_mode part_mode = matrix_mode (r);
	  start_sequence ();
	  rtx descriptor = force_reg (Pmode, XVECEXP (src, 0, 2));
	  rtx stride = r == 1 ? const0_rtx
	    : force_reg (Pmode, gen_int_mode (GET_MODE_SIZE (matrix_mode ()), Pmode));
	  rtx &slot = state_slots[exact_log2 (r)];
	  if (!slot)
	    slot = assign_stack_local (part_mode, GET_MODE_SIZE (part_mode), 0);
	  rtx address = force_reg (Pmode, XEXP (slot, 0));
	  rtx scratch = replace_equiv_address (slot, address);
	  emit_insn (gen_ztt_state_zip_value
	    (mode, Pmode, SET_DEST (value_set), XVECEXP (src, 0, 0), descriptor,
	     XVECEXP (src, 0, 1), scratch, stride));
	  rtx_insn *sequence = get_insns ();
	  end_sequence ();
	  emit_insn_before (sequence, insn);
	  delete_insn (insn);
	  insn = next;
	  continue;
	}
      /* Zip owns two results; single_set must not discard either one.  */
      rtx pattern = NONDEBUG_INSN_P (insn) ? PATTERN (insn) : NULL_RTX;
      if (pattern && GET_CODE (pattern) == PARALLEL
	  && XVECLEN (pattern, 0) == 2
	  && GET_CODE (XVECEXP (pattern, 0, 0)) == SET
	  && GET_CODE (SET_SRC (XVECEXP (pattern, 0, 0))) == UNSPEC
	  && XINT (SET_SRC (XVECEXP (pattern, 0, 0)), 1) == UNSPEC_ZTT_ZIP_A)
	{
	  rtx a = XVECEXP (pattern, 0, 0), b = XVECEXP (pattern, 0, 1);
	  rtx src = SET_SRC (a);
	  gcc_assert (GET_CODE (b) == SET && GET_CODE (SET_SRC (b)) == UNSPEC
		      && XINT (SET_SRC (b), 1) == UNSPEC_ZTT_ZIP_B);
	  machine_mode mode = GET_MODE (SET_DEST (a));
	  unsigned int nregs = m_nregs (mode);
	  start_sequence ();
	  rtx descriptor = force_reg (Pmode, XVECEXP (src, 0, 3));
	  rtx stride = nregs == 1 ? const0_rtx
	    : force_reg (Pmode, gen_int_mode (GET_MODE_SIZE (matrix_mode ()), Pmode));
	  rtx &slot = state_slots[exact_log2 (nregs)];
	  if (!slot)
	    slot = assign_stack_local (mode, GET_MODE_SIZE (mode), 0);
	  rtx address = force_reg (Pmode, XEXP (slot, 0));
	  rtx scratch = replace_equiv_address (slot, address);
	  emit_insn (gen_ztt_state_zip
		     (mode, Pmode, SET_DEST (a), SET_DEST (b),
		      XVECEXP (src, 0, 0), XVECEXP (src, 0, 1), descriptor,
		      XVECEXP (src, 0, 2), scratch, stride));
	  rtx_insn *sequence = get_insns ();
	  end_sequence ();
	  emit_insn_before (sequence, insn);
	  delete_insn (insn);
	  insn = next;
	  continue;
	}
      rtx set = value_set;
      /* Earlier copies may have been recognized before expansion discovered
	 another datatype.  Select the raw-copy code for the final policy.  */
      if (matrix_state && set && m_mode_p (GET_MODE (SET_DEST (set))))
	INSN_CODE (insn) = -1;
      bool rowcol_p = (set && GET_CODE (SET_SRC (set)) == UNSPEC_VOLATILE
		       && XINT (SET_SRC (set), 1) == UNSPECV_ZTT_ROWCOL);
      int flags_code = -1;
      if (set && GET_CODE (SET_SRC (set)) == UNSPEC_VOLATILE)
	switch (XINT (SET_SRC (set), 1))
	  {
	  case UNSPECV_ZTT_CONVERT_FLAGS: flags_code = UNSPEC_ZTT_CONVERT; break;
	  case UNSPECV_ZTT_STRUCTURAL_FLAGS: flags_code = UNSPEC_ZTT_STRUCTURAL; break;
	  case UNSPECV_ZTT_ELEMENTWISE_M_FLAGS: flags_code = UNSPEC_ZTT_ELEMENTWISE_M; break;
	  case UNSPECV_ZTT_ELEMENTWISE_X_FLAGS: flags_code = UNSPEC_ZTT_ELEMENTWISE_X; break;
	  case UNSPECV_ZTT_TERNARY_FLAGS: flags_code = UNSPEC_ZTT_TERNARY; break;
	  case UNSPECV_ZTT_GATHER_FLAGS: flags_code = UNSPEC_ZTT_GATHER; break;
	  case UNSPECV_ZTT_SCATTER_FLAGS: flags_code = UNSPEC_ZTT_SCATTER; break;
	  case UNSPECV_ZTT_ACC_MMUL_FLAGS: flags_code = UNSPEC_ZTT_ACC_MMUL; break;
	  case UNSPECV_ZTT_TERNARY_X_FLAGS: flags_code = UNSPEC_ZTT_TERNARY_X; break;
	  default: break;
	  }
      if (!set || (GET_CODE (SET_SRC (set)) != UNSPEC
		   && !rowcol_p && flags_code < 0))
	{
	  insn = next;
	  continue;
	}
      rtx src = SET_SRC (set);
      /* UNSPEC and UNSPEC_VOLATILE have separate code spaces.  */
      int code = flags_code >= 0 ? flags_code : rowcol_p ? -1 : XINT (src, 1);
      int binary_code = binary_state_unspec (code);
      bool elementwise_p = (code == UNSPEC_ZTT_ELEMENTWISE_M
			    || code == UNSPEC_ZTT_ELEMENTWISE_X
			    || code == UNSPEC_ZTT_TERNARY
			    || code == UNSPEC_ZTT_TERNARY_X);
      bool indexed_p = code == UNSPEC_ZTT_GATHER || code == UNSPEC_ZTT_SCATTER;
      bool structural_p = code == UNSPEC_ZTT_STRUCTURAL;
      bool unary_p = code == UNSPEC_ZTT_CONVERT || structural_p;
      bool memory_p = (code == UNSPEC_ZTT_MEMORY_LOAD
		       || code == UNSPEC_ZTT_MEMORY_STORE);
      /* ACC preparation is needed even when all M values use the single
	 i8/RM prologue policy.  Do not expand that policy's M operations.  */
      if (!matrix_state && !elementwise_p && !indexed_p && !unary_p && !rowcol_p
	  && !memory_p
	  && code != UNSPEC_ZTT_ACC_FROM_M
	  && code != UNSPEC_ZTT_ACC_MMUL)
	{
	  insn = next;
	  continue;
	}
      if (code != UNSPEC_ZTT_MZERO_2D_M && code != UNSPEC_ZTT_MLS_RM
	  && code != UNSPEC_ZTT_MSS_RM && binary_code < 0 && !elementwise_p
	  && !indexed_p && !unary_p && !rowcol_p
	  && !memory_p
	  && code != UNSPEC_ZTT_ACC_FROM_M && code != UNSPEC_ZTT_ACC_MMUL)
	{
	  insn = next;
	  continue;
	}

      machine_mode mode = GET_MODE (SET_DEST (set));
      if (code == UNSPEC_ZTT_MEMORY_STORE)
	mode = GET_MODE (XVECEXP (src, 0, 0));
      /* Slot size follows the formed M operand, not the ACC output count.
	 Matmul reads one window; m2a reads the complete M group.  */
      unsigned int nregs = acc_mode_p (mode)
	? m_nregs (GET_MODE (XVECEXP (src, 0, code == UNSPEC_ZTT_ACC_FROM_M ? 0 : 1)))
	: m_nregs (mode);
      bool mixed_mul = code == UNSPEC_ZTT_ACC_MMUL && XVECLEN (src, 0) == 7;
      if (mixed_mul)
	nregs = MAX (nregs, m_nregs (GET_MODE (XVECEXP (src, 0, 2))));
      if (elementwise_p || indexed_p || unary_p)
	{
	  nregs = m_nregs (GET_MODE (XVECEXP (src, 0, 0)));
	  if (code == UNSPEC_ZTT_ELEMENTWISE_M || code == UNSPEC_ZTT_TERNARY
	      || indexed_p)
	    nregs = MAX (nregs, m_nregs (GET_MODE (XVECEXP (src, 0, 1))));
	  if (code == UNSPEC_ZTT_SCATTER || code == UNSPEC_ZTT_TERNARY
	      || code == UNSPEC_ZTT_TERNARY_X)
	    nregs = MAX (nregs, m_nregs (mode));
	}
      /* The indivisible same-Md operation needs all distinct inputs resident
	 together even when its result can reuse a source.  Diagnose an
	 impossible input assignment before IRA rather than reaching an LRA ICE.
	 This checks the current RTL operands, not a datatype capability tuple.  */
      if (binary_code >= 0 && runtime_profile_p ()
	  && 2 * nregs > active_profile ()->mregs
	  && !rtx_equal_p (XVECEXP (src, 0, 0), XVECEXP (src, 0, 1)))
	{
	  error_at (INSN_LOCATION (insn),
		    "Ztt binary operation requires %u simultaneously allocated "
		    "M registers for distinct sources; profile provides %u",
		    2 * nregs, active_profile ()->mregs);
	  emit_insn_before (gen_rtx_CLOBBER (VOIDmode, SET_DEST (set)), insn);
	  delete_insn (insn);
	  insn = next;
	  continue;
	}
      if (code == UNSPEC_ZTT_ELEMENTWISE_M && runtime_profile_p ()
	  && nregs > 4)
	{
	  rtx lhs = XVECEXP (src, 0, 0), rhs = XVECEXP (src, 0, 1);
	  unsigned int inputs = m_nregs (GET_MODE (lhs));
	  if (!rtx_equal_p (lhs, rhs)
	      || !rtx_equal_p (XVECEXP (src, 0, 3), XVECEXP (src, 0, 4)))
	    inputs += m_nregs (GET_MODE (rhs));
	  if (inputs > active_profile ()->mregs)
	    {
	      error_at (INSN_LOCATION (insn),
			"Ztt elementwise operation requires %u simultaneously "
			"allocated M registers for distinct sources; "
			"profile provides %u", inputs, active_profile ()->mregs);
	      emit_insn_before (gen_rtx_CLOBBER (VOIDmode, SET_DEST (set)), insn);
	      delete_insn (insn);
	      insn = next;
	      continue;
	    }
	}
      /* Old-D and the matrix
	 source must coexist at a fixed-exponent core; spilling cannot make
	 an impossible simultaneous input assignment fit the physical bank.  */
      if (code == UNSPEC_ZTT_TERNARY_X
	  && UINTVAL (XVECEXP (src, 0, 2)) == 4 && runtime_profile_p ())
	{
	  rtx data = XVECEXP (src, 0, 0), old = XVECEXP (src, 0, 5);
	  unsigned int inputs = m_nregs (GET_MODE (data));
	  if (!rtx_equal_p (data, old)
	      || !rtx_equal_p (XVECEXP (src, 0, 3), XVECEXP (src, 0, 6)))
	    inputs += m_nregs (GET_MODE (old));
	  if (inputs > active_profile ()->mregs)
	    {
	      error_at (INSN_LOCATION (insn),
			"Ztt exponent operation requires %u simultaneously "
			"allocated M registers for distinct inputs; "
			"profile provides %u", inputs, active_profile ()->mregs);
	      emit_insn_before (gen_rtx_CLOBBER (VOIDmode, SET_DEST (set)), insn);
	      delete_insn (insn);
	      insn = next;
	      continue;
	    }
	}
      start_sequence ();
      rtx dtype = XVECEXP (src, 0, XVECLEN (src, 0) - 1);
      gcc_assert (CONST_INT_P (dtype));
      rtx descriptor = force_reg (Pmode, mixed_mul ? XVECEXP (src, 0, 4) : dtype);
      rtx scratch = NULL_RTX;
      rtx stride = NULL_RTX;
      if (nregs > 1)
	stride = force_reg (Pmode, gen_int_mode (GET_MODE_SIZE (matrix_mode ()),
					       Pmode));
      if (code == UNSPEC_ZTT_MSS_RM || binary_code >= 0 || elementwise_p
	  || code == UNSPEC_ZTT_MEMORY_STORE
	  || indexed_p || unary_p || rowcol_p
	  || code == UNSPEC_ZTT_ACC_FROM_M || code == UNSPEC_ZTT_ACC_MMUL)
	{
	  rtx &state_slot = state_slots[exact_log2 (nregs)];
	  if (!state_slot)
	    {
	      machine_mode slot_mode = matrix_mode (nregs);
	      state_slot = assign_stack_local (slot_mode,
					       GET_MODE_SIZE (slot_mode), 0);
	    }
	  rtx address = force_reg (Pmode, XEXP (state_slot, 0));
	  scratch = replace_equiv_address (state_slot, address);
	}
      rtx dest = SET_DEST (set);
      if (rowcol_p)
	emit_insn (gen_ztt_state_rowcol
		   (nregs > 4 ? UNSPECV_ZTT_STATE_ROWCOL_REUSE
			      : UNSPECV_ZTT_STATE_ROWCOL,
		    mode, Pmode, dest, XVECEXP (src, 0, 0),
		    XVECEXP (src, 0, 1), descriptor, scratch,
		    stride ? stride : const0_rtx, XVECEXP (src, 0, 2)));
      else switch (code)
	{
	case UNSPEC_ZTT_MEMORY_LOAD:
	  emit_insn (gen_ztt_state_memory_load
		     (mode, Pmode, dest, XVECEXP (src, 0, 0),
		      XVECEXP (src, 0, 1), XVECEXP (src, 0, 2), descriptor));
	  break;
	case UNSPEC_ZTT_MEMORY_STORE:
	  emit_insn (gen_ztt_state_memory_store
		     (mode, Pmode, dest, XVECEXP (src, 0, 0),
		      XVECEXP (src, 0, 1), descriptor, scratch,
		      stride ? stride : const0_rtx, XVECEXP (src, 0, 2)));
	  break;
	case UNSPEC_ZTT_CONVERT:
	case UNSPEC_ZTT_STRUCTURAL:
	  {
	    rtx source_dtype = XVECEXP (src, 0, structural_p ? 2 : 1);
	    unsigned int steps = pack_datatype_steps
	      (MAX (1U, (UINTVAL (dtype) & 0xff) / active_profile ()->uds),
	       MAX (1U, (UINTVAL (source_dtype) & 0xff) / active_profile ()->uds));
	    bool reuse = nregs > 4 && mode == GET_MODE (XVECEXP (src, 0, 0))
	      && rtx_equal_p (dtype, source_dtype);
	    rtx source_descriptor = reuse ? descriptor
	      : force_reg (Pmode, source_dtype);
	    if (structural_p)
	      emit_insn (gen_ztt_state_structural
			 (reuse ? UNSPECV_ZTT_STATE_STRUCTURAL_REUSE
				: UNSPECV_ZTT_STATE_STRUCTURAL,
			  mode, Pmode, dest, XVECEXP (src, 0, 0), descriptor,
			  source_descriptor, scratch,
			  stride ? stride : const0_rtx, GEN_INT (steps),
			  gen_rtx_SCRATCH (Pmode),
			  XVECEXP (src, 0, 1)));
	    else
	      emit_insn (gen_ztt_state_convert
			 (reuse ? UNSPECV_ZTT_STATE_CONVERT_REUSE
				: UNSPECV_ZTT_STATE_CONVERT,
			  mode, Pmode, dest, XVECEXP (src, 0, 0), descriptor,
			  source_descriptor, scratch,
			  stride ? stride : const0_rtx, GEN_INT (steps)));
	    break;
	  }
	case UNSPEC_ZTT_ELEMENTWISE_M:
	case UNSPEC_ZTT_ELEMENTWISE_X:
	case UNSPEC_ZTT_TERNARY:
	case UNSPEC_ZTT_TERNARY_X:
	case UNSPEC_ZTT_GATHER:
	case UNSPEC_ZTT_SCATTER:
	  {
	    bool scalar = (code == UNSPEC_ZTT_ELEMENTWISE_X
			   || code == UNSPEC_ZTT_TERNARY_X);
	    unsigned int groups[3] = {
	      MAX (1U, (UINTVAL (dtype) & 0xff) / active_profile ()->uds), 0, 0
	    };
	    for (unsigned int i = 1; i < (scalar ? 2U : 3U); ++i)
	      groups[i] = MAX (1U, (UINTVAL (XVECEXP (src, 0, i + 2)) & 0xff)
				  / active_profile ()->uds);
	    unsigned int steps = pack_datatype_steps (groups[0], groups[1], groups[2]);
	    if (code == UNSPEC_ZTT_TERNARY_X)
	      {
		bool exponent = UINTVAL (XVECEXP (src, 0, 2)) == 4;
		bool reuse = nregs > 4 && exponent
		  && mode == GET_MODE (XVECEXP (src, 0, 0))
		  && rtx_equal_p (dtype, XVECEXP (src, 0, 3));
		emit_insn (gen_ztt_state_ternary_x
			   (reuse ? UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE
				  : UNSPECV_ZTT_STATE_TERNARY_X,
			    mode, Pmode, dest, XVECEXP (src, 0, 0),
			    XVECEXP (src, 0, 1), descriptor,
			    reuse ? descriptor : force_reg (Pmode, XVECEXP (src, 0, 3)),
			    exponent ? const0_rtx : force_reg (Pmode, XVECEXP (src, 0, 4)),
			    scratch, stride ? stride : const0_rtx,
			    XVECEXP (src, 0, 2), GEN_INT (steps),
			    gen_rtx_SCRATCH (Pmode), XVECEXP (src, 0, 5),
			    const0_rtx));
		break;
	      }
	    if (code == UNSPEC_ZTT_TERNARY)
	      {
		emit_insn (gen_ztt_state_ternary
			   (mode, Pmode, dest, XVECEXP (src, 0, 0),
			    XVECEXP (src, 0, 1), descriptor,
			    force_reg (Pmode, XVECEXP (src, 0, 3)),
			    force_reg (Pmode, XVECEXP (src, 0, 4)),
			    scratch, stride ? stride : const0_rtx,
			    XVECEXP (src, 0, 2), GEN_INT (steps),
			    gen_rtx_SCRATCH (Pmode), XVECEXP (src, 0, 5),
			    const0_rtx));
		break;
	      }
	    if (indexed_p)
	      {
		rtx data_descriptor = force_reg (Pmode, XVECEXP (src, 0, 3));
		rtx count_descriptor = force_reg (Pmode, XVECEXP (src, 0, 4));
		if (code == UNSPEC_ZTT_SCATTER)
		  emit_insn (gen_ztt_state_scatter
			     (mode, Pmode, dest, XVECEXP (src, 0, 0),
			      XVECEXP (src, 0, 1), descriptor, data_descriptor,
			      count_descriptor, scratch, stride ? stride : const0_rtx,
			      XVECEXP (src, 0, 2), GEN_INT (steps),
			      gen_rtx_SCRATCH (Pmode), XVECEXP (src, 0, 5),
			      const0_rtx));
		else
		  emit_insn (gen_ztt_state_gather
			     (mode, Pmode, dest, XVECEXP (src, 0, 0),
			      XVECEXP (src, 0, 1), descriptor, data_descriptor,
			      count_descriptor, scratch, stride ? stride : const0_rtx,
			      XVECEXP (src, 0, 2), GEN_INT (steps),
			      gen_rtx_SCRATCH (Pmode), const0_rtx));
		break;
	      }
	    int state_code = scalar ? UNSPECV_ZTT_STATE_ELEMENTWISE_X
				    : UNSPECV_ZTT_STATE_ELEMENTWISE_M;
	    bool control_scalar = scalar
	      && !data_scalar_variant_p (UINTVAL (XVECEXP (src, 0, 2)));
	    rtx first_dtype = XVECEXP (src, 0, 3);
	    rtx second_dtype = XVECEXP (src, 0, 4);
	    bool reuse_left = nregs > 4
	      && mode == GET_MODE (XVECEXP (src, 0, 0))
	      && rtx_equal_p (dtype, first_dtype) && groups[0] == groups[1];
	    bool reuse_right = !scalar && nregs > 4
	      && mode == GET_MODE (XVECEXP (src, 0, 1))
	      && rtx_equal_p (dtype, second_dtype) && groups[0] == groups[2];
	    if (scalar && reuse_left)
	      state_code = UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE;
	    else if (reuse_left && reuse_right)
	      state_code = UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE;
	    else if (reuse_left)
	      state_code = UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT;
	    else if (reuse_right)
	      state_code = UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT;
	    rtx second_descriptor = control_scalar ? const0_rtx
	      : reuse_right ? descriptor
	      : force_reg (Pmode, second_dtype);
	    /* Preserve the old small-group expansion order and pseudo numbering.  */
	    rtx first_descriptor = reuse_left ? descriptor
	      : (nregs > 4 && !control_scalar
		 && rtx_equal_p (first_dtype, second_dtype))
	      ? second_descriptor : force_reg (Pmode, first_dtype);
	    emit_insn (gen_ztt_state_elementwise
		       (state_code,
			mode, Pmode, dest, XVECEXP (src, 0, 0), XVECEXP (src, 0, 1),
			descriptor, first_descriptor,
			second_descriptor,
			scratch, stride ? stride : const0_rtx,
			XVECEXP (src, 0, 2), GEN_INT (steps),
			gen_rtx_SCRATCH (Pmode), const0_rtx));
	    break;
	  }
	case UNSPEC_ZTT_ACC_FROM_M:
	  emit_insn (gen_ztt_acc_from_m
		     (mode, Pmode, dest, XVECEXP (src, 0, 0), descriptor, scratch,
		      stride ? stride : const0_rtx, const0_rtx));
	  break;
	case UNSPEC_ZTT_ACC_MMUL:
	  if (mixed_mul)
	    emit_insn (gen_ztt_acc_mmul_mixed
		       (mode, Pmode, dest, XVECEXP (src, 0, 0), XVECEXP (src, 0, 1),
			XVECEXP (src, 0, 2), descriptor, scratch,
			stride ? stride : const0_rtx, XVECEXP (src, 0, 3),
			force_reg (Pmode, XVECEXP (src, 0, 5)), const0_rtx));
	  else
	    emit_insn (gen_ztt_acc_mmul
		       (mode, Pmode, dest, XVECEXP (src, 0, 0), XVECEXP (src, 0, 1),
			XVECEXP (src, 0, 2), descriptor, scratch,
			stride ? stride : const0_rtx, XVECEXP (src, 0, 3),
			const0_rtx));
	  break;
	case UNSPEC_ZTT_MZERO_2D_M:
	  emit_insn (gen_ztt_state_zero (mode, Pmode, dest, descriptor));
	  break;
	case UNSPEC_ZTT_MLS_RM:
	  emit_insn (gen_ztt_state_load
		     (mode, Pmode, dest, XVECEXP (src, 0, 0), descriptor));
	  break;
	case UNSPEC_ZTT_MSS_RM:
	  if (nregs == 1)
	    emit_insn (gen_ztt_state_store
		       (mode, Pmode, dest, XVECEXP (src, 0, 0),
			descriptor, scratch));
	  else
	    emit_insn (gen_ztt_group_state_store
		       (mode, Pmode, dest, XVECEXP (src, 0, 0),
			descriptor, scratch, stride));
	  break;
	case UNSPEC_ZTT_MADD_EW:
	case UNSPEC_ZTT_MSUB_EW:
	case UNSPEC_ZTT_MMIN_EW:
	case UNSPEC_ZTT_MMAX_EW:
	case UNSPEC_ZTT_MAND_EW:
	case UNSPEC_ZTT_MANDNOT_EW:
	case UNSPEC_ZTT_MOR_EW:
	case UNSPEC_ZTT_MORNOT_EW:
	case UNSPEC_ZTT_MXOR_EW:
	  if (nregs == 1)
	    emit_insn (gen_ztt_state
		       (binary_code, mode, Pmode, dest, XVECEXP (src, 0, 0),
			XVECEXP (src, 0, 1), descriptor, scratch, const0_rtx));
	  else
	    emit_insn (gen_ztt_group_state
		       (binary_code, mode, Pmode, dest, XVECEXP (src, 0, 0),
			XVECEXP (src, 0, 1), descriptor, scratch, stride,
			gen_rtx_SCRATCH (Pmode), const0_rtx));
	  break;
	default:
	  gcc_unreachable ();
	}
      rtx_insn *sequence = get_insns ();
      end_sequence ();
      emit_insn_before (sequence, insn);
      delete_insn (insn);
      insn = next;
    }
  return TODO_df_finish;
}

const pass_data pass_data_ztt_state =
{
  RTL_PASS, "ztt_state", OPTGROUP_NONE, TV_MACH_DEP,
  0, 0, 0, 0, 0
};

class pass_ztt_state : public rtl_opt_pass
{
public:
  pass_ztt_state (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_ztt_state, ctxt)
  {}

  bool gate (function *) final override
  {
    return TARGET_ZTT && typed_profile_p ();
  }

  unsigned int execute (function *) final override
  {
    bool typed = false;
    bool acc = false;
    bool matrix_asm = false;
    bool calls = false;
    for (rtx_insn *insn = get_insns (); insn;
	 insn = NEXT_INSN (insn))
      if (NONDEBUG_INSN_P (insn))
	{
	  calls |= CALL_P (insn);
	  int nargs = asm_noperands (PATTERN (insn));
	  if (nargs > 0)
	    {
	      auto_vec<rtx, 8> operands;
	      operands.safe_grow (nargs);
	      decode_asm_operands (PATTERN (insn), operands.address (),
			   NULL, NULL, NULL, NULL);
	      for (rtx operand : operands)
		matrix_asm |= m_mode_p (GET_MODE (operand));
	    }
	  subrtx_iterator::array_type array;
	  FOR_EACH_SUBRTX (iter, array, PATTERN (insn), NONCONST)
	    if (value_mode_p (GET_MODE (*iter)))
	      {
		typed = true;
		acc |= acc_mode_p (GET_MODE (*iter));
	      }
	}
    if (!typed)
      {
	if (dump_file)
	  fprintf (dump_file,
		   "Skip Ztt state lowering without typed operands\n");
	return 0;
      }
    if (acc && matrix_asm)
      riscv_ztt_note_acc_reload ();
    /* Even uniform i8 operations before a call need explicit state.  */
    if (calls)
      riscv_ztt_note_call_boundary ();
    return lower_explicit_state ();
  }
};

/* Track complete physical M groups and their descriptor values.  */
class local_md_state
{
  struct fact { rtx group; rtx descriptor; unsigned int identity; }
    facts[M_REG_NUM] = {};
  rtx constants[32] = {}; /* GP_REG_NUM depends on the active RVE option.  */
  unsigned int identities[32] = {};
  unsigned int next_identity = 0;
  unsigned int definition[32] = {};
  bool descriptor_used[32] = {};
  unsigned int next_definition = 0;
  rtx scalar_type = nullptr;

  static rtx substitute (rtx x, const_rtx, void *data)
  {
    return REG_P (x)
      ? static_cast<local_md_state *> (data)->descriptor_value (x) : NULL_RTX;
  }

public:
  void clear ()
  {
    memset (facts, 0, sizeof (facts));
    memset (constants, 0, sizeof (constants));
    memset (identities, 0, sizeof (identities));
    next_identity = 0;
    memset (descriptor_used, 0, sizeof (descriptor_used));
    next_definition = 0;
    scalar_type = nullptr;
  }

  static bool full_gpr_p (rtx reg)
  {
    return REG_P (reg) && GP_REG_P (REGNO (reg)) && GET_MODE (reg) == Pmode;
  }

  rtx descriptor_value (rtx reg) const
  {
    if (full_gpr_p (reg))
      {
	if (REGNO (reg) == GP_REG_FIRST)
	  return const0_rtx;
	if (rtx value = constants[REGNO (reg) - GP_REG_FIRST])
	  return value;
      }
    return reg;
  }

  rtx constant_value (rtx src)
  {
    if (contains_mem_rtx_p (src) || side_effects_p (src))
      return NULL_RTX;
    rtx value = simplify_replace_fn_rtx (src, NULL_RTX, substitute, this);
    return CONST_INT_P (value) ? gen_int_mode (INTVAL (value), Pmode) : NULL_RTX;
  }

  unsigned int descriptor_identity (rtx reg)
  {
    if (!full_gpr_p (reg) || fixed_regs[REGNO (reg)]
	|| global_regs[REGNO (reg)] || CONST_INT_P (descriptor_value (reg)))
      return 0;
    unsigned int &identity = identities[REGNO (reg) - GP_REG_FIRST];
    if (!identity)
      identity = ++next_identity;
    return identity;
  }

  /* Capture the source identity before invalidating the copy destination.  */
  unsigned int copied_identity (rtx pattern)
  {
    if (GET_CODE (pattern) != SET || !full_gpr_p (SET_DEST (pattern))
	|| fixed_regs[REGNO (SET_DEST (pattern))]
	|| global_regs[REGNO (SET_DEST (pattern))])
      return 0;
    return descriptor_identity (SET_SRC (pattern));
  }

  void record_copy (rtx reg, unsigned int identity)
  {
    gcc_assert (full_gpr_p (reg) && identity);
    identities[REGNO (reg) - GP_REG_FIRST] = identity;
  }

  rtx broadcast_value (rtx reg) const
  {
    if (REG_P (reg) && GP_REG_P (REGNO (reg))
	&& (GET_MODE (reg) == QImode || GET_MODE (reg) == HImode
	    || GET_MODE (reg) == SImode))
      {
	/* A lowpart use does not establish the register's high bits.  */
	rtx value = descriptor_value (gen_rtx_REG (Pmode, REGNO (reg)));
	if (CONST_INT_P (value))
	  return gen_int_mode (INTVAL (value), GET_MODE (reg));
      }
    return descriptor_value (reg);
  }

  /* The CSR retains its value when the materializing GPR is overwritten.  */
  bool record_scalar_type (rtx reg)
  {
    rtx value = descriptor_value (reg);
    if (!CONST_INT_P (value))
      {
	scalar_type = nullptr;
	return false;
      }
    bool repeated = scalar_type && rtx_equal_p (scalar_type, value);
    scalar_type = value;
    return repeated;
  }

  void record_constant (rtx reg, rtx value)
  {
    gcc_assert (full_gpr_p (reg) && CONST_INT_P (value));
    constants[REGNO (reg) - GP_REG_FIRST] = value;
    identities[REGNO (reg) - GP_REG_FIRST] = 0;
    definition[REGNO (reg) - GP_REG_FIRST] = ++next_definition;
    descriptor_used[REGNO (reg) - GP_REG_FIRST] = false;
  }

  void note_descriptor_use (rtx reg)
  {
    if (full_gpr_p (reg) && CONST_INT_P (descriptor_value (reg)))
      descriptor_used[REGNO (reg) - GP_REG_FIRST] = true;
  }

  bool redundant_descriptor_p (rtx reg, rtx value) const
  {
    return full_gpr_p (reg) && !fixed_regs[REGNO (reg)]
      && !global_regs[REGNO (reg)] && descriptor_used[REGNO (reg) - GP_REG_FIRST]
      && value && CONST_INT_P (value)
      && rtx_equal_p (descriptor_value (reg), value);
  }

  rtx descriptor_register (rtx reg, const_rtx insn) const
  {
    if (!full_gpr_p (reg) || fixed_regs[REGNO (reg)]
	|| global_regs[REGNO (reg)] || reg_set_p (reg, insn))
      return reg;
    rtx value = descriptor_value (reg);
    if (!CONST_INT_P (value))
      return reg;
    rtx best = reg;
    unsigned int oldest = definition[REGNO (reg) - GP_REG_FIRST];
    /* Prefer the earliest value, not a newer copy that DCE could remove.  */
    for (unsigned int r = GP_REG_FIRST; r < GP_REG_FIRST + GP_REG_NUM; ++r)
      if (!fixed_regs[r] && !global_regs[r]
	  && constants[r - GP_REG_FIRST]
	  && descriptor_used[r - GP_REG_FIRST]
	  && definition[r - GP_REG_FIRST] < oldest
	  && rtx_equal_p (value, constants[r - GP_REG_FIRST]))
	{
	  rtx candidate = gen_rtx_REG (Pmode, r);
	  if (!reg_set_p (candidate, insn))
	    {
	      best = candidate;
	      oldest = definition[r - GP_REG_FIRST];
	    }
	}
    return best;
  }

  void invalidate (rtx reg)
  {
    for (auto &f : facts)
      if (f.group && (reg_overlap_mentioned_p (reg, f.group)
		      || (!f.identity
			  && reg_overlap_mentioned_p (reg, f.descriptor))))
	f.group = nullptr;
    for (unsigned int i = 0; i < GP_REG_NUM; ++i)
      if ((constants[i] || identities[i])
	  && reg_overlap_mentioned_p (reg, gen_rtx_REG (Pmode, GP_REG_FIRST + i)))
	{
	  constants[i] = NULL_RTX;
	  identities[i] = 0;
	  descriptor_used[i] = false;
	}
  }

  bool matches (rtx group, rtx descriptor) const
  {
    if (!REG_P (group) || !M_REG_P (REGNO (group)))
      return false;
    const auto &f = facts[REGNO (group) - M_REG_FIRST];
    return f.group && rtx_equal_p (f.group, group)
      && (f.identity
	  ? full_gpr_p (descriptor)
	    && f.identity == identities[REGNO (descriptor) - GP_REG_FIRST]
	  : rtx_equal_p (f.descriptor, descriptor_value (descriptor)));
  }

  bool matches_packets (rtx group, rtx descriptor, unsigned int step) const
  {
    if (!REG_P (group) || !M_REG_P (REGNO (group)))
      return false;
    unsigned int count = m_nregs (GET_MODE (group));
    if (!count || !step || count % step)
      return false;
    for (unsigned int i = 0; i < count; i += step)
      if (!matches (gen_rtx_REG (matrix_mode (step), REGNO (group) + i),
		    descriptor))
	return false;
    return true;
  }

  unsigned int prepared_inputs (rtx *groups, rtx *descriptors,
				unsigned int steps, bool scalar, bool old_dest) const
  {
    unsigned int prepared = 0;
    unsigned int first = old_dest ? 0 : 1;
    for (unsigned int i = first; i < (scalar ? 2U : 3U); ++i)
      {
	unsigned int step = datatype_step (steps, i);
	bool ready = matches_packets (groups[i], descriptors[i], step);
	/* Follow actual setup order, including an earlier identical operand.  */
	for (unsigned int j = first; j < i; ++j)
	  if (!(prepared & (1U << j))
	      && reg_overlap_mentioned_p (groups[i], groups[j]))
	    ready = rtx_equal_p (groups[i], groups[j])
	      && step && step == datatype_step (steps, j)
	      && rtx_equal_p (descriptor_value (descriptors[i]),
			      descriptor_value (descriptors[j]));
	if (ready)
	  prepared |= 1U << i;
      }
    return prepared;
  }

  void remember (rtx group, rtx descriptor)
  {
    gcc_assert (REG_P (group) && M_REG_P (REGNO (group))
		&& REG_P (descriptor) && GP_REG_P (REGNO (descriptor)));
    invalidate (group);
    facts[REGNO (group) - M_REG_FIRST]
      = { group, descriptor_value (descriptor), descriptor_identity (descriptor) };
  }
};

static void
invalidate_md_store (rtx reg, const_rtx, void *data)
{
  if (!MEM_P (reg))
    static_cast<local_md_state *> (data)->invalidate (reg);
}

static bool
md_raw_transfer_p (rtx pattern)
{
  if (GET_CODE (pattern) != SET)
    return false;
  rtx reg = SET_DEST (pattern), mem = SET_SRC (pattern);
  if (MEM_P (reg))
    std::swap (reg, mem);
  return REG_P (reg) && M_REG_P (REGNO (reg))
    && m_mode_p (GET_MODE (reg)) && m_nregs (GET_MODE (reg)) == 1
    && MEM_P (mem) && GET_MODE (mem) == GET_MODE (reg)
    && REG_P (XEXP (mem, 0)) && GP_REG_P (REGNO (XEXP (mem, 0)));
}

static bool
md_scalar_insn_p (rtx pattern)
{
  subrtx_iterator::array_type array;
  FOR_EACH_SUBRTX (iter, array, pattern, NONCONST)
    if (GET_CODE (*iter) == UNSPEC || GET_CODE (*iter) == UNSPEC_VOLATILE
	|| GET_CODE (*iter) == ASM_INPUT || GET_CODE (*iter) == ASM_OPERANDS
	|| GET_CODE (*iter) == COND_EXEC || GET_CODE (*iter) == PRE_INC
	|| GET_CODE (*iter) == POST_INC || GET_CODE (*iter) == PRE_DEC
	|| GET_CODE (*iter) == POST_DEC || GET_CODE (*iter) == PRE_MODIFY
	|| GET_CODE (*iter) == POST_MODIFY
	|| (REG_P (*iter) && (M_REG_P (REGNO (*iter))
			     || ACC_REG_P (REGNO (*iter)))))
      return false;
  return true;
}

static bool
md_fallthrough_p (basic_block bb)
{
  edge incoming = single_pred_p (bb) ? single_pred_edge (bb) : nullptr;
  return incoming && incoming->src == bb->prev_bb
    && (incoming->flags & EDGE_FALLTHRU)
    && !(incoming->flags & (EDGE_COMPLEX | EDGE_FAKE | EDGE_DFS_BACK
			   | EDGE_IRREDUCIBLE_LOOP | EDGE_CROSSING));
}

/* A plain scalar branch changes neither registers nor Md.  */
static bool
md_preserving_branch_p (rtx_insn *insn)
{
  return JUMP_P (insn) && GET_CODE (PATTERN (insn)) == SET
    && any_condjump_p (insn) && onlyjump_p (insn)
    && recog_memoized (insn) >= 0 && md_scalar_insn_p (PATTERN (insn));
}

/* Only the result GPR changes; the volatile CSR observation remains.  */
static bool
md_read_csr_p (int code)
{
  switch (code)
    {
    case CODE_FOR_riscv_ztt_read_amenlen_si:
    case CODE_FOR_riscv_ztt_read_amenlen_di:
    case CODE_FOR_riscv_ztt_read_ameudsz_si:
    case CODE_FOR_riscv_ztt_read_ameudsz_di:
    case CODE_FOR_riscv_ztt_read_ameown_si:
    case CODE_FOR_riscv_ztt_read_ameown_di:
    case CODE_FOR_riscv_ztt_read_amestype_si:
    case CODE_FOR_riscv_ztt_read_amestype_di:
    case CODE_FOR_riscv_ztt_read_amefflags_si:
    case CODE_FOR_riscv_ztt_read_amefflags_di:
    case CODE_FOR_riscv_ztt_read_amexsat_si:
    case CODE_FOR_riscv_ztt_read_amexsat_di:
    case CODE_FOR_riscv_ztt_read_amestatus_si:
    case CODE_FOR_riscv_ztt_read_amestatus_di:
      return true;
    default:
      return false;
    }
}

/* Remember one complete private spill until its inputs or memory change.  */
class local_raw_spill
{
  rtx reg = nullptr;
  rtx mem = nullptr;

  static bool private_slot_p (rtx x)
  {
    return MEM_P (x) && !MEM_VOLATILE_P (x) && MEM_NOTRAP_P (x)
      && MEM_EXPR (x) && MEM_EXPR (x) == get_spill_slot_decl (false)
      && MEM_OFFSET_KNOWN_P (x) && MEM_SIZE_KNOWN_P (x)
      && known_eq (MEM_SIZE (x), GET_MODE_SIZE (GET_MODE (x)));
  }

public:
  void clear () { reg = mem = nullptr; }

  bool redundant_reload_p (rtx pattern)
  {
    if (md_raw_transfer_p (pattern))
      {
	rtx dest = SET_DEST (pattern), src = SET_SRC (pattern);
	if (MEM_P (dest) && private_slot_p (dest))
	  {
	    reg = src;
	    mem = dest;
	    return false;
	  }
	if (mem && private_slot_p (src) && rtx_equal_p (reg, dest)
	    && rtx_equal_p (mem, src)
	    && known_eq (MEM_OFFSET (mem), MEM_OFFSET (src)))
	  return true;
	clear ();
	return false;
      }
    if (mem)
      {
	if (GET_CODE (pattern) == SET
	    && local_md_state::full_gpr_p (SET_DEST (pattern))
	    && !fixed_regs[REGNO (SET_DEST (pattern))]
	    && !global_regs[REGNO (SET_DEST (pattern))]
	    && REGNO (SET_DEST (pattern)) != HARD_FRAME_POINTER_REGNUM
	    && !reg_overlap_mentioned_p (SET_DEST (pattern), XEXP (mem, 0))
	    && !contains_mem_rtx_p (pattern) && !side_effects_p (pattern)
	    && md_scalar_insn_p (pattern))
	  return false;
	clear ();
      }
    return false;
  }
};

/* Standard integer zero has an all-zero representation.  */
static unsigned int
integer_zero_width (rtx descriptor)
{
  if (!CONST_INT_P (descriptor)
      || (UINTVAL (descriptor) & ~HOST_WIDE_INT_UC (0x780000ff)))
    return 0;
  unsigned int width = UINTVAL (descriptor) & 0xff;
  return width >= 4 && width <= 128 && pow2p_hwi (width) ? width : 0;
}

/* Canonical FP16, BF16, FP32 and FP64 positive zero is all-zero bits.  */
static unsigned int
floating_zero_width (rtx descriptor)
{
  if (!CONST_INT_P (descriptor)
      || ((UINTVAL (descriptor) >> 22) & 15) > 5)
    return 0;
  switch (UINTVAL (descriptor) & ~HOST_WIDE_INT_UC (0x03c00000))
    {
    case 0x14300110: /* FP16.  */
    case 0x20300110: /* BF16.  */
      return 16;
    case 0x20300120:
      return 32;
    case 0x2c300140:
      return 64;
    default:
      return 0;
    }
}

static bool
zero_broadcast_types_p (rtx source, rtx destination)
{
  if (integer_zero_width (source) && integer_zero_width (destination))
    return true;
  return floating_zero_width (source) && floating_zero_width (destination)
    && ((UINTVAL (source) ^ UINTVAL (destination))
	& ~HOST_WIDE_INT_UC (0x03c00000)) == 0;
}

/* Reuse constants with a retained descriptor use.  */
static bool
reuse_typed_descriptors (rtx_insn *insn, rtx src, local_md_state &state)
{
  unsigned int mask;
  switch (XINT (src, 1))
    {
    case UNSPECV_ZTT_SETTYP_P0:
    case UNSPECV_ZTT_STATE_ZERO:
    case UNSPECV_ZTT_INDEX_CONSTRUCT:
    case UNSPECV_ZTT_ACC_ZERO:
    case UNSPECV_ZTT_ACC_CLEAR:
      mask = 1;
      break;
    case UNSPECV_ZTT_ACC_TO_M:
    case UNSPECV_ZTT_ACC_FROM_M:
      mask = 2;
      break;
    case UNSPECV_ZTT_STATE_STORE:
      mask = XVECLEN (src, 0) > 1 ? 2 : 0;
      break;
    case UNSPECV_ZTT_STATE_MEMORY_STORE:
      mask = XVECLEN (src, 0) == 4 ? 4 : 0;
      break;
    case UNSPECV_ZTT_STATE_ZIP_VALUE:
      mask = XVECLEN (src, 0) == 4 ? 2 : 0;
      break;
    case UNSPECV_ZTT_BROADCAST:
    case UNSPECV_ZTT_STATE_ROWCOL:
    case UNSPECV_ZTT_STATE_ROWCOL_REUSE:
    case UNSPECV_ZTT_STATE_ADD:
    case UNSPECV_ZTT_STATE_SUB:
    case UNSPECV_ZTT_STATE_MIN:
    case UNSPECV_ZTT_STATE_MAX:
    case UNSPECV_ZTT_STATE_AND:
    case UNSPECV_ZTT_STATE_ANDNOT:
    case UNSPECV_ZTT_STATE_OR:
    case UNSPECV_ZTT_STATE_ORNOT:
    case UNSPECV_ZTT_STATE_XOR:
      mask = 4;
      break;
    case UNSPECV_ZTT_STATE_CONVERT:
    case UNSPECV_ZTT_STATE_CONVERT_REUSE:
    case UNSPECV_ZTT_STATE_STRUCTURAL:
    case UNSPECV_ZTT_STATE_STRUCTURAL_REUSE:
    case UNSPECV_ZTT_STATE_CONVERT_PREPARED:
    case UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED:
      mask = 6;
      break;
    case UNSPECV_ZTT_STATE_ELEMENTWISE_M:
    case UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE:
    case UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT:
    case UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT:
    case UNSPECV_ZTT_STATE_TERNARY:
    case UNSPECV_ZTT_STATE_GATHER:
    case UNSPECV_ZTT_STATE_SCATTER:
      mask = 28;
      break;
    case UNSPECV_ZTT_STATE_ELEMENTWISE_X:
    case UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE:
    case UNSPECV_ZTT_STATE_TERNARY_X:
    case UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE:
      mask = common_data_scalar_p (src, GET_CODE (PATTERN (insn)) == SET)
	? 28 : 12;
      break;
    case UNSPECV_ZTT_ACC_MMUL:
      mask = XVECLEN (src, 0) == 8 ? 72 : XVECLEN (src, 0) == 7 ? 8 : 0;
      break;
    default:
      return false;
    }
  unsigned int changed = 0;
  for (unsigned int i = 0; mask; ++i, mask >>= 1)
    if (mask & 1)
      {
	gcc_assert (i < (unsigned int) XVECLEN (src, 0));
	rtx *where = &XVECEXP (src, 0, i);
	rtx reg = state.descriptor_register (*where, insn);
	if (reg != *where)
	  {
	    if (!validate_change (insn, where, reg, true))
	      {
		cancel_changes (0);
		return false;
	      }
	    changed |= 1U << i;
	  }
      }
  if (!changed || !apply_change_group ())
    return false;
  df_insn_rescan (insn);
  if (dump_file)
    fprintf (dump_file, "Reuse typed descriptors at insn %d: 0x%x\n",
	     INSN_UID (insn), changed);
  return true;
}

/* DCE can remove workspace calculations that killed descriptor GPRs.  */
static bool
reuse_cleaned_descriptors ()
{
  bool changed = false;
  const bool explicit_state = riscv_ztt_explicit_state_p ();
  local_md_state state;
  basic_block bb;
  FOR_EACH_BB_FN (bb, cfun)
    {
      if (!md_fallthrough_p (bb))
	state.clear ();
      local_raw_spill spill;
      rtx_insn *insn, *next;
      FOR_BB_INSNS_SAFE (bb, insn, next)
	{
	  if (!NONDEBUG_INSN_P (insn))
	    continue;
	  int code = recog_memoized (insn);
	  if (explicit_state && NONJUMP_INSN_P (insn)
	      && !RTX_FRAME_RELATED_P (insn) && code >= 0)
	    {
	      if (spill.redundant_reload_p (PATTERN (insn)))
		{
		  if (dump_file)
		    fprintf (dump_file, "Drop redundant raw reload at insn %d\n",
			     INSN_UID (insn));
		  delete_insn (insn);
		  changed = true;
		  continue;
		}
	    }
	  else
	    spill.clear ();
	  if (md_preserving_branch_p (insn))
	    continue;
	  if (code == CODE_FOR_stack_tiesi || code == CODE_FOR_stack_tiedi
	      || code == CODE_FOR_stack_tie_spsi || code == CODE_FOR_stack_tie_spdi)
	    continue;
	  if (md_read_csr_p (code))
	    {
	      note_stores (insn, invalidate_md_store, &state);
	      continue;
	    }
	  rtx pattern = PATTERN (insn);
	  if (!NONJUMP_INSN_P (insn) || GET_CODE (pattern) != SET)
	    {
	      state.clear ();
	      continue;
	    }
	  /* Raw singleton transfers leave descriptor GPRs unchanged.  */
	  if (code >= 0 && explicit_state && md_raw_transfer_p (pattern))
	    continue;
	  rtx src = SET_SRC (pattern);
	  if (GET_CODE (src) == UNSPEC_VOLATILE && code >= 0)
	    {
	      switch (XINT (src, 1))
		{
		case UNSPECV_ZTT_STATE_STORE:
		case UNSPECV_ZTT_STATE_MEMORY_STORE:
		  /* Prepared stores change memory, not descriptor GPRs.  */
		  if (MEM_P (SET_DEST (pattern))
		      && XVECLEN (src, 0)
			 == (XINT (src, 1) == UNSPECV_ZTT_STATE_STORE ? 1 : 3))
		    continue;
		  break;
		case UNSPECV_ZTT_STATE_LOAD:
		case UNSPECV_ZTT_STATE_MEMORY_LOAD:
		  state.note_descriptor_use
		    (XVECEXP (src, 0, XINT (src, 1) == UNSPECV_ZTT_STATE_LOAD
				      ? 1 : 3));
		  note_stores (insn, invalidate_md_store, &state);
		  continue;
		case UNSPECV_ZTT_SETTYP_P0:
		case UNSPECV_ZTT_STATE_ZERO:
		case UNSPECV_ZTT_INDEX_CONSTRUCT:
		case UNSPECV_ZTT_ACC_ZERO:
		case UNSPECV_ZTT_ACC_CLEAR:
		case UNSPECV_ZTT_ACC_TO_M:
		case UNSPECV_ZTT_ACC_FROM_M:
		case UNSPECV_ZTT_ACC_MMUL:
		case UNSPECV_ZTT_STATE_ZIP_VALUE:
		case UNSPECV_ZTT_STATE_GATHER:
		case UNSPECV_ZTT_STATE_SCATTER:
		case UNSPECV_ZTT_BROADCAST:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_M:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_X:
		case UNSPECV_ZTT_STATE_TERNARY:
		case UNSPECV_ZTT_STATE_TERNARY_X:
		case UNSPECV_ZTT_STATE_CONVERT_PREPARED:
		case UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED:
		case UNSPECV_ZTT_STATE_ROWCOL:
		case UNSPECV_ZTT_STATE_ADD:
		case UNSPECV_ZTT_STATE_SUB:
		case UNSPECV_ZTT_STATE_MIN:
		case UNSPECV_ZTT_STATE_MAX:
		case UNSPECV_ZTT_STATE_AND:
		case UNSPECV_ZTT_STATE_ANDNOT:
		case UNSPECV_ZTT_STATE_OR:
		case UNSPECV_ZTT_STATE_ORNOT:
		case UNSPECV_ZTT_STATE_XOR:
		  changed |= reuse_typed_descriptors (insn, src, state);
		  note_stores (insn, invalidate_md_store, &state);
		  if (common_data_scalar_p (src, true))
		    state.note_descriptor_use (XVECEXP (src, 0, 4));
		  continue;
		default:
		  break;
		}
	    }
	  if (md_scalar_insn_p (pattern))
	    {
	      rtx dest = SET_DEST (pattern);
	      rtx value = local_md_state::full_gpr_p (dest)
		? state.constant_value (src) : NULL_RTX;
	      if (!RTX_FRAME_RELATED_P (insn)
		  && state.redundant_descriptor_p (dest, value))
		{
		  if (dump_file)
		    fprintf (dump_file, "Drop repeated descriptor definition at insn %d\n",
			     INSN_UID (insn));
		  delete_insn (insn);
		  changed = true;
		  continue;
		}
	      note_stores (insn, invalidate_md_store, &state);
	      if (value)
		state.record_constant (dest, value);
	    }
	  else
	    state.clear ();
	}
    }
  return changed;
}

/* Reuse Md along single-predecessor fallthrough chains after allocation.  */
static unsigned int
reuse_local_md ()
{
  bool cleanup = false;
  bool descriptor_cleanup = false;
  const bool explicit_state = riscv_ztt_explicit_state_p ();
  if (dump_file)
    fprintf (dump_file, "Explicit Md state: %d\n", explicit_state);
  local_md_state state;
  basic_block bb;
  FOR_EACH_BB_FN (bb, cfun)
    {
      if (!md_fallthrough_p (bb))
	state.clear ();
      rtx_insn *insn;
      FOR_BB_INSNS (bb, insn)
	{
	  if (!NONDEBUG_INSN_P (insn))
	    continue;
	  if (CALL_P (insn) || JUMP_P (insn))
	    {
	      if (md_preserving_branch_p (insn))
		continue;
	      state.clear ();
	      continue;
	    }
	  /* These zero-length scheduling barriers do not alter Md or GPRs.  */
	  int code = recog_memoized (insn);
	  if (code == CODE_FOR_stack_tiesi || code == CODE_FOR_stack_tiedi
	      || code == CODE_FOR_stack_tie_spsi || code == CODE_FOR_stack_tie_spdi)
	    continue;
	  if (md_read_csr_p (code))
	    {
	      note_stores (insn, invalidate_md_store, &state);
	      continue;
	    }
	  /* Whole-register transfers change payload, not the physical Md.  */
	  if (code >= 0 && explicit_state
	      && md_raw_transfer_p (PATTERN (insn)))
	    continue;
	  rtx set = single_set (insn);
	  rtx src = set ? SET_SRC (set) : NULL_RTX;
	  if (src && GET_CODE (src) == UNSPEC_VOLATILE)
	    {
	      bool zero_broadcast = XINT (src, 1) == UNSPECV_ZTT_BROADCAST
		&& state.broadcast_value (XVECEXP (src, 0, 0)) == const0_rtx
		&& zero_broadcast_types_p
		     (state.descriptor_value (XVECEXP (src, 0, 1)),
		      state.descriptor_value (XVECEXP (src, 0, 2)));
	      if ((explicit_state && XINT (src, 1) == UNSPECV_ZTT_STATE_ZERO)
		  || zero_broadcast)
		{
		  rtx descriptor = XVECEXP (src, 0, zero_broadcast ? 2 : 0);
		  unsigned int width
		    = integer_zero_width (state.descriptor_value (descriptor));
		  bool floating_zero = !width;
		  if (floating_zero)
		    width = floating_zero_width (state.descriptor_value (descriptor));
		  machine_mode mode = GET_MODE (SET_DEST (set));
		  if (width
		      && m_nregs (mode) == MAX (1U, width / active_profile ()->uds))
		    {
		      /* The setter already clears this complete group.  */
		      rtx clear = gen_ztt_typed_msettyp_p0
			(mode, Pmode, SET_DEST (set), descriptor);
		      if (validate_change (insn, &PATTERN (insn), clear, false))
			{
			  df_insn_rescan (insn);
			  cleanup = true;
			  descriptor_cleanup |= zero_broadcast;
			  set = single_set (insn);
			  src = SET_SRC (set);
			  if (dump_file)
			    fprintf (dump_file, "Reuse %s %sclear at insn %d\n",
				     floating_zero ? "floating" : "integer",
				     zero_broadcast ? "broadcast " : "",
				     INSN_UID (insn));
			}
		    }
		}
	      if (XINT (src, 1) == UNSPECV_ZTT_STATE_LOAD
		  || XINT (src, 1) == UNSPECV_ZTT_STATE_MEMORY_LOAD)
		{
		  unsigned int index
		    = XINT (src, 1) == UNSPECV_ZTT_STATE_LOAD ? 1 : 3;
		  rtx *where = &XVECEXP (src, 0, index);
		  rtx old = *where;
		  rtx reg = state.descriptor_register (old, insn);
		  if (reg != old && validate_change (insn, where, reg, false))
		    {
		      df_insn_rescan (insn);
		      cleanup = descriptor_cleanup = true;
		      if (dump_file)
			fprintf (dump_file,
				 "Reuse load descriptor at insn %d: x%u -> x%u\n",
				 INSN_UID (insn), REGNO (old), REGNO (reg));
		    }
		  state.note_descriptor_use (*where);
		}
	      else if (reuse_typed_descriptors (insn, src, state))
		cleanup = descriptor_cleanup = true;
	      rtx group = NULL_RTX, descriptor = NULL_RTX;
	      switch (XINT (src, 1))
		{
		case UNSPECV_ZTT_STATE_LOAD:
		  group = SET_DEST (set); descriptor = XVECEXP (src, 0, 1);
		  break;
		case UNSPECV_ZTT_STATE_MEMORY_LOAD:
		  group = SET_DEST (set); descriptor = XVECEXP (src, 0, 3);
		  break;
		case UNSPECV_ZTT_BROADCAST:
		  group = SET_DEST (set); descriptor = XVECEXP (src, 0, 2);
		  break;
		/* Typed stores leave the complete source group prepared.  */
		case UNSPECV_ZTT_STATE_STORE:
		  if (XVECLEN (src, 0) < 2)
		    break;
		  group = XVECEXP (src, 0, 0); descriptor = XVECEXP (src, 0, 1);
		  break;
		case UNSPECV_ZTT_STATE_MEMORY_STORE:
		  if (XVECLEN (src, 0) != 4)
		    break;
		  group = XVECEXP (src, 0, 0); descriptor = XVECEXP (src, 0, 2);
		  break;
		case UNSPECV_ZTT_SETTYP_P0:
		case UNSPECV_ZTT_STATE_ZERO:
		case UNSPECV_ZTT_INDEX_CONSTRUCT:
		  group = SET_DEST (set); descriptor = XVECEXP (src, 0, 0);
		  break;
		case UNSPECV_ZTT_STATE_ROWCOL:
		case UNSPECV_ZTT_STATE_ROWCOL_REUSE:
		  group = XVECEXP (src, 0, 0);
		  descriptor = XVECEXP (src, 0, 2);
		  if (XVECLEN (src, 0) == 5 && state.matches (group, descriptor))
		    {
		      rtx prepared = gen_ztt_state_rowcol_prepared
			(GET_MODE (group), Pmode, SET_DEST (set), group,
			 XVECEXP (src, 0, 1), descriptor, XVECEXP (src, 0, 4));
		      bool changed = validate_change
			(insn, &PATTERN (insn), prepared, false);
		      gcc_assert (changed);
		      df_insn_rescan (insn);
		      cleanup = true;
		      if (dump_file)
			fprintf (dump_file, "Reuse Md for rowcol at insn %d\n",
				 INSN_UID (insn));
		    }
		  note_stores (insn, invalidate_md_store, &state);
		  state.remember (group, descriptor);
		  state.remember (SET_DEST (set), descriptor);
		  continue;
		case UNSPECV_ZTT_STATE_ZIP_VALUE:
		  {
		    if (XVECLEN (src, 0) != 4)
		      break;
		    group = SET_DEST (set);
		    descriptor = XVECEXP (src, 0, 1);
		    unsigned int step = m_nregs (GET_MODE (group)) / 2;
		    gcc_assert (step && rtx_equal_p (group, XVECEXP (src, 0, 0)));
		    if (state.matches_packets (group, descriptor, step))
		      {
			rtx prepared = gen_ztt_state_zip_value_prepared
			  (GET_MODE (group), group, group, XVECEXP (src, 0, 2));
			bool changed = validate_change
			  (insn, &PATTERN (insn), prepared, false);
			gcc_assert (changed);
			df_insn_rescan (insn);
			cleanup = true;
			if (dump_file)
			  fprintf (dump_file, "Reuse Md for zip at insn %d\n",
				   INSN_UID (insn));
		      }
		    note_stores (insn, invalidate_md_store, &state);
		    for (unsigned int i = 0; i < 2; ++i)
		      state.remember
			(gen_rtx_REG (matrix_mode (step), REGNO (group) + i * step),
			 descriptor);
		    continue;
		  }
		case UNSPECV_ZTT_STATE_CONVERT:
		case UNSPECV_ZTT_STATE_CONVERT_REUSE:
		case UNSPECV_ZTT_STATE_STRUCTURAL:
		case UNSPECV_ZTT_STATE_STRUCTURAL_REUSE:
		case UNSPECV_ZTT_STATE_CONVERT_PREPARED:
		case UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED:
		  {
		    bool prepared_p
		      = XINT (src, 1) == UNSPECV_ZTT_STATE_CONVERT_PREPARED
			|| XINT (src, 1) == UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED;
		    rtx steps = XVECEXP (src, 0, prepared_p ? 3 : 4);
		    group = XVECEXP (src, 0, 0);
		    descriptor = XVECEXP (src, 0, 2);
		    if (!prepared_p
			&& state.matches_packets
			     (group, descriptor, datatype_step (UINTVAL (steps), 1)))
		      {
			bool convert = XINT (src, 1) == UNSPECV_ZTT_STATE_CONVERT
			  || XINT (src, 1) == UNSPECV_ZTT_STATE_CONVERT_REUSE;
			rtx prepared = gen_ztt_state_unary_prepared
			  (convert ? UNSPECV_ZTT_STATE_CONVERT_PREPARED
			   : UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED,
			   GET_MODE (SET_DEST (set)), Pmode, SET_DEST (set),
			   group, XVECEXP (src, 0, 1), descriptor, steps,
			   convert ? const0_rtx : XVECEXP (src, 0, 5));
			if (validate_change (insn, &PATTERN (insn), prepared, false))
			  {
			    df_insn_rescan (insn);
			    cleanup = true;
			    if (dump_file)
			      fprintf (dump_file, "Reuse Md for unary at insn %d\n",
				       INSN_UID (insn));
			  }
		      }
		    note_stores (insn, invalidate_md_store, &state);
		    /* Unary setup prepares each packet, not one combined group.  */
		    for (unsigned int i : { 1U, 0U })
		      {
			rtx reg = i ? XVECEXP (src, 0, 0) : SET_DEST (set);
			unsigned int count = m_nregs (GET_MODE (reg));
			unsigned int step = datatype_step (UINTVAL (steps), i);
			gcc_assert (step && count % step == 0);
			state.invalidate (reg);
			for (unsigned int r = 0; r < count; r += step)
			  state.remember
			    (gen_rtx_REG (matrix_mode (step), REGNO (reg) + r),
			     XVECEXP (src, 0, 1 + i));
		      }
		    continue;
		  }
		case UNSPECV_ZTT_STATE_ELEMENTWISE_M:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_X:
		case UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE:
		case UNSPECV_ZTT_STATE_TERNARY:
		case UNSPECV_ZTT_STATE_TERNARY_X:
		case UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE:
		case UNSPECV_ZTT_STATE_GATHER:
		case UNSPECV_ZTT_STATE_SCATTER:
		  {
		    bool old_dest = common_old_dest_p (XINT (src, 1));
		    bool scalar = common_scalar_p (XINT (src, 1));
		    bool prepared_p = GET_CODE (PATTERN (insn)) == SET;
		    rtx steps = XVECEXP (src, 0, prepared_p ? 6 : 7);
		    rtx regs[] = { SET_DEST (set), XVECEXP (src, 0, 0),
				   XVECEXP (src, 0, 1) };
		    rtx descriptors[] = { XVECEXP (src, 0, 2), XVECEXP (src, 0, 3),
					  XVECEXP (src, 0, 4) };
		    bool reuse_scalar = common_data_scalar_p (src, prepared_p)
		      && REG_P (descriptors[2])
		      && state.record_scalar_type (descriptors[2]);
		    unsigned int prepared = prepared_p ? 0
		      : state.prepared_inputs (regs, descriptors, UINTVAL (steps),
					       scalar, old_dest);
		    if (!prepared_p && prepared)
		      {
			bool changed = false;
			if (prepared == ((scalar ? 2U : 6U) | (old_dest ? 1U : 0U)))
			  {
			    int code = XINT (src, 1);
			    if (code != UNSPECV_ZTT_STATE_GATHER
				&& code != UNSPECV_ZTT_STATE_SCATTER)
			      code = old_dest
				? (scalar ? UNSPECV_ZTT_STATE_TERNARY_X
				   : UNSPECV_ZTT_STATE_TERNARY)
				: (scalar ? UNSPECV_ZTT_STATE_ELEMENTWISE_X
				   : UNSPECV_ZTT_STATE_ELEMENTWISE_M);
			    rtx pattern = old_dest
			      ? gen_ztt_state_common_old_prepared
				  (code, GET_MODE (regs[0]), Pmode, regs[0], regs[1],
				   regs[2], XVECEXP (src, 0, 2), XVECEXP (src, 0, 3),
				   XVECEXP (src, 0, 4), XVECEXP (src, 0, 6), steps,
				   XVECEXP (src, 0, 8))
			      : gen_ztt_state_common_prepared
				  (code, GET_MODE (regs[0]), Pmode, regs[0], regs[1],
				   regs[2], XVECEXP (src, 0, 2), XVECEXP (src, 0, 3),
				   XVECEXP (src, 0, 4), XVECEXP (src, 0, 6), steps);
			    changed = validate_change (insn, &PATTERN (insn),
					       pattern, false);
			    if (changed && dump_file)
			      fprintf (dump_file,
				       "Drop common preparation workspace at insn %d\n",
				       INSN_UID (insn));
			  }
			rtx *mask = &XVECEXP (src, 0, old_dest ? 9 : 8);
			if (!changed && UINTVAL (*mask) != prepared)
			  changed = validate_change (insn, mask, GEN_INT (prepared), false);
			if (changed)
			  {
			    df_insn_rescan (insn);
			    cleanup = true;
			    if (dump_file)
			      fprintf (dump_file,
				       "Reuse Md for common preparation at insn %d: %u\n",
				       INSN_UID (insn), prepared);
			  }
		      }
		    if (reuse_scalar)
		      {
			rtx current = SET_SRC (single_set (insn));
			/* Zero is a late marker, not a request to write zero to TC.  */
			if (validate_change (insn, &XVECEXP (current, 0, 4),
					     const0_rtx, false))
			  {
			    df_insn_rescan (insn);
			    cleanup = descriptor_cleanup = true;
			    if (dump_file)
			      fprintf (dump_file, "Reuse scalar datatype at insn %d\n",
				       INSN_UID (insn));
			  }
		      }
		    note_stores (insn, invalidate_md_store, &state);
		    /* Follow packet setup order; overlapping facts cannot coexist.  */
		    for (unsigned int pos = 0; pos < 3; ++pos)
		      {
			unsigned int i = old_dest ? pos : (pos + 1) % 3;
			if (scalar && i == 2)
			  continue;
			rtx reg = i ? XVECEXP (src, 0, i - 1) : SET_DEST (set);
			unsigned int count = m_nregs (GET_MODE (reg));
			unsigned int step = datatype_step (UINTVAL (steps), i);
			gcc_assert (step && count % step == 0);
			state.invalidate (reg);
			for (unsigned int r = 0; r < count; r += step)
			  state.remember
			    (gen_rtx_REG (matrix_mode (step), REGNO (reg) + r),
			     XVECEXP (src, 0, 2 + i));
		      }
		    continue;
		  }
		case UNSPECV_ZTT_STATE_ADD:
		case UNSPECV_ZTT_STATE_SUB:
		case UNSPECV_ZTT_STATE_MIN:
		case UNSPECV_ZTT_STATE_MAX:
		case UNSPECV_ZTT_STATE_AND:
		case UNSPECV_ZTT_STATE_ANDNOT:
		case UNSPECV_ZTT_STATE_OR:
		case UNSPECV_ZTT_STATE_ORNOT:
		case UNSPECV_ZTT_STATE_XOR:
		  {
		    /* The complete sources and result have the same Md.  */
		    descriptor = XVECEXP (src, 0, 2);
		    rtx lhs = XVECEXP (src, 0, 0), rhs = XVECEXP (src, 0, 1);
		    unsigned int mask = state.matches (lhs, descriptor)
		      | (state.matches (rhs, descriptor) << 1);
		    /* Preparing one complete group also prepares an identical input.  */
		    if (rtx_equal_p (lhs, rhs))
		      mask |= 2;
		    if (mask && XVECLEN (src, 0) > 3)
		      {
			bool changed;
			if (mask == 3)
			  {
			    rtx prepared = gen_ztt_state_prepared
			      (XINT (src, 1), GET_MODE (SET_DEST (set)), Pmode,
			       SET_DEST (set), lhs, rhs, descriptor);
			    changed = validate_change
			      (insn, &PATTERN (insn), prepared, false);
			  }
			else
			  changed = validate_change
			    (insn, &XVECEXP (src, 0, XVECLEN (src, 0) - 1),
			     GEN_INT (mask), false);
			gcc_assert (changed);
			df_insn_rescan (insn);
			cleanup = true;
			if (dump_file)
			  fprintf (dump_file,
				   "Reuse Md for binary at insn %d: sources %u\n",
				   INSN_UID (insn), mask);
		      }
		    note_stores (insn, invalidate_md_store, &state);
		    state.remember (lhs, descriptor);
		    state.remember (rhs, descriptor);
		    state.remember (SET_DEST (set), descriptor);
		    continue;
		  }
		case UNSPECV_ZTT_ACC_TO_M:
		  {
		    machine_mode mode = GET_MODE (XVECEXP (src, 0, 0));
		    unsigned int step = acc_m_nregs (mode);
		    unsigned int count = acc_full_m_nregs (mode);
		    rtx dest = SET_DEST (set);
		    gcc_assert (m_nregs (GET_MODE (dest)) == count);
		    note_stores (insn, invalidate_md_store, &state);
		    /* Each transfer packet establishes its own base Md.  */
		    for (unsigned int i = 0; i < count; i += step)
		      state.remember
			(gen_rtx_REG (matrix_mode (step), REGNO (dest) + i),
			 XVECEXP (src, 0, 1));
		    continue;
		  }
		case UNSPECV_ZTT_ACC_FROM_M:
		  if (XVECLEN (src, 0) == 4)
		    {
		      machine_mode mode = GET_MODE (SET_DEST (set));
		      unsigned int step = acc_m_nregs (mode);
		      group = XVECEXP (src, 0, 0);
		      descriptor = XVECEXP (src, 0, 1);
		      unsigned int count = m_nregs (GET_MODE (group));
		      gcc_assert (count == acc_full_m_nregs (mode));
		      if (state.matches_packets (group, descriptor, step))
			{
			  rtx prepared = gen_ztt_acc_from_m_prepared
			    (mode, Pmode, SET_DEST (set), group, descriptor);
			  bool changed = validate_change
			    (insn, &PATTERN (insn), prepared, false);
			  gcc_assert (changed);
			  df_insn_rescan (insn);
			  cleanup = true;
			  if (dump_file)
			    fprintf (dump_file, "Reuse Md for ACC move at insn %d\n",
				     INSN_UID (insn));
			}
		      note_stores (insn, invalidate_md_store, &state);
		      state.invalidate (group);
		      /* Preparation establishes Md for each source packet.  */
		      for (unsigned int i = 0; i < count; i += step)
			state.remember
			  (gen_rtx_REG (matrix_mode (step), REGNO (group) + i),
			   descriptor);
		      continue;
		    }
		  break;
		case UNSPECV_ZTT_ACC_ZERO:
		  {
		    rtx descriptor = XVECEXP (src, 0, 0);
		    unsigned int width
		      = integer_zero_width (state.descriptor_value (descriptor));
		    bool floating_zero = !width;
		    if (floating_zero)
		      width = floating_zero_width (state.descriptor_value (descriptor));
		    if (width)
		      {
			rtx clear = gen_ztt_acc_clear
			  (GET_MODE (SET_DEST (set)), Pmode,
			   SET_DEST (set), descriptor);
			if (validate_change (insn, &PATTERN (insn), clear, false))
			  {
			    df_insn_rescan (insn);
			    if (dump_file)
			      fprintf (dump_file, "Reuse %s ACC clear at insn %d\n",
				       floating_zero ? "floating" : "integer",
				       INSN_UID (insn));
			  }
		      }
		  }
		  gcc_fallthrough ();
		case UNSPECV_ZTT_ACC_CLEAR:
		  note_stores (insn, invalidate_md_store, &state);
		  continue;
		case UNSPECV_ZTT_ACC_MMUL:
		  {
		    if (XVECLEN (src, 0) != 7 && XVECLEN (src, 0) != 8)
		      break;
		    bool mixed = XVECLEN (src, 0) == 8;
		    rtx lhs = XVECEXP (src, 0, 1), rhs = XVECEXP (src, 0, 2);
		    rtx ld = XVECEXP (src, 0, 3);
		    rtx rd = mixed ? XVECEXP (src, 0, 6) : ld;
		    if (!REG_P (ld) || !REG_P (rd))
		      break;
		    if (reg_overlap_mentioned_p (lhs, rhs)
			&& (!rtx_equal_p (lhs, rhs) || !rtx_equal_p (ld, rd)))
		      break;
		    unsigned int mask = state.matches (lhs, ld)
		      | (state.matches (rhs, rd) << 1);
		    rtx *where = &XVECEXP (src, 0, mixed ? 7 : 6);
		    if (mask == 3)
		      {
			rtx prepared = gen_ztt_acc_mmul_prepared
			  (GET_MODE (SET_DEST (set)), SET_DEST (set),
			   XVECEXP (src, 0, 0), lhs, rhs, XVECEXP (src, 0, 4));
			bool changed = validate_change
			  (insn, &PATTERN (insn), prepared, false);
			gcc_assert (changed);
			df_insn_rescan (insn);
			cleanup = true;
		      }
		    else if (mask)
		      {
			bool changed = validate_change (insn, where, GEN_INT (mask), false);
			gcc_assert (changed);
			if (mixed)
			  {
			    /* The prepared side no longer consumes a descriptor.  */
			    rtx *unused = &XVECEXP (src, 0, mask == 1 ? 3 : 6);
			    changed = validate_change (insn, unused, const0_rtx, false);
			    gcc_assert (changed);
			    df_insn_rescan (insn);
			    cleanup = true;
			    if (dump_file)
			      fprintf (dump_file, "Drop unused Md descriptor at insn %d\n",
				       INSN_UID (insn));
			  }
		      }
		    if (mask && dump_file)
		      fprintf (dump_file, "Reuse Md at insn %d: sources %u\n",
			       INSN_UID (insn), mask);
		    note_stores (insn, invalidate_md_store, &state);
		    state.remember (lhs, ld);
		    state.remember (rhs, rd);
		    continue;
		  }
		default: break;
		}
	      if (group)
		{
		  bool store = XINT (src, 1) == UNSPECV_ZTT_STATE_STORE;
		  bool memory_store
		    = XINT (src, 1) == UNSPECV_ZTT_STATE_MEMORY_STORE;
		  if ((store || memory_store) && state.matches (group, descriptor))
		    {
		      rtx prepared = store
			? gen_ztt_state_store_prepared
			    (GET_MODE (group), SET_DEST (set), group)
			: gen_ztt_state_memory_store_prepared
			    (GET_MODE (group), Pmode, SET_DEST (set), group,
			     XVECEXP (src, 0, 1), XVECEXP (src, 0, 3));
		      bool changed = validate_change
			(insn, &PATTERN (insn), prepared, false);
		      gcc_assert (changed);
		      df_insn_rescan (insn);
		      cleanup = true;
		      if (dump_file)
			fprintf (dump_file, "Reuse Md for typed store at insn %d\n",
				 INSN_UID (insn));
		    }
		  note_stores (insn, invalidate_md_store, &state);
		  state.remember (group, descriptor);
		  continue;
		}
	    }
	  if (md_scalar_insn_p (PATTERN (insn)))
	    {
	      /* Evaluate the SET before invalidating its inputs.  */
	      rtx value = GET_CODE (PATTERN (insn)) == SET
		&& local_md_state::full_gpr_p (SET_DEST (set))
		? state.constant_value (SET_SRC (set)) : NULL_RTX;
	      unsigned int identity = state.copied_identity (PATTERN (insn));
	      note_stores (insn, invalidate_md_store, &state);
	      if (value)
		state.record_constant (SET_DEST (set), value);
	      else if (identity)
		state.record_copy (SET_DEST (set), identity);
	    }
	  else
	    state.clear ();
	}
    }
  /* Dropping private operands exposes dead address and stride calculations.  */
  if (cleanup)
    run_fast_dce ();
  if (riscv_ztt_remove_unused_workspace ())
    {
      cleanup = descriptor_cleanup = true;
      run_fast_dce ();
    }
  if (cleanup)
    {
      if (reuse_cleaned_descriptors ())
	{
	  descriptor_cleanup = true;
	  run_fast_dce ();
	  if (dump_file)
	    fprintf (dump_file, "Reuse descriptors after workspace cleanup\n");
	}
      if (descriptor_cleanup)
	{
	  df_note_add_problem ();
	  df_analyze ();
	}
      return TODO_df_finish;
    }
  return 0;
}

#if CHECKING_P
static void
run_md_reuse_selftests ()
{
  using namespace selftest;
  {
    rtl_dump_test t (SELFTEST_LOCATION, locate_file ("riscv/empty-func.rtl"));
    local_md_state state;
    rtx reg = gen_rtx_REG (Pmode, 10);
    rtx copy = gen_rtx_REG (Pmode, 11);
    rtx matrix = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
    rtx_insn *read = emit_insn
      (Pmode == DImode ? gen_riscv_ztt_read_amefflags_di (reg)
       : gen_riscv_ztt_read_amefflags_si (reg));
    ASSERT_TRUE (md_read_csr_p (CODE_FOR_riscv_ztt_read_amefflags_si));
    ASSERT_TRUE (md_read_csr_p (CODE_FOR_riscv_ztt_read_amefflags_di));
    if (TARGET_ZTT && TARGET_ZICSR)
      ASSERT_TRUE (md_read_csr_p (recog_memoized (read)));
    ASSERT_FALSE (md_read_csr_p (-1));
    ASSERT_FALSE (md_read_csr_p (CODE_FOR_riscv_ztt_none));
    ASSERT_FALSE (md_read_csr_p (CODE_FOR_riscv_ztt_release));
    ASSERT_FALSE (md_read_csr_p (CODE_FOR_riscv_ztt_acquire_si));
    ASSERT_FALSE (md_read_csr_p (CODE_FOR_riscv_ztt_acquire_di));
    state.record_constant (reg, GEN_INT (32));
    state.record_constant (copy, GEN_INT (32));
    state.remember (matrix, reg);
    note_stores (read, invalidate_md_store, &state);
    ASSERT_RTX_EQ (state.descriptor_value (reg), reg);
    ASSERT_TRUE (state.matches (matrix, copy));
    ASSERT_FALSE (state.matches (matrix, reg));
    state.clear ();
    state.remember (matrix, reg);
    state.record_copy (copy, state.descriptor_identity (reg));
    note_stores (read, invalidate_md_store, &state);
    ASSERT_TRUE (state.matches (matrix, copy));
    ASSERT_FALSE (state.matches (matrix, reg));
  }
  {
    rtl_dump_test t (SELFTEST_LOCATION, locate_file ("riscv/empty-func.rtl"));
    rtx reg = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
    rtx mem = gen_rtx_MEM (ZTTMR1mode, gen_rtx_REG (Pmode, 10));
    set_mem_attrs_for_spill (mem);
    rtx store = gen_rtx_SET (mem, reg), load = gen_rtx_SET (reg, mem);
    local_raw_spill spill;
    ASSERT_FALSE (spill.redundant_reload_p (load));
    ASSERT_FALSE (spill.redundant_reload_p (store));
    ASSERT_TRUE (spill.redundant_reload_p (load));
    ASSERT_FALSE (spill.redundant_reload_p
	(gen_rtx_SET (gen_rtx_REG (Pmode, 11), GEN_INT (32))));
    ASSERT_TRUE (spill.redundant_reload_p (load));
    spill.clear ();
    ASSERT_FALSE (spill.redundant_reload_p (load));
    for (unsigned int test = 0; test != 8; ++test)
      {
	rtx other = copy_rtx (mem);
	switch (test)
	  {
	  case 0: MEM_VOLATILE_P (other) = 1; break;
	  case 1: MEM_NOTRAP_P (other) = 0; break;
	  case 2: set_mem_expr (other, NULL_TREE); break;
	  case 3: clear_mem_offset (other); break;
	  case 4: clear_mem_size (other); break;
	  case 5: set_mem_size (other, 1); break;
	  case 6: set_mem_offset (other, 16); break;
	  case 7: XEXP (other, 0) = gen_rtx_REG (Pmode, 11); break;
	  }
	spill.clear ();
	ASSERT_FALSE (spill.redundant_reload_p (store));
	ASSERT_FALSE (spill.redundant_reload_p (gen_rtx_SET (reg, other)));
	ASSERT_FALSE (spill.redundant_reload_p (gen_rtx_SET (other, reg)));
	ASSERT_FALSE (spill.redundant_reload_p (load));
      }
    rtx other_reg = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 1);
    rtx addr = XEXP (mem, 0);
    for (rtx gap : {
	   gen_rtx_SET (addr, GEN_INT (16)),
	   gen_rtx_SET (gen_rtx_REG (SImode, 10), const0_rtx),
	   gen_rtx_SET (stack_pointer_rtx, addr),
	   gen_rtx_SET (hard_frame_pointer_rtx, addr),
	   gen_rtx_SET (reg, other_reg),
	   gen_rtx_SET (other_reg, mem),
	   gen_rtx_SET (gen_rtx_MEM (Pmode, addr), const0_rtx),
	   gen_rtx_SET (gen_rtx_REG (Pmode, 11), gen_rtx_MEM (Pmode, addr)),
	   gen_rtx_UNSPEC_VOLATILE (VOIDmode, gen_rtvec (1, addr), UNSPECV_ZTT),
	   gen_rtx_ASM_INPUT (VOIDmode, "") })
      {
	ASSERT_FALSE (spill.redundant_reload_p (store));
	ASSERT_FALSE (spill.redundant_reload_p (gap));
	ASSERT_FALSE (spill.redundant_reload_p (load));
      }
  }
  for (int code : { UNSPECV_ZTT_STATE_ELEMENTWISE_X,
		   UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE,
		   UNSPECV_ZTT_STATE_TERNARY_X,
		   UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE,
		   UNSPECV_ZTT_STATE_ELEMENTWISE_M, UNSPECV_ZTT_STATE_TERNARY })
    for (unsigned int variant = 0; variant <= 41; ++variant)
      for (bool prepared : { false, true })
	{
	  rtvec args = gen_rtvec (8, const0_rtx, const0_rtx, const0_rtx,
				 const0_rtx, const0_rtx, const0_rtx,
				 const0_rtx, const0_rtx);
	  RTVEC_ELT (args, prepared ? 5 : 6) = GEN_INT (variant);
	  bool data = code == UNSPECV_ZTT_STATE_ELEMENTWISE_X
	    || code == UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE
	    ? IN_RANGE (variant, 13, 26) || IN_RANGE (variant, 29, 30)
	      || IN_RANGE (variant, 39, 40)
	    : ((code == UNSPECV_ZTT_STATE_TERNARY_X
		|| code == UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE) && variant < 4);
	  ASSERT_EQ (common_data_scalar_p
	    (gen_rtx_UNSPEC_VOLATILE (VOIDmode, args, code), prepared), data);
	}
  {
    local_md_state state;
    rtx a = gen_rtx_REG (Pmode, GP_REG_FIRST + 5);
    rtx b = gen_rtx_REG (Pmode, GP_REG_FIRST + 6);
    rtx tc = GEN_INT (0x48000020);
    ASSERT_FALSE (state.record_scalar_type (a));
    state.record_constant (a, tc);
    ASSERT_FALSE (state.record_scalar_type (a));
    ASSERT_TRUE (state.record_scalar_type (a));
    state.invalidate (a);
    state.record_constant (b, tc);
    ASSERT_TRUE (state.record_scalar_type (b));
    ASSERT_FALSE (state.record_scalar_type (a));
    ASSERT_FALSE (state.record_scalar_type (b));
    state.record_constant (b, GEN_INT (0x50000020));
    ASSERT_FALSE (state.record_scalar_type (b));
    state.clear ();
    state.record_constant (b, tc);
    ASSERT_FALSE (state.record_scalar_type (b));
  }
  for (unsigned int variant = 0; variant <= 41; ++variant)
    {
      ASSERT_EQ (scalar_operand_p (const0_rtx, variant, false),
		 variant == 1 || variant == 3 || variant == 5 || variant == 41
		 || IN_RANGE (variant, 13, 26) || IN_RANGE (variant, 29, 30)
		 || IN_RANGE (variant, 39, 40));
      ASSERT_EQ (scalar_operand_p (const0_rtx, variant, true), variant <= 4);
      ASSERT_FALSE (scalar_operand_p (const1_rtx, variant, false));
      ASSERT_FALSE (scalar_operand_p (const1_rtx, variant, true));
    }
  const machine_mode scalar_modes[]
    = { QImode, HImode, SImode, DImode, SFmode, DFmode };
  for (machine_mode mode : scalar_modes)
    {
      rtx reg = gen_raw_REG (mode, LAST_VIRTUAL_REGISTER + 1);
      bool data = mode == Pmode || mode == QImode || mode == HImode
	|| mode == SImode;
      for (unsigned int variant : { 13U, 21U, 22U, 26U, 29U, 30U, 39U, 40U })
	ASSERT_EQ (scalar_operand_p (reg, variant, false), data);
      for (unsigned int variant : { 1U, 3U, 5U, 41U })
	ASSERT_EQ (scalar_operand_p (reg, variant, false), mode == Pmode);
      for (unsigned int variant = 0; variant < 4; ++variant)
	ASSERT_EQ (scalar_operand_p (reg, variant, true), data);
      ASSERT_EQ (scalar_operand_p (reg, 4, true), mode == Pmode);
    }
  const machine_mode float_modes[] = { HFmode, BFmode, SFmode, DFmode };
  for (machine_mode mode : float_modes)
    {
      rtx reg = gen_raw_REG (mode, LAST_VIRTUAL_REGISTER + 1);

      if (mode == HFmode || mode == BFmode)
	{
	  rtx view = gen_rtx_SUBREG (HImode, reg, 0);
	  ASSERT_FALSE (scalar_operand_p (view, 13, false));
	  ASSERT_FALSE (scalar_operand_p (view, 0, true));
	}
      if (mode == SFmode)
	{
	  rtx view = gen_rtx_SUBREG (SImode, reg, 0);
	  ASSERT_EQ (scalar_operand_p (view, 13, false), SImode == Pmode);
	  ASSERT_EQ (scalar_operand_p (view, 0, true), SImode == Pmode);
	}
      ASSERT_TRUE (scalar_operand_p (gen_rtx_SUBREG (Pmode, reg, 0),
				     13, false));
    }
  rtx integer = gen_raw_REG (DImode, LAST_VIRTUAL_REGISTER + 1);
  for (machine_mode narrow : { QImode, HImode, SImode })
    {
      rtx view = gen_rtx_SUBREG (narrow, integer, 0);
      ASSERT_TRUE (scalar_operand_p (view, 13, false));
      ASSERT_TRUE (scalar_operand_p (view, 0, true));
      ASSERT_EQ (scalar_operand_p (view, 41, false), narrow == Pmode);
    }
  for (unsigned int width = 4; width <= 128; width *= 2)
    for (unsigned int properties = 0; properties < 16; ++properties)
      ASSERT_EQ (integer_zero_width
	(GEN_INT ((HOST_WIDE_INT) properties << 27 | width)), width);
  for (unsigned int width : { 0U, 1U, 2U, 3U, 5U, 7U, 12U, 129U, 255U })
    ASSERT_EQ (integer_zero_width (GEN_INT (width)), 0U);
  for (unsigned int bit = 8; bit < 64; ++bit)
    if (bit < 27 || bit > 30)
      ASSERT_EQ (integer_zero_width
	(GEN_INT ((HOST_WIDE_INT_1U << bit) | 32)), 0U);
  ASSERT_EQ (integer_zero_width (gen_rtx_REG (Pmode, 10)), 0U);
  for (unsigned int base : { 0x14300110U, 0x20300110U,
			    0x20300120U, 0x2c300140U })
    for (unsigned int rm = 0; rm < 16; ++rm)
      {
	unsigned HOST_WIDE_INT descriptor = base | (rm << 22);
	ASSERT_EQ (floating_zero_width (GEN_INT (descriptor)),
		   rm < 6 ? base & 0xff : 0U);
	ASSERT_EQ (integer_zero_width (GEN_INT (descriptor)), 0U);
	for (unsigned int bit = 0; bit < 64; ++bit)
	  if (bit < 22 || bit > 25)
	    ASSERT_EQ (floating_zero_width
	      (GEN_INT (descriptor ^ (HOST_WIDE_INT_1U << bit))), 0U);
      }
  for (unsigned int width = 4; width <= 128; width *= 2)
    for (unsigned int properties = 0; properties < 16; ++properties)
      ASSERT_EQ (floating_zero_width
	(GEN_INT ((HOST_WIDE_INT) properties << 27 | width)), 0U);
  ASSERT_EQ (floating_zero_width (gen_rtx_REG (Pmode, 10)), 0U);
  for (unsigned int source : { 0x14300110U, 0x20300110U,
			      0x20300120U, 0x2c300140U })
    for (unsigned int destination : { 0x14300110U, 0x20300110U,
				     0x20300120U, 0x2c300140U })
      for (unsigned int src_rm = 0; src_rm < 16; ++src_rm)
	for (unsigned int dst_rm = 0; dst_rm < 16; ++dst_rm)
	  ASSERT_EQ (zero_broadcast_types_p
	    (GEN_INT (source | src_rm << 22),
	     GEN_INT (destination | dst_rm << 22)),
	    source == destination && src_rm < 6 && dst_rm < 6);
  ASSERT_TRUE (zero_broadcast_types_p (GEN_INT (0x58000004),
				     GEN_INT (0x20000080)));
  ASSERT_FALSE (zero_broadcast_types_p (GEN_INT (0x20300120), GEN_INT (32)));
  ASSERT_FALSE (zero_broadcast_types_p (GEN_INT (32), GEN_INT (0x20300120)));
  ASSERT_FALSE (zero_broadcast_types_p (gen_rtx_REG (Pmode, 10),
				      GEN_INT (0x20300120)));
  ASSERT_FALSE (zero_broadcast_types_p (GEN_INT (0x20300120),
				      gen_rtx_REG (Pmode, 10)));
  int saved_reload_completed = reload_completed;
  rtx operands[] = { gen_rtx_REG (ZTTMR1mode, M_REG_FIRST),
		     gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 1),
		     gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 2) };
  reload_completed = 1;
  ASSERT_EQ (binary_state_length (operands, 0), 32U);
  ASSERT_EQ (binary_state_length (operands, 1), 20U);
  ASSERT_EQ (binary_state_length (operands, 2), 20U);
  ASSERT_EQ (binary_state_length (operands, 3), 8U);
  operands[0] = operands[1] = gen_rtx_REG (ZTTMR8mode, M_REG_FIRST);
  operands[2] = gen_rtx_REG (ZTTMR8mode, M_REG_FIRST + 8);
  ASSERT_EQ (binary_state_length (operands, 0), 268U);
  ASSERT_EQ (binary_state_length (operands, 1), 136U);
  ASSERT_EQ (binary_state_length (operands, 2), 136U);
  ASSERT_EQ (binary_state_length (operands, 3), 4U);
  operands[0] = operands[2];
  ASSERT_EQ (binary_state_length (operands, 3), 4U);
  for (machine_mode mode : { ZTTMR1mode, ZTTMR2mode, ZTTMR4mode,
			    ZTTMR8mode, ZTTMR16mode })
    {
      unsigned int count = m_nregs (mode);
      rtx rowcol[] = { gen_rtx_REG (mode, M_REG_FIRST),
		       gen_rtx_REG (mode, M_REG_FIRST + count) };
      ASSERT_EQ (rowcol_length (rowcol, true), 8U);
      ASSERT_EQ (rowcol_length (rowcol),
		  4U * (3U + (count == 1 ? 2U : 4U * count)));
      rowcol[0] = rowcol[1];
      ASSERT_EQ (rowcol_length (rowcol, true), 4U);
      ASSERT_EQ (rowcol_length (rowcol),
		  4U * (2U + (count == 1 ? 2U : 4U * count)));
    }
  reload_completed = 0;
  ASSERT_EQ (binary_state_length (operands, 3), 8U);
  ASSERT_EQ (rowcol_length (operands, true), 8U);
  reload_completed = saved_reload_completed;
  local_md_state state;
  rtx raw_reg = gen_rtx_REG (ZTTMR1mode, M_REG_FIRST);
  {
    rtx a = gen_rtx_REG (Pmode, 10), b = gen_rtx_REG (Pmode, 11);
    rtx d = gen_rtx_REG (Pmode, 12);
    auto copy = [&state] (rtx dest, rtx src) {
      unsigned int identity = state.copied_identity (gen_rtx_SET (dest, src));
      state.invalidate (dest);
      if (identity)
	state.record_copy (dest, identity);
    };
    for (bool before : { false, true })
      {
	state.clear ();
	if (before)
	  copy (b, a);
	state.remember (raw_reg, a);
	if (!before)
	  copy (b, a);
	ASSERT_TRUE (state.matches (raw_reg, b));
	copy (d, b);
	copy (b, b);
	ASSERT_TRUE (state.matches (raw_reg, b));
	state.invalidate (a);
	ASSERT_FALSE (state.matches (raw_reg, a));
	ASSERT_TRUE (state.matches (raw_reg, b));
	state.invalidate (gen_rtx_SUBREG (QImode, b, 0));
	ASSERT_FALSE (state.matches (raw_reg, b));
	ASSERT_TRUE (state.matches (raw_reg, d));
	copy (b, a);
	ASSERT_FALSE (state.matches (raw_reg, b));
	copy (d, b);
	ASSERT_FALSE (state.matches (raw_reg, d));
      }
    state.clear ();
    state.remember (raw_reg, a);
    for (rtx src : { gen_rtx_MEM (Pmode, a),
		    gen_rtx_PLUS (Pmode, a, const1_rtx),
		    gen_rtx_REG (QImode, 10) })
      ASSERT_EQ (state.copied_identity (gen_rtx_SET (b, src)), 0U);
    ASSERT_EQ (state.copied_identity
      (gen_rtx_SET (gen_rtx_REG (QImode, 11), a)), 0U);
    ASSERT_EQ (state.copied_identity
      (gen_rtx_PARALLEL (VOIDmode, gen_rtvec (1, gen_rtx_SET (b, a)))), 0U);
    if (TARGET_64BIT)
      ASSERT_EQ (state.copied_identity
	(gen_rtx_SET (gen_rtx_REG (SImode, 11), gen_rtx_REG (SImode, 10))), 0U);
    copy (b, a);
    state.record_constant (a, const1_rtx);
    ASSERT_FALSE (state.matches (raw_reg, a));
    ASSERT_TRUE (state.matches (raw_reg, b));
    state.invalidate (raw_reg);
    ASSERT_FALSE (state.matches (raw_reg, b));
    state.remember (raw_reg, b);
    state.clear ();
    copy (a, b);
    ASSERT_FALSE (state.matches (raw_reg, a));
    state.clear ();
  }
  rtx raw_mem = gen_rtx_MEM (ZTTMR1mode, gen_rtx_REG (Pmode, 10));
  ASSERT_TRUE (md_raw_transfer_p (gen_rtx_SET (raw_reg, raw_mem)));
  ASSERT_TRUE (md_raw_transfer_p (gen_rtx_SET (raw_mem, raw_reg)));
  ASSERT_FALSE (md_raw_transfer_p (gen_rtx_SET (raw_reg, raw_reg)));
  ASSERT_FALSE (md_raw_transfer_p
    (gen_rtx_SET (raw_reg, gen_rtx_MEM (ZTTMR2mode, XEXP (raw_mem, 0)))));
  ASSERT_FALSE (md_raw_transfer_p
    (gen_rtx_SET (raw_reg, gen_rtx_MEM (ZTTMR1mode,
	gen_rtx_POST_INC (Pmode, XEXP (raw_mem, 0))))));
  ASSERT_FALSE (md_raw_transfer_p
    (gen_rtx_SET (gen_rtx_REG (ZTTMR1mode, ACC_REG_FIRST), raw_mem)));
  rtx group = gen_rtx_REG (ZTTMR2mode, M_REG_FIRST);
  rtx desc = gen_rtx_REG (SImode, 10);
  state.remember (group, desc);
  ASSERT_TRUE (state.matches (group, desc));
  ASSERT_FALSE (state.matches (gen_rtx_REG (ZTTMR1mode, M_REG_FIRST), desc));
  ASSERT_FALSE (state.matches (group, gen_rtx_REG (SImode, 11)));
  state.invalidate (gen_rtx_REG (SImode, 11));
  ASSERT_TRUE (state.matches (group, desc));
  state.invalidate (desc);
  ASSERT_FALSE (state.matches (group, desc));
  state.remember (group, desc);
  state.invalidate (gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 1));
  ASSERT_FALSE (state.matches (group, desc));
  state.remember (group, desc);
  state.remember (gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 1), desc);
  ASSERT_FALSE (state.matches (group, desc));
  state.clear ();
  ASSERT_FALSE (state.matches (gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + 1), desc));
  const char *saved_profile = riscv_ztt_profile_string;
  riscv_ztt_profile_string = "gcc-runtime-u32-m32-a16";
  for (unsigned int count : { 1U, 2U, 4U, 8U, 16U, 32U })
    for (unsigned int step = 1; step <= count && step <= 16; step *= 2)
      {
	rtx all = gen_rtx_REG (matrix_mode (count), M_REG_FIRST);
	state.clear ();
	ASSERT_FALSE (state.matches_packets (all, desc, step));
	for (unsigned int i = 0; i < count; i += step)
	  {
	    rtx part = gen_rtx_REG (matrix_mode (step), M_REG_FIRST + i);
	    state.remember (part, desc);
	    ASSERT_EQ (state.matches_packets (all, desc, step), i + step == count);
	  }
	ASSERT_FALSE (state.matches_packets (all, gen_rtx_REG (SImode, 11), step));
	state.invalidate (gen_rtx_REG (ZTTMR1mode, M_REG_FIRST + count - 1));
	ASSERT_FALSE (state.matches_packets (all, desc, step));
	state.remember (all, desc);
	ASSERT_EQ (state.matches_packets (all, desc, step), step == count);
	state.clear ();
	ASSERT_FALSE (state.matches_packets (all, desc, step));
      }
  ASSERT_FALSE (state.matches_packets (group, desc, 0));
  ASSERT_FALSE (state.matches_packets (group, desc, 3));
  ASSERT_FALSE (state.matches_packets (desc, desc, 1));
  ASSERT_FALSE (state.matches_packets (const0_rtx, desc, 1));
  for (unsigned int count : { 2U, 4U, 8U, 16U })
    {
      rtx whole = gen_rtx_REG (matrix_mode (count), M_REG_FIRST);
      rtx apart = gen_rtx_REG (matrix_mode (count), M_REG_FIRST + count);
      rtx part = gen_rtx_REG (matrix_mode (count / 2), M_REG_FIRST);
      rtx groups[] = { whole, whole, apart };
      rtx descriptors[] = { desc, desc, desc };
      unsigned int steps = pack_datatype_steps (count, count, count);
      state.clear ();
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, true, true), 2U);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, true, false), 0U);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, false, true), 2U);
      state.remember (whole, desc);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, true, true), 3U);
      state.clear ();
      descriptors[1] = gen_rtx_REG (SImode, 11);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, true, true), 0U);
      descriptors[1] = desc;
      ASSERT_EQ (state.prepared_inputs (groups, descriptors,
	pack_datatype_steps (count, count / 2), true, true), 0U);
      groups[1] = apart;
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, true, true), 0U);
      groups[2] = whole;
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, false, true), 4U);
      groups[1] = whole;
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, false, true), 6U);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, steps, false, false), 4U);
      groups[1] = part;
      unsigned int partial_steps = pack_datatype_steps (count, count / 2, count);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, partial_steps, false, true), 0U);
      state.remember (whole, desc);
      ASSERT_EQ (state.prepared_inputs
	(groups, descriptors, partial_steps, false, true), 1U);
    }
  riscv_ztt_profile_string = saved_profile;
  ASSERT_FALSE (md_scalar_insn_p (gen_rtx_ASM_INPUT (VOIDmode, "")));
  ASSERT_FALSE (md_scalar_insn_p (gen_rtx_POST_INC (SImode, desc)));
  ASSERT_FALSE (md_scalar_insn_p
    (gen_rtx_COND_EXEC (VOIDmode, const1_rtx, gen_rtx_SET (desc, const0_rtx))));

  rtx a = gen_rtx_REG (Pmode, 10), b = gen_rtx_REG (Pmode, 11);
  rtx base = GEN_INT (0x40000000), dtype = GEN_INT (0x40000020);
  state.record_constant (a, base);
  rtx sum = state.constant_value (gen_rtx_PLUS (Pmode, a, GEN_INT (32)));
  ASSERT_TRUE (rtx_equal_p (sum, dtype));
  state.invalidate (a);
  state.record_constant (a, sum);
  state.remember (group, a);
  state.record_constant (b, state.constant_value (a));
  ASSERT_TRUE (state.matches (group, b));
  state.invalidate (a);
  ASSERT_TRUE (state.matches (group, b));
  ASSERT_FALSE (state.matches (group, a));
  state.record_constant (a, GEN_INT (0x40000021));
  ASSERT_FALSE (state.matches (group, a));
  state.invalidate (b);
  ASSERT_FALSE (state.matches (group, b));
  ASSERT_EQ (state.constant_value (gen_rtx_MEM (Pmode, a)), NULL_RTX);
  ASSERT_EQ (state.constant_value (b), NULL_RTX);
  state.record_constant (b, constm1_rtx);
  ASSERT_EQ (state.constant_value (gen_rtx_PLUS (Pmode, b, const1_rtx)), const0_rtx);
  state.invalidate (gen_rtx_SUBREG (QImode, b, 0));
  ASSERT_EQ (state.constant_value (b), NULL_RTX);
  if (TARGET_64BIT)
    {
      rtx si = gen_rtx_REG (SImode, REGNO (b));
      ASSERT_EQ (state.broadcast_value (si), si);
      state.record_constant (b, GEN_INT (HOST_WIDE_INT_C (0x100000000)));
      ASSERT_EQ (state.broadcast_value (si), const0_rtx);
      ASSERT_EQ (state.descriptor_value (si), si);
      ASSERT_TRUE (rtx_equal_p (state.descriptor_value (b),
			      GEN_INT (HOST_WIDE_INT_C (0x100000000))));
      state.invalidate (si);
      ASSERT_EQ (state.broadcast_value (si), si);
      state.record_constant (b, GEN_INT (HOST_WIDE_INT_C (0x180000000)));
      ASSERT_TRUE (rtx_equal_p (state.broadcast_value (si),
			      GEN_INT (-HOST_WIDE_INT_C (0x80000000))));
      rtx low = gen_rtx_SUBREG (SImode, b, 0);
      ASSERT_TRUE (rtx_equal_p
	(state.constant_value (gen_rtx_SIGN_EXTEND (DImode, low)),
	 GEN_INT (-HOST_WIDE_INT_C (0x80000000))));
      state.invalidate (gen_rtx_REG (SImode, REGNO (b)));
      ASSERT_EQ (state.constant_value (b), NULL_RTX);
    }
  state.clear ();
  ASSERT_EQ (state.broadcast_value (gen_rtx_REG (SImode, GP_REG_FIRST)),
	     const0_rtx);
  for (machine_mode mode : { QImode, HImode })
    {
      rtx narrow = gen_rtx_REG (mode, REGNO (b));
      ASSERT_EQ (state.broadcast_value (narrow), narrow);
      state.record_constant (b, GEN_INT (0x10000));
      ASSERT_EQ (state.broadcast_value (narrow), const0_rtx);
      ASSERT_EQ (state.descriptor_value (narrow), narrow);
      ASSERT_TRUE (rtx_equal_p (state.descriptor_value (b), GEN_INT (0x10000)));
      state.record_constant (b, GEN_INT (0x1ffff));
      ASSERT_EQ (state.broadcast_value (narrow), constm1_rtx);
      state.invalidate (narrow);
      ASSERT_EQ (state.broadcast_value (narrow), narrow);
      ASSERT_EQ (state.descriptor_value (b), b);
      ASSERT_EQ (state.broadcast_value (gen_rtx_REG (mode, GP_REG_FIRST)),
		 const0_rtx);
    }
  ASSERT_EQ (state.constant_value (a), NULL_RTX);
  ASSERT_FALSE (state.matches (group, a));

  rtx use_b = gen_rtx_USE (VOIDmode, b);
  state.record_constant (a, dtype);
  state.record_constant (b, dtype);
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  state.note_descriptor_use (a);
  ASSERT_TRUE (rtx_equal_p (state.descriptor_register (b, use_b), a));
  ASSERT_TRUE (state.redundant_descriptor_p (a, dtype));
  ASSERT_FALSE (state.redundant_descriptor_p (b, dtype));
  ASSERT_FALSE (state.redundant_descriptor_p (a, NULL_RTX));
  ASSERT_FALSE (state.redundant_descriptor_p (a, b));
  ASSERT_FALSE (state.redundant_descriptor_p (a, GEN_INT (0x40000021)));
  ASSERT_FALSE (state.redundant_descriptor_p
    (gen_rtx_REG (QImode, REGNO (a)), dtype));
  ASSERT_EQ (state.descriptor_register (a, use_b), a);
  ASSERT_EQ (state.descriptor_register (b, gen_rtx_CLOBBER (VOIDmode, a)), b);
  ASSERT_EQ (state.descriptor_register (b, gen_rtx_SET (b, const0_rtx)), b);
  auto saved_fixed = fixed_regs[REGNO (a)];
  fixed_regs[REGNO (a)] = 1;
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  ASSERT_FALSE (state.redundant_descriptor_p (a, dtype));
  fixed_regs[REGNO (a)] = saved_fixed;
  auto saved_global = global_regs[REGNO (a)];
  global_regs[REGNO (a)] = 1;
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  ASSERT_FALSE (state.redundant_descriptor_p (a, dtype));
  global_regs[REGNO (a)] = saved_global;
  state.record_constant (a, GEN_INT (0x40000021));
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  if (TARGET_64BIT)
    {
      state.record_constant (a, GEN_INT (HOST_WIDE_INT_C (0x140000020)));
      ASSERT_EQ (state.descriptor_register (b, use_b), b);
    }
  state.record_constant (a, dtype);
  state.invalidate (gen_rtx_SUBREG (QImode, a, 0));
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  ASSERT_FALSE (state.redundant_descriptor_p (a, dtype));
  state.clear ();
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  ASSERT_FALSE (state.redundant_descriptor_p (a, dtype));
  state.record_constant (b, dtype);
  state.note_descriptor_use (b);
  state.record_constant (a, dtype);
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  ASSERT_TRUE (rtx_equal_p (state.descriptor_register (a, use_b), b));
  state.clear ();
  state.record_constant (a, dtype);
  state.note_descriptor_use (a);
  state.record_constant (a, dtype);
  state.record_constant (b, dtype);
  ASSERT_EQ (state.descriptor_register (b, use_b), b);
  rtx shared[] = { group, group };
  rtx descriptors[] = { a, b };
  unsigned int steps = pack_datatype_steps (2, 2);
  ASSERT_EQ (state.prepared_inputs
    (shared, descriptors, steps, true, true), 2U);
  state.record_constant (a, GEN_INT (0x40000021));
  ASSERT_EQ (state.prepared_inputs
    (shared, descriptors, steps, true, true), 0U);
  state.invalidate (a);
  ASSERT_EQ (state.prepared_inputs
    (shared, descriptors, steps, true, true), 0U);
}
#endif

const pass_data pass_data_ztt_md_reuse =
{
  RTL_PASS, "ztt_md_reuse", OPTGROUP_NONE, TV_MACH_DEP,
  0, 0, 0, 0, 0
};

class pass_ztt_md_reuse : public rtl_opt_pass
{
public:
  pass_ztt_md_reuse (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_ztt_md_reuse, ctxt)
  {}
  bool gate (function *) final override
  {
    return optimize && TARGET_ZTT && typed_profile_p () && reload_completed;
  }
  unsigned int execute (function *) final override { return reuse_local_md (); }
};

const char *
mangle_builtin_type (const_tree type)
{
  if (TYPE_NAME (type) && TREE_CODE (TYPE_NAME (type)) == TYPE_DECL)
    type = TREE_TYPE (TYPE_NAME (type));
  if (tree attr = lookup_type_attribute (type))
    if (tree id = TREE_VALUE (chain_index (0, TREE_VALUE (attr))))
      return IDENTIFIER_POINTER (id);
  return nullptr;
}

bool
builtin_type_p (const_tree type)
{
  return type != nullptr && lookup_type_attribute (type) != NULL_TREE;
}

bool
verify_type_context (location_t loc, type_context_kind context,
		     const_tree type, bool silent_p)
{
  const_tree original_type = type;
  if (omp_type_context (context) && POINTER_TYPE_P (type))
    type = strip_pointer_types (type);

  if (type == error_mark_node
      || !lookup_attribute ("Ztt sizeless type", TYPE_ATTRIBUTES (type)))
    return true;

  switch (context)
    {
    case TCTX_SIZEOF:
    case TCTX_STATIC_STORAGE:
      if (!silent_p)
	error_at (loc, "AME/Ztt type %qT does not have a fixed C object size",
		  original_type);
      return false;
    case TCTX_ALIGNOF:
      if (!silent_p)
	error_at (loc, "AME/Ztt type %qT does not have a defined C alignment",
		  original_type);
      return false;
    case TCTX_THREAD_STORAGE:
      if (!silent_p)
	error_at (loc, "variables of AME/Ztt type %qT cannot have thread-local"
		  " storage duration", original_type);
      return false;
    case TCTX_POINTER_ARITH:
      if (!silent_p)
	error_at (loc, "arithmetic on pointer to AME/Ztt type %qT",
		  original_type);
      return false;
    case TCTX_DEREFERENCE:
      if (!silent_p)
	error_at (loc, "cannot dereference pointer to AME/Ztt type %qT",
		  original_type);
      return false;
    case TCTX_FIELD:
      if (silent_p)
	;
      else if (lang_GNU_CXX ())
	error_at (loc, "member variables cannot have AME/Ztt type %qT",
		  original_type);
      else
	error_at (loc, "fields cannot have AME/Ztt type %qT", original_type);
      return false;
    case TCTX_ARRAY_ELEMENT:
      if (!silent_p)
	error_at (loc, "array elements cannot have AME/Ztt type %qT",
		  original_type);
      return false;
    case TCTX_ALLOCATION:
      if (!silent_p)
	error_at (loc, "cannot allocate objects with AME/Ztt type %qT",
		  original_type);
      return false;
    case TCTX_DEALLOCATION:
      if (!silent_p)
	error_at (loc, "cannot delete objects with AME/Ztt type %qT",
		  original_type);
      return false;
    case TCTX_EXCEPTIONS:
      if (!silent_p)
	error_at (loc, "cannot throw or catch AME/Ztt type %qT", original_type);
      return false;
    case TCTX_CAPTURE_BY_COPY:
      if (!silent_p)
	error_at (loc, "capture by copy of AME/Ztt type %qT", original_type);
      return false;
    case TCTX_OMP_MAP:
      if (!silent_p)
	error_at (loc, "AME/Ztt type %qT is not allowed in a %<map%> clause",
		  original_type);
      return false;
    case TCTX_OMP_MAP_IMP_REF:
      if (!silent_p)
	error_at (loc, "cannot reference AME/Ztt type %qT in a %<target%>"
		  " region", original_type);
      return false;
    case TCTX_OMP_PRIVATE:
      if (!silent_p)
	error_at (loc, "AME/Ztt type %qT is not allowed in a %<target%>"
		  " %<private%> clause", original_type);
      return false;
    case TCTX_OMP_FIRSTPRIVATE:
      if (!silent_p)
	error_at (loc, "AME/Ztt type %qT is not allowed in a %<target%>"
		  " %<firstprivate%> clause", original_type);
      return false;
    case TCTX_OMP_DEVICE_ADDR:
      if (!silent_p)
	error_at (loc, "AME/Ztt type %qT is not allowed in %<target%> device"
		  " clauses", original_type);
      return false;
    }
  gcc_unreachable ();
}

} // namespace riscv_ztt

rtl_opt_pass *
make_pass_ztt_state (gcc::context *ctxt)
{
  return new riscv_ztt::pass_ztt_state (ctxt);
}

rtl_opt_pass *
make_pass_ztt_md_reuse (gcc::context *ctxt)
{
  return new riscv_ztt::pass_ztt_md_reuse (ctxt);
}

using namespace riscv_ztt;

#include "gt-riscv-ztt-builtins.h"
