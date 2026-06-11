;; Machine description for RISC-V vector dot-product extensions.
;; Copyright (C) 2026 Free Software Foundation, Inc.
;; Contributed by Jiawei Chen (jiawei@iscas.ac.cn), ISCAS.

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

;;
;; Zvdota dot-product instructions
;;

(define_insn "@pred_<zvqwdot>_vv_zvdota<mode>"
  [(set (match_operand:<ZVQWDOTI_ACC> 0 "register_operand"              "=&vr")
	(if_then_else:<ZVQWDOTI_ACC>
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 5 "vector_length_operand"                    "  rvl")
	     (match_operand 6 "const_int_operand"                        "    i")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:<ZVQWDOTI_ACC>
	    [(match_operand:ZVQWDOTI_SRCMODE 3 "register_operand"        "   vr")
	     (match_operand:ZVQWDOTI_SRCMODE 4 "register_operand"        "   vr")
	     (match_operand:<ZVQWDOTI_ACC> 2 "register_operand"          "    0")
	     (match_operand 9 "const_int_operand"                        "    i")]
	    ZVQWDOT)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "<zvqwdot>.vv\t%0,%3,%4%p1"
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<MODE>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "5")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[6])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[7])"))
   (set (attr "avl_type_idx") (const_int 8))
   (set (attr "altfmt")
	(symbol_ref "INTVAL (operands[9])
		     ? riscv_vector::ALTFMT_ALT
		     : riscv_vector::ALTFMT_NONE"))])

(define_insn "@pred_vfwdota_vv_zvdota<mode>"
  [(set (match_operand:<ZVFWDOTBF_ACC> 0 "register_operand"             "=&vr")
	(if_then_else:<ZVFWDOTBF_ACC>
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 5 "vector_length_operand"                    "  rvl")
	     (match_operand 6 "const_int_operand"                        "    i")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:<ZVFWDOTBF_ACC>
	    [(match_operand:ZVFWDOTBF_SRCMODE 3 "register_operand"       "   vr")
	     (match_operand:ZVFWDOTBF_SRCMODE 4 "register_operand"       "   vr")
	     (match_operand:<ZVFWDOTBF_ACC> 2 "register_operand"         "    0")]
	    UNSPEC_VFWDOTA)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "vfwdota.vv\t%0,%3,%4%p1"
  [(set_attr "type" "vfwmaccbf16")
   (set_attr "mode" "<MODE>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "5")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[6])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[7])"))
   (set (attr "avl_type_idx") (const_int 8))
   (set (attr "altfmt") (symbol_ref "riscv_vector::ALTFMT_ALT"))])

(define_insn "@pred_<zvfqwdot>_vv_zvdota<mode>"
  [(set (match_operand:<ZVFQWDOT8F_ACC> 0 "register_operand"            "=&vr")
	(if_then_else:<ZVFQWDOT8F_ACC>
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 5 "vector_length_operand"                    "  rvl")
	     (match_operand 6 "const_int_operand"                        "    i")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:<ZVFQWDOT8F_ACC>
	    [(match_operand:ZVFQWDOT8F_SRCMODE 3 "register_operand"      "   vr")
	     (match_operand:ZVFQWDOT8F_SRCMODE 4 "register_operand"      "   vr")
	     (match_operand:<ZVFQWDOT8F_ACC> 2 "register_operand"        "    0")
	     (match_operand 9 "const_int_operand"                        "    i")]
	    ZVFQWDOT)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "<zvfqwdot_asm>.vv\t%0,%3,%4%p1"
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<MODE>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "5")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[6])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[7])"))
   (set (attr "avl_type_idx") (const_int 8))
   (set (attr "altfmt")
	(symbol_ref "INTVAL (operands[9])
		     ? riscv_vector::ALTFMT_ALT
		     : riscv_vector::ALTFMT_NONE"))])

;; -------------------------------------------------------------------------------
;; ---- Zvbdota batched dot-product instructions
;; -------------------------------------------------------------------------------

(define_insn "@pred_<zvqwbdot>_vv<mode>"
  [(set (match_operand:ZVQWBDOTI 0 "register_operand"                     "=&vr")
	(if_then_else:ZVQWBDOTI
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 6 "vector_length_operand"                    "  rvl")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (match_operand 9 "const_int_operand"                        "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:ZVQWBDOTI
	    [(match_operand:<ZVQWBDOTI_GROUP> 3 "register_operand"       "   vr")
	     (match_operand:<ZVQWBDOTI_SRC> 4 "register_operand"         "   vr")
	     (match_operand 5 "zvbdota_ci_operand"                      "    i")
	     (match_operand:ZVQWBDOTI 2 "register_operand"               "    0")
	     (match_operand 10 "const_int_operand"                       "    i")]
	    ZVQWBDOT)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "<zvqwbdot>.vv\t%0,%3,%4,%5%p1"
  [(set_attr "type" "viwmuladd")
   (set_attr "mode" "<ZVQWBDOTI_SRC>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "6")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[7])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[8])"))
   (set (attr "avl_type_idx") (const_int 9))
   (set (attr "altfmt")
	(symbol_ref "INTVAL (operands[10])
		     ? riscv_vector::ALTFMT_ALT
		     : riscv_vector::ALTFMT_NONE"))])

(define_insn "@pred_vfwbdota_vv<mode>"
  [(set (match_operand:ZVFWBDOTBF 0 "register_operand"                   "=&vr")
	(if_then_else:ZVFWBDOTBF
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 6 "vector_length_operand"                    "  rvl")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (match_operand 9 "const_int_operand"                        "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:ZVFWBDOTBF
	    [(match_operand:<ZVFWBDOTBF_GROUP> 3 "register_operand"      "   vr")
	     (match_operand:<ZVFWBDOTBF_SRC> 4 "register_operand"        "   vr")
	     (match_operand 5 "zvbdota_ci_operand"                      "    i")
	     (match_operand:ZVFWBDOTBF 2 "register_operand"              "    0")]
	    UNSPEC_VFWBDOTA)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "vfwbdota.vv\t%0,%3,%4,%5%p1"
  [(set_attr "type" "vfwmaccbf16")
   (set_attr "mode" "<ZVFWBDOTBF_SRC>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "6")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[7])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[8])"))
   (set (attr "avl_type_idx") (const_int 9))
   (set (attr "altfmt") (symbol_ref "riscv_vector::ALTFMT_ALT"))])

(define_insn "@pred_<zvfqwbdot>_vv<mode>"
  [(set (match_operand:ZVFQWBDOT8F 0 "register_operand"                  "=&vr")
	(if_then_else:ZVFQWBDOT8F
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 6 "vector_length_operand"                    "  rvl")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (match_operand 9 "const_int_operand"                        "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:ZVFQWBDOT8F
	    [(match_operand:<ZVFQWBDOT8F_GROUP> 3 "register_operand"     "   vr")
	     (match_operand:<ZVFQWBDOT8F_SRC> 4 "register_operand"       "   vr")
	     (match_operand 5 "zvbdota_ci_operand"                      "    i")
	     (match_operand:ZVFQWBDOT8F 2 "register_operand"             "    0")
	     (match_operand 10 "const_int_operand"                       "    i")]
	    ZVFQWBDOT)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "<zvfqwbdot_asm>.vv\t%0,%3,%4,%5%p1"
  [(set_attr "type" "vfwmuladd")
   (set_attr "mode" "<ZVFQWBDOT8F_SRC>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "6")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[7])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[8])"))
   (set (attr "avl_type_idx") (const_int 9))
   (set (attr "altfmt")
	(symbol_ref "INTVAL (operands[10])
		     ? riscv_vector::ALTFMT_ALT
		     : riscv_vector::ALTFMT_NONE"))])

(define_insn "@pred_vfbdota_vv<mode>"
  [(set (match_operand:ZVFBDOT32F 0 "register_operand"                   "=&vr")
	(if_then_else:ZVFBDOT32F
	  (unspec:<VM>
	    [(match_operand:<VM> 1 "vector_mask_operand"                 "vmWc1")
	     (match_operand 6 "vector_length_operand"                    "  rvl")
	     (match_operand 7 "const_int_operand"                        "    i")
	     (match_operand 8 "const_int_operand"                        "    i")
	     (match_operand 9 "const_int_operand"                        "    i")
	     (match_operand 10 "const_int_operand"                       "    i")
	     (reg:SI VL_REGNUM)
	     (reg:SI VTYPE_REGNUM)
	     (reg:SI FRM_REGNUM)] UNSPEC_VPREDICATE)
	  (unspec:ZVFBDOT32F
	    [(match_operand:<ZVFBDOT32F_GROUP> 3 "register_operand"      "   vr")
	     (match_operand:<ZVFBDOT32F_SRC> 4 "register_operand"        "   vr")
	     (match_operand 5 "zvbdota_ci_operand"                      "    i")
	     (match_operand:ZVFBDOT32F 2 "register_operand"              "    0")]
	    UNSPEC_VFBDOTA)
	  (match_dup 2)))]
  "TARGET_VECTOR"
  "vfbdota.vv\t%0,%3,%4,%5%p1"
  [(set_attr "type" "vfmuladd")
   (set_attr "mode" "<ZVFBDOT32F_SRC>")
   (set_attr "merge_op_idx" "2")
   (set_attr "vl_op_idx" "6")
   (set (attr "ta") (symbol_ref "riscv_vector::get_ta (operands[7])"))
   (set (attr "ma") (symbol_ref "riscv_vector::get_ma (operands[8])"))
   (set (attr "avl_type_idx") (const_int 9))
   (set (attr "frm_mode")
	(symbol_ref "riscv_vector::get_frm_mode (operands[10])"))])
