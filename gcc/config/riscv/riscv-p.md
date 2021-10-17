(define_mode_iterator VMOV_DSP [
    V4QI V2HI
    (V8QI "TARGET_64BIT")
    (V4HI "TARGET_64BIT")
    (V2SI "TARGET_64BIT")
])

(define_mode_iterator VQIMOD [V4QI (V8QI "TARGET_64BIT")])
(define_mode_iterator VHIMOD [V2HI (V4HI "TARGET_64BIT")])
(define_mode_iterator VSIMOD [SI (V2SI "TARGET_64BIT")])

(define_mode_attr vsdmod_attr
  [(V2HI "SI") (V4HI "DI")])

(define_mode_attr vssmod_attr
  [(V2HI "SI") (V4HI "V2SI")])

(define_mode_attr vhhmod_attr
  [(SI "V2HI") (V2SI "V4HI")])

(define_mode_attr vqsdmod_attr
  [(V4QI "SI") (V8QI "DI")])

(define_mode_attr sd2vqmod_attr
  [(SI "V4QI") (DI "V8QI")])

(define_mode_attr sdvhmod_attr
  [(SI "V2HI") (DI "V4HI")])

(define_mode_attr vsvqmod_attr
  [(SI "V4QI") (V2SI "V8QI")])

(define_mode_attr vqvhmod_attr
  [(V4QI "V2HI") (V8QI "V4HI")])

(define_mode_attr vssdmod_attr
  [(SI "SI") (V2SI "DI")])

