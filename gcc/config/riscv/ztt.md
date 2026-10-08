;; Machine description for the RISC-V AME/Ztt extension.
;; Copyright (C) 2026 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify it under
;; the terms of the GNU General Public License as published by the Free
;; Software Foundation; either version 3, or (at your option) any later
;; version.

;; GCC is distributed in the hope that it will be useful, but WITHOUT ANY
;; WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
;; FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
;; details.

;; You should have received a copy of the GNU General Public License along
;; with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; Instruction and CSR allocations are provisional; see README.ztt.
;;
;; Matrix and accumulator register numbers are compile-time constants rather
;; than GCC hard registers.  UNSPECV_ZTT conservatively orders operations on
;; the architectural matrix state until ABI and data-flow semantics stabilize.

;; Resource operations have distinct effects, not an opaque L0 selector.
;; Before RTL optimization, typed functions add full-bank clobbers and a
;; memory barrier using the parallel forms below.  Scalar wrappers retain
;; the memory barrier but do not acquire an artificial AME frame.
(define_insn "riscv_ztt_acquire_<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec_volatile:X
	  [(match_operand:X 1 "register_operand" "r")]
	  UNSPECV_ZTT_ACQUIRE))
   (clobber (mem:BLK (scratch)))]
  "TARGET_ZTT"
  "ame.acquire\t%0,%1"
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_release"
  [(unspec_volatile [(const_int 0)] UNSPECV_ZTT_RELEASE)
   (clobber (mem:BLK (scratch)))]
  "TARGET_ZTT"
  "ame.release"
  [(set_attr "type" "multi")])

(define_insn "ztt_region_acquire_<X:mode>"
  [(match_parallel 2 "ztt_ownership_operation"
     [(set (match_operand:X 0 "register_operand" "=r")
	   (unspec_volatile:X
	     [(match_operand:X 1 "register_operand" "r")]
	     UNSPECV_ZTT_ACQUIRE))])]
  "TARGET_ZTT"
  "ame.acquire\t%0,%1"
  [(set_attr "type" "multi")])

(define_insn "ztt_region_release"
  [(match_parallel 0 "ztt_ownership_operation"
     [(unspec_volatile [(const_int 0)] UNSPECV_ZTT_RELEASE)])]
  "TARGET_ZTT"
  "ame.release"
  [(set_attr "type" "multi")])

; A proved success edge, not a hardware operation.  Keep reloads and memory
; effects on the owned side of the conditional acquire/query result.
(define_insn "ztt_region_owned"
  [(match_parallel 0 "ztt_ownership_operation"
     [(unspec_volatile [(const_int 0)] UNSPECV_ZTT_OWNED)])]
  "TARGET_ZTT"
  ""
  [(set_attr "type" "ghost")
   (set_attr "length" "0")])

;; CSR reads are volatile observations, not compile-time profile constants.
;; Keep repeated and discarded reads ordered with acquire/release.
;; amestype/amefflags/amexsat use the agreed local-only temporary addresses
;; 0x810/0x811/0x812, not official allocations.  All addresses are decimal
;; below for the MD reader; standard counter CSR names remain unchanged.
(define_int_iterator ZTT_READ_CSR [3264 3265 3267 2064 2065 2066 2048])
(define_int_attr ztt_read_csr_name
  [(3264 "amenlen") (3265 "ameudsz") (3267 "ameown")
   (2064 "amestype") (2065 "amefflags") (2066 "amexsat") (2048 "amestatus")])

(define_insn "riscv_ztt_read_<ztt_read_csr_name>_<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec_volatile:X [(const_int ZTT_READ_CSR)] UNSPECV_ZTT))]
  "TARGET_ZTT && TARGET_ZICSR"
  "csrr\t%0,<ztt_read_csr_name>"
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_none"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_none)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_m"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_m)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_a"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_0_15_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_a)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_mm"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand 2 "const_int5_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_mm)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_ma"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand 2 "const_0_15_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_ma)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_am"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_0_15_operand" "n")
      (match_operand 2 "const_int5_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_am)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_mmm"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand 2 "const_int5_operand" "n")
      (match_operand 3 "const_int5_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_mmm)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_amm"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_0_15_operand" "n")
      (match_operand 2 "const_int5_operand" "n")
      (match_operand 3 "const_int5_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_amm)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_mxm_<X:mode>"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand:X 2 "register_operand" "r")
      (match_operand 3 "const_int5_operand" "n")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_mxm)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_mxx_<X:mode>"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand:X 2 "register_operand" "r")
      (match_operand:X 3 "register_operand" "r")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_mxx)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_mx_<X:mode>"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand:X 2 "register_operand" "r")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_mx)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_ax_<X:mode>"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_0_15_operand" "n")
      (match_operand:X 2 "register_operand" "r")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_ax)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_x_a_<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec_volatile:X
	  [(match_operand 1 "const_int_operand" "n")
	   (match_operand 2 "const_0_15_operand" "n")]
	  UNSPECV_ZTT))]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[1], ZTT_FORMAT_x_a)"
  { return riscv_output_ztt_insn (operands, 1); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_x_m_<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec_volatile:X
	  [(match_operand 1 "const_int_operand" "n")
	   (match_operand 2 "const_int5_operand" "n")]
	  UNSPECV_ZTT))]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[1], ZTT_FORMAT_x_m)"
  { return riscv_output_ztt_insn (operands, 1); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_x_m_x_<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec_volatile:X
	  [(match_operand 1 "const_int_operand" "n")
	   (match_operand 2 "const_int5_operand" "n")
	   (match_operand:X 3 "register_operand" "r")]
	  UNSPECV_ZTT))]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[1], ZTT_FORMAT_x_m_x)"
  { return riscv_output_ztt_insn (operands, 1); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_x_x_<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec_volatile:X
	  [(match_operand 1 "const_int_operand" "n")
	   (match_operand:X 2 "register_operand" "r")]
	  UNSPECV_ZTT))]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[1], ZTT_FORMAT_x_x)"
  { return riscv_output_ztt_insn (operands, 1); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_load_<X:mode>"
  [(unspec_volatile:BLK
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (mem:BLK (match_operand:X 2 "register_operand" "r"))]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_load)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_store_<X:mode>"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand:X 2 "register_operand" "r")]
     UNSPECV_ZTT)
   (clobber (mem:BLK (match_dup 2)))]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_store)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_load_strided_<X:mode>"
  [(unspec_volatile:BLK
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (mem:BLK (match_operand:X 2 "register_operand" "r"))
      (match_operand:X 3 "register_operand" "r")]
     UNSPECV_ZTT)]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_load_strided)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])

(define_insn "riscv_ztt_store_strided_<X:mode>"
  [(unspec_volatile
     [(match_operand 0 "const_int_operand" "n")
      (match_operand 1 "const_int5_operand" "n")
      (match_operand:X 2 "register_operand" "r")
      (match_operand:X 3 "register_operand" "r")]
     UNSPECV_ZTT)
   (clobber (mem:BLK (match_dup 2)))]
  "TARGET_ZTT && riscv_ztt_insn_format_p (operands[0], ZTT_FORMAT_store_strided)"
  { return riscv_output_ztt_insn (operands, 0); }
  [(set_attr "type" "multi")])
