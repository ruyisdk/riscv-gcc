;; Machine description for RISC-V Packed (RVP) extension
;; Copyright (C) 2025 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(include "rvp-iterators.md")

;; Move pattern for PVQIHI modes (byte and halfword packed vectors)
(define_expand "mov<mode>"
  [(set (match_operand:PVQIHI 0 "")
	(match_operand:PVQIHI 1 ""))]
  "TARGET_RVP"
{
  if (riscv_legitimize_move (<MODE>mode, operands[0], operands[1]))
    DONE;
})

;; Internal move pattern for PVQIHI modes
(define_insn "*mov<mode>_internal"
  [(set (match_operand:PVQIHI 0 "nonimmediate_operand" "=r,r,r,r, m,  *f,*f,*r,*m")
	(match_operand:PVQIHI 1 "move_operand"         " r,T,vc,m,rJ,*r*J,*m,*f,*f"))]
  "(register_operand (operands[0], <MODE>mode)
    || reg_or_0_operand (operands[1], <MODE>mode))
   && TARGET_RVP"
  { return riscv_output_move (operands[0], operands[1]); }
  [(set_attr "move_type" "move,const,const,load,store,mtc,fpload,mfc,fpstore")
   (set_attr "type" "move,move,move,load,store,mtc,fpload,mfc,fpstore")
   (set_attr "mode" "<MODE>")])

;; Move pattern for PV2SI mode (2×32-bit packed vector, RV64 only)
(define_expand "movpv2si"
  [(set (match_operand:PV2SI 0 "")
	(match_operand:PV2SI 1 ""))]
  "TARGET_64BIT && TARGET_RVP"
{
  if (riscv_legitimize_move (PV2SImode, operands[0], operands[1]))
    DONE;
})

;; Internal move pattern for PV2SI mode
(define_insn "*movpv2si_64bit"
  [(set (match_operand:PV2SI 0 "nonimmediate_operand" "=r,r,r,r, m,  *f,*f,*r,*f,*m")
	(match_operand:PV2SI 1 "move_operand"         " r,T,vc,m,rJ,*r*J,*m,*f,*f,*f"))]
  "TARGET_64BIT && TARGET_RVP
   && (register_operand (operands[0], PV2SImode)
       || reg_or_0_operand (operands[1], PV2SImode))"
  { return riscv_output_move (operands[0], operands[1]); }
  [(set_attr "move_type" "move,const,const,load,store,mtc,fpload,mfc,fmove,fpstore")
   (set_attr "type" "move,move,move,load,store,mtc,fpload,mfc,fmove,fpstore")
   (set_attr "mode" "PV2SI")])

;; Binary Arithmetic Operations

;; Unified pattern for all binary arithmetic operations
;;   - Basic: padd.b/h/w, psub.b/h/w
;;   - Saturating signed: psadd.b/h/w, pssub.b/h/w
;;   - Saturating unsigned: psaddu.b/h/w, pssubu.b/h/w
;;   - Min/max signed: pmin.b/h/w, pmax.b/h/w
;;   - Min/max unsigned: pminu.b/h/w, pmaxu.b/h/w
(define_insn "<rvp_optab><mode>3"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(rvp_binop:PVALL (match_operand:PVALL 1 "register_operand" "r")
			 (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "<rvp_insn>.<rvp_width>\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Vector shift instructions by scalar amount (operand 2 is scalar SI)
(define_insn "<rvp_shift_optab><mode>3"
  [(set (match_operand:PVALL 0 "register_operand" "=r, r")
        (shift_op:PVALL
          (match_operand:PVALL 1 "register_operand" "r, r")
          (match_operand:SI 2 "reg_or_int_operand" "r, I")))]
  "TARGET_RVP"
  "@
   <rvp_shift_insn>.<rvp_width>s\t%0,%1,%2
   <rvp_shift_insn>i.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "<MODE>")])

;; Signed packed multiply high for all packed element sizes (bytes/halfwords/words)
(define_insn "smul<mode>3_highpart"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
        (smul_highpart:PVALL
          (match_operand:PVALL 1 "register_operand" "r")
          (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "pmulh.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Unsigned packed multiply high for all packed element sizes (bytes/halfwords/words)
(define_insn "umul<mode>3_highpart"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
        (umul_highpart:PVALL
          (match_operand:PVALL 1 "register_operand" "r")
          (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "pmulhu.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; MACC.H00/MACCU.H00: Widening multiply-accumulate (bottom x bottom)
;; MACC.H00:  rd = rd + sext(rs1[15:0]) * sext(rs2[15:0])
;; MACCU.H00: rd = rd + zext(rs1[15:0]) * zext(rs2[15:0])
;; Pattern name with * to work alongside the [u]maddhisi4 expander in riscv.md
(define_insn "*rvp_<u>maddhisi4"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (any_extend:SI
			    (match_operand:HI 1 "register_operand" "r"))
			  (any_extend:SI
			    (match_operand:HI 2 "register_operand" "r")))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc<u>.h00\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; MACC.H01/MACCU.H01: Multiply-accumulate (bottom x top)
;; MACC.H01:  rd = rd + sext(rs1[15:0]) * sext(rs2[31:16])
;; MACCU.H01: rd = rd + zext(rs1[15:0]) * zext(rs2[31:16])
;; Note: H10 (top x bottom) can be achieved by swapping operands.
;; GCC canonicalizes to [u]maddhisi4tb (top x bottom in RTL order).
(define_insn "<u>maddhisi4tb"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (<su_shiftrt>:SI
			    (match_operand:SI 1 "register_operand" "r")
			    (const_int 16))
			  (any_extend:SI
			    (match_operand:HI 2 "register_operand" "r")))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc<u>.h01\t%0,%2,%1"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; MACC.H11/MACCU.H11: Multiply-accumulate (top x top)
;; MACC.H11:  rd = rd + sext(rs1[31:16]) * sext(rs2[31:16])
;; MACCU.H11: rd = rd + zext(rs1[31:16]) * zext(rs2[31:16])
(define_insn "<shiftrt_su>maddhisi4tt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (any_shiftrt:SI
			    (match_operand:SI 1 "register_operand" "r")
			    (const_int 16))
			  (any_shiftrt:SI
			    (match_operand:SI 2 "register_operand" "r")
			    (const_int 16)))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc<shiftrt_su>.h11\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; usmulhisi3: Unsigned x Signed widening multiply (halfword -> word)
;; Standard pattern name from GCC internals.
;; GCC's convention: operand 1 is unsigned, operand 2 is signed.
;; MULSU.H00: rd = sext(rs1[15:0]) * zext(rs2[15:0])
;; Two patterns for different operand orderings from GCC.
(define_insn "usmulhisi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(mult:SI (zero_extend:SI
		   (match_operand:HI 1 "register_operand" "r"))
		 (sign_extend:SI
		   (match_operand:HI 2 "register_operand" "r"))))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h00\t%0,%2,%1"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "*usmulhisi3_alt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(mult:SI (sign_extend:SI
		   (match_operand:HI 1 "register_operand" "r"))
		 (zero_extend:SI
		   (match_operand:HI 2 "register_operand" "r"))))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h00\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; MULSU.H11: Signed x Unsigned widening multiply (top halfword -> word)
;; rd = sext(rs1[31:16]) * zext(rs2[31:16])
;; Two patterns for different operand orderings from GCC.
(define_insn "*usmulhisi3tt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(mult:SI (lshiftrt:SI
		   (match_operand:SI 1 "register_operand" "r")
		   (const_int 16))
		 (ashiftrt:SI
		   (match_operand:SI 2 "register_operand" "r")
		   (const_int 16))))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h11\t%0,%2,%1"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "*usmulhisi3tt_alt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(mult:SI (ashiftrt:SI
		   (match_operand:SI 1 "register_operand" "r")
		   (const_int 16))
		 (lshiftrt:SI
		   (match_operand:SI 2 "register_operand" "r")
		   (const_int 16))))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h11\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; MACCSU.H00: Signed-unsigned multiply-accumulate (bottom x bottom)
