.data
A: .BYTE 1,2,3,4,5,6,7,8,9,10 
sum: .WORD 0
.text
LDR r0, =A
MOV r1, #0
MOV r2, #10

loop:
LDRB r3, [r0], #1
ADD r1,r1,r3 
SUB r2,r2,#1
CMP r2,#0
BNE loop
    
LDR r3, =sum
STR r1, [r3]
.end
    
