#include <stdint.h>
#include "common.h"
#include "utils.h"
#include "armv8reg.h"
#include "gicv3reg.h"

#define	hword(v)		((uint32_t)((v)>>32))
#define	lword(v)		((uint32_t)(v))

void wait(uint32_t t)
{
	volatile uint32_t count = t;
	while ( 0 < count ) {
		count--;
	}
}

void c_exc_handler()
{
	tprintf("c_exc_handler:%08X:%08X\n", (uint32_t)CurrentEL_get(), (uint32_t)ESR_EL1_get());
}

volatile uint32_t t_value1 = 0;
volatile uint32_t t_value2 = 0;

void main_entry()
{
	tprintf("entry_el1\n");
	register uint32_t value1 = 0;
	register uint32_t value2 = 0;


	tprintf("CNTFRQ_EL0:%08X\n", CNTFRQ_EL0_get());
	tprintf("CNTP_CTL_EL0:%08X\n", CNTP_CTL_EL0_get());
	tprintf("CNTP_CVAL_EL0:%08X\n", CNTP_CVAL_EL0_get());
	tprintf("CNTP_TVAL_EL0:%08X\n", CNTP_TVAL_EL0_get());
	tprintf("CNTPCT_EL0:%08X\n", CNTPCT_EL0_get());

	CNTP_CTL_EL0_set(0x07);

	if (0) {
		for (;;) {
			uint64_t val1, val2;
			val1 = CNTP_TVAL_EL0_get();
			val2 = CNTPCT_EL0_get();
			tprintf("CNTP_TVAL_EL0:%08X%08X\n", hword(val1), lword(val1));
			tprintf("CNTPCT_EL0:%08X%08X\n",  hword(val2), lword(val2));
			wait(5000000);
		}
	}

	for (;;) {
		iowrite32(SYSTEM_BASE+0x0008,  value1);
		value1 += 1; t_value1 += 1;
		value2 += 3; t_value2 += 3;
		wait(500000);
		tprintf("LED:%08X\n", value1);
		__asm volatile ("SVC #15":::"memory");
		if ( (value1 != t_value1) || (value2 != t_value2) ) {
			tprintf("ERROR\n");
			for (;;);
		}
		tprintf("main_entry:%08X\n", (uint32_t)CurrentEL_get());
	}
}

int main()
{
	extern void return_el1();

	tprintf_init();
	tprintf("Hello world\n");

	main_entry();

	return 0;
}