;; rd = rd + sext(rs1[15:0]) * zext(rs2[15:0])
;; Two patterns for different operand orderings from GCC.
(define_insn "*rvp_usmaddhisi4"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (zero_extend:SI
			    (match_operand:HI 1 "register_operand" "r"))
			  (sign_extend:SI
			    (match_operand:HI 2 "register_operand" "r")))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccsu.h00\t%0,%2,%1"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "*rvp_usmaddhisi4_alt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (sign_extend:SI
			    (match_operand:HI 1 "register_operand" "r"))
			  (zero_extend:SI
			    (match_operand:HI 2 "register_operand" "r")))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccsu.h00\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; MACCSU.H11: Signed-unsigned multiply-accumulate (top x top)
;; rd = rd + sext(rs1[31:16]) * zext(rs2[31:16])
;; Two patterns for different operand orderings from GCC.
(define_insn "*rvp_usmaddhisi4tt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (lshiftrt:SI
			    (match_operand:SI 1 "register_operand" "r")
			    (const_int 16))
			  (ashiftrt:SI
			    (match_operand:SI 2 "register_operand" "r")
			    (const_int 16)))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccsu.h11\t%0,%2,%1"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

(define_insn "*rvp_usmaddhisi4tt_alt"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (ashiftrt:SI
			    (match_operand:SI 1 "register_operand" "r")
			    (const_int 16))
			  (lshiftrt:SI
			    (match_operand:SI 2 "register_operand" "r")
			    (const_int 16)))
		 (match_operand:SI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccsu.h11\t%0,%1,%2"
  [(set_attr "type" "imul")
   (set_attr "mode" "SI")])

;; Averaging arithmetic operations with standard optab names.
;;
;; GCC's tree-vect-patterns.cc recognizes widening average patterns like:
;;   (int8_t)(((int16_t)a + (int16_t)b) >> 1)
;; and lowers them to IFN_AVG_FLOOR/IFN_AVG_SUB_FLOOR, which map to
;; avg<mode>3_floor/avg_sub<mode>3_floor optabs.
;;
;; P-extension averaging instructions:
;;   paadd/paaddu: signed/unsigned averaging add: (a + b) >> 1
;;   pasub/pasubu: signed/unsigned averaging subtract: (a - b) >> 1
;;
;; These instructions perform overflow-free averaging in hardware by
;; widening operands internally before the add/subtract.
;;
;; Note: The RTL pattern uses (plus:PVALL ...) which has wraparound
;; semantics at element boundaries. However, this correctly models the
;; hardware behavior because paadd/paaddu internally widen operands
;; before addition, avoiding overflow.

;; Signed averaging: avg<mode>3_floor -> paadd, avg_sub<mode>3_floor -> pasub
(define_insn "<savg_optab><mode>3_floor"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(ashiftrt:PVALL
	  (avg_op:PVALL (match_operand:PVALL 1 "register_operand" "r")
			(match_operand:PVALL 2 "register_operand" "r"))
	  (const_int 1)))]
  "TARGET_RVP"
  "<avg_insn>.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Unsigned averaging: uavg<mode>3_floor -> paaddu, uavg_sub<mode>3_floor -> pasubu
(define_insn "<uavg_optab><mode>3_floor"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(lshiftrt:PVALL
	  (avg_op:PVALL (match_operand:PVALL 1 "register_operand" "r")
			(match_operand:PVALL 2 "register_operand" "r"))
	  (const_int 1)))]
  "TARGET_RVP"
  "<avg_insn>u.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Vector comparison expander for signed comparisons
(define_expand "vec_cmp<mode><mode>"
  [(set (match_operand:PVALL 0 "register_operand")
	(match_operator:PVALL 1 "comparison_operator"
	  [(match_operand:PVALL 2 "register_operand")
	   (match_operand:PVALL 3 "register_operand")]))]
  "TARGET_RVP"
{
  riscv_p_expand_vec_cmp (operands);
  DONE;
})

;; Vector comparison expander for unsigned comparisons
(define_expand "vec_cmpu<mode><mode>"
  [(set (match_operand:PVALL 0 "register_operand")
	(match_operator:PVALL 1 "comparison_operator"
	  [(match_operand:PVALL 2 "register_operand")
	   (match_operand:PVALL 3 "register_operand")]))]
  "TARGET_RVP"
{
  riscv_p_expand_vec_cmp (operands);
  DONE;
})

;; Vector conditional mask operation
;; Implements: result = mask ? op1 : op2
;; For each element i: result[i] = mask[i] ? op1[i] : op2[i]
(define_expand "vcond_mask_<mode><mode>"
  [(set (match_operand:PVALL 0 "register_operand")
	(if_then_else:PVALL
	  (match_operand:PVALL 3 "register_operand")
	  (match_operand:PVALL 1 "nonmemory_operand")
	  (match_operand:PVALL 2 "nonmemory_operand")))]
  "TARGET_RVP"
{
  riscv_p_expand_vcond_mask (operands);
  DONE;
})

