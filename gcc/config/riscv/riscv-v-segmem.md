
(define_int_iterator UNSPEC_VLSEG_NFOP [
  UNSPEC_VLSEGB UNSPEC_VLSEGBU
  UNSPEC_VLSEGH UNSPEC_VLSEGHU
  UNSPEC_VLSEGW UNSPEC_VLSEGWU
  UNSPEC_VLSEGE
])

(define_int_iterator UNSPEC_VLSSEG_NFOP [
  UNSPEC_VLSSEGB UNSPEC_VLSSEGBU
  UNSPEC_VLSSEGH UNSPEC_VLSSEGHU
  UNSPEC_VLSSEGW UNSPEC_VLSSEGWU
  UNSPEC_VLSSEGE
])

(define_int_iterator UNSPEC_VLXSEG_NFOP [
  UNSPEC_VLXSEGB UNSPEC_VLXSEGBU
  UNSPEC_VLXSEGH UNSPEC_VLXSEGHU
  UNSPEC_VLXSEGW UNSPEC_VLXSEGWU
  UNSPEC_VLXSEGE
])

(define_int_attr vlseg_nfop_attr [
  (UNSPEC_VLSEGB "b") (UNSPEC_VLSEGBU "bu")
  (UNSPEC_VLSEGH "h") (UNSPEC_VLSEGHU "hu")
  (UNSPEC_VLSEGW "w") (UNSPEC_VLSEGWU "wu")
  (UNSPEC_VLSEGE "e")

  (UNSPEC_VLSSEGB "b") (UNSPEC_VLSSEGBU "bu")
  (UNSPEC_VLSSEGH "h") (UNSPEC_VLSSEGHU "hu")
  (UNSPEC_VLSSEGW "w") (UNSPEC_VLSSEGWU "wu")
  (UNSPEC_VLSSEGE "e")

  (UNSPEC_VLXSEGB "b") (UNSPEC_VLXSEGBU "bu")
  (UNSPEC_VLXSEGH "h") (UNSPEC_VLXSEGHU "hu")
  (UNSPEC_VLXSEGW "w") (UNSPEC_VLXSEGWU "wu")
  (UNSPEC_VLXSEGE "e")
])

(define_int_iterator UNSPEC_VSSEG_NFOP [
  UNSPEC_VLSEGB
  UNSPEC_VLSEGH
  UNSPEC_VLSEGW
  UNSPEC_VLSEGE
])

(define_int_iterator UNSPEC_VSSSEG_NFOP [
  UNSPEC_VLSSEGB
  UNSPEC_VLSSEGH
  UNSPEC_VLSSEGW
  UNSPEC_VLSSEGE
])

(define_int_iterator UNSPEC_VSXSEG_NFOP [
  UNSPEC_VLXSEGB
  UNSPEC_VLXSEGH
  UNSPEC_VLXSEGW
  UNSPEC_VLXSEGE
])

(define_expand "riscv_vseg_element_get_<mode>"
  [(match_operand:<SEG_BASE_MODE> 0 "register_operand")
   (match_operand:VANYSEG128 1 "register_operand")
   (match_operand:SI 2 "const_int_operand")]
  "TARGET_XTHEAD_VECTOR"
{
  if (INTVAL (operands[2]) < 0
      || (INTVAL (operands[2]) > <seg_nf>))
    {
      gcc_unreachable ();
      FAIL;
    }
  poly_int64 offset = INTVAL (operands[2]) * GET_MODE_SIZE (<SEG_BASE_MODE>mode);
  rtx subreg = simplify_gen_subreg (<SEG_BASE_MODE>mode, operands[1],
				    <MODE>mode, offset);
  emit_move_insn (operands[0], subreg);
  DONE;
})

(define_expand "riscv_vseg_element_set_<mode>"
  [(match_operand:VANYSEG128 0 "register_operand")
   (match_operand:VANYSEG128 1 "register_operand")
   (match_operand:SI 2 "const_int_operand")
   (match_operand:<SEG_BASE_MODE> 3 "register_operand")]
  "TARGET_XTHEAD_VECTOR"
{
  if (INTVAL (operands[2]) < 0
      || (INTVAL (operands[2]) > <seg_nf>))
    {
      gcc_unreachable ();
      FAIL;
    }
  poly_int64 offset = INTVAL (operands[2]) * GET_MODE_SIZE (<SEG_BASE_MODE>mode);
  emit_move_insn (operands[0], operands[1]);
  rtx subreg = simplify_gen_subreg (<SEG_BASE_MODE>mode, operands[0],
				    <MODE>mode, offset);
  emit_move_insn (subreg, operands[3]);
  DONE;
})

