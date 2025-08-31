;); Machine description for RISC-V Bit Manipulation operations.
;; Copyright (C) 2025 Free Software Foundation, Inc.
;; Contributed by Jiawei Chen (jiawei@iscas.ac.cn), PLCT ISCAS.

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

;; Packed-SIMD extension.


(define_c_enum "unspec" [
  UNSPEC_PSLLI
  UNSPEC_PSSLAI
  UNSPEC_SSLAI
  UNSPEC_PLI
  UNSPEC_PSEXT
  UNSPEC_PLUI
  UNSPEC_PSLL
  UNSPEC_PADD
  UNSPEC_PSSHA
  UNSPEC_PSRLI
  UNSPEC_PUSATI
  UNSPEC_PSRAI
  UNSPEC_PSATI
  UNSPEC_SATI
  UNSPEC_PSRA
  UNSPEC_PDIFSUMU
  UNSPEC_PDIFSUMAU
  UNSPEC_PMUL
  UNSPEC_PPACK
  UNSPEC_PM2ADD
  UNSPEC_PMULH
])


(define_mode_iterator VQI [(V4QI "!TARGET_64BIT") (V8QI "TARGET_64BIT")])
(define_mode_iterator VHI [(V2HI "!TARGET_64BIT") (V4HI "TARGET_64BIT")])
(define_mode_iterator V_SI [(SI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])
(define_mode_iterator SI_DI [(SI "!TARGET_64BIT") (DI "TARGET_64BIT")])
(define_mode_iterator VPSI [(SI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])
(define_mode_attr PSEXT [(V2HI "V4QI") (V4HI "V8QI")])
(define_mode_iterator VD_SI [(SI "!TARGET_64BIT") (V2SI "TARGET_64BIT")])


(define_mode_iterator VQIHISI [(V4QI "!TARGET_64BIT") (V8QI "TARGET_64BIT")
                            (V2HI "!TARGET_64BIT") (V4HI "TARGET_64BIT")
                            (V2SI "TARGET_64BIT")])

(define_mode_attr SUFFIX [(V4QI "b") (V8QI "b") (V2HI "h") (V4HI "h") (V2SI "w")])
(define_mode_attr PMUL [(V2HI "V4QI") (V4HI "V8QI")])


;Packed Shift Left Immediate intrinsics
(define_insn "riscv_pslli_<SUFFIX>_<VQIHISI:mode><X:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSLLI))]
  "TARGET_RVP"
  "pslli.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])


(define_insn "riscv_psslai_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSSLAI))]
  "TARGET_RVP"
  "psslai.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_psslai_w_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:DI 2 "immediate_operand" "i")]
         UNSPEC_PSSLAI))]
  "TARGET_RVP && TARGET_64BIT"
  "psslai.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_sslai_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "immediate_operand" "i")]
         UNSPEC_SSLAI))]
  "TARGET_RVP && !TARGET_64BIT"
  "sslai\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Immediate Load intrinsics
(define_insn "riscv_pli_b_<VQI:mode><X:mode>_p"
  [(set (match_operand:VQI 0 "register_operand" "=r")
        (unspec:VQI [(match_operand:X 1 "immediate_operand" "i")]
         UNSPEC_PLI))]
  "TARGET_RVP"
  "pli.b\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQI:MODE>")])

(define_insn "riscv_pli_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:X 1 "immediate_operand" "i")]
         UNSPEC_PLI))]
  "TARGET_RVP"
  "pli.h\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_pli_w_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:DI 1 "immediate_operand" "i")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "pli.h\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Sign Extension intrinsics   类型buyizhi
(define_insn "riscv_psext_h_b_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (sign_extend:VHI
        (match_operand:<PSEXT> 1 "register_operand" "r")))]
  "TARGET_RVP"
  "psext.h.b\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psext_w_b_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PSEXT))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.w.b\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_psext_w_h_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (sign_extend:V2SI (match_operand:V4HI 1 "register_operand" "r")))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.w.h\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Load Upper Immediate intrinsics
(define_insn "riscv_plui_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:X 1 "immediate_operand" "i")]
         UNSPEC_PLUI))]
  "TARGET_RVP"
  "plui.h\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_plui_w_<X:mode>_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:X 1 "immediate_operand" "i")]
         UNSPEC_PLUI))]
  "TARGET_RVP && TARGET_64BIT"
  "plui.w\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Shift Left Register intrinsics
