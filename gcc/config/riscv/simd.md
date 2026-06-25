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
  UNSPEC_CLS
  UNSPEC_REV
  UNSPEC_REV16
  UNSPEC_UNZIP8P
  ;; Bitmanip scalar intrinsics (manual "Bitmanip" section).
  UNSPEC_SLX
  UNSPEC_SRX
  UNSPEC_ZIP8P
  UNSPEC_ZIP16P
  UNSPEC_ZIP8HP
  UNSPEC_ZIP16HP
  UNSPEC_UNZIP16P
  UNSPEC_UNZIP8HP
  UNSPEC_UNZIP16HP
  UNSPEC_WZIP8P
  UNSPEC_WZIP16P
  UNSPEC_PSLLI
  UNSPEC_PSSLAI
  UNSPEC_SSLAI
  UNSPEC_PLI
  UNSPEC_PSEXT_B
  UNSPEC_PSEXT_H
  UNSPEC_PZEXT
  UNSPEC_PLUI
  UNSPEC_PSLL
  UNSPEC_PADD
  UNSPEC_PSUB
  UNSPEC_PMIN
  UNSPEC_PMAX
  UNSPEC_PMINU
  UNSPEC_PMAXU
  UNSPEC_PMSEQ
  UNSPEC_PMSLT
  UNSPEC_PMSGT
  UNSPEC_PMSLTU
  UNSPEC_PMSGTU
  UNSPEC_PREDSUM
  UNSPEC_PREDSUMU
  UNSPEC_PMERGE
  UNSPEC_PSSHA
  UNSPEC_PSSHAR
  UNSPEC_PSSHL
  UNSPEC_PSSHLR
  UNSPEC_PSRL
  UNSPEC_PSRLI
  UNSPEC_PUSATI
  UNSPEC_PSABS
  UNSPEC_PABD
  UNSPEC_PABDU
  UNSPEC_PSRAI
  UNSPEC_PSATI
  UNSPEC_SATI
  UNSPEC_PSRA
  UNSPEC_PDIFSUMU
  UNSPEC_PDIFSUMAU
  UNSPEC_PMUL
  UNSPEC_PPACK
  UNSPEC_PPAIRE
  UNSPEC_PPAIREO
  UNSPEC_PPAIROE
  UNSPEC_PPAIRO
  UNSPEC_PM2ADD
  UNSPEC_PMULH
  UNSPEC_PMULHR
  UNSPEC_PMULHU
  UNSPEC_PMULHRU
  UNSPEC_PMULHSU
  UNSPEC_PMULHRSU
  UNSPEC_PMHACC
  UNSPEC_PMHRACC
  UNSPEC_PMHACCU
  UNSPEC_PMHRACCU
  UNSPEC_PMHACCSU
  UNSPEC_PMHRACCSU
  UNSPEC_PMULQ
  UNSPEC_PMULQR
  UNSPEC_PMQACC_H00
  UNSPEC_PMQACC_H01
  UNSPEC_PMQACC_H11
  UNSPEC_PMQRACC_H00
  UNSPEC_PMQRACC_H01
  UNSPEC_PMQRACC_H11
  UNSPEC_PMQACC_W00
  UNSPEC_PMQACC_W01
  UNSPEC_PMQACC_W11
  UNSPEC_PMQRACC_W00
  UNSPEC_PMQRACC_W01
  UNSPEC_PMQRACC_W11
  UNSPEC_PMUL_B00
  UNSPEC_PMUL_B01
  UNSPEC_PMUL_B11
  UNSPEC_PMULU_B00
  UNSPEC_PMULU_B01
  UNSPEC_PMULU_B11
  UNSPEC_PMULSU_B00
  UNSPEC_PMULSU_B11
  UNSPEC_PMUL_H00
  UNSPEC_PMUL_H01
  UNSPEC_PMUL_H11
  UNSPEC_PMULU_H00
  UNSPEC_PMULU_H01
  UNSPEC_PMULU_H11
  UNSPEC_PMULSU_H00
  UNSPEC_PMULSU_H11
  UNSPEC_PMUL_W00
  UNSPEC_PMUL_W01
  UNSPEC_PMUL_W11
  UNSPEC_PMULU_W00
  UNSPEC_PMULU_W01
  UNSPEC_PMULU_W11
  UNSPEC_PMULSU_W00
  UNSPEC_PMULSU_W11
  UNSPEC_MACC_H00
  UNSPEC_MACC_H01
  UNSPEC_MACC_H11
  UNSPEC_MACCU_H00
  UNSPEC_MACCU_H01
  UNSPEC_MACCU_H11
  UNSPEC_MACCSU_H00
  UNSPEC_MACCSU_H11
  UNSPEC_PMACC_H00
  UNSPEC_PMACC_H01
  UNSPEC_PMACC_H11
  UNSPEC_PMACCU_H00
  UNSPEC_PMACCU_H01
  UNSPEC_PMACCU_H11
  UNSPEC_PMACCSU_H00
  UNSPEC_PMACCSU_H11
  UNSPEC_MACC_W00
  UNSPEC_MACC_W01
  UNSPEC_MACC_W11
  UNSPEC_MACCU_W00
  UNSPEC_MACCU_W01
  UNSPEC_MACCU_W11
  UNSPEC_MACCSU_W00
  UNSPEC_MACCSU_W11
  UNSPEC_PM4ADD_B
  UNSPEC_PM2ADD_H
  UNSPEC_PM2ADD_HX
  UNSPEC_PM4ADDU_B
  UNSPEC_PM2ADDU_H
  UNSPEC_PMQ2ADD_H
  UNSPEC_PMQR2ADD_H
  UNSPEC_PM2SADD_H
  UNSPEC_PM2SADD_HX
  UNSPEC_PM2SUB_H
  UNSPEC_PM2SUB_HX
  UNSPEC_PM4ADDSU_B
  UNSPEC_PM2ADDSU_H
  UNSPEC_PM4ADD_I8X8
  UNSPEC_PM2ADD_I16X4
  UNSPEC_PM2ADD_X_I16X4
  UNSPEC_PM4ADDU_U8X8
  UNSPEC_PM2ADDU_U16X4
  UNSPEC_PMQ2ADD_I16X4
  UNSPEC_PMQR2ADD_I16X4
  UNSPEC_PM2SADD_I16X4
  UNSPEC_PM2SADD_X_I16X4
  UNSPEC_PM2SUB_I16X4
  UNSPEC_PM2SUB_X_I16X4
  UNSPEC_PM4ADDSU_I8X8
  UNSPEC_PM2ADDSU_I16X4
  UNSPEC_PM2ADD_W
  UNSPEC_PM2ADD_WX
  UNSPEC_PM2ADDU_W
  UNSPEC_PMQ2ADD_W
  UNSPEC_PM2SUB_W
  UNSPEC_PM2SUB_WX
  UNSPEC_PM2ADDSU_W
  UNSPEC_PMQR2ADD_W
  UNSPEC_PM4ADD_H
  UNSPEC_PM4ADDU_H
  UNSPEC_PM4ADDSU_H
  UNSPEC_PM4ADDA_B
  UNSPEC_PM2ADDA_H
  UNSPEC_PM2ADDA_HX
  UNSPEC_PM4ADDAU_B
  UNSPEC_PM2ADDAU_H
  UNSPEC_PMQ2ADDA_H
  UNSPEC_PMQR2ADDA_H
  UNSPEC_PM2SUBA_H
  UNSPEC_PM2SUBA_HX
  UNSPEC_PM4ADDASU_B
  UNSPEC_PM2ADDASU_H
  UNSPEC_PM4ADDA_I8X8
  UNSPEC_PM2ADDA_I16X4
  UNSPEC_PM2ADDA_X_I16X4
  UNSPEC_PM4ADDAU_U8X8
  UNSPEC_PM2ADDAU_U16X4
  UNSPEC_PMQ2ADDA_I16X4
  UNSPEC_PMQR2ADDA_I16X4
  UNSPEC_PM2SUBA_I16X4
  UNSPEC_PM2SUBA_X_I16X4
  UNSPEC_PM4ADDASU_I8X8
  UNSPEC_PM2ADDASU_I16X4
  UNSPEC_PM2ADDA_W
  UNSPEC_PM2ADDA_WX
  UNSPEC_PM2ADDAU_W
  UNSPEC_PMQ2ADDA_W
  UNSPEC_PM2SUBA_W
  UNSPEC_PM2SUBA_WX
  UNSPEC_PM2ADDASU_W
  UNSPEC_PMQR2ADDA_W
  UNSPEC_PM4ADDA_H
  UNSPEC_PM4ADDAU_H
  UNSPEC_PM4ADDASU_H
  UNSPEC_PMULH_B0
  UNSPEC_PMULH_B1
  UNSPEC_PMULHSU_B0
  UNSPEC_PMULHSU_B1
  UNSPEC_MULH_H0
  UNSPEC_MULH_H1
  UNSPEC_MULHSU_H0
  UNSPEC_MULHSU_H1
  UNSPEC_PMHACC_B0
  UNSPEC_PMHACC_B1
  UNSPEC_PMHACCSU_B0
  UNSPEC_PMHACCSU_B1
  UNSPEC_MHACC_H0
  UNSPEC_MHACC_H1
  UNSPEC_MHACCSU_H0
  UNSPEC_MHACCSU_H1
  UNSPEC_PWMUL_B
  UNSPEC_PWMUL_H
  UNSPEC_PWMULU_B
  UNSPEC_PWMULU_H
  UNSPEC_PWMULSU_B
  UNSPEC_PWMULSU_H
  UNSPEC_PWMACC_H
  UNSPEC_PWMACCU_H
  UNSPEC_PWMACCSU_H
  UNSPEC_PMQWACC_H
  UNSPEC_PMQRWACC_H
  UNSPEC_PM2WADD_H
  UNSPEC_PM2WADD_HX
  UNSPEC_PM2WADDU_H
  UNSPEC_PM2WSUB_H
  UNSPEC_PM2WSUB_HX
  UNSPEC_PM2WADDSU_H
  UNSPEC_PM2WADDA_H
  UNSPEC_PM2WADDA_HX
  UNSPEC_PM2WADDAU_H
  UNSPEC_PM2WSUBA_H
  UNSPEC_PM2WSUBA_HX
  UNSPEC_PM2WADDASU_H
  UNSPEC_PSA
  UNSPEC_PAS
  UNSPEC_PSAS
  UNSPEC_PSSA
  UNSPEC_PAAS
  UNSPEC_PASA
  UNSPEC_PSADD
  UNSPEC_PSSUB
  UNSPEC_PSADDU
  UNSPEC_PSSUBU
  UNSPEC_PAADD
  UNSPEC_PASUB
  UNSPEC_PAADDU
  UNSPEC_PASUBU
  UNSPEC_PSH1ADD
  UNSPEC_PSSH1SADD
  UNSPEC_PWCVT_B
  UNSPEC_PWCVT_H
  UNSPEC_PWCVTU_B
  UNSPEC_PWCVTU_H
  UNSPEC_PWCVTH_B
  UNSPEC_PWCVTH_H
  UNSPEC_PNCVT_B
  UNSPEC_PNCVT_H
  UNSPEC_PNCVTH_B
  UNSPEC_PNCVTH_H
  UNSPEC_PZIP_B
  UNSPEC_PZIP_H
  UNSPEC_PUNZIPE_B
  UNSPEC_PUNZIPE_H
  UNSPEC_PUNZIPO_B
  UNSPEC_PUNZIPO_H
  UNSPEC_PNZIP_B
  UNSPEC_PNZIP_H
  UNSPEC_PNZIPH_B
  UNSPEC_PNZIPH_H
  UNSPEC_PWUNZIPE
  UNSPEC_PWUNZIPO
  UNSPEC_PWUNZIPUE
  UNSPEC_PWUNZIPUO
  UNSPEC_PWUNZIPHE
  UNSPEC_PWUNZIPHO
  UNSPEC_PWADD_B
  UNSPEC_PWADD_H
  UNSPEC_PWADDU_B
  UNSPEC_PWADDU_H
  UNSPEC_PWSUB_B
  UNSPEC_PWSUB_H
  UNSPEC_PWSUBU_B
  UNSPEC_PWSUBU_H
  UNSPEC_PWADDA_B
  UNSPEC_PWADDA_H
  UNSPEC_PWADDAU_B
  UNSPEC_PWADDAU_H
  UNSPEC_PWSUBA_B
  UNSPEC_PWSUBA_H
  UNSPEC_PWSUBAU_B
  UNSPEC_PWSUBAU_H
  UNSPEC_PWSLL
  UNSPEC_PWSLA
  UNSPEC_PNSRL
  UNSPEC_PNSRA
  UNSPEC_PNSRAR
  UNSPEC_PNCLIPU
  UNSPEC_PNCLIPRU
  UNSPEC_PNCLIP
  UNSPEC_PNCLIPR
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
(define_mode_iterator SAT32 [(V4QI "true") (V2HI "true")])
(define_mode_iterator SAT64 [(V8QI "true") (V4HI "true") (V2SI "true")])
(define_mode_iterator SHADD32 [(V2HI "true")])
(define_mode_iterator SHADD64 [(V4HI "true") (V2SI "true")])
(define_mode_attr SAT_NAME [(V4QI "i8x4") (V2HI "i16x2")
                            (V8QI "i8x8") (V4HI "i16x4")
                            (V2SI "i32x2")])
(define_mode_attr USAT_NAME [(V4QI "u8x4") (V2HI "u16x2")
                             (V8QI "u8x8") (V4HI "u16x4")
                             (V2SI "u32x2")])
(define_mode_attr SAT_SUFFIX [(V4QI "b") (V2HI "h")
                              (V8QI "b") (V4HI "h") (V2SI "w")])
(define_mode_attr DSAT_SUFFIX [(V8QI "db") (V4HI "dh") (V2SI "dw")])
(define_mode_attr SSUFFIX [(V4QI "bs") (V2HI "hs")
                            (V8QI "bs") (V4HI "hs") (V2SI "ws")])
(define_mode_attr DSSUFFIX [(V8QI "dbs") (V4HI "dhs") (V2SI "dws")])
(define_mode_attr SCALAR_MODE [(V4QI "QI") (V2HI "HI")
                                (V8QI "QI") (V4HI "HI") (V2SI "SI")])
(define_mode_iterator ABD32 [(V4QI "true") (V2HI "true")])
(define_mode_iterator ABD64 [(V8QI "true") (V4HI "true")])
; 64-bit packed modes excluding V2SI (used by Packed Pair 8x8/16x4, where the
; 32x2 case is handled separately because its RV64 mnemonic is "pack"/ppaireo.w
; rather than ppaire.w, and its RV32 form is intentionally unsupported).
(define_mode_iterator PAIR64 [(V8QI "true") (V4HI "true")])
(define_mode_iterator PMERGE32 [(V4QI "true") (V2HI "true")])
(define_mode_iterator PMERGE64 [(V8QI "true") (V4HI "true") (V2SI "true")])
(define_mode_attr PMERGE_NAME [(V4QI "i8x4") (V2HI "i16x2")
                               (V8QI "i8x8") (V4HI "i16x4")
                               (V2SI "i32x2")])
(define_mode_attr UPMERGE_NAME [(V4QI "u8x4") (V2HI "u16x2")
                                (V8QI "u8x8") (V4HI "u16x4")
                                (V2SI "u32x2")])
; Packed Comparison: result is always unsigned.  Input signedness varies:
; pmseq/pmsne accept both (two intrinsic variants, same instruction);
; pmslt/pmsgt/pmsge/pmsle take signed inputs; pmsltu/pmsgtu/pmsgeu/pmsleu
; take unsigned inputs.  V4QI and UV4QI share the same machine mode, so the
; insns operate on the V*/UV* mode interchangeably; the builtin ftype carries
; the signedness of the inputs.
; Builtin/intrinsic naming: a suffix is added only to disambiguate.
; pmseq/pmsne are sign-agnostic, so the input signedness must be encoded
; explicitly (pmseq_i8x4_u8x4 signed in, pmseq_u8x4_u8x4 unsigned in).
; pmslt/pmsgt/pmsge/pmsle carry signedness in the opcode name (s = signed),
; and pmsltu/pmsgtu/pmsgeu/pmsleu in the opcode (u = unsigned), so the input
; signedness is unambiguous and only the (unsigned) result width is named,
; e.g. pmslt_u8x4 (signed in) and pmsltu_u8x4 (unsigned in).
(define_mode_attr PCMP_SNAME [(V4QI "i8x4_u8x4") (V2HI "i16x2_u16x2")
                              (V8QI "i8x8_u8x8") (V4HI "i16x4_u16x4")
                              (V2SI "i32x2_u32x2")])
(define_mode_attr PCMP_UNAME [(V4QI "u8x4_u8x4") (V2HI "u16x2_u16x2")
                              (V8QI "u8x8_u8x8") (V4HI "u16x4_u16x4")
                              (V2SI "u32x2_u32x2")])
(define_mode_attr PCMP_ONAME [(V4QI "u8x4") (V2HI "u16x2")
                              (V8QI "u8x8") (V4HI "u16x4")
                              (V2SI "u32x2")])

;; -----------------------------------------------------------------
;; Bitmanip scalar intrinsics (manual "Bitmanip" section, spec 48-133).
;; Suffixed names: cls_32/cls_64, rev_32/rev_64, rev16_64, slx_32/slx_64,
;; srx_32/srx_64, wzip8p_64/wzip16p_64, zip/unzip {8,16}{,h}p_64.
;; The XLEN-abstract __riscv_cls/__riscv_rev above remain as aliases.
;; -----------------------------------------------------------------

; cls_32: RV32 -> cls (32-bit CLS); RV64 -> clsw (32-bit CLS on low half).
(define_expand "riscv_cls_32_p"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")] UNSPEC_CLS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx tmp = gen_reg_rtx (DImode);
      emit_insn (gen_riscv_clsw_32_p (tmp, operands[1]));
      emit_move_insn (operands[0], gen_lowpart (SImode, tmp));
    }
  else
    emit_insn (gen_riscv_cls_32_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_cls_32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")] UNSPEC_CLS))]
  "TARGET_RVP && !TARGET_64BIT"
  "cls\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

; On RV64 clsw writes an XLEN (64-bit) result; truncate to the SI result the
; prototype promises.
(define_insn "riscv_clsw_32_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (sign_extend:DI
          (unspec:SI [(match_operand:SI 1 "register_operand" "r")] UNSPEC_CLS)))]
  "TARGET_RVP && TARGET_64BIT"
  "clsw\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

; cls_64 (RV64 only): full 64-bit CLS, result is a small unsigned count;
; the prototype returns `unsigned`, but exposing it as DI matches the
; existing riscv_cls<mode>_p form and the count fits in 32 bits.
(define_insn "riscv_cls_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_CLS))]
  "TARGET_RVP && TARGET_64BIT"
  "cls\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

; rev_32: RV32 -> rev (bit-reverse 32 bits in a 32-bit reg);
; RV64 -> rev (reverse all 64 bits) then srai 32 to bring the 32-bit
; reversed result (which lands in bits 63..32) back to the low half.
(define_expand "riscv_rev_32_p"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")] UNSPEC_REV))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx tmp = gen_reg_rtx (DImode);
      emit_insn (gen_riscv_rev_32_rv64 (tmp, operands[1]));
      emit_move_insn (operands[0], gen_lowpart (SImode, tmp));
    }
  else
    emit_insn (gen_riscv_rev_32_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_rev_32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")] UNSPEC_REV))]
  "TARGET_RVP && !TARGET_64BIT"
  "rev\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

(define_insn "riscv_rev_32_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:SI 1 "register_operand" "r")] UNSPEC_REV))]
  "TARGET_RVP && TARGET_64BIT"
  "rev\t%0,%1\;srai\t%0,%0,32"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

; rev_64 / rev16_64 (RV64 only): single instruction on a 64-bit value.
(define_insn "riscv_rev_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_REV))]
  "TARGET_RVP && TARGET_64BIT"
  "rev\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

(define_insn "riscv_rev16_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")] UNSPEC_REV16))]
  "TARGET_RVP && TARGET_64BIT"
  "rev16\t%0,%1"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

; slx/srx are read-modify-write on rd (the first user argument): rd's prior
; value participates in the 2*XLEN concatenation.  Emit_move copies the user's
; rd into the target first, then the insn reuses that register via match_dup 0.

; slx_32: RV32 -> slx (32-bit); RV64 -> andi+slli+slx sequence (manual).
; RV64 sequence: the 32-bit pair (rd@rs1) must occupy the high halves of two
; 64-bit registers so the 64-bit slx picks the 32-bit result from bits 63..32.
;   slli  rd, rd, 32      ; rd's 32 bits -> bits 63..32
;   andi  t,  rs1, 0xff..  ; keep only rs1's low 32 bits
;   slli  t,  t, 32        ; rs1's 32 bits -> bits 63..32
;   slx   rd, t,  rs2      ; (rd@t)<<shamt, high 32 bits land in bits 63..32
;   srli  rd, rd, 32       ; bring result back to low 32 bits
(define_expand "riscv_slx_32_p"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")
                    (match_operand:SI 3 "register_operand")] UNSPEC_SLX))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx rd = gen_reg_rtx (DImode);
      rtx rs1 = gen_reg_rtx (DImode);
      emit_insn (gen_ashldi3 (rd, gen_lowpart (DImode, operands[0]),
			      GEN_INT (32)));
      rtx t = gen_reg_rtx (DImode);
      emit_insn (gen_anddi3 (t, gen_lowpart (DImode, operands[2]),
			     GEN_INT (0xFFFFFFFF)));
      emit_insn (gen_ashldi3 (rs1, t, GEN_INT (32)));
      emit_insn (gen_riscv_slx_64_raw (rd, rs1,
				       gen_lowpart (DImode, operands[3])));
      emit_insn (gen_lshrdi3 (rd, rd, GEN_INT (32)));
      emit_move_insn (operands[0], gen_lowpart (SImode, rd));
    }
  else
    emit_insn (gen_riscv_slx_32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_slx_32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")] UNSPEC_SLX))]
  "TARGET_RVP && !TARGET_64BIT"
  "slx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

; slx_64 (RV64 only): single 64-bit RMW insn.
(define_expand "riscv_slx_64_p"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:DI 2 "register_operand")
                    (match_operand:SI 3 "register_operand")] UNSPEC_SLX))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_slx_64_raw (operands[0], operands[2],
				   gen_lowpart (DImode, operands[3])));
  DONE;
})

(define_insn "riscv_slx_64_raw"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_SLX))]
  "TARGET_RVP && TARGET_64BIT"
  "slx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

