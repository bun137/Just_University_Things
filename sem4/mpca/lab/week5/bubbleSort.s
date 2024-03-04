.data

array:
	.word 3, 4, 1, 8, 6

length:
	.word 5

	.text

main:
	ldr r1, =array
	ldr r2, =length
	ldr r2, [r2]
	sub r2, r2, #1

outer_loop:
	mov r3, r2
	mov r4, r1

inner_loop:
	ldr r5, [r4]
	ldr r6, [r4, #4]
	cmp r5, r6
	ble no_swap
	str r6, [r4]
	str r5, [r4, #4]

no_swap:
	add  r4, r4, #4
	subs r3, r3, #1
	bne  inner_loop

	subs r2, r2, #1
	bne  outer_loop

exit:
	mov r7, #1
	swi 0
	.end
