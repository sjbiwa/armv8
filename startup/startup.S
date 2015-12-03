#include "armv8reg.h"
	.section .startup
	.align	2
	.global	_startup
	.type	_startup, %function
_startup:
	/* check core number */
	MPIDR_EL1_get(x0)
	and		x0, x0, #0x0f
	cmp		x0, xzr
	bne		end_loop

	/* disable interrupt */
	DAIFSet_seti(0xf)

	/* SP is ELx */
	SPSel_seti(1)

	/* initialize stack */
	adr		x0, stack_el3_base
	mov		sp, x0

	adr		x0, _exc_vector
	VBAR_EL3_set(x0)
	VBAR_EL2_set(x0)

	ldr		x0, =0x00000400
	SCR_EL3_set(x0)
	ldr		x0, =0x00000400
	HCR_EL2_set(x0)
	CPTR_EL3_set(xzr)
	CPTR_EL2_set(xzr)

	/* init GIC */
	mov		x0, #0x0000000f
	MSR S3_6_C12_C12_5, x0	// msr		ICC_SRE_EL3, x0
	//MSR S3_4_C12_C9_5, x0	//msr		ICC_SRE_EL2, x0
	mov		x0, #0x0
	MSR S3_6_C12_C12_4, x0	// 	msr		ICC_CTLR_EL3, x0
	//mov		x0, #0x3
	//msr		ICC_IGRPEN1_EL3, x0

	adr		x0, entry_el1
	ELR_EL3_set(x0)
	ldr		x0, =0x000003C5
	SPSR_EL3_set(x0)
	/* goto EL1 entry_el1 */
	eret

/***************************************/
/* EL1での起動エントリ                 */
/***************************************/
entry_el1:
	/* disable interrupt */
	DAIFSet_seti(0xf)
	/* SP is ELx */
	SPSel_seti(1)
	/* EL1 stack */
	adr		x0, stack_base
	mov		sp, x0
	/* exception vector base */
	adr		x0, _exc_vector
	VBAR_EL1_set(x0)
	/* FPU/SIMD enable */
	ldr		x0, =0x00300000
	CPACR_EL1_set(x0)

	/* BSS clear */
	ldr		x1, =__bss_start
	ldr		x2, =__bss_end
bss_cp:
	cmp		x1, x2
	bhs		end_bss
	str		xzr, [x1], #8
	b		bss_cp

end_bss:
	bl		main
end_loop:
	wfe
	b		end_loop

.macro VECTOR_ENTRY func
	.align	7
	b		\func
.endm
	.section .vector
	.global	_exc_vector
	.type	_exc_vector, %function
_exc_vector:
	.align	11
	/**/
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	/**/
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	/**/
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	/**/
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler
	VECTOR_ENTRY	exc_handler

exc_handler:
	stp		 x0,  x1, [sp, #-16]!
	stp		 x2,  x3, [sp, #-16]!
	stp		 x4,  x5, [sp, #-16]!
	stp		 x6,  x7, [sp, #-16]!
	stp		 x8,  x9, [sp, #-16]!
	stp		x10, x11, [sp, #-16]!
	stp		x12, x13, [sp, #-16]!
	stp		x14, x15, [sp, #-16]!
	stp		x16, x17, [sp, #-16]!
	stp		x18, x30, [sp, #-16]!

	bl		c_exc_handler

	ldp		x18, x30, [sp], #16
	ldp		x16, x17, [sp], #16
	ldp		x14, x15, [sp], #16
	ldp		x12, x13, [sp], #16
	ldp		x10, x11, [sp], #16
	ldp		 x8,  x9, [sp], #16
	ldp		 x6,  x7, [sp], #16
	ldp		 x4,  x5, [sp], #16
	ldp		 x2,  x3, [sp], #16
	ldp		 x0,  x1, [sp], #16
	eret

	.section .stack
	.balign 16
stack_bt:
	.space	65536
stack_base:
	.balign 16
stack_el3_bt:
	.space	65536
stack_el3_base:
