#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdint.h>
#include <stddef.h>
#include "link.h"

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

/* OS固有定義マクロ */
#define	OSAPI
#define	OSAPISTUB

#ifndef NULL
#define	NULL			(0)
#endif

/* ユーティリティマクロ */
#define	arrayof(a)			(sizeof(a)/sizeof((a)[0]))
#define	containerof(ptr, type, member) ({ const typeof(((type *)0)->member) *__mptr = (ptr);(type *)((char*)__mptr-offsetof(type,member));})
#define	ioset32(a,d)		iowrite32(a,ioread32(a)|(d))
#define	ioclr32(a,d)		iowrite32(a,ioread32(a)&(~(d)))
#define	ioset32mask(a,d,m)	iowrite32(a,(ioread32(a)&~(m))|(d))


#ifndef MIN
#define	MIN(a,b)			((a)<(b)?(a):(b))
#endif
#ifndef MAX
#define	MAX(a,b)			((a)>(b)?(a):(b))
#endif

/* アドレスアラインメント演算用マクロ */
#define	PRE_ALIGN_BY(x,n)		((void*)((PtrInt_t)(x) & ~((PtrInt_t)((n)-1))))
#define	POST_ALIGN_BY(x,n)		((void*)(((PtrInt_t)(x)+(PtrInt_t)((n)-1)) & ~((PtrInt_t)((n)-1))))

#define	PTRVAR(x)				((uint8_t*)(x)) /* ポインタ演算用 (バイトアドレス型に変換) */

/* メモリサイズ用 */
#define	SIZE_PRE_ALIGN_BY(x,n)	((MemSize_t)((PtrInt_t)(x) & ~((PtrInt_t)((n)-1))))
#define	SIZE_POST_ALIGN_BY(x,n)	((MemSize_t)(((PtrInt_t)(x)+(PtrInt_t)((n)-1)) & ~((PtrInt_t)((n)-1))))

typedef	uint64_t	PtrInt_t;
typedef	uint64_t	MemSize_t;

extern char	__heap_start;
extern void sys_malloc_init(void);
extern void sys_malloc_add_block(void* start_addr, MemSize_t size);
extern void* __sys_malloc(MemSize_t size);
extern void __sys_free(void* ptr);
extern void _memset(void* ptr, uint32_t val, uint32_t len);
extern void _memcpy(void* dst, void* src, uint32_t len);

extern void gic_init(void);

#endif /* STARTUP_COMMON_H_ */
