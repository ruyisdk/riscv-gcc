;; Typed intrinsic patterns for the RISC-V AME/Ztt extension.
;; Copyright (C) 2026 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify it under
;; the terms of the GNU General Public License as published by the Free
;; Software Foundation; either version 3, or (at your option) any later
;; version.

;; These patterns model fixed P0 and runtime-N profiles; see README.ztt.
;; Logical concatenations are expanded
;; into complete packed/unit/wide operands before these patterns are used.

(define_mode_iterator ZTT_M [ZTTM1 ZTTMR1 ZTTM2 ZTTMR2 ZTTM4 ZTTMR4
                            ZTTMR8 ZTTMR16 ZTTMR32])
(define_mode_iterator ZTT_M1 [ZTTM1 ZTTMR1])
(define_mode_iterator ZTT_G [ZTTM2 ZTTMR2 ZTTM4 ZTTMR4 ZTTMR8 ZTTMR16 ZTTMR32])
(define_mode_attr ztt_store_length [(ZTTM2 "40") (ZTTMR2 "40")
                                   (ZTTM4 "72") (ZTTMR4 "72")
                                   (ZTTMR8 "136") (ZTTMR16 "264")
                                   (ZTTMR32 "520")])
;; Large same-Md operands can consume the whole register bank.  Their
;; state envelope permits complete source/destination overlap.
(define_mode_attr ztt_binary_dest [(ZTTM2 "&Wmr") (ZTTMR2 "&Wmr")
                                  (ZTTM4 "&Wmr") (ZTTMR4 "&Wmr")
                                  (ZTTMR8 "Wmr") (ZTTMR16 "Wmr")
                                  (ZTTMR32 "Wmr")])

;; Boolean alternative attributes are cached per insn code, not per function.
;; Keep the uniform-Md and raw-copy codes distinct in LTO as well as cc1.
(define_expand "mov<mode>"
  [(set (match_operand:ZTT_M1 0 "nonimmediate_operand")
        (match_operand:ZTT_M1 1 "general_operand"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()")

(define_insn "*mov<mode>_uniform"
  [(set (match_operand:ZTT_M1 0 "nonimmediate_operand" "=Wmr,Wmr,A")
        (match_operand:ZTT_M1 1 "general_operand"       "Wmr,A,Wmr"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && !riscv_ztt_explicit_state_p ()"
  "@
   mmov.m.m\t%0,%1
   mls.1r\t%0,%q1
   mss.1r\t%1,%q0"
  [(set_attr "type" "multi")])

(define_insn "*mov<mode>_raw"
  [(set (match_operand:ZTT_M1 0 "nonimmediate_operand" "=Wmr,Wmr,A")
        (match_operand:ZTT_M1 1 "general_operand"       "Wmr,A,Wmr"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt_explicit_state_p ()"
  "@
   #
   mls.1r\t%0,%q1
   mss.1r\t%1,%q0"
  [(set_attr "type" "multi")
   (set_attr "enabled" "no,yes,yes")])

;; This is also the provisional v0.2.4 raw-clear value constructor.
;; It must define the whole M value and retain the settyp side effect.
(define_insn "@ztt_typed_msettyp_p0_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
	(unspec_volatile:ZTT_M
	  [(match_operand:P 1 "register_operand" "r")]
	  UNSPECV_ZTT_SETTYP_P0))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "msettyp\t%0,%1"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_mzero_2d_m_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
	(unspec:ZTT_M
	  [(const_int 0)
	   (match_operand 1 "const_int_operand" "n")]
	  UNSPEC_ZTT_MZERO_2D_M))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "mzero.2d.m\t%0"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_mls_rm_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
	(unspec:ZTT_M
	  [(match_operand:ZTT_M 1 "memory_operand" "A")
	   (match_operand 2 "const_int_operand" "n")]
	  UNSPEC_ZTT_MLS_RM))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "mls.rm\t%0,%q1"
  [(set_attr "type" "multi")])

;; Strided memory has an
;; unknown BLK extent, not the contiguous size of the register value.
;; The state pass replaces these placeholders before allocation.
(define_insn "@ztt_typed_memory_load_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand:BLK 1 "memory_operand" "A")
           (match_operand:P 2 "reg_or_0_operand" "rJ")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          UNSPEC_ZTT_MEMORY_LOAD))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_memory_store_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:BLK 0 "memory_operand" "=A")
        (unspec:BLK
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:P 2 "reg_or_0_operand" "rJ")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          UNSPEC_ZTT_MEMORY_STORE))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_memory_load_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:BLK 1 "memory_operand" "A")
           (match_operand:P 2 "reg_or_0_operand" "rJ")
           (match_operand 3 "const_int_operand" "n")
           (match_operand:P 4 "register_operand" "r")]
          UNSPECV_ZTT_STATE_MEMORY_LOAD))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
{
  output_asm_insn ("msettyp\t%0,%4", operands);
  switch (INTVAL (operands[3]))
    {
    case 1: return "mls.cm\t%0,%q1";
    case 2: return "mls.st\t%0,(%q1),%z2";
    case 3: return "mls.tst\t%0,(%q1),%z2";
    default: gcc_unreachable ();
    }
}
  [(set_attr "type" "multi")
   (set_attr "length" "8")])

(define_insn "@ztt_state_memory_store_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:BLK 0 "memory_operand" "=A")
        (unspec_volatile:BLK
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:P 2 "reg_or_0_operand" "rJ")
           (match_operand:P 3 "register_operand" "r")
           (match_operand 6 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_MEMORY_STORE))
   (clobber (match_operand:ZTT_M 4 "memory_operand" "=A"))
   (use (match_operand:P 5 "reg_or_0_operand" "rJ"))
   (clobber (match_scratch:P 7 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
{
  return riscv_ztt::output_memory_store (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::memory_store_length (<ZTT_M:MODE>mode)"))])

(define_insn "@ztt_state_memory_store_prepared_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:BLK 0 "memory_operand" "=A")
        (unspec_volatile:BLK
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:P 2 "reg_or_0_operand" "rJ")
           (match_operand 3 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_MEMORY_STORE))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p () && reload_completed"
{
  switch (INTVAL (operands[3]))
    {
    case 1: return "mss.cm\t%1,%q0";
    case 2: return "mss.st\t%1,(%q0),%z2";
    case 3: return "mss.tst\t%1,(%q0),%z2";
    default: gcc_unreachable ();
    }
}
  [(set_attr "type" "multi")
   (set_attr "length" "4")])

(define_insn "@ztt_typed_mss_rm_<mode>"
  [(set (match_operand:ZTT_M 0 "memory_operand" "=A")
	(unspec:ZTT_M
	  [(match_operand:ZTT_M 1 "register_operand" "Wmr")
	   (match_operand 2 "const_int_operand" "n")]
	  UNSPEC_ZTT_MSS_RM))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "mss.rm\t%1,%q0"
  [(set_attr "type" "multi")])

;; Subtraction is source2-source1;
;; AND-NOT and OR-NOT complement source2.  Do not commute the operands.
(define_int_iterator ZTT_BINARY [UNSPEC_ZTT_MADD_EW UNSPEC_ZTT_MSUB_EW
                                UNSPEC_ZTT_MMIN_EW UNSPEC_ZTT_MMAX_EW
                                UNSPEC_ZTT_MAND_EW UNSPEC_ZTT_MANDNOT_EW
                                UNSPEC_ZTT_MOR_EW UNSPEC_ZTT_MORNOT_EW
                                UNSPEC_ZTT_MXOR_EW])
(define_int_attr ztt_binary_op [(UNSPEC_ZTT_MADD_EW "add")
                                (UNSPEC_ZTT_MSUB_EW "sub")
                                (UNSPEC_ZTT_MMIN_EW "min")
                                (UNSPEC_ZTT_MMAX_EW "max")
                                (UNSPEC_ZTT_MAND_EW "and")
                                (UNSPEC_ZTT_MANDNOT_EW "andnot")
                                (UNSPEC_ZTT_MOR_EW "or")
                                (UNSPEC_ZTT_MORNOT_EW "ornot")
                                (UNSPEC_ZTT_MXOR_EW "xor")])
(define_int_iterator ZTT_STATE_BINARY [UNSPECV_ZTT_STATE_ADD UNSPECV_ZTT_STATE_SUB
                                      UNSPECV_ZTT_STATE_MIN UNSPECV_ZTT_STATE_MAX
                                      UNSPECV_ZTT_STATE_AND UNSPECV_ZTT_STATE_ANDNOT
                                      UNSPECV_ZTT_STATE_OR UNSPECV_ZTT_STATE_ORNOT
                                      UNSPECV_ZTT_STATE_XOR])
(define_int_attr ztt_state_binary_op [(UNSPECV_ZTT_STATE_ADD "add")
                                      (UNSPECV_ZTT_STATE_SUB "sub")
                                      (UNSPECV_ZTT_STATE_MIN "min")
                                      (UNSPECV_ZTT_STATE_MAX "max")
                                      (UNSPECV_ZTT_STATE_AND "and")
                                      (UNSPECV_ZTT_STATE_ANDNOT "andnot")
                                      (UNSPECV_ZTT_STATE_OR "or")
                                      (UNSPECV_ZTT_STATE_ORNOT "ornot")
                                      (UNSPECV_ZTT_STATE_XOR "xor")])

(define_insn "@ztt_typed_m<ztt_binary_op>_ew_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
	(unspec:ZTT_M
	  [(match_operand:ZTT_M 1 "register_operand" "Wmr")
	   (match_operand:ZTT_M 2 "register_operand" "Wmr")
	   (match_operand 3 "const_int_operand" "n")]
          ZTT_BINARY))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "m<ztt_binary_op>.ew\t%0,%1,%2"
  [(set_attr "type" "multi")])

;; Inputs retain their raw data;
;; only private stack scratch and implicit Md are changed by preparation.
;; Early-clobber keeps the destination setup from clearing either binary input.

(define_insn "@ztt_state_zero_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:P 1 "register_operand" "r")]
          UNSPECV_ZTT_STATE_ZERO))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p ()"
  "msettyp\t%0,%1\;mzero.2d.m\t%0"
  [(set_attr "type" "multi")
   (set_attr "length" "8")])

;; Settyp defines the entire
;; formed group before broadcast.  The source datatype is a GPR value;
;; neither amestype nor an existing M value is an input.
(define_insn "@ztt_typed_broadcast_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "r")
           (match_operand:P 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")]
          UNSPECV_ZTT_BROADCAST))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && (GET_MODE (operands[1]) == QImode || GET_MODE (operands[1]) == HImode
       || GET_MODE (operands[1]) == SImode || GET_MODE (operands[1]) == Pmode)"
  "msettyp\t%0,%3\;mbcast.m.x\t%0,%1,%2"
  [(set_attr "type" "multi")
   (set_attr "length" "8")])

