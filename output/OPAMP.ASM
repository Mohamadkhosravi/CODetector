; Generated by holtek-gcc v3.19, Mon Oct 09 19:17:30 2023
; 
; Configuration:
;       with long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
; SFR address of long-instruction arch:
;    mp0 = -1,1,0
;    mp1 = 4,3,2
;    mp2 = 14,13,12
;    tbp = 9,7,8
;    acc = 5
;    pcl = 6
;    status = 10
;    bp = 11
;    intc = 72
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [4]
acc equ [5]
bp equ [11]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
cz equ [10].6
sc equ [10].7
intc equ [72]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
___sda0c equ [35]
___sda0vos equ [36]
___sda1c equ [37]
___sda1vos equ [38]
public _OPAMPset
#pragma debug scope 2 1
#line 8 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
_OPAMPset .section 'code'
_OPAMPset proc
#line 9 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set _FT
#line 13 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [35].6
#line 20 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].7
#line 21 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].6
#line 25 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].0
#line 26 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].1
#line 27 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].2
#line 28 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].3
#line 29 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].4
#line 30 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].5
#line 32 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr ra
	sz [35].5
	inc ra
	;
	clr _opamp0
	sz ra.0
	set _opamp0
_L2:
#line 36 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr rb
	sz [35].5
	inc rb
	sz ra.0
	jmp _LI1
	sz rb.0
	jmp _L3
	jmp _LI2
_LI1:
	snz rb.0
	jmp _L3
_LI2:
#line 37 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	siza [36]
	jmp _LI3
	jmp _L3
_LI3:
#line 38 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	inc [36]
	jmp _L2
_L3:
#line 41 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	sz [36].0
	jmp _L5
	sz [36].1
	jmp _L5
	sz [36].2
	jmp _L5
	sz [36].3
	jmp _L5
	sz [36].4
	jmp _L5
	mov a,[36]
	mov ra,a
_L5:
#line 44 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].0
#line 45 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].1
#line 46 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].2
#line 47 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].3
#line 48 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].4
#line 49 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [36].5
#line 51 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr ra
	sz [35].5
	inc ra
	;
	clr _opamp0
	sz ra.0
	set _opamp0
#line 55 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,[36]
	mov rb,a
	mov a,0
	sub a,rb
	mov rc,a
	mov a,rc
	orm a,rb
	rlc rb
	clr rb
	rlc rb
	mov a,rb
	mov rd,a
	clr re
	mov a,rb
	mov _VA0OS1[0],a
_L6:
#line 57 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr rb
	sz [35].5
	inc rb
	sz ra.0
	jmp _LI4
	sz rb.0
	jmp _L11
	jmp _LI5
_LI4:
	snz rb.0
	jmp _L11
_LI5:
#line 58 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	dec [36]
#line 59 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,[36]
	sub a,192
	snz z
	jmp _L6
_L11:
#line 62 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	sz [36].0
	jmp _L28
	sz [36].1
	jmp _L28
	sz [36].2
	jmp _L28
	sz [36].3
	jmp _L28
	sz [36].4
	jmp _L28
	clr rb
	sz [36].5
	inc rb
	clr rc
	jmp _L8
_L28:
	mov a,1
	mov rb,a
	clr rc
_L8:
	mov a,rb
	mov _VA0OS2[0],a
#line 66 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,rd
	addm a,rb
	mov a,re
	adcm a,rc
	rlca rc
	rrc rc
	rrc rb
	mov a,rb
	mov _VA0OS[0],a
#line 67 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,rb
	mov [36],a
#line 72 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [35].6
#line 80 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [37].6
#line 87 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].7
#line 88 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].6
#line 92 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].0
#line 93 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].1
#line 94 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].2
#line 95 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].3
#line 96 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].4
#line 97 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].5
#line 99 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr rb
	sz [37].5
	inc rb
	;
	clr _opamp1
	sz rb.0
	set _opamp1
#line 106 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,_VA1OS1[0]
	mov rd,a
	mov a,_VA0OS1[0]
	mov ra,a