(define_c_enum "unspec" [
  ;; Average with Rounding.
  UNSPEC_AVE

  ;; Bit Reverse
  UNSPEC_BITREV

  ;; UNSPEC_INSB
  UNSPEC_INSB

  ;; Bit-wise Pick
  UNSPEC_BPICK

  ;; SIMD 8-bit Integer Compare Equal
  UNSPEC_CMPEQ8

  ;; SIMD 16-bit Integer Compare Equal
  UNSPEC_CMPEQ16

  ;; SIMD 8-bit Count Leading Redundant Sign
  UNSPEC_CLRS8
  ;; SIMD 16-bit Count Leading Redundant Sign
  UNSPEC_CLRS16
  ;; SIMD 32-bit Count Leading Redundant Sign
  UNSPEC_CLRS32

  ;; SIMD 8-bit Count Leading One
  UNSPEC_CLO8
  ;; SIMD 16-bit Count Leading One
  UNSPEC_CLO16
  ;; SIMD 32-bit Count Leading One
  UNSPEC_CLO32

  ;; SIMD 8-bit Count Leading Zero
  UNSPEC_CLZ8
  ;; SIMD 16-bit Count Leading Zero
  UNSPEC_CLZ16
  ;; SIMD 32-bit Count Leading Zero
  UNSPEC_CLZ32

  ;; SIMD 16-bit Cross Addition & Subtraction
  UNSPEC_CRAS16

  ;; SIMD 16-bit Cross Subtraction & Addition
  UNSPEC_CRSA16

  ;; Signed Addition with Q15 Saturation
  UNSPEC_KADDH

  ;; Signed Addition with Q31 Saturation
  UNSPEC_KADDW

  ;; SIMD 16-bit Signed Saturating Cross Addition & Subtraction
  UNSPEC_KCRAS16

  ;; SIMD 16-bit Signed Saturating Cross Subtraction & Addition
  UNSPEC_KCRSA16

  ;; Signed Saturating Double Multiply B16 x B16
  UNSPEC_KDMBB

  ;; Signed Saturating Double Multiply B16 x T16
  UNSPEC_KDMBT

  ;; Signed Saturating Double Multiply T16 x T16
  UNSPEC_KDMTT

  ;; Signed Saturating Double Multiply Addition B16 x B16
  UNSPEC_KDMABB

  ;; Signed Saturating Double Multiply Addition B16 x T16
  UNSPEC_KDMABT

  ;; Signed Saturating Double Multiply Addition T16 x T16
  UNSPEC_KDMATT

  ;; SIMD Signed Saturating Q7 Multiply
  UNSPEC_KHM8

  ;; SIMD Signed Saturating Crossed Q7 Multiply
  UNSPEC_KHMX8

  ;; SIMD Signed Saturating Q15 Multiply
  UNSPEC_KHM16

  ;; SIMD Signed Saturating Crossed Q15 Multiply
  UNSPEC_KHMX16

  ;; Signed Saturating Half Multiply B16 x B16
  UNSPEC_KHMBB

  ;; Signed Saturating Half Multiply B16 x T16
  UNSPEC_KHMBT

  ;; Signed Saturating Half Multiply T16 x T16
  UNSPEC_KHMTT

  ;; SIMD Saturating Signed Multiply Bottom Halfs & Add
  UNSPEC_KMABB

  ;; SIMD Saturating Signed Multiply Bottom & Top Halfs & Add
  UNSPEC_KMABT

  ;; SIMD Saturating Signed Multiply Top Halfs & Add
  UNSPEC_KMATT

  ;; SIMD Saturating Signed Multiply Two Halfs and Two Adds
  UNSPEC_KMADA

  ;; SIMD Saturating Signed Crossed Multiply Two Halfs and Two Adds
  UNSPEC_KMAXDA

  ;; SIMD Saturating Signed Multiply Two Halfs & Subtract & Add
  UNSPEC_KMADS

  ;; SIMD Saturating Signed Multiply Two Halfs & Reverse Subtract & Add
  UNSPEC_KMADRS

  ;; SIMD Saturating Signed Crossed Multiply Two Halfs & Subtract & Add
  UNSPEC_KMAXDS

  ;; Signed Multiply and Saturating Add to 64-Bit Data
  UNSPEC_KMAR64

  ;; SIMD Signed Multiply Two Halfs and Add
  UNSPEC_KMDA

  ;; SIMD Signed Crossed Multiply Two Halfs and Add
  UNSPEC_KMXDA

  ;; SIMD Saturating MSW Signed Multiply Word and Add
  UNSPEC_KMMAC

  ;; SIMD Saturating MSW Signed Multiply Word and Add with Rounding
  UNSPEC_KMMAC_U

  ;; SIMD Saturating MSW Signed Multiply Word and Bottom Half and Add
  UNSPEC_KMMAWB

  ;; SIMD Saturating MSW Signed Multiply Word and Bottom Half and Add with Rounding
  UNSPEC_KMMAWB_U

  ;; SIMD Saturating MSW Signed Multiply Word and Bottom Half & 2 and Add
  UNSPEC_KMMAWB2

  ;; SIMD Saturating MSW Signed Multiply Word and Bottom Half & 2 and Add with Rounding
  UNSPEC_KMMAWB2_U

  ;; SIMD Saturating MSW Signed Multiply Word and Top Half and Add
  UNSPEC_KMMAWT

  ;; SIMD Saturating MSW Signed Multiply Word and Top Half and Add with Rounding
  UNSPEC_KMMAWT_U

  ;; SIMD Saturating MSW Signed Multiply Word and Top Half & 2 and Add
  UNSPEC_KMMAWT2

  ;; SIMD Saturating MSW Signed Multiply Word and Top Half & 2 and Add with Rounding
  UNSPEC_KMMAWT2_U

  ;; SIMD Saturating MSW Signed Multiply Word and Subtract
  UNSPEC_KMMSB

  ;; SIMD Saturating MSW Signed Multiply Word and Subtraction with Rounding
  UNSPEC_KMMSB_U

  ;; SIMD Saturating MSW Signed Multiply Word and Bottom Half & 2
  UNSPEC_KMMWB2

  ;; SIMD Saturating MSW Signed Multiply Word and Bottom Half & 2 with Rounding
  UNSPEC_KMMWB2_U

  ;; SIMD Saturating MSW Signed Multiply Word and Top Half & 2
  UNSPEC_KMMWT2

  ;; SIMD Saturating MSW Signed Multiply Word and Top Half & 2 with Rounding
  UNSPEC_KMMWT2_U

  ;; SIMD Saturating Signed Multiply Two Halfs & Add & Subtract
  UNSPEC_KMSDA

  ;; SIMD Saturating Signed Crossed Multiply Two Halfs & Add & Subtract
  UNSPEC_KMSXDA

  ;; Signed Multiply and Saturating Subtract from 64-Bit Data
  UNSPEC_KMSR64

  ;; SIMD 8-bit Shift Left Logical with Saturation or Shift Right Arithmetic
  UNSPEC_KSLRA8

  ;; SIMD 8-bit Shift Left Logical with Saturation or Rounding Shift Right Arithmetic
  UNSPEC_KSLRA8_U

  ;; SIMD 16-bit Shift Left Logical with Saturation or Shift Right Arithmetic
  UNSPEC_KSLRA16

  ;; SIMD 16-bit Shift Left Logical with Saturation or Rounding Shift Right Arithmetic
  UNSPEC_KSLRA16_U

  ;; Shift Left Logical with Q31 Saturation or Shift Right Arithmetic
  UNSPEC_KSLRAW

  ;; Shift Left Logical with Q31 Saturation or Rounding Shift Right Arithmetic
  UNSPEC_KSLRAW_U

  ;; SIMD 16-bit Signed Saturating Straight Addition & Subtraction
  UNSPEC_KSTAS16

  ;; SIMD 16-bit Signed Saturating Straight Subtraction & Addition
  UNSPEC_KSTSA16

  ;; Signed Subtraction with Q15 Saturation
  UNSPEC_KSUBH

  ;; Signed Subtraction with Q31 Saturation
  UNSPEC_KSUBW

  ;; Multiply and Add to 32-Bit Word
  UNSPEC_MADDR32

  ;; SIMD Saturating MSW Signed Multiply Word & Double
  UNSPEC_KWMMUL

  ;; SIMD Saturating MSW Signed Multiply Word & Double with Rounding
  UNSPEC_KWMMUL_U

  ;; Parallel Byte Sum of Absolute Difference
  UNSPEC_PBSAD

  ;; Parallel Byte Sum of Absolute Difference Accum
  UNSPEC_PBSADA

  ;; Pack Two 16-bit Data from Both Bottom Half
  UNSPEC_PKBB16

  ;; Pack Two 16-bit Data from Bottom and Top Half
  UNSPEC_PKBT16

  ;; Pack Two 16-bit Data from Both Top Half
  UNSPEC_PKTB16

  ;; Pack Two 16-bit Data from Top and Bottom Half
  UNSPEC_PKTT16

  ;; SIMD 8-bit Signed Halving Addition
  UNSPEC_RADD8

  ;; SIMD 16-bit Signed Halving Addition
  UNSPEC_RADD16

  ;; 32-bit Signed Halving Addition
  UNSPEC_RADDW

  ;; SIMD 16-bit Signed Halving Cross Addition & Subtraction
  UNSPEC_RCRAS16

  ;; SIMD 16-bit Signed Halving Cross Subtraction & Addition
  UNSPEC_RCRSA16

  ;; SIMD 16-bit Signed Halving Straight Addition & Subtraction
  UNSPEC_RSTAS16

  ;; SIMD 16-bit Signed Halving Straight Subtraction & Addition
  UNSPEC_RSTSA16

  ;; SIMD 8-bit Signed Halving Subtraction
  UNSPEC_RSUB8

  ;; SIMD 16-bit Signed Halving Subtraction
  UNSPEC_RSUB16

  ;; 64-bit Signed Halving Subtraction
  UNSPEC_RSUB64

  ;; 32-bit Signed Halving Subtraction
  UNSPEC_RSUBW

  ;; SIMD 8-bit Signed Clip Value
  UNSPEC_SCLIP8

  ;; SIMD 16-bit Signed Clip Value
  UNSPEC_SCLIP16

  ;; SIMD 32-bit Signed Clip Value
  UNSPEC_SCLIP32

  ;; SIMD 8-bit Signed Compare Less Than & Equal
  UNSPEC_SCMPLE8

  ;; SIMD 16-bit Signed Compare Less Than & Equal
  UNSPEC_SCMPLE16

  ;; SIMD 8-bit Signed Compare Less Than
  UNSPEC_SCMPLT8

  ;; SIMD 16-bit Signed Compare Less Than
  UNSPEC_SCMPLT16

  ;; Signed Multiply Halfs & Add 64-bit
  UNSPEC_SMAL

  ;; Signed Multiply Bottom Halfs & Add 64-bit
  UNSPEC_SMALBB

  ;; Signed Multiply Bottom Half & Top Half & Add 64-bit
  UNSPEC_SMALBT

  ;; Signed Multiply Top Halfs & Add 64-bit
  UNSPEC_SMALTT

  ;; Signed Multiply Two Halfs and Two Adds 64-bit
  UNSPEC_SMALDA

  ;; Signed Crossed Multiply Two Halfs and Two Adds 64-bit
  UNSPEC_SMALXDA

  ;; Signed Multiply Two Halfs & Subtract & Add 64-bit
  UNSPEC_SMALDS

  ;; Signed Multiply Two Halfs & Reverse Subtract & Add 64-bit
  UNSPEC_SMALDRS

  ;; Signed Crossed Multiply Two Halfs & Subtract & Add 64-bit
  UNSPEC_SMALXDS

  ;; Signed Multiply and Add to 64-Bit Data
  UNSPEC_SMAR64

  ;; Signed Multiply Four Bytes with 32-bit Adds
  UNSPEC_SMAQA

  ;; Signed and Unsigned Multiply Four Bytes with 32-bit Adds
  UNSPEC_SMAQA_SU

  ;; SIMD Signed Multiply Bottom Half & Bottom Half
  UNSPEC_SMBB16

  ;; SIMD Signed Multiply Bottom Half & Top Half
  UNSPEC_SMBT16

  ;; SIMD Signed Multiply Top Half & Top Half
  UNSPEC_SMTT16

  ;; SIMD Signed Multiply Two Halfs and Subtract
  UNSPEC_SMDS

  ;; SIMD Signed Multiply Two Halfs and Reverse Subtract
  UNSPEC_SMDRS

  ;; SIMD Signed Crossed Multiply Two Halfs and Subtract
  UNSPEC_SMXDS

  ;; SIMD MSW Signed Multiply Word
  UNSPEC_SMMUL

  ;; SIMD MSW Signed Multiply Word with Rounding
  UNSPEC_SMMUL_U

  ;; SIMD MSW Signed Multiply Word and Bottom Half
  UNSPEC_SMMWB

  ;; SIMD MSW Signed Multiply Word and Bottom Half with Rounding
  UNSPEC_SMMWB_U

  ;; SIMD MSW Signed Multiply Word and Top Half
  UNSPEC_SMMWT

  ;; SIMD MSW Signed Multiply Word and Top Half with Rounding
  UNSPEC_SMMWT_U

  ;; Signed Multiply Two Halfs & Add & Subtract 64-bit
  UNSPEC_SMSLDA

  ;; Signed Crossed Multiply Two Halfs & Add & Subtract 64-bit
  UNSPEC_SMSLXDA

  ;; Signed Multiply and Subtract from 64-Bit Data
  UNSPEC_SMSR64

  ;; SIMD Signed Crossed 8-bit Multiply
  UNSPEC_SMULX8

  ;; SIMD Signed Crossed 16-bit Multiply
  UNSPEC_SMULX16

  ;; Rounding Shift Right Arithmetic
  UNSPEC_SRA_U

  ;; SIMD 8-bit Rounding Shift Right Arithmetic
  UNSPEC_SRA8_U

  ;; SIMD 16-bit Rounding Shift Right Arithmetic
  UNSPEC_SRA16_U

  ;; SIMD 8-bit Rounding Shift Right Logical
  UNSPEC_SRL8_U

  ;; SIMD 16-bit Rounding Shift Right Logical
  UNSPEC_SRL16_U

  ;; SIMD 16-bit Straight Addition & Subtraction
  UNSPEC_STAS16

  ;; SIMD 16-bit Straight Subtraction & Addition
  UNSPEC_STSA16

  ;; Signed Unpacking
  UNSPEC_SUNPKD810
  UNSPEC_SUNPKD820
  UNSPEC_SUNPKD830
  UNSPEC_SUNPKD831
  UNSPEC_SUNPKD832

  ;; Swap Byte within Halfword
  UNSPEC_SWAP8

  ;; Swap Halfword within Word
  UNSPEC_SWAP16

  ;; SIMD 8-bit Unsigned Clip Value
  UNSPEC_UCLIP8

  ;; SIMD 16-bit Unsigned Clip Value
  UNSPEC_UCLIP16

  ;; SIMD 32-bit Unsigned Clip Value
  UNSPEC_UCLIP32

  ;; SIMD 8-bit Unsigned Compare Less Than & Equal
  UNSPEC_UCMPLE8

  ;; SIMD 16-bit Unsigned Compare Less Than & Equal
  UNSPEC_UCMPLE16

  ;; SIMD 8-bit Unsigned Compare Less Than
  UNSPEC_UCMPLT8

  ;; SIMD 16-bit Unsigned Compare Less Than
  UNSPEC_UCMPLT16

  ;; SIMD 16-bit Unsigned Saturating Cross Addition & Subtraction
  UNSPEC_UKCRAS16

  ;; SIMD 16-bit Unsigned Saturating Cross Subtraction & Addition
  UNSPEC_UKCRSA16

  ;; Unsigned Addition with U16 Saturation
  UNSPEC_UKADDH

  ;; Unsigned Addition with U32 Saturation
  UNSPEC_UKADDW

  ;; Signed Multiply and Saturating Add to 64-Bit Data
  UNSPEC_UKMAR64

  ;; Unsigned Multiply and Saturating Subtract from 64-Bit Data
  UNSPEC_UKMSR64

  ;; SIMD 16-bit Unsigned Saturating Straight Addition & Subtraction
  UNSPEC_UKSTAS16

  ;; SIMD 16-bit Unsigned Saturating Straight Subtraction & Addition
  UNSPEC_UKSTSA16

  ;; Unsigned Subtraction with U16 Saturation
  UNSPEC_UKSUBH

  ;; Unigned Subtraction with U32 Saturation
  UNSPEC_UKSUBW

  ;; Unsigned Multiply and Add to 64-Bit Data
  UNSPEC_UMAR64

  ;; Unsigned Multiply Four Bytes with 32-bit Adds
  UNSPEC_UMAQA

  ;; Unsigned Multiply and Subtract from 64-Bit Data
  UNSPEC_UMSR64

  ;; SIMD Unsigned Crossed 8-bit Multiply
  UNSPEC_UMULX8

  ;; SIMD Unsigned Crossed 16-bit Multiply
  UNSPEC_UMULX16

  ;; SIMD 8-bit Unsigned Halving Addition
  UNSPEC_URADD8

  ;; SIMD 16-bit Unsigned Halving Addition
  UNSPEC_URADD16

  ;; 32-bit Unsigned Halving Addition
  UNSPEC_URADDW

  ;; SIMD 16-bit Unsigned Halving Cross Addition & Subtraction
  UNSPEC_URCRAS16

  ;; SIMD 16-bit Unsigned Halving Cross Subtraction & Addition
  UNSPEC_URCRSA16

  ;; SIMD 16-bit Unsigned Halving Straight Addition & Subtraction
  UNSPEC_URSTAS16

  ;; SIMD 16-bit Unsigned Halving Straight Subtraction & Addition
  UNSPEC_URSTSA16

  ;; SIMD 8-bit Unsigned Halving Subtraction
  UNSPEC_URSUB8

  ;; SIMD 16-bit Unsigned Halving Subtraction
  UNSPEC_URSUB16

  ;; 64-bit Unsigned Halving Subtraction
  UNSPEC_URSUB64

  ;; 32-bit Unsigned Halving Subtraction
  UNSPEC_URSUBW

  ;; Unigned Unpacking
  UNSPEC_ZUNPKD810
  UNSPEC_ZUNPKD820
  UNSPEC_ZUNPKD830
  UNSPEC_ZUNPKD831
  UNSPEC_ZUNPKD832

  ;; Extract Word from 64-bit
  UNSPEC_WEXT

  ;; Multiply and Subtract from 32-Bit Word
  UNSPEC_MSUBR32

  UNSPEC_CRAS32
  UNSPEC_CRSA32
  UNSPEC_KCRAS32
  UNSPEC_KCRSA32

  ;; SIMD Signed Saturating Double Multiply B16 x B16
  UNSPEC_KDMBB16

  ;; SIMD Signed Saturating Double Multiply B16 x T16
  UNSPEC_KDMBT16

  ;; SIMD Signed Saturating Double Multiply T16 x T16
  UNSPEC_KDMTT16

  ;; SIMD Signed Saturating Double Multiply Addition B16 x B16
  UNSPEC_KDMABB16

  ;; SIMD Signed Saturating Double Multiply Addition B16 x T16
  UNSPEC_KDMABT16

  ;; SIMD Signed Saturating Double Multiply Addition T16 x T16
  UNSPEC_KDMATT16

  ;; SIMD Signed Saturating Half Multiply B16 x B16
  UNSPEC_KHMBB16

  ;; SIMD Signed Saturating Half Multiply B16 x T16
  UNSPEC_KHMBT16

  ;; SIMD Signed Saturating Half Multiply T16 x T16
  UNSPEC_KHMTT16

  ;; Saturating Signed Multiply Bottom Words & Add
  UNSPEC_KMABB32

  ;; Saturating Signed Multiply Bottom & Top Words & Add
  UNSPEC_KMABT32

  ;; Saturating Signed Multiply Top Words & Add
  UNSPEC_KMATT32

  ;; Saturating Signed Multiply Two Words and Two Adds
  UNSPEC_KMADA32

  ;; Saturating Signed Crossed Multiply Two Words and Two Adds
  UNSPEC_KMAXDA32

  ;; Saturating Signed Multiply Two Words & Subtract & Add
  UNSPEC_KMADS32

  ;; Saturating Signed Multiply Two Words & Reverse Subtract & Add
  UNSPEC_KMADRS32

  ;; Saturating Signed Crossed Multiply Two Words & Subtract & Add
  UNSPEC_KMAXDS32

  ;; Saturating Signed Multiply Two Words & Add & Subtract
  UNSPEC_KMSDA32

  ;; Saturating Signed Crossed Multiply Two Words & Add & Subtract
  UNSPEC_KMSXDA32

  ;; Signed Multiply Two Words and Add
  UNSPEC_KMDA32

  ;; Signed Crossed Multiply Two Words and Add
  UNSPEC_KMXDA32

  ;; SIMD 32-bit Unsigned Saturating Cross Addition & Subtraction
  UNSPEC_UKCRAS32

  ;; SIMD 32-bit Unsigned Saturating Cross Subtraction & Addition
  UNSPEC_UKCRSA32

  ;; SIMD 32-bit Signed Saturating Straight Addition & Subtraction
  UNSPEC_UKSTAS32

  ;; SIMD 32-bit Unsigned Saturating Straight Subtraction & Addition
  UNSPEC_UKSTSA32

  ;; SIMD 32-bit Unsigned Maximum
  UNSPEC_UMAX32

  ;; SIMD 32-bit Unsigned Minimum
  UNSPEC_UMIN32

  ;; SIMD 32-bit Unsigned Halving Addition
  UNSPEC_URADD32

  ;; SIMD 32-bit Unsigned Halving Cross Addition & Subtraction
  UNSPEC_URCRAS32

  ;; SIMD 32-bit Unsigned Halving Cross Subtraction & Addition
  UNSPEC_URCRSA32

  ;; SIMD 32-bit Unsigned Halving Straight Addition & Subtraction
  UNSPEC_URSTAS32

  ;; SIMD 32-bit Unsigned Halving Straight Subtraction & Addition
  UNSPEC_URSTSA32

  ;; SIMD 32-bit Unsigned Halving Subtraction
  UNSPEC_URSUB32

  ;; SIMD 32-bit Signed Saturating Straight Addition & Subtraction
  UNSPEC_KSTAS32

  ;; SIMD 32-bit Signed Saturating Straight Subtraction & Addition
  UNSPEC_KSTSA32

  ;; SIMD 32-bit Signed Halving Addition
  UNSPEC_RADD32

  ;; SIMD 32-bit Signed Halving Cross Addition & Subtraction
  UNSPEC_RCRAS32

  ;; SIMD 32-bit Signed Halving Cross Subtraction & Addition
  UNSPEC_RCRSA32

  ;; SIMD 32-bit Signed Halving Straight Addition & Subtraction
  UNSPEC_RSTAS32

  ;; SIMD 32-bit Signed Halving Straight Subtraction & Addition
  UNSPEC_RSTSA32

  ;; SIMD 32-bit Signed Halving Subtraction
  UNSPEC_RSUB32

  ;; SIMD 32-bit Straight signed Addition & Subtraction
  UNSPEC_STAS32
  UNSPEC_STSA32

  ;; Signed Multiply Bottom Word & Bottom Word
  UNSPEC_SMBB32

  ;; Signed Multiply Bottom Word & Top Word
  UNSPEC_SMBT32

  ;; Signed Multiply Top Word & Top Word
  UNSPEC_SMTT32

  ;; Signed Multiply Two Words and Subtract
  UNSPEC_SMDS32

  ;; Signed Multiply Two Words and Reverse Subtract
  UNSPEC_SMDRS32

  ;; Signed Crossed Multiply Two Words and Subtract
  UNSPEC_SMXDS32

  ;; Pack Two 32-bit Data from Both Bottom Half
  UNSPEC_PKBB32

  ;; Pack Two 32-bit Data from Bottom and Top Half
  UNSPEC_PKBT32

  ;; Pack Two 32-bit Data from Both Top Half
  UNSPEC_PKTB32

  ;; Pack Two 32-bit Data from Top and Bottom Half
  UNSPEC_PKTT32

  ;; SIMD 32-bit Rounding Shift Right Arithmetic
  UNSPEC_SRA32_U

  ;; SIMD 32-bit Rounding Shift Right Logical
  UNSPEC_SRL32_U

  ;; SIMD 32-bit Shift Left Logical with Saturation or Shift Right Arithmetic
  UNSPEC_KSLRA32

  ;; SIMD 32-bit Shift Left Logical with Saturation or Rounding Shift Right Arithmetic
  UNSPEC_KSLRA32_U

  ;; Rounding Shift Right Arithmetic Immediate Word
  UNSPEC_SRAW_U
])

