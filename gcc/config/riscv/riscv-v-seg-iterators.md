(define_mode_iterator VANYSEG128 [
  VNx2x16HF VNx2x16HI VNx2x16QI VNx2x16SF
  VNx2x16SI VNx2x2DF VNx2x2DI VNx2x32HF
  VNx2x32HI VNx2x32QI VNx2x4DF VNx2x4DI
  VNx2x4SF VNx2x4SI VNx2x64QI VNx2x8DF
  VNx2x8DI VNx2x8HF VNx2x8HI VNx2x8SF
  VNx2x8SI VNx3x16HF VNx3x16HI VNx3x16QI
  VNx3x2DF VNx3x2DI VNx3x32QI VNx3x4DF
  VNx3x4DI VNx3x4SF VNx3x4SI VNx3x8HF
  VNx3x8HI VNx3x8SF VNx3x8SI VNx4x16HF
  VNx4x16HI VNx4x16QI VNx4x2DF VNx4x2DI
  VNx4x32QI VNx4x4DF VNx4x4DI VNx4x4SF
  VNx4x4SI VNx4x8HF VNx4x8HI VNx4x8SF
  VNx4x8SI VNx5x16QI VNx5x2DF VNx5x2DI
  VNx5x4SF VNx5x4SI VNx5x8HF VNx5x8HI
  VNx6x16QI VNx6x2DF VNx6x2DI VNx6x4SF
  VNx6x4SI VNx6x8HF VNx6x8HI VNx7x16QI
  VNx7x2DF VNx7x2DI VNx7x4SF VNx7x4SI
  VNx7x8HF VNx7x8HI VNx8x16QI VNx8x2DF
  VNx8x2DI VNx8x4SF VNx8x4SI VNx8x8HF
  VNx8x8HI])

(define_mode_attr SEG_BASE_MODE [
  (VNx2x16HF "V16HF") (VNx2x16HI "V16HI") (VNx2x16QI "V16QI") (VNx2x16SF "V16SF")
  (VNx2x16SI "V16SI") (VNx2x2DF "V2DF") (VNx2x2DI "V2DI") (VNx2x32HF "V32HF")
  (VNx2x32HI "V32HI") (VNx2x32QI "V32QI") (VNx2x4DF "V4DF") (VNx2x4DI "V4DI")
  (VNx2x4SF "V4SF") (VNx2x4SI "V4SI") (VNx2x64QI "V64QI") (VNx2x8DF "V8DF")
  (VNx2x8DI "V8DI") (VNx2x8HF "V8HF") (VNx2x8HI "V8HI") (VNx2x8SF "V8SF")
  (VNx2x8SI "V8SI") (VNx3x16HF "V16HF") (VNx3x16HI "V16HI") (VNx3x16QI "V16QI")
  (VNx3x2DF "V2DF") (VNx3x2DI "V2DI") (VNx3x32QI "V32QI") (VNx3x4DF "V4DF")
  (VNx3x4DI "V4DI") (VNx3x4SF "V4SF") (VNx3x4SI "V4SI") (VNx3x8HF "V8HF")
  (VNx3x8HI "V8HI") (VNx3x8SF "V8SF") (VNx3x8SI "V8SI") (VNx4x16HF "V16HF")
  (VNx4x16HI "V16HI") (VNx4x16QI "V16QI") (VNx4x2DF "V2DF") (VNx4x2DI "V2DI")
  (VNx4x32QI "V32QI") (VNx4x4DF "V4DF") (VNx4x4DI "V4DI") (VNx4x4SF "V4SF")
  (VNx4x4SI "V4SI") (VNx4x8HF "V8HF") (VNx4x8HI "V8HI") (VNx4x8SF "V8SF")
  (VNx4x8SI "V8SI") (VNx5x16QI "V16QI") (VNx5x2DF "V2DF") (VNx5x2DI "V2DI")
  (VNx5x4SF "V4SF") (VNx5x4SI "V4SI") (VNx5x8HF "V8HF") (VNx5x8HI "V8HI")
  (VNx6x16QI "V16QI") (VNx6x2DF "V2DF") (VNx6x2DI "V2DI") (VNx6x4SF "V4SF")
  (VNx6x4SI "V4SI") (VNx6x8HF "V8HF") (VNx6x8HI "V8HI") (VNx7x16QI "V16QI")
  (VNx7x2DF "V2DF") (VNx7x2DI "V2DI") (VNx7x4SF "V4SF") (VNx7x4SI "V4SI")
  (VNx7x8HF "V8HF") (VNx7x8HI "V8HI") (VNx8x16QI "V16QI") (VNx8x2DF "V2DF")
  (VNx8x2DI "V2DI") (VNx8x4SF "V4SF") (VNx8x4SI "V4SI") (VNx8x8HF "V8HF")
  (VNx8x8HI "V8HI")])