_L12:
#line 103 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr rc
	sz [37].5
	inc rc
	sz rb.0
	jmp _LI6
	sz rc.0
	jmp _L40
	jmp _LI7
_LI6:
	snz rc.0
	jmp _L40
_LI7:
#line 104 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	inc [38]
#line 105 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,[38]
	mov ra,a
	mov a,0
	sub a,ra
	mov rc,a
	mov a,rc
	orm a,ra
	rlc ra
	clr ra
	rlc ra
#line 106 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,62
	sub a,rd
	snz sc
	jmp _L12
_L40:
	mov a,ra
	mov _VA0OS1[0],a
#line 108 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	sz [38].0
	jmp _L14
	sz [38].1
	jmp _L14
	sz [38].2
	jmp _L14
	sz [38].3
	jmp _L14
	sz [38].4
	jmp _L14
	mov a,[38]
	mov ra,a
_L14:
#line 111 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].0
#line 112 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].1
#line 113 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].2
#line 114 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].3
#line 115 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].4
#line 116 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [38].5
#line 118 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr ra
	sz [37].5
	inc ra
	;
	clr _opamp1
	sz ra.0
	set _opamp1
#line 122 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,[38]
	mov rb,a
	mov a,0
	sub a,rb
	mov rc,a
	mov a,rc
	orm a,rb
	rla rb
	and a,1
	mov _VA1OS1[0],a
_L18:
#line 124 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr rb
	sz [37].5
	inc rb
	sz ra.0
	jmp _LI8
	sz rb.0
	jmp _L23
	jmp _LI9
_LI8:
	snz rb.0
	jmp _L23
_LI9:
#line 125 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	dec [38]
#line 126 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,[38]
	mov rb,a
	mov a,0
	sub a,rb
	mov rc,a
	mov a,rc
	orm a,rb
#line 127 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	sz rb.7
	jmp _L18
_L23:
#line 130 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	sz [38].0
	jmp _L33
	sz [38].1
	jmp _L33
	sz [38].2
	jmp _L33
	sz [38].3
	jmp _L33
	sz [38].4
	jmp _L33
	clr rb
	sz [38].5
	inc rb
	clr rc
	jmp _L20
_L33:
	mov a,1
	mov rb,a
	clr rc
_L20:
	mov a,rb
	mov _VA1OS2[0],a
#line 134 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,_VA0OS1[0]
	mov rd,a
	clr re
	sz acc.7
	set re
	mov a,rd
	addm a,rb
	mov a,re
	adcm a,rc
	mov a,rb
	mov rd,a
	mov a,rc
	mov re,a
	rlc re
	clr rd
	rlc rd
	clr re
	mov a,rd
	addm a,rb
	mov a,re
	adcm a,rc
	rlca rc
	rrc rc
	rrc rb
	mov a,rb
	mov ra,a
	mov a,rb
	mov _VA1OS[0],a
#line 135 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,0
	subm a,ra
	mov a,ra
	orm a,rb
	rla rb
	and a,1
	mov [38],a
#line 140 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [37].6
	ret
_OPAMPset endp
#line 140 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
#pragma debug scope 1 1
___pas0 equ [76]
___sdsw equ [32]
___sdpgac0 equ [33]
___sdpgac1 equ [34]
public _OPAMPInit
#pragma debug scope 3 1
#line 149 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
_OPAMPInit .section 'code'
_OPAMPInit proc
#line 153 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [76].2
#line 154 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [76].3
#line 161 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [32].0
#line 162 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [32].1
#line 163 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [32].2
#line 164 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [32].3
#line 165 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [32].4
#line 167 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [32].5
#line 168 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [32].6
#line 170 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].7
#line 171 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].7
#line 174 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,1
	mov [33],a
#line 179 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	mov a,193
	mov [34],a
#line 182 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [35].0
#line 183 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [35].1
#line 186 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [37].0
#line 187 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [37].1
#line 191 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	set [35].6
#line 194 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].7
#line 195 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [36].6
#line 197 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].7
#line 198 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	clr [38].6
#line 203 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	sz _FT
	jmp _L42
#line 204 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
	call _OPAMPset
_L42:
	ret