; srx_32: RV32 -> srx (32-bit); RV64 -> ori+slli+srx sequence (manual).
; RV64 sequence mirrors slx_32 with srx/srli:
;   slli  rd, rd, 32        ; rd's 32 bits -> bits 63..32  (rs1@rd concat high)
;   andi  t,  rs1, 0xff..   ; but srx concatenates rs1@rd, so rs1 is the high
;   slli  t,  t, 32         ; half too
;   srx   rd, t,  rs2       ; (t@rd)>>shamt, low 32 bits land in bits 31..0
;   (no final shift needed: srx writes low XLEN bits)
(define_expand "riscv_srx_32_p"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")
                    (match_operand:SI 3 "register_operand")] UNSPEC_SRX))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx rd = gen_reg_rtx (DImode);
      rtx t = gen_reg_rtx (DImode);
      emit_insn (gen_ashldi3 (rd, gen_lowpart (DImode, operands[0]),
			      GEN_INT (32)));
      emit_insn (gen_anddi3 (t, gen_lowpart (DImode, operands[2]),
			     GEN_INT (0xFFFFFFFF)));
      emit_insn (gen_ashldi3 (t, t, GEN_INT (32)));
      emit_insn (gen_riscv_srx_64_raw (rd, t,
				       gen_lowpart (DImode, operands[3])));
      emit_move_insn (operands[0], gen_lowpart (SImode, rd));
    }
  else
    emit_insn (gen_riscv_srx_32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_srx_32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")] UNSPEC_SRX))]
  "TARGET_RVP && !TARGET_64BIT"
  "srx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "SI")])

; srx_64 (RV64 only): single 64-bit RMW insn.
(define_expand "riscv_srx_64_p"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:DI 2 "register_operand")
                    (match_operand:SI 3 "register_operand")] UNSPEC_SRX))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_srx_64_raw (operands[0], operands[2],
				   gen_lowpart (DImode, operands[3])));
  DONE;
})

(define_insn "riscv_srx_64_raw"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_SRX))]
  "TARGET_RVP && TARGET_64BIT"
  "srx\t%0,%1,%2"
  [(set_attr "type" "simd")
   (set_attr "mode" "DI")])

; wzip8p_64 / wzip16p_64: take two 32-bit sources, produce a 64-bit result.
; RV32 -> wzip8p/wzip16p into an even-odd register pair (=R);
; RV64 -> zip8p/zip16p into a single 64-bit register.
(define_expand "riscv_wzip8p_64_p"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")] UNSPEC_WZIP8P))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_wzip8p_64_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_wzip8p_64_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_wzip8p_64_rv32"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")] UNSPEC_WZIP8P))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_wzip8p_64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")] UNSPEC_WZIP8P))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_wzip16p_64_p"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")] UNSPEC_WZIP16P))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_wzip16p_64_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_wzip16p_64_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_wzip16p_64_rv32"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")] UNSPEC_WZIP16P))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_wzip16p_64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")] UNSPEC_WZIP16P))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

; zip/unzip {8,16}{,h}p_64 (RV64 only): single 64-bit insns, two 64-bit sources.
(define_insn "riscv_zip8p_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_ZIP8P))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip16p_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_ZIP16P))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip8hp_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_ZIP8HP))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_zip16hp_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_ZIP16HP))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip8p_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_UNZIP8P))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip16p_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_UNZIP16P))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip8hp_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_UNZIP8HP))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_unzip16hp_64_p"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:DI 1 "register_operand" "r")
                    (match_operand:DI 2 "register_operand" "r")] UNSPEC_UNZIP16HP))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16hp\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Splat
(define_insn "riscv_pmv_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP"
  "@
   pmv.bs\t%0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP"
  "@
   pmv.bs\t%0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP"
  "@
   pmv.hs\t%0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP"
  "@
   pmv.hs\t%0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_u8x8_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_u8x8_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pmv.dbs\t%0,%1
   pli.db\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pmv.bs\t%0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_pmv_s_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_i8x8_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_i8x8_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pmv.dbs\t%0,%1
   pli.db\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pmv_s_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:QI 1 "nonmemory_operand" "r, Wpb")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pmv.bs\t%0,%1
   pli.b\t%0,%1"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_pmv_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_u16x4_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_u16x4_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pmv.dhs\t%0,%1
   pli.dh\t%0,%1
   plui.dh\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r, r")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pmv.hs\t%0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_i16x4_rv64 (operands[0], operands[1]));
  } else {
    emit_insn (gen_riscv_pmv_s_i16x4_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pmv.dhs\t%0,%1
   pli.dh\t%0,%1
   plui.dh\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pmv_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r, r")
        (unspec:V4HI [(match_operand:HI 1 "nonmemory_operand" "r, Wpi, Wpu")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pmv.hs\t%0,%1
   pli.h\t%0,%1
   plui.h\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_u32x2_rv64 (operands[0], operands[1]));
  } else {
    if (!register_operand (operands[1], SImode))
      operands[1] = force_reg (SImode, operands[1]);
    emit_insn (gen_riscv_pmv_s_u32x2_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:SI 1 "register_operand" "r")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmv.dws\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmv_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r, r")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand" "r, Wpi, Wpw")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pmv.ws\t%0,%1
   pli.w\t%0,%1
   plui.w\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pmv_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand")]
         UNSPEC_PLI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pmv_s_i32x2_rv64 (operands[0], operands[1]));
  } else {
    if (!register_operand (operands[1], SImode))
      operands[1] = force_reg (SImode, operands[1]);
    emit_insn (gen_riscv_pmv_s_i32x2_rv32 (operands[0], operands[1]));
  }
  DONE;
})

(define_insn "riscv_pmv_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:SI 1 "register_operand" "r")]
         UNSPEC_PLI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmv.dws\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmv_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r, r")
        (unspec:V2SI [(match_operand:SI 1 "nonmemory_operand" "r, Wpi, Wpw")]
         UNSPEC_PLI))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pmv.ws\t%0,%1
   pli.w\t%0,%1
   plui.w\t%0,%1"
  [(set_attr "type" "simd, simd, simd")])

;Packed Addition and Subtraction (32-bit)
(define_insn "riscv_padd_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP"
  "padd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_padd_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP"
  "padd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Addition and Subtraction (64-bit)
(define_expand "riscv_padd_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_padd_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_padd_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_padd_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_padd_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && TARGET_64BIT"
  "padd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_padd_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_padd_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_padd_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_padd_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_padd_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && TARGET_64BIT"
  "padd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psub_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP"
  "psub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psub_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP"
  "psub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; Packed Subtraction (64-bit)
(define_expand "riscv_psub_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PSUB))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psub_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psub_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psub_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP && !TARGET_64BIT"
  "psub.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psub_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP && TARGET_64BIT"
  "psub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psub_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PSUB))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psub_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psub_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psub_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP && !TARGET_64BIT"
  "psub.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psub_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP && TARGET_64BIT"
  "psub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pneg_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP"
  "pneg.<SAT_SUFFIX>\t%0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_pneg_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")]
         UNSPEC_PSUB))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pneg_<SAT_NAME>_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pneg_<SAT_NAME>_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pneg_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP && !TARGET_64BIT"
  "pneg.<DSAT_SUFFIX>\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pneg_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")]
         UNSPEC_PSUB))]
  "TARGET_RVP && TARGET_64BIT"
  "pneg.<SAT_SUFFIX>\t%0,%1"
  [(set_attr "type" "simd")])

; Packed Addition with Scalar (32-bit)
(define_insn "riscv_padd_s_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP"
  "padd.<SSUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_padd_s_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP"
  "padd.<SSUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; Packed Addition with Scalar (64-bit)
(define_expand "riscv_padd_s_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand")]
         UNSPEC_PADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_padd_s_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_padd_s_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_padd_s_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.<DSSUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_padd_s_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && TARGET_64BIT"
  "padd.<SSUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_padd_s_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand")]
         UNSPEC_PADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_padd_s_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_padd_s_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_padd_s_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "padd.<DSSUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_padd_s_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:<SCALAR_MODE> 2 "nonmemory_operand" "r")]
         UNSPEC_PADD))]
  "TARGET_RVP && TARGET_64BIT"
  "padd.<SSUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Saturating Addition and Subtraction

(define_insn "riscv_psadd_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PSADD))]
  "TARGET_RVP"
  "psadd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psaddu_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PSADDU))]
  "TARGET_RVP"
  "psaddu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssub_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PSSUB))]
  "TARGET_RVP"
  "pssub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssubu_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PSSUBU))]
  "TARGET_RVP"
  "pssubu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psadd_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PSADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psadd_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psadd_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psadd_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "psadd.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psadd_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSADD))]
  "TARGET_RVP && TARGET_64BIT"
  "psadd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psaddu_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PSADDU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psaddu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psaddu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psaddu_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSADDU))]
  "TARGET_RVP && !TARGET_64BIT"
  "psaddu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psaddu_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSADDU))]
  "TARGET_RVP && TARGET_64BIT"
  "psaddu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pssub_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PSSUB))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pssub_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pssub_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pssub_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSSUB))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssub.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssub_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSSUB))]
  "TARGET_RVP && TARGET_64BIT"
  "pssub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pssubu_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PSSUBU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pssubu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pssubu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pssubu_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSSUBU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssubu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssubu_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PSSUBU))]
  "TARGET_RVP && TARGET_64BIT"
  "pssubu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Averaging Addition and Subtraction

(define_insn "riscv_paadd_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PAADD))]
  "TARGET_RVP"
  "paadd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paaddu_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PAADDU))]
  "TARGET_RVP"
  "paaddu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasub_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PASUB))]
  "TARGET_RVP"
  "pasub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasubu_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PASUBU))]
  "TARGET_RVP"
  "pasubu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_paadd_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PAADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_paadd_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_paadd_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_paadd_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PAADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "paadd.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paadd_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PAADD))]
  "TARGET_RVP && TARGET_64BIT"
  "paadd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_paaddu_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PAADDU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_paaddu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_paaddu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_paaddu_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PAADDU))]
  "TARGET_RVP && !TARGET_64BIT"
  "paaddu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paaddu_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PAADDU))]
  "TARGET_RVP && TARGET_64BIT"
  "paaddu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pasub_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PASUB))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pasub_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pasub_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pasub_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PASUB))]
  "TARGET_RVP && !TARGET_64BIT"
  "pasub.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasub_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PASUB))]
  "TARGET_RVP && TARGET_64BIT"
  "pasub.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pasubu_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PASUBU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pasubu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pasubu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pasubu_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PASUBU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pasubu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasubu_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PASUBU))]
  "TARGET_RVP && TARGET_64BIT"
  "pasubu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Shift-Add

