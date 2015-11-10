0x0000					GICD_CTLR				RW See the register description Distributor Control Register
0x0004					GICD_TYPER				RO IMPLEMENTATION DEFINED Interrupt Controller Type Register
0x0008					GICD_IIDR				RO IMPLEMENTATION DEFINED Distributor Implementer Identification Register
0x0010					GICD_STATUSR			RW 0x000 00000 Error Reporting Status Register, optional
0x0040					GICD_SETSPI_NSR			WO - Set SPI Register
0x0048					GICD_CLRSPI_NSR			WO - Clear SPI Register
0x0050					GICD_SETSPI_SR			WO - Set SPI, Secure Register
0x0058					GICD_CLRSPI_SR			WO - Clear SPI, Secure Register
0x0080-0x00FC			GICD_IGROUPR<n> 		RW IMPLEMENTATION DEFINED Interrupt Group Registers
0x0100-0x017C			GICD_ISENABLER<n> 		RW IMPLEMENTATION DEFINED Interrupt Set-Enable Registers
0x0180-0x01FC			GICD_ICENABLER<n> 		RW IMPLEMENTATION DEFINED Interrupt Clear-Enable Registers
0x0200-0x027C			GICD_ISPENDR<n> 		RW 0x0000 0000 Interrupt Set-Pending Registers
0x0280-0x02FC			GICD_ICPENDR<n> 		RW 0x0000 0000 Interrupt Clear-Pending Registers
0x0300-0x037C			GICD_ISACTIVER<n> 		RW 0x0000 0000 Interrupt Set-Active Registers
0x0380-0x03FC			GICD_ICACTIVER<n> 		RW 0x0000 0000 Interrupt Clear-Active Registers
0x0400-0x07F8			GICD_IPRIORITYR<n> 		RW 0x0000 0000 Interrupt Priority Registers
0x0800-0x081C			GICD_ITARGETSR<n>	 	RO IMPLEMENTATION DEFINED Interrupt Processor Targets Registers
0x0C00-0x0CFC			GICD_ICFGR<n>			RW IMPLEMENTATION DEFINED Interrupt Configuration Registers
0x0D00-0x0D7C			GICD_IGRPMODR<n>		- 0x0000 0000 Interrupt Group Modifier Registers
0x0E00-0x0EFC			GICD_NSACR<n>			RW 0x0000 0000 Non-secure Access Control Registers
0x0F00					GICD_SGIR				WO - Software Generated Interrupt Register
0x0F10-0x0F1C			GICD_CPENDSGIR<n>		RW 0x0000 0000 SGI Clear-Pending Registers
0x0F20-0x0F2C			GICD_SPENDSGIR<n>		RW 0x0000 0000 SGI Set-Pending Registers
0x6100-0x7FD8			GICD_IROUTER<n>			RW 0x0000 0000 Interrupt Routing Registers



0x0000					GICR_CTLR				RW See the register description Redistributor Control Register
0x0004					GICR_IIDR				RO IMPLEMENTATION DEFINED Implementer Identification Register
0x0008					GICR_TYPER				RO IMPLEMENTATION DEFINED Redistributor Type Register
0x0010					GICR_STATUSR			RW 0x0000 0000 Error Reporting Status Register, optional
0x0014					GICR_WAKER				RW See the register description Redistributor Wake Register
0x0040					GICR_SETLPIR			WO - Set LPI Pending Register
0x0048					GICR_CLRLPIR			WO - Clear LPI Pending Register
0x0070					GICR_PROPBASER			RW - Redistributor Properties Base Address Register
0x0078					GICR_PENDBASER			RW - Redistributor LPI Pending Table Base Address Register
0x00A0					GICR_INVLPIR			WO - Redistributor Invalidate LPI Register
0x00B0					GICR_INVALLR			WO - Redistributor Invalidate All Register
0x00C0					GICR_SYNCR				RO - Redistributor Synchronize Register