;; Vector Unit-Stride Segment Loads and Stores
;; ===========================================

; vlseg<nf>{b,h,w}.v vd, (rs1)
; vlseg<nf>e.v vd, (rs1)
; vlseg<nf>{b,h,w}u.v vd, (rs1)

(define_expand "riscv_vlseg<vlseg_nfop_attr>v_<mode>"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=v")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand:SI 2 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[1] = gen_rtx_MEM (<MODE>mode, operands[1]);
  }
)

(define_insn_and_split "riscv_vlseg<vlseg_nfop_attr>v_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=v")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "riscv_vector_mem_operand" "Qmv")
			    (match_operand:SI 2 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vlseg<vlseg_nfop_attr>v_<mode>_internal (
      operands[0], operands[1]));
    DONE;
  }
  [(set_attr "type" "vload")]
)

(define_insn "riscv_vlseg<vlseg_nfop_attr>v_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=v")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "riscv_vector_mem_operand" "Qmv")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vlseg<seg_nf><vlseg_nfop_attr>.v\t%0,%1");
  }
  [(set_attr "type" "vload")]
)

; vlseg<nf>{b,h,w}.v vd, (rs1), vm
; vlseg<nf>e.v vd, (rs1), vm
; vlseg<nf>{b,h,w}u.v vd, (rs1), vm

(define_expand "riscv_vlseg<vlseg_nfop_attr>v_mask_<mode>"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand 2 "register_operand" "r")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (match_operand:SI 4 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[2] = gen_rtx_MEM (<MODE>mode, operands[2]);
  }
)

(define_insn_and_split "riscv_vlseg<vlseg_nfop_attr>v_mask_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand:VANYSEG128 2 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (match_operand:SI 4 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vlseg<vlseg_nfop_attr>v_mask_<mode>_internal (
      operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vload")]
)

(define_insn "riscv_vlseg<vlseg_nfop_attr>v_mask_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand:VANYSEG128 2 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vlseg<seg_nf><vlseg_nfop_attr>.v\t%0,%2,%3.t");
  }
  [(set_attr "type" "vload")]
)

; vsseg<nf>{b,h,w,e}.v vs3, (rs1)

(define_expand "riscv_vsseg<vlseg_nfop_attr>v_<mode>"
  [(set (match_operand 0 "register_operand" "=r")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "register_operand" "v")
			    (match_operand:SI 2 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[0] = gen_rtx_MEM (<MODE>mode, operands[0]);
    emit_insn (gen_riscv_vsseg<vlseg_nfop_attr>v_<mode>_split (
      operands[0], operands[1], operands[2]));
    DONE;
  }
)

(define_insn_and_split "riscv_vsseg<vlseg_nfop_attr>v_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "register_operand" "v")
			    (match_operand:SI 2 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vsseg<vlseg_nfop_attr>v_<mode>_internal (operands[0],
      operands[1]));
    DONE;
  }
  [(set_attr "type" "vstore")]
)

(define_insn "riscv_vsseg<vlseg_nfop_attr>v_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "register_operand" "v")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vsseg<seg_nf><vlseg_nfop_attr>.v\t%1,%0");
  }
  [(set_attr "type" "vstore")]
)

; vsseg<nf>{b,h,w,e}.v vs3, (rs1), vm

