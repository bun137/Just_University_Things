;Write a program to find the factorial of a given number
;Algorithm
;1.The number n is to be saved in R0
;2.Let R1=1
;3.Multiply contents of R0 and R1
;Save the result in R1
;4.Subtract the contents of R0 by 1 to calculate n-1 
;5.Check if the content of R0 is one
;6.Repeat steps 3 to 5 till R0 reaches one
;9.End execution when R0=1

MOV R0, #5
MOV R1, #1
CMP R0, #1
BLE END

LOOP:  
MUL R1, R0, R1
SUB R0, R0, #1
CMP R0, #1
BGT LOOP

END:
MOV R0, R1