;; The call-site range check
;; precedes this indivisible setup/constructor pair.  No old M is an input.
(define_insn "@ztt_typed_index_construct_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:P 1 "register_operand" "r")
           (match_operand 2 "const_int_operand" "n")]
          UNSPECV_ZTT_INDEX_CONSTRUCT))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && IN_RANGE (INTVAL (operands[2]), 0, 1)"
{
  return INTVAL (operands[2]) == 0
    ? "msettyp\t%0,%1\;mrowid.ew\t%0"
    : "msettyp\t%0,%1\;mcolid.ew\t%0";
}
  [(set_attr "type" "multi")
   (set_attr "length" "8")])

(define_insn "@ztt_state_load_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "memory_operand" "A")
           (match_operand:P 2 "register_operand" "r")]
          UNSPECV_ZTT_STATE_LOAD))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p ()"
  "msettyp\t%0,%2\;mls.rm\t%0,%q1"
  [(set_attr "type" "multi")
   (set_attr "length" "8")])

(define_insn "@ztt_state_store_<ZTT_M1:mode>_<P:mode>"
  [(set (match_operand:ZTT_M1 0 "memory_operand" "=A")
        (unspec_volatile:ZTT_M1
          [(match_operand:ZTT_M1 1 "register_operand" "Wmr")
           (match_operand:P 2 "register_operand" "r")]
          UNSPECV_ZTT_STATE_STORE))
   (clobber (match_operand:ZTT_M1 3 "memory_operand" "=A"))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p ()"
  "mss.1r\t%1,%q3\;msettyp\t%1,%2\;mls.1r\t%1,%q3\;mss.rm\t%1,%q0"
  [(set_attr "type" "multi")
   (set_attr "length" "16")])

(define_insn "@ztt_state_store_prepared_<mode>"
  [(set (match_operand:ZTT_M 0 "memory_operand" "=A")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")]
          UNSPECV_ZTT_STATE_STORE))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p () && reload_completed"
  "mss.rm\t%1,%q0"
  [(set_attr "type" "multi")
   (set_attr "length" "4")])

(define_insn "@ztt_state_<ztt_state_binary_op>_<ZTT_M1:mode>_<P:mode>"
  [(set (match_operand:ZTT_M1 0 "register_operand" "=&Wmr")
        (unspec_volatile:ZTT_M1
          [(match_operand:ZTT_M1 1 "register_operand" "Wmr")
           (match_operand:ZTT_M1 2 "register_operand" "Wmr")
           (match_operand:P 3 "register_operand" "r")
           (match_operand 5 "const_int_operand" "n")]
          ZTT_STATE_BINARY))
   (clobber (match_operand:ZTT_M1 4 "memory_operand" "=A"))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p ()"
{
  return riscv_ztt::output_group_state
    (operands, "m<ztt_state_binary_op>.ew\t%0,%1,%2", UINTVAL (operands[5]));
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::binary_state_length (operands, UINTVAL (operands[5]))"))])

(define_insn "@ztt_state_<ztt_state_binary_op>_prepared_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:ZTT_M 2 "register_operand" "Wmr")
           (match_operand:P 3 "register_operand" "r")]
          ZTT_STATE_BINARY))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p () && reload_completed"
{
  return riscv_ztt::output_group_state
    (operands, "m<ztt_state_binary_op>.ew\t%0,%1,%2", 3);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::binary_state_length (operands, 3)"))])

;; Each .1r instruction transfers one M, never a whole typed group.

(define_expand "mov<mode>"
  [(parallel
     [(set (match_operand:ZTT_G 0 "nonimmediate_operand")
           (match_operand:ZTT_G 1 "general_operand"))
      (clobber (match_dup 2))
      (clobber (match_dup 3))])]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
{
  if (MEM_P (operands[0]) && !REG_P (operands[1]))
    operands[1] = force_reg (<MODE>mode, operands[1]);
  operands[2] = gen_rtx_SCRATCH (Pmode);
  operands[3] = gen_rtx_SCRATCH (Pmode);
})

(define_insn_and_split "*mov<ZTT_G:mode>_<P:mode>"
  [(set (match_operand:ZTT_G 0 "nonimmediate_operand" "=Wmr,Wmr,A")
        (match_operand:ZTT_G 1 "general_operand"       "Wmr,A,Wmr"))
   (clobber (match_scratch:P 2 "=X,&r,&r"))
   (clobber (match_scratch:P 3 "=X,&r,&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "#"
  "&& reload_completed"
  [(const_int 0)]
{
  riscv_ztt::split_group_move (operands);
  DONE;
}
  [(set_attr "type" "multi")
   (set_attr "enabled" "no,yes,yes")])

(define_insn "@ztt_group_state_store_<ZTT_G:mode>_<P:mode>"
  [(set (match_operand:ZTT_G 0 "memory_operand" "=A")
        (unspec_volatile:ZTT_G
          [(match_operand:ZTT_G 1 "register_operand" "Wmr")
           (match_operand:P 2 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")]
          UNSPECV_ZTT_STATE_STORE))
   (clobber (match_operand:ZTT_G 3 "memory_operand" "=A"))
   (clobber (match_scratch:P 5 "=&r"))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p ()"
{
  return riscv_ztt::output_group_state (operands, nullptr);
}
  [(set_attr "type" "multi")
   (set_attr "length" "<ztt_store_length>")])

(define_insn "@ztt_group_state_<ztt_state_binary_op>_<ZTT_G:mode>_<P:mode>"
  [(set (match_operand:ZTT_G 0 "register_operand" "=<ztt_binary_dest>")
        (unspec_volatile:ZTT_G
          [(match_operand:ZTT_G 1 "register_operand" "Wmr")
           (match_operand:ZTT_G 2 "register_operand" "Wmr")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 5 "register_operand" "r")
           (match_operand 7 "const_int_operand" "n")]
          ZTT_STATE_BINARY))
   (clobber (match_operand:ZTT_G 4 "memory_operand" "=A"))
   (clobber (match_scratch:P 6 "=&r"))]
  "TARGET_ZTT && riscv_ztt_explicit_state_p ()"
{
  return riscv_ztt::output_group_state
    (operands, "m<ztt_state_binary_op>.ew\t%0,%1,%2", UINTVAL (operands[7]));
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::binary_state_length (operands, UINTVAL (operands[7]))"))])


;; Tensor operands have
;; independent complete modes.  Multiplication uses only the M form.
;; Scalar shift counts use Pmode, never amestype.
(define_int_iterator ZTT_ELEMENTWISE [UNSPEC_ZTT_ELEMENTWISE_M UNSPEC_ZTT_ELEMENTWISE_X])
(define_int_iterator ZTT_STATE_ELEMENTWISE [UNSPECV_ZTT_STATE_ELEMENTWISE_M
                                     UNSPECV_ZTT_STATE_ELEMENTWISE_X
                                     UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE
                                     UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT
                                     UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT
                                     UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE])
(define_int_attr ztt_elementwise_kind [(UNSPEC_ZTT_ELEMENTWISE_M "m")
                                 (UNSPEC_ZTT_ELEMENTWISE_X "x")
                                 (UNSPECV_ZTT_STATE_ELEMENTWISE_M "m")
                                 (UNSPECV_ZTT_STATE_ELEMENTWISE_X "x")
                                 (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE "m_reuse")
                                 (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT "m_reuse_left")
                                 (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT "m_reuse_right")
                                 (UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE "x_reuse")])
(define_int_attr ztt_elementwise_scalar [(UNSPEC_ZTT_ELEMENTWISE_M "false")
                                   (UNSPEC_ZTT_ELEMENTWISE_X "true")
                                   (UNSPECV_ZTT_STATE_ELEMENTWISE_M "false")
                                   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "true")
                                   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE "false")
                                   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT "false")
                                   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT "false")
                                   (UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE "true")])
(define_int_attr ztt_elementwise_rhs_c [(UNSPEC_ZTT_ELEMENTWISE_M "Wmr")
                                    (UNSPEC_ZTT_ELEMENTWISE_X "r")
                                    (UNSPECV_ZTT_STATE_ELEMENTWISE_M "Wmr")
                                    (UNSPECV_ZTT_STATE_ELEMENTWISE_X "r")
                                    (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE "Wmr")
                                    (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT "Wmr")
                                    (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT "0")
                                    (UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE "r")])

;; Tie only a complete
;; compatible source; the other input remains protected by early-clobber.
(define_int_attr ztt_elementwise_dest_c
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "&Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "&Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE "Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT "&Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT "&Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE "Wmr")])
(define_int_attr ztt_elementwise_lhs_c
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE "Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT "0")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT "Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE "Wmr")])
(define_int_attr ztt_elementwise_reuse
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "0")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "0")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE "3")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_LEFT "1")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_M_REUSE_RIGHT "2")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X_REUSE "1")])

