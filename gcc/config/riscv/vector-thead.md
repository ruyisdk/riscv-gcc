
(define_c_enum "unspec" [
  UNSPEC_VMAQA
  UNSPEC_VMAQAU
  UNSPEC_VMAQASU
  UNSPEC_VMAQAUS
  UNSPEC_VPMAQA
  UNSPEC_VPMAQAU
  UNSPEC_VPMAQASU
  UNSPEC_VPMAQAUS
  UNSPEC_VPNCLIP
  UNSPEC_VPNCLIPU
  UNSPEC_VPWADD
  UNSPEC_VPWADDU
])

(define_int_iterator UNSPEC_WMAQA [UNSPEC_VMAQA UNSPEC_VPMAQA])
(define_int_iterator UNSPEC_WMAQAU [UNSPEC_VMAQAU UNSPEC_VPMAQAU])
(define_int_iterator UNSPEC_WMAQASU [UNSPEC_VMAQASU UNSPEC_VPMAQASU])
(define_int_iterator UNSPEC_WMAQAUS [UNSPEC_VMAQAUS UNSPEC_VPMAQAUS])

(define_int_attr maqa [(UNSPEC_VMAQA "maqa") (UNSPEC_VMAQAU "maqa")
		       (UNSPEC_VMAQASU "maqa") (UNSPEC_VMAQAUS "maqa")
		       (UNSPEC_VPMAQA "pmaqa") (UNSPEC_VPMAQAU "pmaqa")
		       (UNSPEC_VPMAQASU "pmaqa") (UNSPEC_VPMAQAUS "pmaqa")])

;; Iterator for pack widening integer add instructions.
(define_int_iterator UNSPEC_WPWADD [UNSPEC_VPWADD UNSPEC_VPWADDU])

;; Iterator and attributes for pack narrowing clip instructions.
(define_int_iterator UNSPEC_VPCLIP [UNSPEC_VPNCLIP UNSPEC_VPNCLIPU])

(define_int_attr tv_su [(UNSPEC_VPNCLIP "") (UNSPEC_VPNCLIPU "u")
			(UNSPEC_VPWADD "") (UNSPEC_VPWADDU "u")])

;;Vector Quad-Widening Integer Multiply-Add with Queue-Add Instructions

