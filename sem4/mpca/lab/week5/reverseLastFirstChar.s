.data

str:
	.asciz "dog"

	.text
	ldr r0, =str
	bl  swap
	b   done

swap:
	push {r4-r6, lr}
	ldrb r4, [r0]
	ldr  r5, =1
	add  r6, r0, r5
	ldrb r6, [r6]
	strb r6, [r0]
	strb r4, [r0, r5]
	pop  {r4-r6, pc}

done:
	mov r7, #1
	swi 0x011
	.end