(define_insn "@ztt_typed_elementwise_<ztt_elementwise_kind>_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "<ztt_elementwise_rhs_c>")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 6 "const_int_operand" "n")]
          ZTT_ELEMENTWISE))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && (<ztt_elementwise_scalar>
       ? riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[3]), false)
       : riscv_ztt::m_mode_p (GET_MODE (operands[2])))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_elementwise_<ztt_elementwise_kind>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=<ztt_elementwise_dest_c>")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "<ztt_elementwise_lhs_c>")
           (match_operand 2 "register_operand" "<ztt_elementwise_rhs_c>")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand:P 7 "reg_or_0_operand" "rJ")
           (match_operand 8 "const_int_operand" "n")
           (match_operand 9 "const_int_operand" "n")
           (match_operand 11 "const_int_operand" "n")]
          ZTT_STATE_ELEMENTWISE))
   (clobber (match_operand 6 "memory_operand" "=A"))
   (clobber (match_scratch:P 10 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && !(UINTVAL (operands[11]) & ~(<ztt_elementwise_scalar> ? 2U : 6U))
   && (reload_completed || operands[11] == const0_rtx)
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[6]))
   && (!(<ztt_elementwise_reuse> & 1)
       || (GET_MODE (operands[0]) == GET_MODE (operands[1])
           && rtx_equal_p (operands[3], operands[4])
           && riscv_ztt::datatype_step (UINTVAL (operands[9]), 0)
              == riscv_ztt::datatype_step (UINTVAL (operands[9]), 1)))
   && (!(<ztt_elementwise_reuse> & 2)
       || (GET_MODE (operands[0]) == GET_MODE (operands[2])
           && rtx_equal_p (operands[3], operands[5])
           && riscv_ztt::datatype_step (UINTVAL (operands[9]), 0)
              == riscv_ztt::datatype_step (UINTVAL (operands[9]), 2)))
   && (<ztt_elementwise_scalar>
       ? riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[8]), false)
       : riscv_ztt::m_mode_p (GET_MODE (operands[2])))"
{
  return riscv_ztt::output_elementwise_state (operands, <ztt_elementwise_scalar>);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::elementwise_length (operands, <ztt_elementwise_scalar>)"))])

;; Scatter reads the old
;; destination.  The late early-clobber prevents its setup from clearing
;; either source, including when a source aliases old_d in the C program.
(define_insn "@ztt_typed_gather_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 6 "const_int_operand" "n")]
          UNSPEC_ZTT_GATHER))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_scatter_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand:ZTT_M 7 "register_operand" "0")
           (match_operand 6 "const_int_operand" "n")]
          UNSPEC_ZTT_SCATTER))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_gather_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=&Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "register_operand" "r")
           (match_operand:P 7 "reg_or_0_operand" "rJ")
           (match_operand 8 "const_int_operand" "n")
           (match_operand 9 "const_int_operand" "n")
           (match_operand 11 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_GATHER))
   (clobber (match_operand 6 "memory_operand" "=A"))
   (clobber (match_scratch:P 10 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && !(UINTVAL (operands[11]) & ~6U)
   && (reload_completed || operands[11] == const0_rtx)
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[6]))"
{
  return riscv_ztt::output_indexed_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length") (symbol_ref "riscv_ztt::indexed_length (operands)"))])

(define_insn "@ztt_state_scatter_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=&Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "register_operand" "r")
           (match_operand:P 7 "reg_or_0_operand" "rJ")
           (match_operand 8 "const_int_operand" "n")
           (match_operand 9 "const_int_operand" "n")
           (match_operand:ZTT_M 11 "register_operand" "0")
           (match_operand 12 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_SCATTER))
   (clobber (match_operand 6 "memory_operand" "=A"))
   (clobber (match_scratch:P 10 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && !(UINTVAL (operands[12]) & ~7U)
   && (reload_completed || operands[12] == const0_rtx)
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[6]))"
{
  return riscv_ztt::output_indexed_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length") (symbol_ref "riscv_ztt::indexed_length (operands)"))])

;; Keep old_d explicit
;; through RTL optimization and preserve its entire formed group at setup.
(define_insn "@ztt_typed_ternary_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand:ZTT_M 7 "register_operand" "0")
           (match_operand 6 "const_int_operand" "n")]
          UNSPEC_ZTT_TERNARY))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_ternary_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=&Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "register_operand" "r")
           (match_operand:P 7 "reg_or_0_operand" "rJ")
           (match_operand 8 "const_int_operand" "n")
           (match_operand 9 "const_int_operand" "n")
           (match_operand:ZTT_M 11 "register_operand" "0")
           (match_operand 12 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_TERNARY))
   (clobber (match_operand 6 "memory_operand" "=A"))
   (clobber (match_scratch:P 10 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && !(UINTVAL (operands[12]) & ~7U)
   && (reload_completed || operands[12] == const0_rtx)
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[6]))"
{
  return riscv_ztt::output_ternary_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length") (symbol_ref "riscv_ztt::ternary_length (operands)"))])

;; Scalar old-D expressions
;; read a tied destination and one independent M source, not two M sources.
(define_insn "@ztt_typed_ternary_x_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "r")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand:P 5 "const_int_operand" "n")
           (match_operand:ZTT_M 7 "register_operand" "0")
           (match_operand 6 "const_int_operand" "n")]
          UNSPEC_ZTT_TERNARY_X))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[3]), true)"
  "#"
  [(set_attr "type" "multi")])

;; TC-to-TB ingress can
;; saturate independently of TD.  Retain flags before the late state pass.
(define_insn "@ztt_typed_ternary_x_flags_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "r")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand:P 5 "const_int_operand" "n")
           (match_operand:ZTT_M 7 "register_operand" "0")
           (match_operand 6 "const_int_operand" "n")]
          UNSPECV_ZTT_TERNARY_X_FLAGS))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[3]), true)"
  "#"
  [(set_attr "type" "multi")])

;; Fixed exponent old-D may
;; overlap a complete same-mode/Md source.  Keep legacy names and constraints.
(define_int_iterator ZTT_STATE_TERNARY_X
  [UNSPECV_ZTT_STATE_TERNARY_X UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE])
(define_int_attr ztt_ternary_suffix
  [(UNSPECV_ZTT_STATE_TERNARY_X "") (UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE "_reuse")])
(define_int_attr ztt_ternary_dest
  [(UNSPECV_ZTT_STATE_TERNARY_X "&Wmr") (UNSPECV_ZTT_STATE_EXPONENT_ACC_REUSE "Wmr")])

(define_insn "@ztt_state_ternary_x<ztt_ternary_suffix>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=<ztt_ternary_dest>")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand:P 7 "reg_or_0_operand" "rJ")
           (match_operand 8 "const_int_operand" "n")
           (match_operand 9 "const_int_operand" "n")
           (match_operand:ZTT_M 11 "register_operand" "0")
           (match_operand 12 "const_int_operand" "n")]
          ZTT_STATE_TERNARY_X))
   (clobber (match_operand 6 "memory_operand" "=A"))
   (clobber (match_scratch:P 10 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && !(UINTVAL (operands[12]) & ~3U)
   && (reload_completed || operands[12] == const0_rtx)
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[6]))
   && riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[8]), true)
   && (REG_P (operands[5]) || UINTVAL (operands[8]) == 4)"
{
  return riscv_ztt::output_scalar_ternary_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::scalar_ternary_length (operands)"))])

(define_int_iterator ZTT_COMMON_PREPARED
  [UNSPECV_ZTT_STATE_ELEMENTWISE_M UNSPECV_ZTT_STATE_ELEMENTWISE_X
   UNSPECV_ZTT_STATE_GATHER])
(define_int_iterator ZTT_COMMON_OLD_PREPARED
  [UNSPECV_ZTT_STATE_TERNARY UNSPECV_ZTT_STATE_TERNARY_X
   UNSPECV_ZTT_STATE_SCATTER])
(define_int_attr ztt_common_kind
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "binary_m")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "binary_x")
   (UNSPECV_ZTT_STATE_GATHER "gather")
   (UNSPECV_ZTT_STATE_TERNARY "ternary_m")
   (UNSPECV_ZTT_STATE_TERNARY_X "ternary_x")
   (UNSPECV_ZTT_STATE_SCATTER "scatter")])