(define_insn "riscv_psh1add_<SAT_NAME>"
  [(set (match_operand:SHADD32 0 "register_operand" "=r")
        (unspec:SHADD32 [(match_operand:SHADD32 1 "register_operand" "r")
                         (match_operand:SHADD32 2 "register_operand" "r")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP"
  "psh1add.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psh1add_<USAT_NAME>"
  [(set (match_operand:SHADD32 0 "register_operand" "=r")
        (unspec:SHADD32 [(match_operand:SHADD32 1 "register_operand" "r")
                         (match_operand:SHADD32 2 "register_operand" "r")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP"
  "psh1add.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssh1sadd_<SAT_NAME>"
  [(set (match_operand:SHADD32 0 "register_operand" "=r")
        (unspec:SHADD32 [(match_operand:SHADD32 1 "register_operand" "r")
                         (match_operand:SHADD32 2 "register_operand" "r")]
         UNSPEC_PSSH1SADD))]
  "TARGET_RVP"
  "pssh1sadd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psh1add_<SAT_NAME>"
  [(set (match_operand:SHADD64 0 "register_operand")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand")
                         (match_operand:SHADD64 2 "register_operand")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psh1add_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psh1add_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psh1add_<SAT_NAME>_rv32"
  [(set (match_operand:SHADD64 0 "register_operand" "=R")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand" "r")
                         (match_operand:SHADD64 2 "register_operand" "r")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "psh1add.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psh1add_<SAT_NAME>_rv64"
  [(set (match_operand:SHADD64 0 "register_operand" "=r")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand" "r")
                         (match_operand:SHADD64 2 "register_operand" "r")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP && TARGET_64BIT"
  "psh1add.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psh1add_<USAT_NAME>"
  [(set (match_operand:SHADD64 0 "register_operand")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand")
                         (match_operand:SHADD64 2 "register_operand")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psh1add_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psh1add_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psh1add_<USAT_NAME>_rv32"
  [(set (match_operand:SHADD64 0 "register_operand" "=R")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand" "r")
                         (match_operand:SHADD64 2 "register_operand" "r")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "psh1add.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psh1add_<USAT_NAME>_rv64"
  [(set (match_operand:SHADD64 0 "register_operand" "=r")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand" "r")
                         (match_operand:SHADD64 2 "register_operand" "r")]
         UNSPEC_PSH1ADD))]
  "TARGET_RVP && TARGET_64BIT"
  "psh1add.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pssh1sadd_<SAT_NAME>"
  [(set (match_operand:SHADD64 0 "register_operand")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand")
                         (match_operand:SHADD64 2 "register_operand")]
         UNSPEC_PSSH1SADD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pssh1sadd_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pssh1sadd_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pssh1sadd_<SAT_NAME>_rv32"
  [(set (match_operand:SHADD64 0 "register_operand" "=R")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand" "r")
                         (match_operand:SHADD64 2 "register_operand" "r")]
         UNSPEC_PSSH1SADD))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssh1sadd.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssh1sadd_<SAT_NAME>_rv64"
  [(set (match_operand:SHADD64 0 "register_operand" "=r")
        (unspec:SHADD64 [(match_operand:SHADD64 1 "register_operand" "r")
                         (match_operand:SHADD64 2 "register_operand" "r")]
         UNSPEC_PSSH1SADD))]
  "TARGET_RVP && TARGET_64BIT"
  "pssh1sadd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Exchanged Addition and Subtraction
;
; Each instruction performs a cross add/subtract on packed halfword or word
; pairs: within each 32-bit word, the even (lower) element of rs1 is combined
; with the odd (upper) element of rs2 and vice versa.  The six variants are:
;   pas  : even=sub, odd=add        (wrap)
;   psa  : even=add, odd=sub        (wrap)
;   psas : even=sat(sub), odd=sat(add)
;   pssa : even=sat(add), odd=sat(sub)
;   paas : even=(sub)>>1, odd=(add)>>1   (averaging)
;   pasa : even=(add)>>1, odd=(sub)>>1   (averaging)
;
; Suffixes: i16x2/i16x4(RV64) use .hx, i16x4(RV32) uses .dhx, i32x2(RV64) uses
; .wx.  On RV32 the i32x2 pas/psa variants have no cross-word instruction and
; are expanded to a pair of scalar add/sub instructions.

(define_insn "riscv_pas_x_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PAS))]
  "TARGET_RVP"
  "pas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psa_x_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PSA))]
  "TARGET_RVP"
  "psa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psas_x_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PSAS))]
  "TARGET_RVP"
  "psas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssa_x_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PSSA))]
  "TARGET_RVP"
  "pssa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paas_x_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PAAS))]
  "TARGET_RVP"
  "paas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasa_x_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PASA))]
  "TARGET_RVP"
  "pasa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pas_x_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PAS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pas_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pas_x_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pas_x_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PAS))]
  "TARGET_RVP && !TARGET_64BIT"
  "pas.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pas_x_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PAS))]
  "TARGET_RVP && TARGET_64BIT"
  "pas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psa_x_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PSA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psa_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psa_x_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psa_x_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PSA))]
  "TARGET_RVP && !TARGET_64BIT"
  "psa.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psa_x_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PSA))]
  "TARGET_RVP && TARGET_64BIT"
  "psa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psas_x_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PSAS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psas_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psas_x_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psas_x_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PSAS))]
  "TARGET_RVP && !TARGET_64BIT"
  "psas.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psas_x_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PSAS))]
  "TARGET_RVP && TARGET_64BIT"
  "psas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pssa_x_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PSSA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pssa_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pssa_x_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pssa_x_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PSSA))]
  "TARGET_RVP && !TARGET_64BIT"
  "pssa.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssa_x_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PSSA))]
  "TARGET_RVP && TARGET_64BIT"
  "pssa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_paas_x_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PAAS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_paas_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_paas_x_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_paas_x_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PAAS))]
  "TARGET_RVP && !TARGET_64BIT"
  "paas.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paas_x_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PAAS))]
  "TARGET_RVP && TARGET_64BIT"
  "paas.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pasa_x_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PASA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pasa_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pasa_x_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pasa_x_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PASA))]
  "TARGET_RVP && !TARGET_64BIT"
  "pasa.dhx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasa_x_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PASA))]
  "TARGET_RVP && TARGET_64BIT"
  "pasa.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pas_x_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PAS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pas_x_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      /* even = a_even - b_odd ; odd = a_odd + b_even  */
      machine_mode mode = GET_MODE (operands[0]);
      rtx out_lo = operand_subword (operands[0], 0, 1, mode);
      rtx out_hi = operand_subword (operands[0], 1, 1, mode);
      rtx a_lo = operand_subword_force (operands[1], 0, mode);
      rtx a_hi = operand_subword_force (operands[1], 1, mode);
      rtx b_lo = operand_subword_force (operands[2], 0, mode);
      rtx b_hi = operand_subword_force (operands[2], 1, mode);
      emit_insn (gen_subsi3 (out_lo, a_lo, b_hi));
      emit_insn (gen_addsi3 (out_hi, a_hi, b_lo));
    }
  DONE;
})

(define_insn "riscv_pas_x_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PAS))]
  "TARGET_RVP && TARGET_64BIT"
  "pas.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psa_x_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PSA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psa_x_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      /* even = a_even + b_odd ; odd = a_odd - b_even  */
      machine_mode mode = GET_MODE (operands[0]);
      rtx out_lo = operand_subword (operands[0], 0, 1, mode);
      rtx out_hi = operand_subword (operands[0], 1, 1, mode);
      rtx a_lo = operand_subword_force (operands[1], 0, mode);
      rtx a_hi = operand_subword_force (operands[1], 1, mode);
      rtx b_lo = operand_subword_force (operands[2], 0, mode);
      rtx b_hi = operand_subword_force (operands[2], 1, mode);
      emit_insn (gen_addsi3 (out_lo, a_lo, b_hi));
      emit_insn (gen_subsi3 (out_hi, a_hi, b_lo));
    }
  DONE;
})

(define_insn "riscv_psa_x_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSA))]
  "TARGET_RVP && TARGET_64BIT"
  "psa.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

; TODO: RV32 下i32x2 psas/pssa/paas/pasa需要标量sadd/ssub/aadd/asub，这些标量；
; intrinsic gcc 还没支持
(define_insn "riscv_psas_x_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSAS))]
  "TARGET_RVP && TARGET_64BIT"
  "psas.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pssa_x_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PSSA))]
  "TARGET_RVP && TARGET_64BIT"
  "pssa.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_paas_x_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PAAS))]
  "TARGET_RVP && TARGET_64BIT"
  "paas.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pasa_x_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PASA))]
  "TARGET_RVP && TARGET_64BIT"
  "pasa.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Absolute Value and Absolute Difference
;
; pabs is a pseudo-operation: pabs(rs1) = pabd(rs1, x0), so it is emitted as
; "pabd.<suffix> %0,%1,x0" per the P-ext proposal.
(define_insn "riscv_pabs_<SAT_NAME>"
  [(set (match_operand:ABD32 0 "register_operand" "=r")
        (unspec:ABD32 [(match_operand:ABD32 1 "register_operand" "r")]
         UNSPEC_PABD))]
  "TARGET_RVP"
  "pabd.<SAT_SUFFIX>\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pabd_<SAT_NAME>"
  [(set (match_operand:ABD32 0 "register_operand" "=r")
        (unspec:ABD32 [(match_operand:ABD32 1 "register_operand" "r")
                       (match_operand:ABD32 2 "register_operand" "r")]
         UNSPEC_PABD))]
  "TARGET_RVP"
  "pabd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pabdu_<USAT_NAME>"
  [(set (match_operand:ABD32 0 "register_operand" "=r")
        (unspec:ABD32 [(match_operand:ABD32 1 "register_operand" "r")
                       (match_operand:ABD32 2 "register_operand" "r")]
         UNSPEC_PABDU))]
  "TARGET_RVP"
  "pabdu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pabs_<SAT_NAME>"
  [(set (match_operand:ABD64 0 "register_operand")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand")]
         UNSPEC_PABD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pabs_<SAT_NAME>_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pabs_<SAT_NAME>_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pabs_<SAT_NAME>_rv32"
  [(set (match_operand:ABD64 0 "register_operand" "=R")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand" "r")]
         UNSPEC_PABD))]
  "TARGET_RVP && !TARGET_64BIT"
  "pabd.<DSAT_SUFFIX>\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pabs_<SAT_NAME>_rv64"
  [(set (match_operand:ABD64 0 "register_operand" "=r")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand" "r")]
         UNSPEC_PABD))]
  "TARGET_RVP && TARGET_64BIT"
  "pabd.<SAT_SUFFIX>\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_pabd_<SAT_NAME>"
  [(set (match_operand:ABD64 0 "register_operand")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand")
                       (match_operand:ABD64 2 "register_operand")]
         UNSPEC_PABD))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pabd_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pabd_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pabd_<SAT_NAME>_rv32"
  [(set (match_operand:ABD64 0 "register_operand" "=R")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand" "r")
                       (match_operand:ABD64 2 "register_operand" "r")]
         UNSPEC_PABD))]
  "TARGET_RVP && !TARGET_64BIT"
  "pabd.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pabd_<SAT_NAME>_rv64"
  [(set (match_operand:ABD64 0 "register_operand" "=r")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand" "r")
                       (match_operand:ABD64 2 "register_operand" "r")]
         UNSPEC_PABD))]
  "TARGET_RVP && TARGET_64BIT"
  "pabd.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pabdu_<USAT_NAME>"
  [(set (match_operand:ABD64 0 "register_operand")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand")
                       (match_operand:ABD64 2 "register_operand")]
         UNSPEC_PABDU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pabdu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pabdu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pabdu_<USAT_NAME>_rv32"
  [(set (match_operand:ABD64 0 "register_operand" "=R")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand" "r")
                       (match_operand:ABD64 2 "register_operand" "r")]
         UNSPEC_PABDU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pabdu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pabdu_<USAT_NAME>_rv64"
  [(set (match_operand:ABD64 0 "register_operand" "=r")
        (unspec:ABD64 [(match_operand:ABD64 1 "register_operand" "r")
                       (match_operand:ABD64 2 "register_operand" "r")]
         UNSPEC_PABDU))]
  "TARGET_RVP && TARGET_64BIT"
  "pabdu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; TODO(difficult): Packed Absolute Difference Sum

;Packed Saturating Absolute Value

(define_insn "riscv_psabs_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PSABS))]
  "TARGET_RVP"
  "psabs.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_psabs_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PSABS))]
  "TARGET_RVP"
  "psabs.h\t%0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_psabs_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PSABS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psabs_i8x8_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_psabs_i8x8_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_psabs_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PSABS))]
  "TARGET_RVP && !TARGET_64BIT"
  "psabs.db\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_psabs_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PSABS))]
  "TARGET_RVP && TARGET_64BIT"
  "psabs.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_psabs_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PSABS))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psabs_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_psabs_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_psabs_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PSABS))]
  "TARGET_RVP && !TARGET_64BIT"
  "psabs.dh\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_psabs_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PSABS))]
  "TARGET_RVP && TARGET_64BIT"
  "psabs.h\t%0,%1"
  [(set_attr "type" "simd")])

;Packed Reduction Sum

(define_expand "riscv_predsum_i8x4_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V4QI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx wide = gen_reg_rtx (DImode);
      rtx low = gen_lowpart (SImode, operands[1]);

      emit_insn (gen_zero_extendsidi2 (wide, low));
      emit_insn (gen_riscv_predsum_i8x8_i32_rv64
		   (operands[0], gen_lowpart (V8QImode, wide), operands[2]));
    }
  else
    emit_insn (gen_riscv_predsum_i8x4_i32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i8x4_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4QI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsum.bs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u8x4_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V4QI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx wide = gen_reg_rtx (DImode);
      rtx low = gen_lowpart (SImode, operands[1]);

      emit_insn (gen_zero_extendsidi2 (wide, low));
      emit_insn (gen_riscv_predsumu_u8x8_u32_rv64
		   (operands[0], gen_lowpart (V8QImode, wide), operands[2]));
    }
  else
    emit_insn (gen_riscv_predsumu_u8x4_u32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u8x4_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4QI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsumu.bs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsum_i16x2_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx wide = gen_reg_rtx (DImode);
      rtx low = gen_lowpart (SImode, operands[1]);

      emit_insn (gen_zero_extendsidi2 (wide, low));
      emit_insn (gen_riscv_predsum_i16x4_i32_rv64
		   (operands[0], gen_lowpart (V4HImode, wide), operands[2]));
    }
  else
    emit_insn (gen_riscv_predsum_i16x2_i32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i16x2_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsum.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u16x2_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx wide = gen_reg_rtx (DImode);
      rtx low = gen_lowpart (SImode, operands[1]);

      emit_insn (gen_zero_extendsidi2 (wide, low));
      emit_insn (gen_riscv_predsumu_u16x4_u32_rv64
		   (operands[0], gen_lowpart (V4HImode, wide), operands[2]));
    }
  else
    emit_insn (gen_riscv_predsumu_u16x2_u32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u16x2_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsumu.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsum_i8x8_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V8QI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_predsum_i8x8_i32_rv64
		 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_predsum_i8x8_i32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i8x8_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V8QI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsum.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u8x8_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V8QI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_predsumu_u8x8_u32_rv64
		 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_predsumu_u8x8_u32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u8x8_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V8QI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsumu.dbs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsum_i16x4_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V4HI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_predsum_i16x4_i32_rv64
		 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_predsum_i16x4_i32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i16x4_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4HI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsum.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u16x4_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V4HI 1 "register_operand")
                            (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_predsumu_u16x4_u32_rv64
		 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_predsumu_u16x4_u32_rv32
		 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u16x4_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4HI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && !TARGET_64BIT"
  "predsumu.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_predsum_i8x8_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V8QI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
  "predsum.bs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_predsumu_u8x8_u32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V8QI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "predsumu.bs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_predsum_i16x4_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4HI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
  "predsum.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_predsumu_u16x4_u32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4HI 1 "register_operand" "r")
                            (match_operand:SI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "predsumu.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

; TODO(difficult): RV32 i64 accumulate variants need wadda/waddau (unimplemented).
; These six i64 intrinsics are RV64-only for now.
(define_expand "riscv_predsum_i8x8_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V8QI 1 "register_operand")
                            (match_operand:DI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_predsum_i8x8_i64_rv64
	     (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i8x8_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V8QI 1 "register_operand" "r")
                            (match_operand:DI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
  "predsum.bs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u8x8_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V8QI 1 "register_operand")
                            (match_operand:DI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_predsumu_u8x8_u64_rv64
	     (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u8x8_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V8QI 1 "register_operand" "r")
                            (match_operand:DI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "predsumu.bs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsum_i16x4_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V4HI 1 "register_operand")
                            (match_operand:DI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_predsum_i16x4_i64_rv64
	     (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i16x4_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V4HI 1 "register_operand" "r")
                            (match_operand:DI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
  "predsum.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u16x4_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V4HI 1 "register_operand")
                            (match_operand:DI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_predsumu_u16x4_u64_rv64
	     (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u16x4_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V4HI 1 "register_operand" "r")
                            (match_operand:DI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "predsumu.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsum_i32x2_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                            (match_operand:DI 2 "nonmemory_operand")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_predsum_i32x2_i64_rv64
	     (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsum_i32x2_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                            (match_operand:DI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUM))]
  "TARGET_RVP && TARGET_64BIT"
  "predsum.ws\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_predsumu_u32x2_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                            (match_operand:DI 2 "nonmemory_operand")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_predsumu_u32x2_u64_rv64
	     (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_predsumu_u32x2_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                            (match_operand:DI 2 "nonmemory_operand" "r")]
         UNSPEC_PREDSUMU))]
  "TARGET_RVP && TARGET_64BIT"
  "predsumu.ws\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Minimum and Maximum
;
; pmin/pmax perform signed element-wise min/max; pminu/pmaxu the unsigned
; variants.  Suffixes follow the same scheme as padd: 32-bit types use
; .b/.h, 64-bit types use .b/.h/.w on RV64 and .db/.dh/.dw on RV32.

;--- PMIN (signed minimum) ---

(define_insn "riscv_pmin_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMIN))]
  "TARGET_RVP"
  "pmin.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmin_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMIN))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmin_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmin_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmin_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMIN))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmin.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmin_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMIN))]
  "TARGET_RVP && TARGET_64BIT"
  "pmin.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMAX (signed maximum) ---

(define_insn "riscv_pmax_<SAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMAX))]
  "TARGET_RVP"
  "pmax.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmax_<SAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMAX))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmax_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmax_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmax_<SAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMAX))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmax.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmax_<SAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMAX))]
  "TARGET_RVP && TARGET_64BIT"
  "pmax.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMINU (unsigned minimum) ---

(define_insn "riscv_pminu_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMINU))]
  "TARGET_RVP"
  "pminu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pminu_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMINU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pminu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pminu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pminu_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMINU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pminu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pminu_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMINU))]
  "TARGET_RVP && TARGET_64BIT"
  "pminu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMAXU (unsigned maximum) ---

(define_insn "riscv_pmaxu_<USAT_NAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMAXU))]
  "TARGET_RVP"
  "pmaxu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmaxu_<USAT_NAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMAXU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmaxu_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmaxu_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmaxu_<USAT_NAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMAXU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmaxu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmaxu_<USAT_NAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMAXU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaxu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Comparison
;
; All comparisons yield an unsigned result.  pmseq is sign-agnostic so the
; signed/unsigned input variants share the pmseq instruction; pmslt/pmsgt take
; signed inputs, pmsltu/pmsgtu take unsigned inputs.  Derived predicates
; (pmsne/pmsge/pmsle/pmsgeu/pmsleu) are expanded as the base comparison
; followed by bitwise NOT (xori -1).  On RV32, 64-bit results live in a
; register pair so the NOT is applied to both halves (two not instructions).

;--- PMSEQ (==), signed input variant ---

(define_insn "riscv_pmseq_<PCMP_SNAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
  "pmseq.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmseq_<PCMP_SNAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmseq_<PCMP_SNAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmseq_<PCMP_SNAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmseq_<PCMP_SNAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmseq.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmseq_<PCMP_SNAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP && TARGET_64BIT"
  "pmseq.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMSEQ (==), unsigned input variant (same instruction) ---

(define_insn "riscv_pmseq_<PCMP_UNAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
  "pmseq.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmseq_<PCMP_UNAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmseq_<PCMP_UNAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmseq_<PCMP_UNAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmseq_<PCMP_UNAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmseq.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmseq_<PCMP_UNAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP && TARGET_64BIT"
  "pmseq.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMSLT (<, signed) ---

(define_insn "riscv_pmslt_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMSLT))]
  "TARGET_RVP"
  "pmslt.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmslt_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSLT))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmslt_<PCMP_ONAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmslt_<PCMP_ONAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmslt_<PCMP_ONAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSLT))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmslt.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmslt_<PCMP_ONAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSLT))]
  "TARGET_RVP && TARGET_64BIT"
  "pmslt.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMSGT (>, signed) ---

(define_insn "riscv_pmsgt_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMSGT))]
  "TARGET_RVP"
  "pmsgt.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmsgt_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSGT))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmsgt_<PCMP_ONAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmsgt_<PCMP_ONAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmsgt_<PCMP_ONAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSGT))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmsgt.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmsgt_<PCMP_ONAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSGT))]
  "TARGET_RVP && TARGET_64BIT"
  "pmsgt.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMSLTU (<, unsigned) ---

(define_insn "riscv_pmsltu_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMSLTU))]
  "TARGET_RVP"
  "pmsltu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmsltu_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSLTU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmsltu_<PCMP_ONAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmsltu_<PCMP_ONAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmsltu_<PCMP_ONAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSLTU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmsltu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmsltu_<PCMP_ONAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSLTU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmsltu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMSGTU (>, unsigned) ---

(define_insn "riscv_pmsgtu_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand" "=r")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand" "r")
                       (match_operand:SAT32 2 "register_operand" "r")]
         UNSPEC_PMSGTU))]
  "TARGET_RVP"
  "pmsgtu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmsgtu_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSGTU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmsgtu_<PCMP_ONAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmsgtu_<PCMP_ONAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmsgtu_<PCMP_ONAME>_rv32"
  [(set (match_operand:SAT64 0 "register_operand" "=R")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSGTU))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmsgtu.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmsgtu_<PCMP_ONAME>_rv64"
  [(set (match_operand:SAT64 0 "register_operand" "=r")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand" "r")
                       (match_operand:SAT64 2 "register_operand" "r")]
         UNSPEC_PMSGTU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmsgtu.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- PMSNE (!=, = pmseq + not), signed input variant ---

(define_expand "riscv_pmsne_<PCMP_SNAME>"
  [(set (match_operand:SAT32 0 "register_operand")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand")
                       (match_operand:SAT32 2 "register_operand")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  emit_insn (gen_riscv_pmseq_<PCMP_SNAME> (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

(define_expand "riscv_pmsne_<PCMP_SNAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmseq_<PCMP_SNAME>_rv64 (tmp, operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmseq_<PCMP_SNAME>_rv32 (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

;--- PMSNE (!=, = pmseq + not), unsigned input variant ---

(define_expand "riscv_pmsne_<PCMP_UNAME>"
  [(set (match_operand:SAT32 0 "register_operand")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand")
                       (match_operand:SAT32 2 "register_operand")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  emit_insn (gen_riscv_pmseq_<PCMP_UNAME> (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

(define_expand "riscv_pmsne_<PCMP_UNAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSEQ))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmseq_<PCMP_UNAME>_rv64 (tmp, operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmseq_<PCMP_UNAME>_rv32 (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

;--- PMSGE (>=, = pmslt + not), signed ---

(define_expand "riscv_pmsge_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand")
                       (match_operand:SAT32 2 "register_operand")]
         UNSPEC_PMSLT))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  emit_insn (gen_riscv_pmslt_<PCMP_ONAME> (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

(define_expand "riscv_pmsge_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSLT))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmslt_<PCMP_ONAME>_rv64 (tmp, operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmslt_<PCMP_ONAME>_rv32 (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

;--- PMSLE (<=, = pmsgt + not), signed ---

(define_expand "riscv_pmsle_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand")
                       (match_operand:SAT32 2 "register_operand")]
         UNSPEC_PMSGT))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  emit_insn (gen_riscv_pmsgt_<PCMP_ONAME> (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

(define_expand "riscv_pmsle_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSGT))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmsgt_<PCMP_ONAME>_rv64 (tmp, operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmsgt_<PCMP_ONAME>_rv32 (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

;--- PMSGEU (>=, = pmsltu + not), unsigned ---

(define_expand "riscv_pmsgeu_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand")
                       (match_operand:SAT32 2 "register_operand")]
         UNSPEC_PMSLTU))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  emit_insn (gen_riscv_pmsltu_<PCMP_ONAME> (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

(define_expand "riscv_pmsgeu_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSLTU))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmsltu_<PCMP_ONAME>_rv64 (tmp, operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmsltu_<PCMP_ONAME>_rv32 (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

;--- PMSLEU (<=, = pmsgtu + not), unsigned ---

(define_expand "riscv_pmsleu_<PCMP_ONAME>"
  [(set (match_operand:SAT32 0 "register_operand")
        (unspec:SAT32 [(match_operand:SAT32 1 "register_operand")
                       (match_operand:SAT32 2 "register_operand")]
         UNSPEC_PMSGTU))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  emit_insn (gen_riscv_pmsgtu_<PCMP_ONAME> (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

(define_expand "riscv_pmsleu_<PCMP_ONAME>"
  [(set (match_operand:SAT64 0 "register_operand")
        (unspec:SAT64 [(match_operand:SAT64 1 "register_operand")
                       (match_operand:SAT64 2 "register_operand")]
         UNSPEC_PMSGTU))]
  "TARGET_RVP"
{
  rtx tmp = gen_reg_rtx (<MODE>mode);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmsgtu_<PCMP_ONAME>_rv64 (tmp, operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pmsgtu_<PCMP_ONAME>_rv32 (tmp, operands[1], operands[2]));
  riscv_emit_packed_not (operands[0], tmp, <MODE>mode);
  DONE;
})

;Packed Merge

(define_insn "riscv_pmerge_si"
  [(set (match_operand:SI 0 "register_operand" "=r,r,r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r,0,r")
                    (match_operand:SI 2 "register_operand" "r,r,0")
                    (match_operand:SI 3 "register_operand" "0,r,r")]
         UNSPEC_PMERGE))]
  "TARGET_RVP"
  "@
   merge\t%0,%1,%2
   mvm\t%0,%2,%3
   mvmn\t%0,%1,%3"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmerge_<UPMERGE_NAME>"
  [(set (match_operand:PMERGE32 0 "register_operand" "=r,r,r")
        (unspec:PMERGE32 [(match_operand:PMERGE32 1 "register_operand" "r,0,r")
                          (match_operand:PMERGE32 2 "register_operand" "r,r,0")
                          (match_operand:PMERGE32 3 "register_operand" "0,r,r")]
         UNSPEC_PMERGE))]
  "TARGET_RVP"
  "@
   merge\t%0,%1,%2
   mvm\t%0,%2,%3
   mvmn\t%0,%1,%3"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmerge_<PMERGE_NAME>"
  [(set (match_operand:PMERGE32 0 "register_operand" "=r,r,r")
        (unspec:PMERGE32 [(match_operand:PMERGE32 1 "register_operand" "r,0,r")
                          (match_operand:PMERGE32 2 "register_operand" "r,r,0")
                          (match_operand:PMERGE32 3 "register_operand" "0,r,r")]
         UNSPEC_PMERGE))]
  "TARGET_RVP"
  "@
   merge\t%0,%1,%2
   mvm\t%0,%2,%3
   mvmn\t%0,%1,%3"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmerge_<UPMERGE_NAME>"
  [(set (match_operand:PMERGE64 0 "register_operand")
        (unspec:PMERGE64 [(match_operand:PMERGE64 1 "register_operand")
                          (match_operand:PMERGE64 2 "register_operand")
                          (match_operand:PMERGE64 3 "register_operand")]
         UNSPEC_PMERGE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmerge_<UPMERGE_NAME>_rv64
		 (operands[0], operands[1], operands[2], operands[3]));
  else
    {
      machine_mode mode = GET_MODE (operands[0]);
      rtx out0 = operand_subword (operands[0], 0, 1, mode);
      rtx out1 = operand_subword (operands[0], 1, 1, mode);
      rtx rs10 = operand_subword_force (operands[1], 0, mode);
      rtx rs11 = operand_subword_force (operands[1], 1, mode);
      rtx rs20 = operand_subword_force (operands[2], 0, mode);
      rtx rs21 = operand_subword_force (operands[2], 1, mode);
      rtx mask0 = operand_subword_force (operands[3], 0, mode);
      rtx mask1 = operand_subword_force (operands[3], 1, mode);

      emit_insn (gen_riscv_pmerge_si (out0, rs10, rs20, mask0));
      emit_insn (gen_riscv_pmerge_si (out1, rs11, rs21, mask1));
    }
  DONE;
})

(define_insn "riscv_pmerge_<UPMERGE_NAME>_rv64"
  [(set (match_operand:PMERGE64 0 "register_operand" "=r,r,r")
        (unspec:PMERGE64 [(match_operand:PMERGE64 1 "register_operand" "r,0,r")
                          (match_operand:PMERGE64 2 "register_operand" "r,r,0")
                          (match_operand:PMERGE64 3 "register_operand" "0,r,r")]
         UNSPEC_PMERGE))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   merge\t%0,%1,%2
   mvm\t%0,%2,%3
   mvmn\t%0,%1,%3"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmerge_<PMERGE_NAME>"
  [(set (match_operand:PMERGE64 0 "register_operand")
        (unspec:PMERGE64 [(match_operand:PMERGE64 1 "register_operand")
                          (match_operand:PMERGE64 2 "register_operand")
                          (match_operand:PMERGE64 3 "register_operand")]
         UNSPEC_PMERGE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmerge_<PMERGE_NAME>_rv64
		 (operands[0], operands[1], operands[2], operands[3]));
  else
    {
      machine_mode mode = GET_MODE (operands[0]);
      rtx out0 = operand_subword (operands[0], 0, 1, mode);
      rtx out1 = operand_subword (operands[0], 1, 1, mode);
      rtx rs10 = operand_subword_force (operands[1], 0, mode);
      rtx rs11 = operand_subword_force (operands[1], 1, mode);
      rtx rs20 = operand_subword_force (operands[2], 0, mode);
      rtx rs21 = operand_subword_force (operands[2], 1, mode);
      rtx mask0 = operand_subword_force (operands[3], 0, mode);
      rtx mask1 = operand_subword_force (operands[3], 1, mode);

      emit_insn (gen_riscv_pmerge_si (out0, rs10, rs20, mask0));
      emit_insn (gen_riscv_pmerge_si (out1, rs11, rs21, mask1));
    }
  DONE;
})

(define_insn "riscv_pmerge_<PMERGE_NAME>_rv64"
  [(set (match_operand:PMERGE64 0 "register_operand" "=r,r,r")
        (unspec:PMERGE64 [(match_operand:PMERGE64 1 "register_operand" "r,0,r")
                          (match_operand:PMERGE64 2 "register_operand" "r,r,0")
                          (match_operand:PMERGE64 3 "register_operand" "0,r,r")]
         UNSPEC_PMERGE))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   merge\t%0,%1,%2
   mvm\t%0,%2,%3
   mvmn\t%0,%1,%3"
  [(set_attr "type" "simd")])

;Packed Sign and Zero Extend
;
;psext.* are real hardware instructions with their own encodings (one-operand
;unary form: rd, rs1), so the templates emit the psext mnemonic directly.
;
;pzext.* are NOT real instructions; per the P-ext spec they are only
;pseudoinstructions of ppaire.* with rs2 == x0, e.g.
;  pzext.h.b  rd, rs1  -> ppaire.b   rd, rs1, x0
;  pzext.w.h  rd, rs1  -> ppaire.h   rd, rs1, x0
;  pzext.dh.b rd, rs1  -> ppaire.db  rd, rs1, x0
;  pzext.dw.h rd, rs1  -> ppaire.dh  rd, rs1, x0
;Hence the pzext templates emit the underlying ppaire.* form with x0 instead
;of a (non-existent) pzext mnemonic.
(define_insn "riscv_psext_b_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP"
  "psext.h.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzext_b_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PZEXT))]
  "TARGET_RVP"
  "ppaire.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_psext_b_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psext_b_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_psext_b_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_psext_b_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dh.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_psext_b_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.h.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_psext_b_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psext_b_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_psext_b_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_psext_b_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dw.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_psext_b_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PSEXT_B))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.w.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_psext_h_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PSEXT_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psext_h_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_psext_h_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_psext_h_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PSEXT_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dw.h\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_psext_h_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PSEXT_H))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.w.h\t%0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_pzext_b_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PZEXT))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pzext_b_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pzext_b_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pzext_b_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PZEXT))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.db\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzext_b_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PZEXT))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_pzext_h_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PZEXT))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pzext_h_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pzext_h_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pzext_h_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PZEXT))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.dh\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzext_h_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PZEXT))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0,%1,x0"
  [(set_attr "type" "simd")])

;Packed Saturation
(define_insn "riscv_pusati_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u4")]
         UNSPEC_PUSATI))]
  "TARGET_RVP"
  "pusati.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psati_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u4")]
         UNSPEC_PSATI))]
  "TARGET_RVP"
  "psati.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pusati_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:SI 2 "const_int_operand")]
         UNSPEC_PUSATI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pusati_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pusati_u16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pusati_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u4")]
         UNSPEC_PUSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pusati.dh\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pusati_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u4")]
         UNSPEC_PUSATI))]
  "TARGET_RVP && TARGET_64BIT"
  "pusati.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pusati_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:SI 2 "const_int_operand")]
         UNSPEC_PUSATI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pusati_u32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pusati_u32x2_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pusati_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u5")]
         UNSPEC_PUSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "pusati.dw\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pusati_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u5")]
         UNSPEC_PUSATI))]
  "TARGET_RVP && TARGET_64BIT"
  "pusati.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psati_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:SI 2 "const_int_operand")]
         UNSPEC_PSATI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psati_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psati_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psati_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u4")]
         UNSPEC_PSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psati.dh\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psati_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u4")]
         UNSPEC_PSATI))]
  "TARGET_RVP && TARGET_64BIT"
  "psati.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psati_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:SI 2 "const_int_operand")]
         UNSPEC_PSATI))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psati_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psati_i32x2_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psati_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u5")]
         UNSPEC_PSATI))]
  "TARGET_RVP && !TARGET_64BIT"
  "psati.dw\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psati_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "const_int_operand" "u5")]
         UNSPEC_PSATI))]
  "TARGET_RVP && TARGET_64BIT"
  "psati.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

; Packed Shifts
(define_insn "riscv_psll_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psrl_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSRL))]
  "TARGET_RVP"
  "@
   psrli.b\t%0,%1,%2
   psrl.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psrl_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PSRL))]
  "TARGET_RVP"
  "@
   psrli.h\t%0,%1,%2
   psrl.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
  "@
   psrai.b\t%0,%1,%2
   psra.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
  "@
   psrai.h\t%0,%1,%2
   psra.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_u8x8_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_u8x8_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})
 

(define_insn "riscv_psll_s_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.db\t%0,%1,%2
   psll.dbs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_i8x8_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_i8x8_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.b\t%0,%1,%2
   psll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
         UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.db\t%0,%1,%2
   psll.dbs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_u16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_u16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dh\t%0,%1,%2
   psll.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_i16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_i16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dh\t%0,%1,%2
   psll.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u4, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.h\t%0,%1,%2
   psll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_u32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_u32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dw\t%0,%1,%2
   psll.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.w\t%0,%1,%2
   psll.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psll_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSLL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psll_s_i32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psll_s_i32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psll_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pslli.dw\t%0,%1,%2
   psll.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psll_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u5, r")]
          UNSPEC_PSLL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   pslli.w\t%0,%1,%2
   psll.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psrl_s_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSRL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psrl_s_u8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psrl_s_u8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psrl_s_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrli.db\t%0,%1,%2
   psrl.dbs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psrl_s_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psrli.b\t%0,%1,%2
   psrl.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psrl_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSRL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psrl_s_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psrl_s_u16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psrl_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrli.dh\t%0,%1,%2
   psrl.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psrl_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSRL))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psrl_s_u32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psrl_s_u32x2_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psrl_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrli.dw\t%0,%1,%2
   psrl.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psrai.w\t%0,%1,%2
   psra.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psra_s_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psra_s_i8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psra_s_i8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psra_s_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R, R")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrai.db\t%0,%1,%2
   psra.dbs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r, r")
        (unspec:V8QI [(match_operand:V8QI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psrai.b\t%0,%1,%2
   psra.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psra_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psra_s_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psra_s_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psra_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrai.dh\t%0,%1,%2
   psra.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psra_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psrai.h\t%0,%1,%2
   psra.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psrl_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psrli.h\t%0,%1,%2
   psrl.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_expand "riscv_psra_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSRA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_psra_s_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_psra_s_i32x2_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_psra_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psrai.dw\t%0,%1,%2
   psra.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_psrl_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r")
                    (match_operand:SI 2 "arith_operand" "u3, r")]
          UNSPEC_PSRL))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psrli.w\t%0,%1,%2
   psrl.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

;Packed Saturating and Rounding Shifts
;
; pssha/psshar: signed saturating (rounding) arithmetic shift, expanded via
; psslai (immediate) / psrai or psrari (negative immediate) / pssha[r].hs.
; psshl/psshlr: unsigned saturating (rounding) logical shift.

(define_insn "riscv_pssha_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP"
  "@
   psslai.h\t%0,%1,%2
   psrai.h\t%0,%1,%n2
   pssha.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_psshar_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r, r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
         UNSPEC_PSSHAR))]
  "TARGET_RVP"
  "@
   psslai.h\t%0,%1,%2
   psrari.h\t%0,%1,%n2
   psshar.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_psshl_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHL))]
  "TARGET_RVP"
{
  if (!register_operand (operands[2], SImode))
    operands[2] = force_reg (SImode, operands[2]);
})

(define_insn "riscv_psshl_s_u16x2_insn"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")]
         UNSPEC_PSSHL))]
  "TARGET_RVP"
  "psshl.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psshlr_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHLR))]
  "TARGET_RVP"
{
  if (!register_operand (operands[2], SImode))
    operands[2] = force_reg (SImode, operands[2]);
})

(define_insn "riscv_psshlr_s_u16x2_insn"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:SI 2 "register_operand" "r")]
         UNSPEC_PSSHLR))]
  "TARGET_RVP"
  "psshlr.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pssha_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pssha_s_i16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_pssha_s_i16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_pssha_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.dh\t%0,%1,%2
   psrai.dh\t%0,%1,%n2
   pssha.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pssha_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psslai.h\t%0,%1,%2
   psrai.h\t%0,%1,%n2
   pssha.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_pssha_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHA))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_pssha_s_i32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_pssha_s_i32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_pssha_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.dw\t%0,%1,%2
   psrai.dw\t%0,%1,%n2
   pssha.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_pssha_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHA))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psslai.w\t%0,%1,%2
   psrai.w\t%0,%1,%n2
   pssha.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_psshar_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHAR))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psshar_s_i16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psshar_s_i16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psshar_s_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R, R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHAR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.dh\t%0,%1,%2
   psrari.dh\t%0,%1,%n2
   psshar.dhs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_psshar_s_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r, r, r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u4, w4, r")]
          UNSPEC_PSSHAR))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psslai.h\t%0,%1,%2
   psrari.h\t%0,%1,%n2
   psshar.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_psshar_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHAR))]
  "TARGET_RVP"
{
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psshar_s_i32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psshar_s_i32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psshar_s_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R, R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHAR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   psslai.dw\t%0,%1,%2
   psrari.dw\t%0,%1,%n2
   psshar.dws\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_insn "riscv_psshar_s_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r, r, r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r, r, r")
                    (match_operand:SI 2 "arith_operand" "u5, w5, r")]
          UNSPEC_PSSHAR))]
  "TARGET_RVP && TARGET_64BIT"
  "@
   psslai.w\t%0,%1,%2
   psrari.w\t%0,%1,%n2
   psshar.ws\t%0,%1,%2"
  [(set_attr "type" "simd, simd, simd")])

