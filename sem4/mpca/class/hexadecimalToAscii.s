.data
a: .word 54

.text
LDR R3, =a
MOV R1, #0x54
AND R0, R1, #0xFF
MOV R0, R0, LSL #4

