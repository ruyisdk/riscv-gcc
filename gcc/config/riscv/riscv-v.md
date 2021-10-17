
(include "riscv-v-iterators.md")

;; vsetvli/vsetvl

(define_insn "riscv_vsetvli"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand    2 "const_us3_operand" "Y")
		    (match_operand    3 "const_us2_operand" "Z")]
		   UNSPEC_VSETVLI))
   (set (reg:SI VTYPE_REGNUM)
	(unspec:SI [(match_dup 1) (match_dup 2) (match_dup 3)]
		   UNSPEC_TYPE))]
  "TARGET_XTHEAD_VECTOR"
  {
    const char *pattern = "vsetvli\t%%0,%%1,%s,%s";
    static char buf[128] = {0};
    snprintf (buf, sizeof (buf), pattern,
	      riscv_output_vector_sew (INTVAL (operands[2])),
	      riscv_output_vector_lmul (INTVAL (operands[3])));
    return buf;
  }
  [(set_attr "type" "vset")]
)

(define_insn "riscv_vsetvli_max"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand 1 "const_us3_operand" "Y")
		    (match_operand 2 "const_us2_operand" "Z")]
		   UNSPEC_VSETVLI_MAX))
   (set (reg:SI VTYPE_REGNUM)
	(unspec:SI [(match_dup 1) (match_dup 2)]
		   UNSPEC_TYPE))]
  "TARGET_XTHEAD_VECTOR"
  {
    const char *pattern = "vsetvli\t%%0,x0,%s,%s";
    static char buf[128] = {0};
    snprintf (buf, sizeof (buf), pattern,
	      riscv_output_vector_sew (INTVAL (operands[1])),
	      riscv_output_vector_lmul (INTVAL (operands[2])));
    return buf;
  }
  [(set_attr "type" "vset")]
)

(define_insn "riscv_vsetvl"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		    (match_operand:SI 2 "register_operand" "r")]
		   UNSPEC_VSETVLR))
   (set (reg:SI VTYPE_REGNUM)
	(unspec:SI [(match_dup 1) (match_dup 2)]
		   UNSPEC_TYPE))]
  "TARGET_XTHEAD_VECTOR"
  "vsetvl\t%0,%1,%2"
  [(set_attr "type" "vset")]
)

(define_expand "mov<mode>"
  [(set (match_operand:VANY128 0 "nonimmediate_operand"  "")
	(match_operand:VANY128 1 "nonimmediate_or_0_operand"  ""))]
  "TARGET_XTHEAD_VECTOR"
  {
    if (can_create_pseudo_p ())
      {
	if (!REG_P (operands[0]))
	  operands[1] = force_reg (<MODE>mode, operands[1]);
      }
  }
)

(define_insn_and_split "riscv_mov_<mode>"
  [(set (match_operand:VANY128
	  0 "nonimmediate_operand"       "=v,   v, v, m")
	(match_operand:VANY128
	  1 "nonimmediate_or_0_operand"  " v, Qvz, m, v"))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    operands[2] = gen_rtx_REG (SImode, 0);
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);

    if (REG_P (operands[0]) && REG_P (operands[1]))
      emit_insn (gen_riscv_vmvvv_<mode>_internal (operands[0], operands[1],
						  operands[2]));
    else if (REG_P (operands[0]) && MEM_P (operands[1]))
      emit_insn (gen_riscv_vlev_<mode>_internal (operands[0], operands[1],
						 operands[2]));
    else if (REG_P (operands[1]) && MEM_P (operands[0]))
      emit_insn (gen_riscv_vsev_<mode>_internal (operands[0], operands[1],
						 operands[2]));
    else if (REG_P (operands[0]) && operands[1] == CONST0_RTX (<MODE>mode))
      emit_insn (gen_riscv_vmvvx_<mode>_internal (operands[0],
	gen_rtx_REG (<VANY128_attr>mode, GP_REG_FIRST), operands[2]));
    else
      gcc_unreachable ();

    DONE;
  }
  [(set_attr "type" "vmove,vmove,vload,vstore")]
)

(define_expand "mov<mode>"
  [(set (match_operand:VANYSEG128 0 "nonimmediate_operand"  "")
	(match_operand:VANYSEG128 1 "nonimmediate_or_0_operand"  ""))]
  "TARGET_XTHEAD_VECTOR"
  {
    if (can_create_pseudo_p ())
      {
	if (!REG_P (operands[0]))
	  operands[1] = force_reg (<MODE>mode, operands[1]);
      }

    emit_insn (gen_riscv_mov_<mode> (operands[0], operands[1]));

    DONE;
  }
)

(define_insn_and_split "riscv_mov_<mode>"
  [(set (match_operand:VANYSEG128
	  0 "nonimmediate_operand"      "=v,   v, v, m")
	(match_operand:VANYSEG128
	  1 "nonimmediate_or_0_operand" " v, Qvz, m, v"))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    int i;
    rtx zero = gen_rtx_REG (SImode, 0);
    if (REG_P (operands[0]) && REG_P (operands[1]))
      {
	for (i = 0; i < <seg_nf>; ++i)
	  {
	    rtx dst_subreg = gen_rtx_REG (<SEG_BASE_MODE>mode,
					  REGNO (operands[0]) + i);
	    rtx src_subreg = gen_rtx_REG (<SEG_BASE_MODE>mode,
					  REGNO (operands[1]) + i);
	    emit_move_insn (dst_subreg, src_subreg);
	  }
      }
    else if (REG_P (operands[0]) && MEM_P (operands[1]))
      {
	emit_insn (gen_riscv_vlsegev_<mode> (
		     operands[0], XEXP (operands[1], 0), zero));
      }
    else if (REG_P (operands[0]) && operands[1] == CONST0_RTX (<MODE>mode))
      {
	for (i = 0; i < <seg_nf>; ++i)
	  {
	    poly_int64 offset = i * GET_MODE_SIZE (<SEG_BASE_MODE>mode);
	    rtx dst_subreg = simplify_gen_subreg (<SEG_BASE_MODE>mode,
	      operands[0], <MODE>mode, offset);

	    emit_move_insn (dst_subreg, CONST0_RTX (<SEG_BASE_MODE>mode));
	  }
      }
    else if (MEM_P (operands[0]) && REG_P (operands[1]))
      {
	emit_insn (gen_riscv_vssegev_<mode> (
		     XEXP (operands[0], 0), operands[1], zero));
      }
    else
      gcc_unreachable ();
    DONE;
  }
  [(set_attr "type" "vmove,vload,vmove,vstore")]
)

