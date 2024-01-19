;Write a program to find GCD of two numbers.

MOV R0, #12
MOV R1, #60

LOOP:
CMP R0, R1
SUBGT R0, R0, R1
SUBLT R1, R1, R0
BNE LOOP