;; Bitwise operations for vector modes
(define_insn "<optab><mode>3"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(any_bitwise:PVALL (match_operand:PVALL 1 "register_operand" "r")
			   (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "<insn>\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "DI")])

(define_insn "one_cmpl<mode>2"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(not:PVALL (match_operand:PVALL 1 "register_operand" "r")))]
  "TARGET_RVP"
  "not\t%0,%1"
  [(set_attr "type" "logical")
   (set_attr "mode" "DI")])

;; ============================================================================
;; PLI/PLUI: Packed Load Immediate Instructions
;; ============================================================================
;;
;; PLI.B rd, imm8   - Broadcast 8-bit value to all bytes
;; PLI.H rd, imm10  - Broadcast 10-bit signed value to all halfwords
;; PLI.W rd, imm10  - Broadcast 10-bit signed value to all words (RV64)
;; PLUI.H rd, imm10 - Broadcast (imm10 << 6) to all halfwords
;; PLUI.W rd, imm10 - Broadcast (imm10 << 22) to all words (RV64)
;;
;; These patterns are handled by riscv_output_move via riscv_output_pli.

;; vec_duplicate patterns for PLI.B/PLI.H/PLI.W
(define_insn "*riscv_pli_vec"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(vec_duplicate:PVALL
	  (match_operand:<PVALL_ELT> 1 "const_int_operand" "<dpli>")))]
  "TARGET_RVP"
  "pli.<rvp_width>\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; vec_duplicate patterns for PLUI.H/PLUI.W
(define_insn "*riscv_plui_vec"
  [(set (match_operand:PVPLUI 0 "register_operand" "=r")
	(vec_duplicate:PVPLUI
	  (match_operand:<PVALL_ELT> 1 "const_int_operand" "<dplui>")))]
  "TARGET_RVP"
  {
    operands[2] = GEN_INT (INTVAL (operands[1]) >> <plui_shift>);
    return "plui.<rvp_width>\t%0,%2";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Pack operations for scalar mode
(define_insn "*ppairoe_h_1"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ior:SI (ashift:SI (match_operand:SI 1 "register_operand" "r")
                       (const_int 16))
		    (lshiftrt:SI (match_operand:SI 2 "register_operand" "r")
                         (const_int 16))))]
  "TARGET_RVP"
  "ppairoe.h\t%0, %2, %1"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "SI")])

(define_insn "*ppairoe_h_2"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ior:SI (lshiftrt:SI (match_operand:SI 1 "register_operand" "r")
                       (const_int 16))
		    (ashift:SI (match_operand:SI 2 "register_operand" "r")
                         (const_int 16))))]
  "TARGET_RVP"
  "ppairoe.h\t%0, %1, %2"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "SI")])

(define_insn "*ppairoe_w_1"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ior:DI (ashift:DI (match_operand:DI 2 "register_operand" "r")
                      (const_int 32))
		    (lshiftrt:DI (match_operand:DI 1 "register_operand" "r")
                         (const_int 32))))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.w\t%0, %1, %2"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "DI")])

(define_insn "*ppaireo_h_1"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (ior:SI (and:SI (match_operand:SI 1 "register_operand" "r")
                    (const_int -65536))
            (and:SI (match_operand:SI 2 "register_operand" "r")
                    (const_int 65535))))]
  "TARGET_RVP"
  "ppaireo.h\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppaireo_h_2"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (ior:SI (and:SI (match_operand:SI 1 "register_operand" "r")
                    (const_int -65536))
            (zero_extend:SI (match_operand:HI 2 "register_operand" "r"))))]
  "TARGET_RVP"
  "ppaireo.h\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppaireo_h_3"
  [(set (match_operand:SI 0 "register_operand" "=r")
    (ior:SI (zero_extend:SI (match_operand:HI 2 "register_operand" "r"))
            (and:SI (match_operand:SI 1 "register_operand" "r")
                    (const_int -65536))))]
  "TARGET_RVP"
  "ppaireo.h\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppaireo_w_1"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ior:DI (and:DI (match_operand:DI 1 "register_operand" "r")
                    (const_int -4294967296))
            (and:DI (match_operand:DI 2 "register_operand" "r")
                    (const_int 4294967295))))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.w\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ppaireo_w_2"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ior:DI (and:DI (match_operand:DI 1 "register_operand" "r")
                    (const_int -4294967296))
            (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.w\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ppaireo_w_3"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ior:DI (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))
            (and:DI (match_operand:DI 1 "register_operand" "r")
                    (const_int -4294967296))))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.w\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ppairo_h"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (ior:SI (and:SI (match_operand:SI 1 "register_operand" "r")
                     (const_int -65536))
             (lshiftrt:SI (match_operand:SI 2 "register_operand" "r")
                          (const_int 16))))]
  "TARGET_RVP"
  "ppairo.h\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppairo_w"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (ior:DI (and:DI (match_operand:DI 1 "register_operand" "r")
                     (const_int -4294967296))
             (lshiftrt:DI (match_operand:DI 2 "register_operand" "r")
                          (const_int 32))))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.w\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Pack vector pattern

(define_expand "vec_setpv2hi"
  [(match_operand:PV2HI 0 "register_operand" "")
   (match_operand:HI 1 "register_operand" "")
   (match_operand:SI 2 "immediate_operand" "")]
  "TARGET_RVP"
{
  HOST_WIDE_INT pos = INTVAL (operands[2]);
  if (pos > 1)
    gcc_unreachable ();
  HOST_WIDE_INT elem = (HOST_WIDE_INT) 1 << pos;
  emit_insn (gen_vec_setv2hi_internal (operands[0], operands[1],
				       operands[0], GEN_INT (elem)));
  DONE;
})

(define_insn "vec_setv2hi_internal"
  [(set (match_operand:PV2HI 0 "register_operand" "=r, r")
    (vec_merge:PV2HI
      (vec_duplicate:PV2HI
        (match_operand:HI 1 "register_operand" "r, r"))
      (match_operand:PV2HI 2 "register_operand" "r, r")
      (match_operand:SI 3 "immediate_operand" "k01, k02")))]
  "TARGET_RVP"
  "@
   ppaireo.h\t%0, %1, %2
   pack\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_expand "vec_setpv2si"
  [(match_operand:PV2SI 0 "register_operand" "")
   (match_operand:SI 1 "register_operand" "")
   (match_operand:SI 2 "immediate_operand" "")]
  "TARGET_RVP && TARGET_64BIT"
{
  HOST_WIDE_INT pos = INTVAL (operands[2]);
  if (pos > 1)
    gcc_unreachable ();
  HOST_WIDE_INT elem = (HOST_WIDE_INT) 1 << pos;
  emit_insn (gen_vec_setv2si_internal (operands[0], operands[1],
				       operands[0], GEN_INT (elem)));
  DONE;
})

(define_insn "vec_setv2si_internal"
  [(set (match_operand:PV2SI 0 "register_operand" "=r, r")
    (vec_merge:PV2SI
      (vec_duplicate:PV2SI
        (match_operand:SI 1 "register_operand" "r, r"))
      (match_operand:PV2SI 2 "register_operand" "r, r")
      (match_operand:SI 3 "immediate_operand" "k01, k02")))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   ppaireo.w\t%0, %1, %2
   pack\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*pack_concatpv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_concat:PV2HI
          (match_operand:HI 1 "register_operand" "r") 
          (match_operand:HI 2 "register_operand" "r")))]
  "TARGET_RVP"
  "pack\t%0, %1, %2"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "SI")])