(define_expand "riscv_psshl_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHL))]
  "TARGET_RVP"
{
  if (!register_operand (operands[2], SImode))
    operands[2] = force_reg (SImode, operands[2]);
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psshl_s_u16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psshl_s_u16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psshl_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "R")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHL))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshl.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psshl_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHL))]
  "TARGET_RVP && TARGET_64BIT"
  "psshl.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psshl_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHL))]
  "TARGET_RVP"
{
  if (!register_operand (operands[2], SImode))
    operands[2] = force_reg (SImode, operands[2]);
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psshl_s_u32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psshl_s_u32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psshl_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHL))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshl.dws\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psshl_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHL))]
  "TARGET_RVP && TARGET_64BIT"
  "psshl.ws\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psshlr_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHLR))]
  "TARGET_RVP"
{
  if (!register_operand (operands[2], SImode))
    operands[2] = force_reg (SImode, operands[2]);
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psshlr_s_u16x4_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psshlr_s_u16x4_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psshlr_s_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHLR))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshlr.dhs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psshlr_s_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHLR))]
  "TARGET_RVP && TARGET_64BIT"
  "psshlr.hs\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_psshlr_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:SI 2 "nonmemory_operand")]
         UNSPEC_PSSHLR))]
  "TARGET_RVP"
{
  if (!register_operand (operands[2], SImode))
    operands[2] = force_reg (SImode, operands[2]);
  if (TARGET_64BIT) {
    emit_insn (gen_riscv_psshlr_s_u32x2_rv64 (operands[0], operands[1], operands[2]));
  } else {
    emit_insn (gen_riscv_psshlr_s_u32x2_rv32 (operands[0], operands[1], operands[2]));
  }
  DONE;
})

(define_insn "riscv_psshlr_s_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHLR))]
  "TARGET_RVP && !TARGET_64BIT"
  "psshlr.dws\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_psshlr_s_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:SI 2 "register_operand" "r")]
          UNSPEC_PSSHLR))]
  "TARGET_RVP && TARGET_64BIT"
  "psshlr.ws\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Pair
;
; ppaire  : pack pair even   (RV32 16x2 & RV64 32x2 -> "pack"; RV64 -> ppaire.h/w;
;           RV32 double-wide -> ppaire.db/dh)
; ppaireo : pack pair even-odd
; ppairoe : pack pair odd-even
; ppairo  : pack pair odd
; Each variant has its own UNSPEC (UNSPEC_PPAIRE/PPAIREO/PPAIROE/PPAIRO); the
; mnemonic and (where relevant) the pack/mv alias carry the distinction.
; Signed and unsigned variants of the same width use the same machine
; instruction, so they are separate patterns only because the builtin names differ.
;
; 32x2 (V2SI) on RV32 is intentionally unsupported: spec marks it "mv" but the
; semantics of ppaireo/ppairoe/ppairo depend on both source register pairs'
; half registers, which a plain mv cannot express.  TODO: implement with
; paired emit_move when needed.  For now the 32x2 builtins are simd64-only.

; ---- 8x4 (V4QI), 32-bit, single form ----
(define_insn "riscv_ppaire_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP"
  "ppaire.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaire_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP"
  "ppaire.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP"
  "ppaireo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP"
  "ppaireo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP"
  "ppairoe.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP"
  "ppairoe.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP"
  "ppairo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP"
  "ppairo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ---- 16x2 (V2HI), 32-bit ----
; ppaire: RV32 -> "pack" (alias), RV64 -> ppaire.h
(define_expand "riscv_ppaire_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppaire_u16x2_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppaire_u16x2_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppaire_u16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && !TARGET_64BIT"
  "pack\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaire_u16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_ppaire_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppaire_i16x2_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppaire_i16x2_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppaire_i16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && !TARGET_64BIT"
  "pack\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaire_i16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ppaireo/ppairoe/ppairo 16x2: single form (no RV32/RV64 mnemonic split)
(define_insn "riscv_ppaireo_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP"
  "ppaireo.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP"
  "ppaireo.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP"
  "ppairoe.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP"
  "ppairoe.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP"
  "ppairo.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP"
  "ppairo.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ---- 8x8 (V8QI) and 16x4 (V4HI), 64-bit: RV32 double-wide / RV64 single ----
; ppaire: RV64 -> ppaire.b/h, RV32 -> ppaire.db/dh
(define_expand "riscv_ppaire_<USAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppaire_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppaire_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppaire_<USAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaire_<USAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ppaireo: RV64 -> ppaireo.b/h, RV32 -> ppaireo.db/dh
(define_expand "riscv_ppaireo_<USAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppaireo_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppaireo_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppaireo_<USAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaireo.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_<USAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ppairoe: RV64 -> ppairoe.b/h, RV32 -> ppairoe.db/dh
(define_expand "riscv_ppairoe_<USAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppairoe_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppairoe_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppairoe_<USAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairoe.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_<USAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ppairo: RV64 -> ppairo.b/h, RV32 -> ppairo.db/dh
(define_expand "riscv_ppairo_<USAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppairo_<USAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppairo_<USAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppairo_<USAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_<USAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; Signed 8x8/16x4 variants (same instructions, distinct builtin names).
(define_expand "riscv_ppaire_<SAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppaire_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppaire_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppaire_<SAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaire_<SAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_ppaireo_<SAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppaireo_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppaireo_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppaireo_<SAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaireo.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_<SAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_ppairoe_<SAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppairoe_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppairoe_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppairoe_<SAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairoe.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_<SAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_ppairo_<SAT_NAME>"
  [(set (match_operand:PAIR64 0 "register_operand")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand")
                        (match_operand:PAIR64 2 "register_operand")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_ppairo_<SAT_NAME>_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_ppairo_<SAT_NAME>_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_ppairo_<SAT_NAME>_rv32"
  [(set (match_operand:PAIR64 0 "register_operand" "=R")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.<DSAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_<SAT_NAME>_rv64"
  [(set (match_operand:PAIR64 0 "register_operand" "=r")
        (unspec:PAIR64 [(match_operand:PAIR64 1 "register_operand" "r")
                        (match_operand:PAIR64 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.<SAT_SUFFIX>\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ---- 32x2 (V2SI), 64-bit RV64 only ----
; RV32 is intentionally unsupported (see TODO at top of section).
; ppaire_u32x2/i32x2 -> "pack"; the other three use their .w mnemonics.
(define_insn "riscv_ppaire_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && TARGET_64BIT"
  "pack\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaire_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIRE))]
  "TARGET_RVP && TARGET_64BIT"
  "pack\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppaireo_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIREO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaireo.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairoe_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIROE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairoe.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_ppairo_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PPAIRO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Widening Convert
;
;pwcvt.* / pwcvtu.* / pwcvth.* are NOT real instructions; per the P-ext spec
;they are pseudoinstructions of the underlying widening instructions:
;  RV32:
;    pwcvt.b   rd_p, rs1 -> pwadd.b   rd_p, rs1, x0   (sign-extend widen)
;    pwcvt.h   rd_p, rs1 -> pwadd.h   rd_p, rs1, x0
;    pwcvtu.b  rd_p, rs1 -> wzip8p    rd_p, rs1, x0   (zero-extend widen)
;    pwcvtu.h  rd_p, rs1 -> wzip16p   rd_p, rs1, x0
;    pwcvth.b  rd_p, rs1 -> wzip8p    rd_p, x0, rs1   (high-half widen)
;    pwcvth.h  rd_p, rs1 -> wzip16p   rd_p, x0, rs1
;  RV64:
;    pwcvt.b   rd, rs1 -> zip8p  rd, rs1, x0  +  psext.h.b rd, rd
;    pwcvt.h   rd, rs1 -> zip16p rd, rs1, x0  +  psext.w.h rd, rd
;    pwcvtu.b  rd, rs1 -> zip8p  rd, rs1, x0
;    pwcvtu.h  rd, rs1 -> zip16p rd, rs1, x0
;    pwcvth.b  rd, rs1 -> zip8p  rd, x0, rs1
;    pwcvth.h  rd, rs1 -> zip16p rd, x0, rs1
;Hence the templates emit the underlying pwadd.b/wzip8p/zip8p/... forms rather
;than a (non-existent) pwcvt mnemonic.  The signed RV64 forms need two insns
;(zip for zero-extend widen, then psext for sign-extend), emitted via
;define_expand reusing the existing riscv_psext_*_rv64 patterns.

; pwcvt_i16x4 (signed b -> h, RV32 pwadd.b / RV64 zip8p + psext.h.b)
(define_expand "riscv_pwcvt_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand")]
         UNSPEC_PWCVT_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      emit_insn (gen_riscv_pwcvt_i16x4_zip_rv64 (operands[0], operands[1]));
      emit_insn (gen_riscv_psext_b_i16x4_rv64 (operands[0], operands[0]));
    }
  else
    emit_insn (gen_riscv_pwcvt_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvt_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVT_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadd.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvt_i16x4_zip_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVT_B))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwcvt_i32x2 (signed h -> w, RV32 pwadd.h / RV64 zip16p + psext.w.h)
(define_expand "riscv_pwcvt_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand")]
         UNSPEC_PWCVT_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      emit_insn (gen_riscv_pwcvt_i32x2_zip_rv64 (operands[0], operands[1]));
      emit_insn (gen_riscv_psext_h_i32x2_rv64 (operands[0], operands[0]));
    }
  else
    emit_insn (gen_riscv_pwcvt_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvt_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVT_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadd.h\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvt_i32x2_zip_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVT_H))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwcvtu_u16x4 (unsigned b -> h, RV32 wzip8p / RV64 zip8p)
(define_expand "riscv_pwcvtu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand")]
         UNSPEC_PWCVTU_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwcvtu_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwcvtu_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvtu_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVTU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvtu_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVTU_B))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwcvtu_u32x2 (unsigned h -> w, RV32 wzip16p / RV64 zip16p)
(define_expand "riscv_pwcvtu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand")]
         UNSPEC_PWCVTU_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwcvtu_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwcvtu_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvtu_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVTU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvtu_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVTU_H))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwcvth_i16x4 / pwcvth_u16x4 (high-half b -> h, RV32 wzip8p / RV64 zip8p).
; Signed and unsigned share the same machine instruction (zero-extend widen of
; the high half); they differ only in the C-level element type, so both map to
; UNSPEC_PWCVTH_B but get distinct pattern names for their distinct builtins.
(define_expand "riscv_pwcvth_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand")]
         UNSPEC_PWCVTH_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwcvth_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwcvth_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvth_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvth_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_B))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwcvth_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand")]
         UNSPEC_PWCVTH_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwcvth_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwcvth_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvth_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvth_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_B))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,x0,%1"
  [(set_attr "type" "simd")])

; pwcvth_i32x2 / pwcvth_u32x2 (high-half h -> w, RV32 wzip16p / RV64 zip16p)
(define_expand "riscv_pwcvth_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand")]
         UNSPEC_PWCVTH_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwcvth_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwcvth_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvth_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvth_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_H))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwcvth_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand")]
         UNSPEC_PWCVTH_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwcvth_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwcvth_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwcvth_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwcvth_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")]
         UNSPEC_PWCVTH_H))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,x0,%1"
  [(set_attr "type" "simd")])

;Packed Narrowing Convert
;
;pncvt.* / pncvth.* are NOT real instructions; per the P-ext spec they are
;pseudoinstructions of the underlying narrowing instructions:
;  RV32:
;    pncvt.b   rd, rs1_p -> pnsrli.b  rd, rs1_p, 0    (low half)
;    pncvt.h   rd, rs1_p -> pnsrli.h  rd, rs1_p, 0
;    pncvth.b  rd, rs1_p -> pnsrli.b  rd, rs1_p, 8    (high half)
;    pncvth.h  rd, rs1_p -> pnsrli.h  rd, rs1_p, 16
;  RV64:
;    pncvt.wb  rd, rs1 -> unzip8p   rd, rs1, x0
;    pncvt.wh  rd, rs1 -> unzip16p  rd, rs1, x0
;    pncvth.wb rd, rs1 -> unzip8hp  rd, rs1, x0
;    pncvth.wh rd, rs1 -> unzip16hp rd, rs1, x0
;Hence the templates emit the underlying pnsrli.b/unzip8p/... forms rather than
;a (non-existent) pncvt mnemonic.  This is the mirror of Packed Widening Convert
;(wide-in/narrow-out vs narrow-in/wide-out); each form is a single instruction,
;so no two-insn expand is needed.  Signed and unsigned variants share the same
;machine instruction and UNSPEC, differing only in the C-level element type;
;they get distinct pattern names for their distinct builtins.

; pncvt_i8x4 / pncvt_u8x4 (narrow h -> b, RV32 pnsrli.b,0 / RV64 unzip8p)
(define_expand "riscv_pncvt_i8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PNCVT_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvt_i8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvt_i8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvt_i8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PNCVT_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvt_i8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PNCVT_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_pncvt_u8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PNCVT_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvt_u8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvt_u8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvt_u8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PNCVT_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvt_u8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PNCVT_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pncvt_i16x2 / pncvt_u16x2 (narrow w -> h, RV32 pnsrli.h,0 / RV64 unzip16p)
(define_expand "riscv_pncvt_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PNCVT_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvt_i16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvt_i16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvt_i16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R")]
         UNSPEC_PNCVT_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvt_i16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PNCVT_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_pncvt_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PNCVT_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvt_u16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvt_u16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvt_u16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R")]
         UNSPEC_PNCVT_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvt_u16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PNCVT_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pncvth_i8x4 / pncvth_u8x4 (high-half h -> b, RV32 pnsrli.b,8 / RV64 unzip8hp)
(define_expand "riscv_pncvth_i8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PNCVTH_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvth_i8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvth_i8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvth_i8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PNCVTH_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvth_i8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PNCVTH_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_pncvth_u8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PNCVTH_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvth_u8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvth_u8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvth_u8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PNCVTH_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvth_u8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PNCVTH_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pncvth_i16x2 / pncvth_u16x2 (high-half w -> h, RV32 pnsrli.h,16 / RV64 unzip16hp)
(define_expand "riscv_pncvth_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PNCVTH_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvth_i16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvth_i16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvth_i16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R")]
         UNSPEC_PNCVTH_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvth_i16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PNCVTH_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_pncvth_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand")]
         UNSPEC_PNCVTH_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pncvth_u16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pncvth_u16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pncvth_u16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R")]
         UNSPEC_PNCVTH_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_pncvth_u16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "r")]
         UNSPEC_PNCVTH_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

;Packed Zip
;
;pzip interleaves two narrow sources (32-bit each) into one wide result
;(64-bit): two V4QI -> V8QI, or two V2HI -> V4HI.
;  RV32: wzip8p/wzip16p rd_p, rs1, rs2  (result in even-odd register pair)
;  RV64: zip8p/zip16p   rd,   rs1, rs2  (result in a single register)
;Signed and unsigned variants share the same machine instruction and UNSPEC,
;differing only in the C-level element type; they get distinct pattern names.

; pzip_i8x8 / pzip_u8x8 (two V4QI -> V8QI)
(define_expand "riscv_pzip_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V4QI 1 "register_operand")
                      (match_operand:V4QI 2 "register_operand")]
         UNSPEC_PZIP_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pzip_i8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pzip_i8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pzip_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PZIP_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzip_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PZIP_B))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pzip_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V4QI 1 "register_operand")
                      (match_operand:V4QI 2 "register_operand")]
         UNSPEC_PZIP_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pzip_u8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pzip_u8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pzip_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PZIP_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzip_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PZIP_B))]
  "TARGET_RVP && TARGET_64BIT"
  "zip8p\t%0,%1,%2"
  [(set_attr "type" "simd")])

; pzip_i16x4 / pzip_u16x4 (two V2HI -> V4HI)
(define_expand "riscv_pzip_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PZIP_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pzip_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pzip_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pzip_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PZIP_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzip_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PZIP_H))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pzip_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PZIP_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pzip_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pzip_u16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pzip_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PZIP_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "wzip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pzip_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PZIP_H))]
  "TARGET_RVP && TARGET_64BIT"
  "zip16p\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Unzip
