/*
 * Copyright (C) 2015 sjbiwa All rights reserved.
 */

#ifndef _GICV3REG_H_
#define	_GICV3REG_H_

#define	GIC_GICD_BASE			(0x80000000u)
#define	GIC_GICR_BASE			(0x80000000u)
#define	GIC_GICC_BASE			(0x80000000u)

#define	GICD_CTLR				(GIC_GICD_BASE+0x0000u)					/* RW See the register description Distributor Control Register */
#define	GICD_TYPER				(GIC_GICD_BASE+0x0004u)					/* RO IMPLEMENTATION DEFINED Interrupt Controller Type Register */
#define	GICD_IIDR				(GIC_GICD_BASE+0x0008u)					/* RO IMPLEMENTATION DEFINED Distributor Implementer Identification Register */
#define	GICD_STATUSR			(GIC_GICD_BASE+0x0010u)					/* RW 0x000 00000 Error Reporting Status Register, optional */
#define	GICD_SETSPI_NSR			(GIC_GICD_BASE+0x0040u)					/* WO - Set SPI Register */
#define	GICD_CLRSPI_NSR			(GIC_GICD_BASE+0x0048u)					/* WO - Clear SPI Register */
#define	GICD_SETSPI_SR			(GIC_GICD_BASE+0x0050u)					/* WO - Set SPI, Secure Register */
#define	GICD_CLRSPI_SR			(GIC_GICD_BASE+0x0058u)					/* WO - Clear SPI, Secure Register */
#define	GICD_IGROUPR	 		(GIC_GICD_BASE+0x0080u)					/* RW IMPLEMENTATION DEFINED Interrupt Group Registers */
#define	GICD_ISENABLER	 		(GIC_GICD_BASE+0x0100u)					/* RW IMPLEMENTATION DEFINED Interrupt Set-Enable Registers */
#define	GICD_ICENABLER	 		(GIC_GICD_BASE+0x0180u)					/* RW IMPLEMENTATION DEFINED Interrupt Clear-Enable Registers */
#define	GICD_ISPENDR	 		(GIC_GICD_BASE+0x0200u)					/* RW 0x0000 0000 Interrupt Set-Pending Registers */
#define	GICD_ICPENDR	 		(GIC_GICD_BASE+0x0280u)					/* RW 0x0000 0000 Interrupt Clear-Pending Registers */
#define	GICD_ISACTIVER	 		(GIC_GICD_BASE+0x0300u)					/* RW 0x0000 0000 Interrupt Set-Active Registers */
#define	GICD_ICACTIVER	 		(GIC_GICD_BASE+0x0380u)					/* RW 0x0000 0000 Interrupt Clear-Active Registers */
#define	GICD_IPRIORITYR	 		(GIC_GICD_BASE+0x0400u)					/* RW 0x0000 0000 Interrupt Priority Registers */
#define	GICD_ITARGETSR		 	(GIC_GICD_BASE+0x0800u)					/* RO IMPLEMENTATION DEFINED Interrupt Processor Targets Registers */
#define	GICD_ICFGR				(GIC_GICD_BASE+0x0C00u)					/* RW IMPLEMENTATION DEFINED Interrupt Configuration Registers */
#define	GICD_IGRPMODR			(GIC_GICD_BASE+0x0D00u)					/* - 0x0000 0000 Interrupt Group Modifier Registers */
#define	GICD_NSACR				(GIC_GICD_BASE+0x0E00u)					/* RW 0x0000 0000 Non-secure Access Control Registers */
#define	GICD_SGIR				(GIC_GICD_BASE+0x0F00u)					/* WO - Software Generated Interrupt Register */
#define	GICD_CPENDSGIR			(GIC_GICD_BASE+0x0F10u)					/* RW 0x0000 0000 SGI Clear-Pending Registers */
#define	GICD_SPENDSGIR			(GIC_GICD_BASE+0x0F20u)					/* RW 0x0000 0000 SGI Set-Pending Registers */
#define	GICD_IROUTER			(GIC_GICD_BASE+0x6100u)					/* RW 0x0000 0000 Interrupt Routing Registers */

#define	GICR_CTLR				(GIC_GICR_BASE+0x0000u)					/* RW See the register description Redistributor Control Register */
#define	GICR_IIDR				(GIC_GICR_BASE+0x0004u)					/* RO IMPLEMENTATION DEFINED Implementer Identification Register */
#define	GICR_TYPER				(GIC_GICR_BASE+0x0008u)					/* RO IMPLEMENTATION DEFINED Redistributor Type Register */
#define	GICR_STATUSR			(GIC_GICR_BASE+0x0010u)					/* RW 0x0000 0000 Error Reporting Status Register, optional */
#define	GICR_WAKER				(GIC_GICR_BASE+0x0014u)					/* RW See the register description Redistributor Wake Register */
#define	GICR_SETLPIR			(GIC_GICR_BASE+0x0040u)					/* WO - Set LPI Pending Register */
#define	GICR_CLRLPIR			(GIC_GICR_BASE+0x0048u)					/* WO - Clear LPI Pending Register */
#define	GICR_PROPBASER			(GIC_GICR_BASE+0x0070u)					/* RW - Redistributor Properties Base Address Register */
#define	GICR_PENDBASER			(GIC_GICR_BASE+0x0078u)					/* RW - Redistributor LPI Pending Table Base Address Register */
#define	GICR_INVLPIR			(GIC_GICR_BASE+0x00A0u)					/* WO - Redistributor Invalidate LPI Register */
#define	GICR_INVALLR			(GIC_GICR_BASE+0x00B0u)					/* WO - Redistributor Invalidate All Register */
#define	GICR_SYNCR				(GIC_GICR_BASE+0x00C0u)					/* RO - Redistributor Synchronize Register */

