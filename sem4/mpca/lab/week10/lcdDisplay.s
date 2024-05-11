.data
    str: .asciz "PES2UG22CS209"
    num: .word 25000

.text
    MOV r0,#1
    MOV r1,#10
    LDR r2,=str
    LDR r8,=num
    LDR r6,[r8]
    MOV r7,#0
    loop:
    SWI 0x204
    BL delay
    CMP r0,#0
    ADD r0,r0,#1
    CMP r0,#0
    BNE loop
    BEQ end


    delay:
    ADD r7,r7,#1
    CMP r7,r6
    BNE delay
    SWI 0x206
    MOV r7,#0
    MOV PC, LR

    end:
    SWI 0x011

