.data
A: .word 0,2,4,6,8,10,12,14,16
B: .word 1,3,5,7,9,11,13,15,17
RES: .word 0,0,0,0,0,0,0,0,0

.text
LDR R0,=A 
LDR R1,=B
LDR R2,=RES
MOV R3,#9

L1:LDR R4,[R0],#4
LDR R5,[R1],#4
ADD R6,R5,R4
STR R6,[R2],#4
SUB R3,R3,#1
CMP R3,#0
BNE L1

.END