#define	GICC_CTLR				(GIC_GICC_BASE+0x0000u)					/* RW See the register description CPU Interface Control Register */
#define	GICC_PMR				(GIC_GICC_BASE+0x0004u)					/* RW 0x0000 0000 Interrupt Priority Mask Register */
#define	GICC_BPR				(GIC_GICC_BASE+0x0008u)					/* RW 0x0000 000xa Binary Point Register */
#define	GICC_IAR				(GIC_GICC_BASE+0x000Cu)					/* RO - Interrupt Acknowledge Register */
#define	GICC_EOIR				(GIC_GICC_BASE+0x0010u)					/* WO - End of Interrupt Register */
#define	GICC_RPR				(GIC_GICC_BASE+0x0014u)					/* RO - Running Priority Register */
#define	GICC_HPPIR				(GIC_GICC_BASE+0x0018u)					/* RO - Highest Priority Pending Interrupt Register */
#define	GICC_ABPR				(GIC_GICC_BASE+0x001Cu)					/* RW 0x0000 000xa Aliased Binary Point Register */
#define	GICC_AIAR				(GIC_GICC_BASE+0x0020u)					/* RO - Aliased Interrupt Acknowledge Register */
#define	GICC_AEOIR				(GIC_GICC_BASE+0x0024u)					/* WO - Aliased End of Interrupt Register */
#define	GICC_AHPPIR				(GIC_GICC_BASE+0x0028u)					/* RO - Aliased Highest Priority Pending Interrupt Register */
#define	GICC_STATUSR			(GIC_GICC_BASE+0x002Cu)					/* RW 0x0000 0000 Error Reporting Status Register, optional */
#define	GICC_APR				(GIC_GICC_BASE+0x00D0u)					/* RW 0x0000 0000 Active Priorities Registers */
#define	GICC_NSAPR				(GIC_GICC_BASE+0x00E0u)					/* RW 0x0000 0000 Non-secure Active Priorities Registers */
#define	GICC_IIDR				(GIC_GICC_BASE+0x00FCu)					/* RO IMPLEMENTATION DEFINED CPU Interface Identification Register */
#define	GICC_DIR				(GIC_GICC_BASE+0x1000u)					/* WO - Deactivate Interrupt Register */


