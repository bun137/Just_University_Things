.text
MOV R0, #0
MOV R1, #1000

loop:
CMP R0, #4
BEQ end 
SWI 0x201
ADD R0, R0, #1
MOV R1, #1000

delay:
SUB R1, R1, #1
CMP R1, #0
BNE delay
B loop

end:
SWI 0x011