(include "riscv-v-mem.md")

;; vmcmp instruction

(define_insn_and_split "riscv_<vop>vv_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK [(match_operand:VANY 1 "register_operand" "v")
		       (match_operand:VANY 2 "register_operand" "v")
		       (match_operand:SI   3 "register_operand" "r")
		       (reg:SI VTYPE_REGNUM)]
		      VECTOR_INT_CMP_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vcmp")]
)

(define_insn "riscv_<vop>vv_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK [(match_operand:VANY 1 "register_operand" "v")
		       (match_operand:VANY 2 "register_operand" "v")
		       (match_operand:SI   3 "register_operand" "r")
		       (reg:SI VTYPE_REGNUM)]
		      VECTOR_INT_CMP_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vcmp")]
)

(define_insn_and_split "riscv_<vop>vx_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK   0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<VANY:mode>_internal_<VMASK:mode> (
	operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vcmp")]
)

(define_insn "riscv_<vop>vx_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK   0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vcmp")]
)

(define_insn_and_split "riscv_<vop>vi_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK   0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "const_int_operand" "i")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vcmp")]
)

(define_insn "riscv_<vop>vi_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK   0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "const_int_operand" "i")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VI))
  (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "vcmp")]
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "0")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:VANY  3 "register_operand" "u")
	   (match_operand:VMASK 4 "vmask_mode_register_operand" "w")
	   (match_operand:SI    5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3], operands[4],
      operands[5]));
    DONE;
  }
  [(set_attr "type" "vcmp")]
)

(define_insn "riscv_<vop_mask>vv_mask_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "0")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:VANY  3 "register_operand" "u")
	   (match_operand:VMASK 4 "vmask_mode_register_operand" "w")
	   (match_operand:SI    5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode,
				     "<vop_mask>.vv\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vcmp")]
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "0")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand:VMASK 4 "vmask_mode_register_operand" "w")
	   (match_operand:SI    5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3], operands[4],
      operands[5]));
    DONE;
  }
  [(set_attr "type" "vcmp")]
)

(define_insn "riscv_<vop_mask>vx_mask_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "0")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand:VMASK 4 "vmask_mode_register_operand" "w")
	   (match_operand:SI    5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode,
				     "<vop_mask>.vx\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vcmp")]
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "0")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 3 "const_int_operand" "i")
	   (match_operand:VMASK 4 "vmask_mode_register_operand" "w")
	   (match_operand:SI    5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3], operands[4],
      operands[5]));
    DONE;
  }
  [(set_attr "type" "vcmp")]
)

(define_insn "riscv_<vop_mask>vi_mask_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "0")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 3 "const_int_operand" "i")
	   (match_operand:VMASK 4 "vmask_mode_register_operand" "w")
	   (match_operand:SI    5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_CMP_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode,
				     "<vop_mask>.vi\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vcmp")]
)

;; vmask instruction

(define_insn_and_split "riscv_<vop>mm_<VALL:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "v")
	   (match_operand:VMASK 2 "vmask_mode_register_operand" "v")
	   (match_operand:SI    3 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_LOGICAL))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VALL:MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>mm_<VALL:mode>_internal_<VMASK:mode> (operands[0],
      operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vlogical")]
)

(define_insn "riscv_<vop>mm_<VALL:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "v")
	   (match_operand:VMASK 2 "vmask_mode_register_operand" "v")
	   (match_operand:SI    3 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_LOGICAL))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VALL:MODE>mode, "<vop>.mm\t%0,%1,%2");
  }
  [(set_attr "type" "vlogical")]
)