(define_insn "*pack_concatpv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_concat:PV2SI
          (match_operand:SI 1 "register_operand" "r") 
          (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_RVP && TARGET_64BIT"
  "pack\t%0, %1, %2"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "DI")])

;; ppaireo.h pattern: take bottom of first operand and top of second operand
;; Matches vec_concat where the top element comes from a shift (extracting top half)
;; For little-endian: ppaireo.h Rd, Ra, Rb means Rd[0] = Ra[0], Rd[1] = Rb[1]
(define_insn "*ppaireo_concatpv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_concat:PV2HI
          (match_operand:HI 1 "register_operand" "r") 
          (subreg:HI (lshiftrt:SI
                       (match_operand:SI 2 "register_operand" "r") 
                       (const_int 16)) 0)))]
  "TARGET_RVP && !TARGET_BIG_ENDIAN"
  "ppaireo.h\t%0, %1, %2"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "SI")])

;; ppaireo.w pattern: take bottom of first operand and top of second operand
;; Matches vec_concat where the top element comes from a shift (extracting top word)
;; For little-endian: ppaireo.w Rd, Ra, Rb means Rd[0] = Ra[0], Rd[1] = Rb[1]
(define_insn "*ppaireo_concatpv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_concat:PV2SI
          (match_operand:SI 1 "register_operand" "r") 
          (subreg:SI (lshiftrt:DI
                       (match_operand:DI 2 "register_operand" "r") 
                       (const_int 32)) 0)))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "ppaireo.w\t%0, %1, %2"
  [(set_attr "type"  "arith")
   (set_attr "mode"  "DI")])

;; ppairoe.h pattern: take top of first operand and bottom of second operand
;; Matches vec_concat where the top element comes from a shift (extracting top half)
;; For little-endian: ppairoe.h Rd, Ra, Rb means Rd[0] = Ra[1], Rd[1] = Rb[0]
(define_insn "*ppairoe_concatpv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_concat:PV2HI
          (subreg:HI (lshiftrt:SI
                       (match_operand:SI 1 "register_operand" "r")
                       (const_int 16)) 0)
          (match_operand:HI 2 "register_operand" "r")))]
  "TARGET_RVP && !TARGET_BIG_ENDIAN"
  "ppairoe.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; ppairoe.w pattern: take top of first operand and bottom of second operand
;; Matches vec_concat where the top element comes from a shift (extracting top word)
;; For little-endian: ppairoe.w Rd, Ra, Rb means Rd[0] = Ra[1], Rd[1] = Rb[0]
(define_insn "*ppairoe_concatpv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_concat:PV2SI
          (subreg:SI (lshiftrt:DI
                       (match_operand:DI 1 "register_operand" "r")
                       (const_int 32)) 0)
          (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "ppairoe.w\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; ppairo.h pattern: take top of first operand and top of second operand
;; Matches vec_concat where the top element comes from a shift (extracting top half)
;; For little-endian: ppairo.h Rd, Ra, Rb means Rd[0] = Ra[1], Rd[1] = Rb[1]
(define_insn "*ppairo_concatpv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_concat:PV2HI
          (subreg:HI (lshiftrt:SI
                       (match_operand:SI 1 "register_operand" "r")
                       (const_int 16)) 0)
          (subreg:HI (lshiftrt:SI
                       (match_operand:SI 2 "register_operand" "r")
                       (const_int 16)) 0)))]
  "TARGET_RVP && !TARGET_BIG_ENDIAN"
  "ppairo.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; ppairo.w pattern: take top of first operand and top of second operand
;; Matches vec_concat where the top element comes from a shift (extracting top word)
;; For little-endian: ppairo.w Rd, Ra, Rb means Rd[0] = Ra[1], Rd[1] = Rb[1]
(define_insn "*ppairo_concatpv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_concat:PV2SI
          (subreg:SI (lshiftrt:DI
                       (match_operand:DI 1 "register_operand" "r")
                       (const_int 32)) 0)
          (subreg:SI (lshiftrt:DI
                       (match_operand:DI 2 "register_operand" "r")
                       (const_int 32)) 0)))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "ppairo.w\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; ============================================================================