(define_int_attr ztt_common_code
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "UNSPECV_ZTT_STATE_ELEMENTWISE_M")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "UNSPECV_ZTT_STATE_ELEMENTWISE_X")
   (UNSPECV_ZTT_STATE_GATHER "UNSPECV_ZTT_STATE_GATHER")
   (UNSPECV_ZTT_STATE_TERNARY "UNSPECV_ZTT_STATE_TERNARY")
   (UNSPECV_ZTT_STATE_TERNARY_X "UNSPECV_ZTT_STATE_TERNARY_X")
   (UNSPECV_ZTT_STATE_SCATTER "UNSPECV_ZTT_STATE_SCATTER")])
(define_int_attr ztt_common_scalar
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "false")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "true")
   (UNSPECV_ZTT_STATE_GATHER "false")
   (UNSPECV_ZTT_STATE_TERNARY "false")
   (UNSPECV_ZTT_STATE_TERNARY_X "true")
   (UNSPECV_ZTT_STATE_SCATTER "false")])
(define_int_attr ztt_common_rhs
  [(UNSPECV_ZTT_STATE_ELEMENTWISE_M "Wmr")
   (UNSPECV_ZTT_STATE_ELEMENTWISE_X "r")
   (UNSPECV_ZTT_STATE_GATHER "Wmr")
   (UNSPECV_ZTT_STATE_TERNARY "Wmr")
   (UNSPECV_ZTT_STATE_TERNARY_X "r")
   (UNSPECV_ZTT_STATE_SCATTER "Wmr")])

(define_insn "@ztt_state_common_prepared_<ztt_common_kind>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "<ztt_common_rhs>")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand 6 "const_int_operand" "n")
           (match_operand 7 "const_int_operand" "n")]
          ZTT_COMMON_PREPARED))]
  "TARGET_ZTT && reload_completed && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && (<ztt_common_scalar>
       ? riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[6]), false)
       : riscv_ztt::m_mode_p (GET_MODE (operands[2])))
   && riscv_ztt::common_prepared_operands_p (operands, <ztt_common_scalar>)"
{
  return riscv_ztt::output_common_prepared (operands, <ztt_common_code>);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::common_prepared_length (operands, <ztt_common_code>)"))])

(define_insn "@ztt_state_common_old_prepared_<ztt_common_kind>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "<ztt_common_rhs>")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 4 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand 6 "const_int_operand" "n")
           (match_operand 7 "const_int_operand" "n")
           (match_operand:ZTT_M 8 "register_operand" "0")]
          ZTT_COMMON_OLD_PREPARED))]
  "TARGET_ZTT && reload_completed && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && (<ztt_common_scalar>
       ? riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[6]), true)
       : riscv_ztt::m_mode_p (GET_MODE (operands[2])))
   && (REG_P (operands[5])
       || (<ztt_common_scalar> && UINTVAL (operands[6]) == 4))
   && riscv_ztt::common_prepared_operands_p (operands, <ztt_common_scalar>)"
{
  return riscv_ztt::output_common_prepared (operands, <ztt_common_code>);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::common_prepared_length (operands, <ztt_common_code>)"))])

;; Each result depends on both
;; old values; distinct tied groups survive allocation and destructive setup.
(define_insn "@ztt_typed_zip_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=&Wmr")
        (unspec:ZTT_M
          [(match_operand:ZTT_M 2 "register_operand" "0")
           (match_operand:ZTT_M 3 "register_operand" "1")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")] UNSPEC_ZTT_ZIP_A))
   (set (match_operand:ZTT_M 1 "register_operand" "=&Wmr")
        (unspec:ZTT_M [(match_dup 2) (match_dup 3) (match_dup 4) (match_dup 5)]
                     UNSPEC_ZTT_ZIP_B))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_zip_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=&Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 2 "register_operand" "0")
           (match_operand:ZTT_M 3 "register_operand" "1")
           (match_operand:P 4 "register_operand" "r")
           (match_operand 5 "const_int_operand" "n")
           (match_operand:P 7 "reg_or_0_operand" "rJ")] UNSPECV_ZTT_STATE_ZIP_A))
   (set (match_operand:ZTT_M 1 "register_operand" "=&Wmr")
        (unspec_volatile:ZTT_M
          [(match_dup 2) (match_dup 3) (match_dup 4) (match_dup 5) (match_dup 7)]
          UNSPECV_ZTT_STATE_ZIP_B))
   (clobber (match_operand:ZTT_M 6 "memory_operand" "=A"))
   (clobber (match_scratch:P 8 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
{
  return riscv_ztt::output_zip_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length") (symbol_ref "riscv_ztt::zip_length (operands)"))])

;; A single tied value keeps the two squares consecutive through allocation.
(define_insn "@ztt_typed_zip_value_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "0")
           (match_operand 2 "const_int_operand" "n")
           (match_operand 3 "const_int_operand" "n")]
          UNSPEC_ZTT_ZIP_VALUE))]
  "TARGET_ZTT && riscv_ztt::runtime_profile_p ()
   && riscv_ztt::m_nregs (<MODE>mode) >= 2"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_zip_value_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "0")
           (match_operand:P 2 "register_operand" "r")
           (match_operand 3 "const_int_operand" "n")
           (match_operand:P 5 "reg_or_0_operand" "rJ")]
          UNSPECV_ZTT_STATE_ZIP_VALUE))
   (clobber (match_operand 4 "memory_operand" "=A"))
   (clobber (match_scratch:P 6 "=&r"))]
  "TARGET_ZTT && riscv_ztt::runtime_profile_p ()
   && riscv_ztt::m_nregs (<ZTT_M:MODE>mode) >= 2"
{
  return riscv_ztt::output_zip_value_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::zip_value_length (operands)"))])

;; Both tied squares already have their required Md after allocation.
(define_insn "@ztt_state_zip_value_prepared_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "0")
           (match_operand 2 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_ZIP_VALUE))]
  "TARGET_ZTT && reload_completed && riscv_ztt::runtime_profile_p ()
   && riscv_ztt::m_nregs (<MODE>mode) >= 2"
{
  return riscv_ztt::output_zip_value_state (operands, true);
}
  [(set_attr "type" "multi") (set_attr "length" "4")])

;; Formed source/destination
;; modes may differ; retain source payload across every source Md setup.
;; Saturating destinations can update amexsat even for an unused result.
;; Preserve that effect before the late state pass, not just afterwards.
;;   Preserve saturation
;; effects before the state pass even when the result has no users.
(define_int_iterator ZTT_INTEGER_ELEMENTWISE
  [UNSPECV_ZTT_ELEMENTWISE_M_FLAGS UNSPECV_ZTT_ELEMENTWISE_X_FLAGS])
(define_int_attr ztt_integer_kind
  [(UNSPECV_ZTT_ELEMENTWISE_M_FLAGS "m") (UNSPECV_ZTT_ELEMENTWISE_X_FLAGS "x")])
(define_int_attr ztt_integer_scalar
  [(UNSPECV_ZTT_ELEMENTWISE_M_FLAGS "false") (UNSPECV_ZTT_ELEMENTWISE_X_FLAGS "true")])
(define_int_attr ztt_integer_rhs_c
  [(UNSPECV_ZTT_ELEMENTWISE_M_FLAGS "Wmr") (UNSPECV_ZTT_ELEMENTWISE_X_FLAGS "r")])

(define_insn "@ztt_typed_elementwise_flags_<ztt_integer_kind>_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "<ztt_integer_rhs_c>")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 6 "const_int_operand" "n")]
          ZTT_INTEGER_ELEMENTWISE))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && (<ztt_integer_scalar>
       ? riscv_ztt::scalar_operand_p (operands[2], UINTVAL (operands[3]), false)
       : riscv_ztt::m_mode_p (GET_MODE (operands[2])))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_gather_flags_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 6 "const_int_operand" "n")]
          UNSPECV_ZTT_GATHER_FLAGS))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_scatter_flags_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand:ZTT_M 7 "register_operand" "0")
           (match_operand 6 "const_int_operand" "n")]
          UNSPECV_ZTT_SCATTER_FLAGS))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_typed_ternary_flags_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")
           (match_operand:ZTT_M 7 "register_operand" "0")
           (match_operand 6 "const_int_operand" "n")]
          UNSPECV_ZTT_TERNARY_FLAGS))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))"
  "#"
  [(set_attr "type" "multi")])
(define_code_iterator ZTT_UNARY_EFFECT [unspec unspec_volatile])
(define_code_attr ztt_effect_suffix [(unspec "") (unspec_volatile "_flags")])
(define_code_attr ztt_convert_unspec
  [(unspec "UNSPEC_ZTT_CONVERT")
   (unspec_volatile "UNSPECV_ZTT_CONVERT_FLAGS")])
(define_code_attr ztt_structural_unspec
  [(unspec "UNSPEC_ZTT_STRUCTURAL")
   (unspec_volatile "UNSPECV_ZTT_STRUCTURAL_FLAGS")])

(define_insn "@ztt_typed_convert<ztt_effect_suffix>_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (ZTT_UNARY_EFFECT:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "const_int_operand" "n")
           (match_operand 3 "const_int_operand" "n")]
          <ztt_convert_unspec>))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))"
  "#"
  [(set_attr "type" "multi")])

;; Reuse only an entire
;; same-mode, same-Md source; keep the old small-group constraints.
(define_int_iterator ZTT_STATE_CONVERT
  [UNSPECV_ZTT_STATE_CONVERT UNSPECV_ZTT_STATE_CONVERT_REUSE])
