
(define_expand "movhf"
  [(set (match_operand:HF 0 "")
   (match_operand:HF 1 ""))]
  "TARGET_XTHEAD_FP16"
{
  if (riscv_legitimize_move (HFmode, operands[0], operands[1]))
    DONE;
})

(define_insn "*movhf_hardfloat"
  [(set (match_operand:HF 0 "nonimmediate_operand" "=f,f,f,m,m,*f,*r,  *r,*r,*m")
	(match_operand:HF 1 "move_operand"         " f,G,m,f,G,*r,*f,*G*r,*m,*r"))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT
   && (register_operand (operands[0], HFmode)
       || reg_or_0_operand (operands[1], HFmode))"
  {
    if (REG_P (operands[0]) && GP_REG_P (REGNO (operands[0]))
	&& REG_P (operands[1]) && FP_REG_P (REGNO (operands[1])))
      return "fmv.x.h\t%0,%1";
    else if (REG_P (operands[0]) && FP_REG_P (REGNO (operands[0]))
	     && ((REG_P (operands[1]) && GP_REG_P (REGNO (operands[1])))
		 || (operands[1] == CONST0_RTX (HFmode))))
      return "fmv.h.x\t%0,%z1";
    else if (REG_P (operands[0]) && FP_REG_P (REGNO (operands[0]))
	     && REG_P (operands[1]) && FP_REG_P (REGNO (operands[1])))
      return "fmv.h\t%0,%1";
    else
      return riscv_output_move (operands[0], operands[1]);
  }
  [(set_attr "move_type" "fmove,mtc,fpload,fpstore,store,mtc,mfc,move,load,store")
   (set_attr "mode" "HF")])

(define_insn "addhf3"
  [(set (match_operand:HF          0 "register_operand" "=f")
	(plus:HF (match_operand:HF 1 "register_operand" " f")
		 (match_operand:HF 2 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fadd.h\t%0,%1,%2"
  [(set_attr "type" "fadd")
   (set_attr "mode" "HF")])

(define_insn "subhf3"
  [(set (match_operand:HF           0 "register_operand" "=f")
	(minus:HF (match_operand:HF 1 "register_operand" " f")
		  (match_operand:HF 2 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fsub.h\t%0,%1,%2"
  [(set_attr "type" "fadd")
   (set_attr "mode" "HF")])

(define_insn "extendhfdf2"
  [(set (match_operand:DF     0 "register_operand" "=f")
	(float_extend:DF
	    (match_operand:HF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_DOUBLE_FLOAT"
  "fcvt.d.h\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "truncdfhf2"
  [(set (match_operand:HF     0 "register_operand" "=f")
	(float_truncate:HF
	    (match_operand:DF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_DOUBLE_FLOAT"
  "fcvt.h.d\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "floatdihf2"
  [(set (match_operand:HF    0 "register_operand" "= f")
	(float:HF
	    (match_operand:DI 1 "register_operand" " r")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.h.l\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "floatunsdihf2"
  [(set (match_operand:HF    0 "register_operand" "= f")
	(unsigned_float:HF
	    (match_operand:DI 1 "register_operand" " r")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.h.lu\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "truncsfhf2"
  [(set (match_operand:HF     0 "register_operand" "=f")
	(float_truncate:HF
	    (match_operand:SF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_DOUBLE_FLOAT"
  "fcvt.h.s\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "floatsihf2"
  [(set (match_operand:HF    0 "register_operand" "= f")
	(float:HF
	    (match_operand:SI 1 "register_operand" " r")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.h.w\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "floatunssihf2"
  [(set (match_operand:HF    0 "register_operand" "= f")
	(unsigned_float:HF
	    (match_operand:SI 1 "register_operand" " r")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.h.wu\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "fix_trunchf<GPR:mode>2"
  [(set (match_operand:GPR      0 "register_operand" "=r")
	(fix:GPR
	    (match_operand:HF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.<GPR:ifmt>.h %0,%1,rtz"
  [(set_attr "type" "fcvt_i")
   (set_attr "mode" "HF")])

(define_insn "fixuns_trunchf<GPR:mode>2"
  [(set (match_operand:GPR      0 "register_operand" "=r")
	(unsigned_fix:GPR
	    (match_operand:HF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.<GPR:ifmt>u.h %0,%1,rtz"
  [(set_attr "type" "fcvt_i")
   (set_attr "mode" "HF")])

(define_insn "l<rint_pattern>hf<GPR:mode>2"
  [(set (match_operand:GPR       0 "register_operand" "=r")
	(unspec:GPR
	    [(match_operand:HF 1 "register_operand" " f")]
	    RINT))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fcvt.<GPR:ifmt>.h %0,%1,<rint_rm>"
  [(set_attr "type" "fcvt_i")
   (set_attr "mode" "HF")])

(define_insn "extendhfsf2"
  [(set (match_operand:SF     0 "register_operand" "=f")
	(float_extend:SF
	    (match_operand:HF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_DOUBLE_FLOAT"
  "fcvt.s.h\t%0,%1"
  [(set_attr "type" "fcvt")
   (set_attr "mode" "HF")])

(define_insn "divhf3"
  [(set (match_operand:HF         0 "register_operand" "=f")
	(div:HF (match_operand:HF 1 "register_operand" " f")
		(match_operand:HF 2 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT && TARGET_FDIV"
  "fdiv.h\t%0,%1,%2"
  [(set_attr "type" "fdiv")
   (set_attr "mode" "HF")])

(define_expand "cstorehf4"
  [(set (match_operand:SI 0 "register_operand")
	(match_operator:SI 1 "fp16_less_or_equal_cmp"
	     [(match_operand:HF 2 "register_operand")
	      (match_operand:HF 3 "register_operand")]))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
{
  riscv_expand_float_scc (operands[0], GET_CODE (operands[1]), operands[2],
			  operands[3]);
  DONE;
})

(define_insn "*cstorehfdi4"
   [(set (match_operand:DI      0 "register_operand" "=r")
	 (match_operator:DI     1 "fp16_less_or_equal_cmp"
	     [(match_operand:HF 2 "register_operand" " f")
	      (match_operand:HF 3 "register_operand" " f")]))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "f%C1.h\t%0,%2,%3"
  [(set_attr "type" "fcmp")
   (set_attr "mode" "HF")])

(define_insn "fmahf4"
  [(set (match_operand:HF         0 "register_operand" "=f")
	(fma:HF (match_operand:HF 1 "register_operand" " f")
		(match_operand:HF 2 "register_operand" " f")
		(match_operand:HF 3 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fmadd.h\t%0,%1,%2,%3"
  [(set_attr "type" "fmadd")
   (set_attr "mode" "HF")])

(define_insn "sminhf3"
  [(set (match_operand:HF          0 "register_operand" "=f")
	(smin:HF (match_operand:HF 1 "register_operand" " f")
		 (match_operand:HF 2 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fmin.h\t%0,%1,%2"
  [(set_attr "type" "fmove")
   (set_attr "mode" "HF")])

(define_insn "smaxhf3"
  [(set (match_operand:HF          0 "register_operand" "=f")
	(smax:HF (match_operand:HF 1 "register_operand" " f")
		 (match_operand:HF 2 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fmax.h\t%0,%1,%2"
  [(set_attr "type" "fmove")
   (set_attr "mode" "HF")])

(define_insn "fmshf4"
  [(set (match_operand:HF                 0 "register_operand" "=f")
	(fma:HF (match_operand:HF         1 "register_operand" " f")
		(match_operand:HF         2 "register_operand" " f")
		(neg:HF (match_operand:HF 3 "register_operand" " f"))))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fmsub.h\t%0,%1,%2,%3"
  [(set_attr "type" "fmadd")
   (set_attr "mode" "HF")])

(define_insn "mulhf3"
  [(set (match_operand:HF          0 "register_operand" "=f")
	(mult:HF (match_operand:HF 1 "register_operand" " f")
		 (match_operand:HF 2 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fmul.h\t%0,%1,%2"
  [(set_attr "type" "fmul")
   (set_attr "mode" "HF")])

(define_insn "fnmshf4"
  [(set (match_operand:HF             0 "register_operand" "=f")
	(fma:HF
	    (neg:HF (match_operand:HF 1 "register_operand" " f"))
	    (match_operand:HF         2 "register_operand" " f")
	    (neg:HF (match_operand:HF 3 "register_operand" " f"))))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fnmadd.h\t%0,%1,%2,%3"
  [(set_attr "type" "fmadd")
   (set_attr "mode" "HF")])

(define_insn "fnmahf4"
  [(set (match_operand:HF             0 "register_operand" "=f")
	(fma:HF
	    (neg:HF (match_operand:HF 1 "register_operand" " f"))
	    (match_operand:HF         2 "register_operand" " f")
	    (match_operand:HF         3 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fnmsub.h\t%0,%1,%2,%3"
  [(set_attr "type" "fmadd")
   (set_attr "mode" "HF")])

(define_insn "sqrthf2"
  [(set (match_operand:HF          0 "register_operand" "=f")
	(sqrt:HF (match_operand:HF 1 "register_operand" " f")))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT && TARGET_FDIV"
  "fsqrt.h\t%0,%1"
  [(set_attr "type" "fsqrt")
   (set_attr "mode" "HF")])

(define_insn "copysignhf3"
  [(set (match_operand:HF             0 "register_operand" "=f")
	(unspec:HF [(match_operand:HF 1 "register_operand" " f")
		    (match_operand:HF 2 "register_operand" " f")]
		     UNSPEC_COPYSIGN))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
  "fsgnj.h\t%0,%1,%2"
  [(set_attr "type" "fsgnj")
   (set_attr "mode" "HF")])

(define_expand "cbranchhf4"
  [(set (pc)
	(if_then_else (match_operator     0 "fp_branch_comparison"
		       [(match_operand:HF 1 "register_operand")
			(match_operand:HF 2 "register_operand")])
		      (label_ref (match_operand 3 ""))
		      (pc)))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT"
{
  riscv_expand_conditional_branch (operands[3], GET_CODE (operands[0]),
				   operands[1], operands[2]);
  DONE;
})

(define_expand "f<quiet_pattern>_quiethf<mode>4"
   [(parallel [(set (match_operand:X      0 "register_operand")
		    (unspec:X
		     [(match_operand:HF 1 "register_operand")
		      (match_operand:HF 2 "register_operand")]
		     QUIET_COMPARISON))
	       (clobber (match_scratch:X 3))])]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT")

(define_insn "*f<quiet_pattern>_quiethf<mode>4_default"
   [(set (match_operand:X      0 "register_operand" "=r")
	 (unspec:X
	  [(match_operand:HF 1 "register_operand" " f")
	   (match_operand:HF 2 "register_operand" " f")]
	  QUIET_COMPARISON))
    (clobber (match_scratch:X 3 "=&r"))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT && ! HONOR_SNANS (HFmode)"
  {
    if (!TARGET_XTHEAD_FCLASS)
      return "frflags\t%3\n\t"
	     "f<quiet_pattern>.h\t%0,%1,%2\n\t"
	     "fsflags %3";
    else
      return "fclass.h\t%0,%1\n\t"
	     "fclass.h\t%3,%2\n\t"
	     "or\t%0,%0,%3\n\t"
	     "slti\t%0,%0,0x100\n\t"
	     "beqz\t%0, 0f\n\t"
	     "f<quiet_pattern>.h\t%0,%1,%2\n"
	     "0:";
  }
  [(set_attr "type" "fcmp")
   (set_attr "mode" "HF")])

(define_insn "*f<quiet_pattern>_quiethf<mode>4_snan"
   [(set (match_operand:X      0 "register_operand" "=r")
	 (unspec:X
	  [(match_operand:HF 1 "register_operand" " f")
	   (match_operand:HF 2 "register_operand" " f")]
	  QUIET_COMPARISON))
    (clobber (match_scratch:X 3 "=&r"))]
  "TARGET_XTHEAD_FP16 && TARGET_HARD_FLOAT && HONOR_SNANS (HFmode)"
  {
    if (!TARGET_XTHEAD_FCLASS)
      return "frflags\t%3\n\t"
	     "f<quiet_pattern>.h\t%0,%1,%2\n\t"
	     "fsflags %3\n\t"
	     "feq.h\tzero,%1,%2";
    else
      return "fclass.h\t%0,%1\n\t"
	     "fclass.h\t%3,%2\n\t"
	     "or\t%0,%0,%3\n\t"
	     "slti\t%0,%0,0x200\n\t"
	     "beqz\t%0, 0f\n\t"
	     "f<quiet_pattern>.h\t%0,%1,%2\n"
	     "0:";
  }
  [(set_attr "type" "fcmp")
   (set_attr "mode" "HF")])
