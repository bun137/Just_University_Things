.data
save: .word 6,6,6,30,40
a: .word 6

.text
LDR R0, =save
LDR R1, =a
MOV R2, #1
LOOP:
CMP R0,R1
BEQ INC
BNE BREAK
INC:
ADD R2, R2, #1
ADD R0, R0, #4
BREAK:
SWI 0x11