(define_int_iterator ZTT_STATE_STRUCTURAL
  [UNSPECV_ZTT_STATE_STRUCTURAL UNSPECV_ZTT_STATE_STRUCTURAL_REUSE])
(define_int_iterator ZTT_STATE_ROWCOL
  [UNSPECV_ZTT_STATE_ROWCOL UNSPECV_ZTT_STATE_ROWCOL_REUSE])
(define_int_attr ztt_unary_reuse_suffix
  [(UNSPECV_ZTT_STATE_CONVERT "") (UNSPECV_ZTT_STATE_CONVERT_REUSE "_reuse")
   (UNSPECV_ZTT_STATE_STRUCTURAL "") (UNSPECV_ZTT_STATE_STRUCTURAL_REUSE "_reuse")
   (UNSPECV_ZTT_STATE_ROWCOL "") (UNSPECV_ZTT_STATE_ROWCOL_REUSE "_reuse")])
(define_int_attr ztt_unary_dest_c
  [(UNSPECV_ZTT_STATE_CONVERT "&Wmr") (UNSPECV_ZTT_STATE_CONVERT_REUSE "Wmr")
   (UNSPECV_ZTT_STATE_STRUCTURAL "&Wmr") (UNSPECV_ZTT_STATE_STRUCTURAL_REUSE "Wmr")
   (UNSPECV_ZTT_STATE_ROWCOL "&Wmr") (UNSPECV_ZTT_STATE_ROWCOL_REUSE "Wmr")])
(define_int_attr ztt_unary_reuse
  [(UNSPECV_ZTT_STATE_CONVERT "false") (UNSPECV_ZTT_STATE_CONVERT_REUSE "true")
   (UNSPECV_ZTT_STATE_STRUCTURAL "false") (UNSPECV_ZTT_STATE_STRUCTURAL_REUSE "true")
   (UNSPECV_ZTT_STATE_ROWCOL "false") (UNSPECV_ZTT_STATE_ROWCOL_REUSE "true")])

(define_insn "@ztt_state_convert<ztt_unary_reuse_suffix>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=<ztt_unary_dest_c>")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand:P 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand 6 "const_int_operand" "n")]
          ZTT_STATE_CONVERT))
   (clobber (match_operand 4 "memory_operand" "=A"))
   (clobber (match_scratch:P 7 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && GET_MODE (operands[4]) == GET_MODE (operands[1])
   && (!<ztt_unary_reuse>
       || (riscv_ztt::m_nregs (GET_MODE (operands[0])) > 4
           && GET_MODE (operands[0]) == GET_MODE (operands[1])
           && rtx_equal_p (operands[2], operands[3])
           && riscv_ztt::datatype_step (UINTVAL (operands[6]), 0)
              == riscv_ztt::datatype_step (UINTVAL (operands[6]), 1)))"
{
  return riscv_ztt::output_conversion_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::conversion_length (operands)"))])

;; The variant distinguishes
;; destination-domain folds (0..9) and absolute value (10) from conversion.
;; Absolute value takes magnitude before destination conversion; the shared
;; envelope only prepares descriptors and preserves the complete source.
(define_insn "@ztt_typed_structural<ztt_effect_suffix>_<mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (ZTT_UNARY_EFFECT:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand 2 "const_int_operand" "n")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          <ztt_structural_unspec>))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_structural<ztt_unary_reuse_suffix>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=<ztt_unary_dest_c>")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand:P 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand 6 "const_int_operand" "n")
           (match_operand 8 "const_int_operand" "n")]
          ZTT_STATE_STRUCTURAL))
   (clobber (match_operand 4 "memory_operand" "=A"))
   (clobber (match_scratch:P 7 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && GET_MODE (operands[4]) == GET_MODE (operands[1])
   && (!<ztt_unary_reuse>
       || (riscv_ztt::m_nregs (GET_MODE (operands[0])) > 4
           && GET_MODE (operands[0]) == GET_MODE (operands[1])
           && rtx_equal_p (operands[2], operands[3])
           && riscv_ztt::datatype_step (UINTVAL (operands[6]), 0)
              == riscv_ztt::datatype_step (UINTVAL (operands[6]), 1)))"
{
  return riscv_ztt::output_structural_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::conversion_length (operands)"))])

;; Distinct codes prevent clobber removal from matching an unprepared input.
(define_int_iterator ZTT_STATE_UNARY_PREPARED
  [UNSPECV_ZTT_STATE_CONVERT_PREPARED UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED])
(define_int_attr ztt_unary_prepared_kind
  [(UNSPECV_ZTT_STATE_CONVERT_PREPARED "convert")
   (UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED "structural")])
(define_int_attr ztt_unary_prepared_output
  [(UNSPECV_ZTT_STATE_CONVERT_PREPARED "output_conversion_state")
   (UNSPECV_ZTT_STATE_STRUCTURAL_PREPARED "output_structural_state")])

(define_insn "@ztt_state_unary_prepared_<ztt_unary_prepared_kind>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand 1 "register_operand" "Wmr")
           (match_operand:P 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")
           (match_operand 4 "const_int_operand" "n")
           (match_operand 5 "const_int_operand" "n")]
          ZTT_STATE_UNARY_PREPARED))]
  "TARGET_ZTT && reload_completed && riscv_ztt::typed_profile_p ()
   && riscv_ztt::m_mode_p (GET_MODE (operands[1]))
   && (!reg_overlap_mentioned_p (operands[0], operands[1])
       || (rtx_equal_p (operands[0], operands[1])
           && rtx_equal_p (operands[2], operands[3])
           && riscv_ztt::datatype_step (UINTVAL (operands[4]), 0)
              == riscv_ztt::datatype_step (UINTVAL (operands[4]), 1)))"
{
  return riscv_ztt::<ztt_unary_prepared_output> (operands, true);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::conversion_length (operands, true)"))])

;; Broadcast selectors may
;; trap even if the result is unused.  The late pass adds source preservation.
(define_insn "@ztt_typed_rowcol_<ZTT_M:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:SI 2 "register_operand" "r")
           (match_operand 3 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          UNSPECV_ZTT_ROWCOL))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_state_rowcol<ztt_unary_reuse_suffix>_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=<ztt_unary_dest_c>")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:SI 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")
           (match_operand:P 5 "reg_or_0_operand" "rJ")
           (match_operand 6 "const_int_operand" "n")]
          ZTT_STATE_ROWCOL))
   (clobber (match_operand:ZTT_M 4 "memory_operand" "=A"))
   (clobber (match_scratch:P 7 "=&r"))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p ()
   && (!<ztt_unary_reuse> || riscv_ztt::m_nregs (<ZTT_M:MODE>mode) > 4)"
{
  return riscv_ztt::output_rowcol_state (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::rowcol_length (operands)"))])

(define_insn "@ztt_state_rowcol_prepared_<ZTT_M:mode>_<P:mode>"
  [(set (match_operand:ZTT_M 0 "register_operand" "=Wmr")
        (unspec_volatile:ZTT_M
          [(match_operand:ZTT_M 1 "register_operand" "Wmr")
           (match_operand:SI 2 "register_operand" "r")
           (match_operand:P 3 "register_operand" "r")
           (match_operand 4 "const_int_operand" "n")]
          UNSPECV_ZTT_STATE_ROWCOL))]
  "TARGET_ZTT && riscv_ztt::typed_profile_p () && reload_completed"
{
  return riscv_ztt::output_rowcol_state (operands, true);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "riscv_ztt::rowcol_length (operands, true)"))])

;; Experimental ACC values for supported numeric types.  Packed values own
;; complete 2/4/8/16-ACC transfer packets; matmul remains nonpacked.
;;   Generic moves preserve the
;; actual Ad and logical Squares via a complete M scratch group.  Packed
;; spills have one 16-byte Ad header per ACC followed by each M payload.
;; Never guess Ad from a shared machine mode or clear the source ACC.

;; ACC images may exceed
;; the M bank; only whole M/ACC transfers use the bounded ZTT_XA subset.
(define_mode_iterator ZTT_A [
  ZTTAR1 ZTTAR2 ZTTAR4 ZTTAR1X2 ZTTAR1X4
  ZTTAR2X2 ZTTAP2X2 ZTTAP4X4 ZTTAP2X4 ZTTAP2X8
  ZTTAP4X8 ZTTAP4X16 ZTTAP8X8 ZTTAP8X16 ZTTAP16X16
  ZTTAR1X8 ZTTAR1X16 ZTTAR2X4 ZTTAR2X8 ZTTAR2X16
  ZTTAR4X2 ZTTAR4X4 ZTTAR4X8 ZTTAR4X16 ZTTAR8
  ZTTAR8X2 ZTTAR8X4 ZTTAR8X8 ZTTAR8X16 ZTTAR16
  ZTTAR16X2 ZTTAR16X4 ZTTAR16X8 ZTTAR16X16 ZTTAP2X16])
(define_mode_iterator ZTT_NPA [
  ZTTAR1 ZTTAR2 ZTTAR4 ZTTAR1X2 ZTTAR1X4
  ZTTAR2X2 ZTTAR1X8 ZTTAR1X16 ZTTAR2X4 ZTTAR2X8
  ZTTAR2X16 ZTTAR4X2 ZTTAR4X4 ZTTAR4X8 ZTTAR4X16
  ZTTAR8 ZTTAR8X2 ZTTAR8X4 ZTTAR8X8 ZTTAR8X16
  ZTTAR16 ZTTAR16X2 ZTTAR16X4 ZTTAR16X8 ZTTAR16X16])
