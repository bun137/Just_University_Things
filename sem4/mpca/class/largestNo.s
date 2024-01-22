.data
g: .word 1,2,3,4,5,6,7,8,9,10

.text
LDR R1,=g
LDR R2, [R1]
MOV R3, #0

LOOP:
  CMP R2, R1
  BGT L1
  MOV R2, R1
L1:
ADD R1, R1, #4
ADD R3, R3, #1
CMP R3, #10
BNE LOOP
