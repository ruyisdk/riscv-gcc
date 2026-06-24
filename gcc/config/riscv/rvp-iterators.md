;; Packed Iterators for the machine description for RISC-V
;; Copyright (C) 2025 Free Software Foundation, Inc.

;; This file is part of GCC.
;;
;; GCC is free software; you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.
;;
;; GCC is distributed in the hope that it will be useful, but
;; WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;; General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; Mode Iterators

;; PVPLUI: Packed vector modes for PLUI instructions (halfword and word)
(define_mode_iterator PVPLUI [
  (PV2HI "!TARGET_64BIT") (PV4HI "TARGET_64BIT")
  (PV2SI "TARGET_64BIT")])

;; PVHIW: 4-byte packed halfword mode (PV2HI only, always supported).
;; Used for instructions whose 4-byte halfword form exists on both RV32 and RV64.
(define_mode_iterator PVHIW [PV2HI])

;; PVHW: 8-byte packed halfword and word modes (PV4HI + PV2SI).
;; Single register on RV64; register pair on RV32.
;; Used for instructions that have distinct DB/DH/DW (RV32) and B/H/W (RV64) forms.
(define_mode_iterator PVHW [PV4HI PV2SI])

;; Element mode for PLI/PLUI vec_duplicate
(define_mode_attr PVALL_ELT [
  (PV4QI "QI") (PV8QI "QI")
  (PV2HI "HI") (PV4HI "HI")
  (PV2SI "SI")])

;; Constraint for PLI vec_duplicate
(define_mode_attr dpli [
  (PV4QI "Os08") (PV8QI "Os08")
  (PV2HI "Os10") (PV4HI "Os10")
  (PV2SI "Os10")])

;; Constraint for PLUI vec_duplicate
(define_mode_attr dplui [
  (PV2HI "Yph06") (PV4HI "Yph06")
  (PV2SI "Yph22")])

;; Shift amount for PLUI (6 for halfword, 22 for word)
(define_mode_attr plui_shift [
  (PV2HI "6") (PV4HI "6")
  (PV2SI "22")])

;; PVQIHI: Packed vector modes for byte and halfword elements only
;; On RV64, we support both 4-byte (PV4QI, PV2HI) and 8-byte (PV8QI, PV4HI) vectors
(define_mode_iterator PVQIHI [PV4QI PV2HI
			      (PV8QI "TARGET_64BIT") (PV4HI "TARGET_64BIT")])

;; PV32: 4-byte packed vector modes (always supported)
(define_mode_iterator PV32 [PV4QI PV2HI])

;; PV64: All 8-byte packed vectors
;; Supported on RV64 (single register) and RV32 (register pairs)
;; RV32 uses PADD.DB/DH/DW and PMV.DBS/DHS/DWS instructions
(define_mode_iterator PV64 [PV8QI PV4HI PV2SI])

;; PV64QH: 8-byte packed vectors with byte/halfword elements only
;; Used for RV32 patterns that have PMV.DBS/DHS and PLI.DB/DH
(define_mode_iterator PV64QH [PV8QI PV4HI])

;; PVMOVE: All packed vector modes for move patterns
;; Includes PV2SI which is now supported on both RV32 and RV64
(define_mode_iterator PVMOVE [PV4QI PV2HI PV8QI PV4HI PV2SI])

;; QIHI: Scalar and packed modes for byte and halfword elements
;; Used for instructions like PSABS that work on both scalar and packed modes
(define_mode_iterator QIHI [QI HI PV4QI PV2HI
			    (PV8QI "TARGET_64BIT") (PV4HI "TARGET_64BIT")])

;; PVALL: All packed vector modes for basic arithmetic operations
;; On RV64, we support both 4-byte (PV4QI, PV2HI) and 8-byte (PV8QI, PV4HI, PV2SI) vectors
(define_mode_iterator PVALL [PV4QI PV2HI
			     (PV8QI "TARGET_64BIT") (PV4HI "TARGET_64BIT")
			     (PV2SI "TARGET_64BIT")])

;; Packed extension mode for RV32 register-pair instructions
(define_mode_iterator RVP_DWIDTH_EXT [PV4HI PV2SI])

;; Mode Attributes

;; PVALL_EXT: Widened result mode for each packed mode
(define_mode_attr PVALL_EXT [(PV4QI "PV4HI") (PV2HI "PV2SI")
			     (PV8QI "PV8HI") (PV4HI "PV4SI")
			     (PV2SI "PV2DI")])

