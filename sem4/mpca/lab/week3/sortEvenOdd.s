.data
A: .WORD 1,2,3,4,5,6,7,8,9,10 
odd: .WORD 0
even: .WORD 0

.text
LDR r0, =A
LDR r1, =odd
LDR r2, =even
MOV r3, #10
loop:
LDR r4, [r0], #4
AND r5, r4, #1
CMP r5, #1
BEQ oddn
BNE evenn
oddn:
STR r4, [r1], #4
ADD r1,r1,#4
SUB r3,r3,#1
B compare
evenn:
STR r4,[r2],#4
ADD r2,r2,#4
SUB r3,r3,#1
B compare
compare:
CMP r3,#0
BNE loop
.end
