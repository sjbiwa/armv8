/*
 * Copyright (C) 2015 sjbiwa All rights reserved.
 */

#include "common.h"
#include "armv8reg.h"
#include "gicv3reg.h"

void gic_init(void)
{
	int ix;
	uint32_t intr_lines = ioread32(GICD_TYPER);
	tprintf("GICD_TYPER=%08X\n", intr_lines);
	intr_lines = 32 * ((intr_lines & 0x1f) + 1);
	if ( 1021 < intr_lines ) {
		intr_lines = 1021;
	}
	tprintf("INTR_LINES=%d\n", intr_lines);

	/************************************************/
	/*	GIC distributor setting	 (Main Core only)	*/
	/************************************************/
	/* GICD control */
	iowrite32(GICD_CTLR, 0x00000037);
	/* SPI GROUP設定 (secure-group1) */
	for ( ix = 1; ix < ((intr_lines+31)/32); ix++ ) {
		iowrite32n(GICD_IGRPMODR, ix, 0xffffffff);
		iowrite32n(GICD_IGROUPR, ix, 0x00000000);
	}
	/* SPI Clear-Enable */
	for ( ix = 1; ix < ((intr_lines+31)/32); ix++ ) {
		iowrite32n(GICD_ICENABLER, ix, 0xffffffff);
	}
	/* SPI Clear-Pending */
	for ( ix = 1; ix < ((intr_lines+31)/32); ix++ ) {
		iowrite32n(GICD_ICPENDR, ix, 0xffffffff);
	}
	/* SPI Clear-Active */
	for ( ix = 1; ix < ((intr_lines+31)/32); ix++ ) {
		iowrite32n(GICD_ICACTIVER, ix, 0xffffffff);
	}
	/* SPI Priority */
	for ( ix = 8; ix < ((intr_lines+3)/4); ix++ ) {
		iowrite32n(GICD_IPRIORITYR, ix, 0x00000000);
	}
	/* SPI Configuration (Trigger-Mode) */
	for ( ix = 2; ix < ((intr_lines+15)/16); ix++ ) {
		iowrite32n(GICD_ICFGR, ix, 0x00000000);
	}
	/* SPI NonSecure Access Control */
	for ( ix = 2; ix < ((intr_lines+15)/16); ix++ ) {
		iowrite32n(GICD_NSACR, ix, 0x00000000);
	}
	/* SPI Routing (Aff3=CORE0) */
	for ( ix = 32; ix < intr_lines; ix++ ) {
		iowrite32n(GICD_IROUTER, ix, 0x00000000);
	}

	/************************************************/
	/*	GIC Redistributor setting (All Core)		*/
	/************************************************/
	iowrite32(GICR_CTLR, 0x07000000);
	iowrite32(GICR_IGRPMODR0, 0xffffffff);
	iowrite32(GICR_IGROUPR0, 0x00000000);
	iowrite32(GICR_ICENABLER0, 0xffffffff);
	iowrite32(GICR_ICPENDR0, 0xffffffff);
	iowrite32(GICR_ICACTIVER0, 0xffffffff);
	for ( ix = 0; ix < 8; ix++ ) {
		iowrite32n(GICR_IPRIORITYR, ix, 0x00000000);
	}
	iowrite32(GICR_ICFGR0, 0x00000000);
	iowrite32(GICR_ICFGR1, 0x00000000);
	iowrite32(GICR_NSACR, 0x00000000);

	/************************************************/
	/*	GIC CPU interface setting (All Core)		*/
	/************************************************/
	ICC_SRE_EL1_set(0x00000007);
	ICC_CTLR_EL1_set(0x00000000);
	ICC_BPR0_EL1_set(0);
	ICC_BPR1_EL1_set(0);
	ICC_IGRPEN1_EL1_set(0x00000001);
	ICC_PMR_EL1_set(0xff);

	tprintf("GIC init complete:%08X\n", (uint32_t)ICC_SRE_EL1_get());
}