;; Element width suffix for RVP instructions
(define_mode_attr rvp_width [(PV8QI "b") (PV4QI "b") (QI "b") (PV4HI "h") (PV2HI "h")
			     (HI "h") (PV2SI "w")])

;; Element width suffix for RV32 register-pair instructions (PMV.DxS, PADD.DB/DH/DW)
(define_mode_attr rvp_dwidth [(PV8QI "db") (PV4HI "dh") (PV2SI "dw")])

;; Element width suffix for RV32 register-pari instruction to extend
(define_mode_attr rvp_extend_width [(PV4HI "b") (PV2SI "h")])

;; Packed extension mode to extend suffix for pattern name
(define_mode_attr rvp_narrow [(PV4HI "pv4qi") (PV2SI "pv2hi")])

;; Packed extension mode extend to suffix for pattern name
(define_mode_attr rvp_ext_mode [(PV4HI "pv4hi") (PV2SI "pv2si")])

;; Code Iterators

(define_code_iterator rvp_binop
  [plus ss_plus us_plus
   minus ss_minus us_minus
   smax umax smin umin eq lt ltu])

(define_code_iterator rvp_widen_op
  [plus minus])

;; Operations for averaging instructions
(define_code_iterator avg_op [plus minus])

;; Operations for shift instructions
(define_code_iterator shift_op [ashift lshiftrt ashiftrt])

;; Code Attributes

(define_code_attr rvp_optab
  [(plus "add") (ss_plus "ssadd") (us_plus "usadd")
   (minus "sub") (ss_minus "sssub") (us_minus "ussub")
   (smax "smax") (umax "umax") (smin "smin") (umin "umin")
   (eq "eq") (lt "lt") (ltu "ltu")])

(define_code_attr rvp_insn
  [(plus "padd") (ss_plus "psadd") (us_plus "psaddu")
   (minus "psub") (ss_minus "pssub") (us_minus "pssubu")
   (smax "pmax") (umax "pmaxu") (smin "pmin") (umin "pminu")
   (eq "pmseq") (lt "pmslt") (ltu "pmsltu")])

(define_code_attr rvp_widen_optab
  [(plus "pwadd") (minus "pwsub")])

(define_code_attr rvp_widen_insn
  [(plus "pwadd") (minus "pwsub")])

;; Averaging arithmetic instruction names
(define_code_attr avg_insn
  [(plus "paadd")
   (minus "pasub")])

;; Optab name prefixes for averaging instructions.
;; avg<mode>3_floor and uavg<mode>3_floor are standard GCC optabs.
;; avg_sub<mode>3_floor and uavg_sub<mode>3_floor are P-extension specific
;; patterns for averaging subtract (not standard GCC optabs).
(define_code_attr savg_optab
  [(plus "avg")
   (minus "avg_sub")])

(define_code_attr uavg_optab
  [(plus "uavg")
   (minus "uavg_sub")])

(define_code_attr rvp_shift_optab
  [(ashift   "ashl")
   (lshiftrt "lshr")
   (ashiftrt "ashr")])

(define_code_attr rvp_shift_insn
  [(ashift   "psll")
   (lshiftrt "psrl")
   (ashiftrt "psra")])

;; PAS/PSA: alternating add-subtract operations
;; pas: even lanes add, odd lanes subtract
;; psa: even lanes subtract, odd lanes add
(define_code_iterator pas_even_op [plus minus])

(define_code_attr pas_odd_op
  [(plus "minus") (minus "plus")])

(define_code_attr pas_insn
  [(plus "pas") (minus "psa")])

;; Absolute difference operations
(define_code_iterator abd_maxop [smax umax])

(define_code_attr abd_minop
  [(smax "smin") (umax "umin")])

(define_code_attr abd_optab
  [(smax "sabd") (umax "uabd")])

(define_code_attr abd_insn
  [(smax "pabd") (umax "pabdu")])

;; Code attributes for macc instructions.
;; Use any_extend and any_shiftrt iterators from iterators.md.
;; Use 'u' attribute from iterators.md for signed/unsigned suffix.

;; Corresponding shift for each extend type (for H01 pattern: extend x shift)
(define_code_attr su_shiftrt [(sign_extend "ashiftrt") (zero_extend "lshiftrt")])

;; Instruction name suffix for shift-based patterns (H11)
(define_code_attr shiftrt_su [(ashiftrt "") (lshiftrt "u")])

;; Corresponding extension pattern name for each extension type
(define_code_attr extension [(sign_extend "extend") (zero_extend "zero_extend")])

;; Corresponding instruction name for packed extension
(define_code_attr rvp_extend_insn [(sign_extend "psext") (zero_extend "pzext")])