(define_insn_and_split "riscv_<vop>m_<VALL:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "v")
	   (match_operand:SI    2 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_PSEUDO_CAST))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VALL:MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_<vop>m_<VALL:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>m_<VALL:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "v")
	   (match_operand:SI    2 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_PSEUDO_CAST))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VALL:MODE>mode, "<vop>.m\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>m_<VALL:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK             0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK [(match_operand:SI 1 "register_operand" "r")
		       (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
				    UNSPEC_TYPE)]
		      VECTOR_MASK_PSEUDO_SET))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VALL:MODE>mode, operands[1], operands[1]);
    emit_insn (gen_riscv_<vop>m_<VALL:mode>_internal_<VMASK:mode> (
      operands[0], operands[1]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>m_<VALL:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK             0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK [(match_operand:SI 1 "register_operand" "r")
		       (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
				    UNSPEC_TYPE)]
		      VECTOR_MASK_PSEUDO_SET))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VALL:MODE>mode, "<vop>.m\t%0");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>m_<mode>"
  [(set (match_operand:DI             0 "register_operand" "=r")
	(unspec:DI [(match_operand    1 "vmask_mode_register_operand" "v")
		    (match_operand:SI 2 "register_operand" "r")
		    (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
				 UNSPEC_TYPE)]
		   VECTOR_MASK_BIT))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_<vop>m_<mode>_internal (operands[0], operands[1],
      operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>m_<mode>_internal"
  [(set (match_operand:DI             0 "register_operand" "=r")
	(unspec:DI [(match_operand    1 "vmask_mode_register_operand" "v")
		    (match_operand:SI 2 "register_operand" "r")
		    (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
				 UNSPEC_TYPE)]
		   VECTOR_MASK_BIT))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.m\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop_mask>m_mask_<mode>"
  [(set (match_operand:DI              0 "register_operand" "=r")
	(unspec:DI [(match_operand     1 "vmask_mode_register_operand" "u")
		     (match_operand    2 "vmask_mode_register_operand" "w")
		     (match_operand:SI 3 "register_operand" "r")
		     (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
				  UNSPEC_TYPE)]
		    VECTOR_MASK_BIT_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop_mask>m_mask_<mode>_internal (
      operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>m_mask_<mode>_internal"
  [(set (match_operand:DI             0 "register_operand" "=r")
	(unspec:DI [(match_operand    1 "vmask_mode_register_operand" "u")
		    (match_operand    2 "vmask_mode_register_operand" "w")
		    (match_operand:SI 3 "register_operand" "r")
		    (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
				 UNSPEC_TYPE)]
		   VECTOR_MASK_BIT_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop_mask>.m\t%0,%1,%2.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>m_<VALL:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "v")
	   (match_operand:SI    2 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_SET_FIRST))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VALL:MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_<vop>m_<VALL:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>m_<VALL:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=v")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "v")
	   (match_operand:SI    2 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_SET_FIRST))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VALL:MODE>mode, "<vop>.m\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop_mask>m_mask_<VALL:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "u")
	   (match_operand:VMASK 2 "vmask_mode_register_operand" "w")
	   (match_operand:SI    3 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_SET_FIRST_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VALL:MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop_mask>m_mask_<VALL:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>m_mask_<VALL:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=u")
	(unspec:VMASK
	  [(match_operand:VMASK 1 "vmask_mode_register_operand" "u")
	   (match_operand:VMASK 2 "vmask_mode_register_operand" "w")
	   (match_operand:SI    3 "register_operand" "r")
	   (unspec:VALL [(const_int 0) (reg:SI VTYPE_REGNUM)]
			UNSPEC_TYPE)]
	  VECTOR_MASK_SET_FIRST_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VALL:MODE>mode,
				     "<vop_mask>.m\t%0,%1,%2.t");
  }
  [(set_attr "type" "vmove")]
)

;; vector bitwise instruction

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITWISE_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITWISE_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vnotv_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:SI   2 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VNOTV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vnotv_<mode>_internal (operands[0], operands[1],
						operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vnotv_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:SI   2 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VNOTV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vnot.v\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vnotv_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VNOTV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vnotv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vnotv_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VNOTV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vnot.v\t%0,%2,%3.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>vi_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_int_operand" "i")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vi_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_int_operand" "i")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITWISE_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITWISE_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "0")
	   (match_operand:VANY               2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "0")
	   (match_operand:VANY               2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<mode>"
  [(set (match_operand:VANY    0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "0")
	   (match_operand:VANY 2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "const_int_operand" "i")
	   (match_operand      4 "vmask_mode_register_operand" "w")
	   (match_operand:SI   5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vi_mask_<mode>_internal"
  [(set (match_operand:VANY    0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "0")
	   (match_operand:VANY 2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "const_int_operand" "i")
	   (match_operand      4 "vmask_mode_register_operand" "w")
	   (match_operand:SI   5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITWISE_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vi\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vmove")]
)

;;vector bit shift instruction

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITSHIFT_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITSHIFT_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:VANY    0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:VANY    0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop>vi_<mode>"
  [(set (match_operand:VANY    0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_K_operand" "K")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop>vi_<mode>_internal"
  [(set (match_operand:VANY    0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_K_operand" "K")
	   (match_operand:SI   3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITSHIFT_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_BITSHIFT_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:VANY    0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "0")
	   (match_operand:VANY 2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand      4 "vmask_mode_register_operand" "w")
	   (match_operand:SI   5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:VANY    0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "0")
	   (match_operand:VANY 2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand      4 "vmask_mode_register_operand" "w")
	   (match_operand:SI   5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<mode>"
  [(set (match_operand:VANY    0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "0")
	   (match_operand:VANY 2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "const_K_operand" "K")
	   (match_operand      4 "vmask_mode_register_operand" "w")
	   (match_operand:SI   5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop_mask>vi_mask_<mode>_internal"
  [(set (match_operand:VANY    0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY 1 "register_operand" "0")
	   (match_operand:VANY 2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "const_K_operand" "K")
	   (match_operand      4 "vmask_mode_register_operand" "w")
	   (match_operand:SI   5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_BITSHIFT_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vi\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vshift")]
)

;;vector narrow shift instruction

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "=&v")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW        1 "register_operand" "v")
	   (match_operand:<VNARROW_attr> 2 "register_operand" "v")
	   (match_operand:SI             3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VNARROW_attr>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "=&v")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW        1 "register_operand" "v")
	   (match_operand:<VNARROW_attr> 2 "register_operand" "v")
	   (match_operand:SI             3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:<VNARROW_attr>               0 "register_operand" "=&v")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW                   1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "register_operand" "r")
	   (match_operand:SI                        3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VNARROW_attr>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:<VNARROW_attr>               0 "register_operand" "=&v")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW                   1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "register_operand" "r")
	   (match_operand:SI                        3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vshift")]
)

(define_insn_and_split "riscv_<vop>vi_<mode>"
  [(set (match_operand:<VNARROW_attr>               0 "register_operand" "=&v")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW                   1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "const_K_operand"  "K")
	   (match_operand:SI                        3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VNARROW_attr>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop>vi_<mode>_internal"
  [(set (match_operand:<VNARROW_attr>               0 "register_operand" "=&v")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW                   1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "const_K_operand"  "K")
	   (match_operand:SI                        3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "vshift")]
)

(define_expand "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "")
	(unspec:<VNARROW_attr>
	  [(match_operand:<VNARROW_attr> 1 "register_operand" "")
	   (match_operand:VNARROW        2 "register_operand" "")
	   (match_operand:<VNARROW_attr> 3 "register_operand" "")
	   (match_operand                4 "vmask_mode_register_operand" "")
	   (match_operand:SI             5 "register_operand" "")]
	  VECTOR_INT_NARROWSHIFT_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>_i"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "+&u")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW        1 "register_operand" "u")
	   (match_operand:<VNARROW_attr> 2 "register_operand" "u")
	   (match_operand                3 "vmask_mode_register_operand" "w")
	   (match_operand:SI             4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VNARROW_attr>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "+&u")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW        1 "register_operand" "u")
	   (match_operand:<VNARROW_attr> 2 "register_operand" "u")
	   (match_operand                3 "vmask_mode_register_operand" "w")
	   (match_operand:SI             4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vshift")]
)

(define_expand "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "")
	(unspec:<VNARROW_attr>
	  [(match_operand:<VNARROW_attr> 1 "register_operand" "")
	   (match_operand:VNARROW        2 "register_operand" "")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 3 "register_operand" "")
	   (match_operand                4 "vmask_mode_register_operand" "")
	   (match_operand:SI             5 "register_operand" "")]
	  VECTOR_INT_NARROWSHIFT_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>_i"
  [(set (match_operand:<VNARROW_attr> 0 "register_operand" "+&u")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW     1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "register_operand" "r")
	   (match_operand             3 "vmask_mode_register_operand" "w")
	   (match_operand:SI          4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VNARROW_attr>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:<VNARROW_attr> 0 "register_operand" "+&u")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW     1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "register_operand" "r")
	   (match_operand             3 "vmask_mode_register_operand" "w")
	   (match_operand:SI          4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vshift")]
)

(define_expand "riscv_<vop_mask>vi_mask_<mode>"
  [(set (match_operand:<VNARROW_attr>    0 "register_operand" "")
	(unspec:<VNARROW_attr>
	  [(match_operand:<VNARROW_attr> 1 "register_operand" "")
	   (match_operand:VNARROW        2 "register_operand" "")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 3 "const_K_operand" "")
	   (match_operand                4 "vmask_mode_register_operand" "")
	   (match_operand:SI             5 "register_operand" "")]
	  VECTOR_INT_NARROWSHIFT_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_i (operands[0],
      operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<mode>_i"
  [(set (match_operand:<VNARROW_attr> 0 "register_operand" "+&u")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW     1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "const_K_operand" "K")
	   (match_operand             3 "vmask_mode_register_operand" "w")
	   (match_operand:SI          4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VNARROW_attr>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vshift")]
)

(define_insn "riscv_<vop_mask>vi_mask_<mode>_internal"
  [(set (match_operand:<VNARROW_attr> 0 "register_operand" "+&u")
	(unspec:<VNARROW_attr>
	  [(match_operand:VNARROW     1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_NARROW_attr> 2 "const_K_operand" "K")
	   (match_operand             3 "vmask_mode_register_operand" "w")
	   (match_operand:SI          4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_NARROWSHIFT_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vi\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vshift")]
)

;; vector arithmetic instruction

; Binary operation

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn_and_split "riscv_<vop>vi_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_M_operand" "i")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop>vi_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_M_operand" "i")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:VANY                0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY  1 "register_operand" "0")
		       (match_operand:VANY 2 "register_operand" "u")
		       (match_operand:VANY 3 "register_operand" "u")
		       (match_operand      4 "vmask_mode_register_operand" "w")
		       (match_operand:SI   5 "register_operand" "r")
		       (reg:SI VTYPE_REGNUM)]
		      VECTOR_INT_ARITH_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "0")
	   (match_operand:VANY               2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "0")
	   (match_operand:VANY               2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "r")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "0")
	   (match_operand:VANY               2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "const_M_operand"  "i")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop_mask>vi_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "0")
	   (match_operand:VANY               2 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 3 "const_M_operand"  "i")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vi\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "<vector_type>")]
)

; Ternary accumulation operation

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:VANY 3 "register_operand" "0")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_ACCUM_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
      operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:VANY 3 "register_operand" "0")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_ACCUM_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vmadd")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:VANY               2 "register_operand" "v")
	   (match_operand:VANY               3 "register_operand" "0")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_ACCUM_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
      operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:VANY               2 "register_operand" "v")
	   (match_operand:VANY               3 "register_operand" "0")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_ACCUM_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vmadd")]
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "u")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand:VANY 4 "register_operand" "0")
		      (match_operand      5 "vmask_mode_register_operand" "w")
		      (match_operand:SI   6 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_ACCUM_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[6], operands[6]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5],
      operands[6]));
    if (REGNO (operands[0]) != REGNO (operands[1]))
      emit_insn (gen_riscv_vmergevvm_mask_<mode> (operands[0], operands[1],
	operands[0], operands[5], operands[6]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "u")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand:VANY 4 "register_operand" "0")
		      (match_operand      5 "vmask_mode_register_operand" "w")
		      (match_operand:SI   6 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_ARITH_ACCUM_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%2,%3,%5.t");
  }
  [(set_attr "type" "vmadd")]
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:VANY               3 "register_operand" "u")
	   (match_operand:VANY               4 "register_operand" "0")
	   (match_operand         5 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 6 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_ACCUM_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[6], operands[6]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5],
      operands[6]));
    if (REGNO (operands[0]) != REGNO (operands[1]))
      emit_insn (gen_riscv_vmergevvm_mask_<mode> (operands[0], operands[1],
	operands[0], operands[5], operands[6]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:VANY               3 "register_operand" "u")
	   (match_operand:VANY               4 "register_operand" "0")
	   (match_operand         5 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 6 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_ARITH_ACCUM_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%2,%3,%5.t");
  }
  [(set_attr "type" "vmadd")]
)

;;vector widen arithmetic instruction

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:<VWIDEN_attr>  0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ 1 "register_operand" "v")
	   (match_operand:VWIDEN_DSHQ 2 "register_operand" "v")
	   (match_operand:SI          3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>  0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ 1 "register_operand" "v")
	   (match_operand:VWIDEN_DSHQ 2 "register_operand" "v")
	   (match_operand:SI          3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ        1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ        1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_expand "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   3 "register_operand" "")
	   (match_operand               4 "vmask_mode_register_operand" "")
	   (match_operand:SI            5 "register_operand" "")]
	  VECTOR_INT_WIDENARITH_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>  0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ 1 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ 2 "register_operand" "u")
	   (match_operand             3 "vmask_mode_register_operand" "w")
	   (match_operand:SI          4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>  0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ 1 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ 2 "register_operand" "u")
	   (match_operand             3 "vmask_mode_register_operand" "w")
	   (match_operand:SI          4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_expand "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ        2 "register_operand" "")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "")
	   (match_operand         4 "vmask_mode_register_operand" "")
	   (match_operand:SI                 5 "register_operand" "")]
	  VECTOR_INT_WIDENARITH_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ        1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ        1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "<vector_type>")
   (set_attr "emode" "<VANY_SCALAR_attr>")]
)

(define_insn_and_split "riscv_<vop>wv_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "v")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "v")
	   (match_operand:SI            3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENARITH_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>wv_<mode>_internal (operands[0], operands[1],
      operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop>wv_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "v")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "v")
	   (match_operand:SI            3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENARITH_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.wv\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn_and_split "riscv_<vop>wx_<mode>"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (unspec:VWIDEN_DSHQ [(const_int 0) (reg:SI VTYPE_REGNUM)]
			       UNSPEC_TYPE)]
	  VECTOR_INT_WIDENWIDENARITH_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>wx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop>wx_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "v")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:SI                 3 "register_operand" "r")
	   (unspec:VWIDEN_DSHQ [(const_int 0) (reg:SI VTYPE_REGNUM)]
			       UNSPEC_TYPE)]
	  VECTOR_INT_WIDENWIDENARITH_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.wx\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")]
)

(define_expand "riscv_<vop_mask>wv_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "")
	   (match_operand:<VWIDEN_attr> 2 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   3 "register_operand" "")
	   (match_operand               4 "vmask_mode_register_operand" "")
	   (match_operand:SI            5 "register_operand" "")]
	  VECTOR_INT_WIDENWIDENARITH_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>wv_mask_<mode>_i (operands[0],
      operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>wv_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "u")
	   (match_operand               3 "vmask_mode_register_operand" "w")
	   (match_operand:SI            4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENARITH_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>wv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop_mask>wv_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "u")
	   (match_operand               3 "vmask_mode_register_operand" "w")
	   (match_operand:SI            4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENARITH_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.wv\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "<vector_type>")]
)

(define_expand "riscv_<vop_mask>wx_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "")
	   (match_operand:<VWIDEN_attr>      2 "register_operand" "")
	   (match_operand:<VANY_SCALAR_attr> 3 "register_operand" "")
	   (unspec:VWIDEN_DSHQ [(const_int 0)] UNSPEC_TYPE)
	   (match_operand         4 "vmask_mode_register_operand" "")
	   (match_operand:SI                 5 "register_operand" "")]
	  VECTOR_INT_WIDENWIDENARITH_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>wx_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>wx_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (unspec:VWIDEN_DSHQ [(const_int 0) (reg:SI VTYPE_REGNUM)]
			       UNSPEC_TYPE)
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (match_dup 0)]
	  VECTOR_INT_WIDENWIDENARITH_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>wx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop_mask>wx_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (unspec:VWIDEN_DSHQ [(const_int 0) (reg:SI VTYPE_REGNUM)]
			       UNSPEC_TYPE)
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (match_dup 0)]
	  VECTOR_INT_WIDENWIDENARITH_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.wx\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "<vector_type>")]
)