(define_insn "<maqa><mode><vqwsmode8>4"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:VQWSIMODES8 2 "register_operand" "vr")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQA)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>.vv\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "u<maqa><mode><vqwsmode8>4"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:VQWSIMODES8 2 "register_operand" "vr")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQAU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>u.vv\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "su<maqa><mode><vqwsmode8>4"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:VQWSIMODES8 2 "register_operand" "vr")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQASU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>su.vv\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "<maqa><mode><vqwsmode8>4_scalar"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VQWSUBMODE8> 2 "register_operand" "r")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQA)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>.vx\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "u<maqa><mode><vqwsmode8>4_scalar"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VQWSUBMODE8> 2 "register_operand" "r")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQAU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>u.vx\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "su<maqa><mode><vqwsmode8>4_scalar"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VQWSUBMODE8> 2 "register_operand" "r")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQASU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>su.vx\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "us<maqa><mode><vqwsmode8>4_scalar"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VQWSUBMODE8> 2 "register_operand" "r")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 1 "register_operand" "0")]
	    UNSPEC_WMAQAUS)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>us.vx\t%0,%2,%3"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "<maqa><mode><vqwsmode8>4_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQA)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>.vv\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "u<maqa><mode><vqwsmode8>4_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQAU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>u.vv\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "su<maqa><mode><vqwsmode8>4_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VQWSIMODES8 3 "register_operand" "vr")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQASU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>su.vv\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "<maqa><mode><vqwsmode8>4_scalar_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:<VQWSUBMODE8> 3 "register_operand" "r")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQA)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>.vx\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "u<maqa><mode><vqwsmode8>4_scalar_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:<VQWSUBMODE8> 3 "register_operand" "r")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQAU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>u.vx\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "su<maqa><mode><vqwsmode8>4_scalar_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:<VQWSUBMODE8> 3 "register_operand" "r")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQASU)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>su.vx\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "us<maqa><mode><vqwsmode8>4_scalar_mask"
  [(set (match_operand:<VQWSMODE8> 0 "register_operand" "=&vr")
	(unspec:<VQWSMODE8>
	  [(unspec:<VQWSMODE8>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:<VQWSUBMODE8> 3 "register_operand" "r")
	      (match_operand:VQWSIMODES8 4 "register_operand" "vr")
	      (match_operand:<VQWSMODE8> 2 "register_operand" "0")]
	    UNSPEC_WMAQAUS)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "v<maqa>us.vx\t%0,%3,%4,%1.t"
  [(set_attr "type" "vmadd")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;;Vector Pack Narrowing Clip Instructions

(define_insn "vpnclip<tv_su><mode>3_nv"
  [(set (match_operand:VWIMODES 0 "register_operand" "=&vr")
	(unspec:VWIMODES
	  [(unspec:VWIMODES
	     [(match_operand:<VWMODE> 1 "register_operand" "vr")
	      (match_operand:VWIMODES 2 "register_operand" "vr")]
	    UNSPEC_VPCLIP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpnclip<tv_su>.wv\t%0,%1,%2"
  [(set_attr "type" "vshift")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "vpnclip<tv_su><mode>3_nv_scalar"
  [(set (match_operand:VWIMODES 0 "register_operand" "=&vr")
	(unspec:VWIMODES
	  [(unspec:VWIMODES
	     [(match_operand:<VWMODE> 1 "register_operand" "vr")
	      (vec_duplicate:VWIMODES
		(match_operand:<VSUBMODE> 2 "register_operand" "r"))]
	    UNSPEC_VPCLIP)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpnclip<tv_su>.wx\t%0,%1,%2"
  [(set_attr "type" "vshift")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "vpnclip<tv_su><mode>3_nv_mask"
  [(set (match_operand:VWIMODES 0 "register_operand" "=&vr")
	(unspec:VWIMODES
	  [(if_then_else:VWIMODES
	     (match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	     (unspec:VWIMODES
	       [(match_operand:<VWMODE> 3 "register_operand" "vr")
		(match_operand:VWIMODES 4 "register_operand" "vr")]
	      UNSPEC_VPCLIP)
	     (match_operand:VWIMODES 2 "register_operand" "0"))
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpnclip<tv_su>.wv\t%0,%3,%4,%1.t"
  [(set_attr "type" "vshift")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "vpnclip<tv_su><mode>3_nv_scalar_mask"
  [(set (match_operand:VWIMODES 0 "register_operand" "=&vr")
	(unspec:VWIMODES
	  [(if_then_else:VWIMODES
	     (match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	     (unspec:VWIMODES
	       [(match_operand:<VWMODE> 3 "register_operand" "vr")
		(vec_duplicate:VWIMODES
		  (match_operand:<VSUBMODE> 4 "register_operand" "r"))]
	      UNSPEC_VPCLIP)
	     (match_operand:VWIMODES 2 "register_operand" "0"))
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpnclip<tv_su>.wx\t%0,%3,%4,%1.t"
  [(set_attr "type" "vshift")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

;; Vector Pack Widening Integer Add

(define_insn "pwadd<tv_su><mode>_vv"
  [(set (match_operand:<VWMODE> 0 "register_operand" "=&vr")
	(unspec:<VWMODE>
	  [(unspec:<VWMODE>
	     [(match_operand:VWIMODES 1 "register_operand" "vr")
	      (match_operand:VWIMODES 2 "register_operand" "vr")]
	    UNSPEC_WPWADD)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpwadd<tv_su>.vv\t%0,%1,%2"
  [(set_attr "type" "varith")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "pwadd<tv_su><mode>_vv_scalar"
  [(set (match_operand:<VWMODE> 0 "register_operand" "=&vr")
	(unspec:<VWMODE>
	  [(unspec:<VWMODE>
	     [(match_operand:VWIMODES 1 "register_operand" "vr")
	      (match_operand:<VSUBMODE> 2 "register_operand" "r")]
	    UNSPEC_WPWADD)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpwadd<tv_su>.vx\t%0,%1,%2"
  [(set_attr "type" "varith")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "pwadd<tv_su><mode>_vv_mask"
  [(set (match_operand:<VWMODE> 0 "register_operand" "=&vr")
	(unspec:<VWMODE>
	  [(unspec:<VWMODE>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VWIMODES 3 "register_operand" "vr")
	      (match_operand:VWIMODES 4 "register_operand" "vr")
	      (match_operand:<VWMODE> 2 "register_operand" "0")]
	    UNSPEC_WPWADD)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpwadd<tv_su>.vv\t%0,%3,%4,%1.t"
  [(set_attr "type" "varith")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])

(define_insn "pwadd<tv_su><mode>_vv_scalar_mask"
  [(set (match_operand:<VWMODE> 0 "register_operand" "=&vr")
	(unspec:<VWMODE>
	  [(unspec:<VWMODE>
	     [(match_operand:<VCMPEQUIV> 1 "register_operand" "vm")
	      (match_operand:VWIMODES 3 "register_operand" "vr")
	      (match_operand:<VSUBMODE> 4 "register_operand" "r")
	      (match_operand:<VWMODE> 2 "register_operand" "0")]
	    UNSPEC_WPWADD)
	   (reg:SI VL_REGNUM)]
	 UNSPEC_USEVL))
   (use (reg:<VLMODE> VTYPE_REGNUM))]
  "TARGET_VECTOR"
  "vpwadd<tv_su>.vx\t%0,%3,%4,%1.t"
  [(set_attr "type" "varith")
   (set_attr "mode" "none")
   (set_attr "emode" "<VSUBMODE>")])