(define_expand "riscv_vsseg<vlseg_nfop_attr>v_mask_<mode>"
  [(set (match_operand 0 "register_operand" "=r")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "register_operand" "v")
			    (match_operand 2 "vmask_mode_register_operand" "w")
			    (match_operand:SI 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[0] = gen_rtx_MEM (<MODE>mode, operands[0]);
    emit_insn (gen_riscv_vsseg<vlseg_nfop_attr>v_mask_<mode>_split (
		operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
)

(define_insn_and_split "riscv_vsseg<vlseg_nfop_attr>v_mask_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "vmask_mode_register_operand" "w")
			    (match_operand:SI 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vsseg<vlseg_nfop_attr>v_mask_<mode>_internal (
      operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vstore")]
)

(define_insn "riscv_vsseg<vlseg_nfop_attr>v_mask_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "register_operand" "v")
			    (match_operand 2 "vmask_mode_register_operand" "w")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vsseg<seg_nf><vlseg_nfop_attr>.v\t%1,%0,%2.t");
  }
  [(set_attr "type" "vstore")]
)

;; Vector Strided Segment Loads and Stores
;; =======================================

; vlsseg<nf>{b,h,w}.v vd, (rs1), rs2
; vlsseg<nf>e.v vd, (rs1), rs2
; vlsseg<nf>{b,h,w}u.v vd, (rs1), rs2

(define_expand "riscv_vlsseg<vlseg_nfop_attr>v_<mode>"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=v")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand 2 "register_operand" "r")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[1] = gen_rtx_MEM (<MODE>mode, operands[1]);
  }
)

(define_insn_and_split "riscv_vlsseg<vlseg_nfop_attr>v_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=v")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 2 "register_operand" "r")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vlsseg<vlseg_nfop_attr>v_<mode>_internal (
		operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vload")]
)

(define_insn "riscv_vlsseg<vlseg_nfop_attr>v_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=v")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 2 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vlsseg<seg_nf><vlseg_nfop_attr>.v\t%0,%1,%2");
  }
  [(set_attr "type" "vload")]
)

; vlsseg<nf>{b,h,w}.v vd, (rs1), rs2, vm
; vlsseg<nf>e.v vd, (rs1), rs2, vm
; vlsseg<nf>{b,h,w}u.v vd, (rs1), rs2, vm

(define_expand "riscv_vlsseg<vlseg_nfop_attr>v_mask_<mode>"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand 2 "register_operand" "r")
			    (match_operand 3 "register_operand" "r")
			    (match_operand 4 "vmask_mode_register_operand" "w")
			    (match_operand 5 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[2] = gen_rtx_MEM (<MODE>mode, operands[2]);
  }
)