;; Pair instructions (PV2HI mode) (PV2SI mode)
;; ============================================================================
(define_insn "*ppaireh_mergepv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_merge:PV2HI
          (vec_select:PV2HI (match_operand:PV2HI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (vec_select:PV2HI (match_operand:PV2HI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (const_int 2)))]
  "TARGET_RVP"
  "pack\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppaireoh_mergepv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_merge:PV2HI
          (vec_select:PV2HI (match_operand:PV2HI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (vec_select:PV2HI (match_operand:PV2HI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (const_int 2)))]
  "TARGET_RVP"
  "ppaireo.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppairoeh_mergepv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_merge:PV2HI
          (vec_select:PV2HI (match_operand:PV2HI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (vec_select:PV2HI (match_operand:PV2HI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (const_int 2)))]
  "TARGET_RVP"
  "ppairoe.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppairoh_mergepv2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
        (vec_merge:PV2HI
          (vec_select:PV2HI (match_operand:PV2HI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (vec_select:PV2HI (match_operand:PV2HI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (const_int 2)))]
  "TARGET_RVP"
  "ppairo.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

(define_insn "*ppairew_mergepv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_merge:PV2SI
          (vec_select:PV2SI (match_operand:PV2SI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (vec_select:PV2SI (match_operand:PV2SI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (const_int 2)))]
  "TARGET_RVP && TARGET_64BIT"
  "pack\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ppaireow_mergepv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_merge:PV2SI
          (vec_select:PV2SI (match_operand:PV2SI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (vec_select:PV2SI (match_operand:PV2SI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (const_int 2)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.w\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ppairoew_mergepv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_merge:PV2SI
          (vec_select:PV2SI (match_operand:PV2SI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)]))
          (vec_select:PV2SI (match_operand:PV2SI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (const_int 2)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.w\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ppairow_mergepv2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
        (vec_merge:PV2SI
          (vec_select:PV2SI (match_operand:PV2SI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (vec_select:PV2SI (match_operand:PV2SI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)]))
          (const_int 2)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.w\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; ============================================================================
;; Pair instructions (PV4QI mode) (PV4HI mode)
;; ============================================================================

;; PPAIRE.B using vec_merge + vec_select
;; Result: rd[0]=op1[0], rd[1]=op2[0], rd[2]=op1[2], rd[3]=op2[2]
;; vec_select produces {op[0], op[0], op[2], op[2]} for each operand
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppaireb_mergepv4qi"
  [(set (match_operand:PV4QI 0 "register_operand" "=r")
        (vec_merge:PV4QI
          (vec_select:PV4QI (match_operand:PV4QI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (vec_select:PV4QI (match_operand:PV4QI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (const_int 10)))]
  "TARGET_RVP"
  "ppaire.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; PPAIRE.H using vec_merge + vec_select
;; Result: rd[0]=op1[0], rd[1]=op2[0], rd[2]=op1[2], rd[3]=op2[2]
;; vec_select produces {op[0], op[0], op[2], op[2]} for each operand
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppaireh_mergepv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_merge:PV4HI
          (vec_select:PV4HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (vec_select:PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (const_int 10)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; PPAIREO.B using vec_merge + vec_select
;; Result: rd[0]=op1[0], rd[1]=op2[1], rd[2]=op1[2], rd[3]=op2[3]
;; vec_select on op1: {0, 0, 2, 2}, on op2: {1, 1, 3, 3}
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppaireob_mergepv4qi"
  [(set (match_operand:PV4QI 0 "register_operand" "=r")
        (vec_merge:PV4QI
          (vec_select:PV4QI (match_operand:PV4QI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (vec_select:PV4QI (match_operand:PV4QI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (const_int 10)))]
  "TARGET_RVP"
  "ppaireo.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; PPAIREO.H using vec_merge + vec_select
;; Result: rd[0]=op1[0], rd[1]=op2[1], rd[2]=op1[2], rd[3]=op2[3]
;; vec_select on op1: {0, 0, 2, 2}, on op2: {1, 1, 3, 3}
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppaireoh_mergepv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_merge:PV4HI
          (vec_select:PV4HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (vec_select:PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (const_int 10)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; PPAIROE.B using vec_merge + vec_select
;; Result: rd[0]=op1[1], rd[1]=op2[0], rd[2]=op1[3], rd[3]=op2[2]
;; vec_select on op1: {1, 1, 3, 3}, on op2: {0, 0, 2, 2}
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppairoeb_mergepv4qi"
  [(set (match_operand:PV4QI 0 "register_operand" "=r")
        (vec_merge:PV4QI
          (vec_select:PV4QI (match_operand:PV4QI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (vec_select:PV4QI (match_operand:PV4QI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (const_int 10)))]
  "TARGET_RVP"
  "ppairoe.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; PPAIROE.H using vec_merge + vec_select
;; Result: rd[0]=op1[1], rd[1]=op2[0], rd[2]=op1[3], rd[3]=op2[2]
;; vec_select on op1: {1, 1, 3, 3}, on op2: {0, 0, 2, 2}
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppairoeh_mergepv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_merge:PV4HI
          (vec_select:PV4HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)]))
          (vec_select:PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (const_int 10)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; PPAIRO.B using vec_merge + vec_select
;; Result: rd[0]=op1[1], rd[1]=op2[1], rd[2]=op1[3], rd[3]=op2[3]
;; vec_select on op1: {1, 1, 3, 3}, on op2: {1, 1, 3, 3}
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppairob_mergepv4qi"
  [(set (match_operand:PV4QI 0 "register_operand" "=r")
        (vec_merge:PV4QI
          (vec_select:PV4QI (match_operand:PV4QI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (vec_select:PV4QI (match_operand:PV4QI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (const_int 10)))]
  "TARGET_RVP"
  "ppairo.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; PPAIRO.H using vec_merge + vec_select
;; Result: rd[0]=op1[1], rd[1]=op2[1], rd[2]=op1[3], rd[3]=op2[3]
;; vec_select on op1: {1, 1, 3, 3}, on op2: {1, 1, 3, 3}
;; vec_merge with mask 0b1010 selects alternating elements
(define_insn "*ppairoh_mergepv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_merge:PV4HI
          (vec_select:PV4HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (vec_select:PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)]))
          (const_int 10)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.h\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; ============================================================================
;; Pair instructions (PV8QI mode)
;; ============================================================================
;; PPAIRE.B: pairs low bytes from each 16-bit halfword
;; Result = {s2[55:48]@s1[55:48], s2[39:32]@s1[39:32], s2[23:16]@s1[23:16], s2[7:0]@s1[7:0]}
;; For V8QI: combines bytes from two operands element-wise
;; Pattern: rd[0]=op0[0], rd[1]=op1[0], rd[2]=op0[2], rd[3]=op1[2], rd[4]=op0[4], rd[5]=op1[4],
;;          rd[6]=op0[6], rd[7]=op1[6]
;; VEC_PERM indices: {0, 8, 2, 10, 4, 12, 6, 14}
(define_insn "*ppaireb_mergepv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_merge:PV8QI
          (vec_select:PV8QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)
                                       (const_int 4) (const_int 4)
                                       (const_int 6) (const_int 6)]))
          (vec_select:PV8QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)
                                       (const_int 4) (const_int 4)
                                       (const_int 6) (const_int 6)]))
          (const_int 170)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; PPAIREO.B: pairs low bytes from op0 and high bytes from op1
;; Result = {s2[63:56]@s1[55:48], s2[47:40]@s1[39:32], s2[31:24]@s1[23:16], s2[15:8]@s1[7:0]} 
;; For V8QI: combines bytes from two operands element-wise
;; Pattern: rd[0]=op0[0], rd[1]=op1[1], rd[2]=op0[2], rd[3]=op1[3], rd[4]=op0[4], rd[5]=op1[5],
;;          rd[6]=op0[6], rd[7]=op1[7]
;; VEC_PERM indices: {0, 9, 2, 11, 4, 13, 6, 15}
(define_insn "*ppaireob_mergepv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_merge:PV8QI
          (vec_select:PV8QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)
                                       (const_int 5) (const_int 5)
                                       (const_int 7) (const_int 7)]))
          (vec_select:PV8QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)
                                       (const_int 4) (const_int 4)
                                       (const_int 6) (const_int 6)]))
          (const_int 170)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; PPAIROE.B: pairs high bytes from op0 and low bytes from op1
;; Result = {s2[55:48]@s1[63:56], s2[39:32]@s1[47:40], s2[23:16]@s1[31:24], s2[7:0]@s1[15:8]}
;; For V8QI: combines bytes from two operands element-wise
;; Pattern: rd[0]=op0[1], rd[1]=op1[0], rd[2]=op0[3], rd[3]=op1[2], rd[4]=op0[5], rd[5]=op1[4],
;;          rd[6]=op0[7], rd[7]=op1[6]
;; VEC_PERM indices: {1, 8, 3, 10, 5, 12, 7, 14}
(define_insn "*ppairoeb_mergepv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_merge:PV8QI
          (vec_select:PV8QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 2) (const_int 2)
                                       (const_int 4) (const_int 4)
                                       (const_int 6) (const_int 6)]))
          (vec_select:PV8QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)
                                       (const_int 5) (const_int 5)
                                       (const_int 7) (const_int 7)]))
          (const_int 170)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; PPAIRO.B: pairs high bytes from op0 and high bytes from op1
;; Result = {s2[63:56]@s1[63:56], s2[47:40]@s1[47:40], s2[31:24]@s1[31:24], s2[15:8]@s1[15:8]}
;; For V8QI: combines bytes from two operands element-wise
;; Pattern: rd[0]=op0[1], rd[1]=op1[1], rd[2]=op0[3], rd[3]=op1[3], rd[4]=op0[5], rd[5]=op1[5],
;;          rd[6]=op0[7], rd[7]=op1[7]
;; VEC_PERM indices: {1, 9, 3, 11, 5, 13, 7, 15}
(define_insn "*ppairob_mergepv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_merge:PV8QI
          (vec_select:PV8QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)
                                       (const_int 5) (const_int 5)
                                       (const_int 7) (const_int 7)]))
          (vec_select:PV8QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 1)
                                       (const_int 3) (const_int 3)
                                       (const_int 5) (const_int 5)
                                       (const_int 7) (const_int 7)]))
          (const_int 170)))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.b\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; zip8p/zip8hp
;; =========================================================================
(define_insn "*zip_mergepv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_merge:PV8QI
          (vec_select:PV8QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 1) (const_int 1)
                                       (const_int 2) (const_int 2)
                                       (const_int 3) (const_int 3)]))
          (vec_select:PV8QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 1) (const_int 1)
                                       (const_int 2) (const_int 2)
                                       (const_int 3) (const_int 3)]))
          (const_int 170)))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ziph_mergepv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_merge:PV8QI
          (vec_select:PV8QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 4) (const_int 4)
                                       (const_int 5) (const_int 5)
                                       (const_int 6) (const_int 6)
                                       (const_int 7) (const_int 7)]))
          (vec_select:PV8QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 4) (const_int 4)
                                       (const_int 5) (const_int 5)
                                       (const_int 6) (const_int 6)
                                       (const_int 7) (const_int 7)]))
          (const_int 170)))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8hp\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; zip16p/zip16hp
