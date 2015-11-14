#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdint.h>

#define	iowrite8n(addr, idx, value)			do { *((volatile uint8_t*)(addr)+idx) = (value); } while (0)
#define	iowrite16n(addr, idx, value)		do { *((volatile uint16_t*)(addr)+idx) = (value); } while (0)
#define	iowrite32n(addr, idx, value)		do { *((volatile uint32_t*)(addr)+idx) = (value); } while (0)
#define	iowrite64n(addr, idx, value)		do { *((volatile uint64_t*)(addr)+idx) = (value); } while (0)
#define	ioread8n(addr, idx)					( *((volatile uint32_t*)(addr)+idx) )
#define	ioread16n(addr, idx)				( *((volatile uint32_t*)(addr)+idx) )
#define	ioread32n(addr, idx)				( *((volatile uint32_t*)(addr)+idx) )
#define	ioread64n(addr, idx)				( *((volatile uint32_t*)(addr)+idx) )

#define	iowrite8(addr, value)				iowrite8n(addr,0,value)
#define	iowrite16(addr, value)				iowrite16n(addr,0,value)
#define	iowrite32(addr, value)				iowrite32n(addr,0,value)
#define	iowrite64(addr, value)				iowrite64n(addr,0,value)
#define	ioread8(addr)						ioread8n(addr,0)
#define	ioread16(addr)						ioread16n(addr,0)
#define	ioread32(addr)						ioread32n(addr,0)
#define	ioread64(addr)						ioread64n(addr,0)

#endif /* STARTUP_COMMON_H_ */