(define_mode_iterator ZTT_XA [
  ZTTAR1 ZTTAR2 ZTTAR4 ZTTAR1X2 ZTTAR1X4
  ZTTAR2X2 ZTTAP2X2 ZTTAP4X4 ZTTAP2X4 ZTTAP2X8
  ZTTAP4X8 ZTTAP4X16 ZTTAP8X8 ZTTAP8X16 ZTTAP16X16
  ZTTAR1X8 ZTTAR1X16 ZTTAR2X4 ZTTAR2X8 ZTTAR2X16
  ZTTAR4X2 ZTTAR4X4 ZTTAR4X8 ZTTAR8 ZTTAR8X2
  ZTTAR8X4 ZTTAR16 ZTTAR16X2 ZTTAP2X16])
(define_mode_attr ztt_acc_m [
  (ZTTAR1 "ZTTMR1")
  (ZTTAR2 "ZTTMR2")
  (ZTTAR4 "ZTTMR4")
  (ZTTAR1X2 "ZTTMR1")
  (ZTTAR1X4 "ZTTMR1")
  (ZTTAR2X2 "ZTTMR2")
  (ZTTAP2X2 "ZTTMR1")
  (ZTTAP4X4 "ZTTMR1")
  (ZTTAP2X4 "ZTTMR1")
  (ZTTAP2X8 "ZTTMR1")
  (ZTTAP4X8 "ZTTMR1")
  (ZTTAP4X16 "ZTTMR1")
  (ZTTAP8X8 "ZTTMR1")
  (ZTTAP8X16 "ZTTMR1")
  (ZTTAP16X16 "ZTTMR1")
  (ZTTAR1X8 "ZTTMR1")
  (ZTTAR1X16 "ZTTMR1")
  (ZTTAR2X4 "ZTTMR2")
  (ZTTAR2X8 "ZTTMR2")
  (ZTTAR2X16 "ZTTMR2")
  (ZTTAR4X2 "ZTTMR4")
  (ZTTAR4X4 "ZTTMR4")
  (ZTTAR4X8 "ZTTMR4")
  (ZTTAR4X16 "ZTTMR4")
  (ZTTAR8 "ZTTMR8")
  (ZTTAR8X2 "ZTTMR8")
  (ZTTAR8X4 "ZTTMR8")
  (ZTTAR8X8 "ZTTMR8")
  (ZTTAR8X16 "ZTTMR8")
  (ZTTAR16 "ZTTMR16")
  (ZTTAR16X2 "ZTTMR16")
  (ZTTAR16X4 "ZTTMR16")
  (ZTTAR16X8 "ZTTMR16")
  (ZTTAR16X16 "ZTTMR16")
  (ZTTAP2X16 "ZTTMR1")])
(define_mode_attr ztt_acc_full_m [
  (ZTTAR1 "ZTTMR1")
  (ZTTAR2 "ZTTMR2")
  (ZTTAR4 "ZTTMR4")
  (ZTTAR1X2 "ZTTMR2")
  (ZTTAR1X4 "ZTTMR4")
  (ZTTAR2X2 "ZTTMR4")
  (ZTTAP2X2 "ZTTMR1")
  (ZTTAP4X4 "ZTTMR1")
  (ZTTAP2X4 "ZTTMR2")
  (ZTTAP2X8 "ZTTMR4")
  (ZTTAP4X8 "ZTTMR2")
  (ZTTAP4X16 "ZTTMR4")
  (ZTTAP8X8 "ZTTMR1")
  (ZTTAP8X16 "ZTTMR2")
  (ZTTAP16X16 "ZTTMR1")
  (ZTTAR1X8 "ZTTMR8")
  (ZTTAR1X16 "ZTTMR16")
  (ZTTAR2X4 "ZTTMR8")
  (ZTTAR2X8 "ZTTMR16")
  (ZTTAR2X16 "ZTTMR32")
  (ZTTAR4X2 "ZTTMR8")
  (ZTTAR4X4 "ZTTMR16")
  (ZTTAR4X8 "ZTTMR32")
  (ZTTAR8 "ZTTMR8")
  (ZTTAR8X2 "ZTTMR16")
  (ZTTAR8X4 "ZTTMR32")
  (ZTTAR16 "ZTTMR16")
  (ZTTAR16X2 "ZTTMR32")
  (ZTTAP2X16 "ZTTMR8")])
(define_mode_attr ztt_acc_move_length [
  (ZTTAR1 "20,24,24")
  (ZTTAR2 "20,36,36")
  (ZTTAR4 "20,52,52")
  (ZTTAR1X2 "40,60,60")
  (ZTTAR1X4 "80,116,116")
  (ZTTAR2X2 "40,76,76")
  (ZTTAP2X2 "28,36,36")
  (ZTTAP4X4 "44,52,52")
  (ZTTAP2X4 "56,76,76")
  (ZTTAP2X8 "112,148,148")
  (ZTTAP4X8 "88,108,108")
  (ZTTAP4X16 "176,212,212")
  (ZTTAP8X8 "76,84,84")
  (ZTTAP8X16 "152,172,172")
  (ZTTAP16X16 "140,148,148")
  (ZTTAR1X8 "160,228,228")
  (ZTTAR1X16 "320,452,452")
  (ZTTAR2X4 "80,148,148")
  (ZTTAR2X8 "160,292,292")
  (ZTTAR2X16 "320,580,580")
  (ZTTAR4X2 "40,108,108")
  (ZTTAR4X4 "80,212,212")
  (ZTTAR4X8 "160,420,420")
  (ZTTAR4X16 "320,836,836")
  (ZTTAR8 "20,84,84")
  (ZTTAR8X2 "40,172,172")
  (ZTTAR8X4 "80,340,340")
  (ZTTAR8X8 "160,676,676")
  (ZTTAR8X16 "320,1348,1348")
  (ZTTAR16 "20,148,148")
  (ZTTAR16X2 "40,300,300")
  (ZTTAR16X4 "80,596,596")
  (ZTTAR16X8 "160,1188,1188")
  (ZTTAR16X16 "320,2372,2372")
  (ZTTAP2X16 "224,292,292")])
(define_mode_attr ztt_acc_stride_c [
  (ZTTAR1 "=X,X,X")
  (ZTTAR2 "=X,&r,&r")
  (ZTTAR4 "=X,&r,&r")
  (ZTTAR1X2 "=X,&r,&r")
  (ZTTAR1X4 "=X,&r,&r")
  (ZTTAR2X2 "=X,&r,&r")
  (ZTTAP2X2 "=X,X,X")
  (ZTTAP4X4 "=X,X,X")
  (ZTTAP2X4 "=X,&r,&r")
  (ZTTAP2X8 "=X,&r,&r")
  (ZTTAP4X8 "=X,&r,&r")
  (ZTTAP4X16 "=X,&r,&r")
  (ZTTAP8X8 "=X,X,X")
  (ZTTAP8X16 "=X,&r,&r")
  (ZTTAP16X16 "=X,X,X")
  (ZTTAR1X8 "=X,&r,&r")
  (ZTTAR1X16 "=X,&r,&r")
  (ZTTAR2X4 "=X,&r,&r")
  (ZTTAR2X8 "=X,&r,&r")
  (ZTTAR2X16 "=X,&r,&r")
  (ZTTAR4X2 "=X,&r,&r")
  (ZTTAR4X4 "=X,&r,&r")
  (ZTTAR4X8 "=X,&r,&r")
  (ZTTAR4X16 "=X,&r,&r")
  (ZTTAR8 "=X,&r,&r")
  (ZTTAR8X2 "=X,&r,&r")
  (ZTTAR8X4 "=X,&r,&r")
  (ZTTAR8X8 "=X,&r,&r")
  (ZTTAR8X16 "=X,&r,&r")
  (ZTTAR16 "=X,&r,&r")
  (ZTTAR16X2 "=X,&r,&r")
  (ZTTAR16X4 "=X,&r,&r")
  (ZTTAR16X8 "=X,&r,&r")
  (ZTTAR16X16 "=X,&r,&r")
  (ZTTAP2X16 "=X,&r,&r")])
(define_mode_attr ztt_acc_state_c [
  (ZTTAR1 "=X")
  (ZTTAR2 "=&r")
  (ZTTAR4 "=&r")
  (ZTTAR1X2 "=&r")
  (ZTTAR1X4 "=&r")
  (ZTTAR2X2 "=&r")
  (ZTTAP2X2 "=X")
  (ZTTAP4X4 "=X")
  (ZTTAP2X4 "=&r")
  (ZTTAP2X8 "=&r")
  (ZTTAP4X8 "=&r")
  (ZTTAP4X16 "=&r")
  (ZTTAP8X8 "=X")
  (ZTTAP8X16 "=&r")
  (ZTTAP16X16 "=X")
  (ZTTAR1X8 "=&r")
  (ZTTAR1X16 "=&r")
  (ZTTAR2X4 "=&r")
  (ZTTAR2X8 "=&r")
  (ZTTAR2X16 "=&r")
  (ZTTAR4X2 "=&r")
  (ZTTAR4X4 "=&r")
  (ZTTAR4X8 "=&r")
  (ZTTAR8 "=&r")
  (ZTTAR8X2 "=&r")
  (ZTTAR8X4 "=&r")
  (ZTTAR16 "=&r")
  (ZTTAR16X2 "=&r")
  (ZTTAP2X16 "=&r")])
