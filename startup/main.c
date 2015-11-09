#include <stdint.h>
#include "common.h"
#include "armv8reg.h"


#define	hword(v)		((uint32_t)((v)>>32))
#define	lword(v)		((uint32_t)(v))

void wait(uint32_t t)
{
	volatile uint32_t count = t;
	while ( 0 < count ) {
		count--;
	}
}

int main()
{
	uint32_t value = 0;
	tprintf_init();

	uint64_t reg;
	uint32_t reg32;
	int32_t ireg32;
	reg32 = VBAR_EL3_get();
	ireg32 = VBAR_EL3_get();
	reg = VBAR_EL3_get();

	reg32 = 0x123400;
	ireg32 = 0x123400;
	reg = 0x123400;

	VBAR_EL3_set(reg32);
	VBAR_EL3_set(ireg32);
	VBAR_EL3_set(reg);

	reg = ID_AA64MMFR0_EL1_get();
	tprintf("ID_AA64MMFR0_EL1=%08X:%08X\n", hword(reg), lword(reg));

	reg = RVBAR_EL3_get();
	tprintf("RVBAR_EL3=%08X:%08X\n", hword(reg), lword(reg));

	reg = VBAR_EL3_get();
	tprintf("VBAR_EL3=%08X:%08X\n", hword(reg), lword(reg));

	for (;;);

	for (;;) {
		tprintf("%08X\n", ioread32(0x0000000080000000L));
		tprintf("%08X\n", ioread32(0x000F000080000010L));
		tprintf("%08X\n", ioread32(0x00F0000080000020L));
		tprintf("%08X\n", ioread32(0x0F00000080000030L));
		tprintf("%08X\n", ioread32(0xF000000080000040L));
		tprintf("%08X\n", ioread32(0x0000000080000050L));
	}
	for (;;) {
		tprintf("Hello world\n");
		tprintf("%d %d %d %d %d\n", sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long));
		tprintf("%d %d %d\n", sizeof(void*), sizeof(float), sizeof(double));
		iowrite32(SYSTEM_BASE+0x0008,  value);
		value++;
		wait(100000);
	}
	return 0;
}

