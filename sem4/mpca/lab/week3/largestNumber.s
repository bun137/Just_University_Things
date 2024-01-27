.data
A: .WORD 1,2,3,4,5,6
.text
LDR r0, = A
LDR r1,[r0] 
MOV R3, #6

loop:
LDR r2, [r0]
CMP r1, r2
BLT maxi
B increment 

maxi:
LDR r1, [r0]
B increment 
    
increment:
ADD r0,r0,#4
SUB r3,r3,#1
CMP r3,#0
BNE loop
    
.end
