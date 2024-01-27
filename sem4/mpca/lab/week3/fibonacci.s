 .data
a: .WORD 9
seq: .WORD 0
.text
LDR r0, =seq 
MOV r1, #0
MOV r2, #1
LDR r3, =a
LDR r4, [r3]

loop:
STR r1, [r0], #4
ADD r5,r1,r2
MOV r1,r2
MOV r2,r5 
SUB r4,r4,#1
CMP r4,#2
BNE loop
.end
