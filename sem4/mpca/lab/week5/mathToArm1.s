.data

a:
	.word 10

b:
	.word 20

z:
	.word 0

	.text

main:
	LDR r1, =a
	LDR r1, [r1]
	LDR r2, =b
	LDR r2, [r2]

	MOV r3, r1, LSL #2
	AND r4, r2, #15
	ORR r0, r3, r4

	LDR r5, =z
	STR r0, [r5]

	MOV r7, #1
	SWI #0
	.end