;; =========================================================================
(define_insn "*zip_mergepv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_merge:PV4HI
          (vec_select:PV4HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 1) (const_int 1)]))
          (vec_select:PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 0)
                                       (const_int 1) (const_int 1)]))
          (const_int 10)))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*ziph_mergepv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_merge:PV4HI
          (vec_select:PV4HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 2) (const_int 2)
                                       (const_int 3) (const_int 3)]))
          (vec_select:PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 2) (const_int 2)
                                       (const_int 3) (const_int 3)]))
          (const_int 10)))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16hp\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; unzip8p/unzip8hp
;; =========================================================================
(define_insn "*unzip_concatpv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_concat:PV8QI
          (vec_select:PV4QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 2)
                                       (const_int 4) (const_int 6)]))
          (vec_select:PV4QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 2)
                                       (const_int 4) (const_int 6)]))))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "unzip8p\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*unziph_concatpv8qi"
  [(set (match_operand:PV8QI 0 "register_operand" "=r")
        (vec_concat:PV8QI
          (vec_select:PV4QI (match_operand:PV8QI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 3)
                                       (const_int 5) (const_int 7)]))
          (vec_select:PV4QI (match_operand:PV8QI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 3)
                                       (const_int 5) (const_int 7)]))))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "unzip8hp\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; unzip16p/unzip16hp
;; =========================================================================
(define_insn "*unzip_concatpv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_concat:PV4HI
          (vec_select:PV2HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 2)]))
          (vec_select:PV2HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 0) (const_int 2)]))))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "unzip16p\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*unziph_concatpv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_concat:PV4HI
          (vec_select:PV2HI (match_operand:PV4HI 1 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 3)]))
          (vec_select:PV2HI (match_operand:PV4HI 2 "register_operand" "r")
                            (parallel [(const_int 1) (const_int 3)]))))]
  "TARGET_RVP && TARGET_64BIT && !TARGET_BIG_ENDIAN"
  "unzip16hp\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; rev16 
;; =========================================================================
(define_insn "*rev16_pv4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
        (vec_select: PV4HI (match_operand:PV4HI 1 "register_operand" "r")
                           (parallel [(const_int 3) (const_int 2)
                                      (const_int 1) (const_int 0)])))]
  "TARGET_RVP && TARGET_64BIT"
  "rev16\t%0, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; Sign/Zero Extension for RV32 with RVP
;; =========================================================================
;; On RV32 with RVP, we want to keep sign_extend and zero_extend as single
;; RTX operations so they can be matched by widening instructions like WADD/WADDU.
;; Without these patterns, GCC would expand them into subreg operations.

;; Sign extend SI to DI on RV32
;; This pattern is matched by the extendsidi2 expander in riscv.md
(define_insn_and_split "*extendsidi2_rvp"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (sign_extend:DI (match_operand:SI 1 "register_operand" "r")))]
  "!TARGET_64BIT && TARGET_RVP && !TARGET_BIG_ENDIAN"
  "#"
  "&& reload_completed"
  [(set (subreg:SI (match_dup 0) 0) (match_dup 1))
   (set (subreg:SI (match_dup 0) 4) (ashiftrt:SI (match_dup 1) (const_int 31)))]
  ""
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Zero extend SI to DI on RV32
;; This pattern is matched by the zero_extendsidi2 expander in riscv.md
(define_insn_and_split "*zero_extendsidi2_rvp"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (zero_extend:DI (match_operand:SI 1 "register_operand" "r")))]
  "!TARGET_64BIT && TARGET_RVP && !TARGET_BIG_ENDIAN"
  "#"
  "&& reload_completed"
  [(set (subreg:SI (match_dup 0) 0) (match_dup 1))
   (set (subreg:SI (match_dup 0) 4) (const_int 0))]
  ""
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; =========================================================================
;; Widening Add Instructions (WADD/WADDU)
;; =========================================================================
;; WADD: Widening signed add - takes two 32-bit operands, produces 64-bit result
;; WADDU: Widening unsigned add - takes two 32-bit unsigned operands, produces 64-bit result
;;
;; Operation: rd_p = sign_extend(rs1) + sign_extend(rs2)
;; Result stored in register pair: X[2*rd_p] = result[31:0], X[2*rd_p+1] = result[63:32]
;; Only available on RV32 (on RV64, use regular 64-bit add)