(define_c_enum "unspecv" [
  ;; Read vxsat.OV flag
  UNSPECV_RDOV

  ;; Clear vxsat.OV flag
  UNSPECV_CLROV
])


;;============================================== mov<vmov_dsp> pattern ================================================

(define_expand "mov<mode>"
  [(set (match_operand:VMOV_DSP 0 "nonimmediate_operand")
	(match_operand:VMOV_DSP 1 "general_operand"))]
  "TARGET_XTHEAD_DSP || TARGET_XTHEAD_ZPSFOPERAND"
{
  if (can_create_pseudo_p ())
    {
      if (!REG_P (operands[0]))
	operands[1] = force_reg (<MODE>mode, operands[1]);
    }
})

(define_insn "*mov<mode>"
  [(set (match_operand:VMOV_DSP 0 "nonimmediate_operand"  "=r,m,r")
	(match_operand:VMOV_DSP 1 "general_operand"       " r,r,m"))]
  "TARGET_XTHEAD_DSP || TARGET_XTHEAD_ZPSFOPERAND"
  {
    return riscv_output_move (operands[0], operands[1]);
  }
)

;; Auto-Vectorization

;; Public SPN
(define_code_iterator varith_op_code
  [plus minus
   ss_plus us_plus
   ss_minus us_minus
   smax smin
   umax umin
])

(define_code_attr varith_op_name
   [(plus "add") (minus "sub")
    (ss_plus "ssadd") (us_plus "usadd")
    (ss_minus "sssub") (us_minus "ussub")
    (smax "smax") (smin "smin")
    (umax "umax") (umin "umin")
])

(define_code_attr varith_op_vext_name
   [(plus "add") (minus "sub")
    (ss_plus "sadd") (us_plus "saddu")
    (ss_minus "ssub") (us_minus "ssubu")
    (smax "max") (smin "min")
    (umax "maxu") (umin "minu")
])

(define_expand "<varith_op_name><mode>3"
  [(set (match_operand:VMOV_DSP 0 "register_operand" "=r")
	(varith_op_code:VMOV_DSP (match_operand:VMOV_DSP 1 "register_operand" "r")
				 (match_operand:VMOV_DSP 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  ""
)


(define_expand "<optab><mode>3"
  [(set (match_operand:VMOV_DSP 0 "register_operand")
	(any_shift:VMOV_DSP (match_operand:VMOV_DSP 1 "register_operand")
			    (match_operand:SI 2 "nonmemory_operand")))]
  "TARGET_XTHEAD_DSP"
  ""
)

(define_expand "maddsidi4"
  [(match_operand:DI 0 "register_operand")
   (match_operand:SI 1 "register_operand")
   (match_operand:SI 2 "register_operand")
   (match_operand:DI 3 "register_operand")]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  {
    emit_insn (gen_riscv_smar64_si (operands[0], operands[3], operands[1], operands[2]));
    DONE;
  }
)

(define_expand "umaddsidi4"
  [(match_operand:DI 0 "register_operand")
   (match_operand:SI 1 "register_operand")
   (match_operand:SI 2 "register_operand")
   (match_operand:DI 3 "register_operand")]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  {
    emit_insn (gen_riscv_umar64_si (operands[0], operands[3], operands[1], operands[2]));
    DONE;
  }
)

(define_expand "msubsidi4"
  [(match_operand:DI 0 "register_operand")
   (match_operand:SI 1 "register_operand")
   (match_operand:SI 2 "register_operand")
   (match_operand:DI 3 "register_operand")]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  {
    emit_insn (gen_riscv_smsr64_si (operands[0], operands[3], operands[1], operands[2]));
    DONE;
  }
)

(define_expand "umsubsidi4"
  [(match_operand:DI 0 "register_operand")
   (match_operand:SI 1 "register_operand")
   (match_operand:SI 2 "register_operand")
   (match_operand:DI 3 "register_operand")]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  {
    emit_insn (gen_riscv_umsr64_si (operands[0], operands[3], operands[1], operands[2]));
    DONE;
  }
)


;;==================================================== RV32 & RV64 ====================================================

(define_int_attr simd8_int_str [
   (UNSPEC_KHM8 "khm8")
   (UNSPEC_KHMX8 "khmx8")
   (UNSPEC_RADD8 "radd8")
   (UNSPEC_RSUB8 "rsub8")
   (UNSPEC_URADD8 "uradd8")
   (UNSPEC_URSUB8 "ursub8")
])

(define_int_attr simd8_int_insn [
   (UNSPEC_KHM8 "khm8")
   (UNSPEC_KHMX8 "khmx8")
   (UNSPEC_RADD8 "radd8")
   (UNSPEC_RSUB8 "rsub8")
   (UNSPEC_URADD8 "uradd8")
   (UNSPEC_URSUB8 "ursub8")
])

(define_int_iterator UNSPEC_SIMD8 [
   UNSPEC_KHM8
   UNSPEC_KHMX8
   UNSPEC_RADD8
   UNSPEC_RSUB8
   UNSPEC_URADD8
   UNSPEC_URSUB8
])

(define_insn "riscv_<simd8_int_str>_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:VQIMOD 2 "register_operand" "r")]
	   UNSPEC_SIMD8))]
  "TARGET_XTHEAD_DSP"
  "<simd8_int_insn>\\t%0,%1,%2"
)

(define_int_attr simd16_int_str [
   (UNSPEC_CRAS16 "cras16")
   (UNSPEC_CRSA16 "crsa16")
   (UNSPEC_KCRAS16 "kcras16")
   (UNSPEC_KCRSA16 "kcrsa16")
   (UNSPEC_KHM16 "khm16")
   (UNSPEC_KHMX16 "khmx16")
   (UNSPEC_KSTAS16 "kstas16")
   (UNSPEC_KSTSA16 "kstsa16")
   (UNSPEC_PKBB16 "pkbb16")
   (UNSPEC_PKBT16 "pkbt16")
   (UNSPEC_PKTB16 "pktb16")
   (UNSPEC_PKTT16 "pktt16")
   (UNSPEC_RADD16 "radd16")
   (UNSPEC_RCRAS16 "rcras16")
   (UNSPEC_RCRSA16 "rcrsa16")
   (UNSPEC_RSTAS16 "rstas16")
   (UNSPEC_RSTSA16 "rstsa16")
   (UNSPEC_RSUB16 "rsub16")
   (UNSPEC_STAS16 "stas16")
   (UNSPEC_STSA16 "stsa16")
   (UNSPEC_UKCRAS16 "ukcras16")
   (UNSPEC_UKCRSA16 "ukcrsa16")
   (UNSPEC_UKSTAS16 "ukstas16")
   (UNSPEC_UKSTSA16 "ukstsa16")
   (UNSPEC_URADD16 "uradd16")
   (UNSPEC_URCRAS16 "urcras16")
   (UNSPEC_URCRSA16 "urcrsa16")
   (UNSPEC_URSTAS16 "urstas16")
   (UNSPEC_URSTSA16 "urstsa16")
   (UNSPEC_URSUB16 "ursub16")])

(define_int_attr simd16_int_insn [
   (UNSPEC_CRAS16 "cras16")
   (UNSPEC_CRSA16 "crsa16")
   (UNSPEC_KCRAS16 "kcras16")
   (UNSPEC_KCRSA16 "kcrsa16")
   (UNSPEC_KHM16 "khm16")
   (UNSPEC_KHMX16 "khmx16")
   (UNSPEC_KSTAS16 "kstas16")
   (UNSPEC_KSTSA16 "kstsa16")
   (UNSPEC_PKBB16 "pkbb16")
   (UNSPEC_PKBT16 "pkbt16")
   (UNSPEC_PKTB16 "pktb16")
   (UNSPEC_PKTT16 "pktt16")
   (UNSPEC_RADD16 "radd16")
   (UNSPEC_RCRAS16 "rcras16")
   (UNSPEC_RCRSA16 "rcrsa16")
   (UNSPEC_RSTAS16 "rstas16")
   (UNSPEC_RSTSA16 "rstsa16")
   (UNSPEC_RSUB16 "rsub16")
   (UNSPEC_STAS16 "stas16")
   (UNSPEC_STSA16 "stsa16")
   (UNSPEC_UKCRAS16 "ukcras16")
   (UNSPEC_UKCRSA16 "ukcrsa16")
   (UNSPEC_UKSTAS16 "ukstas16")
   (UNSPEC_UKSTSA16 "ukstsa16")
   (UNSPEC_URADD16 "uradd16")
   (UNSPEC_URCRAS16 "urcras16")
   (UNSPEC_URCRSA16 "urcrsa16")
   (UNSPEC_URSTAS16 "urstas16")
   (UNSPEC_URSTSA16 "urstsa16")
   (UNSPEC_URSUB16 "ursub16")])

(define_int_iterator UNSPEC_SIMD16 [
   UNSPEC_CRAS16
   UNSPEC_CRSA16
   UNSPEC_KCRAS16
   UNSPEC_KCRSA16
   UNSPEC_KHM16
   UNSPEC_KHMX16
   UNSPEC_KSTAS16
   UNSPEC_KSTSA16
   UNSPEC_RADD16
   UNSPEC_RCRAS16
   UNSPEC_RCRSA16
   UNSPEC_RSTAS16
   UNSPEC_RSTSA16
   UNSPEC_RSUB16
   UNSPEC_STAS16
   UNSPEC_STSA16
   UNSPEC_UKCRAS16
   UNSPEC_UKCRSA16
   UNSPEC_UKSTAS16
   UNSPEC_UKSTSA16
   UNSPEC_URADD16
   UNSPEC_URCRAS16
   UNSPEC_URCRSA16
   UNSPEC_URSTAS16
   UNSPEC_URSTSA16
   UNSPEC_URSUB16
])

(define_insn "riscv_<simd16_int_str>_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
      [(match_operand:VHIMOD 1 "register_operand" "r")
       (match_operand:VHIMOD 2 "register_operand" "r")]
       UNSPEC_SIMD16))]
  "TARGET_XTHEAD_DSP"
  "<simd16_int_insn>\\t%0,%1,%2"
)

(define_int_iterator UNSPEC_PACK16 [
   UNSPEC_PKBB16
   UNSPEC_PKBT16
   UNSPEC_PKTB16
   UNSPEC_PKTT16
])

(define_insn "riscv_<simd16_int_str>_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
      [(match_operand:VHIMOD 1 "register_operand" "r")
       (match_operand:VHIMOD 2 "register_operand" "r")]
       UNSPEC_PACK16))]
  "TARGET_XTHEAD_DSP"
  "<simd16_int_insn>\\t%0,%1,%2"
)

(define_insn "riscv_add8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
    (plus:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")
		 (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "add8\\t%0,%1,%2"
)

(define_insn "riscv_add16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
    (plus:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")
		 (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "add16\\t%0,%1,%2"
)

(define_insn "riscv_add64"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (plus:DI (match_operand:DI 1 "register_operand" "r")
	     (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "add64\\t%0,%1,%2"
)

(define_insn "riscv_ave_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
      [(match_operand:GPR 1 "register_operand" "r")
       (match_operand:GPR 2 "register_operand" "r")]
       UNSPEC_AVE))]
  "TARGET_XTHEAD_DSP"
  "ave\\t%0,%1,%2"
)

(define_insn "riscv_bitrev_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
      [(match_operand:GPR 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")]
       UNSPEC_BITREV))]
  "TARGET_XTHEAD_DSP"
  "bitrev\\t%0,%1,%2"
)

(define_insn "riscv_bitrevi_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
      [(match_operand:GPR 1 "register_operand" "r")
       (match_operand:SI 2 "immediate_operand" "i")]
       UNSPEC_BITREV))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & (BITS_PER_WORD - 1));
  return "bitrevi\\t%0,%1,%2";
}
)

(define_insn "riscv_insb_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
      [(match_operand:GPR 1 "register_operand" "0")
       (match_operand:GPR 2 "register_operand" "r")
       (match_operand:SI 3 "immediate_operand" "i")]
       UNSPEC_INSB))]
  "TARGET_XTHEAD_DSP"
{
  operands[3] = GEN_INT (INTVAL (operands[3]) & (UNITS_PER_WORD - 1));
  return "insb\\t%0,%2,%3";
}
)

(define_insn "riscv_bpick_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
      [(match_operand:GPR 1 "register_operand" "r")
       (match_operand:GPR 2 "register_operand" "r")
       (match_operand:GPR 3 "register_operand" "r")]
       UNSPEC_BPICK))]
  "TARGET_XTHEAD_DSP"
  "bpick\\t%0,%1,%2,%3"
)

(define_insn "riscv_clrs8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
      [(match_operand:VQIMOD 1 "register_operand" "r")]
       UNSPEC_CLRS8))]
  "TARGET_XTHEAD_DSP"
  "clrs8\\t%0,%1"
)

(define_insn "riscv_clrs16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
      [(match_operand:VHIMOD 1 "register_operand" "r")]
       UNSPEC_CLRS16))]
  "TARGET_XTHEAD_DSP"
  "clrs16\\t%0,%1"
)