;
;punzipe/punzipo de-interleave one wide source (64-bit) into one narrow result
;(32-bit): V8QI -> V4QI, or V4HI -> V2HI.  They share the underlying machine
;instructions with pncvt/pncvth (narrowing convert), but take a different input
;mode (the 8x8/16x4 wide form rather than 16x4/32x2), so they need their own
;patterns.  Mapping (same as pncvt/pncvth):
;  RV32:
;    punzipe.b  rd, rs1_p -> pnsrli.b  rd, rs1_p, 0   (even half)
;    punzipo.b  rd, rs1_p -> pnsrli.b  rd, rs1_p, 8   (odd half)
;    punzipe.h  rd, rs1_p -> pnsrli.h  rd, rs1_p, 0
;    punzipo.h  rd, rs1_p -> pnsrli.h  rd, rs1_p, 16
;  RV64:
;    punzipe.wb rd, rs1 -> unzip8p   rd, rs1, x0
;    punzipo.wb rd, rs1 -> unzip8hp  rd, rs1, x0
;    punzipe.wh rd, rs1 -> unzip16p  rd, rs1, x0
;    punzipo.wh rd, rs1 -> unzip16hp rd, rs1, x0
;Signed and unsigned variants share the same machine instruction and UNSPEC,
;differing only in the C-level element type; they get distinct pattern names.

; punzipe_i8x4 / punzipe_u8x4 (V8QI -> V4QI, even half)
(define_expand "riscv_punzipe_i8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PUNZIPE_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipe_i8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipe_i8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipe_i8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "R")]
         UNSPEC_PUNZIPE_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipe_i8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PUNZIPE_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_punzipe_u8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PUNZIPE_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipe_u8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipe_u8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipe_u8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "R")]
         UNSPEC_PUNZIPE_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipe_u8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PUNZIPE_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; punzipo_i8x4 / punzipo_u8x4 (V8QI -> V4QI, odd half)
(define_expand "riscv_punzipo_i8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PUNZIPO_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipo_i8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipo_i8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipo_i8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "R")]
         UNSPEC_PUNZIPO_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipo_i8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PUNZIPO_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_punzipo_u8x4"
  [(set (match_operand:V4QI 0 "register_operand")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PUNZIPO_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipo_u8x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipo_u8x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipo_u8x4_rv32"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "R")]
         UNSPEC_PUNZIPO_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.b\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipo_u8x4_rv64"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PUNZIPO_B))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip8hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

; punzipe_i16x2 / punzipe_u16x2 (V4HI -> V2HI, even half)
(define_expand "riscv_punzipe_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PUNZIPE_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipe_i16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipe_i16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipe_i16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PUNZIPE_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipe_i16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PUNZIPE_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_punzipe_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PUNZIPE_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipe_u16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipe_u16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipe_u16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PUNZIPE_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,0"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipe_u16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PUNZIPE_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16p\t%0,%1,x0"
  [(set_attr "type" "simd")])

; punzipo_i16x2 / punzipo_u16x2 (V4HI -> V2HI, odd half)
(define_expand "riscv_punzipo_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PUNZIPO_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipo_i16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipo_i16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipo_i16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PUNZIPO_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipo_i16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PUNZIPO_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_expand "riscv_punzipo_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PUNZIPO_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_punzipo_u16x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_punzipo_u16x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_punzipo_u16x2_rv32"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "R")]
         UNSPEC_PUNZIPO_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pnsrli.h\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_punzipo_u16x2_rv64"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PUNZIPO_H))]
  "TARGET_RVP && TARGET_64BIT"
  "unzip16hp\t%0,%1,x0"
  [(set_attr "type" "simd")])

;Packed Narrowing Zip
;
;pnzip/pnziph narrow two wide sources into one narrow result by pairing the low
;byte/halfword of corresponding elements: two V2HI -> V4QI (32-bit), or two
;V4HI/V2SI -> V8QI/V4HI (64-bit).  They share the ppaire/ppairo machine
;instructions with Packed Pair, but take wider input modes (the 16x2/16x4/32x2
;form rather than 8x4/8x8/16x4), so they need their own patterns.
;  pnzip  (even-pair) -> ppaire.b/h/db/dh
;  pnziph (odd-pair)  -> ppairo.b/h/db/dh
;Mapping:
;  32-bit (V2HI -> V4QI, single register, both ISAs): ppaire.b / ppairo.b
;  64-bit RV32 (V4HI->V8QI, V2SI->V4HI, register pairs): ppaire.db/dh, ppairo.db/dh
;  64-bit RV64 (V4HI->V8QI, V2SI->V4HI, single register): ppaire.b/h, ppairo.b/h
;Signed and unsigned variants share the same machine instruction and UNSPEC,
;differing only in the C-level element type; they get distinct pattern names.

; ---- 32-bit (V2HI + V2HI -> V4QI), single form, both ISAs ----
(define_insn "riscv_pnzip_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP"
  "ppaire.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnzip_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP"
  "ppaire.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnziph_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP"
  "ppairo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnziph_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r")
        (unspec:V4QI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP"
  "ppairo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ---- 64-bit (V4HI + V4HI -> V8QI), RV32 ppaire.db / RV64 ppaire.b ----
(define_expand "riscv_pnzip_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnzip_i8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnzip_i8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnzip_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.db\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnzip_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pnzip_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnzip_u8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnzip_u8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnzip_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.db\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnzip_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIP_B))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pnziph_i8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnziph_i8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnziph_i8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnziph_i8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.db\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnziph_i8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pnziph_u8x8"
  [(set (match_operand:V8QI 0 "register_operand")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnziph_u8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnziph_u8x8_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnziph_u8x8_rv32"
  [(set (match_operand:V8QI 0 "register_operand" "=R")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.db\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnziph_u8x8_rv64"
  [(set (match_operand:V8QI 0 "register_operand" "=r")
        (unspec:V8QI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_B))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ---- 64-bit (V2SI + V2SI -> V4HI), RV32 ppaire.dh / RV64 ppaire.h ----
(define_expand "riscv_pnzip_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PNZIP_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnzip_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnzip_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnzip_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIP_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.dh\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnzip_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIP_H))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pnzip_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PNZIP_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnzip_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnzip_u16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnzip_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIP_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.dh\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnzip_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIP_H))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pnziph_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PNZIPH_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnziph_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnziph_i16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnziph_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.dh\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnziph_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_H))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pnziph_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PNZIPH_H))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pnziph_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    emit_insn (gen_riscv_pnziph_u16x4_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pnziph_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.dh\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pnziph_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PNZIPH_H))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Widening Unzip
;
;pwunzip* widen one narrow source (32-bit) into one wide result (64-bit) by
;de-interleaving: V4QI -> V2HI (32-bit), V8QI -> V4HI / V4HI -> V2SI (64-bit).
;Six variants, each maps to a different underlying instruction:
;  pwunzipe  (even, signed)   -> psext.h.b / psext.w.h / psext.dh.b / psext.dw.h
;  pwunzipo  (odd,  signed)   -> psrai.h,8 / psrai.w,16 / psrai.dh,8 / psrai.dw,16
;  pwunzipue (even, unsigned) -> ppaire.b %0,%1,x0  / ppaire.h %0,%1,x0  (rs2=0)
;  pwunzipuo (odd,  unsigned) -> ppairo.b %0,%1,x0 / ppairo.h %0,%1,x0 (rs2=0)
;  pwunziphe (high-even)      -> pslli.h,8 / pslli.w,16 / pslli.dh,8 / pslli.dw,16
;  pwunzipho (high-odd)       -> ppairo.b %0,x0,%1 / ppairo.h %0,x0,%1 (rs1=0)
;Signed and unsigned variants share the same machine instruction and UNSPEC
;for e/o (psext/psrai are inherently sign-aware, ue/uo use ppaire/ppairo which
;are sign-agnostic), differing only in the C-level element type; they get
;distinct pattern names.  Immediates (8/16) are written literally into the
;template, not passed as operands.

; ---- 32-bit (V4QI -> V2HI), single form, both ISAs (constraint d,s) ----
(define_insn "riscv_pwunzipe_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP"
  "psext.h.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipo_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP"
  "psrai.h\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipue_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP"
  "ppaire.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipuo_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP"
  "ppairo.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunziphe_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP"
  "pslli.h\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunziphe_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP"
  "pslli.h\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipho_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP"
  "ppairo.b\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipho_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP"
  "ppairo.b\t%0,x0,%1"
  [(set_attr "type" "simd")])

; ---- 64-bit (V8QI -> V4HI), RV32 psext.dh.b etc / RV64 psext.h.b etc ----
; pwunzipe_i16x4 (signed even -> psext)
(define_expand "riscv_pwunzipe_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipe_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipe_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipe_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dh.b\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipe_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.h.b\t%0,%1"
  [(set_attr "type" "simd")])

; pwunzipo_i16x4 (signed odd -> psrai.h,8 / psrai.dh,8)
(define_expand "riscv_pwunzipo_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipo_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipo_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipo_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP && !TARGET_64BIT"
  "psrai.dh\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipo_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP && TARGET_64BIT"
  "psrai.h\t%0,%1,8"
  [(set_attr "type" "simd")])

; pwunzipue_u16x4 (unsigned even -> ppaire.b,rs2=0 / ppaire.db,rs2_p=0)
(define_expand "riscv_pwunzipue_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipue_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipue_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipue_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.db\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipue_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwunzipuo_u16x4 (unsigned odd -> ppairo.b,rs2=0 / ppairo.db,rs2_p=0)
(define_expand "riscv_pwunzipuo_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipuo_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipuo_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipuo_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.db\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipuo_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.b\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwunziphe_i16x4 (signed/unsigned high-even -> pslli.h,8 / pslli.dh,8)
(define_expand "riscv_pwunziphe_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunziphe_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunziphe_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunziphe_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.dh\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunziphe_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && TARGET_64BIT"
  "pslli.h\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwunziphe_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunziphe_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunziphe_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunziphe_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.dh\t%0,%1,8"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunziphe_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && TARGET_64BIT"
  "pslli.h\t%0,%1,8"
  [(set_attr "type" "simd")])

; pwunzipho_i16x4 (signed/unsigned high-odd -> ppairo.b,rs1=0 / ppairo.db,rs1_p=0)
(define_expand "riscv_pwunzipho_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipho_i16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipho_i16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipho_i16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.db\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipho_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.b\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwunzipho_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipho_u16x4_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipho_u16x4_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipho_u16x4_rv32"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.db\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipho_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.b\t%0,x0,%1"
  [(set_attr "type" "simd")])

; ---- 64-bit (V4HI -> V2SI), RV32 psext.dw.h etc / RV64 psext.w.h etc ----
; pwunzipe_i32x2 (signed even -> psext.w.h / psext.dw.h)
(define_expand "riscv_pwunzipe_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipe_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipe_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipe_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP && !TARGET_64BIT"
  "psext.dw.h\t%0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipe_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPE))]
  "TARGET_RVP && TARGET_64BIT"
  "psext.w.h\t%0,%1"
  [(set_attr "type" "simd")])

; pwunzipo_i32x2 (signed odd -> psrai.w,16 / psrai.dw,16)
(define_expand "riscv_pwunzipo_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipo_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipo_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipo_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP && !TARGET_64BIT"
  "psrai.dw\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipo_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPO))]
  "TARGET_RVP && TARGET_64BIT"
  "psrai.w\t%0,%1,16"
  [(set_attr "type" "simd")])

; pwunzipue_u32x2 (unsigned even -> ppaire.h,rs2=0 / ppaire.dh,rs2_p=0)
(define_expand "riscv_pwunzipue_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipue_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipue_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipue_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppaire.dh\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipue_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUE))]
  "TARGET_RVP && TARGET_64BIT"
  "ppaire.h\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwunzipuo_u32x2 (unsigned odd -> ppairo.h,rs2=0 / ppairo.dh,rs2_p=0)
(define_expand "riscv_pwunzipuo_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipuo_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipuo_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipuo_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.dh\t%0,%1,x0"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipuo_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPUO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.h\t%0,%1,x0"
  [(set_attr "type" "simd")])

; pwunziphe_i32x2 (signed/unsigned high-even -> pslli.w,16 / pslli.dw,16)
(define_expand "riscv_pwunziphe_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunziphe_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunziphe_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunziphe_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.dw\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunziphe_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && TARGET_64BIT"
  "pslli.w\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwunziphe_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunziphe_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunziphe_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunziphe_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && !TARGET_64BIT"
  "pslli.dw\t%0,%1,16"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunziphe_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHE))]
  "TARGET_RVP && TARGET_64BIT"
  "pslli.w\t%0,%1,16"
  [(set_attr "type" "simd")])

; pwunzipho_i32x2 (signed/unsigned high-odd -> ppairo.h,rs1=0 / ppairo.dh,rs1_p=0)
(define_expand "riscv_pwunzipho_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipho_i32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipho_i32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipho_i32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.dh\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipho_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.h\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwunzipho_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pwunzipho_u32x2_rv64 (operands[0], operands[1]));
  else
    emit_insn (gen_riscv_pwunzipho_u32x2_rv32 (operands[0], operands[1]));
  DONE;
})

(define_insn "riscv_pwunzipho_u32x2_rv32"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && !TARGET_64BIT"
  "ppairo.dh\t%0,x0,%1"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwunzipho_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")]
         UNSPEC_PWUNZIPHO))]
  "TARGET_RVP && TARGET_64BIT"
  "ppairo.h\t%0,x0,%1"
  [(set_attr "type" "simd")])

;Packed Widening Addition and Subtraction
;
;pwadd/pwsub widen two narrow sources (32-bit each) into one wide result
;(64-bit): two V4QI -> V4HI, or two V2HI -> V2SI.  Each lane is sign/zero
;extended then added/subtracted.
;  RV32: single real instruction pwadd.b/h, pwaddu.b/h, pwsub.b/h, pwsubu.b/h
;        (constraint Wpd,s,t: result in even-odd register pair, two scalar
;         source registers).  These are RV32-only hardware instructions.
;  RV64: no single widening add/sub instruction exists.  The spec gives
;        multi-instruction sequences (e.g. zip8p+psrai.h+psext.h.b+padd.h for
;        pwadd_i16x4, pli.h+zip16p+pm2add.h for pwadd_i32x2) that rely on
;        pm2add.h/pm2sub.h (multiply-parts-accumulate) to emulate widening
;        add/sub.  These sequences are intricate and their semantics via
;        pm2add is non-obvious, so RV64 is NOT implemented yet.
;        TODO: implement the RV64 sequences (or wait for a future RV64
;        register-pair widening extension, per proposal note).  For now the
;        builtins are simd32-only (see simd.def), so RV64 calls error out.
(define_insn "riscv_pwadd_i16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWADD_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadd.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwadd_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWADD_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwaddu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWADDU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwaddu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWADDU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwsub_i16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWSUB_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsub.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwsub_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWSUB_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsub.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwsubu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWSUBU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsubu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwsubu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWSUBU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsubu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Widening Addition and Subtraction Accumulate
;
;pwadda/pwsuba are the accumulating forms of pwadd/pwsub: they widen rs1/rs2
;(two narrow 32-bit sources) and add/sub the wide result into the corresponding
;lanes of rd (a wide 64-bit accumulator): rd += widen(rs1) +/- widen(rs2).
;  RV32: single real instruction pwadda.b/h, pwaddau.b/h, pwsuba.b/h, pwsubau.h
;        (constraint Wpd,s,t: rd_p is a read-modify-write even-odd register
;         pair, s/t are the two narrow scalar sources).  RV32-only hardware.
;  RV64: no single widening accumulate instruction; spec gives multi-insn
;        sequences (zip8p+psrai.h+psext.h.b+padd.h+padd.h, pli.h+zip16p+
;        pm2adda.h, etc.) relying on pm2adda.h (multiply-parts-accumulate).
;        NOT implemented yet.  TODO.  Builtins are simd32-only.
;
;The C prototype is pwadda_i16x4(rd, rs1, rs2) -> rd': rd is a value input
;(the accumulator base) and the function returns the updated accumulator, so
;we model it as: copy rd into the output pair, then run the RMW accumulate
;instruction on that pair.  define_expand emits the copy (emit_move_insn)
;then the RMW insn (operand 0 is "+R", read-write).
(define_expand "riscv_pwadda_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4QI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PWADDA_B))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwadda_i16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwadda_i16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+R")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWADDA_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadda.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwadda_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWADDA_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwadda_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwadda_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWADDA_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwadda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwaddau_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4QI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PWADDAU_B))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwaddau_u16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwaddau_u16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+R")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWADDAU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddau.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwaddau_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWADDAU_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwaddau_u32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwaddau_u32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWADDAU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwaddau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwsuba_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4QI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PWSUBA_B))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwsuba_i16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwsuba_i16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+R")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWSUBA_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsuba.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwsuba_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWSUBA_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwsuba_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwsuba_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWSUBA_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsuba.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwsubau_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4QI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PWSUBAU_B))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwsubau_u16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwsubau_u16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+R")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWSUBAU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsubau.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwsubau_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWSUBAU_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwsubau_u32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwsubau_u32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWSUBAU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwsubau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Widening Shift
;
;pwsll_s/pwsla_s widen one narrow source (32-bit) into a wide result (64-bit)
;and shift each widened lane left by shamt: V4QI -> V4HI, or V2HI -> V2SI.
;pwsll = logical left shift (zero-extend widen), pwsla = arithmetic left shift
;(sign-extend widen).  shamt may be an immediate or a register scalar.
;  RV32: immediate form  pwslli.b/h, pwslai.b/h  (constraint Wpd,s,WpH/<)
;        register form    pwsll.bs/hs, pwsla.bs/hs (constraint Wpd,s,t)
;        Wpd is the even-odd result pair, s the narrow source, WpH/< the uimm,
;        t the shamt register.  RV32-only hardware instructions.
;  RV64: no single widening shift instruction; spec gives multi-insn sequences
;        (pwcvtu.wb+pslli.h, etc.).  NOT implemented yet.  TODO.  Builtins are
;        simd32-only.
;The two output templates pick pwslli/pwslai when shamt is a u4/u5 immediate,
;and pwsll.bs/hs/pwsla.bs/hs when it is a register (matches the existing
;riscv_psll_s_* pattern style).
(define_insn "riscv_pwsll_s_u16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r, r")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PWSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pwslli.b\t%0,%1,%2
   pwsll.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pwsll_s_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r, r")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PWSLL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pwslli.h\t%0,%1,%2
   pwsll.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pwsla_s_i16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R, R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r, r")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PWSLA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pwslai.b\t%0,%1,%2
   pwsla.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pwsla_s_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R, R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r, r")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PWSLA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pwslai.h\t%0,%1,%2
   pwsla.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

;Packed Narrowing Shift
;
;pnsrl_s/pnsra_s/pnsrar_s narrow one wide source (64-bit) into a narrow result
;(32-bit) by shifting each lane right: V4HI -> V4QI, or V2SI -> V2HI.
;pnsrl = logical right shift (zero-extend narrow), pnsra = arithmetic right
;shift (sign-extend narrow), pnsrar = rounding arithmetic right shift.
;shamt may be an immediate or a register scalar.
;  RV32: immediate form  pnsrli.b/h, pnsrai.b/h, pnsrari.b/h (constraint d,Wps,WpH/<)
;        register form    pnsrl.bs/hs, pnsra.bs/hs, pnsrar.bs/hs (constraint d,Wps,t)
;        d is the narrow result register, Wps the wide even-odd source pair,
;        WpH/< the uimm, t the shamt register.  RV32-only hardware.
;  RV64: no single narrowing shift instruction; spec gives multi-insn sequences
;        (psrli.h+unzip8p, etc.).  NOT implemented yet.  TODO.  Builtins are
;        simd32-only.
(define_insn "riscv_pnsrl_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnsrli.b\t%0,%1,%2
   pnsrl.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnsrl_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNSRL))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnsrli.h\t%0,%1,%2
   pnsrl.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnsra_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnsrai.b\t%0,%1,%2
   pnsra.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnsra_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNSRA))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnsrai.h\t%0,%1,%2
   pnsra.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnsrar_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNSRAR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnsrari.b\t%0,%1,%2
   pnsrar.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnsrar_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNSRAR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnsrari.h\t%0,%1,%2
   pnsrar.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

