.data
    a:.word 100000
.equ A, 0x80
.equ B, 0x40
.equ C, 0x20
.equ D, 0x08
.equ E, 0x04
.equ F, 0x02
.equ G, 0x01
.equ P, 0x10

tab:
.word A|B|C|D|E|G 
.word B|C 
.word A|B|F|E|D 
.word A|B|F|C|D 
.word G|F|C 
.word A|G|F|C|D 
.word A|G|E|D|C|F 
.word A|B|C 
.word A|B|C|D|E|F|G 
.word A|B|G|F|C 
.word A|G|E|C|B|F 
.word A|B|C|D|E|F|G|P 
.word A|G|E|D 
.word A|B|C|D|E|G|P 
.word A|G|F|E|D 
.word A|G|F|E 

.text
    MOV r0, #0
    MOV r2, #0
    LDR r8, =tab

    LDR r9, =tab
    ADD r9,r9,#60

again:
    SWI 0x202
    CMP r0, #1
    BEQ loop1
    CMP r0, #2
    BEQ loop2
    B again

loop1:
    MOV r5, #16

back1:
    LDR r1, [r8], #4
    MOV r0, r1
    SWI 0x200
    BL delay
    SUBS r5, r5, #1
    BNE back1
    B again

loop2:
    MOV r5, #16
    

back2:
    LDR r0, [r9],#-4
    SWI 0x200
    BL delay
    SUBS r5, r5, #1
    BNE back2
    B again

delay:
    MOV r4, #64000
delay_loop:
    SUBS r4, r4, #1
    CMP r4, #0
    BNE delay_loop
    BX LR     ; Return to the calling procedure