(define_insn "riscv_clrs32_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
     (unspec:VSIMOD
      [(match_operand:VSIMOD 1 "register_operand" "r")]
       UNSPEC_CLRS32))]
  "TARGET_XTHEAD_DSP"
  "clrs32\\t%0,%1"
)

(define_insn "riscv_clo8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
      [(match_operand:VQIMOD 1 "register_operand" "r")]
       UNSPEC_CLO8))]
  "TARGET_XTHEAD_DSP"
  "clo8\\t%0,%1"
)

(define_insn "riscv_clo16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
      [(match_operand:VHIMOD 1 "register_operand" "r")]
       UNSPEC_CLO16))]
  "TARGET_XTHEAD_DSP"
  "clo16\\t%0,%1"
)

(define_insn "riscv_clo32_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
     (unspec:VSIMOD
      [(match_operand:VSIMOD 1 "register_operand" "r")]
       UNSPEC_CLO32))]
  "TARGET_XTHEAD_DSP"
  "clo32\\t%0,%1"
)

(define_insn "riscv_clz8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
      [(match_operand:VQIMOD 1 "register_operand" "r")]
       UNSPEC_CLZ8))]
  "TARGET_XTHEAD_DSP"
  "clz8\\t%0,%1"
)

(define_insn "riscv_clz16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
      [(match_operand:VHIMOD 1 "register_operand" "r")]
       UNSPEC_CLZ16))]
  "TARGET_XTHEAD_DSP"
  "clz16\\t%0,%1"
)

(define_insn "riscv_clz32_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
     (unspec:VSIMOD
      [(match_operand:VSIMOD 1 "register_operand" "r")]
       UNSPEC_CLZ32))]
  "TARGET_XTHEAD_DSP"
  "clz32\\t%0,%1"
)

(define_insn "riscv_cmpeq8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:VQIMOD 2 "register_operand" "r")]
	   UNSPEC_CMPEQ8))]
  "TARGET_XTHEAD_DSP"
  "cmpeq8\\t%0,%1,%2"
)

(define_insn "riscv_cmpeq16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_CMPEQ16))]
  "TARGET_XTHEAD_DSP"
  "cmpeq16\\t%0,%1,%2"
)

(define_insn "riscv_kabs8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ss_abs:VQIMOD
       (match_operand:VQIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "kabs8\\t%0,%1"
)

(define_insn "riscv_kabs16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(ss_abs:VHIMOD
	  (match_operand:VHIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "kabs16\\t%0,%1"
)

(define_insn "riscv_kabsw"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(ss_abs:SI
	  (match_operand:SI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "kabsw\\t%0,%1"
)

(define_insn "riscv_kabsw_di"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (ss_abs:SI
	  (match_operand:DI 1 "register_operand" "r"))))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "kabsw\\t%0,%1"
)

(define_insn "riscv_kadd8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
    (ss_plus:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")
		    (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "kadd8\\t%0,%1,%2"
)

(define_insn "riscv_kadd16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
    (ss_plus:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")
		    (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "kadd16\\t%0,%1,%2"
)

(define_insn "riscv_kadd64"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ss_plus:DI (match_operand:DI 1 "register_operand" "r")
		(match_operand:DI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "kadd64\\t%0,%1,%2"
)

(define_insn "riscv_kaddh_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KADDH))]
  "TARGET_XTHEAD_DSP"
  "kaddh\\t%0,%1,%2"
)

(define_insn "riscv_kaddw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KADDW))]
  "TARGET_XTHEAD_DSP"
  "kaddw\\t%0,%1,%2"
)

(define_int_iterator UNSPEC_KDMXY [
   UNSPEC_KDMBB
   UNSPEC_KDMBT
   UNSPEC_KDMTT
])

(define_int_attr kdmxy_insn [
   (UNSPEC_KDMBB "kdmbb")
   (UNSPEC_KDMBT "kdmbt")
   (UNSPEC_KDMTT "kdmtt")
])

(define_insn "riscv_<kdmxy_insn>"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI
	  [(match_operand:V2HI 1 "register_operand" "r")
	   (match_operand:V2HI 2 "register_operand" "r")]
	   UNSPEC_KDMXY))]
  "TARGET_XTHEAD_DSP"
  "<kdmxy_insn>\\t%0,%1,%2"
)

(define_insn "riscv_<kdmxy_insn>_di"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (unspec:SI
	    [(match_operand:V2HI 1 "register_operand" "r")
	     (match_operand:V2HI 2 "register_operand" "r")]
	    UNSPEC_KDMXY)))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<kdmxy_insn>\\t%0,%1,%2"
)

(define_int_iterator UNSPEC_KDMAXY [
   UNSPEC_KDMABB
   UNSPEC_KDMABT
   UNSPEC_KDMATT
])

(define_int_attr kdmaxy_insn [
   (UNSPEC_KDMABB "kdmabb")
   (UNSPEC_KDMABT "kdmabt")
   (UNSPEC_KDMATT "kdmatt")
])

(define_insn "riscv_<kdmaxy_insn>"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(unspec:SI
	  [(match_operand:SI 1 "register_operand" "0")
	   (match_operand:V2HI 2 "register_operand" "r")
	   (match_operand:V2HI 3 "register_operand" "r")]
	   UNSPEC_KDMAXY))]
  "TARGET_XTHEAD_DSP"
  "<kdmaxy_insn>\\t%0,%2,%3"
)

(define_insn "riscv_<kdmaxy_insn>_di"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (unspec:SI
	    [(match_operand:SI 1 "register_operand" "0")
	     (match_operand:V2HI 2 "register_operand" "r")
	     (match_operand:V2HI 3 "register_operand" "r")]
	    UNSPEC_KDMAXY)))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<kdmaxy_insn>\\t%0,%2,%3"
)

(define_insn "riscv_khmbb_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:V2HI 1 "register_operand" "r")
	   (match_operand:V2HI 2 "register_operand" "r")]
	   UNSPEC_KHMBB))]
  "TARGET_XTHEAD_DSP"
  "khmbb\\t%0,%1,%2"
)

(define_insn "riscv_khmbt_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:V2HI 1 "register_operand" "r")
	   (match_operand:V2HI 2 "register_operand" "r")]
	   UNSPEC_KHMBT))]
  "TARGET_XTHEAD_DSP"
  "khmbt\\t%0,%1,%2"
)

(define_insn "riscv_khmtt_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:V2HI 1 "register_operand" "r")
	   (match_operand:V2HI 2 "register_operand" "r")]
	   UNSPEC_KHMTT))]
  "TARGET_XTHEAD_DSP"
  "khmtt\\t%0,%1,%2"
)

(define_insn "riscv_kmabb_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMABB))]
  "TARGET_XTHEAD_DSP"
  "kmabb\\t%0,%2,%3"
)

(define_insn "riscv_kmabt_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMABT))]
  "TARGET_XTHEAD_DSP"
  "kmabt\\t%0,%2,%3"
)

(define_insn "riscv_kmatt_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMATT))]
  "TARGET_XTHEAD_DSP"
  "kmatt\\t%0,%2,%3"
)

(define_insn "riscv_kmada_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMADA))]
  "TARGET_XTHEAD_DSP"
  "kmada\\t%0,%2,%3"
)

(define_insn "riscv_kmaxda_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMAXDA))]
  "TARGET_XTHEAD_DSP"
  "kmaxda\\t%0,%2,%3"
)

(define_insn "riscv_kmads_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMADS))]
  "TARGET_XTHEAD_DSP"
  "kmads\\t%0,%2,%3"
)

(define_insn "riscv_kmadrs_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMADRS))]
  "TARGET_XTHEAD_DSP"
  "kmadrs\\t%0,%2,%3"
)

(define_insn "riscv_kmaxds_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMAXDS))]
  "TARGET_XTHEAD_DSP"
  "kmaxds\\t%0,%2,%3"
)

(define_insn "riscv_kmar64_<mode>"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI
	  [(match_operand:DI 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:VSIMOD 3 "register_operand" "r")]
	   UNSPEC_KMAR64))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "kmar64\\t%0,%2,%3"
)

(define_insn "riscv_kmda_<mode>"
  [(set (match_operand:<vssmod_attr> 0 "register_operand" "=r")
	(unspec:<vssmod_attr>
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_KMDA))]
  "TARGET_XTHEAD_DSP"
  "kmda\\t%0,%1,%2"
)

(define_insn "riscv_kmxda_<mode>"
  [(set (match_operand:<vssmod_attr> 0 "register_operand" "=r")
	(unspec:<vssmod_attr>
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_KMXDA))]
  "TARGET_XTHEAD_DSP"
  "kmxda\\t%0,%1,%2"
)

(define_insn "riscv_kmmac_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:VSIMOD 3 "register_operand" "r")]
	   UNSPEC_KMMAC))]
  "TARGET_XTHEAD_DSP"
  "kmmac\\t%0,%2,%3"
)

(define_insn "riscv_kmmac_u_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:VSIMOD 3 "register_operand" "r")]
	   UNSPEC_KMMAC_U))]
  "TARGET_XTHEAD_DSP"
  "kmmac.u\\t%0,%2,%3"
)

(define_insn "riscv_kmmawb_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWB))]
  "TARGET_XTHEAD_DSP"
  "kmmawb\\t%0,%2,%3"
)

(define_insn "riscv_kmmawb_u_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWB_U))]
  "TARGET_XTHEAD_DSP"
  "kmmawb.u\\t%0,%2,%3"
)

(define_insn "riscv_kmmawb2_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWB2))]
  "TARGET_XTHEAD_DSP"
  "kmmawb2\\t%0,%2,%3"
)

(define_insn "riscv_kmmawb2_u_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWB2_U))]
  "TARGET_XTHEAD_DSP"
  "kmmawb2.u\\t%0,%2,%3"
)

(define_insn "riscv_kmmawt_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWT))]
  "TARGET_XTHEAD_DSP"
  "kmmawt\\t%0,%2,%3"
)

(define_insn "riscv_kmmawt_u_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWT_U))]
  "TARGET_XTHEAD_DSP"
  "kmmawt.u\\t%0,%2,%3"
)

(define_insn "riscv_kmmawt2_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWT2))]
  "TARGET_XTHEAD_DSP"
  "kmmawt2\\t%0,%2,%3"
)

(define_insn "riscv_kmmawt2_u_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMMAWT2_U))]
  "TARGET_XTHEAD_DSP"
  "kmmawt2.u\\t%0,%2,%3"
)

(define_insn "riscv_kmmsb_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:VSIMOD 3 "register_operand" "r")]
	   UNSPEC_KMMSB))]
  "TARGET_XTHEAD_DSP"
  "kmmsb\\t%0,%2,%3"
)

(define_insn "riscv_kmmsb_u_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:VSIMOD 3 "register_operand" "r")]
	   UNSPEC_KMMSB_U))]
  "TARGET_XTHEAD_DSP"
  "kmmsb.u\\t%0,%2,%3"
)

(define_insn "riscv_kmsda_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMSDA))]
  "TARGET_XTHEAD_DSP"
  "kmsda\\t%0,%2,%3"
)

(define_insn "riscv_kmsxda_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")
	   (match_operand:<vhhmod_attr> 3 "register_operand" "r")]
	   UNSPEC_KMSXDA))]
  "TARGET_XTHEAD_DSP"
  "kmsxda\\t%0,%2,%3"
)

(define_insn "riscv_kmsr64_<mode>"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (unspec:DI
      [(match_operand:DI 1 "register_operand" "0")
       (match_operand:VSIMOD 2 "register_operand" "r")
       (match_operand:VSIMOD 3 "register_operand" "r")]
       UNSPEC_KMSR64))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "kmsr64\\t%0,%2,%3"
)

(define_insn "riscv_ksllw"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
     (ss_ashift:SI
	(match_operand:SI 1 "register_operand" "r,r")
	(match_operand:SI 2 "const_int_or_reg_operand" "i,r")))]
  "TARGET_XTHEAD_DSP"
{
  if (which_alternative == 0)
    {
      operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "kslliw\\t%0,%1,%2";
    }
  else
    return "ksllw\\t%0,%1,%2";
}
)

(define_insn "riscv_ksllw_di"
  [(set (match_operand:DI 0 "register_operand" "=r,r")
	(sign_extend:DI (ss_ashift:SI
	    (match_operand:SI 1 "register_operand" "r,r")
	    (match_operand:SI 2 "const_int_or_reg_operand" "i,r"))))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
{
  if (which_alternative == 0)
    {
      operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
      return "kslliw\\t%0,%1,%2";
    }
  else
    return "ksllw\\t%0,%1,%2";
}
)

(define_insn "riscv_ksll8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ss_ashift:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ksll8\\t%0,%1,%2"
)

(define_insn "riscv_kslli8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ss_ashift:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "kslli8\\t%0,%1,%2";
}
)

(define_insn "riscv_ksll16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (ss_ashift:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ksll16\\t%0,%1,%2"
)

(define_insn "riscv_kslli16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (ss_ashift:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "kslli16\\t%0,%1,%2";
}
)

