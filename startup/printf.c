#include <stdarg.h>
#include <stdint.h>
#include <stdbool.h>
#include "common.h"

#define	UART_BASE			0x001C090000

#define	UARTDR				(0x000)				/* Data Register */
#define	UARTRSR				(0x004)				/* Receive Status Register */
#define	UARTECR				(0x004)				/* Error Clear Register */
#define	UARTFR				(0x018)				/* Flag Register */
#define	UARTILPR			(0x020)				/* IrDA Low-Power Counter Register */
#define	UARTIBRD			(0x024)				/* Integer Baud Rate Register */
#define	UARTFBRD			(0x028)				/* Fractional Baud Rate Register */
#define	UARTLCR_H			(0x02C)				/* Line Control Register */
#define	UARTCR				(0x030)				/* Control Register */
#define	UARTIFLS			(0x034)				/* Interrupt FIFO Level Select Register */
#define	UARTIMSC			(0x038)				/* Interrupt Mask Set/Clear Register */
#define	UARTRIS				(0x03C)				/* Raw Interrupt Status Register */
#define	UARTMIS				(0x040)				/* Masked Interrupt Status Register */
#define	UARTICR				(0x044)				/* Interrupt Clear Register */
#define	UARTDMACR			(0x048)				/* DMA Control Register */
#define	UARTPeriphID0		(0xFE0)				/* UARTPeriphID0 Register */
#define	UARTPeriphID1		(0xFE4)				/* UARTPeriphID1 Register */
#define	UARTPeriphID2		(0xFE8)				/* UARTPeriphID2 Register */
#define	UARTPeriphID3		(0xFEC)				/* UARTPeriphID3 Register */
#define	UARTPCellID0		(0xFF0)				/* UARTPCellID0 Register */
#define	UARTPCellID1		(0xFF4)				/* UARTPCellID1 Register */
#define	UARTPCellID2		(0xFF8)				/* UARTPCellID2 Register */
#define	UARTPCellID3		(0xFFC)				/* UARTPCellID3 Register */


static int vtsprintf(char* buff,char* fmt,va_list arg);

static int tsprintf_string(char* ,char* );
static int tsprintf_char(int ,char* );
static int tsprintf_decimal(signed long,char* ,int ,int );
static int tsprintf_hexadecimal(unsigned long ,char* ,int ,int ,int );

static int
vtsprintf(char* buff,char* fmt,va_list arg){
	int len;
	int size;
	int zeroflag,width;

	size = 0;
	len = 0;

	while(*fmt){
		if(*fmt=='%'){		/* % に関する処理 */
			zeroflag = width = 0;
			fmt++;

			if (*fmt == '0'){
				fmt++;
				zeroflag = 1;
			}
			if ((*fmt >= '0') && (*fmt <= '9')){
				width = *(fmt++) - '0';
			}

			/* printf ("zerof = %d,width = %d\n",zeroflag,width); */

			switch(*fmt){
			case 'd':		/* 10進数 */
				size = tsprintf_decimal(va_arg(arg,signed long),buff,zeroflag,width);
				break;
			case 'x':		/* 16進数 0-f */
				size = tsprintf_hexadecimal(va_arg(arg,unsigned long),buff,0,zeroflag,width);
				break;
			case 'X':		/* 16進数 0-F */
				size = tsprintf_hexadecimal(va_arg(arg,unsigned long),buff,1,zeroflag,width);
				break;
			case 'c':		/* キャラクター */
				size = tsprintf_char(va_arg(arg,int),buff);
				break;
			case 's':		/* ASCIIZ文字列 */
				size = tsprintf_string(va_arg(arg,char*),buff);
				break;
			default:		/* コントロールコード以外の文字 */
				/* %%(%に対応)はここで対応される */
				len++;
				*(buff++) = *fmt;
				break;
			}
			len += size;
			buff += size;
			fmt++;
		} else {
			*(buff++) = *(fmt++);
			len++;
		}
	}

	*buff = '\0';		/* 終端を入れる */

	va_end(arg);
	return (len);
}