;; Signed widening add (WADD)
;; This pattern matches: (long long)a + (long long)b
(define_insn "*waddsi3"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (plus:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
                 (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "wadd\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Signed widening sub (WSUB)
;; This pattern matches: (long long)a - (long long)b
(define_insn "*wsubsi3"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (minus:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
                  (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "wsub\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Unsigned widening add (WADDU)
;; This pattern matches: (unsigned long long)a + (unsigned long long)b
(define_insn "*waddusi3"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (plus:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
                 (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "waddu\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Unsigned widening sub (WSUBU)
;; This pattern matches: (unsigned long long)a - (unsigned long long)b
(define_insn "*wsubusi3"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (minus:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
                  (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "wsubu\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Widening accumulate (WADDA/WADDAU)
;; rd = acc + sign_extend(rs1) + sign_extend(rs2)
;;   - rd is a DI register pair (R constraint)
;;   - rs1, rs2 are 32-bit registers sign-extended to DI
;;   - "acc" is a DI accumulator tied to rd by the "0" constraint
(define_insn "*wadda<su>si3"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (plus:DI (plus:DI (any_extend:DI (match_operand:SI 1 "register_operand" "r"))
                          (any_extend:DI (match_operand:SI 2 "reg_or_0_operand" "rJ")))
                       (match_operand:DI 3 "register_operand" "0")))]
  "!TARGET_64BIT && TARGET_RVP"
  "wadda<u>\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; Rtl pattern for wadda(u) when the operand has x0 register.
(define_insn "*<su>extend_add"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (plus:DI (any_extend:DI (match_operand:SI 1 "register_operand" "r"))
                 (match_operand:DI 2 "register_operand" "0")))]
  "!TARGET_64BIT && TARGET_RVP"
  "wadda<u>\t%0, %1, zero"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; DI-mode addition for RV32 with RVP
;; Uses ADDD instruction; operands must be register pairs (R constraint)
(define_insn "*adddi3_rvp32"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (plus:DI (match_operand:DI 1 "register_operand" "R")
                 (match_operand:DI 2 "register_operand" "R")))]
  "!TARGET_64BIT && TARGET_RVP"
  "addd\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; DI-mode subtraction for RV32 with RVP
;; Uses SUBD instruction; operands must be register pairs (R constraint)
(define_insn "*subdi3_rvp32"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (minus:DI (match_operand:DI 1 "register_operand" "R")
                  (match_operand:DI 2 "register_operand" "R")))]
  "!TARGET_64BIT && TARGET_RVP"
  "subd\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; widen-multiply for RV32 with RVP
(define_insn "*smulsidi3_rvp"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (mult:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
                 (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "wmul\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*umulsidi3_rvp"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (mult:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
                 (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "wmulu\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

(define_insn "*sumulsidi3_rvp"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (mult:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
                 (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "!TARGET_64BIT && TARGET_RVP"
  "wmulsu\t%0, %2, %1"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; -------------------------------------------------------------------------
;; USATI - Unsigned Saturation Immediate
;; -------------------------------------------------------------------------
;; Saturates a signed value to an unsigned n-bit range [0, 2^n - 1].
;; If rs1 < 0, result is 0.
;; If rs1 > (2^n - 1), result is (2^n - 1).
;; Otherwise, result is rs1.
;;
;; Recognize smin(smax(x, 0), (1 << N) - 1) pattern for USATI.
;; Requires Zbb extension for smax/smin RTL operations.

(define_insn "*usati<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(smin:X (smax:X (match_operand:X 1 "register_operand" "r")
			(const_int 0))
		(match_operand:X 2 "const_int_operand" "n")))]
  "TARGET_RVP
   && IN_RANGE (exact_log2 (INTVAL (operands[2]) + 1), 1,
		GET_MODE_BITSIZE (<X:MODE>mode) - 1)"
{
  operands[2] = GEN_INT (exact_log2 (INTVAL (operands[2]) + 1));
  return "usati\t%0,%1,%2";
}
  [(set_attr "type" "arith")
   (set_attr "mode" "<X:MODE>")])

;; MVM/MVMN: Move under Mask / Move under Mask Negated
;; MVM:  rd = (~rs2 & rd) | (rs2 & rs1) - select rs1 where mask=1
;; MVMN: rd = (~rs2 & rs1) | (rs2 & rd) - select rs1 where mask=0
(define_insn "*mvm<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r,r")
	(ior:X (and:X (not:X (match_operand:X 2 "register_operand" "r,r"))
		      (match_operand:X 1 "register_operand" "0,r"))
	       (and:X (match_dup 2)
		      (match_operand:X 3 "register_operand" "r,0"))))]
  "TARGET_RVP"
  "@
   mvm\t%0,%3,%2
   mvmn\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<X:MODE>")])

;; MVM/MVMN XOR forms: ((a ^ b) & mask) ^ a  or  ((a ^ b) & mask) ^ b
(define_insn "*mvm<X:mode>_xor"
  [(set (match_operand:X 0 "register_operand" "=r,r,r,r")
	(xor:X (and:X (xor:X (match_operand:X 1 "register_operand" "0,r,r,0")
			     (match_operand:X 3 "register_operand" "r,0,0,r"))
		      (match_operand:X 2 "register_operand" "r,r,r,r"))
	       (match_operand:X 4 "register_operand" "1,1,3,3")))]
  "TARGET_RVP"
  "@
   mvm\t%0,%3,%2
   mvmn\t%0,%1,%2
   mvm\t%0,%1,%2
   mvmn\t%0,%3,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<X:MODE>")])

;; PSABS: Saturating absolute value for scalar and packed QI/HI modes
(define_insn "ssabs<mode>2"
  [(set (match_operand:QIHI 0 "register_operand" "=r")
	(ss_abs:QIHI (match_operand:QIHI 1 "register_operand" "r")))]
  "TARGET_RVP"
  "psabs.<rvp_width>\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

(define_insn "abs<mode>2"
  [(set (match_operand:QIHI 0 "register_operand" "=r")
	(abs:QIHI (match_operand:QIHI 1 "register_operand" "r")))]
  "TARGET_RVP"
  "psabs.<rvp_width>\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; PAS/PSA - Packed Add-Subtract (alternating operations)
;; pas.hx: rd[even] = rs1[even] + rs2[even], rd[odd] = rs1[odd] - rs2[odd]
;; psa.hx: rd[even] = rs1[even] - rs2[even], rd[odd] = rs1[odd] + rs2[odd]
;;
;; GCC vectorizes and combines this as:
;;   (vec_merge (vec_select (op1 a b) [even indices])
;;              (vec_select (op2 a b) [odd indices]) mask)
;; Uses iterators: pas_even_op, pas_odd_op, pas_insn

;; pas/psa.hx for PV2HI (RV32/RV64)
(define_insn "*rvp_<pas_insn>_hx_v2hi"
  [(set (match_operand:PV2HI 0 "register_operand" "=r")
	(vec_merge:PV2HI
	  (vec_select:PV2HI
	    (pas_even_op:PV2HI
	      (match_operand:PV2HI 1 "register_operand" "r")
	      (match_operand:PV2HI 2 "register_operand" "r"))
	    (parallel [(const_int 0) (const_int 0)]))
	  (vec_select:PV2HI
	    (<pas_odd_op>:PV2HI (match_dup 1) (match_dup 2))
	    (parallel [(const_int 1) (const_int 1)]))
	  (const_int 1)))]
  "TARGET_RVP"
  "<pas_insn>.hx\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "PV2HI")])

;; pas/psa.hx for PV4HI (RV64 only)
(define_insn "*rvp_<pas_insn>_hx_v4hi"
  [(set (match_operand:PV4HI 0 "register_operand" "=r")
	(vec_merge:PV4HI
	  (vec_select:PV4HI
	    (pas_even_op:PV4HI
	      (match_operand:PV4HI 1 "register_operand" "r")
	      (match_operand:PV4HI 2 "register_operand" "r"))
	    (parallel [(const_int 0) (const_int 0) (const_int 2) (const_int 2)]))
	  (vec_select:PV4HI
	    (<pas_odd_op>:PV4HI (match_dup 1) (match_dup 2))
	    (parallel [(const_int 1) (const_int 1) (const_int 3) (const_int 3)]))
	  (const_int 5)))]
  "TARGET_RVP && TARGET_64BIT"
  "<pas_insn>.hx\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "PV4HI")])

;; pas/psa.wx for PV2SI (RV64 only)
(define_insn "*rvp_<pas_insn>_wx_v2si"
  [(set (match_operand:PV2SI 0 "register_operand" "=r")
	(vec_merge:PV2SI
	  (vec_select:PV2SI
	    (pas_even_op:PV2SI
	      (match_operand:PV2SI 1 "register_operand" "r")
	      (match_operand:PV2SI 2 "register_operand" "r"))
	    (parallel [(const_int 0) (const_int 0)]))
	  (vec_select:PV2SI
	    (<pas_odd_op>:PV2SI (match_dup 1) (match_dup 2))
	    (parallel [(const_int 1) (const_int 1)]))
	  (const_int 1)))]
  "TARGET_RVP && TARGET_64BIT"
  "<pas_insn>.wx\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "PV2SI")])

;; Rounding arithmetic shift right immediate - scalar
;; SRARI: rd = (rs1 + (1 << (shamt-1))) >> shamt (with rounding)
;; Pattern matches: (a + (1 << (n-1))) >> n
;; Shift amount must be in range [1, mode_bitsize-1] to avoid UB.
(define_insn "*srari<X:mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(ashiftrt:X
	  (plus:X (match_operand:X 1 "register_operand" "r")
		  (match_operand:X 2 "const_int_operand" "n"))
	  (match_operand:X 3 "const_int_operand" "n")))]
  "TARGET_RVP
   && IN_RANGE (INTVAL (operands[3]), 1, GET_MODE_BITSIZE (<X:MODE>mode) - 1)
   && INTVAL (operands[2]) == ((HOST_WIDE_INT)1 << (INTVAL (operands[3]) - 1))"
  "srari\t%0,%1,%3"
  [(set_attr "type" "shift")
   (set_attr "mode" "<X:MODE>")])

;; SRARI for SI mode on RV64: matches (ashiftrt:DI (sign_extend:DI (plus:SI ...)) shamt)
;; This is the RTL form GCC generates when combining: addiw + srai -> srari
;; Shift amount must be in range [1, 31] for SI mode.
(define_insn "*srari_sidi"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ashiftrt:DI
	  (sign_extend:DI
	    (plus:SI (match_operand:SI 1 "register_operand" "r")
		     (match_operand:SI 2 "const_int_operand" "n")))
	  (match_operand:DI 3 "const_int_operand" "n")))]
  "TARGET_64BIT && TARGET_RVP
   && IN_RANGE (INTVAL (operands[3]), 1, 31)
   && INTVAL (operands[2]) == ((HOST_WIDE_INT)1 << (INTVAL (operands[3]) - 1))"
  "srari\t%0,%1,%3"
  [(set_attr "type" "shift")
   (set_attr "mode" "SI")])

;; PABD - Packed Absolute Difference
;; pabd.b/h rd, rs1, rs2: rd[i] = |rs1[i] - rs2[i]| (signed)
;; pabdu.b/h rd, rs1, rs2: rd[i] = |rs1[i] - rs2[i]| (unsigned)
;;
;; RTL: (minus (smax a b) (smin a b)) for signed
;;      (minus (umax a b) (umin a b)) for unsigned

(define_insn "<abd_optab><mode>3"
  [(set (match_operand:PVQIHI 0 "register_operand" "=r")
	(minus:PVQIHI
	  (abd_maxop:PVQIHI (match_operand:PVQIHI 1 "register_operand" "r")
			    (match_operand:PVQIHI 2 "register_operand" "r"))
	  (<abd_minop>:PVQIHI (match_dup 1) (match_dup 2))))]
  "TARGET_RVP"
  "<abd_insn>.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;;==========================================================================
;; WMACC(U) - Widening signed(unsigned) multuply-addition
;;==========================================================================
;; rd = rd + <u>signed(X[rs1]) * <u>signed(X[rs2])

(define_insn "<u>maddsidi4"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (plus:DI
          (mult:DI (any_extend:DI (match_operand:SI 1 "register_operand" "r"))
                   (any_extend:DI (match_operand:SI 2 "register_operand" "r")))
          (match_operand:DI 3 "register_operand" "0")))]
  "TARGET_RVP && !TARGET_64BIT"
  "wmacc<u>\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "DI")])

;; ABS - Absolute Value for SI/DI modes
;; abs rd, rs1: rd = (rs1 < 0) ? -rs1 : rs1
;;
;; Note: for the most negative representable value, ABS leaves the
;; operand unchanged, matching the usual two's complement expansion
;; (shift + xor + sub) and C's undefined behavior for abs(INT_MIN)
;; and llabs(LLONG_MIN).

(define_insn "abs<GPR:mode>2"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(abs:GPR (match_operand:GPR 1 "register_operand" "r")))]
  "TARGET_RVP"
  "abs\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "<GPR:MODE>")])

;; ABSW - Absolute Value Word (RV64 only)
;; absw rd, rs1: rd = sext.w(abs(rs1[31:0]))
;;
;; For the most negative 32-bit value (0x80000000), the result is
;; also 0x80000000 after abs and sign-extension, as defined by the
;; base P-extension specification.
(define_insn "*absw"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (abs:SI (match_operand:SI 1 "register_operand" "r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "absw\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])

;; Match sign_extend(subreg(abs(di))) pattern from GCC RTL expansion,
;; e.g. an ABS followed by SEXT.W on RV64.
(define_insn "*absw_di_subreg"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI
	  (subreg:SI (abs:DI (match_operand:DI 1 "register_operand" "r")) 0)))]
  "TARGET_RVP && TARGET_64BIT"
  "absw\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "SI")])