;Packed Narrowing Clip
;
;pnclip* narrow one wide source (64-bit) into a narrow result (32-bit) by
;clipping (saturating to the narrow range) after a shift: V4HI -> V4QI, or
;V2SI -> V2HI.  Four variants:
;  pnclipu  = unsigned clip,            pnclipru = unsigned rounding clip
;  pnclip   = signed clip,              pnclipr  = signed rounding clip
;shamt may be an immediate or a register scalar.
;  RV32: immediate form  pnclipiu.b/h, pnclipriu.b/h, pnclipi.b/h, pnclipri.b/h
;                     (constraint d,Wps,WpH/<)
;        register form    pnclipu.bs/hs, pnclipru.bs/hs, pnclip.bs/hs,
;                         pnclipr.bs/hs  (constraint d,Wps,t)
;        d is the narrow result register, Wps the wide even-odd source pair,
;        WpH/< the uimm, t the shamt register.  RV32-only hardware.
;        Note: the immediate mnemonics carry an extra "i" (pnclipiu/pnclipi)
;        while the register mnemonics drop it (pnclipu.bs/pnclip.bs), matching
;        the binutils opcodes table.
;  RV64: no single narrowing clip instruction; spec gives multi-insn sequences
;        (psrli.h+pnclipup.b, etc.).  NOT implemented yet.  TODO.  Builtins
;        are simd32-only.
(define_insn "riscv_pnclipu_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNCLIPU))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipiu.b\t%0,%1,%2
   pnclipu.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclipu_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNCLIPU))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipiu.h\t%0,%1,%2
   pnclipu.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclipru_s_u8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNCLIPRU))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipriu.b\t%0,%1,%2
   pnclipru.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclipru_s_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNCLIPRU))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipriu.h\t%0,%1,%2
   pnclipru.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclip_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNCLIP))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipi.b\t%0,%1,%2
   pnclip.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclip_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNCLIP))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipi.h\t%0,%1,%2
   pnclip.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclipr_s_i8x4"
  [(set (match_operand:V4QI 0 "register_operand" "=r, r")
        (unspec:V4QI [(match_operand:V4HI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u4, r")]
         UNSPEC_PNCLIPR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipri.b\t%0,%1,%2
   pnclipr.bs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

(define_insn "riscv_pnclipr_s_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r, r")
        (unspec:V2HI [(match_operand:V2SI 1 "register_operand" "R, R")
                      (match_operand:SI 2 "arith_operand" "u5, r")]
         UNSPEC_PNCLIPR))]
  "TARGET_RVP && !TARGET_64BIT"
  "@
   pnclipri.h\t%0,%1,%2
   pnclipr.hs\t%0,%1,%2"
  [(set_attr "type" "simd, simd")])

;Packed Narrowing Clip Pair  -- NOT IMPLEMENTED (TODO)
;
;Spec: P-ext-intrinsics.adoc:2962 "Packed Narrowing Clip Pair".  10 intrinsics
;in two groups:
;  32-bit: pnclipp_i8x4, pnclipup_u8x4, pnclipp_i16x2, pnclipup_u16x2
;          (two narrow 32-bit sources -> one 32-bit result)
;  64-bit: pnclipp_i8x8, pnclipup_u8x8, pnclipp_i16x4, pnclipup_u16x4,
;          pnclipp_i32x2, pnclipup_u32x2
;          (two wide 64-bit sources -> one 64-bit result)
;
;Why not implemented:
;  1. The primary RV64 form is the single instruction pnclipp.b/h/w
;     (pnclipup.b/h/w for unsigned), which is a real RV64-only hardware
;     instruction per the proposal (constraint d,s,t, reads a 128-bit source
;     from rs2+rs1).  BUT binutils (opcodes/riscv-opc.c) does NOT register
;     any pnclipp/pnclipup mnemonic -- only the non-pair pnclipi/pnclipiu/
;     pnclipri/pnclipriu and their .bs/.hs register forms.  So emitting
;     pnclipp would fail at the assembler.
;  2. The RV32 form is a multi-instruction sequence (mv+mv+pnclipi.b, or
;     2x pnclipi.b for the 64-bit group).  Its semantics are unclear: a pair
;     clip takes no shift amount, yet pnclipi.b requires a WpH/< immediate
;     shamt.  The spec does not state which shamt to use (0? the element
;     width?).
;  3. The 32x2 64-bit variants use inconsistent types (int64_t rs1/rs2 rather
;     than int32x2_t) and reference an "nclipi"/"nclipiu" mnemonic (no "p"
;     prefix) for the RV32 form, which does not match the rest of the table.
;
;TODO: implement once (a) binutils gains pnclipp/pnclipup support for RV64,
;and (b) the RV32 sequence + shamt semantics are clarified.  No builtins,
;patterns, header declarations, or tests are added for this section yet.

;Packed Reverse  -- NOT IMPLEMENTED (TODO)
;
;Spec: P-ext-intrinsics.adoc:3043 "Packed Reverse".  10 intrinsics reversing
;element order in a packed vector.
;  32-bit: prev_i8x4/u8x4 (rev8 / rev8+srli), prev_i16x2/u16x2 (ppairoe.h)
;  64-bit: prev_i8x8/u8x8 (rev8 / 2x rev8), prev_i16x4/u16x4 (rev16 / 2x ppairoe.h),
;          prev_i32x2/u32x2 (ppairoe.w / 2x mv)
;
;Why not implemented:
;  1. The 8x4/8x8 forms depend on rev8, which is a ZBB/ZBKB instruction
;     (INSN_CLASS_ZBB_OR_ZBKB), not a P-ext instruction.  Using it from a
;     TARGET_RVP intrinsic crosses extension boundaries and would require
;     TARGET_ZBB_OR_ZBKB to be enabled at assemble time.
;  2. The RV64 8x4 form is rev8+srli -- the srli immediate (to adjust the
;     64-bit rev8 result down to 32-bit) needs derivation, and the RV32 8x8
;     form is 2x rev8 (how to apply 32-bit rev8 to a 64-bit source across a
;     register pair is not obvious).
;  3. The RV32 32x2 form is 2x mv (exchanging high/low words) -- pure move
;     semantics that need explicit register-pair handling.
;  4. The i16x2 forms (ppairoe.h, both ISAs) and the RV64 i32x2 form
;     (ppairoe.w) are simple single-instruction cases that COULD be done now
;     using the existing riscv_ppairoe_* patterns, but are deferred together
;     with the rest of the section for consistency.
;
;TODO: implement the simple ppairoe-based forms first, then derive the rev8
;sequences (with the ZBB dependency clarified) and the 2x mv form.  No
;builtins, patterns, header declarations, or tests are added for this section.

;Packed Multiply High
;
;pmulh* compute the high half of the product of corresponding lanes:
;  pmulh    = signed * signed,        pmulhr   = signed * signed (rounding)
;  pmulhu   = unsigned * unsigned,    pmulhru  = unsigned * unsigned (rounding)
;  pmulhsu  = signed * unsigned,      pmulhrsu = signed * unsigned (rounding)
;32-bit forms (V2HI lanes) use a single instruction on both ISAs
;(constraint d,s,t).  64-bit forms (V4HI/V2SI lanes) use a single RV64
;instruction (pmulh.h/w etc., 64-bit-only in binutils) and a 2x sequence on
;RV32 (2x pmulh.h on the high/low halves, or 2x mulh for the .w form).
;  32-bit (both ISAs): pmulh.h, pmulhr.h, pmulhu.h, pmulhru.h, pmulhsu.h,
;                       pmulhrsu.h  (constraint d,s,t)
;  64-bit RV64:        pmulh.w, pmulhr.w, pmulhu.w, pmulhru.w, pmulhsu.w,
;                       pmulhrsu.w (constraint d,s,t)
;  64-bit RV32:        2x pmulh.h / 2x mulh / etc.  NOT implemented yet.  TODO.
;pmulhsu/pmulhrsu take a signed rs1 and unsigned rs2, so their ftypes mix
;V2HI and UV2HI.
(define_insn "riscv_pmulh_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULH))]
  "TARGET_RVP"
  "pmulh.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhr_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULHR))]
  "TARGET_RVP"
  "pmulhr.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhu_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULHU))]
  "TARGET_RVP"
  "pmulhu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhru_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULHRU))]
  "TARGET_RVP"
  "pmulhru.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULHSU))]
  "TARGET_RVP"
  "pmulhsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhrsu_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULHRSU))]
  "TARGET_RVP"
  "pmulhrsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Multiply High Accumulate -- 32-bit i16x2 (both ISAs, single pmhacc.h)
;rd is RMW accumulator.  define_expand copies rd into output, then RMW insn.
(define_expand "riscv_pmhacc_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMHACC))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhacc_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhacc_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMHACC))]
  "TARGET_RVP"
  "pmhacc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhracc_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMHRACC))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhracc_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhracc_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMHRACC))]
  "TARGET_RVP"
  "pmhracc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccu_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMHACCU))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccu_u16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccu_u16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMHACCU))]
  "TARGET_RVP"
  "pmhaccu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhraccu_u16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMHRACCU))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhraccu_u16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhraccu_u16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMHRACCU))]
  "TARGET_RVP"
  "pmhraccu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMHACCSU))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccsu_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccsu_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU))]
  "TARGET_RVP"
  "pmhaccsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhraccsu_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMHRACCSU))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhraccsu_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhraccsu_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMHRACCSU))]
  "TARGET_RVP"
  "pmhraccsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Multiply High -- 64-bit forms (V4HI lanes)
;
;RV64: single instruction pmulh.h (constraint d,s,t, V4HI in one 64-bit reg).
;RV32: pmulh.h is a 32-bit instruction (2 lanes), so a 64-bit V4HI source
;(4 lanes, in an even-odd register pair) needs two pmulh.h on the low/high
;halves.  We split each V4HI operand into its low/high V2HI subregs and emit
;two pmulh.h.  The .w 32x2 forms (pmulh.w etc.) are RV64-only in binutils and
;have no RV32 single instruction -- their RV32 form would be 2x mulh (scalar),
;left as TODO.


; ---- 64-bit i16x4: RV64 single insn, RV32 2x on high/low V2HI halves.
; pmulh series (2 sources, output only).  RV32 uses force_reg before
; simplify_gen_subreg to avoid ICE on inlined non-REG operands.
(define_expand "riscv_pmulh_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULH))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulh_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulh_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulh_i16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulh_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULH))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhr_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULHR))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhr_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulhr_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhr_i16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulhr_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULHR))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhr.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULHU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhu_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulhu_u16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhu_u16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulhu_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULHU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhru_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULHRU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhru_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulhru_u16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhru_u16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulhru_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULHRU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhru.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhsu_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULHSU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhsu_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulhsu_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhsu_i16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulhsu_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULHSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhrsu_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULHRSU))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhrsu_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulhrsu_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhrsu_i16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulhrsu_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULHRSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhrsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

; pmhacc series (3 sources: rd accumulator + rs1 + rs2, RMW).  RV64-only:
; define_expand copies rd into the output reg, then runs the RMW insn.
(define_expand "riscv_pmhacc_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMHACC))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhacc_i16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhacc_i16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMHACC))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhracc_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMHRACC))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhracc_i16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhracc_i16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMHRACC))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhracc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMHACCU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccu_u16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccu_u16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMHACCU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhraccu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMHRACCU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhraccu_u16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhraccu_u16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMHRACCU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhraccu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMHACCSU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccsu_i16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccsu_i16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhraccsu_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMHRACCSU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhraccsu_i16x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhraccsu_i16x4_rmw"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMHRACCSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhraccsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

; ---- 64-bit i32x2: RV64 single pmulh.w / pmhacc.w (RV32 2x scalar TODO)
(define_insn "riscv_pmulh_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULH))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhr_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULHR))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhr.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULHU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhru_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULHRU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhru.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULHSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhrsu_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULHRSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhrsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

; pmhacc i32x2 (RV64 single, RV32 2x mhacc TODO)
(define_expand "riscv_pmhacc_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMHACC))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhacc_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhacc_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMHACC))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhracc_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMHRACC))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhracc_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhracc_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMHRACC))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhracc.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMHACCU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccu_u32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccu_u32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMHACCU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhraccu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMHRACCU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhraccu_u32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhraccu_u32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMHRACCU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhraccu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMHACCSU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccsu_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccsu_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhraccsu_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMHRACCSU))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhraccsu_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhraccsu_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMHRACCSU))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhraccsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed "Q-format" Multiplication
;
;pmulq* compute the Q-format product (scaled fixed-point multiply) of
;corresponding lanes: pmulq = plain Q-format, pmulqr = rounding Q-format.
;  i16x2 (both ISAs): pmulq.h, pmulqr.h  (constraint d,s,t)
;  i16x4 RV64: pmulq.h, pmulqr.h (single insn on V4HI).  RV32 2x pmulq.h -- TODO.
;  i32x2 RV64: pmulq.w, pmulqr.w (64-bit-only insn).  RV32 2x mulq/mulqr -- TODO.
(define_insn "riscv_pmulq_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULQ))]
  "TARGET_RVP"
  "pmulq.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulqr_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULQR))]
  "TARGET_RVP"
  "pmulqr.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulq_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULQ))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulq_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      /* RV32: pmulq.h is a 32-bit (2-lane) instruction; a 64-bit V4HI pair
         (4 lanes) needs two pmulq.h on the low/high V2HI halves.  force_reg
         each operand first so simplify_gen_subreg never sees a non-REG rtx
         (which would ICE during expand on inlined subregs/mems).  */
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulq_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulq_i16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulq_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULQ))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulq.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulqr_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULQR))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulqr_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmulqr_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulqr_i16x2 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmulqr_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULQR))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulqr.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulq_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULQ))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulq.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulqr_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULQR))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulqr.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed "Q-format" Multiply Parts Accumulate
;
;mqacc.*/mqracc.* (RV32) and pmqacc.w.*/pmqracc.w.* (RV64): Q-format multiply
;of a selected pair of halfwords (h00/h01/h11) or words (w00/w01/w11), with the
;product's middle bits accumulated RMW into rd.  mqracc.* adds a rounding bias
;before extraction.
;  h-series i32  (scalar):   RV32 mqacc.h{00,01,11}/mqracc.h{00,01,11};
;                            RV64 pmqacc.w.h{00,01,11}/pmqracc.w.h{00,01,11}.
;  h-series i32x2 (packed):  RV64 pmqacc.w.h{00,01,11}/pmqracc.w.h{00,01,11};
;                            RV32 2x mqacc.h{00,01,11}/mqracc.h{00,01,11}.
;  w-series i64  (scalar):   RV64 mqacc.w{00,01,11}/mqracc.w{00,01,11};
;                            RV32 mqwacc/mqrwacc (register pair) -- TODO.
;All variants are RMW (the instruction reads and writes rd).

;-------------------- h-series i32 (scalar SI, RMW) --------------------
;rd is the accumulator (operands[1]); it is copied to the output first, then
;the RMW insn accumulates rs1*rs2 into it.  h00 = low*low, h01 = low*high
;(rs1 low * rs2 high), h11 = high*high.
(define_expand "riscv_mqacc_h00_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQACC_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      /* RV64: pmqacc.w.h00 is a packed V2SI instruction operating on both
         32-bit lanes.  The scalar int32_t/int16x2_t values live in lane 0
         (the low 32 bits of a GPR).  Widen rs1/rs2/rd (32-bit V2HI/SI) to
         64-bit V2SI via zero-extend so the full register is owned by the
         insn; lane 1 carries junk but the int32_t result only consumes
         lane 0.  Mirrors riscv_predsum_i8x4_i32 (simd.md:1907).  */
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mqacc_h00_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mqacc_h00_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqacc_h00_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "mqacc.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqacc_h00_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqacc.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqacc_h01_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQACC_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mqacc_h01_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mqacc_h01_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqacc_h01_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H01))]
  "TARGET_RVP && !TARGET_64BIT"
  "mqacc.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqacc_h01_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqacc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqacc_h11_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQACC_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mqacc_h11_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mqacc_h11_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqacc_h11_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "mqacc.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqacc_h11_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqacc.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- mqracc (rounding) h-series i32, same structure ---
(define_expand "riscv_mqracc_h00_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQRACC_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mqracc_h00_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mqracc_h00_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqracc_h00_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "mqracc.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqracc_h00_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqracc.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqracc_h01_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQRACC_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mqracc_h01_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mqracc_h01_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqracc_h01_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H01))]
  "TARGET_RVP && !TARGET_64BIT"
  "mqracc.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqracc_h01_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqracc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqracc_h11_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQRACC_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mqracc_h11_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mqracc_h11_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqracc_h11_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "mqracc.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mqracc_h11_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqracc.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- h-series i32x2 (packed V2SI, RMW) --------------------
;RV64: single pmqacc.w.h*/pmqracc.w.h* on V2SI (operands are int32x2_t/int16x4_t).
;RV32: pmqacc.w.* is RV64-only; split the 64-bit pair into low/high SI/V2HI
;halves and run the scalar mqacc.h*/mqracc.h* on each half.
(define_expand "riscv_pmqacc_h00_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQACC_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqacc_h00_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mqacc_h00_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mqacc_h00_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqacc_h00_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqacc.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqacc_h01_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQACC_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqacc_h01_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mqacc_h01_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mqacc_h01_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqacc_h01_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqacc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqacc_h11_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQACC_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqacc_h11_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mqacc_h11_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mqacc_h11_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqacc_h11_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQACC_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqacc.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqracc_h00_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQRACC_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqracc_h00_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mqracc_h00_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mqracc_h00_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqracc_h00_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqracc.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqracc_h01_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQRACC_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqracc_h01_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mqracc_h01_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mqracc_h01_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqracc_h01_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqracc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqracc_h11_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQRACC_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqracc_h11_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mqracc_h11_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mqracc_h11_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqracc_h11_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqracc.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- w-series i64 (scalar DI, RMW; RV64-only) --------------------
;mqacc.w{00,01,11}/mqracc.w{00,01,11} multiply a selected pair of 32-bit words
;(w00=low*low, w01=low*high, w11=high*high), extract bits [94:31] of the product,
;and accumulate RMW into the 64-bit rd.  RV32 uses the register-pair mqwacc/
;mqrwacc instructions -- TODO (needs even-GPR pair allocation + int32x2_t
;low-half extraction), left RV64-only like predsum_*_i64 (simd.md:2155).
(define_expand "riscv_mqacc_w00_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQACC_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_mqacc_w00_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqacc_w00_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQACC_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "mqacc.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqacc_w01_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQACC_W01))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_mqacc_w01_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqacc_w01_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQACC_W01))]
  "TARGET_RVP && TARGET_64BIT"
  "mqacc.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqacc_w11_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQACC_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_mqacc_w11_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqacc_w11_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQACC_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "mqacc.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqracc_w00_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQRACC_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_mqracc_w00_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqracc_w00_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "mqracc.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqracc_w01_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQRACC_W01))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_mqracc_w01_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqracc_w01_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_W01))]
  "TARGET_RVP && TARGET_64BIT"
  "mqracc.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mqracc_w11_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQRACC_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_mqracc_w11_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mqracc_w11_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQRACC_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "mqracc.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;Packed Multiply Parts
;
;pmul.h.b*/pmulu.h.b*/pmulsu.h.b* multiply a selected byte pair (b00/b01/b11)
;of each 16-bit lane and produce packed 16-bit products.  mul.h*/mulu.h*/mulsu.h*
;(RV32) and pmul.w.h*/pmulu.w.h*/pmulsu.w.h* (RV64) multiply a selected halfword
;pair and produce a 32-bit product per lane.  mul.w*/mulu.w*/mulsu.w* (RV64) multiply
;a selected word pair and produce a 64-bit product.  All non-RMW (write-only rd).
;  b-series i16x2 (both ISAs): pmul.h.bNN/pmulu.h.bNN/pmulsu.h.bNN (single insn;
;    RV64 operates on 4 lanes but the V2HI result consumes the low 2 lanes).
;  b-series i16x4 (packed): RV64 single pmul.h.bNN; RV32 2x pmul.h.bNN.
;  h-series i32 (scalar): RV32 mul.hNN; RV64 pmul.w.hNN (lane 0 = result).
;  h-series i32x2 (packed): RV64 pmul.w.hNN; RV32 2x mul.hNN.
;  w-series i64 (scalar): RV64 mul.wNN; RV32 wmul/wmulu/wmulsu (register pair)
;    -- TODO.

;-------------------- b-series i16x2 (V4QI -> V2HI, single insn, both ISAs) ----
;Signed: pmul.h.bNN; unsigned: pmulu.h.bNN; signed x unsigned: pmulsu.h.bNN.
(define_insn "riscv_pmul_b00_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMUL_B00))]
  "TARGET_RVP"
  "pmul.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmul_b01_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMUL_B01))]
  "TARGET_RVP"
  "pmul.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmul_b11_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMUL_B11))]
  "TARGET_RVP"
  "pmul.h.b11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu_b00_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                       (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULU_B00))]
  "TARGET_RVP"
  "pmulu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu_b01_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                       (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULU_B01))]
  "TARGET_RVP"
  "pmulu.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulu_b11_u16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                       (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULU_B11))]
  "TARGET_RVP"
  "pmulu.h.b11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulsu_b00_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULSU_B00))]
  "TARGET_RVP"
  "pmulsu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulsu_b11_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULSU_B11))]
  "TARGET_RVP"
  "pmulsu.h.b11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- h-series i32 (V2HI -> SI scalar; RV32 mul.hNN, RV64 pmul.w.hNN) ----
;RV64: pmul.w.hNN is a packed V2SI insn; the scalar V2HI/SI values live in lane 0.
;Widen rs1/rs2 (V2HI, 32-bit) via zero-extend to DI so the full 64-bit reg is owned
;by the insn; lane 1 product is discarded.  rd (SI) takes the low 32 bits directly.
;Mirrors riscv_predsum_i8x4_i32 (simd.md:1907), non-RMW form.
(define_expand "riscv_mul_h00_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMUL_H00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mul_h00_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mul_h00_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mul_h00_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMUL_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "mul.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_h00_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMUL_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mul_h01_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMUL_H01))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mul_h01_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mul_h01_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mul_h01_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMUL_H01))]
  "TARGET_RVP && !TARGET_64BIT"
  "mul.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_h01_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMUL_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mul_h11_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMUL_H11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mul_h11_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mul_h11_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mul_h11_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMUL_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "mul.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mul_h11_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMUL_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- mulu_h* (unsigned) ---