(define_mode_attr seg_base_mode [
  (VNx2x16HF "v16hf") (VNx2x16HI "v16hi") (VNx2x16QI "v16qi") (VNx2x16SF "v16sf")
  (VNx2x16SI "v16si") (VNx2x2DF "v2df") (VNx2x2DI "v2di") (VNx2x32HF "v32hf")
  (VNx2x32HI "v32hi") (VNx2x32QI "v32qi") (VNx2x4DF "v4df") (VNx2x4DI "v4di")
  (VNx2x4SF "v4sf") (VNx2x4SI "v4si") (VNx2x64QI "v64qi") (VNx2x8DF "v8df")
  (VNx2x8DI "v8di") (VNx2x8HF "v8hf") (VNx2x8HI "v8hi") (VNx2x8SF "v8sf")
  (VNx2x8SI "v8si") (VNx3x16HF "v16hf") (VNx3x16HI "v16hi") (VNx3x16QI "v16qi")
  (VNx3x2DF "v2df") (VNx3x2DI "v2di") (VNx3x32QI "v32qi") (VNx3x4DF "v4df")
  (VNx3x4DI "v4di") (VNx3x4SF "v4sf") (VNx3x4SI "v4si") (VNx3x8HF "v8hf")
  (VNx3x8HI "v8hi") (VNx3x8SF "v8sf") (VNx3x8SI "v8si") (VNx4x16HF "v16hf")
  (VNx4x16HI "v16hi") (VNx4x16QI "v16qi") (VNx4x2DF "v2df") (VNx4x2DI "v2di")
  (VNx4x32QI "v32qi") (VNx4x4DF "v4df") (VNx4x4DI "v4di") (VNx4x4SF "v4sf")
  (VNx4x4SI "v4si") (VNx4x8HF "v8hf") (VNx4x8HI "v8hi") (VNx4x8SF "v8sf")
  (VNx4x8SI "v8si") (VNx5x16QI "v16qi") (VNx5x2DF "v2df") (VNx5x2DI "v2di")
  (VNx5x4SF "v4sf") (VNx5x4SI "v4si") (VNx5x8HF "v8hf") (VNx5x8HI "v8hi")
  (VNx6x16QI "v16qi") (VNx6x2DF "v2df") (VNx6x2DI "v2di") (VNx6x4SF "v4sf")
  (VNx6x4SI "v4si") (VNx6x8HF "v8hf") (VNx6x8HI "v8hi") (VNx7x16QI "v16qi")
  (VNx7x2DF "v2df") (VNx7x2DI "v2di") (VNx7x4SF "v4sf") (VNx7x4SI "v4si")
  (VNx7x8HF "v8hf") (VNx7x8HI "v8hi") (VNx8x16QI "v16qi") (VNx8x2DF "v2df")
  (VNx8x2DI "v2di") (VNx8x4SF "v4sf") (VNx8x4SI "v4si") (VNx8x8HF "v8hf")
  (VNx8x8HI "v8hi")])

