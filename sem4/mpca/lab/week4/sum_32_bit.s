	.DATA

A:
	.WORD 225

	.TEXT
	LDR R4, =A
	MOV R1, #0
	MOV R2, #0
	LDR R3, [R4]

LOOP:
	MOV     R1, #0
	SUB:CMP R3, #10
	BLT     CONT
	SUBPL   R3, R3, #10
	ADDPL   R1, R1, #1
	CMP     R3, #10
	BGE     SUB

CONT:
	ADD R2, R2, R3
	MOV R3, R1
	CMP R3, #0
	BNE LOOP

DONE:
	SWI 0x011

	.END