_OPAMPInit endp
#line 204 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.c"
#pragma debug scope 1 1
#line 11 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _opamp1
@BITDATASEC .section 'data'
_opamp1	dbit 0
#pragma debug variable 2 1 _opamp1 "opamp1"

@HCCINIT .section 'data'
#line 11 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _opamp0
@BITDATASEC .section 'data'
_opamp0	dbit 0
#pragma debug variable 2 1 _opamp0 "opamp0"

@HCCINIT .section 'data'
#line 10 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _VA1OS2
@HCCINIT0_VA1OS2 .section 'data'
_VA1OS2	db 0
#pragma debug variable 7 1 _VA1OS2 "VA1OS2"

@HCCINIT .section 'data'
#line 10 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _VA1OS1
@HCCINIT0_VA1OS1 .section 'data'
_VA1OS1	db 0
#pragma debug variable 7 1 _VA1OS1 "VA1OS1"

@HCCINIT .section 'data'
#line 10 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _VA1OS
@HCCINIT0_VA1OS .section 'data'
_VA1OS	db 0
#pragma debug variable 7 1 _VA1OS "VA1OS"

@HCCINIT .section 'data'
#line 9 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _VA0OS2
@HCCINIT0_VA0OS2 .section 'data'
_VA0OS2	db 0
#pragma debug variable 7 1 _VA0OS2 "VA0OS2"

@HCCINIT .section 'data'
#line 9 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _VA0OS1
@HCCINIT0_VA0OS1 .section 'data'
_VA0OS1	db 0
#pragma debug variable 7 1 _VA0OS1 "VA0OS1"

@HCCINIT .section 'data'
#line 9 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _VA0OS
@HCCINIT0_VA0OS .section 'data'
_VA0OS	db 0
#pragma debug variable 7 1 _VA0OS "VA0OS"

@HCCINIT .section 'data'
#line 8 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _V_op1
@HCCINIT0_V_op1 .section 'data'
_V_op1	db 2 dup(0)
#pragma debug variable 11 1 _V_op1 "V_op1"

@HCCINIT .section 'data'
#line 7 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
public _V_op0
@HCCINIT0_V_op0 .section 'data'
_V_op0	db 2 dup(0)
#pragma debug variable 11 1 _V_op0 "V_op0"