;;vector widen arithmetic accumulation instruction

(define_expand "riscv_<vop>vv_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ   1 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "")
	   (match_operand:<VWIDEN_attr> 3 "register_operand" "")
	   (match_operand:SI            4 "register_operand" "")]
	  VECTOR_INT_WIDENARITH_ACCUM_VV))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_i (operands[0], operands[1],
					   operands[2], operands[4]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop>vv_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>  0 "register_operand" "+&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ 1 "register_operand" "v")
	   (match_operand:VWIDEN_DSHQ 2 "register_operand" "v")
	   (match_operand:SI          3 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>  0 "register_operand" "+&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ 1 "register_operand" "v")
	   (match_operand:VWIDEN_DSHQ 2 "register_operand" "v")
	   (match_operand:SI          3 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vmadd")]
)

(define_expand "riscv_<vop>vx_<mode>"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ        2 "register_operand" "")
	   (match_operand:<VWIDEN_attr>      3 "register_operand" "")
	   (match_operand:SI                 4 "register_operand" "")]
	  VECTOR_INT_WIDENARITH_ACCUM_VX))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_i (operands[0], operands[1],
					   operands[2], operands[4]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop>vx_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:VWIDEN_DSHQ        2 "register_operand" "v")
	   (match_operand:SI                 3 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:VWIDEN_DSHQ        2 "register_operand" "v")
	   (match_operand:SI                 3 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vmadd")]
)