(define_expand "riscv_mulu_h00_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                     (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMULU_H00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulu_h00_u32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulu_h00_u32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulu_h00_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                     (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULU_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulu.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_h00_u32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                     (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulu_h01_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                     (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMULU_H01))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulu_h01_u32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulu_h01_u32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulu_h01_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                     (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULU_H01))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulu.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_h01_u32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                     (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULU_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulu_h11_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                     (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMULU_H11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulu_h11_u32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulu_h11_u32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulu_h11_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                     (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULU_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulu.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulu_h11_u32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                     (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- mulsu_h* (signed x unsigned) ---
(define_expand "riscv_mulsu_h00_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMULSU_H00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulsu_h00_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulsu_h00_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulsu_h00_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULSU_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulsu_h00_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULSU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulsu_h11_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:V2HI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_PMULSU_H11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulsu_h11_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulsu_h11_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulsu_h11_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMULSU_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulsu.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulsu_h11_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULSU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- b-series i16x4 (V8QI -> V4HI; RV64 single, RV32 2x) ----
;RV32 splits the 64-bit pair into low/high V4QI/V2HI halves and runs the i16x2
;single insn on each (operands[0] V4HI subregs are valid write-only outputs).
(define_expand "riscv_pmul_b00_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMUL_B00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmul_b00_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmul_b00_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmul_b00_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmul_b00_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMUL_B00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmul_b01_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMUL_B01))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmul_b01_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmul_b01_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmul_b01_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmul_b01_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMUL_B01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmul_b11_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMUL_B11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmul_b11_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmul_b11_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmul_b11_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmul_b11_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMUL_B11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.h.b11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulu_b00_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                       (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULU_B00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulu_b00_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulu_b00_u16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulu_b00_u16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulu_b00_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                       (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULU_B00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulu_b01_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                       (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULU_B01))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulu_b01_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulu_b01_u16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulu_b01_u16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulu_b01_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                       (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULU_B01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.h.b01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulu_b11_u16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                       (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULU_B11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulu_b11_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulu_b11_u16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulu_b11_u16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulu_b11_u16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                       (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULU_B11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.h.b11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulsu_b00_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULSU_B00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulsu_b00_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulsu_b00_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulsu_b00_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulsu_b00_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULSU_B00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.h.b00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulsu_b11_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULSU_B11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulsu_b11_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulsu_b11_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulsu_b11_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulsu_b11_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULSU_B11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.h.b11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- h-series i32x2 (V4HI -> V2SI; RV64 single pmul.w.hNN, RV32 2x mul.hNN) ----
;RV32 splits the 64-bit pair into low/high SI/V2HI halves and runs the scalar
;h-series _rv32 insn on each.
(define_expand "riscv_pmul_h00_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMUL_H00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmul_h00_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mul_h00_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mul_h00_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmul_h00_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMUL_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmul_h01_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMUL_H01))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmul_h01_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mul_h01_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mul_h01_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmul_h01_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMUL_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmul_h11_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMUL_H11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmul_h11_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mul_h11_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mul_h11_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmul_h11_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMUL_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmul.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulu_h00_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                       (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULU_H00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulu_h00_u32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulu_h00_u32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulu_h00_u32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulu_h00_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                       (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulu_h01_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                       (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULU_H01))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulu_h01_u32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulu_h01_u32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulu_h01_u32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulu_h01_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                       (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULU_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulu_h11_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                       (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULU_H11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulu_h11_u32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulu_h11_u32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulu_h11_u32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulu_h11_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                       (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulsu_h00_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULSU_H00))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulsu_h00_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulsu_h00_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulsu_h00_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulsu_h00_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULSU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulsu_h11_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMULSU_H11))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulsu_h11_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulsu_h11_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulsu_h11_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulsu_h11_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMULSU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulsu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- w-series i64 (V2SI -> DI scalar; RV64-only) ----
;mul.wNN/mulu.wNN/mulsu.wNN multiply a selected word pair (w00/w01/w11) and
;produce a 64-bit product.  RV32 uses wmul/wmulu/wmulsu (register pair) -- TODO
;(needs even-GPR pair allocation), left RV64-only like mqacc_w*_i64.
(define_expand "riscv_mul_w00_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMUL_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mul_w00_i64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})
; TODO(RV32): wmul uses a register-pair destination (even GPR); needs register-pair
; allocation.  Left RV64-only, matching mqacc_w*_i64 / predsum_*_i64.

(define_insn "riscv_mul_w00_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMUL_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "mul.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mul_w01_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMUL_W01))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mul_w01_i64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mul_w01_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMUL_W01))]
  "TARGET_RVP && TARGET_64BIT"
  "mul.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mul_w11_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMUL_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mul_w11_i64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mul_w11_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMUL_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "mul.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulu_w00_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                     (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMULU_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mulu_w00_u64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulu_w00_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                     (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULU_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "mulu.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulu_w01_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                     (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMULU_W01))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mulu_w01_u64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulu_w01_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                     (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULU_W01))]
  "TARGET_RVP && TARGET_64BIT"
  "mulu.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulu_w11_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                     (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMULU_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mulu_w11_u64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulu_w11_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                     (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULU_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "mulu.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulsu_w00_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMULSU_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mulsu_w00_i64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulsu_w00_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULSU_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "mulsu.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulsu_w11_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMULSU_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_mulsu_w11_i64_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulsu_w11_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMULSU_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "mulsu.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- Packed Multiply Parts Accumulate --------------------
;Three-operand RMW: rd += (selected halfword/word pair product).
;hNN selects the halfword pair (h00=low*low, h01=low*high, h11=high*high);
;wNN selects the word pair likewise.  Structurally identical to the
;q-format mqacc/mqracc family above (simd.md:8141+); the only difference is
;no Q-format product-window extraction -- the full low 32/64-bit product is
;accumulated.  That semantic difference is carried by the hardware mnemonic;
;GCC models both as opaque unspec RMW.
;  h-series i32 (scalar): RV32 macc.hNN/maccu.hNN/maccsu.hNN;
;    RV64 pmacc.w.hNN/etc (lane 0 = result).
;  h-series i32x2 (packed): RV64 pmacc.w.hNN/etc; RV32 2x macc.hNN.
;  w-series i64 (scalar, RV64-only): macc.wNN/maccu.wNN/maccsu.wNN.
;    RV32 uses wmacc/wmaccu/wmaccsu (register pair) -- TODO, like mqacc_w.

;--- macc_h* (signed) ---
(define_expand "riscv_macc_h00_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACC_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_macc_h00_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_macc_h00_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_macc_h00_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACC_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_macc_h00_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACC_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_macc_h01_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACC_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_macc_h01_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_macc_h01_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_macc_h01_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACC_H01))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_macc_h01_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACC_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_macc_h11_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACC_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_macc_h11_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_macc_h11_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_macc_h11_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACC_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "macc.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_macc_h11_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACC_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- maccu_h* (unsigned) ---
(define_expand "riscv_maccu_h00_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACCU_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_maccu_h00_u32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_maccu_h00_u32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccu_h00_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACCU_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccu.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_maccu_h00_u32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccu_h01_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACCU_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_maccu_h01_u32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_maccu_h01_u32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccu_h01_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACCU_H01))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccu.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_maccu_h01_u32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCU_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccu_h11_u32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACCU_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_maccu_h11_u32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_maccu_h11_u32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccu_h11_u32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACCU_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccu.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_maccu_h11_u32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- maccsu_h* (signed x unsigned) ---
(define_expand "riscv_maccsu_h00_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACCSU_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_maccsu_h00_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_maccsu_h00_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccsu_h00_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACCSU_H00))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccsu.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_maccsu_h00_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCSU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccsu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccsu_h11_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MACCSU_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_maccsu_h11_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_maccsu_h11_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccsu_h11_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MACCSU_H11))]
  "TARGET_RVP && !TARGET_64BIT"
  "maccsu.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_maccsu_h11_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCSU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccsu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- h-series i32x2 (packed V2SI, RMW) ---
;RV64: single pmacc.w.h*/etc on V2SI.  RV32: split the 64-bit pair into
;low/high SI/V2HI halves and run the scalar macc.h*/etc on each half.
(define_expand "riscv_pmacc_h00_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACC_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmacc_h00_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_macc_h00_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_macc_h00_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmacc_h00_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACC_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmacc_h01_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACC_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmacc_h01_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_macc_h01_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_macc_h01_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmacc_h01_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACC_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmacc_h11_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACC_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmacc_h11_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_macc_h11_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_macc_h11_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmacc_h11_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACC_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmacc.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmaccu_h00_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACCU_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmaccu_h00_u32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_maccu_h00_u32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_maccu_h00_u32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmaccu_h00_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACCU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmaccu_h01_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACCU_H01))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmaccu_h01_u32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_maccu_h01_u32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_maccu_h01_u32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmaccu_h01_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACCU_H01))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmaccu_h11_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACCU_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmaccu_h11_u32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_maccu_h11_u32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_maccu_h11_u32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmaccu_h11_u32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACCU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmaccsu_h00_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACCSU_H00))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmaccsu_h00_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_maccsu_h00_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_maccsu_h00_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmaccsu_h00_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACCSU_H00))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccsu.w.h00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmaccsu_h11_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMACCSU_H11))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmaccsu_h11_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_maccsu_h11_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_maccsu_h11_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmaccsu_h11_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMACCSU_H11))]
  "TARGET_RVP && TARGET_64BIT"
  "pmaccsu.w.h11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- w-series i64 (scalar DI, RMW; RV64-only) ---
;macc.wNN/maccu.wNN/maccsu.wNN multiply a selected pair of 32-bit words
;(w00=low*low, w01=low*high, w11=high*high) and accumulate into the 64-bit rd.
;RV32 uses wmacc/wmaccu/wmaccsu (register pair) -- TODO (needs even-GPR pair
;allocation), left RV64-only like mqacc_w*_i64 (simd.md:8692) / mul_w*_i64.
(define_expand "riscv_macc_w00_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACC_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_macc_w00_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_macc_w00_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACC_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "macc.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_macc_w01_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACC_W01))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_macc_w01_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_macc_w01_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACC_W01))]
  "TARGET_RVP && TARGET_64BIT"
  "macc.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_macc_w11_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACC_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_macc_w11_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_macc_w11_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACC_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "macc.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccu_w00_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACCU_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_maccu_w00_u64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccu_w00_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCU_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "maccu.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccu_w01_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACCU_W01))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_maccu_w01_u64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccu_w01_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCU_W01))]
  "TARGET_RVP && TARGET_64BIT"
  "maccu.w01\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccu_w11_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACCU_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_maccu_w11_u64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccu_w11_u64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCU_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "maccu.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccsu_w00_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACCSU_W00))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_maccsu_w00_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccsu_w00_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCSU_W00))]
  "TARGET_RVP && TARGET_64BIT"
  "maccsu.w00\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_maccsu_w11_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_MACCSU_W11))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_maccsu_w11_i64_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_maccsu_w11_i64_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MACCSU_W11))]
  "TARGET_RVP && TARGET_64BIT"
  "maccsu.w11\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- Packed Multiplication with Horizontal Addition --------
;Two-operand: rs1*rs2 horizontal-add to a scalar/packed result.  Mirrors the
;Packed Q-format Multiply (pmulq_*, simd.md:8035) structure: the .b/.h/.hx
;mnemonics are single instructions on both ISAs for the 32-bit (V4QI/V2HI->SI)
;forms; the i32x2 packed forms are RV64 single / RV32 2x; the i64 forms are
;RV64 single (RV32 uses wmul+wmacc / pm2wadd sequences -- TODO, like mqacc_w).

;--- 32-bit (both ISAs, single insn): V4QI/V2HI -> SI/USI scalar ---
(define_insn "riscv_pm4add_i8x4"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4QI 1 "register_operand" "r")
                    (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PM4ADD_B))]
  "TARGET_RVP"
  "pm4add.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2add_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADD_H))]
  "TARGET_RVP"
  "pm2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2add_x_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADD_HX))]
  "TARGET_RVP"
  "pm2add.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4addu_u8x4"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4QI 1 "register_operand" "r")
                    (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDU_B))]
  "TARGET_RVP"
  "pm4addu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2addu_u16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDU_H))]
  "TARGET_RVP"
  "pm2addu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmq2add_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQ2ADD_H))]
  "TARGET_RVP"
  "pmq2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmqr2add_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQR2ADD_H))]
  "TARGET_RVP"
  "pmqr2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sadd_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2SADD_H))]
  "TARGET_RVP"
  "pm2sadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sadd_x_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2SADD_HX))]
  "TARGET_RVP"
  "pm2sadd.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sub_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2SUB_H))]
  "TARGET_RVP"
  "pm2sub.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2sub_x_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2SUB_HX))]
  "TARGET_RVP"
  "pm2sub.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm4addsu_i8x4"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V4QI 1 "register_operand" "r")
                    (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDSU_B))]
  "TARGET_RVP"
  "pm4addsu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2addsu_i16x2"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDSU_H))]
  "TARGET_RVP"
  "pm2addsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- 64-bit i32x2 (packed): RV64 single insn; RV32 2x split into low/high ---
;RV64: single pm4add.b/pm2add.h/etc on the full 64-bit vector.  RV32: split
;the 64-bit pair into low/high V4QI/V2HI halves and run the scalar 32-bit
;insn on each (mirrors riscv_pmulq_i16x4, simd.md:8053).
(define_expand "riscv_pm4add_i8x8"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PM4ADD_I8X8))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm4add_i8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pm4add_i8x4 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm4add_i8x4 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm4add_i8x8_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PM4ADD_I8X8))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4add.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2add_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2ADD_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2add_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2add_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2add_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2add_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADD_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2add_x_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2ADD_X_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2add_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2add_x_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2add_x_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2add_x_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADD_X_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2add.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addu_u8x8"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PM4ADDU_U8X8))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm4addu_u8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pm4addu_u8x4 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm4addu_u8x4 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm4addu_u8x8_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDU_U8X8))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addu_u16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2ADDU_U16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2addu_u16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2addu_u16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2addu_u16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2addu_u16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDU_U16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmq2add_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMQ2ADD_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmq2add_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmq2add_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmq2add_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmq2add_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQ2ADD_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pmq2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqr2add_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PMQR2ADD_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqr2add_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmqr2add_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmqr2add_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmqr2add_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQR2ADD_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqr2add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2sadd_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2SADD_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2sadd_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2sadd_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2sadd_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2sadd_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2SADD_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2sadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2sadd_x_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2SADD_X_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2sadd_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2sadd_x_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2sadd_x_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2sadd_x_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2SADD_X_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2sadd.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2sub_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2SUB_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2sub_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2sub_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2sub_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2sub_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2SUB_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2sub.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2sub_x_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2SUB_X_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2sub_x_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2sub_x_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2sub_x_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2sub_x_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2SUB_X_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2sub.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addsu_i8x8"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PM4ADDSU_I8X8))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm4addsu_i8x8_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V8QImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pm4addsu_i8x4 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm4addsu_i8x4 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm4addsu_i8x8_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDSU_I8X8))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addsu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addsu_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM2ADDSU_I16X4))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2addsu_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2addsu_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2addsu_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pm2addsu_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDSU_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- 64-bit i64 (scalar DI/UDI; RV64-only) ---
;pm2add.w/pm2add.wx/pm2addu.w/pmq2add.w/pm2sub.w/pm2sub.wx/pm2addsu.w/pmqr2add.w
;take a V2SI pair, horizontally multiply+add the two words, produce a 64-bit
;result.  pm4add.h/pm4addu.h/pm4addsu.h take a V4HI pair -> 64-bit.  RV32 uses
;wmul+wmacc / pm2wadd sequences -- TODO (needs even-GPR pair allocation / the
;pm2wadd insn family), left RV64-only like mqacc_w / macc_w (simd.md:8692).
(define_expand "riscv_pm2add_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PM2ADD_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm2add_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm2add_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADD_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2add_x_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PM2ADD_WX))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm2add_x_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm2add_x_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADD_WX))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2add.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addu_u32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PM2ADDU_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm2addu_u32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm2addu_u32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADDU_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmq2add_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMQ2ADD_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pmq2add_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmq2add_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQ2ADD_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pmq2add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2sub_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PM2SUB_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm2sub_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm2sub_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2SUB_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2sub.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2sub_x_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PM2SUB_WX))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm2sub_x_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm2sub_x_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2SUB_WX))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2sub.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addsu_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PM2ADDSU_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm2addsu_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm2addsu_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADDSU_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addsu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqr2add_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V2SI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")]
         UNSPEC_PMQR2ADD_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pmqr2add_i32x2_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pmqr2add_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQR2ADD_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqr2add.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4add_i16x4"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM4ADD_H))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm4add_i16x4_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm4add_i16x4_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V4HI 1 "register_operand" "r")
                    (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM4ADD_H))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4add.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addu_u16x4"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM4ADDU_H))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm4addu_u16x4_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm4addu_u16x4_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V4HI 1 "register_operand" "r")
                    (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM4ADDU_H))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addsu_i16x4"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:V4HI 1 "register_operand")
                    (match_operand:V4HI 2 "register_operand")]
         UNSPEC_PM4ADDSU_H))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_insn (gen_riscv_pm4addsu_i16x4_rv64 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_pm4addsu_i16x4_rv64"
  [(set (match_operand:DI 0 "register_operand" "=r")
        (unspec:DI [(match_operand:V4HI 1 "register_operand" "r")
                    (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM4ADDSU_H))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------- Packed Multiplication with Horizontal Addition and Accumulate ---
;Three-operand RMW: rd += (rs1 op rs2) horizontal.  Mirrors the pm2add/pm4add
;family above (simd.md:10967) plus an RMW accumulator, structurally identical
;to the Packed Multiply High Accumulate pmhacc series (simd.md:7363).
;  32-bit (both ISAs, single insn): pm4adda.b/pm2adda.h/etc, RMW into SI/USI.
;  64-bit i32x2 (packed, RMW): RV64 single pm2adda.h/etc; RV32 2x.
;  64-bit i64 (RV64-only, RMW): pm2adda.w/etc, pm4adda.h/etc.
;    RV32 uses wmacc/pm2wadda sequences -- TODO, like mqacc_w / macc_w.

;--- 32-bit (both ISAs, single insn, RMW): V4QI/V2HI -> SI/USI ---
(define_expand "riscv_pm4adda_i8x4"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V4QI 2 "register_operand")
                    (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PM4ADDA_B))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm4adda_i8x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm4adda_i8x4_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V4QI 1 "register_operand" "r")
                    (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDA_B))]
  "TARGET_RVP"
  "pm4adda.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2adda_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2ADDA_H))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2adda_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2adda_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDA_H))]
  "TARGET_RVP"
  "pm2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2adda_x_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2ADDA_HX))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2adda_x_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2adda_x_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDA_HX))]
  "TARGET_RVP"
  "pm2adda.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addau_u8x4"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V4QI 2 "register_operand")
                    (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PM4ADDAU_B))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm4addau_u8x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm4addau_u8x4_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V4QI 1 "register_operand" "r")
                    (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDAU_B))]
  "TARGET_RVP"
  "pm4addau.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addau_u16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2ADDAU_H))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2addau_u16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2addau_u16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDAU_H))]
  "TARGET_RVP"
  "pm2addau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmq2adda_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQ2ADDA_H))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmq2adda_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmq2adda_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQ2ADDA_H))]
  "TARGET_RVP"
  "pmq2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqr2adda_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQR2ADDA_H))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmqr2adda_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmqr2adda_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQR2ADDA_H))]
  "TARGET_RVP"
  "pmqr2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2suba_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2SUBA_H))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2suba_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2suba_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2SUBA_H))]
  "TARGET_RVP"
  "pm2suba.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2suba_x_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2SUBA_HX))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2suba_x_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2suba_x_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2SUBA_HX))]
  "TARGET_RVP"
  "pm2suba.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addasu_i8x4"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V4QI 2 "register_operand")
                    (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PM4ADDASU_B))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm4addasu_i8x4_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm4addasu_i8x4_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V4QI 1 "register_operand" "r")
                    (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDASU_B))]
  "TARGET_RVP"
  "pm4addasu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addasu_i16x2"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2ADDASU_H))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2addasu_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2addasu_i16x2_rmw"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDASU_H))]
  "TARGET_RVP"
  "pm2addasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- 64-bit i32x2 (packed, RMW): RV64 single; RV32 2x split low/high ---
;RV64: single pm4adda.b/pm2adda.h/etc on V2SI accumulator.  RV32: split the
;64-bit pair into low/high V4QI/V2HI halves and run the scalar RMW insn on
;each (mirrors riscv_pmqacc_h00_i32x2, simd.md:8452).
(define_expand "riscv_pm4adda_i8x8"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PM4ADDA_I8X8))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm4adda_i8x8_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V8QImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pm4adda_i8x4_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm4adda_i8x4_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm4adda_i8x8_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDA_I8X8))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4adda.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2adda_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM2ADDA_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2adda_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2adda_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2adda_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm2adda_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDA_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2adda_x_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM2ADDA_X_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2adda_x_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2adda_x_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2adda_x_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm2adda_x_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDA_X_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2adda.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addau_u8x8"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PM4ADDAU_U8X8))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm4addau_u8x8_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V8QImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pm4addau_u8x4_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm4addau_u8x4_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm4addau_u8x8_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDAU_U8X8))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addau.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addau_u16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM2ADDAU_U16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2addau_u16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2addau_u16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2addau_u16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm2addau_u16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDAU_U16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmq2adda_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQ2ADDA_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmq2adda_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmq2adda_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmq2adda_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmq2adda_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQ2ADDA_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pmq2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqr2adda_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PMQR2ADDA_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmqr2adda_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pmqr2adda_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmqr2adda_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmqr2adda_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PMQR2ADDA_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqr2adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2suba_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM2SUBA_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2suba_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2suba_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2suba_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm2suba_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2SUBA_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2suba.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2suba_x_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM2SUBA_X_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2suba_x_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2suba_x_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2suba_x_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm2suba_x_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2SUBA_X_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2suba.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addasu_i8x8"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PM4ADDASU_I8X8))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm4addasu_i8x8_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V8QImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V4QImode, r1, V8QImode, 0);
      rtx s1_hi = simplify_gen_subreg (V4QImode, r1, V8QImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pm4addasu_i8x4_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm4addasu_i8x4_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm4addasu_i8x8_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V8QI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PM4ADDASU_I8X8))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addasu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addasu_i16x4"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM2ADDASU_I16X4))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pm2addasu_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_pm2addasu_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pm2addasu_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pm2addasu_i16x4_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM2ADDASU_I16X4))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- 64-bit i64 (scalar DI/UDI, RMW; RV64-only) ---
;pm2adda.w/pm2adda.wx/pm2addau.w/pmq2adda.w/pm2suba.w/pm2suba.wx/pm2addasu.w/
;pmqr2adda.w accumulate into a 64-bit rd from a V2SI pair; pm4adda.h/pm4addau.h/
;pm4addasu.h from a V4HI pair.  RV32 uses wmacc/pm2wadda sequences -- TODO
;(needs even-GPR pair allocation / the pm2wadda insn family), left RV64-only
;like mqacc_w / macc_w / pm2add_w (simd.md:11540).
(define_expand "riscv_pm2adda_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PM2ADDA_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2adda_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2adda_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADDA_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2adda.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2adda_x_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PM2ADDA_WX))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2adda_x_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2adda_x_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADDA_WX))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2adda.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addau_u32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PM2ADDAU_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2addau_u32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2addau_u32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADDAU_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addau.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmq2adda_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQ2ADDA_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmq2adda_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmq2adda_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQ2ADDA_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pmq2adda.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2suba_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PM2SUBA_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2suba_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2suba_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2SUBA_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2suba.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2suba_x_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PM2SUBA_WX))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2suba_x_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2suba_x_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2SUBA_WX))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2suba.wx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2addasu_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PM2ADDASU_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2addasu_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2addasu_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PM2ADDASU_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pm2addasu.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqr2adda_i32x2"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2SI 2 "register_operand")
                    (match_operand:V2SI 3 "register_operand")]
         UNSPEC_PMQR2ADDA_W))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmqr2adda_i32x2_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmqr2adda_i32x2_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_PMQR2ADDA_W))]
  "TARGET_RVP && TARGET_64BIT"
  "pmqr2adda.w\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4adda_i16x4"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V4HI 2 "register_operand")
                    (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM4ADDA_H))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm4adda_i16x4_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm4adda_i16x4_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V4HI 1 "register_operand" "r")
                    (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM4ADDA_H))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4adda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addau_u16x4"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V4HI 2 "register_operand")
                    (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM4ADDAU_H))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm4addau_u16x4_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm4addau_u16x4_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V4HI 1 "register_operand" "r")
                    (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM4ADDAU_H))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm4addasu_i16x4"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V4HI 2 "register_operand")
                    (match_operand:V4HI 3 "register_operand")]
         UNSPEC_PM4ADDASU_H))]
  "TARGET_RVP && TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm4addasu_i16x4_rv64 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm4addasu_i16x4_rv64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec:DI [(match_dup 0)
                    (match_operand:V4HI 1 "register_operand" "r")
                    (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_PM4ADDASU_H))]
  "TARGET_RVP && TARGET_64BIT"
  "pm4addasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- Packed Multiply High Parts -------------------------