(define_insn "riscv_kslra8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSLRA8))]
  "TARGET_XTHEAD_DSP"
  "kslra8\\t%0,%1,%2"
)

(define_insn "riscv_kslra8_u_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSLRA8_U))]
  "TARGET_XTHEAD_DSP"
  "kslra8.u\\t%0,%1,%2"
)

(define_insn "riscv_kslra16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSLRA16))]
  "TARGET_XTHEAD_DSP"
  "kslra16\\t%0,%1,%2"
)

(define_insn "riscv_kslra16_u_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSLRA16_U))]
  "TARGET_XTHEAD_DSP"
  "kslra16.u\\t%0,%1,%2"
)

(define_insn "riscv_kslraw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSLRAW))]
  "TARGET_XTHEAD_DSP"
  "kslraw\\t%0,%1,%2"
)

(define_insn "riscv_kslraw_u_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSLRAW_U))]
  "TARGET_XTHEAD_DSP"
  "kslraw.u\\t%0,%1,%2"
)

(define_insn "riscv_ksub8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
    (ss_minus:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")
	    (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ksub8\\t%0,%1,%2"
)

(define_insn "riscv_ksub16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
    (ss_minus:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")
	    (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ksub16\\t%0,%1,%2"
)

(define_insn "riscv_ksub64"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (ss_minus:DI (match_operand:DI 1 "register_operand" "r")
	    (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "ksub64\\t%0,%1,%2"
)

(define_insn "*ssneg<mode>"
  [(set (match_operand:VQIMOD 0                "register_operand" "=r")
	(ss_neg:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ksub8\t%0,zero,%1"
)

(define_insn "*ssneg<mode>"
  [(set (match_operand:VHIMOD 0                "register_operand" "=r")
	(ss_neg:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ksub16\t%0,zero,%1"
)

(define_insn "*ssnegdi2"
  [(set (match_operand:DI 0            "register_operand" "=r")
	(ss_neg:DI (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "ksub64\t%0,zero,%1"
)

(define_insn "riscv_ksubh_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSUBH))]
  "TARGET_XTHEAD_DSP"
  "ksubh\\t%0,%1,%2"
)

(define_insn "riscv_ksubw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_KSUBW))]
  "TARGET_XTHEAD_DSP"
  "ksubw\\t%0,%1,%2"
)

(define_insn "riscv_maddr32"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(plus:SI (mult:SI (match_operand:SI 2 "register_operand" "r")
			  (match_operand:SI 3 "register_operand" "r"))
		 (match_operand:SI 1 "register_operand" "0")))]
  "TARGET_XTHEAD_DSP"
  "maddr32\\t%0,%2,%3"
)

(define_insn "riscv_maddr32_di"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (plus:SI (mult:SI (match_operand:SI 2 "register_operand" "r")
					  (match_operand:SI 3 "register_operand" "r"))
				 (match_operand:SI 1 "register_operand" "0"))))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "maddr32\\t%0,%2,%3"
)

(define_insn "riscv_msubr32"
  [(set (match_operand:SI 0 "register_operand" "=r")
	(minus:SI (match_operand:SI 1 "register_operand" "0")
		  (mult:SI (match_operand:SI 2 "register_operand" "r")
			   (match_operand:SI 3 "register_operand" "r"))))]
  "TARGET_XTHEAD_DSP"
  "msubr32\\t%0,%2,%3"
)

(define_insn "riscv_msubr32_di"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(sign_extend:DI (minus:SI (match_operand:SI 1 "register_operand" "0")
				  (mult:SI (match_operand:SI 2 "register_operand" "r")
					   (match_operand:SI 3 "register_operand" "r")))))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "msubr32\\t%0,%2,%3"
)

(define_insn "riscv_maxw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(smax:GPR (match_operand:SI 1 "register_operand" "r")
		  (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "maxw\\t%0,%1,%2"
)

(define_insn "riscv_minw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(smin:GPR (match_operand:SI 1 "register_operand" "r")
		  (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "minw\\t%0,%1,%2"
)

(define_insn "riscv_mulr64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(mult:DI (zero_extend:DI (match_operand:SI 1 "register_operand" "r"))
		 (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_XTHEAD_DSP"
  "mulr64\\t%0,%1,%2"
)

(define_insn "riscv_mulsr64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(mult:DI (sign_extend:DI (match_operand:SI 1 "register_operand" "r"))
		 (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))))]
  "TARGET_XTHEAD_DSP"
  "mulsr64\\t%0,%1,%2"
)

(define_insn "riscv_pbsad_<mode>"
  [(set (match_operand:<vqsdmod_attr> 0 "register_operand" "=r")
	(unspec:<vqsdmod_attr>
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:VQIMOD 2 "register_operand" "r")]
	   UNSPEC_PBSAD))]
  "TARGET_XTHEAD_DSP"
  "pbsad\\t%0,%1,%2"
)

(define_insn "riscv_pbsada_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
	(unspec:X
	  [(match_operand:X 1 "register_operand" "0")
	   (match_operand:<sd2vqmod_attr> 2 "register_operand" "r")
	   (match_operand:<sd2vqmod_attr> 3 "register_operand" "r")]
	   UNSPEC_PBSADA))]
  "TARGET_XTHEAD_DSP"
  "pbsada\\t%0,%2,%3"
)

(define_insn "riscv_radd64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ashiftrt:DI
	    (plus:DI (match_operand:DI 1 "register_operand" "r")
		     (match_operand:DI 2 "register_operand" "r"))
	    (const_int 1)))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "radd64\\t%0,%1,%2"
)

(define_insn "riscv_raddw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_RADDW))]
  "TARGET_XTHEAD_DSP"
  "raddw\\t%0,%1,%2"
)

(define_insn "riscv_rsub64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(ashiftrt:DI
	    (minus:DI (match_operand:DI 1 "register_operand" "r")
		      (match_operand:DI 2 "register_operand" "r"))
	    (const_int 1)))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "rsub64\\t%0,%1,%2"
)

(define_insn "riscv_rsubw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(ashiftrt:GPR
	    (minus:GPR (match_operand:SI 1 "register_operand" "r")
		       (match_operand:SI 2 "register_operand" "r"))
	    (const_int 1)))]
  "TARGET_XTHEAD_DSP"
  "rsubw\\t%0,%1,%2"
)

(define_insn "riscv_sclip8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	   UNSPEC_SCLIP8))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "sclip8\\t%0,%1,%2";
}
)

(define_insn "riscv_sclip16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	   UNSPEC_SCLIP16))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "sclip16\\t%0,%1,%2";
}
)

(define_insn "riscv_sclip32_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	   UNSPEC_SCLIP32))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "sclip32\\t%0,%1,%2";
}
)

(define_int_attr cmple8_int_str
  [(UNSPEC_SCMPLE8 "scmple8")
   (UNSPEC_UCMPLE8 "ucmple8")])

(define_int_attr cmple8_int_insn
  [(UNSPEC_SCMPLE8 "scmple8")
   (UNSPEC_UCMPLE8 "ucmple8")])

(define_int_iterator UNSPEC_CMPLE8 [
   UNSPEC_SCMPLE8
   UNSPEC_UCMPLE8])


(define_insn "riscv_<cmple8_int_str>_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:VQIMOD 2 "register_operand" "r")]
	   UNSPEC_CMPLE8))]
  "TARGET_XTHEAD_DSP"
  "<cmple8_int_insn>\\t%0,%1,%2"
)

(define_int_attr cmple16_int_str
  [(UNSPEC_SCMPLE16 "scmple16")
   (UNSPEC_UCMPLE16 "ucmple16")])

(define_int_attr cmple16_int_insn
  [(UNSPEC_SCMPLE16 "scmple16")
   (UNSPEC_UCMPLE16 "ucmple16")])

(define_int_iterator UNSPEC_CMPLE16 [
   UNSPEC_SCMPLE16
   UNSPEC_UCMPLE16])

(define_insn "riscv_<cmple16_int_str>_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_CMPLE16))]
  "TARGET_XTHEAD_DSP"
  "<cmple16_int_insn>\\t%0,%1,%2"
)

(define_int_attr cmplt8_int_str
  [(UNSPEC_SCMPLT8 "scmplt8")
   (UNSPEC_UCMPLT8 "ucmplt8")])

(define_int_attr cmplt8_int_insn
  [(UNSPEC_SCMPLT8 "scmplt8")
   (UNSPEC_UCMPLT8 "ucmplt8")])

(define_int_iterator UNSPEC_CMPLT8 [
   UNSPEC_SCMPLT8
   UNSPEC_UCMPLT8])

(define_insn "riscv_<cmplt8_int_str>_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:VQIMOD 2 "register_operand" "r")]
	   UNSPEC_CMPLT8))]
  "TARGET_XTHEAD_DSP"
  "<cmplt8_int_insn>\\t%0,%1,%2"
)

(define_int_attr cmplt16_int_str
  [(UNSPEC_SCMPLT16 "scmplt16")
   (UNSPEC_UCMPLT16 "ucmplt16")])

(define_int_attr cmplt16_int_insn
  [(UNSPEC_SCMPLT16 "scmplt16")
   (UNSPEC_UCMPLT16 "ucmplt16")])

(define_int_iterator UNSPEC_CMPLT16 [
   UNSPEC_SCMPLT16
   UNSPEC_UCMPLT16])

(define_insn "riscv_<cmplt16_int_str>_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_CMPLT16))]
  "TARGET_XTHEAD_DSP"
  "<cmplt16_int_insn>\\t%0,%1,%2"
)

(define_insn "riscv_sll8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ashift:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sll8\\t%0,%1,%2"
)

(define_insn "riscv_slli8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ashift:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "slli8\\t%0,%1,%2";
}
)

(define_insn "riscv_sll16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (ashift:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sll16\\t%0,%1,%2"
)

(define_insn "riscv_slli16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (ashift:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "slli16\\t%0,%1,%2";
}
)

(define_insn "riscv_smal_<mode>"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI
	  [(match_operand:DI 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_SMAL))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "smal\\t%0,%1,%2"
)

(define_insn "riscv_smaqa_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vsvqmod_attr> 2 "register_operand" "r")
	   (match_operand:<vsvqmod_attr> 3 "register_operand" "r")]
	   UNSPEC_SMAQA))]
  "TARGET_XTHEAD_DSP"
  "smaqa\\t%0,%2,%3"
)

(define_insn "riscv_smaqa_su_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vsvqmod_attr> 2 "register_operand" "r")
	   (match_operand:<vsvqmod_attr> 3 "register_operand" "r")]
	   UNSPEC_SMAQA_SU))]
  "TARGET_XTHEAD_DSP"
  "smaqa.su\\t%0,%2,%3"
)

(define_int_attr sm16_str
  [(UNSPEC_SMBB16 "smbb16")
   (UNSPEC_SMBT16 "smbt16")
   (UNSPEC_SMTT16 "smtt16")
   (UNSPEC_SMDS "smds")
   (UNSPEC_SMDRS "smdrs")
   (UNSPEC_SMXDS "smxds")])

(define_int_attr sm16_insn
  [(UNSPEC_SMBB16 "smbb16")
   (UNSPEC_SMBT16 "smbt16")
   (UNSPEC_SMTT16 "smtt16")
   (UNSPEC_SMDS "smds")
   (UNSPEC_SMDRS "smdrs")
   (UNSPEC_SMXDS "smxds")])

(define_int_iterator UNSPEC_SM16 [
   UNSPEC_SMBB16
   UNSPEC_SMBT16
   UNSPEC_SMTT16
   UNSPEC_SMDS
   UNSPEC_SMDRS
   UNSPEC_SMXDS])

(define_insn "riscv_<sm16_str>_<mode>"
  [(set (match_operand:<vssmod_attr> 0 "register_operand" "=r")
	(unspec:<vssmod_attr>
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:VHIMOD 2 "register_operand" "r")]
	   UNSPEC_SM16))]
  "TARGET_XTHEAD_DSP"
  "<sm16_insn>\\t%0,%1,%2"
)

(define_code_iterator minmax [smin smax umin umax])
(define_code_attr minmax8_code [(smin "smin8") (smax "smax8") (umin "umin8") (umax "umax8")])
(define_code_attr minmax8_insn [(smin "smin8") (smax "smax8") (umin "umin8") (umax "umax8")])

(define_insn "riscv_<minmax8_code>_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(minmax:VQIMOD
	    (match_operand:VQIMOD 1 "register_operand" "r")
	    (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "<minmax8_insn>\\t%0,%1,%2"
)

(define_code_attr minmax16_code [(smin "smin16") (smax "smax16") (umin "umin16") (umax "umax16")])
(define_code_attr minmax16_insn [(smin "smin16") (smax "smax16") (umin "umin16") (umax "umax16")])

(define_insn "riscv_<minmax16_code>_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(minmax:VHIMOD
	    (match_operand:VHIMOD 1 "register_operand" "r")
	    (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "<minmax16_insn>\\t%0,%1,%2"
)

(define_int_attr xmmul_str
  [(UNSPEC_SMMUL "smmul")
   (UNSPEC_SMMUL_U "smmul_u")
   (UNSPEC_KWMMUL "kwmmul")
   (UNSPEC_KWMMUL_U "kwmmul_u")])

(define_int_attr xmmul_insn
  [(UNSPEC_SMMUL "smmul")
   (UNSPEC_SMMUL_U "smmul.u")
   (UNSPEC_KWMMUL "kwmmul")
   (UNSPEC_KWMMUL_U "kwmmul.u")])

(define_int_iterator UNSPEC_XMMUL [
   UNSPEC_SMMUL
   UNSPEC_SMMUL_U
   UNSPEC_KWMMUL
   UNSPEC_KWMMUL_U])

(define_insn "riscv_<xmmul_str>_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "r")
	   (match_operand:VSIMOD 2 "register_operand" "r")]
	   UNSPEC_XMMUL))]
  "TARGET_XTHEAD_DSP"
  "<xmmul_insn>\\t%0,%1,%2"
)