(define_expand "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   3 "register_operand" "")
	   (match_operand:<VWIDEN_attr> 4 "register_operand" "")
	   (match_operand               5 "vmask_mode_register_operand" "")
	   (match_operand:SI            6 "register_operand" "")]
	  VECTOR_INT_WIDENARITH_ACCUM_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_i (operands[0], operands[1],
      operands[2], operands[3], operands[5], operands[6]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ   3 "register_operand" "u")
	   (match_operand               4 "vmask_mode_register_operand" "w")
	   (match_operand:SI            5 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    if (REGNO (operands[0]) != REGNO (operands[1]))
      emit_insn (gen_riscv_vmergevvm_mask_<vwiden_attr> (operands[0],
	operands[1], operands[0], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "u")
	   (match_operand:VWIDEN_DSHQ   3 "register_operand" "u")
	   (match_operand               4 "vmask_mode_register_operand" "w")
	   (match_operand:SI            5 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vmadd")]
)

(define_expand "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ        3 "register_operand" "")
	   (match_operand:<VWIDEN_attr>      4 "register_operand" "")
	   (match_operand         5 "vmask_mode_register_operand" "")
	   (match_operand:SI                 6 "register_operand" "")]
	  VECTOR_INT_WIDENARITH_ACCUM_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_i (operands[0], operands[1],
      operands[2], operands[3], operands[5], operands[6]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:VWIDEN_DSHQ        3 "register_operand" "u")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    if (REGNO (operands[0]) != REGNO (operands[1]))
      emit_insn (gen_riscv_vmergevvm_mask_<vwiden_attr> (operands[0],
	operands[1], operands[0], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "vmadd")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>         0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr>      1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:VWIDEN_DSHQ        3 "register_operand" "u")
	   (match_operand         4 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 5 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENARITH_ACCUM_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "vmadd")]
)

;; vector reduction instruction

;; Binary operation

(define_insn_and_split "riscv_<vop>vs_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_RED_VS))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vs_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop>vs_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand:VANY 2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_RED_VS))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vs\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn_and_split "riscv_<vop_mask>vs_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_RED_VS_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[5], operands[5]);
    emit_insn (gen_riscv_<vop_mask>vs_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop_mask>vs_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand:VANY 3 "register_operand" "u")
		      (match_operand      4 "vmask_mode_register_operand" "w")
		      (match_operand:SI   5 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_RED_VS_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vs\t%0,%2,%3,%4.t");
  }
  [(set_attr "type" "<vector_type>")]
)

; vector widen reduction instruction