@HCCINIT .section 'data'
public _FT
@HCCINIT	.section 'data'
#line 6 "c:\users\tech\desktop\codetector\OPAMP\OPAMP.h"
@BITDATASEC .section 'data'
_FT	dbit 0
#pragma debug variable 2 1 _FT "FT"
#pragma debug struct_begin 42 "__sdsw_bits"
#pragma debug field 21 8 0 1 "__sds0" ;0,1
#pragma debug field 21 8 0 1 "__sds1" ;1,1
#pragma debug field 21 8 0 1 "__sds2" ;2,1
#pragma debug field 21 8 0 1 "__sds3" ;3,1
#pragma debug field 21 8 0 1 "__sds4" ;4,1
#pragma debug field 21 8 0 1 "__sds5" ;5,1
#pragma debug field 21 8 0 1 "__sds6" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 ___sdsw "__sdsw" 1
#pragma debug struct_begin 44 "__sdpgac0_bits"
#pragma debug field 21 8 0 1 "__sda0pga0" ;0,1
#pragma debug field 21 8 0 1 "__sda0pga1" ;1,1
#pragma debug field 21 8 0 1 "__sda0pga2" ;2,1
#pragma debug field 21 8 0 1 "__sda0pga3" ;3,1
#pragma debug field 21 8 0 1 "__sda0pga4" ;4,1
#pragma debug field 21 8 0 1 "__sda0pga5" ;5,1
#pragma debug field 21 8 0 2 ;6,2
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 ___sdpgac0 "__sdpgac0" 1
#pragma debug struct_begin 46 "__sdpgac1_bits"
#pragma debug field 21 8 0 1 "__sda1pga0" ;0,1
#pragma debug field 21 8 0 1 "__sda1pga1" ;1,1
#pragma debug field 21 8 0 1 "__sda1pga2" ;2,1
#pragma debug field 21 8 0 1 "__sda1pga3" ;3,1
#pragma debug field 21 8 0 1 "__sda1pga4" ;4,1
#pragma debug field 21 8 0 1 "__sda1pga5" ;5,1
#pragma debug field 21 8 0 1 "__sda1pga6" ;6,1
#pragma debug field 21 8 0 1 "__sda1pga7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 47 ""
#pragma debug field 2 46 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 47 1 ___sdpgac1 "__sdpgac1" 1
#pragma debug struct_begin 48 "__sda0c_bits"
#pragma debug field 21 8 0 1 "__sda0bw0" ;0,1
#pragma debug field 21 8 0 1 "__sda0bw1" ;1,1
#pragma debug field 21 8 0 3 ;2,3
#pragma debug field 21 8 0 1 "__sda0o" ;5,1
#pragma debug field 21 8 0 1 "__sda0en" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 49 ""
#pragma debug field 2 48 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 49 1 ___sda0c "__sda0c" 1
#pragma debug struct_begin 50 "__sda0vos_bits"
#pragma debug field 21 8 0 1 "__sda0of0" ;0,1
#pragma debug field 21 8 0 1 "__sda0of1" ;1,1
#pragma debug field 21 8 0 1 "__sda0of2" ;2,1
#pragma debug field 21 8 0 1 "__sda0of3" ;3,1
#pragma debug field 21 8 0 1 "__sda0of4" ;4,1
#pragma debug field 21 8 0 1 "__sda0of5" ;5,1
#pragma debug field 21 8 0 1 "__sda0rsp" ;6,1
#pragma debug field 21 8 0 1 "__sda0ofm" ;7,1
#pragma debug struct_end
#pragma debug union_begin 51 ""
#pragma debug field 2 50 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 51 1 ___sda0vos "__sda0vos" 1
#pragma debug struct_begin 52 "__sda1c_bits"
#pragma debug field 21 8 0 1 "__sda1bw0" ;0,1
#pragma debug field 21 8 0 1 "__sda1bw1" ;1,1
#pragma debug field 21 8 0 3 ;2,3
#pragma debug field 21 8 0 1 "__sda1o" ;5,1
#pragma debug field 21 8 0 1 "__sda1en" ;6,1
#pragma debug field 21 8 0 1 ;7,1
#pragma debug struct_end
#pragma debug union_begin 53 ""
#pragma debug field 2 52 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 53 1 ___sda1c "__sda1c" 1
#pragma debug struct_begin 54 "__sda1vos_bits"
#pragma debug field 21 8 0 1 "__sda1of0" ;0,1
#pragma debug field 21 8 0 1 "__sda1of1" ;1,1
#pragma debug field 21 8 0 1 "__sda1of2" ;2,1
#pragma debug field 21 8 0 1 "__sda1of3" ;3,1
#pragma debug field 21 8 0 1 "__sda1of4" ;4,1
#pragma debug field 21 8 0 1 "__sda1of5" ;5,1
#pragma debug field 21 8 0 1 "__sda1rsp" ;6,1
#pragma debug field 21 8 0 1 "__sda1ofm" ;7,1
#pragma debug struct_end
#pragma debug union_begin 55 ""
#pragma debug field 2 54 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 55 1 ___sda1vos "__sda1vos" 1
#pragma debug struct_begin 56 "__pas0_bits"
#pragma debug field 21 8 0 1 "__pas00" ;0,1
#pragma debug field 21 8 0 1 "__pas01" ;1,1
#pragma debug field 21 8 0 1 "__pas02" ;2,1
#pragma debug field 21 8 0 1 "__pas03" ;3,1
#pragma debug field 21 8 0 1 "__pas04" ;4,1
#pragma debug field 21 8 0 1 "__pas05" ;5,1
#pragma debug field 21 8 0 1 "__pas06" ;6,1
#pragma debug field 21 8 0 1 "__pas07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 57 ""
#pragma debug field 2 56 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 57 1 ___pas0 "__pas0" 1

; 
; Generated by holtek-gcc v3.19, Mon Oct 09 19:17:30 2023
; Rebuild 718
; end of file