(define_int_attr xmmw_str
  [(UNSPEC_KMMWB2 "kmmwb2")
   (UNSPEC_KMMWB2_U "kmmwb2_u")
   (UNSPEC_KMMWT2 "kmmwt2")
   (UNSPEC_KMMWT2_U "kmmwt2_u")
   (UNSPEC_SMMWB "smmwb")
   (UNSPEC_SMMWB_U "smmwb_u")
   (UNSPEC_SMMWT "smmwt")
   (UNSPEC_SMMWT_U "smmwt_u")])

(define_int_attr xmmw_insn
  [(UNSPEC_KMMWB2 "kmmwb2")
   (UNSPEC_KMMWB2_U "kmmwb2.u")
   (UNSPEC_KMMWT2 "kmmwt2")
   (UNSPEC_KMMWT2_U "kmmwt2.u")
   (UNSPEC_SMMWB "smmwb")
   (UNSPEC_SMMWB_U "smmwb.u")
   (UNSPEC_SMMWT "smmwt")
   (UNSPEC_SMMWT_U "smmwt.u")])

(define_int_iterator UNSPEC_XMMW [
   UNSPEC_KMMWB2
   UNSPEC_KMMWB2_U
   UNSPEC_KMMWT2
   UNSPEC_KMMWT2_U
   UNSPEC_SMMWB
   UNSPEC_SMMWB_U
   UNSPEC_SMMWT
   UNSPEC_SMMWT_U])

(define_insn "riscv_<xmmw_str>_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vhhmod_attr> 2 "register_operand" "r")]
	   UNSPEC_XMMW))]
  "TARGET_XTHEAD_DSP"
  "<xmmw_insn>\\t%0,%1,%2"
)


(define_int_attr smxl_str
  [(UNSPEC_SMALBB "smalbb")
   (UNSPEC_SMALBT "smalbt")
   (UNSPEC_SMALTT "smaltt")
   (UNSPEC_SMALDA "smalda")
   (UNSPEC_SMALXDA "smalxda")
   (UNSPEC_SMALDS "smalds")
   (UNSPEC_SMALDRS "smaldrs")
   (UNSPEC_SMALXDS "smalxds")
   (UNSPEC_SMSLDA "smslda")
   (UNSPEC_SMSLXDA "smslxda")])

(define_int_attr smxl_insn
  [(UNSPEC_SMALBB "smalbb")
   (UNSPEC_SMALBT "smalbt")
   (UNSPEC_SMALTT "smaltt")
   (UNSPEC_SMALDA "smalda")
   (UNSPEC_SMALXDA "smalxda")
   (UNSPEC_SMALDS "smalds")
   (UNSPEC_SMALDRS "smaldrs")
   (UNSPEC_SMALXDS "smalxds")
   (UNSPEC_SMSLDA "smslda")
   (UNSPEC_SMSLXDA "smslxda")])

(define_int_iterator UNSPEC_SMXL [
   UNSPEC_SMALBB
   UNSPEC_SMALBT
   UNSPEC_SMALTT
   UNSPEC_SMALDA
   UNSPEC_SMALXDA
   UNSPEC_SMALDS
   UNSPEC_SMALDRS
   UNSPEC_SMALXDS
   UNSPEC_SMSLDA
   UNSPEC_SMSLXDA])

(define_insn "riscv_<smxl_str>_<mode>"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI
	  [(match_operand:DI 1 "register_operand" "0")
	   (match_operand:VHIMOD 2 "register_operand" "r")
	   (match_operand:VHIMOD 3 "register_operand" "r")]
	   UNSPEC_SMXL))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "<smxl_insn>\\t%0,%2,%3"
)

(define_insn "riscv_smar64_si"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI
	  (mult:DI
	    (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))
	    (sign_extend:DI (match_operand:SI 3 "register_operand" "r")))
	  (match_operand:DI 1 "register_operand" "0")))]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  "smar64\\t%0,%2,%3"
)

(define_insn "riscv_smar64_v2si"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (unspec:DI
      [(match_operand:DI 1 "register_operand" "0")
       (match_operand:V2SI 2 "register_operand" "r")
       (match_operand:V2SI 3 "register_operand" "r")]
       UNSPEC_SMAR64))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "smar64\\t%0,%2,%3"
)

(define_insn "riscv_smsr64_si"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(minus:DI (match_operand:DI 1 "register_operand" "0")
	  (mult:DI
	    (sign_extend:DI (match_operand:SI 2 "register_operand" "r"))
	    (sign_extend:DI (match_operand:SI 3 "register_operand" "r")))))]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  "smsr64\\t%0,%2,%3"
)

(define_insn "riscv_smsr64_v2si"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (unspec:DI
      [(match_operand:DI 1 "register_operand" "0")
       (match_operand:V2SI 2 "register_operand" "r")
       (match_operand:V2SI 3 "register_operand" "r")]
       UNSPEC_SMSR64))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "smsr64\\t%0,%2,%3"
)

(define_insn "riscv_umar64_si"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(plus:DI
	  (mult:DI
	    (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))
	    (zero_extend:DI (match_operand:SI 3 "register_operand" "r")))
	  (match_operand:DI 1 "register_operand" "0")))]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  "umar64\\t%0,%2,%3"
)

(define_insn "riscv_umar64_v2si"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (unspec:DI
      [(match_operand:DI 1 "register_operand" "0")
       (match_operand:V2SI 2 "register_operand" "r")
       (match_operand:V2SI 3 "register_operand" "r")]
       UNSPEC_UMAR64))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "umar64\\t%0,%2,%3"
)

(define_insn "riscv_umsr64_si"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(minus:DI (match_operand:DI 1 "register_operand" "0")
	  (mult:DI
	    (zero_extend:DI (match_operand:SI 2 "register_operand" "r"))
	    (zero_extend:DI (match_operand:SI 3 "register_operand" "r")))))]
  "TARGET_XTHEAD_ZPSFOPERAND && !TARGET_64BIT"
  "umsr64\\t%0,%2,%3"
)

(define_insn "riscv_umsr64_v2si"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (unspec:DI
      [(match_operand:DI 1 "register_operand" "0")
       (match_operand:V2SI 2 "register_operand" "r")
       (match_operand:V2SI 3 "register_operand" "r")]
       UNSPEC_UMSR64))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "umsr64\\t%0,%2,%3"
)

(define_insn "riscv_smul8"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
	(mult:V4HI
	   (sign_extend:V4HI (match_operand:V4QI 1 "register_operand" "r"))
	   (sign_extend:V4HI (match_operand:V4QI 2 "register_operand" "r"))))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "smul8\\t%0,%1,%2"
)

(define_insn "riscv_smulx8"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
	(unspec:V4HI
	  [(match_operand:V4QI 1 "register_operand" "r")
	   (match_operand:V4QI 2 "register_operand" "r")]
	   UNSPEC_SMULX8))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "smulx8\\t%0,%1,%2"
)

(define_insn "riscv_smul16"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(mult:V2SI
	   (sign_extend:V2SI (match_operand:V2HI 1 "register_operand" "r"))
	   (sign_extend:V2SI (match_operand:V2HI 2 "register_operand" "r"))))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "smul16\\t%0,%1,%2"
)

(define_insn "riscv_smulx16"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(unspec:V2SI
	  [(match_operand:V2HI 1 "register_operand" "r")
	   (match_operand:V2HI 2 "register_operand" "r")]
	   UNSPEC_SMULX16))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "smulx16\\t%0,%1,%2"
)

(define_insn "riscv_sra_u_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
	[(match_operand:GPR 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")]
	UNSPEC_SRA_U))]
  "TARGET_XTHEAD_DSP"
  "sra.u\\t%0,%1,%2"
)

(define_insn "riscv_srai_u_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
     (unspec:GPR
	[(match_operand:GPR 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")]
	UNSPEC_SRA_U))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & (BITS_PER_WORD - 1));
  return "srai.u\\t%0,%1,%2";
}
)

(define_insn "riscv_sra8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ashiftrt:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sra8\\t%0,%1,%2"
)

(define_insn "riscv_sra8_u_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
	[(match_operand:VQIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "register_operand" "r")]
	 UNSPEC_SRA8_U))]
  "TARGET_XTHEAD_DSP"
  "sra8.u\\t%0,%1,%2"
)

(define_insn "riscv_srai8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (ashiftrt:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "srai8\\t%0,%1,%2";
}
)

(define_insn "riscv_srai8_u_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
	[(match_operand:VQIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "immediate_operand" "i")]
	 UNSPEC_SRA8_U))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "srai8.u\\t%0,%1,%2";
}
)

(define_insn "riscv_sra16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (ashiftrt:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sra16\\t%0,%1,%2"
)

(define_insn "riscv_sra16_u_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
	[(match_operand:VHIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "register_operand" "r")]
	 UNSPEC_SRA16_U))]
  "TARGET_XTHEAD_DSP"
  "sra16.u\\t%0,%1,%2"
)

(define_insn "riscv_srai16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (ashiftrt:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "srai16\\t%0,%1,%2";
}
)

(define_insn "riscv_srai16_u_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
	[(match_operand:VHIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "immediate_operand" "i")]
	 UNSPEC_SRA16_U))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "srai16.u\\t%0,%1,%2";
}
)

(define_insn "riscv_srl8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (lshiftrt:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "srl8\\t%0,%1,%2"
)

(define_insn "riscv_srl8_u_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
	[(match_operand:VQIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "register_operand" "r")]
	 UNSPEC_SRL8_U))]
  "TARGET_XTHEAD_DSP"
  "srl8.u\\t%0,%1,%2"
)

(define_insn "riscv_srli8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (lshiftrt:VQIMOD
	(match_operand:VQIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "srli8\\t%0,%1,%2";
}
)

(define_insn "riscv_srli8_u_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
	[(match_operand:VQIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "immediate_operand" "i")]
	 UNSPEC_SRL8_U))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "srli8.u\\t%0,%1,%2";
}
)

(define_insn "riscv_srl16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (lshiftrt:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "srl16\\t%0,%1,%2"
)

(define_insn "riscv_srl16_u_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
	[(match_operand:VHIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "register_operand" "r")]
	 UNSPEC_SRL16_U))]
  "TARGET_XTHEAD_DSP"
  "srl16.u\\t%0,%1,%2"
)

(define_insn "riscv_srli16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (lshiftrt:VHIMOD
	(match_operand:VHIMOD 1 "register_operand" "r")
	(match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "srli16\\t%0,%1,%2";
}
)

(define_insn "riscv_srli16_u_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
	[(match_operand:VHIMOD 1 "register_operand" "r")
	 (match_operand:SI 2 "immediate_operand" "i")]
	 UNSPEC_SRL16_U))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "srli16.u\\t%0,%1,%2";
}
)

(define_int_attr unpkd_int_str
  [(UNSPEC_SUNPKD810 "sunpkd810")
   (UNSPEC_SUNPKD820 "sunpkd820")
   (UNSPEC_SUNPKD830 "sunpkd830")
   (UNSPEC_SUNPKD831 "sunpkd831")
   (UNSPEC_SUNPKD832 "sunpkd832")
   (UNSPEC_ZUNPKD810 "zunpkd810")
   (UNSPEC_ZUNPKD820 "zunpkd820")
   (UNSPEC_ZUNPKD830 "zunpkd830")
   (UNSPEC_ZUNPKD831 "zunpkd831")
   (UNSPEC_ZUNPKD832 "zunpkd832")])

(define_int_attr unpkd_int_insn
  [(UNSPEC_SUNPKD810 "sunpkd810")
   (UNSPEC_SUNPKD820 "sunpkd820")
   (UNSPEC_SUNPKD830 "sunpkd830")
   (UNSPEC_SUNPKD831 "sunpkd831")
   (UNSPEC_SUNPKD832 "sunpkd832")
   (UNSPEC_ZUNPKD810 "zunpkd810")
   (UNSPEC_ZUNPKD820 "zunpkd820")
   (UNSPEC_ZUNPKD830 "zunpkd830")
   (UNSPEC_ZUNPKD831 "zunpkd831")
   (UNSPEC_ZUNPKD832 "zunpkd832")])

