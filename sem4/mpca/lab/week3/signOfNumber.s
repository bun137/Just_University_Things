
.data
A: .WORD -1,-2,1,2,-3,3,-4,4,9,-9
pos: .WORD 0
neg: .WORD 0
zero: .WORD 0

.text
LDR r0, =A
LDR r1, =pos
LDR r2, =neg
LDR r3, =zero
MOV r4, #10

loop:
LDR r8, [r0], #4
CMP R8, #0
BGT greater
BLT lesser
BEQ equal
lesser:
STR r8, [r2], #4
ADD r2,r2,#4
SUB r4,r4,#1
B compare
greater:
STR r8, [r1], #4
ADD r1,r1,#4
SUB r4,r4,#1
B compare
equal:
STR r8, [r3], #4
ADD r3,r3,#4
SUB r4,r4,#1
B compare
compare:
CMP r4, #0
BNE loop