(define_insn_and_split "riscv_<vop>vs_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ   1 "register_operand" "v")
	   (match_operand:<VWIDEN_attr> 2 "register_operand" "v")
	   (match_operand:SI            3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENRED_VS))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vs_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop>vs_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "=&v")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ   1 "register_operand" "v")
	   (match_operand:<VWIDEN_attr> 2 "register_operand" "v")
	   (match_operand:SI            3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENRED_VS))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vs\t%0,%1,%2");
  }
  [(set_attr "type" "<vector_type>")]
)

(define_expand "riscv_<vop_mask>vs_mask_<mode>"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "")
	(unspec:<VWIDEN_attr>
	  [(match_operand:<VWIDEN_attr> 1 "register_operand" "")
	   (match_operand:VWIDEN_DSHQ   2 "register_operand" "")
	   (match_operand:<VWIDEN_attr> 3 "register_operand" "")
	   (match_operand               4 "vmask_mode_register_operand" "")
	   (match_operand:SI            5 "register_operand" "")]
	  VECTOR_INT_WIDENWIDENRED_VS_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vs_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vs_mask_<mode>_i"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ   1 "register_operand" "u")
	   (match_operand:<VWIDEN_attr> 2 "register_operand" "u")
	   (match_operand               3 "vmask_mode_register_operand" "w")
	   (match_operand:SI            4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENRED_VS_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vs_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "<vector_type>")]
)

(define_insn "riscv_<vop_mask>vs_mask_<mode>_internal"
  [(set (match_operand:<VWIDEN_attr>    0 "register_operand" "+&u")
	(unspec:<VWIDEN_attr>
	  [(match_operand:VWIDEN_DSHQ   1 "register_operand" "u")
	   (match_operand:<VWIDEN_attr> 2 "register_operand" "u")
	   (match_operand               3 "vmask_mode_register_operand" "w")
	   (match_operand:SI            4 "register_operand" "r")
	   (match_dup 0)
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_INT_WIDENWIDENRED_VS_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vs\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "<vector_type>")]
)

;; vector slide instruction and gather instruction

(define_insn_and_split "riscv_<vop>vv_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vv_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vv_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vv\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_expand "riscv_<vop_mask>vv_mask_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "")
		      (match_operand:VALL 2 "register_operand" "")
		      (match_operand      3 "register_operand" "")
		      (match_operand      4 "vmask_mode_register_operand" "")
		      (match_operand:SI   5 "register_operand" "")]
		     VECTOR_INT_GATHER_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vv_mask_<mode>_i"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VV_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vv_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vv_mask_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VV_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vv\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>vx_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "register_operand" "r")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDEGATHER_VX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vx_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vx_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "register_operand" "r")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDEGATHER_VX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vx\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_expand "riscv_<vop_mask>vx_mask_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "")
		      (match_operand:VALL 2 "register_operand" "")
		      (match_operand      3 "register_operand" "")
		      (match_operand      4 "vmask_mode_register_operand" "")
		      (match_operand:SI   5 "register_operand" "")]
		     VECTOR_INT_SLIDEGATHER_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vx_mask_<mode>_i"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "register_operand" "r")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDEGATHER_VX_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vx_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vx_mask_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "register_operand" "r")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDEGATHER_VX_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vx\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>vi_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "const_K_operand" "K")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDE_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vi_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		       (match_operand     2 "const_K_operand" "K")
		       (match_operand:SI  3 "register_operand" "r")
		       (reg:SI VTYPE_REGNUM)]
		      VECTOR_INT_SLIDE_VI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_expand "riscv_<vop_mask>vi_mask_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "")
		      (match_operand:VALL 2 "register_operand" "")
		      (match_operand      3 "const_K_operand" "")
		      (match_operand      4 "vmask_mode_register_operand" "")
		      (match_operand:SI   5 "register_operand" "")]
		     VECTOR_INT_SLIDE_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_i (operands[0], operands[2],
      operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<mode>_i"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "const_K_operand" "K")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDE_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vi_mask_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "const_K_operand" "K")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_SLIDE_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vi\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_<vop>vi_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "const_K_operand" "i")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_<vop>vi_<mode>_internal (operands[0], operands[1],
						  operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop>vi_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "=&v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand      2 "const_K_operand" "i")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "<vop>.vi\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_expand "riscv_<vop_mask>vi_mask_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "")
		      (match_operand:VALL 2 "register_operand" "")
		      (match_operand      3 "const_K_operand" "")
		      (match_operand      4 "vmask_mode_register_operand" "")
		      (match_operand:SI   5 "register_operand" "")]
		     VECTOR_INT_GATHER_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_i (operands[0],
      operands[2], operands[3], operands[4], operands[5]));
    DONE;
  }
)

(define_insn_and_split "riscv_<vop_mask>vi_mask_<mode>_i"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "const_K_operand" "i")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VI_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vi_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_<vop_mask>vi_mask_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "+&u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand      2 "const_K_operand" "i")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_INT_GATHER_VI_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vi\t%0,%1,%2,%3.t");
  }
  [(set_attr "type" "vmove")]
)

;; vector compress instruction

(define_insn_and_split "riscv_vcompressvm_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=&v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand      2 "vmask_mode_register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VCOMPRESS))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vcompressvm_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vcompressvm_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=&v")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "v")
		      (match_operand      2 "vmask_mode_register_operand" "v")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VCOMPRESS))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vcompress.vm\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

;; vector iota and id instruction

(define_insn_and_split "riscv_viotam_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=&v")
	  (unspec:VANY [(match_operand    1 "vmask_mode_register_operand" "v")
			(match_operand:SI 2 "register_operand" "r")
			(reg:SI VTYPE_REGNUM)]
		       UNSPEC_VIOTA))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_viotam_<mode>_internal (operands[0], operands[1],
						 operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_viotam_<mode>_internal"
  [(set (match_operand:VANY             0 "register_operand" "=&v")
	(unspec:VANY [(match_operand    1 "vmask_mode_register_operand" "v")
		      (match_operand:SI 2 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VIOTA))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "viota.m\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_expand "riscv_viotam_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "")
		      (match_operand      2 "vmask_mode_register_operand" "")
		      (match_operand      3 "vmask_mode_register_operand" "")
		      (match_operand:SI   4 "register_operand" "")]
		     UNSPEC_VIOTA_MASK))]
  "TARGET_XTHEAD_VECTOR"
  {
    emit_move_insn (operands[0], operands[1]);
    emit_insn (gen_riscv_viotam_mask_<mode>_i (operands[0], operands[2],
					       operands[3], operands[4]));
    DONE;
  }
)