0x0000					GICC_CTLR				RW See the register description CPU Interface Control Register
0x0004					GICC_PMR				RW 0x0000 0000 Interrupt Priority Mask Register
0x0008					GICC_BPR				RW 0x0000 000xa Binary Point Register
0x000C					GICC_IAR				RO - Interrupt Acknowledge Register
0x0010					GICC_EOIR				WO - End of Interrupt Register
0x0014					GICC_RPR				RO - Running Priority Register
0x0018					GICC_HPPIR				RO - Highest Priority Pending Interrupt Register
0x001C					GICC_ABPR				RW 0x0000 000xa Aliased Binary Point Register
0x0020					GICC_AIAR				RO - Aliased Interrupt Acknowledge Register
0x0024					GICC_AEOIR				WO - Aliased End of Interrupt Register
0x0028					GICC_AHPPIR				RO - Aliased Highest Priority Pending Interrupt Register
0x002C					GICC_STATUSR			RW 0x0000 0000 Error Reporting Status Register, optional
0x00D0-0x00DC			GICC_APR<n>				RW 0x0000 0000 Active Priorities Registers
0x00E0-0x00EC			GICC_NSAPR<n>			RW 0x0000 0000 Non-secure Active Priorities Registers
0x00FC					GICC_IIDR				RO IMPLEMENTATION DEFINED CPU Interface Identification Register
0x1000					GICC_DIR				WO - Deactivate Interrupt Register


						ICC_AP0R<n>_EL1			RW Interrupt Controller Active Priorities Group 0 Registers, n = 0 - 3
						ICC_AP1R<n>_EL1			RW Interrupt Controller Active Priorities Group 1 Registers, n = 0 - 3
						ICC_ASGI1R_EL1			WO Interrupt Controller Alias Software Generated Interrupt Group 1 Register
						ICC_BPR0_EL1			RW Interrupt Controller Binary Point Register 0
						ICC_BPR1_EL1			RW Interrupt Controller Binary Point Register 1
						ICC_CTLR_EL1			RW Interrupt Controller Control Register (EL1)
						ICC_CTLR_EL3			RW Interrupt Controller Control Register (EL3)
						ICC_DIR_EL1				WO Interrupt Controller Deactivate Interrupt Register
						ICC_EOIR0_EL1			WO Interrupt Controller End Of Interrupt Register 0
						ICC_EOIR1_EL1			WO Interrupt Controller End Of Interrupt Register 1
						ICC_HPPIR0_EL1			RO Interrupt Controller Highest Priority Pending Interrupt Register 0
						ICC_HPPIR1_EL1			RO Interrupt Controller Highest Priority Pending Interrupt Register 1
						ICC_IAR0_EL1			RO Interrupt Controller Interrupt Acknowledge Register 0
						ICC_IAR1_EL1			RO Interrupt Controller Interrupt Acknowledge Register 1
						ICC_IGRPEN0_EL1			RW Interrupt Controller Interrupt Group 0 Enable register
						ICC_IGRPEN1_EL1			RW Interrupt Controller Interrupt Group 1 Enable register
						ICC_IGRPEN1_EL3			RW Interrupt Controller Interrupt Group 1 Enable register (EL3)
						ICC_PMR_EL1				RW Interrupt Controller Interrupt Priority Mask Register
						ICC_RPR_EL1				RO Interrupt Controller Running Priority Register
						ICC_SGI0R_EL1			WO Interrupt Controller Software Generated Interrupt Group 0 Register
						ICC_SGI1R_EL1			WO Interrupt Controller Software Generated Interrupt Group 1 Register
						ICC_SRE_EL1				RW Interrupt Controller System Register Enable register (EL1)
						ICC_SRE_EL2				RW Interrupt Controller System Register Enable register (EL2)
						ICC_SRE_EL3				RW Interrupt Controller System Register Enable register (EL3)