/*
  数値 => 10進文字列変換
*/
static int
tsprintf_decimal(signed long val,char* buff,int zf,int wd){
	int i;
	char tmp[10];
	char* ptmp = tmp + 10;
	int len = 0;
	int minus = 0;

	if (!val){		/* 指定値が0の場合 */
		*(ptmp--) = '0';
		len++;
	} else {
		/* マイナスの値の場合には2の補数を取る */
		if (val < 0){
			val = ~val;
			val++;
			minus = 1;
		}
		while (val){
			/* バッファアンダーフロー対策 */
			if (len >= 8){
				break;
			}

			*ptmp = (val % 10) + '0';
			val /= 10;
			ptmp--;
			len++;
		}

	}

	/* 符号、桁合わせに関する処理 */
	if (zf){
		if (minus){
			wd--;
		}
		while (len < wd){
			*(ptmp--) =  '0';
			len++;
		}
		if (minus){
			*(ptmp--) = '-';
			len++;
		}
	} else {
		if (minus){
			*(ptmp--) = '-';
			len++;
		}
		while (len < wd){
			*(ptmp--) =  ' ';
			len++;
		}
	}

	/* 生成文字列のバッファコピー */
	for (i=0;i<len;i++){
		*(buff++) = *(++ptmp);
	}

	return (len);
}

/*
  数値 => 16進文字列変換
*/
static int
tsprintf_hexadecimal(unsigned long val,char* buff,
								int capital,int zf,int wd){
	int i;
	char tmp[10];
	char* ptmp = tmp + 10;
	int len = 0;
	char str_a;

	/* A～Fを大文字にするか小文字にするか切り替える */
	if (capital){
		str_a = 'A';
	} else {
		str_a = 'a';
	}

	if (!val){		/* 指定値が0の場合 */
		*(ptmp--) = '0';
		len++;
	} else {
		while (val){
			/* バッファアンダーフロー対策 */
			if (len >= 8){
				break;
			}

			*ptmp = (val % 16);
			if (*ptmp > 9){
				*ptmp += str_a - 10;
			} else {
				*ptmp += '0';
			}

			val >>= 4;		/* 16で割る */
			ptmp--;
			len++;
		}
	}
	while (len < wd){
		*(ptmp--) =  zf ? '0' : ' ';
		len++;
	}

	for (i=0;i<len;i++){
		*(buff++) = *(++ptmp);
	}

	return(len);
}

/*
  数値 => 1文字キャラクタ変換
*/
static int
tsprintf_char(int ch,char* buff){
	*buff = (char)ch;
	return(1);
}

/*
  数値 => ASCIIZ文字列変換
*/
static int
tsprintf_string(char* str,char* buff){
	int count = 0;
	while(*str){
		*(buff++) = *str;
		str++;
		count++;
	}
	return(count);
}


/*
  Tiny sprintf関数
*/
int
tsprintf(char* buff,char* fmt, ...){
	va_list arg;
	int len;
	int size;
	int zeroflag,width;

	size = 0;
	len = 0;
	va_start(arg, fmt);

	vtsprintf(buff,fmt,arg);

	va_end(arg);
}

/*
  Tiny sprintf関数
*/

static void debug_print_init(void)
{
	iowrite32(UART_BASE+UARTIBRD, 0x6);
	iowrite32(UART_BASE+UARTFBRD, 0x21);
	iowrite32(UART_BASE+UARTLCR_H, 0x70);
	iowrite32(UART_BASE+UARTCR, 0x301);
}

static inline void debug_putc(char c)
{
	while (ioread32(UART_BASE+UARTFR) & (0x1<<5));
	iowrite32(UART_BASE+UARTDR, c);
}

static void debug_print(char* buff)
{
	while ( *buff ) {
		debug_putc(*buff);
		if ( *buff == '\n' ) {
			debug_putc('\r');
		}
		buff++;
	}
}

void tprintf_init(void)
{
	debug_print_init();
}

int tprintf(char* fmt, ...)
{
static char		buff[1024];
	va_list arg;
	int len;
	int size;
	int zeroflag,width;

	size = 0;
	len = 0;
	va_start(arg, fmt);

	vtsprintf(buff,fmt,arg);

	va_end(arg);
	debug_print(buff);
}
