/* { dg-do assemble } */
/* { dg-skip-if "test ldia/ldib and stia/stib insns" { *-*-* } { "*" } { "-march=rv64*xtheadc*" "-march=rv64*xtheade*" } } */
/* { dg-options "--save-temps -O2" } */

#include "addr-modes.h"

typedef signed char schar;
typedef unsigned short ushort;
typedef long long ll;

/* no special function attribute required */
#define ATTR /* */

PRE_STORE(char, ATTR)
/* { dg-final { scan-assembler "th.sbib.*1,0" } } */
PRE_STORE(short, ATTR)
/* { dg-final { scan-assembler "th.shib.*2,0" } } */
PRE_STORE(int, ATTR)
/* { dg-final { scan-assembler "th.swib.*4,0" } } */
PRE_STORE(ll, ATTR)
/* { dg-final { scan-assembler "th.sdib.*8,0" } } */

POST_STORE(char, ATTR)
/* { dg-final { scan-assembler "th.sbia.*1,0" } } */
POST_STORE(short, ATTR)
/* { dg-final { scan-assembler "th.shia.*2,0" } } */
POST_STORE(int, ATTR)
/* { dg-final { scan-assembler "th.swia.*4,0" } } */
POST_STORE(ll, ATTR)
/* { dg-final { scan-assembler "th.sdia.*8,0" } } */

PRE_LOAD(char, ATTR)
/* { dg-final { scan-assembler "th.lbuib.*1,0" } } */
PRE_LOAD(schar, ATTR)
/* { dg-final { scan-assembler "th.lbib.*1,0" } } */
PRE_LOAD(ushort, ATTR)
/* { dg-final { scan-assembler "th.lhuib.*2,0" } } */
PRE_LOAD(short, ATTR)
/* { dg-final { scan-assembler "th.lhib.*2,0" } } */
PRE_LOAD(int, ATTR)
/* { dg-final { scan-assembler "th.lwib.*4,0" } } */
PRE_LOAD(ll, ATTR)
/* { dg-final { scan-assembler "th.ldib.*8,0" } } */

POST_LOAD(char, ATTR)
/* { dg-final { scan-assembler "th.lbuia.*1,0" } } */
POST_LOAD(schar, ATTR)
/* { dg-final { scan-assembler "th.lbia.*1,0" } } */
POST_LOAD(ushort, ATTR)
/* { dg-final { scan-assembler "th.lhuia.*2,0" } } */
POST_LOAD(short, ATTR)
/* { dg-final { scan-assembler "th.lhia.*2,0" } } */
POST_LOAD(int, ATTR)
/* { dg-final { scan-assembler "th.lwia.*4,0" } } */
POST_LOAD(ll, ATTR)
/* { dg-final { scan-assembler "th.ldia.*8,0" } } */

/* { dg-final { scan-assembler-not "\taddi" } } */

/* { dg-final { cleanup-saved-temps } } */

