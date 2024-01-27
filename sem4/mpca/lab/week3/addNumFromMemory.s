
.data
num1: .word 5
num2: .word 10
result: .word 0

.text
LDR R0, =num1
LDR R1, =num2
LDR R2, [R0]
LDR R3, [R1]
ADD R4, R2, R3
LDR R5, =result
STR R4, [R5]