;Two-operand high-half multiply.  Structurally identical to the Packed
;Multiply Parts family (simd.md:8847+): .b selects byte 0/1, .h selects
;halfword 0/1; the product's high half is taken (vs. Packed Multiply Parts
;which uses the full product via bNN/hNN word-pair selection).
;  b-series i16x2 (both ISAs, single insn): pmulh.h.bN/pmulhsu.h.bN.
;  h-series i32 (scalar): RV32 mulh.hN/mulhsu.hN, RV64 pmulh.w.hN/etc.
;  b-series i16x4 (packed): RV64 single, RV32 2x.
;  h-series i32x2 (packed): RV64 pmulh.w.hN, RV32 2x mulh.hN.

;--- b-series i16x2 (V2HI, V4QI -> V2HI; single insn, both ISAs) ---
(define_insn "riscv_pmulh_b0_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULH_B0))]
  "TARGET_RVP"
  "pmulh.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulh_b1_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULH_B1))]
  "TARGET_RVP"
  "pmulh.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_b0_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULHSU_B0))]
  "TARGET_RVP"
  "pmulhsu.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pmulhsu_b1_i16x2"
  [(set (match_operand:V2HI 0 "register_operand" "=r")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMULHSU_B1))]
  "TARGET_RVP"
  "pmulhsu.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- h-series i32 (scalar SI; RV32 mulh.hN, RV64 pmulh.w.hN) ---
;RV64: pmulh.w.hN is a packed V2SI insn; the scalar SI/int16x2_t values live
;in lane 0.  Widen rs1/rs2 (32-bit SI/V2HI) to 64-bit V2SI via zero-extend so
;the full register is owned by the insn; lane 1 product is discarded.  rd (SI)
;takes the low 32 bits.  Mirrors riscv_mul_h00_i32 (simd.md:8924).
(define_expand "riscv_mulh_h0_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_MULH_H0))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulh_h0_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulh_h0_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulh_h0_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MULH_H0))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulh.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulh_h0_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MULH_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulh_h1_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_MULH_H1))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulh_h1_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulh_h1_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulh_h1_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MULH_H1))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulh.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulh_h1_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MULH_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulhsu_h0_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_MULHSU_H0))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulhsu_h0_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulhsu_h0_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulhsu_h0_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MULHSU_H0))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulhsu.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhsu_h0_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MULHSU_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mulhsu_h1_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")]
         UNSPEC_MULHSU_H1))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    {
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[1]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      emit_insn (gen_riscv_mulhsu_h1_i32_rv64
		   (operands[0],
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
    }
  else
    emit_insn (gen_riscv_mulhsu_h1_i32_rv32 (operands[0], operands[1], operands[2]));
  DONE;
})

(define_insn "riscv_mulhsu_h1_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MULHSU_H1))]
  "TARGET_RVP && !TARGET_64BIT"
  "mulhsu.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mulhsu_h1_i32_rv64"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (unspec:SI [(match_operand:V2SI 1 "register_operand" "r")
                    (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MULHSU_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- b-series i16x4 (packed V8QI -> V4HI; RV64 single, RV32 2x) ---
;RV64: single pmulh.h.bN/pmulhsu.h.bN on the full 64-bit vector.  RV32: split
;the 64-bit pair into low/high V4QI/V2HI halves and run the i16x2 insn on each
;(mirrors riscv_pmul_b00_i16x4, simd.md:9273).
(define_expand "riscv_pmulh_b0_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULH_B0))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulh_b0_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulh_b0_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulh_b0_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulh_b0_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULH_B0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulh_b1_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULH_B1))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulh_b1_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulh_b1_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulh_b1_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulh_b1_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULH_B1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhsu_b0_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULHSU_B0))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhsu_b0_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulhsu_b0_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhsu_b0_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulhsu_b0_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULHSU_B0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhsu_b1_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V8QI 2 "register_operand")]
         UNSPEC_PMULHSU_B1))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhsu_b1_i16x4_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V4HImode, operands[1]);
      rtx r2 = force_reg (V8QImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, operands[0], V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmulhsu_b1_i16x2 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmulhsu_b1_i16x2 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulhsu_b1_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMULHSU_B1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- h-series i32x2 (packed V4HI -> V2SI; RV64 pmulh.w.hN, RV32 2x mulh.hN) ---
(define_expand "riscv_pmulh_h0_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_MULH_H0))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulh_h0_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V2SImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulh_h0_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulh_h0_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulh_h0_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MULH_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulh_h1_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_MULH_H1))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulh_h1_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V2SImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulh_h1_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulh_h1_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulh_h1_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MULH_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulh.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhsu_h0_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_MULHSU_H0))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhsu_h0_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V2SImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulhsu_h0_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulhsu_h0_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulhsu_h0_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MULHSU_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmulhsu_h1_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")]
         UNSPEC_MULHSU_H1))]
  "TARGET_RVP"
{
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmulhsu_h1_i32x2_rv64 (operands[0], operands[1], operands[2]));
  else
    {
      rtx r1 = force_reg (V2SImode, operands[1]);
      rtx r2 = force_reg (V4HImode, operands[2]);
      rtx d_lo = simplify_gen_subreg (SImode, operands[0], V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, operands[0], V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mulhsu_h1_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mulhsu_h1_i32_rv32 (d_hi, s1_hi, s2_hi));
    }
  DONE;
})

(define_insn "riscv_pmulhsu_h1_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MULHSU_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmulhsu.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------- Packed Multiply High Parts Accumulate ---------------------------
;Three-operand RMW: rd += (high-half product of selected byte/halfword pair).
;Mirrors the Packed Multiply High Parts family above (simd.md:12760) plus an
;RMW accumulator, structurally identical to the Packed Multiply High
;Accumulate pmhacc series (simd.md:7404) and the mqacc_* RMW accumulators.
;  b-series i16x2 (both ISAs, single RMW insn): pmhacc.h.bN/pmhaccsu.h.bN.
;  h-series i32 (scalar, RMW): RV32 mhacc.hN/mhaccsu.hN, RV64 pmhacc.w.hN/etc.
;  b-series i16x4 (packed, RMW): RV64 single, RV32 2x.
;  h-series i32x2 (packed, RMW): RV64 pmhacc.w.hN, RV32 2x mhacc.hN.

;--- b-series i16x2 (V2HI rd accumulator; single RMW insn, both ISAs) ---
(define_expand "riscv_pmhacc_b0_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PMHACC_B0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhacc_b0_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhacc_b0_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMHACC_B0))]
  "TARGET_RVP"
  "pmhacc.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhacc_b1_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PMHACC_B1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhacc_b1_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhacc_b1_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMHACC_B1))]
  "TARGET_RVP"
  "pmhacc.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_b0_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PMHACCSU_B0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccsu_b0_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccsu_b0_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU_B0))]
  "TARGET_RVP"
  "pmhaccsu.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_b1_i16x2"
  [(set (match_operand:V2HI 0 "register_operand")
        (unspec:V2HI [(match_operand:V2HI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V4QI 3 "register_operand")]
         UNSPEC_PMHACCSU_B1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmhaccsu_b1_i16x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmhaccsu_b1_i16x2_rmw"
  [(set (match_operand:V2HI 0 "register_operand" "+r")
        (unspec:V2HI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU_B1))]
  "TARGET_RVP"
  "pmhaccsu.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- h-series i32 (scalar SI RMW; RV32 mhacc.hN, RV64 pmhacc.w.hN) ---
;RV64: pmhacc.w.hN is a packed V2SI insn; the scalar SI values live in lane 0.
;Widen rs1/rs2 (32-bit SI/V2HI) to 64-bit V2SI via zero-extend so the full
;register is owned by the insn; lane 1 product is discarded.  Mirrors
;riscv_mqacc_h00_i32 (simd.md:8141).
(define_expand "riscv_mhacc_h0_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MHACC_H0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mhacc_h0_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mhacc_h0_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mhacc_h0_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MHACC_H0))]
  "TARGET_RVP && !TARGET_64BIT"
  "mhacc.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mhacc_h0_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MHACC_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mhacc_h1_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MHACC_H1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mhacc_h1_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mhacc_h1_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mhacc_h1_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MHACC_H1))]
  "TARGET_RVP && !TARGET_64BIT"
  "mhacc.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mhacc_h1_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MHACC_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mhaccsu_h0_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MHACCSU_H0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mhaccsu_h0_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mhaccsu_h0_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mhaccsu_h0_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MHACCSU_H0))]
  "TARGET_RVP && !TARGET_64BIT"
  "mhaccsu.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mhaccsu_h0_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MHACCSU_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_mhaccsu_h1_i32"
  [(set (match_operand:SI 0 "register_operand")
        (unspec:SI [(match_operand:SI 1 "register_operand")
                    (match_operand:SI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_MHACCSU_H1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    {
      rtx acc = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2 (acc, operands[0]));
      rtx r1 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r1, force_reg (SImode, gen_lowpart (SImode, operands[2]))));
      rtx r2 = gen_reg_rtx (DImode);
      emit_insn (gen_zero_extendsidi2
		   (r2, force_reg (SImode, gen_lowpart (SImode, operands[3]))));
      emit_insn (gen_riscv_mhaccsu_h1_i32_rv64
		   (gen_lowpart (V2SImode, acc),
		    gen_lowpart (V2SImode, r1),
		    gen_lowpart (V2SImode, r2)));
      emit_move_insn (operands[0], gen_lowpart (SImode, acc));
    }
  else
    emit_insn (gen_riscv_mhaccsu_h1_i32_rv32 (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_mhaccsu_h1_i32_rv32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec:SI [(match_dup 0)
                    (match_operand:SI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_MHACCSU_H1))]
  "TARGET_RVP && !TARGET_64BIT"
  "mhaccsu.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_mhaccsu_h1_i32_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V2SI 2 "register_operand" "r")]
         UNSPEC_MHACCSU_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- b-series i16x4 (packed V4HI rd RMW; RV64 single, RV32 2x) ---
;RV64: single pmhacc.h.bN/pmhaccsu.h.bN on the full 64-bit vector.  RV32: split
;the 64-bit pair into low/high V2HI/V4QI halves and run the i16x2 RMW insn on
;each (mirrors riscv_pmqacc_h00_i32x2, simd.md:8452).
(define_expand "riscv_pmhacc_b0_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PMHACC_B0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhacc_b0_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmhacc_b0_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmhacc_b0_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhacc_b0_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMHACC_B0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhacc_b1_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PMHACC_B1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhacc_b1_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmhacc_b1_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmhacc_b1_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhacc_b1_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMHACC_B1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_b0_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PMHACCSU_B0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhaccsu_b0_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmhaccsu_b0_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmhaccsu_b0_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhaccsu_b0_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU_B0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.h.b0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_b1_i16x4"
  [(set (match_operand:V4HI 0 "register_operand")
        (unspec:V4HI [(match_operand:V4HI 1 "register_operand")
                      (match_operand:V4HI 2 "register_operand")
                      (match_operand:V8QI 3 "register_operand")]
         UNSPEC_PMHACCSU_B1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhaccsu_b1_i16x4_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V4HImode, operands[0]);
      rtx r1 = force_reg (V4HImode, operands[2]);
      rtx r2 = force_reg (V8QImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (V2HImode, r0, V4HImode, 0);
      rtx d_hi = simplify_gen_subreg (V2HImode, r0, V4HImode, 4);
      rtx s1_lo = simplify_gen_subreg (V2HImode, r1, V4HImode, 0);
      rtx s1_hi = simplify_gen_subreg (V2HImode, r1, V4HImode, 4);
      rtx s2_lo = simplify_gen_subreg (V4QImode, r2, V8QImode, 0);
      rtx s2_hi = simplify_gen_subreg (V4QImode, r2, V8QImode, 4);
      emit_insn (gen_riscv_pmhaccsu_b1_i16x2_rmw (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_pmhaccsu_b1_i16x2_rmw (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhaccsu_b1_i16x4_rv64"
  [(set (match_operand:V4HI 0 "register_operand" "+r")
        (unspec:V4HI [(match_dup 0)
                      (match_operand:V4HI 1 "register_operand" "r")
                      (match_operand:V8QI 2 "register_operand" "r")]
         UNSPEC_PMHACCSU_B1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.h.b1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;--- h-series i32x2 (packed V2SI rd RMW; RV64 pmhacc.w.hN, RV32 2x mhacc.hN) ---
(define_expand "riscv_pmhacc_h0_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_MHACC_H0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhacc_h0_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V2SImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mhacc_h0_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mhacc_h0_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhacc_h0_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MHACC_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhacc_h1_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_MHACC_H1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhacc_h1_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V2SImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mhacc_h1_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mhacc_h1_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhacc_h1_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MHACC_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhacc.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_h0_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_MHACCSU_H0))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhaccsu_h0_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V2SImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mhaccsu_h0_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mhaccsu_h0_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhaccsu_h0_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MHACCSU_H0))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.w.h0\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmhaccsu_h1_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2SI 2 "register_operand")
                      (match_operand:V4HI 3 "register_operand")]
         UNSPEC_MHACCSU_H1))]
  "TARGET_RVP"
{
  emit_move_insn (operands[0], operands[1]);
  if (TARGET_64BIT)
    emit_insn (gen_riscv_pmhaccsu_h1_i32x2_rv64 (operands[0], operands[2], operands[3]));
  else
    {
      rtx r0 = force_reg (V2SImode, operands[0]);
      rtx r1 = force_reg (V2SImode, operands[2]);
      rtx r2 = force_reg (V4HImode, operands[3]);
      rtx d_lo = simplify_gen_subreg (SImode, r0, V2SImode, 0);
      rtx d_hi = simplify_gen_subreg (SImode, r0, V2SImode, 4);
      rtx s1_lo = simplify_gen_subreg (SImode, r1, V2SImode, 0);
      rtx s1_hi = simplify_gen_subreg (SImode, r1, V2SImode, 4);
      rtx s2_lo = simplify_gen_subreg (V2HImode, r2, V4HImode, 0);
      rtx s2_hi = simplify_gen_subreg (V2HImode, r2, V4HImode, 4);
      emit_insn (gen_riscv_mhaccsu_h1_i32_rv32 (d_lo, s1_lo, s2_lo));
      emit_insn (gen_riscv_mhaccsu_h1_i32_rv32 (d_hi, s1_hi, s2_hi));
      emit_move_insn (operands[0], r0);
    }
  DONE;
})

(define_insn "riscv_pmhaccsu_h1_i32x2_rv64"
  [(set (match_operand:V2SI 0 "register_operand" "+r")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2SI 1 "register_operand" "r")
                      (match_operand:V4HI 2 "register_operand" "r")]
         UNSPEC_MHACCSU_H1))]
  "TARGET_RVP && TARGET_64BIT"
  "pmhaccsu.w.h1\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- Packed Widening Multiply ----------------------------
;Two-operand widening multiply: V4QI->V4HI / V2HI->V2SI.  RV32 has single
;insns (pwmul.b/pwmul.h/pwmulu.*/pwmulsu.*) producing a 64-bit result in a
;register pair (=R).  RV64 has no single widening-mul insn; the spec sequences
;(zip8p+pmul.h.b01 / zip16p+pmul.w.h01 / pwcvtu+pmulsu.h.b00) are not yet
;wired here -- builtins are simd32-only (see simd.def), so RV64 calls error
;out, matching the existing pwadd/pwsub family (simd.md:6758+).

(define_insn "riscv_pwmul_i16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWMUL_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmul.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwmul_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWMUL_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmul.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwmulu_u16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWMULU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmulu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwmulu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWMULU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmulu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwmulsu_i16x4"
  [(set (match_operand:V4HI 0 "register_operand" "=R")
        (unspec:V4HI [(match_operand:V4QI 1 "register_operand" "r")
                      (match_operand:V4QI 2 "register_operand" "r")]
         UNSPEC_PWMULSU_B))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmulsu.b\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pwmulsu_i32x2"
  [(set (match_operand:V2SI 0 "register_operand" "=R")
        (unspec:V2SI [(match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWMULSU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmulsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------------------- Packed Widening Multiply Accumulate ------------------
;Three-operand RMW widening accumulate: rd (V2SI/UV2SI) += (rs1 * rs2) where
;rs1/rs2 are V2HI/UV2HI (the product widens to 32-bit).  RV32 has single RMW
;insns (pwmacc.h/pwmaccu.h/pwmaccsu.h) using a register pair (=R).  RV64 has
;no single widening-mul-accumulate insn; the spec sequences (zip16p+pmacc.w.h01
; / pwcvtu+pmaccsu.w.h00) are not yet wired -- builtins are simd32-only, so RV64
;calls error out, matching the existing pwadda/pwsuba family (simd.md:6854+).

(define_expand "riscv_pwmacc_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWMACC_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwmacc_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwmacc_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWMACC_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmacc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwmaccu_u32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWMACCU_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwmaccu_u32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwmaccu_u32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWMACCU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmaccu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pwmaccsu_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PWMACCSU_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pwmaccsu_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pwmaccsu_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PWMACCSU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pwmaccsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------- Packed "Q-format" Multiply with Widening Accumulate -------------
;Three-operand RMW widening Q-format accumulate: rd (V2SI) += Q(rs1*rs2) where
;rs1/rs2 are V2HI (product widens to 32-bit).  RV32 single RMW insns
;(pmqwacc.h/pmqrwacc.h) using a register pair (=R).  RV64 sequences
;(zip16p+pmqacc.w.h01 / zip16p+pmqracc.w.h01) not wired -- simd32-only, RV64
;errors out, matching pwmacc / pwadda.

(define_expand "riscv_pmqwacc_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQWACC_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmqwacc_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmqwacc_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQWACC_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmqwacc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pmqrwacc_i32x2"
  [(set (match_operand:V2SI 0 "register_operand")
        (unspec:V2SI [(match_operand:V2SI 1 "register_operand")
                      (match_operand:V2HI 2 "register_operand")
                      (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PMQRWACC_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pmqrwacc_i32x2_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pmqrwacc_i32x2_rmw"
  [(set (match_operand:V2SI 0 "register_operand" "+R")
        (unspec:V2SI [(match_dup 0)
                      (match_operand:V2HI 1 "register_operand" "r")
                      (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PMQRWACC_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pmqrwacc.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------- Packed Multiplication with Widening Horizontal Addition ----------
;Two-operand widening mul+horizontal-add: V2HI -> DI (64-bit result in a
;register pair, =R).  RV32 single insns (pm2wadd.h/pm2wadd.hx/pm2waddu.h/
;pm2wsub.h/pm2wsub.hx/pm2waddsu.h).  RV64 sequences (zext.w+pm4add.h / etc.)
;not wired -- simd32-only, RV64 errors out, matching pwmul / pwadd.

(define_insn "riscv_pm2wadd_i64"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADD_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wadd.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2wadd_x_i64"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADD_HX))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wadd.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2waddu_u64"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADDU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2waddu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2wsub_i64"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WSUB_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wsub.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2wsub_x_i64"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WSUB_HX))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wsub.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_insn "riscv_pm2waddsu_u64"
  [(set (match_operand:DI 0 "register_operand" "=R")
        (unspec:DI [(match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADDSU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2waddsu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

;-------- Packed Multiplication with Widening Horizontal Addition and Accumulate
;Three-operand RMW widening mul+horizontal-add accumulate: rd (DI/UDI) +=
;(rs1 * rs2) widened where rs1/rs2 are V2HI/UV2HI.  RV32 single RMW insns
;(pm2wadda.h/pm2wadda.hx/pm2waddau.h/pm2wsuba.h/pm2wsuba.hx/pm2waddasu.h)
;using a register pair (+R).  RV64 sequences (zext.w+pm4adda.h / etc.) not
;wired -- simd32-only, RV64 errors out, matching pm2wadd / pwmacc.

(define_expand "riscv_pm2wadda_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2WADDA_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2wadda_i64_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2wadda_i64_rmw"
  [(set (match_operand:DI 0 "register_operand" "+R")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADDA_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wadda.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2wadda_x_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2WADDA_HX))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2wadda_x_i64_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2wadda_x_i64_rmw"
  [(set (match_operand:DI 0 "register_operand" "+R")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADDA_HX))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wadda.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2waddau_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2WADDAU_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2waddau_u64_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2waddau_u64_rmw"
  [(set (match_operand:DI 0 "register_operand" "+R")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADDAU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2waddau.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2wsuba_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2WSUBA_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2wsuba_i64_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2wsuba_i64_rmw"
  [(set (match_operand:DI 0 "register_operand" "+R")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WSUBA_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wsuba.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2wsuba_x_i64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2WSUBA_HX))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2wsuba_x_i64_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2wsuba_x_i64_rmw"
  [(set (match_operand:DI 0 "register_operand" "+R")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WSUBA_HX))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2wsuba.hx\t%0,%1,%2"
  [(set_attr "type" "simd")])

(define_expand "riscv_pm2waddasu_u64"
  [(set (match_operand:DI 0 "register_operand")
        (unspec:DI [(match_operand:DI 1 "register_operand")
                    (match_operand:V2HI 2 "register_operand")
                    (match_operand:V2HI 3 "register_operand")]
         UNSPEC_PM2WADDASU_H))]
  "TARGET_RVP && !TARGET_64BIT"
{
  emit_move_insn (operands[0], operands[1]);
  emit_insn (gen_riscv_pm2waddasu_u64_rmw (operands[0], operands[2], operands[3]));
  DONE;
})

(define_insn "riscv_pm2waddasu_u64_rmw"
  [(set (match_operand:DI 0 "register_operand" "+R")
        (unspec:DI [(match_dup 0)
                    (match_operand:V2HI 1 "register_operand" "r")
                    (match_operand:V2HI 2 "register_operand" "r")]
         UNSPEC_PM2WADDASU_H))]
  "TARGET_RVP && !TARGET_64BIT"
  "pm2waddasu.h\t%0,%1,%2"
  [(set_attr "type" "simd")])

