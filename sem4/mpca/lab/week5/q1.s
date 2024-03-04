.data

A:
	.word 2, 4, 6, 8
	.word 1, 3, 5, 7
	.word 10, 12, 14, 16
	.word 11, 13, 15, 17

B:
	.word 1, 1, 1, 1
	.word 1, 0, 1, 0
	.word 0, 1, 0, 1
	.word 1, 1, 1, 1

C:
	.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

	.text
	mov r0, #4
	mov r1, #4
	mov r2, #4
	bl  multiply
	b   done

multiply:
	push {r4-r10, lr}
	ldr  r4, =A
	ldr  r5, =B
	ldr  r6, =C
	mov  r7, #0

outer:
	mov r8, #0

inner:
	mov r9, #0
	mov r10, #0

sum:
	ldr r11, [r4, r7, lsl #2]
	ldr r12, [r5, r8, lsl #2]
	mul r11, r11, r12
	add r9, r9, r11
	add r10, r10, #1
	cmp r10, r2
	bne sum
	str r9, [r6, r7, lsl #2]
	add r8, r8, #1
	cmp r8, r1
	bne inner
	add r7, r7, #1
	cmp r7, r0
	bne outer
	pop {r4-r10, pc}

done:
	mov r7, #1
	swi 0x011
	.end