(define_insn_and_split "riscv_vlsseg<vlseg_nfop_attr>v_mask_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand:VANYSEG128 2 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 3 "register_operand" "r")
			    (match_operand 4 "vmask_mode_register_operand" "w")
			    (match_operand 5 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_vlsseg<vlseg_nfop_attr>v_mask_<mode>_internal (
      operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vload")]
)

(define_insn "riscv_vlsseg<vlseg_nfop_attr>v_mask_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand:VANYSEG128 2 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 3 "register_operand" "r")
			    (match_operand 4 "vmask_mode_register_operand" "w")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLSSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vlsseg<seg_nf><vlseg_nfop_attr>.v\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vload")]
)

; vssseg<nf>{b,h,w,e}.v vs3, (rs1), rs2

(define_expand "riscv_vssseg<vlseg_nfop_attr>v_<mode>"
  [(set (match_operand 0 "register_operand" "=r")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand:VANYSEG128 2 "register_operand" "v")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[0] = gen_rtx_MEM (<MODE>mode, operands[0]);
    emit_insn (gen_riscv_vssseg<vlseg_nfop_attr>v_<mode>_split (
		operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
)

(define_insn_and_split "riscv_vssseg<vlseg_nfop_attr>v_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand:VANYSEG128 2 "register_operand" "v")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vssseg<vlseg_nfop_attr>v_<mode>_internal (
		operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vstore")]
)

(define_insn "riscv_vssseg<vlseg_nfop_attr>v_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand:VANYSEG128 2 "register_operand" "v")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vssseg<seg_nf><vlseg_nfop_attr>.v\t%2,%0,%1");
  }
  [(set_attr "type" "vstore")]
)

; vssseg<nf>{b,h,w,e}.v vs3, (rs1), rs2, vm

(define_expand "riscv_vssseg<vlseg_nfop_attr>v_mask_<mode>"
  [(set (match_operand 0 "register_operand" "=r")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (match_operand 4 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[0] = gen_rtx_MEM (<MODE>mode, operands[0]);
    emit_insn (gen_riscv_vssseg<vlseg_nfop_attr>v_mask_<mode>_split (
		operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
)

(define_insn_and_split "riscv_vssseg<vlseg_nfop_attr>v_mask_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (match_operand 4 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vssseg<vlseg_nfop_attr>v_mask_<mode>_internal (
		operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vstore")]
)

(define_insn "riscv_vssseg<vlseg_nfop_attr>v_mask_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSSSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vssseg<seg_nf><vlseg_nfop_attr>.v\t%2,%0,%1,%3.t");
  }
  [(set_attr "type" "vstore")]
)

;; Vector Indexed Segment Loads and Stores
;; =======================================

; vlxseg<nf>{b,h,w}.v vd, (rs1), vs2
; vlxseg<nf>e.v vd, (rs1), vs2
; vlxseg<nf>{b,h,w}u.v vd, (rs1), vs2

(define_expand "riscv_vlxseg<vlseg_nfop_attr>v_<mode>"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=&v")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "r")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[1] = gen_rtx_MEM (<MODE>mode, operands[1]);
  }
)

(define_insn_and_split "riscv_vlxseg<vlseg_nfop_attr>v_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=&v")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vlxseg<vlseg_nfop_attr>v_<mode>_internal (
		operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vload")]
)

(define_insn "riscv_vlxseg<vlseg_nfop_attr>v_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=&v")
	(unspec:VANYSEG128 [(match_operand:VANYSEG128 1 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 2 "register_operand" "v")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLXSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vlxseg<seg_nf><vlseg_nfop_attr>.v\t%0,%1,%2");
  }
  [(set_attr "type" "vload")]
)

; vlxseg<nf>{b,h,w}.v vd, (rs1), vs2, vm
; vlxseg<nf>e.v vd, (rs1), vs2, vm
; vlxseg<nf>{b,h,w}u.v vd, (rs1), vs2, vm

(define_expand "riscv_vlxseg<vlseg_nfop_attr>v_mask_<mode>"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=&u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand 2 "register_operand" "r")
			    (match_operand 3 "register_operand" "u")
			    (match_operand 4 "vmask_mode_register_operand" "w")
			    (match_operand 5 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[2] = gen_rtx_MEM (<MODE>mode, operands[2]);
  }
)

(define_insn_and_split "riscv_vlxseg<vlseg_nfop_attr>v_mask_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=&u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand:VANYSEG128 2 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 3 "register_operand" "u")
			    (match_operand 4 "vmask_mode_register_operand" "w")
			    (match_operand 5 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_vlxseg<vlseg_nfop_attr>v_mask_<mode>_internal (
      operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vload")]
)

(define_insn "riscv_vlxseg<vlseg_nfop_attr>v_mask_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "register_operand" "=&u")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "0")
			    (match_operand:VANYSEG128 2 "riscv_vector_mem_operand" "Qmv")
			    (match_operand 3 "register_operand" "u")
			    (match_operand 4 "vmask_mode_register_operand" "w")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VLXSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vlxseg<seg_nf><vlseg_nfop_attr>.v\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vload")]
)

; vsxseg<nf>{b,h,w,e}.v vs3, (rs1), vs2

(define_expand "riscv_vsxseg<vlseg_nfop_attr>v_<mode>"
  [(set (match_operand 0 "register_operand" "=r")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[0] = gen_rtx_MEM (<MODE>mode, operands[0]);
    emit_insn (gen_riscv_vsxseg<vlseg_nfop_attr>v_<mode>_split (
		operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
)

(define_insn_and_split "riscv_vsxseg<vlseg_nfop_attr>v_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vsxseg<vlseg_nfop_attr>v_<mode>_internal (
		operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vstore")]
)

(define_insn "riscv_vsxseg<vlseg_nfop_attr>v_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "register_operand" "v")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSXSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vsxseg<seg_nf><vlseg_nfop_attr>.v\t%2,%0,%1");
  }
  [(set_attr "type" "vstore")]
)

; vsxseg<nf>{b,h,w,e}.v vs3, (rs1), vs2, vm

(define_expand "riscv_vsxseg<vlseg_nfop_attr>v_mask_<mode>"
  [(set (match_operand 0 "register_operand" "=r")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (match_operand 4 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  {
    operands[0] = gen_rtx_MEM (<MODE>mode, operands[0]);
    emit_insn (gen_riscv_vsxseg<vlseg_nfop_attr>v_mask_<mode>_split (
      operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
)

(define_insn_and_split "riscv_vsxseg<vlseg_nfop_attr>v_mask_<mode>_split"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (match_operand 4 "register_operand" "r")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSXSEG_NFOP))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<SEG_BASE_MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vsxseg<vlseg_nfop_attr>v_mask_<mode>_internal (
		operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vstore")]
)

(define_insn "riscv_vsxseg<vlseg_nfop_attr>v_mask_<mode>_internal"
  [(set (match_operand:VANYSEG128 0 "riscv_vector_mem_operand" "=Qmv")
	(unspec:VANYSEG128 [(match_operand 1 "register_operand" "v")
			    (match_operand 2 "register_operand" "v")
			    (match_operand 3 "vmask_mode_register_operand" "w")
			    (reg:SI VTYPE_REGNUM)]
			   UNSPEC_VSXSEG_NFOP))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
      "vsxseg<seg_nf><vlseg_nfop_attr>.v\t%2,%0,%1,%3.t");
  }
  [(set_attr "type" "vstore")]
)
