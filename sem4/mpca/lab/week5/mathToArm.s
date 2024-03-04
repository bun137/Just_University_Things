.data

a:
	.word 5

b:
	.word 10

c:
	.word 3

x:
	.word 0

	.text

main:
	LDR r1, =a
	LDR r1, [r1]
	LDR r2, =b
	LDR r2, [r2]
	LDR r3, =c
	LDR r3, [r3]

	ADD r0, r1, r2
	SUB r0, r0, r3

	LDR r4, =x
	STR r0, [r4]

	MOV r7, #1
	SWI #0
	.end