(define_mode_attr seg_nf [
  (VNx2x16HF "2") (VNx2x16HI "2") (VNx2x16QI "2") (VNx2x16SF "2")
  (VNx2x16SI "2") (VNx2x2DF "2") (VNx2x2DI "2") (VNx2x32HF "2")
  (VNx2x32HI "2") (VNx2x32QI "2") (VNx2x4DF "2") (VNx2x4DI "2")
  (VNx2x4SF "2") (VNx2x4SI "2") (VNx2x64QI "2") (VNx2x8DF "2")
  (VNx2x8DI "2") (VNx2x8HF "2") (VNx2x8HI "2") (VNx2x8SF "2")
  (VNx2x8SI "2") (VNx3x16HF "3") (VNx3x16HI "3") (VNx3x16QI "3")
  (VNx3x2DF "3") (VNx3x2DI "3") (VNx3x32QI "3") (VNx3x4DF "3")
  (VNx3x4DI "3") (VNx3x4SF "3") (VNx3x4SI "3") (VNx3x8HF "3")
  (VNx3x8HI "3") (VNx3x8SF "3") (VNx3x8SI "3") (VNx4x16HF "4")
  (VNx4x16HI "4") (VNx4x16QI "4") (VNx4x2DF "4") (VNx4x2DI "4")
  (VNx4x32QI "4") (VNx4x4DF "4") (VNx4x4DI "4") (VNx4x4SF "4")
  (VNx4x4SI "4") (VNx4x8HF "4") (VNx4x8HI "4") (VNx4x8SF "4")
  (VNx4x8SI "4") (VNx5x16QI "5") (VNx5x2DF "5") (VNx5x2DI "5")
  (VNx5x4SF "5") (VNx5x4SI "5") (VNx5x8HF "5") (VNx5x8HI "5")
  (VNx6x16QI "6") (VNx6x2DF "6") (VNx6x2DI "6") (VNx6x4SF "6")
  (VNx6x4SI "6") (VNx6x8HF "6") (VNx6x8HI "6") (VNx7x16QI "7")
  (VNx7x2DF "7") (VNx7x2DI "7") (VNx7x4SF "7") (VNx7x4SI "7")
  (VNx7x8HF "7") (VNx7x8HI "7") (VNx8x16QI "8") (VNx8x2DF "8")
  (VNx8x2DI "8") (VNx8x4SF "8") (VNx8x4SI "8") (VNx8x8HF "8")
  (VNx8x8HI "8")])

(define_mode_attr seg_lmul [
  (VNx2x16HF "2") (VNx2x16HI "2") (VNx2x16QI "1") (VNx2x16SF "4")
  (VNx2x16SI "4") (VNx2x2DF "1") (VNx2x2DI "1") (VNx2x32HF "4")
  (VNx2x32HI "4") (VNx2x32QI "2") (VNx2x4DF "2") (VNx2x4DI "2")
  (VNx2x4SF "1") (VNx2x4SI "1") (VNx2x64QI "4") (VNx2x8DF "4")
  (VNx2x8DI "4") (VNx2x8HF "1") (VNx2x8HI "1") (VNx2x8SF "2")
  (VNx2x8SI "2") (VNx3x16HF "2") (VNx3x16HI "2") (VNx3x16QI "1")
  (VNx3x2DF "1") (VNx3x2DI "1") (VNx3x32QI "2") (VNx3x4DF "2")
  (VNx3x4DI "2") (VNx3x4SF "1") (VNx3x4SI "1") (VNx3x8HF "1")
  (VNx3x8HI "1") (VNx3x8SF "2") (VNx3x8SI "2") (VNx4x16HF "2")
  (VNx4x16HI "2") (VNx4x16QI "1") (VNx4x2DF "1") (VNx4x2DI "1")
  (VNx4x32QI "2") (VNx4x4DF "2") (VNx4x4DI "2") (VNx4x4SF "1")
  (VNx4x4SI "1") (VNx4x8HF "1") (VNx4x8HI "1") (VNx4x8SF "2")
  (VNx4x8SI "2") (VNx5x16QI "1") (VNx5x2DF "1") (VNx5x2DI "1")
  (VNx5x4SF "1") (VNx5x4SI "1") (VNx5x8HF "1") (VNx5x8HI "1")
  (VNx6x16QI "1") (VNx6x2DF "1") (VNx6x2DI "1") (VNx6x4SF "1")
  (VNx6x4SI "1") (VNx6x8HF "1") (VNx6x8HI "1") (VNx7x16QI "1")
  (VNx7x2DF "1") (VNx7x2DI "1") (VNx7x4SF "1") (VNx7x4SI "1")
  (VNx7x8HF "1") (VNx7x8HI "1") (VNx8x16QI "1") (VNx8x2DF "1")
  (VNx8x2DI "1") (VNx8x4SF "1") (VNx8x4SI "1") (VNx8x8HF "1")
  (VNx8x8HI "1")])