(define_mode_attr ztt_acc_from_length [
  (ZTTAR1 "20")
  (ZTTAR2 "44")
  (ZTTAR4 "76")
  (ZTTAR1X2 "56")
  (ZTTAR1X4 "112")
  (ZTTAR2X2 "88")
  (ZTTAP2X2 "24")
  (ZTTAP4X4 "32")
  (ZTTAP2X4 "64")
  (ZTTAP2X8 "128")
  (ZTTAP4X8 "80")
  (ZTTAP4X16 "160")
  (ZTTAP8X8 "48")
  (ZTTAP8X16 "112")
  (ZTTAP16X16 "80")
  (ZTTAR1X8 "224")
  (ZTTAR1X16 "448")
  (ZTTAR2X4 "176")
  (ZTTAR2X8 "352")
  (ZTTAR2X16 "704")
  (ZTTAR4X2 "152")
  (ZTTAR4X4 "304")
  (ZTTAR4X8 "608")
  (ZTTAR8 "140")
  (ZTTAR8X2 "280")
  (ZTTAR8X4 "560")
  (ZTTAR16 "268")
  (ZTTAR16X2 "536")
  (ZTTAP2X16 "256")])
(define_mode_attr ztt_acc_mul_state_c [
  (ZTTAR1 "=X")
  (ZTTAR2 "=&r")
  (ZTTAR4 "=&r")
  (ZTTAR1X2 "=X")
  (ZTTAR1X4 "=X")
  (ZTTAR2X2 "=&r")
  (ZTTAR1X8 "=X")
  (ZTTAR1X16 "=X")
  (ZTTAR2X4 "=&r")
  (ZTTAR2X8 "=&r")
  (ZTTAR2X16 "=&r")
  (ZTTAR4X2 "=&r")
  (ZTTAR4X4 "=&r")
  (ZTTAR4X8 "=&r")
  (ZTTAR4X16 "=&r")
  (ZTTAR8 "=&r")
  (ZTTAR8X2 "=&r")
  (ZTTAR8X4 "=&r")
  (ZTTAR8X8 "=&r")
  (ZTTAR8X16 "=&r")
  (ZTTAR16 "=&r")
  (ZTTAR16X2 "=&r")
  (ZTTAR16X4 "=&r")
  (ZTTAR16X8 "=&r")
  (ZTTAR16X16 "=&r")])
(define_mode_attr ztt_acc_clear_length [
  (ZTTAR1 "4")
  (ZTTAR2 "4")
  (ZTTAR4 "4")
  (ZTTAR1X2 "8")
  (ZTTAR1X4 "16")
  (ZTTAR2X2 "8")
  (ZTTAP2X2 "8")
  (ZTTAP4X4 "16")
  (ZTTAP2X4 "16")
  (ZTTAP2X8 "32")
  (ZTTAP4X8 "32")
  (ZTTAP4X16 "64")
  (ZTTAP8X8 "32")
  (ZTTAP8X16 "64")
  (ZTTAP16X16 "64")
  (ZTTAR1X8 "32")
  (ZTTAR1X16 "64")
  (ZTTAR2X4 "16")
  (ZTTAR2X8 "32")
  (ZTTAR2X16 "64")
  (ZTTAR4X2 "8")
  (ZTTAR4X4 "16")
  (ZTTAR4X8 "32")
  (ZTTAR4X16 "64")
  (ZTTAR8 "4")
  (ZTTAR8X2 "8")
  (ZTTAR8X4 "16")
  (ZTTAR8X8 "32")
  (ZTTAR8X16 "64")
  (ZTTAR16 "4")
  (ZTTAR16X2 "8")
  (ZTTAR16X4 "16")
  (ZTTAR16X8 "32")
  (ZTTAR16X16 "64")
  (ZTTAP2X16 "64")])
(define_mode_attr ztt_acc_zero_length [
  (ZTTAR1 "8")
  (ZTTAR2 "8")
  (ZTTAR4 "8")
  (ZTTAR1X2 "16")
  (ZTTAR1X4 "32")
  (ZTTAR2X2 "16")
  (ZTTAP2X2 "16")
  (ZTTAP4X4 "32")
  (ZTTAP2X4 "32")
  (ZTTAP2X8 "64")
  (ZTTAP4X8 "64")
  (ZTTAP4X16 "128")
  (ZTTAP8X8 "64")
  (ZTTAP8X16 "128")
  (ZTTAP16X16 "128")
  (ZTTAR1X8 "64")
  (ZTTAR1X16 "128")
  (ZTTAR2X4 "32")
  (ZTTAR2X8 "64")
  (ZTTAR2X16 "128")
  (ZTTAR4X2 "16")
  (ZTTAR4X4 "32")
  (ZTTAR4X8 "64")
  (ZTTAR4X16 "128")
  (ZTTAR8 "8")
  (ZTTAR8X2 "16")
  (ZTTAR8X4 "32")
  (ZTTAR8X8 "64")
  (ZTTAR8X16 "128")
  (ZTTAR16 "8")
  (ZTTAR16X2 "16")
  (ZTTAR16X4 "32")
  (ZTTAR16X8 "64")
  (ZTTAR16X16 "128")
  (ZTTAP2X16 "128")])

(define_expand "mov<mode>"
  [(parallel
     [(set (match_operand:ZTT_A 0 "nonimmediate_operand")
           (match_operand:ZTT_A 1 "general_operand"))
      (clobber (match_dup 2))
      (clobber (match_dup 3))
      (clobber (match_dup 4))
      (clobber (match_dup 5))
      (use (match_dup 6))])]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)"
{
  if (MEM_P (operands[0]) && !REG_P (operands[1]))
    operands[1] = force_reg (<ZTT_A:MODE>mode, operands[1]);
  if (lra_in_progress && riscv_ztt_acc_reload_p ())
    {
      rtx slot = riscv_ztt_acc_reload_slot ();
      slot = replace_equiv_address
	(slot, force_reg (Pmode, XEXP (slot, 0)));
      emit_insn (gen_ztt_acc_borrowed_move
	(<ZTT_A:MODE>mode, Pmode, operands[0], operands[1], slot));
      DONE;
    }
  operands[2] = gen_rtx_SCRATCH (<ztt_acc_m>mode);
  operands[3] = gen_rtx_SCRATCH (Pmode);
  operands[4] = gen_rtx_SCRATCH (Pmode);
  operands[5] = gen_rtx_SCRATCH (Pmode);
  operands[6] = gen_rtx_REG (Pmode, RISCV_ZTT_SCALE_REGNUM);
})

(define_insn "*mov<ZTT_A:mode>_<P:mode>"
  [(set (match_operand:ZTT_A 0 "nonimmediate_operand" "=War,War,A")
        (match_operand:ZTT_A 1 "general_operand"       "War,A,War"))
   (clobber (match_scratch:<ztt_acc_m> 2 "=&Wmr,&Wmr,&Wmr"))
   (clobber (match_scratch:P 3 "=&r,&r,&r"))
   (clobber (match_scratch:P 4 "=X,&r,&r"))
   (clobber (match_scratch:P 5 "<ztt_acc_stride_c>"))
   (use (reg:P S11_REGNUM))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)"
{
  return riscv_ztt::output_acc_move (operands);
}
  [(set_attr "type" "multi")
   (set_attr "length" "<ztt_acc_move_length>")])

;; The M bank is internally borrowed and restored, not clobbered.  Md is
;; compiler-private here: the state pass prepares it at every typed use.
(define_insn "@ztt_acc_borrowed_move_<ZTT_A:mode>_<P:mode>"
  [(set (match_operand:ZTT_A 0 "nonimmediate_operand" "=War,War,A")
	(match_operand:ZTT_A 1 "general_operand" "War,A,War"))
   (clobber (match_operand 2 "memory_operand" "=A,A,A"))
   (clobber (match_scratch:P 3 "=&r,&r,&r"))
   (clobber (match_scratch:P 4 "=&r,&r,&r"))
   (clobber (match_scratch:P 5 "=&r,&r,&r"))
   (use (reg:P S11_REGNUM))]
  "TARGET_ZTT && riscv_ztt_acc_reload_p ()
   && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)"
{
  return riscv_ztt::output_acc_borrowed_move (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
	(symbol_ref "riscv_ztt::acc_borrowed_move_length (operands)"))])

(define_insn "@ztt_acc_clear_<ZTT_A:mode>_<P:mode>"
  [(set (match_operand:ZTT_A 0 "register_operand" "=War")
        (unspec_volatile:ZTT_A
          [(match_operand:P 1 "register_operand" "r")]
          UNSPECV_ZTT_ACC_CLEAR))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)"
{
  return riscv_ztt::output_acc_clear (operands, false);
}
  [(set_attr "type" "multi")
   (set_attr "length" "<ztt_acc_clear_length>")])

(define_insn "@ztt_acc_zero_<ZTT_A:mode>_<P:mode>"
  [(set (match_operand:ZTT_A 0 "register_operand" "=War")
        (unspec_volatile:ZTT_A
          [(match_operand:P 1 "register_operand" "r")]
          UNSPECV_ZTT_ACC_ZERO))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)"
{
  return riscv_ztt::output_acc_clear (operands, true);
}
  [(set_attr "type" "multi")
   (set_attr "length" "<ztt_acc_zero_length>")])

