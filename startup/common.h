/*
 * common.h
 *
 *  Created on: 2015/10/18
 *      Author: biwa
 */

#ifndef STARTUP_COMMON_H_
#define STARTUP_COMMON_H_

#define	SYSTEM_BASE					0x001C010000

#define	iowrite32(addr, value)		do { *((volatile uint32_t*)(addr)) = (value); } while (0)
#define	ioread32(addr)				( *((volatile uint32_t*)(addr)) )


extern void tprintf_init(void);
extern int tprintf(char* fmt, ...);

#endif /* STARTUP_COMMON_H_ */