(define_insn_and_split "riscv_viotam_mask_<mode>_i"
  [(set (match_operand:VANY             0 "register_operand" "+&u")
	(unspec:VANY [(match_operand    1 "vmask_mode_register_operand" "u")
		      (match_operand    2 "vmask_mode_register_operand" "w")
		      (match_operand:SI 3 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VIOTA_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_viotam_mask_<mode>_internal (operands[0],
     operands[1], operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_viotam_mask_<mode>_internal"
  [(set (match_operand:VANY             0 "register_operand" "+&u")
	(unspec:VANY [(match_operand    1 "vmask_mode_register_operand" "u")
		      (match_operand    2 "vmask_mode_register_operand" "w")
		      (match_operand:SI 3 "register_operand" "r")
		      (match_dup 0)
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VIOTA_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "viota.m\t%0,%1,%2.t");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vidv_<mode>"
  [(set (match_operand:VANY             0 "register_operand" "=v")
	(unspec:VANY [(match_operand:SI 1 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VID))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[1], operands[1]);
    emit_insn (gen_riscv_vidv_<mode>_internal (operands[0], operands[1]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vidv_<mode>_internal"
  [(set (match_operand:VANY             0 "register_operand" "=v")
	(unspec:VANY [(match_operand:SI 1 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VID))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vid.v\t%0");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vidv_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand      2 "vmask_mode_register_operand" "w")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VID_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vidv_mask_<mode>_internal (operands[0], operands[1],
						    operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vidv_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "0")
		      (match_operand      2 "vmask_mode_register_operand" "w")
		      (match_operand:SI   3 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VID_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vid.v\t%0,%2.t");
  }
  [(set_attr "type" "vmove")]
)

;; vector vmerge(vmv) instruction

(define_insn_and_split "riscv_vmvvv_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "=v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand:SI   2 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VMVVV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vmvvv_<mode>_internal (operands[0], operands[1],
						operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmvvv_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "=v")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "v")
		      (match_operand:SI   2 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VMVVV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmv.v.v\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmergevvm_mask_<mode>"
  [(set (match_operand:VALL               0 "register_operand" "=u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand:VALL 2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VMERGEVVM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vmergevvm_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmergevvm_mask_<mode>_internal"
  [(set (match_operand:VALL               0 "register_operand" "=u")
	(unspec:VALL [(match_operand:VALL 1 "register_operand" "u")
		      (match_operand:VALL 2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     UNSPEC_VMERGEVVM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmerge.vvm\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmvvx_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:SI                 2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVVX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vmvvx_<mode>_internal (operands[0], operands[1],
						operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmvvx_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:SI                 2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVVX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmv.v.x\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmvvx_<mode>_internal"
  [(set (match_operand:VFANY            0 "register_operand" "=v")
	(unspec:VFANY
	  [(match_operand:<VF_SEM_ATTR> 1 "register_operand" "r")
	   (match_operand:SI            2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVVX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && (REGNO (operands[1]) == 0)"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmv.v.x\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmergevxm_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMERGEVXM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vmergevxm_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmergevxm_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMERGEVXM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmerge.vxm\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmvvi_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "const_M_operand"  "i")
	   (match_operand:SI                 2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVVI))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vmvvi_<mode>_internal (operands[0], operands[1],
						operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmvvi_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "const_M_operand"  "i")
	   (match_operand:SI                 2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVVI))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmv.v.i\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmergevim_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_M_operand"  "i")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMERGEVIM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vmergevim_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmergevim_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_M_operand"  "i")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMERGEVIM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmerge.vim\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vmove")]
)

;; vector permutation instruction

(define_insn_and_split "riscv_vextxv_<mode>"
  [(set (match_operand:<VANY_SCALAR_attr> 0 "register_operand" "=r")
	(unspec:<VANY_SCALAR_attr>
	  [(match_operand:VANY            1 "register_operand" "v")
	   (match_operand:SI              2 "register_operand" "r")
	   (match_operand:SI              3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VEXTXV))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[3], operands[3]);
    emit_insn (gen_riscv_vextxv_<mode>_internal (operands[0], operands[1],
						 operands[2], operands[3]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vextxv_<mode>_internal"
  [(set (match_operand:<VANY_SCALAR_attr> 0 "register_operand" "=r")
	(unspec:<VANY_SCALAR_attr>
	  [(match_operand:VANY            1 "register_operand" "v")
	   (match_operand:SI              2 "register_operand" "r")
	   (match_operand:SI              3 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VEXTXV))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vext.x.v\t%0,%1,%2");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmvsx_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:SI                 2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVSX))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vmvsx_<mode>_internal (operands[0], operands[1],
						operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmvsx_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=v")
	(unspec:VANY
	  [(match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")
	   (match_operand:SI                 2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVSX))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmv.s.x\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

(define_insn_and_split "riscv_vmvxs_<mode>"
  [(set (match_operand:<VANY_SCALAR_attr> 0 "register_operand" "=r")
	(unspec:<VANY_SCALAR_attr>
	  [(match_operand:VANY            1 "register_operand" "v")
	   (match_operand:SI              2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVXS))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[2], operands[2]);
    emit_insn (gen_riscv_vmvxs_<mode>_internal (operands[0], operands[1],
						operands[2]));
    DONE;
  }
  [(set_attr "type" "vmove")]
)

(define_insn "riscv_vmvxs_<mode>_internal"
  [(set (match_operand:<VANY_SCALAR_attr> 0 "register_operand" "=r")
	(unspec:<VANY_SCALAR_attr>
	  [(match_operand:VANY            1 "register_operand" "v")
	   (match_operand:SI              2 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMVXS))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vmv.x.s\t%0,%1");
  }
  [(set_attr "type" "vmove")]
)

;; carry and borrow

(define_insn_and_split "riscv_<vop_mask>vvm_mask_<mode>"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "u")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_CARRYUSE_VVM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vvm_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vadd")]
)

(define_insn "riscv_<vop_mask>vvm_mask_<mode>_internal"
  [(set (match_operand:VANY               0 "register_operand" "=u")
	(unspec:VANY [(match_operand:VANY 1 "register_operand" "u")
		      (match_operand:VANY 2 "register_operand" "u")
		      (match_operand      3 "vmask_mode_register_operand" "w")
		      (match_operand:SI   4 "register_operand" "r")
		      (reg:SI VTYPE_REGNUM)]
		     VECTOR_CARRYUSE_VVM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vvm\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vadd")]
)

(define_insn_and_split "riscv_<vop_mask>vxm_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_CARRYUSE_VXM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vxm_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vadd")]
)

(define_insn "riscv_<vop_mask>vxm_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_CARRYUSE_VXM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode,
				     "<vop_mask>.vxm\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vadd")]
)

(define_insn_and_split "riscv_vadcvim_mask_<mode>"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_M_operand"  "i")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VADCVIM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vadcvim_mask_<mode>_internal (operands[0],
      operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vadd")]
)

(define_insn "riscv_vadcvim_mask_<mode>_internal"
  [(set (match_operand:VANY                  0 "register_operand" "=u")
	(unspec:VANY
	  [(match_operand:VANY               1 "register_operand" "u")
	   (match_operand:<VANY_SCALAR_attr> 2 "const_M_operand"  "i")
	   (match_operand         3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                 4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VADCVIM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<MODE>mode, "vadc.vim\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vadd")]
)

(define_insn_and_split "riscv_<vop_mask>vvm_mask_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY  1 "register_operand" "u")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:VMASK 3 "vmask_mode_register_operand" "w")
	   (match_operand:SI    4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_CARRYOUT_VVM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vvm_mask_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vadd")]
)

(define_insn "riscv_<vop_mask>vvm_mask_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK    0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY  1 "register_operand" "u")
	   (match_operand:VANY  2 "register_operand" "u")
	   (match_operand:VMASK 3 "vmask_mode_register_operand" "w")
	   (match_operand:SI    4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_CARRYOUT_VVM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode,
				     "<vop_mask>.vvm\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vadd")]
)

(define_insn_and_split "riscv_<vop_mask>vxm_mask_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK           0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY                    1 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:VMASK        3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                      4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_CARRYOUT_VXM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_<vop_mask>vxm_mask_<VANY:mode>_internal_<VMASK:mode> ( 
      operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vadd")]
)

(define_insn "riscv_<vop_mask>vxm_mask_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK           0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY                    1 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "register_operand" "r")
	   (match_operand:VMASK        3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                      4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  VECTOR_CARRYOUT_VXM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode,
				     "<vop_mask>.vxm\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vadd")]
)

(define_insn_and_split "riscv_vmadcvim_mask_<VANY:mode>_<VMASK:mode>"
  [(set (match_operand:VMASK           0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY                    1 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "const_M_operand"  "i")
	   (match_operand:VMASK        3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                      4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMADCVIM_MASK))]
  "TARGET_XTHEAD_VECTOR"
  "#"
  "&& TARGET_XTHEAD_VSPLIT"
  [(clobber (const_int 0))]
  {
    riscv_emit_vsetvli (<VANY:MODE>mode, operands[4], operands[4]);
    emit_insn (gen_riscv_vmadcvim_mask_<VANY:mode>_internal_<VMASK:mode> (
      operands[0], operands[1], operands[2], operands[3], operands[4]));
    DONE;
  }
  [(set_attr "type" "vadd")]
)

(define_insn "riscv_vmadcvim_mask_<VANY:mode>_internal_<VMASK:mode>"
  [(set (match_operand:VMASK          0 "vmask_mode_register_operand" "=&v")
	(unspec:VMASK
	  [(match_operand:VANY                    1 "register_operand" "u")
	   (match_operand:<VANY:VANY_SCALAR_attr> 2 "const_M_operand"  "i")
	   (match_operand:VMASK        3 "vmask_mode_register_operand" "w")
	   (match_operand:SI                      4 "register_operand" "r")
	   (reg:SI VTYPE_REGNUM)]
	  UNSPEC_VMADCVIM_MASK))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR"
  {
    return riscv_output_vector_insn (<VANY:MODE>mode,
				     "vmadc.vim\t%0,%1,%2,%3");
  }
  [(set_attr "type" "vadd")]
)

(define_expand "riscv_velement_set_<mode>"
  [(match_operand:VALL 0 "register_operand")
   (match_operand:VALL 1 "register_operand")
   (match_operand:SI 2 "const_int_operand" "")
   (match_operand 3 "register_operand")]
  "TARGET_XTHEAD_VECTOR"
{
  machine_mode sub_mode = riscv_vector_register_mode (<MODE>mode);

  if (INTVAL (operands[2]) < 0
      || (INTVAL (operands[2])
	  > (GET_MODE_SIZE (<MODE>mode) / GET_MODE_SIZE (sub_mode))))
    {
      gcc_unreachable ();
      FAIL;
    }
  poly_int64 offset = INTVAL (operands[2]) * GET_MODE_SIZE (sub_mode);
  emit_move_insn (operands[0], operands[1]);
  rtx subreg = simplify_gen_subreg (sub_mode, operands[0],
				    <MODE>mode, offset);
  emit_move_insn (subreg, operands[3]);
  DONE;
})

(define_expand "riscv_velement_get_<mode>"
  [(match_operand 0 "register_operand")
   (match_operand:VALL 1 "register_operand")
   (match_operand:SI 2 "const_int_operand")]
  "TARGET_XTHEAD_VECTOR"
{
  machine_mode sub_mode = riscv_vector_register_mode (<MODE>mode);

  if (INTVAL (operands[2]) < 0
      || (INTVAL (operands[2])
	  > (GET_MODE_SIZE (<MODE>mode) / GET_MODE_SIZE (sub_mode))))
    {
      gcc_unreachable ();
      FAIL;
    }
  poly_int64 offset = INTVAL (operands[2]) * GET_MODE_SIZE (sub_mode);
  rtx subreg = simplify_gen_subreg (sub_mode, operands[1],
				    <MODE>mode, offset);
  emit_move_insn (operands[0], subreg);
  DONE;
})
