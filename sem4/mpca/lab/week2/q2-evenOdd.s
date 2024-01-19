;Write an ALP using ARM instruction set to check if a number stored in a register is even
;or odd. If even, store 00 in R0, else store FF in R0

MOV R1, #4
AND R3, R1, #1
CMP R3, #0
BEQ EVEN
MOV R0, #0xFF
B END
EVEN:
MOV R0, #0x00
END:


