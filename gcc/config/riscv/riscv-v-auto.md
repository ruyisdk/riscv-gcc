
;; Vector
(define_expand "vec_duplicate<mode>"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(vec_duplicate:VANY
	  (match_operand:<VANY_SCALAR_attr> 1 "register_operand" "r")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vmvvx_<mode> (operands[0], operands[1],
				       gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "add<mode>3"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")
   (match_operand:VANY_RVV 2 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vaddvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "sub<mode>3"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")
   (match_operand:VANY_RVV 2 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vsubvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "mul<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(mult:VANY (match_operand:VANY 1 "register_operand" "v")
		   (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vmulvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "div<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(div:VANY (match_operand:VANY 1 "register_operand" "v")
		  (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vdivvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

;;(define_expand "ssadd<mode>3"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(ss_plus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		      (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vsaddvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "usadd<mode>3"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_plus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		      (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vsadduvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "sssub<mode>3"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(ss_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vssubvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "ussub<mode>3"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vssubuvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)

(define_expand "udiv<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(udiv:VANY (match_operand:VANY 1 "register_operand" "v")
		   (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vdivuvv_<mode> (operands[0], operands[1], operands[2],
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "mod<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(mod:VANY (match_operand:VANY 1 "register_operand" "v")
		  (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vremvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "umod<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(umod:VANY (match_operand:VANY 1 "register_operand" "v")
		   (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vremuvv_<mode> (operands[0], operands[1], operands[2],
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "smax<mode>3"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")
   (match_operand:VANY_RVV 2 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vmaxvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "smin<mode>3"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")
   (match_operand:VANY_RVV 2 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vminvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "umax<mode>3"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")
   (match_operand:VANY_RVV 2 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vmaxuvv_<mode> (operands[0], operands[1], operands[2],
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "umin<mode>3"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")
   (match_operand:VANY_RVV 2 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vminuvv_<mode> (operands[0], operands[1], operands[2],
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "and<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(and:VANY (match_operand:VANY 1 "register_operand" "v")
		  (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vandvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "ior<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(ior:VANY (match_operand:VANY 1 "register_operand" "v")
		  (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vorvv_<mode> (operands[0], operands[1], operands[2],
				       gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "xor<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(xor:VANY (match_operand:VANY 1 "register_operand" "v")
		  (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vxorvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "widen_ssum<mode>3"
  [(set (match_operand:<VWIDEN_attr> 0 "register_operand" "=v")
	(plus:<VWIDEN_attr>
	  (sign_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 1 "register_operand" "v"))
	  (sign_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 2 "register_operand" "v"))))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vwaddvv_<mode> (operands[0], operands[1], operands[2],
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "widen_usum<mode>3"
  [(set (match_operand:<VWIDEN_attr> 0 "register_operand" "=v")
	(plus:<VWIDEN_attr>
	  (zero_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 1 "register_operand" "v"))
	  (zero_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 2 "register_operand" "v"))))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vwadduvv_<mode> (operands[0], operands[1],
      operands[2], gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

;;(define_expand "reduc_smax_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredmaxvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_smin_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredminvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_umax_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredmaxuvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_umin_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredminuvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_plus_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredsumvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_and_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredandvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_ior_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredoruvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)
;;
;;(define_expand "reduc_xor_scal_<mode>"
;;  [(set (match_operand:VANY 0 "register_operand" "=v")
;;	(us_minus:VANY (match_operand:VANY 1 "register_operand" "v")
;;		       (match_operand:VANY 2 "register_operand" "v")))]
;;  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
;;  {
;;    emit_insn (gen_riscv_vredxorvv_<mode> (operands[0], operands[1], operands[2], gen_rtx_REG (SImode, 0)));
;;    DONE;
;;  }
;;)

(define_expand "smul<mode>3_highpart"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(mult:VANY (match_operand:VANY 1 "register_operand" "v")
		   (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vmulhvv_<mode> (operands[0], operands[1], operands[2],
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "umul<mode>3_highpart"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(mult:VANY (match_operand:VANY 1 "register_operand" "v")
		   (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vmulhuvv_<mode> (operands[0], operands[1],
      operands[2], gen_rtx_REG (SImode, 0)));
    DONE;
  }
)


(define_expand "madd<mode><vwiden_attr>4"
  [(set (match_operand:<VWIDEN_attr> 0 "register_operand" "+v")
	(plus:<VWIDEN_attr>
	  (mult:<VWIDEN_attr> (sign_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 1 "register_operand" "v"))
			      (sign_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 2 "register_operand" "v")))
	(match_dup 0)))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vwmaccvv_<mode> (operands[0], operands[1],
      operands[2], operands[3], gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "umadd<mode><vwiden_attr>4"
  [(set (match_operand:<VWIDEN_attr> 0 "register_operand" "+v")
	(plus:<VWIDEN_attr>
	  (mult:<VWIDEN_attr> (zero_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 1 "register_operand" "v"))
			      (zero_extend:<VWIDEN_attr>
	    (match_operand:VWIDEN_DSHQ 2 "register_operand" "v")))
	(match_dup 0)))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vwmaccuvv_<mode> (operands[0], operands[1],
      operands[2], operands[3], gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "vashl<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(ashift:VANY (match_operand:VANY 1 "register_operand" "v")
		     (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vsllvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "vashr<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(ashiftrt:VANY (match_operand:VANY 1 "register_operand" "v")
		       (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vsravv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "vlshr<mode>3"
  [(set (match_operand:VANY 0 "register_operand" "=v")
	(lshiftrt:VANY (match_operand:VANY 1 "register_operand" "v")
		       (match_operand:VANY 2 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vsrlvv_<mode> (operands[0], operands[1], operands[2],
					gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_mode_iterator VI32 [ V2HI V4QI ])
(define_mode_iterator VI64 [ V2SI V4HI V8QI ])

(define_expand "neg<mode>2"
  [(set (match_operand:VI32 0	     "register_operand" "=r")
	(neg:VI32   (match_operand:VI32 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  ""
)

(define_expand "neg<mode>2"
  [(set (match_operand:VI64 0	   "register_operand" "=r")
	(neg:VI64 (match_operand:VI64 1 "register_operand" "r")))]
  "(TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN)
   || (TARGET_XTHEAD_DSP && TARGET_64BIT)"
  {
    if (!(TARGET_XTHEAD_DSP && TARGET_64BIT) && TARGET_XTHEAD_VECTOR
	&& TARGET_XTHEAD_VSPN)
      {
	emit_insn (gen_riscv_vrsubvi_<mode> (operands[0], operands[1],
	  const0_rtx, gen_rtx_REG (SImode, 0)));
	DONE;
      }
  }
)

(define_expand "neg<mode>2"
  [(match_operand:VANY_RVV 0 "register_operand")
   (match_operand:VANY_RVV 1 "register_operand")]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vrsubvi_<mode> (operands[0], operands[1], const0_rtx,
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "trunc<vnarrow_attr><mode>2"
  [(set (match_operand:<VNARROW_attr> 0 "register_operand" "=v")
	(truncate:<VNARROW_attr>
	  (match_operand:VNARROW 1 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    emit_insn (gen_riscv_vnsrlvi_<mode> (operands[0], operands[1], const0_rtx,
					 gen_rtx_REG (SImode, 0)));
    DONE;
  }
)

(define_expand "extend<vwiden_attr><mode>2"
  [(set (match_operand:<VWIDEN_attr> 0 "register_operand" "=v")
	(sign_extend:<VWIDEN_attr>
	  (match_operand:VWIDEN_DSHQ 1 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    rtx x0 = gen_rtx_REG (SImode, 0);
    emit_insn (gen_riscv_vwaddvx_<mode> (operands[0], operands[1], x0, x0));
    DONE;
  }
)

(define_expand "zero_extend<vwiden_attr><mode>2"
  [(set (match_operand:<VWIDEN_attr> 0 "register_operand" "=v")
	(zero_extend:<VWIDEN_attr>
	  (match_operand:VWIDEN_DSHQ 1 "register_operand" "v")))
   (clobber (const_int 0))]
  "TARGET_XTHEAD_VECTOR && TARGET_XTHEAD_VSPN"
  {
    rtx x0 = gen_rtx_REG (SImode, 0);
    emit_insn (gen_riscv_vwadduvx_<mode> (operands[0], operands[1], x0, x0));
    DONE;
  }
)
