#include "armv8reg.h"
	.section .startup
	.align	2
	.global	_startup
	.type	_startup, %function
_startup:
	/* disable interrupt */
	DAIFSet_seti(0xf)
	//msr		DAIFset, #0xf

	/* initialize stack */
	adr		x0, stack_base
	mov		sp, x0

	/* BSS clear */
	eor		x0, x0, x0
	ldr		x1, =__bss_start
	ldr		x2, =__bss_end
bss_cp:
	cmp		x1, x2
	bhs		end_bss
	str		x0, [x1], #8
	b		bss_cp

end_bss:
	bl		main

	.section .stack
	.balign 16
stack_bt:
	.space	65536
stack_base:
