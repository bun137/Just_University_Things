.data

A:
	.WORD 5, 10, 15, 20, 25, 30, 35, 40, 45, 50
	KEY   : .WORD 30
	COUNT : .WORD 10
	.text
	LDR   R0, =A
	LDR   R1, =KEY
	LDR   R3, =COUNT
	MOV   R2, #0

L1:
	LDR  R6, [R1]
	LDR  R4, [R0]
	CMP  R4, R6
	BEQ  GOTCHA
	ADD  R0, R0, #4
	SUBS R3, R3, #1
	CMP  R3, #0
	BNE  L1
	B    END

GOTCHA:
	MOV R2, #1
	SWI 0x011

END:
	MOV R2, #0
	SWI 0x011
