
(define_c_enum "unspec" [
  UNSPEC_VMV

  UNSPEC_VLB UNSPEC_VLBU
  UNSPEC_VLH UNSPEC_VLHU
  UNSPEC_VLW UNSPEC_VLWU

  UNSPEC_VLSB UNSPEC_VLSBU
  UNSPEC_VLSH UNSPEC_VLSHU
  UNSPEC_VLSW UNSPEC_VLSWU

  UNSPEC_VLXB UNSPEC_VLXBU
  UNSPEC_VLXH UNSPEC_VLXHU
  UNSPEC_VLXW UNSPEC_VLXWU

  UNSPEC_VSUXB
  UNSPEC_VSUXH
  UNSPEC_VSUXW
])

(define_insn "*riscv_vsetvl<VIMODES64:sew>m<VIMODES64:lmul>_<P:mode>_clobber"
  [(set (match_operand:P 0 "register_operand" "=&r")
	(unspec:P [(match_operand:P 1 "register_operand" "r")
                   (unspec:VIMODES64 [(const_int 0)] UNSPEC_VSETVL)]
		   UNSPEC_VSETVL))
   (set (reg:SI VL_REGNUM) (unspec:SI [(match_dup 1)
                                       (unspec:VIMODES64 [(const_int 0)] UNSPEC_VSETVL)]
                                      UNSPEC_VSETVL))
   (set (reg:VIMODES64 VTYPE_REGNUM) (unspec:VIMODES64 [(const_int 0)] UNSPEC_VSETVL))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)"
  "vsetvli\t%0,%1,e<VIMODES64:sew>,m<VIMODES64:lmul>"
  [(set_attr "type" "vset")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Write VL & Vtype
(define_insn "riscv_vsetvl<mode>"
  [(set (reg:P VL_REGNUM) (unspec:P [(match_operand:P 0 "register_operand" "r")] UNSPEC_VSETVL))
   (set (reg:P VTYPE_REGNUM) (unspec:P [(match_operand:P 1 "register_operand" "r")] UNSPEC_VSETVL))]
  "TARGET_VECTOR"
  "vsetvl\tx0, %0, %1"
  [(set_attr "type" "vset")
   (set_attr "mode" "none")])

(define_insn_and_split "mov<mode>_v0p7"
  [(set (match_operand:VMODES 0 "reg_or_mem_operand"  "=vr,vr,m")
	(unspec:VMODES
	  [(match_operand:VMODES 1 "reg_or_mem_operand"  "vr,m,vr")]
	 UNSPEC_VWLDST))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)"
  "#"
  "&& reload_completed
   && TARGET_XTHEAD_VSPLIT"
  [(const_int 0)]
  {
    if (!(REG_P (operands[0]) && REG_P (operands[1]) && (REGNO (operands[0]) == REGNO (operands[1]))))
      {
	rtx tmp_vl = TARGET_VECTOR_TEMP2 (Pmode);
	rtx push_vl = TARGET_64BIT ? gen_riscv_vreadvldi (tmp_vl) : gen_riscv_vreadvlsi (tmp_vl);
	rtx tmp_reg = TARGET_VECTOR_TEMP (Pmode);
	rtx push = TARGET_64BIT ? gen_read_vtypedi (tmp_reg) : gen_read_vtypesi (tmp_reg);
	rtx pop = TARGET_64BIT ? gen_riscv_vsetvldi (tmp_vl, tmp_reg) : gen_riscv_vsetvlsi (tmp_vl, tmp_reg);
	emit_insn (push_vl);
	emit_insn (push);
	emit_insn (gen_vsetvli_x0_<vlmode>());
	emit_insn (gen_mov<mode>_nosetvl (operands[0], operands[1]));
	emit_insn (pop);
      }
    else
      emit_note (NOTE_INSN_DELETED);
    DONE;
  }
  [(set_attr "type" "vmove,vload,vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_split
  [(set (match_operand:VMODES 0 "register_operand"  "")
	(unspec:VMODES
	  [(match_operand:VMODES 1 "register_operand"  "")]
	 UNSPEC_VWLDST))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)
   && (REGNO (operands[0]) == REGNO (operands[1]))"
  [(const_int 0)]
  "
    emit_note (NOTE_INSN_DELETED);
    DONE;
  "
)

(define_insn_and_split "mov<mode>_v0p7"
  [(set (match_operand:VMASKMODES 0 "reg_or_mem_operand"  "=vr,vr, m")
	(unspec:VMASKMODES
	  [(match_operand:VMASKMODES 1 "reg_or_mem_operand"  " vr, m, vr")]
	 UNSPEC_VWLDST))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)"
  "#"
  "&& reload_completed
   && TARGET_XTHEAD_VSPLIT"
  [(const_int 0)]
  {
    if (!(REG_P (operands[0]) && REG_P (operands[1]) && (REGNO (operands[0]) == REGNO (operands[1]))))
      {
	rtx tmp_vl = TARGET_VECTOR_TEMP2 (Pmode);
	rtx push_vl = TARGET_64BIT ? gen_riscv_vreadvldi (tmp_vl) : gen_riscv_vreadvlsi (tmp_vl);
	rtx tmp_reg = TARGET_VECTOR_TEMP (Pmode);
	rtx push = TARGET_64BIT ? gen_read_vtypedi (tmp_reg) : gen_read_vtypesi (tmp_reg);
	rtx pop = TARGET_64BIT ? gen_riscv_vsetvldi (tmp_vl, tmp_reg) : gen_riscv_vsetvlsi (tmp_vl, tmp_reg);
	emit_insn (push_vl);
	emit_insn (push);
	emit_insn (gen_vsetvli_x0_vnx16qi());
	emit_insn (gen_mov<mode>_nosetvl (operands[0], operands[1]));
	emit_insn (pop);
      }
    else
      emit_note (NOTE_INSN_DELETED);
    DONE;
  }
  [(set_attr "type" "vmove,vload,vstore")
   (set_attr "mode" "none")])

(define_split
  [(set (match_operand:VMASKMODES 0 "register_operand"  "")
	(unspec:VMASKMODES
	  [(match_operand:VMASKMODES 1 "register_operand"  "")]
	 UNSPEC_VWLDST))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)
   && (REGNO (operands[0]) == REGNO (operands[1]))"
  [(const_int 0)]
  "
    emit_note (NOTE_INSN_DELETED);
    DONE;
  "
)

(define_insn "mov<mode>_nosetvl"
  [(set (match_operand:VMODES 0 "reg_or_mem_operand" "=vr,vr,m")
	(unspec:VMODES
	  [(match_operand:VMODES 1 "reg_or_mem_operand" "vr,m,vr")
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)"
  "@
   vmv.v.v\t%0,%1
   vle.v\t%0,%1
   vse.v\t%1,%0"
  [(set_attr "type" "vmove,vload,vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "mov<mode>_nosetvl"
  [(set (match_operand:VMASKMODES 0 "reg_or_mem_operand" "=vr,vr,m")
	(unspec:VMASKMODES
	  [(match_operand:VMASKMODES 1 "reg_or_mem_operand" "vr,m,vr")
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:VNx16QI VTYPE_REGNUM))]
  "TARGET_VECTOR && target_subset_version_p (\"v\", 0, 7)"
  "@
   vmv.v.v\t%0,%1
   vle.v\t%0,%1
   vse.v\t%1,%0"
  [(set_attr "type" "vmove,vload,vstore")
   (set_attr "mode" "none")])

(define_expand "vext<mode>"
  [(parallel [(set (match_operand:<VSUBMODE> 0 "register_operand")
		   (unspec:<VSUBMODE>
		     [(vec_select:<VSUBMODE>
			(match_operand:VIMODES 1 "register_operand")
			(parallel [(match_operand:SI 2 "register_operand")]))
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vext<mode>_nosetvl"
  [(set (match_operand:<VSUBMODE> 0 "register_operand" "=r")
	(unspec:<VSUBMODE>
	  [(vec_select:<VSUBMODE>
	     (match_operand:VIMODES 1 "register_operand" "vr")
	     (parallel [(match_operand:SI 2 "register_operand" "r")]))
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vext.x.v\t%0,%1,%2"
  [(set_attr "type" "vmove")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;(define_expand "vmv<mode>"
;  [(parallel [(set (match_operand:VMODES 0 "register_operand")
;		   (unspec:VMODES
;		     [(unspec:VMODES
;			[(match_operand:VMODES 1 "register_operand")]
;		       UNSPEC_VMV)
;		      (reg:SI VL_REGNUM)]
;		    UNSPEC_USEVL))
;	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
;  "TARGET_VECTOR"
;{
;})
;
;(define_insn "vmv<mode>_nosetvl"
;  [(set (match_operand:VMODES 0 "register_operand" "=vr")
;	(unspec:VMODES
;	  [(unspec:VMODES
;	     [(match_operand:VMODES 1 "register_operand" "vr")]
;	    UNSPEC_VMV)
;	   (reg:SI VL_REGNUM)]
;	 UNSPEC_USEVL))
;   (use (reg:<VLMODE> VTYPE_REGNUM))]
;  "TARGET_VECTOR"
;  "vmv.v.v\t%0,%1"
;  [(set_attr "type" "vector")
;   (set_attr "mode" "none")])

;; Load/store instructions.

(define_int_iterator UNSPEC_VLMEM_OP [
  UNSPEC_VLB UNSPEC_VLBU
  UNSPEC_VLH UNSPEC_VLHU
  UNSPEC_VLW UNSPEC_VLWU
])

(define_int_iterator UNSPEC_VLSMEM_OP [
  UNSPEC_VLSB UNSPEC_VLSBU
  UNSPEC_VLSH UNSPEC_VLSHU
  UNSPEC_VLSW UNSPEC_VLSWU
])

(define_int_iterator UNSPEC_VLXMEM_OP [
  UNSPEC_VLXB UNSPEC_VLXBU
  UNSPEC_VLXH UNSPEC_VLXHU
  UNSPEC_VLXW UNSPEC_VLXWU
])

(define_int_attr vlmem_op_attr [
  (UNSPEC_VLB "b") (UNSPEC_VLBU "bu")
  (UNSPEC_VLH "h") (UNSPEC_VLHU "hu")
  (UNSPEC_VLW "w") (UNSPEC_VLWU "wu")

  (UNSPEC_VLSB "b") (UNSPEC_VLSBU "bu")
  (UNSPEC_VLSH "h") (UNSPEC_VLSHU "hu")
  (UNSPEC_VLSW "w") (UNSPEC_VLSWU "wu")

  (UNSPEC_VLXB "b") (UNSPEC_VLXBU "bu")
  (UNSPEC_VLXH "h") (UNSPEC_VLXHU "hu")
  (UNSPEC_VLXW "w") (UNSPEC_VLXWU "wu")

  (UNSPEC_VSUXB "b")
  (UNSPEC_VSUXH "h")
  (UNSPEC_VSUXW "w")
])

(define_int_attr vlmem_order_attr [
  (UNSPEC_VLXB "")
  (UNSPEC_VLXH "")
  (UNSPEC_VLXW "")

  (UNSPEC_VSUXB "u")
  (UNSPEC_VSUXH "u")
  (UNSPEC_VSUXW "u")
])

(define_int_iterator UNSPEC_VSMEM_OP [
  UNSPEC_VLB
  UNSPEC_VLH
  UNSPEC_VLW
])

(define_int_iterator UNSPEC_VSSMEM_OP [
  UNSPEC_VLSB
  UNSPEC_VLSH
  UNSPEC_VLSW
])

(define_int_iterator UNSPEC_VSXMEM_OP [
  UNSPEC_VLXB
  UNSPEC_VLXH
  UNSPEC_VLXW
  UNSPEC_VSUXB
  UNSPEC_VSUXH
  UNSPEC_VSUXW
])

(define_int_iterator UNSPEC_VSOXMEM_OP [
  UNSPEC_VLXB
  UNSPEC_VLXH
  UNSPEC_VLXW
])

;; Vector Unit-Stride Instructions

(define_expand "vl<vlmem_op_attr><mode>"
  [(parallel [(set (match_operand:VIMODES 0 "register_operand")
		   (unspec:VIMODES
		     [(mem:VIMODES (match_operand 1 "register_operand"))
		      (reg:SI VL_REGNUM)]
		    UNSPEC_VLMEM_OP))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vl<vlmem_op_attr><mode>_nosetvl"
  [(set (match_operand:VIMODES 0 "register_operand" "=vr")
	(unspec:VIMODES
	  [(match_operand:VIMODES 1 "memory_operand" "m")
	   (reg:SI VL_REGNUM)]
	 UNSPEC_VLMEM_OP))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vl<vlmem_op_attr>.v\t%0,%1"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vl<vlmem_op_attr><mode>_mask"
  [(parallel [(set (match_operand:VIMODES 0 "register_operand")
		   (unspec:VIMODES
		     [(if_then_else:VIMODES
			(match_operand:<VCMPEQUIV> 1 "register_operand")
			(mem:VIMODES
			  (match_operand 3 "register_operand"))
			(match_operand:VIMODES 2 "register_operand"))
		       (reg:SI VL_REGNUM)]
		    UNSPEC_VLMEM_OP))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vl<vlmem_op_attr><mode>_mask_nosetvl"
  [(set (match_operand:VIMODES 0 "register_operand" "=vr")
	(unspec:VIMODES
	  [(if_then_else:VIMODES
	     (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")
	     (match_operand:VIMODES 1 "memory_operand" "m")
	     (match_operand:VIMODES 3 "register_operand" "0"))
	   (reg:SI VL_REGNUM)]
	 UNSPEC_VLMEM_OP))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vl<vlmem_op_attr>.v\t%0,%1,%2.t"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vs<vlmem_op_attr><mode>"
  [(parallel [(set (mem:VIMODES (match_operand 1 "register_operand"))
		   (unspec:VIMODES
		     [(match_operand:VIMODES 0 "register_operand")
		      (mem:VIMODES (match_dup 1))
		      (reg:SI VL_REGNUM)]
		    UNSPEC_VSMEM_OP))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vs<vlmem_op_attr><mode>_nosetvl"
  [(set (match_operand:VIMODES 1 "memory_operand" "+m")
	(unspec:VIMODES
	  [(match_operand:VIMODES 0 "register_operand" "vr")
	   (match_dup 1)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_VSMEM_OP))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vs<vlmem_op_attr>.v\t%0,%1"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vs<vlmem_op_attr><mode>_mask"
  [(parallel [(set (mem:VIMODES (match_operand 2 "register_operand"))
		   (unspec:VIMODES
		     [(unspec:VIMODES
			[(match_operand:<VCMPEQUIV> 0 "register_operand")
			 (match_operand:VIMODES 1 "register_operand")
			 (mem:VIMODES (match_dup 2))]
		       UNSPEC_MASKED_STORE)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_VSMEM_OP))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vs<vlmem_op_attr><mode>_mask_nosetvl"
  [(set (match_operand:VIMODES 0 "memory_operand" "+m")
	(unspec:VIMODES
	  [(unspec:VIMODES
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VIMODES 2 "register_operand" "vr")
	      (match_dup 0)]
	    UNSPEC_MASKED_STORE)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_VSMEM_OP))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vs<vlmem_op_attr>.v\t%2,%0,%1.t"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector Strided Instructions

(define_expand "vls<vlmem_op_attr><mode>"
  [(parallel [(set (match_operand:VIMODES 0 "register_operand")
		   (unspec:VIMODES
		     [(unspec:VIMODES
			[(match_operand 1 "register_operand")
			 (match_operand 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vls<vlmem_op_attr><mode>_nosetvl"
  [(set (match_operand:VIMODES 0 "register_operand" "=&vr")
	(unspec:VIMODES
	  [(unspec:VIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand 2 "register_operand" "r")
	      (mem:BLK (scratch))]
	    UNSPEC_VLSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vls<vlmem_op_attr>.v\t%0,(%1),%2"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vls<vlmem_op_attr><mode>_mask"
  [(parallel [(set (match_operand:VIMODES 0 "register_operand")
		   (unspec:VIMODES
		     [(if_then_else:VIMODES
		      (match_operand:<VCMPEQUIV> 1 "register_operand")
		      (unspec:VIMODES
			[(match_operand 3 "register_operand")
			 (match_operand 4 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLSMEM_OP)
		      (match_operand:VIMODES 2 "register_operand"))
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vls<vlmem_op_attr><mode>_mask_nosetvl"
  [(set (match_operand:VIMODES 0 "register_operand" "=vr")
	(unspec:VIMODES
	  [(if_then_else:VIMODES
	     (match_operand:<VCMPEQUIV> 3 "register_operand" "vm")
	     (unspec:VIMODES
	       [(match_operand 1 "register_operand" "r")
		(match_operand 2 "register_operand" "r")
		(mem:BLK (scratch))]
	      UNSPEC_VLSMEM_OP)
	     (match_operand:VIMODES 4 "register_operand" "0"))
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vls<vlmem_op_attr>.v\t%0,(%1),%2,%3.t"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vss<vlmem_op_attr><mode>"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
		        [(match_operand:VIMODES 0 "register_operand")
			 (match_operand 1 "register_operand")
			 (match_operand 2 "register_operand")]
		       UNSPEC_VSSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vss<vlmem_op_attr><mode>_nosetvl"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand:VIMODES 0 "register_operand" "vr")
	      (match_operand 1 "register_operand" "r")
	      (match_operand 2 "register_operand" "r")]
	    UNSPEC_VSSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vss<vlmem_op_attr>.v\t%0,(%1),%2"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vss<vlmem_op_attr><mode>_mask"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand:<VCMPEQUIV> 0 "register_operand")
			 (match_operand:VIMODES 1 "register_operand")
			 (match_operand 2 "register_operand")
			 (match_operand 3 "register_operand")]
		       UNSPEC_VSSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vss<vlmem_op_attr><mode>_mask_nosetvl"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand:<VCMPEQUIV> 3 "register_operand" "vm")
	      (match_operand:VIMODES 0 "register_operand" "vr")
	      (match_operand 1 "register_operand" "r")
	      (match_operand 2 "register_operand" "r")]
	    UNSPEC_VSSMEM_OP)
	    (reg:SI VL_REGNUM)]
	  UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vss<vlmem_op_attr>.v\t%0,(%1),%2,%3.t"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector Indexed Instructions

(define_expand "vlx<vlmem_op_attr><mode>"
  [(parallel [(set (match_operand:VIMODES 0 "register_operand")
		   (unspec:VIMODES
		     [(unspec:VIMODES
			[(match_operand 1 "register_operand")
			 (match_operand:VIMODES 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vlx<vlmem_op_attr><mode>_nosetvl"
  [(set (match_operand:VIMODES 0 "register_operand" "=&vr")
	(unspec:VIMODES
	  [(unspec:VIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand:VIMODES 2 "register_operand" "vr")
	      (mem:BLK (scratch))]
	    UNSPEC_VLXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlx<vlmem_op_attr>.v\t%0,(%1),%2"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vlx<vlmem_op_attr><mode>_mask"
  [(parallel [(set (match_operand:VIMODES 0 "register_operand")
		   (unspec:VIMODES
		     [(unspec:VIMODES
			[(match_operand:<VCMPEQUIV> 1 "register_operand")
			 (match_operand:VIMODES 2 "register_operand")
			 (match_operand 3 "register_operand")
			 (match_operand:VIMODES 4 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vlx<vlmem_op_attr><mode>_mask_nosetvl"
  [(set (match_operand:VIMODES 0 "register_operand" "=vr")
	(unspec:VIMODES
	  [(unspec:VIMODES
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VIMODES 2 "register_operand" "0")
	      (match_operand 3 "register_operand" "r")
	      (match_operand:VIMODES 4 "register_operand" "vr")
	      (mem:BLK (scratch))]
	    UNSPEC_VLXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlx<vlmem_op_attr>.v\t%0,(%3),%4,%1.t"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector Ordered-Indexed Store instructions for builtin

(define_expand "vs<vlmem_order_attr>x<vlmem_op_attr><mode>"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 0 "register_operand")
			 (match_operand:VIMODES 1 "register_operand")
			 (match_operand:VIMODES 2 "register_operand")]
		       UNSPEC_VSXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vs<vlmem_order_attr>x<vlmem_op_attr><mode>_nosetvl"
   [(set (mem:BLK (scratch))
	 (unspec:BLK
	   [(unspec:BLK
	      [(match_operand 0 "register_operand" "r")
	       (match_operand:VIMODES 1 "register_operand" "vr")
	       (match_operand:VIMODES 2 "register_operand" "vr")]
	     UNSPEC_VSXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vs<vlmem_order_attr>x<vlmem_op_attr>.v\t%2,(%0),%1"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vs<vlmem_order_attr>x<vlmem_op_attr><mode>_mask"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand:<VCMPEQUIV> 0 "register_operand")
			 (match_operand 1 "register_operand")
			 (match_operand:VIMODES 2 "register_operand")
			 (match_operand:VIMODES 3 "register_operand")]
		       UNSPEC_VSXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vs<vlmem_order_attr>x<vlmem_op_attr><mode>_mask_nosetvl"
   [(set (mem:BLK (scratch))
	 (unspec:BLK
	   [(unspec:BLK
	      [(match_operand:<VCMPEQUIV> 0 "register_operand" "vm")
	       (match_operand 1 "register_operand" "r")
	       (match_operand:VIMODES 2 "register_operand" "vr")
	       (match_operand:VIMODES 3 "register_operand" "vr")]
	     UNSPEC_VSXMEM_OP)
	   (reg:SI VL_REGNUM)]
	  UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vs<vlmem_order_attr>x<vlmem_op_attr>.v\t%3,(%1),%2,%0.t"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector segment load/store

;; Vector Unit-Stride Instructions

(define_expand "vseg_load<vlmem_op_attr><mode>"
  [(parallel [(set (match_operand:VTIMODES 0 "register_operand")
		   (unspec:VTIMODES
		     [(unspec:VTIMODES
			[(match_operand 1 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_load<vlmem_op_attr><mode>"
  [(set (match_operand:VTIMODES 0 "register_operand" "=vr")
	(unspec:VTIMODES
	  [(unspec:VTIMODES
	     [(match_operand 1 "register_operand" "r")
	      (mem:BLK (scratch))]
	    UNSPEC_VLMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlseg<NF><vlmem_op_attr>.v\t%0, (%1)"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_load<vlmem_op_attr><mode>_mask"
  [(parallel [(set (match_operand:VTIMODES 0 "register_operand")
		   (unspec:VTIMODES
		     [(unspec:VTIMODES
			[(match_operand 3 "register_operand")
			 (match_operand:<VCMPEQUIV> 1 "register_operand")
			 (match_operand:VTIMODES 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_load<vlmem_op_attr><mode>_mask"
  [(set (match_operand:VTIMODES 0 "register_operand" "=vr")
	(unspec:VTIMODES
	  [(unspec:VTIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")
	      (match_operand:VTIMODES 3 "register_operand" "0")
	      (mem:BLK (scratch))]
	    UNSPEC_VLMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlseg<NF><vlmem_op_attr>.v\t%0, (%1), %2.t"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_store<vlmem_op_attr><mode>"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 1 "register_operand")
			 (match_operand:VTIMODES 0 "register_operand")]
		       UNSPEC_VSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_store<vlmem_op_attr><mode>"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand 0 "register_operand" "r")
	      (match_operand:VTIMODES 1 "register_operand" "vr")]
	    UNSPEC_VSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vsseg<NF><vlmem_op_attr>.v\t%1, (%0)"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_store<vlmem_op_attr><mode>_mask"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 2 "register_operand")
			 (match_operand:VTIMODES 1 "register_operand")
			 (match_operand:<VCMPEQUIV> 0 "register_operand")]
		       UNSPEC_VSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_store<vlmem_op_attr><mode>_mask"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand 0 "register_operand" "r")
	      (match_operand:VTIMODES 1 "register_operand" "vr")
	      (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")]
	    UNSPEC_VSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vsseg<NF><vlmem_op_attr>.v\t%1, (%0), %2.t"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector Strided Instructions

(define_expand "vseg_strided_load<vlmem_op_attr><mode>"
  [(parallel [(set (match_operand:VTIMODES 0 "register_operand")
		   (unspec:VTIMODES
		     [(unspec:VTIMODES
			[(match_operand 1 "register_operand")
			 (match_operand 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_strided_load<vlmem_op_attr><mode>"
  [(set (match_operand:VTIMODES 0 "register_operand" "=vr")
	(unspec:VTIMODES
	  [(unspec:VTIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand 2 "register_operand" "r")
	      (mem:BLK (scratch))]
	    UNSPEC_VLSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlsseg<NF><vlmem_op_attr>.v\t%0, (%1), %2"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_strided_load<vlmem_op_attr><mode>_mask"
  [(parallel [(set (match_operand:VTIMODES 0 "register_operand")
		   (unspec:VTIMODES
		     [(unspec:VTIMODES
			[(match_operand 3 "register_operand")
			 (match_operand 4 "register_operand")
			 (match_operand:<VCMPEQUIV> 1 "register_operand")
			 (match_operand:VTIMODES 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_strided_load<vlmem_op_attr><mode>_mask"
  [(set (match_operand:VTIMODES 0 "register_operand" "=vr")
	(unspec:VTIMODES
	  [(unspec:VTIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand 4 "register_operand" "r")
	      (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")
	      (match_operand:VTIMODES 3 "register_operand" "0")
	      (mem:BLK (scratch))]
	    UNSPEC_VLSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlsseg<NF><vlmem_op_attr>.v\t%0, (%1), %4, %2.t"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_strided_store<vlmem_op_attr><mode>"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 1 "register_operand")
			 (match_operand 2 "register_operand")
			 (match_operand:VTIMODES 0 "register_operand")]
		       UNSPEC_VSSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_strided_store<vlmem_op_attr><mode>"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand 0 "register_operand" "r")
	      (match_operand 2 "register_operand" "r")
	      (match_operand:VTIMODES 1 "register_operand" "vr")]
	    UNSPEC_VSSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vssseg<NF><vlmem_op_attr>.v\t%1, (%0), %2"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_strided_store<vlmem_op_attr><mode>_mask"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 2 "register_operand")
			 (match_operand 3 "register_operand")
			 (match_operand:VTIMODES 1 "register_operand")
			 (match_operand:<VCMPEQUIV> 0 "register_operand")]
		       UNSPEC_VSSMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_strided_store<vlmem_op_attr><mode>_mask"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand 0 "register_operand" "r")
	      (match_operand 3 "register_operand" "r")
	      (match_operand:VTIMODES 1 "register_operand" "vr")
	      (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")]
	    UNSPEC_VSSMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vssseg<NF><vlmem_op_attr>.v\t%1, (%0), %3, %2.t"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector Indexed Instructions

(define_expand "vseg_idx_load<vlmem_op_attr><mode>"
  [(parallel [(set (match_operand:VTIMODES 0 "register_operand")
		   (unspec:VTIMODES
		     [(unspec:VTIMODES
			[(match_operand 1 "register_operand")
			 (match_operand 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_idx_load<vlmem_op_attr><mode>"
  [(set (match_operand:VTIMODES 0 "register_operand" "=&vr")
	(unspec:VTIMODES
	  [(unspec:VTIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand 2 "register_operand" "vr")
	      (mem:BLK (scratch))]
	    UNSPEC_VLXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlxseg<NF><vlmem_op_attr>.v\t%0, (%1), %2"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_idx_load<vlmem_op_attr><mode>_mask"
  [(parallel [(set (match_operand:VTIMODES 0 "register_operand")
		   (unspec:VTIMODES
		     [(unspec:VTIMODES
			[(match_operand 3 "register_operand")
			 (match_operand 4 "register_operand")
			 (match_operand:<VCMPEQUIV> 1 "register_operand")
			 (match_operand:VTIMODES 2 "register_operand")
			 (mem:BLK (scratch))]
		       UNSPEC_VLXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_idx_load<vlmem_op_attr><mode>_mask"
  [(set (match_operand:VTIMODES 0 "register_operand" "=&vr")
	(unspec:VTIMODES
	  [(unspec:VTIMODES
	     [(match_operand 1 "register_operand" "r")
	      (match_operand 4 "register_operand" "vr")
	      (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")
	      (match_operand:VTIMODES 3 "register_operand" "0")
	      (mem:BLK (scratch))]
	    UNSPEC_VLXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vlxseg<NF><vlmem_op_attr>.v\t%0, (%1), %4, %2.t"
  [(set_attr "type" "vload")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_idx_store<vlmem_op_attr><mode>"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 1 "register_operand")
			 (match_operand 2 "register_operand")
			 (match_operand:VTIMODES 0 "register_operand")]
		       UNSPEC_VSOXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_idx_store<vlmem_op_attr><mode>"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand 0 "register_operand" "r")
	      (match_operand 2 "register_operand" "vr")
	      (match_operand:VTIMODES 1 "register_operand" "vr")]
	    UNSPEC_VSOXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vsxseg<NF><vlmem_op_attr>.v\t%1, (%0), %2"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_expand "vseg_idx_store<vlmem_op_attr><mode>_mask"
  [(parallel [(set (mem:BLK (scratch))
		   (unspec:BLK
		     [(unspec:BLK
			[(match_operand 2 "register_operand")
			 (match_operand 3 "register_operand")
			 (match_operand:VTIMODES 1 "register_operand")
			 (match_operand:<VCMPEQUIV> 0 "register_operand")]
		       UNSPEC_VSOXMEM_OP)
		      (reg:SI VL_REGNUM)]
		    UNSPEC_USEVL))
	      (use (reg:<VLMODE> VTYPE_REGNUM))])]
  "TARGET_VECTOR"
{
})

(define_insn "*vseg_idx_store<vlmem_op_attr><mode>_mask"
  [(set (mem:BLK (scratch))
	(unspec:BLK
	  [(unspec:BLK
	     [(match_operand 0 "register_operand" "r")
	      (match_operand 3 "register_operand" "vr")
	      (match_operand:VTIMODES 1 "register_operand" "vr")
	      (match_operand:<VCMPEQUIV> 2 "register_operand" "vm")]
	    UNSPEC_VSOXMEM_OP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vsxseg<NF><vlmem_op_attr>.v\t%1, (%0), %3, %2.t"
  [(set_attr "type" "vstore")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])