(define_insn "@ztt_acc_to_m_<ZTT_XA:mode>_<P:mode>"
  [(set (match_operand:<ztt_acc_full_m> 0 "register_operand" "=Wmr")
        (unspec_volatile:<ztt_acc_full_m>
          [(match_operand:ZTT_XA 1 "register_operand" "War")
           (match_operand:P 2 "register_operand" "r")]
          UNSPECV_ZTT_ACC_TO_M))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_XA:MODE>mode)"
{
  return riscv_ztt::output_acc_to_m (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "8 * riscv_ztt::acc_nregs (GET_MODE (operands[1])) / riscv_ztt::acc_transfer_accs (GET_MODE (operands[1]))"))])

;; The state pass supplies explicit private memory before IRA.  Never
;; clear a live M operand just to prepare its descriptor for an ACC move.
(define_insn "@ztt_typed_acc_from_m_<mode>"
  [(set (match_operand:ZTT_XA 0 "register_operand" "=War")
        (unspec:ZTT_XA
          [(match_operand:<ztt_acc_full_m> 1 "register_operand" "Wmr")
           (match_operand 2 "const_int_operand" "n")]
          UNSPEC_ZTT_ACC_FROM_M))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_XA:MODE>mode)"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_acc_from_m_<ZTT_XA:mode>_<P:mode>"
  [(set (match_operand:ZTT_XA 0 "register_operand" "=War")
        (unspec_volatile:ZTT_XA
          [(match_operand:<ztt_acc_full_m> 1 "register_operand" "Wmr")
          (match_operand:P 2 "register_operand" "r")
           (match_operand:P 4 "reg_or_0_operand" "rJ")
           (match_operand 5 "const_int_operand" "n")]
          UNSPECV_ZTT_ACC_FROM_M))
   (clobber (match_operand:<ztt_acc_full_m> 3 "memory_operand" "=A"))
   (clobber (match_scratch:P 6 "<ztt_acc_state_c>"))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_XA:MODE>mode)"
{
  return riscv_ztt::output_acc_state (operands, false);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (if_then_else (match_test "INTVAL (operands[5]) != 0")
                      (const_int 8)
                      (const_int <ztt_acc_from_length>)))])

;; Formed after allocation when every source packet already has its Md.
(define_insn "@ztt_acc_from_m_prepared_<ZTT_XA:mode>_<P:mode>"
  [(set (match_operand:ZTT_XA 0 "register_operand" "=War")
        (unspec_volatile:ZTT_XA
          [(match_operand:<ztt_acc_full_m> 1 "register_operand" "Wmr")
           (match_operand:P 2 "register_operand" "r")]
          UNSPECV_ZTT_ACC_FROM_M))]
  "TARGET_ZTT && reload_completed
   && riscv_ztt::acc_mode_supported_p (<ZTT_XA:MODE>mode)"
{
  return riscv_ztt::output_acc_from_m (operands);
}
  [(set_attr "type" "multi")
   (set (attr "length")
        (symbol_ref "4 * (riscv_ztt::acc_nregs (GET_MODE (operands[0])) + riscv_ztt::acc_nregs (GET_MODE (operands[0])) / riscv_ztt::acc_transfer_accs (GET_MODE (operands[0])))"))])

;; A tied accumulator input enforces read/modify/write.  When old_acc
;; remains live, ordinary ACC moves preserve it before the destructive
;; update; this also works when the profile provides only one ACC.
;;   Tuple results tie the entire
;; old value: only Square zero is updated and all other members survive.
(define_insn "@ztt_typed_acc_mmul_<mode>"
  [(set (match_operand:ZTT_NPA 0 "register_operand" "=War")
        (unspec:ZTT_NPA
          [(match_operand:ZTT_NPA 1 "register_operand" "0")
           (match_operand:<ztt_acc_m> 2 "register_operand" "Wmr")
           (match_operand:<ztt_acc_m> 3 "register_operand" "Wmr")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          UNSPEC_ZTT_ACC_MMUL))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_NPA:MODE>mode)"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_acc_mmul_<ZTT_NPA:mode>_<P:mode>"
  [(set (match_operand:ZTT_NPA 0 "register_operand" "=War")
        (unspec_volatile:ZTT_NPA
          [(match_operand:ZTT_NPA 1 "register_operand" "0")
           (match_operand:<ztt_acc_m> 2 "register_operand" "Wmr")
           (match_operand:<ztt_acc_m> 3 "register_operand" "Wmr")
           (match_operand:P 4 "register_operand" "r")
           (match_operand 7 "const_int_operand" "n")
           (match_operand:P 6 "reg_or_0_operand" "rJ")
           (match_operand 8 "const_int_operand" "n")]
          UNSPECV_ZTT_ACC_MMUL))
   (clobber (match_operand:<ztt_acc_m> 5 "memory_operand" "=A"))
   (clobber (match_scratch:P 9 "<ztt_acc_mul_state_c>"))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_NPA:MODE>mode)
   && IN_RANGE (INTVAL (operands[8]), 0, 3)"
{
  return riscv_ztt::output_acc_state (operands, true);
}
  [(set_attr "type" "multi")
   (set (attr "length")
	(symbol_ref "riscv_ztt::acc_mmul_length (operands, false)"))])

;; Both source groups have their required Md; retain the complete old ACC.
(define_insn "@ztt_acc_mmul_prepared_<mode>"
  [(set (match_operand:ZTT_A 0 "register_operand" "=War")
        (unspec_volatile:ZTT_A
          [(match_operand:ZTT_A 1 "register_operand" "0")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "register_operand" "Wmr")
           (match_operand 4 "const_int_operand" "n")]
          UNSPECV_ZTT_ACC_MMUL))]
  "TARGET_ZTT && reload_completed
   && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[3]))
   && IN_RANGE (INTVAL (operands[4]), 0, 5)"
{
  return riscv_ztt::acc_mmul_template (UINTVAL (operands[4]));
}
  [(set_attr "type" "multi")
   (set_attr "length" "4")])

;; Each source carries its own
;; complete runtime M mode and descriptor.  Do not infer either from ACC.
;; Packed formation uses one complete P-Square window of each source;
;; the output mode still owns every unchanged tail ACC and its actual Ad.
(define_insn "@ztt_typed_acc_mmul_mixed_<mode>"
  [(set (match_operand:ZTT_A 0 "register_operand" "=War")
        (unspec:ZTT_A
          [(match_operand:ZTT_A 1 "register_operand" "0")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "register_operand" "Wmr")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 6 "const_int_operand" "n")
           (match_operand 7 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          UNSPEC_ZTT_ACC_MMUL))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[3]))"
  "#"
  [(set_attr "type" "multi")])

;; Keep saturated and FP
;; tuples observable before the datatype-state pass, even for dead results
;; and FP inputs with integer destinations.  Preserve amefflags/amexsat.
(define_insn "@ztt_typed_acc_mmul_flags_<mode>"
  [(set (match_operand:ZTT_A 0 "register_operand" "=War")
        (unspec_volatile:ZTT_A
          [(match_operand:ZTT_A 1 "register_operand" "0")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "register_operand" "Wmr")
           (match_operand 5 "const_int_operand" "n")
           (match_operand 6 "const_int_operand" "n")
           (match_operand 7 "const_int_operand" "n")
           (match_operand 4 "const_int_operand" "n")]
          UNSPECV_ZTT_ACC_MMUL_FLAGS))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[3]))"
  "#"
  [(set_attr "type" "multi")])

(define_insn "@ztt_acc_mmul_mixed_<ZTT_A:mode>_<P:mode>"
  [(set (match_operand:ZTT_A 0 "register_operand" "=War")
        (unspec_volatile:ZTT_A
          [(match_operand:ZTT_A 1 "register_operand" "0")
           (match_operand 2 "register_operand" "Wmr")
           (match_operand 3 "register_operand" "Wmr")
           (match_operand:P 4 "reg_or_0_operand" "rJ")
           (match_operand 7 "const_int_operand" "n")
           (match_operand:P 6 "reg_or_0_operand" "rJ")
           (match_operand:P 8 "reg_or_0_operand" "rJ")
           (match_operand 9 "const_int_operand" "n")]
          UNSPECV_ZTT_ACC_MMUL))
   (clobber (match_operand 5 "memory_operand" "=A"))
   (clobber (match_scratch:P 10 "=&r"))]
  "TARGET_ZTT && riscv_ztt::acc_mode_supported_p (<ZTT_A:MODE>mode)
   && riscv_ztt::m_mode_p (GET_MODE (operands[2]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[3]))
   && riscv_ztt::m_mode_p (GET_MODE (operands[5]))
   && IN_RANGE (INTVAL (operands[9]), 0, 3)
   && (REG_P (operands[4])
       || (reload_completed && (INTVAL (operands[9]) & 1)))
   && (REG_P (operands[8])
       || (reload_completed && (INTVAL (operands[9]) & 2)))"
{
  return riscv_ztt::output_acc_state (operands, true, true);
}
  [(set_attr "type" "multi")
   (set (attr "length")
	(symbol_ref "riscv_ztt::acc_mmul_length (operands, true)"))])