(define_insn "riscv_psll_bs_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand" "=r")
        (unspec:VQI [(match_operand:VQI 1 "register_operand" "r")
                    (match_operand:VQI 2 "register_operand" "r")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
  "psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psll_hs_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
  "psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psll_ws_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "psll.ws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Addition intrinsics
(define_insn "riscv_padd_<SUFFIX>s_<mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (plus:VQIHISI (match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")))]
  "TARGET_RVP"
  "psll.<SUFFIX>s\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_padd_ws_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (plus:V2SI (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_RVP && TARGET_64BIT"
  "psll.ws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Saturating Arithmetic Shift intrinsics
(define_insn "riscv_pssha_hs_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pssha.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pssha_ws_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "pssha.ws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_sha_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "sha\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_ssha_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "ssha\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_psshar_hs_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "psshar.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psshar_ws_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "psshar.ws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_shar_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "shar\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_sshar_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "sshar\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;Packed Shift Right Logical Immediate intrinsics
(define_insn "riscv_psrli_b_<VQI:mode><X:mode>_p"
  [(set (match_operand:VQI 0 "register_operand" "=r")
        (unspec:VQI [(match_operand:VQI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRLI))]
  "TARGET_RVP"
  "psrli.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQI:MODE>")])

(define_insn "riscv_psrli_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRLI))]
  "TARGET_RVP"
  "psrli.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_psrli_w_<X:mode>_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRLI))]
  "TARGET_RVP && TARGET_64BIT"
  "psrli.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Unsigned Saturating Immediate intrinsics
(define_insn "riscv_pusati_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand"               "=   r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"  "    r")
		      (match_operand:X 2 "immediate_operand"     "i")]
		     UNSPEC_PUSATI))]
  "TARGET_RVP"
  "pusati.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_pusati_w_<mode>_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
		       (match_operand:X 2 "immediate_operand" "i")] UNSPEC_PUSATI))]
  "TARGET_RVP && TARGET_64BIT"
  "pusati.w\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;usati=uclip32=pusati_w
(define_insn "riscv_usati_<VD_SI:mode><X:mode>_p"
  [(set (match_operand:VD_SI 0 "register_operand" "=r")
	(unspec:VD_SI [(match_operand:VD_SI 1 "register_operand" "r")
		       (match_operand:X 2 "immediate_operand" "i")] UNSPEC_PUSATI))]
  "TARGET_RVP"
  "usati\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VD_SI:MODE>")])

;Packed Arithmetic Shift Right Immediate intrinsics
(define_insn "riscv_psrai_<SUFFIX>_<VQIHISI:mode><X:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRAI))]
  "TARGET_RVP"
  "psrai.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_psrari_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRAI))]
  "TARGET_RVP"
  "psrari.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_psrari_w_<mode>_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRAI))]
  "TARGET_RVP && TARGET_64BIT"
  "psrari.w\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_srari_<VD_SI:mode><X:mode>_p"
  [(set (match_operand:VD_SI 0 "register_operand" "=r")
        (unspec:VD_SI [(match_operand:VD_SI 1 "register_operand" "r")
                    (match_operand:X 2 "immediate_operand" "i")]
         UNSPEC_PSRAI))]
  "TARGET_RVP"
  "srari\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VD_SI:MODE>")])

;Packed Signed Saturating Immediate intrinsics
(define_insn "riscv_psati_h_<VHI:mode><X:mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=   r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand" "    r")
		     (match_operand:X 2 "immediate_operand"     " i")]
		     UNSPEC_PSATI))]
  "TARGET_RVP"
  "psati.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VHI:MODE>")])

(define_insn "riscv_psati_w_<mode>_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
		       (match_operand:X 2 "immediate_operand" "i")] UNSPEC_PSATI))]
  "TARGET_RVP && TARGET_64BIT"
  "sclip32\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_sati_<VD_SI:mode><X:mode>_p"
  [(set (match_operand:VD_SI 0 "register_operand" "=r")
	(unspec:VD_SI [(match_operand:VD_SI 1 "register_operand" "r")
		       (match_operand:X 2 "immediate_operand" "i")] UNSPEC_PSRAI))]
  "TARGET_RVP"
  "sati\t%0,%1,%2"
  [(set_attr "type"   "simd")
   (set_attr "mode" "<VD_SI:MODE>")])

;Packed Shift Right Logical Register intrinsics
(define_insn "riscv_psrl_<SUFFIX>s_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")]
         UNSPEC_PSLLI))]
  "TARGET_RVP"
  "psrl.<SUFFIX>s\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

;Packed Predicated Summation intrinsics
(define_insn "riscv_predsum_<SUFFIX>s_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (plus:VQIHISI (match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")))]
  "TARGET_RVP"
  "predsum.<SUFFIX>s\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_predsumu_<SUFFIX>s_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (plus:VQIHISI (match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")))]
  "TARGET_RVP"
  "predsumu.<SUFFIX>s\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])