(define_int_iterator UNSPEC_UNPKD [
   UNSPEC_SUNPKD810
   UNSPEC_SUNPKD820
   UNSPEC_SUNPKD830
   UNSPEC_SUNPKD831
   UNSPEC_SUNPKD832
   UNSPEC_ZUNPKD810
   UNSPEC_ZUNPKD820
   UNSPEC_ZUNPKD830
   UNSPEC_ZUNPKD831
   UNSPEC_ZUNPKD832])

(define_insn "riscv_<unpkd_int_str>_<mode>"
  [(set (match_operand:<vqvhmod_attr> 0 "register_operand" "=r")
     (unspec:<vqvhmod_attr>
      [(match_operand:VQIMOD 1 "register_operand" "r")]
       UNSPEC_UNPKD))]
  "TARGET_XTHEAD_DSP"
  "<unpkd_int_insn>\\t%0,%1"
)

(define_insn "riscv_swap8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
     (unspec:VQIMOD
      [(match_operand:VQIMOD 1 "register_operand" "r")]
       UNSPEC_SWAP8))]
  "TARGET_XTHEAD_DSP"
  "swap8\\t%0,%1"
)

(define_insn "riscv_swap16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
     (unspec:VHIMOD
      [(match_operand:VHIMOD 1 "register_operand" "r")]
       UNSPEC_SWAP16))]
  "TARGET_XTHEAD_DSP"
  "swap16\\t%0,%1"
)

(define_insn "riscv_uclip8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
	(unspec:VQIMOD
	  [(match_operand:VQIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	   UNSPEC_UCLIP8))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x7);
  return "uclip8\\t%0,%1,%2";
}
)

(define_insn "riscv_uclip16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
	(unspec:VHIMOD
	  [(match_operand:VHIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	   UNSPEC_UCLIP16))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0xf);
  return "uclip16\\t%0,%1,%2";
}
)

(define_insn "riscv_uclip32_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	   UNSPEC_UCLIP32))]
  "TARGET_XTHEAD_DSP"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "uclip32\\t%0,%1,%2";
}
)

