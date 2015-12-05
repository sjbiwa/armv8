#include <stdint.h>
#include <string.h>
#include "common.h"
#include "utils.h"
#include "armv8reg.h"
#include "gicv3reg.h"

#define	hword(v)		((uint32_t)((uint64_t)(v)>>32))
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
	tprintf("ELR:%08X SPSR:%08X\n",(uint32_t)ELR_EL1_get(), (uint32_t)SPSR_EL1_get());
	for (;;);
}

volatile uint32_t t_value1 = 0;
volatile uint32_t t_value2 = 0;

void main_entry()
{
	tprintf("entry_el1\n");
	register uint32_t value1 = 0;
	register uint32_t value2 = 0;

	tprintf("entry step:EL=%08X\n", CurrentEL_get());

	tprintf("CNTFRQ_EL0:%08X\n", CNTFRQ_EL0_get());
	tprintf("CNTP_CTL_EL0:%08X\n", CNTP_CTL_EL0_get());
	tprintf("CNTP_CVAL_EL0:%08X\n", CNTP_CVAL_EL0_get());
	tprintf("CNTP_TVAL_EL0:%08X\n", CNTP_TVAL_EL0_get());
	tprintf("CNTPCT_EL0:%08X\n", CNTPCT_EL0_get());
	tprintf("MPIDR_EL1:%08X\n", MPIDR_EL1_get());

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

	tprintf("sys_malloc_init\n");
	sys_malloc_init();
	sys_malloc_add_block((void*)0x80100000/*&__heap_start*/, 0x1000000);
	tprintf("sys_malloc_init done\n");

	gic_init();
	timer_test();

	for (;;);
#define	PTR_MAX		100
static	void* ptr[PTR_MAX];
	MemSize_t size = 256;
	int32_t idx = 0;

	for (;;) {
		ptr[idx] =  __sys_malloc(size);
		tprintf("__sys_malloc:%d:%08X:%08X\n", idx, hword(ptr[idx]), lword(ptr[idx]));
		_memset(ptr[idx], 0x45, size);
		idx++;
		wait(500000);

		if ( idx == PTR_MAX ) {
			/* free */
			for ( idx=PTR_MAX/2; 0<=idx; idx--) {
				tprintf("free:low:%d:%08X:%08X\n", idx, hword(ptr[idx]), lword(ptr[idx]));
				__sys_free(ptr[idx]);
			}
			for ( idx=PTR_MAX/2+1; idx<PTR_MAX; idx++) {
				tprintf("free:high:%d:%08X:%08X\n", idx, hword(ptr[idx]), lword(ptr[idx]));
				__sys_free(ptr[idx]);
			}
			idx = 0;
		}

		size += 10;
		if ( 4096 < size ) {
			size = 256;
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
	tprintf_init();
	main_entry();

	return 0;
}

