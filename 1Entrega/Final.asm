include macros2.asm
include number.asm
.MODEL LARGE 
.386 
.STACK 200h 
.DATA 
	_6.5 dd 6.5 
	_2.3 dd 2.3 
	_5 dd 5 
	_2 dd 2 
	_3 dd 3 
	_5.6 dd 5.6 
	_.5 dd .5 
	_3.4 dd 3.4 
	_1.6 dd 1.6 
	_7 dd 7 
	_4 dd 4 
	_ls dd ? 
	_n dd ? 
	_li dd ? 
	_a dd ? 
	_b dd ? 
	_i dd ? 
	_cadena db  30 dup (?) '$'
	_s db  30 dup (?) '$'
	_peso db  30 dup (?) '$'
	_aux dd ? 
.CODE 
	 mov AX,@DATA 
	 mov DS,AX 
	 FLD _6.5 
	 FSTP _ls  ; Asignacion 
	 FLD _2.3 
	 FSTP _i  ; Asignacion 
	 FLD _5 
	 FLD _b 
	 FADD 
	 FSTP _aux 
	 FLD _sum 
	 FLD _aux 
	 FADD 
	 FSTP _aux 
	 FLD _cont 
	 FLD _1 
	 FADD 
	 FSTP _aux 
	 FLD _sum 
	 FLD _2 
	 FADD 
	 FSTP _aux 
	 FLD _cont 
	 FLD _1 
	 FADD 
	 FSTP _aux 
	 FLD _sum 
	 FLD _3 
	 FADD 
	 FSTP _aux 
	 FLD _cont 
	 FLD _1 
	 FADD 
	 FSTP _aux 
	 FLD _sum 
	 FLD _5.6 
	 FADD 
	 FSTP _aux 
	 FLD _cont 
	 FLD _1 
	 FADD 
	 FSTP _aux 
	 FLD _sum 
	 FLD _cont 
	 FDIV 
	 FSTP _aux 
	 FLD _5.6 
	 FSTP _a  ; Asignacion 
	 FLD _.5 
	 FSTP _li  ; Asignacion 
	 FLD _a 
	 FLD _3.4 
	 BLT 
	 FSTP _aux 
	 FLD _5 
	 FLD _b 
	 FADD 
	 FSTP _aux 
	 FLD _a 
	 FLD _aux 
	 BGT 
	 FSTP _aux 
	 FLD _aux 
	 FLD _aux 
	 BNE 
	 FSTP _aux 
	 FLD _1.6 
	 FSTP _i  ; Asignacion 
	 FLD _a 
	 FLD _7 
	 BGE 
	 FSTP _aux 
	 FLD _5 
	 FLD _b 
	 FADD 
	 FSTP _aux 
	 FLD _aux 
	 FSTP _i  ; Asignacion 
	 FLD _a 
	 FLD _7 
	 BGE 
	 FSTP _aux 
	 FLD _a 
	 FLD _4 
	 BGE 
	 FSTP _aux 
	 FLD _1.6 
	 FSTP _i  ; Asignacion 
	 FLD _a 
	 FLD _7 
	 BGE 
	 FSTP _aux 
	 FLD _a 
	 FLD _4 
	 BGE 
	 FSTP _aux 
	 FLD _1.6 
	 FSTP _i  ; Asignacion 
	 FLD _a 
	 FLD _7 
	 BGE 
	 FSTP _aux 
	 FLD _1.6 
	 FSTP _i  ; Asignacion 
mov ax, 4C00h 
int 21h 
END 