(define_insn "riscv_sub8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
    (minus:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")
		  (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sub8\\t%0,%1,%2"
)


(define_insn "riscv_sub16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
    (minus:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")
		  (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sub16\\t%0,%1,%2"
)

(define_insn "riscv_sub64"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (minus:DI (match_operand:DI 1 "register_operand" "r")
	      (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "sub64\\t%0,%1,%2"
)

(define_insn "*neg<mode>"
  [(set (match_operand:VQIMOD 0             "register_operand" "=r")
	(neg:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sub8\t%0,zero,%1"
)

(define_insn "*neg<mode>"
  [(set (match_operand:VHIMOD 0             "register_operand" "=r")
	(neg:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "sub16\t%0,zero,%1"
)

(define_insn "riscv_ukadd8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
    (us_plus:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")
		    (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ukadd8\\t%0,%1,%2"
)

(define_insn "riscv_ukadd16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
    (us_plus:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")
		    (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "ukadd16\\t%0,%1,%2"
)

(define_insn "riscv_ukadd64"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (us_plus:DI (match_operand:DI 1 "register_operand" "r")
		(match_operand:DI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "ukadd64\\t%0,%1,%2"
)

(define_insn "riscv_ukaddh_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_UKADDH))]
  "TARGET_XTHEAD_DSP"
  "ukaddh\\t%0,%1,%2"
)

(define_insn "riscv_ukaddw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_UKADDW))]
  "TARGET_XTHEAD_DSP"
  "ukaddw\\t%0,%1,%2"
)

(define_insn "riscv_ukmar64_<mode>"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI
	  [(match_operand:DI 1 "register_operand" "0")
	   (match_operand:VSIMOD 2 "register_operand" "r")
	   (match_operand:VSIMOD 3 "register_operand" "r")]
	   UNSPEC_UKMAR64))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "ukmar64\\t%0,%2,%3"
)

(define_insn "riscv_ukmsr64_<mode>"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (unspec:DI
      [(match_operand:DI 1 "register_operand" "0")
       (match_operand:VSIMOD 2 "register_operand" "r")
       (match_operand:VSIMOD 3 "register_operand" "r")]
       UNSPEC_UKMSR64))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "ukmsr64\\t%0,%2,%3"
)

(define_insn "riscv_uksub8_<mode>"
  [(set (match_operand:VQIMOD 0 "register_operand" "=r")
    (us_minus:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")
		     (match_operand:VQIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "uksub8\\t%0,%1,%2"
)

(define_insn "riscv_uksub16_<mode>"
  [(set (match_operand:VHIMOD 0 "register_operand" "=r")
    (us_minus:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")
		     (match_operand:VHIMOD 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "uksub16\\t%0,%1,%2"
)

(define_insn "riscv_uksub64"
  [(set (match_operand:DI 0 "register_operand" "=r")
    (us_minus:DI (match_operand:DI 1 "register_operand" "r")
		 (match_operand:DI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "uksub64\\t%0,%1,%2"
)

(define_insn "*usneg<mode>"
  [(set (match_operand:VQIMOD 0                "register_operand" "=r")
	(us_neg:VQIMOD (match_operand:VQIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "uksub8\t%0,zero,%1"
)

(define_insn "*usneg<mode>"
  [(set (match_operand:VHIMOD 0                "register_operand" "=r")
	(us_neg:VHIMOD (match_operand:VHIMOD 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP"
  "uksub16\t%0,zero,%1"
)

(define_insn "*usnegdi2"
  [(set (match_operand:DI 0            "register_operand" "=r")
	(us_neg:DI (match_operand:DI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "uksub64\t%0,zero,%1"
)

(define_insn "riscv_uksubh_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_UKSUBH))]
  "TARGET_XTHEAD_DSP"
  "uksubh\\t%0,%1,%2"
)

(define_insn "riscv_uksubw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_UKSUBW))]
  "TARGET_XTHEAD_DSP"
  "uksubw\\t%0,%1,%2"
)

(define_insn "riscv_umaqa_<mode>"
  [(set (match_operand:VSIMOD 0 "register_operand" "=r")
	(unspec:VSIMOD
	  [(match_operand:VSIMOD 1 "register_operand" "0")
	   (match_operand:<vsvqmod_attr> 2 "register_operand" "r")
	   (match_operand:<vsvqmod_attr> 3 "register_operand" "r")]
	   UNSPEC_UMAQA))]
  "TARGET_XTHEAD_DSP"
  "umaqa\\t%0,%2,%3"
)

(define_insn "riscv_umul8"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
	(mult:V4HI
	   (zero_extend:V4HI (match_operand:V4QI 1 "register_operand" "r"))
	   (zero_extend:V4HI (match_operand:V4QI 2 "register_operand" "r"))))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "umul8\\t%0,%1,%2"
)

(define_insn "riscv_umulx8"
  [(set (match_operand:V4HI 0 "register_operand" "=r")
	(unspec:V4HI
	  [(match_operand:V4QI 1 "register_operand" "r")
	   (match_operand:V4QI 2 "register_operand" "r")]
	   UNSPEC_UMULX8))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "umulx8\\t%0,%1,%2"
)

(define_insn "riscv_umul16"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(mult:V2SI
	   (zero_extend:V2SI (match_operand:V2HI 1 "register_operand" "r"))
	   (zero_extend:V2SI (match_operand:V2HI 2 "register_operand" "r"))))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "umul16\\t%0,%1,%2"
)

(define_insn "riscv_umulx16"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(unspec:V2SI
	  [(match_operand:V2HI 1 "register_operand" "r")
	   (match_operand:V2HI 2 "register_operand" "r")]
	   UNSPEC_UMULX16))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "umulx16\\t%0,%1,%2"
)

(define_insn "riscv_uradd64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(lshiftrt:DI
	    (plus:DI (match_operand:DI 1 "register_operand" "r")
		     (match_operand:DI 2 "register_operand" "r"))
	    (const_int 1)))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "uradd64\\t%0,%1,%2"
)

(define_insn "riscv_uraddw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_URADDW))]
  "TARGET_XTHEAD_DSP"
  "uraddw\\t%0,%1,%2"
)

(define_insn "riscv_ursub64"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI
	  [(match_operand:DI 1 "register_operand" "r")
	   (match_operand:DI 2 "register_operand" "r")]
	   UNSPEC_URSUB64))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "ursub64\\t%0,%1,%2"
)

(define_insn "riscv_ursubw_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:SI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	   UNSPEC_URSUBW))]
  "TARGET_XTHEAD_DSP"
  "ursubw\\t%0,%1,%2"
)

(define_insn "riscv_wext_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:DI 1 "register_operand" "r")
	   (match_operand:SI 2 "register_operand" "r")]
	UNSPEC_WEXT))]
  "TARGET_XTHEAD_ZPSFOPERAND"
  "wext\\t%0,%1,%2"
)

(define_insn "riscv_wexti_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec:GPR
	  [(match_operand:DI 1 "register_operand" "r")
	   (match_operand:SI 2 "immediate_operand" "i")]
	UNSPEC_WEXT))]
  "TARGET_XTHEAD_ZPSFOPERAND"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "wexti\\t%0,%1,%2";
}
)

(define_insn "riscv_rdov_<mode>"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(unspec_volatile:GPR [(const_int 0)] UNSPECV_RDOV))]
  "TARGET_XTHEAD_DSP || TARGET_XTHEAD_ZPSFOPERAND"
  "rdov\\t%0"
)

(define_insn "riscv_clrov"
  [(unspec_volatile [(const_int 0)] UNSPECV_CLROV)]
  "TARGET_XTHEAD_DSP || TARGET_XTHEAD_ZPSFOPERAND"
  "clrov"
)


;;==================================================== RV64 only ====================================================

(define_insn "riscv_add32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (plus:V2SI (match_operand:V2SI 1 "register_operand" "r")
	       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "add32\\t%0,%1,%2"
)

(define_insn "riscv_sub32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (minus:V2SI (match_operand:V2SI 1 "register_operand" "r")
		(match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "sub32\\t%0,%1,%2"
)

(define_insn "*negv2si3"
  [(set (match_operand:V2SI 0           "register_operand" "=r")
	(neg:V2SI (match_operand:V2SI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "sub32\t%0,zero,%1"
)

(define_insn "riscv_kadd32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (ss_plus:V2SI (match_operand:V2SI 1 "register_operand" "r")
		  (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "kadd32\\t%0,%1,%2"
)

(define_int_attr rv64_simd32_int_str
  [(UNSPEC_CRAS32 "cras32")
   (UNSPEC_CRSA32 "crsa32")
   (UNSPEC_KCRAS32 "kcras32")
   (UNSPEC_KCRSA32 "kcrsa32")
   (UNSPEC_UKCRAS32 "ukcras32")
   (UNSPEC_UKCRSA32 "ukcrsa32")
   (UNSPEC_UKSTAS32 "ukstas32")
   (UNSPEC_UKSTSA32 "ukstsa32")
   (UNSPEC_URADD32 "uradd32")
   (UNSPEC_URCRAS32 "urcras32")
   (UNSPEC_URCRSA32 "urcrsa32")
   (UNSPEC_URSTAS32 "urstas32")
   (UNSPEC_URSTSA32 "urstsa32")
   (UNSPEC_URSUB32 "ursub32")
   (UNSPEC_KSTAS32 "kstas32")
   (UNSPEC_KSTSA32 "kstsa32")
   (UNSPEC_RADD32 "radd32")
   (UNSPEC_RCRAS32 "rcras32")
   (UNSPEC_RCRSA32 "rcrsa32")
   (UNSPEC_RSTAS32 "rstas32")
   (UNSPEC_RSTSA32 "rstsa32")
   (UNSPEC_RSUB32 "rsub32")
   (UNSPEC_STAS32 "stas32")
   (UNSPEC_STSA32 "stsa32")
   (UNSPEC_PKBB32 "pkbb32")
   (UNSPEC_PKBT32 "pkbt32")
   (UNSPEC_PKTB32 "pktb32")
   (UNSPEC_PKTT32 "pktt32")])

(define_int_attr rv64_simd32_int_insn
  [(UNSPEC_CRAS32 "cras32")
   (UNSPEC_CRSA32 "crsa32")
   (UNSPEC_KCRAS32 "kcras32")
   (UNSPEC_KCRSA32 "kcrsa32")
   (UNSPEC_UKCRAS32 "ukcras32")
   (UNSPEC_UKCRSA32 "ukcrsa32")
   (UNSPEC_UKSTAS32 "ukstas32")
   (UNSPEC_UKSTSA32 "ukstsa32")
   (UNSPEC_URADD32 "uradd32")
   (UNSPEC_URCRAS32 "urcras32")
   (UNSPEC_URCRSA32 "urcrsa32")
   (UNSPEC_URSTAS32 "urstas32")
   (UNSPEC_URSTSA32 "urstsa32")
   (UNSPEC_URSUB32 "ursub32")
   (UNSPEC_KSTAS32 "kstas32")
   (UNSPEC_KSTSA32 "kstsa32")
   (UNSPEC_RADD32 "radd32")
   (UNSPEC_RCRAS32 "rcras32")
   (UNSPEC_RCRSA32 "rcrsa32")
   (UNSPEC_RSTAS32 "rstas32")
   (UNSPEC_RSTSA32 "rstsa32")
   (UNSPEC_RSUB32 "rsub32")
   (UNSPEC_STAS32 "stas32")
   (UNSPEC_STSA32 "stsa32")
   (UNSPEC_PKBB32 "pkbb32")
   (UNSPEC_PKBT32 "pkbt32")
   (UNSPEC_PKTB32 "pktb32")
   (UNSPEC_PKTT32 "pktt32")])

(define_int_iterator UNSPEC_RV64_SIMD32 [
   UNSPEC_CRAS32
   UNSPEC_CRSA32
   UNSPEC_KCRAS32
   UNSPEC_KCRSA32
   UNSPEC_UKCRAS32
   UNSPEC_UKCRSA32
   UNSPEC_UKSTAS32
   UNSPEC_UKSTSA32
   UNSPEC_URADD32
   UNSPEC_URCRAS32
   UNSPEC_URCRSA32
   UNSPEC_URSTAS32
   UNSPEC_URSTSA32
   UNSPEC_URSUB32
   UNSPEC_KSTAS32
   UNSPEC_KSTSA32
   UNSPEC_RADD32
   UNSPEC_RCRAS32
   UNSPEC_RCRSA32
   UNSPEC_RSTAS32
   UNSPEC_RSTSA32
   UNSPEC_RSUB32
   UNSPEC_STAS32
   UNSPEC_STSA32])

(define_int_iterator UNSPEC_RV64_PACK32 [
   UNSPEC_PKBB32
   UNSPEC_PKBT32
   UNSPEC_PKTB32
   UNSPEC_PKTT32])

(define_insn "riscv_<rv64_simd32_int_str>"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")]
       UNSPEC_RV64_SIMD32))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<rv64_simd32_int_insn>\\t%0,%1,%2"
)

(define_insn "riscv_<rv64_simd32_int_str>"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")]
       UNSPEC_RV64_PACK32))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<rv64_simd32_int_insn>\\t%0,%1,%2"
)

(define_insn "riscv_kabs32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (ss_abs:V2SI
       (match_operand:V2SI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "kabs32\\t%0,%1"
)

(define_int_attr rv64_kdmb_int_str
  [(UNSPEC_KDMBB16 "kdmbb16")
   (UNSPEC_KDMBT16 "kdmbt16")
   (UNSPEC_KDMTT16 "kdmtt16")
   (UNSPEC_KHMBB16 "khmbb16")
   (UNSPEC_KHMBT16 "khmbt16")
   (UNSPEC_KHMTT16 "khmtt16")])

(define_int_attr rv64_kdmb_int_insn
  [(UNSPEC_KDMBB16 "kdmbb16")
   (UNSPEC_KDMBT16 "kdmbt16")
   (UNSPEC_KDMTT16 "kdmtt16")
   (UNSPEC_KHMBB16 "khmbb16")
   (UNSPEC_KHMBT16 "khmbt16")
   (UNSPEC_KHMTT16 "khmtt16")])

(define_int_iterator UNSPEC_RV64_KDMB [
   UNSPEC_KDMBB16
   UNSPEC_KDMBT16
   UNSPEC_KDMTT16
   UNSPEC_KHMBB16
   UNSPEC_KHMBT16
   UNSPEC_KHMTT16])

(define_insn "riscv_<rv64_kdmb_int_str>"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V4HI 1 "register_operand" "r")
       (match_operand:V4HI 2 "register_operand" "r")]
       UNSPEC_RV64_KDMB))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<rv64_kdmb_int_insn>\\t%0,%1,%2"
)

(define_int_attr rv64_kdma_int_str
  [(UNSPEC_KDMABB16 "kdmabb16")
   (UNSPEC_KDMABT16 "kdmabt16")
   (UNSPEC_KDMATT16 "kdmatt16")])

(define_int_attr rv64_kdma_int_insn
  [(UNSPEC_KDMABB16 "kdmabb16")
   (UNSPEC_KDMABT16 "kdmabt16")
   (UNSPEC_KDMATT16 "kdmatt16")])

(define_int_iterator UNSPEC_RV64_KDMA [
   UNSPEC_KDMABB16
   UNSPEC_KDMABT16
   UNSPEC_KDMATT16])

(define_insn "riscv_<rv64_kdma_int_str>"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(unspec:V2SI
	  [(match_operand:V2SI 1 "register_operand" "0")
	   (match_operand:V4HI 2 "register_operand" "r")
	   (match_operand:V4HI 3 "register_operand" "r")]
	   UNSPEC_RV64_KDMA))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<rv64_kdma_int_insn>\\t%0,%2,%3"
)

(define_int_attr rv64_km32_int_str
  [(UNSPEC_KMABB32 "kmabb32")
   (UNSPEC_KMABT32 "kmabt32")
   (UNSPEC_KMATT32 "kmatt32")
   (UNSPEC_KMADA32 "kmada32")
   (UNSPEC_KMAXDA32 "kmaxda32")
   (UNSPEC_KMADS32 "kmads32")
   (UNSPEC_KMADRS32 "kmadrs32")
   (UNSPEC_KMAXDS32 "kmaxds32")
   (UNSPEC_KMSDA32 "kmsda32")
   (UNSPEC_KMSXDA32"kmsxda32")])

(define_int_attr rv64_km32_int_insn
  [(UNSPEC_KMABB32 "kmabb32")
   (UNSPEC_KMABT32 "kmabt32")
   (UNSPEC_KMATT32 "kmatt32")
   (UNSPEC_KMADA32 "kmada32")
   (UNSPEC_KMAXDA32 "kmaxda32")
   (UNSPEC_KMADS32 "kmads32")
   (UNSPEC_KMADRS32 "kmadrs32")
   (UNSPEC_KMAXDS32 "kmaxds32")
   (UNSPEC_KMSDA32 "kmsda32")
   (UNSPEC_KMSXDA32"kmsxda32")])

(define_int_iterator UNSPEC_RV64_KM32 [
   UNSPEC_KMABB32
   UNSPEC_KMABT32
   UNSPEC_KMATT32
   UNSPEC_KMADA32
   UNSPEC_KMAXDA32
   UNSPEC_KMADS32
   UNSPEC_KMADRS32
   UNSPEC_KMAXDS32
   UNSPEC_KMSDA32
   UNSPEC_KMSXDA32])

(define_insn "riscv_<rv64_km32_int_str>"
  [(set (match_operand:DI 0 "register_operand" "=r")
	(unspec:DI
	  [(match_operand:DI 1 "register_operand" "0")
	   (match_operand:V2SI 2 "register_operand" "r")
	   (match_operand:V2SI 3 "register_operand" "r")]
	   UNSPEC_RV64_KM32))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<rv64_km32_int_insn>\\t%0,%2,%3"
)

(define_insn "riscv_ukadd32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (us_plus:V2SI (match_operand:V2SI 1 "register_operand" "r")
		  (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "ukadd32\\t%0,%1,%2"
)

(define_insn "riscv_uksub32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (us_minus:V2SI (match_operand:V2SI 1 "register_operand" "r")
		   (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "uksub32\\t%0,%1,%2"
)

(define_insn "*usnegv2si3"
  [(set (match_operand:V2SI 0              "register_operand" "=r")
	(us_neg:V2SI (match_operand:V2SI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "uksub32\t%0,zero,%1"
)

(define_insn "riscv_umax32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (umax:V2SI (match_operand:V2SI 1 "register_operand" "r")
	       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "umax32\\t%0,%1,%2"
)

(define_insn "riscv_umin32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (umin:V2SI (match_operand:V2SI 1 "register_operand" "r")
	       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "umin32\\t%0,%1,%2"
)

(define_insn "riscv_smax32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (smax:V2SI (match_operand:V2SI 1 "register_operand" "r")
	       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "smax32\\t%0,%1,%2"
)

(define_insn "riscv_smin32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (smin:V2SI (match_operand:V2SI 1 "register_operand" "r")
	       (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "smin32\\t%0,%1,%2"
)

(define_insn "riscv_ksub32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
    (ss_minus:V2SI (match_operand:V2SI 1 "register_operand" "r")
		   (match_operand:V2SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "ksub32\\t%0,%1,%2"
)

(define_insn "*ssnegv2si3"
  [(set (match_operand:V2SI 0              "register_operand" "=r")
	(ss_neg:V2SI (match_operand:V2SI 1 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "ksub32\t%0,zero,%1"
)

(define_int_attr rv64_sm32_int_str
  [(UNSPEC_KMDA32 "kmda32")
   (UNSPEC_KMXDA32 "kmxda32")
   (UNSPEC_SMBB32 "smbb32")
   (UNSPEC_SMBT32 "smbt32")
   (UNSPEC_SMTT32 "smtt32")
   (UNSPEC_SMDS32 "smds32")
   (UNSPEC_SMDRS32 "smdrs32")
   (UNSPEC_SMXDS32 "smxds32")])

(define_int_attr rv64_sm32_int_insn
  [(UNSPEC_KMDA32 "kmda32")
   (UNSPEC_KMXDA32 "kmxda32")
   (UNSPEC_SMBB32 "smbb32")
   (UNSPEC_SMBT32 "smbt32")
   (UNSPEC_SMTT32 "smtt32")
   (UNSPEC_SMDS32 "smds32")
   (UNSPEC_SMDRS32 "smdrs32")
   (UNSPEC_SMXDS32 "smxds32")])

(define_int_iterator UNSPEC_RV64_SM32 [
   UNSPEC_KMDA32
   UNSPEC_KMXDA32
   UNSPEC_SMBB32
   UNSPEC_SMBT32
   UNSPEC_SMTT32
   UNSPEC_SMDS32
   UNSPEC_SMDRS32
   UNSPEC_SMXDS32])

(define_insn "riscv_<rv64_sm32_int_str>"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (unspec:DI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:V2SI 2 "register_operand" "r")]
       UNSPEC_RV64_SM32))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<rv64_sm32_int_insn>\\t%0,%1,%2"
)

(define_insn "riscv_srl32_u"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")]
       UNSPEC_SRL32_U))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "srl32.u\\t%0,%1,%2"
)

(define_insn "riscv_srli32_u"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:SI 2 "immediate_operand" "i")]
       UNSPEC_SRL32_U))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "srli32.u\\t%0,%1,%2";
}
)

(define_insn "riscv_sra32_u"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")]
       UNSPEC_SRA32_U))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "sra32.u\\t%0,%1,%2"
)

(define_insn "riscv_srai32_u"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:SI 2 "immediate_operand" "i")]
       UNSPEC_SRA32_U))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "srai32.u\\t%0,%1,%2";
}
)

(define_insn "riscv_sraw_u"
  [(set (match_operand:SI 0 "register_operand" "=r")
     (unspec:SI
      [(match_operand:SI 1 "register_operand" "r")
       (match_operand:SI 2 "immediate_operand" "i")]
       UNSPEC_SRAW_U))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "sraiw.u\\t%0,%1,%2";
}
)

(define_insn "riscv_sraw_u_di"
  [(set (match_operand:DI 0 "register_operand" "=r")
     (sign_extend:DI (unspec:SI
       [(match_operand:SI 1 "register_operand" "r")
        (match_operand:SI 2 "immediate_operand" "i")]
       UNSPEC_SRAW_U)))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "sraiw.u\\t%0,%1,%2";
}
)

(define_code_iterator vshift32 [ss_ashift ashift ashiftrt lshiftrt])
(define_code_attr vshift32_code [(ss_ashift "ksll32") (ashift "sll32") (ashiftrt "sra32") (lshiftrt "srl32")])
(define_code_attr vshift32_insn [(ss_ashift "ksll32") (ashift "sll32") (ashiftrt "sra32") (lshiftrt "srl32")])

(define_insn "riscv_<vshift32_code>"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(vshift32:V2SI
	    (match_operand:V2SI 1 "register_operand" "r")
	    (match_operand:SI 2 "register_operand" "r")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "<vshift32_insn>\\t%0,%1,%2"
)

(define_code_iterator vshift32_imm [ss_ashift ashift ashiftrt lshiftrt])
(define_code_attr vshift32_imm_code [(ss_ashift "kslli32") (ashift "slli32")
				     (ashiftrt "srai32") (lshiftrt "srli32")])
(define_code_attr vshift32_imm_insn [(ss_ashift "kslli32") (ashift "slli32")
				     (ashiftrt "srai32") (lshiftrt "srli32")])

(define_insn "riscv_<vshift32_imm_code>"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
	(vshift32_imm:V2SI
	  (match_operand:V2SI 1 "register_operand" "r")
	  (match_operand:SI 2 "immediate_operand" "i")))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);
  return "<vshift32_imm_insn>\\t%0,%1,%2";
}
)

(define_insn "riscv_kslra32"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")]
       UNSPEC_KSLRA32))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "kslra32\\t%0,%1,%2"
)

(define_insn "riscv_kslra32_u"
  [(set (match_operand:V2SI 0 "register_operand" "=r")
     (unspec:V2SI
      [(match_operand:V2SI 1 "register_operand" "r")
       (match_operand:SI 2 "register_operand" "r")]
       UNSPEC_KSLRA32_U))]
  "TARGET_XTHEAD_DSP && TARGET_64BIT"
  "kslra32.u\\t%0,%1,%2"
)