;Packed Arithmetic Shift Right Register intrinsics
(define_insn "riscv_psra_<SUFFIX>s_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
  "psra.<SUFFIX>s\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])


;Packed Addition and Saturating Addition intrinsics
(define_insn "riscv_padd_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
  "padd.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_sadd_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" "r")] UNSPEC_PUSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "sadd.w\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_psadd_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
  "psadd.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_aadd_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" "r")] UNSPEC_PUSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "aadd\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_paadd_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand" "=r")
        (unspec:VQIHISI [(match_operand:VQIHISI 1 "register_operand" "r")
                    (match_operand:VQIHISI 2 "register_operand" "r")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
  "paadd.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])


;Packed Subtraction and Saturating Subtraction intrinsics
;普通减 (minus)、有符号饱和减 (ss_minus) 和无符号饱和减 (us_minus)。
(define_insn "riscv_psub_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "psub.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_ssub_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" "r")] UNSPEC_PUSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ssub\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pssub_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(ss_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pssub.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_asub_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" "r")] UNSPEC_PUSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "asub\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pasub_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pasub.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

;uksubw=ssubu
(define_insn "riscv_ssubu_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(us_minus:SI (match_operand:SI 1 "register_operand" "r")
		     (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "ssubu\t%0,%1,%2"
  [(set_attr "type" "simd")])

; k|(uk)|? sub==PSSUBU
(define_insn "riscv_pssubu_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pssubu.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_asubu_p"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(us_minus:SI (match_operand:SI 1 "register_operand" "r")
		     (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "asubu\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasubu_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pasubu.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])


;Packed Difference intrinsics
(define_insn "riscv_pdif_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand" "=r")
        (unspec:VQI [(match_operand:VQI 1 "register_operand" "r")
                    (match_operand:VQI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pdif.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pdifu_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand" "=r")
        (unspec:VQI [(match_operand:VQI 1 "register_operand" "r")
                    (match_operand:VQI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pdifu.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pdif_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pdif.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pdifu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pdifu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

;Packed Shift Left and Shift Right intrinsics
(define_insn "riscv_slx_<mode>_p"
  [(set (match_operand:VPSI 0 "register_operand" "=r")
        (unspec:VPSI [(match_operand:VPSI 1 "register_operand" "r")
                    (match_operand:VPSI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "slx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_srx_<mode>_p"
  [(set (match_operand:VPSI 0 "register_operand" "=r")
        (unspec:VPSI [(match_operand:VPSI 1 "register_operand" "r")
                    (match_operand:VPSI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "srx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

;Packed Multiplication intrinsics
(define_insn "riscv_pmul32_h_b01_p"
  [(set (match_operand:V2HI 0 "register_operand"                       "=r")
	    (mult:V2HI
	      (sign_extend:V4QI (match_operand:V4QI 1 "register_operand" " r"))
	      (sign_extend:V4QI (match_operand:V4QI 2 "register_operand" " r"))))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmul.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmul64_h_b01_p"
  [(set (match_operand:V4HI 0 "register_operand"                       "=r")
	    (mult:V4HI
	      (sign_extend:V8QI (match_operand:V8QI 1 "register_operand" " r"))
	      (sign_extend:V8QI (match_operand:V8QI 2 "register_operand" " r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmul_w_h01_p"
  [(set (match_operand:V2SI 0 "register_operand"                       "=r")
	    (mult:V2SI
	      (sign_extend:V4HI (match_operand:V4HI 1 "register_operand" " r"))
	      (sign_extend:V4HI (match_operand:V4HI 2 "register_operand" " r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu32_h_b01_p"
  [(set (match_operand:V2HI 0 "register_operand"                       "=r")
	    (mult:V2HI
	      (sign_extend:V4QI (match_operand:V4QI 1 "register_operand" " r"))
	      (sign_extend:V4QI (match_operand:V4QI 2 "register_operand" " r"))))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmul.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu64_h_b01_p"
  [(set (match_operand:V4HI 0 "register_operand"                       "=r")
	    (mult:V4HI
	      (sign_extend:V8QI (match_operand:V8QI 1 "register_operand" " r"))
	      (sign_extend:V8QI (match_operand:V8QI 2 "register_operand" " r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu_w_h01_p"
  [(set (match_operand:V2SI 0 "register_operand"                       "=r")
	    (mult:V2SI
	      (sign_extend:V4HI (match_operand:V4HI 1 "register_operand" " r"))
	      (sign_extend:V4HI (match_operand:V4HI 2 "register_operand" " r"))))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_h01_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
	(mult:V2HI (match_operand:V2HI 1 "register_operand" "r")
		     (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "mul.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_h01_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
	(mult:V2HI (match_operand:V2HI 1 "register_operand" "r")
		     (match_operand:V2HI 2 "register_operand" "r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulu.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_w01_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(mult:V2SI (match_operand:V2SI 1 "register_operand" "r")
		     (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_RVP && TARGET_64BIT"
  "mul.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_w01_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(mult:V2SI (match_operand:V2SI 1 "register_operand" "r")
		     (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_RVP && TARGET_64BIT"
  "mulu.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Multiply-Accumulate intrinsics
(define_insn "riscv_pmacc_w_h01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
    (plus:V2SI
	(unspec:V2SI [(match_operand:V4HI 1 "register_operand"   " 0")
		     (match_operand:V4HI 2 "register_operand" " r")]
             UNSPEC_PSSHA)
		     (match_operand:V2SI 3 "register_operand" " r")))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h01.b\t%0,%1,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_pmaccu_w_h01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
    (plus:V2SI
	(unspec:V2SI [(match_operand:V4HI 1 "register_operand"   " 0")
		     (match_operand:V4HI 2 "register_operand" " r")]
             UNSPEC_PSSHA)
		     (match_operand:V2SI 3 "register_operand" " r")))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h01.b\t%0,%1,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_macc_h01_p"
  [(set (match_operand:V2HI 0 "register_operand"              "=r")
	(unspec:V2HI [(match_operand:V2HI 1 "register_operand"   " 0")
		     (match_operand:V2HI 2 "register_operand" " r")
		     (match_operand:V2HI 3 "register_operand" " r")]
             UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc.h01.b\t%0,%1,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2HI")])

(define_insn "riscv_maccu_h01_p"
  [(set (match_operand:V2HI 0 "register_operand"              "=r")
	(unspec:V2HI [(match_operand:V2HI 1 "register_operand"   " 0")
		     (match_operand:V2HI 2 "register_operand" " r")
		     (match_operand:V2HI 3 "register_operand" " r")]
             UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccu.h01.b\t%0,%1,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2HI")])

(define_insn "riscv_macc_w01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " 0")
		     (match_operand:V2SI 2 "register_operand" " r")
		     (match_operand:V2SI 3 "register_operand" " r")]
             UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "macc.w01.b\t%0,%1,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_maccu_w01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " 0")
		     (match_operand:V2SI 2 "register_operand" " r")
		     (match_operand:V2SI 3 "register_operand" " r")]
             UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "maccu.w01.b\t%0,%1,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

;Packed Vector Move and Merge intrinsics
;; cmix==mvm
(define_insn "riscv_mvm_<X:mode>_p"
  [(set (match_operand:X 0 "register_operand"       "=r")
	  (ior:X
	    (and:X
	      (match_operand:X 1 "register_operand" " r")
	      (match_operand:X 3 "register_operand" " r"))
	    (and:X
	      (match_operand:X 2 "register_operand" " r")
	      (not:X (match_dup 3)))))]
  "TARGET_RVP"
  "mvm\t%0,%3,%1,%2"
  [(set_attr "type"   "simd")
   (set_attr "mode"   "<MODE>")])

(define_insn "riscv_mvmn_<mode>_p"
  [(set (match_operand:X 0 "register_operand"              "=r")
	(unspec:X [(match_operand:X 1 "register_operand"   " 0")
		     (match_operand:X 2 "register_operand" " r")
		     (match_operand:X 3 "register_operand" " r")] UNSPEC_PDIFSUMAU))]
  "TARGET_RVP"
  "mvmn\t%0,%3,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_merge_<mode>_p"
  [(set (match_operand:X 0 "register_operand"              "=r")
	(unspec:X [(match_operand:X 1 "register_operand"   " 0")
		     (match_operand:X 2 "register_operand" " r")
		     (match_operand:X 3 "register_operand" " r")] UNSPEC_PDIFSUMAU))]
  "TARGET_RVP"
  "merge\t%0,%3,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

;Packed Difference and Summation intrinsics
;; PBSAD=pdifsumu_b, PBSADA=pdifsumau_b
(define_insn "riscv_pdifsumu_b_<mode>_p"
  [(set (match_operand:X 0 "register_operand"              "=r")
	(unspec:X [(match_operand:X 1 "register_operand"   " r")
		     (match_operand:X 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP"
  "pdifsumu.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pdifsumau_b_<mode>_p"
  [(set (match_operand:X 0 "register_operand"              "=r")
	(unspec:X [(match_operand:X 1 "register_operand"   " 0")
		     (match_operand:X 2 "register_operand" " r")
		     (match_operand:X 3 "register_operand" " r")] UNSPEC_PDIFSUMAU))]
  "TARGET_RVP"
  "pdifsumau.b\t%0,%2,%3"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

;Packed Shift-and-Add (SH1ADD) Intrinsics
(define_insn "riscv_psh1add_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP"
  "psh1add.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psh1add_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "psh1add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psh1sadd_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && !TARGET_64BIT"
  "psh1sadd\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssh1sadd_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP"
  "pssh1sadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pssh1sadd_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "pssh1sadd.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Zip and Unzip Intrinsics
(define_insn "riscv_unzip8p_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip16p_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip8hp_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip16hp_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip8p_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip16p_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip8hp_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip16hp_p"
  [(set (match_operand:DI 0 "register_operand"              "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand"   " r")
		     (match_operand:DI 2 "register_operand" " r")] UNSPEC_PDIFSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Multiply Intrinsics (Lane Variants 00 and 11)
(define_insn "riscv_pmul_h_b00_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:<PSEXT> 1 "register_operand" "r")
                     (match_operand:<PSEXT> 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP"
  "pmul.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmul_w_h00_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmul_h_b11_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:<PSEXT> 1 "register_operand" "r")
                     (match_operand:<PSEXT> 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP"
  "pmul.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmul_w_h11_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu_h_b00_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:<PSEXT> 1 "register_operand" "r")
                     (match_operand:<PSEXT> 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP"
  "pmulu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulu_w_h00_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu_h_b11_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:<PSEXT> 1 "register_operand" "r")
                     (match_operand:<PSEXT> 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP"
  "pmulu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulu_w_h11_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulsu_h_b00_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:<PSEXT> 1 "register_operand" "r")
                     (match_operand:<PSEXT> 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP"
  "pmulsu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulsu_w_h00_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulsu_h_b11_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:<PSEXT> 1 "register_operand" "r")
                     (match_operand:<PSEXT> 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP"
  "pmulsu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulsu_w_h11_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_h00_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                     (match_operand:V4QI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && !TARGET_64BIT"
  "mul.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_w00_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "mul.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_h11_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                     (match_operand:V4QI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && !TARGET_64BIT"
  "mul.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_w11_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "mul.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_h00_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                     (match_operand:V4QI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulu.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_w00_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "mulu.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_h11_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                     (match_operand:V4QI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulu.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_w11_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "mulu.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulsu_h00_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                     (match_operand:V4QI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulsu_w00_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "mulsu.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulsu_h11_p"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                     (match_operand:V4QI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulsu_w11_p"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                     (match_operand:V4HI 2 "register_operand" "r")]
                    UNSPEC_PMUL))]
  "TARGET_RVP && TARGET_64BIT"
  "mulsu.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed and Reordered Pack Intrinsics
(define_insn "riscv_ppack_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "ppack.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_ppack_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PPACK))]
 "TARGET_RVP && TARGET_64BIT"
 "ppack.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppackbt_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "ppackbt.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_ppackbt_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PPACK))]
 "TARGET_RVP && TARGET_64BIT"
 "ppackbt.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_packbt_<mode>_p"
  [(set (match_operand:V_SI 0 "register_operand"              "=r")
	(unspec:V_SI [(match_operand:V_SI 1 "register_operand"   " r")
		     (match_operand:V_SI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "packbt\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_ppacktb_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "ppacktb.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_ppacktb_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PPACK))]
 "TARGET_RVP && TARGET_64BIT"
 "ppacktb.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_packtb_<mode>_p"
  [(set (match_operand:V_SI 0 "register_operand"              "=r")
	(unspec:V_SI [(match_operand:V_SI 1 "register_operand"   " r")
		     (match_operand:V_SI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "packtb\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_ppackt_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "ppackt.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_ppackt_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PPACK))]
 "TARGET_RVP && TARGET_64BIT"
 "ppackt.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_packt_<mode>_p"
  [(set (match_operand:V_SI 0 "register_operand"              "=r")
	(unspec:V_SI [(match_operand:V_SI 1 "register_operand"   " r")
		     (match_operand:V_SI 2 "register_operand" " r")] UNSPEC_PPACK))]
  "TARGET_RVP"
  "packt\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])



;Packed Multiply-Add and Multiply-Add-Accumulate Intrinsics
(define_insn "riscv_pm2add_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2add_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4add_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand"              "=r")
	(unspec:VQI [(match_operand:VQI 1 "register_operand"   " r")
		     (match_operand:VQI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm4add.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm4add_h_p"
  [(set (match_operand:V4HI 0 "register_operand"              "=r")
	(unspec:V4HI [(match_operand:V4HI 1 "register_operand"   " r")
		     (match_operand:V4HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm4add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2adda_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2adda_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2adda.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4adda_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand"              "=r")
	(unspec:VQI [(match_operand:VQI 1 "register_operand"   " r")
		     (match_operand:VQI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm4adda.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm4adda_h_p"
  [(set (match_operand:V4HI 0 "register_operand"              "=r")
	(unspec:V4HI [(match_operand:V4HI 1 "register_operand"   " r")
		     (match_operand:V4HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm4adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2add_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2add.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2add_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2add.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2adda_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2adda.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2adda_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2adda.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2addu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2addu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2addu_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2addu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4addu_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand"              "=r")
	(unspec:VQI [(match_operand:VQI 1 "register_operand"   " r")
		     (match_operand:VQI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm4addu.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm4addu_h_p"
  [(set (match_operand:V4HI 0 "register_operand"              "=r")
	(unspec:V4HI [(match_operand:V4HI 1 "register_operand"   " r")
		     (match_operand:V4HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm4addu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2addau_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2addau.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2addau_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2addau.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4addau_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand"              "=r")
	(unspec:VQI [(match_operand:VQI 1 "register_operand"   " r")
		     (match_operand:VQI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm4addau.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm4addau_h_p"
  [(set (match_operand:V4HI 0 "register_operand"              "=r")
	(unspec:V4HI [(match_operand:V4HI 1 "register_operand"   " r")
		     (match_operand:V4HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm4addau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmq2add_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pmq2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmq2add_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmq2add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmqr2add_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pmqr2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmqr2add_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmqr2add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmq2adda_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pmq2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmq2adda_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmq2adda.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmqr2adda_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pmqr2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmqr2adda_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmqr2adda.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sub_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2sub.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2sub_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2sub.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sadd_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2sadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2suba_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2suba.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2suba_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2suba.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sub_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2sub.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2sub_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2sub.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sadd_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2sadd.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2suba_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2suba.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2suba_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2suba.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2addsu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2addsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2addsu_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2addsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4addsu_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand"              "=r")
	(unspec:VQI [(match_operand:VQI 1 "register_operand"   " r")
		     (match_operand:VQI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm4addsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm4addsu_h_p"
  [(set (match_operand:V4HI 0 "register_operand"              "=r")
	(unspec:V4HI [(match_operand:V4HI 1 "register_operand"   " r")
		     (match_operand:V4HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm4addsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2addasu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm2addasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm2addasu_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm2addasu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4addasu_b_<mode>_p"
  [(set (match_operand:VQI 0 "register_operand"              "=r")
	(unspec:VQI [(match_operand:VQI 1 "register_operand"   " r")
		     (match_operand:VQI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pm4addasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pm4addasu_h_p"
  [(set (match_operand:V4HI 0 "register_operand"              "=r")
	(unspec:V4HI [(match_operand:V4HI 1 "register_operand"   " r")
		     (match_operand:V4HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pm4addasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmqacc_w_h01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmqacc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmqracc_w_h01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmqracc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqacc_h01_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "mqacc.h01\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_mqacc_w01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "mqacc.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqracc_h01_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "mqracc.h01\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_mqracc_w01_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "mqracc.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Cross-Lane Packed Add/Sub Intrinsics
(define_insn "riscv_pas_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pas_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pas.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psa_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "psa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psa_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "psa.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psas_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "psas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_psas_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "psas.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssa_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pssa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pssa_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pssa.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paas_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "paas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_paas_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "paas.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasa_hx_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand"              "=r")
	(unspec:VHI [(match_operand:VHI 1 "register_operand"   " r")
		     (match_operand:VHI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
  "TARGET_RVP"
  "pasa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pasa_wx_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pasa.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Comparison and Min/Max Intrinsics
(define_insn "riscv_mseq_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mseq\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmseq_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pmseq.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_mslt_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mslt\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmslt_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pmslt.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_msltu_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "msltu\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmsltu_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pmsltu.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_pmin_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pmin.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_pminu_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pminu.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_pmax_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pmax.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

(define_insn "riscv_pmaxu_<SUFFIX>_<VQIHISI:mode>_p"
  [(set (match_operand:VQIHISI 0 "register_operand"                  "=r")
	(us_minus:VQIHISI (match_operand:VQIHISI 1 "register_operand" " r")
			(match_operand:VQIHISI 2 "register_operand" " r")))]
  "TARGET_RVP"
  "pmaxu.<SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<VQIHISI:MODE>")])

;Packed High-half Multiply and Accumulate Intrinsics
(define_insn "riscv_pmulh_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulh.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

;pmulh_w=smmul
(define_insn "riscv_pmulh_w_p"
  [(set (match_operand:SI 0 "register_operand"                       "=r")
	(truncate:SI
	  (lshiftrt:DI
	    (mult:DI
	      (sign_extend:DI (match_operand:SI 1 "register_operand" " r"))
	      (sign_extend:DI (match_operand:SI 2 "register_operand" " r")))
	    (const_int 32))))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmulh.w\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "HI")])

(define_insn "riscv_pmulh_h_b0_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulh.h_b0\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulh_w_h0_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulh.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulh_h_b1_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulh.h_b1\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulh_w_h1_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulh.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhu_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhr_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhr.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhr_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhr.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhru_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhru.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhru_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhru.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhsu_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_h_b0_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhsu.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhsu_w_h0_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhsu.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_h_b1_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhsu.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhsu_w_h1_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhsu.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhrsu_h_<mode>_p"
  [(set (match_operand:VHI 0 "register_operand" "=r")
        (unspec:VHI [(match_operand:VHI 1 "register_operand" "r")
                    (match_operand:VHI 2 "register_operand" "r")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
  "pmulhrsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "<MODE>")])

(define_insn "riscv_pmulhrsu_w_p"
  [(set (match_operand:V2SI 0 "register_operand"              "=r")
	(unspec:V2SI [(match_operand:V2SI 1 "register_operand"   " r")
		     (match_operand:V2SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && TARGET_64BIT"
 "pmulhrsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulh_h1_p"
  [(set (match_operand:V2HI 0 "register_operand"              "=r")
	(unspec:V2HI [(match_operand:V2HI 1 "register_operand"   " r")
		     (match_operand:V2HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulh.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhr_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulhr\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhru_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulhru\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulh_h0_p"
  [(set (match_operand:V2HI 0 "register_operand"              "=r")
	(unspec:V2HI [(match_operand:V2HI 1 "register_operand"   " r")
		     (match_operand:V2HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulh.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhsu_h0_p"
  [(set (match_operand:V2HI 0 "register_operand"              "=r")
	(unspec:V2HI [(match_operand:V2HI 1 "register_operand"   " r")
		     (match_operand:V2HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulhsu.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhsu_h1_p"
  [(set (match_operand:V2HI 0 "register_operand"              "=r")
	(unspec:V2HI [(match_operand:V2HI 1 "register_operand"   " r")
		     (match_operand:V2HI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulhsu.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhrsu_p"
  [(set (match_operand:SI 0 "register_operand"              "=r")
	(unspec:SI [(match_operand:SI 1 "register_operand"   " r")
		     (match_operand:SI 2 "register_operand" " r")] UNSPEC_PM2ADD))]
 "TARGET_RVP && !TARGET_64BIT"
 "mulhrsu\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Register-pair Packed-SIMD Intrinsics(RV32 Only)
;Packed Immediate Load Intrinsics
(define_insn "riscv_pli_db_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:SI 1 "immediate_operand" "i")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pli.db\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_pli_dh_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:SI 1 "immediate_operand" "i")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pli.dh\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "V2SI")])

(define_insn "riscv_plui_dh_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:SI 1 "immediate_operand" "i")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "plui.dh\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Word-Pair Shift and Shift-Add Intrinsics
(define_insn "riscv_pwslli_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwslli.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwslli_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwslli.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wslli_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wslli\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwslai_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwslai.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwslai_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwslai.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wslai_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wslai\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwsll_bs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsll.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwsll_hs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsll.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wsll_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wsll\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwsla_bs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsla.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwsla_hs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsla.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wsla_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wsla\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Word-Pair Interleave Intrinsics
(define_insn "riscv_wzip8p_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wzip16p_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Word-Pair Arithmetic Intrinsics
(define_insn "riscv_pwadd_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadd.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwadd_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wadd_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wadd\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwadda_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadda.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwadda_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadda.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_wadda_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "wadda\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwaddu_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddu.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwaddu_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_waddu_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "waddu\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwaddau_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddau.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pwaddau_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddau.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_waddau_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "waddau\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Word-Pair Predicated Summation Intrinsics
(define_insn "riscv_predsum_dbs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsum.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_predsum_dhs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsum.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_predsumu_dbs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsumu.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_predsumu_dhs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsumu.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;Packed Narrow shift right logical Intrinsics
(define_insn "riscv_pnsrli_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnsrli_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nsrli_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nsrli\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;Packed Narrow Clip Unsigned Intrinsics
(define_insn "riscv_pnclipiu_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipiu.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipiu_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipiu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipiu_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipiu\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipriu_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipriu.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipriu_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipriu.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipriu_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipriu\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;Packed Narrow Shift Right Arithmetic Intrinsics
(define_insn "riscv_pnsrai_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrai.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnsrai_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrai.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nsrai_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nsrai\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnsrari_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrari.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnsrari_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrari.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nsrari_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nsrari\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;Packed Narrow Clip Intrinsics
(define_insn "riscv_pnclipi_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipi.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipi_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipi.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipi_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipi\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipri_b_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipri.b\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipri_h_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipri.h\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipri_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipri\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipu_bs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipu.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipu_hs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipu.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipu_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipu\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipru_bs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipru.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipru_hs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipru.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipru_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipru\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclip_bs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclip.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclip_hs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclip.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclip_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclip\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipr_bs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipr.bs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_pnclipr_hs_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnclipr.hs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_nclipr_p"
  [(set (match_operand:SI          0 "register_operand" "=r")
	(unspec:SI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "nclipr\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

;Packed Shift and Arithmetic Intrinsics(Register-Pair Variant)
(define_insn "riscv_pslli_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pslli_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pslli_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psll_dbs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psll.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psll_dhs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psll.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psll_dws_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psll.dws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psslai_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psslai.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psslai_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "immediate_operand" "i")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psslai.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pssha_dhs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssha.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pssha_dws_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssha.dws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psshar_dhs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshar.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psshar_dws_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshar.dws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psrl_dbs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psrl.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psrl_dhs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psrl.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psrl_dws_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psrl.dws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psra_dbs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psra.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psra_dhs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psra.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psra_dws_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psra.dws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Sign-Extension Intrinsics (Register-Pair Variant)
(define_insn "riscv_psext_dh_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dh.b\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psext_dw_b_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dw.b\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psext_dw_h_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dw.h\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Absolute and Addition Intrinsics (Register-Pair Variant)
(define_insn "riscv_psabs_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psabs.db\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psabs_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psabs.dh\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_padd_dbs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_padd_dhs_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_padd_dws_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dws\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Register-Pair Packed Arithmetic Intrinsics
(define_insn "riscv_padd_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_padd_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_padd_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;; add64=addd
(define_insn "riscv_addd_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "addd\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psadd_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psadd.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psadd_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psadd.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psadd_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psadd.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paadd_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "paadd.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paadd_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "paadd.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paadd_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "paadd.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psaddu_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psaddu.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psaddu_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psaddu.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psaddu_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psaddu.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paaddu_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "paaddu.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paaddu_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "paaddu.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paaddu_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(plus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "paaddu.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psub_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(minus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psub.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psub_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(minus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psub.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psub_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(minus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "psub.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_subd_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(minus:DI (match_operand:DI 1 "register_operand" " r")
		 (match_operand:DI 2 "register_operand" " r")))]
  "TARGET_RVP && !TARGET_64BIT"
  "subd\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Register-Pair Packed Pack/Unpack Intrinsics
(define_insn "riscv_ppack_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppack.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppack_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppack.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppackbt_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppackbt.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppackbt_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppackbt.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppacktb_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppacktb.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppacktb_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppacktb.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppackt_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppackt.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_ppackt_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppackt.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Register-Pair Saturating & Accumulating Add/Sub Intrinsics
(define_insn "riscv_pas_dhx_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pas.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psa_dhx_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psa.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_psas_dhx_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psas.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pssa_dhx_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssa.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_paas_dhx_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "paas.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pasa_dhx_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pasa.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Register-Pair Comparison Intrinsics
(define_insn "riscv_pmseq_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmseq.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmseq_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmseq.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmseq_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmseq.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmslt_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmslt.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmslt_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmslt.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmslt_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmslt.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmsltu_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmsltu.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmsltu_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmsltu.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmsltu_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmsltu.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

;Packed Register-Pair Min/Max Intrinsics
(define_insn "riscv_pmin_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmin.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmin_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmin.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmin_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmin.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pminu_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pminu.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pminu_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pminu.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pminu_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pminu.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmax_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmax.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmax_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmax.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmax_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmax.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmaxu_db_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmaxu.db\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmaxu_dh_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmaxu.dh\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_pmaxu_dw_p"
  [(set (match_operand:DI          0 "register_operand" "=r")
	(unspec:DI [(match_operand:DI 1 "register_operand" "r")
		       (match_operand:DI 2 "register_operand" " r")] UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmaxu.dw\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])