#define ICC_AP0R_EL1_get(n)			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_AP0R" #n "_EL1":"=r"(_reg_)::"memory");_reg_;})	/* RW Interrupt Controller Active Priorities Group 0 Registers, n = 0 - 3 */
#define ICC_AP0R_EL1_set(n,v)		__asm__ volatile ("MSR ICC_AP0R" #n "_EL1, %0"::"r"(v):"memory")								/* RW Interrupt Controller Active Priorities Group 0 Registers, n = 0 - 3 */
#define ICC_AP1R_EL1_get(n)			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_AP1R" #n "_EL1":"=r"(_reg_)::"memory");_reg_;})	/* RW Interrupt Controller Active Priorities Group 1 Registers, n = 0 - 3 */
#define ICC_AP1R_EL1_set(n,v)		__asm__ volatile ("MSR ICC_AP1R" #n "_EL1, %0"::"r"(v):"memory")								/* RW Interrupt Controller Active Priorities Group 1 Registers, n = 0 - 3 */
#define ICC_ASGI1R_EL1_set(v)		__asm__ volatile ("MSR ICC_ASGI1R_EL1, %0"::"r"(v):"memory")									/* WO Interrupt Controller Alias Software Generated Interrupt Group 1 Register */
#define ICC_BPR0_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_BPR0_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller Binary Point Register 0 */
#define ICC_BPR0_EL1_set(v)			__asm__ volatile ("MSR ICC_BPR0_EL1, %0"::"r"(v):"memory")										/* RW Interrupt Controller Binary Point Register 0 */
#define ICC_BPR1_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_BPR1_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller Binary Point Register 1 */
#define ICC_BPR1_EL1_set(v)			__asm__ volatile ("MSR ICC_BPR1_EL1, %0"::"r"(v):"memory")										/* RW Interrupt Controller Binary Point Register 1 */
#define ICC_CTLR_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_CTLR_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller Control Register (EL1) */
#define ICC_CTLR_EL1_set(v)			__asm__ volatile ("MSR ICC_CTLR_EL1, %0"::"r"(v):"memory")										/* RW Interrupt Controller Control Register (EL1) */
#define ICC_CTLR_EL3_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_CTLR_EL3":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller Control Register (EL3) */
#define ICC_CTLR_EL3_set(v)			__asm__ volatile ("MSR ICC_CTLR_EL3, %0"::"r"(v):"memory")										/* RW Interrupt Controller Control Register (EL3) */
#define ICC_DIR_EL1_set(v)			__asm__ volatile ("MSR ICC_DIR_EL1, %0"::"r"(v):"memory")										/* WO Interrupt Controller Deactivate Interrupt Register */
#define ICC_EOIR0_EL1_set(v)		__asm__ volatile ("MSR ICC_EOIR0_EL1, %0"::"r"(v):"memory")										/* WO Interrupt Controller End Of Interrupt Register 0 */
#define ICC_EOIR1_EL1_set(v)		__asm__ volatile ("MSR ICC_EOIR1_EL1, %0"::"r"(v):"memory")										/* WO Interrupt Controller End Of Interrupt Register 1 */
#define ICC_HPPIR0_EL1_get()		({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_HPPIR0_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RO Interrupt Controller Highest Priority Pending Interrupt Register 0 */
#define ICC_HPPIR1_EL1_get()		({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_HPPIR1_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RO Interrupt Controller Highest Priority Pending Interrupt Register 1 */
#define ICC_IAR0_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_IAR0_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RO Interrupt Controller Interrupt Acknowledge Register 0 */
#define ICC_IAR1_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_IAR1_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RO Interrupt Controller Interrupt Acknowledge Register 1 */
#define ICC_IGRPEN0_EL1_get()		({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_IGRPEN0_EL1":"=r"(_reg_)::"memory");_reg_;})	/* RW Interrupt Controller Interrupt Group 0 Enable register */
#define ICC_IGRPEN0_EL1_set(v)		__asm__ volatile ("MSR ICC_IGRPEN0_EL1, %0"::"r"(v):"memory")									/* RW Interrupt Controller Interrupt Group 0 Enable register */
#define ICC_IGRPEN1_EL1_get()		({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_IGRPEN1_EL1":"=r"(_reg_)::"memory");_reg_;})	/* RW Interrupt Controller Interrupt Group 1 Enable register */
#define ICC_IGRPEN1_EL1_set(v)		__asm__ volatile ("MSR ICC_IGRPEN1_EL1, %0"::"r"(v):"memory")									/* RW Interrupt Controller Interrupt Group 1 Enable register */
#define ICC_IGRPEN1_EL3_get()		({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_IGRPEN1_EL3":"=r"(_reg_)::"memory");_reg_;})	/* RW Interrupt Controller Interrupt Group 1 Enable register (EL3) */
#define ICC_IGRPEN1_EL3_set(v)		__asm__ volatile ("MSR ICC_IGRPEN1_EL3, %0"::"r"(v):"memory")									/* RW Interrupt Controller Interrupt Group 1 Enable register (EL3) */
#define ICC_PMR_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_PMR_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller Interrupt Priority Mask Register */
#define ICC_PMR_EL1_set(v)			__asm__ volatile ("MSR ICC_PMR_EL1, %0"::"r"(v):"memory")										/* RW Interrupt Controller Interrupt Priority Mask Register */
#define ICC_RPR_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_RPR_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RO Interrupt Controller Running Priority Register */
#define ICC_SGI0R_EL1_set(v)		__asm__ volatile ("MSR ICC_SGI0R_EL1, %0"::"r"(v):"memory")										/* WO Interrupt Controller Software Generated Interrupt Group 0 Register */
#define ICC_SGI1R_EL1_set(v)		__asm__ volatile ("MSR ICC_SGI1R_EL1, %0"::"r"(v):"memory")										/* WO Interrupt Controller Software Generated Interrupt Group 1 Register */
#define ICC_SRE_EL1_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_SRE_EL1":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller System Register Enable register (EL1) */
#define ICC_SRE_EL1_set(v)			__asm__ volatile ("MSR ICC_SRE_EL1, %0"::"r"(v):"memory")										/* RW Interrupt Controller System Register Enable register (EL1) */
#define ICC_SRE_EL2_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_SRE_EL2":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller System Register Enable register (EL2) */
#define ICC_SRE_EL2_set(v)			__asm__ volatile ("MSR ICC_SRE_EL2, %0"::"r"(v):"memory")										/* RW Interrupt Controller System Register Enable register (EL2) */
#define ICC_SRE_EL3_get()			({uint64_t _reg_;__asm__ volatile ("MRS %0, ICC_SRE_EL3":"=r"(_reg_)::"memory");_reg_;})		/* RW Interrupt Controller System Register Enable register (EL3) */
#define ICC_SRE_EL3_set(v)			__asm__ volatile ("MSR ICC_SRE_EL3, %0"::"r"(v):"memory")										/* RW Interrupt Controller System Register Enable register (EL3) */

#endif